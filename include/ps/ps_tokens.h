/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2016.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    PS interface tokens
*/

/*  */

#ifndef PS_TOKENS_H_INCLUDED
#define PS_TOKENS_H_INCLUDED

#include <booleanmath/cfg_tokens.h>
#include <ps/libps_exports.h>

/**
    @defgroup PS_TOKENS Tokens
    @ingroup PS
    @{
*/

/** Equivalent to what was previously known as BOM_option_mode_int*/
#define PS_variant_option_mode_unknown                    CFG_mode_unknown

/** An opcode offset that indicates that the right operand is provided as string and not as tag */
#define PS_variant_op_rhs_is_string                       1000

/** Equivalent to what was previously known as BOM_option_mode_enum
    "2" < "10" but "2E0" > "1E1" */
#define PS_variant_option_mode_dynamic_comparison         CFG_mode_dynamic_comparison

/** Indicate that the variant option will be considered as lexicohgraphic value
    "2" > "10" and "2E0" > "1E1" */
#define PS_variant_option_mode_lexicographic_comparison   CFG_mode_lexicographic_comparison

/** Indicate that the variant option  will be considered as numeric value
    "2" < "10" and "2E0" < "1E1" */
#define PS_variant_option_mode_numeric_comparison         CFG_mode_numeric_comparison

/** Indicate that the variant option will be considered as integer value */
#define PS_variant_option_mode_integer_comparison         CFG_mode_integer_comparison

/** Indicate that the variant option will be considered as Date value
    convert values to UTC dates using DATE_convert_iso_date_to_date_t() (tc_date.h) before comparing */
#define PS_variant_option_mode_date_comparison            CFG_mode_date_comparison

/** Indicate that the variant option will be considered as discretionary value
    UNSET means "none of" else it means "any of" */
#define PS_variant_option_mode_discretionary              CFG_mode_discretionary

/** Indicate that the variant option will be considered as designator value */
#define PS_variant_option_mode_model_designator_option    CFG_mode_model_designator_option

/** Indicate that the option will be considered as logical value with only two states, e.g. On/Off, True/False, or present/absent */
#define PS_variant_option_mode_logical_comparison         CFG_mode_logical_comparison

/** Indicate the option will support free form values */
#define PS_variant_option_mode_free_form                  CFG_mode_free_form

/** Indicate the option will support multiple selection */
#define PS_variant_option_mode_multi_select               CFG_mode_multi_select


/** Operator codes */

/** The left operand selects one VariantRevision from all those that reference the same parent
 *  Variant (VariantRevision.parent_variant).
 *  The expression may optionally restrict the domain of values for this Variant.
 */
#define PS_variant_operator_declare                       CFG_operator_declare

/** The right operand records the use of a specific value index for the Variant specified in the
 *  left operand.
 */
#define PS_variant_operator_assy_uses                     CFG_operator_assy_uses

/** The right operand assigns a specific value index for the Variant specified in the left operand
 *  in a derived default.
 */
#define PS_variant_operator_assign                        CFG_operator_assign

/** The right operand defines a fixed default value index for the Variant specified in the left
 *  operand.
 */
#define PS_variant_operator_default                       CFG_operator_default

/** The right operand specifies the value index to which the Variant specified in the left operand
 *  is compared using the Equal comparator.
 */
#define PS_variant_operator_is_equal                      CFG_operator_is_equal

/** The right operand specifies the value index to which the Variant specified in the left operand
 *  is compared using the Not Equal comparator.
 */
#define PS_variant_operator_not_equal                     CFG_operator_not_equal

/** The left operand specifies the condition of a Rule Check under which the error message given in
 *  the right operand should be displayed.
 */
#define PS_variant_operator_error_if                      CFG_operator_error_if

/** Specifies a comment that does not impact Boolean evaluation. */
#define PS_variant_operator_comment                       CFG_operator_comment

/** The right operand defines the variant scope for a BOMLine. */
#define PS_variant_operator_load_if                       CFG_operator_load_if

