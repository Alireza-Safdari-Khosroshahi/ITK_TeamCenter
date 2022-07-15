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

#ifndef TEAMCENTER_SERVICES_CORE_PROJECTLEVELSECURITYSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_PROJECTLEVELSECURITYSERVICE_HXX

#include <teamcenter/services/core/_2007_09/Projectlevelsecurity.hxx>
#include <teamcenter/services/core/_2009_04/Projectlevelsecurity.hxx>
#include <teamcenter/services/core/_2009_10/Projectlevelsecurity.hxx>
#include <teamcenter/services/core/_2012_09/Projectlevelsecurity.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class ProjectlevelsecurityService;

/**
 * This service provides operations that are mainly used to accomplish Project Administration
 * Application and Smart Navigator related use cases.  Project Administration Application
 * provides the functionality to manage <b>TC_Project </b>objects. <b>TC_project</b>
 * creation, modification, copying and deletion are the main operations that are supported,
 * besides providing a way to manage team members and manage their membership status
 * like privileged, non-privileged and team administrators. This service also provides
 * operations to assign objects to projects and remove  objects from  projects.  The
 * following are list of supported actions by the project level security service.
 * <br>
 * <ul>
 * <li type="disc">Creation of a <b>TC_Project </b>or list of<b> TC_Project</b> objects.
 * </li>
 * <li type="disc">Modification of a <b>TC_Project</b> or list of <b>TC_Project</b>
 * objects.
 * </li>
 * <li type="disc">Copying of <b>TC_Project</b> or list of <b>TC_Project</b> objects.
 * </li>
 * <li type="disc">Deletion of <b>TC_Project</b> or list of <b>TC_Project</b> objects.
 * </li>
 * <li type="disc">Getting team members of a <b>TC_Project</b> or list of <b>TC_Project</b>
 * objects.
 * </li>
 * <li type="disc">Assignment of objects to a <b>TC_Project</b> or list of <b>TC_Project</b>
 * objects.
 * </li>
 * <li type="disc">Removal of objects from a <b>TC_Project </b>or list of <b>TC_Project</b>
 * objects.
 * </li>
 * <li type="disc">Enabling user or list of users to set their default projects
 * </li>
 * <li type="disc">Enabling users to get configuration of Smart folders for displaying
 * projects in hierarchical manner which is configured by an administrator.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API ProjectlevelsecurityService
    : public Teamcenter::Services::Core::_2007_09::Projectlevelsecurity,
             public Teamcenter::Services::Core::_2009_04::Projectlevelsecurity,
             public Teamcenter::Services::Core::_2009_10::Projectlevelsecurity,
             public Teamcenter::Services::Core::_2012_09::Projectlevelsecurity
{
public:
    static ProjectlevelsecurityService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation returns the list of  <b>TC_Project</b> objects for each of  the users
     * in the input structure based on the additional criteria like active projects only,
     * user privileged projects only and programs only. The output for this operation is
     * a UserProjectsInfoResponse structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param userProjectsInfoInputs
     *        A list of UserProjectsInfoInput structures.
     *
     * @return
     *         This operation returns a UserProjectsInfoResponse structure. Any error that occurred
     *         while finding the projects for the given user is added to the error list in ServiceData
     *         object against the user object.
     *
     */
    virtual Teamcenter::Services::Core::_2009_10::Projectlevelsecurity::UserProjectsInfoResponse getUserProjects ( const std::vector< Teamcenter::Services::Core::_2009_10::Projectlevelsecurity::UserProjectsInfoInput >& userProjectsInfoInputs ) = 0;

    /**
     * This operation copies  the given list of <b>TC_Project</b> objects. The operation
     * also copies any information which is in contained in the project. Data such as project
     * team members and any objects assigned to the source project will also be copied to
     * the new project. If a project with given project ID exists in the system then this
     * operation will return error 101010.  The operation will continue with copying the
     * other projects.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param copyProjectsInfos
     *        A list of CopyProjectsInfo structures.
     *
     * @return
     *         This operation returns a ProjectOpsOutput structure.
     *
     */
    virtual Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectOpsResponse copyProjects ( const std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::CopyProjectsInfo >& copyProjectsInfos ) = 0;

    /**
     * This operation creates <b>TC_Project</b> objects using the given input information.
     * If the project with given project ID exists in the system then this operation will
     * return unique id violation error 101010.  However, creation of rest of the projects
     * will continue.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param projectInfos
     *        A list of ProjectInformation objects.
     *
     * @return
     *         This operation returns a ProjectOpsOutput structure.
     *
     */
    virtual Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectOpsResponse createProjects ( const std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectInformation >& projectInfos ) = 0;

    /**
     * This operation returns team members for the given list of <b>TC_Project</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param projectObjs
     *        A list of ProjectClientId structures one for each of the given projects.
     *
     * @return
     *         This operation returns a ProjectTeamsResponse structure. Any partial errors that
     *         occur while getting the team for any given project will be returned in the error
     *         list in ServiceData against the unique client id given as input.
     *
     */
    virtual Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectTeamsResponse getProjectTeams ( const std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectClientId >& projectObjs ) = 0;

    /**
     * This operation modifies the given list of <b>TC_Project</b> objects using the given
     * input. This operation will not modify the project ID and project name. Rest of the
     * project properties can be modified using this operation. If project ID and name are
     * specified this operation will ignore them.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Project Level Security Admistration - Provide the a mechanism for organizing data
     * and implementing access control based on project membership. Data assigned to projects
     * can be searched for and viewed in the context of the project and can be distributed
     * across multiple sites.
     *
     * @param modifyProjectsInfos
     *        Vector of ModifyProjectsInfo structures.
     *
     * @return
     *         This operation returns a ProjectOpsOutput structure.
     *
     */
    virtual Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectOpsResponse modifyProjects ( const std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ModifyProjectsInfo >& modifyProjectsInfos ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProjectlevelsecurityService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

