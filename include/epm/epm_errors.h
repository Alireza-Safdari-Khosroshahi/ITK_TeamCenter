/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    EPM Errors
*/

/*  */

#ifndef EPM_ERRORS_H
#define EPM_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif
#include <epm/libepm_exports.h>

/**
    @defgroup EPM_ERRORS Errors
    @ingroup EPM
    @{
*/

#define EPM_internal_error                          (EMH_EPM_error_base + 1)
#define EPM_no_definitions_file                     (EMH_EPM_error_base + 2)

/**
    An invalid attempt to perform a task that has not been assigned.
    Will auto assign if possible.
*/
#define EPM_unassigned_task                         (EMH_EPM_error_base + 3)

#define EPM_job_initialization_failed               (EMH_EPM_error_base + 4)
#define EPM_unknown_process                         (EMH_EPM_error_base + 5)
#define EPM_unable_to_locate_node_id                (EMH_EPM_error_base + 7)
#define EPM_unable_to_load_subtask                  (EMH_EPM_error_base + 8)

/**
    This error is returned if a job being loaded cannot find its defintion
    in the process definition file. It should only happen if the user/sa
    has mistakenly, or otherwise, changed the name of the process definition
    so that the job cannot be continued.
*/
#define EPM_lost_definition                         (EMH_EPM_error_base + 9)

#define EPM_duplicate_registration                  (EMH_EPM_error_base + 12)
#define EPM_access_denied                           (EMH_EPM_error_base + 14)
#define EPM_invalid_state_change                    (EMH_EPM_error_base + 15)
#define EPM_already_completed                       (EMH_EPM_error_base + 17)

/** The handler is not registered. */
#define EPM_handler_not_registered                  (EMH_EPM_error_base + 18)

#define EPM_object_already_attached                 (EMH_EPM_error_base + 19)
#define EPM_invalid_argument                        (EMH_EPM_error_base + 20)
#define EPM_undefined_source_task                   (EMH_EPM_error_base + 21)

/** An interactive environment is required for this task handler. */
#define EPM_interactive_env_required                (EMH_EPM_error_base + 22)

/** A party was not specified for the proposed action. */
#define EPM_invalid_proposed_party                  (EMH_EPM_error_base + 23)

#define EPM_preconditions_not_met                   (EMH_EPM_error_base + 24)

/** Operation not allowed in current context. */
#define EPM_invalid_operation                       (EMH_EPM_error_base + 25)

