/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef TYPECANNEDMETHOD_ERRORS_H
#define TYPECANNEDMETHOD_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TYPE_CANNED_METHOD_ERRORS Errors
    @ingroup TYPE_CANNED_METHOD
    @{
*/

#define METHOD_CM_class_not_initialized                         (EMH_METHOD_CM_error_base + 0)
#define METHOD_CM_internal_error                                (EMH_METHOD_CM_error_base + 1)
#define METHOD_CM_module_not_initialized                        (EMH_METHOD_CM_error_base + 2)
#define METHOD_CM_module_initialization_failure                 (EMH_METHOD_CM_error_base + 3)
#define METHOD_CM_register_failed                               (EMH_METHOD_CM_error_base + 4)
#define METHOD_CM_failed_to_process_internal_cm                 (EMH_METHOD_CM_error_base + 5)
#define METHOD_CM_user_insufficient_privilege                   (EMH_METHOD_CM_error_base + 6)
#define METHOD_CM_delete_failed                                 (EMH_METHOD_CM_error_base + 7)
#define METHOD_CM_invalid_msg_name                              (EMH_METHOD_CM_error_base + 8)
#define METHOD_CM_invalid_msg_name_length                       (EMH_METHOD_CM_error_base + 9)
#define METHOD_CM_invalid_action_type                           (EMH_METHOD_CM_error_base + 10)
#define METHOD_CM_invalid_method_name                           (EMH_METHOD_CM_error_base + 11)
#define METHOD_CM_invalid_method_name_length                    (EMH_METHOD_CM_error_base + 12)
#define METHOD_CM_method_not_available                          (EMH_METHOD_CM_error_base + 13)
#define METHOD_CM_invalid_optionValue_count                     (EMH_METHOD_CM_error_base + 14)
#define METHOD_CM_invalid_optionValues                          (EMH_METHOD_CM_error_base + 15)
#define METHOD_CM_extent_failed                                 (EMH_METHOD_CM_error_base + 16)
#define METHOD_CM_functionPtr_not_found                         (EMH_METHOD_CM_error_base + 17)
#define METHOD_CM_invalid_create_arguments                      (EMH_METHOD_CM_error_base + 18)
#define METHOD_CM_create_arg_list_failed                        (EMH_METHOD_CM_error_base + 19)
#define METHOD_CM_USER_add_CM_failed                            (EMH_METHOD_CM_error_base + 20)
#define METHOD_CM_ask_type_name_failed                          (EMH_METHOD_CM_error_base + 21)
#define METHOD_CM_ask_msg_name_failed                           (EMH_METHOD_CM_error_base + 22)
#define METHOD_CM_ask_action_type_failed                        (EMH_METHOD_CM_error_base + 23)
#define METHOD_CM_ask_method_name_failed                        (EMH_METHOD_CM_error_base + 24)

#define METHOD_CM_invalid_isMandatory_entry                     (EMH_METHOD_CM_error_base + 25)
#define METHOD_CM_invalid_userQuery_entry                       (EMH_METHOD_CM_error_base + 26)

#define METHOD_CM_non_unique_data                               (EMH_METHOD_CM_error_base + 27)

#define METHOD_CM_invalid_method_tag                            (EMH_METHOD_CM_error_base + 28)
#define METHOD_CM_tag_not_valid                                 (EMH_METHOD_CM_error_base + 29)
#define METHOD_CM_param_not_found                               (EMH_METHOD_CM_error_base + 30)

#define METHOD_CM_null_tag                                      (EMH_METHOD_CM_error_base + 31)
#define METHOD_CM_tokenize_failed                               (EMH_METHOD_CM_error_base + 32)
#define METHOD_CM_invalid_query_detail                          (EMH_METHOD_CM_error_base + 33)
#define METHOD_CM_func_dict_not_initialized                     (EMH_METHOD_CM_error_base + 34)
#define METHOD_CM_get_registered_types_failed                   (EMH_METHOD_CM_error_base + 35)
#define METHOD_CM_methods_not_implemented                       (EMH_METHOD_CM_error_base + 36)

/**
    @name Error Messages corresponding to import based on RULE_val_t
    @{
*/
#define METHOD_CM_import_invalid_class                          (EMH_METHOD_CM_error_base + 41)
#define METHOD_CM_import_invalid_child_count                    (EMH_METHOD_CM_error_base + 42)
#define METHOD_CM_import_invalid_parameters_name                (EMH_METHOD_CM_error_base + 43)
#define METHOD_CM_import_invalid_option_cnt                     (EMH_METHOD_CM_error_base + 44)
#define METHOD_CM_import_invalid_parameters_child_name          (EMH_METHOD_CM_error_base + 45)
#define METHOD_CM_import_invalid_input_structure                (EMH_METHOD_CM_error_base + 46)
/** @} */

/**
    @name Error Messages corresponding to TcParameters handling from TypeCannedMethod
    @{
*/
#define METHOD_CM_TcParameter_delete_failed                   (EMH_METHOD_CM_error_base + 51)
#define METHOD_CM_create_TcParameters_failed                  (EMH_METHOD_CM_error_base + 52)
#define METHOD_CM_save_TcParameters_failed                    (EMH_METHOD_CM_error_base + 53)
#define METHOD_CM_ask_TcParameters_failed                     (EMH_METHOD_CM_error_base + 54)
/** @} */

/**
    @name Error Messages corresponding to createObjects Method Implementation
    @{
*/
#define METHOD_CM_createObjects_opt_cnt_invalid                 (EMH_METHOD_CM_error_base + 61)
#define METHOD_CM_createObjects_type_does_not_exist             (EMH_METHOD_CM_error_base + 62)
#define METHOD_CM_createObjects_rel_does_not_exist              (EMH_METHOD_CM_error_base + 63)
#define METHOD_CM_createObjects_invalid_message                 (EMH_METHOD_CM_error_base + 64)
#define METHOD_CM_createObjects_invalid_object_type             (EMH_METHOD_CM_error_base + 65)
#define METHOD_CM_createObjects_failed                          (EMH_METHOD_CM_error_base + 66)
#define METHOD_CM_createObjects_create_rel_failed               (EMH_METHOD_CM_error_base + 67)
#define METHOD_CM_createObjects_save_rel_failed                 (EMH_METHOD_CM_error_base + 68)
/** @} */

/**
    @name Error Messages corresponding to checkLatestReleased Method Implementation
    @{
*/
#define METHOD_CM_checkLatestReleased_invalid_option            (EMH_METHOD_CM_error_base + 71)
#define METHOD_CM_checkLatestReleased_invalid_working_rev_count (EMH_METHOD_CM_error_base + 72)
#define METHOD_CM_failed_to_get_item                            (EMH_METHOD_CM_error_base + 73)
#define METHOD_CM_max_working_rev_limit_exceeded                (EMH_METHOD_CM_error_base + 74)
#define METHOD_CM_checkLatestReleased_invalid_message           (EMH_METHOD_CM_error_base + 75)
#define METHOD_CM_checkLatestReleased_invalid_integer           (EMH_METHOD_CM_error_base + 76)
#define METHOD_CM_disallow_creation                             (EMH_METHOD_CM_error_base + 77)
/** @} */

/**
    @name Error Messages corresponding to copyVariantExpr Method Implementation
    @{
*/
#define METHOD_CM_copyVariant_invalid_message_name              (EMH_METHOD_CM_error_base + 81)
/** @} */

/**
    @name Error Messages corresponding to checkLatestReleased Method Implementation
    @{
*/
#define METHOD_CM_disallow_cut                                  (EMH_METHOD_CM_error_base + 91)
/** @} */

/**
    @name Error Messages corresponding to autoAssignToProject Method Implementation
    @{
*/
#define METHOD_CM_autoAssignToProject_invalid_message           (EMH_METHOD_CM_error_base + 101)
#define METHOD_CM_autoAssignToProject_invalid_object_type       (EMH_METHOD_CM_error_base + 102)
#define METHOD_CM_autoAssignToProject_failed                    (EMH_METHOD_CM_error_base + 103)
/** @} */

/**
    @name Error Messages corresponding to checkValidationResultsWithRules Method Implementation
    @{
*/
#define METHOD_CM_checkValidationResultsWithRules_invalid_message  (EMH_METHOD_CM_error_base + 126)
#define METHOD_CM_checkValidationResultsWithRules_ruleitemrevision_not_provided (EMH_METHOD_CM_error_base + 127)
/** @} */

/** @} */

#endif

