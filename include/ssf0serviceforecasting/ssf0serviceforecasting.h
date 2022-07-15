/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    SSF0ServiceForecasting module.

    The ITK ssf0serviceforecasting functions include:
    <ul>
    <li>A function to create Maintenance Action
    <li>A function to complete Maintenance Action
    <li>A function to cancel Maintenance Action
    <li>A function to extend due date of Maintenance Action
    </ul>

    To use these functions, include ssf0serviceforecasting.h
*/


#ifndef SSF0SERVICEFORECASTING_H
#define SSF0SERVICEFORECASTING_H

#include <unidefs.h>
#include <ssf0serviceforecasting/libssf0serviceforecasting_exports.h>

/**
    @defgroup SSF0SERVICEFORECASTING APIs and data types for Service Forecasting module
    @ingroup  TC
    @{
*/

/** Disposition property on SSF0MaintenanceAction */
#define SSF0MADISPOSITION_ATTR "disposition"

/** Approval property on SSF0MaintenanceAction */
#define SSF0MAAPPROVAL_ATTR "approval"

/** Disposition value "Rejected */
#define SSF0MAAPPROVAL_VAL "Rejected"

/** Disposition value "Cancelled */
#define SSF0MADISPOSITION_VAL "Cancelled"

/** Disposition value "Completed */
#define SSF0MADISPOSITIONCOMPLETE_VAL "Completed"

/** Class Name SSF0ActionExtension */
#define SSF0ACTIONEXTENSION_REL "SSF0ActionExtension"

/** object_name property on SSF0MaintenanceAction */
#define OBJECTSTRING_ATTR "object_string"

/** Voided Relation Name */
#define SSF0VOIDED_REL "STP0Voided"

/** CorrectiveAction Relation Name */
#define CORRECTIVEACTION_REL "CorrectiveAction"

/** Status value  InProgress*/
#define SSF0INPROGRESS_ATTR "InProgress"

/** Status value  InProgress*/
#define INPROGRESS_REL "InProgress"

/** ssf0IsExtensionPending property on SSF0MaintenanceAction */
#define ISEXTENSIONPENDING_ATTR "ssf0IsExtensionPending"

/** Approval status value "Approved */
#define SSF0MAAPPROVALCOMPLETED "Approved"

/** Approval status value "Completed */
#define SSF0COMPLETED_REL "Completed"

/** fnd0state property on TaskExecutionFormInfo*/
#define SSF0FND0STATE_ATTR "fnd0state"

/** state property value Complete*/
#define SSF0FND0STATE_COMPLETE "Complete"

/** state property value Closed*/
#define SSF0FND0STATE_CLOSED "Closed"

/** state property value Aborted*/
#define SSF0FND0STATE_ABORTED "Aborted"

/** Class Name SSS0JobActivityRevision */
#define SSS0JOBACTIVITYREVISIONCLASS "SSS0JobActivityRevision"

/** Class Name SSS0SvcWorkOrderRevision */
#define SSS0WORKORDERREVISIONCLASS "SSS0SvcWorkOrderRevision"


