/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa structure management services


*/

/** @if HISTORY_SECTION
   date         name                 description of change
03-Sep-2008  Stacey McIntire         Added new error for findHighestNumberInExpand service
$HISTORY$
==================================================================================================
@endif */

#ifndef SOASTRUCTUREMANAGEMENT_ERRORS_H
#define SOASTRUCTUREMANAGEMENT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOASTRUCTUREMANAGEMENT_ERRORS Errors for Structure Management SOA operations
    @ingroup SOASTRUCTUREMANAGEMENT
    @{
*/
/** The highest sequence number could not be found. */
#define SOASTRUCTUREMANAGEMENT_fail_find_high_seq_num                                     (EMH_SOASTRUCTUREMANAGEMENT_error_base + 0)

/** An empty input list was sent to compareNetEffectivity SOA operation. */
#define SOASTRUCTUREMANAGEMENT_invalid_lines                                              (EMH_SOASTRUCTUREMANAGEMENT_error_base + 1)

/** A null parent was sent to the add operation in the Structure SOA service. Please contact your system administrator. */
#define SOASTRUCTUREMANAGEMENT_null_parent_for_add                                        (EMH_SOASTRUCTUREMANAGEMENT_error_base + 2)

/** No object was found to add for the add operation in the Structure SOA service. Please make sure that one of the item, item revision, element or line is provided with a value. Also, please report this error to your system administrator. */
#define SOASTRUCTUREMANAGEMENT_no_object_to_add                                           (EMH_SOASTRUCTUREMANAGEMENT_error_base + 3)

/** An invalid input was provided for adding a substitute. Please correct and also report this error to your system administrator. */
#define SOASTRUCTUREMANAGEMENT_invalid_input_for_substitute                               (EMH_SOASTRUCTUREMANAGEMENT_error_base + 4)

/** No valid criterion is found for the given input scope. */
#define SOASTRUCTUREMANAGEMENT_valid_criteria_not_found                                   (EMH_SOASTRUCTUREMANAGEMENT_error_base + 5)
/** @} */

/** An error has occurred while retrieving the variant expression match information for the input BOM Line set "%1$". */
#define SOASTRUCTUREMANAGEMENT_fail_to_get_variant_expr_match_info                        (EMH_SOASTRUCTUREMANAGEMENT_error_base + 6)

/** A single Variant Rule cannot be applied if the window is in &quot;Overlay&quot; mode. Multiple Variant Rules are expected in this case. */
#define SOASTRUCTUREMANAGEMENT_fail_to_apply_input_svr                                    (EMH_SOASTRUCTUREMANAGEMENT_error_base + 7)

/** The &quot;Overlay&quot; mode requires at least two variant rules to be loaded. The specified Variant Rule cannot be removed, because that would leave only one loaded Variant Rule. */
#define SOASTRUCTUREMANAGEMENT_fail_to_remove_input_svr                                   (EMH_SOASTRUCTUREMANAGEMENT_error_base + 8)

/** An empty BOM Variant Rule has been received. Please provide a valid BOM Variant Rule. */
#define SOASTRUCTUREMANAGEMENT_invalid_variant_rule                                       (EMH_SOASTRUCTUREMANAGEMENT_error_base + 9)

/** An empty saved Variant Rule has been received. At least one valid saved Variant Rule is required for the action mode "%1$" with BOM Window configuration mode "%2$". */
#define SOASTRUCTUREMANAGEMENT_invalid_svr_list                                           (EMH_SOASTRUCTUREMANAGEMENT_error_base + 10)

/** The operation "%1$" is not implemented. Please report this error to your system administrator. */
#define SOASTRUCTUREMANAGEMENT_operation_not_implemented                                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 11)

/** The BOM Window object received is either null or invalid. Please provide a valid BOM Window object. */
#define SOASTRUCTUREMANAGEMENT_invalid_bom_window                                         (EMH_SOASTRUCTUREMANAGEMENT_error_base + 12)

/** The BOM Window configuration mode 2 (Overlay) does not support editing of BOM Variant Rule(s). Please change the BOM Window Variant configuration mode to 0 (single rule - single value) or 1 (single rule - multi value) to edit the BOM Variant Rule(s). */
#define SOASTRUCTUREMANAGEMENT_edit_var_rule_unsupported                                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 13)

/** The provided Variant Option value entry is either empty or does not exist. */
#define SOASTRUCTUREMANAGEMENT_invalid_option_value                                       (EMH_SOASTRUCTUREMANAGEMENT_error_base + 14)

/** An internal error has occurred in the "TcSoaStructureManagement" module. Please report this error to your system administrator. */
#define SOASTRUCTUREMANAGEMENT_internal_error                                             (EMH_SOASTRUCTUREMANAGEMENT_error_base + 15)

/** The starting line provided for partial expansion is either null or invalid. Please provide a valid line as the starting line for partial expansion. */
#define SOASTRUCTUREMANAGEMENT_invalid_starting_line                                      (EMH_SOASTRUCTUREMANAGEMENT_error_base + 16)

/** The line path identified by the client ID "%1$" could not be completely configured. The reason could be either that the path is invalid in the given context, or that it is configured out due to denied read access or configuration rules. */
#define SOASTRUCTUREMANAGEMENT_path_not_configured                                        (EMH_SOASTRUCTUREMANAGEMENT_error_base + 17)

/** The provided attribute name or value to resolve an occurrence chain is empty. */
#define SOASTRUCTUREMANAGEMENT_partial_expand_attrnames_attrvalues_empty                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 18)

/** Providing several attribute names to resolve an occurrence chain is not supported. */
#define SOASTRUCTUREMANAGEMENT_partial_expand_multiple_attrnames_unsupported              (EMH_SOASTRUCTUREMANAGEMENT_error_base + 19)

/** The "Run In Background" job could not be executed as scheduled. The problem could be with the Dispatcher infrastructure, or the "Asynchronous Service Translator" installation. Please contact your system administrator.*/
#define SOASTRUCTUREMANAGEMENT_async_not_working                                          (EMH_SOASTRUCTUREMANAGEMENT_error_base + 20)

/** The "Duplicate" operation has failed, because the selected BOM Line "%1$" is not associated with a valid Item Revision.*/
#define SOASTRUCTUREMANAGEMENT_duplicate_invalid_tag                                      (EMH_SOASTRUCTUREMANAGEMENT_error_base + 21)

/**
    The End item "%1$" for the Unit effectivity is invalid, because it must be a valid Item or Item Revision.
*/
#define SOASTRUCTUREMANAGEMENT_ic_invalid_unit_end_item                                   (EMH_SOASTRUCTUREMANAGEMENT_error_base + 22)

/**
     No incremental change contexts can be found based on the provided search criteria. Please check the condition:"%1$" &lt; incremental change context start Unit &lt;= "%2$", and incremental change context end Unit &gt;= "%2$".
*/
#define SOASTRUCTUREMANAGEMENT_no_icrevs_matching_criteria                                (EMH_SOASTRUCTUREMANAGEMENT_error_base + 23)

/**
    The following Unit Effectivities are invalid: %1$. The start Unit must be greater than or equal to 0, and must be less than the end Unit.
*/
#define SOASTRUCTUREMANAGEMENT_invalid_units_specified                                    (EMH_SOASTRUCTUREMANAGEMENT_error_base + 24)

/**
    The following Date Effectivities are invalid: %1$. The start date must be before the end date, and must not be null.
*/
#define SOASTRUCTUREMANAGEMENT_invalid_dates_specified                                    (EMH_SOASTRUCTUREMANAGEMENT_error_base + 25)

/**
    No incremental change contexts can be found based on the provided search criteria. Please check the condition:"%1$" &lt; incremental change context start Date &lt;= "%2$", and incremental change context end Date &gt;= "%2$".
*/
#define SOASTRUCTUREMANAGEMENT_no_icrevs_matching_criteria_date                           (EMH_SOASTRUCTUREMANAGEMENT_error_base + 26)

/** The provided BOM Lines are not from the same BOM Window.*/
#define SOASTRUCTUREMANAGEMENT_lines_are_from_different_window                            (EMH_SOASTRUCTUREMANAGEMENT_error_base + 27)

/** The provided BOM Line "%1$" is not in scope for "In Context" editing. */
#define SOASTRUCTUREMANAGEMENT_abs_occ_bomline_out_of_scope                               (EMH_SOASTRUCTUREMANAGEMENT_error_base + 28)

/** The provided BOM Line "%1$" is already defined by a higher level "In Context". */
#define SOASTRUCTUREMANAGEMENT_abs_occ_bomline_already_at_higher_level                    (EMH_SOASTRUCTUREMANAGEMENT_error_base + 29)

/** The "Replace" operation has completed with errors. */
#define SOASTRUCTUREMANAGEMENT_replace_failed                                             (EMH_SOASTRUCTUREMANAGEMENT_error_base + 30)

/** The post-processing cleanup activity has failed for the mass update, because the Change item "%1$" could not be cleaned up properly. Please check if the current user has access rights on the Markup object associated to this Change item.*/
#define SOASTRUCTUREMANAGEMENT_massupdate_cleanup_failed                                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 31)
/** Unable to create revision rule. */
#define SOASTRUCTUREMANAGEMENT_unable_create_rev_rule                                     (EMH_SOASTRUCTUREMANAGEMENT_error_base + 32)

/** Invalid input parameter: An Add/Remove or ChangeAttachment change must be accompanied by the attachment
 *  in the AffectedObject slot of the object map of the icChangesInfo member.
 */
#define SOASTRUCTUREMANAGEMENT_invalid_attachment_object                                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 33)

/** Invalid input parameter: In case of an Add/Remove or ChangeAttachment change, the object supplied in the
 * AffectedObject slot of the object map of the icChangesInfo member must be a Workspace Object.
 */
#define SOASTRUCTUREMANAGEMENT_invalid_attachment_object_not_a_wso                        (EMH_SOASTRUCTUREMANAGEMENT_error_base + 34)

/** Multiple inputs are not supported by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_multiple_input_not_supported                               (EMH_SOASTRUCTUREMANAGEMENT_error_base + 35)

/** Closure Rules are not supported by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_closure_rule_not_supported                                 (EMH_SOASTRUCTUREMANAGEMENT_error_base + 36)

/** Design Elements are not supported as selected objects by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_design_element_not_supported_as_selected_object            (EMH_SOASTRUCTUREMANAGEMENT_error_base + 37)

/** The Partition "%1$" is without any valid configuration context. It is, therefore, not supported by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_partition_without_configuration_context_not_supported      (EMH_SOASTRUCTUREMANAGEMENT_error_base + 38)

/** The parameter Mfg0connected_parts is not supported by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_parameter_mfg0connected_parts_is_not_supported             (EMH_SOASTRUCTUREMANAGEMENT_error_base + 39)

/** The parameter cpd_bom_effectivity is not supported by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_parameter_cpd_bom_effectivity_is_not_supported             (EMH_SOASTRUCTUREMANAGEMENT_error_base + 40)

/** Application Models are not supported as selected objects by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_application_model_not_supported_as_selected_object         (EMH_SOASTRUCTUREMANAGEMENT_error_base + 41)

/** Historical Partitions are not supported as selected objects by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_historical_partition_not_supported_as_selected_object      (EMH_SOASTRUCTUREMANAGEMENT_error_base + 42)

/** BOM Markups are not supported as selected objects by the 4GD to 4GD compare and accountability functionality.
 */
#define SOASTRUCTUREMANAGEMENT_bom_markup_not_supported                                   (EMH_SOASTRUCTUREMANAGEMENT_error_base + 43)

/** An Incremental Change context must be applied in order to propagate changes.
 */
#define SOASTRUCTUREMANAGEMENT_no_ic_for_propagation                                      (EMH_SOASTRUCTUREMANAGEMENT_error_base + 44)

/**The "findMatchingCandidates" operation requires at least one search candidate object and none were found.
 */
#define SOASTRUCTUREMANAGEMENT_no_search_candidates                                       (EMH_SOASTRUCTUREMANAGEMENT_error_base + 45)

/**The "findMatchingCandidates" operation requires at least one object to search for and none were found.
 */
#define SOASTRUCTUREMANAGEMENT_no_source_objects                                          (EMH_SOASTRUCTUREMANAGEMENT_error_base + 46)

/**The "findMatchingCandidates" operation has received an invalid property criterion (%1$) for the property "%2$".
 */
#define SOASTRUCTUREMANAGEMENT_invalid_property_criteria                                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 47)

/**The "findMatchingCandidates" operation has found that a property criterion element is missing. The required property criteria elements are the following: "Reason", "Property Name", "Property Operator", "Property Value" and "Property Type".
 */
#define SOASTRUCTUREMANAGEMENT_missing_property_criteria                                  (EMH_SOASTRUCTUREMANAGEMENT_error_base + 48)

/** The candidates cannot be aligned.
 */
#define SOASTRUCTUREMANAGEMENT_unable_to_align_candidates                                 (EMH_SOASTRUCTUREMANAGEMENT_error_base + 49)

  /** An error has occurred while retrieving unit net occurrence information for the line "%1$".
 */
 #define SOASTRUCTUREMANAGEMENT_unable_to_get_net_effectivity_info                        (EMH_SOASTRUCTUREMANAGEMENT_error_base + 50)

/** An internal error has occurred during the cutback occurrence effectivity operation. Please contact your system administrator for more information.
*/
#define SOASTRUCTUREMANAGEMENT_error_in_cutback_occurrence_effectivity_operation          (EMH_SOASTRUCTUREMANAGEMENT_error_base + 51)

/** An internal error has occurred accessing an Occurrence Effectivity Cutback for %1$. Please contact your system administrator for more information.
*/
#define SOASTRUCTUREMANAGEMENT_error_accessing_occurrence_effectivity_cutback             (EMH_SOASTRUCTUREMANAGEMENT_error_base + 52)

/** Invalid input received for creation of Occurrence Effectivity Cutback (%1$) for %2$.
*/
#define SOASTRUCTUREMANAGEMENT_invalid_input_for_cutback_occurrence_effectivity_operation (EMH_SOASTRUCTUREMANAGEMENT_error_base + 53)

/** An internal error has occurred during creation or modification of Occurrence Effectivity Cutback (%1$) for %2$. Please contact your system administrator for more information.
*/
#define SOASTRUCTUREMANAGEMENT_error_in_create_modify_occurrence_effectivity_operation    (EMH_SOASTRUCTUREMANAGEMENT_error_base + 54)

/** Only provide either BOM Variant Rules or Saved Variant Rules. */
#define SOASTRUCTUREMANAGEMENT_invalid_input                                              (EMH_SOASTRUCTUREMANAGEMENT_error_base + 55)

/** @} */
#endif
