/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef TYPE_CANNEDMETHOD_H
#define TYPE_CANNEDMETHOD_H

#include <tc/tc_startup.h>
#include <tccore/workspaceobject.h>
#include <tccore/method.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TYPE_CANNED_METHOD Canned Methods
    @ingroup METHOD
    @{
*/

/** Pre-Condition Method */
#define METHOD_CM_Pre_Condition_type        0

/** Pre-Action Method */
#define METHOD_CM_Pre_Action_type           1   

/** Base-Action Method */
#define METHOD_CM_Base_Action_type          2   

/** Post-Action Method */
#define METHOD_CM_Post_Action_type          3   

/** Maximum Message Name */
#define METHOD_CM_MAX_MSG_NAME_LEN          32

/** Maximum Canned Method Name */
#define METHOD_CM_MAX_METHOD_NAME_LEN       32 

/** Used to tokenize method userData */
#define METHOD_CM_PARAM_DELIM               "::"       

/** Used to tokenize query name and attr name */
#define METHOD_CM_QUERY_ATTR_DELIM          "~"   

/** Number of class attributes. */
#define METHOD_CM_NUM_OF_ATTRS              9    

/**
    Minimum number of class attributes required for creating instance of TypeCannedMethod
*/
#define METHOD_CM_MIN_NUM_OF_ATTRS          6    

#define METHOD_CM_TYPE_NAME_ATTR            "type_name"
#define METHOD_CM_MSG_NAME_ATTR             "msg_name"
#define METHOD_CM_ACTION_TYPE_ATTR          "action_type"
#define METHOD_CM_METHOD_NAME_ATTR          "method_name"
#define METHOD_CM_EXEC_SEQ_ATTR             "exec_seq"
#define METHOD_CM_METHOD_OPTIONS_ATTR       "method_options"
#define METHOD_CM_OPTION_PARAMETERS         "parameters"
#define METHOD_CM_OPTION_PARAMETERS_PARAM   "parameter"

/**
    Structure to handle func_name to ptr mapping. 
*/
typedef struct METHOD_CM_func_name_and_ptr_s
{
    char                func_name[METHOD_CM_MAX_METHOD_NAME_LEN +1];
    METHOD_function_t   func_ptr;
} METHOD_CM_func_name_and_ptr_t, *METHOD_CM_func_name_and_ptr_p_t;


/**
    Structure to hold information related to available canned method. 
*/
TCCORE_API typedef struct METHOD_CM_Func_Detail_s
{
    char        classOrObjectType [WSO_name_size_c +1];
    char        msgName [METHOD_CM_MAX_MSG_NAME_LEN +1];
    int         actionType;
    char        funcName [METHOD_CM_MAX_METHOD_NAME_LEN];
    const char* userDataTemplate;
    const char* isMandatoryTemplate;
    const char* userSavedQueryDetail;
} METHOD_CM_Func_Detail_t, *METHOD_CM_Func_Detail_p_t;

#ifdef __cplusplus
    extern "C"{
#endif

extern TCCORE_API int METHOD_CM_init_module();

/**
    Retrieves all configured canned methods in the database.
*/
extern TCCORE_API int METHOD_CM_extent(
    int*                count,              /**< (O) Number of configured canned methods */
    tag_t**             canned_method_tags  /**< (OF) count List of tags of configured canned methods.
                                                The calling function needs to #MEM_free this argument. */
    );

/**
    Adds func_name to function pointer mapping information for the session.
    <br/>The func_name used in #METHOD_CM_add_method2 calls must have a 
    mapping function pointer to use for internal method registration. 
    This mapping information is added by using this ITK. 

    <b>Restrictions:</b>

    This ITK must be called only from the USER EXIT #USER_add_canned_methods. 

    func_name must be unique through out the system.
    It is advised that sites prefix their methods with a unique key representing the Site.

    <b>Return Values:</b>

    #METHOD_CM_internal_error - TypeCannedMethod Internal Error
*/
extern TCCORE_API int METHOD_CM_register_function(
    const char*         func_name,  /**< (I) Name of the canned method that will appear in the 
                                        Business Rules Application Action Rules Tree Node. 
                                        @note This argument must be unique for a given canned method. */
    METHOD_function_t   func_ptr    /**< (I) Function Pointer for the canned method */
    );

/**
    Adds canned methods. 
    <br/>If a site wants to add custom methods as canned methods so as to make these canned methods available for
    configuration from the Business Rules Application, then this ITK can be used.

    <b>Restrictions:</b>
    <OL>
    <LI>This ITK must be called only from the USER EXIT #USER_add_canned_methods. 
    <LI>func_name must be unique through out the system.
        It is advised that sites prefix their methods with a unique key representing the Site.
    </OL>

    <b>Return Values:</b>

    #METHOD_CM_internal_error - TypeCannedMethod Internal Error
*/
extern TCCORE_API int METHOD_CM_add_method2(
    const char          *type_name,                                     /**< (I) Name of class or Types for which the canned method can be configured */
    const char          *msg_name,                                      /**< (I) Operation Name for which the canned method can be registered against */
    int                 action_type,                                    /**< (I) When to register method. 0 for pre-condition 1 for 
                                                                            pre-action, 2 ?for base-action.
                                                                            In the V8 release, there will be no support for configuring
                                                                            canned methods for base action, 3 for post-action */
    const char          *func_name,                                     /**< (I) Name of the canned method that will appear in the
                                                                            Business Rules Application Action Rules Tree Node.
                                                                            Note: This argument must be unique for a given canned method. */
    const char*         user_data_template,                             /**< (I) Options required during canned method configuration and 
                                                                            also during registration. This must be a single string,
                                                                            with each parameter separated in the string by a separator "::".
                                                                            The delimiter is fixed to be "::". */
    const char*         is_mandatory_template,                          /**< (I) Details regarding whether a canned method option is mandatory
                                                                            or optional. 1 for Mandatory and 0 for optional. 
                                                                            This must be a single string, with each parameter separated
                                                                            in the string by a separator "::". */
    const char*         user_dataQuery_detail                           /**< (I) This can be NULL only if the userDataTemplate is NULL,
                                                                            or else this should have a one-to-one mapping for the 
                                                                            parameters in the userDataTemplate.
                                                                            The SavedQuery detail should be mentioned for parameters that
                                                                            need to have a List Box of values displayed in the
                                                                            Portal Client Application. A blank space (i.e., "  ") can be
                                                                            mentioned for parameters that do not need any list box values
                                                                            for display in Portal Client. Along with the SavedQuery name,
                                                                            the attribute whose value needs to be displayed should be
                                                                            mentioned as param1QueryName~attribute_name, where "~" is the
                                                                            delimiter between saved query name and attribute name.
                                                                            attribute_name is the attribute of the query results whose value
                                                                            needs to be displayed in the list box. 
                                                                            <p>
                                                                            The separator between query Name and Attribute Name must be
                                                                            "~" (i.e., tilda).  */
    );

/**
   Retrieves details related to a configured canned method from the database.
*/
extern TCCORE_API int METHOD_CM_describe(
    tag_t               cmTag,                                          /**< (I) Tag of canned method for which details are required */
    char                type_name[WSO_name_size_c + 1],                 /**< (O) Name of Type against which the canned method is configured */
    char                msg_name[METHOD_CM_MAX_MSG_NAME_LEN + 1],       /**< (O) Name of Operation for which the canned method is configured */
    int*                action_type,                                    /**< (O) Action Type for which the canned method is configured<br>
                                                                            0 ?Pre-Condition<br>
                                                                            1 ?Pre-Action<br>
                                                                            2 ?Base-Action. For V8 configuration of canned methods for
                                                                            base action will not be supported.<br>
                                                                            3 ?Post-Action */
    char                method_name[METHOD_CM_MAX_METHOD_NAME_LEN + 1], /**< (O) Name of the configured canned method */
    int*                exec_seq,                                       /**< (O) Order of execution of this canned method, 
                                                                            when there are more than one canned method for the same type,
                                                                            same message and same action type. */
    int*                option_value_cnt,                               /**< (O) Number of parameters values as mentioned during
                                                                            configuration of canned methods */
    int*                option_cnt,                                     /**< (O) Number of options required for canned method as mentioned
                                                                            while adding canned method 
                                                                            (i.e., argument method_options as mentioned in #METHOD_CM_add_method2) */
    char****            option_values                                   /**< (OF) option_value_cnt Array of array of Strings representing the
                                                                            canned method parameters as mentioned during configuration of canned method. 

                                                                            The internal array of strings will have option_cnt elements,
                                                                            whereas the external array will have option_value_cnt elements
                                                                            (which are array of strings)char* [num_of_option_values]
                                                                            [num_of_options];

                                                                            The calling function needs to free the memory allocated for
                                                                            this argument. An example of how to #MEM_free the 
                                                                            allocated memory is shown below

                                                                            To free the memory allocated, each of the elements in
                                                                            option_values needs to be looped option_value_cnt times and
                                                                            each array needs to be freed.

    @code
        int inx = 0;

        for ( inx = 0; inx < num_of_option_values; inx++)
        {    
            MEM_free( option_values[inx]);
        }
    @endcode */
    );

/**
    Logs the details of the input canned method to the syslog file. 
    <br/>This ITK could be used in the implementation of custom (i.e., site) canned methods,
    so as to report details of canned method when an error is encountered
*/
extern TCCORE_API int METHOD_CM_log_details(
    tag_t               cmTag
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
