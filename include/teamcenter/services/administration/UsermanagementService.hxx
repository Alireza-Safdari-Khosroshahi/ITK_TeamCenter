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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION_USERMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION_USERMANAGEMENTSERVICE_HXX

#include <teamcenter/services/administration/_2007_01/Usermanagement.hxx>
#include <teamcenter/services/administration/_2012_09/Usermanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            class UsermanagementService;

/**
 * This service provides operations to manage <b>User</b> business objects and create
 * Discipline objects in Organization application. The User management functionality
 * enables administrators to create new users, modify existing users and delete users
 * as well as retrieving user information. Discipline creation functionality allows
 * system administrators to add new Discipline objects to the system. It currently supports
 * following operation:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Create new Discipline objects.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaadministrationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaadministrationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAADMINISTRATIONSTRONGMNGD_API UsermanagementService
    : public Teamcenter::Services::Administration::_2007_01::Usermanagement,
             public Teamcenter::Services::Administration::_2012_09::Usermanagement
{
public:
    static UsermanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates a list of new <b>Discipline</b> objects based on the list
     * of CreateDisciplineIn objects. If  parent group is specified in the CreateDisciplinesIn
     * object, the discipline objects would be added into the group. This operation requires
     * system administration or group administration privilege.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param disciplines
     *        A list of CreateDisciplinesIn objects to specify initial data for the new discipline
     *        objects and parent group. A new discipline object is created for each CreateDisciplinesIn
     *        object in the list.
     *
     * @return
     *         It returns a CreateDisciplinesResponse object which contains a list of CreateDisciplinesOutput
     *         objects one for each CreateDisciplinesIn object, and a ServiceData element. The newly
     *         created discipline objects are added to the created object list of the ServiceData
     *         as well. If the given discipline name in a CreateDisciplineIn object exists, it will
     *         return error message "The discipline name is used by another discipline (either its
     *         discipline name or translations)" with error code <b>10183</b>.  If the login user
     *         is not system administrator or group administrator, it will return error message
     *         "User is not a system administrator or a group administrator" with error code <b>10013</b>.
     *
     */
    virtual Teamcenter::Services::Administration::_2007_01::Usermanagement::CreateDisciplinesResponse createDisciplines ( const std::vector< Teamcenter::Services::Administration::_2007_01::Usermanagement::CreateDisciplinesIn >& disciplines ) = 0;

    /**
     * This operation retrieves information of all group members for a list of users specified
     * in the list of GetUserGroupMembersInputData inputs. The information includes Group
     * object, Role object, User object, status, group admin privilege, and default role
     * flag of the user group members. The returned results could contain information only
     * for the active group members of the user or both active and inactive group members
     * of the user depending on option includeInactive setting in GetUserGroupMembersInputData.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param inputObjects
     *        A list of GetUserGroupMembersInputData objects. Each GetUserGroupMembersInputData
     *        specifies the specified matching User object and option flag to include inactive
     *        group members.
     *
     * @return
     *         A list of group member information for each requested User object. The following
     *         partial errors may be returned. - 10214 The source User object is null. - 10034 Fails
     *         to get  group members for a given user.
     *
     *
     * @exception ServiceException
     *           If system errors occur.
     */
    virtual Teamcenter::Services::Administration::_2012_09::Usermanagement::GetUserGroupMembersResponse getUserGroupMembers ( const std::vector< Teamcenter::Services::Administration::_2012_09::Usermanagement::GetUserGroupMembersInputData >& inputObjects ) = 0;

    /**
     * This operation updates the properties on one or more GroupMembers.The following properties
     * may be updated: membership_data_source, ga,default_role, status.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param inputObjects
     *        A list of GroupMember objects and the desired property values.
     *
     * @return
     *         The modified GroupMember objects are returned in the Updated list of the ServiceData.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setGroupMemberProperties ( const std::vector< Teamcenter::Services::Administration::_2012_09::Usermanagement::GroupMemberInput >& inputObjects ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UsermanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/administration/Administration_undef.h>
#endif