#define EPM_children_not_completed                  (EMH_EPM_error_base + 27)
#define EPM_template_not_found                      (EMH_EPM_error_base + 28)
#define EPM_already_suspended                       (EMH_EPM_error_base + 29)
#define EPM_target_object_not_attached              (EMH_EPM_error_base + 30)
#define EPM_wrong_number_of_arguments               (EMH_EPM_error_base + 31)
#define EPM_missing_req_arg                         (EMH_EPM_error_base + 32)
#define EPM_attachments_not_found                   (EMH_EPM_error_base + 33)
#define EPM_not_in_process                          (EMH_EPM_error_base + 34)
#define EPM_job_corrupted                           (EMH_EPM_error_base + 35)
#define EPM_cannot_delete_job                       (EMH_EPM_error_base + 36)
#define EPM_task_not_complete                       (EMH_EPM_error_base + 37)
#define EPM_attachment_not_found                    (EMH_EPM_error_base + 38)
#define EPM_wrong_attachment_type                   (EMH_EPM_error_base + 39)
#define EPM_unable_to_add_procedure                 (EMH_EPM_error_base + 40)
#define EPM_unable_to_remove_procedure              (EMH_EPM_error_base + 41)
#define EPM_unable_to_replace_procedure             (EMH_EPM_error_base + 42)
#define EPM_object_referenced_elsewhere             (EMH_EPM_error_base + 43)
#define EPM_task_has_no_signoffs                    (EMH_EPM_error_base + 44)
#define EPM_check_job_existence                     (EMH_EPM_error_base + 45)
#define EPM_error_in_set_protection                 (EMH_EPM_error_base + 46)
#define EPM_unable_to_initiate_process              (EMH_EPM_error_base + 47)
#define EPM_cannot_find_job_procdeffile             (EMH_EPM_error_base + 48)
#define EPM_cannot_find_SA_procdeffile              (EMH_EPM_error_base + 49)
#define EPM_created_default_procdeffile             (EMH_EPM_error_base + 50)
#define EPM_cannot_create_procdeffile               (EMH_EPM_error_base + 51)
#define EPM_cannot_perform_action                   (EMH_EPM_error_base + 52)
#define EPM_cannot_lock_procdeffile                 (EMH_EPM_error_base + 53)
#define EPM_cannot_add_handler                      (EMH_EPM_error_base + 54)
#define EPM_cannot_remove_task_from_wso             (EMH_EPM_error_base + 55)
#define EPM_cannot_reset_parent_task                (EMH_EPM_error_base + 56)
#define EPM_cannot_restore_parent_task              (EMH_EPM_error_base + 57)
#define EPM_cannot_upgrade_task                     (EMH_EPM_error_base + 58)
#define EPM_cannot_destroy_NamedRevisionAnchor      (EMH_EPM_error_base + 59)
#define EPM_audit_file_not_found                    (EMH_EPM_error_base + 60)
#define EPM_unknown_rule_handler                    (EMH_EPM_error_base + 61)
#define EPM_procedure_ref_in_group                  (EMH_EPM_error_base + 62)
#define EPM_cannot_find_job_name                    (EMH_EPM_error_base + 63)
#define EPM_status_type_ref_by_procedure            (EMH_EPM_error_base + 64)
#define EPM_no_selection_in_tablewindow             (EMH_EPM_error_base + 65)
#define EPM_zero_number_of_reviewers                (EMH_EPM_error_base + 66)
#define EPM_no_acl_selection                        (EMH_EPM_error_base + 67)
#define EPM_object_based_not_supported              (EMH_EPM_error_base + 68)
#define EPM_role_and_group_blank                    (EMH_EPM_error_base + 69)
#define EPM_no_such_release_level                   (EMH_EPM_error_base + 70)
#define EPM_duplicate_process_definition_name       (EMH_EPM_error_base + 71)
#define EPM_invalid_object                          (EMH_EPM_error_base + 72)
#define EPM_invalid_taskinbox_object                (EMH_EPM_error_base + 73)
#define EPM_duplicate_handler_name_in_task_action   (EMH_EPM_error_base + 74)
#define EPM_object_already_exists                   (EMH_EPM_error_base + 75)
#define EPM_adhoc_signoff_disabled                  (EMH_EPM_error_base + 76)
#define EPM_invalid_group_name                      (EMH_EPM_error_base + 77)
#define EPM_invalid_role_name                       (EMH_EPM_error_base + 78)
#define EPM_not_perform_signoff_task                (EMH_EPM_error_base + 79)
#define EPM_unable_to_find_subtask                  (EMH_EPM_error_base + 80)
#define EPM_invalid_duration                        (EMH_EPM_error_base + 81)
#define EPM_duplicate_task_name                     (EMH_EPM_error_base + 82)
#define EPM_br_preconditions_not_met                (EMH_EPM_error_base + 83)
#define EPM_rule_handler_error_preface              (EMH_EPM_error_base + 84)
#define EPM_action_handler_error_preface            (EMH_EPM_error_base + 85)

/** The initial action was successful, but a subsequent task in the workflow may have failed. For additional details, please read the rest of the error messages. */
#define EPM_successful_with_warnings                (EMH_EPM_error_base + 86)

#define EPM_parent_task_has_not_started             (EMH_EPM_error_base + 87)
#define EPM_task_demoted                            (EMH_EPM_error_base + 88)
#define EPM_secure_task_failure                     (EMH_EPM_error_base + 89)
#define EPM_invalid_object_status                   (EMH_EPM_error_base + 90)
#define EPM_no_signoff_comments                     (EMH_EPM_error_base + 91)
#define EPM_invalid_argument_value                  (EMH_EPM_error_base + 92)
#define EPM_invalid_prop_values                     (EMH_EPM_error_base + 93)
#define EPM_missing_attachs_for_target              (EMH_EPM_error_base + 94)
#define EPM_missing_released_attachs                (EMH_EPM_error_base + 95)
#define EPM_missing_attachs_rel_list                (EMH_EPM_error_base + 96)
#define EPM_missing_working_attachs                 (EMH_EPM_error_base + 97)
#define EPM_tess_winsock_failed                     (EMH_EPM_error_base + 98)
#define EPM_tess_failed_to_connect                  (EMH_EPM_error_base + 99)
#define EPM_tess_socket_error                       (EMH_EPM_error_base + 100)
#define EPM_background_tess_warning                 (EMH_EPM_error_base + 101)
#define EPM_tessellation_no_valid_targets           (EMH_EPM_error_base + 102)
#define EPM_tessellation_failed                     (EMH_EPM_error_base + 103)

