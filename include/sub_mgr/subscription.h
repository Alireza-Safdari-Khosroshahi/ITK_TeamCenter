/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by
    clients of the Subscription Manager.
*/

/*  */

#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include <pom/pom/pom_tokens.h>
#include <unidefs.h>

#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup SUBSCRIPTION Subscription Manager

    ITK functions are provided for you to take advantage of the subscription for Assign Status and Attach event types.
    The following new ITK functions are implemented in the existing subscription_itk.cxx,
    tceventmgr_itk.cxx, and tcactionhandler.cxx in the \\src\\sub_mgr module.

    @{
*/

#define SCM_class_name_c              "ImanSubscription"

/**
    @name Defines the notifications priorities on subscription object
    @{
*/

#define SCM_enquiry_normal              "Normal"  /**< priority is normal */
#define SCM_enquiry_high                "High"    /**< priority is high */
#define SCM_enquiry_low                 "Low"     /**< priority is low */

/** @} */

/*
    @name Frequency enumerations for notifications on subscription object
    @{
*/
#define SCM_enquiry_immediately        "Immediately" /**< frequency is immediately as soon as an events are occured*/
#define SCM_enquiry_daily              "Daily"       /**< frequency is daily, notifications are send every day */
#define SCM_enquiry_weekly             "Weekly"      /**< frequency is weekly, notifications are send every week on specify day*/

/** @} */

/*
    @name Execution day enumerations for notifications on subscription object
    @{
*/
#define SCM_enquiry_sunday             "Sunday"        /**< execution day is set to sunday */
#define SCM_enquiry_monday             "Monday"        /**< execution day is set to monday */
#define SCM_enquiry_tuesday            "Tuesday"       /**< execution day is set to tuesday */
#define SCM_enquiry_wednesday          "Wednesday"     /**< execution day is set to wednesday */ 
#define SCM_enquiry_thursday           "Thursday"      /**< execution day is set to thursday */
#define SCM_enquiry_friday             "Friday"        /**< execution day is set to friday */
#define SCM_enquiry_saturday           "Saturday"      /**< execution day is set to saturday */

/** @} */

/**
    Subscription message struct
*/
typedef struct TcSubscriptionActionMsg_s
{
    tag_t   subscriber;
    tag_t   targetObject;
    char*   objectString;
    char*   objTypeName;
    tag_t   eventType;
    tag_t   eventInitiator;
    date_t  timeEventOccured;
    int     attrCount;
    char**  attrNames;
    char**  attrValues;
    tag_t   modifiedObject;
    int    refDataCount;
    char** refDataNames;
    char** refDataValues;
    tag_t  notification;
} TcSubscriptionActionMsg_t, *TcSubscriptionActionMsg_p_t ;

/**
    Subscribe revision operator.
*/
typedef enum SCM_subscribe_to_rev_option_e
{
    SCM_subscribe_to_rev_none,
    SCM_subscribe_to_all_revs,
    SCM_subscribe_to_item_revs,
    SCM_subscribe_to_baseline_revs
} SCM_subscribe_to_rev_option_t;

/**
     Comparative operators.

*/
typedef enum SCM_condition_math_operator_e
{
    SCM_equal     = POM_enquiry_equal,          /**< Math operators "are equal"                 */
    SCM_not_equal = POM_enquiry_not_equal       /**< Math operators "are not equal"                 */
} SCM_condition_math_operator_t;

#ifdef __cplusplus
extern "C"{
#endif

/**
     Builds message that is required to process a Subscription.
     @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_object if the parameter @p target_object is invalid
    <li>#ITK_internal_error in case of other error
    </ul>
*/
extern SUB_MGR_API int SCM_build_subscription_msg(
    tag_t                           subscriber,          /**< (I) This parameter is reserved for future use */
    tag_t                           target_object,       /**< (I) Tag of the object on which the event occured */
    const char*                     obj_str_of_target,   /**< (I) The property "object_string" of the target object */
    tag_t                           target_object_type,  /**< (I) Type tag of the object on which the event occured */
    tag_t                           event_type,          /**< (I) Event Type that is occured */
    date_t                          event_time,          /**< (I) Time when the event occured */
    TcSubscriptionActionMsg_t*      subscription_msg     /**< (O) Subscription message */
    );

/**
     Creates a new notification object that can be passed while creating a Subscription definition
     using #SCM_subscribe_with_condition or #SCM_subscribe_with_notification.
     <br><br>
     This API allows the parameters of the notification e-mail to be specified.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_string_too_long if the input subject string is too long
     <li>#PROP_not_found if an invalid property name has been specified for the subscription target object
     </ul>
*/
extern SUB_MGR_API int SCM_create_notification(
    tag_t              target,              /**< (I) The object to monitor as part of the related subscription */
    const char*        subject,             /**< (I) Subject of the notification e-mail */
    const char*        message,             /**< (I) Message body of the notification e-mail */
    int                properties_count,    /**< (I) Number of properties to include in the notification e-mail */
    const char**       properties,          /**< (I) Properties to include in the notification e-mail */
    tag_t*             notification         /**< (O) New notification object */
    );

/**
     Creates a new Subscription object against the target object.  
     <br/><br/>
     Subscriptions created from this ITK do not function as notification subscriptions.
     This API is intended for triggering custom handlers or handlers that do not specifically
     notify the user.  In order to create Notification subscriptions, use
     #SCM_subscribe_with_notification_options and the #STDHANDLER_MAIL_NOTIFY_ID handler.
     <br/><br/>
     Use #TCACTIONHANDLER_find_handler to retrieve the handler tag.
     <br/><br/>
     Retrieve the event tag with #TCEVENTTYPE_find.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_invalid_subscriber if no subscriber tag was specified
     <li>#SCM_invalid_subscription_handler if an invalid handler is provided
     </ul>
*/
extern SUB_MGR_API int SCM_subscribe(
    tag_t              target,              /**< (I) The object to monitor for the specified event type */
    tag_t              subscriber,          /**< (I) User that is subscribing to the change */
    tag_t              event_type,          /**< (I) Type of event that will trigger the subscription */
    tag_t              handler,             /**< (I) Handler that will process the subscription */
    date_t             execution_time,      /**< (I) When the subscription should be processed.
                                                     <br/>A NULLDATE will trigger immediate processing. */
    date_t             expiration_date,     /**< (I) When the subscription expires.  NULLDATE specifies no expiration. */
    int                parameter_count,     /**< (I) Number of parameters being passed to the handler */
    const char**       handler_parameters,  /**< (I) Parameters being passed to the handler */
    tag_t*             subscription         /**< (O) New subscription object */
    );

/**
     Creates a new Subscription object against the target object type. 
     This API is intended for defining BMIDE based condition criteria instead of attribute based criteria,
     for triggering multiple handlers in the specified order. If this is not the case, use #SCM_subscribe,
     #SCM_subscribe_with_notification or #SCM_subscribe_with_notification_options instead.
     <br><br>
     Subscriptions created from this ITK can function as notification subscriptions if the
     notification object is passed. This can be created using #SCM_create_notification.
     NULLTAG can be specified if none of the handlers are expecting a notification object.
     A notification object is required for the #STDHANDLER_MAIL_NOTIFY_ID handler.
     <br><br>
     Use #TCACTIONHANDLER_find_handler to retrieve the handler tag.
     <br><br>
     Retrieve the event tag with #TCEVENTTYPE_find.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_invalid_subscriber if no subscriber tag was specified
     <li>#SCM_invalid_condition if invalid condition name or signature was specified
     <li>#SCM_duplicate_subscription_handlers when duplicate handlers are specified in the array
     <li>#SCM_invalid_event_type if the event does not respond to target object type
     </ul>
*/
extern SUB_MGR_API int SCM_subscribe_with_condition(
    tag_t              target,              /**< (I) The object to monitor for the specified event type */
    tag_t              subscriber,          /**< (I) User that is subscribing to the change */
    tag_t              event_type,          /**< (I) Type of event that will trigger the subscription */
    int                handler_count,       /**< (I) Number of handlers to be called for this subscription
                                                     In order of execution. */
    const tag_t*       handlers,            /**< (I) List of Handlers that will process the subscription */
    date_t             execution_time,      /**< (I) When the subscription should be processed.
                                                     <br/>A NULLDATE will trigger immediate processing. */
    date_t             expiration_date,     /**< (I) When the subscription expires.  NULLDATE specifies no expiration. */
    const int*         parameter_count,     /**< (I) Array of size @p handler_count, that represents the number of parameters
                                                     being passed to each of the handler from the (handlers - handler_count) list */
    const char***      handler_parameters,  /**< (I) Array of parameters being passed to each of the handler from the (handlers - handler_count) list */
    tag_t              condition,           /**< (I) The condition to evaluate when processing this subscription.
                                                     Can be NULLTAG */
    tag_t              notification,        /**< (I) The notification object to be used for notification handlers.
                                                     Can be NULLTAG */
    tag_t*             subscription         /**< (O) New subscription object */
    );

/**
     Creates a new notification object that can be passed while creating a Subscription definition
     using #SCM_subscribe_with_condition or #SCM_subscribe_with_notification.
     <br><br>
     This API allows the parameters of the notification e-mail to be specified.
     @returns
     <ul>
     <li>#ITK_ok on success.
     <li>#POM_string_too_long if the input subject string is too long.
     <li>#PROP_not_found if an invalid property name was specified for the subscription target object.
     </ul>
*/
extern SUB_MGR_API int SCM_subscribe_with_notification(
    tag_t              target,              /**< (I) The object to monitor for the specified event type */
    tag_t              subscriber,          /**< (I) User that is subscribing to the change */
    tag_t              event_type,          /**< (I) Type of event that will trigger the subscription */
    tag_t              handler,             /**< (I) Handler which will process the subscription */
    date_t             execution_time,      /**< (I) When the subscription should be processed.
                                                     <br/>A NULLDATE will trigger immediate processing. */
    date_t             expiration_date,     /**< (I) When the subscription expires.  NULLDATE specifies no expiration. */
    int                parameter_count,     /**< (I) Number of parameters to be called for this subscription
                                                     in order of execution. */
    const char**       handler_parameters,  /**< (I) Array of parameters being passed to each of the handler from the (handlers - handler_count) list */
    tag_t              notification,        /**< (I) The notification object to be used for notification handlers.
                                                     <br/>This can be NULLTAG */
    tag_t*             subscription         /**< (O) New subscription object */
    );

/**
     Creates a new object Subscription against the target object.
     <br/><br/>
     This API allows the parameters of the notification e-mail to be specified.
     <br/><br/>
     Use #TCACTIONHANDLER_find_handler to retrieve the handler tag. For e-mail
     notification, use the #STDHANDLER_MAIL_NOTIFY_ID handler. The handler
     parameters are the IDs of the users to be notified.
     <br/><br/>
     Retrieve the event tag with #TCEVENTTYPE_find.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_invalid_subscriber if no subscriber tag was specified
     <li>#POM_string_too_long if the input subject string is too long
     <li>#PROP_not_found if an invalid property name was specified for the subscription target object
     </ul>
*/
extern SUB_MGR_API int SCM_subscribe_with_notification_options(
    tag_t              target,              /**< (I) The object to monitor for the specified event type */
    tag_t              subscriber,          /**< (I) User that is subscribing to the change */
    tag_t              event_type,          /**< (I) Type of event that will trigger the subscription */
    tag_t              handler,             /**< (I) Handler that will process the notification */
    date_t             execution_time,      /**< (I) When the subscription should be processed.
                                                     <br/>A NULLDATE will trigger immediate processing. */
    date_t             expiration_date,     /**< (I) When the subscription expires.  NULLDATE specifies no expiration. */
    int                parameter_count,     /**< (I) Number of parameters being passed to the handler */
    const char**       handler_parameters,  /**< (I) Parameters being passed to the handler.  For the #STDHANDLER_MAIL_NOTIFY_ID handler,
                                                     the user IDs of the people to be notified. */
    const char*        subject,             /**< (I) Subject of the notification e-mail */
    const char*        message,             /**< (I) Message body of the notification e-mail */
    int                properties_count,    /**< (I) Number of properties to include in the notification e-mail */
    const char**       properties,          /**< (I) Properties to include in the notification e-mail */
    tag_t*             subscription         /**< (O) New subscription object */
    );

/**
     Retrieves the notification tag from a Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_tag on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_notification(
          tag_t            subscription,       /**< (I) Subscription object */
          tag_t*           notification        /**< (O) Notification object */
          );

/**
     Sets the notification object to be used for notification handlers for a given Subscription object. 
     <br/>Notifications can be created through the #SCM_create_notification method.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_tag on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_set_notification(
          tag_t            subscription,       /**< (I) Subscription object */
          tag_t            notification        /**< (I) Notification object */
          );

