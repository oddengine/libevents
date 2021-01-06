#pragma once

#include "../../src/events/eventdispatcher.h"

class DummyEventDispatcher : public EventDispatcher
{
public:
    DummyEventDispatcher();
    virtual ~DummyEventDispatcher();

    void dosomething();
};
