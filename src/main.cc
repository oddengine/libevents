#include "events/event.h"
#include "../tests/events/dummyeventtarget.h"

EventListener *listener;

void onComplete(IEvent *e)
{
    auto dummy = (DummyEventTarget *)e->Target();
    dummy->RemoveEventListener(Event::COMPLETE, listener);
}

int main(int argc, char *argv[])
{
    listener = EventListener::Create(onComplete);

    auto dummy = std::make_shared<DummyEventTarget>();
    dummy->AddEventListener(Event::COMPLETE, listener);
    dummy->DoSomething();
}
