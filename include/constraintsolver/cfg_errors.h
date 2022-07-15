/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2019.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This header file contains error codes for the Configurator Integration.
*/

#ifndef CFG_ERRORS_H
#define CFG_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CFG_ERRORS Errors
    @ingroup CFG
    @{
*/

#define  CFG_error_base                    EMH_CFG_error_base
/** An internal configurator error occurred. */
#define  CFG_internal_error                (CFG_error_base + 0)
/** A general configurator error occurred. */
#define  CFG_general_error                 (CFG_error_base + 1)
/** The following product is invalid: [%1$]%2$ (Context: %3$). */
#define  CFG_invalid_product               (CFG_error_base + 2)
/** The following feature value is invalid: [%1$]%2$ (Context: %3$). */
#define  CFG_invalid_feature_value         (CFG_error_base + 3)
/** The following feature family is invalid: [%1$]%2$ (Context: %3$). */
#define  CFG_invalid_feature_family        (CFG_error_base + 4)
/** An invalid feature combination was found (Context: %1$). */
#define  CFG_invalid_feature_combination   (CFG_error_base + 5)
/** An invalid product configuration was found (Context: %1$). */
#define  CFG_invalid_product_configuration (CFG_error_base + 6)
/** An invalid expression was found (Context: %1$). */
#define  CFG_invalid_expression            (CFG_error_base + 7)
/** The following Boolean operator is invalid: %1$ (Context: %2$). */
#define  CFG_invalid_boolean_operator      (CFG_error_base + 8)
/** An invalid effectivity date was found (Context: %1$). */
#define  CFG_invalid_effectivity_date      (CFG_error_base + 9)
/** A time-out occurred (Context: %1$). */
#define  CFG_timeout_occured               (CFG_error_base + 10)
/** A resource is not available (Context: %1$). */
#define  CFG_resource_not_available        (CFG_error_base + 11)
/** The following functionality is not implemented: %1$ (Version: %2$). */
#define  CFG_functionality_not_implemented (CFG_error_base + 12)
/** A configurator implementation specific error occurred (Context: %1$). */
#define  CFG_configurator_specific_error   (CFG_error_base + 13)
/** The variant expression contains unmatched quote at position %1$. */
#define  CFG_parse_expr_unmatched_quote    (CFG_error_base + 14)
/** The variant expression contains unmatched bracket at position %1$. */
#define  CFG_parse_expr_unmatched_brackt   (CFG_error_base + 15)
/** An unexpected token "%1$" was found at position %2$. */
#define  CFG_parse_expr_unexpected_token   (CFG_error_base + 16)
/** The entry "%1$" was found at position %2$ when an option value was expected. */
#define  CFG_parse_expr_missing_opt_val    (CFG_error_base + 17)
/** The token "%1$" is missing after "%2$" at position %3$. */
#define  CFG_parse_expr_missing_token      (CFG_error_base + 18)
/** The variant expression adaptor does not support %1$ used at position %2$. */
#define  CFG_parse_expr_unknown_feature    (CFG_error_base + 19)
/** The XML tag "%1$" has no text value. */
#define  CFG_convert_expr_xml_tag_no_txt   (CFG_error_base + 20)
/** The string "%1$" cannot be converted into an expression. */
#define  CFG_convert_expr_invalid_input    (CFG_error_base + 21)
/** The operator code "%1$" in token at position %2$ is unknown. */
#define  CFG_convert_expr_unknown_opcode   (CFG_error_base + 22)
/** The variant value "%1$" in token at position %2$ is unknown. */
#define  CFG_convert_expr_unknown_value    (CFG_error_base + 23)
/** The variant family "%1$" in token at position %2$ is unknown. */
#define  CFG_convert_expr_unknown_famly    (CFG_error_base + 24)
/** An ambiguous option value name "%1$" in namespace "%2$" in token at position %3$ was found: %4$. */
#define  CFG_convert_expr_ambiguous_val    (CFG_error_base + 25)
/** An ambiguous option family name "%1$" in token at position %2$ was found: %3$. */
#define  CFG_convert_expr_ambiguous_fam    (CFG_error_base + 26)
/** The option namespace "%1$" in token at position %2$ is invalid. */
#define  CFG_convert_expr_inval_name_sp    (CFG_error_base + 27)
/** The variant family "%1$" in token at position %2$ is invalid. */
#define  CFG_convert_expr_inval_family     (CFG_error_base + 28)
/** The variant option value "%1$" for family "%2$" in token at position %3$ is invalid. */
#define  CFG_convert_expr_invalid_value    (CFG_error_base + 29)
/** The variant option value "%1$" for family "%2$" in token at position %3$ is invalid: its value is not numeric. */
#define  CFG_convert_expr_value_not_num    (CFG_error_base + 30)
/** The variant option value "%1$" for family "%2$" in token at position %3$ is invalid: the value unit of measure "%4$" does not match the family unit of measure "%5$". */
#define  CFG_convert_expr_value_bad_uom    (CFG_error_base + 31)
/** The option / family / family namespace combination "%1$" / "%2$" / "%3$" in token at position %4$ is invalid. */
#define  CFG_convert_expr_inval_combinat   (CFG_error_base + 32)
/** The family "%1$" for option / family namespace combination "%2$" / "%3$" in token at position %4$ is invalid. */
#define  CFG_convert_expr_inval_fam_comb   (CFG_error_base + 33)
/** There is no option value in token at position %1$. */
#define  CFG_convert_expr_no_optionvalue   (CFG_error_base + 34)
/** The variant option value "%1$" for the family "%2$" in the token at position "%3$" is invalid: the value is not a valid date. */
#define  CFG_convert_expr_value_not_date   (CFG_error_base + 35)
/** The variant option value "%1$" for the family "%2$" in the token at position "%3$" is invalid: the value is not an integer. */
#define  CFG_convert_expr_value_not_int    (CFG_error_base + 36)
/** The operation has failed to read the following variant expression: %1$. Please check the Teamcenter server syslog file for more information. */
#define CFG_failed_to_read_variant_expression                   ( CFG_error_base + 37 )
/** The operation has failed to validate the following variant expression: %1$. Please check the Teamcenter server syslog file for more information. */
#define CFG_failed_to_validate_variant_expression               ( CFG_error_base + 38 )
/** The operation has failed to parse the following variant expression: %1$. Please check the Teamcenter server syslog file for more information. */
#define CFG_failed_to_parse_variant_expression                  ( CFG_error_base + 39 )
/** The operation has failed because the specified request does not contain any expression and/or product configuration. */
#define CFG_expression_absent_in_request                        ( CFG_error_base + 40 )
/** The Revision Rule creation has failed, because too many arguments are specified. Please report this error to your system administrator. */
#define CFG_revisionrule_attribute_client_element               ( CFG_error_base + 41 )
/** The Expression "%1$" always evaluates to TRUE, which is redundant with the product configuration. */
#define CFG_expression_degenerate_true                          ( CFG_error_base + 42 )
/** The Expression "%1$" always evaluates to FALSE, which can never be satisfied in the product configuration. */
#define CFG_expression_degenerate_false                         ( CFG_error_base + 43 )
/** The Expression "%1$" is outside of product variability. */
#define CFG_expression_outside_variability                      ( CFG_error_base + 44 )
/** Default rule "%1$" references more than one feature family. Default rules that assign more than one family need to be broken up into separate default rules for each feature family. */
#define CFG_default_rule_multiple_family                        ( CFG_error_base + 45 )
/** The Feature Combination "%1$" contains both a configuration expression attribute and a value reference attribute. Only one should be specified. */
#define CFG_feature_combination_expression_value_present        ( CFG_error_base + 46 )
/** The Feature Combination "%1$" contains neither a configuration expression attribute nor a value reference attribute. */
#define CFG_feature_combination_expression_value_absent         ( CFG_error_base + 47 )
/** The Feature Combination "%1$" represents an unsatisfiable configuration expression "%2$". */
#define CFG_feature_combination_unsatisfiable_expression        ( CFG_error_base + 48 )
/** Either the Feature Combination "%1$" does not constitute a valid configuration expression, or the product "%2$" contains no variability expression. */
#define CFG_feature_combination_expr_product_variability        ( CFG_error_base + 49 )
/** A new expression identifier "%1$" was generated and assigned, because the provided identifier "%2$" is alreaedy in use. */
#define CFG_new_expression_id_generated                          ( CFG_error_base + 50 )
/** No persistent ID could be retrieved. Please check the Teamcenter syslog file for more information and report this error to your system administrator. */
#define CFG_persistent_id_retrieval_failed                       ( CFG_error_base + 51 )
/** The operation has failed, because the product "%1$" contains no variability expression. */
#define CFG_product_variability_expressions_absent              ( CFG_error_base + 52 )
/** The search criteria provided as input parameters are invalid. Please report this error to your system administrator. */
#define CFG_invalid_search_criteria                             ( CFG_error_base + 53 )
/** The value "%1$" for the "applyConstraints" bit pattern is invalid. Please refer to documentation for valid values. */
#define CFG_invalid_apply_constraints                           ( CFG_error_base + 54 )
/** The provided solve profile is invalid. Please refer to the documentation for valid values. */
#define CFG_invalid_solve_profile                               ( CFG_error_base + 55 )
/** The provided Free-Form expression is invalid, because it contains "%1$". Only "assert" statements are supported. */
#define CFG_invalid_free_form_expression                              ( CFG_error_base + 56 )
/** An internal error has occurred in the module perfconfigurator: "%1$". Please report this error to your system administrator. */
#define CFG_internal_perfconfigurator_error                     ( CFG_error_base + 57 )
/**

    @}
*/

#endif
