/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by
    clients of the Enterprise Process Modelling classes (EPM).
*/

/*  */

#ifndef EPM_H
#define EPM_H

#include <unidefs.h>

#include <epm/cr.h>
#include <epm/epm_errors.h>
#include <tc/tc_arguments.h>
#include <tc/tc_startup.h>
#include <tccore/tctype.h>
#include <tccore/workspaceobject.h>
#include <common/tc_deprecation_macros.h>

#include <epm/libepm_exports.h>


/**
    @defgroup EPM Enterprise Process Modeling (EPM)

    The Enterprise Process Management (EPM) functions provide you with the capability to
    write action and rule handler code. You must include the header file epm.h in your source code.

    @warning EPM functions have been specially developed for custom EPM applications and procedures.
    Using these functions with other workflow applications (e.g., CR, CM), procedures, and tasks
    can result in unpredictable behavior and could cause loss of data.

    @{
*/

#define EPM_select_signoff_team_task     "select-signoff-team"            /**< Select signoff team task */
#define EPM_perform_signoffs_task        "perform-signoffs"                /**< Perform signoffs task */

/** Set the size for person name (userid).
<br/>In the database, the person name contains up to 128 characters, the user name/id up to 32 characters,and 3 more characters for '(', ')' and ' '.
<br/>The total is 128 + 32 + 3 = 163 characters, which are set for the user size. */
#define EPM_user_size_c                  163                           

/**
    Decisions that can be set by the reviewers while performing the signoff
*/
typedef enum EPM_signoff_decision_e {
             EPM_no_decision         = 0,        /**< No decision */
             EPM_approve_decision    = 'Y',        /**< Approve decision */
             EPM_reject_decision     = 'N'        /**< Reject decision */
} EPM_signoff_decision_t;


#define EPM_comment2_size_c               4000    /**< Length of the comments */

/**
    States of the tasks <br/>
    For suspended state the value 128 mentioned below is ORed with the value of the current state
    when the task is suspended.
    This is done to retain the original state value of the task before it was suspended. <br/>
    This enables the task to transition to its original state value when resumed. <br/> 
    The value 128 and above should be used to retrieve tasks that are in suspended state. 
*/
typedef enum EPM_state_e
{
    EPM_unassigned       = (1 << 0)  /* 1 */    /**< Unassigned task state */
   ,EPM_pending          = (1 << 1)  /* 2 */    /**< Pending task state */
   ,EPM_started          = (1 << 2)  /* 4 */    /**< Started task state */
   ,EPM_completed        = (1 << 3)  /* 8 */    /**< Completed task state */
   ,EPM_skipped          = (1 << 4)  /* 16 */    /**< Skipped task state */
   ,EPM_aborted          = (1 << 5)  /* 32 */    /**< Aborted task state */
   ,EPM_failed           = (1 << 6)  /* 64 */    /**< Failed task state */
   ,EPM_suspended        = (1 << 7)  /* 128 */    /**< Suspended task state */
} EPM_state_t;

/**
    Type of schedule task attached to workflow,
    defines values for Fnd0ScheduleCategory property on EPMTask
*/
typedef enum EPM_schedule_category_e
{
    EPM_NO_SCHEDULE,            /**< No schedule task attached to workflow */
    EPM_LOCAL_SCHEDULE,            /**< Schedule task attached to workflow is local */
    EPM_REMOTE_SCHEDULE_PROXY    /**< Schedule task attached to workflow is a remote proxy link */
} EPM_schedule_category_t;


/**
    Actions on the task
*/
#define EPM_assign_action               1        /**< Assign action */
#define EPM_start_action                2        /**< Start action */
#define EPM_complete_action             4        /**< Complete action */
#define EPM_skip_action                 5        /**< Skip action */
#define EPM_suspend_action              6        /**< Suspend action */
#define EPM_resume_action               7        /**< Resume action */
#define EPM_undo_action                 8        /**< Undo action */
#define EPM_abort_action                9        /**< Abort action */
#define EPM_fail_action                 10        /**< Fail action */

#define EPM_perform_action              100        /**< Perform action */
#define EPM_add_attachment_action       101        /**< Add attachment to a task */
#define EPM_remove_attachment_action    102        /**< Remove attachment of a task */
#define EPM_approve_action              104        /**< Approve action */
#define EPM_reject_action               105        /**< Reject action */
#define EPM_promote_action              106        /**< Promote action */
#define EPM_demote_action               107        /**< Demote action */
#define EPM_refuse_action               108        /**< Refuse action */
#define EPM_assign_approver_action      109        /**< Assign approver to a task */
#define EPM_notify_action               110        /**< Notify action */

#define EPM_start_on_complete_action     EPM_start_action        /**< Start action */
#define EPM_complete_on_complete_action  EPM_complete_action    /**< Complete action */
#define EPM_start_on_fail_action         EPM_fail_action        /**< Fail action */
#define EPM_restart_on_complete_action   200                    /**< Restart on complete action */
#define EPM_restart_on_fail_action       201                    /**< Restart on fail action */
#define EPM_start_on_start_action        202                    /**< Start on start action */
#define EPM_claim_action                 203                    /**< Claim action */


/** Actions from 1000-32000 are user defined */
#define EPM_user_action                 1000

typedef int EPM_action_t;
/** @} */

/**
    @name Attachment Types
    @{
*/
#define EPM_target_attachment               1        /**< Target attachment type */
#define EPM_reference_attachment            3        /**< Reference attachment type */
#define EPM_signoff_attachment              4        /**< Signoff attachment type */
#define EPM_release_status_attachment       5        /**< Release Status attachment type */
#define EPM_comment_attachment              6        /**< Comment attachment type */
#define EPM_instruction_attachment          7        /**< Instruction attachment type */
#define EPM_interprocess_task_attachment    8        /**< Interprocess task attachment type */
#define EPM_schedule_task_attachment        9        /**< Schedule task attachment type */
#define EPM_replica_target_attachment       10       /**< Replica Proposed target attachment type */
/**
    Attachment types used as handler argument values
*/
#define EPM_ATT_TARGET "target"                            /**< Target attachment */
#define EPM_ATT_REFERENCE "reference"                      /**< Reference attachment */
#define EPM_ATT_PROCESS "process"                          /**< Process attachment */
#define EPM_ATT_SIGNOFF "signoff"                          /**< Signoff attachment */
#define EPM_ATT_COMMENT "comment"                          /**< Comment attachment */
#define EPM_ATT_INSTRUCTION "instruction"                  /**< Instruction attachment */
#define EPM_ATT_INTERPROCESS_TASK "interprocess_task"      /**< Interprocess task attachment */
#define EPM_ATT_SCHEDULE_TASK "schedule_task"              /**< Schedule task attachment */
#define EPM_ATT_BOTH "both"                                /**< Target and Reference attachments */
#define EPM_ATT_ALL "all"                                  /**< All attachments */

/** Attachment Types from 1000-32000 are user defined */
#define EPM_user_attachment             1000
/** @} */

/** Maximum template name length */
#define EPM_max_template_name_length    81        /**< Size of the template name */


/** Actions from Assignment List **/
#define EPM_Perform                 0   /**< Perform action */
#define EPM_Review                  1   /**< Review action */
#define EPM_Acknowledge             2   /**< Acknowledge action */
#define EPM_Notify                  3   /**< Notify action */
#define EPM_Required_Review         4   /**< Required Review action */
#define EPM_Required_Acknowledge    5   /**< Required Acknowledge action */

typedef enum EPM_path_type_e{
    EPM_success_path_type,                /**< Success path */
    EPM_failure_path_type,                /**< Failure path */
    EPM_restart_success_path_type,        /**< Restart success path */
    EPM_refail_failure_path_type        /**< Refail failure path */
} EPM_path_type_t;

/**
<table border="1">
<tr><td><b>Result setting</b></td><td colspan="6"><b>Tasks that use setting</b></td></tr>
<tr><td>EPM_RESULT_Unset</td>               <td>Do</td>  <td>Review/PSO/Route/Ack</td>  <td>EPMTask</td>  <td>Cond (Auto/Manual)</td>  <td>SST</td>  <td>Validate</td></tr>
<tr><td>EPM_RESULT_Completed</td>           <td>Do</td>  <td></td>                      <td>EPMTask</td>  <td></td>                    <td>SST</td>  <td></td></tr>
<tr><td>EPM_RESULT_Approved</td>            <td></td>    <td>Review/PSO/Route/Ack</td>  <td></td>         <td></td>                    <td></td>     <td></td></tr>
<tr><td>EPM_RESULT_Rejected</td>            <td></td>    <td>Review/PSO/Route/Ack</td>  <td></td>         <td></td>                    <td></td>     <td></td></tr>
<tr><td>EPM_RESULT_Unable_to_complete</td>  <td>Do</td>  <td></td>                      <td>EPMTask</td>  <td>Cond (Manual)</td>       <td></td>     <td></td></tr>
<tr><td>EPM_RESULT_True</td>                <td></td>    <td></td>                      <td></td>         <td>Cond (Auto/Manual)</td>  <td></td>     <td></td></tr>
<tr><td>EPM_RESULT_False</td>               <td></td>    <td></td>                      <td></td>         <td>Cond (Auto/Manual)</td>  <td></td>     <td></td></tr>
<tr><td>EPM_RESULT_No_error</td>            <td></td>    <td></td>                      <td></td>         <td></td>                    <td></td>     <td>Validate</td></tr>
</table>
*/

/**
    Task results
*/
#define EPM_RESULT_Unset "Unset"                                /**< Unset */
#define EPM_RESULT_Completed "Completed"                        /**< Completed */
#define EPM_RESULT_Approved "Approved"                            /**< Approved */
#define EPM_RESULT_Rejected "Rejected"                            /**< Rejected */
#define EPM_RESULT_Unable_to_complete "Unable_to_complete"        /**< Unable to complete */
#define EPM_RESULT_True "True"                                    /**< True */
#define EPM_RESULT_False "False"                                /**< False */
#define EPM_RESULT_No_error "No_error"                            /**< No error */

#define EPM_comment_size_c               4000

typedef struct EPM_action_message_s{
    tag_t                 task;             /**< Task on which action was triggered */
    EPM_action_t          action;           /**< Action that was triggered */
    EPM_state_t           proposed_state;   /**< State that task will change to after actions are completed w/o errors */
    TC_argument_list_t* arguments;          /**< Argument specified in procedure */
    tag_t                 data;             /**< System data */
} EPM_action_message_t;

typedef struct EPM_rule_message_s{
    tag_t                 task;               /**< Task on which action was triggered */
    EPM_action_t          proposed_action;    /**< Action that was triggered */
    TC_argument_list_t* arguments;            /**< Argument specified in procedure */
    tag_t                 tag;                /**< System data */
} EPM_rule_message_t;

typedef enum EPM_decision_e{
    EPM_nogo,             /**< Constraints for rule/rule handler not satisfied, action and state transition should not occur */
    EPM_undecided,        /**< Still unknown whether it is a go or nogo decision due to insufficient or pending data */
    EPM_go                /**< Rule/rule handler passed - constraints satisfied */
} EPM_decision_t;

/**
    @name EPMConditionTask
    @{
*/
#define EPM_RESULT_TRUE                 1    /**< True result for condition task */
#define EPM_RESULT_FALSE                0    /**< False result for condition task */

/** This is the default value for a new EPMConditionTask */
#define EPM_RESULT_UNSET                2
/** @} */

typedef int (*EPM_action_handler_t) (EPM_action_message_t);
typedef EPM_decision_t   (*EPM_rule_handler_t)   (EPM_rule_message_t);

/**
    Query argument to #EPM_ask_assigned_tasks
*/
#define EPM_inbox_query                 1

