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

    Cfg token declarations
*/

#ifndef CFG_TOKENS_H
#define CFG_TOKENS_H

/**
    @defgroup CFG_TOKENS Configurator Interface Tokens
    @ingroup CFG

    Defines token values for the attribute "fnd0operator" for the
    Business Objects "Fnd0EffectivityExpression" and "Fnd0VariantExpression".
    @{
*/

/**
    Indicates dynamic comprasion of values which is determined at runtime based on the values that exist in the family
    "2" < "10" but "2E0" > "1E1"
*/
#define CFG_mode_dynamic_comparison         (1 << 0)

/**
    Indicates that the variant option will be considered as lexicographic value
    "2" > "10" and "2E0" > "1E1"
*/
#define CFG_mode_lexicographic_comparison   (1 << 1)

/**
    Indicates that the variant option  will be considered as numeric value
    "2" < "10" and "2E0" < "1E1"
*/
#define CFG_mode_numeric_comparison         (1 << 2)

/**
    Indicates that the variant option will be considered as integer value
*/
#define CFG_mode_integer_comparison         (1 << 3)

/**
    Indicates that the variant option will be considered as Date value
    convert values to UTC dates using DATE_convert_iso_date_to_date_t() (tc_date.h) before comparing
*/
#define CFG_mode_date_comparison            (1 << 4)

/**
    Indicates that the variant option will be considered as discretionary value
    UNSET means "none of" else it means "any of"
*/
#define CFG_mode_discretionary              (1 << 5)

/**
    Indicates that the variant option will be considered as designator value
*/
#define CFG_mode_model_designator_option    (1 << 6)

/**
    Indicates that the option will be considered as logical value with only two states
    e.g. On/Off, True/False, or present/absent
*/
#define CFG_mode_logical_comparison         (1 << 7)

/**
    Indicates the option will support free form values.
    i.e. the option is not limited to a fixed discrete value list.
*/
#define CFG_mode_free_form                  (1 << 8)

/**
    Indicates the option will support multiple selection
*/
#define CFG_mode_multi_select               (1 << 9)

/**
    Indicates the option will be considered a Product Line
*/
#define CFG_mode_product_line               (1 << 10)

/**
    Indicates the option will be considered an Effectivity family
*/
#define CFG_mode_effectivity_family         (1 << 11)

/**
    Indicates the option will be considered a Feature family/Option family
*/
#define CFG_mode_feature_family             (1 << 12)

/**
    Indicates the option will be considered a Dynamic family
*/
#define CFG_mode_dynamic_family             (1 << 13)

/**
    Indicates the option will be considered a Feature set
*/
#define CFG_mode_feature_set_family         (1 << 14)

/**
 Indicates the option will be considered a family with static list of features
 */
#define CFG_mode_static_feature_family      (1 << 15)
/**
    Indicates mode has not been set i.e it is a default mode
*/
#define CFG_mode_unknown                           0

/**
    "Declare" operator is used to select one VariantRevision from all those that reference the same parent
    Variant (VariantRevision.parent_variant).
    The expression may optionally restrict the domain of values for this Variant.
*/
#define CFG_operator_declare                       1

/**
    It records the use of a specific value index for the Variant specified.
*/
#define CFG_operator_assy_uses                     2

/**
    Indicates the assignment of one value to another using "Assign" operator.
*/
#define CFG_operator_assign                        3

/**
    Indicates a fixed default value index for the Variant specified.
*/
#define CFG_operator_default                       4

/**
    Indicates the comparison of two values using "Equal" operator.
*/
#define CFG_operator_is_equal                      5

/**
    Indicates the comparison of two values using "Not Equal" operator.
*/
#define CFG_operator_not_equal                     6

/**
    Indicates the condition of a Rule Check under which the error message given
    should be displayed.
*/
#define CFG_operator_error_if                      7

/** Specifies a comment that does not impact Boolean evaluation. */
#define CFG_operator_comment                       8

/**
    Indicates the condition expression that are used in configuration filters.
*/
#define CFG_operator_load_if                       9

/**
    Combines the two values with the "And" operator.
*/
#define CFG_operator_and                           10

/**
    Combines the two values with the "Or" operator.
*/
#define CFG_operator_or                            11

/**
    Defines the default assignment to be applied in a Derived Default if the
    value condition is met.
*/
#define CFG_operator_if                            12

/**
    Indicates the comparison of two values using "Greater Than" operator.
*/
#define CFG_operator_gt                            13

/**
    Indicates the comparison of two values using "Less Than" operator.
*/
#define CFG_operator_lt                            14

/**
    Indicates the comparison of two values using "Greater Than Equal To" operator.
*/
#define CFG_operator_gt_eq                         15

/**
    Indicates the comparison of two values using "Less Than Equal To" operator.
*/
#define CFG_operator_lt_eq                         16

/**
    Encloses the value in brackets using "Brackets" operator.
*/
#define CFG_operator_brackets                      17

/**
    This opertaor used by the VariantRules to store their criteria in expressions.
*/
#define CFG_operator_rule_set                      18

/**
    Indicates the condition enclosed in a Named Variant Expression.
*/
#define CFG_operator_named_expr                    19

/**
    Indicates the logical tree of an expression that forms a Named Variant
    Expression Meta-expression.
*/
#define CFG_operator_meta_expr                     20

/**
    references the Named Variant Expression identified by the text given.
*/
#define CFG_operator_nve_ref                       21

/**
    Negates the value - ONLY SUPPORTED IN META-EXPRESSIONS.
*/
#define CFG_operator_not                           22

