/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
#ifndef SCHMGT_ERRORS_H
#define SCHMGT_ERRORS_H
#include <common/emh_const.h>

/**
@defgroup SCHMGT_ERRORS Errors
@ingroup SCHMGT
@{
*/

#define SCHMGT_ERROR_BASE                                                   EMH_SCHMGT_error_base

#define SCHMGT_not_initialized                                              (SCHMGT_ERROR_BASE + 1)
#define SCHMGT_invalid_parameters                                           (SCHMGT_ERROR_BASE + 2)
#define SCHMGT_schedule_with_id_already_exists                              (SCHMGT_ERROR_BASE + 3)
#define SCHMGT_schedule_revision_already_exists                             (SCHMGT_ERROR_BASE + 4)
#define SCHMGT_task_with_id_already_exists                                  (SCHMGT_ERROR_BASE + 5)
#define SCHMGT_task_revision_already_exists                                 (SCHMGT_ERROR_BASE + 6)
#define SCHMGT_some_task_revisions_could_not_be_deleted                     (SCHMGT_ERROR_BASE + 7)
#define SCHMGT_some_tasks_could_not_be_deleted                              (SCHMGT_ERROR_BASE + 8)
#define SCHMGT_some_tasks_could_not_be_updated                              (SCHMGT_ERROR_BASE + 9)
#define SCHMGT_task_has_invalid_parent                                      (SCHMGT_ERROR_BASE + 10)
#define SCHMGT_cost_form_with_id_already_exists                             (SCHMGT_ERROR_BASE + 11)
#define SCHMGT_invalid_user                                                 (SCHMGT_ERROR_BASE + 12)
#define SCHMGT_no_memberships_for_user                                      (SCHMGT_ERROR_BASE + 13)
#define SCHMGT_no_memberships_for_schedule                                  (SCHMGT_ERROR_BASE + 14)
#define SCHMGT_test_failed                                                  (SCHMGT_ERROR_BASE + 15)
#define SCHMGT_internal_error                                               (SCHMGT_ERROR_BASE + 16)
#define SCHMGT_taskdependency_create_failed                                 (SCHMGT_ERROR_BASE + 17)
#define SCHMGT_taskdependency_update_failure                                (SCHMGT_ERROR_BASE + 18)
#define SCHMGT_taskdependency_delete_failed                                 (SCHMGT_ERROR_BASE + 19)
#define SCHMGT_schedulemember_create_failed                                 (SCHMGT_ERROR_BASE + 20)
#define SCHMGT_schedulemember_update_failed                                 (SCHMGT_ERROR_BASE + 21)
#define SCHMGT_schedulemember_no_delete                                     (SCHMGT_ERROR_BASE + 22)
#define SCHMGT_schedulemember_warn_delete                                   (SCHMGT_ERROR_BASE + 23)
#define SCHMGT_schedulemember_delete_failed                                 (SCHMGT_ERROR_BASE + 24)
#define SCHMGT_resource_not_schedule_member                                 (SCHMGT_ERROR_BASE + 25)
#define SCHMGT_cant_load_ets                                                (SCHMGT_ERROR_BASE + 26)
#define SCHMGT_cant_find_ets_fn                                             (SCHMGT_ERROR_BASE + 27)
#define SCHMGT_schedulemember_user_exists                                   (SCHMGT_ERROR_BASE + 28)
#define SCHMGT_scheduledeliverable_exists                                   (SCHMGT_ERROR_BASE + 29)
#define SCHMGT_workflow_properties_not_set                                  (SCHMGT_ERROR_BASE + 30)
#define SCHMGT_parent_task_has_workflow                                     (SCHMGT_ERROR_BASE + 31)
#define SCHMGT_task_with_subtask_cannot_have_wflw                           (SCHMGT_ERROR_BASE + 32)
#define SCHMGT_schedule_baseline_name_already_exists                        (SCHMGT_ERROR_BASE + 33)
#define SCHMGT_orphaned_schedule_baseline                                   (SCHMGT_ERROR_BASE + 34)
#define SCHMGT_no_privilege_to_delete_object                                (SCHMGT_ERROR_BASE + 35)
#define SCHMGT_invalid_operation_direct_set                                 (SCHMGT_ERROR_BASE + 36)
#define SCHMGT_resourceassignment_create_failed                             (SCHMGT_ERROR_BASE + 37)
#define SCHMGT_task_creation_failed                                         (SCHMGT_ERROR_BASE + 38)
#define SCHMGT_task_copy_failed                                             (SCHMGT_ERROR_BASE + 39)
#define SCHMGT_get_task_properties_failed                                   (SCHMGT_ERROR_BASE + 40)
#define SCHMGT_get_tasks_in_schedule_failed                                 (SCHMGT_ERROR_BASE + 41)
#define SCHMGT_schedule_not_revisable                                       (SCHMGT_ERROR_BASE + 42)
#define SCHMGT_scheduletask_not_revisable                                   (SCHMGT_ERROR_BASE + 43)
#define SCHMGT_no_privilege_to_create_object                                (SCHMGT_ERROR_BASE + 44)
#define SCHMGT_no_privilege_to_modify_object                                (SCHMGT_ERROR_BASE + 45)
#define SCHMGT_invalid_deliverable_type                                     (SCHMGT_ERROR_BASE + 46)
#define SCHMGT_cannot_move_del_sch_summary_task                             (SCHMGT_ERROR_BASE + 47)
#define SCHMGT_summary_task_cannot_be_added                                 (SCHMGT_ERROR_BASE + 48)
#define SCHMGT_schedule_with_old_copy                                       (SCHMGT_ERROR_BASE + 49)
#define SCHMGT_master_schedule_is_part_of_another_master                    (SCHMGT_ERROR_BASE + 50)
#define SCHMGT_failed_to_checkout_license                                   (SCHMGT_ERROR_BASE + 51)
#define SCHMGT_user_needs_author_license                                    (SCHMGT_ERROR_BASE + 52)
#define SCHMGT_change_schedule_summary_task_type_failed                     (SCHMGT_ERROR_BASE + 53)
#define SCHMGT_CO_flow_not_correct                                          (SCHMGT_ERROR_BASE + 54)
#define SCHMGT_CI_flow_not_correct                                          (SCHMGT_ERROR_BASE + 55)
#define SCHMGT_Undo_flow_not_correct                                        (SCHMGT_ERROR_BASE + 56)
#define SCHMGT_Duplicate_SubSchedule                                        (SCHMGT_ERROR_BASE + 57)
#define SCHMGT_Task_can_not_SaveAs                                          (SCHMGT_ERROR_BASE + 58)
#define SCHMGT_task_has_no_assignments                                      (SCHMGT_ERROR_BASE + 59)
#define SCHMGT_failure_launching_workflow                                   (SCHMGT_ERROR_BASE + 60)
#define SCHMGT_schedule_deleted                                             (SCHMGT_ERROR_BASE + 61)
#define SCHMGT_undo_not_supported                                           (SCHMGT_ERROR_BASE + 62)
#define SCHMGT_task_undo_not_supported                                      (SCHMGT_ERROR_BASE + 63)
#define SCHMGT_circular_master_subschedule                                  (SCHMGT_ERROR_BASE + 64)
#define SCHMGT_workflowtriggered_othersite                                  (SCHMGT_ERROR_BASE + 65)
#define SCHMGT_remote_object_not_available                                  (SCHMGT_ERROR_BASE + 66)
#define SCHMGT_WF_initiated_cannot_update_attributes                        (SCHMGT_ERROR_BASE + 67)
#define SCHMGT_owner_can_pub_unpublish_sch                                  (SCHMGT_ERROR_BASE + 68)
#define SCHMGT_remote_export_not_support                                    (SCHMGT_ERROR_BASE + 69)
#define SCHMGT_template_unpublish_sch_no_workflow                           (SCHMGT_ERROR_BASE + 70)
#define SCHMGT_timesheet_workflow_not_support                               (SCHMGT_ERROR_BASE + 71)
#define SCHMGT_ActualStartDate_after_ActualEndDate                          (SCHMGT_ERROR_BASE + 72)
#define SCHMGT_ActualEndDate_Before_ActualStartDate                         (SCHMGT_ERROR_BASE + 73)
#define SCHMGT_Status_Cannot_Change_AS_PC100                                (SCHMGT_ERROR_BASE + 74)
/** The amount of work complete cannot be less than the calculated value based on approved work. */
#define SCHMGT_WorkComplete_lessthan_ApprovedWork                           (SCHMGT_ERROR_BASE + 75)
#define SCHMGT_ActualStart_Beyond_PrefDate                                  (SCHMGT_ERROR_BASE + 76)
#define SCHMGT_ActualFinish_Beyond_PrefDate                                 (SCHMGT_ERROR_BASE + 77)
#define SCHMGT_PC_Cannotbe_morethan_100                                     (SCHMGT_ERROR_BASE + 78)
#define SCHMGT_CannotSettoNull_whenFinishAlready                            (SCHMGT_ERROR_BASE + 79)
#define SCHMGT_Status_hasto_beComplete                                      (SCHMGT_ERROR_BASE + 80)
#define SCHMGT_PC_Cannotbe_lessthan_100                                     (SCHMGT_ERROR_BASE + 81)
#define SCHMGT_CannotSetFinish_whenStartNull                                (SCHMGT_ERROR_BASE + 82)
#define SCHMGT_assigned_to_inactive_users                                   (SCHMGT_ERROR_BASE + 83)
#define SCHMGT_schedulemember_to_inactive_users                             (SCHMGT_ERROR_BASE + 84)
#define SCHMGT_Lock_LockedByOther                                           (SCHMGT_ERROR_BASE + 85)
#define SCHMGT_Unlock_LockByOther                                           (SCHMGT_ERROR_BASE + 86)
#define SCHMGT_Delete_OtherThenOrphaned                                     (SCHMGT_ERROR_BASE + 87)
#define SCHMGT_PROXY_TASK_SAME_SCHED                                        (SCHMGT_ERROR_BASE + 88)
#define SCHMGT_TASK_HAS_PROXY                                               (SCHMGT_ERROR_BASE + 89)
#define SCHMGT_Invalid_Argument                                             (SCHMGT_ERROR_BASE + 90)
#define SCHMGT_task_deleted                                                 (SCHMGT_ERROR_BASE + 91)
#define SCHMGT_no_summary_exec_update                                       (SCHMGT_ERROR_BASE + 92)
#define SCHMGT_no_orphaned_exec_update                                      (SCHMGT_ERROR_BASE + 93)
#define SCHMGT_shift_schedule_non_interactive_ERROR                         (SCHMGT_ERROR_BASE + 94)
#define SCHMGT_invalid_property_to_update                                   (SCHMGT_ERROR_BASE + 95)