#define EPM_mutually_exclusive_arguments            (EMH_EPM_error_base + 104)
#define EPM_error_reading_plmxml_file               (EMH_EPM_error_base + 105)
#define EPM_fails_progression_path                  (EMH_EPM_error_base + 106)
#define EPM_no_status_attachment                    (EMH_EPM_error_base + 107)
#define EPM_unequal_component_statuses              (EMH_EPM_error_base + 108)
#define EPM_invalid_assembly_status                 (EMH_EPM_error_base + 109)
#define EPM_no_entry_in_prog_path_file              (EMH_EPM_error_base + 110)
#define EPM_no_entry_for_status                     (EMH_EPM_error_base + 111)
#define EPM_tess_failed_to_read                     (EMH_EPM_error_base + 112)
#define EPM_tess_failed_to_listen                   (EMH_EPM_error_base + 113)
#define EPM_tess_failed_to_bind                     (EMH_EPM_error_base + 114)
#define EPM_assm_stat_not_in_comp_prog              (EMH_EPM_error_base + 115)
#define EPM_comp_stat_not_in_comp_prog              (EMH_EPM_error_base + 116)
#define EPM_empty_note_values                       (EMH_EPM_error_base + 117)
#define EPM_missing_inprocess_attachs               (EMH_EPM_error_base + 118)
#define EPM_double_argument_value                   (EMH_EPM_error_base + 119)
#define EPM_duplicate_root_task_template_name       (EMH_EPM_error_base + 120)
#define EPM_duplicate_subtask_template_name         (EMH_EPM_error_base + 121)
#define EPM_tclink_failed_to_connect                (EMH_EPM_error_base + 122)
#define EPM_tclink_socket_error                     (EMH_EPM_error_base + 123)
#define EPM_signoff_quorum_not_met                  (EMH_EPM_error_base + 124)
#define EPM_signoff_profile_not_staffed             (EMH_EPM_error_base + 125)
#define EPM_interprocess_task_dependency_not_met    (EMH_EPM_error_base + 126)
#define EPM_invalid_target_type                     (EMH_EPM_error_base + 127)
#define EPM_invalid_target_revision                 (EMH_EPM_error_base + 128)
#define EPM_target_not_workspaceobject              (EMH_EPM_error_base + 129)
#define EPM_predecessor_not_completed               (EMH_EPM_error_base + 130)
#define EPM_or_predecessors_not_completed           (EMH_EPM_error_base + 131)
#define EPM_argument_dependency                     (EMH_EPM_error_base + 136)
#define EPM_invalid_attachment                      (EMH_EPM_error_base + 137)
#define EPM_error_initialising_plmxml_sdk           (EMH_EPM_error_base + 138)
/** The attachment "%1$" is using an unsupported configuration parameter set. */
#define EPM_unsupported_cparam                      (EMH_EPM_error_base + 139)
/** Attachments using different configuration parameter sets are not allowed in the same task. */
#define EPM_cparam_mismatch                         (EMH_EPM_error_base + 140)

/** The workflow handler "CONFMGMT_cut_back_effectivity" is used in mode "MergeCMEffectivity", which requires the "UseECNEffectivity" parameter. Please report this error to your system administrator. */
#define EPM_cutback_merge_mode_needs_ecneffectivity             (EMH_EPM_error_base + 141)
/** The workflow handler "CONFMGMT_cut_back_effectivity" is used in mode "MergeCMEffectivity", which does not support multiple effectivity intent families. */
#define EPM_cutback_merge_mode_multifamily_intent_not_valid     (EMH_EPM_error_base + 142)

#define EPM_resource_list_creation_failed           (EMH_EPM_error_base + 230)
#define EPM_resource_list_delete_failed             (EMH_EPM_error_base + 231)
#define EPM_resource_list_null_inputs               (EMH_EPM_error_base + 232)
#define EPM_resource_list_wrong_values              (EMH_EPM_error_base + 233)

#define EPM_duplicate_surrogate                     (EMH_EPM_error_base + 234)
#define EPM_not_valid_surrogate                     (EMH_EPM_error_base + 235)
#define EPM_failed_to_get_surrogate                 (EMH_EPM_error_base + 236)

#define EPM_assignment_list_creation_failed         (EMH_EPM_error_base + 237)

/** Invalid EPM Assignment List Object. */
#define EPM_assignment_list_invalid_object          (EMH_EPM_error_base + 238)
#define EPM_assignment_list_invalid_inputs          (EMH_EPM_error_base + 239)
#define EPM_assignment_non_unique_name              (EMH_EPM_error_base + 240)
#define EPM_assignment_list_modification_failed     (EMH_EPM_error_base + 241)
#define EPM_assignment_list_set_attr_failed         (EMH_EPM_error_base + 242)
#define EPM_assignment_list_ask_attr_failed         (EMH_EPM_error_base + 243)
#define EPM_assignment_list_delete_failed           (EMH_EPM_error_base + 244)
#define EPM_assignment_list_attach_to_proc_failed   (EMH_EPM_error_base + 245)
#define EPM_relation_type_not_found                 (EMH_EPM_error_base + 246)
#define EPM_no_proc_template_found                  (EMH_EPM_error_base + 247)
#define EPM_assignment_list_initialize_failed       (EMH_EPM_error_base + 248)
#define EPM_failed_to_replace_resource              (EMH_EPM_error_base + 249)
#define EPM_failed_to_assign_resource               (EMH_EPM_error_base + 250)

/** The copy of the EPM Assignment List "%1$" has failed. */
#define EPM_assignment_list_copy_failed             (EMH_EPM_error_base + 251)

#define EPM_target_wrong_number_of_targets          (EMH_EPM_error_base + 257)
#define EPM_target_wrong_number_of_relations        (EMH_EPM_error_base + 258)
#define EPM_target_missing_refs                     (EMH_EPM_error_base + 259)
#define EPM_target_wrong_number_of_refs             (EMH_EPM_error_base + 260)
#define EPM_target_empty_ref                        (EMH_EPM_error_base + 261)
#define EPM_target_old_ref                          (EMH_EPM_error_base + 262)
#define EPM_target_bad_form_prop                    (EMH_EPM_error_base + 263)
#define EPM_to_from_attach_mutually_inclusive       (EMH_EPM_error_base + 264)
#define EPM_to_from_attach_req_with_multiple_proc   (EMH_EPM_error_base + 265)
#define EPM_to_from_attach_vals_not_valid           (EMH_EPM_error_base + 266)
#define EPM_cannot_attach_parent_process_to_task    (EMH_EPM_error_base + 267)
#define EPM_run_ext_cmd_user_error                  (EMH_EPM_error_base + 268)
#define EPM_cannot_cut_inherited_wc                 (EMH_EPM_error_base + 269)
/** The current user does not have privileges to assign a Responsible Party to the Task "%1$" or Job "%2$". */
#define EPM_no_privilege_to_assign                  (EMH_EPM_error_base + 270)
#define EPM_standin_action_not_supported            (EMH_EPM_error_base + 271)
#define EPM_processes_in_loop                       (EMH_EPM_error_base + 272)
#define EPM_rev_rule_unconfig_child                 (EMH_EPM_error_base + 273)
#define EPM_not_a_task_or_process                   (EMH_EPM_error_base + 274)
#define EPM_task_circular_dependency                (EMH_EPM_error_base + 275)
#define EPM_task_belongs_to_same_process            (EMH_EPM_error_base + 276)
#define EPM_target_is_a_remote_object               (EMH_EPM_error_base + 277)
#define EPM_decision_cannot_be_set                  (EMH_EPM_error_base + 278)
#define EPM_incorrect_pass_for_secure_task          (EMH_EPM_error_base + 279)
#define EPM_obsolete_handler                        (EMH_EPM_error_base + 280)
#define EPM_check_user_privilege                    (EMH_EPM_error_base + 281)
#define EPM_not_valid_quorum                        (EMH_EPM_error_base + 282)
#define EPM_participant_creation_failed             (EMH_EPM_error_base + 283)
#define EPM_invalid_wait_setting                    (EMH_EPM_error_base + 284)
#define EPM_assignment_list_already_exists          (EMH_EPM_error_base + 285)
#define EPM_target_modified                         (EMH_EPM_error_base + 286)

#define EPM_TCX_AH_argument_string_len              (EMH_EPM_error_base + 287)
#define EPM_TCX_AH_option_not_defined               (EMH_EPM_error_base + 288)
#define EPM_TCX_RH_string_error                     (EMH_EPM_error_base + 289)
#define EPM_TCX_RH_option_not_defined               (EMH_EPM_error_base + 290)
#define EPM_TCX_AH_dataset_type_not_in_db           (EMH_EPM_error_base + 291)
#define EPM_TCX_AH_tool_type_not_in_db              (EMH_EPM_error_base + 292)
#define EPM_TCX_AH_no_tool_format                   (EMH_EPM_error_base + 293)
#define EPM_TCX_AH_reference_not_found              (EMH_EPM_error_base + 294)

#define EPM_not_valid_quorum_reset                  (EMH_EPM_error_base + 295)

#define EPM_zero_quorum_not_allowed                 (EMH_EPM_error_base + 296)
#define EPM_not_valid_quorum_percent                (EMH_EPM_error_base + 297)