typedef enum EPM_handler_type_e{
    EPM_rule_handler_type,                    /**< Rule handler type */
    EPM_action_handler_type                    /**< Action handler type */
} EPM_handler_type_t;

typedef enum EPMTaskType
{
    eEPMDoTask,                        /**< Do Task type */
    eEPMReviewTask,                    /**< Review task type */
    eEPMSelectSignoffTask,            /**< Select Signoff task type */
    eEPMPerformSignoffTask,            /**< Perform Signoff task type */
    eEPMAcknowledgeTask,            /**< Acknowledge task type */
    eEPMConditionTask,                /**< Condition task type */
    eEPMNotifyTask,                    /**< Notify task type */
    eEPMRouteTask,                    /**< Route task type */
    eEPMOrTask,                        /**< OR task type */
    eEPMSyncTask,                    /**< Sync task type */
    eEPMAddStatusTask,                /**< Add Status task type */
    eECMImpactAnalysisTask,            /**< Impact Analysis task type */
    eECMPrepareECOTask,                /**< Prepare ECO task type */
    eECMChecklistTask,                /**< Checklist task type */
    eEPMValidateTask,                /**< EPMValidate task type */
    eEPMUnknownTask                    /**< Unknown task type */
} EPM_task_type_t;

/**
    Resource list used in Process Assignment Lists
*/
typedef struct EPM_resource_list_s
{
     int    count;                        /**< Number of resources/profiles */
     tag_t  *resources;                    /**< List of resources */
     tag_t  *profiles;                    /**< List of profiles */
     int    *actions;                    /**< List of actions */
     int    revQuorum;                    /**< Review quorum */
     int    ackQuorum;                    /**< Acknowledge quorum */
     int    waitForUndecidedReviewers;  /**< Wait for undecided reviewers */
} EPM_resource_list_t;

/**
    @name Relation Types
    @{
*/
#define EPM_TEMPLATE_BASED_ON_RELATION_TYPE "EPM_template_based_on"                /**< Template based on relation type */
#define EPM_SIGNOFF_PROFILE_RELATION_TYPE   "EPM_signoff_profile"                /**< Signoff profile relation type */
#define SUBSCRIBED_REMOTEINBOXES_RELATION_TYPE "subscribed_remoteinboxes"        /**< Subscribed remote inbox relation type */
/** @} */

