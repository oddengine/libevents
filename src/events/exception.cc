#include "exception.h"

const Exception *Exception::AbortError = new Exception("AbortError", "The operation was aborted.");
const Exception *Exception::ConstraintError = new Exception("ConstraintError", "A mutation operation in a transaction failed because a constraint was not satisfied.");
const Exception *Exception::DataCloneError = new Exception("DataCloneError", "The object can not be cloned.");
const Exception *Exception::DataError = new Exception("DataError", "Provided data is inadequate.");
const Exception *Exception::EncodingError = new Exception("EncodingError", "The encoding or decoding operation failed.");
const Exception *Exception::HierarchyRequestError = new Exception("HierarchyRequestError", "The node tree hierarchy is not correct.");
const Exception *Exception::IndexSizeError = new Exception("IndexSizeError", "The index is not in the allowed range.");
const Exception *Exception::InvalidAccessError = new Exception("InvalidAccessError", "The object does not support the operation or argument.");
const Exception *Exception::InvalidCharacterError = new Exception("InvalidCharacterError", "The string contains invalid characters.");
const Exception *Exception::InvalidModificationError = new Exception("InvalidModificationError", "The object cannot be modified in this way.");
const Exception *Exception::InvalidNodeTypeError = new Exception("InvalidNodeTypeError", "The node is incorrect or has an incorrect ancestor for this operation.");
const Exception *Exception::InvalidStateError = new Exception("InvalidStateError", "The object is in an invalid state.");
const Exception *Exception::NamespaceError = new Exception("NamespaceError", "The operation is not allowed by Namespaces in XML.");
const Exception *Exception::NetworkError = new Exception("NetworkError", "A network error occurred.");
const Exception *Exception::NoModificationAllowedError = new Exception("NoModificationAllowedError", "The object cannot be modified.");
const Exception *Exception::NotAllowedError = new Exception("NotAllowedError", "The operation is not allowed.");
const Exception *Exception::NotFoundError = new Exception("NotFoundError", "The object cannot be found here.");
const Exception *Exception::NotReadableError = new Exception("NotReadableError", "The input/output read operation failed.");
const Exception *Exception::NotSupportedError = new Exception("NotSupportedError", "The operation is not supported.");
const Exception *Exception::OperationError = new Exception("OperationError", "The operation failed for an operation-specific reason.");
const Exception *Exception::QuotaExceededError = new Exception("QuotaExceededError", "The quota has been exceeded.");
const Exception *Exception::ReadOnlyError = new Exception("ReadOnlyError", "The mutating operation was attempted in a \"readonly\" transaction.");
const Exception *Exception::SecurityError = new Exception("SecurityError", "The operation is insecure.");
const Exception *Exception::SyntaxError = new Exception("SyntaxError", "The string did not match the expected pattern.");
const Exception *Exception::TimeoutError = new Exception("TimeoutError", "The operation timed out.");
const Exception *Exception::TransactionInactiveError = new Exception("TransactionInactiveError", "A request was placed against a transaction that is currently not active or is finished.");
const Exception *Exception::TypeError = new Exception("TypeError", "The value is not of the expected type.");
const Exception *Exception::URLMismatchError = new Exception("URLMismatchError", "The given URL does not match another URL.");
const Exception *Exception::UnknownError = new Exception("UnknownError", "The operation failed for an unknown transient reason.");
const Exception *Exception::VersionError = new Exception("VersionError", "An attempt was made using a lower version than the existing version.");
const Exception *Exception::WrongDocumentError = new Exception("WrongDocumentError", "The object is in the wrong Document.");

Exception::Exception(const std::string &name, const std::string &message)
    : name_(name),
      message_(message)
{
}

Exception::~Exception()
{
}

std::string Exception::String()
{
    return name_ + ": " + message_;
}
