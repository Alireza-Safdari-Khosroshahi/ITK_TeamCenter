/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the constants, data structures and function
    prototypes for working with the class Preferences and specifically
    with the C ITK interface to this class.
*/

/*  */

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>

#include <tc/libtc_exports.h>

/**
    @defgroup PREF Preferences
    @ingroup TC

    Teamcenter has implemented preferences functions that
    allows users to customize the operating environment.

    Detailed information is supplied for the following aspects of preferences functions:
    <ul>
    <li>The location of preference files, and the precedence rules employed in reading and writing to them.
    <li>The syntax of preference codes and values.
    <li>The Preference codes currently defined for preferences in Teamcenter.
    </ul>

    Teamcenter makes use of this mechanism itself, and it also provides ITK level functions for programmers
    to make use of the same preference mechanism.
    <br/>Programmers can define their own preference codes if they wish, or they can read and write to
    existing Teamcenter preferences.

    If you intend to add new preference codes, we suggest that you prefix them with your company name,
    thus ensuring that they will not conflict with any preference codes that Teamcenter may implement in the future.

    @note Teamcenter may alter or obsolete preference codes as the product evolves.
    These changes will be documented in the Release Notes.
    @{
*/

/**
   Defines different values that can be used as protection scopes or value locations.
*/
typedef enum TC_preference_search_scope_e{
    TC_preference_all,                   /**< All scope - Deprecated                 */
    TC_preference_user,                  /**< User value                             */
    TC_preference_role,                  /**< Role value                             */
    TC_preference_group,                 /**< Group value                            */
    TC_preference_site,                  /**< Site value                             */
    TC_preference_system,                /**< System value (for protection scope only)  */
    TC_preference_cots_location,         /**< COTS value (for location only)         */
    TC_preference_overlay_location,      /**< OVERLAY value (for location only)      */
    TC_preference_env_variable_location, /**< Environment value (for location only)  */
    TC_preference_overlay_xml_file,      /**< Value from overlay xml file            */
    TC_preference_default_value          /**< Default value provided during creation of definition   */
} TC_preference_search_scope_t;

/**
   Different actions that can be specified during an import operation, in case of conflict.
*/
typedef enum PREF_import_actions_e
{
    PREF_import_action_skip,                                /**< Skip the operation for the preference  */
    PREF_import_action_override,                            /**< Override with the specified preference */
    PREF_import_action_merge,                               /**< Merge the specified preference values with the existing ones */
    PREF_import_action_merge_with_latest,                   /**< choose latest while merging the values , for single value this could override with latest.*/
    PREF_import_action_override_with_source,                /**< This will ignore the target values and overrides with source. */
    PREF_import_action_keep_target,                         /**< This will ignore source values and keeps target only. */
    PREF_import_action_choose_latest,                       /**< This will apply the import algorithm and choose latest modified values */
    PREF_import_action_choose_source_for_unresolvable,      /**< If import has a conflict then choose source values. */
    PREF_import_action_choose_target_for_unresolvable       /**< If import has conflict then choose target values. */
} PREF_import_actions_t;

/**
   Defines the supported preference types
*/
typedef enum PREF_preference_type_e {
    PREF_preference_string,          /**< Preference of type String   */
    PREF_preference_logical,         /**< Preference of type Logical  */
    PREF_preference_integer,         /**< Preference of type Integer  */
    PREF_preference_double,          /**< Preference of type Double   */
    PREF_preference_date             /**< Preference of type Date     */
} PREF_preference_type_t;

/**
   Holds the preference definition
*/
typedef struct {
    char*                          preferenceName;        /**< Preference name. */
    char*                          preferenceCategory;    /**< Preference category. */
    char*                          preferenceDescription; /**< Preference description. */
    TC_preference_search_scope_t   preferenceScope;       /**< Preference protection scope. */
    PREF_preference_type_t         preferenceType;        /**< Preference type. */
    logical                        isArray;               /**< Specifies if preference has multiple values. */
    logical                        isDisabled;            /**< Specifies if preference is disabled. */
} PREF_preference_definition_t, *PREF_preference_definition_p_t;

/**
   Holds the preference context values
*/
typedef struct {
    char*  contextName;
    int    numberOfValues;
    char** values;
} PREF_preference_context_values_t, *PREF_preference_context_values_p_t;

/**
   Holds the entire information about a preference,
   i.e. preference definition information and context specific values.
*/
typedef struct {
    PREF_preference_definition_t      preferenceDefinition;
    int                               numberOfContexts;
    PREF_preference_context_values_t* contextValues;
} PREF_preference_object_t, *PREF_preference_object_p_t;

#ifdef __cplusplus
extern "C"{
#endif

/**
   @name Initialization of Preferences module
   @{
*/
/**
   Loads all of the values and definitions from database.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Any error arises due to POM query.
   </ul>
*/
    extern TC_API int PREF_initialize(void);

/**
    @deprecated #PREF_reinitialize deprecated in Teamcenter 11.6.

    Re-loads all of the values and definitions from database to reflect updates from outside the session.
 
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Any error arises due to POM query.
    </ul>
 */
    TC_DEPRECATED_NO_REPLACEMENT( "11.6", "PREF_reinitialize" )
    extern TC_API int PREF_reinitialize();
/** @} */

/**
   @name Preferences Protection Scope
   The protection scope defines the lowest-level of users allowed to provide a value (e.g. create an instance of the preference). This can be modified
   only by a system administrator.
   <br/>Possible values are:
   <ul>
   <li>#TC_preference_user: all users are allowed to provide a value. Instances can be created at the User, Role, Group and Site levels.
   <li>#TC_preference_role: only system and group administrators can provide a value. Instances can be created at the Role, Group and Site levels only.
   <li>#TC_preference_group: only system and group administrators can provide a value. Instances can be created at the Group and Site levels only.
   <li>#TC_preference_site: only system administrators can provide a value. Instances can be only created at the Site level.
   <li>#TC_preference_system: Same restrition as for #TC_preference_site. However, the protection scope cannot be modified by a system administrator.
   </ul>
   @{
*/
/**
   Asks the protection scope for a given preference.
   <br/>Possible returned values are #TC_preference_user, #TC_preference_role, #TC_preference_group, #TC_preference_site and #TC_preference_system.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_protection_scope(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t*       protection_scope        /**< (O) The protection scope of the preference */
        );

