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

   This header file declares data types and ITKs to be used by customers of Teamcenter Schedule Management
*/

#ifndef SCHMGTBRIITK_H
#define SCHMGTBRIITK_H
#include <tc/tc_startup.h>
#include <base_utils/Mem.h>

#include <schmgt/schmgt_itk.h>
#include <common/tc_deprecation_macros.h>
#include <schmgt_bridge/libschmgt_bridge_exports.h>

/**
   @defgroup SCHMGT_BRIDGE Schedule Management Bridge
   @ingroup SCHMGT
   @{
*/
#define RECALCULATE_EXEC       1 /**< Recalculate the execution data */
#define RECALCULATE_SCHED      2 /**< Recalculate the scheduling data */
#define RECALCULATE_ALL        0 /**< Recalculate both scheduling and execution data */
#define NUM_OF_ATTRIBS         32 /**< The maximum size of arrays in these structures */
#define PASTE_AFTER            2 /**< The Schedule Task is pasted below the target Schedule Task.*/
#define PASTE_UNDER            1 /**< The Schedule Task is pasted as a child of the target Schedule Task.*/

#ifdef __cplusplus
extern "C" {
#endif

/**
  Holds attribute values to update.
*/
typedef struct AttributeUpdateContainer_d
{
    char* attrName;     /**< The attribute name. */
    char* attrValue;    /**< The attribute value. In case of date value, use toString() function in Teamcenter::DateTime to get the value as string.
                        <ul>
                        <li>0: Use the DateTime::DateTime(int year,int month,int day,int hour=0,int minutes=0,int seconds=0) API to construct date string.
                        </ul>
                        */
    int attrType;       /**< The attribute type: 0-char, 1-date, 2-double, 3-float, 4-int, 5-boolean, 6-short, 7-string, 8-reference. Currently unused. */
} AttributeUpdateContainer_t;

/**
  Holds custom attribute values to update.
*/
typedef struct TypedAttributeUpdateContainer_d
{
    char* objectType;                                   /**< The object type. Valid types are "ScheduleTaskType" and "ScheduleType". */
    int updatesSize;                                    /**< The number of attribute updates. */
    AttributeUpdateContainer_t updates[NUM_OF_ATTRIBS]; /**< The attribute updates. */
} TypedAttributeUpdateContainer_t;

/**
  Holds information to create a Schedule Task.
*/
typedef struct TaskCreateContainer_d
{
    tag_t newTag;                                                           /**< The tag for the new task generated using POM_allocate_tag. Currently unused. */
    char* name;                                                             /**< The name. */
    char* desc;                                                             /**< The description. */
    char* objectType;                                                       /**< The business object type to create. */
    date_t start;                                                           /**< The start date. */
    date_t finish;                                                          /**< The finish date. */
    int workEstimate;                                                       /**< The work estimate in minutes. */
    tag_t parent;                                                           /**< The tag of the parent Task. */
    tag_t prevSibling;                                                      /**< The tag of its previous sibling. */
    int otherAttributesSize;                                                /**< The number of other attributes. */
    AttributeUpdateContainer_t otherAttributes[NUM_OF_ATTRIBS];             /**< Additional out-of-the-box (OOTB) attributes */
    int typedAttrContSize;                                                  /**< The number of custom attributes */
    TypedAttributeUpdateContainer_t typedOtherAttributes[NUM_OF_ATTRIBS];   /**< The custom attributes */
} TaskCreateContainer_t;


/**
  Holds information to update a scheduling object.
*/
typedef struct ObjectUpdateContainer_d
{
    tag_t object;                                                   /**< The object to update. */
    int updatesSize;                                                /**< The number of OOTB updates. */
    AttributeUpdateContainer_t updates[NUM_OF_ATTRIBS];             /**< The OOTB attributes to update. */
    int typedUpdatesSize;                                           /**< The number of custom updates. */
    TypedAttributeUpdateContainer_t typedUpdates[NUM_OF_ATTRIBS];   /**< The custom attributes to update. */
} ObjectUpdateContainer_t;


/**
  Holds information to move a Task.
*/
typedef struct MoveRequest_d
{
    tag_t task;        /**< The Task to move. */
    tag_t newParent;   /**< The new parent of the Task. */
    tag_t prevSibling; /**< The Task above the requested location. */
} MoveRequest_t;

/**
   Holds information to create an assignment.
*/
typedef struct AssignmentCreate_d
{
    tag_t newAssignTag;         /**< The tag for the new assignment generated using POM_allocate_tag. Currently unused. */
    char* taskID;               /**< The UID of the Task being assigned. */
    char* assigneeID;           /**< The UID of the User being assigned. */
    char* disciplineID;         /**< The UID of the Discipline being assigned. */
    double assignedPercentage;  /**< The percentage assigned. */
} AssignmentCreate_t;

/**
   Holds information to update an assignment.
*/
typedef struct AssignmentUpdate_d
{
    tag_t assignment;           /**< The assignment being updated. */
    double assignedPercentage;  /**< The new percentage to be assigned. */
} AssignmentUpdate_t;


/**
   Holds information to create a dependency (or Cross Schedule Dependency)
*/
typedef struct DependencyCreate_d
{
    tag_t newDependencyTag; /**< The tag for the new dependency generated using POM_allocate_tag. Currently unused. */
    tag_t pred_task;        /**< The predecessor Task. */
    tag_t succ_task;        /**< The successor Task. */
    int dep_type;           /**< The dependency type. Valid values are:
                               <ul>
                               <li>0: Finish to Start
                               <li>1: Finish to Finish
                               <li>2: Start to Start
                               <li>3: Start to Finish
                               </ul> */
    int lag_time;           /**< The lag time in minutes. */
} DependencyCreate_t;

/**
   Holds information to update a dependency by providing a new lag and type.
*/
typedef struct DependencyUpdate_d
{
    tag_t dependency;       /**< The dependency to update. */
    int new_type;           /**< The dependency type. Valid values are:
                               <ul>
                               <li>0: Finish to Start
                               <li>1: Finish to Finish
                               <li>2: Start to Start
                               <li>3: Start to Finish
                               </ul> */
    int new_lag;            /**< The new lag time in minutes. */
} DependencyUpdate_t;


/**
   Holds information to add a member to a given schedule.
*/
typedef struct AddMembers_d
{
    tag_t schedule;         /**< The Schedule. */
    char* resource_id;      /**< The UID of the User being added. */
    int membership_level;   /**< The membership level in that schedule. Valid values are:
                               <ul>
                               <li>0: Observer
                               <li>1: Participant
                               <li>2: Coordinator
                               </ul> */
    char* cost;             /**< The cost value using '.' as a decimal separator (e.g. "15.3"). */
    char* currency;         /**< The ISO-4217 currency code. */
} AddMembers_t;


/**
   Holds information to insert a sub schedule inside master schedule.
*/
typedef struct InsertScheduleContainer_d
{
    tag_t sub_schedule;           /**< Sub schedule tag which needs to be inserted. */
    tag_t master_schedule;        /**< Master schedule tag inside which sub schedule needs to be inserted.*/
    tag_t master_schedule_task;   /**< Reference of master schedule task under which sub schedule needs to be inserted.*/
    bool adjust_master_dates;     /**< Boolean value of true will allow the master start and/or end date to automatically adjust if
                                     the sub schedule start and/or finish date do not lie between the master dates. */
}SCHMGT_insert_schedule_container_t;


/**
   Holds information to detach a sub schedule from master schedule.
*/
typedef struct DetachScheduleContainer_d
{
    tag_t sub_schedule;      /**< The schedule that is being detached from the master schedule. */
    tag_t master_schedule;   /**< The master schedule from which the subSchedule is being detached. */
}SCHMGT_detach_schedule_container_t;


/**
   Holds information to create a schedule deliverable.
*/
typedef struct ScheduleDeliverableData_d
{
    tag_t schedule;             /**< The schedule to contain this deliverable. This is required. */
    char* deliverable_type;     /**< The type of the deliverable. This is required. */
    char* deliverable_name;     /**< The name of the deliverable. This is required.*/
    tag_t deliverable_reference; /**< A reference to the deliverable.(optional) */
}SCHMGT_schedule_deliverable_data_t;

/**
   Holds information to create a schedule task deliverable.
*/
typedef struct ScheduleTaskDeliverableData_d
{
    tag_t schedule_task;             /**< The task which will contain this delievable. */
    tag_t schedule_deliverable;      /**< The schedule deliverable to reference. */
    int  submit_type;                /**< The submit type. Valid values are:
                                        <ul>
                                        <li>0: Submit as target
                                        <li>1: Submit as reference
                                        <li>3: Don't submit
                                        </ul> */
}SCHMGT_schedule_task_deliverable_data_t;

/**
   Holds information to create a Schedule.
*/
typedef struct NewScheduleContainer_d
{
    char* name;                                                               /**< The name. Valid value cannot be null. */
    char* description;                                                        /**< The description. Valid value can be empty string. */
    char* id;                                                                 /**< Id. Valid value cannot be null. */
    char* customer_name;                                                      /**< The customer's name. Valid value can be empty string */
    char* customer_number;                                                    /**< The customer's ID. Valid value can be empty string. */
    date_t start_date;                                                        /**< The start Date. Valid value cannot be null. */
    date_t finish_date;                                                       /**< The finishDate. Valid value cannot be null. */
    int priority;                                                             /**< The priority. Valid values are {0-lowest,1-low,2-MediumLow,3-Medium,4-High,5-VeryHigh,6-Highest}. */
    bool dates_linked;                                                        /**< areDatesLinked? */
    bool published;                                                           /**< Indicates whether the schedule is published. Valid values - true or false. */
    bool notifications_enabled;                                               /**< Indicates whether notifications should be enabled. Valid values - true or false. */
    bool percent_linked;                                                      /**< Indicates whether percentage complete should be linked to work complete.Valid values - true, false. */
    bool is_template;                                                         /**< Indicates whether the schedule is a template. Valid values - true, false. */
    bool is_public;                                                           /**< Indicates whether the schedule is public. Valid values - true, false. */
    char* type;                                                               /**< This is the object_type of the schedule being created. It could be "Schedule" or any of the custom types created by the customer. */
    char* bill_code;                                                          /**< The billCode. Valid value can be empty string. */
    char* bill_sub_code;                                                      /**< The bill sub code. Valid value can be empty string. */
    char* bill_type;                                                          /**< The bill rate. Valid value can be NULLTAG. */
    tag_t bill_rate;                                                          /**< A collection of additional attributes (Optional). */
    int other_attributes_size;                                                /**< The number of additional attributes. */
    AttributeUpdateContainer_t other_attributes[NUM_OF_ATTRIBS];              /**< A collection of additional attributes (Optional) */
    int typed_attribute_container_size;                                       /**< The number of custom attributes. */
    TypedAttributeUpdateContainer_t typed_other_attributes[NUM_OF_ATTRIBS];   /**< A collection of custom attributes (Optional) */
}SCHMGT_new_schedule_container_t;

typedef struct CostDetailContainer_d SCHMGT_costs_detail_container_t;
struct CostDetailContainer_d
{
    int total_estimated_minutes;                               /**< total estimated minutes of a schedule or a task. */
    int total_accrued_minutes;                                 /**< total accrued minutes of a schedule or a task. */
    double total_estimated_cost;                               /**< total estimated cost of a schedule or a task. */
    double total_accrued_cost;                                 /**< total accrued cost of a schedule or a task. */
    int fixed_cost_size;                                       /**< number of fixed costs in a task. */
    tag_t* fixed_cost_tag_list;                                /**< vector of fixed cost details. */
    char* bill_code;                                           /**< bill code for a task. */
    char* bill_sub_code;                                       /**< bill sub code for a task. */
    char* billing_type;                                        /**< billing type for a task. */
    tag_t bill_rate;                                           /**< bill rate for a task. */
    char* currency;                                            /**< task currency. */
    tag_t task;                                                /**< tag of a task. */
    int num_childern;                                          /**< number of children of a task. */
    SCHMGT_costs_detail_container_t** costs_detail_container_List;         /**< Task cost details of all child tasks. */
};


typedef struct EVMDataRequest_d
{
    tag_t task;                                                  /**< The Task to calculate the earned value data */
    logical calc_basis_selected;                                 /**< Calc basis selected flag > */
    logical  calc_work_complete;                                 /**< Calc work complete flag> */
    logical selected_label;                                      /**< Selected label flag> */
} SCHMGT_evm_data_request_t;

typedef struct EVMDataResponse_d
{
    char* result_string;                                  /**< The result string in EVM results */
    double value;                                        /**< Value of result string. */
}SCHMGT_evm_data_response_t;

typedef struct FixedCostData_d
{
    double estimated_cost;                                       /**< Estimated cost from fixed cost */
    double accrrued_cost;                                       /**< Estimated cost from accrued cost  */
}FixedCostData_t;

typedef struct ResourceAssignmentSingleTask_d
{
    date_t day;                   /**< The day on which the resource load is computed */
    tag_t user_tag;               /**< The User whose resource load is computed */
    tag_t calendar_tag;           /**< Calendar of the User */

    tag_t schedule_tag;           /**< The Schedule where the User is a member and is assigned to the Schedule Tasks in the Schedule */
    tag_t sch_task_tag;           /**< The Schedule Task where the User is a Resource Assignment */

    char* sch_name;            /**< The name of the Schedule */
    date_t sch_start_date;        /**< The start date of the Schedule */
    date_t sch_end_date;          /**< The end date of the Schedule */

    char* task_name;            /**< The name of the Schedule Task where the User is a Resource Assignment */
    date_t task_start_date;        /**< The start date of the Schedule Task */
    date_t task_end_date;          /**< The end date of the Schedule Task */

    double task_minutes;           /**< TThe work estimate in minutes of the ScheduleTask */
    double resource_minutes;       /**< The work complete in minutes of the ScheduleTask. */
    double stack_Base;             /**< Signifies the nth resource load information in a day.*/

    double task_minutes_overLoad;  /**< The resource overload in minutes. */
    char* userData;             /**< Colon delimited user information for mouse over tooltip or table information.For eg.,  User tcadmin;Calenddar baseCalendar; Schedule mySchedule; Task myTask; Capacity 8hrs; Yield 100%; Utilized 6hrs; Untililized 2hrs; Overload 0hrs */
} ResourceAssignmentSingleTask_t;


typedef struct ResourceAssignmentDayStack_d
{
    int num_elements;                         /**< The number of resource load elements in a day*/
    ResourceAssignmentSingleTask_t* stack;    /**< Resource load information for a day */
} ResourceAssignmentDayStack_t;


typedef struct ResourceAssignmentStacks_d
{
    char* user_name;                     /**<  The user whose resource load is calculated. */
    int days;                               /**<  The number od days over which the resource load is calculated */
    ResourceAssignmentDayStack_t* stacks;   /**<  A list containing the calculated resource load information of the User */
} SCHMGT_resource_assignment_stacks_t;


typedef struct RequestInformation_d
{
    tag_t resource;                   /**<  The User whose resource load needs to be calculated. */
    char* resource_name;           /**<  The User name whose resource load needs to be calculated.*/
    date_t range_start;               /**<  The start date of the range over which the resource load needs to be calculated. */
    date_t range_end;                 /**<  The end date of the range over which the resource load needs to be calculated.*/
    int num_schedules;                /**<  The number of Schedules in which User is assigned to Schedule Tasks*/
    tag_t* schedules_to_include;      /**<  The Schedules to be taken into account for those tasks assigned to the User */
    int behavior;                     /**<  Indicates how the system would generate resource data for resource load calculation:
                                         <ul>
                                         <li>1: get all data from the server,
                                         <li>2 and 3: use algorithm to generate  data for debugging.
                                         </ul>
                                      */
} SCHMGT_request_information_t;

/**
   Structure to define a fixed cost to be added to a Schedule Task.
   <br/>It is used as input parameter of the #SCHMGT_add_fixed_cost ITK
*/
typedef struct AddFixedCost_d
{
    tag_t scheduleTask;             /**< The Schedule Task */
    char* name;                     /**< The name of fixed cost */
    char* estimate;                 /**< The estimated cost. Valid value can be empty string */
    char* actual;                   /**< The actual cost. Valid value can be empty string */
    char* currency;                 /**< ISO-4217 code for currency of the costs */
    bool useActual;                 /**< Should accrual calculations use the "actual" cost? */
    char* billCode;                 /**< The billing code. Valid values are determined by the LOV  {unassigned, General, Management,
                                     * ProjectMgmt, Sales, Training, Travel, ProductDev, SoftwareDev} */

    char* subCode;                  /**< The billing subcode. Valid values are determined by the LOV. Values are following
                                     * groups depending upon billcode.eg. If billcode is General then you can mentioned
                                     * subcode as either of following set (unassigned, Accounting, Clerical, CorpAdmin,
                                     * IT, Meetings, Other)
                                     <br>Following are the list of billcode and corresponding valid values for sub code.
                                     <br/>For BillCode 'unassigned' = { unassigned }
                                     <br/>For BillCode 'General' ={ unassigned, Accounting, Clerical, CorpAdmin, IT, Meetings, Other }
                                     <br/>For Bill code Management = { unassigned, Executive, ProjMgmt,vDesign/Plan, Meetings, Training, Other}
                                     <br/>For BillCode 'ProiectMgmt' ={ unassigned,Management, Meetings, Design/Plan, Training, Teaching, Clerical, Email, Other }
                                     <br/>For BillCode 'Sales' ={ unassigned, MajorAccts, General, Admin, Training, Other }
                                     <br/>For BillCode 'Training' ={ unassigned, Billable, Customer1, Customer2, Customer3, Region1, Region2, Region3, Other }
                                     <br/>For BillCode 'Travel' ={ unassigned, Billable, Region1, Region2, Region3, Other }
                                     <br/>For BillCode 'ProductDev' ={ unassigned, Planning, Design, Development, ProcessMgt, Validation, Other }
                                     <br/>For BillCode 'SoftwareDev' ={unassigned, Concept, Definition, Development, Introduction, Training, Other } */

    char* billingType;          /**< The billing type. Valid value are { unassigned, Billable, Billed, Standard, Unbillable} */

    int accrualType;            /**< The cost accrual type (0=start, 1=prorated, 2=end) */
} AddFixedCost_t;


/**
     Defines the different types of "What If" analysis.
*/
typedef enum SCHMGT_what_if_analysis_option_e
{
    SCHMGT_what_if_analysis_start,                        /**< Start What-If analysis by locking the Schedule so that other users will not be able to update the Schedule in other sessions.                    */
    SCHMGT_what_if_analysis_save_and_continue,            /**< Save the changes made on the Schedule to the database and continue What-If analysis. Save What-If changes and continue.      */
    SCHMGT_what_if_analysis_save_and_exit,                /**< Save What-If changes and exit to the database and exit the What-If analysis mode by releasing the the lock on the Schedule so that other users can modify the Schedule.          */
    SCHMGT_what_if_analysis_cancel_and_exit               /**< Cancel What-If analysis by discarding the changes and exit        */
} SCHMGT_what_if_analysis_option_t;


/**
  Performs the scale Schedule operation on the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_scale_schedule_non_interactive(
    tag_t schedule,          /**< (I) The tag of the Schedule to scale */
    double factor,           /**< (I) The value of the factor by which to scale */
    int type,                /**< (I) The type of scale:  0-Work Estimate, 1-Duration */
    logical check_state,     /**< (I) True: the operation will fail if the schedule has started. False: the operation will attempt to scale a started schedule. */
    int* number_updated_tasks,  /**< (O) The number of updated Tasks */
    tag_t** updated_tasks    /**< (OF) number_updated_tasks The updated Tasks */
    );

