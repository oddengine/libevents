#include "events.h"

EventListener::EventListener(IEventHandler handler, int count)
{
    m_handler = handler;
    m_count = count;
}

EventListener::~EventListener()
{
}
