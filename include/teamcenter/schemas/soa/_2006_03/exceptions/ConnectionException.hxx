/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_CONNECTIONEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_CONNECTIONEXCEPTION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <string>

#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>

/**
 *  The Connection exception is used to catch any network or I/O
 *  errors while marshalling a service request. These exception
 *  usually be recovered from, that is after the problem with the
 *  network has been fixed, the last service request can be retried.
 *
 */
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


class TCSOACOMMON_API ConnectionException: public InternalServerException
{
public:
    ConnectionException();
    virtual ~ConnectionException();
    explicit ConnectionException( const std::string& message );
    ConnectionException( const std::string& message, const int code, const Error::Severity level );

    virtual std::string getLocalName() const;

    SOA_CLASS_NEW_OPERATORS


private:


};

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

