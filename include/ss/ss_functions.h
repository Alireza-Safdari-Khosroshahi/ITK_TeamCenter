/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Defines System Service (SS) specific methods

*/

/*  */


#ifndef SS_FUNCTIONS_H
#define SS_FUNCTIONS_H

#include <unidefs.h>
#include <ss/ss_types.h>

#include <ss/libss_exports.h>

/**
    @defgroup SS_FUNCTIONS Functions
    @ingroup SS

    Teamcenter has implemented some System Specific methods.

    The ITK system level functions include:
    <ul>
    <li>A function to generates a unique name that can be used for directory name or a file name.
    <li>A function to retrieve the address of a function in a library.
    <li>A function to retrieve the name of the Teamcenter server host.
    <li>A function to retrieve the IP address of the Teamcenter server host.
    <li>A function that delays the Teamcenter server process for the specified number of seconds.
    </ul>

    @{
*/

/** 
    Defines a generic type of function pointer.
    It will need to be cast to the proper signature before usage.
*/
typedef void(*SS_function_pointer_t)(void);

#ifdef __cplusplus
extern "C"{
#endif

/**
   Generates a unique name that can be used for directory name or a file name.

   @returns #ITK_ok always      
*/
    extern SS_API int SS_generate_unique_name(
        char** unique_name                /**< (OF) The generated unique name */
        );

    

/**
   Retrieves the address of a function in a library.

   @note No extension is to be provided for the library name.
   
   @code
   SS_function_pointer_t function_pointer;
   int ifail = SS_get_function_pointer_in_library( "libtextsrv", "TXTSRV_get_supported_languages_list", &function_pointer );
   if( ITK_ok == ifail )
   {
       int nbLanguages = 0;
       char** languageCodeList = 0;
       char** languageNameList = 0;
       / /  Now casting the function pointer to match the signature of the TXTSRV_get_supported_languages_list API
       ifail = ((int (*)(int*, char***, char***))function_pointer)(&nbLanguages, &languageCodeList, &languageNameList);
       [...]
   }
   @endcode

   @returns 
   <ul>
   <li>#ITK_ok on success
   <li>#SS_shlib_no_such_file if the library @p library_name cannot be found
   <li>#SS_shlib_invalid_library if the library @p library_name cannot be loaded
   <li>#SS_shlib_operation_failed if the function @p function_name cannot be found in the library @p library_name
   <li>Possibly other errors
   </ul>
*/
    extern SS_API int SS_get_function_pointer_in_library(
        const char * library_name,                /**< (I) Shared library name (without any platform extension) */
        const char * function_name,               /**< (I) Function name */
        SS_function_pointer_t* function_pointer   /**< (O) Function address */
        );

/**
   Retrieves the name of the Teamcenter server host.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SS_NOHOST if the host name cannot be determined
   </ul>
*/
    extern SS_API int SS_get_host_name(
        char ** host_name                        /**< (OF) The host name */
        );

/**
   Retrieves the IP address of the Teamcenter server host.
   @note The function only returns IPv4 addresses for the moment.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SS_NOHOSTADDR if the host address cannot be determined
   </ul>        
*/
    extern SS_API int SS_get_host_address(
        const char * host_name,                        /**< (I) The name of the server host */
        char ** host_ip_address                    /**< (OF) The IP address of the machine */
        );

/** @} */

/**  @defgroup SIGNAL_HANDLING Signal handling routines 
     @ingroup SS_FUNCTIONS
     @{
*/

/**
    Delays the Teamcenter server process for the specified number of seconds

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SS_NOSLEEP in case of failure
    </ul> 
*/
    extern SS_API int SS_delay_process(
        int seconds                /**< (I) The number of seconds to sleep */
        );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ss/libss_undef.h>
#endif
