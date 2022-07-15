/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/




#ifndef TEAMCENTER_SOA_CLIENT_REQUESTLISTENER_HXX
#define TEAMCENTER_SOA_CLIENT_REQUESTLISTENER_HXX

#include <string>
#include <map>

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * This is a simple structure used to hold information about the service
 * request or response.
 *
 */
class TCSOACLIENTMNGD_API ServiceInfo
{
public:
    /**
     * String the uniquely identifies the service request.
     */
    const std::string id;
        
    /**
     * The name of the service, the port defined in the WSDL.
     */
    const std::string service;
    
    /**
     * The name of the service operation
     */
    const std::string operation;
    
    /**
     * The XML document making up the service reqeust or response.
     */
    const std::string& xmlDocument;     //lint !e1725 only use this while in scope of the current service request
    
    ServiceInfo( const std::string& id,        const std::string& service, 
          const std::string& operation, const std::string& xmlDocument );
    ~ServiceInfo(void){};

    SOA_CLASS_NEW_OPERATORS

private:
    static const std::string  omitXml;
    static std::map< unsigned long, std::string> icctMethods;
    static std::string extractICCTOperation( const std::string& operation, const std::string& xmlDocument );
    
    ServiceInfo( ); 

};

/**
 * This interface is used to framework to notify the client application when
 * a service request is sent or its response recieved.
 */
class TCSOACLIENTMNGD_API RequestListener
{
public:


    RequestListener(void){};
    virtual ~RequestListener(void){};

    /**
     * This method is called before every service request.
     * 
     * @param info  Information describing the service operation
     */
    virtual void serviceRequest ( const ServiceInfo& info ) = 0;
    
    /**
     * The method is called after the service response is recived.
     * 
     * @param info Information describing the service operation
     */
    virtual void serviceResponse( const ServiceInfo& info ) = 0;


};


}}}//end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

