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

    Product Configurator related definitions that are related to constraint solving.
*/

#ifndef TEAMCENTER_CONSTRAINTSOLVER_H
#define TEAMCENTER_CONSTRAINTSOLVER_H

#include <constraintsolver/libconstraintsolver_exports.h>

/**
    @defgroup CSLV Constraint Solver

    Product Configurator related definitions that are related to constraint solving.
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
    Holds severity definitions of a configurator constraint.

    <br/>The severities follow an order of precedence based on their integer value.
    For example, the severity #CFG_severity_init_empty has lower precedence than #CFG_severity_error_level.

    <br/>A future release may insert severity level. It is therefore recommended to store severity levels by name,
    and translate severity level names to CFG_severity_t at runtime before passing a CFG_severity_t to an API.
    This way your code will pick up the current value assignment that is used in the current Teamcenter release.
    The relative ordering between severity level names will not change across Teamcenter releases.
    Use #CSLV_get_severity_level and #CSLV_get_severity_name to convert to and from CFG_severity_t.
*/
typedef enum CFG_severity
{
    CFG_severity_init_empty = -8,        /**< A constraint has initialized a family with the empty value. */
    CFG_severity_default_selected = -4,  /**< A constraint has assigned a default value. */
    CFG_severity_package_default = -2,   /**< A constraint has assigned a default value. */
    CFG_severity_unknown = 0,            /**< An administrator authored constraint with unknown severity has assigned a value. */
    CFG_severity_information_level = 1,  /**< A constraint with INFORMATION severity has assigned a value. */
    CFG_severity_warning_level = 2,      /**< A constraint with WARNING severity has assigned a value. */
    CFG_severity_error_level = 4,        /**< A constraint with ERROR severity has assigned a value. */
    CFG_severity_input_selected = 8      /**< The value was specified in the input. */
} CFG_severity_t;

/**

    @}
*/

/**
   Converts the names of severity levels to CFG_severity_t (an opaque enum data type).
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CFG_configurator_specific_error if @p name is invalid
   </ul>
*/
extern int CONSTRAINTSOLVER_API CSLV_get_severity_level(
    const char * name,      /**< (I) The names of severity levels. e.g. CFG_CONFIGURATOR_user_severity.*/
    CFG_severity_t * level  /**< (O) The severity level corresponding to the severity name. */
   );

/**
   Converts a CFG_severity_t token (an opaque enum data type) to the name of severity levels.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CSLV_invalid_severity_token if @p level is invalid
   </ul>
*/
extern int CONSTRAINTSOLVER_API CSLV_get_severity_name(
    CFG_severity_t level, /**< (I) A severity token */
    const char ** name    /**< (O) The names of severity levels. e.g. CFG_CONFIGURATOR_user_severity.*/
   );

/**

    @}
*/

#ifdef __cplusplus
}
#endif

#include <constraintsolver/libconstraintsolver_undef.h>
#endif /* TEAMCENTER_CONSTRAINTSOLVER_H */
