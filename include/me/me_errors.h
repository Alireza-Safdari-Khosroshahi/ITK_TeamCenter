/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the error codes for the ME module
*/

/*  */

#ifndef ME_ERRORS_H
#define ME_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup ME_ERRORS Errors
    @ingroup ME
    @{
*/

#define ME_initialization_failed            (EMH_ME_error_base + 1)
#define ME_activity_self_predecessor        (EMH_ME_error_base + 2)
#define ME_activity_not_in_class            (EMH_ME_error_base + 3)
#define ME_rel_already_exists               (EMH_ME_error_base + 4)
#define ME_activity_cyclic_pred_structure   (EMH_ME_error_base + 5)
#define ME_invalid_activity                 (EMH_ME_error_base + 6)
#define ME_invalid_relation                 (EMH_ME_error_base + 7)
#define ME_cannot_remove_activity           (EMH_ME_error_base + 8)
#define ME_cloning_error_during             (EMH_ME_error_base + 9)
#define ME_cloning_error_recovered          (EMH_ME_error_base + 10)
#define ME_cannot_reference_bvrs            (EMH_ME_error_base + 11)
#define ME_cannot_reference_variants        (EMH_ME_error_base + 12)
#define ME_bad_default_rule                 (EMH_ME_error_base + 13)
#define ME_cannot_ignore_attribute          (EMH_ME_error_base + 14)
#define ME_cannot_cut_inherited_srcline     (EMH_ME_error_base + 15)
#define ME_cannot_find_setup_view_type      (EMH_ME_error_base + 16)
#define ME_cloning_error_clone              (EMH_ME_error_base + 17)

#define ME_invalid_line_tag                 (EMH_ME_error_base + 100)
#define ME_line_object_not_loaded           (EMH_ME_error_base + 101)
#define ME_line_invalid_transform           (EMH_ME_error_base + 102)
#define ME_line_not_configured              (EMH_ME_error_base + 103)
#define ME_appearance_line_add              (EMH_ME_error_base + 104)
#define ME_appearance_line_remove           (EMH_ME_error_base + 105)
#define ME_appgroup_bomline_no_add          (EMH_ME_error_base + 106)
#define ME_bad_appgroup_placeholder         (EMH_ME_error_base + 108)
#define ME_no_appgroup_substitute           (EMH_ME_error_base + 109)
#define ME_no_appgroup_on_line              (EMH_ME_error_base + 110)
#define ME_line_remove_descendant           (EMH_ME_error_base + 111)
#define ME_line_reparent_descendant         (EMH_ME_error_base + 112)
#define ME_line_invalid_parent_window       (EMH_ME_error_base + 113)
#define ME_line_invalid_appearance          (EMH_ME_error_base + 114)
#define ME_line_invalid_appr_group          (EMH_ME_error_base + 115)
#define ME_line_invalid_child               (EMH_ME_error_base + 116)
#define ME_no_appgroup_allowed              (EMH_ME_error_base + 117)
#define ME_no_product_available             (EMH_ME_error_base + 118)
#define ME_source_referenced                (EMH_ME_error_base + 119)
#define ME_no_primary                       (EMH_ME_error_base + 120)
#define ME_no_secondary                     (EMH_ME_error_base + 121)

#define ME_invalid_window_tag               (EMH_ME_error_base + 150)
#define ME_window_invalid_root_line         (EMH_ME_error_base + 151)
#define ME_window_invalid_key_tag           (EMH_ME_error_base + 152)
#define ME_window_invalid_search_tag        (EMH_ME_error_base + 153)
#define ME_window_invalid_rev_rule          (EMH_ME_error_base + 154)
#define ME_assy_win_not_grp_or_appr         (EMH_ME_error_base + 155)
#define ME_window_unable_to_create_line     (EMH_ME_error_base + 156)
#define ME_window_circular_structure        (EMH_ME_error_base + 157)
#define ME_create_pathnode_fail             (EMH_ME_error_base + 158)
#define ME_remove_pathnode_fail             (EMH_ME_error_base + 159)
#define ME_cannot_link_more_than_one        (EMH_ME_error_base + 160)
#define ME_cannot_link_to_packed_line       (EMH_ME_error_base + 161)

#define PLMXMLTCM_export_xml_fail           (EMH_ME_error_base + 162)
#define PLMXMLTCM_write_xml_fail            (EMH_ME_error_base + 163)
#define ME_attachment_dup_not_allowed       (EMH_ME_error_base + 164)
#define ME_invalid_ic_tag                   (EMH_ME_error_base + 165)
#define APPGRP_line_subst_not_allowed       (EMH_ME_error_base + 166)
#define APPGRP_line_cant_be_loaded          (EMH_ME_error_base + 167)

#define ME_object_not_dataset_or_form       (EMH_ME_error_base + 168)
#define ME_line_has_ices                    (EMH_ME_error_base + 169)

#define ME_ipa_not_found                    (EMH_ME_error_base + 170)
#define ME_ipa_not_exist                    (EMH_ME_error_base + 171)
#define ME_ipa_no_consumed_product_in_process (EMH_ME_error_base + 172)
#define ME_ref_window_not_found             (EMH_ME_error_base + 173)
#define ME_filteredIPA_not_found            (EMH_ME_error_base + 174)
#define ME_validate_remove_level_fail       (EMH_ME_error_base + 175)
#define ME_cyclic_dependencies              (EMH_ME_error_base + 176)
#define ME_invalid_calculation_mode         (EMH_ME_error_base + 177)
#define ME_GRM_relation_not_found           (EMH_ME_error_base + 178)
#define ME_form_type_not_found              (EMH_ME_error_base + 179)
#define ME_missing_object_type              (EMH_ME_error_base + 180)
#define ME_search_not_supported             (EMH_ME_error_base + 181)
#define ME_mfgs_invalid_top_item_revision   (EMH_ME_error_base + 182)
#define ME_mfgs_invalid_occurrences         (EMH_ME_error_base + 183)
#define ME_mfgs_invalid_parent_irs_and_occ_threads (EMH_ME_error_base + 184)
#define ME_occ_types_list_not_available     (EMH_ME_error_base + 185)
#define ME_not_supported_object_type        (EMH_ME_error_base + 186)

#define ME_invalid_input_data               (EMH_ME_error_base + 187)
#define ME_encount_data_export_error        (EMH_ME_error_base + 188)
#define ME_assignment_not_supported         (EMH_ME_error_base + 189)
#define ME_can_link_only_BOPLines           (EMH_ME_error_base + 190)

#define ME_invalid_partition_parent_process   (EMH_ME_error_base + 300)
#define ME_invalid_partition_parent           (EMH_ME_error_base + 301)
#define ME_invalid_process_parent_process     (EMH_ME_error_base + 302)
#define ME_invalid_process_parent             (EMH_ME_error_base + 303)
#define ME_invalid_operation_parent_partition (EMH_ME_error_base + 304)
#define ME_invalid_operation_parent           (EMH_ME_error_base + 305)
#define ME_invalid_paste_duplicate_object     (EMH_ME_error_base + 306)
#define ME_invalid_paste_target_no_context    (EMH_ME_error_base + 307)
#define ME_invalid_copy_action_rule           (EMH_ME_error_base + 308)
#define ME_cannot_copy_mfgs                   (EMH_ME_error_base + 309)



#define ME_internal_error                                      (EMH_ME_error_base + 350)
#define ME_copy_root_apn_failed                                (EMH_ME_error_base + 351)
#define ME_invalid_root_object                                 (EMH_ME_error_base + 352)
#define ME_invalid_configurtation_window                       (EMH_ME_error_base + 353)
#define ME_invalid_copy_action_rules                           (EMH_ME_error_base + 354)
#define ME_getting_object_from_root_failed                     (EMH_ME_error_base + 355)
#define ME_no_paste_objects                                    (EMH_ME_error_base + 356)
#define ME_no_BOMWindow_set                                    (EMH_ME_error_base + 357)
#define ME_invalid_object                                      (EMH_ME_error_base + 358)
#define ME_no_write_access_to_bvr                              (EMH_ME_error_base + 359)
#define ME_uninitialized_line                                  (EMH_ME_error_base + 360)
#define ME_no_POM_class                                        (EMH_ME_error_base + 361)
#define ME_unsupported_type                                    (EMH_ME_error_base + 362)
#define ME_no_BOMWindow                                        (EMH_ME_error_base + 363)
#define ME_child_obj_not_Form                                  (EMH_ME_error_base + 364)
#define ME_obj_not_Form                                        (EMH_ME_error_base + 365)
#define ME_time_analysis_cannot_be_read                        (EMH_ME_error_base + 366)
#define ME_time_analysis_cannot_be_modified                    (EMH_ME_error_base + 367)
#define ME_time_analysis_cannot_be_created                     (EMH_ME_error_base + 368)
#define ME_time_analysis_rel_not_found                         (EMH_ME_error_base + 369)
#define ME_time_analysis_rel_cannot_be_created                 (EMH_ME_error_base + 370)
#define ME_time_analysis_rel_cannot_be_saved                   (EMH_ME_error_base + 371)
#define ME_invalid_input_parameters                            (EMH_ME_error_base + 372)
#define ME_import_mfgs_cannot_load_document                    (EMH_ME_error_base + 373)
#define ME_import_mfgs_missing_parts_pref                      (EMH_ME_error_base + 374)
#define ME_import_mfgs_missing_mfgs_pref                       (EMH_ME_error_base + 375)
#define ME_import_mfgs_invalid_parts_pref                      (EMH_ME_error_base + 376)
#define ME_import_mfgs_invalid_mfgs_pref                       (EMH_ME_error_base + 377)
#define ME_cant_assign_OG_child_and_parent                     (EMH_ME_error_base + 378)
#define ME_cant_cut_and_paste_from_base_to_OG                  (EMH_ME_error_base + 379)
#define ME_restructuring_isnot_allowed                         (EMH_ME_error_base + 380)
#define ME_restructuring_in_OG_not_allowed                     (EMH_ME_error_base + 381)
#define ME_invalid_search_scope_in_OG_search                   (EMH_ME_error_base + 382)
#define ME_ogwindow_and_baseview_flags_are_not_insync          (EMH_ME_error_base + 383)
#define ME_activity_multiple_assignment_of_resource            (EMH_ME_error_base + 384)
#define ME_failed_to_resolve_relation_type                     (EMH_ME_error_base + 385)
#define ME_update_flow_invalid_sequence_number                 (EMH_ME_error_base + 386)
#define ME_update_flow_invalid_object_type                     (EMH_ME_error_base + 387)
#define ME_negative_value_not_allowed                          (EMH_ME_error_base + 388)
#define ME_number_overflow                                     (EMH_ME_error_base + 389)
#define ME_delete_all_filteredIPA_failure                      (EMH_ME_error_base + 390)

/**
The PLMXML export has failed, because Logical Assignments cannot be added to Views.
*/
#define MEPLMXML_cannot_add_LA_to_view                         (EMH_ME_error_base + 391)

/**
The PLMXML export has failed, because Constraints cannot be added to Views.
*/
#define MEPLMXML_cannot_add_constraint_to_view                 (EMH_ME_error_base + 392)

/**
The PLMXML export has failed, because the called object "%1$" cannot be loaded.
*/
#define MEPLMXML_cannot_load_called_object                     (EMH_ME_error_base + 393)

/**
The PLMXML import has failed, because the PLM called object "%1$" cannot be loaded from the file "%2$".
*/
#define MEPLMXML_cannot_load_plm_called_object                 (EMH_ME_error_base + 394)

/**
The PLMXML import has failed, because the Logical Assignment type "%1$" cannot be loaded.
*/
#define MEPLMXML_cannot_get_LA_type                            (EMH_ME_error_base + 395)

/**
The PLMXML import has failed, because the Tool Requirement "%1$" cannot be loaded.
*/
#define MEPLMXML_cannot_load_TR                                (EMH_ME_error_base + 396)

/**
The PLMXML import has failed, because the node "%1$" cannot be assigned to the Logical Assignment object "%2$".
*/
#define MEPLMXML_cannot_assign_node_to_LA                      (EMH_ME_error_base + 397)

/**
The Logical Assignment object "%1$" could not be deleted during the Application Interface import because the data is corrupted. Please contact your system administrator.
*/
#define MEPLMXML_cannot_delete_LA                              (EMH_ME_error_base + 398)

/**
The Constraint object "%1$" could not be exported because the data is corrupted. Please contact your system administrator.
*/
#define MEPLMXML_failed_export_constraint_object               (EMH_ME_error_base + 399)

/**
The Constraint object "%1$" could not be imported because the data is corrupted. Please contact your system administrator.
*/
#define MEPLMXML_failed_import_constraint_object               (EMH_ME_error_base + 400)

/** A circular flow was detected between the object "%1$" of type "%2$" and the object "%3$" of type "%4$" due to incremental changes. Please correct the incremental flows or update the property "%5$" of the previously mentioned objects such that there are no circular flows. Then update the flows through the "Tools->Update Flows" command.*/
#define ME_update_flow_circular_dependency                     (EMH_ME_error_base + 401)

/**
The log file path could not be found.
*/
#define ME_log_file_path_not_found                             (EMH_ME_error_base + 402)

/**
The import of Manufacturing features has completed with some errors. Please refer to the log file for the errors.
*/
#define ME_import_mfgs_has_some_errors                         (EMH_ME_error_base + 403)

/**
The import of Manufacturing features has completed with some warnings. Please refer to the log file for the warnings.
*/
#define ME_import_mfgs_has_some_warnings                       (EMH_ME_error_base + 404)

/**
The input container and the scope are not from the same BOM window. Please select the lines from the same BOM window.
*/
#define ME_inputs_from_different_BOMWindows                    (EMH_ME_error_base + 405)

/**
The Manufacturing feature with Occurrence Note "%1$" and value "%2$" cannot be created by importing from the plmxml file. Please refer to the log file for details.
*/
#define ME_cannot_create_mfg_while_import                      (EMH_ME_error_base + 406)

/**
The Manufacturing feature with Occurrence Note "%1$" and value "%2$" cannot be updated by importing from the plmxml file. Please refer to the log file for details.
*/
#define ME_cannot_update_mfg_while_import                      (EMH_ME_error_base + 407)

/**
No Manufacturing feature was found in the input plmxml file "%$1". The input plmxml file is either invalid, or does not contain any information about Manufacturing features.
*/
#define ME_no_mfg_found_in_input_plmxml                        (EMH_ME_error_base + 408)

/**
Assembly Arrangements cannot be cut from a BOM View Revision. They can only be deleted.
*/
#define ME_cut_arrangement_not_allowed                         (EMH_ME_error_base + 409)

/**
Editing of attachments is not allowed for substitute lines when the "In Context" edit mode is turned on.
*/
#define ME_ic_updates_not_allowed_for_subs                     (EMH_ME_error_base + 410)
/**
The Incremental Change criteria are invalid, because they do not contain any valid intents or statuses.
*/
#define ME_ic_invalid_search_criteria                          (EMH_ME_error_base + 451)
/**
The input status string "%1$" is invalid. It should match a value in the List Of Values named "Mfg0PropagationStates".
*/
#define ME_invalid_propagation_status                          (EMH_ME_error_base + 452)
/**
The List Of Values named "Mfg0PropagationStates" could not be found. Perhaps the database schema is out-of-sync.
*/
#define ME_invalid_propagation_lov_status                      (EMH_ME_error_base + 453)
/**
A Path Node on the following line could not be created: %1$. Please check the line for errors.
*/
#define ME_unable_to_create_apn                                (EMH_ME_error_base + 454)
/**
The input data must have a context line, a context object and 1 or more target lines.
*/
#define ME_invalid_propagation_data                            (EMH_ME_error_base + 455)

/**
The specified scopes are invalid. Scopes must have an "Appearance Path Node" associated with them.
*/
#define ME_invalid_propagation_scopes                          (EMH_ME_error_base + 456)

/**
The specified status is invalid. The database needs to be checked for object "%1$" to make sure statuses are correct.
*/
#define ME_invalid_summary_status                              (EMH_ME_error_base + 457)

/**
The configured Item Revision does not match the newly created Item Revision for Item "%1$". Please make sure the Revision Rule supports this case by adding Working clause to it.
*/
#define ME_missing_revrule_clause_for_new_rev                  (EMH_ME_error_base + 475)

/**
The root BOM View "%1$" could not be locked. Please ensure that it is not locked by another session.
*/
#define ME_unable_to_lock_root_bv                              (EMH_ME_error_base + 476)

/**
The root BOM View Revision "%1$" could not be locked. Please ensure that it is not locked by another session.
*/
#define ME_unable_to_lock_root_bvr                             (EMH_ME_error_base + 477)

/**
No valid types are found in the value for the preference "%1$".
*/
#define ME_missing_types_in_preference                         (EMH_ME_error_base + 510)

/**
No value is defined for the preference "%1$".
*/
#define ME_missing_preference                                  (EMH_ME_error_base + 511)

/**
A default closure rule cannot be created. Please try again by specifying a valid closure rule.
*/
#define ME_cannot_create_dynamic_closure_rule                  (EMH_ME_error_base + 512)

/**
The assignment of lines cannot proceed, because another active session could be editing the structure. Please try again later.
*/
#define ME_detected_active_assign_context                      (EMH_ME_error_base + 513)

/**
The context assignment has failed in the source structure, because the parent BOM views could not be locked. Perhaps another Teamcenter session has already locked them. Please try again later.
*/
#define ME_detected_locked_assign_context_source               (EMH_ME_error_base + 514)

/**
The context assignment has failed in the target structure, because the parent BOM views could not be locked. Perhaps another Teamcenter session has already locked them. Please try again later.
*/
#define ME_detected_locked_assign_context_target               (EMH_ME_error_base + 515)

/**
The call to the SOA operation "searchConnectedLines" has failed. Please check the errors below to determine the cause. Alternatively, check the Teamcenter server syslog file for more information.
*/
#define ME_search_connected_lines_failed                       (EMH_ME_error_base + 516)

/**
The object "%1$" cannot be deleted, because it is checked-out by the user "%2$".
*/
#define ME_delete_attachment_failed                            (EMH_ME_error_base + 517)

/**
The Manufacturing BOM and Engineering BOM roots must be linked before performing the current operation.
*/
#define ME_mbom_ebom_roots_not_linked                          (EMH_ME_error_base + 520)

/**
A temporary Revision Rule could not be created. Please check the syslog for errors.
*/
#define ME_unable_to_create_rev_rule                           (EMH_ME_error_base + 521)

/**
A temporary Revision Rule could not be created in order to configure the reference structure with unit and date effectivity. Please check the syslog for errors.
*/
#define ME_unable_to_create_rev_rule_for_ref_structure         (EMH_ME_error_base + 522)

/**
No revision rule is associated with the source window.
*/
#define ME_null_rev_rule_on_source_window                      (EMH_ME_error_base + 523)

/**
The revision "%1$" does not exist for the item "%2$".
*/
#define ME_invalid_revision_for_item                           (EMH_ME_error_base + 524)

/**
A Revision Rule must be explicitly specified, because the supplied root is a Structure Context without a Revision Rule.
*/
#define ME_must_supply_revision_rule                           (EMH_ME_error_base + 525)

/**
No Revision Rule is attached to the Configuration Context of the supplied Structure Context.
*/
#define ME_no_rev_rule_in_cc_of_sc                             (EMH_ME_error_base + 526)

/**
No Configuration Context is associated to the supplied Structure Context.
*/
#define ME_no_cc_linked_to_sc                                  (EMH_ME_error_base + 527)

/**
The root object "%1$" of the supplied Structure Context is not supported. Only the following types are accepted: %2$.
*/
#define ME_invalid_root_in_sc                                  (EMH_ME_error_base + 528)

/**
The supplied root object "%1$" is invalid. Only the following types are accepted: %2$.
*/
#define ME_invalid_root_object_type                            (EMH_ME_error_base + 529)

/**
No Revision Rule exists with the name "%1$".
*/
#define ME_invalid_revision_rule                               (EMH_ME_error_base + 530)

/**
The Item and the Revision Rule could not be retrieved from the supplied parameters.
*/
#define ME_failed_to_get_item_and_revrule                      (EMH_ME_error_base + 531)

/**
The Structure Context must contain only one root node, but it contains %1$.
*/
#define ME_invalid_no_of_roots_in_sc                           (EMH_ME_error_base + 532)

/**
No Items can be found using the following multi-field keys: %1$.
*/
#define ME_invalid_mfk                                         (EMH_ME_error_base + 533)

/**
No Items can be found using the Item ID "%1$".
*/
#define ME_invalid_item_id                                     (EMH_ME_error_base + 534)

/**
* The following revision change XML file cannot be opened: %1$.
*/
#define ME_cannot_open_revisionchange_xml_file                 (EMH_ME_error_base + 535)
/**
* The Item Revision "%1$" in the Change Object "%2$" cannot be found in the configured structure.
*/
#define ME_incorrect_item_revision                             (EMH_ME_error_base + 536)
/**
* No unit or date effectivity can be found on the Manufacturing Change Notice "%1$".
*/
#define ME_no_unit_date_eff_on_mcn                             (EMH_ME_error_base + 537)
/**
* No end item effectivity can be found on the Manufacturing Change Notice "%1$".
*/
#define ME_no_end_item_eff_on_mcn                              (EMH_ME_error_base + 538)
/**
The Manufacturing BOM (MBOM) assembly node does not contain any assigned lines. Please select an MBOM assembly node that contains lines assigned from Engineering BOM.
*/
#define ME_missing_assigned_lines_below_mbom_assm              (EMH_ME_error_base + 539)

/**
No Engineering BOM Lines can be found below the Manufacturing BOM assembly with the provided ID "%1$" in the context strings.
*/
#define ME_missing_ebom_lines_for_mbom_assm                    (EMH_ME_error_base + 540)

/**
The BOM Line used as basis for calculating the relative transformations in the Manufacturing BOM assembly could not be found. Please ensure that the reuse assembly is valid.
*/
#define ME_missing_basis_in_mbom_threads                       (EMH_ME_error_base + 541)

/**
Not all the BOM Lines can be found for all the provided identifiers. Please ensure that the reuse assembly is valid.
*/
#define ME_mismatched_lines_and_threads_count                  (EMH_ME_error_base + 542)

/**
The Engineering BOM Line used as a basis for calculating the relative transformation could not be found. Please ensure that the reuse assembly is valid.
*/
#define ME_missing_basis_line_lines_computed_from_threads      (EMH_ME_error_base + 543)

/**
Duplicate transformations are found on the assigned lines. Please ensure that the reuse assembly does not have duplicate transformations.
*/
#define ME_dup_transforms_exist                                (EMH_ME_error_base + 544)

/**
The number of BOM Lines to be aligned using the patterns in the Engineering BOM and the Manufacturing BOM reuse assemblies do not match. Please check the Teamcenter syslog file for errors, and report this error.
*/
#define ME_mismatched_pattern_lines                            (EMH_ME_error_base + 545)

/**
The inverse matrix could not be computed. Please check the transformation on the BOM Line "%1$".
*/
#define ME_cannot_compute_matrix_inverse                       (EMH_ME_error_base + 546)

/**
The alignment cannot continue, because the Engineering BOM item does not match the Manufacturing BOM item.
*/
#define ME_mismatched_items_for_align                          (EMH_ME_error_base + 547)

/* The Item Revision "%1$" cannot be attached to the Change Object "%2$", because the Item Revision "%3$" is already attached to it. */
#define ME_line_rev_already_in_mcn                             (EMH_ME_error_base + 548)
/* No Change Object is associated to the structure "%1$".*/
#define ME_structure_no_mcn                                    (EMH_ME_error_base + 549)
/* The Item Revision "%1$" is already attached to the Change Object "%2$".*/
#define ME_line_rev_already_exist                              (EMH_ME_error_base + 550)
/* The Item Revision "%1$" is not found in the Change Object "%2$".*/
#define ME_line_rev_not_found                                  (EMH_ME_error_base + 551)
/* An invalid BOM Line property "%1$" is listed in the preference "%2$".
*/
#define ME_invalid_bom_property_in_preference                  (EMH_ME_error_base + 552)
/**
* No input BOM Lines can be found for the Manufacturing feature "%1$".
*/
#define ME_no_bomlines_found                                   (EMH_ME_error_base + 553)
/**
* An invalid BOM Line is provided to the Manufacturing feature "%1$".
*/
#define ME_invalid_bomline                                     (EMH_ME_error_base + 554)
/**
* The object "%1$" provided to the Manufacturing feature "%2$" is invalid, because it is of type "%3$". The allowed types are: %4$.
*/
#define ME_expected_object_invalid                             (EMH_ME_error_base + 555)
/**
* No object has been provided to the Manufacturing feature "%1$". Please provide an object of the following type: %2$..
*/
#define ME_null_object_invalid                                 (EMH_ME_error_base + 556)

/**
* The "Paste" operation is only supported within a same Bill Of Material (BOM) structure.
*/
#define ME_different_structure                                 (EMH_ME_error_base + 557)

/**
* The "Paste or Replace Assembly In Context" operation has failed, because it expects an Item Revision without a BOM View Revision and "%1$" contains one.
*/
#define ME_object_has_bom_view_revision                        (EMH_ME_error_base + 558)

/**
* The "%1$" operation has failed, because the value "%3$" for the argument "%2$" is invalid. Valid values are: %4$.
*/
#define ME_invalid_arg_to_operation                            (EMH_ME_error_base + 559)

/**
* Cloning attachments for the object "%1$" has failed. Please check the Teamcenter server syslog file for more information.
*/
#define ME_problem_cloning_attachments_for_object              (EMH_ME_error_base + 560)

/**
* Cloning rules of type "Reference" is not allowed for Relations of type "%1$" (Mfg0MEAssignmentRecipeRel).
*/
#define ME_reference_cloning_rule_not_allowed_mbom_recipe      (EMH_ME_error_base + 561)

/**
* Cloning rules of type "Clone" is not allowed for Relations of type "%1$" (Mfg0MEResolvedMBOMRel).
*/
#define ME_clone_cloning_rule_not_allowed_mbom_recipe_resolve  (EMH_ME_error_base + 562)

/**
* The input argument "%1$" is invalid because it contains the value "%2$" at index "%3$".
*/
#define ME_invalid_input_arguments                             (EMH_ME_error_base + 563)

/**
* The necessary schema is missing. Please ensure the "%1$" template is current and try again.
*/
#define ME_missing_schema                                      (EMH_ME_error_base + 564)

/**
* The structures must be linked for this action to succeed.
*/
#define ME_missing_root_link                                   (EMH_ME_error_base + 565)

/**
* The revision "%1$" cannot be unlinked, because the revision "%2$" is linked.
*/
#define ME_mismatched_design_part_rev                          (EMH_ME_error_base + 566)

/**
* The preference "MEDesignToBom_Enabled" must be set to "true" to enable any Design EBOM (Engineering Bill of Material) related functionality.
*/
#define ME_design_ebom_disabled                                (EMH_ME_error_base + 567)

/**
* The structure cannot be used for aligning Design and EBOM (Engineering Bill of Material) objects, because Part CAD links exist on some of its BOM Lines.
*/
#define ME_design_ebom_alignment_disabled                      (EMH_ME_error_base + 568)

/**
* The Design revision "%1$" cannot be aligned with the BOM revision "%2$", because "%1$" does not meet the maturity criterion.
*/
#define ME_design_not_mature                                   (EMH_ME_error_base + 569)

/**
* The Part "%1$" cannot be aligned with the Design "%2$" because it is already aligned with the Design "%3$".
*/
#define ME_design_invalid_item_to_align                        (EMH_ME_error_base + 570)

/**
The Design Line "%1$" cannot be aligned to the Part BOM Line "%2$" because the Part BOM Line may already be aligned. Use the "Find" functionality to locate the existing alignment in the Design Structure and remove that alignment before trying again.
*/
#define ME_design_invalid_idic_alignment                       (EMH_ME_error_base + 571)

/**
An alignment cannot be performed as the selection contains a root BOM Line.
*/
#define ME_design_invalid_line_for_align                       (EMH_ME_error_base + 572)

/**
The property alignment cannot be performed because the Design revision "%1$" is not connected to the Part revision "%2$".
*/
#define ME_design_invalid_connection_for_prop_align            (EMH_ME_error_base + 573)

/**
The operation "%1$" cannot be revised because access is denied on the root activity.
*/
#define ME_operation_revise_not_allowed_root_activity_access   (EMH_ME_error_base + 574)

/**
The structure "%1$" is locked by the user "%2$". Please try to create an alternative after some time or choose to create it in the background
*/
#define ME_unable_to_lock_structure                            (EMH_ME_error_base + 575)

/**
The operation "%1$" found that the number of input Part lines and the number of processed Part lines do not match.
*/
#define ME_partline_results_do_not_match                       (EMH_ME_error_base + 576)

/**
 The "Find Future Revisions" has failed because the revision rule must contain at least one "Has Status" clause with effectivity.
 */
#define ME_REVRULE_INVALID_NO_HASSTATUS                        (EMH_ME_error_base + 577)

/**
 The "Find Future Revisions" has failed because the revision rule must contain a date or unit effectivity clause.
*/
#define ME_REVRULE_INVALID_NO_EFFECTIVITY                      (EMH_ME_error_base + 578)

/**
 The "Find Future Revisions" has failed because the revision rule must contain an end item clause.
*/
#define ME_REVRULE_INVALID_NO_ENDITEM                          (EMH_ME_error_base + 579)

/**
 The transient Revision Rule cannot be created. Please contact your system administrator.
 */
#define ME_CANNOT_CREATE_TRANSIENT_REVRULE                     (EMH_ME_error_base + 580)

/**
Applying the Product view could not be completed because the stamping of visualization reconciliation metadata has failed for the following objects "%1$". 
*/
#define ME_idic_stamping_failed                                (EMH_ME_error_base + 581)

/**
The rule "%1$" defined in the preference "%2$" is invalid.
*/
#define ME_error_parsing_cloning_rule                          (EMH_ME_error_base + 582)

/**
No revision changes are found.
*/
#define ME_no_revision_changes_found                           (EMH_ME_error_base + 583)

/**
No variant rule is associated with the product variant "%1$".
*/
#define ME_missing_variant_rule                                (EMH_ME_error_base + 584)

/**
The configuration of the structure "%1$" does not include the variant rule "%2$".
*/
#define ME_config_svr_mismatch                                 (EMH_ME_error_base + 585)

/**
The configuration of the structure "%1$" does not include the product variant "%2$".
*/
#define ME_config_pv_mismatch                                  (EMH_ME_error_base + 586)

/**
The configuration of the structure "%1$" does not include the following variant rules: %2$.
*/
#define ME_config_svrs_mismatch                                (EMH_ME_error_base + 587)

/**
The configuration of the structure "%1$" does not include the following product variants: %2$.
*/
#define ME_config_pvs_mismatch                                 (EMH_ME_error_base + 588)

/**
The configuration of the structure "%1$" does not include the following variant rules and product variants: %2$.
*/
#define ME_config_svrs_pvs__mismatch                           (EMH_ME_error_base + 589)

/**
The source object "%1$" cannot be pasted under the target object "%2$", because it already exists under "%3$".
*/
#define ME_paste_by_rule_duplicate_op                          (EMH_ME_error_base + 590)

/**
The utility "%1$" has failed because the parameter "%2$" is invalid or missing.
*/
#define ME_feature_failed_invalid_or_missing                   (EMH_ME_error_base + 591)

/**
No Operations or Processes found for processing in "%1$". 
*/
#define ME_no_operations_processes_found                       (EMH_ME_error_base + 592)

/**
The Manufacturing feature "%1$" has detected that the "ApplicationRef" "%2$" is invalid. 
*/
#define ME_found_invalid                                       (EMH_ME_error_base + 593)

/**
The "Paste by Rule" operation can only be performed from Classic BOP to Plant BOP.
*/
#define ME_pastebyrule_src_invalid                             (EMH_ME_error_base + 594)

/**
The object "%1$" cannot be checked-out which is attached to the line "%2$". Please check the Teamcenter server syslog file for more information.
*/
#define ME_checkout_attachment_failed                          (EMH_ME_error_base + 595)

/**
The object "%1$" cannot be checked-in which is attached to the line "%2$". Please check the Teamcenter server syslog file for more information.
*/
#define ME_checkin_attachment_failed                           (EMH_ME_error_base + 596)

/**
The ID "%1$" specified in the "contextRef" attribute of the PLMXML "AttributeContext" element with ID "%2$" could not be resolved.
*/
#define MEPLMXML_cannot_resolve_contextRef                     (EMH_ME_error_base + 599)
 
/**
The following Appearance Path Nodes could not be mapped to any BOM Line: %1$.
*/
#define MEPLMXML_cannot_resolve_APN                            (EMH_ME_error_base + 600)

/**
The input object "%1$" is invalid. The valid scope is process line from Plant Bill of Process structure.
*/
#define ME_set_scope_invalid_object_type                       (EMH_ME_error_base + 601)

/**
The product scope cannot be set on the process line "%1$" as the process structure is not part of Collaboration Context.
*/
#define ME_process_not_in_cc                                   (EMH_ME_error_base + 602)

/**
The product scope cannot be set on the process line "%1$" as the Bill of Material structure and the Bill of Process structure are not part of Collaboration Context.
*/
#define ME_structures_not_in_cc                                (EMH_ME_error_base + 603)

/**
The product scope is not set.
*/
#define ME_product_scope_not_set                               (EMH_ME_error_base + 604)

/**
The input context process line "%1$" is invalid because it is not part of a Collaboration Context.
*/
#define ME_invalid_context_process_line                         (EMH_ME_error_base + 605)

/**
The input product scope "%1$" is invalid because it is not part of a Collaboration Context.
*/
#define ME_invalid_product_scope                                (EMH_ME_error_base + 606)

/**
The input product scope "%1$" is invalid because the product scope and context process line are not part of the same Collaboration Context.
*/
#define ME_product_scope_not_in_same_cc                         (EMH_ME_error_base + 607)

/**
The Manufacturing Validation Test client "%1$" is not in the preference "%2$".
*/
#define ME_mfg_validation_test_framework_cannot_find_client    (EMH_ME_error_base + 608)

/**
No Manufacturing Validation Test type is specified in the preference "%1$".
*/
#define ME_mfg_validation_test_framework_no_validation_test_types (EMH_ME_error_base + 609)

/**
No Manufacturing Validation Test is registered for the type "%1$". Please contact your system administrator.
*/
#define ME_mfg_validation_test_framework_no_validation_tests_registered_for_type (EMH_ME_error_base + 610)

/**
The object "%1$" attached to the line "%2$" cannot be unchecked-out. Please check the Teamcenter server syslog file for more information.
*/
#define ME_cancel_checkout_attachment_failed                    (EMH_ME_error_base + 611)

/** @} */
#endif
