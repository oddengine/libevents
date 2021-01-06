#include "dummyeventdispatcher.h"
#include "../../src/events/event.h"

DummyEventDispatcher::DummyEventDispatcher()
{
}

DummyEventDispatcher::~DummyEventDispatcher()
{
}

void DummyEventDispatcher::dosomething()
{
    this->dispatchEvent(std::make_shared<Event>(Event::COMPLETE, this));
}
