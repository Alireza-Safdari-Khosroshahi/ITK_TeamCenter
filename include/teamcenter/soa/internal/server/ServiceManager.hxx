/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_SERVICE_MANAGER_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_SERVICE_MANAGER_HXX

#include <vector>
#include <string>
#include <map>
#include <teamcenter/soa/server/SoaServerExports.h>



namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {


class  TCSOASERVER_API ServiceManager
{
public:
    static ServiceManager& instance(); // it's a singleton

    //Let the registerService return the registeredService. this will used
    //to assign to a static string in the Skelton to ensure it is called
    //when a particular skelton is defined (equivalent to static block in java)
    std::string registerService( const std::string& serviceName);
    const std::vector <std::string>& getServiceList() const;


private:
    ServiceManager(); //ensure everyone accesses it via method instance()
    std::vector<std::string> serviceList;


};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
