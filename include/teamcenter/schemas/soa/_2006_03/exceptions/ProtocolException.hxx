/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  **/
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_PROTOCOLEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_PROTOCOLEXCEPTION_HXX


#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>

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


/**
 * The Protocol excetpion is used to catch and errors in the content
 * of a service request. These errors are generally a result of a
 * programming error and can not be recovered from.
 *
 */
class TCSOACOMMON_API ProtocolException: public InternalServerException
{
public:
    ProtocolException();
    virtual ~ProtocolException();
    explicit  ProtocolException( const std::string& message );
    ProtocolException( const std::string& message, const int code, const Error::Severity level );

    virtual std::string getLocalName() const;

    SOA_CLASS_NEW_OPERATORS

private:

};

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
