#pragma once

#include <string>

#include "eventlistener.h"

namespace odd
{

    class IEventTarget;

    class Object
    {
    public:
        virtual std::string String() = 0;
    };

    class IEvent : Object
    {
    public:
        virtual void SetType(std::string event) = 0;
        virtual std::string Type() = 0;
        virtual void SetTarget(IEventTarget *target) = 0;
        virtual IEventTarget *Target() = 0;
        virtual void SetCurrentTarget(IEventTarget *target) = 0;
        virtual IEventTarget *CurrentTarget() = 0;
        virtual void StopPropagation() = 0;
        virtual bool PropagationStopped() = 0;
        virtual IEvent *Clone() = 0;

    protected:
        friend class IEventTarget;
    };

    class IEventTarget
    {
    public:
        virtual void AddEventListener(const std::string &type, EventListener *listener) = 0;
        virtual void RemoveEventListener(const std::string &type, EventListener *listener) = 0;
        virtual bool HasEventListeners(const std::string &type = "") = 0;

    protected:
        virtual EventResult DispatchEvent(IEvent *e) = 0;
    };

} // namespace odd
