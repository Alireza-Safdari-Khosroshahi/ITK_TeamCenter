/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa core services


*/

/** @if HISTORY_SECTION
====================================================================================================
17-Mar-2008  estifano                Add change management service specific error handling
$HISTORY$
==================================================================================================
@endif */

#ifndef SOACHANGEMGT_ERRORS_H
#define SOACHANGEMGT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOACORE_ERRORS TCWS Errors
    @ingroup SOACORE
    @{
*/

/** Type of change must be specified. */
#define SOACHANGEMGT_type_must_be_specified                                  (EMH_SOACHANGEMGT_error_base + 0)
#define SOACHANGEMGT_folder_name_must_be_specified                           (EMH_SOACHANGEMGT_error_base + 1)
#define SOACHANGEMGT_cannot_hide_system_level_folder                         (EMH_SOACHANGEMGT_error_base + 2)

/** The operation has failed, because no creatable "Change" types could be found. */
#define SOACHANGEMGT_failed_to_find_creatable_change_types                   (EMH_SOACHANGEMGT_error_base + 3)
/** The required endItem argument is missing. */
#define SOACHANGEMGT_end_item_must_be_specified                              (EMH_SOACHANGEMGT_error_base + 4)
/** Either one of date or unit effectivity must be specified. */
#define SOACHANGEMGT_either_date_or_unit_must_be_specified                   (EMH_SOACHANGEMGT_error_base + 5)
/** A valid release status is missing on the specified Change Notice Revision object. Only one of the values listed in the preference "MEMCN_release_statuses" must be used. */
#define SOACHANGEMGT_missing_status_on_change_object                         (EMH_SOACHANGEMGT_error_base + 6)
/** The Change Notice Revision "%2$" is currently not effective for the "%1$" status. */
#define SOACHANGEMGT_change_object_status_is_not_effective                   (EMH_SOACHANGEMGT_error_base + 7)
/** The solution folder for the Change Notice Revision "%1$" should be modifiable, but the system sees it as not modifiable. Please check the condition associated with business object constant "CmHasSolutionItemCreCondition" on the Change Notice Revision. */
#define SOACHANGEMGT_change_object_solution_folder_unmodifiable              (EMH_SOACHANGEMGT_error_base + 8)
/** The impacted folder for the Change Notice Revision "%1$" should be modifiable, but the system sees it as not modifiable. Please check the condition associated with business object constant "CmHasImpactedItemCreCondition" on the Change Notice Revision. */
#define SOACHANGEMGT_change_object_impacted_folder_unmodifiable              (EMH_SOACHANGEMGT_error_base + 9)
/** The Change Notice Revision "%2$" cannot be associated to the BOM Window, because the type "%1$" of the top line Item of the BOM Window does not appear in the preference "MEMCN_change_notice_mandatory_types". */
#define SOACHANGEMGT_cannot_associate_mcn_to_window                          (EMH_SOACHANGEMGT_error_base + 10)
/** The input does not contain a valid BOM Window object. */
#define SOACHANGEMGT_input_window_input                                      (EMH_SOACHANGEMGT_error_base + 11)
/** The Change Notice Revision has been associated with the BOM Window. However, the solution folder for the Change Notice Revision "%1$" should be modifiable, but the system cannot verify that completely because the condition parameters are not known. Please check the condition associated to the business object constant "CmHasSolutionItemCreCondition" on the Change Notice Revision, in case of errors while updating the solution folder. */
#define SOACHANGEMGT_change_object_solution_folder_maybe_unmodifiable        (EMH_SOACHANGEMGT_error_base + 12)
/** The Change Notice Revision has been associated with the BOM Window. However, the impacted folder for the Change Notice Revision "%1$" should be modifiable, but the system cannot verify that completely because the condition parameters are not known. Please check the condition associated to the business object constant "CmHasImpactedItemCreCondition" on the Change Notice Revision,  in case of errors while updating the impacted folder. */
#define SOACHANGEMGT_change_object_impacted_folder_maybe_unmodifiable        (EMH_SOACHANGEMGT_error_base + 13)
/** The current user does not have write access to change the Previous Effectivity property of the Change Notice Revision "%1$". */
#define SOACHANGEMGT_no_access_to_set_prev_eff                               (EMH_SOACHANGEMGT_error_base + 14)
/** No Change Notice Revision is set on the current BOM Window. */
#define SOACHANGEMGT_no_change_object_on_window                              (EMH_SOACHANGEMGT_error_base + 15)
/** The Manufacturing Change Notice feature is not enabled. Please check the value of the preference "MEMCN_management_enabled". */
#define SOACHANGEMGT_mcn_not_enabled                                         (EMH_SOACHANGEMGT_error_base + 16)
/** One or more of the selected revisions is already in another Change Notice Revision. */
#define SOACHANGEMGT_revision_in_another_mcn                                 (EMH_SOACHANGEMGT_error_base + 17)
/** The creation of a change lineage has failed because no Solution Item or Impacted item is provided. */
#define SOACHANGEMGT_solution_or_impacted_empty                              (EMH_SOACHANGEMGT_error_base + 18)
/** Not all Solution Items are attached to the same or ECN revision.*/
#define SOACHANGEMGT_solution_items_attached_to_multiple_ecns                (EMH_SOACHANGEMGT_error_base + 19)
/** Not all Impacted Items are attached to the same or ECN revision.*/
#define SOACHANGEMGT_impacted_items_attached_to_multiple_ecns                (EMH_SOACHANGEMGT_error_base + 20)
/** The operation can only be performed in the context of Change Notice Revision objects. */
#define SOACHANGEMGT_invalid_change_object                                   (EMH_SOACHANGEMGT_error_base + 21)
/** At least one of the input objects must have a Lineage group. */
#define SOACHANGEMGT_no_lineage_group                                        (EMH_SOACHANGEMGT_error_base + 22)
/** Each input object must be either a Solution Item or an Impacted Item of the context Change Notice Revision. */
#define SOACHANGEMGT_not_solution_or_impacted                                (EMH_SOACHANGEMGT_error_base + 23)
/** "%1$" Change Items cannot be derived for the following reason: */
#define  SOACHANGEMGT_cannot_derive_change_items                             (EMH_SOACHANGEMGT_error_base + 24)
/** @} */
#endif
