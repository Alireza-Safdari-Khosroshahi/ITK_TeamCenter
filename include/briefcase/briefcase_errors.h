/* @<COPYRIGHT_START>@
* ===============================================
* Copyright 2018 UGS Corp. All Rights Reserved.
* ===============================================
* @<COPYRIGHT_END>@
*/


/**
    @file

    Briefcase errors

*/

#ifndef BRIEFCASE_ERRORS_H
#define BRIEFCASE_ERRORS_H
#include <common/emh_const.h>

/**
    @defgroup BRIEFCASE_ERRORS Briefcase Errors
    @ingroup BRIEFCASE
    @{
*/

#define   BRIEFCASE_error_base    EMH_BRIEFCASE_error_base

/** The briefcase module not initialised. */
#define   BCASE_module_not_initialised        (BRIEFCASE_error_base+1)

/**
    Could not open the briefcase file.
*/
#define   BCASE_unable_to_open_container      (BRIEFCASE_error_base + 2)

/**
    Could not close the briefcase file.
*/
#define   BCASE_unable_to_close_container     (BRIEFCASE_error_base + 3)

/**
    The Part file "%1$" cannot be added into the briefcase. Please refer to the server log file for details, or contact your system administrator.
*/
#define   BCASE_unable_to_add_part            (BRIEFCASE_error_base + 4)

/**
    Cannot add the part into briefcase.
*/
#define   BCASE_part_not_found                (BRIEFCASE_error_base + 5)

/**
    Unable to set the property on briefcase.
*/
#define   BCASE_unable_set_property           (BRIEFCASE_error_base + 6)

/**
    Unable to get the property of briefcase.
*/
#define   BCASE_unable_get_property           (BRIEFCASE_error_base + 7)

/**
    Unable to set the property group on briefcase.
*/
#define   BCASE_unable_set_group              (BRIEFCASE_error_base + 8)

/**
    Unable to get the property group of briefcase.
*/
#define   BCASE_unable_get_group              (BRIEFCASE_error_base + 9)

/**
    Unable to extract the briefcase into the given location.
*/
#define   BCASE_extract_failed                (BRIEFCASE_error_base + 10)

/**
    The given part already exists in the briefcase.
*/
#define   BCASE_part_already_exists           (BRIEFCASE_error_base + 11)

/**
    Unable to get the contents of the briefcase.
*/
#define   BCASE_unable_to_get_contents        (BRIEFCASE_error_base + 12)

/**
    The contents of "%1$" and "%2$" cannot be compared because the briefcases are of different types.
*/
#define   BCASE_unable_to_compare_contents    (BRIEFCASE_error_base + 13)

/** @} */

#endif