/** The operation of Scale Schedule has encountered a problem. Please check the following Teamcenter server log for more details: %1$. */
#define SCHMGT_scale_schedule_non_interactive_ERROR                         (SCHMGT_ERROR_BASE + 96)

#define SCHMGT_workflow_template_not_present                                (SCHMGT_ERROR_BASE + 97)
#define SCHMGT_workflow_already_launched                                    (SCHMGT_ERROR_BASE + 98)
#define SCHMGT_workflow_failed_for_summary                                  (SCHMGT_ERROR_BASE + 99)
#define SCHMGT_invalid_conditiond_parameters                                (SCHMGT_ERROR_BASE + 100)
#define SCHMGT_task_status_complete_condition                               (SCHMGT_ERROR_BASE + 101)
#define SCHMGT_CAN_NOT_IMPORT_EXISTING_SCHEDULE                             (SCHMGT_ERROR_BASE + 102)
#define SCHMGT_ORGANIZATION_NOT_IN_SYNC                                     (SCHMGT_ERROR_BASE + 103)
#define SCHMGT_PLMXML_IMPORT_OTHER_TYPE                                     (SCHMGT_ERROR_BASE + 105)
#define SCHMGT_PLMXML_EXPORT_IMPORT_ONLY_SCHEDULE                           (SCHMGT_ERROR_BASE + 106)
#define SCHMGT_cannot_unassign_completed_Task                               (SCHMGT_ERROR_BASE + 107)
#define SCHMGT_cannot_update_null_assignment                                (SCHMGT_ERROR_BASE + 108)
#define SCHMGT_cannot_assign_same_resource                                  (SCHMGT_ERROR_BASE + 109)
#define SCHMGT_invalid_target_objects                                       (SCHMGT_ERROR_BASE + 110)

/** You do not have sufficient permissions to abort tasks. */
#define SCHMGT_abort_permission_denied                                      (SCHMGT_ERROR_BASE + 111)

/** Task has unallocated placeholder assignments (Group, Role, or  Discipline). Please allocate, or delete, these assignments, then manually launch the workflow. */
#define SCHMGT_incorrectly_assigned_task                                    (SCHMGT_ERROR_BASE + 112)

/** The Schedule or Task cannot be deleted because the system is configured to not allow the deletion of Schedules or Tasks when in the &quot;%1$&quot; state. The preferences "SM_PREVENT_UPDATE_STATES" and "SM_PREVENT_DELETE_STATES" specify the Schedule states in which Schedules or Tasks cannot be deleted. */
#define SCHMGT_system_not_configured_for_delete                             (SCHMGT_ERROR_BASE + 113)

/**  System preference error: One of the required system preference is not set. */
#define SCHMGT_required_system_preference_not_set                           (SCHMGT_ERROR_BASE + 114)

/**  The Schedule or Task cannot be updated because the system is configured to not allow the update of Schedules or Tasks when in the "%1$" state. The preference "SM_PREVENT_UPDATE_STATES" specificies those states of the Schedule in which the Schedules or Tasks cannot be updated. */
#define SCHMGT_system_not_configured_for_update                             (SCHMGT_ERROR_BASE + 115)