/**
   Performs the recalculation operation on the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_recalculate_schedule_non_interactive (
    tag_t schedule,  /**< (I) The tag of the Schedule being updated */
    int type,        /**< (I) The type of recalculation: RECALCULATE_EXEC, RECALCULATE_SCHED, RECALCULATE_ALL */
    logical async    /**< (I) Schedule the recalculation in the background */
    );

/**
   Performs the shift operation on the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_shift_schedule_non_interactive(
    tag_t schedule,                /**< (I)  The tag of the Schedule to shift */
    date_t new_date,               /**< (I)  The new date */
    logical new_finish,            /**< (I)  True: newDate is the new finish date. False: newDate is the new start date. */
    int* number_updated_tasks,        /**< (O)  The number of updated Tasks */
    tag_t** updated_tasks          /**< (OF)  number_updated_tasks The updated Tasks */
    );

/**
   Creates Tasks in the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_create_tasks_non_interactive (
    const tag_t &schedule,                    /**< (I) The Schedule tag which is been updated */
    int num_create,                           /**< (I) Number of Tasks to create */
    TaskCreateContainer_t* create_inputs,     /**< (I) numCreate Containers to create the Tasks */
    tag_t** created_tasks,                    /**< (OF) numCreate Tags of the created Tasks */
    int* num_updated_tasks,                   /**< (O) Number of Tasks updated */
    tag_t** updated_tasks                     /**< (OF) num_updated_tasks Tags of the updated Tasks */
    );

