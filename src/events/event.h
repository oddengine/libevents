#pragma once

#include "events.h"

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
    static const std::string RELEASE;
    static const std::string REMOVED;

    static Event *Create(const std::string &type, IEventTarget *target)
    {
        return new Event(type, target);
    }

    Event(const std::string &type, IEventTarget *target);
    virtual ~Event();

    std::string Type() override;
    IEventTarget *Target() override;
    void SetCurrentTarget(IEventTarget *target) override;
    IEventTarget *CurrentTarget() override;
    void StopPropagation() override;
    bool PropagationStopped() override;
    IEvent *Clone() override;
    std::string String() override;

protected:
    void SetType(std::string type) override;
    void SetTarget(IEventTarget *target) override;

    std::string type_;
    IEventTarget *target_;
    IEventTarget *current_target_;
    bool propagation_stopped_;
};