/**
   Asks the protection scope for several given preferences.
   <br/>Possible returned values are #TC_preference_user, #TC_preference_role, #TC_preference_group, #TC_preference_site and #TC_preference_system.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if the preference name in @p preference_names is invalid ("*").
   <li>#PREF_missing_preference_name if the preference name in @p preference_names is empty or NULL.
   <li>#PREF_preferences_not_existing (error) if one of the preferences does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_protection_scopes(
        int                                 preference_count,       /**< (I) The number of preferences */
        const char**                        preference_names,       /**< (I) The array of preference names */
        TC_preference_search_scope_t**      protection_scopes        /**< (OF) preference_count The array of protection scopes for the preferences */
        );

/**
   Sets the protection scope for a given preference.
   <br/>Valid values for the protection scope are #TC_preference_user, #TC_preference_role, #TC_preference_group,
   #TC_preference_site and #TC_preference_system.
   <br/>The TC_preference_system value is only to be used to convert a hierarchical preference to a System preference.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_protection_scope if the protection scope is invalid.
   <li>#PREF_user_not_system_admin if the user of is not a system administrator.
   <li>#PREF_cannot_change_protection_scope_of_system_pref if the preference is a system preference.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND will be returned if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_set_protection_scope(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        protection_scope        /**< (I) The new protection scope */
        );

/**
   Sets the protection scope for several given preferences.
   <br/>Valid values for the protection scopes are #TC_preference_user, #TC_preference_role, #TC_preference_group,
   #TC_preference_site and #TC_preference_system.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_protection_scope if any of the protection scopes in @p protection_scopes is invalid.
   <li>#PREF_user_not_system_admin if the user of is not a system administrator.
   <li>#PREF_cannot_change_protection_scope_of_system_prefs if one of the preferences is a system preference.
   <li>#PREF_invalid_preference_name if the preference name in @p preference_names is invalid ("*").
   <li>#PREF_missing_preference_name if the preference name in @p preference_names is empty or NULL.
   <li>#PREF_preferences_not_existing (warning) if one of the preferences does not exist.
   </ul>
*/
    extern TC_API int PREF_set_protection_scopes(
        int                                   preference_count,     /**< (I) The number of preferences */
        const char**                          preference_names,     /**< (I) The array of preference names */
        TC_preference_search_scope_t          protection_scopes[]   /**< (I) The array of new protection scopes */
        );

/**
   Checks if the current user has the needed permission to create/modify an instance for a given preference.

   <br/>There can be preference instances for the Site (only to be created/modified by the system administrators), for any Group or any Role (only to be created/modified by the system and group administrators), any User (to be created by any user).
   <br/>Furthermore, a preference is defined by its protection scope, which determines the lowest level where an instance can be created:
   <ul>
   <li>User: instances can be created for the Site, for any Group, any Role, any User.
   <li>Role: instances can only be created for the Site, for any Group and any Role.
   <li>Group: instances can be only created for the Site and for any Group.
   <li>Site/System: only a Site instance can be created.
   </ul>

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_is_instance_writable (
        const char*        preference_name,       /**< (I) The preference name */
        logical*           is_instance_writable   /**< (O) Indicates if the preference instance is writable.
                                                     <br/> True means the preference instance is writable.
                                                     <br/> False means the preference instance is not writable. */
        );
/** @} */

/**
   @name Preferences Environment Enabled Information
   The Environment Enabled flag determines if a preference value can be retrieved from a system environment value.
   <br/>If set to true, the existence of an environment variable with the name of the preference is checked. If it
   exists, the value is retrieved.
   @note Multi-valued preferences cannot be retrieved through environment variable.
   @{
*/
/**
   Asks the flag that authorizes a preference value to come from an environment variable.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_environment_set_flag(
        const char*                         preference_name,        /**< (I) The name of the preference */
        logical*                            flag                    /**< (O) The status for the environment set */
        );

/**
   Asks the flags that authorize preference values to come from an environment variable.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if the preference name in @p preference_names is invalid ("*").
   <li>#PREF_missing_preference_name if the preference name in @p preference_names is empty or NULL.
   <li>#PREF_preferences_not_existing (error) if one of the preferences does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_environment_set_flags(
        int                                 preference_count,       /**< (I) The number of preferences */
        const char**                        preference_names,       /**< (I) The array of preference names */
        logical**                           flags                   /**< (OF) preference_count The array of statuses for the environment set */
        );

/**
   Sets the flag that authorizes a preference value to come from an environment variable.
   <br/>Valid values are true (allow) or false.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_user_not_system_admin if the user of is not a system administrator.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_set_environment_set_flag(
        const char*                         preference_name,        /**< (I) The name of the preference */
        logical                             flag                    /**< (I) The status for the environment set */
        );

/**
   Sets the flag that authorizes preference values to come from an environment variable.
   <br/>Valid values are true (allow) or false.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_user_not_system_admin if the user of is not a system administrator.
   <li>#PREF_invalid_preference_name if the preference name in @p preference_names is invalid ("*").
   <li>#PREF_missing_preference_name if the preference name in @p preference_names is empty or NULL.
   <li>#PREF_preferences_not_existing (warning) if one of the preferences does not exist.
   </ul>
*/
    extern TC_API int PREF_set_environment_set_flags(
        int                                 preference_count,       /**< (I) The number of preferences */
        const char**                        preference_names,       /**< (I) The array of preference names */
        const logical                       flag[]                  /**< (I) The array of statuses for the environment set */
        );