#ifdef __cplusplus
extern "C"{
#endif

/**
    This ITK is used to initialize the EPM module and register some workflow handlers.
*/
extern EPM_API int EPM_init_module();

/**
    Registers a rule handler for a given handlerName.
    The handlerName is the name you interactively supply to the Handler Name field found on the Task Definition window.

    Example(s): The following is a sample rule handler EPM_check_responsible_party,
    which is registered using USER_register_callbacks.

    @code
        EPM_decision_t EPM_check_responsible_party(EPM_rule_message_t msg)
        {
            int s;
            EPM_decision_t decision = EPM_nogo;
            char* userName;
            tag_t aUserTag, responsibleParty;

            s = EPM_ask_responsible_party(msg.task, &responsibleParty);
            if (responsibleParty, NULLTAG)
            {
                decision = EPM_go;
            }

            if(s == ITK_ok && decision == EPM_nogo)
            {
                s = POM_get_user (&userName, &aUserTag);
                MEM_free (userName);

                if (s == ITK_ok)
                {
                    if (aUserTag, responsibleParty)
                    decision = EPM_go;
                }
            }
            return decision;
        }

        USER_register_callbacks()
        {
            s=EPM_register_rule_handler("check_responsible_party",
                                        "Success when logged in user is the responsible party for this task",
                                        EPM_check_responsible_party);
        }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#EPM_duplicate_registration if rule handler with the same name already exists
    </ul>
*/
extern EPM_API int EPM_register_rule_handler(
    const char*        handler_name,           /**< (I) Is a character string that identifies the handler.
                                                    This string is then input into the Handler Name field on
                                                    the Task Definition window when you want to use it. */
    const char*        handler_description,    /**< (I) Is a character string that should describe what
                                                    the handler does and what arguments it takes.
                                                    The string displays in the Task Definition window. */
    EPM_rule_handler_t function_pointer        /**< (I) Is the address to the function being registered */
    );

/**
    Registers an action handler for a given handlerName.
    The handlerName must match the name you interactively supply to the
    Handler Name field found on the Task Definition window.

    @code
        #include <epm/epm.h>
        #include <epm/epm_deprecated.h>

        int EPM_system( EPM_action_message_t msg )
        {
            int err = ITK_ok;
            char* arg = 0;

            if( TC_number_of_arguments( msg.arguments ) > 0 )
            {
                get first argument

                arg = TC_next_argument( msg.arguments );
                System( arg );
            }
            return err;     return an ITK error code if an error occurred
        }

        USER_register_callbacks()
        {
            int err = EPM_register_action_handler( "system",
                                                   "The first argument to handler gets sent as argument to system()",
                                                   EPM_system);
        }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#EPM_duplicate_registration if action handler with the same name already exists
    </ul>
*/
extern EPM_API int EPM_register_action_handler(
    const char*          handler_name,            /**< (I) Is a character string that must match the Handler Name
                                                    field on the Task Definition window */
    const char*          handler_description,     /**< (I) A character string that should describe what
                                                    the handler does and what arguments it takes.
                                                    The string displays in the Task Definition window. */
    EPM_action_handler_t function_pointer         /**< (I) The address to the function being registered */
    );

/**
    Adds release status to the list of release status objects for the given job.
*/
extern EPM_API int EPM_add_release_status_to_process(
    tag_t          job,             /**< (I) Job on which release status is to be set */
    tag_t          release_status    /**< (I) The release status tag */
    );

/**
    Retrieves the decision, comments and decision date from when the given user performed a signoff.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#EPM_no_decision if no decision has been made
    <li>#EPM_unknown if user is specified and no signoffs are present
    </ul>
*/
extern EPM_API int EPM_ask_decision(
    tag_t                  task_tag,                         /**< (I)  Task on which the decision, comments and date is required*/
    tag_t                  user,                            /**< (I)  User for which the decision, comments and date is required */
    EPM_signoff_decision_t* decision,                       /**< (O)  Decision taken by the user for the task */
    char                   **comments,                      /**< (OF) Comments from the user */
    date_t*                decision_date                     /**< (O)  Date on which the decision was taken */
    );

/**
    Checks whether the workspace object is released.
*/
extern EPM_API int EPM_ask_if_released(
    tag_t          workspace_object,    /**< (I) Workspace object on which the released status is to be checked */
    int*           is_released          /**< (O) The value 0 indicates not released, while 1 indicates released */
    );

/**
    Retrieves list of jobs for which the given object is one of the target objects in the job.
    Only the jobs which are in process are returned.
    Those jobs that are already completed are not listed.
*/
extern EPM_API int EPM_ask_active_job_for_target(
    tag_t          target_object,    /**< (I)  Target object on which the jobs are to be searched */
    int*           count,           /**< (O)  Number of jobs */
    tag_t**        jobs             /**< (OF) count List of jobs in which target_object is a one of the targets */
    );

/**
    Get the following information about accessors in a specified release procedure level:
    number of accessors, groups to which accessors belong, roles to which accessors belong,
    and the access each accessor has to the target object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#EPM_no_acl_defined_for_release_level if no ACLS defined for this task template
    </ul>
*/
    extern EPM_API int EPM_ask_template_access(
        tag_t          task_tag,               /**< (I) Task to find access */
        int*           nb_of_accessors,          /**< (O) Total number of accessors */
        char***        group_names,             /**< (OF) nb_of_accessors Strings giving accessor groups.
                                                   #MEM_free this list of strings. */
        char***        role_names,              /**< (OF) nb_of_accessors Strings giving accessor roles.
                                                   #MEM_free this list of strings. */
        int**          access_codes             /**< (OF) nb_of_accessors Values giving access list for each accessor.
                                                   #MEM_free this list. Go to Access Masks for additional information
                                                   about constructing access masks. */
        );

/**
   Retrieves minimum number of signoffs (approvals) required to
   complete the specified task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PROP_invalid_object if the input task is null
   </ul>
*/
    extern EPM_API int EPM_ask_quorum(
        tag_t          task_tag,                /**< (I) Task to ask quorum on */
        int*           quorum                  /**< (O) Quorum count for the task */
        );

/**
   Retrieves the list of release status objects for the given job.
   Release status objects contain effectivity and release information
   that will be applied to the target objects.
*/
    extern EPM_API int EPM_ask_release_statuses(
        tag_t          job,                     /**< (I)  Job on which the release status objects are to be requested */
        int*           count,                   /**< (O)  Number of release status objects */
        tag_t**        release_status_objects   /**< (OF) count List of release status objects for the job */
        );

/**
   Retrieves the status_type object of the given name.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_type_not_found if status type not found
   </ul>
*/
    extern EPM_API int EPM_find_status_type(
        const char*    status_type,      /**< (I) Status type name */
        tag_t*         status           /**< (O) Status type tag */
        );

/**
   Removes the specified release status from the list of release statuses of the job.
   This also deletes the release_status from the database.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_already_completed if root task is completed
   <li>#CXPOM_value_not_in_list if release status attachment is not found
   </ul>
*/
    extern EPM_API int EPM_remove_release_status(
        tag_t          job,             /**< (I) Job on which the release_status is to be removed */
        tag_t          release_status    /**< (I) Release status that is to be removed */
        );

/**
   Removes the release status from target objects.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_wrong_class if the input release_status is a tag to an object other
   than a release status object
   <li>#CXPOM_invalid_tag if input root_tag is a tag to an object other
   than a task object
   </ul>
*/
    extern EPM_API int EPM_remove_status_from_targets(
        tag_t         release_status,            /**< (I) Release status tag*/
        tag_t         root_tag                   /**< (I) Root task tag*/
        );

/**
   Reloads the job and all of the tasks in the job.
   If any other ITK or Workspace sessions have modified the job since it was last loaded,
   then calling this function assures that all values asked for will
   be the most current values in the database.

   @note This function is called automatically before a change is made to a task,
   so it is only needed before calling an EPM_ask_xxx function.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_invalid_argument if job tag is NULLTAG
   </ul>
*/
    extern EPM_API int EPM_refresh_job(
        tag_t          job      /**< (I) Workflow process to be reloaded.
                                   Also its tasks, signoffs and release levels will be reloaded */
        );


/**
   Outputs the name of the action. Returns any one of the following actions:
   The returned string is localized in the server locale. The possible values
   (for a server running in English) and their associated TextServer keys are as follows:

   <ul>
   <li>Assign: the key is "EPM_action_1".
   <li>Start: the key is "EPM_action_2".
   <li>Complete: the key is "EPM_action_4".
   <li>Suspend: the key is "EPM_action_6".
   <li>Resume: the key is "EPM_action_7".
   <li>Skip: the key is "EPM_action_5".
   <li>Abort: the key is "EPM_action_9".
   <li>Undo: the key is "EPM_action_8".
   <li>Fail: the key is "EPM_action_10".
   <li>Perform: the key is "EPM_action_100".
   <li>Add Attachment: the key is "EPM_action_101".
   <li>Remove Attachment: the key is "EPM_action_102".
   <li>Approve: the key is "EPM_action_104".
   <li>Reject: the key is "EPM_action_105".
   <li>Promote: the key is "EPM_action_106".
   <li>Demote: the key is "EPM_action_107".
   <li>Refuse: the key is "EPM_action_108".
   <li>Assign Approver: the key is "EPM_action_109".
   <li>Notify: the key is "EPM_action_110".
   </ul>
*/
    extern EPM_API int EPM_ask_action_string2(
        EPM_action_t   action,                                 /**< (I)  Action for which the name is required */
        char           **string                                /**< (OF) Name of the action */
        );


/**
   Given the state of the task, this routine returns corresponding character string.
   The returned string is localized in the server locale. The possible values
   (for a server running in English) and their associated TextServer keys are as follows:

   <ul>
   <li>Unassigned: the key is "EPM_state_1".
   <li>Pending: the key is "EPM_state_2".
   <li>Started: the key is "EPM_state_4".
   <li>Completed: the key is "EPM_state_8".
   <li>Skipped: the key is "EPM_state_16".
   <li>Aborted: the key is "EPM_state_32"
   <li>Failed: the key is "EPM_state_64"
   <li>Suspended: the key is "EPM_state_128".
   </ul>
*/
    extern EPM_API int EPM_ask_state_string2(
        EPM_state_t    state,                                  /**< (I)  State of the task for which the name is required */
        char           **string                                /**< (OF) Name of the task state */
        );


/**
   Outputs the name of the attachment associated with the input attachment type.
   #EPM_target_attachment, #EPM_reference_attachment, #EPM_signoff_attachment, #EPM_release_status_attachment
   #EPM_comment_attachment, #EPM_instruction_attachment, #EPM_interprocess_task_attachment 
   #EPM_schedule_task_attachment, #EPM_replica_target_attachment or #EPM_user_attachment.

   The returned string is localized in the server locale. The possible values
   (for a server running in English) and their associated TextServer keys are as follows:

   <ul>
   <li>Target: key is "EPM_attachment_1".
   <li>Reference: key is "EPM_attachment_3".
   <li>Signoff: key is "EPM_attachment_4".
   <li>ReleaseStatus: key is "EPM_attachment_5".
   <li>Comment: key is "EPM_attachment_6".
   <li>Instruction: key is "EPM_attachment_7".
   <li>Replica Proposed Target: key is "EPM_attachment_10".
   </ul>

   @note Attachment types from 1000-32000 are user defined.
*/
    extern EPM_API int EPM_ask_attachment_string2(
        int            attachment_type,                        /**< (I)  One of the attachment types like EPM_target_attachment, EPM_reference_attachment etc */
        char           **type_string                           /**< (OF) Name of the attachment type for ex. Target, Reference etc */
        );

/**
   Allocates an array of strings and fills it with
   all the procedure names in the system.
*/
    extern EPM_API int EPM_ask_all_procedure_names(
        int*           procedure_count,     /**< (O)  Number of procedures */
        char***        procedure_names      /**< (OF) procedure_count List of procedure names */
        );

/**
   Refreshes the job and all of its tasks.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_internal_error if refresh job fails for unknown error
   </ul>
*/
    extern EPM_API int EPM_refresh_entire_job(
        tag_t          job      /**< (I) Job to be refreshed */
        );

/**
   Retrieves name of the procedure for the given job.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_template_not_found if template corresponding to the procedure_name is not found
   </ul>
*/
    extern EPM_API int EPM_ask_procedure_name2(
        tag_t          job,                       /**< (I)  Job for which the procedure name is requested */
        char           **procedure_name           /**< (OF) Procedure name for the job */
        );

/**
   Retrieves the tag to the audit file.
   The audit file is an ImanFile in text format where all actions to all tasks have been written to.
   It is a chronological history of actions taken on a job.
*/
    extern EPM_API int EPM_ask_audit_file(
        tag_t          job,                       /**< (I)  Job for which the audit file is required */
        tag_t*         audit_file                 /**< (O)  Tag of the audit file for the job */
        );

/**
    Assigns responsible party to a given task. Responsible party can be either a user or a resource pool.
    <br/>This method also logs the comment. If the comment parameter is empty/null, the comment will not be saved.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_access_denied if action is denied on the task for logged-in user.
    <li>#EPM_invalid_object if error getting the task
    </ul>
*/
extern EPM_API int EPM_assign_responsible_party_with_comments(
    tag_t          task,                      /**< (I) Task for which the respnsible party is to be assigned */
    tag_t          responsible_party,         /**< (I) New responsible party for the task */
    const char*    comments                   /**< (I) Comments for the task */       
    );

/**
   Assigns responsible party to the given task.
   Responsible party can be either a user or a resource pool.
*/
    extern EPM_API int EPM_assign_responsible_party(
        tag_t          task,                      /**< (I) Task for which the respnsible party is to be assigned */
        tag_t          responsible_party          /**< (I) New responsible party for the task */
        );

/**
   Given the task, this routine gets corresponding responsible party.
*/
    extern EPM_API int EPM_ask_responsible_party(
        tag_t          task,                     /**< (I) Task on which the respnsible party is requested */
        tag_t*         responsible_party          /**< (O) Assigned responsible party */
        );

/**
   Retrieves the existing state of the task.
*/
    extern EPM_API int EPM_ask_state(
        tag_t          task,       /**< (I)  Task on which the state is requested*/
        EPM_state_t*   state       /**< (O)  Existing state of the task */
        );

/**
   Causes the specified action to execute for the specified task
   assuming that the business rules listed in the procedure all pass.
   The action and comments are recorded in the audit file.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_access_denied if demote action is denied on the task for logged-in user
   </ul>
*/
    extern EPM_API int EPM_trigger_action(
        tag_t          task,               /**< (I) Task on which the action is to be triggered */
        EPM_action_t   action,             /**< (I) Trigger action on the task */
        const char*    comments            /**< (I) Comments during the trigger to be recorded in the audit file */
        );

/**
   Causes the specified action to execute for the specified task
   assuming that the business rules listed in the procedure all pass.
   The action and comments are recorded in the audit file.
   Also checks that the logged in user is a valid user to complete a do task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_access_denied if demote action is denied on the task for logged-in user
   <li>#EPM_incorrect_pass_for_secure_task if password for a secure task does not match with that of the logged in user
   </ul>
*/
    extern EPM_API int EPM_trigger_action_if_privileged(
        tag_t          task,               /**< (I) Task on which the action is to be triggered */
        EPM_action_t   action,             /**< (I) Trigger action on the task */
        const char*    comments            /**< (I) Comments during the trigger to be recorded in the audit file */
        );

/**
   Causes the specified action to execute for the specified secure task
   assuming that the business rules listed in the process definition pass.
   The action and comments are recorded in the audit file.

   <b>Restrictions:</b>

   The ITK program must have logged into the POM as the user assigned to
   this task's responsible party in order for this function to work.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_access_denied if demote action is denied on the task for logged-in user
   <li>#EPM_incorrect_pass_for_secure_task if password for a secure task does not match with that of the logged in user
   </ul>
*/
    extern EPM_API int EPM_trigger_secure_action(
        tag_t          task,           /**< (I) The tag of the secure task */
        EPM_action_t   action,         /**< (I) EPM_action associated with the task that is to be performed */
        const char*    comments,       /**< (I) Comments to be recorded along with the action */
        const char*    password        /**< (I) Password of current user performing the action */
        );

/**
   Retrieves all the objects attached to the given task (for the given attachment type).
   The total number of attached objects is stored as count.
   This function requires the task and the attachment_type as inputs.
   The following are valid attachment types:
   #EPM_target_attachment, #EPM_reference_attachment, #EPM_signoff_attachment, #EPM_release_status_attachment
   #EPM_comment_attachment, #EPM_instruction_attachment, #EPM_interprocess_task_attachment 
   #EPM_schedule_task_attachment or #EPM_replica_target_attachment.
   Rule or action handlers dealing with target or reference attachment types should use the root task.

   @code
   tag_t task;
   int count;
   POM-tag_t* attachments;

   EPM_ask_attachments(task,
   EPM_reference_attachment,
   &count,
   &attachments);
   @endcode
*/
    extern EPM_API int EPM_ask_attachments(
        tag_t          task,                  /**< (I)  Task on which the attachments are requested */
        int            attachment_type,       /**< (I)  Specific attachment type like EPM_target_attachment, EPM_reference_attachment etc*/
        int*           count,                 /**< (O)  Number of attachments of specified type on the task */
        tag_t**        attachments            /**< (OF) count List of attachments */
        );

/**
   Retrieves all the objects attached to the given task and corresponding attachment types.
   The total number of attachments is stored in variable count.
   The following are valid attachment types:
   #EPM_target_attachment, #EPM_reference_attachment, #EPM_signoff_attachment, #EPM_release_status_attachment
   #EPM_comment_attachment, #EPM_instruction_attachment, #EPM_interprocess_task_attachment 
   #EPM_schedule_task_attachment or #EPM_replica_target_attachment.
*/
    extern EPM_API int EPM_ask_all_attachments(
        tag_t          task,                    /**< (I)  Task on which the attachments are requested */
        int*           count,                   /**< (O)  Number of attachments */
        tag_t**        attachments,             /**< (OF) count List of attachments */
        int**          attachment_types         /**< (OF) count List of attachment types */
        );

/**
   Retrieves all target objects of a given type.
*/
    extern EPM_API int EPM_ask_typed_attachments(
        tag_t         task,                                  /**< (I)  Task on which the attachments are requested */
        const char*   object_type,                           /**< (I)  Type of objects to be returned */
        int*          count,                                 /**< (O)  Number of attachments of object type */
        tag_t**       attachments                            /**< (OF) count List of attachments of the specified object type */
        );

/**
   Adds an array of attachments to the given task.
   The total number of attachments is passed as count.
   See also #EPM_ask_attachments and #EPM_ask_all_attachments.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_invalid_object if error getting parent process
   <li>#EPM_task_belongs_to_same_process: For interprocess task attachment type, if supplied task process and current process is same
   <li>#EPM_task_circular_dependency: For interprocess task attachment type, if supplied task causes circular dependency
   <li>#EPM_not_a_task_or_process: For interprocess task attachment type, if supplied task tag is neither a task or process
   <li>#EPM_duplicate_reviewer: For signoff attachment type, if duplicate signoff member found
   <li>#EPM_object_already_attached if attachment object is already present on the task
   </ul>
*/
    extern EPM_API int EPM_add_attachments(
        tag_t          task,                  /**< (I) Task on which the attachments are to be added */
        int            count,                 /**< (I) Number of attachments to be attached */
        const tag_t*   attachments,           /**< (I) Attachments to be attached to the task */
        const int*     attachment_types       /**< (I) List of attachment types */
        );

/**
   Removes objects attached to the task.
   Tags of the objects to be deleted are stored in the array of attachments.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_already_completed if task is already completed
   <li>#CXPOM_value_not_in_list if attachment to be removed is not found
   <li>#EPM_job_corrupted if job is corrupt when detaching target attachment from task
   <li>#EPM_cannot_remove_task_from_wso: Error during removal of the tasks from the target release status list
   </ul>
*/
    extern EPM_API int EPM_remove_attachments(
        tag_t          task,               /**< (I) Task on which the attachment is to be removed */
        int            count,              /**< (I) Number of attachments to be removed */
        const tag_t*   attachments         /**< (I) List of attachments to be removed */
        );

/**
   Removes attachments attached by a specific relation to the task.
   This is because, one attachment can be attached by more than one attachment type (Target, Reference etc..)
   Tags of the objects to be deleted are stored in the array of attachments.
   The following are valid attachment types:
   #EPM_target_attachment, #EPM_reference_attachment, #EPM_signoff_attachment, #EPM_release_status_attachment
   #EPM_comment_attachment, #EPM_instruction_attachment, #EPM_interprocess_task_attachment 
   #EPM_schedule_task_attachment or #EPM_replica_target_attachment.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_already_completed if task is already completed
   <li>#CXPOM_value_not_in_list if attachment to be removed is not found
   <li>#EPM_job_corrupted if job is corrupt when detaching target attachment from task
   <li>#EPM_cannot_remove_task_from_wso if an error has occurred during removal of the tasks from the target release status list
   </ul>
*/
    extern EPM_API int EPM_remove_attachments_from_att_type(
        tag_t          task,                                       /**< (I) Task on which the attachment is to be removed */
        int            count,                                      /**< (I) Number of attachments to be removed */
        const tag_t*   attachments,                                /**< (I) List of attachments to be removed */
        const int*     attachment_types                             /**< (I) Attachment type of the objects to be removed. For ex. EPM_target_attachment,
                                                                       EPM_reference_attachment etc. */
        );

/**
   Retrieves an array of tasks assigned to the given responsible party.
   Always give #EPM_inbox_query as the query argument.
*/
    extern EPM_API int EPM_ask_assigned_tasks(
        tag_t          responsible_party,      /**< (I)  Responsible party for which assigned tasks are required */
        int            query,                  /**< (I)  Takes following values:
                                                  0 - eliminates tasks which are completed or skipped
                                                  1 - eliminates tasks which are completed or skipped or suspended
                                                  2 - only includes tasks which are started*/
        int*           count,                  /**< (O)  Number of tasks assigned to responsible party */
        tag_t**        tasks                   /**< (OF) count List of tasks */
        );

/**
   Retrieves root task of the given task or job.
*/
    extern EPM_API int EPM_ask_root_task(
        tag_t          job_or_task,        /**< (I) Job or task for which root task is required */
        tag_t*         root_task           /**< (O) Root task of the job or task */
        );

/**
   Retrieves an array of subtasks attached to the task.
*/
    extern EPM_API int EPM_ask_sub_tasks(
        tag_t          task,         /**< (I) Task for which all its sub-tasks are required */
        int*           count,        /**< (O) Number of subtasks */
        tag_t**        tasks         /**< (OF) count List of subtasks */
        );

/**
   Retrieves the subtask with the given name.
*/
    extern EPM_API int EPM_ask_sub_task(
        tag_t          task,                /**< (I) Task for which sub-task is required */
        const char*    sub_task_name,       /**< (I) Name of the subtask */
        tag_t*         sub_task             /**< (O) Subtask corresponding to name, NULLTAG if task not found */
        );

/**
   Retrieves parent task of the given task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_job_corrupted if job is corrupt
   </ul>
*/
    extern EPM_API int EPM_ask_parent_task(
        tag_t          task,             /**< (I) Task for which parent task is required */
        tag_t*         parent_task       /**< (O) Parent task */
        );


/**
   Retrieves the name of the given task.
*/
    extern EPM_API int EPM_ask_name2(
        tag_t          task,                            /**< (I)  Task of which name is required */
        char           **name                           /**< (OF) Name of the task */
        );

/**
   Retrieves the description of the given task.
*/
    extern EPM_API int EPM_ask_description2(
        tag_t          task,                                   /**< (I)  Task of which description is required */
        char           **description                           /**< (OF) Description on the task */
        );

/**
   Given the task, returns the corresponding job.
*/
    extern EPM_API int EPM_ask_job(
        tag_t          task,     /**< (I) Task of which job is required */
        tag_t*         job       /**< (O) Job for the task */
        );

/**
   Retrieves a task from a process given a task name.
*/
    extern EPM_API int EPM_search_task_in_job(
        tag_t          task,          /**< (I) Task within a job from which the sub-task is required */
        const char*    task_name,      /**< (I) The task name to find */
        tag_t*         sub_task        /**< (O) Task from the job corresponding to the task_name */
        );

/**
   Provides a list of tags to predecessor tasks with respect to the given task instantiation.
   This ITK function does not deal with task definitions but with a task instantiation.
   Predecessors are currently determined by the names of the sibling tasks that
   appear as arguments in the check-completion handler of the given task.
*/
    extern EPM_API int EPM_ask_task_dependencies(
        const tag_t    task,                     /**< (I)  Task on which the predecessors are required */
        int*           nb_of_predecessors,       /**< (O)  Number of predecessors found */
        tag_t**        predecessor_tasks         /**< (OF) nb_of_predecessors List of predecessors found for the task */
        );


/**
   Retrieves the default review process name that is assigned to a given object type.
   This review process is based on the current login group.
*/
    extern EPM_API int EPM_ask_default_process2(
        const char     *object_type,        /**< (I) Object for which default process is required */
        char           **process_name       /**< (OF) Default review process name */
        );


/**
   Retrieves the default review process name for a given Work that is assigned to a given object type.
   This review process is based on the current login group.
*/
    extern EPM_API int EPM_ask_default_process_for2(
        tag_t          workspace_object,                       /**< (I)  Workspace object */
        char           **process_name                          /**< (OF) Review process for this object based on the current login group */
        );

/**
   Sets action handler EPM-hold to "false" in order for a subsequent.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_complete_action to be able to complete a task if all other conditions are met
   </ul>
*/
    extern EPM_API int EPM_remove_task_hold(
        tag_t          task_tag          /**< (I) The task tag */
        );

/**
   Retrieves the resource pool object given a group, role, and
   a flag indicating if sub groups are allowed.
   This method will create and save a resourcepool object if
   no such resourcepool object exists in the data base.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if unable to find or create resource pool
   </ul>
*/
    extern EPM_API int EPM_get_resource_pool(
        tag_t          group,           /**< (I) The Group tag */
        tag_t          role,            /**< (I) The role tag */
        logical        allow_subgroup,  /**< (I) The flag indicating if subgroups are allowed */
        tag_t*         resourcepool     /**< (O) The resource pool tag */
        );

/**
   Retrieves the resource pool object given a group, role,
   a flag indicating if sub groups are allowed.
   and a flag indicating if all members should be included in the resource pool
   This method will create and save a resourcepool object if
   no such resourcepool object exists in the data base.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if unable to find or create resource pool
   </ul>
*/
    extern EPM_API int EPM_ask_resourcepool(
        tag_t          group,           /**< (I) The Group tag */
        tag_t          role,            /**< (I) The role tag */
        logical        allow_subgroup,  /**< (I) The flag indicating if subgroups are allowed */
        logical        all_members,     /**< (I) The flag indicating if it is all members type resource pool */
        tag_t*         resourcepool     /**< (O) The resource pool tag */
        );

/**
   Asks resource pool group, role, and if subgroups are allowed.
*/
    extern EPM_API int EPM_ask_resource_pool_group_role(
        tag_t          resourcepool,     /**< (I) The given resource pool tag */
        tag_t*         group,            /**< (O) The group tag */
        tag_t*         role,             /**< (O) The role tag */
        logical*       allow_subgroup    /**< (O) The flag indicating if subgroups are allowed */
        );

/**
   Asks resource pool name.
*/
    extern EPM_API int EPM_get_resource_pool_name(
        tag_t          resourcepool,       /**< (I) The given resource pool object */
        char**         resourcepool_name   /**< (OF) Display name for given resource pool object */
        );

/**
   Asks resource pool subscribers.
*/
    extern EPM_API int EPM_ask_resource_pool_subscribers(
        tag_t           resourcepool,          /**< (I) The given resource pool object */
        int*            u_count,               /**< (O) The user count */
        tag_t**         u_tags                 /**< (OF) u_count List of user tags */
        );

/**
   Retrieves the out-of-office attributes for a user. 
   <br/>This function gives the user's delegatee,
   start date and end date if the user is out of office.
*/
    extern EPM_API int EPM_ask_out_of_office(
        tag_t          user,             /**< (I) The user tag */
        tag_t*         delegate,         /**< (O) The delegate tag. It can be an user tag, a groupmember tag or a resourcepool tag. */
        date_t*        start_date,       /**< (O) The start date */
        date_t*        end_date          /**< (O) The end date */
        );

/**
   Sets the out-of-office for a user. 
   <br/>This function includes:
   <ul>
   <li>Assigning delegatee
   <li>Setting out-of-office start date and end date
   <li>Reset out-of-office when set delegate, startDate and endDate to NULL
   </ul>

   <b>Restrictions:</b>
   User without System Admin privilege will not be allowed to set the out-of-office for other users.
   Group Administrators will only be able to set the out-of-office for users within their group.
*/
    extern EPM_API int EPM_set_out_of_office(
        tag_t          user,            /**< (I) The user tag. */
        tag_t          delegate,        /**< (I) The delegatee tag. It can be a user tag, a groupmember tag or a resource pool tag. */
        date_t         start_date,       /**< (I) The start date. The date when the user starts being out-of-office. */
        date_t         end_date          /**< (I) The end date. The date when the user ends his out-of-office time. */
        );

/**
   Assigns the delegatee for a user, when he is out of office.

   <b>Restrictions:</b>
   User without System Admin privilege will not be allowed to set the out-of-office for other users.
   Group Administrators will only be able to set the out-of-office for users within their group.
*/
    extern EPM_API int EPM_set_out_of_office_delegate(
        tag_t          user,             /**< (I) The user tag */
        tag_t          delegate          /**< (I) The delegatee tag. It can be a user tag, a groupmember tag or a resource pool tag. */
        );

/**
   Set the start date and end date for a user when he is out of office.

   <b>Restrictions:</b>
   User without System Admin privilege will not be allowed to set the out-of-office for other users.
   Group Administrators will only be able to set the out-of-office for users within their group.
*/
    extern EPM_API int EPM_set_out_of_office_dates(
        tag_t          user,             /**< (I) The user tag */
        date_t         start_date,       /**< (I) The start date. The date when the user starts being out-of-office. */
        date_t         end_date          /**< (I) The end date. The date when the user ends his out-of-office time. */
        );

/**
   Sets the task's due date for a task.
*/
    extern EPM_API int EPM_set_task_due_date(
        tag_t          task,             /**< (I) The task tag */
        date_t         due_date          /**< (I) The task's due date */
        );

/**
   Reset task due date to NULL for a task.
*/
    extern EPM_API int EPM_reset_task_due_date(
        tag_t          task           /**< (I) The task tag */
        );

/**
   Retrieves the task's due date given the task tag.
*/
    extern EPM_API int EPM_ask_task_due_date(
        tag_t          task,            /**< (I) The task tag */
        date_t*        due_date         /**< (O) The task's due date */
        );

/**
   Sets the task's late flag for a task, and also triggers the emailing of all the late task recipients.

   <b>Restrictions:</b>
   This function requires that you set the ByPassPrivilege.
*/
    extern EPM_API int EPM_set_task_late(
        tag_t          task,            /**< (I) The task tag */
        logical        late_flag        /**< (I) The task's late flag */
        );

/**
   Retrieves the task's late flag given a task tag.
*/
    extern EPM_API int EPM_ask_task_late(
        tag_t          task,           /**< (I) The task tag */
        logical*       late_flag       /**< (O) The task's late flag */
        );

/**
   Sets the task duration for a task.
   The task's duration is the total of : years(yrs) + weeks(wks) + days(dys) + hours(hrs) + minutes(mns)

   The function will reset the task's duration if all integer inputs are zeroes (0).
   In this case, #EPM_ask_task_duration will get the duration from a task's EPMTaskDefinition.
*/
    extern EPM_API int EPM_set_task_duration(
        tag_t          task,             /**< (I) The task tag */
        int            years,            /**< (I) The whole number of years to be set for duration (yrs) */
        int            weeks,            /**< (I) The whole number of weeks to be set for duration (wks) */
        int            days,             /**< (I) The whole number of days to be set for duration (dys) */
        int            hours,            /**< (I) The whole number of hours to be set for duration (hrs) */
        int            minutes           /**< (I) The whole number of minutes to be set for duration (mns) */
        );

/**
   Retrieves the task duration for a task.
   The task's duration will be the total of:
   years(yrs) + weeks(wks) + days(dys) + hours(hrs) + minutes(mns)
*/
    extern EPM_API int EPM_ask_task_duration(
        tag_t          task,           /**< (I) The task tag */
        int*           yrs,            /**< (O) The whole number of years of the task's duration (yrs) */
        int*           wks,            /**< (O) The whole number of weeks of the task's duration (wks) */
        int*           dys,            /**< (O) The whole number of days of the task's duration (dys) */
        int*           hrs,            /**< (O) The whole number of hours of the task's duration (hrs) */
        int*           mns             /**< (O) The whole number of minutes of the task's duration (mns) */
        );

/**
   Finds all the tasks that are late in the responsible Party's Inbox.
   Those tasks are not already completed or not suspended.
*/
    extern EPM_API int EPM_ask_users_late_tasks(
        tag_t          user,           /**< (I) The user tag. This can be either a user tag or a resource pool tag. */
        int*           count,          /**< (O) The number of all the tasks that are late and
                                          not-yet completed but not suspended, in this user's Inbox . */
        tag_t**        late_tasks       /**< (OF) count Array of all the tasks that are late and
                                           not-yet completed but not suspended, in this responsible party's Inbox. */
        );

/**
   Adds subscribed resource pools to user's Inbox.
*/
    extern EPM_API int EPM_add_subscribed_resource_pools(
        tag_t          user,           /**< (I) The user tag */
        int            count,          /**< (I) The number of subscribed resource pools to be added into user's Inbox */
        const tag_t*   resourcepools   /**< (I) The subscribed resourcepool tags to be added into the user's Inbox */
        );

/**
   Removes subscribed resource pools from user's Inbox.
*/
    extern EPM_API int EPM_remove_subscribed_resource_pools(
        tag_t          user,           /**< (I) The user tag */
        int            count,          /**< (I) The number of subscribed resource pools to be removed from the user's Inbox */
        const tag_t*   resourcepools   /**< (I) The resource pool objects that will be removed from the user Inbox */
        );

/**
   Adds subscribed remote inboxes to User Inbox
*/
    extern EPM_API int EPM_set_subscribed_remote_inboxes(
        tag_t user,                 /**< (I) The user tag */
        int count,                  /**< (I) Number of remote inboxes to be subscribed to the User Inbox */
        const tag_t *site_tags       /**< (I) Sites whose remote inbox objects will be subscribed by the user */
        );

/**
   Retrieves the subscribed resource pools inboxes.
*/
    extern EPM_API int EPM_remove_all_subscribed_remote_inboxes(
        tag_t user            /**< (I) The user tag */
        );

/**
   Retrieves the subscribed resource pools inboxes.
*/
    extern EPM_API int EPM_ask_subscribed_remote_inboxes(
        tag_t user,            /**< (I) The user tag */
        int *count,            /**< (O) The number of sites whose inbox are subscribed */
        tag_t **site_tags       /**< (OF) count Sites whose inbox are subscribed by the user */
        );

/**
   Retrieves the tag of the remote inbox corresponding to the site
*/
    extern EPM_API int EPM_ask_remote_inbox(
        tag_t    user,              /**< (I) The user tag */
        tag_t    site,              /**< (I) The site tag */
        tag_t*   remote_inbox        /**< (O) The remote inbox corresponding to the site */
        );

/**
   Retrieves the subscribed resource pools Inboxes.
*/
    extern EPM_API int EPM_ask_subscribed_resource_pools(
        tag_t          user,          /**< (I) The user tag */
        int*           count,         /**< (O) The number of subscribed resource pools inboxes */
        tag_t**        resourcepools  /**< (OF) count List of resourcepool objects whose inboxes are subscribed by the user */
        );

/**
   Retrieves the task's recipient tags.
   They are the tags of all users, groups, alias lists that will
   receive email notification when task become late (not completed before the due date).
*/
    extern EPM_API int EPM_ask_late_task_recipients(
        tag_t          task,           /**< (I) The task tag */
        int*           count,          /**< (O) The number of recipients in this task */
        tag_t**        recipients      /**< (OF) count Array of task's recipient tags.
                                          They are user tags, group tags or alias list tags that
                                          match the criteria in the above description. */
        );

/**
   Sets the recipients for a task.
   These are the tags of all users, groups, alias lists that will be
   sent emails when the task are not completed before the due date.
*/
    extern EPM_API int EPM_set_late_task_recipients(
        tag_t          task,                       /**< (I) The task tag */
        int            count,                      /**< (I) The number of recipients in this task */
        const tag_t*   recipient_tags               /**< (I) Array of task's recipients tags.
                                                       They can be user tags, group tags or alias list tags. */
        );


/**
   Retrieves the list of recipients depending on the token type.
   The "token" can take values like $PROPOSED_REVIEWERS, $PROPOSED_RESPONSIBLE_PARTY ...

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_wrong_class for $PROJECT token, if the first project class corresponding to the first attachment of the root task is wrong
   </ul>
*/
    extern EPM_API int EPM_ask_recipients_for_token(
        tag_t          task,                /**< (I) The task tag */
        const char*    token,               /**< (I) Token represents intended recipients of a notification. */
        int*           count,               /**< (O) The count holds the number of recipients.*/
        tag_t**        recipient_tags       /**< (OF) count List of user tags for recipients */
        );

/**
   Retrieves the list of participants depending on the token type.
   The "token" can take values like $PROPOSED_REVIEWERS, $PROPOSED_RESPONSIBLE_PARTY ...

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#WSOUIF_object_not_found for addresslist type, if address list is not found for the participant
   <li>#EPM_target_object_not_attached for $TARGET, if no target attachments are found for the task
   </ul>
*/
    extern EPM_API int EPM_ask_participants_for_token(
        tag_t       task,                       /**< (I) Task tag */
        const char* token,                      /**< (I) Represents intended recipients of a notification like $PROPOSED_REVIEWERS, $PROPOSED_RESPONSIBLE_PARTY ... */
        int         *group_member_count,        /**< (O) Number of group members */
        tag_t       **gm_tags,                  /**< (OF) group_member_count List of group member tags for participants */
        int         *resource_pools_count,      /**< (O)  Number resource pools */
        tag_t       **resource_pool_tags        /**< (OF) resource_pools_count List of resource pools for participants*/
        );

/**
   Retrieves recipients based on preference value.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_wrong_class: For $PROJECT token, if the first project class corresponding to the first attachment of the root task is wrong
   </ul>
*/
    extern EPM_API int EPM_add_resource_pool_recipients_for_preference(
        tag_t          task,                   /**< (I)  Task tag */
        int            *count,                 /**< (O)  Number of recipients for preference */
        tag_t          **recipient_tags        /**< (OF) count List of recipients */
        );

/**
   Sets the logical is_done property for a task.
*/
    extern EPM_API int EPM_set_adhoc_signoff_selection_done(
        tag_t          task,                /**< (I) The task tag */
        logical        selection_done       /**< (I) The task's is_done logical property */
        );

/**
   Retrieves the logical is_done property of a task.
*/
    extern EPM_API int EPM_get_adhoc_signoff_selection_done(
        tag_t          task,                    /**< (I) The task tag */
        logical*       selection_done           /**< (O) The task's is_done logical property */
        );


/**
   Demote the task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_access_denied if demote action is denied on the task for logged-in user
   </ul>
*/
    extern EPM_API int EPM_demote_task(
        const tag_t    task_tag,       /**< (I) The task tag */
        const char*    comments        /**< (I) Demote comments */
        );

/**
   Promote the task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_access_denied if promote action is denied on the task for logged-in user
   <li>#EPM_interprocess_task_dependency_not_met if failed to complete interdependent tasks
   </ul>
*/
    extern EPM_API int EPM_promote_task(
        const tag_t    task_tag,        /**< (I) The task tag */
        const char*    comments         /**< (I) Promote comments */
        );

/**
   Retrieves the task name if the task is a review task,
   or the subtask of a review task, such as select-signoff-team and perform-signoff task.
   This function will work properly with parallel tasks.
*/
    extern EPM_API int EPM_ask_review_task_name2(
        const tag_t    task_tag,                                  /**< (I) The task tag */
        char           **review_task_name                         /**< (OF) The name of the review task */
        );

/**
   Retrieves a list of the names of all release levels for the given release procedure.

   @note The user is responsible for freeing the memory for the array of release level names.
   Call #MEM_free to free memory for the entire list.
   This call to #MEM_free also frees the memory for the individual strings at the same time.

   @code
   char** names;
   int n;

   EPM_ask_review_task_names(task_tag, &n, &names);

   MEM_free(names);
   @endcode
*/
    extern EPM_API int EPM_ask_review_task_names(
        tag_t          task_tag,                   /**< (I)  Task on which review task names are required */
        int*           count,                      /**< (O)  Number of review tasks */
        char***        review_task_names           /**< (OF) count List of review tasks */
        );

/**
   Retrieves the number of tasks and tasks' tags of a given task type,
   such as all the review tasks, in a job.
*/
    extern EPM_API int EPM_get_type_tasks(
        const tag_t           job_tag,           /**< (I) The tag of the job that contains the tasks */
        const EPM_task_type_t task_type,         /**< (I) Task type */
        int*                  number_of_tasks,   /**< (O) Number of tasks found with the specified type in the job */
        tag_t**               task_tags          /**< (OF) number_of_tasks Tags of those tasks */
        );


/**
   @deprecated #EPM_set_task_decision2 deprecated in Teamcenter 12.2. Use #EPM_set_task_decision3 instead.

   Sets the decision on a review task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_inbox_folder_out_of_date if signoff type is groupmember, and logged-in user is different from signoff user/surrogate user
   <li>#EPM_role_and_group_does_not_match_required: For any other signoff object types, logged-in user is different from signoff user/surrogate user
   <li>#EPM_select_signoff_team_not_completed if select-signoff task is not commplete
   </ul>
*/
    TC_DEPRECATED("12.2","EPM_set_task_decision2","EPM_set_task_decision3")
    extern EPM_API int EPM_set_task_decision2(
        tag_t                 task_tag,                  /**< (I) The tag of a perform signoff task or a review task */
        tag_t                 signoff_tag,               /**< (I) The tag of signoff */
        CR_signoff_decision_t decision,                  /**< (I) The decision */
        const char            *comments                  /**< (I) The comments */
        );

/**
   Sets the decision on a review task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_inbox_folder_out_of_date if signoff type is groupmember, and logged-in user is different from signoff user/surrogate user
   <li>#EPM_role_and_group_does_not_match_required: For any other signoff object types, logged-in user is different from signoff user/surrogate user
   <li>#EPM_select_signoff_team_not_completed if select-signoff task is not commplete
   </ul>
*/
    extern EPM_API int EPM_set_task_decision3(
        tag_t                 task_tag,                  /**< (I) The tag of a perform signoff task or a review task */
        tag_t                 signoff_tag,               /**< (I) The tag of signoff */
        EPM_signoff_decision_t decision,                 /**< (I) The decision */
        const char            *comments                  /**< (I) The comments */
        );


/**
   @deprecated #EPM_set_secure_task_decision2 deprecated in Teamcenter 12.2. Use #EPM_set_secure_task_decision3 instead.

   Sets the decision on a secure review task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_inbox_folder_out_of_date if signoff type is groupmember, and logged-in user is different from signoff user/surrogate user
   <li>#EPM_role_and_group_does_not_match_required: For any other signoff object types, logged-in user is different from signoff user/surrogate user
   <li>#EPM_select_signoff_team_not_completed if select-signoff task is not commplete
   <li>#EPM_incorrect_pass_for_secure_task if password for a secure task does not match with that of the logged in user
   </ul>
*/
    TC_DEPRECATED("12.2","EPM_set_secure_task_decision2","EPM_set_secure_task_decision3")
    extern EPM_API int EPM_set_secure_task_decision2(
        tag_t                 task_tag,                          /**< (I) The tag of a perform signoff task or a review task */
        tag_t                 signoff_tag,                       /**< (I) The tag of signoff */
        CR_signoff_decision_t decision,                          /**< (I) The decision */
        const char            *comments,                         /**< (I) The comments */
        const char*           password                           /**< (I) Password of signoff user */
        );

/**
   Sets the decision on a secure review task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_inbox_folder_out_of_date if signoff type is groupmember, and logged-in user is different from signoff user/surrogate user
   <li>#EPM_role_and_group_does_not_match_required: For any other signoff object types, logged-in user is different from signoff user/surrogate user
   <li>#EPM_select_signoff_team_not_completed if select-signoff task is not commplete
   <li>#EPM_incorrect_pass_for_secure_task if password for a secure task does not match with that of the logged in user
   </ul>
*/
    extern EPM_API int EPM_set_secure_task_decision3(
        tag_t                 task_tag,                          /**< (I) The tag of a perform signoff task or a review task */
        tag_t                 signoff_tag,                       /**< (I) The tag of signoff */
        EPM_signoff_decision_t decision,                         /**< (I) The decision */
        const char            *comments,                         /**< (I) The comments */
        const char*           password                           /**< (I) Password of signoff user */
        );



/**
   Checks whether the current user is a valid performer for the task.
*/
    extern EPM_API int EPM_is_valid_performer(
        tag_t          task,         /**< (I) Task tag */
        logical*       valid         /**< (O) True if user is a valid performer else false */
        );

/**
   Retrieves required accessors for a review task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_given_neither_group_nor_role if group and role are null when obtaining accessors
   <li>#EPM_invalid_group_name if group name is invalid
   </ul>
*/
    extern EPM_API int EPM_ask_required_reviewer_types(
        tag_t          task,                     /**< (I)  Task tag */
        int*           count,                    /**< (O)  Number of accesors */
        tag_t**        required_accessors        /**< (OF) count List of accessors depending on the signoff profiles of the task */
        );

/**
   Given the name or pattern of a group and the name of a role return
   corresponding tags:
   the groups if not null,
   else the roles if not null,
   else the accessors (presumably role-in-group).

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_given_neither_group_nor_role if neither group nor role is specified
   <li>#EPM_invalid_group_name if invalid group is entered
   </ul>
*/
    extern EPM_API int EPM_ask_accessor_tags(
        tag_t          group,              /**< (I)  Group in which the accesors are to be searched. Can be NULL. In this case, n_accesors = 1 and accesors = role */
        logical        allow_subgroups,    /**< (I)  If true then search in the sub-groups */
        tag_t          role,               /**< (I)  Role in which the accessors are to be searched. Can be NULL. */
        int*           n_accessors,        /**< (O)  Number of accessors depending upon group, role. */
        tag_t**        accessors           /**< (OF) n_accessors List of accessors */
        );

/**
   Creates a process with process name, description, process template tag,
   and attachments (like target or reference) as arguments.
   The newly created process will not start.
   The new process's tag will be returned.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#WS_infodba_cannot_create_wsobjects if current logged-in user is infodba
   <li>#EPM_target_not_workspaceobject if target type attachment is not a WSO object
   <li>#WSO_already_archived if target WSO is already archived
   <li>#EPM_target_modified if EPM_RELEASE_MODIFIED_BVR envt variable is defined, target is of type BVR and BVR is modified
   <li>#EPM_in_release_process if multiple processes preference is set to OFF and target WSO is referenced in more than one task
   </ul>
*/
    extern EPM_API int EPM_create_process_deferred_start(
        const char*    name,                               /* <I> Name of the process */
        const char*    description,                        /* <I> Process description */
        const tag_t    process_template,                    /* <I> Process template tag */
        int            attachment_count,                    /* <I> Number of attachments */
        const tag_t*   attachments,                        /* <I> Attachments to the process */
        const int*     attachment_types,                    /* <I> Attachment types like target or reference */
        tag_t*         new_process                          /* <O> New process */
        );

/**
   Creates a new process with the process name, description, process template tag,
   and attachments (like target or reference).
   The new process will be started and it's tag will be returned.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#WS_infodba_cannot_create_wsobjects if current logged-in user is infodba
   <li>#EPM_target_not_workspaceobject if target type attachment is not a WSO object
   <li>#WSO_already_archived if target WSO is already archived
   <li>#EPM_target_modified if EPM_RELEASE_MODIFIED_BVR envt variable is defined, target is of type BVR and BVR is modified
   <li>#EPM_in_release_process if multiple processes preference is set to OFF and target WSO is referenced in more than one task
   </ul>
*/
    extern EPM_API int EPM_create_process(
        const char*          name,                 /**< (I) Name of the process */
        const char*          description,          /**< (I) Process description */
        const tag_t          process_template,      /**< (I) Process template tag */
        int                  attachment_count,      /**< (I) Number of attachments */
        const tag_t*         attachments,          /**< (I) Attachments to the process */
        const int*           attachment_types,      /**< (I) Attachment types like target or reference */
        tag_t*               new_process            /**< (O) New process */
        );

/**
   Creates a new process based on the given parameters.
   The new process's tag will be returned.
   This ITK is typically used to initiate a Workflow process from a Schedule.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_template_not_found if process temmplate is null
   <li>#SA_finding_user if privileged is not specified and valid user cannot be found
   <li>#WS_infodba_cannot_create_wsobjects if current logged-in user is infodba
   <li>#EPM_unable_to_initiate_process: Unable to initiate process
   <li>#EPM_job_corrupted if root task of the newly created process is invalid
   <li>#EPM_target_not_workspaceobject if target type attachment is not a WSO object
   <li>#WSO_already_archived if target WSO is already archived
   <li>#EPM_target_modified if EPM_RELEASE_MODIFIED_BVR envt variable is defined, target is of type BVR and BVR is modified
   <li>#EPM_in_release_process if multiple processes preference is set to OFF and target WSO is referenced in more than one task
   </ul>
*/
    extern EPM_API int EPM_create_assigned_process(
        const char*        name,              /**< (I) Process name */
        const char*        description,       /**< (I) Process description*/
        tag_t              process_template,  /**< (I) Existing process template*/
        const char*        privileged_user,   /**< (I) Privileged user of a task */
        int                user_count,        /**< (I) Count of users */
        char**             user_list,         /**< (I) List of users to assign */
        date_t             due_date,          /**< (I) Due date */
        int                attachment_count,  /**< (I) Attachment count */
        const tag_t*       attachment_list,   /**< (I) Attachment list */
        const int*         attachment_types,  /**< (I) Attachment types */
        const char*        container_uid,     /**< (I) Container object to relate process to */
        char*              relation_name,     /**< (I) Relation to use with container. If this is NULL,
                                                 its value is altered based on container class name.
                                                 For Folder classname, relationName is set to contents.
                                                 For Item classname, relationName is set to value of preferance Item_default_relation <br>*/
        tag_t*        new_process        /**< (O) New process */
        );


/**
   Retrieves the tasks of a specific state from the process.
*/
    extern EPM_API int EPM_ask_tasks(
        const tag_t    process,       /**< (I)  Process for which the tasks are required */
        EPM_state_t    task_state,    /**< (I)  Tasks only of this state will be returned */
        int*           count,         /**< (O)  Number of tasks of the specific state */
        tag_t**        tasks          /**< (OF) count List of tasks */
        );

/**
   Retrieves the dependency between the task and the predecessor task.
*/
    extern EPM_API int EPM_ask_task_result_dependency(
        const tag_t    dependent_task,        /**< (I) Task on which the dependency is required */
        const tag_t    predecessor_task,      /**< (I) Predecessor of the dependent task */
        int*           result                 /**< (O) Can be one of 0 ,1 or 2 depending on the predecessor task */
        );

/**
   Clears the process stage list for the task.
*/
    extern EPM_API int EPM_clear_process_stage(
        const          tag_t task          /**< (I) Task for which the process stage needs to be cleared */
        );

/**
   Retrieves all forms attached to this task.
*/
    extern EPM_API int EPM_ask_task_forms(
        const tag_t    task,     /**< (I)  Task on which forms are required */
        int*           count,    /**< (O)  Number of forms */
        tag_t**        forms     /**< (OF) count List of forms for the task */
        );

/**
   Retrieves unassigned profiles for this task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if signoff profile obtained is invalid
   </ul>
*/
    extern EPM_API int EPM_ask_unassigned_profiles(
        tag_t          job,                        /**< (I)  Job of the task */
        tag_t          task,                       /**< (I)  Task for which unassigned profiles are required */
        int*           count,                      /**< (O)  Number of unassigned profiles for the task */
        tag_t**        unassigned_profile_tags     /**< (OF) count List of profiles */
        );


/**
   Retrieves unassigned profile names for the task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if signoff profile obtained is invalid
   </ul>
*/
    extern EPM_API int EPM_ask_unassigned_profile_names(
        tag_t          task,                       /**< (I) The task. */
        int*           n_unassigned_profiles,      /**< (O) Number of unassigned profiles for the task. */
        char***        unassigned_profile_names    /**< (OF) n_unassigned_profiles List of unassigned profiles. 
                                                    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free 
                                                   on the container only. */
        );


/**
   Retrieves all the required signoff profiles for a task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if signoff profile obtained is invalid
   </ul>
*/
    extern EPM_API int EPM_ask_required_profile_names(
        tag_t          task,                       /**< (I)  Task tag */
        int*           n_required_signoffs,        /**< (O)  Number of required signoff profiles */
        char***        required_profile_names      /**< (OF) n_required_signoffs List of profiles
                                                  <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free 
                                                  on the container only. */

        );

/**
   Attaches sub-processes to a parent process.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_invalid_operation if subprocess is not of type EPMProcess
   <li>#EPM_cannot_attach_parent_process_to_task if subprocess is the parent process itself
   <li>#EPM_internal_error if error while extracing all subprocesses of parent process
   <li>#EPM_object_already_attached if sub-process to be attached is already a subprocess of the parent
   </ul>
*/

    extern EPM_API int EPM_attach_sub_processes(
        tag_t          parent_process_tag,         /**< (I) Parent process on which sub-processes are to be attached */
        int            count,                      /**< (I) Number of subprocesses */
        const tag_t*   secondary_processes_tags    /**< (I) count List of subprocesses */
        );

/**
   Removes sub-processes attached to a task.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_tag if parent process tag is invalid
   </ul>
*/
    extern EPM_API int EPM_remove_sub_processes(
        tag_t          parent_process_tag,         /**< (I) Parent process on which sub-processes are to be removed */
        int            count,                      /**< (I) Number of subprocesses */
        const tag_t*   secondary_processes_tags    /**< (I) count List of subprocesses */
        );

/**
   Retrieves sub-processes attached to a parent process.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_tag if parent process tag is invalid
   </ul>
*/
    extern EPM_API int EPM_ask_sub_processes(
        tag_t          parent_process_tag,         /**< (I)  Parent process on which sub-processes are to be obtained */
        int*           count,                      /**< (O)  Number of subprocesses */
        tag_t**        secondary_processes_tags    /**< (OF) count List of subprocesses */
        );

/**
   Retrieves parent processes for a sub-process.
*/
    extern EPM_API int EPM_ask_parent_processes(
        tag_t          subprocess_tag,            /**< (I)  Subprocess for which its parent processes are required */
        int*           count,                     /**< (O)  Number of parent processes for the subprocess */
        tag_t**        parent_processes_tags      /**< (OF) count List of parent processes */
        );


/**
    Deep copies existing Process Assignment List.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_copy_failed if copying the assignment list has failed.(e.g. @p assignment_list is incorrect, @p list_name already exists 
       or some internal error occurred during copy operation)
   <li>#EPM_assignment_list_invalid_object if the assignment list is NULL or an invalid object.(e.g. @p assignment_list is incorrect)
   <li>#EPM_assignment_list_already_exists and #EPM_assignment_non_unique_name if the assignment list name to be created already
       exists.(e.g. @p list_name already exists)
   </ul>
*/
    extern EPM_API int EPM_assignment_list_copy(
        const tag_t                   assignment_list,       /**< (I) Reference assignment list. */
        const char*                   list_name,             /**< (I) Name of the new assignment list. */
        const int                     n_descriptions,        /**< (I) Length of the description array. */
        const char**                  descriptions ,         /**< (I) n_descriptions Descriptions of the process assignment list. */
        const logical                 is_shared,             /**< (I) If @c true, creates a shared assignment list. */
        tag_t*                        new_assignment_list    /**< (O) Newly created assignment list. */
   );


/**
   Creates a Process Assignment List for a workflow process template.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_creation_failed if creation of resource list failed
   </ul>
*/

    extern EPM_API int EPM_assignment_list_create(
        const char*                   list_name,         /**< (I) Name of the new assignment list */
        int                           desc_length,       /**< (I) Length of the description */
        char**                       desc_array,        /**< (I) Description of the process assignment list */
        tag_t                         proc_template,     /**< (I) Process template for which the list is created */
        logical                       is_shared,         /**< (I) If true, create a shared assignment list */
        int                           resources_count,   /**< (I) Count of resources array */
        const tag_t*                  templates_array,   /**< (I) List of task templates to assign the resources to */
        const EPM_resource_list_t*    resources,         /**< (I) Resource list to be included in the assignment list */
        tag_t*                        new_assn_List      /**< (O) New assignment list */
        );

/**
   Modifies an existing Process Assignment List.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_modification_failed if resources is NULL or if failed to append the task templates and resources
   </ul>
*/

    extern EPM_API int EPM_assignment_list_edit(
        tag_t                         assn_list,         /**< (I) Assignment list to be edited */
        const char*                   list_name,         /**< (I) Assignment list name */
        int                           desc_length,       /**< (I) Decription length */
        char**                        desc_array,        /**< (I) Decription of assignment list */
        tag_t                         proc_template,     /**< (I) Process template */
        logical                       is_shared,         /**< (I) If true, create a shared list */
        int                           resources_count,   /**< (I) Count of resources array */
        const tag_t*                  templates_array,   /**< (I) List of task templates to assign the resources to */
        const EPM_resource_list_t*    resources          /**< (I) Resources for the assignment list*/
        );

/**
   Provides the details like process templates, resources etc of the process assignment list.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_ask_attr_failed if error occured while extracting name, description, task templates or resources
   <li>#EPM_no_proc_template_found if no process templates for the assignment list are found
   </ul>
*/
    extern EPM_API int EPM_assignment_list_describe(
        tag_t           assn_list,          /**< (I)  Assignmnet list tag */
        char**          list_name,          /**< (OF) Name of the assignment list */
        int*            desc_length,        /**< (O)  Description of the list */
        char***         desc_array,         /**< (OF) desc_length Descriptions */
        logical*        is_shared,          /**< (O)  True if assignment list is shared */
        tag_t*          proc_template,      /**< (O)  Process template in assignment list */
        int*            resources_count,    /**< (O)  Number of resources */
        tag_t**         templates_array,    /**< (OF) resources_count List of templates */
        tag_t**         resources           /**< (OF) resources_count List of resources */
        );

/**
   Creates an EPMResourceList Business Object.
*/
    extern EPM_API int EPM_resource_list_create(
        int          count,        /**< (I) Number of resources, profiles and actions */
        const tag_t  *resources,   /**< (I) Resources to be added to the object */
        const tag_t  *profiles,    /**< (I) Profiles to be added to the object */
        const int    *actions,     /**< (I) Action types to be added to the object */
        int          rev_quorum,    /**< (I) Review quorum */
        int          ack_quorum,    /**< (I) Acknowledge quorum */
        int          wait_for_undecided_reviewers, /**< (I) If true, wait for undecided reviewers */
        tag_t*       resource_list /**< (O) The new resource list created */
        );

/**
   Modifies an existing EPMResourceList Business Object.
*/
    extern EPM_API int EPM_resource_list_edit(
        tag_t         resource_list,  /**< (I) Resourcelist business object */
        int           count,          /**< (I) Number of resources, profiles and actions */
        const tag_t   *resources,     /**< (I) Resources to be added to the object */
        const tag_t   *profiles,      /**< (I) Profiles to be added to the object */
        const int     *actions,       /**< (I) Action types to be added to the object */
        int           rev_quorum,     /**< (I) Review quorum */
        int           ack_quorum,     /**< (I) Acknowledge quorum */
        int           wait_for_undecided_reviewers /**< (I) Wait for undecided reviewers setting */
        );

/**
   Retrieves details like resources, profiles actions etc from the existing EPMResourceList Business Object.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_resource_list_wrong_values if resource count and action count are different
   </ul>
*/
    extern EPM_API int EPM_resource_list_describe(
        tag_t   resource_list,                      /**< (I) Resourcelist business object  */
        int     *rev_quorum,                        /**< (O) Review quorum */
        int     *ack_quorum,                        /**< (O) Acknowledge quorum */
        int     *wait_for_undecided_reviewers,      /**< (O) Wait for undecided reviewers setting */
        int     *count,                             /**< (O) Number of resources, profiles and actions */
        tag_t   **resources,                        /**< (OF) count List of resources from the resourceList */
        tag_t   **profiles,                         /**< (OF) count List of profiles from the resourceList */
        int     **actions                           /**< (OF) count List of actions from the resourceList */
        );

/**
   Finds all the assignment lists where the given resource has been used.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_no_attr_of_this_name if attribute resource does not exists for class EPMAssignmentList or EPMResourceList
   </ul>
*/
    extern EPM_API int EPM_find_assignment_lists(
        tag_t    resource,         /**< (I)  Resource to be searched */
        int      *num_of_lists,    /**< (O)  Number of lists in which the resource is found */
        tag_t    **lists           /**< (OF) num_of_lists List of assignment lists */
        );

/**
   Replaces or removes the resource in the given Assignment Lists.\n
   If new_resource is a NULLTAG then old resource will be removed.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_ask_attr_failed if no resource attribute query failed
   <li>#EPM_failed_to_replace_resource if failed to replace or remove resource
   </ul>
*/
    extern EPM_API int EPM_replace_resource_in_lists(
        int      count,                   /**< (I) Number of assignment lists */
        const tag_t    *assn_lists,       /**< (I) Count number of assignment lists from which the resource should be replaced */
        tag_t    old_resource,            /**< (I) Resource to be replaced */
        tag_t    new_resource             /**< (I) New resource that replaces the old resource. If NULLTAG then old resource will be removed */
        );

/**
   Finds the assignment list by the name.
*/
    extern EPM_API int  EPM_get_assignment_list(
        char    *list_name,  /**< (I) Name of the assignment list */
        tag_t   *assn_list   /**< (O) Assignment list tag */
        );

/**
   Returns all the assignment list objects in the database.
*/
    extern EPM_API int EPM_assignment_list_extent(
        int*     n_instances,   /**< (O) Number of instances */
        tag_t**  instance_tags  /**< (OF) n_instances List of instances */
        );

/**
   Retrieves all the assignment lists of the logged-in user, of its group  and also other assignments lists.
*/
    extern EPM_API int EPM_get_all_assignment_lists(
        int*     n_own_lists,        /**< (O)  Number of assignment lists of logged-in user */
        tag_t**  own_list_tags,      /**< (OF) n_own_lists List of assignment lists owned by logged-in user */
        int*     n_group_lists,      /**< (O)  Number of assignment lists of group of logged-in user*/
        tag_t**  group_list_tags,    /**< (OF) n_group_lists List of assignment lists of the logged-in user's group */
        int*     n_other_lists,      /**< (O)  Number of all other assignments lists */
        tag_t**  other_list_tags     /**< (OF) n_other_lists List of other assignment lists */
        );

/**
   This ITK assigns an assignment list to a process.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_ask_attr_failed if failed to fetch task_templates or resources attributes of assignment list
   <li>#EPM_resource_list_wrong_values if resource count and action count are different
   <li>#EPM_failed_to_assign_resource if failed to assign resource for a task
   </ul>
*/
    extern EPM_API int EPM_assign_assignment_list(
        tag_t    process,             /**< (I)  Process to be assigned */
        tag_t    assignment_list      /**< (I)  List to which the process is to be assigned */
        );

/**
   Assigns all the tasks in a workflow process:
   <ul>
   <li>if the assignment list is not null, using the assignment list
   <li>if the assignment list if null, it assigns all the tasks using the resources list.
   <br>In such a case the parameters num_of_templates, task_templates and resources should be specified.
   </ul>
   <br>The function returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_assignment_list_ask_attr_failed if failed to fetch task_templates or resources attributes of assignment list
   <li>#EPM_resource_list_wrong_values if resource count and action count are different
   <li>#EPM_failed_to_assign_resource if failed to assign resource for a task
   </ul>
*/
    extern EPM_API int EPM_assign_to_all_tasks(
        tag_t                          assignment_list,     /**< (I)  Assignment list using which tasks from the process are assigned. Can be NULLTAG */
        int                            num_of_templates,    /**< (I)  Number of task templates */
        const tag_t*                   task_templates,      /**< (I)  Task templates to which the resources are to be assigned */
        const EPM_resource_list_t*     resources,           /**< (I)  Resources to be assigned to task templates */
        tag_t                          process              /**< (I)  Process to be assigned to assignment list */
        );

/**
   Sets the surrogate user for user inbox.
*/
    extern EPM_API int EPM_set_surrogate_user(
        tag_t   user,                /**< (I) User for which surrogate user is required */
        tag_t   surrogate_user,      /**< (I) Surrogate user */
        date_t  start_date,          /**< (I) Start date for the surrogate */
        date_t  end_date             /**< (I) End date till the surrogate is active */
        );

/**
   Removes the surrogate user for user inbox.
*/
    extern EPM_API int EPM_remove_surrogate_user(
        tag_t   user,              /**< (I) User for which surrogate user is to be removed */
        tag_t   surrogate_user,    /**< (I) Surrogate user */
        int     *count,            /**< (O) Number of claimed tasks */
        tag_t   **claimed_tasks    /**< (OF) count List of claimed tasks */
        );

/**
   Sets the logged in user as the active surrogate on task or signoff. \n
   Any exceptions encountered during tranfer of surrogates are stored in exceptions_list.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if current user tag obtained is NULLTAG
   <li>#EPM_not_valid_surrogate if signoff, and signoff user is not a valid surrogate or if current user cannot be set as surrogate for task
   <li>#EPM_standin_action_not_supported if responsible party for the task is a resourcepool
   </ul>
*/
    extern EPM_API int EPM_claim_as_surrogate(
        tag_t    task_or_signoff,    /**< (I)  Task or signoffs on which the logged-in user is assigned a surrogate */
        logical  xfer_checkouts,     /**< (I)  If true, transfer the checked out objects from the old surrogate to new */
        int      *exceptions_count,  /**< (O)  Number of exceptions encountered during transfer of checkouts */
        tag_t    **exceptions_list   /**< (OF) exceptions_count List of exceptions */
        );

/**
   Retrieves current surrogates for the users as of current date. If users contains an tags which are not TC users,
   those tags are ignored.
*/
    extern EPM_API int EPM_get_current_surrogates(
        int             user_count,        /**< (I)  Number of users */
        const tag_t*    users,             /**< (I)  User list for which surrogates are requested */
        int*            surrogate_count,   /**< (O)  Number of surrogates for users */
        tag_t**         surrogate_users    /**< (OF) surrogate_count List of surrogates */
        );

/**
   Releases the claim from active surrogate on task or signoff.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_internal_error if current user tag obtained is NULLTAG
   <li>#EPM_not_valid_surrogate if signoff, and signoff user is not a valid surrogate or current user is not the responsible party of the task
   </ul>
*/

    extern EPM_API int  EPM_release_claim(
        tag_t   task_or_signoff,    /**< (I)  Task or surrogate on which the claim is to be released */
        logical xfer_checkouts,     /**< (I)  If true, transfer the checkouts from surrogate user to owner*/
        int     *exceptions_count,  /**< (O)  Number of exceptions encountered during transfer of checkouts */
        tag_t   **exceptions_list   /**< (OF) exceptions_count List of exceptions */
        );

/**
   Fetches the assignments lists for a particular job.
*/
    extern EPM_API int EPM_get_assignmentlists_by_job(
        tag_t    job_tag,            /**< (I)  Job on which the lists are required */
        int*     n_own_lists,        /**< (O)  Logged-in user assignment list count */
        tag_t**  own_list_tags,      /**< (OF) n_own_lists List of assignment lists */
        int*     n_group_lists,      /**< (O)  Logged-in user group assignment list count */
        tag_t**  group_list_tags,    /**< (OF) n_group_lists List of group assignment lists */
        int*     n_other_lists,      /**< (O)  Other assignment list count */
        tag_t**  other_list_tags     /**< (OF) n_other_lists List of other assignment lists */
        );

/**
   Fetches the process template for a particular assignment list.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_no_proc_template_found if process template not found
   </ul>
*/
    extern EPM_API int EPM_assnlist_get_proc_template(
        tag_t    assn_list,          /**< (I) Assignment list */
        tag_t*   process_template    /**< (O) Process template for the assignment list */
        );

/**
   Sets the result for a task, given the task tag.
*/
    extern EPM_API int EPM_set_task_result(
        tag_t          task,                 /**< (I) The task tag */
        const char*    result                /**< (I) The task's  result value to be set.
                                                It can be: EPM_RESULT_Unset
                                                EPM_RESULT_Completed
                                                EPM_RESULT_Approved
                                                EPM_RESULT_Rejected
                                                EPM_RESULT_Unable_to_complete
                                                EPM_RESULT_True
                                                EPM_RESULT_False
                                                EPM_RESULT_No_error
                                                It can be any string for a Condition task.
                                                <br> */
        );

/**
   Retrieves the result of a task.
*/
    extern EPM_API int EPM_get_task_result(
        tag_t          task,               /**< (I) The task tag */
        char**         result              /**< (OF) The task's result value.
                                              It can be: EPM_RESULT_Unset
                                              EPM_RESULT_Completed
                                              EPM_RESULT_Approved
                                              EPM_RESULT_Rejected
                                              EPM_RESULT_Unable_to_complete
                                              EPM_RESULT_True
                                              EPM_RESULT_False
                                              EPM_RESULT_No_error
                                              It can be any string for a Condition task.
                                              <br> */

        );


/**
   Adds group members as reviewers for a select signoff team task

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_already_completed if select signoff team task is already completed
   </ul>
*/
    extern EPM_API int EPM_add_reviewers_on_task (
        tag_t          sst_task,               /**< (I) select signoff team task to add reviewers */
        logical        add_excess_as_adhoc,    /**< (I) If true then adds reviewers which could not be added to profiles as adhoc */
        int            n_group_members,        /**< (I) Number of group members to be added as reviewers */
        const tag_t *  group_members           /**< (I) Group members to be added as reviewers */
        );

/**
   Adds group members as reviewers for a select signoff team task. Reviewer may be required or optional specified by
   signoffRequired parameter.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_already_completed if select signoff team task is already completed
   </ul>
*/
    extern EPM_API int EPM_add_reviewers_on_task_with_signoff (
        tag_t          sst_task,               /**< (I) select signoff team task to add reviewers */
        logical        add_excess_as_adhoc,    /**< (I) If true then adds reviewers which could not be added to profiles as adhoc */
        int            n_group_members,        /**< (I) Number of group members to be added as reviewers */
        const tag_t *  group_members,          /**< (I) Group members to be added as reviewers */
        const char *   signoff_required         /**< (I) Indicates whether signoff is Optional or Required
                                                        <br/>Possible values are the internal names of LOV "Fnd0DecisionRequired"
                                                        <br/>If null pointer is provided, the ITK behaviour is similar to #EPM_add_reviewers_on_task. */
        );                                              

/**
   Retrieves the @c wait_for_undecided_reviewers value of a Review task.
*/
    extern EPM_API int EPM_get_wait_for_undecided_reviewers(
        tag_t          task,                     /**< (I) The task tag */
        int*           undecided_reviewer_count  /**< (O) The Review task's wait_for_undecided_reviewers value. It can be: 0 or 1<br> */
        );


/**
   Creates a Participant object of type participant_type and sets its
   attribute to the specified assignee.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_internal_error if unable to save new participant for assignee
   </ul>
*/
    extern EPM_API int EPM_create_participant(
        tag_t        assignee,                       /**< (I) The assignee tag. This can be either a group member tag or a resource pool tag. */
        tag_t        participant_type,               /**< (I) The type of participant that needs to be created */
        tag_t*       participant                     /**< (O) The tag of the new participant object */
        );


/**
    Creates participant objects corresponding to @p participant_type_list and updates its 
    attribute to the assignees as specified by @p assignee_list

    <br/>The create operation is rolled back in case of error. 

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_value if invalid values of assignees are passed.
   <li>#TYPE_unknown_type if invalid participant types are passed. 
   </ul>
*/
extern EPM_API int EPM_create_participants(
    int                assignee_count,            /* <I>  Total number of assignees. */ 
    const tag_t*       assignee_list,             /* <I>  List of assignees. */
    const tag_t*       participant_type_list,     /* <I>  List of participant types. */
    int*               participant_count,         /* <O>  Total number of participants. */
    tag_t**            participant_list           /* <OF> participantCount Participants corresponding to assignees and participant types. */
);


/**
   Retrieves the participant type based on the type name.
*/
    extern EPM_API int EPM_get_participanttype(
        char*       type_name,                         /**< (I) Participant type name */
        tag_t*      participant_type                   /**< (O) Participant type for the name */
        );

/**
   Retrieves a list of participants which correspond to the keywords specified in @p participant_value.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#WSOUIF_object_not_found for addresslist type, if address list is not found for the participant
   <li>#EPM_target_object_not_attached for $TARGET, if no target attachments are found for the task
   </ul>
*/
    extern EPM_API int EPM_get_participants(
        const char* participant_value,     /**< (I)  The keyword for which the members are required. For ex. $PROCESSOWNER, user:Smith, resourcepool:manufacturing::engineer etc. Can be comma-seperated list */
        tag_t       task,                  /**< (I)  The task for which the participant_value is to be evaluated. */
        int*        member_count,          /**< (O)  The total number of group members corresponding to participant_type.  */
        tag_t**     members,               /**< (OF) member_count Group members corresponding to participant_type. */
        int*        rp_count,              /**< (O)  The total number of resource pools corresponding to participant_type. */
        tag_t**     rps,                   /**< (OF) rp_count Resource pools corresponding to participant_type. */
        logical     single_participant     /**< (I)  If true, members of only first participant_type (in a comma-seperated list) are returned. */
        );

/**
   Retrieves a single participant which correspond to the keywords specified in @p participant_value.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#WSOUIF_object_not_found for addresslist type, if address list is not found for the participant
   <li>#EPM_target_object_not_attached for $TARGET, if no target attachments are found for the task
   </ul>
*/
    extern EPM_API int EPM_get_participant(
        const char* participant_value,     /**< (I) The keyword for which the member is required. For ex. $PROCESSOWNER, user:Smith, resourcepool:manufacturing::engineer etc. */
        tag_t       task,                  /**< (I) The task for which the participant_value is to be evaluated. */
        tag_t*      member,                /**< (O) The group member corresponding to the participant_ value. */
        tag_t*      rp,                    /**< (O) The resource pool corresponding to the participant_ value. */
        logical*    is_resourcepool        /**< (O) Indicates if the member being returned is a resource pool. */
        );

/**
   Allows the logged-in user to claim a task assigned to a resource pool.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EPM_no_privilege_to_assign if user do not have sufficient privileges to assign
   <li>#EPM_delegate if delegate fails
   </ul>
*/
    extern EPM_API int EPM_claim_task(
        tag_t                 task_tag,                          /**< (I) Tag of the task to be claimed */
        tag_t                 signoff                            /**< (I) Tag of the signoff object, for a perform-signoff task */
        );

/*
    Checks if the provided Task is claimable by the currently logged-in user.

    If the task is assigned to resource pool and the logged-in user is 
    neither dba, nor the task responsible party, nor the owner of the job, the returned value @p allow_claim is false. 
    <br/>Otherwise, the returned value @p allow_claim is true.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#EPM_invalid_argument if the @p task is #NULLTAG
    <li>#EPM_invalid_object if the @p is not a valid Task
    </ul>

*/
extern EPM_API int EPM_is_task_claimable(
    tag_t          task,            /**< (I) Tag of the task to be checked for claim */
    logical*       allow_claim      /**< (O) The flag indicating if task is claimable or not */
    );

/*
    Checks if the logged-in User has the specified privilege on the target object(s) of a given task.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#EPM_invalid_object if the input task tag is incorrect
    <li>#EPM_access_denied if the privilege name is incorrect
    </ul>
*/
extern EPM_API int EPM_check_access(
    tag_t         task,            /**< (I) Task tag */
    const char *  privilege,       /**< (I) Privilege name. Choices are READ, WRITE, DELETE, CHANGE, PROMOTE, DEMOTE, COPY, IMPORT, EXPORT, TRANSFER_IN and TRANSFER_OUT.*/
    logical*      verdict          /**< (O) Specifies whether the privilege is granted or revoked. */
    );

/**
    Advances or demotes the currently started Task based on the state of the provided Task.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_invalid_object if @p task is #NULLTAG.
    </ul>
*/
extern EPM_API int EPM_trigger_advancer(
    const    tag_t          task           /**< (I) The Task/Subtask object that will trigger the advancement */
    );

#ifdef __cplusplus
}
#endif

