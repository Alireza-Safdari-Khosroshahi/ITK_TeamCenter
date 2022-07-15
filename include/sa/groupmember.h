/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all the functions to be used
    by clients of the GroupMember class which is part of the System
    Administration module of Teamcenter Engineering.
 
    <b>Restrictions:</b>
  
    This include file should not generally be used by anyone.
    Normally sa.h or groupmember.hxx should be included instead.
*/

/*  */

#ifndef GROUPMEMBER_H
#define GROUPMEMBER_H

#include <pom/pom/pom.h>
#include <sa/libsa_exports.h>

/**
    @defgroup GROUPMEMBER Group Member
    @ingroup SA

    @note
    <OL>
    <LI>If the login user is NOT a System Administrator or a Group Administrator,
        then these functions find and return only active groupmembers.
    <LI>If the login user is a System Administrator or a Group Administrator and
        the preference TC_suppress_inactive_group_members is set to 1,
        then these functions find and return only active groupmembers.
    <LI>If the login user is a System Administrator or a Group Administrator and
        the preference TC_suppress_inactive_group_members is set to 0,
        then these functions find and return both active and inactive groupmembers.
    </OL>

    These functions may return members that are inactive users;
    call #SA_find_groupmembers_by_accessor if you are only interested in active users

    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
    Allocates an array of tags and stores in the array all groupmembers in the database.
    The client is responsible for deallocating the array of member_tags.
    Use #MEM_free to free the memory pointed to by member_tags.
*/
extern SA_API int SA_extent_groupmember(
    int*          num_of_groupmembers,  /**< (O) Stores the size of the array */
    tag_t**       member_tags           /**< (OF) num_of_groupmembers Points to the array of tags */
    );

/**
    Allocates an array of tags and stores in the array all active groupmembers in the database.
    The client is responsible for deallocating the array of member_tags.
    Use #MEM_free to free the memory pointed to by member_tags.
*/
extern SA_API int SA_extent_active_groupmember(
    int*          num_of_activegroupmembers,    /**< (O) Stores the size of the array */
    tag_t**       member_tags                   /**< (OF) num_of_activegroupmembers Points to the array of tags */
    );

/**
    Initializes a GroupMember object. 
    It is not saved to the database until an explicit call to POM_save occurs. 
    You must specify the member_tag, group_tag, user_tag and the group administration attributes.
    The group_admin_flag attribute indicates if the group member is to be the group administrator 
    (true for group administrator, false if not).
    Setting the group administrator attribute to true without having system administration privileges results in an error.

    You normally use this function with a subclass of GroupMember.
    For example, if you defined a class special GroupMember, 
    you would first call #POM_create_instance to create the object in memory.
    Then you would use this function to initialize the attributes which were inherited from GroupMember.
    Finally, you would use additional POM calls to initialize the attributes comprising your specialization of GroupMember.

    <b>Restrictions:</b>

    You can only access this function when logged in as a system or group administrator.
*/
extern SA_API int SA_initialize_groupmember(
    tag_t         member_tag,       /**< (I) */
    tag_t         group_tag,        /**< (I) */
    tag_t         user_tag,         /**< (I) */
    logical       group_admin_flag  /**< (I) */
    );

/**
    Creates a GroupMember object. It is not saved to the database until an explicit call to #AOM_save is made.
    You must specify a member_tag, group_tag, user_tag, and the group administration attributes.

    The group_admin_flag attribute indicates if the group member is to be the group administrator
    (true for group administrator, false if not).
    Setting the group administrator attribute to true without having system administration privileges results in an error.

    <b>Restrictions:</b>

    You can only access this function when logged in as a system or group administrator.
*/
extern SA_API int SA_create_groupmember(
    tag_t         group_tag,            /**< (I) */
    tag_t         user_tag,             /**< (I) */
    logical       group_admin_flag,     /**< (I) */
    tag_t*        member_tag            /**< (O) */
    );

/**
    Returns the user tag attribute for this group member.
*/
extern SA_API int SA_ask_groupmember_user(
    tag_t         member_tag,   /**< (I) */
    tag_t*        user_tag      /**< (O) */
    );

/**
    Returns the group tag attribute for this group member.
*/
extern SA_API int SA_ask_groupmember_group(
    tag_t         member_tag,   /**< (I) */
    tag_t*        group_tag     /**< (O) */
    );

/**
    Returns the group administration attribute for this group member. 
    The group_admin_flag attribute indicates if the group member is to be the group administrator
    (true for group administrator, false if not).
*/
extern SA_API int SA_ask_groupmember_group_priv(
    tag_t         member_tag,           /**< (I) */
    logical*      group_admin_flag      /**< (O) */
    );

