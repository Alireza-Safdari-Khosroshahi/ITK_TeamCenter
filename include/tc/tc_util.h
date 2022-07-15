/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Utility functions for Teamcenter
*/

/*  */

#ifndef TC_UTIL_H
#define TC_UTIL_H

/** @if DOX_IGNORE
    For "logical" -- coding standards demand that each .c file include unidefs anyway
@endif */
#include <unidefs.h>
#include <stdarg.h>

#include <fclasses/tc_stdio.h>

#include <tc/libtc_exports.h>

/**
    @defgroup TC_UTIL Teamcenter Utility
    @ingroup TC
    @{
*/

/**
    Defines different types of Teamcenter URLs depending on the client types.
    @note The input value HTML is for legacy web client and is obsolete
*/
typedef enum URLFormat_e {
    PORTAL, /**< Teamcenter Rich Client URL. */
    DHTML,  /**< Teamcenter Thin Client(DHTML) URL. */
    HTML,   /**< Teamcenter Thin Client(HTML) URL. This Client Does Not Exist Anymore. */
    AWC,    /**< Teamcenter Active Workspace URL. */
    SHF     /**< Teamcenter SoftLine, HardLines and Footwear Web Client URL. */
} urlFormat_t;

#ifdef __cplusplus
extern "C"{
#endif

extern TC_API int TC_alloc_fixed_array(
    int             count,
    int             element_size,
    char***         new_memory
    );

extern TC_API char** TC_pack_strings(
    int                nstrings,
    char**             strings,
    char***            packed_strings
    );

extern TC_API char** TC_pack_strings_transient(
    int                nstrings,
    char**             strings,
    char***            packed_strings
    );

/**
    Given an array of MEM_alloc()ed strings, calls #MEM_free on each element and then #MEM_free on the array itself.
    This is useful for freeing unpacked string arrays. (Use #MEM_free on packed strings.)
    This is null-pointer-proof, just as all good freeing functions should be.
*/
extern TC_API void TC_free_strings (
    char**           array
    );

/**
    Cover for SS_getenv, returns a static (hence never null)
*/
extern TC_API const char* TC_getenv (
    const char*             value
    );

/**
    Wrapper function to the fopen() function to ensure the file whose pathname is UTF-8 encoded is open correctly 
    when Teamcenter is running in the UTF-8 mode.

    The parameter "mode" is the string containing a file access mode. It can be:
    <ul>
        <li> "r"  - read
        <li> "w"  - write
        <li> "a"  - append
        <li> "r+" - read/update
        <li> "w+" - write/update
        <li> "a+" - append/update
    </ul>

    The function returns a pointer to the opened FILE object. 
*/
extern TC_API FILE * TC_fopen (
    const char *filename,           /**< (I) The string containing the name of the file to be opened (can include path) */ 
    const char *mode                /**< (I) The string containing a file access mode */
    );

/**
    Wrapper function to the printf() to handle console printing of formatted data for the case when Teamcenter is 
    running in either non-UTF-8 or UTF-8 mode.

    On success, the function returns the total number of characters written. If a writing error occurs, a negative
    number is returned.

    For example:
    @code
        TC_printf( "Example: output of string1 (%s) and string2 (%s) with UTF-8 format\n", stringValue1, stringValue2 ); 
    @endcode
*/
extern TC_API int TC_printf( 
    const char * format,       /**< (I) String formart that contains the text to be written to stdout */
    ...                        /**< (I) Additional arguments */
    );

/**
    Wrapper function to the fprintf() to handle both console and file stream printing of formatted data when Teamcenter is 
    running in either Non UTF-8 or UTF-8 mode.

    On success, the function returns the total number of characters written. If a writing error occurs, a negative
    number is returned.

    For example:
    @code
        FILE *outFile;
        TC_fprintf( outFile, "Example: output of string1 (%s) and string2 (%s) with UTF-8 format\n", stringValue1, stringValue2 ); 
    @endcode
*/
extern TC_API int TC_fprintf( 
    FILE *fp,                   /**< (I) Pointer to a FILE object that identifies an output stream */ 
    const char * format,        /**< (I) The string contains the format string of the output */
    ...                         /**< (I) additional arguments */
    );

/**
    Wrapper function to the vfprintf() to write formatted data from variable argument list to stream for the case
    when Teamcenter is running in either Non UTF-8 or UTF-8 mode.

    On success, the  function returns the total number of characters written. If a writing error occurs, a negative
    number is returned.
*/
extern TC_API int TC_vfprintf(
    FILE * stream,                /**< (I)  pointer to a FILE object that identifies an output stream  */
    const char * format,          /**< (I)  The string contains the format string of the output */
    va_list arg                   /**< (I)  A value identifies a variable argument lists */
    );

/**
    Invokes the command processor to execute a system command. It is a wrapper function to the system() API to handle
    command string properly for the case when Teamcenter is running in either non-UTF-8 or UTF-8 mode.


    A null pointer can be provided as the command string to check for the existence of command processor.

    The function returns the status code from the command executed, if the comamnd is not a null pointer. It returns a
    non-zero value if the command is a null pointer and a command processor is available, and a zero value if the
    command processor is not available.

    For example:
    @code
        TC_system( "dir" ); 
    @endcode
*/
extern TC_API int TC_system(
    const char*    command     /**< (I) String containing the system command to be executed */ 
    );

/**
    Wrapper function to fgets() which is used in the loop to continuously read number of bytes from the
    specified stream and stores it into the string pointed to by str.

    Different from fgets() function which is a byte oriented, this function works on character base. It
    ensures to not truncate the multibyte string when reads it from the stream. Also, when running under
    the UTF-8 enabled Teamcenter environment, this function will converts the read-in string into the
    UTF-8 encoding before putting it into the buffer pointed to by str.

    On success, the function returns str.
    If the end-of-file is encountered while attempting to read a character, the eof indicator is set (feof). 
    If this happens before any characters could be read, the pointer returned is a null pointer (and the contents 
    of str remain unchanged).  If a read error occurs, the error indicator (ferror) is set and a null pointer is 
    also returned (but the contents pointed by str may have changed). 

    Here is an example of how to use TC_fgets() within the while-loop statement:
    @code
       FILE * fp = fopen( filename, "rt");
       while ( TC_fgets( str, buffer_size, fp ) != 0 )
       {
          ...
       } 
    @endcode

*/
extern TC_API char * TC_fgets(
    char *str,           /**< (I) pointer to an array of chars where the string read is stored */
    int num,             /**< (I) the maximum number of bytes to be read, including the end-of-string termination character */
    FILE *stream         /**< (I) pointer to a FILE object that identifies an input stream  */
    );


extern TC_API logical isNXManager (void);

extern TC_API logical isAPIServer (void);


/**
    Prints to "stream" all the environment variables that satisfy the given filtering,
    prefixed by "prefix" (or by nothing if "prefix" is null so you can e.g. supply an indent).
    The filtering is done by printing just those variables that include "filter" as a substring.
    If "filter" starts with a "^", then the variable must 'start' with the substring.
    If "filter" is null, all variables are printed. So a typical use might be
    #TC_print_env_vars( ERROR_system_log, "^TC", NULL );
*/
extern TC_API void TC_print_env_vars (
    FILE*            stream,
    const char*      filter,
    const char*      prefix
    );

/**
    Essentially prints a "what $TC_LIBRARY/libtcupdate" to stream
*/
extern TC_API void TC_print_what_tcupdate (
    FILE* stream
    );

/**
    On Windows: logs DLL versions
*/
extern TC_API void TC_print_dll_versions (
    FILE* stream
    );

/**
    Starts recording MEM_alloc()ators, prints a report
*/
extern TC_API void SM_start_logging (void);

extern TC_API void SM_report_logging (
    FILE*            stream
    );

/**
    Implemented in urlserver.cxx

    Returns 0 on failure (no URL for tag, or error), ptr to string on success (#MEM_free to dispose)
*/
extern TC_API char* TCWEB_tag_to_url(
    tag_t             tag
    );

/**
    Generates a URL to the targeted object for a specified application type.

    @note The URL type #HTML is deprecated starting Tc10.1. Calling this ITK with this parameter will provide default URL.

    @returns
    <ul>
    <li>#ITK_ok on success.</li>
    <li>#ITK_Web_server_not_defined if the preference "WEB_default_site_server" is not set.</li>
    </ul>
*/
extern TC_API int TC_tag_to_url(
    tag_t           tag,        /**< (I) Tag of the object */
    urlFormat_t     urlType,    /**< (I) Type of needed URL: #AWC, #SHF, #PORTAL,#DHTML or #HTML */
    char**          url         /**< (OF) URL to the targeted object*/
    );

/**
    Implemented in iman_util.cxx

    Returns true if TIE importer is running
*/
extern TC_API logical TC_isTIEImport(void);

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif
