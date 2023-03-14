#pragma once

#include <functional>
#include <list>
#include <map>
#include <string>

namespace odd
{

    class IEvent;

    enum class EventResult
    {
        // Event was not canceled by event handler or default event handler.
        kNotCanceled,
        // Event was canceled by event handler; i.e. a script handler calling StopPropagation.
        kCanceledByEventHandler,
        // Event was canceled by the default event handler; i.e. executing the default action.
        // This result should be used sparingly as it deviates from the Event Dispatch model.
        // Default event handlers really shouldn't be invoked inside of dispatch.
        kCanceledByDefaultEventHandler,
        // Event was canceled but suppressed before dispatched to event handler. This
        // result should be used sparingly; and its usage likely indicates there is
        // potential for a bug. Trusted events may return this code; but untrusted
        // events likely should always execute the event handler the developer intends
        // to execute.
        kCanceledBeforeDispatch,
    };

    typedef std::function<void(IEvent *)> IEventHandler;

    class EventListener
    {
    public:
        struct EventListenerOptions
        {
            bool Once;
        };

        static EventListener *Create(IEventHandler handler, EventListenerOptions options = {})
        {
            return new EventListener(handler, options);
        }

        EventListener(IEventHandler handler, EventListenerOptions options = {});
        ~EventListener();

        EventListenerOptions Options() { return options_; }
        void Invoke(IEvent *e);
        bool Matches(EventListener *listener);

    protected:
        IEventHandler handler_;
        EventListenerOptions options_;
    };

    class MappableEventListenerCollection
    {
    public:
        MappableEventListenerCollection();
        ~MappableEventListenerCollection();

        static MappableEventListenerCollection *Create()
        {
            return new MappableEventListenerCollection();
        }

        void Add(EventListener *listener);
        void Remove(EventListener *listener, bool immediately = false);
        std::list<EventListener *>::iterator Next(std::list<EventListener *>::iterator it, std::list<EventListener *>::iterator end);
        void RemoveEventually();
        std::list<EventListener *>::iterator begin() { return list_.begin(); }
        std::list<EventListener *>::iterator end() { return list_.end(); }
        size_t size() { return list_.size(); }

    protected:
        std::list<EventListener *> list_;
        std::map<uintptr_t, std::list<EventListener *>::iterator> elements_;
        std::map<uintptr_t, std::list<EventListener *>::iterator> removed_;
    };

} // namespace odd
