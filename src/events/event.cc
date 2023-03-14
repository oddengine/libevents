#include "event.h"

namespace odd
{

    const std::string Event::ACTIVATE = "activate";
    const std::string Event::ADDED = "added";
    const std::string Event::CANCEL = "cancel";
    const std::string Event::CHANGE = "change";
    const std::string Event::CLEAR = "clear";
    const std::string Event::CLOSE = "close";
    const std::string Event::COMPLETE = "complete";
    const std::string Event::CONNECT = "connect";
    const std::string Event::DEACTIVATE = "deactivate";
    const std::string Event::IDLE = "idle";
    const std::string Event::INIT = "init";
    const std::string Event::OPEN = "open";
    const std::string Event::RELEASE = "release";
    const std::string Event::REMOVED = "removed";

    Event::Event(const std::string &type, IEventTarget *target)
        : type_(type),
          target_(target),
          current_target_(nullptr),
          propagation_stopped_(false)
    {
    }

    Event::~Event()
    {
    }

    void Event::SetType(std::string type)
    {
        type_ = type;
    }

    std::string Event::Type()
    {
        return type_;
    }

    void Event::SetTarget(IEventTarget *target)
    {
        target_ = target;
    }

    IEventTarget *Event::Target()
    {
        return target_;
    }

    void Event::SetCurrentTarget(IEventTarget *target)
    {
        current_target_ = target;
    }

    IEventTarget *Event::CurrentTarget()
    {
        return current_target_;
    }

    void Event::StopPropagation()
    {
        propagation_stopped_ = true;
    }

    bool Event::PropagationStopped()
    {
        return propagation_stopped_;
    }

    IEvent *Event::Clone()
    {
        return new Event(type_, target_);
    }

    std::string Event::String()
    {
        return "[Event type=" + type_ + "]";
    }

} // namespace odd
