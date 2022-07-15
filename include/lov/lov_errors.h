/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef LOV_ERRORS_H
#define LOV_ERRORS_H

#include <common/emh_const.h>
#include <lov/liblov_exports.h>
/**
    @defgroup LOV_ERRORS Errors
    @ingroup LOV
    @{
*/

#define LOV_not_initialized          (EMH_LOV_error_base + 1)
#define LOV_no_load_class          (EMH_LOV_error_base + 2)
#define LOV_no_load_lov           (EMH_LOV_error_base + 3)
#define LOV_invalid_lov_name      (EMH_LOV_error_base + 4)
#define LOV_invalid_value_type      (EMH_LOV_error_base + 5)
#define LOV_invalid_usage          (EMH_LOV_error_base + 6)
#define LOV_inconsistent_value      (EMH_LOV_error_base + 7)
#define LOV_no_create           (EMH_LOV_error_base + 8)
#define LOV_no_create_enquiry      (EMH_LOV_error_base + 9)
#define LOV_already_attached      (EMH_LOV_error_base + 10)
#define LOV_attach_error          (EMH_LOV_error_base + 11)
#define LOV_detach_error          (EMH_LOV_error_base + 12)
#define LOV_invalid_type          (EMH_LOV_error_base + 13)
#define LOV_no_right_to_do          (EMH_LOV_error_base + 14)
#define LOV_invalid_argument      (EMH_LOV_error_base + 15)
#define LOV_having_multiple_lov      (EMH_LOV_error_base + 16)
#define LOV_not_registered_reference    (EMH_LOV_error_base + 17)
#define LOV_invalid_reference           (EMH_LOV_error_base + 18)
#define LOV_inconsistent_tag            (EMH_LOV_error_base + 19)
#define LOV_no_memory                   (EMH_LOV_error_base + 20)
#define LOV_cant_get_displayable_string (EMH_LOV_error_base + 21)
#define LOV_cant_get_length_of_values   (EMH_LOV_error_base + 22)
#define LOV_cant_get_values             (EMH_LOV_error_base + 23)
#define LOV_having_corrupted_data       (EMH_LOV_error_base + 24)
#define LOV_insert_msg_not_supported    (EMH_LOV_error_base + 25)
#define LOV_set_msg_not_supported       (EMH_LOV_error_base + 26)
#define LOV_inconsistent_filter_definition  (EMH_LOV_error_base + 27)
#define LOV_inconsistent_value_index        (EMH_LOV_error_base + 28)
#define LOV_operation_not_supported         (EMH_LOV_error_base + 29)
#define LOV_inconsistent_value_descs        (EMH_LOV_error_base + 30)
#define LOV_invalid_filter                  (EMH_LOV_error_base + 31)
#define LOV_circular_filter                 (EMH_LOV_error_base + 32)
#define LOV_invalid_search_value            (EMH_LOV_error_base + 33)
#define LOV_having_duplicate_values         (EMH_LOV_error_base + 34)
#define LOV_having_multiple_condition       (EMH_LOV_error_base + 35)

/**
    @name LOVDP related errors
    @{
*/

#define LOV_entry_referenced                (EMH_LOV_error_base + 36)
#define LOV_entry_not_found                 (EMH_LOV_error_base + 37)
#define LOV_is_referenced                   (EMH_LOV_error_base + 38)
#define LOV_having_multiple_entries         (EMH_LOV_error_base + 39)
#define LOV_need_master_display_to_set      (EMH_LOV_error_base + 40)
#define LOV_lovdp_not_found                 (EMH_LOV_error_base + 41)
#define LOV_incostistant_lovdps             (EMH_LOV_error_base + 42)
#define LOV_no_attachments                  (EMH_LOV_error_base + 43)
#define LOV_is_not_localized                (EMH_LOV_error_base + 44)
#define LOV_not_registed_for_lookup         (EMH_LOV_error_base + 45)
#define LOV_default_lov_not_found           (EMH_LOV_error_base + 46)
#define LOV_lovdp_attr_not_found            (EMH_LOV_error_base + 47)
/** @} */

/**
    @name LOV Value Description Localization related errors
    @{
*/
#define LOVValueDesc_display_value_for_non_existent_value  (EMH_LOV_error_base + 49)
/** @} */

