/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Header file to define errors for eim system services
*/

/*  */

#ifndef SS_ERRORS_H
#define SS_ERRORS_H

#include <common/emh_const.h>

#include <ss/libss_exports.h>

/**
    @defgroup SS_ERRORS Errors
    @ingroup SS
    @{
*/

#define SS_ERROR_BASE         EMH_SS_error_base
#define PREF_ERROR_BASE       EMH_PREF_error_base

/** Invalid path name */
#define SS_NOPATH           (SS_ERROR_BASE + 1)

/** Unable to change directory */
#define SS_NOCHDIR          (SS_ERROR_BASE + 2)

/** Unable to change protection on file */
#define SS_NOCHMOD          (SS_ERROR_BASE + 3)

/** Unable to change ownership of file */
#define SS_NOCHOWN          (SS_ERROR_BASE + 4)

/** Unable to create a directory */
#define SS_NOMKDIR          (SS_ERROR_BASE + 5)

/** Unable to delete a directory */
#define SS_NORMDIR          (SS_ERROR_BASE + 6)

/** Unable to get user id */
#define SS_NOGETUID         (SS_ERROR_BASE + 11)

/** Unable to set user id */
#define SS_NOSETUID         (SS_ERROR_BASE + 12)

/** Unable to get group id */
#define SS_NOGETGID         (SS_ERROR_BASE + 13)

/** Invalid reference to non-local process */
#define SS_NONLOCALPID      (SS_ERROR_BASE + 15)

/** Unable to signal process */
#define SS_NOSIG            (SS_ERROR_BASE + 16)

/** Unable to create process */
#define SS_NOPROC           (SS_ERROR_BASE + 17)

/** Path name too long for system call */
#define SS_PATHTOOBIG       (SS_ERROR_BASE + 18)

/** Wait terminated prematurely */
#define SS_WAITTERM         (SS_ERROR_BASE + 19)

/** Unable to get host name */
#define SS_NOHOST           (SS_ERROR_BASE + 20)

/** Unable to get host id number */
#define SS_NOHOSTADDR       (SS_ERROR_BASE + 21)

/** Unable to allocate memory */
#define SS_NOMEM            (SS_ERROR_BASE + 23)

/** Memory was not allocated prior to call */
#define SS_NOMEMALLOCATED   (SS_ERROR_BASE + 24)

/** Unable to create ipc queue */
#define SS_NOCRTIPC         (SS_ERROR_BASE + 37)

/** Unable to delete ipc queue */
#define SS_NODELIPC         (SS_ERROR_BASE + 39)

/** Unable to execute the process */
#define SS_NOEXECUTE        (SS_ERROR_BASE + 40)

/** Access to file or directory denied */
#define SS_NOACCESS         (SS_ERROR_BASE + 41)

/** Unable to send message to queue */
#define SS_NOSNDMSG         (SS_ERROR_BASE + 42)

/** Unable to receive message from queue */
#define SS_NORCVMSG         (SS_ERROR_BASE + 43)

/** No message was queued on the queue */
#define SS_NOMSGAVAIL       (SS_ERROR_BASE + 44)

/** Invalid message size */
#define SS_BADMSGSIZE       (SS_ERROR_BASE + 46)

/** Message was too big for buffer */
#define SS_MSGTOOBIG        (SS_ERROR_BASE + 47)

/** Unable to notify process of message */
#define SS_NONOTIFY         (SS_ERROR_BASE + 48)

/** Unable to create ipc entry in table */
#define SS_NOIPCENTRY       (SS_ERROR_BASE + 49)

/** Unable to find ipc entry in table */
#define SS_NOSUCHIPC        (SS_ERROR_BASE + 50)

/** Unable to delete ipc entry from table */
#define SS_NOFREEIPC        (SS_ERROR_BASE + 51)

/** Unable to set message handler */
#define SS_NOMSGHAND        (SS_ERROR_BASE + 52)

/** Queue is disabled */
#define SS_QUEDISABLED      (SS_ERROR_BASE + 53)

/** Process did not delay desired time */
#define SS_NOSLEEP          (SS_ERROR_BASE + 54)

/** Unable to set signal handler */
#define SS_NOSIGHAN         (SS_ERROR_BASE + 55)

/** Unable to get login name */
#define SS_NOLOGINNAME      (SS_ERROR_BASE + 56)