/**
    Deletes a Subscription object.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SCM_no_subscription if no subscription exists with the given parameters
    </ul>
*/
extern SUB_MGR_API int SCM_unsubscribe(
    tag_t              subscription     /**< (I) Subscription object */
    );

/**
    Finds a Subscription object matching the specified input parameters. 
    <br/>If no object is found, @p subscription is set to NULLTAG. This should be used when searching for Subscriptions with
    multiple Action Handlers or an attached Condition.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SCM_invalid_parameters if input paramters are bad
    </ul>
*/
extern SUB_MGR_API int SCM_find_subscription(
    tag_t              target,          /**< (I) The object to monitor for the specified event type */
    tag_t              subscriber,      /**< (I) User that is subscribing to the change */
    tag_t              event_type,      /**< (I) Type of event that will trigger the subscription */
    tag_t              handler,         /**< (I) Handler that will process the notification */
    tag_t*             subscription     /**< (O) Subscription object */
    );

/**
     Finds a Subscription object matching the specified input parameters. 
     <br/>If no object is found, subscription is set to NULLTAG. This should be used when searching for Subscriptions with
     multiple Action Handlers or an attached Condition.
     @returns #ITK_ok always
*/
extern SUB_MGR_API int SCM_find_subscription_with_condition(
    tag_t              target,          /**< (I) The object subscribed for the specified event type */
    tag_t              subscriber,      /**< (I) The user subscribed for the change */
    tag_t              event_type,      /**< (I) Type of event which triggers the subscription */
    int                handler_count,   /**< (I) Number of input handlers */
    const tag_t*       handlers,        /**< (I) Handlers that will process the notification */
    tag_t              condition,       /**< (I) The condition used for filtering target objects on the subscription */
    tag_t*             subscription     /**< (O) ImanSubscription object found using the specified search parameters */
    );

