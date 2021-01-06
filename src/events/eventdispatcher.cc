#include "eventdispatcher.h"
#include "event.h"

#include <thread>

EventDispatcher::EventDispatcher()
{
    m_recursion = 0;
}

EventDispatcher::~EventDispatcher()
{
}

void EventDispatcher::addEventListener(const std::string &type, std::shared_ptr<EventListener> listener)
{
    if (type == "" || listener == nullptr)
    {
        throw new Error("DataError", "Provided data is inadequate.");
    }

    std::lock_guard<std::recursive_mutex> lock(m_mtx);

    auto &typed = m_listeners[type];
    typed[uintptr_t(listener.get())] = listener;
}

void EventDispatcher::removeEventListener(const std::string &type, std::shared_ptr<EventListener> listener)
{
    if (type == "" || listener == nullptr)
    {
        throw new Error("DataError", "Provided data is inadequate.");
    }

    std::lock_guard<std::recursive_mutex> lock(m_mtx);

    auto &typed = m_listeners[type];
    typed.erase(uintptr_t(listener.get()));
}

bool EventDispatcher::hasEventListener(const std::string &type)
{
    std::lock_guard<std::recursive_mutex> lock(m_mtx);

    if (type == "")
    {
        return m_listeners.size() > 0;
    }

    auto &typed = m_listeners[type];
    return typed.size() > 0;
}

void EventDispatcher::dispatchEvent(std::shared_ptr<IEvent> event)
{
    if (event == nullptr)
    {
        throw new Error("DataError", "Provided data is inadequate.");
    }

    std::lock_guard<std::recursive_mutex> lock(m_mtx);

    if (++m_recursion > MAX_RECURSION)
    {
        throw new Error("AbortError", "Max recursion reached.");
    }

    // Make a shallow copy of the listener map, so that it triggers the event to the exact listeners.
    auto typed = m_listeners[event->type()];
    for (auto it = typed.begin(); it != typed.end(); it++)
    {
        it->second->m_handler(event);

        if (it->second->m_count > 0 && --it->second->m_count == 0)
        {
            removeEventListener(event->type(), it->second);
        }
        if (event->stoppedPropagation())
        {
            break;
        }
    }
}