#define EPM_single_participant_allowed              (EMH_EPM_error_base + 298)

#define EPM_inbox_folder_out_of_date                (EMH_EPM_error_base + 299)
#define EPM_origin_uid_not_set                      (EMH_EPM_error_base + 301)

#define EPM_checkout_and_checkin_not_allowed        (EMH_EPM_error_base + 302)

#define EPM_duplicate_template_name                 (EMH_EPM_error_base + 303)

#define EPM_cannot_modify_replica_template          (EMH_EPM_error_base + 304)
#define EPM_cannot_modify_template                  (EMH_EPM_error_base + 305)
#define EPM_no_resources_found                      (EMH_EPM_error_base + 306)
#define EPM_error_getting_workflow_template         (EMH_EPM_error_base + 307)
#define EPM_duplicate_assignment_list               (EMH_EPM_error_base + 308)
#define EPM_error_getting_signoff_role              (EMH_EPM_error_base + 309)
#define EPM_bad_release_date_status_name            (EMH_EPM_error_base + 310)
#define EPM_error_getting_particip_assignee         (EMH_EPM_error_base + 311)
#define EPM_duplicate_workflow_template             (EMH_EPM_error_base + 312)
#define EPM_error_getting_signoff_group             (EMH_EPM_error_base + 313)
#define EPM_incorrect_workflow_template             (EMH_EPM_error_base + 314)
#define EPM_target_with_invalid_status              (EMH_EPM_error_base + 315)

/** One of the required arguments "%1$" is not specified for this Workflow handler. */
#define EPM_invalid_group_arguments                 (EMH_EPM_error_base + 316)
#define EPM_UserInbox_name_change_failed            (EMH_EPM_error_base + 317)

#define EPM_cannot_assign_resources                 (EMH_EPM_error_base + 318)

/** The creation of the subprocess relation has failed. Please contact your system administrator and check the following Teamcenter server log file: %1$. */
#define EPM_cannot_create_subprocess                (EMH_EPM_error_base + 319)

/** The creation of the interprocess task dependency relation has failed. */
#define EPM_cannot_create_interprocess_dependency   (EMH_EPM_error_base + 320)

/** The action "%2$" in the task "%1$" has been submitted for background processing. */
#define EPM_async_task_action_submitted             (EMH_EPM_error_base + 321)

/** The action "%2$" in the task "%1$" is already being processed in the background. */
#define EPM_async_task_action_processing            (EMH_EPM_error_base + 322)

/** The task template "%1$" cannot be set for background processing. Only the root task and its immediate children can be directly set for background processing. */
#define EPM_cannot_set_task_template_to_async       (EMH_EPM_error_base + 323)

/** The action "%1$", which has been triggered by the task "%2$", is not applicable because its current state is "%3$". */
#define EPM_invalid_action_for_task_state           (EMH_EPM_error_base + 324)

/** The jobs through which the selected object went could not be retrieved. Please refer to the syslog file for more details: %1$. */
#define EPM_audit_fail_to_get_jobs                  (EMH_EPM_error_base + 325)

/** The current release status of the target object "%1$" is "%2$". To proceed in this workflow, the status of the target object must be one of the following: %3$. */
#define EPM_no_entry_for_current_status             (EMH_EPM_error_base + 326)

/** The current release status of the target object "%1$" is "%2$". The status to apply is defined as "%3$" in the current workflow, but a workflow that applies one of the following statuses is required: %4$. */
#define EPM_no_entry_in_progression_path            (EMH_EPM_error_base + 327)

/** Although the task "%1" is not an asynchronous task, an asynchronous task exists along the promote path. Therefore, the action "%2$" in the task "%1$" has been submitted for background processing. */
#define EPM_promote_sync_task_submitted_as_async    (EMH_EPM_error_base + 328)

/** Although the task "%1" is not an asynchronous task, an asynchronous task exists along the demote path. Therefore, the action "%2$" in the task "%1$" has been submitted for background processing. */
#define EPM_demote_sync_task_submitted_as_async     (EMH_EPM_error_base + 329)

/** The task "%1$" could not be performed, because the current user is neither a responsible party nor an active surrogate for the task.*/
#define EPM_user_not_valid_performer                (EMH_EPM_error_base + 330 )

/** The value for the property "%1$" on the object "%3$" of type "%2$" contains an unsupported typed reference object. For the user, the property value type should be "String", "User" or "GroupMember". For all members and the resource pool, its value should be "String", "GroupMember", "Group", "Role" or "ResourcePool". */
#define EPM_unsupported_prop_value                   (EMH_EPM_error_base + 331)

