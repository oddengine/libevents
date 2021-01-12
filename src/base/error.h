#pragma once

#include "object.h"

#include <string>

class Error : public Object
{
public:
    static const Error *AbortError;
    static const Error *ConstraintError;
    static const Error *DataCloneError;
    static const Error *DataError;
    static const Error *EncodingError;
    static const Error *HierarchyRequestError;
    static const Error *IndexSizeError;
    static const Error *InvalidAccessError;
    static const Error *InvalidCharacterError;
    static const Error *InvalidModificationError;
    static const Error *InvalidNodeTypeError;
    static const Error *InvalidStateError;
    static const Error *NamespaceError;
    static const Error *NetworkError;
    static const Error *NoModificationAllowedError;
    static const Error *NotAllowedError;
    static const Error *NotFoundError;
    static const Error *NotReadableError;
    static const Error *NotSupportedError;
    static const Error *OperationError;
    static const Error *QuotaExceededError;
    static const Error *ReadOnlyError;
    static const Error *SecurityError;
    static const Error *SyntaxError;
    static const Error *TimeoutError;
    static const Error *TransactionInactiveError;
    static const Error *TypeError;
    static const Error *URLMismatchError;
    static const Error *UnknownError;
    static const Error *VersionError;
    static const Error *WrongDocumentError;

    Error(const std::string &name, const std::string &message = "");
    virtual ~Error();

    std::string toString() override;

    std::string m_name;
    std::string m_message;
};