/**
     Sets the object or class subscribed for given Subscription.
     <br/>The target can be an object (for object based subscriptions) or a type object (for class based subscriptions).
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access for subscription
     <li>#SCM_duplicate_subscription in case subscription already exists with the specified attributes
     <li>#SCM_no_privilege_to_subscribe in case of insufficient privilege
     </ul>
*/
extern SUB_MGR_API int SCM_set_target(
    tag_t              subscription,    /**< (I) Subscription object */
    tag_t              target           /**< (I) The object subscribed for the specified event type */
    );

/**
     Sets the subscriber for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access for subscription
     <li>#SCM_invalid_subscriber if an invalid subscriber has been specified
     <li>#SCM_duplicate_subscription in case subscription already exists with the specified attributes
     <li>#SCM_no_privilege_to_subscribe in case of insufficient privilege
     </ul>
*/
extern SUB_MGR_API int SCM_set_subscriber(
    tag_t              subscription,    /**< (I) Subscription object  */
    tag_t              subscriber       /**< (I) User that is subscribing to the change */
    );

/** 
    Sets the name of a Subscription object.
    <br/>The @p name parameter can be a NULL pointer, if the Subscription does not have any name.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_string_too_long if the input subject string is too long
    </ul>
*/
extern SUB_MGR_API  int SCM_set_name(
    tag_t              subscription,    /**< (I) Subscription object*/
    const char*        name             /**< (I) Name of the Subscription object,*/
    );