#ifdef __cplusplus
extern "C"{
#endif


/**
   Maintenance Action object structure that holds the entire information about
   a Maintenance Action which is required to perform the base Maintenance Action.
*/
    typedef struct 
    {
        logical maintenance_action_is_auto_complete;                    /**< The maintenance action auto complete */
        logical maintenance_action_is_canceled;                         /**< The maintenance action is canceled */
        logical maintenance_action_is_completed;                        /**< The maintenance action is complete */
        logical maintenance_action_is_due_date_extended;                /**< The maintenance action extention object  */
        tag_t maintenance_action_asset;                                 /**< The maintenance action asset */
        tag_t maintenance_action_part_in_progress;                      /**< The maintenance action impacted part */
        tag_t maintenance_action_part_completed_voided;                 /**< The maintenance action status */
        tag_t maintenance_action_zone;                                  /**< The maintenance action zone */
        tag_t maintenance_action_serv_req;                              /**< The maintenance action source service requirement */
        tag_t maintenance_action_str_context;                           /**< The maintenance action structure context */
        date_t maintenance_action_due_date;                             /**< The maintenance action due date */
        char * maintenance_action_name;                                 /**< The maintenance action name */
        char * maintenance_action_note;                                 /**< The maintenance action note */
        char * maintenance_action_usage;                                 /**< The maintenance action part usage */        
    } SSF0SERVICEFORECASTING_requires_maintenance_action_t;



/**
   Maintenance Action object structure that holds the entire information about
   a Maintenance Action which is satisfied by the base Maintenance Action.
*/
    typedef struct
    {
        logical maintenance_action_is_auto_complete;                    /**< The maintenance action auto complete */
        logical maintenance_action_is_canceled;                         /**< The maintenance action is canceled */
        logical maintenance_action_is_completed;                        /**< The maintenance action is complete */
        logical maintenance_action_is_due_date_extended;                /**< The maintenance action extention object  */
        tag_t maintenance_action_asset;                                 /**< The maintenance action asset */
        tag_t maintenance_action_part_in_progress;                      /**< The maintenance action impacted part */
        tag_t maintenance_action_part_completed_voided;                 /**< The maintenance action status */
        tag_t maintenance_action_zone;                                  /**< The maintenance action zone */
        tag_t maintenance_action_serv_req;                              /**< The maintenance action source service requirement */
        tag_t maintenance_action_str_context;                           /**< The maintenance action structure context */
        date_t maintenance_action_due_date;                             /**< The maintenance action due date */
        char * maintenance_action_name;                                 /**< The maintenance action name */
        char * maintenance_action_note;                                 /**< The maintenance action note */
        char * maintenance_action_usage;                                 /**< The maintenance action part usage */
    } SSF0SERVICEFORECASTING_satisfies_maintenance_action_t;


/**
   Maintenance Action object structure that holds the entire information about
   a Maintenance Action. This also contains information about requires and satisfies Maintenance Actions.
*/
    typedef struct
    {
        logical maintenance_action_is_auto_complete;                                            /**< The maintenance action auto complete */
        logical maintenance_action_is_canceled;                                                 /**< The maintenance action is canceled */
        logical maintenance_action_is_completed;                                                /**< The maintenance action is complete */
        logical maintenance_action_is_due_date_extended;                                        /**< The maintenance action extention object  */
        tag_t maintenance_action_asset;                                                         /**< The maintenance action asset */
        tag_t maintenance_action_part_in_progress;                                              /**< The maintenance action impacted part */
        tag_t maintenance_action_part_completed_voided;                                         /**< The maintenance action status */
        tag_t maintenance_action_zone;                                                          /**< The maintenance action zone */
        tag_t maintenance_action_serv_req;                                                      /**< The maintenance action source service requirement */
        tag_t maintenance_action_str_context;                                                   /**< The maintenance action structure context */
        date_t maintenance_action_due_date;                                                     /**< The maintenance action due date */
        char * maintenance_action_name;                                                         /**< The maintenance action name */
        char * maintenance_action_note;                                                         /**< The maintenance action note */
        char * maintenance_action_usage;                                                         /**< The maintenance action part usage */
        int number_of_requires_ma;                                                              /**< The number of requires maintenance action  */
        SSF0SERVICEFORECASTING_requires_maintenance_action_t* requires_maintenance_actions;     /**< The requires maintenance action  */
        int number_of_satisfies_ma;                                                             /**< The number of satisfies maintenance action  */
        SSF0SERVICEFORECASTING_satisfies_maintenance_action_t* satisfies_maintenance_actions;   /**< The number of satisfies maintenance action  */
    } SSF0SERVICEFORECASTING_create_maintenance_action_t;



/**
   Creates a Maintenance Action object.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SERVICEFORECASTING_invalid_due_date error if invalid date is provided.
   <li>#SERVICEFORECASTING_ma_create_sc_absent error if structure context is not provided.
   <li>#SERVICEFORECASTING_ma_create_sr_absent error if service requirement is not provided.
   <li>#SERVICEFORECASTING_ma_create_physical_part_absent error if physical part is not provided.
   </ul>
*/
    extern SSF0SERVICEFORECASTING_API int SSF0SERVICEFORECASTING_create_maintenance_action (
        const SSF0SERVICEFORECASTING_create_maintenance_action_t * maintenance_action_info,      /**< (I) Information to create a maintenance action objects.*/
        tag_t* created_maintenance_action                                                        /**< (O) The created maintenance action */
        );

/**
   Cancels the Maintenance Action object.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SERVICEFORECASTING_ma_invalid_role error if logged in user role is not valid.
   <li>#SERVICEFORECASTING_ma_in_approval error if maintenance action is in due date approval process.
   </ul>
*/
    extern SSF0SERVICEFORECASTING_API int SSF0SERVICEFORECASTING_cancel_maintenance_action ( 
        int num_cancel_maintenance_actions,                     /**< (I) Number of maintenance actions to cancel */
        const tag_t* cancel_maintenance_actions                 /**< (I) The maintenance actions to cancel */
        );


/**
   Completes the Maintenance Action object.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SERVICEFORECASTING_ma_invalid_role error if logged in user role is not valid.
   <li>#SERVICEFORECASTING_ma_in_approval error if maintenance action is in due date approval process.
   </ul>
*/
    extern SSF0SERVICEFORECASTING_API int SSF0SERVICEFORECASTING_complete_maintenance_action( 
        int num_complete_maintenance_actions,                      /**< (I) Number of maintenance actions to complete */
        const tag_t* complete_maintenance_actions                  /**< (I) The maintenance actions to complete */
        );


/**
   Extends the due date for the Maintenance Action object.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SERVICEFORECASTING_invalid_due_date error if invalid date is provided.
   <li>#SERVICEFORECASTING_duplicate_extension error if maintenance action is already in due date approval process.
   </ul>
*/
    extern SSF0SERVICEFORECASTING_API int SSF0SERVICEFORECASTING_create_maintenance_extension (
        int num_extend_maintenance_actions,                    /**< (I) Number of maintenance actions to be extended */
        const tag_t* extend_maintenance_actions,               /**< (I) The maintenance actions to be extended */
        date_t request_date,                                   /**< (I) New proposed due date for the maintenance action */
        const char * note                                      /**< (I) Note for extension object */
        );


#ifdef __cplusplus
}
#endif

/**
    @}
*/

#include <ssf0serviceforecasting/libssf0serviceforecasting_undef.h>

#endif