/**
    Returns the role tag attribute for this group member.
*/
extern SA_API int SA_ask_groupmember_role(
    tag_t         member_tag,   /**< (I) */
    tag_t*        role_tag      /**< (O) */
    );

/**
    Sets the user_tag attribute for the group member.
*/
extern SA_API int SA_set_groupmember_user(
    tag_t         member_tag,   /**< (I) */
    tag_t         user_tag      /**< (I) */
    );

/**
    Sets the group_tag attribute for the group member.
*/
extern SA_API int SA_set_groupmember_group(
    tag_t         member_tag,   /**< (I) */
    tag_t         group_tag     /**< (I) */
    );

/**
    Sets the group_admin_flag attribute for the group member.
    The group_admin_flag attribute indicates if the group member is to be the group administrator
    (true for group administrator, false if not).
    Setting the group_admin_flag attribute to true without having 
    system administration privileges returns an integer error code.
*/
extern SA_API int SA_set_groupmember_group_priv(
    tag_t         member_tag,       /**< (I) */
    logical       group_admin_flag  /**< (I) */
    );

/**
    Sets the role_tag attribute for the group member.

    <b>Restrictions:</b>

    You can only access these functions when logged in as a system or group administrator.
*/
extern SA_API int SA_set_groupmember_role(
    tag_t         member_tag,   /**< (I) */
    tag_t         role_tag      /**< (I) */
    );

/**
    Finds all groupmembers with the specified group and user tags.
    If an error occurs, then a non-zero integer returns.
    If no GroupMember exists with the specified group and user tags, 
    then a zero returns and a #NULLTAG is given for the groupmember tag.
*/
extern SA_API int SA_find_groupmembers(
    tag_t         user_tag,     /**< (I) */
    tag_t         group_tag,    /**< (I) */
    int*          n_members,    /**< (O) */
    tag_t**       member_tags   /**< (OF) n_members */
    );

/**
    Allocates an array of tags and stores in the array all group members of the specified group.
    The client is responsible for deallocating the array of member_tags. 
    Use #MEM_free to free the memory pointed to by member_tags.
*/
extern SA_API int SA_find_groupmembers_by_group(
    tag_t         group_tag,        /**< (I) */
    int*          num_of_members,   /**< (O) Stores the size of the array */
    tag_t**       member_tags       /**< (OF) num_of_members Points to the array of tags */
    );

/**
    Allocates an array of tags and stores in the array all group members who reference the specified user.
    The client is responsible for deallocating the array of member_tags.
    Use #MEM_free to free the memory pointed to by member_tags.
*/
extern SA_API int SA_find_groupmember_by_user(
    tag_t         user_tag,         /**< (I) */
    int*          num_of_members,   /**< (O) Stores the size of the array */
    tag_t**       member_tags       /**< (OF) num_of_members Points to the array of tags */
    );

/**
    Retrieves all the group members which are referenced by the specified @p user.
    <br/>Group members are filtered on the basis of the @p include_inactive flag.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SA_Invalid_User if the provided user is invalid.
    <li>#SA_finding_all_groupmember_by_user if the query has failed to execute
    </ul>
*/
extern SA_API int SA_find_all_groupmember_by_user(
    tag_t         user,              /**< (I) User tag references the group members */
    logical       include_inactive,  /**< (I) Filters the active/inactive group members. 
                                              <br>Valid values are: 
                                              <ul> 
                                              <li>true: all (active and inactive) group members are retrieved.
                                              <li>false: only active group members are retrieved.
                                              </ul>*/
    int*          num_of_members,    /**< (O) The number of values in members array */
    tag_t**       members            /**< (OF) num_of_members The array of tags */
    );

/**
    Allocates an array of tags and stores in the array all group members of a given group and role tag.
    member_tags points to the array of tags.
    num_of_members stores the size of the array.
    The client is responsible for deallocating the array of member_tags. 
    Use #MEM_free to free the memory pointed to by member_tags.
*/
extern SA_API int SA_find_groupmember_by_role(
    tag_t         role_tag,         /**< (I) */
    tag_t         group_tag,        /**< (I) */
    int*          num_of_members,   /**< (O) */
    tag_t**       member_tags       /**< (OF) num_of_members */
    );