/**  Task has no privileged user. Please add any user from the Organization application, and launch the workflow again. */
#define SCHMGT_task_has_no_privileged_user                                  (SCHMGT_ERROR_BASE + 116)

/**  The workflow process on task has already been launched, so a privileged user cannot be modified or deleted. */
#define SCHMGT_privileged_user_cannot_be_deleted                            (SCHMGT_ERROR_BASE + 117)

/**  The currently selected Schedule is already aborted. */
#define SCHMGT_schedule_is_already_aborted                                  (SCHMGT_ERROR_BASE + 118)

/**  Complete or closed tasks cannot be aborted. */
#define SCHMGT_complete_closed_task_cannot_be_aborted                       (SCHMGT_ERROR_BASE + 119)

/**  Task once aborted cannot be undone. */
#define SCHMGT_abort_can_not_be_un_aborted                                  (SCHMGT_ERROR_BASE + 120)

/**  Schedule Deliverable cannot be created/updated/deleted because the schedule state is either complete/closed/aborted. */
#define SCHMGT_schedule_deliverable_error_on_prevented_state                (SCHMGT_ERROR_BASE + 121)

/**  ScheduleTask Deliverable cannot be created/updated/deleted because the schedule state is either complete/closed/aborted. */
#define SCHMGT_schedule_task_deliverable_error_on_prevented_state_schedule  (SCHMGT_ERROR_BASE + 122)

/**  ScheduleTask Deliverable cannot be created/updated/deleted because the task state is either complete/closed/aborted. */
#define SCHMGT_schedule_task_deliverable_error_on_prevented_state_task      (SCHMGT_ERROR_BASE + 123)