/**
   @name Obsolete definitions
   @{
*/
#define EBR_decision_t                  EPM_decision_t            /**< decision on the task */
#define EBR_undecided                   EPM_undecided            /**< no decision */
#define EBR_nogo                        EPM_nogo                /**< decision will stall the workflow process */
#define EBR_go                          EPM_go                    /**< decision will make the workflow process get started */

#define EPM_task_action_t               EPM_action_t            /**< Trigger actions on the task */
#define EPM_task_state_t                EPM_state_t                /**< Task states */

#define EPM_assign_task                 EPM_assign_action        /**< Assign action for task */
#define EPM_start_task                  EPM_start_action        /**< Start action for task */
#define EPM_complete_task               EPM_complete_action        /**< Complete action for task */
#define EPM_skip_task                   EPM_skip_action            /**< Skip action for task */
#define EPM_suspend_task                EPM_suspend_action        /**< Suspend action for task */
#define EPM_resume_task                 EPM_resume_action        /**< Resume action for task */
#define EPM_undo_task                   EPM_undo_action            /**< Undo action for task */
#define EPM_abort_task                  EPM_abort_action        /**< Abort action for task */
#define EPM_do_task                     EPM_perform_action        /**< Perform action for task */
#define EPM_project_task_attachment     EPM_schedule_task_attachment
/** @} */

/** @} EPM group */

#include <epm/libepm_undef.h>
#endif
