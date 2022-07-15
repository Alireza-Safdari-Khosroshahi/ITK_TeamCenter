/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_INVALIDCREDENTIALSEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_INVALIDCREDENTIALSEXCEPTION_HXX


#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/SoaException.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2006_03
            {
               namespace Exceptions
               {


class TCSOACOMMON_API InvalidCredentialsException : public SoaException
{

public:
    InvalidCredentialsException();
    virtual ~InvalidCredentialsException();
    explicit  InvalidCredentialsException( const std::string& message );
    InvalidCredentialsException( const std::string& message, const int code, const Error::Severity level );

    const Error&        getError()const;

    virtual std::string  getLocalName() const;

    SOA_CLASS_NEW_OPERATORS

private:
    Error           m_error;


};

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