/**
    @name Dynamic lov related errors
    @{
*/
/** The LOV value description "%1$" is not a string type property. */
#define LOV_invalid_value_description                  (EMH_LOV_error_base + 50)
/**The specified LOV sort order "%1$" is invalid. A valid sort order is either 1 (for ascending) or 2 (for descending). */
#define LOV_invalid_sort_order                         (EMH_LOV_error_base + 51)
/** The property "%1$" is not a valid sort property. The property must be one of the following: "%2$". */
#define LOV_invalid_sort_property_name                 (EMH_LOV_error_base + 52)
/** Select a value for the property "%1$". */
#define LOV_select_value_for_property                  (EMH_LOV_error_base + 53)
/** The value "%1$" is not a valid value for the property "%2$" of type "%3$". */
#define LOV_selected_value_not_valid                   (EMH_LOV_error_base + 55)
/** The value "%1$" is not in the range "%2$".*/
#define LOV_selected_value_not_valid_in_range          (EMH_LOV_error_base + 56)
/** The dynamic LOV "%1$" has an invalid configuration: the LOV value property "%2$" does not exist. Please contact your business modeler administrator about this issue. */
#define LOV_incorrect_lov_value_property               (EMH_LOV_error_base + 57)
/** Sorting is not supported for column quot;%1$quot;, because it represents an array property. */
#define LOV_prop_sorting_not_supported                 (EMH_LOV_error_base + 58)
/** No value is available for the LOV. Please enter a value.  */
#define LOV_values_not_available                       (EMH_LOV_error_base + 59)
/** No value is available for the LOV.  */
#define LOV_values_not_available_call_admin            (EMH_LOV_error_base + 60)
/** Valid values are of type "%1$" within a range of "%2$" to "%3$".  */
#define LOV_values_for_type_only_valid_in_range        (EMH_LOV_error_base + 61)
/** No LOV value matches the input text "%1$".  */
#define LOV_values_not_available_for_input             (EMH_LOV_error_base + 62)
/** This field is automatically populated when selecting a value for the "%1$" property.  */
#define LOV_value_auto_populated_for_property          (EMH_LOV_error_base + 63)
/** @} */

/**
    @name User Settings LOV related errors
    @{
*/
/** The query type "%1$" for the Dynamic LOV "%2$" is not supported. Please contact your system administrator.  */
#define LOV_query_type_not_supported                   (EMH_LOV_error_base + 64)
/** @} */

/**
    @name Object based Condition LOV related errors
    @{
*/
/** Teamcenter is unable to determine the List of Values (LOV) to use for the property "%1$", because all the conditions attached to this property evaluated to false. This indicates that appropriate values may not have been entered for the fields that this property is dependent upon, or that the system may not be configured correctly. Please contact your administrator to configure the system so that a list can be displayed.*/
#define LOV_cannot_find_show_no_value                  (EMH_LOV_error_base + 65)
/** Teamcenter is unable to determine a specific List of Values (LOV) for the property "%1$", because all conditions attached to this property evaluated to false. This indicates that appropriate values may not have been entered for the fields that this property is dependent upon, or that the system may not be configured correctly. To assist with the query, the system displays all values to choose from. Alternatively, enter appropriate values for other dependent properties in order to see a specific list. */
#define LOV_cannot_find_show_all_values                (EMH_LOV_error_base + 66)
/** @} */

/**
    @name LOV Value Localization related errors
    @{
*/
/** The value &quot;%1$&quot;, for which the value localization &quot;%2$&quot; is specified, does not exist in the LOV &quot;%3$&quot;. */
#define LOVVALUE_display_value_for_non_existent_value   (EMH_LOV_error_base + 67)
/** @} */

/**
    @name   Errors related to the dynamic LOV used on a Name Value Pair name
    @{
*/
/** The specified name "%1$" already exists. Duplicate Name-Value pairs are not allowed.  */
#define LOV_NV_same_name_already_exists                 (EMH_LOV_error_base + 68)
/** The specified name "%1$" cannot be used for the value type "%3$", because it already is used for the value type "%2$".  */
#define LOV_NV_name_exists_with_different_type          (EMH_LOV_error_base + 69)

/** The business object name and the owning object cannot be both null.*/
#define LOV_null_bo_owning_object                       (EMH_LOV_error_base + 70)
/** @} */

/** @} */

#include <lov/liblov_undef.h>
#endif
