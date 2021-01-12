#pragma once

#include "../base/object.h"

#include <atomic>
#include <functional>
#include <memory>
#include <string>

class IEvent : Object
{
public:
    virtual std::string type() = 0;
    virtual void *source() = 0;
    virtual void *target() = 0;
    virtual bool stoppedPropagation() = 0;

    virtual void stopPropagation() = 0;
    virtual std::shared_ptr<IEvent> clone() = 0;

protected:
    friend class EventDispatcher;

    virtual void set_target(void *target) = 0;
};

typedef std::function<void(std::shared_ptr<IEvent>)> IEventHandler;

class EventListener
{
public:
    EventListener(IEventHandler handler, int count = 0);
    ~EventListener();

    IEventHandler m_handler;
    std::atomic<int> m_count;
};

class IEventDispatcher
{
public:
    virtual void addEventListener(const std::string &type, std::shared_ptr<EventListener> listener) = 0;
    virtual void removeEventListener(const std::string &type, std::shared_ptr<EventListener> listener) = 0;
    virtual bool hasEventListener(const std::string &type) = 0;

protected:
    virtual void dispatchEvent(std::shared_ptr<IEvent> event) = 0;
};
