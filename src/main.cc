#include <string>

#include "events/event.h"
#include "../tests/events/dummyeventdispatcher.h"

std::shared_ptr<EventListener> listener;

void onComplete(std::shared_ptr<IEvent> e)
{
    auto dummy = (DummyEventDispatcher *)e->target();
    dummy->removeEventListener(Event::COMPLETE, listener);
}

int main(int argc, char *argv[])
{
    listener = std::make_shared<EventListener>(onComplete);

    auto dummy = std::make_shared<DummyEventDispatcher>();
    dummy->addEventListener(Event::COMPLETE, listener);
    dummy->dosomething();
}
