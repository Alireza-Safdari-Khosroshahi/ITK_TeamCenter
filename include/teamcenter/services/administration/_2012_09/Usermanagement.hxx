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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2012_09_USERMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2012_09_USERMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/GroupMember.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
#include <teamcenter/soa/client/model/User.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            namespace _2012_09
            {
                class Usermanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Usermanagement
{
public:

    struct GetUserGroupMembersInputData;
    struct GetUserGroupMembersOutput;
    struct GetUserGroupMembersResponse;
    struct GroupMemberInput;
    struct RoleUser;
    struct UserGroupMemberData;

    /**
     * A map of property names and desired values (string/string).
     */
    typedef std::map< std::string, std::vector< std::string > > GroupMemberPropValuesMap;

    /**
     * This structure holds the input data to retrieve the group member information of a
     * given user.
     */
    struct GetUserGroupMembersInputData
    {
        /**
         * The given user object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * The option flag to include inactive group memers in returned group members data.
         */
        bool includeInactive;
        /**
         * The option flag to include User objects in returned group member data.
         */
        bool includeUser;
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
    };

    /**
     * This structure holds all user group member data for a given user.
     */
    struct GetUserGroupMembersOutput
    {
        /**
         * Unmodified value from the GetUserGroupMembersInputData.clientId. This can be used
         * by the caller to indentify this data structure with the source input data.
         */
        std::string clientId;
        /**
         * All user group member data for a specific user.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Usermanagement::UserGroupMemberData > memebrs;
    };

    /**
     * A list of user group members outputs, one for each of the given User object.
     */
    struct GetUserGroupMembersResponse
    {
        /**
         * List of group member information, one for each User object.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Usermanagement::GetUserGroupMembersOutput > outputs;
        /**
         * The object which holds the partial errors that occurred during retrieving user group
         * member data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds a GroupMember object, whose properties need to be updated and
     * a map of property names and their corresponding values.
     */
    struct GroupMemberInput
    {
        /**
         * The GroupMember business object whose propeties  need to be updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GroupMember>  groupMember;
        /**
         * A map of  property names and desired value(string/string).
         */
        GroupMemberPropValuesMap groupMemberPropValuesMap;
    };

    /**
     * This structure holds role, user, group member status, default role flag and group
     * admin privilege for a group member.
     */
    struct RoleUser
    {
        /**
         * The Role of a group member.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  role;
        /**
         * The User of a group member.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * True if the group member is active.
         */
        bool isActive;
        /**
         * True if the this Role is the default in the group member.
         */
        bool isDefaultRole;
        /**
         * True if the group member has administrative privilege
         */
        bool isGroupAdmin;
    };

    /**
     * This structure holds the all group member data under a group for the given user.
     */
    struct UserGroupMemberData
    {
        /**
         * The group of the group members in the RoleUser list.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group;
        /**
         * The list of RoleUser objects which belong to the same group.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Usermanagement::RoleUser > roleUsers;
    };




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


protected:
    virtual ~Usermanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

