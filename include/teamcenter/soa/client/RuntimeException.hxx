/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/**

    @file

    This is a generic RuntimeException that is used usually to indicate
    a programming error or internal error in the client

    InternalError  - Client internal error.
    TypeMismatch   - Property type mismatch, caused by asking for the wrong type
                     (e.g. int from string property).
    NotLoaded      - Something (property or object) was asked for that isn't
                     in the client side model
    UserError      - For user use.
    Unknown        - Unknown error.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_RUNTIMEEXCEPTION_HXX
#define TEAMCENTER_SOA_CLIENT_RUNTIMEEXCEPTION_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API RuntimeException
{
public:

    enum ErrorType
    {
        InternalError,
        NotImplemented,
        TypeMismatch,
        NotLoaded,
        UserError,
        LibLoadError,
        Unknown
    };

    explicit RuntimeException( ErrorType t = Unknown, const std::string& message = "" );
    virtual ~RuntimeException();

    const std::string& getMessage() const;
    ErrorType getType() const;

    SOA_CLASS_NEW_OPERATORS

private:
    ErrorType m_type;
    std::string m_message;
};
}}} //end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