/** Invalid pid */
#define SS_INVPID           (SS_ERROR_BASE + 57)

/** Environment variable does not exist */
#define SS_NOSUCHVAR        (SS_ERROR_BASE + 58)

/** Unable to set environment variable */
#define SS_NOSETVAR         (SS_ERROR_BASE + 59)

/** Unable to get time */
#define SS_NOTIME           (SS_ERROR_BASE + 60)

/** Unable to initialize CFI */
#define SS_NOCFI            (SS_ERROR_BASE + 70)

/** Unable to create file */
#define SS_NOCREATE         (SS_ERROR_BASE + 71)

/** File already exists */
#define SS_FILEEXISTS       (SS_ERROR_BASE + 72)

/** File does not exist */
#define SS_NOSUCHFILE       (SS_ERROR_BASE + 73)

/** Unable to open file */
#define SS_NOOPEN           (SS_ERROR_BASE + 74)

/** Unable to close file */
#define SS_NOCLOSE          (SS_ERROR_BASE + 75)

/** Invalid open mode */
#define SS_INVMODE          (SS_ERROR_BASE + 76)

/** Unable to delete a file */
#define SS_NODELETE         (SS_ERROR_BASE + 77)

/** Unable to rename file */
#define SS_NORENAME         (SS_ERROR_BASE + 78)

/** Invalid context for this operation */
#define SS_BADCONTEXT       (SS_ERROR_BASE + 80)

/** Unable to read data */
#define SS_NOREAD           (SS_ERROR_BASE + 81)

/** Unable to write data */
#define SS_NOWRITE          (SS_ERROR_BASE + 82)

/** Unable to position the file */
#define SS_NOSEEK           (SS_ERROR_BASE + 84)

/** Unable to copy the file */
#define SS_NOCOPY           (SS_ERROR_BASE + 85)

/** Unable to move the file */
#define SS_NOMOVE           (SS_ERROR_BASE + 86)

/** Unable to get file stats */
#define SS_NOSTAT           (SS_ERROR_BASE + 87)

/** File is already open */
#define SS_ALREADYOPEN      (SS_ERROR_BASE + 89)

/** File is in use */
#define SS_FILEBUSY         (SS_ERROR_BASE + 90)

/** File is not open */
#define SS_FILENOTOPEN      (SS_ERROR_BASE + 91)

/** Invalid file descriptor */
#define SS_INV_FD           (SS_ERROR_BASE + 92)

/** Invalid user name */
#define SS_NO_SUCH_USER     (SS_ERROR_BASE + 93)

/** Invalid locale. Check LC_ALL or LANG environment */
#define SS_BAD_LOCALE       (SS_ERROR_BASE + 94)

/** Bad function name */
#define SS_BADFUNCNAME      (SS_ERROR_BASE + 95)

/** Unable to get function address */
#define SS_NOGETADDR        (SS_ERROR_BASE + 96)

/** TC_LIBRARY env var is undefined */
#define SS_NOLIBENV         (SS_ERROR_BASE + 97)

/** Unable to read from pipe */
#define SS_NOPIPEREAD       (SS_ERROR_BASE + 98)

/** Unable to write to pipe */
#define SS_NOPIPEWRITE      (SS_ERROR_BASE + 99)

/** Unable to open directory */
#define SS_NOOPENDIR        (SS_ERROR_BASE + 100)

/** Unable to close directory */
#define SS_NOCLOSEDIR       (SS_ERROR_BASE + 101)

/** Unable to read directory entry */
#define SS_NOREADDIR        (SS_ERROR_BASE + 102)

/** Directory already exists */
#define SS_DIREXISTS        (SS_ERROR_BASE + 103)

/** End of File Encountered */
#define SS_EOF              (SS_ERROR_BASE + 104)

/** Unable to get Current Directory */
#define SS_NOCWD            (SS_ERROR_BASE + 105)

/** Directory does not exist */
#define SS_NOSUCHDIR        (SS_ERROR_BASE + 106)

/** Unable to classify pathname */
#define SS_NOCLASSIFY       (SS_ERROR_BASE + 111)

/** File is not translatable */
#define SS_NOT_TRANS        (SS_ERROR_BASE + 116)

/** Invalid data type for translation */
#define SS_INV_DTYPE        (SS_ERROR_BASE + 117)

/** String is too large to print */
#define SS_STRTOOBIG        (SS_ERROR_BASE + 118)

