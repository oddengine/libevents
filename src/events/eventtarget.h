#pragma once

#include <atomic>
#include <map>
#include <mutex>
#include <string>

#include "events.h"

namespace odd
{

#define MAX_RECURSION 8

    class EventTarget : public IEventTarget
    {
    public:
        EventTarget();
        virtual ~EventTarget();

        void AddEventListener(const std::string &type, EventListener *listener) override;
        void RemoveEventListener(const std::string &type, EventListener *listener) override;
        bool HasEventListeners(const std::string &type = "") override;

    protected:
        EventResult DispatchEvent(IEvent *e) override;

    private:
        std::recursive_mutex mtx_;
        std::map<std::string, MappableEventListenerCollection *> listeners_;
        std::atomic<int> recursion_;
    };

} // namespace odd
