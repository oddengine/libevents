#include "error.h"

const Error *Error::AbortError = new Error("AbortError", "The operation was aborted.");
const Error *Error::ConstraintError = new Error("ConstraintError", "A mutation operation in a transaction failed because a constraint was not satisfied.");
const Error *Error::DataCloneError = new Error("DataCloneError", "The object can not be cloned.");
const Error *Error::DataError = new Error("DataError", "Provided data is inadequate.");
const Error *Error::EncodingError = new Error("EncodingError", "The encoding or decoding operation failed.");
const Error *Error::HierarchyRequestError = new Error("HierarchyRequestError", "The node tree hierarchy is not correct.");
const Error *Error::IndexSizeError = new Error("IndexSizeError", "The index is not in the allowed range.");
const Error *Error::InvalidAccessError = new Error("InvalidAccessError", "The object does not support the operation or argument.");
const Error *Error::InvalidCharacterError = new Error("InvalidCharacterError", "The string contains invalid characters.");
const Error *Error::InvalidModificationError = new Error("InvalidModificationError", "The object cannot be modified in this way.");
const Error *Error::InvalidNodeTypeError = new Error("InvalidNodeTypeError", "The node is incorrect or has an incorrect ancestor for this operation.");
const Error *Error::InvalidStateError = new Error("InvalidStateError", "The object is in an invalid state.");
const Error *Error::NamespaceError = new Error("NamespaceError", "The operation is not allowed by Namespaces in XML.");
const Error *Error::NetworkError = new Error("NetworkError", "A network error occurred.");
const Error *Error::NoModificationAllowedError = new Error("NoModificationAllowedError", "The object cannot be modified.");
const Error *Error::NotAllowedError = new Error("NotAllowedError", "The operation is not allowed.");
const Error *Error::NotFoundError = new Error("NotFoundError", "The object cannot be found here.");
const Error *Error::NotReadableError = new Error("NotReadableError", "The input/output read operation failed.");
const Error *Error::NotSupportedError = new Error("NotSupportedError", "The operation is not supported.");
const Error *Error::OperationError = new Error("OperationError", "The operation failed for an operation-specific reason.");
const Error *Error::QuotaExceededError = new Error("QuotaExceededError", "The quota has been exceeded.");
const Error *Error::ReadOnlyError = new Error("ReadOnlyError", "The mutating operation was attempted in a \"readonly\" transaction.");
const Error *Error::SecurityError = new Error("SecurityError", "The operation is insecure.");
const Error *Error::SyntaxError = new Error("SyntaxError", "The string did not match the expected pattern.");
const Error *Error::TimeoutError = new Error("TimeoutError", "The operation timed out.");
const Error *Error::TransactionInactiveError = new Error("TransactionInactiveError", "A request was placed against a transaction that is currently not active or is finished.");
const Error *Error::TypeError = new Error("TypeError", "The value is not of the expected type.");
const Error *Error::URLMismatchError = new Error("URLMismatchError", "The given URL does not match another URL.");
const Error *Error::UnknownError = new Error("UnknownError", "The operation failed for an unknown transient reason.");
const Error *Error::VersionError = new Error("VersionError", "An attempt was made using a lower version than the existing version.");
const Error *Error::WrongDocumentError = new Error("WrongDocumentError", "The object is in the wrong Document.");

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
