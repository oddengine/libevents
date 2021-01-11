#include "error.h"

const Error *Error::AbortError = new Error("AbortError", "Max recursion reached.");
const Error *Error::DataError = new Error("DataError", "Provided data is inadequate.");

Error::Error(const std::string &name, const std::string &message)
{
    m_name = name;
    m_message = message;
}

Error::~Error()
{
}

std::string Error::toString()
{
    return m_name + ": " + m_message;
}
