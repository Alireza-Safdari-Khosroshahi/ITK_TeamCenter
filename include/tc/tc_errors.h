/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Defines error codes used within all areas of Teamcenter
*/

/*  */

#ifndef TC_ERRORS_H
#define TC_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TC_ERRORS ITK Errors
    @ingroup TC
    @{
*/

#define TC_ERROR_BASE                   EMH_TC_error_base

/**
    ITK_not_initialized: call ITK_init_module or ITK_auto_login.
*/
#define ITK_not_initialized                                                     (TC_ERROR_BASE + 1)

/**
    ITK_auto_login_failed: No parameters on command line or could not connect to session manager.
*/
#define ITK_auto_login_failed                                                   (TC_ERROR_BASE + 2)

/**
    ITK_internal_error: Unclassified error/exception. See system log file for possible explanation.
*/
#define ITK_internal_error                                                      (TC_ERROR_BASE + 3)

/**
    ITK_general_user_error: Unclassified user error. e.g. saving object that has not been changed.
*/
#define ITK_general_user_error                                                  (TC_ERROR_BASE + 4)

/**
    ITK_wso_no_change: Save request for unchanged workspaceobject: %1$
*/
#define ITK_wso_no_change                                                       (TC_ERROR_BASE + 5)

/**
    ITK_duplicate_constructors: Duplicate constructors
*/
#define ITK_duplicate_constructors                                              (TC_ERROR_BASE + 6)

/**
    ITK_invalid_flag: Invalid flag found in the argument list
*/
#define ITK_invalid_flag                                                        (TC_ERROR_BASE + 7)

/**
    ITK_invalid_name: Invalid name found in the argument list
*/
#define ITK_invalid_name                                                        (TC_ERROR_BASE + 8)

/**
    ITK_invalid_date: use format %1$
*/
#define ITK_invalid_date                                                        (TC_ERROR_BASE + 9)

/**
    Action %1$ already registered for class %2$
*/
#define ITK_duplicate_action                                                    (TC_ERROR_BASE +10)

/**
    Action %1$ not registered for class %2$
*/
#define ITK_no_match_for_action                                                 (TC_ERROR_BASE +11)

/**
    ITK function passed a NULL input tag.
*/
#define ITK_invalid_nulltag                                                     (TC_ERROR_BASE +12)

/**
    The function %1$ is obsolete when using the new rules-based AM
*/
#define ITK_old_am_function                                                     (TC_ERROR_BASE +13)

/**
    TC_acs_error: error checking for Flexlm license
*/
#define ITK_no_acs_license                                                      (TC_ERROR_BASE +14)

/**
    '%1$' is too large - number entered should not exceed '%2$'
*/
#define ITK_number_too_large                                                    (TC_ERROR_BASE +15)

/**
    '%1$' is too small - number entered should not be less than '%2$'
*/
#define ITK_number_too_small                                                    (TC_ERROR_BASE +16)

/**
    Cannot open the TCTEXT file
*/
#define ITK_cannot_open_tc_text_file                                            (TC_ERROR_BASE +17)

/**
    Failed to auto login using web cookie
*/
#define ITK_web_cookie_auto_login_failed                                        (TC_ERROR_BASE +18)

/**
    The value of '%1$' is invalid - check range
*/
#define ITK_parameter_invalid_value                                             (TC_ERROR_BASE +19)

/**
    Web Server Preference is not defined:%1$
*/
#define ITK_Web_server_not_defined                                              (TC_ERROR_BASE +20)

/**
    You have not logged in for %1$ days,  ask your system administrator to reset your account
*/
#define ITK_non_login_timeout                                                   (TC_ERROR_BASE +21)

/**
    Teamcenter has detected a serious internal error; To maintain data integrity log out and restart Teamcenter, otherwise data corruption could occur.
*/
#define ITK_serious_error                                                       (TC_ERROR_BASE +22)

/**
    The current user is not licensed to perform authoring functions in Teamcenter. Please contact your system administrator for further assistance.
*/
#define ITK_no_author_license                                                   (TC_ERROR_BASE +23)

/**
    The current user is not licensed to use Teamcenter Consumer features. Please contact your system administrator for further assistance.
*/
#define ITK_no_consumer_license                                                 (TC_ERROR_BASE +24)

/**
    No Flexlm license is available for Teamcenter optional module &apos;%1$&apos;.
*/
#define ITK_no_optional_module_license                                          (TC_ERROR_BASE +25)

/**
    No Flexlm license is available for Teamcenter concurrent module &apos;%1$&apos;.
*/
#define ITK_no_concurrent_module_license                                        (TC_ERROR_BASE +26)

/**
    Following three error codes are reserved for future purpose. No error text avilable yet.
*/
#define ITK_no_occasional_license                                               (TC_ERROR_BASE +27)
#define ITK_no_viewer_license                                                   (TC_ERROR_BASE +28)
#define ITK_no_user_license                                                     (TC_ERROR_BASE +29)

/**
    An internal error has occurred: the code version is posterior to the version of the installed database.
*/
#define ITK_wrong_shared_library                                                (TC_ERROR_BASE +30)

/**
    The Replica user &quot;%1$&quot; is not allowed to log into this site.
*/
#define ITK_replica_user_login_denied                                           (TC_ERROR_BASE +31)

/**
    Too many objects were found to generate the report. Please redefine your search, or change the value for the preference "Crf_Report_objects_limit".
*/
#define CRF_too_many_objects                                                    (TC_ERROR_BASE +32)

/**
    The License Server &quot;%1$&quot; already exists. Please specify a different License Server name.
*/
#define ITK_duplicate_license_server_name                                       (TC_ERROR_BASE +33)

/**
   A License Server with host &quot;%1$&quot; and port number &quot;%2$&quot; already exists. Please specify a different host and port number.
*/
#define ITK_duplicate_license_server_hostname_port                              (TC_ERROR_BASE +34)

/**
    The name of the license bundle &quot;%1$&quot; exceeds the 9 character limit.
*/
#define ITK_wrong_licensebundle_name_size                                       (TC_ERROR_BASE +35)

/**
    There are duplicate entries for the license bundle &quot;%1$&quot;. Please provide unique license bundle names.
*/
#define ITK_duplicate_licensebundles                                            (TC_ERROR_BASE +36)

/**
    The attempted action requires a named user license of &quot;%1$&quot;. All licenses for this feature have been assigned to other users. For more licenses, contact your system administrator responsible for licensing.
*/
#define ITK_no_module_license                                                   (TC_ERROR_BASE +37)

/**
   The license level does not match the base license level of the license bundle &quot;%1$&quot;. The license level of the bundle will be used.
*/
#define ITK_mismatch_in_license_level                                           (TC_ERROR_BASE +38)

/**
   A license bundle with name &quot;%1$&quot; does not exist. Please provide a valid license bundle name.
*/
#define ITK_invalid_licensebundle_name                                          (TC_ERROR_BASE +39)

/**
   A license server with name &quot;%1$&quot; does not exist. Please provide a valid license server name.
*/
#define ITK_invalid_license_server_name                                         (TC_ERROR_BASE +40)

/**
   The number of active users of the license bundle &quot;%1$&quot; exceeds the number of purchased licenses.
*/
#define ITK_insufficient_licensebundles                                         (TC_ERROR_BASE +41)

/**
   Teamcenter cannot acquire a license for the module key(s): %1$. Please contact your system administrator responsible for licensing.
*/
#define ITK_license_not_present                                                 (TC_ERROR_BASE +42)

/**
   The line could not be read entirely. Please report this error to your system administrator.
*/
#define TC_full_line_not_read                                                   (TC_ERROR_BASE +43)

/**
   The buffer size (%1$) is too small to hold the UTF-8 encoded data.
*/
#define TC_insufficient_buffer_to_hold_utf8_data                                (TC_ERROR_BASE +44)

/**
  The following entries in the list of failover license servers are not valid machines: %1$.
*/
#define ITK_invalid_failover_license_servers                                    (TC_ERROR_BASE +45)

/**
  The license server "%1$" cannot be deleted, because it is referenced by a user or a site.
*/
#define ITK_invalid_license_servers_delete                                      (TC_ERROR_BASE +46)

/**
  The Flexlm license server encountered an error when setting the user definition. Please contact your system administrator responsible for licensing.
*/
#define ITK_error_setting_licensing_user_definition                             (TC_ERROR_BASE +47)

/**
  The Flexlm license server encountered an error when returning a named user count for the module &quot;%1$&quot;. Please contact your system administrator responsible for licensing.
*/
#define ITK_flex_failed_module_count                                            (TC_ERROR_BASE +48)

/**
  The Flexlm license server encountered an error when disconnecting from the license server. Please contact your system administrator responsible for licensing.
*/
#define ITK_flex_failed_disconnect                                              (TC_ERROR_BASE +49)

/**
    The current user "%1$" is not licensed to perform administrative functions in Teamcenter. Please contact your system administrator for further assistance.
*/
#define ITK_no_admin_license                                                    (TC_ERROR_BASE +50)

/**
  The Flexlm license server has encountered an error when connecting the license server. Please contact your system administrator responsible for licensing.
*/
#define ITK_flex_failed_connect                                                 (TC_ERROR_BASE +51)

/**
    The server initialization has failed. Please check the server syslog file for more information or contact your system administrator for further assistance.
*/
#define ITK_init_failed                                                         (TC_ERROR_BASE +52)

/** The version string "%1$" must be in the format "[d+](.[d+])*", where 'd' represents a digit. */
#define ITK_invalid_version_format                                              (TC_ERROR_BASE +53)

/** A possible violation of the global license contract was detected. Please contact the system administrator for further assistance. */
#define ITK_global_license_mismatch                                             (TC_ERROR_BASE +54)

/** The user "%2$" does not have permissions to find the object "%1$". Only the user or a system administrator can find the object. Please contact your system administrator. */
#define TC_cannot_find_login_license_info                                       (TC_ERROR_BASE +55)

/** The user "%2$" does not have permissions to update the object "%1$". Only the user or a system administrator can update the object. Please contact your system administrator.*/
#define TC_cannot_update_login_license_info                                     (TC_ERROR_BASE +56)

/** The current country infomation could not be retrieved. Please check the server syslog file for more information or contact your system administrator for further assistance. */
#define TC_cannot_acquire_country_information                                   (TC_ERROR_BASE +57)

/** The user "%1$" does not have permissions to view or update the license information. Please contact your system administrator. */
#define TC_no_access_permission_to_license_info                                 (TC_ERROR_BASE +58)

/** The TcSSO token cannot be decoded, probably due to a mediator key mismatch between TcSS and Teamcenter. */
#define TC_async_mismatch_mediator_key                                          (TC_ERROR_BASE +59)

/**
Invalid license server type "%1$" used to create or update the license server. Valid license server type values are NULS and ILS. NULS - Named User License Server and ILS - Integration License Server.
*/
#define ITK_invalid_license_server_type                                         (TC_ERROR_BASE + 60)

/**
The license server "%1$" intended to be used as the "%2$" server for the given license server is not "%3$" server type. Valid license server should be of type "%3$". Where ILS is Integration License Server and NULS is Named User License Server.
*/
#define ITK_incompatible_server_type_for_configuring_license_server             (TC_ERROR_BASE + 61)

/**
The license server "%1$" cannot have multiple license server setup, as it is an integration license server. Only a regular license server can have multiple license server.
*/
#define ITK_integration_server_cannot_have_multiple_license_server              (TC_ERROR_BASE + 62)

/**
The license server name is empty. Please provide a value.
*/
#define ITK_license_server_name_empty                                           (TC_ERROR_BASE + 63)

/**
The license server host name is empty. Please provide a value.
*/
#define ITK_license_server_host_name_empty                                      (TC_ERROR_BASE + 64)

/**
The license server "%1$" cannot be modified as the given license server is being used as one of the multiple server of "%2$". Please detach "%1$" from the "%2$" and change the type.
*/
#define ITK_cannot_modify_license_server_type_used_by_another_license_server    (TC_ERROR_BASE + 65)

/**
The license server "%1$" cannot have more than one integration license servers. Please provide only one integration license server.
*/
#define ITK_cannot_have_more_than_one_multiple_license_server                   (TC_ERROR_BASE + 66)

/**
A license server cannot be created or modified without a valid site. Please contact your system administrator.
*/
#define TC_license_server_requires_site                                         (TC_ERROR_BASE +67)

/** The environment variables TC_XML_ENCODING and UGII_UTF8_MODE are incorrectly setup in order to ensure proper UTF-8 support. "UGII_UTF8_MODE" must be set to "1" and "TC_XML_ENCODING" to "UTF-8". */
#define TC_mismatch_utf8_settings                                               (TC_ERROR_BASE + 68)

/** The Flexlm license server encountered a "tcrs_swim" license which is not valid for Teamcenter. Please contact your system administrator for further assistance. */
#define TC_no_access_permission_to_license_tcrs_swim                            (TC_ERROR_BASE + 69)

/** Integration License Server contains one or more named user licenses. Please contact your system administrator for further analysis. */
#define TC_license_server_only_connecting_first                                 (TC_ERROR_BASE + 70)

/** The starting and ending year cannot be blank. */
#define TC_blank_starting_ending_year                                           (TC_ERROR_BASE + 71)

/**  An invalid value has been passed for month. Following are the valid formats: numeric, month name or 3 letter abbreviation. */
#define TC_invalid_month_provided                                               (TC_ERROR_BASE + 72)

/** An invalid value has been passed for year. Valid year has to be between 1970 and 9999. */
#define TC_invalid_year_provided                                                (TC_ERROR_BASE + 73)

/** An invalid value has been passed for date range. An ending month/year cannot precede starting month/year. */
#define TC_invalid_date_range_provided                                          (TC_ERROR_BASE + 74)

/**
An integration license server "%1$" cannot be attached to "%2$". Only a named user license server can be attached.
*/
#define ITK_cannot_attach_integration_license_server                            (TC_ERROR_BASE + 75)

/**
The type of the default license server must be the Named User License Server (NULS).
*/
#define ITK_invalid_server_type_for_default_lisense_server                      (TC_ERROR_BASE + 76)

/**
The license server type of "%1$" cannot be modified because the given license server is attached to "%2$". Please detach "%1$" from "%2$" before changing the type.
*/
#define ITK_cannot_modify_license_server_type_attached_with_another_object      (TC_ERROR_BASE + 77)

/**
The name of the default local license server cannot be changed.
*/
#define ITK_cannot_change_license_server_name                                   (TC_ERROR_BASE + 78)

/**
User "%1$", needs to be at "%2$" seat level license to perform the "%3$" operation on "%4$" business object.
*/
#define TC_inappropriate_seat_level_license_for_operation                       (TC_ERROR_BASE + 79)

/** @} */

#endif