/**
     Sets the type of event for a given Subscription.
     <br/>The provided event type must be a valid event type mapping for the target object type.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access for subscription
     <li>#SCM_duplicate_subscription in case subscription already exists with the specified attributes
     <li>#SCM_invalid_event_type if an invalid event type has been specified
    </ul>
*/    
extern SUB_MGR_API int SCM_set_event_type(
    tag_t              subscription,    /**< (I) Subscription object */
    tag_t              event_type       /**< (I) Type of event which triggers the subscription */
    );


/**
     Sets an array of handlers to execute during subscription event processing. When an event from the
     given subscription is being processed, each of the handlers will be run in order.
     <br><br>
     The same handler can not appear twice in the list.
     <br><br>
     The handlers will be executed in the order they specified in the array.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access for subscription
     <li>#SCM_duplicate_subscription_handlers when duplicate handlers are specified in the array
     <li>#SCM_duplicate_subscription when setting handlers results in duplicate subscription
     <li>#SCM_invalid_condition in case of invalid subscription condition has been specified
     </ul>
*/
extern SUB_MGR_API int SCM_set_handlers(
    tag_t              subscription,    /**< (I) Subscription object */
    int                handler_count,   /**< (I) Number of handlers to set for the subscription */
    const tag_t*       handlers         /**< (I) handler_count Handlers to set for the subscription */
    );

/**
     Sets the time of day that the Subscription will execute
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access for subscription
    </ul>
*/
extern SUB_MGR_API int SCM_set_execution_time(
    tag_t              subscription,    /**< (I) Subscription object */
    date_t             execution_time   /**< (I) Time of the day at which subscription will execute */
    );

/**
     Sets the expiration date of a Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access for subscription
    </ul>
*/
extern SUB_MGR_API int SCM_set_expiration_date(
    tag_t              subscription,    /**< (I) Subscription object */
    date_t             expiration_date  /**< (I) Date of the month the subscription should be valid.
                                                 <br/>Beyond this date subscription will not be valid */
    );


/**
     Sets an array of array of handler parameters for the given subscription handlers.
     <br><br>
     The number of input counts should match the number of handlers for the subscription.
     Each handler will have its own set of parameters.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access to subscription
     </ul>
*/
extern SUB_MGR_API int SCM_set_handler_parameters_array(
    tag_t              subscription,     /**< (I) Subscription object */
    const int*         parameter_counts, /**< (I) Number of parameters for each handler set for the subscription */
    const char***      parameters        /**< (I) parameter_counts Parameters to be used for each handler of the subscription */
    );

/**
     Sets a condition to use during subscription event processing. When an event from the
     given Subscription is being processed, the condition will be evaluated. If the condition
     evaluates to false, the event will not be processed.
     <br><br>
     The condition must have a POM_object and UserSession as parameters.
     <br><br>
     This can only be used on class based subscriptions.
     <br><br>
     Setting the condition to NULLTAG will remove the current condition from the subscription.
     If this is done, no condition will be evaluated to filter the subscription events.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_no_modify_access if user has no modify access to subscription
     <li>#SCM_invalid_condition if the condition specified does not include the correct signature
     <li>#SCM_duplicate_subscription when setting condition results in duplicate subscription
     </ul>
*/
extern SUB_MGR_API int SCM_set_condition(
    tag_t              subscription,    /**< (I) Subscription object */
    tag_t              condition        /**< (I) Condition to set on the subscription */
    );

/**
     Retrieves the target from a Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_target(
    tag_t              subscription,    /**< (I)  Subscription object */
    tag_t*             target           /**< (O)  Tag of the target object */
    );
/** 
    Sets the notification frequency on events generated from subscriptions object, as well as the execution period.
    <ul>
    <li>If @p execution_frequency is #SCM_enquiry_immediately, @p execution_time and @p execution_day shall be ignored.
    <li>If @p execution_frequency is #SCM_enquiry_daily, @p execution_day shall be ignored.
    <li>If @p execution_frequency is #SCM_enquiry_weekly, @p execution_time and @p execution_day both should have valid values.
    </ul>
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCM_invalid_frequency in case of invalid frequency value.
    <li>#SCM_set_execution_period_failed in case of invalid parameters.
    <li>#SCM_invalid_execution_day if @p execution_day is an invalid day.
    </ul>
    
*/

extern SUB_MGR_API int SCM_set_execution_period(
    tag_t           subscription,      /**< (I) Subscription object. */
    const char*     execution_frequency,         /**< (I) Frequency can be one of values
                                              #SCM_enquiry_immediately <br/>
                                              #SCM_enquiry_daily <br/>
                                              #SCM_enquiry_weekly <br/>
                                              <br/>If NULL pass throws #SCM_invalid_frequency error*/
    date_t          execution_time,          /**< (I) Only the hour and minutes are useful. */
    const char*     execution_day            /**< (I) 7 days of week can be one of following
                                              #SCM_enquiry_sunday <br/>
                                              #SCM_enquiry_monday <br/>
                                              #SCM_enquiry_tuesday <br/>
                                              #SCM_enquiry_wednesday <br/>
                                              #SCM_enquiry_thursday <br/>
                                              #SCM_enquiry_friday <br/>
                                              #SCM_enquiry_saturday <br/>
                                              it can be null in case @p execution_frequency is #SCM_enquiry_immediately,#SCM_enquiry_daily*/
    );