/**
    Defines the maximum range of validity up to which a CFG_operator_load_if condition can be
    expanded.
*/
#define CFG_operator_applicability                 23

/**
    Defines how a dependent variant variable maps to its a master variable when substituting
    dependent variables, e.g. how "Risk" maps to "Size".
*/
#define CFG_operator_use_dependent                 24

/**
    A Variant Expression with this operator code defines the applicability condition used in a filter
    expression that qualifies the parent expression.
*/
#define CFG_operator_condition                     25

/**
    Defines configuration criteria which may become active under certain conditions.
*/
#define CFG_operator_criteria_set                  26

/**
    Defines configuration criteria for a transient variant rule.
    The operand references the POM user tag for which the transient criteria was created.
    The string attribute specifies the POM session that created this expression.
*/
#define CFG_operator_transient_criteria_set        27

/**
    A Variant Expression with this operator code represents a configuration validation criterion
    which must evaluate to true in order for a configuration rule to be considered valid.
*/
#define CFG_operator_inclusive_constraint          28

/**
    A Variant Expression with this operator code represents a configuration validation criterion
    which must evaluate to false in order for a configuration rule to be considered valid.
*/
#define CFG_operator_exclusive_constraint          29

/**
    Defines a filter expression that qualifies a configuration validation criterion
    with ERROR severity specified.
*/
#define CFG_operator_constraint_error              30

/**
    Defines a filter expression that qualifies a configuration validation criterion
    with INFORM severity specified.
*/
#define CFG_operator_constraint_inform             31

/**
    Defines a filter expression that qualifies a configuration validation criterion
    with WARN severity specified.
*/
#define CFG_operator_constraint_warn               32

/**
    Variant Expressions with this operator code define criteria that all products of a given "model"
    or "product family" have in common.
*/
#define CFG_operator_product_family_condition      33

/**
    A Variant Expression with this operator code records the use of a value range for the Variant
    specified.
*/
#define CFG_operator_value_range                   34

/**
    Defines a "persistentID" operator
*/
#define CFG_operator_persistent_id                 35

/**
    Combines the value defining a "product family" condition with the value defining
    an applicability condition using the operator "AND".
*/
#define CFG_operator_filter_condition              36

/**
    It defines a filter expression that qualifies a Default Assignment
*/
#define CFG_operator_derived_default_rule          37

/**
    This operator specifies an unconditional Default Assignment
*/
#define CFG_operator_fixed_default_rule            38

/**
    Defines a "tautology" (TT) expression that always evaluates to true. No operands.
*/
#define CFG_operator_tt                            39

/**
    Defines a "contradiction" (CT) expression that always evaluates to false. No operands.
*/
#define CFG_operator_ct                            40

/**
    A Variant Expression with this operator code represents a configuration validation criterion
    which must evaluate to true in order for a configuration rule to be considered valid.
*/
#define CFG_operator_availability_constraint       41

/**
    Defines an enforced condition for a rule.
    <br/>E.g. Exclude Rule : ~model | ~applicability | model & applicability & ~restriction
    <br/>Include Rule : ~model | ~applicability | model & applicability & restriction
*/
#define CFG_operator_enforced_condition            42

/**
    Defines a variant expression which is a combined representation of package.
    <br/>E.g. If the Package P1 has members A1, B1 and C1, its expression will be "A1 & B1 & C1".
*/
#define CFG_product_line_variant_expression        43

/**
    A Variant Expression with this operator code records the use of a subject section for
    all constraints
*/
#define CFG_operator_constraint_subject            44

/**
    A Variant Expression with this operator code represents a configuration criterion with a package rule
    which must evaluate to true in order for a configuration rule to be considered valid.
    E.g. If the Package P1 has members (A|B|C) & (Q1|Q2) & D & E with applicability as Model=M1,
    its expression will be ( ( (A|B|C) & (Q1|Q2) & D & E ) & ( M1) )
*/
#define CFG_operator_package_rule_constraint       45

/**
    A Variant Expression with this operator code represents a default configuration criterion with
    a package rule Which act as tie breaker for alternatives in a Package line.
    E.g. If the Package P1 has members (A|B*|C) & (Q1*|Q2) & D & E with applicability as Model=M1,
    where    indicates defaults among alternatives.
    Its default expression will be (( B & Q1 ))
*/
#define CFG_operator_package_default_constraint    46

/**
    A Variant Expression with this operator code represents mutually exclusiveness of Features within a Family.
    E.g. If the Feature Family has members (A|B|C),
    Then mutually exclusive constraint could be ^(A, B, C).
*/
#define CFG_feature_family_expression              47

/**
    This operator specifies a configurator criteria expression based on user selected features.
*/
#define CFG_operator_user_criteria                 48

/**
    This operator specifies a configurator criteria expression based on expanded feature list.
    @deprecated This is deprecated in Tc11.6 and will be removed in Tc13. Use #CFG_operator_rule_set instead
*/
#define CFG_operator_expanded_criteria             49

/**
    A Variant Expression with this operator code represents a exception criterion with a feature in a Feature Family.
    This expression act as exception to a mutually exclusiveness of Features within a Family.
    E.g. If the Feature Family has members (A|B|C) and Feature B has exception for Model=M1,
    Then mutually exclusive constraint could be ^(A, B & !M1, C) instead of ^(A, B, C).
*/
#define CFG_feature_family_exception_expression    50

