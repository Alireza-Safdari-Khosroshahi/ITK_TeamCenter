/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef SUBSCRIPTION_ERRORS_H
#define SUBSCRIPTION_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup SUBSCRIPTION_ERRORS Subscription Errors
    @ingroup SUBSCRIPTION
    @{
*/

#define SCM_module_not_initialized          (EMH_SCM_error_base + 0)
#define SCM_internal_error                  (EMH_SCM_error_base + 1)
#define SCM_duplicate_subscription          (EMH_SCM_error_base + 2)
#define SCM_invalid_target_object           (EMH_SCM_error_base + 3)
#define SCM_invalid_event_type              (EMH_SCM_error_base + 4)
#define SCM_invalid_subscription_handler    (EMH_SCM_error_base + 5)
#define SCM_invalid_subscriber              (EMH_SCM_error_base + 6)
#define SCM_no_modify_access                (EMH_SCM_error_base + 7)
#define SCM_no_delete_access                (EMH_SCM_error_base + 8)
#define SCM_subscriptions_disabled          (EMH_SCM_error_base + 9)
#define SCM_no_subscription                 (EMH_SCM_error_base + 10)
#define SCM_invalid_parameters              (EMH_SCM_error_base + 11)
#define SCM_no_privilege_to_subscribe       (EMH_SCM_error_base + 12)
#define SCM_invalid_status                  (EMH_SCM_error_base + 13)
#define SCM_invalid_relation                (EMH_SCM_error_base + 14)
#define SCM_invalid_secondary_object_type   (EMH_SCM_error_base + 15)
#define SCM_invalid_rev_flag                (EMH_SCM_error_base + 16)

/** An invalid subscription condition has been specified. Please verify that the condition is one of the following: %1$. If this is correct, check that the condition signature includes at least one of the following object types: %2$. */
#define SCM_invalid_condition               (EMH_SCM_error_base + 17)

/** Duplicate action handlers have been specified as input to the specified subscription. Please verify that the list of input handlers does not contain any duplicate values. */
#define SCM_duplicate_subscription_handlers (EMH_SCM_error_base + 18)

/** The subscription could not be created with the given criteria. Please verify that the input values are valid and will not cause duplicate subscriptions. */
#define SCM_create_subscriptions_failed     (EMH_SCM_error_base + 19)

/** The operation to find subscriptions could not be completed with the given input criteria. Please verify that the input values are valid for use with subscriptions. */
#define SCM_find_subscriptions_failed       (EMH_SCM_error_base + 20)

/** The specified subscription could not be modified with the given criteria. Please verify that the input values are valid and will not cause duplicate subscriptions. */
#define SCM_modify_subscriptions_failed     (EMH_SCM_error_base + 21)

/** The operation to get subscriptions could not be completed with the given input criteria. Please verify that the input values are valid for use with subscriptions. */
#define SCM_get_subscriptions_failed        (EMH_SCM_error_base + 22)

/** The operation to set priority could not be completed with the given input value. Please verify that the input values are Low, Normal and High. */
#define SCM_set_priority_failed             (EMH_SCM_error_base + 23)

/** An invalid user ID is set as a transfer notifier. */
#define SCM_invalid_userid                  (EMH_SCM_error_base + 24)

/** An invalid frequency is specified. Please verify that input values are Immediately, Daily and Weekly. */
#define SCM_invalid_frequency               (EMH_SCM_error_base + 25)

/** An invalid execution day is specified. Please verify that input values are Sunday, Monday, Tuesday, Wednesday, Thursday, Friday and Saturday.*/
#define SCM_invalid_execution_day           (EMH_SCM_error_base + 26)

/** The operation to set the execution period could not be completed with the given input. Please verify that the input values are valid.*/
#define SCM_set_execution_period_failed     (EMH_SCM_error_base + 27)

/** An invalid start date is specified. It must be equal to or later than the current date. */
#define SCM_set_start_date_failed           (EMH_SCM_error_base + 28)

/** An invalid end date is specified. It must be later than the start date. */
#define SCM_set_end_date_failed             (EMH_SCM_error_base + 29)

/** An invalid expiration date is specified. It must not be earlier than the current date. */
#define SCM_invalid_expiration_date         (EMH_SCM_error_base + 30)

/** The specified child type option is invalid. It must be one of the following: child_types, child_types_same_class, subtypes, subtypes_same_class, or child_primary_types. */
#define SCM_invalid_child_type_option       (EMH_SCM_error_base + 31)

/** The target user does not have access to the subscription. */
#define SCM_notifier_access_failed          (EMH_SCM_error_base + 32)

/** The target user cannot notify other users, because it is not the owner of the subscription.*/
#define SCM_set_temporary_notifier_failed   (EMH_SCM_error_base + 33)

/** An invalid attribute criteria is specified. It must be one of AND or OR for logical operators, and =, < , >, !=, <=, >= for math operators.*/
#define SCM_invalid_attribute_criteria      (EMH_SCM_error_base + 34)

/** The operation to retrieve data of Assign Event type could not be completed. Please check the Teamcenter syslog file.*/
#define SCM_get_assign_event_data_failed    (EMH_SCM_error_base + 35)

/** The new subscriber cannot be the same as the original one.*/
#define SCM_no_self_transfer                (EMH_SCM_error_base + 36)

/** The operation to unsubscribe could not be completed. Please verify that the input values are valid or the Subscription could have been deleted.*/
#define SCM_unsubscribe_failed              (EMH_SCM_error_base + 37)

/** The operation to copy Subscriptions could not be completed. Please verify that the input Subscriptions and users are valid.*/
#define SCM_save_as_subscription_failed     (EMH_SCM_error_base + 38)

/** The asynchronous messaging system is not installed or configured correctly. Please contact the system administrator to configure the Teamcenter server for asynchronous messaging support.*/
#define SCM_async_messaging_error           (EMH_SCM_error_base + 39)

/** The new recipients added to the Subscription "%1$" could not be notified. Please check the Teamcenter syslog file. */
#define SCM_recipient_notification_failed   (EMH_SCM_error_base + 40)

/** The Message "%1$" will not be published to the message cache, because its UID could not be retrieved. */ 
#define SCM_publish_message_failed_uid      (EMH_SCM_error_base + 41)

/** Unread Messages for the user "%1$" could not be published to the message cache. */ 
#define SCM_publish_message_failed          (EMH_SCM_error_base + 42)

/** The initialization of the aysnchronous messaging system has failed. Please contact the system administrator. */ 
#define SCM_async_message_init_fail         (EMH_SCM_error_base + 43)

/** A Subscription Template named "%1$" already exists. Please enter a unique name for the Subscription Template.*/
#define SCM_duplicate_subscription_template             (EMH_SCM_error_base + 44)

/** Subscription Templates can only be created, modified or deleted by a privileged user.*/
#define SCM_subscription_template_no_privilege          (EMH_SCM_error_base + 45)

/** The name of a Subscription Template cannot be modified.*/
#define SCM_subscription_template_name_not_modifiable   (EMH_SCM_error_base + 46)

/** The creation of Subscription Templates could not be completed. Please verify that the closure rule, subscribed object, target object and their criteria are valid.*/
#define SCM_create_subscription_template_failed         (EMH_SCM_error_base + 47)

/** The retrieval of Subscription Templates could not be completed. Please verify that the specified subscribed object is valid.*/
#define SCM_get_subscription_template_failed            (EMH_SCM_error_base + 48)

/** The modification of Subscription Templates could not be completed. Please verify that the specified Subscription Templates are valid.*/
#define SCM_modify_subscription_template_failed         (EMH_SCM_error_base + 49)

/** The operation to unsubscribe could not be completed. The user is not a valid notifier.*/
#define SCM_invalid_unsubscriber                        (EMH_SCM_error_base + 50)

/** The following properties are not valid to configure for the type "%2$" as subscribable properties: %1$.*/
#define SCM_invalid_criteria_property                   (EMH_SCM_error_base + 51)

/** A Subscription Criteria Property Configuration for type "%1$" already exists. */
#define SCM_duplicate_criteria_configuration            (EMH_SCM_error_base + 52)

/** A value provided for the preference "SCM_newsfeed_purge_threshold" is invalid. The valid values are positive integers.*/
#define SCM_invalid_newsfeed_purge_threshold            (EMH_SCM_error_base + 53)

/** @} */

#include <sub_mgr/libsub_mgr_undef.h>
#endif

