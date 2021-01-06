#include "errorevent.h"

const std::string ErrorEvent::ERROR = "error";

ErrorEvent::ErrorEvent(const std::string &type, void *target, const std::string &name, const std::string &message)
    : Event(type, target),
      m_error(name, message)
{
}

ErrorEvent::~ErrorEvent()
{
}

std::shared_ptr<IEvent> ErrorEvent::clone()
{
    return std::make_shared<ErrorEvent>(m_type, m_target, m_error.m_name, m_error.m_message);
}

std::string ErrorEvent::toString()
{
    return "[ErrorEvent type=" + m_type + ", name=" + m_error.m_name + ", message=" + m_error.m_message + "]";
}