/** Too many arguments for read */
#define SS_TOOMANYARGS      (SS_ERROR_BASE + 119)

/** Unable to print file */
#define SS_NOPRINT          (SS_ERROR_BASE + 120)

/** Process does not exist */
#define SS_NO_SUCH_PROC     (SS_ERROR_BASE + 121)

/** Invalid NFS Configuration file */
#define SS_INV_CFG_FILE     (SS_ERROR_BASE + 123)

/** Unable to get process status */
#define SS_NOPROCSTAT       (SS_ERROR_BASE + 130)

/** Encoding conversion failed */
#define SS_NOCONVERSION     (SS_ERROR_BASE + 131)

/* Errors for loading shared library at run time */
/*returned when the call to load a library (dlopen or LoadLibrary) fails.*/
#define SS_shlib_invalid_library  (SS_ERROR_BASE + 140)

#define SS_shlib_no_sym           (SS_ERROR_BASE + 141)
#define SS_shlib_no_memory        (SS_ERROR_BASE + 142)

/* the shared library file does not exist */
#define SS_shlib_no_such_file     (SS_ERROR_BASE + 143)
#define SS_shlib_exception_caught (SS_ERROR_BASE + 144)
/* if running a managed method threw an exception when trying to invoke it */
#define SS_shlib_invocation_exception (SS_ERROR_BASE + 145)

/* generic catch all for other errors */
#define SS_shlib_operation_failed (SS_ERROR_BASE + 146)

/* NOTE: please don't use 1147-1200.  They are reserved for additional
loading shared library errors */

/**
    @name Date & Time errors
    @{
*/

/** Invalid day of the week */
#define SS_invDayOfWeek     (SS_ERROR_BASE + 201)

/** Invalid day of the month */
#define SS_invDayOfMonth    (SS_ERROR_BASE + 202)

/** Invalid day of the year */
#define SS_invDayOfYear     (SS_ERROR_BASE + 203)

/** Invalid month name */
#define SS_invMonth         (SS_ERROR_BASE + 204)

/** Input year out of bounds */
#define SS_yearBounds       (SS_ERROR_BASE + 205)

/** Input month number out of bounds */
#define SS_monthBounds      (SS_ERROR_BASE + 206)

/** Input week number out of bounds */
#define SS_weekBounds       (SS_ERROR_BASE + 207)

/** Input hours out of bounds */
#define SS_12hourBounds     (SS_ERROR_BASE + 208)

/** Input hours out of bounds */
#define SS_24hourBounds     (SS_ERROR_BASE + 209)

/** Input minutes out of bounds */
#define SS_minuteBounds     (SS_ERROR_BASE + 210)

/** Input seconds out of bounds */
#define SS_secondBounds     (SS_ERROR_BASE + 211)

/** Time zone invalid */
#define SS_invTimeZone      (SS_ERROR_BASE + 212)

/** Function is not implemented */
#define SS_NOT_IMPLEMENTED  (SS_ERROR_BASE + 300)

/** @} */

/**
    @name PreferenceFile errors
    @{
*/

/** Preference not found */
#define PF_NOTFOUND                                                  ( PREF_ERROR_BASE + 0 )

/** Preference value index out of bounds */
#define PF_BOUNDS                                                    ( PREF_ERROR_BASE + 1 )

/** Preferences have not been loaded */
#define PF_NOTLOADED                                                 ( PREF_ERROR_BASE + 2 )

/** Internal error in preference file processing */
#define PF_ERROR                                                     ( PREF_ERROR_BASE + 3 )

/** Unable to load preference file */
#define PF_NO_LOAD                                                   ( PREF_ERROR_BASE + 4 )

/** Unable retreiving a particular value of a preference */
#define PF_VALUES                                                    ( PREF_ERROR_BASE + 5 )

/** Preference value not been defined consistently */
#define PF_CONFLICT                                                  ( PREF_ERROR_BASE + 6 )

/** Preference value not been defined correctly */
#define PF_INVALID                                                   ( PREF_ERROR_BASE + 7 )

/** No preferences found for export */
#define PF_NOTHING_TO_EXPORT                                         ( PREF_ERROR_BASE + 8 )

/** Cannot delete COTS preference */
#define PF_CANNOT_DELETE_COTS                                        ( PREF_ERROR_BASE + 9 )