/** 
    Sets the temporary notifier using date range.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCM_no_self_transfer if @p temp_notifier is the original subscriber.
    <li>#SCM_set_end_date_failed if @p transfer_end_date anterior to @p transfer_start_date.
    <li>#SCM_set_start_date_failed if @p transfer_start_date earlier than @p transfer_end_date.
    <li>#SCM_no_modify_access if @p temp_notifier does not have modify permission.
    </ul>
*/

extern SUB_MGR_API int SCM_set_temporary_notifier(
     tag_t           subscription,          /**< (I) Subscription object*/
     tag_t           temp_notifier,         /**< (I) User to notify for temporary period */
     date_t          transfer_start_date,   /**< (I) Temporary transfer start date, only year, month, day is important */
     date_t          transfer_end_date      /**< (I) Temporary transfer end date, only year, month, day is important */
     );

/** 
    Sets the Subscription to new user permanently.
    <br/>The susbcriber and the user in the notifier list will be replaced with the @p transferred_to user.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCM_invalid_userid if @p transferred_to is invalid notifier.
    <li>#SCM_no_modify_access if @p transferred_to does not have an access to modify the subscription.
    <li>#SCM_no_privilege_to_subscribe if @p transferred_to user does not have privilege to subscribe.
    </ul>
*/
     
extern SUB_MGR_API int SCM_set_permanent_transfer(
     tag_t           subscription,         /**< (I) Subscription object*/
     tag_t           transferred_to        /**< (I) New owner of subscription */
     );


/** 
    Sets the priority on subscription notification.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCM_set_priority_failed if an invalid priority set on subscription. Please set #SCM_enquiry_normal, SCM_enquiry_high or SCM_enquiry_high as priority.
    </ul>
*/
extern SUB_MGR_API int SCM_set_priority(
     tag_t             subscription,             /**< (I) Subscription object*/
     const char*       execution_priority        /**< (I) Use one of following:<ul>
                                                    <li>#SCM_enquiry_normal
                                                    <li>#SCM_enquiry_high
                                                    <li>#SCM_enquiry_low
                                                    </ul>
                                                 It can be a null pointer in case of @p execution_priority to be ignored.*/
     );

/** 
    Sets the susbscription active or inactive state.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SCM_no_modify_access if the user does not have an access to modify the subscription.
    </ul>

*/
extern SUB_MGR_API int SCM_set_is_active(
     tag_t           subscription,       /**< (I) Subscription object */
     logical         is_active           /**< (I) True for active, false for inactive*/
     );

/** 
    Retrieves the frequency, execution time and execution day of a Subscription.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_attr_id on incorrect subscription object
    </ul>
*/
extern SUB_MGR_API int SCM_ask_execution_period(
      tag_t             subscription,         /**< (I) Subscription object.*/
      char**            execution_frequency,  /**< (OF) one of following value <br/>
                                                     #SCM_enquiry_immediately <br/>
                                                     #SCM_enquiry_daily <br/>
                                                     #SCM_enquiry_weekly <br/>*/
      date_t*           execution_time,       /**< (O) Execution time. Only the hour and minute is filled. */
      char**            execution_day         /**< (OF) one of following values
                                                  #SCM_enquiry_sunday <br/>
                                                  #SCM_enquiry_monday <br/>
                                                  #SCM_enquiry_tuesday <br/>
                                                  #SCM_enquiry_wednesday <br/>
                                                  #SCM_enquiry_thursday <br/>
                                                  #SCM_enquiry_friday <br/>
                                                  #SCM_enquiry_saturday <br/>
                                                  It can be a null pointer in case execution day is not set <br/>*/
      );

/** 
    Retrieves the priority on Notifications.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_attr_id on incorrect subscription object
    </ul>
    
*/
extern SUB_MGR_API int SCM_ask_priority(
     tag_t           subscription,       /**< (I) Subscription object */
     char**          priority            /**< (OF) The returned value can be:
                                            <ul>
                                            <li>#SCM_enquiry_normal
                                            <li>#SCM_enquiry_high
                                            <li>#SCM_enquiry_low
                                            </ul>
                                            It can be a null pointer in case if not set.
                                         */
     );

/** 
    Retrieves the active or inactive status of a Subscription.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_attr_id on incorrect subscription object
    </ul>
*/
extern SUB_MGR_API int SCM_ask_is_active(
     tag_t           subscription,       /**< (I) Subscription object */
     logical*        is_active           /**< (O) true for active, false for inactive*/
     );

/** 
    Retrieves the name of a Subscription.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_attr_id on incorrect subscription object
    </ul>
*/
extern SUB_MGR_API int SCM_ask_name(
     tag_t             subscription,     /**< (I) Subscription object */
     char**            name              /**< (OF) Name of Subscription  <br/>
                                                It can be a null pointer if the name is not set*/
     );

/**
     Retrieves the user subscribing to the change from a Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_subscriber(
    tag_t              subscription,    /**< (I) Subscription object */
    tag_t*             subscriber       /**< (O) User subscribing to the change */
    );