/**  The schedule cannot be updated because the schedule state is either complete/closed/aborted. */
#define SCHMGT_schedule_update_error_on_prevented_state                     (SCHMGT_ERROR_BASE + 124)

/**  A Schedule Baseline cannot be created/updated/deleted because the schedule state is either complete/closed/aborted. */
#define SCHMGT_schedule_baseline_error_on_prevented_state                   (SCHMGT_ERROR_BASE + 125)

/**  Baseline task cannot be done because the schedule state is either complete/closed/aborted. */
#define SCHMGT_baseline_task_update_error_on_prevented_state_schedule       (SCHMGT_ERROR_BASE + 126)

/**  Baseline task cannot be done because the task state is either complete/closed/aborted. */
#define SCHMGT_baseline_task_update_error_on_prevented_state_task           (SCHMGT_ERROR_BASE + 127)

/**  Proxy task cannot be created because the schedule state is either complete/closed/aborted. */
#define SCHMGT_proxy_task_create_error_on_prevented_state_schedule          (SCHMGT_ERROR_BASE + 128)

/**  Proxy task cannot be created because the task state is either complete/closed/aborted. */
#define SCHMGT_proxy_task_create_error_on_prevented_state_task              (SCHMGT_ERROR_BASE + 129)

/** A task is outside the range of the schedule. */
#define SCHMGT_task_outside_schedule_range                                  (SCHMGT_ERROR_BASE + 130)

/**  The Schedule Task cannot be updated because the task state is either complete/closed/aborted. Refresh the schedule to obtain the latest copy.*/
#define SCHMGT_schedule_task_update_error_on_prevented_state_task           (SCHMGT_ERROR_BASE + 131)

/**  A Schedule Member cannot be created/updated/deleted because the schedule state is either complete/closed/aborted. */
#define SCHMGT_schedule_member_error_on_prevented_state_schedule            (SCHMGT_ERROR_BASE + 132)

/**  Costs cannot be created/modified/deleted because the task state is either complete/closed/aborted. */
#define SCHMGT_cost_update_error_on_prevented_state_schedule                (SCHMGT_ERROR_BASE + 133)

/**  Costs cannot be created/modified/deleted because the task state is either complete/closed/aborted. */
#define SCHMGT_cost_update_error_on_prevented_state_task                    (SCHMGT_ERROR_BASE + 134)

/**  Notifications cannot be created/modified/deleted because the task state is either complete/closed/aborted. */
#define SCHMGT_task_notification_update_error_on_prevented_state_schedule   (SCHMGT_ERROR_BASE + 135)

/**  Notifications cannot be created/modified/deleted because the task state is either complete/closed/aborted. */
#define SCHMGT_task_notification_update_error_on_prevented_state_task       (SCHMGT_ERROR_BASE + 136)

/** The Check-out on Schedule &quot;%1$&quot; was not granted, because it has been locked by the user &quot;%2$&quot; who is currently modifying the Schedule, or has an open deferred session. */
#define SCHMGT_checkout_LockedByOther                                       (SCHMGT_ERROR_BASE + 137)

/** There are no tasks to filter. */
#define SCHMGT_no_tasks_to_filter                                           (SCHMGT_ERROR_BASE + 138)

/** The filter operation has failed because the input task &quot;%1$&quot; is invalid. */
#define SCHMGT_invalid_task_to_filter                                       (SCHMGT_ERROR_BASE + 139)

/**  The workflow process on the task &quot;%1$&quot; has already been launched, so its workflow owner cannot be modified or deleted. */
#define SCHMGT_workflow_owner_cannot_be_deleted                             (SCHMGT_ERROR_BASE + 140)

/**  The privileged user assigned to the Schedule Task "%1$" is invalid. Please assign either a user or a resource pool of any type. */
#define SCHMGT_invalid_privileged_user                                      (SCHMGT_ERROR_BASE + 141)

