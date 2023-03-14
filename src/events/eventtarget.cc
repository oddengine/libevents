#include "eventtarget.h"

#include <thread>

#include "event.h"
#include "exception.h"

EventTarget::EventTarget()
{
    recursion_ = 0;
}

EventTarget::~EventTarget()
{
    listeners_.clear();
}

void EventTarget::AddEventListener(const std::string &type, EventListener *listener)
{
    if (type == "" || listener == nullptr)
    {
        throw Exception::DataError;
    }

    std::lock_guard<std::recursive_mutex> lock(mtx_);

    auto m = listeners_[type];
    if (m == nullptr)
    {
        m = MappableEventListenerCollection::Create();
        listeners_[type] = m;
    }
    m->Add(listener);
}

void EventTarget::RemoveEventListener(const std::string &type, EventListener *listener)
{
    if (type == "" || listener == nullptr)
    {
        throw Exception::DataError;
    }

    std::lock_guard<std::recursive_mutex> lock(mtx_);

    auto m = listeners_[type];
    if (m != nullptr)
    {
        m->Remove(listener, recursion_ == 0);
    }
}

bool EventTarget::HasEventListeners(const std::string &type)
{
    std::lock_guard<std::recursive_mutex> lock(mtx_);

    if (type == "")
    {
        return listeners_.size() > 0;
    }

    auto m = listeners_[type];
    return m != nullptr && m->size() > 0;
}

EventResult EventTarget::DispatchEvent(IEvent *e)
{
    if (e == nullptr)
    {
        throw Exception::DataError;
    }

    std::lock_guard<std::recursive_mutex> lock(mtx_);

    e->SetCurrentTarget(this);

    // Check recursion.
    recursion_++;
    if (recursion_ > MAX_RECURSION)
    {
        throw Exception::AbortError;
    }

    // Get the typed listener collection.
    auto result = EventResult::kNotCanceled;

    auto m = listeners_[e->Type()];
    if (m != nullptr)
    {
        // Loop to invoke the handlers.
        for (auto it = m->begin(); it != m->end(); it = m->Next(it, m->end()))
        {
            auto listener = *it;
            listener->Invoke(e);

            if (listener->Options().Once)
            {
                m->Remove(listener, recursion_ == 0);
            }
            if (e->PropagationStopped())
            {
                result = EventResult::kCanceledByEventHandler;
                break;
            }
        }
        if (recursion_ == 1)
        {
            m->RemoveEventually();
        }
    }
    recursion_--;
    return result;
}