/** @} */

/**
   @name Preferences Count
   @{
*/
/**
   Retrieves the number of values that exist for a particular preference name.

   @note If the preference is not defined at all, @p value_count will be 0.

   @returns #ITK_ok always
*/
    extern TC_API int PREF_ask_value_count(
        const char*     preference_name,    /**< (I) The name of the preference */
        int*            value_count         /**< (O) The number of values */
        );

/**
   Retrieves the number of values that exist for a particular preference name at a specific location.
   <br/>If the preference does not have an instance at the given location, the returned value count is 0.

   Valid values for the location are #TC_preference_user , #TC_preference_role , #TC_preference_group, and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_value_count_at_location(
        const char*                         preference_name,        /**< (I) The number of preferences */
        TC_preference_search_scope_t        location,               /**< (I) The location where to look for the preference */
        int*                                value_count             /**< (O) The number of values at the location */
        );

/** @} */

/**
    @name String Preferences
    @{
*/
/**
   Asks the value of a preference of data type is "String".

   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   <br/>The index is used to determine which value to retrieve if the preference has multiple values. The index starts at 0.
   If the preference is single-valued, use the value 0.

   @note No error is returned if the preference does not exist.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PF_BOUNDS if @p index is negative, or if the preference has at least a value and the index goes beyond the existing number of values.
   </ul>
*/
    extern TC_API int PREF_ask_char_value(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             index,              /**< (I) The index of the value to retrieve */
        char**          value               /**< (OF) The returned value */
        );

/**
   Asks all the values of the preference whose data type is "String".
   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if @p preference_name does not refer to an existing preference.
   </ul>
*/
    extern TC_API int PREF_ask_char_values(
        const char*     preference_name,    /**< (I) Preference name */
        int*            count,              /**< (O) Number of values in the value array */
        char***         value               /**< (OF) count Array of returned values.
                                             <br/>The array is packed, which means that the memory is to be deallocated using #MEM_free only on the container. */
        );

/**
   Sets the values of a preference whose data type is "String".
   <br/>This ITK can be used to set preferences of type other than "String" (i.e. "Integer", "Double", "Logical", "Date"). However, using the other flavors ITKs
   (#PREF_set_int_values, #PREF_set_double_values, #PREF_set_logical_values for "Integer", "Double", "Logical" respectively ) is encouraged.

   @note If the preference does not defined, its definition will be created and an instance with the provided values will be created at the User location.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PF_NULL_VALUE if @p value_count is strictly positive and @p values is a null pointer.
   <li>#PF_NULL_VALUE if any value in @p values is a null string
   <li>#PREF_not_a_int_value if the preference data type is "Integer" and one of the values is not an integer.
   <li>#PREF_not_a_double_value if the preference data type is "Double" and one of the values is not a double.
   <li>#PREF_not_a_logical_value if the preference data type is "Logical" and one of the values is not a logical.</li>
   <li>#PREF_not_a_date_value if the preference data type is "Date" and one of the values is not a date.</li>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   </ul>
*/
    extern TC_API int PREF_set_char_values(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             value_count,        /**< (I) The number of values */
        char*           values[]            /**< (I) value_count The array of values */
        );

/**
   Asks the value of a preference whose data type is "String" at a specific level.
   <br/>The index is used to determine which value to retrieve if the preference has multiple values. The index starts at 0.

   <br/>Valid values for the location are #TC_preference_user , #TC_preference_role , #TC_preference_group , #TC_preference_site and #TC_preference_overlay_location.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_char_value instead.

   @returns
   <ul>
   <li>#ITK_ok on success. If there is no value at the provided location, the output value will be a null pointer.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_char_value_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the value */
        int                                 index,                  /**< (I) The index at which to retrieve the value */
        char**                              value                   /**< (OF) The returned value */
        );

/**
   Asks all the values of the preference whose data type is "String".

   Valid values for the location are #TC_preference_user , #TC_preference_role , #TC_preference_group , and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_char_values instead.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_char_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the values */
        int*                                count,                  /**< (O) The number of values in the value array */
        char***                             values                  /**< (OF) count The array of values
                                                                       <br/>The array is packed, which means that the memory is to be deallocated using #MEM_free only on the container. */
        );


/**
   Sets the value(s) of a preference whose data type is "String" at a specific level.

   <br/>Valid values for the locations are #TC_preference_user , #TC_preference_role , #TC_preference_group , and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_set_char_values instead.

   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PREF_value_cannot_be_set_at_location if the specified location does not match the existing protection scope for the preference.</li>
   <li>#PREF_invalid_location if the location is invalid.</li>
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to write at the given location:
   <ol>
   <li>Only system administrators can write at the site location</li>
   <li>Only group administrators can write at the group or role location</li>
   <li>Normal users can only write at the user location</li>
   </ol>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   <li>#PREF_not_a_int_value if the preference data type is "Integer" and one of the values is not an integer.
   <li>#PREF_not_a_double_value if he preference data type is "Double" and one of the values is not a double.
   <li>#PREF_not_a_logical_value if the preference data type is "Logical" and one of the values is not a logical.</li>
   <li>#PREF_not_a_date_value if the preference data type is "Date" and one of the values is not a date.</li>
   </ul>

   @warning If the preference does not exist, no error is returned. Instead the preference will be created.
   <br/>The value of the "location" argument will also become the protection scope.
   <br/>However, the system will match what is possible:
   <ul>
   <li>if the logged-in user is a site administrator, any value can be given to the protection scope. The preference value will be set at the location.
   <li>if the logged-in user is a group administrator, the location can be anything but "TC_preference_site". If the value is "TC_preference_site", the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   <li>if the logged-in user is a regular user, the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   </ul>
*/
    extern TC_API int PREF_set_char_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to set the values */
        int                                 value_count,            /**< (I) The number of values in the value array */
        char*                               values[]                /**< (I) The array of values */
        );