/** The dynamic participant "%1$" specified as an handler argument is not a single assignable dynamic participant. */
#define EPM_single_assignable_dp_handler             (EMH_EPM_error_base + 332)

/** The operation has failed, because it has failed to create a dynamic participant of type "%1$". Please refer to the Teamcenter server syslog file for more details. */
#define EPM_failed_to_create_participant             (EMH_EPM_error_base + 333)

/** The assignee argument value "%1$" could not be resolved either as a "GroupMember", or as a "ResourcePool". */
#define EPM_failed_to_resolve_assignee_argument      (EMH_EPM_error_base + 334)

/** The operation has failed, because the participant type could not be retrieved from the keyword "%1$". */
#define EPM_failed_to_get_participant_type           (EMH_EPM_error_base + 335)

/** The dynamic participant "%1$" specified as an handler argument is not a multi-assignable dynamic participant. */
#define EPM_multi_assignable_dp_handler              (EMH_EPM_error_base + 336)

/** Assigning the dynamic participants "%1$" to the object "%2$" is not allowed, because the criteria specified in BMIDE condition "%3$" is not satisfied. */
#define EPM_dp_assigning_not_allowed                 (EMH_EPM_error_base + 337)

/** The task "%1$" cannot be found. Please check the path "%2$" specified for the task. */
#define EPM_invalid_task_path                        (EMH_EPM_error_base + 338)

/** The specified task "%1$" is of type "%2$", which is invalid. A task of type "%3$" is expected. */
#define EPM_invalid_task_type                        (EMH_EPM_error_base + 339)

/** The current operation has aborted, because the Task "%1$" cannot be claimed. Either the current user is not privileged to claim it, or it has already been claimed.*/
#define EPM_unable_to_claim                          (EMH_EPM_error_base + 340)

/** The object "%1$" contains a voided Digital Signature. */
#define EPM_void_digital_signature                   (EMH_EPM_error_base + 341)

/** The object "%1$" must have a minimum of "%2$" valid Digital Signatures. */
#define EPM_minimum_valid_digital_signature          (EMH_EPM_error_base + 342)

/** The Digital Signature cannot be applied to the object "%1$", because the Digital Signature message is empty. */
#define EPM_invalid_digital_sign_message             (EMH_EPM_error_base + 343)

/** The object "%1$" contains an invalid Digital Signature. */
#define EPM_invalid_digital_signature                (EMH_EPM_error_base + 344)

/** The current user cannot be authenticated for Digital Signature, because the Digital Signature message information received by the server is empty. One possible cause is trying to use the Digital Signature feature on an unsupported client (e.g. Thin client). */
#define EPM_unable_to_authenticate_empty_message     (EMH_EPM_error_base + 345)

/** The signoff on the Task "%1$" or Job "%2$" cannot be delegated, because it contains a duplicate reviewer "%3$". */
#define EPM_signoff_member_exists                    (EMH_EPM_error_base + 346)

/** This handler can only be applied to completed actions of "Select Signoff" tasks. */
#define EPM_invalid_task_or_action_type              (EMH_EPM_error_base + 347)

/** The number of reviewers assigned to the task "%1$" must be at least %2$. */
#define EPM_assign_minimum_reviewer                  (EMH_EPM_error_base + 348)

/** Either the task "%1$" does not exist or it is not of type "Select Signoff". */
#define EPM_task_not_found                           (EMH_EPM_error_base + 349)

/** The user "%1$" is not a valid approver, because the system administrator has not allowed the user to be an approver. */
#define EPM_invalid_approver                         (EMH_EPM_error_base + 350)

/** The user "%1$" cannot be added as an approver, because the user is already an approver in another approval task in the same workflow process. */
#define EPM_approver_in_another_task                 (EMH_EPM_error_base + 351)

/** The workflow has been launched in a background session. */
#define EPM_worfklow_launched_in_background          (EMH_EPM_error_base + 352)

/** Objects cannot be pasted in the Folder "%1$", because this Folder is to contain only the folders "%2$" and "%3$". */
#define EPM_invalid_paste_objects_in_inbox_folder    (EMH_EPM_error_base + 353)

/** Objects cannot be pasted in the Folder "%1$", because this Folder contain only "%2$". */
#define EPM_invalid_paste_objects_in_task_folder     (EMH_EPM_error_base + 354)

/** The system does not allow the Folder "%1$" to be cut, because it may contain active workflow tasks. */
#define EPM_invalid_cut_objects                      (EMH_EPM_error_base + 355)