/** The Schedule &quot;%1$&quot; has been aborted. No further action is allowed on this schedule. */
#define SCHMGT_schedule_aborted_can_not_be_un_aborted                       (SCHMGT_ERROR_BASE + 142)

/**  The Task &quot;%1$&quot; has been aborted. No further action is allowed on this task. */
#define SCHMGT_task_aborted_can_not_be_un_aborted                           (SCHMGT_ERROR_BASE + 143)

/**  Resource assignments cannot be added to or removed from the tasks "%1$", because the workflow has already been triggered. Only the resource load of the existing assignment can be changed. */
#define SCHMGT_resource_can_not_be_added_deleted                            (SCHMGT_ERROR_BASE + 144)

/** The provided value for the member privilege is invalid. Valid values are 0 (observer), 1 (participant) and 2 (coordinator). */
#define SCHMGT_invalid_member_privilege                                     (SCHMGT_ERROR_BASE + 145)

/** The claim operation has failed because the assignment is invalid. Please refresh the schedule task folder and try again. */
#define SCHMGT_invalid_assignment_to_claim                                  (SCHMGT_ERROR_BASE + 146)

/** The schedule process history audit records for the selected object could not be retrieved. Please refer to the syslog file for more details: %1$. */
#define SCHMGT_fail_to_get_schedule_audit_records                           (SCHMGT_ERROR_BASE + 147)

/** Resource assignments cannot be added to a Schedule Summary Task. */
#define SCHMGT_cannot_assign_schedule_summary                               (SCHMGT_ERROR_BASE + 148)

/** The provided Task Dependency type is invalid. Valid Task Dependency types are: 0(Finish to Start), 1(Finish to Finish), 2(Start to Start), and 3(Start to Finish). */
#define SCHMGT_invalid_dependency_type                                      (SCHMGT_ERROR_BASE + 149)

/** Task Dependencies can only be created between two Schedule Tasks or between a Schedule Task and a Proxy Task. */
#define SCHMGT_dependency_required_task_types                               (SCHMGT_ERROR_BASE + 150)

/** Task Dependencies can not be created between two Proxy Tasks. */
#define SCHMGT_dependency_invalid_proxy_tasks                               (SCHMGT_ERROR_BASE + 151)

/** The factor to scale a Schedule must be greater than zero. */
#define SCHMGT_valid_scale_factor                                           (SCHMGT_ERROR_BASE + 152)

/** Cannot scale the Schedule since it contains Schedule Tasks that are already started. */
#define SCHMGT_cannot_scale_started_tasks                                   (SCHMGT_ERROR_BASE + 153)

/**  Task Assignments can only be claimed when the Schedule Tasks are assigned to a Resource Pool with "Any" option. The "Any" option specifies that any member of the Resource Pool can claim the Schedule Task. */
#define SCHMGT_cannot_claim_non_pool                                        (SCHMGT_ERROR_BASE + 154)

/**  Task Assignments can only be claimed when the user claiming the Schedule Task is a member of the Resource Pool. */
#define SCHMGT_cannot_claim_non_member                                      (SCHMGT_ERROR_BASE + 155)

/** "%1$" cannot be set as the active baseline, because it is not a Schedule baseline. */
#define SCHMGT_invalid_baseline_schedule                                    (SCHMGT_ERROR_BASE + 156)

/** The Schedule baseline "%1$" cannot be set as an active baseline, because it is not a baseline of the Schedule %2$. */
#define SCHMGT_different_baseline_schedule                                  (SCHMGT_ERROR_BASE + 157)

/** The planning or execution data cannot be updated, because the Schedule "%1$" is locked by the user "%2$". */
#define SCHMGT_locked_by_another_user                                       (SCHMGT_ERROR_BASE + 158)
/** The Schedule Task "%1$" cannot be checked-out, because Schedule Tasks of types Schedule Summary Task, Summary Task and Phase Task cannot be checked-out. */
#define SCHMGT_invalid_checkout_objects                                     (SCHMGT_ERROR_BASE + 159)