/** @} */

/**
    @name Integer Preferences
    @{
*/
/**
   Asks the value of a preference whose data type is "Integer".

   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   <br/>The index is used to determine which value to retrieve if the preference has multiple values. The index starts at 0.
   If the preference is single-valued, use the value 0.

   @warning If the preference is not of type "Integer", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   <li>#PF_NOTFOUND if the preference does not exist.
   <li>#PF_BOUNDS if @p index is negative, or if the preference has at least a value and the index goes beyond the existing number of values.
   </ul>
*/
    extern TC_API int PREF_ask_int_value(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             index,              /**< (I) The index of the value to retrieve */
        int*            value               /**< (O) The value */
        );

/**
   Asks all the values of the preference whose data type is "Integer".
   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   @warning If the preference is not of type "Integer", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PF_NOTFOUND if @p preference_name does not refer to an existing preference
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   </ul>
*/
    extern TC_API int PREF_ask_int_values(
        const char*     preference_name,    /**< (I) Preference name */
        int*            value_count,        /**< (O) Number of values in the value array */
        int**           values              /**< (OF) value_count Array of returned values */
        );

/**
   Sets the value(s) of a preference whose data type is "Integer".

   @note If the preference does not defined, its definition will be created and an instance with the provided values will be created at the User location.

   @warning If the preference is not of type "Integer", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to set the preference value (e.g. a site-protected preference)
   </ul>
*/
    extern TC_API int PREF_set_int_values(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             value_count,        /**< (I) The number of values */
        int             values[]            /**< (I) value_count The array of values */
        );

/**
   Asks the value of a preference whose data type is "Integer" at a given location.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, #TC_preference_site
   <br/>The value #TC_preference_site applies also to System preferences.

   <br/>The index is used to determine which value to retrieve if the preference has multiple values. The index starts at 0.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_int_value instead.

   @warning If the preference is not of type "Integer", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist or does not have any value at this location.
   <li>#PF_BOUNDS if @p index is negative, or if the preference has at least a value and the index goes beyond the existing number of values.
   </ul>
*/
    extern TC_API int PREF_ask_int_value_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the value */
        int                                 index,                  /**< (I) The index of the value requested */
        int*                                value                   /**< (O) The returned value */
        );

/**
   Asks all the values of the preference whose data type is "Integer" at the specified location.

   Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_int_values instead.

   @warning If the preference is not of type "Integer", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success. If there is no value at the provided location, @p values will be a null pointer and @p value_count is zero.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_int_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the values */
        int*                                value_count,            /**< (O) The number of values in the value array */
        int**                               values                  /**< (OF) value_count The array of values */
        );

/**
   Sets the value(s) of a preference whose data type is "Integer" at a specific location.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_set_int_values instead.

   @warning If the preference is not of type "Integer", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PREF_invalid_location if the location is invalid.</li>
   <li>#PREF_value_cannot_be_set_at_location if the specified location does not match the existing protection scope for the preference.</li>
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to write at the given location:
        <ol>
        <li>Only system administrators can write at the site location</li>
        <li>Only group administrators can write at the group or role location</li>
        <li>Normal users can only write at the user location</li>
        </ol>
   </li>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   </ul>

   @warning If the preference does not exist, no error is returned. Instead the preference will be created.
   <br/>The value of the "location" argument will also become the protection scope.
   <br/>However, the system will match what is possible:
   <ul>
   <li>if the logged-in user is a site administrator, any value can be given to the protection scope. The preference value will be set at the location.
   <li>if the logged-in user is a group administrator, the location can be anything but "TC_preference_site". If the value is "TC_preference_site", the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   <li>if the logged-in user is a regular user, the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   </ul>
*/
    extern TC_API int PREF_set_int_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to set the value */
        int                                 value_count,            /**< (I) The number of values in the value array */
        int                                 values[]                /**< (I) The array of values */
        );
/** @} */

/**
    @name Double Preferences
    @{
*/
/**
   Asks the value of a preference whose data type is "Double".

   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   <br/>The index is used to determine which value to retrieve if the preference has multiple values. The index starts at 0.
   If the preference is single-valued, use the value 0.

   @warning If the preference is not of type "Double", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   <li>#PF_NOTFOUND if @p preference_name does not exist.
   <li>#PF_BOUNDS if @p index is negative, or if the preference has at least a value and the index goes beyond the existing number of values.
   </ul>
*/
    extern TC_API int PREF_ask_double_value(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             index,              /**< (I) The index of the value to retrieve */
        double*         value               /**< (O) */
        );

/**
   Asks all the values of the preference whose data type is "Double".
   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   @warning If the preference is not of type "Double", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PF_NOTFOUND if @p preference_name does not refer to an existing preference.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   </ul>
*/
    extern TC_API int PREF_ask_double_values(
        const char*     preference_name,    /**< (I) Preference name */
        int*            value_count,        /**< (O) Number of values in the value array */
        double**        values              /**< (OF) value_count Array of returned values */
        );


/**
   Sets the value(s) of a preference whose data type is "Double".

   @note If the preference does not defined, its definition will be created and an instance with the provided values will be created at the User location.

   @warning If the preference is not of type "Double", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to set the preference value (e.g. a site-protected preference)
   </ul>
*/
    extern TC_API int PREF_set_double_values(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             value_count,        /**< (I) The number of values */
        double          values[]            /**< (I) value_count The array of values */
        );

