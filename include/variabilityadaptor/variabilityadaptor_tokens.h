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
    light weight configurator token declarations. These string constants are used while de-serializing the CRS XML. The CRS XML contains strings for
    severity, supported data types and constraint types which are compared to these string constant and then are mapped corresponding in-memory enum values.
*/

#ifndef VARIABILITYADAPTOR_TOKENS_H
#define VARIABILITYADAPTOR_TOKENS_H

/**
    @defgroup VARIABILITYADAPTOR_TOKENS Tokens
    @ingroup VARIABILITYADAPTOR

    Defines token values for the attribute "fnd0operator" for the
    Business Objects "Fnd0EffectivityExpression" and "Fnd0VariantExpression".
    @{
*/

/**  Error Constraint Severity */
#define CFG_REST_CONFIGURATOR_Error_Severity                 CFG_CONFIGURATOR_error_severity

/**  Information Constraint Severity */
#define CFG_REST_CONFIGURATOR_Info_Severity                  CFG_CONFIGURATOR_info_severity

/**  Warning Constraint Severity */
#define CFG_REST_CONFIGURATOR_Warning_Severity               CFG_CONFIGURATOR_warning_severity

/**  Default Constraint Severity */
#define CFG_REST_CONFIGURATOR_Default_Severity               CFG_CONFIGURATOR_default_severity

/**  User Default Constraint Severity */
#define CFG_REST_CONFIGURATOR_User_Default_Severity          CFG_CONFIGURATOR_user_default_severity

/**  System Default Constraint Severity */
#define CFG_REST_CONFIGURATOR_System_Default_Severity        CFG_CONFIGURATOR_system_default_severity

/**  Package Default Constraint Severity */
#define CFG_REST_CONFIGURATOR_Package_Default_Severity       CFG_CONFIGURATOR_package_default_severity

/**  Constant for floating point data type */
#define CFG_REST_CONFIGURATOR_FLOATINGPOINT_TYPE             CFG_CONFIGURATOR_floating_point_type

/**  Constant for date data type */
#define CFG_REST_CONFIGURATOR_DATE_TYPE                      CFG_CONFIGURATOR_date_type

/**  Constant for integer data type */
#define CFG_REST_CONFIGURATOR_INTEGER_TYPE                   CFG_CONFIGURATOR_integer_type

/**  Constant for boolean data type */
#define CFG_REST_CONFIGURATOR_BOOLEAN_TYPE                   CFG_CONFIGURATOR_boolean_type

/**  Constant for Text data type */
#define CFG_REST_CONFIGURATOR_TEXT_TYPE                      CFG_CONFIGURATOR_text_type

/**  Constant for value effectivity constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_VALUE_EFFECTIVITY           CFG_CONFIGURATOR_constraint_value_effectivity

/**  Constant for availability constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_AVAILABILITY                CFG_CONFIGURATOR_constraint_availability

/**  Constant for default constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_default                     CFG_CONFIGURATOR_constraint_default

/**  Constant for exclude constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_EXCLUDE                     CFG_CONFIGURATOR_constraint_exclude

/**  Constant for include constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_INCLUDE                     CFG_CONFIGURATOR_constraint_include

/**  Constant for package constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_PACKAGE                     CFG_CONFIGURATOR_constraint_package

/**  Constant for summary constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_SUMMARY                     CFG_CONFIGURATOR_constraint_summary

/**  Constant for availability rule constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_AVAILABILITY_RULE           CFG_CONFIGURATOR_constraint_availability_rule

/**  Constant for allocation constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_ALLOCATION                  CFG_CONFIGURATOR_constraint_allocation

/**  Constant for feature family constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_FEATURE_FAMILY              CFG_CONFIGURATOR_constraint_feature_family

/**  Constant for conditional package constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_CONDITIONAL_PACKAGE         CFG_CONFIGURATOR_constraint_conditional_package

/** Constant for reverse package constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_REVERSE_PACKAGE             CFG_CONFIGURATOR_constraint_reverse_package

/** Constant for package Default constraint type */
#define CFG_REST_CONFIGURATOR_CONSTRAINT_PACKAGE_DEFAULT             CFG_CONFIGURATOR_constraint_package_default

/**  Constant for constraint behavior implies type */
#define CFG_REST_CONFIGURATOR_BEHAVIOR_IMPLIES                       CFG_CONFIGURATOR_behavior_implies

/**  Constant for constraint behavior equivalence type */
#define CFG_REST_CONFIGURATOR_BEHAVIOR_EQUIVALENCE                   CFG_CONFIGURATOR_behavior_equivalence

/**  Constant for constraint behavior xor type */
#define CFG_REST_CONFIGURATOR_BEHAVIOR_XOR                           CFG_CONFIGURATOR_behavior_xor

/**  Integer constant that indicates REST API was executed successfuly. **/
#define CFG_REST_Success                                              0

/**  Integer constant that indicates REST API execution failed. Details of failure can be found in the response JSON string. **/
#define CFG_REST_Fail                                                -1

/**

    @}
 */
#endif