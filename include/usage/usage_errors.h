/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes returned by the USAGE ITK module.
*/

/*  */

#ifndef USAGE_ERRORS_H
#define USAGE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup USAGE_ERRORS USAGE Errors
    @ingroup USAGE
    @{
*/

#define USAGE_design_rev_has_no_rendering               (EMH_USAGE_error_base +   0)
#define USAGE_design_rev_not_precise                    (EMH_USAGE_error_base +   1)
#define USAGE_design_rev_has_no_status                  (EMH_USAGE_error_base +   2)
#define USAGE_design_proxy_objects                      (EMH_USAGE_error_base +   3)
#define USAGE_unable_link_parts_to_new_rev              (EMH_USAGE_error_base +   4)
#define USAGE_async_multiple_objects                    (EMH_USAGE_error_base +   5)
#define USAGE_async_in_progress                         (EMH_USAGE_error_base +   6)
#define USAGE_async_start_failed                        (EMH_USAGE_error_base +   7)
#define USAGE_unable_to_delete_temp_file                (EMH_USAGE_error_base +   8)
#define USAGE_unable_link_occs_under_IA                 (EMH_USAGE_error_base +   9)
#define USAGE_invalid_design_occ                        (EMH_USAGE_error_base +   10)
#define USAGE_invalid_rev_rule_for_publish              (EMH_USAGE_error_base +   11)
#define USAGE_bom_not_fully_configured                  (EMH_USAGE_error_base +   12)
#define USAGE_unlinked_part_occurrences                 (EMH_USAGE_error_base +   13)
#define USAGE_drawing_rev_has_no_specification_dataset  (EMH_USAGE_error_base +   14)
#define USAGE_dataset_write_access_denied               (EMH_USAGE_error_base +   15)
#define USAGE_unable_to_delete_tempfile                 (EMH_USAGE_error_base +   16)
#define USAGE_bomline_not_in_context_of_ia              (EMH_USAGE_error_base +   17)
#define USAGE_usagewc_module_not_available              (EMH_USAGE_error_base +   18)

/** @} */

#endif
