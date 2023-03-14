#pragma once

#include <string>

class Exception
{
public:
    static const Exception *AbortError;
    static const Exception *ConstraintError;
    static const Exception *DataCloneError;
    static const Exception *DataError;
    static const Exception *EncodingError;
    static const Exception *HierarchyRequestError;
    static const Exception *IndexSizeError;
    static const Exception *InvalidAccessError;
    static const Exception *InvalidCharacterError;
    static const Exception *InvalidModificationError;
    static const Exception *InvalidNodeTypeError;
    static const Exception *InvalidStateError;
    static const Exception *NamespaceError;
    static const Exception *NetworkError;
    static const Exception *NoModificationAllowedError;
    static const Exception *NotAllowedError;
    static const Exception *NotFoundError;
    static const Exception *NotReadableError;
    static const Exception *NotSupportedError;
    static const Exception *OperationError;
    static const Exception *QuotaExceededError;
    static const Exception *ReadOnlyError;
    static const Exception *SecurityError;
    static const Exception *SyntaxError;
    static const Exception *TimeoutError;
    static const Exception *TransactionInactiveError;
    static const Exception *TypeError;
    static const Exception *URLMismatchError;
    static const Exception *UnknownError;
    static const Exception *VersionError;
    static const Exception *WrongDocumentError;

    Exception(const std::string &name, const std::string &message = "");
    virtual ~Exception();

    std::string Name() { return name_; }
    std::string Message() { return message_; }

    std::string String();

protected:
    std::string name_;
    std::string message_;
};
