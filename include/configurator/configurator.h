/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/*  */

/**
    @file

    This file contains the constants and data structures for working with Configurator.
    The Configurator module deals with variant data such as option families, values and constraints.
*/

#ifndef TEAMCENTER_CONFIGURATOR_H
#define TEAMCENTER_CONFIGURATOR_H

#include <constraintsolver/constraintsolver.h>

#include <configurator/libconfigurator_exports.h>

/**
    @defgroup CFG Configurator
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
    Holds parameters to filter the constraints which take part in evaluation of a configuration.
*/
typedef struct
{
    int n_intents;              /**< Number of elements in intents. */
    const char ** intents;      /**< Constraint filter based on their intent types such as Marketing, Sales etc. Refer the property cfg0Intents on type Cfg0AbsConfiguratorWSO. */
    int n_object_types;         /**< Number of elements in object_types. */
    const char ** object_types; /**< Constraint filter based on their object type such as Cfg0AbsValidationRule. <br/>The wild cards are not supported.
                                If an inheritable type such as Cfg0AbsConstraintRule is specified, then all the subtypes of Cfg0AbsConstraintRule are processed. */
} CFG_constraint_filter_t;

/**
    Holds a profile which configures the evaluation of a configuration against configurator constraints.
    <br/>For example, user wants to evaluate a configuration against all constraints in the system. He wants the constraints with intent as Sales
    and type Cfg0AbsDefaultRule or Cfg0AbsIncludeRule to update the configuration. He does no want constraints with intent as Technical and type as Cfg0AbsValidationRule
    to update the configuration. If a constraint with a severity #CFG_severity_default_selected or lower conflicts with the configuration, he wants the constraint to be
    ignored in the evaluation. If the configuration conflicts with a set of constraints, then, he wish to see only those constraints with severity as #CFG_severity_error_level or above.
    <br/>The solve profile for such a requirement will look like:
    @code
    char  *active_intents[] = { "Sales" };
    char  *active_object_types[] = { "Cfg0AbsDefaultRule", "Cfg0AbsIncludeRule" };
    CFG_constraint_filter_t active_constraint_filter;
    active_constraint_filter.n_CFG_intents = 1;
    active_constraint_filter.CFG_intents = active_intents;
    active_constraint_filter.n_CFG_object_types = 2;
    active_constraint_filter.CFG_object_types = active_object_types;

    char *passive_intents[] = { "Technical" };
    char *passive_object_types[] = { "Cfg0AbsValidationRule" };
    CFG_constraint_filter_t passive_constraint_filter;
    passive_constraint_filter.n_CFG_intents = 1;
    passive_constraint_filter.CFG_intents = passive_intents;
    passive_constraint_filter.n_CFG_object_types = 1;
    passive_constraint_filter.CFG_object_types = passive_object_types;

    CFG_solve_profile_t solve_profile;
    solve_profile.min_report_severity = CFG_severity_error_level;
    solve_profile.min_error_severity = CFG_severity_information_level;
    solve_profile.active_constraint_filter = &active_constraint_filter;
    solve_profile.passive_constraint_filter = &passive_constraint_filter;
    @endcode
*/
typedef struct
{
    CFG_severity_t min_report_severity;                         /**< Minimum #CFG_severity_t to be reported back. */
    CFG_severity_t min_error_severity;                          /**< Minimum #CFG_severity_t to be evaluated for validation failures. */
    const CFG_constraint_filter_t* active_constraint_filter;    /**< Evaluate constraints to modify the configuration. */
    const CFG_constraint_filter_t* passive_constraint_filter;   /**< Evaluate constraints but do not modify the configuration. */
} CFG_solve_profile_t;

/**
    Holds the satisfiability state of a configuration against the constraints evaluated.
*/
typedef enum CFG_satisfiability
{
    CFG_satisfiable = 0,        /**< The configuration is satisfiable against the constraints evaluated. */
    CFG_unsatisfiable = 1,      /**< The configuration is not satisfiable against the constraints evaluated. */
    CFG_undetermined = 2        /**< The satisfiability of the configuration could not be determined. */
} CFG_satisfiability_t;

#ifdef __cplusplus
}
#endif

/** @} */

#include <configurator/libconfigurator_undef.h>
#endif
