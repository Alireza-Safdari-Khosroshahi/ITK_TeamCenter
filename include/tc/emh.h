/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header defines the ITK interface to the Teamcenter error store.
*/

/*  */

#ifndef EMH_H
#define EMH_H

#include <tc/tc_startup.h>

#define EMH_severity_information    1
#define EMH_severity_warning        2
#define EMH_severity_error          3
#define EMH_severity_user_error     4

#include <tc/libtc_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @name Error severities
    @{
*/
#define EMH_WARNING                     1
#define EMH_SERIOUS                     2
#define EMH_FATAL                       3
/** @} */

/** Maximum size of error message */
#define EMH_MAXEMSG                     1024

/**
    @defgroup EMH Error Message Handler (EMH)
    @ingroup TC

    The Error Message Handler (EMH) ITK interface is defined in file emh.h.

    <b>New Error Handling For V3.2</b>
    Teamcenter stores errors on a central stack. An error may be posted at a low level and each layer of
    the code handles the error reported by the level below, potentially adding a new error of its
    own to the top of the stack to add more contextual information to the exception being reported.

    This stack of errors is what you see displayed in the Teamcenter error window at the UIF.
    ITK functions always return the top error from the stack (if there is one - if everything is ok
    #ITK_ok is returned). These functions enable you to access the full error stack, and also to
    decode individual Teamcenter error codes ('ifails') into the internationlized (I18N) texts
    that are defined in the UIL and displayed in the error windows at the UIF.

    @note It is desirable to inform Teamcenter that you have handled an error received from
          the ITK interface by calling #EMH_clear_errors.

    @note For compatibility with other ITK calls (unless otherwise specifically noted below)
          EMH functions return #ITK_ok, they do not return failure codes.



    <b>Migration From pre-V3.2 Error Handling</b>
    Prior to V3.2 errors were attached to individual objects, so the pre-V3.2 EMH functions needed
    the tag of an Teamcenter object as an argument. For V3.2 these functions are still supported,
    the tag argument is ignored and #NULLTAG may be supplied. However please do not use these functions for
    new code. (With due notice) they may be phased out sometime in the future.



    <b>Error Severity</b>
    Teamcenter errors are classified according to their severity.
    They can be errors, warnings, or information.
    Where an argument to an EMH function refers to severity,
    this can take values #EMH_severity_information, #EMH_severity_warning and #EMH_severity_error.
    The topmost severity is used as the title of any error window we display.
    #EMH_severity_error is the usual one to use.



    <b>User-Defined Error Codes</b>
    You can add you own error messages to Teamcenter ITK.
    Teamcenter has reserved an error message range expressly for this purpose.
    The reserved range for these user-defined error messages is: 919000 thru 919999.



    <b>Return Values</b>
    The EMH functions do not return failure codes,
    but for compatibility with other ITK calls (unless specifically noted otherwise)
    these functions always return the token #ITK_ok.



    <b>Customizing Error Messages in Portal</b>
    The procedure for creating custom error messages in Portal is as follows:
    <ol>
    <li>Update your code to include emh_const.h.
    <li>Add the \#define statement for your error message.
        For example:
        @code
            #define CONNECT_FAILURE (EMH_USER_error_base + 10)
        @endcode
    <li>Copy \%TC_MSG_ROOT\%\\&lt;desired_locale&gt;\\ue_errors.xml to your \%TC_USER_MSG_DIR\%.
    <li>Add a line to define the text string corresponding to your custom message in ue_errors.xml.
        For example, \<error id = "100"\> Unable to connect \</error\>.
    </ol>

    @{
*/

/**
    Adds the specified error code to the top of the error store.
*/
extern TC_API int EMH_store_error(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail      /**< (I) Code of the error being stored */
    );

/**
    Adds the specified error code to the top of the error store.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_error_s1(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Adds the specified error code to the top of the error store.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_error_s2(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Adds the specified error code to the top of the error store.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_error_s3(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Adds the specified error code to the top of the error store.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_error_s4(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s4         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Adds the specified error code to the top of the error store.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_error_s5(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s4,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s5         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Adds the specified error code to the top of the error store.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_error_s7(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s4,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s5,         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s6,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s7         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Resets the error store and stores the specified ifail code as the start of a new stack of errors.
    Equivalent to #EMH_clear_errors followed by #EMH_store_error.
*/
extern TC_API int EMH_store_initial_error(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail      /**< (I) Code of the error being stored */
    );

/**
    Resets the error store and stores the specified ifail code as the start of a new stack of errors.
    Equivalent to #EMH_clear_errors followed by #EMH_store_error.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_initial_error_s1(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Resets the error store and stores the specified ifail code as the start of a new stack of errors.
    Equivalent to #EMH_clear_errors followed by #EMH_store_error.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_initial_error_s2(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Resets the error store and stores the specified ifail code as the start of a new stack of errors.
    Equivalent to #EMH_clear_errors followed by #EMH_store_error.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_initial_error_s3(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Resets the error store and stores the specified ifail code as the start of a new stack of errors.
    Equivalent to #EMH_clear_errors followed by #EMH_store_error.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_initial_error_s4(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s4         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Resets the error store and stores the specified ifail code as the start of a new stack of errors.
    Equivalent to #EMH_clear_errors followed by #EMH_store_error.

    String arguments are substituted into the translated UIL string when the error is displayed in an error window,
    where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).
*/
extern TC_API int EMH_store_initial_error_s5(
    int             severity,  /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    int             ifail,     /**< (I) Code of the error being stored */
    const char*     s1,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s2,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s3,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s4,        /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    const char*     s5         /**< (I) Character string being substituted into the internationalized message
                                    associated with this ifail code */
    );

/**
    Gives the ifail on top of the error store.

    This will be the same as the last ifail code returned by an ITK call.

    If the error store is currently empty ifail will be returned zero.
*/
extern TC_API int EMH_ask_last_error(
    int*            ifail  /**< (O) Ifail code from the top of the error stack */
    );

/**
    Gives the severities, ifail codes, and associated internationalized texts for each error on the error store.

    Errors are in historical order (i.e., ifails[0] is from the bottom of the stack).

    The returned pointers are only valid until the next call is made to the ITK.
    You should not hang on to these pointers after this, or attempt to modify their contents in any way.
    texts[n_ifails-1] is the message corresponding to the most recent error
*/
extern TC_API int EMH_ask_errors(
    int*            n_ifails,      /**< (O) Number of errors in the error store */
    const int**     severities,    /**< (O) n_ifails #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
    const int**     ifails,        /**< (O) n_ifails Integer code for each error in the store */
    const char***   texts          /**< (O) n_ifails Internationalized text strings for each error in the store */
    );

/**
    Clears the entire error store up to the last protected mark. To clear errors before a protected mark you must clear the protect
    mark first.

    Ideally this should be called once you have handled an error condition reported by an ITK call.
*/
extern TC_API int EMH_clear_errors( void );

/**
    Removes the ifail currently at the top of the error store (i.e., the one stored most recently).

    You must give the ifail you intend removing,
    as confirmation that you have received and understood the error before removing it.
*/
extern TC_API int EMH_clear_last_error(
    int             ifail  /**< (I) Ifail code on the top of the error stack that you wish to remove */
    );

/**
    An error protect mark protects the current state of the error store against being cleared or overwritten.
    This is useful if you must make another ITK call (which theoretically may post errors of its own)
    as part of handling an error, for which you then want to display the error stack. For example:

    @code
        tag_t object;
        int mark;

        if ( ITK_call( object ) != ITK_ok )
        {
            char* name;
            EMH_set_protect_mark( &mark );
            ITK_ask_name( object, &name );

            EMH_clear_protect_mark( mark );
            EMH_ask_errors( ... );
            display_my_error( ... );
            EMH_clear_errors();
        }
    @endcode
*/
extern TC_API int EMH_set_protect_mark(
    int*            mark   /**< (O) Identifies the error protect mark */
    );

extern TC_API int EMH_clear_protect_mark(
    int             mark   /**< (I) Identifies the error protect mark */
    );

/**
    Returns the internationalized (I18N) text associated with the specified ifail code.
    Note the storage associated with this string must be freed after use by #MEM_free or #TC_free_text.

    @note This function operates outside the context of your current session.
    It simply translates a code into its equivalent text without
    filling in object properties specific to your session.
    If you require details of your current errors, use #EMH_ask_errors to print the error stack.
*/
extern TC_API int EMH_ask_error_text(
    int             ifail,     /**< (I) Integer ifail code */
    char**          text       /**< (OF) I18N text message corresponding to the ifail */
    );


/** @} EMH group */

#ifdef __cplusplus
}
#endif

