#include "event.h"

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
const std::string Event::REMOVED = "removed";

Event::Event(const std::string &type, void *target)
{
    m_type = type;
    m_target = target;
}

Event::~Event()
{
}

std::string Event::type()
{
    return m_type;
}

void *Event::target()
{
    return m_target;
}

bool Event::stoppedPropagation()
{
    return m_stopPropagation;
}

void Event::stopPropagation()
{
    m_stopPropagation = true;
}

std::shared_ptr<IEvent> Event::clone()
{
    return std::make_shared<Event>(m_type, m_target);
}

std::string Event::toString()
{
    return "[Event type=" + m_type + "]";
}