/** Combines the left and the right operand with the And operator. */
#define PS_variant_operator_and                           CFG_operator_and

/** Combines the left and the right operand with the Or operator. */
#define PS_variant_operator_or                            CFG_operator_or

/** The left operand defines the default assignment to be applied in a Derived Default if the right
 *  operand's condition is met.
 */
#define PS_variant_operator_if                            CFG_operator_if

/** The right operand specifies the value text to which the Variant specified in the left operand is
 *  compared using the Greater Than comparator.
 */
#define PS_variant_operator_gt                            CFG_operator_gt

/** The right operand specifies the value text to which the Variant specified in the left operand is
 *  compared using the Less Than comparator.
 */
#define PS_variant_operator_lt                            CFG_operator_lt

/** The right operand specifies the value text to which the Variant specified in the left operand is
 *  compared using the Greater Than Or Equal comparator.
 */
#define PS_variant_operator_gt_eq                         CFG_operator_gt_eq

/** The right operand specifies the value text to which the Variant specified in the left operand is
 *  compared using the Less Than Or Equal comparator.
 */
#define PS_variant_operator_lt_eq                         CFG_operator_lt_eq

/** Encloses the right operand in brackets and ignores the left operand. */
#define PS_variant_operator_brackets                      CFG_operator_brackets

/** The right operand specifies the value index to use for the Variant specified in the left operand
 *  in a Saved Variant Rule.
 */
#define PS_variant_operator_rule_set                      CFG_operator_rule_set

/** The left operand defines the condition enclosed in a Named Variant Expression. */
#define PS_variant_operator_named_expr                    CFG_operator_named_expr

/** The right operand defines the logical tree of an expression that forms a Named Variant
 *  Expression Meta-expression.
 */
#define PS_variant_operator_meta_expr                     CFG_operator_meta_expr

/** The left operand references the Named Variant Expression identified by the text given in the
 *  right operand.
 */
#define PS_variant_operator_nve_ref                       CFG_operator_nve_ref

/** Negates the right operand and ignores the left - ONLY SUPPORTED IN META-EXPRESSIONS. */
#define PS_variant_operator_not                           CFG_operator_not

/** Defines the maximum range of validity up to which a PS_variant_operator_load_if condition can be
 *  expanded.
 */
#define PS_variant_operator_applicability                 CFG_operator_applicability

/** Defines how a dependent variant variable maps to its a master variable when substituting
 *  dependent variables, e.g. how "Risk" maps to "Size".
 */
#define PS_variant_operator_use_dependent                 CFG_operator_use_dependent

/** A VariantExpression with this operator code defines the applicability condition used in a filter
 *  expression that qualifies the parent expression.
 */
#define PS_variant_operator_condition                     CFG_operator_condition

/** Defines configuration criteria which may become active under certain conditions. */
#define PS_variant_operator_criteria_set                  CFG_operator_criteria_set

/** Defines configuration criteria for a transient variant rule.
 *  The right operand references the POM user tag for which the transient criteria was created.
 *  The string attribute specifies the POM session that created this expression.
*/
#define PS_variant_operator_transient_criteria_set        CFG_operator_transient_criteria_set

/** A VariantExpression with this operator code represents a configuration validation criterion
 *  which must evaluate to true in order for a configuration rule to be considered valid.
 */
#define PS_variant_operator_inclusive_constraint          CFG_operator_inclusive_constraint

/** A VariantExpression with this operator code represents a configuration validation criterion
 *  which must evaluate to false in order for a configuration rule to be considered valid.
 */
#define PS_variant_operator_exclusive_constraint          CFG_operator_exclusive_constraint

/** The left operand defines a filter expression that qualifies a configuration validation criterion
 *  with ERROR severity specified by the right operand.
 */
#define PS_variant_operator_constraint_error              CFG_operator_constraint_error

