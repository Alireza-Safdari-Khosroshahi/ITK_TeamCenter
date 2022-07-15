/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/*  */

/**
    @file

    This file contains the constants, data structures and public C ITK function prototypes for working with configurator.
    The configurator module deals with variant data such as Families, values and rules.
*/

#ifndef TEAMCENTER_CFG0CONFIGURATOR_H
#define TEAMCENTER_CFG0CONFIGURATOR_H

#include <configurator/configurator.h>
#include <unidefs.h>
#include <Cfg0configurator/libcfg0configurator_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    @defgroup CFG0CONFIGURATOR Product Configurator (CFG0)
    @ingroup TC

    The Product Configurator (CFG0) module is intended to give a consistent interface to
    operate on Product Configurator data such as feature families, features, allocations and constraint rules.

    @{
*/

/**
   Holds an Family revision and its value revisions for given configurator perspective and set of family tags.
*/
typedef struct
{
    tag_t family_revision;                  /**< Family object. */
    int n_value_revisions;                  /**< The number of elements in @p value_revisions. */
    const tag_t * value_revisions;          /**< n_value_revisions Array of configured value revisions for @p family_revision. */
} CFG0_option_family_values_t;

/**
   Holds allocation revisions for given configurator perspective and set of family and value tags.
*/
typedef struct
{
    tag_t allocated_object;                  /**< Allocated object. */
    int n_allocation_revisions;              /**< Number of elements in @p allocation_revisions. */
    const tag_t * allocation_revisions;      /**< n_allocation_revisions Array of allocation revisions for @p allocated_object. */
} CFG0_allocation_t;

/**
   Holds information for a violated configurator constraint which is reported as part of a conflict.
*/
typedef struct
{
    tag_t violated_constraint;   /**< The object of violated constraint. */
    const char * message;        /**< The message that is associated with the violated constraint. <br/>It is populated only if @p violated_constraint is #NULLTAG. */
} CFG0_violation_info_t;

/**
   Holds information for a conflict found during evaluation of configuration against configurator constraints.
*/
typedef struct
{
    int n_violations;                        /**< The number of elements in @p violations. */
    const CFG0_violation_info_t* violations; /**< Array of violated configurator constraints. */
} CFG0_conflict_info_t;

/**
   Holds a variant Feature information.
*/
typedef struct
{
    tag_t family;           /**< The Family object for @p value_id. */
    const char * value_id;  /**< The ID of the Feature. */
    tag_t value;            /**< The object of the Feature. */
} CFG0_option_value_info_t;

/**
   Qualifies the Features associated with an expression. The expression could be obtained from evaluation of a configuration
   against a configuration. The expression will have a number of values which can be mapped to the contributing constraints or
   the input configuration which can be treated as a user constraint.
*/
typedef struct
{
    CFG_severity_t severity;                     /**< The severity of the contributing constraint. */
    const CFG0_option_value_info_t* value_info;  /**< The contributed Feature information. */
} CFG0_sample_expr_value_info_t;

/**
   Holds information of single configuration solver profile entry of string type as defined in @ref CFG_CONFIGURATION_PROFILE.
   <br/>For example, to evaluate configurator constraints having an active intent "Technical", the solver profile entry can be specified as:
   @code
   const char *key_text = CFG_active_intent_filter_key;
   const char *value_texts[1] = { "Technical" };
   CFG0_conf_solver_profile_str_entry_t str_profile_entry;
   str_profile_entry.key_text = keyText;
   str_profile_entry.n_values = 1;
   str_profile_entry.values = ( const char** ) &value_texts;
   @endcode
*/
typedef struct
{
    const char *key_text;   /**< key text for configuration solver profile string type entry. */
    int n_values;           /**< Number of values in array @p values. */
    const char **values;    /**< n_values Values corresponding to @p key_text. */
} CFG0_conf_solver_profile_str_entry_t;

/**
   Holds information of single configuration solver profile entry of integer type as defined in @ref CFG_CONFIGURATION_PROFILE.
   <br/>For example, to specify the minimum error severity as #CFG_severity_warning_level while evaluating the configurator constraints, the solver profile entry can be specified as:
   @code
   const char *key_text = CFG_min_error_severity_key;
   const int *value_ints[1] = { (int)CFG_severity_warning_level };
   CFG0_conf_solver_profile_int_entry_t int_profile_entry;
   int_profile_entry.key_text = key_text;
   int_profile_entry.n_values = 1;
   int_profile_entry.values = &value_ints;
   @endcode
*/
typedef struct
{
    const char *key_text; /**< key text for configuration solver profile integer type entry. */
    int n_values;         /**< Number of values in array @p values. */
    const int *values;    /**< n_values Values corresponding to @p key_text. */
} CFG0_conf_solver_profile_int_entry_t;

/**
   Holds information of single configuration solver profile entry of boolean type as defined in @ref CFG_CONFIGURATION_PROFILE.
   <br/>For example, to specify that the configurator constraint evaluation should not compute all the conflicts, the solver profile entry can be specified as:
   @code
   const char *key_text = CFG_compute_all_problems_key;
   const bool *value_bools[1] = { false };
   CFG0_conf_solver_profile_bool_entry_t bool_profile_entry;
   bool_profile_entry.key_text = key_text;
   bool_profile_entry.n_values = 1;
   bool_profile_entry.values = &value_bools;
   @endcode
*/
typedef struct
{
    const char *key_text;  /**< key text for configuration solver profile boolean type entry. */
    int n_values;          /**< Number of values in array @p values. */
    const bool *values;    /**< @p n_values Values corresponding to @p key_text. */
} CFG0_conf_solver_profile_bool_entry_t;

/**
   Holds information of single configuration solver profile entry of double type as defined in @ref CFG_CONFIGURATION_PROFILE.
*/
typedef struct
{
    const char *key_text;    /**< key text for configuration solver profile double type entry. */
    int n_values;            /**< Number of values in array @p values. */
    const double *values;    /**< @p n_values Values corresponding to @p key_text. */
} CFG0_conf_solver_profile_double_entry_t;

/**
   Holds information of single configuration solver profile entry of tag_t type as defined in @ref CFG_CONFIGURATION_PROFILE.
*/
typedef struct
{
    const char *key_text;   /**< key text for configuration solver profile tag_t type entry. */
    int n_values;           /**< Number of values in array @p values. */
    const tag_t *values;    /**< @p n_values Values corresponding to @p key_text. */
} CFG0_conf_solver_profile_tag_entry_t;

/**
   Holds information of single configuration solver profile entry of date type as defined in @ref CFG_CONFIGURATION_PROFILE.
*/
typedef struct
{
    const char *key_text;    /**< key text for configuration solver profile date_t type entry. */
    int n_values;            /**< Number of values in array @p values. */
    const date_t *values;    /**< @p n_values Values corresponding to @p key_text. */
} CFG0_conf_solver_profile_date_entry_t;

/**
    Holds information of configuration solver profile entries of various types.
    The configuration solver profile is used to control the behavior of configurator constraint evaluation.
    The solver profile entries hold various configuration tokens as keys and their values as defined in @ref CFG_CONFIGURATION_PROFILE.

    <br/>For example, to validate configurations against all configurator constraints without computing all conflicts, the configuration solver profile can be set as:
    @code
    // Define solver profile entry to consider constraints with minimum error severity as warning.
    const char *key_min_err = CFG_min_error_severity_key;
    const int *value_int_min_err[1] = { (int)CFG_severity_warning_level };
    CFG0_conf_solver_profile_int_entry_t err_profile_entry;
    err_profile_entry.key_text = key_min_err;
    err_profile_entry.n_values = 1;
    err_profile_entry.values = &value_int_min_err;

    // Define solver profile entry to consider constraints with minimum severity as warning while reporting the conflicts.
    const char *key_min_rep = CFG_min_report_severity_key;
    const int *value_int_min_rep[1] = { (int)CFG_severity_warning_level };
    CFG0_conf_solver_profile_int_entry_t rep_profile_entry;
    rep_profile_entry.key_text = key_min_rep;
    rep_profile_entry.n_values = 1;
    rep_profile_entry.values = &value_int_min_rep;

    // Define solver profile entry to define timeout in seconds for constraint evaluation and computing violations.
    const char *key_timeout = CFG_violation_computation_timeout_key;
    const int *value_timeout[1] = { 2 };
    CFG0_conf_solver_profile_int_entry_t timeout_profile_entry;
    timeout_profile_entry.key_text = key_timeout;
    timeout_profile_entry.n_values = 1;
    timeout_profile_entry.values = &value_timeout;

    CFG0_conf_solver_profile_int_entry_t int_profile_entries[3];
    int_profile_entries[0] = err_profile_entry;
    int_profile_entries[1] = rep_profile_entry;
    int_profile_entries[2] = timeout_profile_entry;

    // Define solver profile entry to avoid computing all conflicts.
    const char *key_compute_all = CFG_compute_all_problems_key;
    const bool *value_comp_all[1] = { false };
    CFG0_conf_solver_profile_bool_entry_t comp_all_profile_entry;
    comp_all_profile_entry.key_text = key_compute_all;
    comp_all_profile_entry.n_values = 1;
    comp_all_profile_entry.values = &value_comp_all;

    // Define solver profile entry to apply constraints.
    const char *key_appl_constr = CFG_apply_config_constraints_key;
    const bool *value_appl_constr[1] = { true };
    CFG0_conf_solver_profile_bool_entry_t appl_constr_profile_entry;
    appl_constr_profile_entry.key_text = key_appl_constr;
    appl_constr_profile_entry.n_values = 1;
    appl_constr_profile_entry.values = &value_appl_constr;

    CFG0_conf_solver_profile_bool_entry_t bool_profile_entries[2];
    bool_profile_entries[0] = comp_all_profile_entry;
    bool_profile_entries[1] = appl_constr_profile_entry;

    // Create configuration profile with solver profile entries.
    CFG0_conf_solver_profile_info_t solver_profile_info;
    solver_profile_info.n_int_type_profile_entries = 3;
    solver_profile_info.int_type_profile_entries = int_profile_entries;

    solver_profile_info.n_bool_type_profile_entries = 2;
    solver_profile_info.bool_type_profile_entries = bool_profile_entries;

    // It is absolutely essential to initialize all unused profile entry pointers to null to avoid unexpected exceptions.
    solver_profile_info.n_str_type_profile_entries = 0;
    solver_profile_info.str_type_profile_entries = 0;
    solver_profile_info.n_double_type_profile_entries = 0;
    solver_profile_info.double_type_profile_entries = 0;
    solver_profile_info.n_tag_type_profile_entries = 0;
    solver_profile_info.tag_type_profile_entries = 0;
    solver_profile_info.n_date_type_profile_entries = 0;
    solver_profile_info.date_type_profile_entries = 0;
    @endcode
*/
typedef struct
{
    int n_str_type_profile_entries;                                             /**< Number of profile entries having string datatype. */
    const CFG0_conf_solver_profile_str_entry_t *str_type_profile_entries;       /**< n_str_type_profile_entries array containing profile entries having string datatype. */

    int n_int_type_profile_entries;                                             /**< Number of profile entries having integer datatype. */
    const CFG0_conf_solver_profile_int_entry_t *int_type_profile_entries;       /**< n_int_type_profile_entries array containing profile entries having integer datatype. */

    int n_bool_type_profile_entries;                                            /**< Number of profile entries having boolean datatype. */
    const CFG0_conf_solver_profile_bool_entry_t *bool_type_profile_entries;     /**< n_bool_type_profile_entries array containing profile entries having boolean datatype. */

    int n_double_type_profile_entries;                                          /**< Number of profile entries having double datatype. */
    const CFG0_conf_solver_profile_double_entry_t *double_type_profile_entries; /**< n_double_type_profile_entries array containing profile entries having double datatype. */

    int n_tag_type_profile_entries;                                             /**< Number of profile entries having tag_t datatype. */
    const CFG0_conf_solver_profile_tag_entry_t *tag_type_profile_entries;       /**< n_tag_type_profile_entries array containing profile entries having tag_t datatype. */

    int n_date_type_profile_entries;                                            /**< Number of profile entries having date_t datatype. */
    const CFG0_conf_solver_profile_date_entry_t *date_type_profile_entries;     /**< n_date_type_profile_entries array containing profile entries having date_t datatype. */
} CFG0_conf_solver_profile_info_t;

/**
Represents a pair of conditions to compare.
<br/>E.g. @p left_condition is the expression @c "[NS]A=A1 & [NS]B=B1" and @p right_condition is the expression @c "[NS]B=B1 | [NS]B=B2".
<br/>The left and right may or may not be logically the same.
<br/>The expression string should be in the Teamcenter formula format.
*/
typedef struct
{
    const char* left_condition;        /**< The left hand side condition for comparison (i.e. applicability / variant expression / effectivity expression) */
    const char* right_condition;       /**< The right hand side condition for comparison (i.e. applicability / variant expression / effectivity expression) */
} CFG0_condition_to_compare_t;

/**
Defines the possible values for overlap_state of a pair of conditions.
*/
typedef enum CFG0_overlap_state_e
{
    CFG0_overlap_state_none = 0,        /**< The two expressions have no overlap. There is no satisfying solution common to both expressions. A conjunction(AND combination) of the two is unsatisfiable. */
    CFG0_overlap_state_match = 1,       /**< Two expressions have overlap state "match" if they are logically equivalent. Every solution that satisfies one expression also satisfies the other, and vice versa. */
    CFG0_overlap_state_subset = 2,      /**< An expression e1 has overlap state "subset" with expression e2 if the solution set of e1 is a subset of the solution set of e2. The conjunction "e1 AND NOT e2" is unsatisfiable. */
    CFG0_overlap_state_superset = 3,    /**< An expression e1 has overlap state "superset" with expression e2 if the solution set of e1 is a superset of the solution set of e2. The conjunction "NOT e1 AND e2" is unsatisfiable. */
    CFG0_overlap_state_intersect = 4    /**< The two expressions overlap. The solution set of the expression has some overlap with the solution set of the reference expression. */
} CFG0_overlap_state_t;

/**
Holds variant and effectivity expressions in string format or a variant and/or effectivity configurable object.
<br/>If @p configurable is #NULLTAG, only the variant and effectivity expressions are considered.
<br/>Configurable object is not supported. It is a provision for future release.
*/
typedef struct
{
    const char * variant;           /**< Variant expression in string format. */
    const char * effectivity;       /**< Effectivity expression in string format. */
    tag_t configurable;             /**< Variant and/or effectivity configurable object. */
}CFG0_configurable_expression_t;

/**
Holds a set of CFG0_configurable_expression_t.
*/
typedef struct
{
    int n_configurations;                                       /**< (I)  Number of configurations in @p configurations. */
    const CFG0_configurable_expression_t **configurations;      /**< (I)  n_configurations The configuration expressions to be validated. */
}CFG0_configuration_set_t;

/**
    @name Search Functions
    @{
*/

/**
   Retrieves an array of Family revision and its value revisions for given configurator perspective and set of family tags.
   <br/>All configured value revisions will be retrieved if input family revision is not provided.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG0CONFIGURATOR_invalid_configuration_perspective  if @p perspective is invalid
   <li>#CFG0CONFIGURATOR_option_family_not_found if any member of @p family_revisions is invalid
   </ul>
*/
extern int CFG0CONFIGURATOR_API CFG0_get_option_values(
    const tag_t perspective,                       /**< (I)  The perspective of a Configurator Context which holds configuration parameters such as Revision Rule, Rule Date etc. */
    const int n_family_revisions,                  /**< (I)  Number of input family revisions. */
    const tag_t * family_revisions,                /**< (I)  List of family revisions. */
    int * n_values,                                /**< (O)  Number of structures retrieved. */
    CFG0_option_family_values_t** values           /**< (OF) n_values Array of family revision and its value revisions  <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/**
   Retrieves allocation objects for given configurator perspective and specified objects such as Family, value tags.
   <br/>For example, a Family color is allocated to a product context Car.
   <br/>For the @p perspective with the product context and a revision rule, @p objects with Family color, the @p allocations will contain the configured allocation revision.
   <br/>Retrieves all allocation objects if @p objects is passed as empty.
   <br/>If no allocation revision is found for an object in @p objects , the object is not returned in @p allocations.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG0CONFIGURATOR_invalid_configuration_perspective  if @p perspective is invalid
   </ul>

   @note
   <br/>If @p objects contains an invalid object, no error is returned and the object is not returned in @p allocations.
*/
extern int CFG0CONFIGURATOR_API CFG0_get_allocation_objects(
    const tag_t perspective,                       /**< (I)  The perspective of a Configurator Context which holds configuration parameters such as Revision Rule, Rule Date etc. */
    const int n_objects,                           /**< (I)  Number of elements in @p objects. */
    const tag_t * objects,                         /**< (I)  n_objects List of object tags for which allocation objects are requested. */
    int * n_allocations,                           /**< (O)  Number of elements in @p allocations. */
    CFG0_allocation_t ** allocations               /**< (OF) n_allocations Array of allocation revision.<br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/** @} */

/**
    @name Constraint Solve Functions
    @{
*/

/**
   Analyzes an input configuration against configurator constraints. The configurator constraints are filtered based on input solve profile.
   Solve profile can be passed by two ways:
   <br/>1. Setting solve profile on @p perspective using #CFG0_set_configuration_information ITK.
   <br/>2. Setting argument @p solve_profile.
   <br/>If solve profile passed by both ways then solve profile from @p solve_profile will be consumed.The analysis is reported in @p satisfiable and @p complete.
   <br/>If the configuration is found #CFG_satisfiable, then a sample expression is returned in @p sample_configuration. The sample expression is an updated configuration
   with additional Feature selections which are contributed by constraints. The @p solve_profile also controls the constraints which can contribute to @p sample_configuration.
   <br/>If the configuration is found #CFG_unsatisfiable, then no sample expression is returned. However, the set of conflicting constraints which make the configuration
   #CFG_unsatisfiable are reported in @p conflicts.
   <br/>If the sample expression contains all required selections for a #CFG_satisfiable configuration, the @p complete is reported as true.
   <br/>If a configuration is #CFG_satisfiable but for the sample expression, @p complete is reported as false, then the missing required selections are reported in @p required_families.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG0CONFIGURATOR_invalid_configuration_perspective if @p perspective is invalid
   <li>#CFG_invalid_solve_profile if @p solve_profile is null or contains an invalid #CFG_severity_t.
   <li>#CFG_functionality_not_implemented if @p solve_profile specifies #CFG_constraint_filter_t or the min_report_severity and min_error_severity are not the same.
   <li>#CFG_invalid_expression if @p in_configuration is NULL or empty.
   </ul>

   @note
   <br/>For a given @p in_configuration and a set of configurator constraints, the @p sample_configuration is just one of the possible #CFG_satisfiable configurations.
*/
extern int CFG0CONFIGURATOR_API CFG0_analyze_configuration(
    const tag_t perspective,                                      /**< (I)  The perspective of a Configurator Context which holds configuration parameters such as Revision Rule, Rule Date etc. */
    const char * in_configuration,                                /**< (I)  The input variant configuration expression to be analyzed. */
    const CFG_solve_profile_t * solve_profile,                    /**< (I)  The #CFG_solve_profile_t to filter the configurator constraints. */
    CFG_satisfiability_t * satisfiable,                           /**< (O)  The result of analysis whether the @p in_configuration is satisfiable against the configurator constraints. */
    char ** sample_configuration,                                 /**< (OF) One of the (possibly many) configurations that satisfy the input criteria as well as all constraints. */
    int * n_sample_value_states,                                  /**< (O)  Number of elements in @p sample_value_states. */
    CFG0_sample_expr_value_info_t** sample_value_states,          /**< (OF) n_sample_value_states Array of sample configuration Feature states.<br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    int  *  n_conflicts,                                          /**< (O)  Number of elements in @p conflicts. */
    CFG0_conflict_info_t ** conflicts,                            /**< (OF) n_conflicts Array of conflicting constraints. Each conflict has a set of violated constraints.<br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    logical * complete,                                           /**< (O)  The result of analysis whether the @p sample_configuration is complete. */
    int * n_required_families,                                    /**< (O)  Number of elements in @p required_families. */
    tag_t ** required_families                                    /**< (OF) n_required_families Array of required families which have no selection in @p sample_configuration. */
    );

/**
   Sets the configuration information on a session configurable object. Configuration information is used for
   variant configuration which includes parameters such as Configurator Context, reporting severity,
   compute all violations and apply configurator constraints as defined in @ref CFG_CONFIGURATION_PROFILE.

   A session_configurable is an object which supports session configurable behavior. It is used for
   variant configuration e.g. a Variant Rule, a Configurator Perspective.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG0CONFIGURATOR_invalid_configuration_perspective if @p perspective is invalid.
   <li>#CFG0CONFIGURATOR_invalid_product_item_count if @p perspective has no or multiple product items associated with it.
   <li>#CFG0CONFIGURATOR_input_object_is_not_session_configurable if @p session_configurable does not support ConfigurationSession behavior.
   <li>#CFG0CONFIGURATOR_input_session_configurable_object_unavailable if @p session_configurable is NULLTAG.
   </ul>

   @note If @p solver_profile_info is provided then all unused profile entries must be initialized to NULL.
   <br/>
*/
extern int CFG0CONFIGURATOR_API CFG0_set_configuration_information(
    const tag_t perspective,                                       /**< (I) The perspective of a Configurator Context which holds configuration parameters such as Revision Rule, Rule Date etc. */
    const CFG0_conf_solver_profile_info_t *solver_profile_info,    /**< (I) Structure containing configuration information. If @p solver_profile_info is NULL, the preference @p TC_Default_Solve_Type and preference @p Cfg0DefaultValidationMode is used to initialized the solver profile.*/
    const tag_t session_configurable                               /**< (I) Session configurable object tag on which configuration information is to be set. */
    );

/**
   Gets the configuration information from session configurable objects. Configuration information is used for
   variant configuration which includes parameters such as Configurator Context, reporting severity,
   compute all violations and apply configurator constraints as defined in @ref CFG_CONFIGURATION_PROFILE.

   A session_configurable is an object which supports session configurable behavior. It is used for
   variant configuration e.g. a Variant Rule.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG0CONFIGURATOR_input_session_configurable_object_unavailable if any of the @p session_configurable_objs is a NULLTAG.
   <li>#CFG0CONFIGURATOR_input_object_is_not_session_configurable if any of the @p session_configurable_objs does not support ConfigurationSession behavior.
   </ul>
*/
extern int CFG0CONFIGURATOR_API CFG0_get_configuration_information(
    const int n_session_configurable_objects,               /**< (I) Number of session configurable objects in @p session_configurable_objs. */
    const tag_t *session_configurable_objs,                 /**< (I) n_session_configurable_ojects Array of session configurable object tags for which configuration information is needed. */
    tag_t **perspectives,                                   /**< (OF) n_session_configurable_ojects Array of the perspectives of a Configurator Contexts which hold configuration parameters such as Revision Rule, Rule Date etc. */
    CFG0_conf_solver_profile_info_t **solver_profile_infos  /**< (OF) n_session_configurable_ojects Array of structures containing configuration information.<br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
    );

/**
   Validates input configuration expressions against configurator constraints.
   <br/>The configurator constraints are filtered based on #CFG0_conf_solver_profile_info_t set on the @p perspective. The verdicts of validation are reported in @p verdicts.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG0CONFIGURATOR_invalid_configuration_perspective if @p perspective is invalid
   <li>#CFG0CONFIGURATOR_invalid_product_item_count if @p perspective contains multiple product items
   <li>#CFG_convert_expr_unknown_value if @p context_expression or any member of @p configurations is not a valid variant expression.
   </ul>

*/
extern int CFG0CONFIGURATOR_API CFG0_validate_configurations(
    const tag_t perspective,                                      /**< (I)  The perspective of a Configurator Context which holds configuration parameters such as Revision Rule, Rule Date, solve profile etc. */
    const char* context_expression,                               /**< (I)  The expression which acts as a constraint for validation. A NULL or empty expression is treated as a true expression. */
    const int n_configurations,                                   /**< (I)  Number of configurations in @p configurations. */
    const char ** configurations,                                 /**< (I)  n_configurations The variant configuration expressions to be validated. */
    CFG_satisfiability_t ** verdicts                              /**< (OF) n_configurations The results of validation whether the @p configurations are satisfiable against the configurator constraints and @p context_expression. */
    );

/**
Compares pairs of conditions and provides the verdict for each pair.
<br/>The diagram below shows the verdict resulting from a given left expression and different right expressions:

<pre>
left_condition:                |---------------|
right_condition 0:    |----|                                : CFG0_overlap_state_none
right_condition 1:        |------|                          : CFG0_overlap_state_intersect
right_condition 2:                    |----|                : CFG0_overlap_state_subset
right_condition 3:                       |-------|          : CFG0_overlap_state_intersect
right_condition 4: |-----------------------------|          : CFG0_overlap_state_superset
right_condition 5:             |---------------|            : CFG0_overlap_state_match
right_condition 6:            |--------------------|        : CFG0_overlap_state_superset
right_condition 7:        |--------------------|            : CFG0_overlap_state_superset
right_condition 8:             FALSE                        : CFG0_overlap_state_none
right_condition 9:             TRUE                         : CFG0_overlap_state_superset
</pre>

@returns
<ul>
<li>#ITK_ok on success.
<li>#CFG0CONFIGURATOR_invalid_configuration_perspective if @p perspective is null or not a perspective object.
<li>#CFG0CONFIGURATOR_invalid_product_item_count if @p perspective contains multiple product items.
<li>#CFG0CONFIGURATOR_invalid_condition_to_compare if @p condition is invalid is either null or empty.
</ul>
*/
extern CFG0CONFIGURATOR_API int CFG0_get_overlap_states(
    const tag_t perspective,                        /**< (I) The perspective of a configurator context which holds configuration parameters such as revision rule, rule date. It is used to convert the expression strings into boolean expressions. */
    const logical only_match,                       /**< (I) Indicates which overlap states are of interest. <br/>If set to @c true, the only retrieved states are #CFG0_overlap_state_match and #CFG0_overlap_state_none. */
    const int n_conditions,                         /**< (I) The number of elements in @p conditions. */
    const CFG0_condition_to_compare_t **conditions, /**< (I) n_conditions Array of conditions to compare. */
    CFG0_overlap_state_t** overlap_states           /**< (OF) The overlap statuses for each given pair of expressions. */
);

/**
Validates sets of configuration expressions against some configurator constraints.

@returns
<ul>
<li>#ITK_ok on success
<li>#CFG0CONFIGURATOR_invalid_configuration_perspective if @p perspective is null or not a perspective object.
<li>#CFG0CONFIGURATOR_invalid_product_item_count if @p perspective contains multiple product items.
<li>#CFG0CONFIGURATOR_invalid_configuration_set if any member of @p configurations is not a valid variant expression.
<li>#CFG_functionality_not_implemented if @p configurations is a configurable object.
<li>#CFG0CONFIGURATOR_unsupported_config_profile_info_provided if @p solver_profile_info structure contains incorrect information.
<li>#ITK_no_concurrent_module_license if no concurrent licenses are available.
</ul>
*/
extern int CFG0CONFIGURATOR_API CFG0_validate_configurations_set(
    const tag_t perspective,                                        /**< (I)  The perspective of a Configurator Context which holds configuration parameters such as Revision Rule, Rule Date, solve profile etc. */
    const CFG0_conf_solver_profile_info_t *solver_profile_info,     /**< (I)  Structure containing configuration information. <br/>If @p solver_profile_info is NULL, the preferences @c TC_Default_Solve_Type and @c Cfg0DefaultValidationMode are used to initialize the solver profile.*/
    const CFG0_configurable_expression_t * context_expression,      /**< (I)  The expression which acts as a constraint for validation. A NULL or empty expression is treated as a true expression. */
    const int n_configurations,                                     /**< (I)  Number of configurations. */
    const CFG0_configuration_set_t ** configurations,               /**< (I)  n_configurations The list of configurations to be validated. */
    CFG_satisfiability_t ** verdicts                                /**< (OF) n_configurations The validation results for each configuration, indicating whether they are satisfiable against the configurator constraints and @p context_expression. */
);

/**
Reports the conflicts between constraints for a given Variant Rule.
<br/>CFG0_report_constraint_conflicts.json defines the output JSON schema.
<br/>JSON schema is present in the kit.

@returns
<ul>
<li>#ITK_ok on success
<li>#CFG0CONFIGURATOR_invalid_configuration_perspective if @p variant_rule has no perspective object, or if no solve profile information is stored in @p variant_rule.
<li>#CFG0CONFIGURATOR_unsupported_config_profile_info_provided if @p v_rule contains incorrect config profile information.
<li>#ITK_parameter_invalid_value if @p revision_rule is not of type Revision Rule, or if @p variant_rule is not of type or sub-type of Variant Rule.
<li>#ITK_no_concurrent_module_license if no config_solve_level2 license not available.
</ul>
*/
extern int CFG0CONFIGURATOR_API CFG0_report_constraint_conflicts(
    tag_t revision_rule,                                     /**< (I) The Revision Rule to use for variability data filtering.
                                                                 <br/>This parameter is optional and can be #NULLTAG. In this case, the Revision Rule information will be extracted from @p variant_rule. */
    tag_t variant_rule,                                      /**< (I) Variant Rule to be validated. The solve profile information is extracted from this parameter. */
    int n_familes,                                           /**< (I) Number of families. */
    const tag_t* families,                                   /**< (I) n_families Families for which conflicts will be provided. */
    char** json_buffer                                       /**< (OF) The constraints conflicts in JSON format. */
);
/** @} */

/** @} */
#ifdef __cplusplus
}
#endif
#include <Cfg0configurator/libcfg0configurator_undef.h>
#endif