/**
     Retrieves the event type from a Subscription
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_event_type(
    tag_t              subscription,    /**< (I) Subscription object */
    tag_t*             event_type       /**< (O) Type of event that will trigger the subscription */
    );


/**
     Retrieves the ordered array of handlers to be executed for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_handlers(
    tag_t              subscription,    /**< (I) Subscription object */
    int*               handler_count,   /**< (O) Number of handlers set for the subscription */
    tag_t**            handlers         /**< (OF) handler_count Handlers set for the subscription */
    );

/**
     Retrieves the execution time from a Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_execution_time(
    tag_t              subscription,    /**< (I) Subscription object */
    date_t*            execution_time   /**< (O) Time of day the subscription will be execute */
    );

/**
     Retrieves the expiration date from a Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_expiration_date(
    tag_t              subscription,    /**< (I) Subscription object */
    date_t*            expiration_date  /**< (O) Day till subscription is valid*/
    );


/**
     Retrieves an array of array of handler parameters for the given Subscription.
     <br><br>
     The number of output counts will match the number of handlers for the subscription.
     Each handler will have its own set of parameters.
     <br><br>
     The caller is responsible for freeing each of the arrays in the output parameters using
     #TC_free_strings, and then freeing the output parameters itself.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_handler_parameters_array(
    tag_t              subscription,     /**< (I) Subscription object */
    int*               handler_count,    /**< (O) Number of event handlers set for the subscription */
    int**              parameter_counts, /**< (OF) handler_count Number of parameters for each handler set for the subscription */
    char****           parameters        /**< (OF) parameter_counts Parameters to be used for each handler of the subscription */
    );

/**
     Retrieves condition to be evaluated for the given subscription execution.
     <br><br>
     If no condition is set, NULLTAG will be returned.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_condition(
    tag_t              subscription,    /**< (I) Subscription object */
    tag_t*             condition        /**< (O) Condition set on the subscription */
    );

/**
     Retrieves the e-mail subject to be displayed in notifications for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object
     </ul>
*/
extern SUB_MGR_API int SCM_ask_notification_subject(
    tag_t              subscription,    /**< (I) Subscription object */
    char**             subject          /**< (OF) Subject of the notification e-mail */
    );

/**
     Sets the e-mail subject to be displayed in notifications for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_tag on incorrect subscription object tag
     <li>#SCM_no_modify_access if the user does not have the permission to modify this subscription
     <li>#POM_string_too_long if the input subject string is too long
     </ul>
*/
extern SUB_MGR_API int SCM_set_notification_subject(
    tag_t              subscription,    /**< (I) Subscription object */
    const char*        subject          /**< (I) Subject of the notification e-mail */
    );

/**
     Retrieves the e-mail message to be displayed in notifications for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object tag
     </ul>
*/
extern SUB_MGR_API int SCM_ask_notification_message(
    tag_t              subscription,    /**< (I) Subscription object */
    char**             message          /**< (OF) Message body of the notification e-mail */
    );

/**
     Sets the e-mail message to be displayed in notifications for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_tag on incorrect subscription object tag
     <li>#SCM_no_modify_access if the user does not have the permission to modify this subscription
     <li>#POM_string_too_long if the input subject string is too long
     <li>#POM_invalid_attr_id on incorrect subscription object tag
     </ul>
*/
extern SUB_MGR_API int SCM_set_notification_message(
    tag_t              subscription,    /**< (I) Subscription object */
    const char*        message          /**< (I) Message body of the notification e-mail */
    );

/**
     Retrieves the object properties to be displayed in notifications for the given Subscription.
     <br/><br/>
     The returned array of properties should be freed with a single #MEM_free call.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object tag
     </ul>
*/
extern SUB_MGR_API int SCM_ask_notification_properties(
    tag_t              subscription,    /**< (I) Subscription object */
    int*               count,           /**< (O) Number of properties */
    char***            properties       /**< (OF) count Object properties to be displayed in the body of the notification e-mail */
    );

/**
     Sets the object properties to be displayed in notifications for the given Subscription.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#POM_invalid_attr_id on incorrect subscription object tag
     <li>#SCM_no_modify_access if the user does not have the permission to modify this Subscription
     <li>#PROP_not_found if an invalid property name is specified for the Subscription target object
     </ul>
*/
extern SUB_MGR_API int SCM_set_notification_properties(
    tag_t              subscription,    /**< (I) Subscription object */
    int                count,           /**< (I) Number of properties.  Can be zero. */
    char**             properties       /**< (I) Object properties to be displayed in the body of the notification e-mail */
    );

