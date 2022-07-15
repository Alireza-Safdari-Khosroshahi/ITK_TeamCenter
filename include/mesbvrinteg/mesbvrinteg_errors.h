/*===============================================================================
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the error codes for the MESBVRINTEG module
*/

/*  */

#ifndef MESBVRINTEG_ERRORS_H
#define MESBVRINTEG_ERRORS_H

#include <common/emh_const.h>
#include <mesbvrinteg/libmesbvrinteg_exports.h>

/**
    @defgroup MESBVRINTEG_ERRORS MESBVRINTEG Errors
    @ingroup MESINTEG
    @{
*/

/** An internal error has occurred. Please contact your system administrator. */
#define MESBVRINTEG_internal_error                                                  (EMH_MESBVRINTEG_error_base + 1)
/** The target object is not of type Process nor Operation.*/
#define MESBVRINTEG_incorrect_selection_type                                        (EMH_MESBVRINTEG_error_base + 10)
/** An error has occurred while validating the selected data "%1$". */
#define MESBVRINTEG_exception_validating_data                                       (EMH_MESBVRINTEG_error_base + 11)
/** The release status of the object "%1$" is not part of the configured release statuses. */
#define MESBVRINTEG_no_release_status                                               (EMH_MESBVRINTEG_error_base + 12)
/** The release status flag "%1$" cannot be found. Please contact your system administrator. */
#define MESBVRINTEG_missing_release_flag                                            (EMH_MESBVRINTEG_error_base + 13)
/** The object type "%1$" cannot be found. Please contact your system administrator. */
#define MESBVRINTEG_incorrect_object_type                                           (EMH_MESBVRINTEG_error_base + 14)
/** The preference "%1$" is not in the specified format. */
#define MESBVRINTEG_incorrect_preference_specification                              (EMH_MESBVRINTEG_error_base + 15)
/** No Work Area is assigned for the object "%1$". Please assign a Work Area to the object. */
#define MESBVRINTEG_no_work_area_assigned                                           (EMH_MESBVRINTEG_error_base + 16)
/** The structure of the object "%1$" is incorrect: it contains multi-level of processes. */
#define MESBVRINTEG_hierarchy_error_more_than_two_levels                            (EMH_MESBVRINTEG_error_base + 17)
/** The structure of the object "%1$" is incorrect: it must contain at least one child Compound Operation or Operation child. */
#define MESBVRINTEG_hierarchy_error_no_comp_op_nor_op_children                      (EMH_MESBVRINTEG_error_base + 18)
/** The structure of the object "%1$" is incorrect: it contains a mix of processes, compound operations and operations. */
#define MESBVRINTEG_hierarchy_error_mixed_comp_op_and_op                            (EMH_MESBVRINTEG_error_base + 19)
/** A full export must be run before releasing an update. Perform a full export on the selected Execution Plan. */
#define MESBVRINTEG_full_export_creation_error                                      (EMH_MESBVRINTEG_error_base + 20)
/** The object class "%1$" cannot be found. Please contact your system administrator. */
#define MESBVRINTEG_workarea_preference_type_invalid                                (EMH_MESBVRINTEG_error_base + 21)
/** The object class "%1$" is neither of type Process, nor Compound Operation, nor Operation, nor Step nor derived from any of these. Please contact your system administrator. */
#define MESBVRINTEG_workarea_preference_type_invalid_not_derived_from_proc_or_op    (EMH_MESBVRINTEG_error_base + 22)
/** Only a single Bill Of Processes (BOP) Window can be configured in the structure. Please remove any additional BOP Window from the execution Plan.*/
#define MESBVRINTEG_single_bop_window_validation_failed                             (EMH_MESBVRINTEG_error_base + 23)
/** The EPM Task Template "%1$" does not exist. */
#define MESBVRINTEG_epmtask_template_absent                                         (EMH_MESBVRINTEG_error_base + 24)
/** More than one flow alternative path exist for the object "%1$". Please make sure there are no alternative flow paths for the object. */
#define MESBVRINTEG_flow_Alternative_paths                                          (EMH_MESBVRINTEG_error_base + 25)
/** The structure of the object "%1$" is incorrect: the root object of a Process Structure must not be of type Compound Operation, nor Operation, nor any of their derived types. */
#define MESBVRINTEG_hierarchy_invalid_root_object                                   (EMH_MESBVRINTEG_error_base + 26)
/** The dispatcher wait time limit, as specified in the preference "%1$", has been reached. Please check that the dispatcher services are running, and check the log file in the dispatcher staging directory for the request ID %2$ for more details. */
#define MESBVRINTEG_defined_time_limit_reached_for_dispatcher                       (EMH_MESBVRINTEG_error_base + 27)
/** The dispatcher request "generatemeswirepfiles" could not be created. Please refer to the Teamcenter server log file for details. */
#define MESBVRINTEG_Failed_to_create_dispatcher_request                             (EMH_MESBVRINTEG_error_base + 28)
/** The translation has failed for the request ID %1$. Please refer to the Teamcenter server log file for details. */
#define MESBVRINTEG_translation_failed                                              (EMH_MESBVRINTEG_error_base + 29)
/** The dispatcher is not installed. No MHT files will be generated for this request. Please contact your system administrator to intall and configure the "generatemeswirep" translator. */
#define MESBVRINTEG_dispatcher_not_installed                                        (EMH_MESBVRINTEG_error_base + 30)
/** The structure of the object "%1$" is incorrect: Compound Operations may only have Steps as children. */
#define MESBVRINTEG_hierarchy_invalid_comp_op                                       (EMH_MESBVRINTEG_error_base + 31)
/** The Work Area object "%1$" name is invalid. Work Area names must not include any whitespaces. */
#define MESBVRINTEG_work_area_name_invalid                                          (EMH_MESBVRINTEG_error_base + 32)
/** No full flow path was detected for the object "%1$". Please make sure there are no alternative flow paths for the object. */
#define MESBVRINTEG_flow_no_full_path                                               (EMH_MESBVRINTEG_error_base + 33)
/** The Application Object was absent from the previous Execution Plan, so the delta export cannot be executed. Please perform a full export on the selected Execution Plan again. */
#define MESBVRINTEG_ai_absent_in_execution_plan                                     (EMH_MESBVRINTEG_error_base + 34)
/** No Visualization Structure Context is attached to the previous Request Object. */
#define MESBVRINTEG_vsc_not_attached                                                (EMH_MESBVRINTEG_error_base + 35)
/** No release candidate can be found in the structure. */
#define MESBVRINTEG_no_release_candidate_present                                    (EMH_MESBVRINTEG_error_base + 36)
/** The Workflow Template is invalid. Please provide a valid Workflow template. */
#define MESBVRINTEG_invalid_workflow_template                                       (EMH_MESBVRINTEG_error_base + 37)
/** The root of the Bill Of Processes (BOP) Window must always be a Process. */
#define MESBVRINTEG_root_process_validation_failed                                  (EMH_MESBVRINTEG_error_base + 38)
/** Remove any additional Work Area from "%1$" because only one Work Area can be attached to an object. */
#define MESBVRINTEG_single_workarea_attached_validation_failed                      (EMH_MESBVRINTEG_error_base + 39)
/** The object "%1$" has multiple effectivities. Only one effectivity is expected. */
#define MESBVRINTEG_multiple_effectivity                                            (EMH_MESBVRINTEG_error_base + 40)
/** The provided release status "%1$" cannot be applied to the object "%2$", because it already has the "%3$" status. */
#define MESBVRINTEG_invalid_release_status                                          (EMH_MESBVRINTEG_error_base + 41)
/** An execution plan must contain a process structure in order to be released to the Manufacturing Execution System (MES) application. */
#define MESBVRINTEG_execution_plan_missing_process_structure                        (EMH_MESBVRINTEG_error_base + 42)
/** The release status "%2$" of the Change object "%1$" is not part of the Manufacturing Execution System (MES) release statuses. */
#define MESBVRINTEG_mcn_release_status_incorrect                                    (EMH_MESBVRINTEG_error_base + 43)
/** No configured release status is attached to the Change Object "%1$". */
#define MESBVRINTEG_mcn_no_release_status                                           (EMH_MESBVRINTEG_error_base + 44)
/** No effectivity is attached to the Change Object "%1$". */
#define MESBVRINTEG_mcn_no_effectivity                                              (EMH_MESBVRINTEG_error_base + 45)
/** The effectivity of the Change Object "%1$" differs from that of the referenced Plant Bill Of Processes (BOP) Window. */
#define MESBVRINTEG_mcn_effectivity_differ_from_window                              (EMH_MESBVRINTEG_error_base + 46)
/** The Item Revision "%2$" attached to the Change Object "%1$" is not configured in the referenced Plant Bill Of Process (BOP) structure. Please attach the appropriate Item Revision to the Change Object. */
#define MESBVRINTEG_mcn_attached_input_line_not_configured                          (EMH_MESBVRINTEG_error_base + 47)
/** No input line is attached to the Change Object "%1$". */
#define MESBVRINTEG_mcn_input_lines_absent                                          (EMH_MESBVRINTEG_error_base + 48)
/** Multiple release statuses are attached to the Change Object "%1$". Change Objects should have only one configured release status. */
#define MESBVRINTEG_mcn_multiple_release_status                                     (EMH_MESBVRINTEG_error_base + 49)
/** No value is provided for the Previous Effectivity property of the Change Object "%1$". */
#define MESBVRINTEG_mcn_previous_effectivity_absent                                 (EMH_MESBVRINTEG_error_base + 50)
/** The Change Object "%1$" is currently not effective for the "%2$" status. */
#define MESBVRINTEG_mcn_release_status_not_effectivity                              (EMH_MESBVRINTEG_error_base + 51)
/** The previous effectivity of the Change Object "%1$" does not match the one of the impacted item "%2$". */
#define MESBVRINTEG_mcn_previous_effectivity_not_matching                           (EMH_MESBVRINTEG_error_base + 52)
/** The release status of the Item "%2$" does not match the release status of the Change Object "%1$".*/
#define MESBVRINTEG_mcn_mismatch_release_status                                     (EMH_MESBVRINTEG_error_base + 53)
/** The standard text bulk update operation cannot continue, because of an invalid Change Notice revision with Item ID "%1$".*/
#define STX_bulk_update_invalid_item_id                                             (EMH_MESBVRINTEG_error_base + 54)
/** The standard text bulk update operation cannot continue, because of an invalid Revision Rule named "%1$".*/
#define STX_bulk_update_invalid_rev_rule_name                                       (EMH_MESBVRINTEG_error_base + 55)
/** The standard text bulk update operation cannot continue, because it is unable to create file "%1$".*/
#define STX_bulk_update_cannot_create_logfile                                       (EMH_MESBVRINTEG_error_base + 56)
/** The standard text bulk update operation cannot continue, because Microsoft Word is required yet not installed.*/
#define STX_bulk_update_cannot_find_word_installed                                  (EMH_MESBVRINTEG_error_base + 57)
/** The standard text bulk update encounted a problem. Please refer to the log dataset attached to the reference folder of the Change Notice for additional information*/
#define STX_bulk_update_problem_refer_log_dataset                                   (EMH_MESBVRINTEG_error_base + 58)
/** The standard text bulk update operation cannot continue, because the standard text Revision Rule does not configure a revision found in the Change Notice revision. Please refer to the log dataset attached to the reference folder of the change notice revision for additional information. */
#define STX_bulk_update_no_configured_revision                                      (EMH_MESBVRINTEG_error_base + 59)
/** The validation of the Process Structure has failed, because the property "Sign-off Required" is not set to "true" for the object "%1$".*/
#define MESBVRINTEG_signoff_signature_required                                      (EMH_MESBVRINTEG_error_base + 60)
/** The validation of the Work Area assigned to "%1$" has failed. Please associate the Manufacturing Execution System (MES) resource location to the Work Area.*/
#define MESBVRINTEG_workarea_resource_required                                      (EMH_MESBVRINTEG_error_base + 61)
/** The specified structure context type "%1$" is invalid.*/
#define MESBVRINTEG_invalid_structure_context_type                                  (EMH_MESBVRINTEG_error_base + 62)
/** The specified Collaboration Context object "%1$" is invalid because it must be of type "%2$".*/
#define MESBVRINTEG_invalid_execution_plan_type                                     (EMH_MESBVRINTEG_error_base + 63)
/** The execution plan "%1$" is not configured as work order.*/
#define MESBVRINTEG_no_work_order_configuration                                     (EMH_MESBVRINTEG_error_base + 64)
/** Find word order status operation has failed.*/
#define MESBVRINTEG_find_work_order_status_failed                                   (EMH_MESBVRINTEG_error_base + 65)
/** @} */
#include <mesbvrinteg/libmesbvrinteg_undef.h>
#endif

