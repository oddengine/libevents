#include "dummyeventtarget.h"

#include "../../src/events/event.h"

DummyEventTarget::DummyEventTarget()
    : EventTarget() {
}

DummyEventTarget::~DummyEventTarget() {
}

void DummyEventTarget::DoSomething() {
    DispatchEvent(Event::Create(Event::COMPLETE, this));
}