/**
    Creates a Subscription for Assign Status event type.
    <br><br>
    <b>Restrictions:</b>
    This ITK function is used only for Assign Status event type.

    @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_invalid_subscriber if no subscriber tag has been specified
     <li>#SCM_invalid_status if an invalid release status type name has been specified
     <li>#SCM_invalid_rev_flag if the rev flag is set to true but the target is not an item object
     <li>#SCM_duplicate_subscription in case subscription already exists with the specified attributes
     <li>#SCM_no_privilege_to_subscribe if the user does not have the privilege to create this subscription
     </ul>
*/
extern SUB_MGR_API int SCM_subscribe_assign_status_event(
    tag_t              target,                      /**< (I) Tag of the target object */
    tag_t              subscriber,                  /**< (I) User tag for the subscriber */
    tag_t              handler,                     /**< (I) Tag of the action handler */
    date_t             execution_time,              /**< (I) Time when the event needs to be processed by the daemon */
    date_t             expiration_date,             /**< (I) Date when the subscription expires */
    int                parameter_count,             /**< (I) Number of action handler parameters */
    const char**       parameters,                  /**< (I) parameter_count String array of action handler parameters */
    const char*        release_status_type_name,    /**< (I) This is the name of a release status type.
                                                            If the string is an empty string, it means any status. */
    logical            all_rev_flag,                /**< (I) If this flag is true, the target object subscribed must be
                                                            an Item object so that when release status is assigned to
                                                            an ItemRevision object under the Item object,
                                                            proper action gets carried out.
                                                            If this flag is false, then proper action gets carried out when
                                                            the target object itself is assigned a release status. */
    tag_t*             subscription                 /**< (O) The tag of created subscription */
    );

/**
    Creates a Subscription for an Attach event type.

    <b>Restrictions:</b>
    This ITK function is used only for Attach event type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SCM_invalid_subscriber if no subscriber tag has been specified
    <li>#SCM_invalid_relation if an invalid relation type name has been specified
    <li>#SCM_invalid_secondary_object_type if an invalid secondary object type name has been specified
    <li>#SCM_invalid_rev_flag if the rev flag is set to true but the target is not an item object
    <li>#SCM_no_privilege_to_subscribe if the user does not have the privilege to create this subscription
    <li>#SCM_duplicate_subscription if a Subscription already exists with the attributes specified
    </ul>
*/
extern SUB_MGR_API int SCM_subscribe_attach_event(
    tag_t              target,                      /**< (I) Tag of the target object */
    tag_t              subscriber,                  /**< (I) User tag for the subscriber */
    tag_t              handler,                     /**< (I) Tag of the action handler */
    date_t             execution_time,              /**< (I) Time when the event is processed by the daemon */
    date_t             expiration_date,             /**< (I) Date when the subscription expires */
    int                parameter_count,             /**< (I) Number of action handler parameters */
    const char**       parameters,                  /**< (I) parameter_count String array of action handler parameters */
    const char*        relation_type_name,          /**< (I) This is the name of a Teamcenter Engineering relation.
                                                            If the string is an empty string, it means any relation. */
    const char*        secondary_object_type_name,  /**< (I) This is the name of a secondary object type.
                                                            If the string is an empty string, it means any object type. */
    logical            all_rev_flag,                /**< (I) If this flag is true, the target object subscribed must be
                                                            an Item object so that when a secondary object is attached to
                                                            an ItemRevision object under the Item object, proper action gets
                                                            carried out. If this flag is false, then proper action gets
                                                            carried out when the target object itself gets a
                                                            secondary object attached. */
    tag_t*             subscription                 /**< (O) The tag of created subscription */
    );

/**
    Creates a Subscription object for Assign Status event type.

    <b>Restrictions:</b>
    This ITK function is used only for Assign Status event type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SCM_invalid_subscriber if no subscriber tag has been specified
    <li>#SCM_invalid_status if an invalid release status type name has been specified
    <li>#SCM_invalid_rev_flag if the rev flag is set to true but the target is not an item object
    <li>#SCM_no_privilege_to_subscribe if the user does not have the privilege to create this subscription
    <li>#SCM_duplicate_subscription if a subscription already exists with the attributes specified
    </ul>
*/
extern SUB_MGR_API int SCM_subscribe_to_status_event(
    tag_t              target,                      /**< (I) Tag of the target object */
    tag_t              subscriber,                  /**< (I) User tag for the subscriber */
    tag_t              handler,                     /**< (I) Tag of the action handler */
    date_t             execution_time,              /**< (I) Time when the event needs to be processed by the daemon */
    date_t             expiration_date,             /**< (I) Date when the subscription expires */
    int                parameter_count,             /**< (I) Number of action handler parameters */
    const char**       parameters,                  /**< (I) parameter_count String array of action handler parameters */
    SCM_condition_math_operator_t math_operator,    /**< (I) math operator for subscription condition,
                                                             if SCM_equal, event fired for the target has the given status assigned
                                                             if SCM_not_equal, event fired if the target has an assigned status different from the given status.
                                                             SCM_not_equal math operator is NOT applicable if release status type name input is empty */
    const char*        release_status_type_name,    /**< (I) This is the name of a release status type.
                                                            If the string is an empty string, it means any status. */
    SCM_subscribe_to_rev_option_t rev_option,       /**< (I)if SCM_subscribe_to_rev_none, no event is fired when a status event occurs on any item revision of the target item, but
                                                               the event is fired only when a status event occurs on the target item.
                                                            if SCM_subscribe_to_all_revs, a status event is also fired when a status event occurs on any item revision of the target item.
                                                            if SCM_subscribe_to_item_revs, a status event is also fired when a status event occurs on any Base item revision of the target item.
                                                            if SCM_subscribe_to_baseline_revs, a status event is also fired when a status event occurs on any Baseline item revision of the target item.
                                                            this option is applicable only if the target is an item */
    tag_t*             subscription                 /**< (O) The tag of created subscription */
    );

