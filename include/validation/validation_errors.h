/*==================================================================================================

                    Copyright (c) 2003 Electronic Data Systems Corporation
                             Unpublished - All rights reserved
                                       Shape Data

===================================================================================================*/

/**
    @file

    Error codes returned by the VO ITK module.
*/

/*  */

#ifndef VALIDATION_ERRORS_H
#define VALIDATION_ERRORS_H

/*================================================================================================*/

#include <common/emh_const.h>
#include <validation/libvalidation_exports.h>

/*================================================================================================*/

/**
    @defgroup VALIDATION_ERRORS Validation Errors
    @ingroup VALIDATION
    @{
*/

#define VALIDATION_internal_error               (EMH_VALIDATION_error_base + 0)
#define VALIDATION_not_administrator            (EMH_VALIDATION_error_base + 1)
#define VALIDATION_data_initialize_failed       (EMH_VALIDATION_error_base + 2)
#define VALIDATION_create_data_obj_failed       (EMH_VALIDATION_error_base + 3)
#define VALIDATION_cannot_create_duplicate_data (EMH_VALIDATION_error_base + 4)
#define VALIDATION_get_data_failed              (EMH_VALIDATION_error_base + 5)
#define VALIDATION_null_query_failed            (EMH_VALIDATION_error_base + 6)
#define VALIDATION_query_failed                 (EMH_VALIDATION_error_base + 7)
#define VALIDATION_combine_query_failed         (EMH_VALIDATION_error_base + 8)
#define VALIDATION_execute_query_failed         (EMH_VALIDATION_error_base + 9)
#define VALIDATION_create_result_obj_failed     (EMH_VALIDATION_error_base + 10)
#define VALIDATION_compound_result_failed       (EMH_VALIDATION_error_base + 11)
#define VALIDATION_vm_not_found                 (EMH_VALIDATION_error_base + 12)
#define VALIDATION_vm_out_of_date               (EMH_VALIDATION_error_base + 13)
/**
 The following NX targets do not have validation results, and the validation operation needs to be run once more on them: %1$.
*/
#define VALIDATION_some_vm_not_found            (EMH_VALIDATION_error_base + 14)

#define VALIDATION_rule_itemrev_format_error    (EMH_VALIDATION_error_base + 20)
#define VALIDATION_rule_dataset_file_not_found  (EMH_VALIDATION_error_base + 21)
#define VALIDATION_rule_parser_error            (EMH_VALIDATION_error_base + 22)
#define VALIDATION_rule_invalid_rule_file       (EMH_VALIDATION_error_base + 23)
#define VALIDATION_rule_no_target_or_rule       (EMH_VALIDATION_error_base + 24)
#define VALIDATION_rule_checker_not_found       (EMH_VALIDATION_error_base + 25)
#define VALIDATION_rule_open_mqclog_failed      (EMH_VALIDATION_error_base + 26)
#define VALIDATION_rule_parse_xmllog_failed     (EMH_VALIDATION_error_base + 27)
#define VALIDATION_rule_unknown_checkmate_log   (EMH_VALIDATION_error_base + 28)
#define VALIDATION_rule_dup_checker_name_found  (EMH_VALIDATION_error_base + 29)
#define VALIDATION_rules_are_not_met            (EMH_VALIDATION_error_base + 30)

#define VALIDATION_invalid_validation_obj       (EMH_VALIDATION_error_base + 31)
#define VALIDATION_no_existing_agent            (EMH_VALIDATION_error_base + 32)
#define VALIDATION_mutiple_agents_found         (EMH_VALIDATION_error_base + 33)

/**
 * No object of type "%1$" and name "%2$" could be found.
 */
#define VALIDATION_unable_to_find_object        (EMH_VALIDATION_error_base + 34)


/**
 * Objects of type "%1$" are not supported for the "%2$" operation.
 */
#define VALIDATION_invalid_object_for_operation (EMH_VALIDATION_error_base + 35)


/**
 * The value for the report parameter "%1$" is invalid.
 */
#define VALIDATION_invalid_value                (EMH_VALIDATION_error_base + 36)

#define VALIDATION_exp_error_base                (EMH_VALIDATION_error_base + 100)
#define VALIDATION_exp_internal_error            (EMH_VALIDATION_error_base + 101)
#define VALIDATION_exp_err_invalid_syntax        (EMH_VALIDATION_error_base + 102)
#define VALIDATION_exp_err_SIGFPE                (EMH_VALIDATION_error_base + 103)
#define VALIDATION_exp_err_no_var                (EMH_VALIDATION_error_base + 104)
#define VALIDATION_exp_err_unexpected_end        (EMH_VALIDATION_error_base + 105)
#define VALIDATION_exp_err_underflow             (EMH_VALIDATION_error_base + 106)
#define VALIDATION_exp_err_overflow              (EMH_VALIDATION_error_base + 107)
#define VALIDATION_exp_err_unbalanced_quotes     (EMH_VALIDATION_error_base + 108)
#define VALIDATION_exp_err_misformed_unit        (EMH_VALIDATION_error_base + 109)
#define VALIDATION_exp_err_spaces_in_name        (EMH_VALIDATION_error_base + 110)
#define VALIDATION_exp_err_quoted_var            (EMH_VALIDATION_error_base + 111)
#define VALIDATION_exp_err_unexpected_str        (EMH_VALIDATION_error_base + 112)
#define VALIDATION_exp_err_spaces_before_unit_bracket  (EMH_VALIDATION_error_base + 113)
#define VALIDATION_exp_max_err                   (EMH_VALIDATION_error_base + 150)

#define VALIDATION_req_severity_msg              (EMH_VALIDATION_error_base + 151)

#define VALIDATION_agent_revise_not_supported    (EMH_VALIDATION_error_base + 152)
#define VALIDATION_checker_revise_not_supported  (EMH_VALIDATION_error_base + 153)

/** @} */

#include <validation/libvalidation_undef.h>
/*================================================================================================*/

#endif  /* VALIDATION_ERRORS_H */

/*================================================================================================*/