/**
   Updates Tasks in the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_update_tasks_non_interactive(
    const tag_t &schedule,                    /**< (I) The Schedule in which the Tasks are to be updated */
    int number_tasks_to_update,               /**< (I) The number of Tasks to update */
    ObjectUpdateContainer_t* update_inputs,   /**< (I) number_tasks_to_update. Containers to update the Tasks */
    int *number_updated_tasks,                /**< (O) Number of Tasks updated */
    tag_t** updated_tasks                     /**< (OF) number_updated_tasks Tags of the updated Tasks */
    );

/**
   Moves Tasks within the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_move_tasks_non_interactive(
    const tag_t &schedule,                   /**< (I) The Schedule in which the Tasks are to be updated */
    int number_tasks_to_move,                /**< (I) The number of Tasks to move */
    MoveRequest_t* update_inputs             /**< (I) number_tasks_to_move Inputs for move */
    );

/**
    Creates dependency between two tasks.
    <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input and no dependency will be created by the function.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCHMGT_cannot_create_dependency_between_template_and_non_template_schedule if dependency should be created between a task from a template schedule and a task from a schedule that is not a template.
    </ul>
*/
extern SCHMGTBRI_API int SCHMGT_create_dependency2(
    tag_t schedule,                     /**< (I) The Schedule in which to create the Dependencies */
    int numCreate,                      /**< (I) The number of Dependencies being created */
    DependencyCreate_t* createInputs,   /**< (I) numCreate Containers to create the Dependencies */
    tag_t** createdDependencies,        /**< (OF) numCreate Tags for the created Dependencies */
    int* numUpdatedTasks,               /**< (O) The number of updated Tasks */
    tag_t** updatedTasks,               /**< (OF) numUpdatedTasks Tags of the updated Tasks */
    int* numProxyCreated,               /**< (O) The number of created proxy Tasks */
    tag_t** createdProxies              /**< (OF) numProxyCreated Tags of the created proxy Tasks */
    );

