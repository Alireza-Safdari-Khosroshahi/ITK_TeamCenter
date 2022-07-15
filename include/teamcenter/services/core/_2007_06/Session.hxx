/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_CORE__2007_06_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2007_06_SESSION_HXX



#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2007_06
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:





    /**
     * By Default the service operations will retrieve property value data straight from
     * the POM. When <code>refresh</code> is set to true, a refresh will be done on business
     * objects before getting any property data. This will update the POM with fresh data
     * from the database. The refresh is only applied to business objects that are actually
     * being returned by a service operation. This applies only to database objects, and
     * is not applied to runtime objects.  This is applied to all subsequent service requests
     * from the same client. If multiple clients are sharing the same Teamcenter server
     * session the refresh POM state is applied per client. Setting this to true will have
     * a performance impact but will grantee all property values returned are up-to-date.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param refresh
     *        If true, the business objects are refreshed before getting property values, if false
     *        the properties are retrieved from the POM without checks to the database.
     *
     * @return
     *         True is always returned.
     *
     */
    virtual bool refreshPOMCachePerRequest ( bool refresh ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