/** Locked by same user */
#define PF_LOCKED_BY_SAME_USER                                       ( PREF_ERROR_BASE + 10 )

/** Locked by another user */
#define PF_LOCKED_BY_ANOTHER_USER                                    ( PREF_ERROR_BASE + 11 )

/** Preferences have not been locked */
#define PF_NOT_LOCKED                                                ( PREF_ERROR_BASE + 12 )

/** In SOA call to TcSOAAdministration setPreferences, the SITE scope is incompatible with an object being passed. */
#define PF_INCONSISTENT_SCOPE_DEFINITION                             ( PREF_ERROR_BASE + 13 )

/** NULL value is passed to the set for a preference. */
#define PF_NULL_VALUE                                                ( PREF_ERROR_BASE + 14 )

/** Preference is not deleted as it is not found in the given scope. */
#define PF_NOT_DELETED                                               ( PREF_ERROR_BASE + 15 )

/** Memory has failed to be allocated. */
#define PF_NOMEM                                                     ( PREF_ERROR_BASE + 16 )

/** The current logged-in user does not have system administrator privileges. */
#define PREF_user_not_system_admin                                   ( PREF_ERROR_BASE + 20 )

/** The protection scope of the preference cannot be changed because it is a System preference. */
#define PREF_cannot_change_protection_scope_of_system_pref           ( PREF_ERROR_BASE + 21 )

/** The preference cannot be converted to a System preference because it is an out-of-the-box Hierarchical preference. */
#define PREF_cannot_convert_to_system_pref                           ( PREF_ERROR_BASE + 22 )

/** The protection scopes of the following preferences cannot be changed because they are System preferences. */
#define PREF_cannot_change_protection_scope_of_system_prefs          ( PREF_ERROR_BASE + 23 )

/** The preferences cannot be converted to a System preference because it has out-of-the-box Hierarchical preferences. */
#define PREF_cannot_convert_to_system_prefs                          ( PREF_ERROR_BASE + 24 )

/** The current logged-in user does not have the necessary privileges to carry out the preference action. */
#define PREF_insufficient_privileges                                 ( PREF_ERROR_BASE + 25 )

/** The preferences do not exist in the DB. */
#define PREF_preferences_not_existing                                ( PREF_ERROR_BASE + 27 )

/** The protection scope of the preference does not allow to set a value at the proposed location */
#define PREF_value_cannot_be_set_at_location                         ( PREF_ERROR_BASE + 28 )

/** The specified level does not match the existing protection scope for the preference. */
#define PREF_value_cannot_be_asked_at_location                       ( PREF_ERROR_BASE + 29 )

/** The provided protection scope is invalid. */
#define PREF_invalid_protection_scope                                ( PREF_ERROR_BASE + 30 )

/** The provided location is invalid */
#define PREF_invalid_location                                        ( PREF_ERROR_BASE + 31 )

/** Specified object information does not correspond to any user, role or group  */
#define PREF_invalid_location_input                                  ( PREF_ERROR_BASE + 51 )

/** Both an object and a location are specified  */
#define PREF_duplicate_location_input                                ( PREF_ERROR_BASE + 52 )

/** Specified locations is invalid  */
#define PREF_invalid_location_for_operation                          ( PREF_ERROR_BASE + 53 )

/** Preference has not been created yet. This parameter is mandatory */
#define PREF_missing_definition_parameter                            ( PREF_ERROR_BASE + 55 )

/** Preference definition parameter value is invalid */
#define PREF_invalid_definition_value                                ( PREF_ERROR_BASE + 56 )

/** The value "%1$" given to the parameter "%2$" for the preference "%3$" is invalid,
    because this is an out-of-the-box preference and the parameter expected value is "%4$". */
#define PREF_parameter_value_not_applicable_to_ootb_preferences      ( PREF_ERROR_BASE + 57 )

/** Preference is a COTS preference with protection scope of System */
#define PREF_no_protection_scope_change_on_ootb_system_preference    ( PREF_ERROR_BASE + 58 )

/** The name of the preference is missing */
#define PREF_missing_preference_name                                 ( PREF_ERROR_BASE + 59 )

/** The provided preference name is invalid. */
#define PREF_invalid_preference_name                                 ( PREF_ERROR_BASE + 60 )

/** The specified level does not match the existing protection scope for the preference. */
#define PREF_value_cannot_be_removed_at_location                     ( PREF_ERROR_BASE + 61 )