/**
    A Variant Expression with this operator code represents a Package Feature Expression with
    a Package Rule which is derived from "Cfg0AbsPackageRule.cfg0PackageFeature" property.
    E.g. If the Package Pkg1 from PKG_Fam family has members (A|B|C) & (Q1|Q2) & D & E with
    applicability as Model=M1, its Package Feature Expression will be "PKG_Fam = Pkg1".
    This expression will be saved on Package Rule which will save the complication and
    cost of creating expression from "Cfg0AbsPackageRuleThrd.cfg0PackageFeatureThread"
    property during solve operation.
*/
#define CFG_operator_package_variant               51

/**
    Defines Feature Family in the constraint is an Optional/Discretionary family in nature.
    i.e. Having presence of the operator in FeatureFamilyConstraint says Feature Family is Optional.
    For Eg: If the Feature Family has members (A|B|C) and opcode CFG_discretionary_feature_family is present in constraint,
    Then mutually exclusive constraint could be ^(A, B, C, )
    An empty value be mutually exclusive to other members of family.
*/
#define CFG_discretionary_feature_family           52

/**
    A Variant Expression with this operator code represents exception of Feature within a Feature Family.
    For e.g: If the Feature Family has Features A, B, C then we can define an exception between Feature Family and Feature "A"
    by creating an exception rule using CFG_operator_exception_rule_constraint constant.
*/
#define CFG_operator_exception_rule_constraint     53

/**
    A Variant Expression with this operator code represents a Package Feature Expression with
    a Package Rule which is derived from "Cfg0AbsPackageRule.cfg0PackageFeature" property.
    E.g. If the Package Pkg1 from PKG_Fam family has members (A|B|C) & (Q1|Q2) & D & E with
    applicability as Model=M1, its Package Feature Expression will be "PKG_Fam = Pkg1".
    This expression will be saved on Package Rule which will save the complication and
    cost of creating expression from "Cfg0AbsPackageRuleThrd.cfg0PackageFeatureThread"
    property during solve operation.
*/
#define CFG_operator_package_variant               51

/**
    Defines Feature Family in the constraint is an Optional/Discretionary family in nature.
    i.e. Having presence of the operator in FeatureFamilyConstraint says Feature Family is Optional.
    For Eg: If the Feature Family has members (A|B|C) and opcode CFG_discretionary_feature_family is present in constraint,
    Then mutually exclusive constraint could be ^(A, B, C, )
    An empty value be mutually exclusive to other members of family.
*/
#define CFG_discretionary_feature_family           52

/**
    A Variant Expression with this operator code represents exception of Feature within a Feature Family.
    For e.g: If the Feature Family has Features A, B, C then we can define an exception between Feature Family and Feature "A"
    by creating an exception rule using CFG_operator_exception_rule_constraint constant.
*/
#define CFG_operator_exception_rule_constraint     53

/**
    Offset indicating that this operator is effectivty related
*/
#define CFG_effectivity_operator_offset            500

/**
    Selects one VariantRevision for effectivity options from all that reference the same parent Variant (VariantRevision.parent_variant).
    The expression may optionally restrict the domain of values for this Variant.
*/
#define CFG_effectivity_operator_declare                   (CFG_effectivity_operator_offset + CFG_operator_declare)

/**
    Records the use of a specific value index for the Variant specified
*/
#define CFG_effectivity_operator_used_value                (CFG_effectivity_operator_offset + CFG_operator_assy_uses)

/**
    Expressions with this operator code record the use of an effectivity value range for the Variant specified
*/
#define CFG_effectivity_operator_value_range               (CFG_effectivity_operator_offset + CFG_operator_value_range)

/**
    Defines a fixed value index for the Variant specified
*/
#define CFG_effectivity_operator_fixed_default_rule        (CFG_effectivity_operator_offset + CFG_operator_fixed_default_rule)

/**
    Specifies the condition of a Rule Check under which the error message given should be displayed
*/
#define CFG_effectivity_operator_error_if                  (CFG_effectivity_operator_offset + CFG_operator_error_if)

/**
    Defines the effectivity scope for an EffectivityConfigurable object
*/
#define CFG_effectivity_operator_load_if                   (CFG_effectivity_operator_offset + CFG_operator_load_if)

/**
    Defines how a dependent effectivity variable maps to its a master variable when substituting dependent variables
    e.g. how "Vacation" maps to "Date"
*/
#define CFG_effectivity_operator_use_dependent             (CFG_effectivity_operator_offset + CFG_operator_use_dependent)

/**
    Defines configuration criteria which may become active under certain conditions
*/
#define CFG_effectivity_operator_criteria_set              (CFG_effectivity_operator_offset + CFG_operator_criteria_set)

/**
    Defines the maximum range of validity up to which a PS_effectivity_operator_load_if condition can be expanded
*/
#define CFG_effectivity_operator_applicability             (CFG_effectivity_operator_offset + CFG_operator_applicability)

/**
    Combines the value defining a "product family" effectivity condition with the value defining an effectivity applicability condition using the operator AND
*/
#define CFG_effectivity_operator_filter_condition          (CFG_effectivity_operator_offset + CFG_operator_filter_condition)

/**
    Expressions with this operator code define effectivity criteria all products of a given "model" or "product family" have in common
*/
#define CFG_effectivity_operator_product_family_condition  (CFG_effectivity_operator_offset + CFG_operator_product_family_condition)

/**
    Expressions with this operator code define the applicability condition used in a filter expression that that qualifies the parent effectivity expression
*/
#define CFG_effectivity_operator_condition                 (CFG_effectivity_operator_offset + CFG_operator_condition)

/**
    Expressions with this operator code represent configuration validation criteria which all configuration rules should pass in order to be considered valid
*/
#define CFG_effectivity_operator_inclusive_constraint      (CFG_effectivity_operator_offset + CFG_operator_inclusive_constraint)

