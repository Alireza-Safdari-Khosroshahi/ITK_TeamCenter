/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

#ifndef PRG1PROGRAMPLANNINGAPP_ERRORS_H
#define PRG1PROGRAMPLANNINGAPP_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup PRG1PROGRAMPLANNINGAPP_ERRORS Program Planning Advanced Errors
    @ingroup PRG1PROGRAMPLANNINGAPP
    @{
*/

/** prg1programplanningapp module errors */
#define PRG1PROGRAMPLANNINGAPP_error_base                               EMH_PRG1PROGRAMPLANNINGAPP_error_base

/**    An internal error has occurred in the Program Planning Advanced module. Please report this error to your system administrator. */
#define PRG1PROGRAMPLANNINGAPP_internal_error                           ( PRG1PROGRAMPLANNINGAPP_error_base + 1 )

/**    The same Configurator Context must be associated to the Application Model and the Program Plan. */
#define PRG1PROGRAMPLANNINGAPP_invalid_configurator_context_error       ( PRG1PROGRAMPLANNINGAPP_error_base + 2 )

/**    The Configurator Context associated with this Plan does not have any Product Models defined. */
#define PRG1PROGRAMPLANNINGAPP_no_product_models                        ( PRG1PROGRAMPLANNINGAPP_error_base + 3 )

/**    The Plan Partition provided is invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_plan_partition                   ( PRG1PROGRAMPLANNINGAPP_error_base + 4 )

/**    The Plan object provided is invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_plan                             ( PRG1PROGRAMPLANNINGAPP_error_base + 5 )

/**    There are no Product Models associated with the current Plan object. */
#define PRG1PROGRAMPLANNINGAPP_no_models_for_this_plan                  ( PRG1PROGRAMPLANNINGAPP_error_base + 6 )

/**    The Configurator Context does not have any associated Application Model for Variability organization. */
#define PRG1PROGRAMPLANNINGAPP_no_appmodel_for_variability              ( PRG1PROGRAMPLANNINGAPP_error_base + 7 )

/**    The operation could not be performed, because no Configurator Context is associated with the selected Plan object. */
#define PRG1PROGRAMPLANNINGAPP_no_configurator_context                  ( PRG1PROGRAMPLANNINGAPP_error_base + 8 )

/**    The operation could not be performed, because selected Option Value is already associated with other Plan object. */
#define PRG1PROGRAMPLANNINGAPP_plan_code_unique_constraint_violation    ( PRG1PROGRAMPLANNINGAPP_error_base + 9 )

/**    The add operation could not be performed as one or more Product Models are already associated with Plan objects. */
#define PRG1PROGRAMPLANNINGAPP_product_model_add_failed                 ( PRG1PROGRAMPLANNINGAPP_error_base + 10 )

/**    The remove operation could not be performed as one or more Product Models are associated with Target objects. */
#define PRG1PROGRAMPLANNINGAPP_product_model_remove_failed              ( PRG1PROGRAMPLANNINGAPP_error_base + 11 )

/**    The available Product Models have already been consumed. */
#define PRG1PROGRAMPLANNINGAPP_no_more_product_models_available         ( PRG1PROGRAMPLANNINGAPP_error_base + 12 )

/**    The Plan "%1$" does not have any associated Plan option. */
#define PRG1PROGRAMPLANNINGAPP_missing_plan_option                      ( PRG1PROGRAMPLANNINGAPP_error_base + 13 )

/**    The Application Model provided is invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_appmodel                         ( PRG1PROGRAMPLANNINGAPP_error_base + 14 )

/**    The Variant Rule name provided is invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_rule_name                        ( PRG1PROGRAMPLANNINGAPP_error_base + 15 )

/**    The Option Values provided are invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_options                          ( PRG1PROGRAMPLANNINGAPP_error_base + 16 )

/**    The Configurator Context provided is invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_config_context                   ( PRG1PROGRAMPLANNINGAPP_error_base + 17 )

/**    The provided Target Element is invalid. */
#define PRG1PROGRAMPLANNINGAPP_invalid_target_element                   ( PRG1PROGRAMPLANNINGAPP_error_base + 18 )

/**    The "add" operation could not be performed, because one or more input Product Models are not associated with the parent Plan object. */
#define PRG1PROGRAMPLANNINGAPP_product_model_add_input_invalid          ( PRG1PROGRAMPLANNINGAPP_error_base + 19 )

/**    The "remove" operation could not be performed, because the input Product Model is associated with at least one Plan object in the hierarchy below the input Plan. */
#define PRG1PROGRAMPLANNINGAPP_product_model_used_in_plan_hierarchy     ( PRG1PROGRAMPLANNINGAPP_error_base + 20 )

/**    The parent Plan "%1$" does not contain any associated Product Models. */
#define PRG1PROGRAMPLANNINGAPP_no_product_models_on_parent_plan         ( PRG1PROGRAMPLANNINGAPP_error_base + 21 )

/**    The input Product Line or Product Models provided are empty. */
#define PRG1PROGRAMPLANNINGAPP_empty_product_line_or_product_models     ( PRG1PROGRAMPLANNINGAPP_error_base + 22 )

/**    No Product Models are associated with the Product Line "%1$". */
#define PRG1PROGRAMPLANNINGAPP_no_product_models_with_product_line      ( PRG1PROGRAMPLANNINGAPP_error_base + 23 )
/** @} */

#endif
