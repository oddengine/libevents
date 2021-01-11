#pragma once

#include <atomic>
#include <functional>
#include <memory>
#include <string>

class Error
{
public:
    Error(const std::string &name, const std::string &message = "");
    virtual ~Error();

    std::string m_name;
    std::string m_message;
};

class IEvent
{
public:
    virtual std::string type() = 0;
    virtual void *target() = 0;
    virtual bool stoppedPropagation() = 0;

    virtual void stopPropagation() = 0;
    virtual std::shared_ptr<IEvent> clone() = 0;
    virtual std::string toString() = 0;
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
