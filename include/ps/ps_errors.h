/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2020.
   Siemens Digital Industries Software.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Error code definitions for the Product Structure (PS) module.

*/

/*  */

#ifndef PS_ERRORS_H
#define PS_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup PS_ERRORS Errors
    @ingroup PS
    @{
*/

#define PS_error_base                      EMH_PS_error_base

#define PS_internal_error                 (PS_error_base +  1)
#define PS_insufficient_privilege         (PS_error_base +  2)
#define PS_invalid_occurrence             (PS_error_base +  3)
#define PS_not_found                      (PS_error_base +  4)
#define PS_invalid_view_type              (PS_error_base +  5)
#define PS_invalid_bom_view               (PS_error_base +  6)
#define PS_invalid_bvr                    (PS_error_base +  7)
#define PS_cyclic_structure               (PS_error_base +  8)
#define PS_invalid_value                  (PS_error_base +  9)
#define PS_no_transform                   (PS_error_base + 10)
#define PS_invalid_item                   (PS_error_base + 12)
#define PS_invalid_item_rev               (PS_error_base + 13)
#define PS_invalid_class                  (PS_error_base + 14)
#define PS_invalid_ref_class              (PS_error_base + 15)
#define PS_duplicate                      (PS_error_base + 16)
#define PS_invalid_attribute              (PS_error_base + 17)
#define PS_invalid_child_item             (PS_error_base + 18)
#define PS_invalid_note_type              (PS_error_base + 19)
#define PS_no_note_of_this_type           (PS_error_base + 20)
#define PS_cant_modify_bvr                (PS_error_base + 21)
#define PS_bvr_is_precise                 (PS_error_base + 22)
#define PS_no_seq_no                      (PS_error_base + 23)
#define PS_bvr_in_use                     (PS_error_base + 24)
#define PS_invalid_occurrence_flag        (PS_error_base + 25)
#define PS_no_note_types                  (PS_error_base + 26)
#define PS_unmodifiable_item              (PS_error_base + 27)
#define PS_unmodifiable_item_rev          (PS_error_base + 28)
#define PS_duplicate_substitute           (PS_error_base + 29)
#define PS_no_such_substitute             (PS_error_base + 30)
#define PS_cant_delete_preferred          (PS_error_base + 31)
#define PS_shared_bvr                     (PS_error_base + 32)
#define PS_no_default_view_type           (PS_error_base + 33)
#define PS_multiple_view_ambiguity        (PS_error_base + 34)
#define PS_duplicate_bom_view             (PS_error_base + 35)
#define PS_duplicate_bvr                  (PS_error_base + 36)
#define PS_cant_unattach_bvr              (PS_error_base + 37)
#define PS_no_bvr_of_view_type            (PS_error_base + 38)
#define PS_note_string_too_long           (PS_error_base + 39)
#define PS_bvr_needs_refresh              (PS_error_base + 40)
#define PS_note_invalid_default_value     (PS_error_base + 41)
#define PS_has_old_transform_only         (PS_error_base + 42)
#define PS_could_not_convert_transform    (PS_error_base + 43)
#define PS_no_legacy_transform_factor     (PS_error_base + 44)
#define PS_not_a_plmxml_transform         (PS_error_base + 45)
#define PS_already_plmxml_transform       (PS_error_base + 46)
#define PS_two_transforms                 (PS_error_base + 47)
#define PS_allow_plmxml_pref_invalid      (PS_error_base + 48)
#define PS_transform_format_pref_invalid  (PS_error_base + 49)
#define PS_transform_units_pref_invalid   (PS_error_base + 50)
#define PS_invalid_occ_type               (PS_error_base + 51)
#define PS_cyclic_pred_structure          (PS_error_base + 52)
#define PS_pred_rel_exists                (PS_error_base + 53)
#define PS_self_predecessor               (PS_error_base + 54)
#define PS_could_not_get_units_from_form  (PS_error_base + 55)
#define PS_no_ug_master_for_item_rev      (PS_error_base + 56)
#define PS_no_form_attached_to_ug_part    (PS_error_base + 57)
#define PS_cant_cut_occurrence            (PS_error_base + 58)
#define PS_client_data_defn_in_use        (PS_error_base + 59)
#define PS_no_occurrence_name             (PS_error_base + 60)
#define PS_cannot_add_bv_to_linked_vi     (PS_error_base + 61)
#define PS_cannot_change_view_in_vi       (PS_error_base + 62)
#define PS_cannot_change_vi_sos           (PS_error_base + 63)
#define PS_cannot_add_to_vi_structure     (PS_error_base + 64)
#define PS_cannot_remove_in_vi_structure  (PS_error_base + 65)
#define PS_modvar_ref_prevents_rename     (PS_error_base + 66)

/** The operation has failed, because the Option &quot;%1$&quot; is referenced by the following objects: &quot;%2$&quot;. */
#define PS_option_is_referenced           (PS_error_base + 67)

#define PS_invalid_apn_tag                (PS_error_base + 68)
#define PS_invalid_absocc_id              (PS_error_base + 69)
#define PS_invalid_attr_tag               (PS_error_base + 70)
#define PS_invalid_attachment_tag         (PS_error_base + 71)
#define PS_invalid_absocc_grm_anchor      (PS_error_base + 72)
#define PS_no_valid_types                 (PS_error_base + 73)
#define PS_referenced_by_ic               (PS_error_base + 74)
#define PS_no_such_substitute_context     (PS_error_base + 75)
#define PS_duplicate_substitute_context   (PS_error_base + 76)
#define PS_cannot_delete_vi_sos           (PS_error_base + 77)
#define PS_inconsistent_occ_effs          (PS_error_base + 78)
#define PS_occ_eff_upgrade_failed         (PS_error_base + 79)
#define PS_occ_eff_refd_by_non_occ        (PS_error_base + 80)
#define PS_occ_eff_refd_by_modified_occ   (PS_error_base + 81)
#define PS_invalid_opt_item               (PS_error_base + 82)
#define PS_duplicate_optional_item        (PS_error_base + 83)
#define PS_no_optional_item               (PS_error_base + 84)
#define PS_no_qual_bvr_access             (PS_error_base + 85)
#define PS_affo_not_absoccdata            (PS_error_base + 86)
#define PS_duplicate_arrangement_name     (PS_error_base + 87)
#define PS_invalid_arrangement_tag        (PS_error_base + 88)
#define PS_arrangement_import_xml_error   (PS_error_base + 89)
#define PS_arrangement_export_xml_error   (PS_error_base + 90)
/* <Syed> PS_apn_referenced_by_a_replica denotes If an APN references a STUB  */
#define PS_occ_references_replica_object  (PS_error_base + 91)
#define PS_reln_has_ices_cannot_delete    (PS_error_base + 92)
#define PS_var_exp_remotely_owned         (PS_error_base + 93)
#define PS_can_not_perform_export         (PS_error_base + 94)
#define PS_cannot_share_absocc            (PS_error_base + 95)
#define PS_invalid_seq_no                 (PS_error_base + 96)
#define PS_serious_error                  (PS_error_base + 97)
#define PS_unable_to_export               (PS_error_base + 98)

/**
    @defgroup ROLLUP_ERRORS BOM Rollup Errors
    @ingroup PS_ERRORS
    @{
*/
#define PS_rollup_input_prop_len_error    (PS_error_base + 99)
#define PS_rollup_output_prop_len_error   (PS_error_base + 100)
#define PS_rollup_assert_prop_len_error   (PS_error_base + 101)
#define PS_rollup_invalid_template_error  (PS_error_base + 102)
#define PS_rollup_name_prop_len_error     (PS_error_base + 103)
#define PS_rollup_desc_prop_len_error     (PS_error_base + 104)
#define PS_rollup_delim_prop_len_error    (PS_error_base + 105)
#define PS_rollup_context_prop_len_error  (PS_error_base + 106)
#define PS_rollup_scope_prop_len_error    (PS_error_base + 107)
#define PS_rollup_template_exists_error   (PS_error_base + 108)
#define PS_rollup_temp_dir_error          (PS_error_base + 109)
#define PS_invalid_uid_value              (PS_error_base + 110)
/** @} */

/**
    @defgroup PL_ERRORS Publish Action/Link Errors
    @ingroup PS_ERRORS
    @{
*/
#define PS_publishlink_invalid_source                   (PS_error_base + 111)
#define PS_publishlink_invalid_target                   (PS_error_base + 112)
#define PS_publishlink_invalid_type                     (PS_error_base + 113)
#define PS_publishlink_target_already_has_source        (PS_error_base + 114)
#define PS_publishlink_invalid_target_to_remove         (PS_error_base + 115)
#define PS_publishlink_invalid_target_multiple_sources  (PS_error_base + 116)
#define PS_publishlink_multiple_links                   (PS_error_base + 117)
#define PS_publishlink_data_flag                        (PS_error_base + 118)
#define PS_publishlink_not_exist_for_source             (PS_error_base + 119)
#define PS_publishlink_not_exist_for_target             (PS_error_base + 120)
#define PS_publish_no_data_found                        (PS_error_base + 121)
#define PS_publishlink_can_not_create_publishlink_on_replica_object    (PS_error_base + 122)
#define PS_publishlink_invalid_source_type                 (PS_error_base + 123)
#define PS_publishlink_invalid_target_type                 (PS_error_base + 124)
#define PS_empty_usage_addr                (PS_error_base + 125)
#define PS_empty_pos_des                   (PS_error_base + 126)
#define PS_publishlink_mismatch_source_target_logical_identity   (PS_error_base + 127)
#define PS_publishlink_all_target_logical_identity_not_same   (PS_error_base + 128)
#define PS_publishlink_target_needs_design_required       (PS_error_base + 129)
#define PS_publishlink_source_already_has_plink           (PS_error_base + 130)
#define PS_publishlink_cannot_delete                      (PS_error_base + 131)
#define PS_arrangement_find_used_anchor_error             (PS_error_base + 132)
#define PS_invalid_existing_thread                        (PS_error_base + 133)

/** The BOM View Revision &quot;%1$&quot; cannot be exported without its BOM View. Either the BOM View does not exist or it has no &quot;EXPORT&quot; privilege. */
#define PS_export_no_bv_in_bvr                            (PS_error_base + 134)

#define PS_transfer_no_bv_in_bvr                          (PS_error_base + 135)

/** @} */

/**
    @defgroup BB_ERRORS Bounding Box Errors
    @ingroup PS_ERRORS
    @{
*/
#define PS_invalid_dataset                                (PS_error_base + 136)

#define PS_invalid_Qualifier_tag                          (PS_error_base + 137)

#define PS_drawingType_component_error                    (PS_error_base + 139)
#define PS_topline_cannot_be_source                       (PS_error_base + 140)
#define PS_topline_cannot_be_target                       (PS_error_base + 141)
/** @} */

/**
    @defgroup CVR_ERRORS Condition Validation Result Errors
    @ingroup PS_ERRORS
    @{
*/
#define PS_condvalresult_cannot_delete                   (PS_error_base + 142)

#define PS_invalid_substitute                            (PS_error_base + 143)
#define PS_cant_overwrite_existing_value                 (PS_error_base + 144)
#define PS_cant_edit_existing_value                      (PS_error_base + 145)

#define PS_option_referenced              (PS_error_base + 146)
#define PS_cant_delete_option_value       (PS_error_base + 147)

#define PS_retrieve_plmxml_tag_error      (PS_error_base + 148)

/** @} */

/** No revision for validation based on the preference "PS_Default_Rev_For_Occ_Cond_Validation" can be found.  */
#define PS_no_revision_for_validation     (PS_error_base + 149)
/** The child object has failed the validation of a certain condition */
#define PS_occurrence_validation_error    (PS_error_base + 150)
/** The type of the child object is invalid for the type of the parent based on occurrence condition. */
#define PS_occurrence_invalid_type        (PS_error_base + 151)

/**
    @defgroup MU_ERRORS Mass Update Errors
    @ingroup PS_ERRORS
    @{
*/

/** ChangeItemRevision is null. Please supply a valid ChangeItemRevision. */
#define PS_massupdate_no_changeitem                         (PS_error_base + 152)

/** Update is not modifiable or not active, meaning the mass update operation has already been performed.
    Please supply a different ChangeItemRevision with a modifiable, active update. */
#define PS_massupdate_already_done                          (PS_error_base + 153)

/** ChangeItemRevision is not modifiable. Please supply a modifiable ChangeItemRevision. */
#define PS_massupdate_changeitem_not_modifiable             (PS_error_base + 154)

/** Parent Item of the target ItemRevision is not selectable because it is not modifiable. */
#define PS_massupdate_parent_not_modifiable                 (PS_error_base + 155)

/** Parent ItemRevision of the target ItemRevision is not selectable because it is not modifiable. */
#define PS_massupdate_parent_rev_not_modifiable             (PS_error_base + 156)

/** Parent ItemRevision of the target ItemRevision is not selectable because it is referenced by another active ChangeItem. */
#define PS_massupdate_parent_in_another_active_changeitem   (PS_error_base + 157)

/** ChangeItemRevision has no updates. Please supply a ChangeItemRevision that has an update. */
#define PS_massupdate_no_markups                            (PS_error_base + 158)

/** ChangeItemRevision has multiple updates. Please supply a ChangeItemRevision that has a single update. */
#define PS_massupdate_multiple_markups                      (PS_error_base + 159)

/** Target ItemRevision is not valid. Please supply a valid target ItemRevision. */
#define PS_massupdate_invalid_target                        (PS_error_base + 160)

/** New ItemRevision is null and required, or not valid. Please supply a valid new ItemRevision. */
#define PS_massupdate_invalid_newpart                       (PS_error_base + 161)

/** Impacted (parent of the target) ItemRevision is null or not valid. Please supply a valid impacted ItemRevision. */
#define PS_massupdate_invalid_impacted                      (PS_error_base + 162)

/** ChangeItemRevision is null and required, or not valid. Please supply a valid ChangeItemRevision. */
#define PS_massupdate_invalid_changeitem                    (PS_error_base + 163)

/** Update is null and required, or not valid. Please supply a valid update. */
#define PS_massupdate_invalid_markup_change                 (PS_error_base + 164)

/** Mass Update operation is not valid. Please supply a valid Mass Update operation. */
#define PS_massupdate_invalid_operation_type                (PS_error_base + 165)

/** New ItemRevision is the same as the target ItemRevision or the impacted (parent of the target) ItemRevision.
    Please supply another new ItemRevision. */
#define PS_massupdate_newpart_conflict                      (PS_error_base + 166)

/** Update for this Mass Update operation already exists. */
#define PS_massupdate_markup_change_already_exists          (PS_error_base + 167)

/** There is already an operation type assigned to the selected target/impacted parent ItemRevision pair.
    Select a different target and impacted parent ItemRevision pair,
    or delete the existing pair and add a new operation with the same target and impacted parent ItemRevision pair. */
#define PS_massupdate_markup_change_add_conflict            (PS_error_base + 168)

/** Update does not belong to this ChangeItemRevision. Please supply a different update and/or ChangeItemRevision. */
#define PS_massupdate_markup_change_not_member              (PS_error_base + 169)

/** Parent ItemRevision is not selectable because it is not valid for the specified operation. */
#define PS_massupdate_parent_rev_invalid_for_operation      (PS_error_base + 170)

/** Solution ItemRevision found in Change Item Revision Solution Psuedo Folder is not modifiable. */
#define PS_massupdate_latest_parent_rev_not_updateable      (PS_error_base + 171)

/** ChangeItemRevision is not the right type. */
#define PS_massupdate_changeitem_wrong_type                 (PS_error_base + 172)

/** More than one Mass Update dataset report is attached to the ChangeItemRevision. */
#define PS_massupdate_multiple_dataset_reports              (PS_error_base + 173)

/** More than one report is attached to the Mass Update dataset. */
#define PS_massupdate_multiple_dataset_report_refs          (PS_error_base + 174)

/** Unable to add problem part revision to the Problem Items Psuedo Folder on the Change Item Revision.
    Please check condition engine rules are correct for access rights. */
#define PS_massupdate_changeitem_problem_folder_failure     (PS_error_base + 175)

/** Unable to add impacted part revision to the Impacted Items Psuedo Folder on the Change Item Revision.
    Please check condition engine rules are correct for access rights. */
#define PS_massupdate_changeitem_impacted_folder_failure    (PS_error_base + 176)

/** Unable to add solution part revision to the Solution Items Psuedo Folder on the Change Item Revision.
    Please check condition engine rules are correct for access rights. */
#define PS_massupdate_changeitem_solution_folder_failure    (PS_error_base + 177)

/** Update was successful but failed to add solution part revision to the Solution Items Pseudo Folder on the Change Item Revision.
    Please check condition engine rules are correct for access rights. */
#define PS_massupdate_changeitem_updated_sol_folder_failure (PS_error_base + 178)

/**
* The option name cannot be modified because the parent Item is multi-sited.
*/
#define PS_option_item_multisited                           (PS_error_base + 179)

/** The parent Item of the target Item Revision is not selectable because it is a Variant Item. */
#define PS_massupdate_parent_is_variant_item                (PS_error_base + 180)

/** The parent Item of the target Item Revision is not selectable because it has a Variant Item. */
#define PS_massupdate_parent_has_variant_item               (PS_error_base + 181)

/** The parent Item Revision of the target Item Revision is not selectable because its BOM View Revision is checked-out. */
#define PS_massupdate_parent_bvr_checked_out                (PS_error_base + 182)

/** Saving of "StoredOptionSet" objects has been disabled through the preference "DisableSaveSos".
    Please contact your system administrator for more information. */
#define PS_sos_save_disabled                                (PS_error_base + 183)

/** The option &quot;%1$&quot; cannot be renamed to &quot;%2$&quot;, because an option with same name already exists on the Item &quot;%3$&quot;. */
#define PS_option_name_already_used                         (PS_error_base + 184)

/**
    @}
*/

/**
    @ingroup ROLLUP_ERRORS
    @{
*/
/** BOM Rollup failed to retrieve the quantity for BOMLine &quot;%1$&quot;. */
#define PS_rollup_quantity_error                           (PS_error_base + 185)
/** The quantity of BOMLine &quot;%1$&quot; is &quot;As Required&quot;, which is zero for the purpose of BOM Rollup calculations. */
#define PS_rollup_quantity_asrequired                      (PS_error_base + 186)
/** @} */

/** The provided impacted object list cannot be NULL or empty. Please provide an impacted object list with one or more elements. */
#define PS_massupdate_invalid_impacted_object_list         (PS_error_base + 187)

/** The impacted object "%1$" is active in another change object (%2$). */
#define PS_massupdate_impacted_object_active_in_another_changeitem    (PS_error_base + 188)

/** The number of attempts to generate a unique persistent ID for the variant expression "%$1" has exceeded the maximum of %2$. Please contact your system administrator. */
#define PS_unique_persistentid_error       (PS_error_base + 189)

/** %1$ */
#define PS_duplicate_error                 (PS_error_base + 190)

/** The update of the impacted object was successful, but it has failed to add the solution object "%1$" to the Solution Items Pseudo-Folder on the Change Item Revision.
    Please check the Change Item Revision specific condition engine rules for access rights. */
#define PS_massupdate_changeitem_sol_folder_failure         (PS_error_base + 191)

/** The update of the impacted object was successful, but it has failed to add the solution object "%1$" to the Solution Items Folder available in the user's Newstuff folder.
    Please check if the current user has access rights to the Solution Items Folder. */
#define PS_massupdate_sol_folder_failure                    (PS_error_base + 192)

/** The impacted object could not be added to the Impacted Items Pseudo-Folder on the Change Item Revision.
    Please check the Change Item Revision specific condition engine rules for access rights. */
#define PS_massupdate_changeitem_imp_folder_failure         (PS_error_base + 193)

/** The impacted object could not be added to the Impacted Items Folder available in the user's Newstuff folder.
    Please check if the current user has access rights to the Impacted Items Folder. */
#define PS_massupdate_imp_folder_failure                    (PS_error_base + 194)

/** No Variant Expression exists for the following persistent IDs: %1$. */
#define PS_invalid_persistentid_error                       (PS_error_base + 195)

/** No modular variant condition can be created, because the line "%1$" already contains a product configurator-authored variant condition. */
#define PS_cannot_create_modular_variant_condition          (PS_error_base + 196)

/** A problem has been detected with the Appearance Path Node (APN) information of the loaded structure. Please ask your system adiministrator to run the utility "apn_medic" in order to identify and repair inconsistencies in the APN structure. */
#define PS_apn_structure_corruption                         (PS_error_base + 197)

/** The following problem has been detected during Variant upgrade: %1$. */
#define PS_variant_migrate_error                            (PS_error_base + 198)

/** An invalid tag was detected for a replacing or replaced cutback occurrence. Please contact your system administrator for more information. */
#define PS_invalid_cutback_occurrence                       (PS_error_base + 199)

/** No occurrence was found to be replaced. You must specify an occurrence to be replaced for the cutback action. */
#define PS_no_impacted_occurrence_for_cutback               (PS_error_base + 200)

/** No replacing occurrence was found. You must specify an occurrence to be the replacing occurrence for the cutback action. */
#define PS_no_solution_occurrence_for_cutback               (PS_error_base + 201)

/** A cutback replacing occurrence cannot also be specified as a replaced occurrence within an active cutback. */
#define PS_same_occ_replacing_and_replaced_in_cutback       (PS_error_base + 202)

/** A replaced occurrence does not have an existing occurrence effectivity defined. Only use occurrences with existing occurrence effectivity defined for cutback replacement. */
#define PS_no_occ_eff_on_replaced_occ                       (PS_error_base + 203)

/** The name field is empty. A name is required for cutback creation. */
#define PS_no_name_found_for_cutback                        (PS_error_base + 204)

/** The effectivity field is empty. An effectivity is required for cutback creation. */
#define PS_no_effectivity_found_for_cutback                 (PS_error_base + 205)

/** The XML file generated by the "variant_data_analysis" utility cannot be migrated because it contains complex data condition (refer to the "ComplexityAnalysisNode" node). Please correct the data condition and re-generate the XML file. */
#define PS_complex_data_condition                           (PS_error_base + 206)

/** The BOM View Revision cannot be deleted because it contains occurrences. */
#define PS_bvr_not_empty_for_delete                         (PS_error_base + 207)

/** No matching revision found for seedpart in context of selected revision rule. */
#define PS_no_matching_revision_found                       (PS_error_base + 208)

/** The Revision Rule "All" or any Revision Rule with the "Precise" rule entry is not valid for the "Where Used Configured Parent" query. */
#define PS_invalid_revision_rule                            (PS_error_base + 209)

/** An invalid tag was detected for target part. */
#define PS_invalid_target_tag                               (PS_error_base + 210)

/** No valid target revisions of referring assembly found for the selected target part.*/
#define PS_no_valid_target_revision                         (PS_error_base + 211)

/** Invalid level has been selected.*/
#define PS_invalid_level_indicator                          (PS_error_base + 212)

/** Selected seed part is not referenced by any other assembly.*/
#define PS_no_valid_reference                               (PS_error_base + 213)

/** The provided BOM Line is not in scope for "In Context" editing. */
#define PS_absocc_ctxt_bomline_out_of_scope                 (PS_error_base + 214)

/** The Item "%1$" cannot be added as its own substitute. */
#define PS_item_substitute_itself                           (PS_error_base + 215)

/** The selected components cannot be added to a Solution Variant of Reuse category. */
#define PS_cannot_add_to_reuse_sv_structure                 (PS_error_base + 216)

/** The selected components cannot be removed from a Solution Variant of Reuse category. */
#define PS_cannot_remove_to_reuse_sv_structure              (PS_error_base + 217)

/** A non-modifiable active markup of non-Mass Update type already exists on "%1$". */
#define PS_massupdate_non_massupdate_markup_active          (PS_error_base + 218)

/** @deprecated #PS_massupdate_impacted_object_active_in_other_changeitems deprecated in Teamcenter 12.3. */
#define PS_massupdate_impacted_object_active_in_other_changeitems    (PS_error_base + 219)
TC_DEPRECATED_PREPROCESSOR( "12.3", PS_massupdate_impacted_object_active_in_other_changeitems, "" )

/** No proposed Item Revision is provided for the impacted object "%1$". */
#define PS_massupdate_proposed_item_not_provided            (PS_error_base + 220)

/** An invalid action is provided for the impacted object "%1$". */
#define PS_massupdate_invalid_action_type                   (PS_error_base + 221)

/** The proposed Item Revision provided is the same as the impacted object "%1$".  */
#define PS_massupdate_proposed_item_same_as_impacted        (PS_error_base + 222)

/** An invalid proposed Item Revision is provided for the impacted object "%1$".  */
#define PS_massupdate_invalid_proposed_item_provided        (PS_error_base + 223)

/** The problem Item Revision is the same as the proposed Item Revision "%1$".  */
#define PS_massupdate_problem_item_same_as_proposed_item    (PS_error_base + 224)

/** The structure of the parent "%1$" cannot be modified without the object first being revised. */
#define PS_parent_requires_revise                           (PS_error_base + 225)

/** @} */

/**
    @ingroup COLLABORATIVE BOM VIEW REVISION
    @{
*/

/** The specified operation is not supported for Collaborative BOM View Revisions. */
#define PS_not_supported_for_collaborative_bvr              (PS_error_base + 226)

/** The revisable occurrence for this collaborative BOM View Revision is NULL. */
#define PS_collaborative_bvr_null_ro                        (PS_error_base + 227)

/** One PS Occurrence is expected for each Revisable Occurrence. */
#define PS_psocc_count_inconsistent_with_rev_occ            (PS_error_base + 228)

/** @deprecated #PS_no_remove_privilege_for_collaborative_bvr deprecated in Teamcenter 12.3. Use #PS_no_remove_privilege_for_collaborative_parent instead. */
#define PS_no_remove_privilege_for_collaborative_bvr        (PS_error_base + 229)
TC_DEPRECATED_PREPROCESSOR( "12.3", PS_no_remove_privilege_for_collaborative_bvr, "PS_no_remove_privilege_for_collaborative_parent" )

/** "%1$" was not removed because you do not have access. */
#define PS_no_remove_privilege_for_collaborative_parent     (PS_error_base + 229)

/** "%1$" is not a valid Revisable Occurrence Revision type. */
#define PS_invalid_rev_occ_revision_type                    (PS_error_base + 230)

/** The Revisable Occurrence "%1$" cannot be deleted because it is referenced in multiple BOM View Revisions. */
#define PS_revocc_referred_by_multiple_bvr                  (PS_error_base + 231)

/** The Occurrence Revision "%1$" does not refer to the BOM View Revision "%2$". */
#define PS_bvr_rev_occ_mismatch                             (PS_error_base + 232)

/** @deprecated #PS_no_add_privilege_for_collaborative_bvr deprecated in Teamcenter 12.3. Use #PS_no_add_privilege_for_collaborative_parent instead. */
#define PS_no_add_privilege_for_collaborative_bvr           (PS_error_base + 233)
TC_DEPRECATED_PREPROCESSOR( "12.3", PS_no_add_privilege_for_collaborative_bvr, "PS_no_add_privilege_for_collaborative_parent" )

/** The occurrence creation failed because you do not have access to add an occurrence under "%1$". */
#define PS_no_add_privilege_for_collaborative_parent        (PS_error_base + 233)

/** The Markup type for the scoped mass update action handler is invalid. The valid value for Markup type is either "massUpdate" or "scopedMarkup". */
#define PS_markup_type_invalid                              (PS_error_base + 234)

/** The scoped mass update action handler can only accept one Item Revision target at a time. */
#define PS_markup_target_invalid                            (PS_error_base + 235)

/** The structure could not be copied because the structure management mode of the target BOM View is different from the source BOM View. */
#define PS_cannot_copy_struct_mgmt_mode_mismatch            (PS_error_base + 236)

/** The parent BOM View Revision or Item Revision for a new Revisable Occurrence must be specified. */
#define PS_revocc_requires_parent                           (PS_error_base + 237)

/** @} */

/**
    @defgroup ENTCBA_ERRORS ENTCBA Errors
    @ingroup ENTCBA
    @{
*/

/** An internal error has occurred in the CAD BOM Alignment module. */
#define PS_entcba_internal_error                            (PS_error_base + 238)

/** Failed to create an occurrence alignment between %1$" with "%2$" due to invalid input. */
#define PS_entcba_invalid_input_error                       (PS_error_base + 239)

/** "%1$" and "%2$" do not have alignment.*/
#define PS_entcba_alignment_not_found_error                 (PS_error_base + 240)

/** "%1$" and "%2$" has an existing alignment.*/
#define PS_entcba_input_already_aligned                     (PS_error_base + 241)
/** @} */


/**
    @ingroup PS_ERRORS
    @{
*/

/** "%1$" has expression based effectivity and cannot be modified using object based effectivity. Please remove the existing expression based effectivity to author an object based effectivity. */
#define PS_has_expr_based_eff_cant_have_object_based_eff    (PS_error_base + 242)

/** "%1$" has object based effectivity and cannot be modified using expression based effectivity. Please remove the existing object based effectivity to author an expression based effectivity. */
#define PS_has_object_based_eff_cant_have_expr_based_eff    (PS_error_base + 243)

/** The "Save As" operation is not supported for Product Collaborative BOM View Revisions. */
#define PS_saveas_not_supported_for_product_collaborative_bvr (PS_error_base + 244)

/** The Substitute Group "%1$" cannot be deleted because it is used in a different BOM View Revision. */
#define PS_substitute_group_used_in_other_bvr               (PS_error_base + 245)

/** The Substitute Group cannot be modified because the BOM View Revision "%1$" is released.  */
#define PS_bvr_is_released                                  (PS_error_base + 246)

/** @} */

/** Revisable occurrence revision cannot be created under non-collaborative parent "%1$". */
#define PS_revocc_not_allowed_under_non_collab_parent        (PS_error_base + 247)

/** @deprecated #PS_revocc_auto_revise_blocked_by_existing_working_revision deprecated in Teamcenter 12.4. Use #PS_revocc_revise_blocked_by_existing_working_revision instead */
#define PS_revocc_auto_revise_blocked_by_existing_working_revision        (PS_error_base + 248)
TC_DEPRECATED_PREPROCESSOR( "12.4", PS_revocc_auto_revise_blocked_by_existing_working_revision, "PS_revocc_revise_blocked_by_existing_working_revision" )

/** The auto-revise of "%1$" (occurrence type "%2$") is not supported because of a pre-existing discontinued working revision "%3$". */
#define PS_revocc_auto_revise_blocked_by_discontinued_working_revision    (PS_error_base + 249)

/** "%1$" is not a valid input type.*/
#define PS_entcba_invalid_single_input_error                       (PS_error_base + 250)

/** The following errors occurred while aligning "%1$" and "%2$": "%3$".*/
#define PS_entcba_partial_align_in_packed_lines                    (PS_error_base + 251)

/** The following errors occurred during unalignment of "%1$" and "%2$": "%3$".*/
#define PS_entcba_partial_unalign_in_packed_lines                  (PS_error_base + 252)

/** The alignment and unalignment operations are not supported between packed lines.*/
#define PS_entcba_align_unalign_between_packed_lines               (PS_error_base + 253)

/** The current user does not have modify access on the object "%1$". Please contact your system Administrator. */
#define PS_no_access_for_modification                              (PS_error_base + 254)

/** The revision of "%1$" (occurrence revision type "%2$") is blocked as the limit for allowed working revisions has been reached. The latest pre-existing working revision "%3$". */
#define PS_revocc_revise_blocked_by_existing_working_revision      (PS_error_base + 255)

/** The occurrence alignment between "%1$" and "%2$" could not be created because the part required is false on Design "%3$".*/
#define PS_entcba_part_required_false                              (PS_error_base + 256)

/** The occurrence alignment between "%1$" and "%2$" could not be created because the design required is false on Part "%3$".*/
#define PS_entcba_design_required_false                            (PS_error_base + 257)

/** "%1$" is not aligned with any part.*/
#define PS_entcba_alignment_not_found_for_design_error             (PS_error_base + 258)

/** "%1$" is not aligned with any design.*/
#define PS_entcba_alignment_not_found_for_part_error               (PS_error_base + 259)

/** The following errors occurred during unalignment of "%1$": "%2$"*/
#define PS_entcba_partial_unalign_in_packed_lines_for_single_input (PS_error_base + 260)

/** The "Revise" action for a "Duplicate" operation is not supported for Collaborative BOM View Revisions. */
#define PS_duplicate_revise_not_supported_for_collaborative_bvr    (PS_error_base + 261)

/** The occurrence alignment between "%1$" and "%2$" could not be created because the design "%3$" is already aligned.*/
#define PS_entcba_align_between_multiple_designs                   (PS_error_base + 262)

/** The occurrence alignment between "%1$" and "%2$" could not be created because the part "%3$" is already aligned.*/
#define PS_entcba_align_between_multiple_parts                     (PS_error_base + 263)

/** The occurrence alignment between "%1$" and "%2$" could not be created because the design "%3$" and the part "%4$" are already aligned.*/
#define PS_entcba_align_between_multiple_designs_parts             (PS_error_base + 264)

/** Revision Rule is not valid. Please supply a valid Revision Rule. */
#define PS_revision_rule_invalid                                   (PS_error_base + 265)

/** Page size is not valid. Please supply a valid page size. */
#define PS_invalid_page_size                                       (PS_error_base + 266)

/** An option was applied to the Where Used Pagination feature that is not currently supported. Please check PS_where_used_with_cursor for supported options. */
#define PS_where_used_unsupported_option                           (PS_error_base + 267)

/** The unalignment operation is not supported for "%1$", as context "%2$" is released.*/
#define PS_entcba_unalign_not_supported_for_released_context       (PS_error_base + 268)

/** The occurrence alignment between "%1$" and "%2$" could not be created because no revision is configured for "%3$".*/
#define PS_entcba_align_unconfigured_revision                      (PS_error_base + 269)

/** The unalignment operation is not supported between "%1$" and "%2$" because no revision is configured for "%3$".*/
#define PS_entcba_unalign_unconfigured_revision                    (PS_error_base + 270)

/** The unalignment operation is not supported for "%1$" because it has no configured revision.*/
#define PS_entcba_unalign_all_unconfigured_revision                (PS_error_base + 271)

/** The quantity cannot be decreased less than "%1$" because the occurrence contains alignments. To enter the decreased value, remove the alignment. */
#define PS_cannot_decrease_qty_for_aligned_occurrence              (PS_error_base + 272)

/** The provided Unit Of Measure (UoM) cannot be used because the occurrence contains alignments. To update the UoM, remove the alignment. */
#define PS_cannot_update_uom_for_aligned_occurrence                (PS_error_base + 273)

/** The Appearance Path Node of UID "%1$" has a conflict at the importing site. */
#define PS_apn_uid_has_collided_during_import                      (PS_error_base + 274)

/** Remote site ID "%1$" does not contain all the Appearace Path Nodes under the input Appearance Path Root "%2$". */
#define PS_apns_not_present_on_remote_site                         (PS_error_base + 275)

/** PS_error_ceiling should always be last and always be equal to the biggest error code. */
#define PS_error_ceiling                                           (PS_error_base + 275)

#endif
