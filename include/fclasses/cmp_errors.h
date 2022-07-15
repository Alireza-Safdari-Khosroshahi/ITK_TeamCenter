/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Errors for the Generic Compare Engine
*/

/*  */

#ifndef CMP_ERRORS_H
#define CMP_ERRORS_H

#include <common/emh_const.h>
#include <fclasses/libfclasses_exports.h>

/**
    @defgroup CMP_ERRORS Errors
    @ingroup CMP
    @{
*/

#define CMP_internal_error              (EMH_CMP_error_base +   0)
#define CMP_initialization_failure      (EMH_CMP_error_base +   1)
#define CMP_descriptor_is_locked        (EMH_CMP_error_base +   2)
#define CMP_descriptor_create_failed    (EMH_CMP_error_base +   3)
#define CMP_descriptor_delete_failed    (EMH_CMP_error_base +   4)
#define CMP_duplicate_descriptor_name   (EMH_CMP_error_base +   5)
#define CMP_element_add_failed          (EMH_CMP_error_base +   6)
#define CMP_element_remove_failed       (EMH_CMP_error_base +   7)
#define CMP_invalid_element_for_desc    (EMH_CMP_error_base +   8)
#define CMP_element_already_present     (EMH_CMP_error_base +   9)
#define CMP_cannot_delete_elements      (EMH_CMP_error_base +  10)
#define CMP_invalid_method_for_element  (EMH_CMP_error_base +  11)
#define CMP_no_internal_logic           (EMH_CMP_error_base +  12)
#define CMP_value_type_mismatch         (EMH_CMP_error_base +  13)
#define CMP_unsupported_value_type      (EMH_CMP_error_base +  14)
#define CMP_no_multi_value_props        (EMH_CMP_error_base +  15)
#define CMP_cache_index_out_of_range    (EMH_CMP_error_base +  16)
#define CMP_conversion_not_implemented  (EMH_CMP_error_base +  17)
#define CMP_element_cache_mismatch      (EMH_CMP_error_base +  18)
#define CMP_set_is_empty                (EMH_CMP_error_base +  19)
#define CMP_invalid_cache_type          (EMH_CMP_error_base +  20)
#define CMP_invalid_tag                 (EMH_CMP_error_base +  21)
#define CMP_cannot_cull_set             (EMH_CMP_error_base +  22)
#define CMP_invalid_set                 (EMH_CMP_error_base +  23)
#define CMP_narrow_failed               (EMH_CMP_error_base +  24)
#define CMP_aggregate_type_locked       (EMH_CMP_error_base +  25)
#define CMP_bad_itk_argument            (EMH_CMP_error_base +  26)
#define CMP_standard_desc_not_found     (EMH_CMP_error_base +  27)
#define CMP_no_value                    (EMH_CMP_error_base +  28)

/** @} */

#include <fclasses/libfclasses_undef.h>
#endif

