/*==============================================================================
                Copyright (c) 2009 Siemens PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
   @file
 
   This header file declares all data types and constants to be used by clients of
   MRO module.
*/

#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <unidefs.h>
#include <servicerequest/libservicerequest_exports.h>

/**
    @defgroup SERVICEREQUEST Service Request

    The Service Request module implements the basic set of classes and behaviour
    for the ServiceRequest module.

    @{
*/

/**
    Structure to hold the cost.
    <br>This is used by the function #SERVICEREQUEST_get_cost.
*/
typedef struct {
    char* estimated_labor_cost;     /**< The estimated labor cost */
    char* estimated_labor_hours;    /**< The estimated labor hours */
    char* estimated_material_cost;  /**< The estimated material cost */
    char* estimated_total_cost;     /**< The estimated total cost */
 
    char* actual_labor_cost;        /**< The actual labor cost */
    char* actual_labor_hours;       /**< The actual labor hours */
    char* actual_material_cost;     /**< The actual material cost */
    char* actual_total_cost;        /**< The actual total cost */
} SERVICEREQUEST_cost_t, *SERVICEREQUEST_cost_p_t;

#ifdef __cplusplus
extern "C"{
#endif
    /**
       Initializes the Service Request module.
       <br>This must be called before calling any other SERVICEREQUEST functions.
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_init_module();
    
    /**
       Retrieves the cost for a given Service Request object.
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_get_cost  (
        tag_t service_request,             /**< (I) The Service Request object */
        SERVICEREQUEST_cost_t* cost        /**< (O) A structure containing all the cost information relative to the Service Request 
                                           <br>All the memory of all the members of the returned structure will need to be freed 
                                           using the #MEM_free call, or using #SERVICEREQUEST_free_cost on the structure itself. */
        );
    
    /**
       Deallocates the elements in the provided #SERVICEREQUEST_cost_t structure.
       <br>The function does not de-allocate the structure itself.

       @returns #ITK_ok always
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_free_cost(
        SERVICEREQUEST_cost_t* cost       /**< (I) The structure which elements are to be deallocated */
        );

    /**
       Cancels the requested Service Request.
       <br><ul>
       <li>If the object is a Requested Activity or a Delegate Service Request object, the operation cancels it.
       <li>If the object is a Primary Service Request object, it cancels the Primary Service Request and
       all its Delegate Service Requests and its Requested Activities.
       </ul>
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_cancel_service_object    (
        tag_t service_object  /**< (I) The Service object to cancel */
        );
    
    /**
       Delegates the Service Request
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_delegate_requests    (
        tag_t primary_service_request,        /**< (I) The primary service request */
        tag_t performs_service_request,       /**< (I) The performs service request */
        tag_t delegate_create_input,          /**< (I) The delegate create input */
        int   num_activities,                 /**< (I) Number of requested activities */
        const tag_t *requested_activites,     /**< (I) Array of requested activities */
        tag_t *new_delegate_service_request,  /**< (O) The new delegate service request */
        int   *num_requests_to_refresh,       /**< (O) Number of service requests needing refresh */
        tag_t **requests_to_refresh           /**< (OF) num_requests_to_refresh Array of service requests needing refresh */
        );
    
    /**
       Creates requested activities
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_create_request_activities (
        tag_t requested_activity_create_input, /**< (I) Tag of requested activity create input */
        logical requalify_request_activity,    /**< (I) Determines if this is a requalify */
        int   *num_requested_activities,       /**< (O) Number of new requested activities */
        tag_t **new_requested_activities       /**< (OF) num_requested_activities Array of tags for the new requested activities */
        );
     
    /**
       Substitutes an existing error in the error stack with a specified one.
       <br>If the error @p error_to_replace is found in the error stack, its whole content is cleared
       and the new error @p replacement_error is added to the error stack.
       
       @returns
       <ul>
       <li>#ITK_ok if the error @p error_to_replace was found and the replacement was completed.
       <li>Error @p replacement_error if the error @p error_to_replace was not found in the error stack.
       </ul>
    */
    extern SERVICEREQUEST_API int SERVICEREQUEST_replace_error (
        int   severity,            /**< (I) Error severity */
        int   error_to_replace,    /**< (I) Error ID */
        int   replacement_error,   /**< (I) Error code to be compared */
        const char *s1,            /**< (I) Value for the parameter 1 in the new parameterized error message */
        const char *s2,            /**< (I) Value for the parameter 2 in the new parameterized error message */
        const char *s3,            /**< (I) Value for the parameter 3 in the new parameterized error message */
        const char *s4,            /**< (I) Value for the parameter 4 in the new parameterized error message */
        const char *s5,            /**< (I) Value for the parameter 5 in the new parameterized error message */
        const char *s6,            /**< (I) Value for the parameter 6 in the new parameterized error message */
        const char *s7             /**< (I) Value for the parameter 7 in the new parameterized error message */
        );
#ifdef __cplusplus
}
#endif

/** @} */

#include <servicerequest/libservicerequest_undef.h>

#endif