/**
   Asks the value of a preference whose data type is "Double" at a given location.

   <br/>Index is used to determine which value to retrieve if the preference has multiple values. Index starts at 0.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_double_value instead.

   @warning If the preference is not of type "Double", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if the preference does not exist or does not have any value at this location.
   <li>#PF_BOUNDS if @p index is negative, or if the preference has at least a value and the index goes beyond the existing number of values.
   </ul>
*/
    extern TC_API int PREF_ask_double_value_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the value */
        int                                 index,                  /**< (I) The index of the value to retrieve */
        double*                             value                   /**< (O) The returned value */
        );

/**
   Asks all the values of the preference whose data type is "Double" at the specified location.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_double_values instead.

   @warning If the preference is not of type "Double", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success. If there is no value at the provided location, @p values will be a null pointer and @p value_count is zero.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if @p preference_name does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_double_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the values */
        int*                                value_count,            /**< (O) The number of values in the value array */
        double**                            values                  /**< (OF) value_count The array of values */
        );

/**
   Sets the value(s) of a preference whose data type is "Double" at a specific location.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>The #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_set_double_values instead.

   @warning If the preference is not of type "Double", no error is returned. Information is added, however, to the Teamcenter syslog.

   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PREF_invalid_location if the location is invalid.</li>
   <li>#PREF_value_cannot_be_set_at_location if the specified location does not match the existing protection scope for the preference.</li>
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to write at the given location:
        <ol>
        <li>Only system administrators can write at the site location.</li>
        <li>Only group administrators can write at the group or role location.</li>
        <li>Normal users can only write at the user location.</li>
        </ol>
   </li>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   </ul>

   @warning If the preference does not exist, no error is returned. Instead the preference will be created.
   <br/>The value of the "location" argument will also become the protection scope.
   <br/>However, the system will match what is possible:
   <ul>
   <li>if the logged-in user is a site administrator, any value can be given to the protection scope. The preference value will be set at the location.
   <li>if the logged-in user is a group administrator, the location can be anything but "TC_preference_site". If the value is "TC_preference_site", the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   <li>if the logged-in user is a regular user, the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   </ul>
*/
    extern TC_API int PREF_set_double_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to set the value */
        int                                 value_count,            /**< (I) The number of values in the value array */
        double                              values[]                /**< (I) The array of values */
        );
/** @} */

/**
    @name Logical Preferences
    @{
*/
/**
   Asks the value of a preference whose data type is "Logical".

   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   <br/>The index is used to determine which value to retrieve if the preference has multiple values. The index starts at 0.
   If the preference is single-valued, use the value 0.

   @note If using an invalid index or if the preference name refers to a preference that does not exist,
   no error will be returned and the value "false" will be retrieved.

   @warning If the preference is not of type "Logical", no error is returned and the retrieved value is "false".

   @returns #ITK_ok always
*/
    extern TC_API int PREF_ask_logical_value(
        const char*     preference_name,    /**< (I) The name of the preference */
        int             index,              /**< (I) The index of the value to retrieve */
        logical*        value               /**< (O) The value */
        );

/**
   Asks all the values of the preference whose data type is "Logical".

   <br/>The value is returned as specified at the first possible location starting at the location equal to the protection scope of the preference.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PF_NOTFOUND if @p preference_name does not exist.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   </ul>
*/
    extern TC_API int PREF_ask_logical_values(
        const char*     preference_name,    /**< (I) Preference name */
        int*            value_count,        /**< (O) Number of values in the value array */
        logical**       values              /**< (OF) value_count Array of returned values */
        );

/**
   Sets the value of a preference whose data type is "Logical".

   @note If the preference does not defined, its definition will be created and an instance with the provided values will be created at the User location.

   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privileges
        <ol>
        <li>Only system administrators can write at the site location.</li>
        <li>Only group administrators can write at the group or role location.</li>
        <li>Normal users can only write at the user location.</li>
        </ol>
   </li>
   </ul>
*/
    extern TC_API int PREF_set_logical_value(
        const char*                         preference_name,        /**< (I) The name of the preference */
        logical                             value                   /**< (I) The value */
        );

/**
   Sets the values of a preference whose data type is "Logical".

   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privileges:
        <ol>
        <li>Only system administrators can write at the site location.</li>
        <li>Only group administrators can write at the group or role location.</li>
        <li>Normal users can only write at the user location.</li>
        </ol>
   </li>
   </ul>

   @warning The value is set at the location which is the protection scope if the preference definition exist
   or else a runtime definition is created.
*/
    extern TC_API int PREF_set_logical_values(
        const char*                          preference_name,        /**< (I) The name of the preference */
        int                                  value_count,            /**< (I) The number of values in the array */
        logical                              values[]                /**< (I) The array of values */
        );

/**
   Asks the value of a preference whose data type is "Logical" at the specified location.

   <br/>Index is used to determine which value to retrieve if the preference has multiple values. Index starts at 0.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_logical_value instead.

   @note If using an invalid index or if the preference name refers to a preference that does not exist or no value is found at the location,
   no error will be returned and the value "false" will be retrieved.

   @warning If the preference is not of type "Logical", no error is returned and the retrieved value is "false".

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   </ul>
*/
    extern TC_API int PREF_ask_logical_value_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the value */
        int                                 index,                  /**< (I) The index of the value to retrieve */
        logical*                            value                   /**< (O) The returned value */
        );

/**
   Asks the value of a preference whose data type is "Logical" at the specified location.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_ask_logical_values instead.

   @warning If the preference is not of type "Logical", no error is returned, @p value_count is provided accurately but the retrieved values are "false".

   @returns
   <ul>
   <li>#ITK_ok on success. If there is no value at the provided location, the @p values will be a null pointer and @p value_count would be zero.
   <li>#PREF_value_cannot_be_asked_at_location if the specified level does not match the existing protection scope for the preference.
   <li>#PREF_invalid_location if the location is invalid.
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*").
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL.
   <li>#PF_NOTFOUND if @p preference_name does not exist.
   </ul>
*/
    extern TC_API int PREF_ask_logical_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to retrieve the values */
        int*                                value_count,            /**< (O) The number of values in the array */
        logical**                           values                  /**< (OF) value_count The array of values */
        );