/** The Signoff Quorum cannot be modified, because the Signoff Quorum is set to 100% by the task template and the value for the preference "SIGNOFF_adhoc_quorum" is set to 2 (which means that the user can only set the Signoff Quorum to a value greater than the one set by the task template). */
#define EPM_cannot_modify_signoff_quorum             (EMH_EPM_error_base + 356)

/** The following objects cannot be added as targets, because they do not meet the condition "%2$": %1$. */
#define EPM_invalid_targets_for_filter               (EMH_EPM_error_base + 357)

/** The participant "%1$" is not assigned to the target "%2$". */
#define EPM_empty_dynamic_participant                (EMH_EPM_error_base + 358)

/** The assignee "%1$" does not meet the group/role eligibility "%2$" for the participant "%3$". */
#define EPM_incorrect_participant_assignee           (EMH_EPM_error_base + 359)

/** The syntax is invalid for the condition "%1$" of the template filter. */
#define EPM_invalid_filter_condition                 (EMH_EPM_error_base + 360)

/** The current user cannot perform the "Stand-In" operation on the Task "%1$",  because its state is "%2$". */
#define EPM_invalid_standin_for_task_state           (EMH_EPM_error_base + 361)

/** The current user cannot perform the "Stand-In" operation on the Task "%1$", because the signoff decision on the task is "%2$". */
#define EPM_invalid_standin_for_signoff_decision     (EMH_EPM_error_base + 362)

/** The "Stand-In" operation has already been performed on the Task "%1$" by another user.*/
#define EPM_already_standin                          (EMH_EPM_error_base + 363)

/** The current user cannot perform the "Release" operation on the Task "%1$", because its state is "%2$".*/
#define EPM_invalid_release_for_task_state           (EMH_EPM_error_base + 364)

/** The current user cannot perform  the "Release" operation on the Task "%1$", because the signoff decision on the task is "%2$". */
#define EPM_invalid_release_for_signoff_decision     (EMH_EPM_error_base + 365)


/** The target "%1$" cannot be attached, because it is of type Task.*/
#define EPM_target_is_epm_task_object                (EMH_EPM_error_base + 366)

/** The signoff on the Task "%1$" or Job "%2$" cannot be delegated, because the selected member, or resource pool, "%3$", is not in the signoff profiles. */
#define EPM_invalid_signoff_member                   (EMH_EPM_error_base + 367)

/** Please provide a password in order to complete the secure Task "%1$".*/
#define EPM_empty_password_for_secure_task           (EMH_EPM_error_base + 368)

/** The due date cannot be earlier than the current date. */
#define EPM_invalid_due_date                         (EMH_EPM_error_base + 369)

/** The reassignment email cannot be generated, because the following information is not specified properly: %1$.*/
#define EPM_insufficient_data_to_generate_email      (EMH_EPM_error_base + 370)

/** The Out of Office delegation for the user "%1$" is cyclic and loops back to itself. */
#define EPM_cyclic_out_of_office_delegate            (EMH_EPM_error_base + 371)

/** The release status cannot be applied to the target object "%1$" because it is checked-out. */
#define EPM_invalid_target_for_set_status            (EMH_EPM_error_base + 372)


/** The Reviewer "%1$" does not have "Read" access to the target attachments. */
#define EPM_no_target_read_access_for_reviewer       (EMH_EPM_error_base + 373)


/** The task result must be set to a valid value before performing the "%1$" action. */
#define EPM_task_result_not_set                      (EMH_EPM_error_base + 374)
/**
    RLM_not_initialized
*/
#define EPM_initialize_failed                        (EMH_EPM2_error_base + 1)

/**
    RLM_lock:   %1$
*/
#define EPM_lock                                     (EMH_EPM2_error_base + 5)

/**
    RLM_unlock: %1$
*/
#define EPM_unlock                                   (EMH_EPM2_error_base + 6)

/**
    RLM_save:   %1$
*/
#define EPM_save                                     (EMH_EPM2_error_base + 7)

/**
    RLM_change_ACL:     unable to change ACL or owner
*/
#define EPM_change_ACL                               (EMH_EPM2_error_base + 22)

/**
    RLM_delegate:      Must be the signoff user or an SA to delegate a signoff to someone else.
*/
#define EPM_delegate                                 (EMH_EPM2_error_base + 33)

/**
    RLM_negativeUnitNo:  Unit numbers must be 0 or greater if set.
*/
#define EPM_negative_serial_number                   (EMH_EPM2_error_base + 35)

/**
    RLM_endBeforeStartSerNo:    End unit number must be greater than or equal to start unit no.
*/
#define EPM_end_before_start_serial_number           (EMH_EPM2_error_base + 36)