/**
    Expressions with this operator code represent effectivity configuration validation criteria which all configuration rules should not meet in order to be considered valid
*/
#define CFG_effectivity_operator_exclusive_constraint      (CFG_effectivity_operator_offset + CFG_operator_exclusive_constraint)

/**
    Defines a filter expression that qualifies a configuration validation criteria ERROR severity specified
*/
#define CFG_effectivity_operator_constraint_error          (CFG_effectivity_operator_offset + CFG_operator_constraint_error)

/**
    Defines a filter expression that qualifies a configuration validation criteria INFORM severity specified
*/
#define CFG_effectivity_operator_constraint_inform         (CFG_effectivity_operator_offset + CFG_operator_constraint_inform)

/**
Defines a filter expression that qualifies a configuration validation criteria WARN severity specified.
*/
#define CFG_effectivity_operator_constraint_warn           (CFG_effectivity_operator_offset + CFG_operator_constraint_warn)

/**
    Defines a filter expression that qualifies the effectivity default assignment
*/
#define CFG_effectivity_operator_derived_default_rule      (CFG_effectivity_operator_offset + CFG_operator_derived_default_rule)

/**
    @}
*/

/**
    @defgroup CFG_CONSTRAINT Configurator Constraint tokens
    @ingroup CFG

    Defines token values for the configurator constraint severity, type, data type.
    @{
*/

/**  The severity of a value assignment that was made based on the given input, e.g. user input.
     The constant maps to CFG_severity_t value CFG_severity_input_selected. */
#define CFG_CONFIGURATOR_user_severity                      "User"

/**  Error Constraint Severity.
     The constant maps to CFG_severity_t value CFG_severity_error_level.
     The constant maps to LOV "Cfg0SelectionClassification" value "Error".
     The constant maps to LOV "Cfg0ConstraintSeverity" value "Error". */
#define CFG_CONFIGURATOR_error_severity                     "Error"

/**  Information Constraint Severity.
     The constant maps to CFG_severity_t value CFG_severity_information_level.
     The constant maps to LOV "Cfg0SelectionClassification" value "Info".
     The constant maps to LOV "Cfg0ConstraintSeverity" value "Info" */
#define CFG_CONFIGURATOR_info_severity                      "Info"

/**  Warning Constraint Severity.
     The constant maps to CFG_severity_t value CFG_severity_warning_level.
     The constant maps to LOV "Cfg0SelectionClassification" value "Warning".
     The constant maps to LOV "Cfg0ConstraintSeverity" value "Warning" */
#define CFG_CONFIGURATOR_warning_severity                   "Warning"

/**  The severity of a constraint that suggest a default value for a family.
     The constant maps to CFG_severity_t value CFG_severity_default_selected.
     The constant maps to LOV "Cfg0SelectionClassification" value "Default". */
#define CFG_CONFIGURATOR_default_severity                   "Default"

/**  The severity of a constraint that suggest a default value among multiple alternatives in a package rule.
     The constant maps to CFG_severity_t value CFG_severity_package_default.
     The constant maps to LOV "Cfg0SelectionClassification" value "PackageDefault". */
#define CFG_CONFIGURATOR_package_default_severity           "PackageDefault"

/**  The severity of a system generated constraint that initializes discretionary families with the empty value.
     The constant maps to CFG_severity_t value CFG_severity_init_empty.
     The constant maps to LOV "Cfg0SelectionClassification" value "EmptyInitialized". */
#define CFG_CONFIGURATOR_Init_Empty_Severity            "EmptyInitialized"

/**  The severity of a constraint for which READ access is denied has assigned a value.
     If a feature selection is not known precisely, it will be represented as Unknown.
     The constant maps to CFG_severity_t value CFG_severity_unknown.
     The constant maps to LOV "Cfg0SelectionClassification" value "Unknown". */
#define CFG_CONFIGURATOR_Unknown_Severity               "Unknown"

#if MAJOR_VERSION < 13000
/**  User Default Constraint Severity. This constant is deprecated in Tc12.3 and will be removed in Tc13. Please use CFG_CONFIGURATOR_default_severity */
#define CFG_CONFIGURATOR_user_default_severity          "UserDefault"

/**  System Default Constraint Severity. This constant is deprecated in Tc12.3 and will be removed in Tc13. Please use CFG_CONFIGURATOR_Init_Empty_Severity */
#define CFG_CONFIGURATOR_system_default_severity        "Mandatory"

#ifdef WNT /*  */
#pragma deprecated( "CFG_CONFIGURATOR_user_default_severity" )   /* Deprecated in Tc12.3. Please use CFG_CONFIGURATOR_default_severity */
#pragma deprecated( "CFG_CONFIGURATOR_system_default_severity" ) /* Deprecated in Tc12.3. Please use CFG_CONFIGURATOR_Init_Empty_Severity */
#endif     /* #ifdef WNT */
#endif     /* #if MAJOR_VERSION */

/**  Constant for floating point data type */
#define CFG_CONFIGURATOR_floating_point_type                "FloatingPoint"

/**  Constant for date data type */
#define CFG_CONFIGURATOR_date_type                          "Date"

/**  Constant for integer data type */
#define CFG_CONFIGURATOR_integer_type                       "Integer"

/**  Constant for boolean data type */
#define CFG_CONFIGURATOR_boolean_type                       "Boolean"

/**  Constant for Text data type */
#define CFG_CONFIGURATOR_text_type                          "Text"