/**
   Sets the values of a preference whose data type is "Logical" at the specified location.

   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>The value #TC_preference_site applies also to System preferences.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_set_logical_values instead.

   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PREF_invalid_location if the location is invalid.</li>
   <li>#PREF_value_cannot_be_set_at_location if the specified location does not match the existing protection scope for the preference.</li>
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to write at the given location:
        <ol>
        <li>Only system administrators can write at the site location.</li>
        <li>Only group administrators can write at the group or role location.</li>
        <li>Normal users can only write at the user location.</li>
        </ol>
   </li>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   </ul>

   @warning If the preference does not exist, no error is returned. Instead the preference will be created.
   br>The value of the "location" argument will also become the protection scope.
   <br/>However, the system will match what is possible:
   <ul>
   <li>if the logged-in user is a site administrator, any value can be given to the protection scope. The preference value will be set at the location.
   <li>if the logged-in user is a group administrator, the location can be anything but "TC_preference_site". If the value is "TC_preference_site", the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   <li>if the logged-in user is a regular user, the protection scope of the preference and the location of the value will be set as "TC_preference_user".
   </ul>
*/
    extern TC_API int PREF_set_logical_values_at_location(
        const char*                         preference_name,        /**< (I) The name of the preference */
        TC_preference_search_scope_t        location,               /**< (I) The location where to set the value */
        int                                 value_count,            /**< (I) The number of values in the array */
        logical                             values[]                /**< (I) The array of values */
        );
/** @} */

/**
    @name Preferences Definitions
    @{
*/
/**
   Creates or changes a preference according to a #PREF_preference_object_t structure.

   <br/>If the preference does not already exist in the database, all the declaration data will be needed,
   otherwise an error (as explained below) will be returned.

   <br/>In the input structure:
   <ul>
   <li>preferenceName
   <ul>
   <li>#PREF_invalid_preference_name if @p preference_name is invalid ("*"). </li>
   <li>#PREF_missing_preference_name if @p preference_name is empty or NULL. </li>
   </ul>
   </li>

   <li>preferenceCategory
   <br/>The name of the category where the preference is sorted.
   <br/>If the string is empty, the parameter will not be taken into account. However, in case the
   preference has not been created yet, it will be assumed that the preference will go under the
   General category.
   <br/>If the string is not empty and if the category does not exists in the system already, new category would be created and the preference
   would go under this category.
   </li>

   <li>preferenceDescription
   <br/>The description associated with the preference.
   <ul>
   <li>If the string is empty, the parameter will not be taken into account.
   "No description is available for this preference." would be added as the preference description.
   <br/>However, in case the preference has not been created yet, this parameter is mandatory
   </li>
   <li>If the string is not empty, the code will consider this to be a valid description. </li>
   </ul>
   </li>

   <li>preferenceScope
    <br/>The protection scope: valid values are User, Role, Group, Site and System.
    <ul>
        <li>If the preference does not exist, this information is mandatory.
            br/>#PREF_invalid_protection_scope will be returned if the protection scope is invalid.
        </li>
        <li>If the preference exists:
        <br/>If the string is not empty, the code will consider this to be a modification. Therefore:
        <ul>
        <li>#PREF_invalid_protection_scope, if the protection scope is invalid. </li>
        <li>#PREF_no_protection_scope_change_on_ootb_system_preference if system scope is changed to hierarchical scope( user, role, group and site ). </li>
        <li>Hierarchical scope can be changed to system scope. </li>
        </ul>
        </li>
    </ul>
   </li>

   <li>preferenceType
   <br/>Defines the type of the preference: #PREF_preference_string, #PREF_preference_logical, #PREF_preference_integer, #PREF_preference_double, #PREF_preference_date.
   <br/>If the preference does not exist, this piece of information will be needed and if any other data type is provided,  #PREF_definition_type_invalid will be returned.
   <br/>If the preference exists, the new type does not match with existing preference type, then #PREF_parameter_value_change_not_expected will be returned.
   </li>

   <li>IsDisabled
   <br/>Definition IsDisabled attributed is ignored.
   </li>

   <li>IsArray
   <br/>Single valued preference can be changed to multivalued, but when change multivalued preference to singular, then warning message is added in syslog.
   </li>

   <li>contextValues
   <br/>If context values are provided, then default value instance would be created.
   <br/>Default value instance is created only during preference definition creation.
   </li>
   </ul>

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_insufficient_privileges if the logged-in user does not have the system admin privilege.
   </ul>
*/
    extern TC_API int PREF_set_definition(
        const char* preference_name,                          /**< (I) The name of the preference                             */
        PREF_preference_object_t preference_object,           /**< (I) The preference object describing the preference to add */
        logical env_variable_enabled                          /**< (I) Defines if the value for the given preference can come from the environment variable. */
        );

/**
   Deletes the definition of the specified preferences.
   <br/>If the intent is to delete the value, use #PREF_delete_preference or #PREF_delete_preference_at_location ITKs instead.
   <br/>The preference definition and all preference value instances would be removed but category is not deleted.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PREF_insufficient_privileges if the logged-in user does not have system administrator privileges.
   <li>#PREF_preferences_not_existing (warning) if one or more preferences do not exist. The call will proceed with the removal of the other preference definitions though.
   </ul>
*/
    extern TC_API int PREF_delete_definition(
        int nb_of_preferences,                  /**< (I) The number of preference definition to delete.   */
        const char** preference_names,          /**< (I) The name of the preferences.                     */
        logical delete_all_custom_definitions   /**< (I) Since there is no difference between custom and OOTB preference definition,
                                                        @p delete_all_custom_definitions is not used. */
        );
