/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef LM_H
#define LM_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>
#include <tc/libtc_exports.h>

/**
    @defgroup LM Log Manager (LM)
    @ingroup TC

    The log manager module has been deprecated as of Tc11.  This functionality will be removed in Tc13.

    The Log Manager (LM) provides the ability to capture a number of significant system events in the log database.
    The events are categorized into five classes:

    <table>
    <tr><td>Security      </td><td>This log contains information regarding the attempted access to unauthorized data.
                                   The information maintained includes failed login events and attempts to
                                   access unauthorized objects in the database.                                </td></tr>
    <tr><td>Administration</td><td>This log tracks changes made to system objects such as 
                                   users, groups, volumes, etc., and system events such as releasing an object.</td></tr>
    <tr><td>Journal       </td><td>This is a session log which tracks objects accessed from the database and
                                   the activities performed on those objects, as well as a trace through software modules.
                                   Each time you invoke or exit a module, the Log Manager posts an entry.
                                   Anytime access to an object occurs, an entry which includes the action 
                                   (i.e., read, modify, create, delete, etc.) gets logged in the database.     </td></tr>
    <tr><td>System        </td><td>This log contains entries which are about the operation of the platform such as
                                   startup and shutdown events of Teamcenter.                      </td></tr>
    <tr><td>Application   </td><td>This log tracks actions performed on objects at a session level,
                                   such as creation of folders, etc.                                           </td></tr>
    </table>

    Teamcenter creates a set of logs to monitor the use of the system. 
    The logs can be broken up into two categories:
    <ul>
    <li>User logs
    <li>System logs
    </ul>

    These logs are created with names of the form \<application\>.\<jnl, trc, log\> 
    in the user's current working directory.
    The system logs are located in the directory \$TC_LOG directory and are called
    administration.log, installation.log, security.log, and system.log.

    The application log files contain high volume, application specific information.
    The log files contain information about significant events that take place in Teamcenter.
    These events include logging on to the system, creation of objects, deletion of objects, freezing of objects, etc.

    The journal and traceback files contain information regarding specific subroutine calls made in Teamcenter.

    The system logs record low volume, system events. 
    For example, the security log includes information regarding attempted protection violation by users.
    The administration log contains information such as creation of a new user, new group, or volume.
    The system log can contain information such as the release of an item or dataset.

    Preference files can control logging. 
    You can enable application logs by placing an entry in either the user or site preference file.
    The entries are:

    TC_Application_Logging={ON | OFF} <br>
    TC_Journalling={ON | OFF}

    Tracebacks cannot be disabled.

    You can control system logs by setting an environment variable.
    The variables are:

    TC_Administration_Logging={ON | OFF} <br>
    TC_Security_Logging={ON | OFF} <br>
    TC_System_Logging={ON | OFF} <br>
    TC_Installation_Logging={ON | OFF}

    The default is OFF if no environment variable is found or its value is not "ON".

    The logging system initializes itself when the first event is posted to a log.
    There are only a few routines for posting entries in the various logs.

    The event numbers reside in log.h in the directory \$TC_INCLUDE. 
    You can add your own user event numbers.
    Your new user event numbers must start with event number 9001.
    To add events, you define a new event number in log.h and create an appropriate message in 
    log_text.uil in the \$TC_SYS_UID_DIR directory.

    The character string parm that you supply in the post_event calls is inserted into 
    the log file to give more detailed information.

    @code
        LM_post_info(LM_application_log(),LM_CREATE, folder_name); 

        or

        LM_post_event(LM_security_log(), LM_ACCESS_VIOLATION, folder_tag, folder_name); 
    @endcode

    The format of the entries in the log files are: 
    event_num user_name (os_name, hostname, application, date/time) - operation [tag] [parm].

    @{
*/

