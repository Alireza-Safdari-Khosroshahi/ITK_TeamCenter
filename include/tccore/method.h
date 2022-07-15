/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Method function prototypes
*/

/*  */

#ifndef METHOD_H
#define METHOD_H

#include <unidefs.h>
#include <tc/emh.h>
#include <tc/tc_startup.h>
#include <tc/tc_arguments.h>
#include <fclasses/tc_stdarg.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup METHOD Methods

    Methods control the behavior of Teamcenter objects.
    Methods are registered for combinations of object type and message (save, create, etc).
    The ITK allows additional control of primary Teamcenter types and custom types.

    Methods' ITK functions are logically grouped and presented in this topic as follows:

    Prototypes for methods functions are found in the method.h header file

    Teamcenter system messages (e.g., save, delete) are defined with their arguments in tc_msg.h

    Module-specific messages are defined in \<module\>_msg.h, (e.g., #ITEM_create_msg is defined in item_msg.h).
    @{
*/

/**
    Identifies a registered method, e.g. to add a pre/post action to it.
*/
typedef struct METHOD_id_s
{
    int   reserved;    /**< reserved for future use */
    void* id;
} METHOD_id_t;

/**
    Contextual information passed with a message to a function registered as an action for a method.
*/
typedef struct METHOD_message_s
{
    tag_t                 object;       /**< Reserved for future use. */
    METHOD_id_t           method;
    void*                 system_data;  /**< Data structures for different messages. Use macros to access data. */
    TC_argument_list_t* user_args;    /**< Arguments from add_action. */
    tag_t                 object_tag;
    const char*           prop_name;
    void*                 imanProp;     /**< Internal use only */
    void*                 propDesc;     /**< Internal use only */
} METHOD_message_t;

/**
    All functions registered as base, pre or post actions,
    or pre condition handlers must be of this type.
    Return value should be #ITK_ok to indicate1 success,
    or the value of the top error from the error store to indicate failure.
*/
typedef int (* METHOD_function_t)(
    METHOD_message_t*,
    va_list
    );

typedef enum METHOD_action_type_e
{
    METHOD_pre_action_type,
    METHOD_post_action_type
} METHOD_action_type_t;

/** Enumeration for Extension Point Type Operation */
typedef enum ExtensionPointType_e
{
    ExtensionPointType_Unknown,
    ExtensionPointType_PreCondition,
    ExtensionPointType_PreAction,
    ExtensionPointType_Post,
    ExtensionPointType_Base
}ExtensionPointType_t;

/**
    @name METHOD Execution Functions

    @note Execution of registered methods is implemented in Teamcenter core code for
    all Teamcenter defined messages. ITK is only only required to define custom messages.

    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
    A message (e.g., save, delete) is passed to an object in order to execute the
    method registered for the relevant combination of message and object type.
    Messages are uniquely defined by a text string,
    but for efficiency at run-time we use an integer message identifier.
    This function returns the integer ID associated with the given message name.

    The macro #METHOD_SETUP_MESSAGE will declare a static int in function,
    cache the msg_id and look it up on the first pass and return an integer failure code if the lookup failed.
    This will save time by eliminating the need to look up the msg_id each time a message is dispatched.
*/
extern TCCORE_API int METHOD_get_message_id(
    const char*         msg_name,   /**< (I) Text identifier for the message,
                                            as defined in a \<module\>_msg.h include file */
    int*                msg_id      /**< (O) Run-time identifier for the message */
    );

extern TCCORE_API int METHOD_get_message_name ( int msg_id, char **method_name );

extern TCCORE_API int METHOD_get_prop_message_name ( int msg_id, const char *property_name, char **method_name );

#ifdef __cplusplus
}
#endif

/**
    This macro can be used to setup a static message id in your routines to save repeated lookups.
    Note that if lookup fails it will cause the function you are invoking it from to return an ifail code:
    so your function must be returning an int.
*/
#define METHOD_SETUP_MESSAGE(msg_name,msg_id)                                       \
static int  (msg_id) = 0;                                                           \
if ( (msg_id) == 0 )                                                                \
{                                                                                   \
    int  setup_err = METHOD_get_message_id( (msg_name), &(msg_id) );                \
    if ( setup_err != ITK_ok )                                                      \
    {                                                                               \
        TC_write_syslog ("No method defined for message name '%s'\n", msg_name);  \
        EMH_store_error( EMH_severity_error, setup_err );                           \
        return setup_err;                                                           \
    }                                                                               \
}

/** @} */

/**
    @name METHOD Registration Functions
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
This ITK can only be used to add pre/post on meta operation not for legacy operations
The existing APIs have to be used to add pre/post for legacy operations and should not be used to add meta operations.
Valid value for prePostFlag are follows:
1 for pre-condition
2 for pre-action
3 for post_action
*/

extern TCCORE_API int  METHOD_attach_action(
    const char* typeName,   /**< (I) Name of the Teamcenter type */
    const char* methodName, /**< (I) Name of the meta operation */
    int prePostFlag,        /**< (I) Type of the meta operation */
    METHOD_function_t fn,   /**< (I) condition handler function */
    TC_argument_list_t* userData    /**< (I) List of static arguments that pass values to every
                                                invocation of the condition handler function in this session */
    );

/**
    Registers a method base action. The given function becomes the base action
    used to implement the specified type/message combination.

    @note This function cannot be used to replace the registered base action of a default Teamcenter type.
    This function can only be used to register base actions for new types.
*/
extern TCCORE_API int  METHOD_register_method(
    const char*           type_name,    /**< (I) Name of the Teamcenter type that is registering this method */
    const char*           msg_name,     /**< (I) Identifies the message being registered */
    METHOD_function_t     base_action,  /**< (I) Base action function invoked by this method */
    TC_argument_list_t* user_args,    /**< (I) List of static arguments that pass values to every
                                                invocation of the base action in this session */
    METHOD_id_t*          method_id     /**< (O) Identifies the newly registered method
                                                (e.g., add pre- or post-actions, add a pre-condition) */
    );

/**
    Registers the given function as a pre-condition handler for this method.
    This function should check entry conditions for the method,
    returning #ITK_ok if it is OK to proceed and execute the actions.
*/
extern TCCORE_API int  METHOD_add_pre_condition(
    METHOD_id_t           method_id,                /**< (I) Identifies the method that a pre-condition will be added to */
    METHOD_function_t     pre_condition_handler,    /**< (I) Pre-condition handler function */
    TC_argument_list_t* user_args                 /**< (I) List of static arguments whose values are passed to
                                                            every invocation of this pre-condition in this session */
    );

/**
    Adds a pre- or post- action to an existing method.
    These will be executed before and after the base action, respectively.
*/
extern TCCORE_API int  METHOD_add_action(
    METHOD_id_t           method_id,        /**< (I) Identifies the method that the action will be added to */
    METHOD_action_type_t  action_type,      /**< (I) #METHOD_pre_action_type or #METHOD_post_action_type */
    METHOD_function_t     action_handler,   /**< (I) Pre- or post- action function */
    TC_argument_list_t* user_args         /**< (I) List of static arguments whose values are passed to
                                                    every invocation of this action in this session */
    );

/**
    Adds a pre- or post- action to an existing method.
    These will be executed before and after the base action, respectively.

    Additional logical input argument: auto_dispatched is used to specify if the post-action function attached
    to the create message of Item, ItemRevision, ImanRelation and Dataset is not auto-dispatched
    as post-action on save operation.
*/
extern TCCORE_API int  METHOD_add_action2(
    METHOD_id_t           method_id,        /**< (I) Identifies the method that the action will be added to */
    METHOD_action_type_t  action_type,      /**< (I) #METHOD_pre_action_type or #METHOD_post_action_type */
    METHOD_function_t     action_handler,   /**< (I) Pre- or post- action function */
    TC_argument_list_t*   user_args,        /**< (I) List of static arguments whose values are passed to
                                                    every invocation of this action in this session */
    logical               auto_dispatched   /**< (I) true if method is to be autodispatced to save operation */
    );

/**
    Adds user arguments to the extension attach specified by the method id, the action type and the extension name. 
    These user arguments will be passed to the function of the extension through the message data.

    @note This function supports only the extensions defined in BMIDE since such extensions can be identified by name. 
    If user parameters are defined in BMIDE for the extension, use #BMF_get_user_params to retrieve the parameter values.

    <br>This function returns:
    <ul>
    <li>#ITK_ok on success
    <li>#BMF_internal_error if the value of the parameters "action_type" or "extension_name" is invalid or if any 
    of the arguments in "user_args" are of an invalid type. 
    </ul>
*/
extern TCCORE_API int METHOD_add_user_arguments(
    METHOD_id_t          method_id,       /**< (I) The method to which the named extension is attached */
    ExtensionPointType_t action_type,     /**< (I) Extension point type, e.g. #ExtensionPointType_PreCondition,
                                                                              #ExtensionPointType_PreAction or  
                                                                              #ExtensionPointType_Post */
    const char*          extension_name,  /**< (I) Name of the extension to which the user arguments are added */
    int                  num_user_args,   /**< (I) Number of user arguments */
    const TC_argument_t* user_args        /**< (I) Array of #TC_argument_t  structures */
    );

/**
    Looks for the registered method used to implement the specified type/message combination.
    This is useful for registering pre- or post-actions or a pre-condition for a method created elsewhere in the system.

    @note #METHOD_find_method will return #ITK_ok even if there are no registered methods for the type/message combination.
    You should perform the check mentioned in the code fragment below,
    to ascertain if the method is registered for the type/message combination or not.

    If method_id.id == 0 , it implies, that we do not have
    methods implemented on type_name for msg_name

    @code
        if (method_id.id == 0)
        {
            ...this means that the method is not registered for the specified type/message
        }
    @endcode
*/
extern TCCORE_API int METHOD_find_method(
    const char*         type_name,  /**< (I) Name of the Teamcenter type that is registering this method */
    const char*         msg_name,   /**< (I) Identifies the message for which the method is registered */
    METHOD_id_t*        method_id   /**< (O) Returns an identifier for the method found */
    );


/**
    Finds the identifer of the message that is programmatically registered at the specified type.
    @note #METHOD_find_method should be used to find the identifier of the message or operation that is defined in BMIDE.
*/
extern  TCCORE_API  int  METHOD_find_dynamic_method(
    const char*     type_name,      /**< (I) Name of the Teamcenter type that is dynamically registering this method */
    const char*     msg_name,       /**< (I) Identifies the message for which the method is dynamically registered */
    METHOD_id_t*    method_id       /**< (O) Returns an identifier for the method found */
    );

/** @} */

/**
    Sends a message to an object or property.
    The specified method will be executed depending on the message and the type of the object or property.

    @note This function can operate on an object or a property depending on the method executed.
    Property methods only operate on properties; other methods operate on objects.

    @note If this message does not apply to a specific instance (e.g., create, find) use #METHOD_execute_using.
*/
extern TCCORE_API int METHOD_execute(
    tag_t               object,     /**< (I) Tag of the object or property to which you want to pass the message */
    int                 msg_id,     /**< (I) Run-time identifier for the message you want passed to the object or property */
    ...                             /**< Variable argument list as defined for the message in the \<module\>_msg.h header file */
    );

/**
    Dispatches a message qualified by an explicit type.
    The specified method will be executed depending on the message and the type.

    @note This function can operate on an object or a property depending on the method executed.
    Property methods only operate on properties; other methods operate on objects.
*/
extern TCCORE_API int METHOD_execute_using(
    tag_t               object,     /**< (I) Tag of the object or property to which you want to pass the message.
                                        If this message is not applicable to a specific instance
                                        (e.g., create, find) pass #NULLTAG. */
    tag_t               tc_type,    /**< (I) Type to execute the message for */
    int                 msg_id,     /**< (I) */
    ...                             /**< Variable argument list as defined for the message in the \<module\>_msg.h header file */
    );

/**
    Checks the entry conditions for a method without executing the method.

    @note This function can operate on an object or a property depending on the method executed.
    Property methods only operate on properties; other methods operate on objects.
*/
extern TCCORE_API int METHOD_check_pre_conditions(
    tag_t               object, /**< (I) Tag of the object or property that will be passed the message */
    int                 msg_id, /**< (I) Run-time identifier for the message passed to the object or property */
    ...                         /**< Variable argument list as defined for the message in the <module>_msg.h header file */
    );

/**
    Checks the entry conditions for a method without executing the method.
    
    @note This function is a variation of METHOD_check_pre_conditions but without calling function invoker.  
    Function invoker shall only be used to call legacy extension with new metaframework opertion.
    
    @note This function can operate on an object or a property depending on the method executed.
    Property methods only operate on properties; other methods operate on objects.
*/
extern TCCORE_API int METHOD_check_pre_conditions_message(
    tag_t               object, /**< (I) Tag of the object or property that will be passed the message */
    int                 msg_id, /**< (I) Run-time identifier for the message passed to the object or property */
    ...                         /**< Variable argument list as defined for the message in the <module>_msg.h header file */
    );

/**
    Enables calling pre action method without calling the base method itself.
*/
extern TCCORE_API int  METHOD_call_pre_action(
    tag_t               object, /**< (I) Tag of the object or property that will be passed the message */
    int                 msg_id, /**< (I) Run-time identifier for the message passed to the object or property */
    ...                         /**< Variable argument list as defined for the message in the <module>_msg.h header file */
    );

/**
    Enables calling pre action method without calling the base method itself.

    @note This function is a variation of METHOD_call_pre_action but without calling function invoker.  
    Function invoker shall only be used to call legacy extension with new metaframework opertion.
    
    @note This function can operate on an object or a property depending on the method executed.
    Property methods only operate on properties; other methods operate on objects.
*/
extern TCCORE_API int  METHOD_call_pre_action_message(
    tag_t               object, /**< (I) Tag of the object or property that will be passed the message */
    int                 msg_id, /**< (I) Run-time identifier for the message passed to the object or property */
    ...                         /**< Variable argument list as defined for the message in the <module>_msg.h header file */
    );

/**
    Suppport for Property-specific methods.
    Registers a property method base action. The given function becomes the base action
    used to implement the specified type/property/message combination.
    @note In version Tc8 and later, Property Operation should be configured in BMIDE.
    Please refer to the section: Add a Property Operation in Business Modeler IDE Guide for details.
*/
extern TCCORE_API int  METHOD_register_prop_method(
    const char*           type_name,        /**< (I) Name of the Teamcenter type for which
                                                this method is being registered */
    const char*           property_name,    /**< (I) Identifies the message being registered */
    const char*           msg_name,         /**< (I) Name of the property for which this method is being registered */
    METHOD_function_t     base_action,      /**< (I) Base action function invoked by this method */
    TC_argument_list_t* user_args,        /**< (I) List of static arguments that pass values to every
                                                invocation of the base action in this session */
    METHOD_id_t*          method_id         /**< (O) Identifies the newly registered method
                                                (e.g., add pre- or post-actions, add a pre-condition) */
    );

/**
    Looks for the registered property method used to implement the specified type/property message combination.
    This is useful for registering pre- or post-actions or a pre-condition for a method created elsewhere in the system.
*/
extern TCCORE_API int METHOD_find_prop_method(
    const char*         type_name,      /**< (I) Name of the Teamcenter type that is registering this method */
    const char*         property_name,  /**< (I) Name of the property for which this method is being registered */
    const char*         msg_name,       /**< (I) Identifies the message for which the method is registered */
    METHOD_id_t*        method_id       /**< (O) Returns an identifier for the method found */
    );

/**
    A property message (e.g., ask, set) is passed to an object in order to execute the
    method registered for the relevant combination of message, property and object type.
    Messages are uniquely defined by a text string,
    but for efficiency at run-time we use an integer message identifier.
    This function returns the integer ID associated with the given message name.

    The macro #METHOD_SETUP_PROP_MESSAGE will declare a static int in function,
    cache the msg_id and look it up on the first pass, and return an integer failure code if the lookup failed.
    This will save time by eliminating the need to look up the msg_id each time a message is dispatched.
*/
extern TCCORE_API int METHOD_get_prop_message_id(
    const char*         msg_name,       /**< (I) Text identifier for the message,
                                                as defined in a \<module\>_msg.h include file */
    const char*         property_name,  /**< (I) Name of the property associated with the message ID */
    int*                msg_id          /**< (O) Run-time identifier for the message */
    );

/**
    This function is here so that we can use it in the macros.
    Users should use the macro instead of using it directly.
*/
extern TCCORE_API int METHOD_merge_prop_message_id(
    int                 merge_msg_id,   /**< (I) */
    const char*         property_name,  /**< (I) */
    int*                msg_id          /**< (O) */
    );

extern TCCORE_API int METHOD__is_prop_registered(
    tag_t               objTag,
    const char*         methodName,
    const char*         propName,
    logical*            registered
    );

/**
    Enables calling post action method without calling the base method itself.
*/
extern TCCORE_API int  METHOD_call_post_action
    ( tag_t                   object,                   /**< (I) */
      int                     msg_id,                   /**< (I) */
      ...
    );

/**
    Enables calling post action method without calling the base method itself.

    @note This function is a variation of METHOD_call_post_action but without calling function invoker.  
    Function invoker shall only be used to call legacy extension with new metaframework opertion.
    
    @note This function can operate on an object or a property depending on the method executed.
    Property methods only operate on properties; other methods operate on objects.
*/
extern TCCORE_API int  METHOD_call_post_action_message
    ( tag_t                   object,                   /**< (I) */
      int                     msg_id,                   /**< (I) */
     ...
    );

extern TCCORE_API int METHOD__register_operationFn(
    const char*           type_name,    /**< (I) Name of the Teamcenter type that is registering this method */
    const char*           msg_name,     /**< (I) Identifies the message being registered */
    METHOD_function_t     base_action,  /**< (I) Base action function invoked by this method */
    TC_argument_list_t*   user_args,    /**< (I) List of static arguments that pass values to every
                                                invocation of the base action in this session */
    METHOD_id_t*          method_id     /**< (O) Identifies the newly registered method
                                                (e.g., add pre- or post-actions, add a pre-condition) */
                  );

extern TCCORE_API int  METHOD__register_prop_operationFn(
    const char*           type_name,        /**< (I) Name of the Teamcenter type for which
                                                this method is being registered */
    const char*           property_name,    /**< (I) Identifies the message being registered */
    const char*           msg_name,         /**< (I) Name of the property for which this method is being registered */
    METHOD_function_t     base_action,      /**< (I) Base action function invoked by this method */
    TC_argument_list_t*   user_args,        /**< (I) List of static arguments that pass values to every
                                                invocation of the base action in this session */
    METHOD_id_t*          method_id         /**< (O) Identifies the newly registered method
                                                (e.g., add pre- or post-actions, add a pre-condition) */
    );

/**
    Retrieves the property descriptor embedded in the #METHOD_message_t message.
    
    @note This function is a variation of #METHOD_PROP_MESSAGE_OBJECT or #METHOD_PROP_MESSAGE_PROP_NAME
    which retrieves other information embedded in the #METHOD_message_t message.

    @returns
    <ul>
    <li>#ITK_ok on success. 
        <br/>If no property descriptor can be found, the returned parameter @p property_descriptor is #NULLTAG.</li>
    <li>#METHOD_invalid_type if an invalid value is provided for the @p message parameter.</li>
    </ul>
*/
extern TCCORE_API int METHOD_get_message_property_descriptor(
    const METHOD_message_t*     message,                    /**< (I) The message whose contextual information contains the property */
    tag_t*                      property_descriptor         /**< (O) The tag of the property descriptor */
    );

#ifdef __cplusplus
}
#endif

/**
    This macro can be used to setup a static message id in your routines to save repeated lookups.
*/
#define METHOD_SETUP_PROP_MESSAGE(msg_name,property_name,msg_id)                            \
static int  (msg_id) = 0;                                                                   \
if ( (msg_id) == 0 )                                                                        \
{                                                                                           \
    int setup_err = METHOD_get_prop_message_id( (msg_name), (property_name), &(msg_id) );   \
    if ( setup_err != ITK_ok ) return setup_err;                                            \
    else if ((msg_id) == 0)                                                                 \
{ TC_write_syslog ("File %s; Line # %d; no message '%s' registered for property '%s'",    \
                     __FILE__, __LINE__, (msg_name), (property_name));                      \
        return ITK_general_user_error;                                                      \
      }                                                                                     \
}                                                                                           \
else                                                                                        \
{                                                                                           \
    int setup_err = METHOD_merge_prop_message_id( (msg_id), (property_name), &(msg_id) );   \
    if ( setup_err != ITK_ok ) return setup_err;                                            \
}

#define METHOD_PROP_MESSAGE_OBJECT(msg, objectTag) (objectTag) = (msg)->object_tag;

#define METHOD_PROP_MESSAGE_PROP_NAME(msg, propName) (propName) = (msg)->prop_name;

/** @} */

#include <tccore/libtccore_undef.h>
#endif
