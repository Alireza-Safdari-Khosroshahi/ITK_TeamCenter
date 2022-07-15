/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  **/
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_SERVICEEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_SERVICEEXCEPTION_HXX


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


class TCSOACOMMON_API ServiceException : public SoaException
{

public:

    ServiceException ();
    virtual ~ServiceException();
    explicit ServiceException ( const std::string& message );
    ServiceException ( const std::string& message, const int code, const Error::Severity level );

    void addMessage( const std::string& message );
    void addMessage( const std::string& message, const int code, const Error::Severity level );

    const std::vector< std::string >& getMessages()const;
    const std::vector< Error >&        getErrors()const;

    void setUid( const std::string& uid );
    const std::string& getUid( )const;
    bool isUidSet()const;
    void setClientId( const std::string& clientId );
    const std::string& getClientId( )const;
    bool isClientIdSet() const;


    virtual std::string getLocalName() const;

    SOA_CLASS_NEW_OPERATORS

private:

    std::vector<std::string>    m_messages;
    std::vector<Error>          m_errors;
    std::string                 m_uid;
    bool                        m_uidSet;
    std::string                 m_clientId;
    bool                        m_clientIdSet;
};

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif




