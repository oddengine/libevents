#pragma once

#include "object.h"

#include <string>

class Error : public Object
{
public:
    static const Error *AbortError;
    static const Error *DataError;

    Error(const std::string &name, const std::string &message = "");
    virtual ~Error();

    std::string toString() override;

    std::string m_name;
    std::string m_message;
};