/** The Schedule Task "%1$" cannot be modified, because the logged-in user is neither assigned to the Task nor is the coordinator of the Schedule. */
#define SCHMGT_user_not_assigned_to_update_task                             (SCHMGT_ERROR_BASE + 160)

/** The Schedule "%1$" cannot be modified by the current user, because it does not belong to its list of coordinators. */
#define SCHMGT_user_not_coordinator_to_update_task                          (SCHMGT_ERROR_BASE + 161)

/** The Schedule Task "%1$" cannot be updated, because it is in the "%2$" state. The preference "SM_PREVENT_TASK_START_UPDATE_STATES" specifies the states in which Schedule Tasks cannot be updated. */
#define SCHMGT_task_dates_not_configured_for_update                         (SCHMGT_ERROR_BASE + 162)

/** The Sub-Schedule "%1$" cannot be detached from the master schedule, because it is in the "%2$" state. The preference "SM_ALLOW_INPROCESS_REMOVAL_OF_SUB_SCHEDULE" specifies the states in which Sub-Schedules cannot be detached. */
#define SCHMGT_sub_schedule_cannot_be_detached                              (SCHMGT_ERROR_BASE + 163)

/** The following properties of the Master or Sub-schedule/Template "%1$" cannot be modified: "Is Schedule Public", "Is Schedule Template" and "Published". */
#define SCHMGT_invalid_master_sch_property_to_update                        (SCHMGT_ERROR_BASE + 164)

/** The Schedule Task "%1$" of type Schedule Summary Task, Summary Task, or Phase Task, cannot be modified explicitly. */
#define SCHMGT_invalid_task_to_modify_explicitly                            (SCHMGT_ERROR_BASE + 165)

/** The user "%1$" does not satisfy the required assignment criteria. Please verify the criteria defined on the Schedule Task "%2$" using the "Task Assignment" dialog. */
#define SCHMGT_fail_assignment_criteria                                     (SCHMGT_ERROR_BASE + 166)

/**  The user "%1$" does not belong to the discipline "%2$.*/
#define SCHMGT_person_reassign_validation_error                             (SCHMGT_ERROR_BASE + 167)

/**  The filter operation has failed because the input Discipline, Group/Role or Qualification is invalid. Please verify the criteria being passed to the filter operation.*/
#define SCHMGT_filter_users_invalid_data                                    (SCHMGT_ERROR_BASE + 168)

/**  The Schedule date range "%1$ - %2$" must be at least 24 hours long.*/
#define SCHMGT_schedule_invalid_date_range                                  (SCHMGT_ERROR_BASE + 169)

/**  Workflow cannot be launched on Schedule Task "%1$", because it is in the "%2$" state.*/
#define SCHMGT_workflow_on_closed_state_tasks                               (SCHMGT_ERROR_BASE + 170)

/**  The cost value cannot be modified, because the user "%1$" is inactive. */
#define SCHMGT_costvalue_for_inactive_user                                  (SCHMGT_ERROR_BASE + 171)

/**  The resource load cannot be modified, because the user "%1$" is inactive. */
#define SCHMGT_resourceload_for_inactive_user                               (SCHMGT_ERROR_BASE + 172)

/**  The user "%1$" cannot be added as privileged user or workflow process owner, because the user is inactive. */
#define SCHMGT_privileged_user_for_inactive_user                            (SCHMGT_ERROR_BASE + 173)

/**  The schedule member cannot be modified, because the user "%1$" is inactive. */
#define SCHMGT_schedulemember_update_for_inactive_user                      (SCHMGT_ERROR_BASE + 174)

/** The object "%1$" of type "%2$" cannot be deleted, because it is referenced by the Events Table object. */
#define SCHMGT_is_referenced_by_events_table                                (SCHMGT_ERROR_BASE + 301)

