/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef TE_ERRORS_H
#define TE_ERRORS_H

#include <common/emh_const.h>
#include <itk/libitk_exports.h>

/**
    @defgroup TE_ERRORS TE Errors
    @ingroup TE
    @{
*/

#define TE_initialize_failed           (EMH_TE_error_base + 1)
#define TE_PS_initialize_failed        (EMH_TE_error_base + 2)
#define TE_file_could_not_be_opened    (EMH_TE_error_base + 3)
#define TE_current_node_not_set        (EMH_TE_error_base + 4)
#define TE_could_not_write_to_file     (EMH_TE_error_base + 5)

#define TE_implementation_not_done     (EMH_TE_error_base + 10)
#define TE_set_null_value              (EMH_TE_error_base + 11)
#define TE_could_not_find_sp_item      (EMH_TE_error_base + 12)
#define TE_could_not_find_sp_item_rev  (EMH_TE_error_base + 13)
#define TE_bad_return_status           (EMH_TE_error_base + 14)
#define TE_return_status_stop          (EMH_TE_error_base + 15)

#define TE_node_selector_not_set       (EMH_TE_error_base + 20)
#define TE_rt_entry_handler_not_set    (EMH_TE_error_base + 21)
#define TE_rt_exit_handler_not_set     (EMH_TE_error_base + 22)
#define TE_at_node_handler_not_set     (EMH_TE_error_base + 23)
#define TE_reg_handler_not_set         (EMH_TE_error_base + 24)
#define TE_fw_entry_handler_not_set    (EMH_TE_error_base + 25)
#define TE_fw_exit_handler_not_set     (EMH_TE_error_base + 26)
#define TE_rv_entry_handler_not_set    (EMH_TE_error_base + 27)
#define TE_rv_exit_handler_not_set     (EMH_TE_error_base + 28)

#define TE_key_cannot_be_null          (EMH_TE_error_base + 30)

#define TE_viewtype_notfound           (EMH_TE_error_base + 40)
#define TE_revrule_notfound            (EMH_TE_error_base + 41)
#define TE_entry_not_found_inconfig    (EMH_TE_error_base + 42)
#define TE_multiple_saved_variants     (EMH_TE_error_base + 43)
#define TE_variant_not_right_type      (EMH_TE_error_base + 44)
#define TE_variant_not_found           (EMH_TE_error_base + 45)
#define TE_itemrev_no_bvr_attached     (EMH_TE_error_base + 46)

/** @} */

#include <itk/libitk_undef.h>
#endif

