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

#ifndef TEAMCENTER_SERVICES_CORE__2009_04_PROJECTLEVELSECURITY_HXX
#define TEAMCENTER_SERVICES_CORE__2009_04_PROJECTLEVELSECURITY_HXX

#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
#include <teamcenter/soa/client/model/TC_Project.hxx>
#include <teamcenter/soa/client/model/User.hxx>


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
            namespace _2009_04
            {
                class Projectlevelsecurity;

class TCSOACORESTRONGMNGD_API Projectlevelsecurity
{
public:

    struct LoadProjectDataForUserResponse;

    /**
     * Object that holds applicable projects.
     */
    struct LoadProjectDataForUserResponse
    {
        /**
         * List of <b>TC_project</b> objects found.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  > applicableProjects;
        /**
         * A  standard  ServicData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation returns list of projects for a given user, group and role combination.
     * If no group and role is specified it obtains all the projects for the specified user.
     * If any of the arguments passed are invalid an error is returned by the operation
     * added as a partial error.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param user
     *        The <b>User</b> object.
     *
     * @param group
     *        The <b>Group</b> object in which the user belongs to.
     *
     * @param role
     *        The <b>Role</b> object in which the user belongs to.
     *
     * @return
     *         This operation returns a LoadProjectDataForUserResponse structure. Any error that
     *         occurred while finding the projects for the given arguments is added to the sandard
     *         ServiceData object.
     *
     */
    virtual Teamcenter::Services::Core::_2009_04::Projectlevelsecurity::LoadProjectDataForUserResponse loadProjectDataForUser ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  role ) = 0;


protected:
    virtual ~Projectlevelsecurity() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

