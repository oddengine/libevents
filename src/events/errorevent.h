#pragma once

#include "../base/error.h"
#include "event.h"

class ErrorEvent : public Event
{
public:
    static const std::string ERROR;

    ErrorEvent(const std::string &type, void *target, const std::string &name, const std::string &message = "");
    virtual ~ErrorEvent();

    std::string name();
    std::string message();

    std::shared_ptr<IEvent> clone() override;
    std::string toString() override;

protected:
    Error m_error;
};
