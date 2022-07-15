/**
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/


/**
    @file

    Indexed Bill Of Materials (IBOM) errors

*/

#ifndef IBOM_ERRORS_H
#define IBOM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup IBOM_ERRORS Indexed Bill Of Materials Errors
    @ingroup  IBOM
    @{
*/

#define IBOM_error_base                             EMH_IBOM_error_base

/**
    An internal error has occurred in the Indexed BOM (IBOM) module. Please report this to your system administrator.
*/
#define IBOM_internal_error                         (IBOM_error_base + 1)

/**
    The option "%1$" is not in a Transfer Formula.
*/
#define IBOM_invalid_option                         (IBOM_error_base + 2)

/**
    No BOM structure with a proper top line is specified for the "Export" operation
*/
#define IBOM_topline_is_empty                       (IBOM_error_base + 3)

/**
    The BOM Window could not be exported for the following reason: %1$.
*/
#define IBOM_invalid_bomwindow                      (IBOM_error_base + 4)

/**
   No Indexed BOM Window matches the input parameters.
*/
#define IBOM_no_indexed_bom_window                  (IBOM_error_base + 5)

/**
   More than one Indexed BOM Window matches the input parameters.
*/
#define IBOM_multiple_indexed_bom_windows_match     (IBOM_error_base + 6)

/**
   The provided effectivity "%1$" contains an invalid date.
*/
#define IBOM_wrong_date_in_effectivity              (IBOM_error_base + 7)

/**
   Too many effectivites are provided for generating an indexed BOM.
*/
#define IBOM_too_many_effectivities                 (IBOM_error_base + 8)

/**
   The provided occurrence thread chains are invalid. Please refer the tcserver syslog for details. 
*/
#define IBOM_invalid_occ_thread_chains              (IBOM_error_base + 9)

/** @} */

#endif