/**
   Creates Dependencies between Tasks.
*/
extern SCHMGTBRI_API int SCHMGT_create_dependency(
    tag_t schedule,                   /**< (I) The schedule in which to create the Dependencies */
    int numCreate,                    /**< (I) The number of Dependencies being created */
    DependencyCreate_t* createInputs, /**< (I) The inputs needed to create the Dependencies */
    tag_t** createdDependencies,      /**< (0F) numCreate The created Dependency Tags */
    int* numUpdatedTasks,             /**< (0) The number of updated Tasks */
    tag_t** updatedTasks              /**< (0F) numUpdatedTasks The list of updated Tasks */
    );

/**
   Updates Dependencies in the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_update_dependency(
    tag_t schedule,                     /**< (I) The Schedule in which to update the Dependencies */
    int numUpdate,                      /**< (I) The number of Dependencies being updated */
    DependencyUpdate_t* updateInputs,   /**< (I) numUpdate Containers to update the Dependencies */
    int* numUpdatedTasks,               /**< (O) The number of updated Tasks */
    tag_t** updatedTasks                /**< (OF) numUpdatedTasks Tags of the updated Tasks */
    );

/**
    Deletes Dependencies in the Schedule.
    <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for the given input and no dependency will be deleted by the function.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCHMGT_taskdependency_delete_failed if dependency to be deleted between tasks is invalid or already deleted.
    </ul>
*/
extern SCHMGTBRI_API int SCHMGT_delete_dependency2(
    tag_t schedule,         /**< (I) The Schedule in which the Schedule Task Dependencies are to deleted*/
    int numDelete,          /**< (I) The number of Schedule Task Dependencies to delete */
    tag_t* dependencies,    /**< (I) The Schedule Task Dependencies to delete */
    int* numUpdatedTasks,   /**< (O) The number of updated Schedule Tasks */
    tag_t** updatedTasks    /**< (OF) The updateded Schedule Tasks */
    );