/**  Constant for value effectivity constraint type */
#define CFG_CONFIGURATOR_constraint_value_effectivity       "valueEffectivityConstraint"

/**  Constant for availability constraint type */
#define CFG_CONFIGURATOR_constraint_availability            "availabilityConstraint"

/**  Constant for default constraint type */
#define CFG_CONFIGURATOR_constraint_default                 "defaultConstraint"

/**  Constant for exclude constraint type */
#define CFG_CONFIGURATOR_constraint_exclude                 "excludeConstraint"

/**  Constant for include constraint type */
#define CFG_CONFIGURATOR_constraint_include                 "includeConstraint"

/**  Constant for package constraint type */
#define CFG_CONFIGURATOR_constraint_package                 "packageConstraint"

/**  Constant for summary constraint type */
#define CFG_CONFIGURATOR_constraint_summary                 "summaryConstraint"

/**  Constant for availability rule constraint type */
#define CFG_CONFIGURATOR_constraint_availability_rule       "availabilityRuleConstraint"

/**  Constant for allocation constraint type */
#define CFG_CONFIGURATOR_constraint_allocation              "allocationConstraint"

/**  Constant for feature family constraint type */
#define CFG_CONFIGURATOR_constraint_feature_family          "featureFamilyConstraint"

/**  Constant for conditional package constraint type */
#define CFG_CONFIGURATOR_constraint_conditional_package     "conditionalPackageConstraint"

/** Constant for reverse package constraint type */
#define CFG_CONFIGURATOR_constraint_reverse_package         "reversePackageConstraint"

/** Constant for package Default constraint type */
#define CFG_CONFIGURATOR_constraint_package_default         "conditionalPackageDefaultConstraint"

/**  Constant for constraint behavior implies type */
#define CFG_CONFIGURATOR_behavior_implies                   "implies"

/**  Constant for constraint behavior equivalence type */
#define CFG_CONFIGURATOR_behavior_equivalence               "equivalence"

/**  Constant for constraint behavior xor type */
#define CFG_CONFIGURATOR_behavior_xor                       "xor"

/**

    @}
*/

/**
    @defgroup CFG_CONFIGURATION_PROFILE Configurator configuration profile tokens
    @ingroup CFG

    Defines token values for the configurator product context configuration.
    @{
*/

/**
    Value for this key is scalar of type boolean which enables configurator
    constraints evaluation.

    If this flag is set to true, various constraints of type other than
    Default Rule such as Include Rule, Exclude Rule will be exercised
    else they will be ignored.
*/
#define CFG_PROFILE_apply_config_constraints_key                             "CFG_PROFILE_applyConfigConstraints"

/**
    Value for this key is scalar of type boolean which enables configurator
    constraints evaluation of Default Rule type.

    If this flag is set to true, constraints of type Default Rule will be
    exercised else they will be ignored.
*/
#define CFG_PROFILE_apply_defaults_key                                       "CFG_PROFILE_applyDefaults"

/**
    Value for this key is scalar of type boolean which skips criteria
    update based on Validation Rule type ( e.g. Exclude Rule, Availability Rule ).

    If this flag is set to true, expansion of an expression will ignore rule of
    Validation Rule type else those will be considered.
*/
#define CFG_PROFILE_skip_criteria_updt_based_on_validation_rules_key         "CFG_PROFILE_skipCriteriaUpdatesBasedOnValidationRules"

/**
    Value for this key is scalar of type boolean which allows reporting of violations
    if expression contains multiple selections from mutually exclusive single select
    enumerated family.

    If this flag is set to true, violations will be reported for multiple selections
    from mutually exclusive single select enumerated family else those will not be reported.
*/
#define CFG_PROFILE_report_violtn_for_mutually_excl_constraint_key           "CFG_PROFILE_reportViolationForMutuallyExclusiveConstraint"

/**
    Value for this key is scalar of type boolean which performs validation only.
    It disables expression expansion.

    If this flag is set to true, expression expansion will be disabled else
    it will be expanded.
*/
#define CFG_PROFILE_validate_without_expand_key                              "CFG_PROFILE_validateWithoutExpand"

/**
    Value for this key is scalar of type integer. It is minimum #CFG_severity_t
    to be evaluated for validation failures.

    If error severity is not provided, #CFG_severity_error_level is used.
*/
#define CFG_PROFILE_min_error_severity_key                                   "CFG_PROFILE_minErrorSeverity"

/**
    Value for this key is scalar of type integer. It is minimum #CFG_severity_t
    to be reported back.

    If report severity is not provided, #CFG_severity_error_level is used.
*/
#define CFG_PROFILE_min_report_severity_key                                  "CFG_PROFILE_minReportSeverity"

/**
    Value for this key is scalar of type boolean which enables computation of
    all the problems of the unsat core while reporting violations.

    If this flag is set to true, all the problems of the unsat core are computed
    while reporting violations else only first problem is reported.
*/
#define CFG_PROFILE_compute_all_problems_key                                 "CFG_PROFILE_computeAllProblems"

/**
    Value for this key is scalar of type integer which provides the max time in seconds
    that should be spent for removing false positive violations.

    If value for this key is not provided, default time out value will be fetched
    from "Cfg0ViolationComputationTimeout" preference.
*/
#define CFG_PROFILE_violation_computation_timeout_key                        "CFG_PROFILE_violationComputationTimeout"

