#pragma once

#include "events.h"

enum EventResult
{
    ER_NONE = 0,
    ER_CONSUMED = 1,
};

class Event : public IEvent
{
public:
    static const std::string ACTIVATE;
    static const std::string ADDED;
    static const std::string CANCEL;
    static const std::string CHANGE;
    static const std::string CLEAR;
    static const std::string CLOSE;
    static const std::string COMPLETE;
    static const std::string CONNECT;
    static const std::string DEACTIVATE;
    static const std::string IDLE;
    static const std::string INIT;
    static const std::string OPEN;
    static const std::string REMOVED;

    Event(const std::string &type, void *source);
    virtual ~Event();

    std::string type() override;
    void *source() override;
    void *target() override;
    bool stoppedPropagation() override;

    void stopPropagation() override;
    std::shared_ptr<IEvent> clone() override;
    std::string toString() override;

protected:
    void set_target(void *target) override;

    std::string m_type;
    void *m_source;
    void *m_target;
    EventResult m_result = ER_NONE;
};
