/*
  Copyright 2020 Siemens Digital Industries Software
  ==================================================
  Copyright 2010.
  Siemens Product Lifecycle Management Software Inc.
  All Rights Reserved.
  ==================================================
  Copyright 2020 Siemens Digital Industries Software
*/


/**
    @file schmgt_itk.h
*/

#ifndef SCHMGTITK_H
#define SCHMGTITK_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>
#include <schmgt/libschmgt_exports.h>

/**
    @defgroup SCHEDULE_MANAGEMENT Schedule Management
    @{
*/

/** The request to update the information in a Schedule Task. */
typedef struct ExecUpdateRequest_s
{
    tag_t task;         /**< The tag of the task being updated */
    logical updateAS;   /**< true if updating the actual start date */
    date_t newAS;       /**< The new actual start date (null allowed) */
    logical updateAF;   /**< true if updating the actual finish date */
    date_t newAF;       /**< The new actual finish date (null allowed) */
    int updateAW;       /**< The updated approved work (for use with the timesheet system) (use 0 if no change) */
    double newPC;       /**< The new percent complete (use -1 if no change is requested) */
    int newStatus;      /**< The new status (use -1 if no change is requested) */
    int newWC;          /**< The new work complete (use -1 if no change is requested) */
    int newWR;          /**< The new work remaining (use -1 if no change is requested) */
} ExecUpdateRequest_t;


/** The request to update the information in a Schedule Task. */
typedef struct ExecutionUpdateRequest_s
{
    tag_t task;             /**< The tag of the task being updated */
    logical updateAS;       /**< true if updating the actual start date */
    date_t newAS;           /**< The new actual start date (null allowed) */
    logical updateAF;       /**< true if updating the actual finish date */
    date_t newAF;           /**< The new actual finish date (null allowed) */
    int updateAW;           /**< The updated approved work (for use with the timesheet system) (use 0 if no change) */
    double newPC;           /**< The new percent complete (use -1 if no change is requested) */
    int newWC;              /**< The new work complete (use -1 if no change is requested) */
    int newWR;              /**< The new work remaining (use -1 if no change is requested) */
    char* newFnd0Status;    /**< The new fnd0status (use -1 if no change is requested) */
} ExecutionUpdateRequest_t;