#define EMH_MAX_NUM_EMSG 100

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @name Obsolete Functions

    The following functions have never been publicly documented,
    however we are attempting to maintain their intended functionality for migration purposes.
    Please do not use these functions in any new code.
    @{
*/

/**
    If index is zero, this returns the error codes currently on the error store.

    @note The error code are returned with the lowest-level error first.
    If index is non-zero, it returns just the index'th-1 error code.

    @note This functions returns the number of errors it is giving back,
    NOT an ifail code as is normal for Teamcenter ITK.

    @warning this routine expects you to have allocated space for int *codes yourself
*/
extern TC_API int EMH_get_error_codes(
    tag_t           tag,            /**< (I) */
    int             index_name,     /**< (I) */
    int             max,            /**< (I) */
    int*            codes           /**< (O) */
    );

/**
    If index is zero, this returns the error messages currently on the error store.

    @note The error messages are returned with the lowest-level error first.
    If index is non-zero, it returns just the index'th-1 error message.

    @note This functions returns the number of errors it is giving back,
    *NOT* an ifail code as is normal for Teamcenter ITK.

    @warning this routine expects you to have allocates space for
    char* msgs[] to be a max array of pointers to space for error text to be strcpy'd to.
    You almost certainly want to call #EMH_ask_errors instead
*/
extern TC_API int EMH_get_error_text(
    tag_t           tag,            /**< (I) */
    int             index_name,     /**< (I) */
    int             max,            /**< (I) */
    char*           msgs[]          /**< (O) */
    );

/**
    Generate an ERROR_note when this ifail occurs.
*/
extern TC_API int EMH_catch_ifail(
    int             ifail   /**< (I) */
    );

/**
    Report the earliest ERROR_raise and its associated traceback
*/
extern TC_API int EMH_ask_initial_traceback (
    const char *separator,      /**< (I) */
    char **traceback            /**< (OF) */
    );

/**
    Clear our memory of any ERROR_raises
*/
extern TC_API void EMH_clear_initial_traceback(void);


/**
    Copy our memory of any signals/ERROR_internals to the database, then clear it.
*/
extern TC_API void EMH_capture_initial_traceback(void);


/**
    A routine to force a re-open on the error text file
*/
extern TC_API void EMH_close_error_text_file(void);


/**
    A routine to call ERROR_ask_system_log
*/
extern TC_API char* EMH_ask_system_log( void );

/**
    Retrieves the path to the Teamcenter server syslog file.
    
    @returns #ITK_ok always
*/
extern TC_API int EMH_ask_system_log_filename (
            char**  file_path    /**< (OF) Path to the syslog file */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif
