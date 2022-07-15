// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2009.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 
/** 
    @file 
 
    SOA C++ Performance Monitor
 
*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PERFORMANCEMONITOR_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PERFORMANCEMONITOR_HXX


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

/**
 */
class  TCSOASERVER_API PerformanceMonitor
{
public: 
 


    virtual std::string invokeMethod( const std::string& method, const std::string& xmlIn );
    virtual void initialize();



protected:

    std::map< std::string, std::string (*)( const std::string& xmlIn ) > _svcMap;
    std::string m_serviceName;


};    // End Class

}}}}    // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif

