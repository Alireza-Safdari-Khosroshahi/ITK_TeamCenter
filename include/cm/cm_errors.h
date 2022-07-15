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

    CM errors

*/

/*  */

#ifndef CM_ERRORS_H
#define CM_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/** Unknown error in CM module. */
#define CM_unknown                           (EMH_CHGMGT_error_base + 0)

/** Unable to generate a legal ID. */
#define CM_create_id_gen_failed              (EMH_CHGMGT_error_base + 1)

/** Unable to generate a legal Revision ID. */
#define CM_create_rev_id_gen_failed          (EMH_CHGMGT_error_base + 2)

/** Creation failed. */
#define CM_unable_to_create                  (EMH_CHGMGT_error_base + 3)

/** The type specified is invalid. */
#define CM_invalid_type                      (EMH_CHGMGT_error_base + 4)

/** The CM initialization failed. */
#define CM_initialization_failed             (EMH_CHGMGT_error_base + 6)

/** Duplicate revision or Change item already has revision. */
#define CM_duplicate_rev                     (EMH_CHGMGT_error_base + 7)

/** CM Object not modifiable. */
#define CM_object_not_modifiable             (EMH_CHGMGT_error_base + 8)

/** Unable to create a master form. */
#define CM_master_form_creation_failed       (EMH_CHGMGT_error_base + 9)

/** The specified change type is not found. */
#define CM_change_type_not_found             (EMH_CHGMGT_error_base + 10)

/** The Impacted item relation is not found. */
#define CM_impacted_item_reln_not_found      (EMH_CHGMGT_error_base + 11)

/** A duplicate item is pasted. */
#define CM_duplicate_item_pasted             (EMH_CHGMGT_error_base + 12)

/** The specified tag is invalid or null. */
#define CM_specified_tag_is_null             (EMH_CHGMGT_error_base + 13)

/** Unable to determine the relation name. */
#define CM_cannot_determine_relation_name    (EMH_CHGMGT_error_base + 14)

/** The query ID is not specified. */
#define CM_query_id_not_specified            (EMH_CHGMGT_error_base + 15)

/** The Change home folder is duplicated. */
#define CM_folder_already_exists             (EMH_CHGMGT_error_base + 16)

/** Non Change items cannot be pasted. */
#define CM_cannot_paste_non_ChangeItems      (EMH_CHGMGT_error_base + 17)

/** The Relation creation is not allowed. */
#define CM_relation_creation_not_allowed     (EMH_CHGMGT_error_base + 18)

/** The value for the preference CM_relation_creation_flag is invalid. */
#define CM_invalid_relation_preference_value            (EMH_CHGMGT_error_base + 19)

/** A specific revision must be selected. */
#define CM_must_select_specific_revision                (EMH_CHGMGT_error_base + 20)

/** Wrong closure status. */
#define CM_wrong_closure_status                         (EMH_CHGMGT_error_base + 21)

/** Wrong disposition status. */
#define CM_wrong_disposition_status                     (EMH_CHGMGT_error_base + 22)

/** The relation name to remove must be specified. */
#define CM_must_specify_relation_name_to_remove         (EMH_CHGMGT_error_base + 23)

/** The specified folder does not exist. */
#define CM_folder_dose_not_exist                        (EMH_CHGMGT_error_base + 24)

/** Unable to retrieve the specified Revision rule. */
#define CM_unable_to_get_revrule             (EMH_CHGMGT_error_base + 25)

/** Unable to retrieve the specified Change item. */
#define CM_unable_to_get_chng                (EMH_CHGMGT_error_base + 26)

/** Invalid Change item type specified in CM_note_types_to_track site preference. */
#define CM_pref_set_wrongly                  (EMH_CHGMGT_error_base + 27)

/** The Note type mentioned for Change item type in CM_note_types_to_track site preference is invalid. */
#define CM_invalid_notetype_in_pref          (EMH_CHGMGT_error_base + 28)

/** The relation specified is not found. */
#define CM_impacted_to_problem_relation_not_found (EMH_CHGMGT_error_base + 29)

