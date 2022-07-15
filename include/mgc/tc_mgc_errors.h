/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Mentor Integration Errors
*/

/*  */

#ifndef TC_MGC_ERRORS_H
#define TC_MGC_ERRORS_H

#include <common/emh_const.h>
#include <mgc/libmgc_exports.h>

/**
    @defgroup MCG_ERRORS MGC Errors
    @ingroup MGC
    @{
*/

#define EMH_MGC_error_base              59000

#define MGC_fail_to_open_file           (EMH_MGC_error_base +  1)
#define MGC_empty_line_read             (EMH_MGC_error_base +  2)
#define MGC_corrupt_input_file          (EMH_MGC_error_base +  3)
#define MGC_dataset_not_defined         (EMH_MGC_error_base +  4)
#define MGC_object_not_checkout         (EMH_MGC_error_base +  5)
#define MGC_object_already_checkout     (EMH_MGC_error_base +  6)
#define MGC_invalid_property_value      (EMH_MGC_error_base +  7)
#define MGC_module_not_initialized      (EMH_MGC_error_base +  8)
#define MGC_fail_in_system_call         (EMH_MGC_error_base +  9)
#define MGC_checkout_by_other_user      (EMH_MGC_error_base + 10)
#define MGC_internal_error              (EMH_MGC_error_base + 11)
#define MGC_connection_fail             (EMH_MGC_error_base + 12)
#define MGC_object_checkin_from_tc    (EMH_MGC_error_base + 13)
#define MGC_checkout_dummy_item         (EMH_MGC_error_base + 14)
#define MGC_environment_not_set         (EMH_MGC_error_base + 15)
#define MGC_item_type_mismatch          (EMH_MGC_error_base + 16)

/** @} */

#include <mgc/libmgc_undef.h>
#endif
