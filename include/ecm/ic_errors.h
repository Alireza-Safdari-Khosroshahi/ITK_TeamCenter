/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    IC errors
*/

/*  */

#ifndef IC_ERRORS_H
#define IC_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup IC_ERRORS Errors
    @ingroup IC
    @{
*/

#define IC_duplicate_ice                  (EMH_IC_error_base + 1)
#define IC_no_write_ic_rev                (EMH_IC_error_base + 2)
#define IC_internal_error                 (EMH_IC_error_base + 3)
#define IC_cannot_delete_affected_object  (EMH_IC_error_base + 4)
#define IC_ice_not_in_ic_rev              (EMH_IC_error_base + 5)
#define IC_not_modifiable                 (EMH_IC_error_base + 6)
#define IC_duplicate_ice_during_cfwd      (EMH_IC_error_base + 7)
#define IC_icm_pref_not_set               (EMH_IC_error_base + 8)

/** @} */

#endif
