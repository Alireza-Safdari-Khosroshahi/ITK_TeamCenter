 /*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all the functions to be used
    by clients of the User class which is part of the System
    Administration module of Teamcenter Engineering.

    <b>Restrictions:</b>

    This include file should not generally be used by anyone.
    Normally sa.h or user.hxx should be included instead.
*/

/*  */

#ifndef USER_H
#define USER_H

#include <sa/sa.h>
#include <unidefs.h>

#include <sa/libsa_exports.h>

/**
    @defgroup USER User
    @ingroup SA
    @{
*/

/**
   Structure that holds property name and value(s) of the additional properties of User object that are defined on Fnd0CustomUserProfile
*/
typedef struct SA_user_profile_props_s {
    char*  prop_name;        /**< Property name */
    int    n_values;         /**< Number of values for the property */
    char** values;           /**< Values for the property in string format */
} SA_user_profile_props_t;

#ifdef __cplusplus
     extern "C"{
#endif


/**
    Allocates an array of tags and stores in the array all users in the database.
*/
extern SA_API int SA_extent_user(
    int*          n_users,  /**< (O) Number of users */
    tag_t**       users     /**< (OF) n_users Users in the database */
    );

/**
    This suppresses deactivated users from the list
*/
extern SA_API int SA_extent_active_user(
    int*          n_users,    /**< (O) Number of users */
    tag_t**       users       /**< (OF) n_users Users */
    );


/**
    Initializes a User object. It is not saved to the database until an explicit call to POM_save occurs.
    <br/>You must specify the user_id, person_name and password.

    <br/>You normally use this function with a subclass of User.
    <br/>For example, if you defined a class special User,
    you would first call #POM_create_instance to create the object in memory.
    <br/>Then you would use this function to initialize the attributes which were inherited from User.
    <br/>Finally, you would use additional POM calls to initialize the attributes comprising your specialization of User.

    <b>Restrictions:</b>
    This function is only valid when you are logged in as the system administrator.
*/
extern SA_API int SA_initialize_user2(
    tag_t         user,                             /**< (I) */
    const char    *user_id,                         /**< (I) */
    const char    *person_name,                     /**< (I) */
    const char    *password                         /**< (I) */
    );


/**
    Creates a User object with 'active' status and 'author' license level.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    <br/>You must specify the user_id, person_name and password.
    <br/>You must also specify the login group and OS user name by calling
    #SA_set_user_login_group and #SA_set_os_user_name2.

    <b>Restrictions:</b>
    This function is only valid when you are logged in as the system administrator.
*/
extern SA_API int SA_create_user2(
    const char    *user_id,                             /**< (I) */
    const char    *person_name,                         /**< (I) */
    const char    *password,                            /**< (I) */
    tag_t*        user                                  /**< (O) */
    );


/**
    Creates a User object.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    <br/>You must specify the user_id, person_name, password, license_level and status for the user.
    <br/>The valid values for licenseLevel are 'author' = 0,'consumer' = 1, 'occasionaluser' = 2.
    The valid values for status are 'active' = 0 or 'inactive' = 1.
    <br/>You must also specify the login group and OS user name by calling #SA_set_user_login_group
    and #SA_set_os_user_name2.

    <b>Restrictions:</b>
    <br/>This function is only valid when you are logged in as the system administrator.
*/
extern SA_API int SA_create_licensed_user2(
    const char    *user_id,                                   /**< (I) */
    const char    *person_name,                               /**< (I) */
    const char    *password,                                  /**< (I) */
    int           license_level,                              /**< (I) */
    int           user_status,                                /**< (I) */
    tag_t*        user                                        /**< (O) */
    );

/**
    Creates a User object.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    <br/>The login group and OS user name must be specified by calling
    the ITKs #SA_set_user_login_group and #SA_set_os_user_name2. 
    
    <br/><br/>This function validates that the specified status, license level, and license bundle are valid and that

    the user may be created with these values.  It sets the status and license level properties for the unsaved User object, but the
    license bundle property must be set by calling #SA_set_user_license_status after #SA_create_licensed_user3 and #AOM_save.
    <br/><br/>A purchased license bundle may include a base license level.  If the license_level parameter
    does not match the license level contained in the specified bundle, the user's license level is set to the level contained in the bundle.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SA_Invalid_User if the user id is invalid
    <li>#ITK_invalid_licensebundle_name if the license bundle name is invalid
    <li>#ITK_insufficient_licensebundles if there are not enough available license bundles
    <li>#SA_not_a_system_administrator if the caller is not an administrator
    </ul>    
    @note This function is only valid when you are logged in as the system administrator.
*/
extern SA_API int SA_create_licensed_user3(
    const char    *user_id,                                  /**< (I) The user ID */
    const char    *person_name,                              /**< (I) The person name */
    const char    *password,                                 /**< (I) The login password */
    int           license_level,                             /**< (I) The license level. Valid values are <ul><li>0: author</li><li>1: consumer</li><li>2: occasional user</li></ul> */
    const char    *license_bundle,                           /**< (I) The license bundle.  This should be a valid bundle name or null. */
    int           user_status,                               /**< (I) The user status. Valid values are <ul><li>0: active</li><li>1: inactive</li></ul> */
    tag_t*        user                                       /**< (O) The newly created user */
    );

/**
    Creates a User object.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    <br/>The login group and OS user name must be specified by calling
    the ITKs #SA_set_user_login_group and #SA_set_os_user_name2. 
    <br/><br/>This function validates that the specified status, license server, license level, and license bundle are valid and that
    the user may be created with these values.  It sets the status and license level properties for the unsaved User object, but the
    license bundle property must be set by calling #SA_set_user_license_status after #SA_create_user_with_license_information and #AOM_save.
    <br/><br/>A purchased license bundle may include a base license level.  If the license_level parameter
    does not match the license level contained in the specified bundle, the user's license level is set to the level contained in the bundle.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SA_Invalid_User if the user id is invalid
    <li>#ITK_invalid_licensebundle_name if the license bundle name is invalid
    <li>#ITK_insufficient_licensebundles if there are not enough available license bundles
    <li>#SA_not_a_system_administrator if the caller is not an administrator
    </ul>    
    @note This function is only valid when you are logged in as the system administrator.
*/
extern SA_API int SA_create_user_with_license_information(
    const char    *user_id,                                  /**< (I) The user id */
    const char    *person_name,                              /**< (I) The person name */
    const char    *password,                                 /**< (I) The login password */
    int           license_level,                             /**< (I) The license level. Valid values are <ul><li>0: author</li><li>1: consumer</li><li>2: occasional user</li></ul> */
    const char    *license_bundle,                           /**< (I) The license bundle.  This should be a valid bundle name or null. */
    const char    *license_server,                           /**< (I) The license server.  This should be a valid server name or null. */
    int           user_status,                               /**< (I) The user status. Valid values are <ul><li>0: active</li><li>1: inactive</li></ul> */
    tag_t*        user                                       /**< (O) The newly created user */
    );


/**
    Sets the user identifier attribute of the user.
*/
extern SA_API int SA_set_user_identifier2(
    tag_t         user,                         /**< (I) */
    const char    *user_id                       /**< (I) */
    );

/**
    Sets the person attribute of the user.
*/
extern SA_API int SA_set_user_person(
    tag_t         user,     /**< (I) */
    tag_t         person    /**< (I) */
    );
/**
    Changes the password attribute of the user.
    You must be logged in as the user referenced by @p user to change the password.
    <br/>The system administrator can also change the password.
*/
extern SA_API int SA_change_user_password2(
    tag_t         user,                                  /**< (I) */
    const char    *new_password,                         /**< (I) */
    const char    *old_password                          /**< (I) */
    );

/**
    Sets the default login group attribute of the user.
*/
extern SA_API int SA_set_user_login_group(
    tag_t         user,     /**< (I) */
    tag_t         group     /**< (I) */
    );

/**
    Sets the default volume name attribute of the user.

    <b>Restrictions:</b>
*/
extern SA_API int SA_set_user_default_volume2(
    tag_t         user,                                     /**< (I) */
    const char    *volume_name                              /**< (I) */
    );


/**
    Sets the default local volume name attribute of the user.

    <b>Restrictions:</b>
*/
extern SA_API int SA_set_user_default_local_volume2(
    tag_t         user,                                     /**< (I) */
    const char    *volume_name                              /**< (I) */
    );


/**
    Finds a user with the specified user_id. The user_id is unique in the database.
    <br/>If @p user_id does not exist, @p user will be #NULLTAG.
    
    @note This ITK is NOT case sensitive in regards to user ID.
*/
extern SA_API int SA_find_user2(
    const char    *user_id,                      /**< (I) */
    tag_t*        user                           /**< (O) */
    );


/**
    Returns the value of the identifier attribute for a user.
*/
extern SA_API int SA_ask_user_identifier2(
    tag_t         user,                         /**< (I) */
    char          **user_id                      /**< (OF) */
    );


/**
    Returns the value of the name attribute for a user.
*/
extern SA_API int SA_ask_user_person_name2(
    tag_t         user,                              /**< (I) */
    char          **person_name                      /**< (OF) */
    );

/**
    Returns the value of @p person attribute for a user.
*/
extern SA_API int SA_ask_user_person(
    tag_t         user,     /**< (I) */
    tag_t*        person    /**< (O) */
    );

/**
    Returns the value of the home @p folder attribute for a user.
    <br/>The home folder was implicitly created when you created the user.
*/
extern SA_API int SA_ask_user_home_folder(
    tag_t         user,     /**< (I) */
    tag_t*        folder    /**< (O) */
    );

/**
    Returns the value of the mailbox tag attribute for this user.
    <br/>The mailbox was implicitly created when you created the user.
*/
extern SA_API int SA_ask_user_mailbox(
    tag_t         user,     /**< (I) */
    tag_t*        folder    /**< (O) */
    );

/**
    Returns the value of the newstuff folder tag attribute for this user.
    <br/>The mailbox was implicitly created when you created the user.
*/
extern SA_API int SA_ask_user_newstuff_folder(
    tag_t         user,     /**< (I) */
    tag_t*        folder    /**< (O) */
    );

/**
    Returns the default login group attribute for the user.
*/
extern SA_API int SA_ask_user_login_group(
    tag_t         user,     /**< (I) */
    tag_t*        group     /**< (O) */
    );


/**
    Returns the default volume name attribute for the user.
*/
extern SA_API int SA_ask_user_default_volume2(
    tag_t         user,                                     /**< (I) */
    char          **volume_name                             /**< (OF) */
    );


/**
    Returns the default local volume name attribute for the user.
*/
extern SA_API int SA_ask_user_default_local_volume2(
    tag_t         user,                                     /**< (I) */
    char          **volume_name                             /**< (OF) */
    );

/**
    Allocates an array of tags and stores in the array all tags of objects owned by the specified user.
*/
extern SA_API int SA_find_user_objects(
    tag_t         user,             /**< (I) */
    int*          n_objects,        /**< (O) Stores the size of the array */
    tag_t**       objects           /**< (OF) n_objects Points to the array of tags */
    );


/**
    new_owning_user and new_owning_group may be #NULLTAG, provided delete_objects is true
*/
extern SA_API int SA_delete_user(
    tag_t         user,                 /**< (I) */
    tag_t         new_owning_user,      /**< (I) */
    tag_t         new_owning_group,     /**< (I) */
    logical       delete_objects        /**< (I) */
    );


/**
    Sets the IP (Intellectual Property) clearance attribute of a Teamcenter user.
 */
extern SA_API int SA_set_user_ip_clearance(
        tag_t user,                 /**< (I) */
        const char * ip_clearance      /**< (I) */
        );


/**
    Returns the value of the IP (Intellectual Property) clearance attribute of a
    Teamcenter user.
 */
extern SA_API int SA_ask_user_ip_clearance2(
        tag_t user,                                 /**< (I) */
        char **ip_clearance                            /**< (OF) */
        );

/**
    Sets the Government clearance attribute of a Teamcenter user.
 */
extern SA_API int SA_set_user_gov_clearance(
        tag_t user,                 /**< (I) */
        const char * gov_clearance      /**< (I) */
        );

/**
    Returns the value of the Government clearance attribute of a
    Teamcenter user.
 */
extern SA_API int SA_ask_user_gov_clearance2(
        tag_t user,                                 /**< (I) */
        char **gov_clearance                           /**< (OF) */
        );

/**
    Sets the geography attribute of a Teamcenter user.
 */
extern SA_API int SA_set_user_geography(
        tag_t user,                /**< (I) */
        const char * geography        /**< (I) */
        );

/**
    Returns the value of the geography attribute of a Teamcenter user.
*/
extern SA_API int SA_ask_user_geography2(
        tag_t user,                               /**< (I) */
        char **geography                             /**< (OF) */
        );

/**
    Sets the value of "User Declared Geography" attribute of the Teamcenter user.
    <br/>Appropriate values for @p geography are two-character codes from ISO 3166. NULL value 
    is allowed for user declared geography, if the value is NULL then the default value
    is considered to be an empty string (i.e. "").

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if @p user is not a valid user.
    <li>#SA_no_system_admin_for_user_property if @p user is neither the System Administrator nor same as that of the logged in user.
    </ul>
 */
extern SA_API int SA_set_user_declared_geography(
        tag_t user,                /**< (I) The user for which the user declared geography is being set. */
        const char * geography     /**< (I) The country code of the country representaed in ISO 3166 format. NULL value is allowed for user declared geography, if the value is NULL then the default value is considered to be an empty string (i.e. "")  */
        );

/**
    Retrieves the value of "User Declared Geography" attribute of the Teamcenter user.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if @p user is not a valid user.
    </ul>
*/
extern SA_API int SA_ask_user_declared_geography(
        tag_t user,                               /**< (I) The user for which the user declared geography is being set. */
        char **geography                          /**< (OF) The country code of the country representaed in ISO 3166 format. Or an empty string (i.e. "") if the given user has not declared georaphical location via #SA_set_user_declared_geography far. */
        );

/**
    Sets the nationality attribute of a Teamcenter user.
 */
extern SA_API int SA_set_user_nationality(
        tag_t user,                /**< (I) */
        const char * nationality      /**< (I) */
        );


/**
    Returns the value of the nationality attribute of a Teamcenter user.
 */
extern SA_API int SA_ask_user_nationality2(
        tag_t user,                               /**< (I) */
        char **nationality                        /**< (OF) */
        );

/**
    Sets the ttc_date (technology transfer certification date) attribute of
    a Teamcenter user.
 */
extern SA_API int SA_set_user_ttc_date(
        tag_t user,                /**< (I) */
        date_t ttc_date            /**< (I) */
        );

/**
    Returns the value of the ttc_date (technology transfer certification date)
    attribute of a Teamcenter user.
 */
extern SA_API int SA_ask_user_ttc_date(
        tag_t user,                /**< (I) */
        date_t *ttc_date            /**< (O) */
        );


/**
    Sets the operating system user name attribute of a Teamcenter Engineering user.
*/
extern SA_API int SA_set_os_user_name2(
    tag_t         user,                          /**< (I) */
    const char    *os_user_name                  /**< (I) */
    );


/**
    Returns the value of the OS user name attribute for a user.
*/
extern SA_API int SA_ask_os_user_name2(
     tag_t         user,                          /**< (I) */
     char          **os_user_name                 /**< (OF) */
     );

/**
    Returns the list of mapped attributes for a user.
*/
extern SA_API int SA_get_mapped_user_attr_list(
    int*     n_attributes,         /**< (O) */
    char***  list                  /**< (OF) n_attributes */);
/**
    Returns the user status.
*/
extern SA_API int SA_get_user_status(
    const tag_t   user,                      /**< (I) */
    int           *status                        /**< (O) */
    );
/**
    Sets the user status.
*/
extern SA_API int SA_set_user_status(
    const tag_t   user,                      /**< (I) */
    int           new_status                 /**< (I) */
    );
/**
    Sets the data source for the user
*/
extern SA_API int SA_set_user_last_sync_date(
    const tag_t   user,                      /**< (I) */
    date_t        sync_date                  /**< (I) */
    );
/**
    Returns the user last sync date.
*/
extern SA_API int SA_get_user_last_sync_date(
    const tag_t   user,                      /**< (I) */
    date_t        *sync_date                 /**< (O) */
    );
/**
    Sets the data source for the user
*/
extern SA_API int SA_set_user_data_source(
    const tag_t   user,                      /**< (I) */
    int           data_source                /**< (I) */
    );
/**
    Returns the user data source.
*/
extern SA_API int SA_get_user_data_source(
    const tag_t   user,                      /**< (I) */
    int           *data_source               /**< (O) */
    );

/**
    Sets user citizenships. 
    
    @note If the number of citizenships is zero, it will empty user citizenships.
    
    @returns 
    <ul>
    <li>#ITK_ok on success
    <li>#SA_invalid_citizenship will returned if each citizenship is not two-letter string.
    <li>#PROP_invalid_object will be returned if user input tag is not valid User tag.
    </ul>
 */
extern SA_API int SA_set_user_citizenships(
    tag_t user,                  /**< (I) The tag of the user to whom the citizenships are to be set*/
    int n_citizenships,          /**< (I) The number of citizenships. */
    const char** citizenships    /**< (I) n_citizenships Citizenships to be set to the user */
    );

/**
   Retrieves user citizenships

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SA_no_privilege_for_citizenship if the login user is not system admin or user himself.
   <li>#PROP_invalid_object if @p user is not valid User tag.
   </ul>
 */
extern SA_API int SA_ask_user_citizenships(
    tag_t user,           /**< (I) The tag of the user whose citizenship is to be retrieved.*/
    int *n_citizenships,  /**< (O) Number of citizenships*/
    char*** citizenships  /**< (OF) n_citizenships The citizenships*/
    );

/** 
    Sets the license level, license bundle and status of the desired user.
    <br>The number of purchased and used licenses for @p specified license_level and @p license_bundle are returned.

    @returns
    <ul>
    <li>#SA_Invalid_User if the user id is invalid
    <li>#SA_low_on_available_licenses if the number of available licenses are less than the threshold value set by license_warning_level preference
    <li>#SA_low_on_available_license_bundles if the number of available licenses in the bundle are less than the threshold value set by license_warning_level preference
    <li>#ITK_invalid_licensebundle_name if the license bundle name is invalid
    <li>#ITK_mismatch_in_license_level if the desired user license level does not match with the one present in the license bundle
    <li>#ITK_insufficient_licensebundles if there are not enough number of license bundles
    <li>#SA_not_a_system_administrator if the caller is not an administrator
    </ul>
    @note This function is only valid when you are logged in as the system administrator.
*/
extern SA_API int SA_set_user_license_status(
    tag_t  user,                 /**< (I) An existing user */
    int    user_status,          /**< (I) The user status. Valid values are <ul><li>0: active</li><li>1: inactive</li></ul> */
    int    license_level,        /**< (I) The license level. Valid values are <ul><li>0: author</li><li>1: consumer</li><li>2: occasional user</li></ul> */
    const char *license_bundle,  /**< (I) The license bundle.  This should be a valid bundle name or null. */
    int    *purchased,           /**< (O) Number of purchased licenses */
    int    *used,                /**< (O) Number of used licenses */
    int    *purchased_bundles,   /**< (O) Number of purchased bundles */
    int    *used_bundles         /**< (O) Number of used bundles */
    );

/** 
    Sets the license level, license bundle and status of the desired user.
    <br/>The caller must be a Teamcenter system administrator.
    <br/>The number of purchased and used licenses for @p license_level and @p license_bundle are returned.

    @returns
    <ul>
    <li>#SA_Invalid_User if the user id is invalid
    <li>#SA_low_on_available_licenses if the number of available licenses are less than the threshold value set by license_warning_level preference
    <li>#SA_low_on_available_license_bundles if the number of available licenses in the bundle are less than the threshold value set by license_warning_level preference
    <li>#ITK_invalid_licensebundle_name if the license bundle name is invalid
    <li>#ITK_mismatch_in_license_level if the desired user license level does not match with the one present in the license bundle
    <li>#ITK_insufficient_licensebundles if there are not enough number of license bundles
    </ul>
*/
extern SA_API int SA_set_user_license_status_with_server(
    tag_t  user,                 /**< (I) An existing user */
    int    user_status,          /**< (I) The user status. Valid values are <ul><li>0: active</li><li>1: inactive</li></ul> */
    int    license_level,        /**< (I) The license level. Valid values are <ul><li>0: author</li><li>1: consumer</li><li>2: occasional user</li></ul> */
    const char *license_bundle,  /**< (I) The license bundle.  This should be a valid bundle name or null. */
    const char *license_server,  /**< (I) The license server.  This should be a valid server name or null */
    int    *purchased,           /**< (O) Number of purchased licenses */
    int    *used,                /**< (O) Number of used licenses */
    int    *purchased_bundles,   /**< (O) Number of purchased bundles */
    int    *used_bundles         /**< (O) Number of used bundles */
    );

/**
    Creates a Custom User Profile for the given user if it does not already exist.
    <br/>This ITK can also be used to modify the properties of an existing Custom User Profile.

    <br/>It validates that the specified properties are valid and that the Custom User Profile may be created with 
    these values. It also sets the property fnd0custom_user_profile on the User object with newly created Custom User Profile.
    
    <br/>Custom User profiles enable customers to define custom properties on User objects. The custom properties of User should 
    be defined on the Fnd0CustomUserProfile business object to see them on any of the Teamcenter client interfaces.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if the given user is invalid.
    <li>#SA_invalid_custom_user_profile_property if the supplied Fnd0CustomUserProfile properties are invalid.
    <li>#SA_invalid_custom_user_profile_value if the supplied values for the Fnd0CustomUserProfile properties are invalid.
    </ul>

    <b>Restrictions:</b>
    This function only supports setting of primitive property types.  
*/
extern SA_API int SA_set_user_profile_attributes(
    tag_t                          user,                        /**< (I) Tag of an existing user */
    int                            n_profile_props,             /**< (I) Number of profile properties */
    const SA_user_profile_props_t  *profile_props               /**< (I) n_profile_props Custom User Profile properties */
    );
/**
    Retrieves the value of sponsorable attribute of the Teamcenter user. 
    <br/>If the value is 1, the user can be used for sponsored authentication.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if the given user is invalid.
    </ul>
*/
extern SA_API int SA_ask_user_sponsorability(
    tag_t      user,                       /**< (I) Tag of an existing user */
    int*       sponsorable                 /**< (O) Sponsorable flag of given user */
    );

/**
    Sets the sponsorable attribute of a Teamcenter user. 
    <br/>The value is set to 0 at the time of the user creation.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if the given user is invalid.
    </ul>
*/
extern SA_API int SA_set_user_sponsorability(
    tag_t     user,                       /**< (I) Tag of an existing user */
    int       sponsorable                 /**< (I) Value of Sponsorable flag to be set */
    );

/**
    Retrieves the value of "VIS License Level" attribute for the Teamcenter user. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if @p user is not a valid user.
    </ul>
*/
extern SA_API int SA_ask_user_vis_license_level(
    tag_t      user,                       /**< (I) The user for which the VIS license level is requested. */
    int*       vis_license_level           /**< (O) The VIS License Level. */
    );

/**
    Sets the value of "VIS License Level" attribute for the Teamcenter user. 
    <br/>The value is set to 0 (Base VIS License) at the time of the user creation.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_Invalid_User if @p user is not a valid user.
    <li>#PROP_invalid_value if @p vis_license_level is not a valid Visualization License Level.  
    The valid values for vis_license_level are 0 (base), 1 (standard), 2 (professional) or 3 (mockup).
    </ul>
*/
extern SA_API int SA_set_user_vis_license_level(
    tag_t     user,                       /**< (I) The user for which the VIS license level is requested. */
    int       vis_license_level           /**< (I) The VIS License Level. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