/** Unable to retrieve the specified BOMSupersedure. */
#define CM_unable_to_get_supersedure         (EMH_CHGMGT_error_base + 30)

/** Unable to retrieve the Change item for the given BOMSupersedure. */
#define CM_unable_to_get_changeTag           (EMH_CHGMGT_error_base + 31)

/** Unable to retrieve the problem item revision. */
#define CM_unable_to_get_problem_bvr         (EMH_CHGMGT_error_base + 32)

/** Unable to retrieve pure adds and pure cancels for the bomline. */
#define CM_unable_to_get_pure_addscancels    (EMH_CHGMGT_error_base + 33)

/** The maximum number of Item revisions that can be selected when creating BOMSupersedure object is 2. */
#define CM_affected_item_mismatch            (EMH_CHGMGT_error_base + 34)

/** Invalid form property entered in site preference. */
#define CM_invalid_bomedit_form_prop         (EMH_CHGMGT_error_base + 35)

/** Unable to create a BOMSupersedure. */
#define CM_impacted_item_mismatch            (EMH_CHGMGT_error_base + 36)

/** The change home folder name cannot be blank. */
#define CM_must_specify_folder_name          (EMH_CHGMGT_error_base + 37)

/** A change home folder query name must be specified. */
#define CM_must_specify_query_name           (EMH_CHGMGT_error_base + 38)

/** The change home folder query criteria must match its value. */
#define CM_query_criteria_value_mismatch     (EMH_CHGMGT_error_base + 39)

/** The site level folder cannot be hidden during creation. */
#define CM_site_level_not_allowed            (EMH_CHGMGT_error_base + 40)

/** Only Schedule items can be pasted. */
#define CM_cannot_paste_non_ScheduleItems    (EMH_CHGMGT_error_base + 41)

/** No value is specified in CM_note_types_to_track site preference. */
#define CM_empty_value_for_notetype_in_pref  (EMH_CHGMGT_error_base + 42)

/** The specified condition is not satisfied. */
#define CM_cut_or_paste_not_allowed          (EMH_CHGMGT_error_base + 43)

/** The property "%1$" cannot be modified because the condition "Cm0isIncorporationStatusEditable" is not satisfied. Look at the expression of the condtiion defined in BMIDE to find the reason for the failure. */
#define CM_inc_status_not_modifiable         (EMH_CHGMGT_error_base + 44)

/** The corresponding Impacted Item of the Solution Item being incorporated cannot be found.
Either use the "Relate Solution To Impacted" functionality to specify the corresponding Impacted Item of the Solution Item being incorporated;
Or make sure that one, and only one, Impacted Item of the Change Notice Revision which authorized the Solution Item being incorporated, is a revision of the same Item of which the Solution Item being incorporated is a revision. */
#define CM_impacted_of_solution_not_found    (EMH_CHGMGT_error_base + 45)

/** "%2$" is already present in the chain "%3$" through the relation "%1$". */
#define CM_relation_already_exists           (EMH_CHGMGT_error_base + 46)

/**Objects cannot have relations on themselves.*/
#define CM_self_related                      (EMH_CHGMGT_error_base + 47)

/** "%1$" is not of type "Change Notice". */
#define CM_object_not_ecn_type               (EMH_CHGMGT_error_base + 48)

/** The creation of a Change Lineage has failed because either an invalid Item or no solution Item or an impacted item is provided. */
#define CM_solution_or_impacted_invalid              (EMH_CHGMGT_error_base + 49)

/** Not all solution Items are attached to the same Change Notice Revision.*/
#define CM_solution_items_attached_to_multiple_ecns  (EMH_CHGMGT_error_base + 50)

/** Not all impacted Items are attached to the same Change Notice Revision.*/
#define CM_impacted_items_attached_to_multiple_ecns  (EMH_CHGMGT_error_base + 51)

/** Some impacted Items do not contain any attached Change Notice Revision.*/
#define CM_no_ecn_for_impacted_items                 (EMH_CHGMGT_error_base + 52)