/**
    RLM_endBeforeStartDate:     End date must be greater than or equal to start date.
*/
#define EPM_end_before_start_date                    (EMH_EPM2_error_base + 37)

/**
    RLM_role_duplicated: An access level for role "%1$" already exists for this release level.
*/
#define EPM_role_duplicated                          (EMH_EPM2_error_base + 38)

/**
    Cannot edit old effectivity attributes in v7 effectivity mode.
*/
#define EPM_cannot_edit_old_effectivities            (EMH_EPM2_error_base + 39)


/**
    Unknown error in EPM
    This is some error for which we have no explanation.
*/
#define EPM_unknown                                  (EMH_EPM2_error_base + 100)

/** #EPM_init_module not called */
#define EPM_not_initialized                          (EMH_EPM2_error_base + 101)

/** Invalid operation on a completed task or release level */
#define EPM_task_already_completed                   (EMH_EPM2_error_base + 102)

/** #EPM_init_module not called */
#define EPM_lowest_level_reached                     (EMH_EPM2_error_base + 103)

/** #EPM_init_module not called */
#define EPM_in_release_process                       (EMH_EPM2_error_base + 104)

/** #EPM_init_module not called */
#define EPM_already_released                         (EMH_EPM2_error_base + 105)

/** All reviewers were not added */
#define EPM_not_all_added                            (EMH_EPM2_error_base + 106)

/** User is not authorized to edit effectivity data. */
#define EPM_not_effectivity_user                     (EMH_EPM2_error_base + 107)

/** Cannot reassign reviewer */
#define EPM_cannot_reassign                          (EMH_EPM2_error_base + 108)

/** Duplicate reviewer found */
#define EPM_duplicate_reviewer                       (EMH_EPM2_error_base + 109)

/** A decision has already been rendered */
#define EPM_decision_already_rendered                (EMH_EPM2_error_base + 110)

/** The EPM Job type was not found in the database */
#define EPM_type_not_found                           (EMH_EPM2_error_base + 111)

/** The object is currently reserved and cannot be released */
#define EPM_object_is_reserved                       (EMH_EPM2_error_base + 112)

/** User was not found in the database */
#define EPM_user_not_found                           (EMH_EPM2_error_base + 113)

/** User for person not found in the database */
#define EPM_user_for_person_not_found                (EMH_EPM2_error_base + 114)

/** Error occurred in handler */
#define EPM_error_in_handler                         (EMH_EPM2_error_base + 115)

/** Argument is invalid */
#define EPM_argument_invalid                         (EMH_EPM2_error_base + 116)

/** Wrong number of arguments */
#define EPM_wrong_num_of_args                        (EMH_EPM2_error_base + 117)

/** Groupmember not found */
#define EPM_groupmember_not_found                    (EMH_EPM2_error_base + 118)

/** The last release status attachment cannot be removed because there must be at least one. */
#define EPM_cannot_remove_last_release_status        (EMH_EPM2_error_base + 119)

/** The last target attachment cannot be removed because there must be at least one. */
#define EPM_cannot_remove_last_target_object         (EMH_EPM2_error_base + 120)

/** You do not have permission to remove a target object from this CR job. */
#define EPM_access_denied_removing_target            (EMH_EPM2_error_base + 121)

/** There is no defined protection for release level. */
#define EPM_no_acl_defined_for_release_level         (EMH_EPM2_error_base + 122)

/** Invalid role name. */
#define EPM_role_name_invalid                        (EMH_EPM2_error_base + 123)

/** Invalid group name. */
#define EPM_group_name_invalid                       (EMH_EPM2_error_base + 124)

/** You must specify one of group name and role name. */
#define EPM_given_neither_group_nor_role             (EMH_EPM2_error_base + 125)

/** The current login group and/or role does not match with the required group and/or role. */
#define EPM_role_and_group_does_not_match_required   (EMH_EPM2_error_base + 126)

/** The subtask "Select-Signoff-Team" is not completed yet. */
#define EPM_select_signoff_team_not_completed        (EMH_EPM2_error_base + 127)

/** @if DOX_IGNORE
    Error codes for toolkit handlers offset by 300 from EMH_EPM2_error_base so as to make
    transition to published code easier
@endif */

#define EPM_cannot_open_file                         ( EMH_EPM2_error_base + 301 )
#define EPM_invalid_decision                         ( EMH_EPM2_error_base + 302 )
#define EPM_no_current_release_level                 ( EMH_EPM2_error_base + 303 )

/** @} */

#include <epm/libepm_undef.h>
#endif
