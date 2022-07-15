/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used
    by clients of the System Administration classes and their clients.
*/

/*  */

#ifndef SA_H
#define SA_H

/**
    @defgroup SA System Administration

    The primary purpose of the System Administration (SA) ITK module is to
    allow System Administrators to control and manage the access to the Teamcenter Engineering system.

    You must use the include file sa.h with the functions in this section.

    <b>Common Return Values</b>

    #CXPOM_invalid_tag - Invalid tag passed in

    @{
*/

/**
    @name Defines that are common to Person, Group, and Role
    @{
*/
#define SA_name_size_c                       32
#define SA_group_name_size_c                 128
#define SA_person_name_size_c                128
#define SA_discipline_name_size_c            128
#define SA_description_size_c                240
#define SA_full_path_size_c                  240
/** @} */

/**
    @name Defines used by Person routines
    @{
*/
#define SA_state_size_c                        2
#define SA_address_size_c                     64
#define SA_city_size_c                        32
#define SA_zip_size_c                         10
#define SA_organization_size_c                32
#define SA_phone_size_c                       32
#define SA_email_size_c                       240
/** @} */

/**
    @name Defines used by Group routines
    @{
*/
#define SA_organization_name_size_c            250
#define SA_organization_id_size_c               14
#define SA_organization_type_size_c              4
#define SA_organization_legal_name_size_c      250
#define SA_organization_alternate_name_size_c  250
#define SA_organization_address_size_c        1024
#define SA_organization_url_size_c            1024
/** @} */

/**
    @name Defines used by User routines
    @{
*/
#define SA_password_size_c                    32
#define SA_user_size_c                        32
#define SA_site_size_c                        32
#define SA_volume_name_size_c                 32
#define SA_pref_code_size_c                   32
#define SA_pref_value_size_c                  32
#define SA_ip_clearance_size_c               128
#define SA_gov_clearance_size_c              128
#define SA_nationality_size_c                  2
#define SA_locale_size_c                       5
#define SA_timezone_size_c                    32
#define SA_geography_size_c                    2
/**
    Size of the license server name.
*/
#define SA_licenseserver_size_c              128
/** @} */

/**
    @name Defines used by Site routines
    @{
*/
#define SA_node_size_c                        4000 /* To Accomodate URL */
/** @} */

#include <sa/sa_errors.h>
#include <sa/person.h>
#include <sa/discipline.h>
#include <sa/role.h>
#include <sa/group.h>
#include <sa/groupmember.h>
#include <sa/user.h>
#include <sa/workcontext.h>
#include <sa/site.h>
#include <ss/ss_const.h>

#include <sa/libsa_exports.h>

#ifdef __cplusplus
        extern "C"{
#endif

/**
    Initializes the system administration module.
    <br/>Call this function immediately before any other SA functions are called.
*/
extern SA_API int SA_init_module( void );

/**
    Cleans up and exits the system administration module.
    <br/>This API is to be called once all SA activity is completed.
*/
extern SA_API int SA_exit_module( void );

/**
   Retrieves the name of the preference file corresponding to the named group.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_internal_error if @p group_name is incorrect
   <li>#SA_group_pfile_not_set if the preference @c TC_GROUP_PFILE is not set.
   <li>#SA_group_pfile_dir_bad if the directory specified by the preference @c TC_GROUP_PFILE is incorrect. A @p file_name is nonetheless retrieved. 
   <li>#SA_group_pfile_not_found if the preference file is not found. A @p file_name is nonetheless retrieved. 
   </ul>
*/
extern SA_API int SA_ask_h_group_pfile (
    const char*   group_name,   /**< (I) The name of the group */
    char**        file_name     /**< (OF) The name of the corresponding preference file */
    );


/**
   Retrieves the preference file name for the specified role.
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_internal_error if @p role_name is incorrect
   <li>#SA_role_pfile_not_set if the preference @c TC_ROLE_PFILE is not set.
   <li>#SA_role_pfile_dir_bad if the directory specified by the preference @c TC_ROLE_PFILE is incorrect. A @p file_name is nonetheless retrieved. 
   <li>#SA_role_pfile_not_found if the preference file is not found. A @p file_name is nonetheless retrieved. 
   </ul>
*/
extern SA_API int SA_ask_role_pfile2(
    const char    *role_name,                       /**< (I) */
    char          **file_name                       /**< (OF) */
    );


/**
   Retrieves the preference file name for the specified user.
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_internal_error if @p user_name is incorrect
   <li>#SA_user_pfile_not_set if the preference @c TC_USER_PFILE is not set.
   <li>#SA_user_pfile_dir_bad if the directory specified by the preference @c TC_USER_PFILE is incorrect. A @p file_name is nonetheless retrieved. 
   <li>#SA_user_pfile_not_found if the preference file is not found. A @p file_name is nonetheless retrieved. 
   </ul>
*/
extern SA_API int SA_ask_user_pfile2(
    const char    *user_name,                   /**< (I) The user name. */
    char          **file_name                   /**< (OF) The path to the preference file. */
    );

/**
    Reads an AM rule tree from the given path, plus decide whether to overwrite existing ACLs.
    <br/>This function replaces any existing rule tree, and saves the new one.
*/
extern SA_API int SA_read_am_rule_tree(
    const char*   path_name,    /**< (I) */
    logical       replace_acls  /**< (I) */
    );

/**
    Writes the current AM rule tree to the given file
*/
extern SA_API int SA_write_am_rule_tree(
    const char*   path_name     /**< (I) */
    );

extern SA_API int SA_set_user_home_site(
    tag_t         user,     /**< (I) The user tag */
    tag_t         home_site_tag /**< (I) The home site tag */
    );

extern SA_API int SA_ask_user_home_site(
    tag_t         user,     /**< (I) The user tag */
    tag_t*        home_site_tag /**< (O) The home site tag */
    );

extern SA_API int SA_set_user_remote_sites_deny_login(
    tag_t         user,       /**< (I) The user tag */
    int           n_remote_sites, /**< (I) Number of remote sites */
    tag_t*        remote_sites    /**< (I) n_remote_sites The remote site tags */
    );

extern SA_API int SA_ask_user_remote_sites_deny_login(
    tag_t         user,       /**< (I)  The user tag */
    int*          n_remote_sites, /**< (O)  Number of remote sites */
    tag_t**       remote_sites    /**< (OF) n_remote_sites The remote site tags */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