/** Some solution Items do not contain any attached Change Notice Revision.*/
#define CM_no_ecn_for_solution_items                 (EMH_CHGMGT_error_base + 53)

/** Multiple Change Notices are related to the same POM Space, which is not supported. */
#define CM_multiple_ecn_for_pom_space                (EMH_CHGMGT_error_base + 54)

/** @deprecated #CM_multiple_ecn_for_change_space deprecated in Teamcenter 11.2.3. Use #CM_multiple_ecn_for_pom_space instead */
#define CM_multiple_ecn_for_change_space             (EMH_CHGMGT_error_base + 54)
TC_DEPRECATED_PREPROCESSOR( "11.2.3", CM_multiple_ecn_for_change_space, "CM_multiple_ecn_for_pom_space" )

/** The following preceding Change objects are not released: %1$. */
#define CM_validate_change_notice_dependency (EMH_CHGMGT_error_base + 55)

/** "%1$" is concurrent but is not a target of the same workflow. */
#define CM_concurrent_not_in_target          (EMH_CHGMGT_error_base + 56)

/** The object "%1$" cannot be released because its predecessor object "%2$" is not released. */
#define CM_predecessor_not_released          (EMH_CHGMGT_error_base + 57)

/** The current release status of the target object "%1$" is "%2$". The current workflow defines the status to apply as "%3$", but a workflow that applies one of the following statuses is required: %4$. */
#define CM_no_entry_in_progression_path      (EMH_CHGMGT_error_base + 58)

/** The current release status of the target object "%1$" is "%2$". To proceed in this workflow, the status of the target object must be one of the following: %3$. */
#define CM_no_entry_for_current_status       (EMH_CHGMGT_error_base + 59)

/** The operation can only be performed in the context of Change Notice Revision objects. */
#define CM_invalid_change_object             (EMH_CHGMGT_error_base + 61)

/** At least one of the input objects must have a Lineage group. */
#define CM_no_lineage_group                  (EMH_CHGMGT_error_base + 62)

/** Each input object must be either a Solution Item or an Impacted Item of the context Change Notice Revision. */
#define CM_not_solution_or_impacted          (EMH_CHGMGT_error_base + 63)

/** "%1$" is already present in the chain "%2$" through a concurrent dependency. */
#define CM_concurrent_relation_already_exists         (EMH_CHGMGT_error_base + 64)

/** "%1$" is already present in the chain "%2$" through a successor dependency. */
#define CM_successor_relation_already_exists          (EMH_CHGMGT_error_base + 65)

/** "%1$" is already present in the chain "%2$" through a predecessor dependency.*/
#define CM_predecessor_relation_already_exists        (EMH_CHGMGT_error_base + 66)

/** "%1$" could not be promoted due to the following reason: %2$. */
#define CM_promote_to_public_error                    (EMH_CHGMGT_error_base + 67)

/** The intent value "%1$" is invalid because the preference "CM_single_intent_per_changenotice_enabled" has specified that Change Notices can only be configured by a single intent. */
#define CM_invalid_intent_error                       (EMH_CHGMGT_error_base + 68)

/** "%1$" cannot be a solution for "%2$" because it is created in-context of another change "%3$". */
#define CM_solution_item_inconsistent_space           (EMH_CHGMGT_error_base + 69)

/** Preferences for CM-baseline-solution-item-revisions-on-change-notice handler are disabled. Enable the preferences "%1$" and "%2$" and try again. */
#define CM_baseline_solution_item_preferences_not_set (EMH_CHGMGT_error_base + 70)

/** The following arguments to the Workflow handler "%2$" are missing or invalid: %1$. */
#define CM_derive_workflow                            (EMH_CHGMGT_error_base + 71)

/** The selected Change Items for derive cannot be retrieved. */
#define  CM_cannot_retrieve_change_items_for_derive         (EMH_CHGMGT_error_base + 72)

/** The relation can not be established because the object is already in some other active change. */
#define  CM_cannot_establish_relation_already_in_change         (EMH_CHGMGT_error_base + 73)
#endif