#ifdef __cplusplus
 extern "C"{
#endif

/**
    You invoke the initialize function to prepare the log manager for subsequent use. 
    You can nest #LM_init_module. That is, it may be called many times before any call to #LM_exit_module.

    #LM_init_module no longer needs to be called. It is called automatically when an event is posted.

    @code
        #include <tc/lm.h> 

        procname()
        {
            int status;
            ...
            status = LM_init_module();
            if (status != ITK_ok)
            {
                ...perform error handling
            }
            
            log manager facility functions
            
            status = LM_exit_module();  
            if(status != ITK_ok)
            {
                ...perform error handling via EMH
            }
        } 
    @endcode
*/
extern TC_API int LM_init_module(void);

extern TC_API int LM_exit_module(void);

/**
    @name Log File IDs

    Routines to return the id of the particular log file for subsequent routines
    @{
*/

/** @deprecated #LM_application_log deprecated in Teamcenter 11.2. */
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_application_log")
extern TC_API int LM_application_log(void);

/** @deprecated #LM_administration_log deprecated in Teamcenter 11.2. */
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_administration_log")
extern TC_API int LM_administration_log(void);

/** @deprecated #LM_security_log deprecated in Teamcenter 11.2. */
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_security_log")
extern TC_API int LM_security_log(void);

/** @deprecated #LM_system_log deprecated in Teamcenter 11.2. */
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_system_log")
extern TC_API int LM_system_log(void);

/** @deprecated #LM_install_log deprecated in Teamcenter 11.2. */
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_install_log")
extern TC_API int LM_install_log(void);

/** @deprecated #LM_journal deprecated in Teamcenter 11.2. */
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_journal")
extern TC_API int LM_journal(void);

/** @} */

/**
    Routine to start and stop logging dynamically
*/
extern TC_API int LM_enable_logging (
    int             log_file    /**< (I) */
    );

extern TC_API int LM_disable_logging(
    int             log_file    /**< (I) */
    );

extern TC_API int LM_enabled(
    int             log_file    /**< (I) */
    );

/**
    @name Routines to post events to the log files
    @{
*/

/**
    @deprecated #LM_post_info deprecated in Teamcenter 11.2.
*/
TC_DEPRECATED_NO_REPLACEMENT("11.2", "LM_post_info")
extern TC_API int LM_post_info (
    int             log_file,   /**< (I) */
    int             event,      /**< (I) */
    const char*     parm        /**< (I) */
    );

/**
    @deprecated #LM_post_event deprecated in Teamcenter 9.1.2.7. Use #LM_post_info instead
*/
TC_DEPRECATED("9.1.2.7", "LM_post_event", "LM_post_info")
extern TC_API int LM_post_event(
    int             log_file,   /**< (I) */
    int             event,      /**< (I) */
    tag_t           tag,        /**< (I) */
    const char*     parm        /**< (I) */ 
    );

typedef enum LM_severity_e {
    LM_INFORMATION,         /**< NO SEVERITY ASSOCIATED */
    LM_ERROR,               /**< WARNING */
    LM_SEVERE,              /**< DATA MAY BE CORRUPT */
    LM_CRITICAL,            /**< DATA CORRUPT, SYSTEM MAY FAIL */
    LM_FATAL                /**< DATA CORRUPT SYSTEM FAILED */
} LM_severity_t;

typedef enum LM_exception_class_e {
    LM_SYSTEM_EXCEPTION,    /**< SYSTEM LEVEL EXCEPTION */
    LM_CORE_EXCEPTION,      /**< CORE DUMP CONDITION */
    LM_USER_EXCEPTION,      /**< END-USER EXCEPTION */
    LM_JOURNAL_EXCEPTION    /**< JOURNAL PROGRAM EXCEPTION */
} LM_exception_class_t;

extern TC_API int LM_post_journal_exception(
    tag_t                objectId,               /**< (I) */
    LM_exception_class_t exceptionType,          /**< (I) */
    LM_severity_t        exceptionSeverity,      /**< (I) */
    const char*          userMessage             /**< (I) */
    );

/** @} */

/** @} LM group */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif
