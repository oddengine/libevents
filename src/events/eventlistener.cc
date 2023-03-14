#include "eventlistener.h"

namespace odd
{

    EventListener::EventListener(IEventHandler handler, EventListenerOptions options)
        : handler_(handler),
          options_(options)
    {
    }

    EventListener::~EventListener()
    {
    }

    void EventListener::Invoke(IEvent *e)
    {
        handler_(e);
    }

    bool EventListener::Matches(EventListener *listener)
    {
        return listener == this;
    }

    MappableEventListenerCollection::MappableEventListenerCollection()
    {
    }

    MappableEventListenerCollection::~MappableEventListenerCollection()
    {
    }

    void MappableEventListenerCollection::Add(EventListener *listener)
    {
        auto key = uintptr_t(listener);

        auto it = elements_.find(key);
        if (it == elements_.end())
        {
            list_.push_back(listener);
            elements_[key] = --list_.end();
            removed_.erase(key);
        }
    }

    void MappableEventListenerCollection::Remove(EventListener *listener, bool immediately)
    {
        auto key = uintptr_t(listener);

        auto it = elements_.find(key);
        if (it != elements_.end())
        {
            if (!immediately)
            {
                removed_[key] = it->second;
                return;
            }
            list_.erase(it->second);
            elements_.erase(key);
            removed_.erase(key);
        }
    }

    std::list<EventListener *>::iterator MappableEventListenerCollection::Next(std::list<EventListener *>::iterator it, std::list<EventListener *>::iterator end)
    {
        for (it++; it != end; it++)
        {
            auto key = uintptr_t(*it);
            if (removed_.find(key) == removed_.end())
            {
                return it;
            }
        }
        return end;
    }

    void MappableEventListenerCollection::RemoveEventually()
    {
        for (auto it = removed_.begin(); it != removed_.end(); it++)
        {
            auto key = uintptr_t(*it->second);
            list_.erase(it->second);
            elements_.erase(key);
        }
        removed_.clear();
    }

} // namespace odd