/**
    @deprecated #SCHMGT_delete_dependency deprecated in Teamcenter 11.5. Use #SCHMGT_delete_dependency2 instead.

    Deletes Dependencies in the Schedule.
*/
TC_DEPRECATED("11.5", "SCHMGT_delete_dependency", "SCHMGT_delete_dependency2" )
extern SCHMGTBRI_API int SCHMGT_delete_dependency(
    tag_t schedule,         /**< (I) The Schedule in which the Schedule Task Dependencies are to deleted*/
    int numDelete,          /**< (I) The number of Schedule Task Dependencies to delete */
    tag_t** dependencies,   /**< (I) The Schedule Task Dependencies to delete */
    int* numUpdatedTasks,   /**< (O) The number of updated Schedule Tasks */
    tag_t** updatedTasks    /**< (OF) The updateded Schedule Tasks */
    );

/**
   Retrieves all the Schedule tasks in the critical path in the provided Schedule.
   <br/>The critical path is the series of tasks (or even a single task) that dictates the calculated start date or finish date of the project.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted if the @p schedule is invalid or has been deleted.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_critical_tasks(
    tag_t schedule,                /**< (I)  The Schedule on which the critical path needs to be calculated */
    int* num_tasks,                /**< (O)  The number of Tasks in the critical path */
    tag_t** critical_tasks,        /**< (OF) num_tasks The schedule tasks in the critical path */
    int* num_proxy_tasks,          /**< (O)  The number of proxy Tasks in the critical path */
    tag_t** critical_proxy_tasks   /**< (OF) num_proxy_tasks The proxy Tasks in the critical path */
    );

/**
   Launches the workflow on Task.
*/
extern SCHMGTBRI_API int SCHMGT_launch_workflow(
    tag_t task,      /**< (I)  The Task for launch workflow */
    tag_t* epmJob    /**< (OF) The launched EPM Job */
    );

/**
   Deletes Tasks in the Schedule.
*/
extern SCHMGTBRI_API  int SCHMGT_delete_tasks_non_interactive
(
    tag_t   schedule,            /**< (I)  The Schedule tag */
    int     numTasksToDelete,    /**< (I)  Number of Tasks to delete */
    tag_t*  tasksToDelete,       /**< (I)  numTasksToDelete Tags of the Tasks to delete */
    int*    numUpdatedTasks,     /**< (O)  Number of Tasks updated */
    tag_t** updatedTasks,        /**< (OF) numUpdatedTasks Tags of the updated Tasks */
    int*    numOrphanedTasks,    /**< (O)  Number of Tasks orphaned */
    tag_t** orphanedTasks        /**< (OF) numOrphanedTasks Tags of the orphaned Tasks */
    );

/**
   Creates Resource Assignments to Tasks in the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_create_assignments (
    const tag_t &schedule,                   /**< (I) The Schedule tag */
    int numCreate,                           /**< (I) Number of Assignments to create */
    AssignmentCreate_t* createInputs,        /**< (I) numCreate Containers to create the Assignments */
    int* numCreatedAssignments,              /**< (O) The number of created Assignments */
    tag_t** createdAssignments               /**< (OF) numCreatedAssignments Tags of the created Assignments */
    );

/**
   Creates Resource Assignments to Tasks in the Schedule with place holder.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
   No assignments will have been created by the function.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
   <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to create assignment on the Schedule task.
   <li>#SCHMGT_task_deleted error if schedule task is deleted.
   <li>#SCHMGT_resource_can_not_be_added_deleted if resource cannot be added or deleted if workflow process is assigned to Schedule task.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_create_assignments_with_placeholder (
    tag_t &schedule,                                    /**< (I) The Schedule tag */
    int num_create,                                     /**< (I) Number of Assignments to create */
    AssignmentCreate_t* create_inputs,                  /**< (I) numCreate Containers to create the Assignments */
    bool* is_placeholder_array,                         /**< (I) The array for isPlaceHolder flag */
    tag_t* placeholder_array,                           /**< (I) The placeholder input array */
    int* num_created_assignments,                       /**< (O) The number of created Assignments */
    tag_t** created_assignments                         /**< (OF) num_created_assignments Tags of the created Assignments */
    );

/**
   Updates Resource Assignments in the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_update_assignments (
    const tag_t &schedule,                   /**< (I) The Schedule tag */
    int numUpdate,                           /**< (I) Number of Assignments to update */
    AssignmentUpdate_t* updateInputs,        /**< (I) numUpdate Containers to update the Assignments */
    int* numUpdatedAssignments,              /**< (O)  The number of updated Assignments */
    tag_t** updatedAssignments               /**< (OF) numUpdatedAssignments Tags of the updated Assignments */
    );

/**
   Deletes Resource Assignments in the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_delete_assignments(
    tag_t schedule,       /**< (I) The Schedule in which to delete the dependencies */
    int numDelete,        /**< (I) The number of dependencies to delete */
    tag_t* assignments    /**< (I) numDelete Tags of the Assignments to delete */
    );

/**
   Updates the Schedule.
*/
extern SCHMGTBRI_API int SCHMGT_update_schedule_non_interactive(
    ObjectUpdateContainer_t  update,    /**< (I)  The Schedule to update */
    int* numUpdatedTasks,               /**< (O)  The number of updated Tasks */
    tag_t** updatedTasks                /**< (OF) numUpdatedTasks Tags of the updated Tasks */
    );


