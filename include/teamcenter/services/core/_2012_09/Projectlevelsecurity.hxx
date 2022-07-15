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

#ifndef TEAMCENTER_SERVICES_CORE__2012_09_PROJECTLEVELSECURITY_HXX
#define TEAMCENTER_SERVICES_CORE__2012_09_PROJECTLEVELSECURITY_HXX

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
            namespace _2012_09
            {
                class Projectlevelsecurity;

class TCSOACORESTRONGMNGD_API Projectlevelsecurity
{
public:

    struct ProjectInformation;
    struct CopyProjectsInfo;
    struct ModifyProjectsInfo;
    struct ProjectClientId;
    struct ProjectOpsOutput;
    struct ProjectOpsResponse;
    struct ProjectTeamData;
    struct ProjectTeamsResponse;
    struct TeamMemberInfo;

    /**
     * Structure that holds the information required to create the destination project.
     */
    struct ProjectInformation
    {
        /**
         * The project ID of  the project  to be created.
         */
        std::string projectId;
        /**
         * The name of the project to be created.
         */
        std::string projectName;
        /**
         * The description of the project to be created.
         */
        std::string projectDescription;
        /**
         * The value of <b>useProgramContext</b> attribute on <b>TC_Project</b>.
         */
        bool useProgramContext;
        /**
         * The value of active attribute on <b>TC_Project</b>.
         */
        bool active;
        /**
         * The value of visible attribute on <b>TC_Project</b>.
         */
        bool visible;
        /**
         * A list of TeamMemberInfo structures.
         */
        std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::TeamMemberInfo > teamMembers;
        /**
         * Unique identifier used by the client to track any errors.
         */
        std::string clientId;
    };

    /**
     * Structure that holds project information required to create a new <b>TC_Project </b>object
     * using this operation.
     */
    struct CopyProjectsInfo
    {
        /**
         * The <b>TC_Project</b> of  a project  to be copied.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  sourceProject;
        /**
         * A ProjectInformation structure containing the destination project details..
         */
        Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectInformation projectInfo;
        /**
         * Unique identifier used by the client to track any errors.
         */
        std::string clientId;
    };

    /**
     * This structure holds the <b>TC_Project</b> object and the information required to
     * modify the project.
     */
    struct ModifyProjectsInfo
    {
        /**
         * The <b>TC_Project</b> object  to be modified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  sourceProject;
        /**
         * A ProjectInformation structure.
         */
        Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectInformation projectInfo;
        /**
         * Unique identifier for the client to track any errors.
         */
        std::string clientId;
    };

    /**
     * This structure holds <b>TC_Project </b>object and corresponding client id.
     */
    struct ProjectClientId
    {
        /**
         * The <b>TC_Project</b> object whose team members need to be retrieved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  tcProject;
        /**
         * Unique identifier used by the client to track any errors.
         */
        std::string clientId;
    };

    /**
     * Structure that holds the <b>TC_Project </b>object.
     */
    struct ProjectOpsOutput
    {
        /**
         * The created <b>TC_Project</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  project;
        /**
         * Unique identifier used by the client to track any errors.
         */
        std::string clientId;
    };

    /**
     * Response from the project create, modify operations.
     */
    struct ProjectOpsResponse
    {
        /**
         * Vector of ProjectOpsOuput objects.
         */
        std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectOpsOutput > projectOpsOutputs;
        /**
         * Service data with the partial error information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds team member information for a single project.
     */
    struct ProjectTeamData
    {
        /**
         * The <b>TC_Project</b> object for which team members are obtained.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  project;
        /**
         * A list of non privileged members of the given project.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > regularMembers;
        /**
         * A  list of project team adminstrators of the given project.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > projectTeamAdmins;
        /**
         * A list of privileged members of the given project.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > privMembers;
    };

    /**
     * This structure holds team member information for all the given projects.
     */
    struct ProjectTeamsResponse
    {
        /**
         * List of ProjectTeamData objects one for each of the given projects.
         */
        std::vector< Teamcenter::Services::Core::_2012_09::Projectlevelsecurity::ProjectTeamData > projectTeams;
        /**
         * A standard ServiceData object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A structure contains team member information and their status.
     */
    struct TeamMemberInfo
    {
        /**
         * The team member of a project.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  teamMember;
        /**
         * A value indicating Team member status .  Valid values are 0,1 and 2. 0 = non prvilged
         * member, 1= privilged member and 2 = Project team adminstrator.
         */
        int teamMemberType;
    };




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


protected:
    virtual ~Projectlevelsecurity() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

