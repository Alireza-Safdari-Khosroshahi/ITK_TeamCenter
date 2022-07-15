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

#ifndef TEAMCENTER_SERVICES_CORE__2008_05_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2008_05_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2008_05
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:





    /**
     * This operation unloads Business Objects. If input contains one or more Business Objects
     * then it will call AOM_unload for each object otherwise it will call unloadAll  to
     * unload all the objects.
     * <br>
     * <br>
     * Note that unloadAll will unload both C++ along with POM objects.
     * <br>
     *
     * @param objsToUnload
     *        A list of model objects to unload.
     *
     * @return
     *         It will return partial error if any.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData unloadObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objsToUnload ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