/**
  Replaces assignments on a Schedule task.
  <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
  No assignments will have been replaced by the function.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#SCHMGT_invalid_user error if user is invalid.
  <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
  <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to replace assignment on the Schedule task.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_replace_assignment(
    tag_t schedule,                          /**< (I) The schedule tag */
    int number_assignments_to_delete,        /**< (I) The number of assignments to delete */
    const tag_t* assignments_to_delete,      /**< (I) number_assignments_to_delete The assignments to delete */
    int number_assignments_to_create,        /**< (I) Number of assignments to create */
    const AssignmentCreate_t* create_inputs, /**< (I) number_assignments_to_create The inputs needed to create the Assignment */
    int* number_created_assignments,         /**< (O)  The number of created assignments */
    tag_t** created_assignments,             /**< (OF) number_created_assignments The created assignments */
    int* number_updated_assignments,         /**< (O)  The number of updated assignments */
    tag_t** updated_assignments              /**< (OF) number_updated_assignments The updated assignments */
    );


/**
   Creates Resource Assignments to Tasks in the Schedule.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
   No assignments will have been created by the function.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>SCHMGT_invalid_assignment_to_claim if the user being assigned is invalid.
   <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to create assignment on the Schedule task.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_claim_assignment (
    tag_t task,                  /**< (I) The task on which the assignmented is to be created. */
    tag_t assignment,            /**< (I) The resource who is to be assigned to the Schedule task. */
    tag_t* new_assignments       /**< (OF) The created assignment. */
    );



/**
  Add members to the specified schedule.
  <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
  No members will have been added by the function.

  <br/>Furthermore, the index of the offending structure will be indicated in the output parameter "invalid_input_index".
  <br/>Its value is "-1" when no error is detected for the input structure.

  <br/>The output parameter "members" (of size "num_added_members") will contain the tags of the added members up to the last successful addition.
  <br/>If an error has occurred during the addition of one of the members, the function will return the associated error for that member structure.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#SCHMGT_invalid_user error if user is invalid.
  <li>#SCHMGT_invalid_member_privilege error if privilege value is incorrect.
  <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
  <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to add member to the schedule.
  <li>Possibly other errors can be returned.
  </ul>
 */
extern SCHMGTBRI_API int SCHMGT_add_members (
    int num_members,                    /**< (I) The number of members to add */
    AddMembers_t* add_member_inputs,    /**< (I) The inputs needed to add members */
    int *invalid_input_index,           /**< (OF) Index of the invalid input member */
    int *num_added_members,             /**< (OF) The number of added members */
    tag_t** members                     /**< (OF) num_added_members Tag for the added members. */
    );


/**
  Inserts a given Schedule as a sub-schedule inside another master Schedule.
  <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input and no schedules will have been inserted by the function.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#SCHMGT_cannot_insert_unpublished_sub_schedule error if any sub-schedule is baseline or unpublished
  <li>#SCHMGT_cannot_insert_non_template_sub_schedule_into_template_master_schedule error if a sub-schedule that is not a template is to be inserted into a template master Schedule.
  <li>#SCHMGT_cannot_insert_template_sub_schedule_into_non_template_master_schedule error if a template sub-schedule is to be inserted into a master Schedule that is not a template.
  <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to insert a sub-schedule into another Schedule.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_insert_schedule (
    const SCHMGT_insert_schedule_container_t *insert_container, /**< (I) The information of the sub-schedules and the master schedule. */
    int number_schedules_to_insert,                             /**< (I) The number of sub-schedules for insert. */
    int*    number_updated_tasks,                               /**< (O) Number of Tasks updated */
    tag_t** updated_tasks                                       /**< (OF) number_updated_tasks The updated Tasks */
    );

/**
   Removes a sub-schedule from a master Schedule.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
   No schedules will have been detached by the function.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
   <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to detach a Schedule from another Schedule.
   </ul>
 */
extern SCHMGTBRI_API int SCHMGT_detach_schedule(
    const SCHMGT_detach_schedule_container_t *detach_container,   /**< (I) The inputs needed to detach sub schedule from a master schedule. */
    int number_schedules_to_detach,                               /**< (I) The number of sub schedule to be removed from a master schedule. */
    int*    number_updated_tasks,                                 /**< (O) Number of updated Tasks. */
    tag_t** updated_tasks                                         /**< (OF) number_updated_tasks The updated Tasks */
    );

/**
  Creates a Schedule deliverable.
  <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
  No schedule deliverables will have been created by the function.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
  <li>#SCHMGT_no_privilege_to_create_object if user does not have privilege to create schedule deliverables.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_create_schedule_deliverable(
    const SCHMGT_schedule_deliverable_data_t *sch_deliverable_data,  /**< (I) The inputs needed to create schedule deliverable. */
    int number_create,                                               /**< (I) The number of schedule deliverable to be created. */
    tag_t** created_schedule_deliverable                             /**< (OF)number_create The created schedule deliverable. */
    );

/**
   Creates a Task deliverable.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
   No Task deliverables will have been created by the function.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_no_privilege_to_create_object if user does not have privilege to create Task deliverables.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_create_schedule_task_deliverable(
    const SCHMGT_schedule_task_deliverable_data_t *task_deliverable_data,  /**< (I) The inputs needed to create task deliverable. */
    int number_create,                                                     /**< (I) The number of task deliverable to be created. */
    tag_t** created_task_deliverable                                       /**< (OF) number_create The created task deliverable. */
    );

/**
   Creates a Schedule.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.
   No Schedule will have been created by the function.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_no_privilege_to_create_object if user does not have privilege to create Schedule.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_create_new_schedule(
    const SCHMGT_new_schedule_container_t *create_inputs,       /**< (I)  The inputs needed to create the Schedules. */
    int number_schedules_create,                                /**< (I)  The number of Schedules being created. */
    tag_t** created_schedules                                  /**< (OF) number_schedules_create The created Schedules. */
    );


/**
   Retrieves the cost rollup data for a Task.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
   <li>#SCHMGT_invalid_member_privilege error if user does not have privilige to see cost data.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_get_cost_rollup_data (
    tag_t schedule_task,                                        /**< (I) The task on which the total costs need to be calculated */
    SCHMGT_costs_detail_container_t** costs_detail_container    /**< (OF) A list specifying the computed total cost for each input ScheduleTask*/
    );


/**
   Retrieves the Earned Value Management (EVM) data for a Schedule.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_get_evm_data (
    int num_requests,                                             /**< (I) Number of Schedule Tasks*/
    SCHMGT_evm_data_request_t* evm_data_requests,                 /**< (I) Specifies the Schedule or the ScheduleTask and the various criteria  based on which the the earned value calculations are calculated  */
    SCHMGT_evm_data_response_t** evm_data_response                /**< (OF) num_requests Contains the earned values results for each Schedule or Schedule Task on which the earned value data was requested */
    );