/** Could not find scope for the provided UID "%1$". */
#define PREF_uid_scope_not_found                                     ( PREF_ERROR_BASE + 62 )

/**Could not delete COTS preference definition. */
#define PREF_cannot_delete_ootb_preference_definition                ( PREF_ERROR_BASE + 63 )

/**Could not delete preference definition. */
#define PREF_cannot_delete_preference_definition                     ( PREF_ERROR_BASE + 64 )

/** Tha arguments passed-in the delete definition operation (ITK or SOA) are inconsistent. */
#define PREF_delete_definitions_incorrect_arguments                  ( PREF_ERROR_BASE + 65 )

/** An invalid value is provided for environment variable flag. Valid values are "true" or "false" */
#define PREF_invalid_value_for_env_variable_flag                     ( PREF_ERROR_BASE + 66 )

/** The preference cannot be created as new because it already exists */
#define PREF_cannot_create__pref_already_exists                      ( PREF_ERROR_BASE + 67 )

/** An error was spotted in the imported preference file for the preference mentioned */
#define PREF_import__error_in_pref_definition                        ( PREF_ERROR_BASE + 68 )

/** Preference is a Hierarchical COTS preference: it cannot be changed to a System preference */
#define PREF_ootb_hierarchical_cannot_be_changed_to_system           ( PREF_ERROR_BASE + 69 )

/** The "version" attribute is wrong or missing from the "preferences" tag in the input preferences XML file  */
#define PREF_invalid_version                                         ( PREF_ERROR_BASE + 70 )

/** The value "%1$" is invalid for the preference "%2$" of type integer. */
#define PREF_not_a_int_value                                         ( PREF_ERROR_BASE + 71 )

/** The value "%1$" is invalid for the preference "%2$" of type double. */
#define PREF_not_a_double_value                                      ( PREF_ERROR_BASE + 72 )

/** The value "%1$" is invalid for the preference "%2$" of type date. */
#define PREF_not_a_date_value                                        ( PREF_ERROR_BASE + 73 )

/** The value "%1$" is invalid for the preference "%2$" of type logical. */
#define PREF_not_a_logical_value                                     ( PREF_ERROR_BASE + 74 )

/** The instance to be removed for the preference "%1$" does not exist at the location "%2$". */
#define PREF_instance_not_found_at_location                          ( PREF_ERROR_BASE + 75 )

/** Some errors have occurred while importing the preferences. Please check the detailed report file (if using the 'preferences_manager' utility), or the Teamcenter server syslog file (otherwise). */
#define PREF_report_import_pref_partial_error                        ( PREF_ERROR_BASE + 76 )

/** The category "%1$" could not be created, because it already exists. */
#define PREF_cannot_create_category_already_exists                   ( PREF_ERROR_BASE + 78 )

/** The PREF version could not be increased for the vision number "%1$". */
#define PREF_fail_to_increment_version                               ( PREF_ERROR_BASE + 79 )

/** Fail to insert the preference in shared memory. */
#define PREF_fail_to_insert_to_shared                                ( PREF_ERROR_BASE + 81 )

/** The PREF version could not be found. */
#define PREF_fail_to_get_version                                     ( PREF_ERROR_BASE + 82 )

/** Fail to load the preference for "%1$". */
#define PREF_fail_to_load_preferences                                ( PREF_ERROR_BASE + 83 )

/** Fail to load the create and populate shared memory. */
#define PREF_fail_to_populate_shared_memory                          ( PREF_ERROR_BASE + 84 )

/** Fail to store the preference file, locked "%1$". */
#define PREF_fail_to_store_file                                      ( PREF_ERROR_BASE + 85 )

/** Fail to sync the preference master memory. Size is zero */
#define PREF_fail_to_sync_master_memory                              ( PREF_ERROR_BASE + 86 )

/** Not supposed to enter the shared preference function "%1$" */
#define PREF_function_not_supported_in_share                         ( PREF_ERROR_BASE + 87 )

/** Fail to consistency check */
#define PREF_fail_to_check_consistency                               ( PREF_ERROR_BASE + 89 )

/** Fail to get mutex */
#define PREF_mutex_unavailable                                       ( PREF_ERROR_BASE + 90 )

/** The shared memory Preferences master data could not be created at this location: %1$. The system is reverting to using in-process memory for Preferences. Please report this error to your system administrator. */
#define PREF_error_creating_preferences_master_metadata              ( PREF_ERROR_BASE + 91 )

