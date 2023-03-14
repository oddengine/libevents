#pragma once

#include "event.h"

class ErrorEvent : public Event
{
public:
    static const std::string ERROR;

    static ErrorEvent *Create(const std::string &type, IEventTarget *target, const std::string &name, const std::string &message = "")
    {
        return new ErrorEvent(type, target, name, message);
    }

    ErrorEvent(const std::string &type, IEventTarget *target, const std::string &name, const std::string &message = "");
    virtual ~ErrorEvent();

    std::string Name() { return name_; }
    std::string Message() { return message_; }

    IEvent *Clone() override;
    std::string String() override;

protected:
    std::string name_;
    std::string message_;
};
