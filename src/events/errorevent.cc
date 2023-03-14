#include "errorevent.h"

const std::string ErrorEvent::ERROR = "error";

ErrorEvent::ErrorEvent(const std::string &type, IEventTarget *target, const std::string &name, const std::string &message)
    : Event(type, target),
      name_(name),
      message_(message)
{
}

ErrorEvent::~ErrorEvent()
{
}

IEvent *ErrorEvent::Clone()
{
    return new ErrorEvent(type_, target_, name_, message_);
}

std::string ErrorEvent::String()
{
    return "[ErrorEvent type=" + type_ + ", name=" + name_ + ", message=" + message_ + "]";
}
