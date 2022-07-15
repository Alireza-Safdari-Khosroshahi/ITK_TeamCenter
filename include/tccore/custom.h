/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains functions for dynamic loading of custom libraries
*/

/*  */

#ifndef CUSTOM_H
#define CUSTOM_H

#include <tccore/libtccore_exports.h>

/**
    @defgroup CUSTOM Customization
    @{
*/

#define NO_CUSTOMIZATION           0
#define ONLY_CURRENT_CUSTOMIZATION 1
#define ALL_CUSTOMIZATIONS         2
#define GM_LIBRARY                 "libgm"

typedef int (* CUSTOM_EXIT_ftn_t) (
    int*,
    va_list
    );

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This function registers customizations for all the customization contexts registered in the site preference file.

    It goes through each custom library registered in the site preference file
    <UL>
    <LI>Loads the custom library and
    <LI>Call the entry point function pointer to register custom exits
    </UL>
    The entry point function contains the custom registrations for the required USER_ USERSERVICE_ exits

    These custom registrations are done using the ITK #CUSTOM_register_exit

    This ITK should be called only in USER_preint_module in user_init.c. It should not be called anywhere else.
*/
extern TCCORE_API int CUSTOM_register_callbacks ( void );

/**
    This function executes the custom callbacks registered for a particular USER_ or USERSERVICE_ exit

    For each custom library registered in the site preference file,
    <UL>
    <LI>Get the corresponding custom function pointer
    <LI>Execute the custom function with the arguments passed
    </UL>
    This function is called in each of the USER_ and USERSERVICE_ exit functions. 

    The va_list has to be expanded in the custom function

    This function is called in all the USER_ and USERSERVICE_ functions in user_exits and server_exits.
*/
extern TCCORE_API int CUSTOM_execute_callbacks (
    int*                decision,   /**< (O) Whether to execute #ALL_CUSTOMIZATIONS,
                                            #ONLY_CURRENT_CUSTOMIZATION or #NO_CUSTOMIZATION */
    const char*         ftn_name,   /**< (I) Name of the USER_ or USERSERVICE_ exit. 
                                            The variables that need to be passed to the custom exit (a custom function pointer) */ 
    ...                             /**< (I) */
    );

/**
    This function registers a custom exit (a custom function pointer) for a given USER_ and USERSERVICE_ exit function
*/
extern TCCORE_API int CUSTOM_register_exit (
    const char*         context,        /**< (I) The context in which this custom exit has to be registered.
                                            It is the name of the  customization library (eg GM, Ford, Suzuki, etc..) */
    const char*         base_ftn_name,  /**< (I) Name of the USER_ or USERSERVICE_ exit for which the 
                                            custom exit has to be registered (e.g. #USER_new_dataset_name) */
    CUSTOM_EXIT_ftn_t   custom_ftn      /**< (I) The name of the custom exit (a custom function pointer) */
    );

/**
    This function executes custom callbacks registered in a particular library for a particular USER_ or USERSERVICE_ exit
    <UL>
    <LI>Get the corresponding custom function pointer
    <LI>Execute the custom function with the arguments passed
    </UL>
    The va_list has to be expaned in the custom function
*/
extern TCCORE_API int CUSTOM_execute_callbacks_from_library ( 
    int*                decision,   /**< (O) Whether to execute #ALL_CUSTOMIZATIONS,
                                        #ONLY_CURRENT_CUSTOMIZATION or #NO_CUSTOMIZATION */
    const char*         lib_name,   /**< (I) Name of the customization context (e.g. GM, Ford, Suzuki, etc..) */ 
    const char*         ftn_name,   /**< (I) Name of the USER_ or USERSERVICE_ exit. 
                                        The variables that need to be passed to the custom exit (a custom function pointer) */ 
    ...                             /**< (I) */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <tccore/libtccore_undef.h>

#endif