typedef struct ProxyCreate_s
{
    tag_t schedule;     /**< The tag of the schedule where the proxy will be created*/
    tag_t home_task;    /**< The tag of the task to be proxied */
    tag_t ref_task;     /**< The tag of the task where the proxy should be placed */
} ProxyCreate_t;

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * This function updates the execution data for a schedule task.
     */
    extern SCHMGT_API int SCHMGT_update_tasks_exec_data (
        ExecUpdateRequest_t *request,    /**< (I) The update requests */
        int size                        /**< (I) The number of requests */);

    /**
     * This function updates the execution data for a schedule task.
     */
    extern SCHMGT_API int SCHMGT_update_task_exec_data (
        tag_t task,          /**< (I) The tag of the task being updated */
        logical updateAS,    /**< (I) true if updating the actual start date */
        date_t newAS,        /**< (I) The new actual start date (null allowed) */
        logical updateAF,    /**< (I) true if updating the actual finish date */
        date_t newAF,        /**< (I) The new actual finish date (null allowed) */
        int updateAW,        /**< (I) The updated approved work (for use with the timesheet system) (use 0 if no change) */
        double newPC,        /**< (I) The new percent complete (use -1 if no change is requested) */
        int newStatus,       /**< (I) The new status (use -1 if no change is requested) */
        int newWC,           /**< (I) The new work complete (use -1 if no change is requested) */
        int newWR            /**< (I) The new work remaining (use -1 if no change is requested) */
        );

    /**
    * @deprecated #SCHMGT_copyTaskWithPasteSpecial deprecated in Teamcenter 11.2.3. Use #SCHMGT_copy_tasks_with_paste_special instead.

    * This ITK will perform paste operation of copied schedule tasks to target Schedule task.
    * Target Schedule task may be a normal task or Summary task or Schedule Summary task.
    * Copied Schedule tasks may be normal tasks or Summary task with recursively having child tasks
    * and summary tasks or Schedule Summary task. As per the logical options provided it will perform
    * creating dependencies, creating Assignments, creating Members, etc.
    */
    TC_DEPRECATED("11.2.3", "SCHMGT_copyTaskWithPasteSpecial", "SCHMGT_copy_tasks_with_paste_special" )
    extern SCHMGT_API int SCHMGT_copyTaskWithPasteSpecial(
        tag_t fromSchedule,                /**< (I)  The tag of the selected Schedule */
        tag_t* tasks,                      /**< (I)  The list of Schedule tasks to paste */
        int numberOfTasks,                 /**< (I)  The number of tasks to paste */
        tag_t toSchedule,                  /**< (I)  The tag of the target Schedule */
        tag_t targetTask,                  /**< (I)  The tag of the target Schedule Task */
        int pasteType,                     /**< (I)  The option for paste Type */
        int numberOfCopies,                /**< (I)  The number of times the paste operation to perform */
        logical offsetCalculate,           /**< (I)  The option to calculate the offset of the Tasks */
        logical includeAssignments,        /**< (I)  The option to create new Assignments */
        logical includeDependencies,       /**< (I)  The option to create new Dependencies */
        logical includeDeliverables,       /**< (I)  The option to create new Deliverables */
        logical useExistingDeliverables,   /**< (I)  The option to use existing Deliverables */
        logical updateMembership,          /**< (I)  The option to create new members */
        logical resetDeliverables,         /**< (I)  The option to reset the Deliverables */
        logical copyWorkflow,              /**< (I)  The option to copy work flow content */
        logical copyCost,                  /**< (I)  The option to copy cost information */
        logical asynchRecalculateSchedule, /**< (I)  The option to execute the validation of Schedule Engine */
        int* numberOfIfails,               /**< (O)  The number of ifails and failed tasks */
        int** ifails,                      /**< (OF) numberOfIfails The ifail values for failed tasks */
        tag_t** failedTasks,               /**< (OF) numberOfIfails The failed tasks list */
        int* numberOfCreatedTasks,         /**< (O)  The number of created Schedule tasks */
        tag_t** createdTasks               /**< (OF) numberOfCreatedTasks The list of created Schedule tasks */
        );


    /**
     * This function sets the status of the schedule.
     */
    extern SCHMGT_API int SCHMGT_set_schedule_status (
        tag_t schedule, /**< (I) The schedule tag */
        char* status    /**< (I) Status of the schedule*/
        );

    /**
     * This function sets the status of the schedule task.
     */
    extern SCHMGT_API int SCHMGT_set_task_status (
        tag_t task,     /**< (I) The schedule task tag */
        char* status    /**< (I) Status of the schedule*/
        );

    /**
     * This function sets the percent complete of the schedule task.
     */
    extern SCHMGT_API int SCHMGT_set_percent_complete (
        tag_t task,         /**< (I) The schedule task tag */
        double pcomplete    /**< (I) percent complete of the task*/
        );

    /**
     * This function sets the work complete of the schedule task.
     */
    extern SCHMGT_API int SCHMGT_set_work_complete (
        tag_t task,     /**< (I) The schedule task tag */
        int wcomplete   /**< (I) work complete of the task*/
        );

    /**
     * This function sets the Actual start date of the schedule task.
     */
    extern SCHMGT_API int SCHMGT_initialize_actual_start_date (
        tag_t task /**< (I) The schedule task tag */
        );

    /**
     * This function sets the Actual finish date of the schedule task.
     */
    extern SCHMGT_API int SCHMGT_initialize_actual_finish_date (
        tag_t task /**< (I) The schedule task tag */
        );

    /**
     * This function updates the execution data for a schedule task.
     */
    extern SCHMGT_API int SCHMGT_update_task_exec_data1 (
        tag_t task,         /**< (I) The tag of the task being updated */
        logical updateAS,   /**< (I) true if updating the actual start date */
        date_t newAS,       /**< (I) The new actual start date (null allowed) */
        logical updateAF,   /**< (I) true if updating the actual finish date */
        date_t newAF,       /**< (I) The new actual finish date (null allowed) */
        int updateAW,       /**< (I) The updated approved work (for use with the timesheet system) (use 0 if no change) */
        double newPC,       /**< (I) The new percent complete (use -1 if no change is requested) */
        int newWC,          /**< (I) The new work complete (use -1 if no change is requested) */
        int newWR,          /**< (I) The new work remaining (use -1 if no change is requested) */
        char* fnd0status    /**< (I) The new string status (use "-1" if no change is requested) */
        );

    /**
     * This function updates the execution data for a schedule task.
     */
    extern SCHMGT_API int SCHMGT_update_tasks_exec_data1 (
        ExecutionUpdateRequest_t *request, /**< (I) The update requests */
        int size,                          /**< (I) The number of requests */
        int *noTaksUpdated,                /**< (O) The number of requests */
        tag_t **updatedTasks               /**< (OF) The number of requests */
        );

    /**
     * @deprecated #SCHMGT_create_proxy_tasks deprecated in Teamcenter 11.2.3. Use #SCHMGTBRI_create_proxy_tasks instead.

     * This function creates FND0ProxyTasks.
     */
    TC_DEPRECATED("11.2.3", "SCHMGT_create_proxy_tasks", "SCHMGTBRI_create_proxy_tasks" )
    extern SCHMGT_API int SCHMGT_create_proxy_tasks (
        ProxyCreate_t *createContainers /**< (I) The create containers */,
        int numberOfCreates             /**< (I) The number of created */,
        tag_t **createdProxies          /**< (OF) The created proxy tasks*/
        );

    /**
        Retrieves the Schedule Tasks in a given state for the logged-in user.
        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#SCHMGT_Invalid_Argument if @p state is a null pointer or not a valid Task state
        </ul>
    */
    extern SCHMGT_API int SCHMGT_get_schedule_tasks_for_user (
        const char* state,        /**< (I) State of the Schedule Task. <br/>Valid values are not_started, in_progress, complete, closed, aborted. */
        int* num_tasks,           /**< (O) Number of Schedule Tasks */
        tag_t** schedule_tasks    /**< (OF) num_tasks The Schedule Tasks */
        );

#ifdef __cplusplus
}
#endif

/**
   @}
*/

#include <schmgt/libschmgt_undef.h>
#endif
