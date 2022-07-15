/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2018.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Cfg0configurator solution token declarations
*/

#ifndef CFG0CONFIGURATOR_TOKENS_H
#define CFG0CONFIGURATOR_TOKENS_H

#include <booleanmath/cfg_tokens.h>
#include <variabilityadaptor/variabilityadaptor_tokens.h>
/**
    @defgroup CFG0CONFIGURATOR_TOKENS Tokens
    @ingroup CFG0CONFIGURATOR

    Defines token values for the attribute "fnd0operator" for the
    Business Objects "Fnd0EffectivityExpression" and "Fnd0VariantExpression".
    @{
*/

/**  String value data type of a family */
#define CFG0CONFIGURATOR_String_Value_Type      "String"

/**  Integer value data type of a family */
#define CFG0CONFIGURATOR_Integer_Value_Type     "Integer"

/**  Floating Point/Numeric value data type of a family */
#define CFG0CONFIGURATOR_Floating_Value_Type    "Floating Point"

/**  Boolean value data type of a family */
#define CFG0CONFIGURATOR_Boolean_Value_Type     "Boolean"

/**  Date value data type of a family */
#define CFG0CONFIGURATOR_Date_Value_Type        "Date"

/**  Error Constraint Severity */
#define CFG0CONFIGURATOR_Error_Severity         CFG_REST_CONFIGURATOR_Error_Severity

/**  Information Constraint Severity */
#define CFG0CONFIGURATOR_Info_Severity          CFG_REST_CONFIGURATOR_Info_Severity

/**  Warning Constraint Severity */
#define CFG0CONFIGURATOR_Warning_Severity       CFG_REST_CONFIGURATOR_Warning_Severity

/**  Default Constraint Severity */
#define CFG0CONFIGURATOR_Default_Severity       CFG_REST_CONFIGURATOR_Default_Severity

/**  Mandatory Constraint Severity */
#define CFG0CONFIGURATOR_Mandatory_Severity     "Mandatory"

/**  Unknown Constraint Severity */
#define CFG0CONFIGURATOR_Unknown_Severity       "Unknown"

/**
 * Indicates that the option will be considered a Product Line
 */
#define CFG0_option_mode_product_line           CFG_mode_product_line

/**
 * A VariantExpression with this operator code represents a configuration validation criterion
 *  which must evaluate to true in order for a configuration rule to be considered valid.
 */
#define CFG0_operator_availability_constraint   CFG_operator_availability_constraint

/**
 Defines an enforced condition for a rule.
 <br/>E.g. Exclude Rule : ~model | ~applicability | model & applicability & ~restriction
 <br/>Include Rule : ~model | ~applicability | model & applicability & restriction
 */
#define CFG0_operator_enforced_condition        CFG_operator_enforced_condition

/**
  Defines a variant expression which is a combined representation of package.
  <br/>E.g. If the Package P1 has members A1, B1 and C1, its expression will be "A1 & B1 & C1".
 */
#define CFG0_product_line_variant_expression    CFG_product_line_variant_expression

/**

    @}
 */
#endif