/**
    Creates a Subscription for New IR event type.

    <b>Restrictions:</b>
    This ITK function is used only for New IR event type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SCM_invalid_subscriber if no subscriber tag was specified
    <li>#SCM_invalid_rev_flag if the rev flag is set to true but the target is not an item object
    <li>#SCM_no_privilege_to_subscribe if the user does not have the privilege to create this subscription
    <li>#SCM_duplicate_subscription if a subscription already exists with the attributes specified
    </ul>
*/
extern SUB_MGR_API int SCM_subscribe_to_rev_create_event(
    tag_t              target,                      /**< (I) Tag of the target object that must be an item*/
    tag_t              subscriber,                  /**< (I) User tag for the subscriber */
    tag_t              handler,                     /**< (I) Tag of the action handler */
    date_t             execution_time,              /**< (I) Time when the event needs to be processed by the daemon */
    date_t             expiration_date,             /**< (I) Date when the subscription expires */
    int                parameter_count,             /**< (I) Number of action handler parameters */
    const char**       parameters,                  /**< (I) parameter_count String array of action handler parameters */
    SCM_subscribe_to_rev_option_t rev_option,       /**< (I) if SCM_subscribe_to_all_revs, a new IR event is fired when any item revision is created for the target item.
                                                             if SCM_subscribe_to_item_revs, a new IR event is fired when any Base item revision is created for the target item.
                                                             if SCM_subscribe_to_baseline_revs, a new IR event is fired when any Baseline item revision is created for the target item.
                                                             SCM_subscribe_to_rev_none option is NOT applicable and the target must be an item */
    tag_t*             subscription                 /**< (O) The tag of created subscription */
    );

/**
     Sets the named subscription object with inactive or active Subscription. 
     <br/>It also provides the way to specify the frequency at which the notification is to be set.
     <br><br>
      Notification tag should be created before passing to API, Use NULLTAG to ignore the parameter.

     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#SCM_invalid_subscriber if no subscriber tag was specified
     <li>#PROP_not_found if an invalid property name is specified for the Subscription target object
     </ul>
*/
extern SUB_MGR_API int SCM_subscribe_with_options(
        tag_t                               target,              /**< (I) The object to monitor for the specified event type */
        tag_t                               subscriber,          /**< (I) User that is subscribing to the change */
        tag_t                               event_type,          /**< (I) Type of event that will trigger the subscription */
        tag_t                               handler,             /**< (I) Handler that will process the subscription */
        date_t                              execution_time,      /**< (I) When the subscription should be processed.
                                                                          NULLDATE will trigger immediate processing .*/
        date_t                              expiration_date,     /**< (I) When the subscription expires.  NULLDATE specifies no expiration.*/
        int                                 parameter_count,     /**< (I) Number of parameters being passed to the handler */
        const char**                        handler_parameters,  /**< (I) Parameters being passed to the handler */
        const char*                         name,                /**< (I) Name of subscription. It can be a null pointer if the Subscription does not have any name. */
        logical                             is_active,           /**< (I) If this flag is true- Subscriptions are active. 
                                                                      <br/> If this flag is false Subscriptions are inactive.*/
        const char*                         execution_priority,  /**< (I) Subscription priority <br/>
                                                                        #SCM_enquiry_normal <br/>
                                                                        #SCM_enquiry_high <br/>
                                                                        #SCM_enquiry_low <br/>*/
        tag_t                               notification,        /**< (I) Notification object attached with this subscription*/
        const char*                         execution_frequency, /**< (I) Frequency of executing Subscription notifications 
                                                                      <br/> If #SCM_enquiry_immediately, 
                                                                      <br/>    then @p execution_time & @p execution_day parameters will be ignored
                                                                      <br/> If #SCM_enquiry_daily, 
                                                                      <br/>           then  @p execution_day parameters will be ignored 
                                                                      <br/> If #SCM_enquiry_weekly 
                                                                      <br/>           then  notification will be triggered on @p execution_day */
        const char*                         execution_day,      /**< (I) Execution day of Subscription notification configured for weekly execution <br/>
                                                                       #SCM_enquiry_sunday <br/>
                                                                       #SCM_enquiry_monday <br/>
                                                                       #SCM_enquiry_tuesday <br/>
                                                                       #SCM_enquiry_wednesday <br/>
                                                                       #SCM_enquiry_thursday <br/>
                                                                       #SCM_enquiry_friday <br/>
                                                                       #SCM_enquiry_saturday <br/>*/
        tag_t*                              subscription        /**<  (O) New subscription object */
        );

extern SUB_MGR_API void write_Attributexml_keyword( const char         *prefix,
                                                    const char         *keyword1,
                                                    const char         *value1,
                                                    const char         *keyword2,
                                                    const char         *value2,
                                                    char               **buffer
                                                    );
/**
   Retrieves all the subscribable types and their children for each child type options.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_name class if the attribute, group or user name does not follow the naming rules - i.e. printable and length restrictions
   <li>#POM_no_attr_of_this_name if no attribute exists with the given name in the specified class.
   </ul>
*/
extern SUB_MGR_API int SCM_get_subscrible_types (
    const char* child_type_option,                   /**< (I) The option to specify what child type to use */
    int*        count,                               /**< (O) Number of tags */
    tag_t**     types                                /**< (OF) count Types of tags */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sub_mgr/libsub_mgr_undef.h>
#endif
