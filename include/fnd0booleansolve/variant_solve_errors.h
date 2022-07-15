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
    @file variant_solve_errors.h

    This header file contains error codes for the Variant Solve module.
*/

#ifndef VARIANT_SOLVE_ERRORS_H
#define VARIANT_SOLVE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup VARIANT_SOLVE_ERRORS Variant Solve Errors
    @ingroup BOOLEANSOLVE
    @{
*/

#define  VARSOLVE_error_base                                            EMH_VARSOLVE_error_base
#define  VARSOLVE_internal_error                                        (VARSOLVE_error_base + 0)
#define  VARSOLVE_solve_expr_too_complex                                (VARSOLVE_error_base + 1)
#define  VARSOLVE_expr_is_not_normalized                                (VARSOLVE_error_base + 2)
#define  VARSOLVE_expr_is_not_a_CNF                                     (VARSOLVE_error_base + 3)
/**The value "%1$" is not a valid expression operator code.*/
#define  VARSOLVE_invalid_expr_opcode                                   (VARSOLVE_error_base + 4)

/**
* The object "%1$" of type "%2$" is not a variant configurable object.
*/
#define  VARSOLVE_object_is_not_variant_configurable                    (VARSOLVE_error_base + 5)

/**
* The input expression is invalid.
*/
#define  VARSOLVE_expr_is_invalid                                       (VARSOLVE_error_base + 6)

/**
* The object "%1$" of type "%2$" is not a valid context Item or Item Revision.
*/
#define  VARSOLVE_context_is_invalid                                    (VARSOLVE_error_base + 7)

/**
* The input variant rule expression "%1$" is invalid for current product context. Product context rules are not considered while configuring the content.
*/
#define  VARSOLVE_variant_rule_expr_invalid                             (VARSOLVE_error_base + 8)

/**
* Configuration Conjunctive Normal Form objects cannot be created for the solve state "%1$".
*/
#define  VARSOLVE_invalid_solve_state_combination                       (VARSOLVE_error_base + 9)

/**
 * The object "%1$" of type "%2$" is not a session configurable object.
 */
#define  VARSOLVE_input_object_is_not_session_configurable              (VARSOLVE_error_base + 10)

/**
 * The object "%1$" of type "%2$" does not support modular hierarchy variant configuration.
 */
#define  VARSOLVE_input_object_modular_hierarchy_unsupported             (VARSOLVE_error_base + 11)

 /**
 * The provided search parameter should at least specify the primary object, the object name or the object ID.
 */
#define VARSOLVE_invalid_variant_rule_search_param                       ( VARSOLVE_error_base + 13 )

/**
* The variant rule expression "%1$" is valid but incomplete for the current product context "%2$". Content filtering is supported only if the configuration is valid and complete.
*/
#define VARSOLVE_variant_rule_expr_valid_but_incomplete                     ( VARSOLVE_error_base + 14 )

/** @} */

#endif
