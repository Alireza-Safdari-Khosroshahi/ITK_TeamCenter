/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_INTERNALSERVEREXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_INTERNALSERVEREXCEPTION_HXX


#include <string>

#include <vector>
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


/**
 * The internal server exception is used to catch any exceptions while
 * processing a service across the different tiers.
 *
 **/
class TCSOACOMMON_API InternalServerException: public SoaException
{
public:
    InternalServerException();
    explicit InternalServerException( const std::string& message );
    InternalServerException( const std::string& message, const int code, const Error::Severity level );
    virtual ~InternalServerException();

    virtual const Error& getError()const;
    virtual std::string  getLocalName() const;

    void addMessage(const std::string& message, const int code, const Error::Severity level );
    const std::vector<Error>& getErrors() const;


    SOA_CLASS_NEW_OPERATORS
    
private: 
    std::vector<Error>   m_error;
    


};

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