/**
   Verifies the Schedule for effort driven values.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_verify_schedule(
    tag_t schedule,         /**< (I) The Schedule which has to be verified for effort driven values. */
    int *num_failed,        /**< (O) Number of Tasks in the Schedule which have a problem with effort driven values. */
    tag_t** failed_tasks,   /**< (OF) num_failed The tasks which have a problem with effort driven values. */
    int* num_messages,      /**< (0) Number of messages specifying the problems with the effort driven values. */
    char***  error_messages /**< (OF) num_messages The error messages specifying the problems with the effort driven values. */
    );


/**
   Retrieves the resource load data for a User.
   <br/><br/>If any input structure is invalid, the method will stop the processing at that index and return the error code for that input.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
   <li>#SCHMGT_invalid_user error if user is invalid.
   <li>#SCHMGT_invalid_member_privilege error if user does not have privilige to view resource load data.
   </ul>
 */
extern SCHMGTBRI_API int SCHMGT_get_resource_graph_stack_data(
    const SCHMGT_request_information_t* request_info,         /**< (I) The information of the User for whom the resource graph data is required.*/
    SCHMGT_resource_assignment_stacks_t* assignment_stacks    /**< (OF) The calculated resource graph data of the User */
    );

/**
  Generates unique task ID.
  <br/><br>This ID will be used for creation of dispatcher task.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>DISPATCHER_ERROR_unable_to_obtain_host_information if dispatcher could not find the host information of machine.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_generate_unique_task_id(
    char** unique_task_id      /**< (OF) Generated unique task id */
    );

/**
   Creates a new schedule based on the input schedule.
   <br/><br/>If the input schedule is invalid, the method will stop the processing at that index and return the error code for that input.
   No schedules will have been copied by the function.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SCHMGT_schedule_deleted error if schedule tag is invalid.
   <li>#SCHMGT_no_privilege_to_modify_object if the user does not have privilege to copy a Schedule.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_copy_schedule (
    int number_schedules_to_copy,                             /**< (I) The number of schedules to copy. */
    tag_t*    original_schedules,                             /**< (I) Schedules to copy */
    tag_t** created_schedules                                 /**< (OF) number_schedules_to_copy Copied schedules */
    );


/**
   @deprecated #SCHMGT_get_schedule_summary_task deprecated in Teamcenter 11.3. Use #AOM_ask_value_tag instead.

   This function Retrieves the schedule summary task of a schedule.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Errors on failure.
   </ul>
*/
TC_DEPRECATED( "11.3", "SCHMGT_get_schedule_summary_task", "AOM_ask_value_tag" )
extern SCHMGTBRI_API int SCHMGT_get_schedule_summary_task(
    const tag_t*  schedule,       /**< (I) The schedule tag. */
    tag_t* schedule_Summary_task  /**< (O) The schedule summary task tag. */
    );

/**
   Converts client datetime to server timezone datetime.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Error on failure.
   </ul>
*/
extern SCHMGTBRI_API int SCHMGT_convert_date_server_timezone(
    const char* client_date_time, /**< (I) The client datetime. Format: yyyy-MM-ddThh:mm:ss zz:zz. */
    char** server_date_time       /**< (OF) The datetime in server timezone. Format: yyyy-MM-dd hh:mm:ss zz:zz. */
    );


/**
  Adds Fixed Costs to the specified Schedule Task.
  <br/><br>If any input structure is invalid, the method will stop the processing at that index and will return the error code for that input.
  <br/>On error, no fixed cost will be added by the function.
  <br/>The parameter @p invalid_input_index contains the index of the first offending structure in case of error.
  Its value is "-1" when no error is detected for the input structures.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#SCHMGT_schedule_deleted error if schedule tag does not exists.
  <li>#SCHMGT_no_privilege_to_modify_object if user does not have privilege to add fixedCost to the schedule.
  <li>Possibly other errors can be returned.
  </ul>
 */
extern SCHMGTBRI_API int SCHMGT_add_fixed_cost (
    int num_fixed_costs,                                /**< (I) The number of fixed costs to add */
    const AddFixedCost_t* add_fixed_cost_inputs,        /**< (I) num_fixed_costs The inputs needed to add fixed costs */
    int *invalid_input_index,                           /**< (O) Index of the first invalid input cost */
    int *num_added_fixed_costs,                         /**< (O) The number of added fixed costs */
    tag_t** added_fixed_costs                           /**< (OF) num_added_fixed_costs Tag for the added fixed costs */
    );

/*
  Copies and pastes Schedule Tasks to a target Schedule Task.
  <br/>As per the provided options, it creates dependencies,
  Assignments, Members, etc.

  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#SCHMGT_invalid_parameters if one or more parameters passed to the function is invalid.
  <li>#SCHMGT_task_creation_failed if Schedule Tasks creation has failed.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_copy_tasks_with_paste_special (
    const tag_t source_schedule,               /**< (I)  The source Schedule */
    const unsigned int n_tasks,                /**< (I)  The number of tasks to paste */
    const tag_t* tasks,                        /**< (I)  n_tasks The list of Schedule Tasks to paste. Copied Schedule Tasks may be normal tasks or Summary Task with recursively having child tasks and Summary Tasks or Schedule Summary Task. */
    const tag_t target_schedule,               /**< (I)  The target Schedule */
    const tag_t target_task,                   /**< (I)  The target Schedule Task. Target Schedule Task may be a normal task or Summary Task or Schedule Summary Task. */
    const unsigned int paste_type,             /**< (I)  The option for paste Type. <br/>Valid values are:
                                                  <ul><li> #PASTE_AFTER: The Schedule Task is pasted below the target Schedule Task.</li>
                                                  <li> #PASTE_UNDER: The Schedule Task is pasted inside the target Schedule Task.</li></ul> */
    const unsigned int number_copies,          /**< (I)  The number of times the paste operation is to be performed */
    const logical calculate_offset,            /**< (I)  The option to calculate the offset of the Tasks */
    const logical include_assignments,         /**< (I)  The option to create new Assignments */
    const logical include_dependencies,        /**< (I)  The option to create new Dependencies */
    const logical include_deliverables,        /**< (I)  The option to create new Deliverables */
    const logical use_existing_deliverables,   /**< (I)  The option to use existing Deliverables */
    const logical update_membership,           /**< (I)  The option to create new members */
    const logical reset_deliverables,          /**< (I)  The option to reset the Deliverables */
    const logical copy_workflow,               /**< (I)  The option to copy work flow content */
    const logical copy_cost,                   /**< (I)  The option to copy cost information */
    const logical async_recalculate_schedule,  /**< (I)  The option to execute the validation of Schedule Engine */
    int* n_errors,                             /**< (O)  The number of errors and failed tasks */
    int** errors,                              /**< (OF) n_errors The error codes for the operation on Tasks  */
    tag_t** failed_tasks,                      /**< (OF) n_errors The Tasks for which the operation failed  */
    int* n_created_tasks,                      /**< (O)  The number of created Schedule Tasks */
    tag_t** created_tasks                      /**< (OF) n_created_tasks The list of created Schedule Tasks */
    );

