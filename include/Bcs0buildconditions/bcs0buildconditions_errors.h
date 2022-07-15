/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the error codes of Bcs0buildconditions

*/

#ifndef BCS0BUILDCONDITIONS_ERRORS_H
#define BCS0BUILDCONDITIONS_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup BCS0BUILDCONDITIONS_ERRORS Build Conditions errors
    @ingroup BCS0BUILDCONDITIONS
    @{
*/

/** Base module errors */
#define BCS0BUILDCONDITIONS_ERROR_BASE     EMH_BCS0BUILDCONDITIONS_error_base

/**
 * The operation "%1$" has failed, because an invalid Configuration Perspective was passed.
 */
#define BCS0BUILDCONDITIONS_invalid_configuration_perspective                              ( BCS0BUILDCONDITIONS_ERROR_BASE + 1 )

/**
 * An invalid Revision Rule was found in the context "%1$".
 */
#define BCS0BUILDCONDITIONS_invalid_content_revision_rule                                   ( BCS0BUILDCONDITIONS_ERROR_BASE + 2 )

/**
 * An invalid container was found in the context "%1$".
 */
#define BCS0BUILDCONDITIONS_invalid_container                                               ( BCS0BUILDCONDITIONS_ERROR_BASE + 3 )

/**
 * An invalid variant criterion was found in the context "%1$".
 */
#define BCS0BUILDCONDITIONS_invalid_content_variant_criteria                                ( BCS0BUILDCONDITIONS_ERROR_BASE + 4 )

/**
* An internal error has occurred in the module Build Conditions (Bcs0buildconditions). Please report this error to your system administrator.
*/
#define BCS0BUILDCONDITIONS_internal_error                                                  ( BCS0BUILDCONDITIONS_ERROR_BASE + 5 )

/**
* The page size value cannot be negative.
*/
#define BCS0BUILDCONDITIONS_negative_page_size                                              ( BCS0BUILDCONDITIONS_ERROR_BASE + 6 )

/**
* The input perspective contains an invalid configurator context.
*/
#define BCS0BUILDCONDITIONS_invalid_context_set_on_perspective                              ( BCS0BUILDCONDITIONS_ERROR_BASE + 7 )

/**
* The input list of build conditions to skip contains an invalid formula "%1$".
*/
#define BCS0BUILDCONDITIONS_invalid_build_conditions_to_skip                                ( BCS0BUILDCONDITIONS_ERROR_BASE + 8 )

/**
* The input list of contents to skip contains an invalid tag.
*/
#define BCS0BUILDCONDITIONS_invalid_contents_to_skip                                        ( BCS0BUILDCONDITIONS_ERROR_BASE + 9 )

/**
* The input content "%1$" of type "%2$" is not a variant configurable object.
*/
#define BCS0BUILDCONDITIONS_input_content_is_not_variant_configurable                       ( BCS0BUILDCONDITIONS_ERROR_BASE + 10 )

/**
* The operation "%1$" has failed, because no input expression is passed.
*/
#define BCS0BUILDCONDITIONS_invalid_input_expressions_size                                  ( BCS0BUILDCONDITIONS_ERROR_BASE + 11 )

/**
* The operation "%1$" has failed, because an invalid input expression is passed.
*/
#define BCS0BUILDCONDITIONS_invalid_input_expression                                        ( BCS0BUILDCONDITIONS_ERROR_BASE + 12 )

/**
* The input content "%1$" of type "%2$" is not an effectivity configurable object.
*/
#define BCS0BUILDCONDITIONS_input_content_is_not_effectivity_configurable                   ( BCS0BUILDCONDITIONS_ERROR_BASE + 13 )

/**
* A negative or zero value for the number of content types is not allowed.
*/
#define BCS0BUILDCONDITIONS_invalid_number_of_content_types                                 ( BCS0BUILDCONDITIONS_ERROR_BASE + 14 )

/**
* An operation "%1$" is not overriden on object "%2$" of type "%3$".
*/
#define BCS0BUILDCONDITIONS_unable_to_construct_search_recipe_object                        ( BCS0BUILDCONDITIONS_ERROR_BASE + 15 )

/** @} */
#endif
