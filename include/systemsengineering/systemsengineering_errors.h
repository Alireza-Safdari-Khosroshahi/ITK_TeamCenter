/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2010.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SYSTEMSENGINEERING_ERRORS_H
#define SYSTEMSENGINEERING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SYSTEMSENGINEERING_ERRORS Errors
    @ingroup SYSTEMSENGINEERING
    @{
*/

#define SYSTEMSENGINEERING_error_base                           EMH_SYSTEMSENGINEERING_error_base

/**
    @name BUDGET_ERRORS_GROUP Budget related errors
    @{
*/

/**
    BudgetDefinition Name error messages
*/
#define SYSTEMSENGINEERING_budget_definition_name_exist         (SYSTEMSENGINEERING_error_base + 1)

/**
    EditBudget operation-context line error
*/
#define SYSTEMSENGINEERING_edit_budget_context_line             (SYSTEMSENGINEERING_error_base + 2)

/**
    EditBudget operation error
*/
#define SYSTEMSENGINEERING_edit_budget_error                    (SYSTEMSENGINEERING_error_base + 3)

/**
    This error implies an action cannot be performed as a stub is found
*/
#define SYSTEMSENGINEERING_stub_found                           (SYSTEMSENGINEERING_error_base + 4)

/** @} */

/**
    @name SYSTEM_ENGINEERING_ERRORS_GROUP System Engineering related errors
    @{
*/
/**
    The Top Line can not be deleted
*/
#define SYSTEMSENGINEERING_top_line                             (SYSTEMSENGINEERING_error_base + 51)

/**
   Multiple revisions found for the Function
*/
#define SYSTEMSENGINEERING_multiple_function_revisions          (SYSTEMSENGINEERING_error_base + 52)

/**
    The object is released
*/
#define SYSTEMSENGINEERING_object_is_released                   (SYSTEMSENGINEERING_error_base + 53)

/**
    The Function is referenced in other structure
*/
#define SYSTEMSENGINEERING_function_referenced                  (SYSTEMSENGINEERING_error_base + 54)

/**
    The element "%1$" of type "%2$" (%3$) has already been added to the interface specification "%4$".
*/
#define SYSTEMSENGINEERING_element_already_exists               (SYSTEMSENGINEERING_error_base + 55)

/** @} */

/**
    @name Interface Management errors (Interface Specification, Interface Element, Signal Elements, etc).
    @{
*/
/**
    The default value %1$ is not in the range of values defined for the property "%2$" (seg0DefaultValue) on "%3$".
*/
#define SYSTEMSENGINEERING_default_value_out_of_range           (SYSTEMSENGINEERING_error_base + 101)

/**
    The minimum value cannot be greater than the maximum value.
*/
#define SYSTEMSENGINEERING_min_value_greater_than_max           (SYSTEMSENGINEERING_error_base + 102)

/**
    The interaction can connect only one source and one target block.
*/
#define SYSTEMSENGINEERING_invalid_number_of_source_and_target_blocks           (SYSTEMSENGINEERING_error_base + 103)

/**
    The Direction of the Port %1$ was not changed because it is defined by the attached interface elements.
*/
#define SYSTEMSENGINEERING_failed_to_edit_port_direction        (SYSTEMSENGINEERING_error_base + 104)

/**
    The interface element "%1$" of type "%3$" with the subject "%2$" is already present on port "%4$" of "%5$".
*/
#define SYSTEMSENGINEERING_interface_element_already_exists      (SYSTEMSENGINEERING_error_base + 105)

/**
    The Exchange element subject "%1$" cannot be changed to "%2$", because an interface element with a same name, subject and type is already present on the selected port.
*/
#define SYSTEMSENGINEERING_subject_cannot_be_changed            (SYSTEMSENGINEERING_error_base + 106)

/** @} */

/** @} */

#endif