/**
  Creates a proxy Task.
  <br/>The proxy task is only a mirror of the original, proxy tasks creates cross-schedule dependencies.

  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#SCHMGT_TASK_HAS_PROXY if this task already has a proxy in this schedule.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGTBRI_create_proxy_tasks (
        unsigned int num_create_containers,                /**< (I) The number of proxies to create */
        const ProxyCreate_t *create_containers,            /**< (I) The proxy create containers */
        tag_t **created_proxies                            /**< (OF) num_create_containers The proxies created. */
    );

/**
  Copies and pastes Schedule Tasks to a target Schedule Task.
  <br/>As per the provided options, it creates dependencies,
  Assignments, Members, etc.
  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#SCHMGT_invalid_parameters if one or more parameters passed to the function is invalid.
  <li>#SCHMGT_task_creation_failed if Schedule Tasks creation has failed.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_copy_tasks_with_paste_special (
                        const tag_t source_schedule,               /**< (I)  The source Schedule */
                        const unsigned int n_tasks,                /**< (I)  The number of tasks to paste */
                        const tag_t* tasks,                        /**< (I)  n_tasks The list of Schedule Tasks to paste. Copied Schedule Tasks may be normal tasks or Summary Task with recursively having child tasks and Summary Tasks or Schedule Summary Task. */
                        const tag_t target_schedule,               /**< (I)  The target Schedule */
                        const tag_t target_task,                   /**< (I)  The target Schedule Task. Target Schedule Task may be a normal task or Summary Task or Schedule Summary Task. */
                        const unsigned int paste_type,             /**< (I)  The option for paste Type. <br/>Valid values are:
                                                                   <ul><li> #PASTE_AFTER: The Schedule Task is pasted below the target Schedule Task.</li>
                                                                   <li> #PASTE_UNDER: The Schedule Task is pasted inside the target Schedule Task.</li></ul> */
                        const unsigned int number_copies,          /**< (I)  The number of times the paste operation is to be performed */
                        const logical calculate_offset,            /**< (I)  The option to calculate the offset of the Tasks */
                        const logical include_assignments,         /**< (I)  The option to create new Assignments */
                        const logical include_dependencies,        /**< (I)  The option to create new Dependencies */
                        const logical include_deliverables,        /**< (I)  The option to create new Deliverables */
                        const logical use_existing_deliverables,   /**< (I)  The option to use existing Deliverables */
                        const logical update_membership,           /**< (I)  The option to create new members */
                        const logical reset_deliverables,          /**< (I)  The option to reset the Deliverables */
                        const logical copy_workflow,               /**< (I)  The option to copy work flow content */
                        const logical copy_cost,                   /**< (I)  The option to copy cost information */
                        const logical async_recalculate_schedule,  /**< (I)  The option to execute the validation of Schedule Engine */
                        int* n_errors,                             /**< (O)  The number of errors and failed tasks */
                        int** errors,                              /**< (OF) n_errors The error codes for the operation on Tasks  */
                        tag_t** failed_tasks,                      /**< (OF) n_errors The Tasks for which the operation failed  */
                        int* n_created_tasks,                      /**< (O)  The number of created Schedule Tasks */
                        tag_t** created_tasks                      /**< (OF) n_created_tasks The list of created Schedule Tasks */
    );


/**
  Performs the What-If analysis on a Schedule by making scheduling changes locally without affecting other users.    
  <br/>Only the following operations can be performed:
  <ul>
  <li>Modification of all the properties of the Schedule. 
  <li>Modification of all the properties of the ScheduleTask other than the following execution properties : status, work complete, complete percent, actual start date, actual finish date, work remaining.
  <li>Creation, deletion and update of ScheduleTask, ResourceAssignment, TaskDependency, and Fnd0ProxyTask objects.
  </ul>

  <br/>The following operations cannot be performed:
  <ul>
  <li>Modification of the the following execution properties of the ScheduleTask : status, work complete, complete percent, actual start date, actual finish date, work remaining.
  <li>Insertion of a Schedule and detachment of Schedule operations.
  </ul>

  <br/>Only the following operations can be performed by other users when a Schedule is in What-If analysis mode:
  <ul>
  <li>Modification of the following execution properties of the ScheduleTask : status, work complete, complete percent, actual start date, actual finish date, work remaining.
  </ul>

  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#SCHMGT_schedule_deleted if the Schedule has been deleted.
  <li>#SCHMGT_Lock_LockedByOther if the lock on Schedule was not granted, because it is currently held by the user,who is currently modifying the Schedule.
  <li>#SCHMGT_Unlock_LockByOther if the Schedule cannot be unlocked, because it is locked by the user.
  </ul>
*/
extern SCHMGTBRI_API int SCHMGT_what_if_analysis (
                        const tag_t schedule,                                     /**< (I)  The Schedule to set the What-If analysis mode */                        
                        const SCHMGT_what_if_analysis_option_t what_if_option     /**< (I)  Specifies the What-If analysis option */
    );


#ifdef __cplusplus
}
#endif

/** @} */

#include <schmgt_bridge/libschmgt_bridge_undef.h>
#endif
