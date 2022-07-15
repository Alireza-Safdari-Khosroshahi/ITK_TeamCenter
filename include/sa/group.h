/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all the functions to be used
    by clients of the Group class which is part of the System
    Administration module of Teamcenter Engineering.

    <b>Restrictions:</b>

    This include file should not generally be used by anyone.
    Normally sa.h or group.hxx should be included instead.
*/

/*  */

#ifndef GROUP_H
#define GROUP_H

#include <unidefs.h>
#include <sa/sa.h>

#include <sa/libsa_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup GROUP Group
    @ingroup SA
    @{
*/

/**
    Allocates an array of tags, and stores in the array all groups in the database.
    group_tags points to the array of tags. num_of_groups stores the size of the array.
    The client is responsible for deallocating the array of group_tags.
    Use #MEM_free to free the memory pointed to by group_tags.
*/
extern SA_API int SA_extent_group(
    int*          num_of_groups,    /**< (O) */
    tag_t**       group_tags        /**< (OF) num_of_groups */
    );

/**
    Initializes a group. To save it to the database, call AOM_save().

    @note The name is forced to lower case before being set.

    <b>Restrictions:</b>

    You must be logged in as a Teamcenter Engineering system administrator to use this function.

    <b>Return Values:</b>

    #POM_invalid_value - Invalid privilege, must be 0 or 1.
*/
extern SA_API int SA_initialize_h_group(
    tag_t         group_tag,        /**< (I) The group to initialize */
    const char*   groupname,        /**< (I) The group's new name */
    int           privilege,        /**< (I) The group's new SA privilege (1 if it is an SA group, 0 if not) */
    tag_t         parent_group      /**< (I) */
    );

/**
    Creates a new group (an instance of the class "Group"). To save it to the database, call AOM_save().

    @note The name is forced to lower case before being set.

    <b>Restrictions:</b>

    You must be logged in as a Teamcenter Engineering system administrator to use this function.

    <b>Return Values:</b>

    #POM_invalid_value - Invalid privilege, must be 0 or 1.
*/
extern SA_API int SA_create_h_group(
    const char*   groupname,        /**< (I) The new group's name */
    int           privilege,        /**< (I) The new group's SA privilege (1 if it is an SA group, 0 if not) */
    tag_t         parent_group,     /**< (I) */
    tag_t*        group_tag         /**< (O) The new group */
    );


/**
    Sets the name attribute of the group.
*/
extern SA_API int SA_set_group_name2(
    tag_t         group_tag,                        /**< (I) */
    const char    *groupname                        /**< (I) */
    );

/**
    Sets the description attribute of the group.
*/
extern SA_API int SA_set_group_description2(
    tag_t         group_tag,                                /**< (I) */
    const char    *description                              /**< (I) */
    );

/**
    Sets the system privilege attribute of the group. Valid inputs for privilege are:
    <UL>
    <LI>0 - for user privileges
    <LI>1 - for system administration privileges
    </UL>

    If privilege is set to 1, the group is a system administration group.
    You must be logged in as a user belonging to a group that has system administration privileges to set privilege to 1.
    Otherwise, you will receive an error.
*/
extern SA_API int SA_set_group_system_priv(
    tag_t         group_tag,    /**< (I) */
    int           privilege     /**< (I) */
    );

extern SA_API int SA_set_group_parent(
    tag_t         group_tag,        /**< (I) */
    tag_t         parent_group      /**< (I) */
    );

/**
    Sets the default volume name attribute for the group.
*/
extern SA_API int SA_set_group_volume_name2(
    tag_t         group_tag,                            /**< (I) */
    const char    *volume_name                          /**< (I) */
    );


/**
    Sets the default local volume name attribute for the group.
*/
extern SA_API int SA_set_group_local_volume_name2(
    tag_t         group_tag,                            /**< (I) */
    const char    *volume_name                          /**< (I) */
    );

/*
    Sets the organization_name attribute of the group.
*/
extern SA_API int SA_set_group_organization_name2(
    tag_t         group_tag,                                            /**< (I) */
    const char    *organization_name                                    /**< (I) */
    );


/**
    Sets the organization_id attribute of the group.
*/
extern SA_API int SA_set_group_organization_id2(
    tag_t         group_tag,                                        /**< (I) */
    const char    *organization_id                                  /**< (I) */
    );


/**
    Sets the organization_type attribute of the group.
*/
extern SA_API int SA_set_group_organization_type2(
    tag_t         group_tag,                                            /**< (I) */
    const char    *organization_type                                    /**< (I) */
    );


/**
    Sets the organization_legal_name attribute of the group.
*/
extern SA_API int SA_set_group_organization_legal_name2(
    tag_t         group_tag,                                                        /**< (I) */
    const char    *organization_legal_name                                          /**< (I) */
    );


/**
    Sets the organization_alternate_name attribute of the group.
*/
extern SA_API int SA_set_group_organization_alternate_name2(
    tag_t         group_tag,                                                                /**< (I) */
    const char    *organization_alternate_name                                              /**< (I) */
    );


/**
    Sets the organization_address attribute of the group.
*/
extern SA_API int SA_set_group_organization_address2(
    tag_t         group_tag,                                                  /**< (I) */
    const char    *organization_address                                       /**< (I) */
    );

/**
    Sets the organization_url attribute of the group.
*/
extern SA_API int SA_set_group_organization_url2(
    tag_t         group_tag,                                          /**< (I) */
    const char    *organization_url                                   /**< (I) */
    );

/**
    Sets the operational_status attribute of the group.
*/
extern SA_API int SA_set_group_operational_status(
    tag_t         group_tag,            /**< (I) */
    int           operational_status    /**< (I) */
    );


/**
    Sets the nationality attribute of the group.
*/
extern SA_API int SA_set_group_nationality2(
    tag_t         group_tag,                                /**< (I) */
    const char    *nationality                              /**< (I) */
    );

/**
    Adds a role to the group.

    <b>Restrictions:</b>

    You can only access this function when logged in as a system or group administrator.
*/
extern SA_API int SA_add_role_to_group(
    tag_t         group_tag,    /**< (I) */
    tag_t         role_tag      /**< (I) */
    );

/**
    Removes a role from the group.

    <b>Restrictions:</b>

    You can only access this function when logged in as a system or group administrator.
*/
extern SA_API int SA_remove_role_from_group(
    tag_t         group_tag,    /**< (I) */
    tag_t         role_tag      /**< (I) */
    );

/**
    Finds a group with the specified full name.
    If an error occurs, then a non-zero integer returns.
    If no Group exists with the specified name,
    then a zero returns on the stack and a #NULLTAG returns for the group tag.
*/
extern SA_API int SA_find_group(
                                const char*   groupname,                        /**< (I) */
                                tag_t*        group_tag                         /**< (O) */
                                );


/**
   Retrieves the name attribute for this group.
*/
extern SA_API int SA_ask_group_name2(
    tag_t         group_tag,                        /**< (I) */
    char          **groupname                       /**< (OF) */
    );

extern SA_API int SA_ask_group_full_name(
    tag_t         group_tag,        /**< (I) */
    char**        group_full_name   /**< (OF) */
    );

extern SA_API int SA_ask_group_localized_full_name(
    tag_t         group_tag,            /**< (I) */
    char**        group_loc_full_name   /**< (OF) */
    );

extern SA_API int SA_ask_group_display_name(
    tag_t         group_tag,            /**< (I) */
    char**        group_display_name    /**< (OF) */
    );


/**
   Retrieves the description attribute for this group.
*/
extern SA_API int SA_ask_group_description2(
    tag_t         group_tag,                                /**< (I) */
    char          **description                             /**< (OF) */
    );

/**
    Retrieves the system privilege attribute of the group. The output values for privilege are:
    <UL>
    <LI>0 - for user privileges
    <LI>1 - for system administration privileges
    </UL>
*/
extern SA_API int SA_ask_group_system_priv(
    tag_t         group_tag,    /**< (I) */
    int*          privilege     /**< (O) */
    );

extern SA_API int SA_ask_group_parent(
    tag_t         group_tag,    /**< (I) */
    tag_t*        parent        /**< (O) */
    );

extern SA_API int SA_ask_group_child_groups(
    tag_t         group_tag,    /**< (I) */
    logical       immediate_only,/**< (I) */ /* one-level or full expansion */
    int *         n_children,   /**< (O) */
    tag_t**       children      /**< (OF) n_children */
    );


/**
    Retrieves the default volume name attribute for the group.
*/
extern SA_API int SA_ask_group_volume_name2(
    tag_t         group_tag,                            /**< (I) */
    char          **volume_name                         /**< (OF) */
    );


/**
    Retrieves the default local volume name attribute for the group.
*/
extern SA_API int SA_ask_group_local_volume_name2(
    tag_t         group_tag,                            /**< (I) */
    char          **volume_name                         /**< (OF) */
    );


/**
    Retrieves the organization_name attribute of the group.
*/
extern SA_API int SA_ask_group_organization_name2(
    tag_t         group_tag,                                            /**< (I) */
    char          **organization_name                                   /**< (OF) */
    );


/**
    Retrieves the organization_id attribute of the group.
*/
extern SA_API int SA_ask_group_organization_id2(
    tag_t         group_tag,                                        /**< (I) */
    char          **organization_id                                 /**< (OF) */
    );


/**
    Retrieves the organization_type attribute of the group.
*/
extern SA_API int SA_ask_group_organization_type2(
    tag_t         group_tag,                                            /**< (I) */
    char          **organization_type                                   /**< (OF) */
    );

/**
    Retrieves the organization_legal_name attribute of the group.
*/
extern SA_API int SA_ask_group_organization_legal_name2(
    tag_t         group_tag,                                                        /**< (I) */
    char          **organization_legal_name                                         /**< (OF) */
    );



/**
    Retrieves the organization_alternate_name attribute of the group.
*/
extern SA_API int SA_ask_group_organization_alternate_name2(
    tag_t         group_tag,                                                                /**< (I) */
    char          **organization_alternate_name                                             /**< (OF) */
    );


/**
    Retrieves the organization_address attribute of the group.
*/
extern SA_API int SA_ask_group_organization_address2(
    tag_t         group_tag,                                                  /**< (I) */
    char          **organization_address                                      /**< (OF) */
    );


/**
    Retrieves the organization_url attribute of the group.
 */
extern SA_API int SA_ask_group_organization_url2(
    tag_t         group_tag,                                          /**< (I) */
    char          **organization_url                                  /**< (OF) */
    );

/**
    Retrieves the operational_status attribute of the group.
*/
extern SA_API int SA_ask_group_operational_status(
    tag_t         group_tag,            /**< (I) */
    int*          operational_status    /**< (O) */
    );


/**
    Retrieves the nationality attribute of the group.
*/
extern SA_API int SA_ask_group_nationality2(
    tag_t         group_tag,                                /**< (I) */
    char          **nationality                             /**< (OF) */
    );

/**
    Allocates an array of tags and stores in the array all roles of the specified group.
    role_tags points to the array of tags. num_of_roles stores the size of the array.
    The client is responsible for deallocating the array of role_tags.
    Use #MEM_free to free the memory pointed to by role_tags.
*/
extern SA_API int SA_ask_roles_from_group(
    tag_t         group_tag,        /**< (I) */
    int*          num_of_roles,     /**< (O) */
    tag_t**       role_tags         /**< (OF) num_of_roles */
    );

/**
    Retrieves the default role attribute of the group.

    When a user is assigned a default group,
    the user is automatically assigned the default role in that group.
*/
extern SA_API int SA_ask_group_default_role(
    tag_t         group_tag,    /**< (I) */
    tag_t*        role_tag      /**< (O) */
    );

/**
    Sets the default role attribute of the group.
    When a user is assigned a default group, the user is automatically assigned the default role in that group.

    <b>Restrictions:</b>

    This function can only be accessed when logged in as a system administrator.
*/
extern SA_API int SA_set_group_default_role(
    tag_t         group_tag,    /**< (I) */
    tag_t         role_tag      /**< (I) */
    );

/**
    Allows the current user to change to a different group and/or role.
    To change to the default role in a given group, use a role_tag value of #NULLTAG.
*/
extern SA_API int SA_change_group(
    tag_t         group_tag,    /**< (I) */
    tag_t         role_tag      /**< (I) */
    );

/**
    This function returns the default role in a group for a specified user.
*/
extern SA_API int SA_ask_user_default_role_in_group(
    tag_t         user_tag,     /**< (I) Tag of the user to find a role for */
    tag_t         group_tag,    /**< (I) Group to find the role in */
    tag_t*        role_tag      /**< (O) Default role tag */
    );

/** @if DOX_IGNORE
    23-Sep-1997
    The following ITKs are implemented for IMAN-PC and are intentionally not
    documented.  We may turn them into public and fully documented in the future.
@endif */

extern SA_API int SA_extent_group_count(
    int*          num_groups    /**< (O) */
    );

extern SA_API int SA_list_groups(
                                 int*          num_groups,   /**< (O) The number of groups */
                                 tag_t**       group_tags,   /**< (OF) num_groups The group tags */
                                 char***       group_names   /**< (OF) num_groups The group names. Please notice that only the group_names array needs to be freed.
                                                             The individual items within the array itself do NOT */
                                                             );

extern SA_API int SA_list_h_groups(
                                   int*          num_groups,       /**< (O) The number of groups */
                                   tag_t**       group_tags,       /**< (OF) num_groups The group tags */
                                   tag_t**       parent_groups,    /**< (OF) num_groups Corresponding parent group tags */
                                   char***       group_names       /**< (OF) num_groups The group names. Please notice that only the group_names array needs to be freed.
                                                                   The individual items within the array itself do NOT */
                                                                   );
/**
    Retrieves the list of mapped attributes for a group.
*/
extern SA_API int SA_get_mapped_group_attr_list(
    int*    numberOfAttributes,   /**< (O) */
    char*** list                  /**< (OF) numberOfAttributes */);

/**
    Sets the data source for the group
*/
extern SA_API int SA_set_group_last_sync_date(
    const tag_t          group_tag,                     /**< (I) */
    date_t               syncDate                       /**< (I) */
    );
/**
    Retrieves the group last sync date.
*/
extern SA_API int SA_get_group_last_sync_date(
    const tag_t   group_tag,                      /**< (I) */
    date_t        *syncDate                       /**< (O) */
    );
/**
    Sets the data source for the group
*/
extern SA_API int SA_set_group_data_source(
    const tag_t         group_tag,                     /**< (I) */
    int                 dataSource                     /**< (I) */
    );
/**
    Retrieves the group data source.
*/
extern SA_API int SA_get_group_data_source(
    const tag_t   group_tag,                          /**< (I) */
    int           *dataSource                         /**< (O) */
    );

extern SA_API int SA_ask_group_full_name_by_localized_full_name(
    const char *locGroupFullName,               /**< (I) */
    char **groupFullName                        /**< (OF) */
    );

extern SA_API int SA_find_group_by_localized_full_name(
    const char *localizedFullName,              /**< (I) */
    tag_t *groupTag                             /**< (O) */
    );

extern SA_API int SA_find_groups_by_localized_full_name(
    const char *localizedFullName,          /**< (I) */
    int *num_groups,                        /**< (O) */
    tag_t **groupTags                       /**< (OF) */
    );

/** 
    Finds privileged groups.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other POM errors
    </ul>
*/
extern SA_API int SA_find_privileged_groups(
    int *num_groups,                        /**< (O)   The number of groups */
    tag_t **groups                          /**< (OF)  num_groups tags of privileged groups*/
    );

/**
    Finds the groups based on the current user privileges.
    <br/>If the current user is a system administrator, all existing groups are retrieved including priviled groups.
    <br/>Otherwise, only the non-privileged groups are retrieved.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other POM errors
    </ul>
 */
extern SA_API int SA_find_privilege_honored_groups(
    int *num_groups,                     /**< (O)  The number of groups */
    tag_t **groups                       /**< (OF) num_groups tags of privilege honored groups*/
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