/**
    Locates group member objects. 
    The caller may find the group members by role, group, user, or 
    any combination of the input parameters as shown in the synopsis. 
    As a result, this function passes the number of members found and an array of member tags. 
    It is the caller's responsibility to free the returned tags.

    The following are some examples of how this function may be used:
    <UL>
    <LI>To find members of a group with a certain role, 
        the caller must provide the group name and the role name to this function as a searching criteria.
        For the user_id parameter, the caller may enter a NULL string.
    <LI>To verify a user is a member of a group and having a certain role,
        the caller must provide the group_name, the role_name, and the user_id.
        If in fact, there is such a member, the function will return number_found and a list of members tags. 
    </UL>
*/
extern SA_API int SA_find_groupmember_by_rolename (
    const char*   role_name,        /**< (I) NULL allowed */
    const char*   group_name,       /**< (I) NULL allowed */
    const char*   user_id,          /**< (I) NULL allowed */
    int*          number_found,     /**< (O) */
    tag_t**       list              /**< (OF) number_found */
    );

/**
    Allocates an array of tags and stores in the array all groupmembers associated with the particular accessor tag.
    This accessor may be a user, a group, or a role. 

    The client is responsible for freeing the array of member_tags.
    Use #MEM_free to free the memory pointed to by member_tags.
*/
extern SA_API int SA_find_groupmembers_by_accessor(
    tag_t         accessor,         /**< (I) */
    int*          num_of_members,   /**< (O) Stores the size of the array */
    tag_t**       member_tags       /**< (OF) num_of_members Points to the array of tags */
    );

/**
    Retrieves the current groupmember tag of the logged-in user, based on the current group and role.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Potentially other errors
    </ul>
*/
extern SA_API int SA_ask_current_groupmember(
    tag_t*        current_groupmember_tag   /**< (O) The current group member */
    );

/**
    Checks if the group member is inactive. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag error if the parameter @p groupmember_tag is invalid.
    </ul>
*/
extern SA_API int SA_ask_groupmember_inactive(
    tag_t         groupmember_tag,  /**< (I) The group member which status is asked */
    logical*      is_deactivated    /**< (O) Status of the group member */
    );

/**
    Sets the status of the input groupmember to active or inactive.

    <b>Restrictions:</b>

    You can only access this function when logged in as a system or group administrator. 
*/
extern SA_API int SA_set_groupmember_inactive(
    tag_t         groupmember_tag,  /**< (I) */
    logical       deactivate        /**< (I) */
    );

extern SA_API int SA_is_groupmember_default_role(
    tag_t         groupmember_tag,                      /**< (I) */
    logical*      is_default_role                       /**< (O) */
    );

/**
    This function returns the default role in a group for a specified user.
    If the default role is not defined, a null tag will be returned.
*/
extern SA_API int SA_ask_default_role(
    tag_t         user_tag,     /**< (I) Tag of the user to find a role for */
    tag_t         group_tag,    /**< (I) Group to find the role in */
    tag_t*        role_tag      /**< (O) Default role tag */
    );

/**
    This function sets the default role in a group for a specified user.
*/
extern SA_API int SA_set_default_role(
    tag_t         user_tag,    /**< (I) user tag */
    tag_t         group_tag,   /**< (I) group tag */
    tag_t         role_tag     /**< (I) default role tag */
    );

/** 
    Finds group members with given group name, role name, user ID  and user name.
    <br/>At least one of the four input criteria should not be empy. If both the user ID and the user name are specified, 
    the group members that match either the user ID or the user name are returned.
    
    @note The entries in the parameters @p group_name, @p role_name, @p user_id and @p user_name are case-insensitive and 
    support the use of the wildcard character as defined by the preference "TC_pattern_match_style".
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SA_find_group_members_invalid_argument on invalid input arguments.
    <li>Possibly other POM errors
    </ul>
*/
extern SA_API int SA_find_group_members(
    const char*     group_name,       /**< (I) The group name of the group members. */
    const char*     role_name,        /**< (I) The role name of the group members.  */
    const char*     user_id,          /**< (I) The user ID of the group memebrs. */
    const char*     user_name,        /**< (I) The user name of the group members. */
    logical   include_inactive,       /**< (I) Flag to include inactive group members in the search. */
    logical   include_subgroups,      /**< (I) Flag to include group members from subgroups of matching groups in the search. */
    int*            number_found,     /**< (O) The number of group members*/
    tag_t**         members,          /**< (OF) number_found Found group members */
    tag_t**         groups,           /**< (OF) number_found Corresponding groups  */
    tag_t**         roles,            /**< (OF) number_found Corresponding roles  */
    tag_t**         users             /**< (OF) number_found Corresponding users  */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
