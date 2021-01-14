#include "dummyeventdispatcher.h"
#include "../../src/events/event.h"

#include <gtest/gtest.h>

static int n = 0;
std::shared_ptr<EventListener> listener1;
std::shared_ptr<EventListener> listener2;
std::shared_ptr<EventListener> listener3;

void onEvent(std::shared_ptr<IEvent> e)
{
    n++;
}

void onComplete(std::shared_ptr<IEvent> e)
{
    n++;

    auto dummy = (DummyEventDispatcher *)e->target();
    dummy->removeEventListener(Event::COMPLETE, listener2);
    dummy->dosomething();
}

TEST(EventDispatcher, addEventDispatcher)
{
    listener1 = std::make_shared<EventListener>(onEvent);
    listener2 = std::make_shared<EventListener>(onComplete);
    listener3 = std::make_shared<EventListener>(onEvent);

    auto dummy = std::make_shared<DummyEventDispatcher>();
    ASSERT_FALSE(dummy->hasEventListener(Event::COMPLETE));

    dummy->addEventListener(Event::COMPLETE, listener1);
    dummy->addEventListener(Event::COMPLETE, listener2);
    dummy->addEventListener(Event::COMPLETE, listener3);
    ASSERT_TRUE(dummy->hasEventListener(Event::COMPLETE));

    dummy->dosomething();
    ASSERT_EQ(n, 5);
    dummy->dosomething();
    ASSERT_EQ(n, 7);

    dummy->removeEventListener(Event::COMPLETE, listener1);
    dummy->removeEventListener(Event::COMPLETE, listener3);
    ASSERT_FALSE(dummy->hasEventListener(Event::COMPLETE));

    dummy->dosomething();
    ASSERT_EQ(n, 7);
}
