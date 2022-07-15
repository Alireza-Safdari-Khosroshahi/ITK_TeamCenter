/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes for the UOM (Unit of Measure) module
*/

/*  */

#ifndef UOM_ERRORS_H_DEFINED
#define UOM_ERRORS_H_DEFINED

#include <common/emh_const.h>

/**
    @defgroup UOM_ERRORS Errors
    @ingroup UOM
    @{
*/

#define  UOM_internal_error          (EMH_UOM_error_base + 0)
#define  UOM_invalid                 (EMH_UOM_error_base + 1)
#define  UOM_insufficient_privilege  (EMH_UOM_error_base + 2)
#define  UOM_none_defined            (EMH_UOM_error_base + 3)
#define  UOM_duplicate_uom           (EMH_UOM_error_base + 4)

/** @} */


#endif