/** @} */


/**
    @name Preferences Import and Export
    @{
*/
/**
   Exports the specified preferences from the specified location to the specified
   output file.
   <br/>Nothing will be exported if the named preferences are not found under the specified
   location.

   The possible values for the location parameter are:
   <table>
   <tr><td>#TC_preference_user </td><td>Exports the specified preferences from the user location.</td></tr>
   <tr><td>#TC_preference_role </td><td>Exports the specified preferences from the user location.</td></tr>
   <tr><td>#TC_preference_group</td><td>Exports the specified preferences from the group location.</td></tr>
   <tr><td>#TC_preference_site </td><td>Exports the specified preferences from the site location.</td></tr>
   </table>

   The user/role/group are the ones for the current logged-in user.
*/
    extern TC_API int PREF_export_preference_list(
        int                             preference_count,   /**< (I) Number of preferences to export */
        char**                          preference_names,   /**< (I) Name of the preferences to export */
        TC_preference_search_scope_t    location,           /**< (I) Location of the preferences to export */
        const char*                     output_file_name    /**< (I) Output export file name */
        );

/**
   Exports all the preferences at the specified location to the specified
   output file.
   <br/>Nothing will be exported if there are no preferences under
   the specified scope.
   <br/>(For e.x. if the scope is specified as TC_preference_user, all the
   user preferences for the current logged in user would be exported.)

   The possible values for the location parameter are:
   <table>
   <tr><td>#TC_preference_user </td><td>Exports all the preferences at the user location.</td></tr>
   <tr><td>#TC_preference_role </td><td>Exports all the preferences at the user location.</td></tr>
   <tr><td>#TC_preference_group</td><td>Exports all the preferences at the group location.</td></tr>
   <tr><td>#TC_preference_site </td><td>Exports all the preferences at the site location.</td></tr>
   </table>

   The user/role/group are the ones for the current logged-in user.
*/
    extern TC_API int PREF_export_preferences(
        TC_preference_search_scope_t    location,           /**< (I) Location to be considered for export */
        const char*                     output_file_name    /**< (I) Output export file name */
        );


/**
   Exports all the preferences belonging to the specified categories from the specified location
   scope to the specified output file.
   <br/>Nothing will be exported if there are no preferences matching the criteria at the specified
   location.
   <br/>E.g. if the specified location is TC_preference_user, all the user preferences for the current
   logged-in user will be exported.

   The possible values for the location parameter are:
   <table>
   <tr><td>#TC_preference_user </td><td>Exports all the preferences at the user location.</td></tr>
   <tr><td>#TC_preference_role </td><td>Exports all the preferences at the role location.</td></tr>
   <tr><td>#TC_preference_group</td><td>Exports all the preferences at the group location.</td></tr>
   <tr><td>#TC_preference_site </td><td>Exports all the preferences at the site location.</td></tr>
   </table>
   The user/role/group are the ones for the current logged-in user.
*/
    extern TC_API int PREF_export_preferences_with_category(
        TC_preference_search_scope_t location,             /**< (I) Location to be considered for export */
        int                          number_of_categories, /**< (I) Number of categories */
        char**                       categories,           /**< (I) Categories to be considered for export */
        const char*                  output_file_name      /**< (I) Output export file name */
        );

/**
   Imports all the preferences in the specified xml file at the specified location.

   The possible values for the location parameter are:
   <table>
   <tr><td>#TC_preference_user </td><td>Imports the preferences in the xml file at the user location.</td></tr>
   <tr><td>#TC_preference_role </td><td>Imports the preferences in the xml file at the role location.</td></tr>
   <tr><td>#TC_preference_group</td><td>Imports the preferences in the xml file at the group location.</td></tr>
   <tr><td>#TC_preference_site </td><td>Imports the preferences in the xml file at the site location.</td></tr>
   </table>
   The user/role/group are the ones for the current logged-in user.

   The action parameter specifies the action to be taken in the event of a
   preference existing in the database. The possible values for the action
   parameter are:
   <table>
   <tr><td>#PREF_import_action_skip    </td><td>Skips the preference and does not do any
   further processing for this preference.</td></tr>
   <tr><td>#PREF_import_action_override</td><td>Overrides the values of the preference in
   the database with the values in the specified
   xml file.                              </td></tr>
   <tr><td>#PREF_import_action_merge   </td><td>Merges the values for the preference in the
   database with the values in the specified xml
   file. This merge is a simple union of the values
   in the database and the xml file.      </td></tr>
   </table>

   <b>Restrictions:</b>
   <br/>If the specified location TC_preference_site, the logged-in user must have system
   administrative privileges.
   <br/>If the specified location is TC_preference_group or TC_preference_role, the logged-in user
   must have at least group administrative privileges.
*/
    extern TC_API int PREF_import_preferences(
        TC_preference_search_scope_t    location,     /**< (I) Location where to import the preferences */
        const char*                     input_xml,    /**< (I) Path to the input XML file name */
        PREF_import_actions_t           action        /**< (I) Action to be considered in the event of conflict with the information already present in the database */
        );

