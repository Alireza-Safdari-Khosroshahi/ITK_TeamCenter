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

#ifndef TEAMCENTER_SERVICES_CORE__2009_10_PROJECTLEVELSECURITY_HXX
#define TEAMCENTER_SERVICES_CORE__2009_10_PROJECTLEVELSECURITY_HXX

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
            namespace _2009_10
            {
                class Projectlevelsecurity;

class TCSOACORESTRONGMNGD_API Projectlevelsecurity
{
public:

    struct ProjectInfo;
    struct UserProjectsInfo;
    struct UserProjectsInfoInput;
    struct UserProjectsInfoResponse;

    /**
     * This structure holds the TC_Project and a flag indicating the user's membership type.
     */
    struct ProjectInfo
    {
        /**
         * The <b>TC_Project</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  project;
        /**
         * Flag indicating if the given  user is a privleged  member.
         */
        bool isUserPrivileged;
    };

    /**
     * This structure holds the projects for one of the given users.
     */
    struct UserProjectsInfo
    {
        /**
         * The <b>User</b> object of Teamcenter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * Flag to indicate the status of projects  returned True indicates only active projects
         * are returned. False indicates both active and inactive projects are returned.
         */
        bool activeProjectsOnly;
        /**
         * Flag to indicate if returned projects  are privleged or not.True indicates projects
         * are privileged, false indicates all projects where the user is a member of regardless
         * of privilege in the projects.
         */
        bool privilegedProjectsOnly;
        /**
         * Flag Indicating if user wants to get program only pojects of the user, false indicates
         * returning all projects where regardless of status program only  value of <b>TC_Project</b>.
         */
        bool programsOnly;
        /**
         * An id associated with a client.
         */
        std::string clientId;
        /**
         * A list of ProjectInfo structure.
         */
        std::vector< Teamcenter::Services::Core::_2009_10::Projectlevelsecurity::ProjectInfo > projectsInfo;
    };

    /**
     * This structure holds the User object and criteria to find the user projects.
     */
    struct UserProjectsInfoInput
    {
        /**
         * The <b>User</b> object of Teamcenter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * Flag Indicating if user wants to get active projects or
         * <br>
         * not.True indicates return only active projects of the user, false indicates return
         * both active and inactive projects of the user.
         */
        bool activeProjectsOnly;
        /**
         * Flag Indicating if user wants to get privleged projects
         * <br>
         * or not.True indicates return privileged projects of the user, false indicates return
         * all projects where the user is a member of regardless of status.
         */
        bool privilegedProjectsOnly;
        /**
         * Flag Indicating if user wants to get program only projects of the user, false indicates
         * return all projects regardless of status program only.
         */
        bool programsOnly;
        /**
         * An id associated with a client.
         */
        std::string clientId;
    };

    /**
     * This structure holds the projects for all the given users.
     */
    struct UserProjectsInfoResponse
    {
        /**
         * List of UserProjectsInfo structures one for each given user..
         */
        std::vector< Teamcenter::Services::Core::_2009_10::Projectlevelsecurity::UserProjectsInfo > userProjectInfos;
        /**
         * A  standard ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Projectlevelsecurity() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

