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

#ifndef TEAMCENTER_SERVICES_CORE__2007_09_PROJECTLEVELSECURITY_HXX
#define TEAMCENTER_SERVICES_CORE__2007_09_PROJECTLEVELSECURITY_HXX

#include <teamcenter/soa/client/model/TC_Project.hxx>
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
            namespace _2007_09
            {
                class Projectlevelsecurity;

class TCSOACORESTRONGMNGD_API Projectlevelsecurity
{
public:

    struct AssignedOrRemovedObjects;

    /**
     * This structure holds the projects and workspace objects.
     */
    struct AssignedOrRemovedObjects
    {
        /**
         * A list of <b>TC_Project</b> objects  to which the the given set of workspace objects
         * need to be assigned or from which the objects need to be removed.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  > projects;
        /**
         * A list of objects that needs to be assigned ( added ) to the given projects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectToAssign;
        /**
         * A list of objects that needs to be removed  from the given projects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectToRemove;
    };




    /**
     * This operation assigns the given set of workspace objects to the given projects.
     * Similarly, it removes an additional set of given workspace objects from the same
     * set of given projects. If user is not privileged to assign objects to any of the
     * given projects then this operation will return the error 101014 : You have insufficient
     * privilege to assign object to a project. Similarly, if user is not privileged to
     * remove objects from any of the given projects then this operation will return error
     * 101015: You have insufficient privilege to remove object from a project.  These errors
     * will not terminate processing of rest of the objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param assignedOrRemovedobjects
     *        A list of AssignedOrRemovedObjects.
     *
     * @return
     *         This operation returns a standard  ServiceData. The updated list of objects will
     *         be added into the servicedata as updated list of objects and errors such as:
     *         <br>
     *         <ul>
     *         <li type="disc">101014 : You have insufficient privilege to assign object to a project
     *         </li>
     *         <li type="disc">101015: You have insufficient privilege to remove object from a project
     *         </li>
     *         </ul>
     *         <br>
     *         Are returned.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData assignOrRemoveObjects ( const std::vector< Teamcenter::Services::Core::_2007_09::Projectlevelsecurity::AssignedOrRemovedObjects >& assignedOrRemovedobjects ) = 0;


protected:
    virtual ~Projectlevelsecurity() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