/**
    Value for this key is scalar of type boolean which converts negative selection into equivalent
    positive selection for enumerated family only.

    If this flag is set to true, negative selection for enumerated family will
    be converted to equivalent positive selections which is used for expression
    expansion else it will not be converted.
    e.g. If an enumerated family contains three option values (a1, a2, a3) and part
    of expression is (!a2), if this flag is set to true, this selection
    will be converted to positive equivalent selections i.e. ( a1 | a3 ).
    Otherwise, (!a2) will be used as is for expression expansion.
*/
#define CFG_PROFILE_resolve_to_positive_enumerations_key                     "CFG_PROFILE_resolveToPositiveEnumerations"

/**
    Value for this key is scalar of type boolean which enables computation of valid range(s) out of
    provided range in criteria expression.

    If this flag is set to true and validation verdict is true then valid range(s) computation of
    all valid subset ranges will be done. Verdict is expected to be valid for entire subset range.

    If this flag is set to false, valid range(s) computation will not be done.
*/
#define CFG_PROFILE_process_complete_validation_range_key                    "CFG_PROFILE_processCompleteValidationRange"

/**
    Value for this key is scalar of type boolean which enables computation of valid value range(s)
    of free form families.

    If this flag is set to true, valid range(s) computation of valid value range(s) of free form
    families will be done.

    If this flag is set to false, valid range(s) computation will not be done and existing range
    on a family without considering constraints will be returned.
*/
#define CFG_PROFILE_compute_range_for_freeform_family_key                    "CFG_PROFILE_computeRangeForFreeFormFamily"

/**
    Value for this key an array of type string. This contains Business Object Type names as
    defined in BMIDE. These constraint types are used for getting constraints from
    Cfg0ConfiguratorPerspective which are used for modification of the input expression.

    If this value for this key is not set then default values are "Cfg0AbsDefaultRule" and
    "Cfg0AbsIncludeRule".
*/
#define CFG_PROFILE_active_constraint_type_filter_key                        "CFG_PROFILE_activeConstraintTypeFilter"

/**
    Value for this key an array of type string. This contains Business Object Type names as
    defined in BMIDE. These constraint types are used for getting constraints from
    Cfg0ConfiguratorPerspective which are used for validation of the input expression.

    If this value for this key is not set then default values are "Cfg0AbsDefaultRule",
    "Cfg0AbsIncludeRule" and "Cfg0AbsValidationRule".
*/
#define CFG_PROFILE_passive_constraint_type_filter_key                       "CFG_PROFILE_passiveConstraintTypeFilter"

/**
    Value for this key an array of type string. This contains Cfg0Intents as specified
    in the Cfg0ConfiguratorPerspective which are used for getting constraints.
    These constraints are used for modification of the input expression.

    If this value for this key is not set then default behavior is to use all
    Cfg0Intents specified in the Cfg0ConfiguratorPerspective.
*/
#define CFG_PROFILE_active_intent_filter_key                                 "CFG_PROFILE_activeIntentFilter"

/**
    Value for this key an array of type string. This contains Cfg0Intents as specified
    in the Cfg0ConfiguratorPerspective which are used for getting constraints.
    These constraints are used for validation of the input expression.

    If this value for this key is not set then default behavior is to use all
    Cfg0Intents specified in the Cfg0ConfiguratorPerspective.
*/
#define CFG_PROFILE_passive_intent_filter_key                                "CFG_PROFILE_passiveIntentFilter"

/**
    Value for this key is scalar of type boolean which enables empty value for discretionary and boolean
    families as system suggestion. Empty value is suggested only when it is not in conflict with any other
    constraints in the system ( user defined or derived constraints )

    If this flag is set to true and validation verdict is true then output expression for a configuration contains
    empty value for discretionary families if no other feature is enforced by any other constraints.
    In case of order mode, user should set this flag as true.

    If this flag is set to false, empty value will not be suggested by system. In case of overlay mode,
    user should set this flag as false.

*/
#define CFG_PROFILE_prefer_empty_value_for_discretionary_family_key          "CFG_PROFILE_preferEmptyValueForDiscretionary"

/**
    Value for this key is scalar of type boolean which enables use of non-conflicting low severity rules lower
    than severity defined in a key "CFG_min_error_severity_key". These low severity rules will be used for getting
    solution during Expand operation.

    If this flag is set to true and validation verdict is true then output expression is expanded using all rules even
    though they are lower than CFG_min_error_severity_key. In case of order mode, user should set this flag as true.

    If this flag is set to false, expansion will not consider rules lower than CFG_min_error_severity_keyseverity.
    In case of overlay mode, user should set this flag as false.
*/
#define CFG_PROFILE_consider_low_severity_rules_for_expansion_key            "CFG_PROFILE_considerLowSeverityRulesForExpansion"
/**
    Value for this key is scalar of type boolean which disables computation of severity for an expression literal of type #CFG0_sample_expr_value_info_t. This is performance intensive operation.
    If this flag is set to true, the system will not compute constraint severity for each expression term.
    If this flag is set to false, the system will compute constraint severity for each expression term. Default value is false, if this key is not set.
*/
#define CFG_PROFILE_skip_solution_severity_processing_key                    "CFG_PROFILE_skipSolutionSeverityProcessing"

/**
    Value for this key is scalar of type boolean which validates the input expression to give #CFG_satisfiability_t verdict and will not minimize the violation set specified in #CFG0_violation_info_t. This is performance intensive operation.
    If this flag is set to true, the system will not compute violation and no violation are reported, only verdict will be returned.
    If this flag is set to false, the system will compute violation and minimize violation( remove false positive ). Default value is false, if this key is not set.
*/
#define CFG_PROFILE_validate_and_skip_violation_minimization_key             "CFG_PROFILE_validateAndSkipViolationMinimization"

