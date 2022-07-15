/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_ERRORSTACK_HXX
#define TEAMCENTER_SOA_CLIENT_ERRORSTACK_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

struct  ErrorValue
{
    enum ErrorSeverity
    {
        Error_severity_information = 1,
        Error_severity_warning     = 2,
        Error_severity_error       = 3
    };

    int code;
    std::string message;
    ErrorSeverity level;
};
class ModelObject;
class TCSOACLIENTMNGD_API ErrorStack
{
public:
    ~ErrorStack();










    /**
     * Returns true if the ErrorStack has a  Client-Index associated with it.
     * @return  true if the ErrorStack has a Client-Index associated with it.
     */
    bool hasClientIndex() const;
    
    
    /**
     * Returns the  Client-Index.
     * If the service implementation did not add a Client-Index to the ErrorStack
     * this method will return -1.
     *
     * @return  The  Client-Index.
     */
    int  getClientIndex() const;

   /**
     * Returns true if the ErrorStack has a Client-ID associated with it.
     * @return  true if the ErrorStack has a Client-ID associated with it.
     */
    bool               hasClientId() const;
    /**
     * Returns the  Client-ID.
     * If the service implementation did not add a  Client-ID to the ErrorStack
     * this method will return an empty string.
     * 
     * @return  The  Client-ID.
     */
    const std::string& getClientId() const;

   /**
     * Returns true if the ErrorStack has an associated object.
     * @return  true if the ErrorStack has an associated object.
     */
    bool         hasAssociatedObject() const;

    /**
     * Returns the  associated object.
     * If the service implementation did not add an  associated object to the ErrorStack
     * this method will return null.
     * 
     * @return  The  associated object.
     */
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getAssociatedObject() const;

    int getErrorValueCount() const;

   /**
     * Return the nth ErrorValue for this error.
     * Any given error may have multiple contributing reasons, each ErrorValue
     * in the returned array represents a different contributor to this error.
     * 
     * @return The nth ErrorValue for this error.
     */
    const ErrorValue& getErrorValue( int inx ) const;

    SOA_CLASS_NEW_OPERATORS

private:
    friend class ModelManagerImpl;
    friend class DefaultObjectFactory;
    ErrorStack();

    std::string m_clientId;
    int         m_clientIndex;
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> m_modelObj;
    std::vector< ErrorValue > m_stack;

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
