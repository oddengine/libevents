#pragma once

#include "../../src/events/eventtarget.h"

class DummyEventTarget : public EventTarget {
public:
    DummyEventTarget();
    virtual ~DummyEventTarget();

    void DoSomething();
};
