#include "dummyeventtarget.h"

#include <gtest/gtest.h>

#include "../../src/events/event.h"

int n = 0;
EventListener *listener1;
EventListener *listener2;
EventListener *listener3;

void onEvent(IEvent *e)
{
    n++;
}

void onComplete(IEvent *e)
{
    n++;

    auto dummy = (DummyEventTarget *)e->Target();
    dummy->RemoveEventListener(Event::COMPLETE, listener2);
    dummy->DoSomething();
}

TEST(EventTarget, AddEventListener)
{
    listener1 = EventListener::Create(onEvent);
    listener2 = EventListener::Create(onComplete);
    listener3 = EventListener::Create(onEvent);

    auto dummy = std::make_shared<DummyEventTarget>();
    ASSERT_FALSE(dummy->HasEventListeners(Event::COMPLETE));

    dummy->AddEventListener(Event::COMPLETE, listener1);
    dummy->AddEventListener(Event::COMPLETE, listener2);
    dummy->AddEventListener(Event::COMPLETE, listener3);
    ASSERT_TRUE(dummy->HasEventListeners(Event::COMPLETE));

    dummy->DoSomething();
    ASSERT_EQ(n, 5);
    dummy->DoSomething();
    ASSERT_EQ(n, 7);

    dummy->RemoveEventListener(Event::COMPLETE, listener1);
    dummy->RemoveEventListener(Event::COMPLETE, listener3);
    ASSERT_FALSE(dummy->HasEventListeners(Event::COMPLETE));

    dummy->DoSomething();
    ASSERT_EQ(n, 7);
}