/**
    Value for this key is scalar of type boolean which get available values for each family individually after resetting the input expression for the inquired family. This is performance intensive operation.

    If this flag is set to true, the system will get available values for each family individually after resetting the input expression.

    If this flag is set to false, the system will not get available values for each family individually after resetting the input expression. Default value is false, if this key is not set.
*/

#define CFG_PROFILE_get_all_available_values_per_family_key                  "CFG_PROFILE_getAllAvailableValuesPerFamily"

/**
    Value for this key is scalar of type boolean which get package details. This is performance intensive operation.

    If this flag is set to true, the system will get package details.

    If this flag is set to false, the system will only get the status of the value is that value is a package. Default value is false, if this key is not set.
*/

#define CFG_PROFILE_get_package_deatils_key                                  "CFG_PROFILE_getPackageDetails"

/**
    A boolean variable which requests configurator to determine if the input criteria can translate to complete
    configuration considering the relevant set of rules/ constraints.

    Complete configuration has assingment for every family/variable. If the criteria can translate into a complete configuration,
    solution expression representing the configuration is also returned
*/
#define CFG_PROFILE_check_completeness                                       "CFG_PROFILE_check_completeness"

/**
    The CFG_PROFILE_solve_type_key represents the BooleanSolve::SolveType ( a bit pattern specifying the requested solve types ).
    Value for this key is of type BooleanSolve::SolveType and the list of valid values are available in fnd0booleansolve/BooleanSolve.hxx.
    This key is used to set the solve type on variant expression block of the variant rule through configuration session behavior.
    The key/value pair is persisted in varaint expression block's property "cfg0CriteriaEntries".
    Use the getSolveType() function of Variant Expression to get the value peristed in expression block.
*/
#define CFG_PROFILE_solve_type_key                                           "CFG_PROFILE_solve_type"

/**
    This key expects a scalar value of type boolean which decides how to interpret literal expressions about unallocated feature families in conditions and criteria.
        true: The system interprets literal expressions about an unallocated feature family in variant conditions and solve criteria the same as the expression constant "true".
        false: The system interprets literal expressions about an unallocated feature family in variant conditions and solve criteria the same as the expression constant "false".
*/
#define CFG_PROFILE_configure_out_unallocated_features_key                   "CFG_PROFILE_configureOutUnallocatedFeatures"

/**
    It is a date property which holds the date & time of the compiled rule set used to configure the perspective.
    The variability information (such as properties cfg0IncludeRules, cfg0OptionValues etc.) provided by the perspective are configured
    using the Revision Rule and cfg0RuleSetCompileDate. NULL values are allowed for the cfg0RuleSetCompileDate.
*/
#define CFG_CRITERIA_ruleset_compile_date_key                                "CFG_CRITERIA_cfg0RuleSetCompileDate"

/**
    It is a string property which holds the serialized recipe of a RevisionRule from which it could be reconstructed later.
*/
#define CFG_CRITERIA_revision_rule_recipe_key                                "CFG_CRITERIA_cfg0RevisionRuleRecipe"

/**
    It is a string property which holds name of the Productwhich anchors the variability. Its is used in conjunction with cfg0ProductNamespace parameter to resolve
    any ambiguity in variant variable names. For example, resolving Capacity into [Refrigerator]Capacity versus [WashingMachine]Capacity.
*/
#define CFG_CRITERIA_product_name_key                                        "CFG_CRITERIA_cfg0ProductName"

/**
    It is a string property which holds the namespace of the Product which anchors the variability. It is used in conjunction with cfg0ProductName parameter
    to resolve any ambiguity in variant variable names. For example, resolving Capacity into [Refrigerator]Capacity versus [WashingMachine]Capacity.
*/
#define CFG_CRITERIA_product_namespace_key                                   "CFG_CRITERIA_cfg0ProductNamespace"

