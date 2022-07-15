/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa project management services

    
*/

/** @if HISTORY_SECTION
====================================================================================================
22-May-2006  Tom Nguyen         Error codes for soaproject management
$HISTORY$
==================================================================================================
@endif */

#ifndef SOAPROJECTMANAGEMENT_ERRORS_H
#define SOAPROJECTMANAGEMENT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAPROJECTMANAGEMENT_ERRORS TCWS Errors
    @ingroup SOAPROJECTMANAGEMENT
    @{
*/

/* Not a valid scheduling object */
#define SOAPROJECTMANAGEMENT_not_scheduling_object_to_delete (EMH_SOAPROJECTMANAGEMENT_error_base + 0)

#define SOAPROJECTMANAGEMENT_could_not_delete_object         (EMH_SOAPROJECTMANAGEMENT_error_base + 1)

/* Schedule of baseline and task does not match */
#define SOAPROJECTMANAGEMENT_schedule_not_match              (EMH_SOAPROJECTMANAGEMENT_error_base + 2)

#define SOAPROJECTMANAGEMENT_invalid_schedule_to_load        (EMH_SOAPROJECTMANAGEMENT_error_base + 3)

#define SOAPROJECTMANAGEMENT_error_loading_schedule          (EMH_SOAPROJECTMANAGEMENT_error_base + 4)

#define SOAPROJECTMANAGEMENT_error_copying_schedule          (EMH_SOAPROJECTMANAGEMENT_error_base + 5)

#define SOAPROJECTMANAGEMENT_invalid_schedule_to_modify      (EMH_SOAPROJECTMANAGEMENT_error_base + 6)

#define SOAPROJECTMANAGEMENT_error_modifying_schedule        (EMH_SOAPROJECTMANAGEMENT_error_base + 7)

#define SOAPROJECTMANAGEMENT_error_loading_assignment        (EMH_SOAPROJECTMANAGEMENT_error_base + 8)

#define SOAPROJECTMANAGEMENT_invalid_resource_to_load        (EMH_SOAPROJECTMANAGEMENT_error_base + 9)

#define SOAPROJECTMANAGEMENT_required_site_preference_not_set (EMH_SOAPROJECTMANAGEMENT_error_base + 10)

#define SOAPROJECTMANAGEMENT_error_bad_parameter              (EMH_SOAPROJECTMANAGEMENT_error_base + 11)

#define SOAPROJECTMANAGEMENT_soap_error                       (EMH_SOAPROJECTMANAGEMENT_error_base + 12)

#define SOAPROJECTMANAGEMENT_soap_tcp_error                   (EMH_SOAPROJECTMANAGEMENT_error_base + 13)

#define SOAPROJECTMANAGEMENT_error_translation_failed         (EMH_SOAPROJECTMANAGEMENT_error_base + 14)

#define XML_DATA_SERIALIZATION_ERROR                          (EMH_SOAPROJECTMANAGEMENT_error_base + 75)

#define XML_DATA_DESERIALIZATION_ERROR                          (EMH_SOAPROJECTMANAGEMENT_error_base + 76)

#define XML_DATA_INCOMPLETE_DOCUMENT                          (EMH_SOAPROJECTMANAGEMENT_error_base + 77)

//#define                           (EMH_SOAPROJECTMANAGEMENT_error_base + 78)

#define FMS_INVALID_TICKET                                      (EMH_SOAPROJECTMANAGEMENT_error_base + 79)

#define DATA_TRANSFORM_ERR_TRANS_TASK                          (EMH_SOAPROJECTMANAGEMENT_error_base + 80)

#define XDATA_TRANSFORM_ERR_TRANS_SCH                          (EMH_SOAPROJECTMANAGEMENT_error_base + 81)

#define DATA_TRANSFORM_ERR_TRANS_DEP                          (EMH_SOAPROJECTMANAGEMENT_error_base + 82)

#define DATA_TRANSFORM_ERR_TRANS_ASSIGN                          (EMH_SOAPROJECTMANAGEMENT_error_base + 83)

#define DATA_TRANSFORM_ERR_TRANS_CAL                          (EMH_SOAPROJECTMANAGEMENT_error_base + 84)

#define DATA_TRANSFORM_ERR_TRANS_CAL_EVENT                      (EMH_SOAPROJECTMANAGEMENT_error_base + 85)

#define DATA_TRANSFORM_ERR_TRANS_RANGE_EVENT                  (EMH_SOAPROJECTMANAGEMENT_error_base + 86)

#define DATA_TRANSFORM_ERR_TRANS_CV                           (EMH_SOAPROJECTMANAGEMENT_error_base + 87)

#define DATA_TRANSFORM_ERR_TRANS_FC                              (EMH_SOAPROJECTMANAGEMENT_error_base + 88)

#define DATA_TRANSFORM_ERR_TRANS_BR                              (EMH_SOAPROJECTMANAGEMENT_error_base + 89)

#define DATA_LOOKUP_ERR_FIND_SCHEDULE                          (EMH_SOAPROJECTMANAGEMENT_error_base + 90)

#define DATA_LOOKUP_ERR_FIND_PROGRAM                          (EMH_SOAPROJECTMANAGEMENT_error_base + 91)

#define DATA_LOOKUP_ERR_FIND_TASK                              (EMH_SOAPROJECTMANAGEMENT_error_base + 92)

#define DDATA_LOOKUP_ERR_FIND_ASSIGNMENTS                      (EMH_SOAPROJECTMANAGEMENT_error_base + 93)

#define SERVER_INTERFACE_ERR_TRANSACTION                      (EMH_SOAPROJECTMANAGEMENT_error_base + 94)

#define MULT_OPER_ERR                                          (EMH_SOAPROJECTMANAGEMENT_error_base + 95)

#define VALIDATOR_TASK_END_BEFORE_START                          (EMH_SOAPROJECTMANAGEMENT_error_base + 96)

#define VALIDATOR_TASK_START_BEFORE_SCH_START                  (EMH_SOAPROJECTMANAGEMENT_error_base + 97)

#define VALIDATOR_TASK_END_AFTER_SCH_END                      (EMH_SOAPROJECTMANAGEMENT_error_base + 98)

#define VALIDATOR_TASK_ACT_FINISH_WITH_NO_ACT_START              (EMH_SOAPROJECTMANAGEMENT_error_base + 99)

#define VALIDATOR_TASK_ACT_START_AFTER_ACT_FINISH              (EMH_SOAPROJECTMANAGEMENT_error_base + 100)

#define VALIDATOR_GENERIC_ERROR                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 101)

#define VALIDATOR_TASK_CANT_MOVE_WITH_FIXED_CONSTRAINT          (EMH_SOAPROJECTMANAGEMENT_error_base + 102)

#define VALIDATOR_TASK_OUTSIDE_OF_SCHEDULE_BOUNDARIES          (EMH_SOAPROJECTMANAGEMENT_error_base + 103)

#define VALIDATOR_TASK_START_DATE_VIOLATES_DEPENDENCY_OR_CONSTRAINT      (EMH_SOAPROJECTMANAGEMENT_error_base + 104)

#define VALIDATOR_UPDATE_PERCENT_COMPLETE                      (EMH_SOAPROJECTMANAGEMENT_error_base + 105)

#define VALIDATOR_CIRCULAR_DEPENDENCY                          (EMH_SOAPROJECTMANAGEMENT_error_base + 106)

#define VALIDATOR_CIRCULAR_DEPENDENCY_BETWEEN_PARENT_CHILD      (EMH_SOAPROJECTMANAGEMENT_error_base + 107)

#define VALIDATOR_CANT_CREATE_DEPENDENCY_TO_SAME_TASK          (EMH_SOAPROJECTMANAGEMENT_error_base + 108)

#define SCH_FINISH_BEFORE_START                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 109)

#define VALIDATOR_SCHEDULE_DATE_IS_OUTSIDE_MASTER_SCHEDULE_BOUNDARIES       (EMH_SOAPROJECTMANAGEMENT_error_base + 110)

#define PG_NO_SUB                                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 111)

#define T_PMC_SUM_SCHED_UPD                                          (EMH_SOAPROJECTMANAGEMENT_error_base + 112)

#define T_PMC_SUM_EXEC_UPD                                          (EMH_SOAPROJECTMANAGEMENT_error_base + 113)

#define T_PMC_NAME_LENGTH_EXCEED                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 114)

#define T_PMC_DESC_LENGTH_EXCEED                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 115)

#define D_PMC_CHANGE_PHASE                                          (EMH_SOAPROJECTMANAGEMENT_error_base + 116)

#define S_PMC_NAME_LENGTH_EXCEED                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 117)

#define S_PMC_DESC_LENGTH_EXCEED                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 118)

#define S_PMC_SUM_SCHED_TEMP_UPD                                  (EMH_SOAPROJECTMANAGEMENT_error_base + 119)

#define S_PMC_SUM_SCHED_PUB_UPD                                      (EMH_SOAPROJECTMANAGEMENT_error_base + 120)

#define SS_PMC_SUM_SCHED_PUBLISH_UPD                              (EMH_SOAPROJECTMANAGEMENT_error_base + 121)

#define START_DATE_NULL                                              (EMH_SOAPROJECTMANAGEMENT_error_base + 122)

#define FINISH_DATE_NULL                                          (EMH_SOAPROJECTMANAGEMENT_error_base + 123)

#define S_CANNOT_UPDATE_OBJECTS_IN_DIFFERENT_SCHEDULES              (EMH_SOAPROJECTMANAGEMENT_error_base + 124)

#define S_CANNOT_DELETE_OBJECTS_IN_DIFFERENT_SCHEDULES              (EMH_SOAPROJECTMANAGEMENT_error_base + 125)

#define REQUEST_CONTAINER_OPERATION_IS_UNDEFINED                    (EMH_SOAPROJECTMANAGEMENT_error_base + 126)
#define REQUEST_CONTAINER_SCHEDULE_UID_IS_UNDEFINED                 (EMH_SOAPROJECTMANAGEMENT_error_base + 127)
#define REQUEST_CONTAINER_MISSING_ATTRIBUTE_VALUE                   (EMH_SOAPROJECTMANAGEMENT_error_base + 128)
#define REQUEST_CONTAINER_IS_UNDEFINED                              (EMH_SOAPROJECTMANAGEMENT_error_base + 129)
#define VALIDATE_IGNORED_NEW_SAME_AS_OLD_VALUE                      (EMH_SOAPROJECTMANAGEMENT_error_base + 130)
#define RESPONSE_NOT_GENERATED                                      (EMH_SOAPROJECTMANAGEMENT_error_base + 131)
#define SOAPROJECTMANAGEMENT_error_no_exec_form                     (EMH_SOAPROJECTMANAGEMENT_error_base + 132)

#define REQUEST_SERVICE_TYPE_DATA_CORUPTION                         (EMH_SOAPROJECTMANAGEMENT_error_base + 133)
#define SCALE_INVALID_FACTOR                                        (EMH_SOAPROJECTMANAGEMENT_error_base + 134)
#define SCALE_CHECK_NOT_STARTED                                     (EMH_SOAPROJECTMANAGEMENT_error_base + 135)
#define SOA_PM_DEP_INVALID_TYPE                                     (EMH_SOAPROJECTMANAGEMENT_error_base + 136)
#define SOA_PM_DEP_REQUIRE_TASK_OR_PROXY                            (EMH_SOAPROJECTMANAGEMENT_error_base + 137)
#define SOA_PM_DEP_NO_PROXY_TO_PROXY                                (EMH_SOAPROJECTMANAGEMENT_error_base + 138)

#define SOA_CANT_ASSIGN_SCHED_SUMMARY                               (EMH_SOAPROJECTMANAGEMENT_error_base + 139)
#define SOA_CANT_CHANGE_ASSIGN_ON_WF                                (EMH_SOAPROJECTMANAGEMENT_error_base + 140)

/**  Assignments can only be claimed when the tasks are assigned to a resource pool with "Any" option. The "Any" option specifies that any member of the resource pool can claim the task. */
#define SOA_cannot_claim_non_pool                                   (EMH_SOAPROJECTMANAGEMENT_error_base + 141)

/**  Assignments can only be claimed when the user claiming the task is a member of the Resource Pool. */
#define SOA_cannot_claim_non_member                                 (EMH_SOAPROJECTMANAGEMENT_error_base + 142)

/** The Schedule cannot be modified because it is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_modify                      (EMH_SOAPROJECTMANAGEMENT_error_base + 143)
/** The ScheduleTask cannot be added because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_add_task                    (EMH_SOAPROJECTMANAGEMENT_error_base + 144)
/** The Resource assignment cannot be added because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_add_resource                (EMH_SOAPROJECTMANAGEMENT_error_base + 145)
/** The Dependency cannot be added because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_add_dependency              (EMH_SOAPROJECTMANAGEMENT_error_base + 146)
/** The ScheduleTask cannot be modified because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_modify_task                 (EMH_SOAPROJECTMANAGEMENT_error_base + 147)
/** The Dependency cannot be modified because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_modify_resource_assignmnet  (EMH_SOAPROJECTMANAGEMENT_error_base + 148) 
/** The Dependency cannot be modified because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_modify_dependency           (EMH_SOAPROJECTMANAGEMENT_error_base + 149)
/** The ScheduleTask cannot be deleted because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_delete_task                 (EMH_SOAPROJECTMANAGEMENT_error_base + 150) 
/** The Resource assignment cannot be removed because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_remove_resoursce_assignment (EMH_SOAPROJECTMANAGEMENT_error_base + 151)
/** The Dependency cannot be deleted because schedule is in the following state. */
#define VALIDATOR_schedule_preservation_cannot_delete_dependency           (EMH_SOAPROJECTMANAGEMENT_error_base + 152)
/** The Summary task cannot be modified because it is in the following state. */
#define VALIDATOR_summary_preservation_cannot_modify                       (EMH_SOAPROJECTMANAGEMENT_error_base + 153) 
/** The ScheduleTask cannot be added because summary task is in the following state. */
#define VALIDATOR_summary_preservation_cannot_add_task                     (EMH_SOAPROJECTMANAGEMENT_error_base + 154) 
/** The ScheduleTask cannot be deleted because summary task is in the following state. */
#define VALIDATOR_summary_preservation_cannot_delete_task                  (EMH_SOAPROJECTMANAGEMENT_error_base + 155)
/** The ScheduleTask cannot be modified because it is in the following state. */
#define VALIDATOR_task_preservation_cannot_modify                          (EMH_SOAPROJECTMANAGEMENT_error_base + 156)
/** The ScheduleTask cannot be deleted because it is in the following state. */
#define VALIDATOR_task_preservation_cannot_delete                          (EMH_SOAPROJECTMANAGEMENT_error_base + 157)
/** The Resource assignment cannot be added because task is in the following state. */
#define VALIDATOR_task_preservation_cannot_add_resource_assignment         (EMH_SOAPROJECTMANAGEMENT_error_base + 158)
/** The Resource assignment cannot be modified because task is in the following state. */
#define VALIDATOR_task_preservation_cannot_modify_resoursce_assignment     (EMH_SOAPROJECTMANAGEMENT_error_base + 159)
/** The Resource assignment cannot be removed because task is in the following state. */
#define VALIDATOR_task_preservation_cannot_remove_resoursce_assignment     (EMH_SOAPROJECTMANAGEMENT_error_base + 160)
/** The Dependency cannot be added because dependent and predecessor tasks are in the following states. */
#define VALIDATOR_tasks_preservation_cannot_add_dependency                 (EMH_SOAPROJECTMANAGEMENT_error_base + 161)
/** The Dependency cannot be modified because dependent and predecessor tasks are in the following states. */
#define VALIDATOR_tasks_preservation_cannot_modify_dependency              (EMH_SOAPROJECTMANAGEMENT_error_base + 162) 
/** The Dependency cannot be deleted because dependent and predecessor tasks are in the following states. */
#define VALIDATOR_tasks_preservation_cannot_delete_dependency              (EMH_SOAPROJECTMANAGEMENT_error_base + 163)
/** Start date of the scheduletask cannot be modified because it is in the following state. */
#define VALIDATOR_start_date_preservation_cannot_modify                    (EMH_SOAPROJECTMANAGEMENT_error_base + 164) 
/** Execution data of the scheduletask cannot be modified because it is in the following state. */
#define VALIDATOR_execution_data_preservation_cannot_modify                (EMH_SOAPROJECTMANAGEMENT_error_base + 165)
/** The proposed change would affect the Task "%1$", which is not in the current schedule. */
#define VALIDATOR_proxy_cannot_move                                        (EMH_SOAPROJECTMANAGEMENT_error_base + 166) 

/** @} */

#endif

