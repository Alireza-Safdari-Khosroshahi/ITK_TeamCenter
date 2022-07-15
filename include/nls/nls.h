/**
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2013.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains functions to initialize Teamcenter internal encoding and to convert character data
    from and to Teamcenter internal encoding

*/

#ifndef NLS_H
#define NLS_H

/** @if DOX_IGNORE
    For "logical" -- coding standards demand that each .c file include unidefs anyway
@endif */
#include <unidefs.h>
#include <nls/libnls_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/***    Function prototypes    ***/

/**
   Checks if the Teamcenter system is configured for UTF-8 encoding, and is running as such.
   The system comprises the server and the database.
   <br/>Depends on a callback function to determine if the system is configured for UTF-8 encoding, and is running as such.
   NLS_register_system_is_running_utf8_callback() is used to register the call back function. Typically the callback is registered during startup.
   #TC_is_system_running_utf8 is the Teamcenter default call back function.

   @returns
   <ul>
   <li>@c true if the Teamcenter system is properly configured for UTF-8 encoding, and is running as such.
   <li>@c false if the Teamcenter system is not configured for UTF-8 encoding.
   </ul>
*/
extern NLS_API logical NLS_is_system_running_utf8(void);

/**
   Checks if the Teamcenter server is properly configured for UTF-8 encoding.

   The function returns:
   <ul>
   <li>true if the Teamcenter server is properly configured for UTF-8 encoding
   <li>false if the Teamcenter server is not configured for UTF-8 encoding.
   </ul>
*/
extern NLS_API logical NLS_is_server_utf8_configured(void);

/**
   Converts given character data from platform encoding to Teamcenter internal encoding.
   <br>The caller is responsible for freeing the memory associated with the converted data using
   #MEM_free API.

   The function does not return any value.
*/
extern NLS_API void NLS_external_to_internal(
    const char*  str_ext,     /**< (I)  The input character data in platform encoding  */
    char**       str_int      /**< (OF) The converted character data in Teamcenter internal encoding */
    );

/**
   Converts given character data from Teamcenter internal encoding to platform encoding. If any
   character cannot be converted to platform encoding, it will be substituted with '#' character.
   <br>The caller is responsible for freeing the memory associated with the converted data using
   #MEM_free API.

   The function does not return any value.
*/
extern NLS_API void NLS_internal_to_external(
    const char*  str_int,       /**< (I)  The input character data in Teamcenter internal encoding*/
    char**       str_ext        /**< (OF) The converted character data in platform encoding  */
    );

/**
   Converts given argument data from platform encoding to UTF-8 encoding if Teamcenter is running in
   UTF-8 internal encoding. Otherwise, the argument data is returned as is.
   <br>This API should be called once in the beginning of the main program to convert values of all input
   arguments from platform encoding to UTF-8 encoding, if Teamcenter is running in UTF-8 encoding. The
   caller is responsible for freeing the memory associated with converted argument data (argv_utf8) using
   #MEM_free API

   The function does not return any value.
*/
extern NLS_API void NLS_init_utf8(
    int   argc,        /**< (I) Number of arguments to be converted */
    const char  **argv,/**< (I) Values of arguments to be converted */
    char  ***argv_utf8 /**< (OF) Values of arguments converted to UTF-8 encoding */
);

/**
    Converts a UTF-8 encoded character string to the platform encoding.
    <br/>If any character cannot be converted to the platform encoding, it will be substituted with the '#' character.
    However, if conversion error occurs, a copy of the input string is passed in the parameter @p platform_encoded_string.

   @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NLS_utf8_to_system_results_data_loss (warning) if one or more characters are substituted with '#' during conversion. The string is still being converted.
    <li>#NLS_utf8_to_system_conversion_exception if any other error has occurred during encoding conversion. The original string in the original encoding is retrieved in the parameter @p platform_encoded_string
    </ul>
*/
extern NLS_API int NLS_convert_from_utf8_to_platform_encoding(
    const char*  utf8_encoded_string,            /**< (I)  The input character data in UTF-8 encoding */
    char**       platform_encoded_string         /**< (OF) The converted character data in platform encoding */
    );


/**
    Converts a platform encoded character string to the UTF-8 encoding.
    <br/>If a conversion error occurs, the input platform encoded string is copied into @p utf8_encoded_string.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NLS_system_to_utf8_conversion_fail if any other error has occurred during encoding conversion. The original string in the original encoding is retrieved in the parameter @p utf8_encoded_string
    </ul>
*/
extern NLS_API int NLS_convert_from_platform_to_utf8_encoding(
    const char*  platform_encoded_string,     /**< (I)  The input character data in platform encoding  */
    char**       utf8_encoded_string          /**< (OF) The converted character data in UTF-8 encoding  */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <nls/libnls_undef.h>

#endif