/** The left operand defines a filter expression that qualifies a configuration validation criterion
 *  with INFORM severity specified by the right operand.
 */
#define PS_variant_operator_constraint_inform             CFG_operator_constraint_inform

/** The left operand defines a filter expression that qualifies a configuration validation criterion
 *  with WARN severity specified by the right operand.
 */
#define PS_variant_operator_constraint_warn               CFG_operator_constraint_warn

/** VariantExpressions with this operator code define criteria that all products of a given "model"
 *  or "product family" have in common.
 */
#define PS_variant_operator_product_family_condition      CFG_operator_product_family_condition

/** A VariantExpression with this operator code records the use of a value range for the Variant
 *  specified in the left operand.
 */
#define PS_variant_operator_value_range                   CFG_operator_value_range

/**
 * Defines a "persistentID" operator
 */
#define PS_variant_operator_persistent_id                 CFG_operator_persistent_id

/** Combines the left operand defining a "product family" condition with the right operand defining
 *  an applicability condition using the operator AND.
 */
#define PS_variant_operator_filter_condition              CFG_operator_filter_condition

/** The left operand defines a filter expression that qualifies a Default Assignment specified by
 *  the right operand.
 */
#define PS_variant_operator_derived_default_rule          CFG_operator_derived_default_rule

/** The right operand specifies an unconditional Default Assignment. */
#define PS_variant_operator_fixed_default_rule            CFG_operator_fixed_default_rule

/** Defines a "tautology" (TT) expression that always evaluates to true. No operands. */
#define PS_variant_operator_tt                            CFG_operator_tt

/** Defines a "contradiction" (CT) expression that always evaluates to false. No operands. */
#define PS_variant_operator_ct                            CFG_operator_ct

/** A VariantExpression with this operator code represents a configuration validation criterion
 which must evaluate to true in order for a configuration rule to be considered valid.
 */
#define PS_variant_operator_feasibility_constraint        CFG_operator_feasibility_constraint

/** Defines an enforced condition for a rule.
 e.g. Exclude Rule : ~model | ~applicability | model & applicability & ~restriction
 Include Rule : ~model | ~applicability | model & applicability & restriction
 */
#define PS_variant_operator_enforced_condition            CFG_operator_enforced_condition

/** Defines a variant expression which is a combined representation of package
 e.g. Package P1 has member A1, B1 and C1
 Expression will A1 & B1 & C1
 */
#define PS_product_line_variant_expression                CFG_product_line_variant_expression

/** Offset for PSM-PCA operators */
#define PS_obsolete_classic_options_offset                400
#define PS_variant_reserved_1                             401
#define PS_variant_reserved_2                             412
#define PS_variant_reserved_3                             404
#define PS_variant_reserved_4                             407
#define PS_variant_reserved_5                             418

/** Offset indicating that this operator is effectivty related */
#define PS_effectivity_operator_offset                    CFG_effectivity_operator_offset

/** The left operand selects one VariantRevision for effectivity options from all that reference the same parent Variant (VariantRevision.parent_variant).
 *  The expression may optionally restrict the domain of values for this Variant.
 */
#define PS_effectivity_operator_declare                   CFG_effectivity_operator_declare

/** The right operand records the use of a specific value index for the Variant specified in the left operand */
#define PS_effectivity_operator_used_value                CFG_effectivity_operator_used_value

/** Expressions with this operator code record the use of an effectivity value range for the Variant specified in the left operand */
#define PS_effectivity_operator_value_range               CFG_effectivity_operator_value_range

/** The right operand defines a fixed value index for the Variant specified in the left operand */
#define PS_effectivity_operator_fixed_default_rule        CFG_effectivity_operator_fixed_default_rule

/** The left operand specifies the condition of a Rule Check under which the error message given in the right operand should be displayed */
#define PS_effectivity_operator_error_if                  CFG_effectivity_operator_error_if

/** The right operand defines the effectivity scope for an EffectivityConfigurable object */
#define PS_effectivity_operator_load_if                   CFG_effectivity_operator_load_if