/**
    The CFG_PROFILE_solve_type_key represents the BooleanSolve::SolveType ( a bit pattern specifying the requested solve types ).
    Value for this key is of type BooleanSolve::SolveType and the list of valid values are available in fnd0booleansolve/BooleanSolve.hxx.
    This key is used to set the solve type on variant expression block of the variant rule through configuration session behavior.
    The key/value pair is persisted in varaint expression block's property "cfg0CriteriaEntries".
    Use the getSolveType() function of Variant Expression to get the value peristed in expression block.
*/
#define CFG_PROFILE_solve_type_key                                           "CFG_PROFILE_solve_type"
#if TC_MAJOR_VERSION + TC_MINOR_VERSION <= 11007 /** Deprecated in Tc11.5, removed in Tc11.7 and later */

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_apply_config_constraints_key instead */
#define CFG_apply_config_constraints_key                            CFG_PROFILE_apply_config_constraints_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_apply_defaults_key instead */
#define CFG_apply_defaults_key                                      CFG_PROFILE_apply_defaults_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_skip_criteria_updt_based_on_validation_rules_key instead */
#define CFG_skip_criteria_updates_based_on_validation_rules_key     CFG_PROFILE_skip_criteria_updt_based_on_validation_rules_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_report_violtn_for_mutually_excl_constraint_key instead */
#define CFG_report_violation_for_mutually_exclusive_constraint_key  CFG_PROFILE_report_violtn_for_mutually_excl_constraint_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_validate_without_expand_key instead */
#define CFG_validate_without_expand_key                             CFG_PROFILE_validate_without_expand_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_min_error_severity_key instead */
#define CFG_min_error_severity_key                                  CFG_PROFILE_min_error_severity_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_min_report_severity_key instead */
#define CFG_min_report_severity_key                                 CFG_PROFILE_min_report_severity_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_compute_all_problems_key instead */
#define CFG_compute_all_problems_key                                CFG_PROFILE_compute_all_problems_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_violation_computation_timeout_key instead */
#define CFG_violation_computation_timeout_key                       CFG_PROFILE_violation_computation_timeout_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_resolve_to_positive_enumerations_key instead */
#define CFG_resolve_to_positive_enumerations_key                    CFG_PROFILE_resolve_to_positive_enumerations_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_process_complete_validation_range_key instead */
#define CFG_process_complete_validation_range_key                   CFG_PROFILE_process_complete_validation_range_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_compute_range_for_freeform_family_key instead */
#define CFG_compute_range_for_freeform_family_key                   CFG_PROFILE_compute_range_for_freeform_family_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_active_constraint_type_filter_key instead */
#define CFG_active_constraint_type_filter_key                       CFG_PROFILE_active_constraint_type_filter_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_passive_constraint_type_filter_key instead */
#define CFG_passive_constraint_type_filter_key                      CFG_PROFILE_passive_constraint_type_filter_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_active_intent_filter_key instead */
#define CFG_active_intent_filter_key                                CFG_PROFILE_active_intent_filter_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_passive_intent_filter_key instead */
#define CFG_passive_intent_filter_key                               CFG_PROFILE_passive_intent_filter_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_prefer_empty_value_for_discretionary_family_key instead */
#define CFG_prefer_empty_value_for_discretionary_family_key         CFG_PROFILE_prefer_empty_value_for_discretionary_family_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_consider_low_severity_rules_for_expansion_key instead */
#define CFG_consider_low_severity_rules_for_expansion_key           CFG_PROFILE_consider_low_severity_rules_for_expansion_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_skip_solution_severity_processing_key instead */
#define CFG_skip_solution_severity_processing_key                   CFG_PROFILE_skip_solution_severity_processing_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_validate_and_skip_violation_minimization_key instead */
#define CFG_validate_and_skip_violation_minimization_key            CFG_PROFILE_validate_and_skip_violation_minimization_key

/** @deprecated This is deprecated in Tc11.5 and will be removed in Tc13. Use #CFG_PROFILE_get_all_available_values_per_family_key instead */
#define CFG_get_all_available_values_per_family_key                 CFG_PROFILE_get_all_available_values_per_family_key

#ifdef WNT
/** #pragma deprecated issues warning C4995 (which is treated as an error in Teamcenter builds) unlike __declspec(deprecated), which triggers warning C4996*/
#pragma deprecated( "CFG_apply_config_constraints_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_apply_config_constraints_key */
#pragma deprecated( "CFG_apply_defaults_key" ) /** deprecated in Tc11.5. Please use CFG_apply_defaults_key */
#pragma deprecated( "CFG_skip_criteria_updates_based_on_validation_rules_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_skip_criteria_updt_based_on_validation_rules_key */
#pragma deprecated( "CFG_report_violation_for_mutually_exclusive_constraint_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_report_violtn_for_mutually_excl_constraint_key */
#pragma deprecated( "CFG_validate_without_expand_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_validate_without_expand_key */
#pragma deprecated( "CFG_min_error_severity_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_min_error_severity_key */
#pragma deprecated( "CFG_min_report_severity_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_min_report_severity_key */
#pragma deprecated( "CFG_compute_all_problems_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_compute_all_problems_key */
#pragma deprecated( "CFG_violation_computation_timeout_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_violation_computation_timeout_key */
#pragma deprecated( "CFG_resolve_to_positive_enumerations_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_resolve_to_positive_enumerations_key */
#pragma deprecated( "CFG_process_complete_validation_range_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_process_complete_validation_range_key */
#pragma deprecated( "CFG_compute_range_for_freeform_family_key " ) /** deprecated in Tc11.5. Please use CFG_PROFILE_compute_range_for_freeform_family_key */
#pragma deprecated( "CFG_active_constraint_type_filter_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_active_constraint_type_filter_key */
#pragma deprecated( "CFG_passive_constraint_type_filter_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_passive_constraint_type_filter_key */
#pragma deprecated( "CFG_active_intent_filter_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_active_intent_filter_key */
#pragma deprecated( "CFG_passive_intent_filter_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_passive_intent_filter_key */
#pragma deprecated( "CFG_prefer_empty_value_for_discretionary_family_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_prefer_empty_value_for_discretionary_family_key */
#pragma deprecated( "CFG_consider_low_severity_rules_for_expansion_key " ) /** deprecated in Tc11.5. Please use CFG_PROFILE_consider_low_severity_rules_for_expansion_key */
#pragma deprecated( "CFG_skip_solution_severity_processing_key" ) /** deprecated in Tc11.5. Please use CFG_PROFILE_skip_solution_severity_processing_key */
#pragma deprecated( "CFG_validate_and_skip_violation_minimization_key " ) /** deprecated in Tc11.5. Please use CFG_PROFILE_validate_and_skip_violation_minimization_key */
#pragma deprecated( "CFG_get_all_available_values_per_family_key " ) /** deprecated in Tc11.5. Please use CFG_PROFILE_get_all_available_values_per_family_key */
#pragma deprecated( "CFG_operator_expanded_criteria " ) /** deprecated in Tc11.6. CFG_operator_rule_set is used for expanded criteria*/
#endif /** #ifdef WNT */
#endif /** #if TC_MAJOR_VERSION + TC_MINOR_VERSION <= 11007 */

/**
    @}
*/

#endif
