#pragma once

#include <atomic>
#include <map>
#include <mutex>
#include <string>

#include "events.h"

#define MAX_RECURSION 8

class EventDispatcher : public IEventDispatcher
{
public:
    EventDispatcher();
    ~EventDispatcher();

    void addEventListener(const std::string &type, std::shared_ptr<EventListener> listener) override;
    void removeEventListener(const std::string &type, std::shared_ptr<EventListener> listener) override;
    bool hasEventListener(const std::string &type) override;

protected:
    void dispatchEvent(std::shared_ptr<IEvent> event) override;

private:
    std::recursive_mutex m_mtx;
    std::map<std::string, std::map<uintptr_t, std::shared_ptr<EventListener>>> m_listeners;
    std::atomic<int> m_recursion;
};
