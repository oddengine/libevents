#pragma once

#include "../../src/events/eventtarget.h"

using namespace odd;

class DummyEventTarget : public EventTarget
{
public:
    DummyEventTarget();
    virtual ~DummyEventTarget();

    void DoSomething();
};