/** The object "%1$" of type "%2$" cannot be unchecked-out, because it is checked-out by the user "%3$". */
#define SCHMGT_undo_checkout_is_not_supported                               (SCHMGT_ERROR_BASE + 302)

/** The object "%1$" of type "%2$" cannot be checked-in, because  it is checked-out by the user "%3$". */
#define SCHMGT_checkin_is_not_supported                                     (SCHMGT_ERROR_BASE + 303)

/** A dependency between the Task "%1$" and "%2$" already exists. */
#define SCHMGT_dependency_already_exists                                    (SCHMGT_ERROR_BASE + 304)

/** The preference "SiteTimeZone" is required to be set for the Schedule Manager application. Please contact your system administrator to properly configure this preference.*/ 
#define SCHMGT_SiteTimeZone_preference_is_not_set_or_invalid                (SCHMGT_ERROR_BASE + 305)

/** The Schedule finish date "%1$" cannot be before the Schedule start date "%2$". */
#define SCHMGT_finish_date_before_start_date            (SCHMGT_ERROR_BASE + 306)

/** The given time zone value "%1$" is invalid. Please refer "Timezone" LOV for valid values.*/
#define SCHMGT_time_zone_is_invalid                                         (SCHMGT_ERROR_BASE + 307)

/** Please select a valid value for the property "%1$" and try again.*/
#define SCHMGT_invalid_schedule_task_property_value                         (SCHMGT_ERROR_BASE + 308)

/** An unpublished or baseline schedule cannot be inserted as a sub-schedule.*/
#define SCHMGT_cannot_insert_unpublished_sub_schedule                       (SCHMGT_ERROR_BASE + 309)

/** Only a schedule template can be inserted into a template master schedule.*/
#define SCHMGT_cannot_insert_non_template_sub_schedule_into_template_master_schedule     (SCHMGT_ERROR_BASE + 310)

/** A schedule template cannot be inserted into a master schedule that is not a template.*/
#define SCHMGT_cannot_insert_template_sub_schedule_into_non_template_master_schedule     (SCHMGT_ERROR_BASE + 311)

/** A dependency cannot be created between a task from a template schedule and a task from a schedule that is not a template.*/
#define SCHMGT_cannot_create_dependency_between_template_and_non_template_schedule       (SCHMGT_ERROR_BASE + 312)

/** The instance of type "%1$" is not supported for this deliverable.*/
#define SCHMGT_invalid_task_deliverable_type                                             (SCHMGT_ERROR_BASE + 313)

/** The selected operation cannot be performed because the Schedule "%1$" is locked by "%2$".*/
#define SCHMGT_invalid_operation_on_schedule_locked_by_user                              (SCHMGT_ERROR_BASE + 314)

/** The new Schedule cannot be created because the source or template schedule contains inactive users as schedule members.*/
#define SCHMGT_cannot_create_schedule_from_template_with_inactive_users                  (SCHMGT_ERROR_BASE + 315)
/** The workflow template "%1$" does not exist.*/
#define SCHMGT_workflow_template_not_exists                                              (SCHMGT_ERROR_BASE + 316)

/**
@defgroup SRM_INTEGRATION_ERRORS Errors related to Supplier Relationship Management Integration functionality
@ingroup SCHMGT_ERRORS
@{
*/

/** Supplier Relationship Management error base */
#define EMH_SCHMGT_SRM_error_base                                           (EMH_SCHMGT_error_base + 500)

/**
External Recipients and Internal users (Organization/Project Teams/Disciplines) both cannot be assigned to a task. Assign either External Recipients or Internal users.
*/
#define SCHMGT_SRM_both_external_internal_resources                         (EMH_SCHMGT_SRM_error_base + 1)

/**
External Recipients from different Supplier companies cannot be assigned to a task.
*/
#define SCHMGT_SRM_different_company                                        (EMH_SCHMGT_SRM_error_base + 2)
/** @} */

/** @} */
#endif