/**
   Imports the preferences in the specified xml file, only from the specified categories,
   and into the specified location.

   The possible values for the location parameter are:
   <table>
   <tr><td>#TC_preference_user </td><td>Imports the preferences in the xml file at the user location. </td></tr>
   <tr><td>#TC_preference_role </td><td>Imports the preferences in the xml file at the role location. </td></tr>
   <tr><td>#TC_preference_group</td><td>Imports the preferences in the xml file at the group location.</td></tr>
   <tr><td>#TC_preference_site </td><td>Imports the preferences in the xml file at the site location. </td></tr>
   </table>

   The action parameter specifies the action to be taken in the event of a
   preference existing in the database. The possible values for the action
   parameter are:
   <table>
   <tr><td>#PREF_import_action_skip    </td><td>Skips the preference and does not do any
   further processing for this preference.</td></tr>
   <tr><td>#PREF_import_action_override</td><td>Overrides the values of the preference in
   the database with the values in the specified
   xml file.                              </td></tr>
   <tr><td>#PREF_import_action_merge   </td><td>Merges the values for the preference in the
   database with the values in the specified xml
   file. This merge is a simple union of the values
   in the database and the xml file.      </td></tr>
   </table>

   <b>Restrictions:</b>
   <br/>If the specified location is TC_preference_site, the logged-in user must have
   system administrative privileges.
   <br/>If the specified location is TC_preference_group or TC_preference_role, the logged-in user must
   have at least group administrative privileges.
*/
    extern TC_API int PREF_import_preferences_with_category(
        TC_preference_search_scope_t location,   /**< (I) Location where to import the preferences  */
        const char*                  input_xml,  /**< (I) Path to the input XML file name */
        int                          number_of_categories, /**< (I) Number of categories given as input */
        char**                       category_names,       /**< (I) Categories to be considered for import */
        PREF_import_actions_t        action      /**< (I) Action to be considered in the event of conflict with the information already present in the database */
        );
/** @} */

/**
    @name Deleting Preferences Instances
    @{
*/
/**
   Deletes the specified preference instance from the location that
   matches the preference protection scope.

   <b>Restrictions:</b>
   <br/>If the preference being deleted is a site-protected preference, the logged-in user must have
   system administrative privileges.
   <br/>If the preference being deleted is a group/role-protected preference, the logged-in user must
   have at least group administrative privileges.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_not_allow_default_value_instance_delete if preference has only default values. The default value instance can be deleted only when definition is deleted.
   </ul>
*/
    extern TC_API int PREF_delete_preference(
        const char*                     preference_name      /**< (I) Name of the preference which instance is to be deleted. */
        );


/**
   Deletes the specified preference instance from the specified location.

   The location are the ones as seen from the logged-in user.
   <br/>Valid values for the location are #TC_preference_user, #TC_preference_role, #TC_preference_group, and #TC_preference_site.
   <br/>If the preference being deleted is a site-protected preference, the logged-in user must have system administrative privileges.
   <br/>If the preference being deleted is a group/role-protected preference, the logged-in user must have at least group administrative privileges.

   @note Do not use this API unless very knowledgeable about preferences. Otherwise, please use #PREF_delete_preference instead.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to remove instances at the provided location.
   <li>#PREF_invalid_location if @p location is invalid.
   <li>#PREF_value_cannot_be_removed_at_location if @p location does not match the protection scope for the preference.
   <li>#PREF_not_allow_default_value_instance_delete if @p preference_name has only default values.
   <li>#PF_NOTFOUND if @p preference_name does not exist.
   </ul>
*/
    extern TC_API int PREF_delete_preference_at_location(
        const char*                     preference_name,     /**< (I) Name of the preference which instance is to be deleted */
        TC_preference_search_scope_t    location             /**< (I) The location where to delete the preference instance */
        );


/**
   Deletes the specified preference instance from the specified location.

   <br/>The location can be any location for which the logged-in user has privileges.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PREF_insufficient_privileges if the logged-in user does not have the privilege to remove instances based on protection scope of the @p preference_name.
   <li>#PREF_not_allow_default_value_instance_delete if @p preference_name has only default values.
   </ul>
*/
    extern TC_API int PREF_delete_non_session_preference(
        char* preference_name,        /**< (I) Name of the preference which instance is to be deleted */
        tag_t object                  /**< (I) User, Role or Group tag */
        );
/** @} */


/**
    @name Preferences Refresh and Lock
    @{
*/
/**
    Refreshes all preferences in current session.
   @p preference_name is not used.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Any error arises due to POM query.
   </ul>
*/
    extern TC_API int PREF_refresh(
        const char*     preference_name     /**< (I) Name of preference to refresh */
        );

/**
   Refreshes the preferences specified in @p  preference_names for the current session.
   @returns
   #ITK_ok always.
*/
    extern TC_API int PREF_refresh_preferences(
        const int          n_preferences,             /**< (I) The number of preferences to be refreshed.*/
        const char**       preference_names           /**< (I) n_preferences The list of preferences to be refreshed.*/
    );

/** @} */

/**
   @name Deprecated APIs
   @{
*/

/**
   @deprecated #PREF_lock_site_preferences deprecated in Teamcenter 11.6.

   Locks site preferences.
   <br/>Use this to have exclusive modification privileges to site preferences.
   <br/>Once the modifications are done, use #PREF_unlock_site_preferences to unlock.

   <b>Restrictions:</b> The logged-in user must have site administrative privileges.

   <br/>Due to the re-architecture of preferences from XML storage to database objects, this operation is no longer required. So it has been deprecated since Tc11.6.0.

   @returns
   <ul>
   <li>#ITK_ok always
   </ul>
*/
    TC_DEPRECATED_NO_REPLACEMENT( "11.6", "PREF_lock_site_preferences" )
    extern TC_API int PREF_lock_site_preferences( );

/**
   @deprecated #PREF_unlock_site_preferences deprecated in Teamcenter 11.6.

   Unlocks site preferences.

   <b>Restrictions:</b> The logged-in user must have site administrative privileges.

   <br/>Due to the re-architecture of preferences from XML storage to database objects, this operation is no longer required. So it has been deprecated since Tc11.6.0.

   @returns
   <ul>
   <li>#ITK_ok always
   </ul>
*/
    TC_DEPRECATED_NO_REPLACEMENT( "11.6", "PREF_unlock_site_preferences" )
    extern TC_API int PREF_unlock_site_preferences( );

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif


#include <tc/libtc_undef.h>
#endif
