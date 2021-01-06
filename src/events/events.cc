#include "events.h"

Error::Error(const std::string &name, const std::string &message)
{
    m_name = name;
    m_message = message;
}

Error::~Error()
{
}

EventListener::EventListener(IEventHandler handler, int count)
{
    m_handler = handler;
    m_count = count;
}

EventListener::~EventListener()
{
}