/** The preferences could not be exported using the "Manage Administrative Data" mode. Please refer to the syslog file for more information. */
#define PREF_fail_to_export_manage_admin_data                        ( PREF_ERROR_BASE + 92 )

/** No preferences are exported, because the following stylesheet-related preferences are not found: %1$. */
#define PREF_nothing_to_export_for_stylesheet                        ( PREF_ERROR_BASE + 93 )

/** The preferences related to the location "%2" with ID "%1$" are not exported, because no Global Site Identity record cannot be found for it. */
#define PREF_invalid_gsid_for_owner                                  ( PREF_ERROR_BASE + 94 )

/** The supplied date "%1$" is either invalid or its format is incorrect. */
#define PREF_invalid_date                                            ( PREF_ERROR_BASE + 95 )

/** Parsing, exporting or importing of preferences files are not supported in Shared Memory mode when the file contains Manage Admininistrative data. */
#define PREF_fail_to_process_manage_admin_data_format                ( PREF_ERROR_BASE + 96 )

/** The "Manage Administrative Data" file "%1$" could not be imported. Please check the content and format of the input file for correctness.  */
#define PREF_fail_to_import_manage_admin_data                        ( PREF_ERROR_BASE + 97 )

/** The preferences import operation has failed, because the source site ID could not be found in the input "Manage Administrative Data" file "%1$". Please check the input file for correctness.*/
#define PREF_unable_to_find_source_site_id                           ( PREF_ERROR_BASE + 98 )

/** The preferences import operation has failed, because the candidate key could not be found in the input "Manage Administrative Data" file "%1$". Please check the input file for correctness. */
#define PREF_fail_to_process_import_mode                             ( PREF_ERROR_BASE + 99 )

/** The preferences import operation has failed, because the instances could not be found in the input "Manage Administrative Data" file "%1$". Please check the input file for correctness. */
#define PREF_fail_to_import_instances_manage_admin_data              ( PREF_ERROR_BASE + 100 )

/** The preferences import operation has failed, because the organization preference instance could not be found in the input "Manage Administrative Data" file "%1$". Please check the input file for correctness. */
#define PREF_fail_to_update_org_instance_for_manage_admin_data       ( PREF_ERROR_BASE + 101 )

/** The creation or modification of preferences has failed because the maximum size for preferences has been reached by the system. Please contact your system administrator. */
#define PREF_number_preferences_limit_reached                        ( PREF_ERROR_BASE + 102 )

/** The creation or modification of preferences has failed because preferences are locked by the same user in another session. Please either release the lock in the other session or close the other session, then try again. */
#define PREF_lock_by_other_session                                   ( PREF_ERROR_BASE + 103 )

/** The values for preference "%1$" cannot be set because the preference definition does not exist. Please contact your system administrator. */
#define PREF_definition_not_exist                                    ( PREF_ERROR_BASE + 104 )

/** The creation or modification of preferences has failed because an invalid preference type "%1$" has been specified. Please contact your system administrator. */
#define PREF_definition_type_invalid                                 ( PREF_ERROR_BASE + 105 )

/** A value of type "%3$" is entered for the preference "%1$", but the preference's data type is "%2$". */
#define PREF_not_of_specified_type                                   ( PREF_ERROR_BASE + 106 )

/** The default values for the preference "%1$" cannot be deleted. */
#define PREF_not_allow_default_value_instance_delete                 ( PREF_ERROR_BASE + 107 )

/** The value "%1$" given to the parameter "%2$" for the preference "%3$" is invalid. The expected value is "%4$". */
#define PREF_parameter_value_change_not_expected                     ( PREF_ERROR_BASE + 108 )

/** The preference category "%1$" does not exist. */
#define PREF_category_not_exist                                      ( PREF_ERROR_BASE + 109 )

/** The preference category "%1$" cannot be deleted because one or more preferences are using that category. */
#define PREF_category_used                                           ( PREF_ERROR_BASE + 110 )

/** The creation or modification of the preference "%1$" failed, because the value provided for the preference is greater than the maximum allowed size of 4000 bytes at the following positions: %2$. */
#define PREF_long_value                                              ( PREF_ERROR_BASE + 111 )


/** @} */

/** @} */

#include <ss/libss_undef.h>

#endif
