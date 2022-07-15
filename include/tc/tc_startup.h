/*
  Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2009.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
   @file tc_startup.h

    This file was tc.h. Code was moved here to allow tc.h to call tcinit.h so
    that customized code calling tc.h would not have to change.
    New files should include tcinit.h.

   This file contains the prototypes for basic tc ITK usage.
   It also contains a few include files that contain the prototypes that
   almost every ITK program will use.

*/

/*  */

#ifndef TC_STARTUP_H
#define TC_STARTUP_H

#include <fclasses/tc_basic.h>
#include <pom/pom/pom.h>
#include <base_utils/Mem.h>
#include <stdarg.h>
#include <stdio.h>
#include <common/basic_definitions.h>

#include <tc/libtc_exports.h>

/**
   @defgroup TC Integration Tool Kit
   @{
*/

/** Default Text Mode for ITK Batch Program */
#define ITK_BATCH_TEXT_MODE     0

#ifdef __cplusplus
extern "C"
{
#endif

/**
   Main functions for all ITK utility.

   <br/>Create your own implementation of this utility to address your needs. The utility will need to be linked with itk_main.o,
   which is done if the linkitk.sh or linkitk.bat script from ADK (Application Development Kit) is called.

   <br/>The Teamcenter infrastructure will call your utility ITK_user_main upon execution.

   @param[in] argc The number of input arguments
   @param[in] argv The array of input arguments
*/
/* */
    extern int ITK_user_main(
        int argc,
        char** argv
        );

/**
   @name Login / Logout
   @{
*/
/**
   This function calls as much initialisation code as possible
   without actually logging in with a user name and password.
   Calling this before ITK_init_module may make ITK_init_module faster.
*/
    extern TC_API int ITK_init_to_login (void);


/**
   Initializes different key modules in the Teamcenter server.
   <br/>It internally calls #TC_init_cmain.

   @note Ensure that this ITK is called prior to calling #ITK_ask_cli_argument
   <br/>#ITK_user_main already calls #TC__initialise_tc.
*/
    extern TC_API void TC__initialise_tc(
        int  argc,                  /* <I> */
        char **  argv               /* <I> */
        );


/**
   Routine to initialize the basic system service routines from SYSS
   module.  It also initializes the Preferences module.
*/
    extern TC_API int TC_init_cmain (int argc, char **argv);

/**
   The original method, ITK_init_module, initializes the Integration Tool Kit (ITK) for use. \
    <br/>For convenience, also logs into the POM.
    <br/>This m ethod is now in libtcinit, and calls register_init_functions() followed by a call toTC_init_module.
    <br/>TC_init_module is the rest of the method that was not moved to tcinit.

    @warning #ITK_init_module or #ITK_auto_login must be called before calling any other ITK functions,
    unless otherwise stated in the description of specific ITK functions.
*/
    extern TC_API int TC_init_module(
        const char*     users_id,           /**< (I) */
        const char*     users_password,     /**< (I) */
        const char*     users_group         /**< (I) */
        );

/**
   Initializes TC for sponsored login

   @warning #TC_init_module_sponsored or #ITK_auto_login must be called before calling any other ITK functions,
   unless otherwise stated in the description of specific ITK functions.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_account_values if sponsoring user id, password or sponsored user id is invalid
   <li>#POM_invalid_name if the sponsored user name does not follow naming rules
   <li>#POM_user_and_group_invalid if sponsored user is not a member of the group
   </ul>
*/
    extern TC_API int TC_init_module_sponsored(
        const char*   user_id,                /**< (I) User id of the sponsoring user */
        const char*   user_password,          /**< (I) Password of the sponsoring user */
        const char*   sponsored_user,         /**< (I) User id of the sponsored user */
        const char*   sponsored_user_group    /**< (I) Sponsored user's group */
        );

/**
   ITK_init_module attempts an automatic login first by assuming sufficient data is available
   on the command line.

   @note If the site system administrator has set the TC_auto_login preference variable to TRUE,
   the user does not need to enter in a user name, password, or group in the command line.
   The operating system user name is assumed.
    <br/>However, if the user wants to use a login name other than their operating system name,
   they may use the command line format:
    <br/><b>your_program -u=\<user_id\> -p=\<password\> -g=\<group\> </b>
    <br/><br/>This method also leverages calls made using a password file through the '-pf=' parameter.
    <br/><b>your_program -u=\<user_id\> -pf=\<path_to_password_file\> -g=\<group\> </b>

   This method is now in libtcinit, and calls register_init_functions() followed by a call to
   TC_init_module, which is the old ITK_init_module() in infomanager_itk.cxx

*/
    extern TC_API int TC_auto_login(void);

/**
   Exits this module.
*/
    extern TC_API int ITK_exit_module(
        logical         ignore_unsaved_stuff    /**< (I) This flag is passed to #POM_stop.
                                                   If false, an error is returned if there are unsaved modified objects. */
        );


/** @} */




/**
   @name Teamcenter Version
   @{
*/
/**
   Retrieves the full version of the release (e.g. "10.1.4").

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SS_NOSUCHFILE if the resource file that contains the information cannot be retrieved.
   <li>#CAE_XML_failed_to_parse_xml_file if the parsing of the file that contains the version information has failed.
   </ul>
*/
    extern TC_API int ITK_ask_full_version(
        char** release                  /**< (OF) A string representing the Teamcenter release */
        );

/**
   Determines if the current Teamcenter release is higher or equal to the specified release.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SS_NOSUCHFILE if the resource file that contains the information cannot be retrieved.
   <li>#CAE_XML_failed_to_parse_xml_file if the parsing of the file that contains the version information has failed.
   <li>#ITK_invalid_version_format if @p minimum_version or the determined version release is not in the expected format (integers separated by the '.' character, e.g. "10.1.6.1").
   </ul>
*/
    extern TC_API int ITK_is_release_at_least(
        const char*   minimum_version,  /**< (I) A string representing the minimum Teamcenter version, e.g. "10.1.4".
                                           <br/>The string is composed of at least one group and up to 4 groups
                                           separated by the '.' character: the major version (mandatory), the minor version,
                                           the service pack, the patch.
                                           <br/>If either the service pack or the patch information is missing (e.g. "10.1.4"
                                           or "10.1"), the assumed value is "0".
                                           <br/>If the string is null or empty, the verdict is "true" and no error is returned.
                                           @note If the string contains a final period (e.g. "10.1."), the character is not taken
                                           into account (e.g. same as if the entered string is "10.1"). */
        logical*         verdict           /**< (O) "true" if the current Platform release is @p minimum_version or higher. */
        );

/**
   Determines if the current Teamcenter release is higher or equal to the specified release in the given release stream or in the absolute.

   @code
       logical verdict = false;
       if( ITK_ok == ITK_is_release_at_least_advanced( "10.1.5", false, &verdict ) && verdict )
       {
           //The code in here will be run with 10.1.5, 10.1.5.1, 10.1.7 (for example), but not for 11.2.1.
       }
       if( ITK_ok == ITK_is_release_at_least_advanced( "10.1.5", true, &verdict ) && verdict )
       {
           //The code in here will be run with 10.1.5, 10.1.5.1, 10.1.7 (for example), as well as 11.2.1, 11.2.2, etc.
       }
   @endcode

   @note Calling this API with @p in_absolute equal to @c true is the same as invoking #ITK_is_release_at_least.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SS_NOSUCHFILE if the resource file that contains the information cannot be retrieved.
   <li>#CAE_XML_failed_to_parse_xml_file if the parsing of the file that contains the version information has failed.
   <li>#ITK_invalid_version_format if @p minimum_version or the determined version release is not in the expected format (integers separated by the '.' character, e.g. "10.1.6.1").
   </ul>
*/
    extern TC_API int ITK_is_release_at_least_advanced(
        const char*   minimum_version,  /**< (I) A string representing the minimum Teamcenter version, e.g. "10.1.4".
                                           <br/>The string is composed of at least one group and up to 4 groups
                                           separated by the '.' character: the major version (mandatory), the minor version,
                                           the service pack, the patch.
                                           <br/>If either the service pack or the patch information is missing (e.g. "10.1.4"
                                           or "10.1"), the assumed value is "0".
                                           <br/>If the string is null or empty, the verdict is "true" and no error is returned.
                                           @note If the string contains a final period (e.g. "10.1."), the character is not taken
                                           into account (e.g. same as if the entered string is "10.1"). */
        const logical    in_absolute,   /**< (I) Determines if the check is made in the absolute (@c true) or only against the
                                           the major release (i.e. the first portion @p minimum_version; @c false). */
        logical*         verdict        /**< (O) "true" if the current Platform release is @p minimum_version or higher. */
        );
/** @} */

/**
   @name Journalling
   @{
*/
/**
   Sets journalling for the ITK, WSOM, AOM, and FL functions of Teamcenter.


   @note This function does not control normal journalling that takes place in a
   Teamcenter session -
   it only controls additional journalling that takes place inside your custom ITK code.
*/
    extern TC_API int ITK_set_journalling (
        int             on_or_off   /**< (I) Set to 0 to turn journalling off, or to non-zero to turn journalling on. */
        );

/**
   Asks the current state of the journalling flag as set via #ITK_set_journalling.
   This allows users to develop code that can dynamically switch journalling on or off.
   Expected use would be in exits and methods.

   Returns Journalling_enabled if true; Journalling_suppressed if false.
*/
    extern TC_API logical ITK_ask_journalling (void);
/** @} */


/**
   Sets the current state of the tcserver managed mode. TC_managed_mode is set to true if the tcserver is in 4 tier mode.
*/
    extern TC_API void ITK__set_managed_mode (
        logical             value   /**< (I) Set to 1 to indicate server is in managed mode. */
        );

/**
   Asks the current state of the tcserver managed mode. Returns true if the tcserver is in 4 tier mode

*/
    extern TC_API logical ITK__ask_managed_mode (void);

/**
   Returns the tag of the object passed to your program as an argument.
    <br/>For an Application Encapsulation shell, this is the tag of the selected Dataset.
    <br/>For a follow-up action, this is the tag of the Job.

   @note Ensure that #TC__initialise_tc has been invoked prior to this call.
*/
    extern TC_API int ITK_ask_object(
        tag_t*          objectId    /**< (O) */
        );

/**
   Returns the action passed to the shell program by Application Encapsulation or Release Management
   (e.g., create, open, save as, etc.). The AE actions are defined in ae.h.

   <b>Restrictions:</b>

   This function only returns the action code, not any argument to the code.
   Use #ITK_ask_action_argument to get the argument.

   @note Ensure that #TC__initialise_tc has been invoked prior to this call.
*/
    extern TC_API char* ITK_ask_action(void);

/**
   This function returns the argument that was passed to an ITK program from
   Teamcenter when an external ITK program is invoked through Teamcenter.

   There is a special parameter passed to the process that
   contains the tag of the object being acted on and the action.

   In order to get the tag of the dataset, the function should be invoked as follows:
   @code
   tag_string = ITK_ask_action_argument (NULL);
   @endcode
   In order to convert the tag_string to an actual tag, use #POM_string_to_tag.

   In order to get the format of the dataset, the function can be invoked as follows:
   @code
   format_string = ITK_ask_action_argument("-f");
   @endcode

   @note Ensure that #TC__initialise_tc has been invoked prior to this call.
*/
    extern TC_API char* ITK_ask_action_argument(
        const char*       key   /**< (I) */
        );

/**
    Returns the value associated with a command line argument.

   <b>Restrictions:</b>
    <ul>
    <li>The argument @p argument_name cannot contain a space character as its last character,
   if the value expected is to follow immediately.
    <br/>Whenever the last character is a space, the next argument,
    if any, is returned as the value of the function.</li>
    <li>The argument @p argument_name cannot exceed 255 characters.</li>
    </ul>

    <b>Usage:</b>
    <ul><li>If the program is called with @c command @c -i=on, use the call
    @c ITK_ask_cli_argument( @c "-i=" @c ) to retrieve the value @c on.</li>
    <li>If the program is called with @c command @c -i @c on, use the call
    @c ITK_ask_cli_argument( @c "-i " @c ) to retrieve the value @c on. <br/>Note how the string
    @c "-i " contains a space character.</li>
    </ul>

   @note Ensure that #TC__initialise_tc has been invoked prior to this call.
*/
    extern TC_API char* ITK_ask_cli_argument(
    const char*       argument_name   /**< (I) The name of the argument for which the value is to be returned. */
        );

/**
   Initializes the Teamcenter text services.
   This is necessary to get the correct error strings when you use #EMH_get_error_text,
   or by certain other Teamcenter functions that make use of text services, like forms.
*/
    extern TC_API int ITK_initialize_text_services(
        int             unused  /**< (I) The value is not used anymore */
        );

/**
   Returns the version control information.
*/
    extern TC_API int ITK_ask_update_level(
        int*            update_level    /**< (O) Version number of the release */
        );

/**
   Extracts the switch string and the corresponding value string from the argument string passed into the function.
    <br/>The format of the switch-value pair must conform to the following pattern: [^=]*=[^=]*.
    <br/>The switch and the value can be any alpha-numeric string that does not contain the equal (=) character.
    <br/>The equal (=) character is used to delimit the switch and the value.
*/
    extern TC_API int ITK_ask_argument_named_value(
        const char*     argument,   /**< (I) */
        char**          flag,       /**< (OF) */
        char**          value       /**< (OF) */
        );

/**
   Converts a #date_t structure into a text representation.
    <br/>The date is formatted according to the DefaultDateFormat string defined in timelocal_locale.xml localized text resource file.
*/
    extern TC_API int ITK_date_to_string (
        date_t          a_date,     /**< (I) Supplied date_t structure */
        char**          a_string    /**< (OF) Text representation of specified date */
        );

/**
   Converts a text string into a date_t structure.
    <br/>The string is assumed to be formatted according to the DefaultDateFormat value in time.uil.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_invalid_date if the string is not a valid date.
   </ul>
*/
    extern TC_API int ITK_string_to_date (
        const char*     a_string,   /**< (I) Specified date string */
        date_t*         a_date      /**< (O) Date as a date_t structure */
        );


/**
   Creates a text string from the current date, using the format defined by the key "DefaultDateFormat"
   in the localized text resource file "timelocal_locale.xml".

   @returns #ITK_ok always
*/
    extern TC_API int ITK_ask_default_date_format (
        char**          date_string     /**< (OF) */
        );

/**
   Allows a system administrator to bypass Access Manager controls on objects.
    <br/>Switching the bypass on typically allows the system administrator to modify, delete,
   or otherwise access objects at will.

    <br/><br/>When using the old AM, all access control is disabled by the bypass facility.
   However, the effect of bypass in the new AM is dependent on the Has Teamcenter::Bypass rule
   in the AM Rules Tree.

   @note It is recommended to use the C++ Bypass class object instead of this API.
   This class has a destructor which will reset the bypass when the object goes out of scope.
   This improves the handling of error conditions and reduces the chances that the bypass will last too long.

   The user must be a Teamcenter system administrator.
*/
    extern TC_API int ITK_set_bypass(
        logical         on_or_off   /**< (I) Whether to switch bypass on (true) or off (false) */
        );

/**
   Checks if bypass is switched on.
*/
    extern TC_API int ITK_ask_bypass(
        logical*        has_bypass  /**< (O) Whether bypass is switched on */
        );

    extern TC_API int ITK_set_in_ic_context(
        logical         on_or_off   /**< (I) */
        );

    extern TC_API int ITK_ask_in_ic_context(
        logical*        in_ic_context   /**< (O) */
        );

    extern TC_API int ITK_set_obj_edited_in_ic_context(
        tag_t obj                   /**< (I) */
        );

    extern TC_API int ITK_reset_obj_edited_in_ic_context(
        tag_t obj                   /**< (I) */
        );

    extern TC_API int  ITK_is_obj_edited_in_ic_context(
        tag_t obj,                  /**< (I) */
        logical* res                /**< (O) */
        );


    /**
    Loads the data from the given locations, converts them to character string equivalents and writes the results
    to the syslog file.
    */
    extern TC_API void TC_write_syslog (
        const char*      control_string,    /**< (I)  Pointer to a null-terminated string specifying how to interpret the
                                                      data. The format string consists of ordinary characters (except %),
                                                      which are copied unchanged into the syslog file, and conversion
                                                      specifications. Each conversion specification (% and characters following)
                                                      has the format as specificed in std::printf. <br>
                                                      All arguments following the control_string specify the data to print.
                                                      If any argument after default conversions is not the type expected by the
                                                      corresponding conversion specifier, or if there are fewer arguments than required by control_string,
                                                      the behavior is undefined. If there are more arguments than required by control_string,
                                                      the extraneous arguments are evaluated and ignored.
                                            */
        ...                                 /**< (I) */
        );

    /**
        Raises an exception (#ERROR_raise) using the error #ITK_internal_error as well as a given message.

        @note The macro #ERROR_line can be used to substitute both @p file_name and @p line_number parameters.
    */
    extern TC_API void TC_report_serious_error (
        const char*      file_name,         /**< (I) The file where the error has occurred. */
        int              line_number,       /**< (I) The line where the error has occurred. */
        const char*      error_message ,    /**< (I) The potentially parameterized message to be associated with the exception.
                                               <br/>@c \%s indicates a string parameter, @c \%d a digit, etc.
                                               <br/>The parameters are to be provided as subsequent arguments of this API. */
        ...                                 /**< (I) The parameters (if any) to be used in @p error_message. */
        );

/**
   Implemented in memorymonitorwindow.cxx

   Returns virtual memory use under various categories (some CPU types give more data than others)
   (These numbers may be of interest to ITK programmers, but probably not to system administrators)
*/
    extern TC_API int TC_ask_memory_statistics (
        int*            count,  /**< (O) */
        char***         names,  /**< (OF) count */
        int**           values  /**< (OF) count */
        );

/**
   Reports SM+OM in-use space. Ignores OM-UNDO
*/
    extern TC_API int TC_ask_memory_in_use ( void );

/**
 *   Prints the current memory statistics into a specified file.
 *   @param output_file - File pointer to an already opened output file where the memory statistics will be written out
 *   @return ITK_ok on success, on error returns ITK_internal_error
 */
    extern TC_API int TC_print_memory_statistics(
        FILE            *output_file            /**< (I) File pointer to an already opened output file where the memory statistics will be written out */
        );

/* NB the returned 'UID' is not persistent to another session for a BOM tag, and is invalid on PROP tags */
    extern TC_API void ITK__convert_tag_to_uid(
        tag_t            aTag,  /**< (I) */
        char**           uid    /**< (OF) */
        );

    extern TC_API void ITK__convert_uid_to_tag(
        const char*      uid,   /**< (I) */
        tag_t*           aTag   /**< (O) */
        );

/**
   Checks if the Teamcenter system is configured for UTF-8 encoding, and is running as such.
   <br/>The system comprises the server and the database.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TC_mismatch_utf8_settings if Teamcenter server is running in UTF-8 database and there is a mismatch in UTF-8 settings for environment variables TC_XML_ENCODING and UGII_UTF8_MODE.
       <br/>This is only applicable to Windows platform.
   </ul>
*/
extern TC_API int TC_is_system_running_utf8(
    logical* is_running_utf8                /**< (O) Determines if system is running in utf8. The value is
                                                    @c true if the Teamcenter system is properly configured for UTF-8 encoding, and is running as such.
                                                    @c false if the Teamcenter system is not configured for UTF-8 encoding.
                                                    */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <tc/libtc_undef.h>
#endif