/** Defines how a dependent effectivity variable maps to its a master variable when substituting dependent variables, e.g. how "Vacation" maps to "Date" */
#define PS_effectivity_operator_use_dependent             CFG_effectivity_operator_use_dependent

/** Defines configuration criteria which may become active under certain conditions */
#define PS_effectivity_operator_criteria_set              CFG_effectivity_operator_criteria_set

/** Defines the maximum range of validity up to which a PS_effectivity_operator_load_if condition can be expanded */
#define PS_effectivity_operator_applicability             CFG_effectivity_operator_applicability

/** Combines the left operand defining a "product family" effectivity condition with the right operand defining an effectivity applicability condition using the operator AND */
#define PS_effectivity_operator_filter_condition          CFG_effectivity_operator_filter_condition

/** Expressions with this operator code define effectivity criteria all products of a given "model" or "product family" have in common */
#define PS_effectivity_operator_product_family_condition  CFG_effectivity_operator_product_family_condition

/** Expressions with this operator code define the applicability condition used in a filter expression that that qualifies the parent effectivity expression */
#define PS_effectivity_operator_condition                 CFG_effectivity_operator_condition

/** Expressions with this operator code represent configuration validation criteria which all configuration rules should pass in order to be considered valid */
#define PS_effectivity_operator_inclusive_constraint      CFG_effectivity_operator_inclusive_constraint

/** Expressions with this operator code represent effectivity configuration validation criteria which all configuration rules should not meet in order to be considered valid */
#define PS_effectivity_operator_exclusive_constraint      CFG_effectivity_operator_exclusive_constraint

/** The left operand defines a filter expression that qualifies a configuration validation criteria ERROR severity specified by the right operand */
#define PS_effectivity_operator_constraint_error          CFG_effectivity_operator_constraint_error

/** The left operand defines a filter expression that qualifies a configuration validation criteria INFORM severity specified by the right operand */
#define PS_effectivity_operator_constraint_inform         CFG_effectivity_operator_constraint_inform

/** The left operand defines a filter expression that qualifies a configuration validation criteria WARN severity specified by the right operand */
#define PS_effectivity_operator_constraint_warn           CFG_effectivity_operator_constraint_warn

/** The left operand defines a filter expression that qualifies the effectivity default assignment given in the right operand */
#define PS_effectivity_operator_derived_default_rule      CFG_effectivity_operator_derived_default_rule

/**
    @name Class tokens

    Used to identify PS classes with client data functions.
    @{
*/
#define  PS_min_class_token         1001
#define  PS_view_type               1001
#define  PS_bom_view                1002
#define  PS_bom_view_revision       1003
#define  PS_occurrence              1004
#define  PS_max_class_token         1004
/** @} */

/**
    When the instance is copied, the client data gets copied with it.
*/
#define  PS_copyable                (1 << 0)

/**
    All op's (create/unload/save/refresh/delete) are handled for the user.
    Therefore they only ask/set the values within their client data instance.
    The instance will be of the class used for typing.
*/
#define  PS_manage                  (1 << 1)

#define  PS_valid_props             (PS_copyable | PS_manage)

/**
    Occurrence flags.
*/
#define  PS_qty_as_required         (1 << 0)

/**
    Represents the EndItem of the occurrence
*/
#define  PS_mono_override           (1 << 1)

/**
    Do where used for any number of levels until you reach assemblies with no parent assemblies.
*/
#define  PS_where_used_all_levels   -1

#define  PS_max_note_length         160

/**
    All BOMViews created via the user interface are of this type.
*/
#define  PS_default_view_type_name  "view"

/**
    Preference values for legacy transform format
*/
typedef enum
{
    PS_transform_format_in_legacy,
    PS_transform_format_written_by_ug,
    PS_transform_format_unknown
}PS_legacy_transform_format_t;

/** @} */

#include <ps/libps_undef.h>
#endif
