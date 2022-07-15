/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef BMF_H
#define BMF_H

#include <tc/tc_startup.h>
#include <tc/emh.h>
#include <tccore/method.h>
#include <itk/libitk_exports.h>


/**
    @defgroup BMF Business Modeler Framework (BMF)
    @{
*/

/**
    @name Maximum BMF sizes
    @{
*/
/**

BMF_MESSAGE_NAME_size_c has been increased to 1024 due to meta operationID requirement.
BMF_VALIDITY_size_c has been increased to 1280 due to same

*/
#define BMF_NAME_size_c                     32 
#define BMF_TYPE_size_c                     32
#define BMF_PROP_NAME_size_c               132
#define BMF_LIB_NAME_size_c                 64
#define BMF_MESSAGE_NAME_size_c           1024
#define BMF_CONDITION_size_c               132
#define BMF_EXTENSION_NAME_size_c          132
#define BMF_VALIDITY_size_c               1280
#define BMF_EXTENSION_ARGNAME_size_c        64 
#define BMF_EXTENSION_STRGVAL_size_c        64 
/** @} */

/**
    @name BMF Class Names
    @{
*/
#define BMOperationClassName               "BMOperation"
#define ExtensionClassName                 "Extension"
#define ExtensionDescriptorClassName       "ExtensionDescriptor"
#define ExtensionPointClassName            "ExtensionPoint"
#define PropertyBMOperationClassName       "PropertyBMOperation"
#define TypeBMOperationClassName           "TypeBMOperation"

#define EXTENSION_POINT_PRECONDITION_STR   "pre-condition"
#define EXTENSION_POINT_PREACTION_STR      "pre-action"
#define EXTENSION_POINT_BASEACTION_STR     "base"
#define EXTENSION_POINT_POSTACTION_STR     "post-action"
/** @} */

/**
    @name BMF Preferences
    @{
*/
#define BMF_BYPASS_ALL_EXTENSION_RULES_PREF     "BMF_BYPASS_ALL_EXTENSION_RULES"
#define BMF_CLASS_AND_TYPE_DISPLAY_LIST_PREF    "BMF_CLASS_AND_TYPE_DISPLAY_LIST"
#define BMF_CUSTOM_IMPLEMENTOR_PATH_PREF        "BMF_CUSTOM_IMPLEMENTOR_PATH"
#define BMF_ENABLE_DEBUG_PREF                   "BMF_ENABLE_DEBUG"
#define BMF_SUPPRESS_ACTION_RULES_DISPLAY_PREF  "BMF_SUPPRESS_ACTION_RULES_DISPLAY"
#define BMF_USE_BMF_PREF                        "BMF_USE_BMF"
#define BMF_LOAD_IND_OBJECT_PREF                "BMF_LOAD_IND_OBJECT"                     
/** @} */

#define BMF_IMPLEMENTER_CLASS_DELIMETER  "::"


/** Enumeration for Extension Language Type */
typedef enum ExtensionLangType_e
{
    extensionLangType_unknown,
    extensionLangType_c,
    extensionLangType_c_plusplus,
    extensionLangType_java,
    extensionLangType_script,
    extensionLangType_dotnet
}ExtensionLangType_t;


typedef struct ExtensionDescDetail_s
{
    tag_t extntag;
    int   n_params;
    char** params;
    char* condition;
    int priority;
    tag_t desctag;
}ExtensionDescDetail_t;

/** Enumeration for BMF User Exit Processes */
typedef enum BMF_user_exit_process_e
{
    BMF_UE_CONTINUE,
    BMF_USER_EXIT_RETURN,
    BMF_USER_EXIT_ERROR
}BMF_user_exit_process_t;

/** Stucture for storing the extionsion user arguments **/
typedef struct BMF_extension_arguments_s
{
    char paramName[BMF_EXTENSION_ARGNAME_size_c + 1];
    union val_union
    {
         int int_value;
         double double_value;
         char str_value[BMF_EXTENSION_STRGVAL_size_c + 1];
    }arg_val;

}BMF_extension_arguments_t;

#define BMF_EXECUTE_USER_EXIT_EXTENSIONS(args) \
{\
    int bmf_stat = BMF_UE_CONTINUE; \
    bmf_stat = BMF_process_userexit args;\
    if (bmf_stat == BMF_USER_EXIT_RETURN ) \
       return ITK_ok; \
    else if (bmf_stat == BMF_USER_EXIT_ERROR ) { EMH_ask_last_error(&bmf_stat); return bmf_stat;}\
}

typedef int (*CPLUSPLUS_EXTENSION)(const char*, METHOD_message_t*, va_list);

#ifdef __cplusplus
extern "C"{
#endif
    
/**
   This is an unpublished ITK function and should not be used directly.
   This function can change without notice.
*/
extern ITK_API int BMF_process_userexit(
        char* typeName,                            /**< (I) */
        char* propName,                            /**< (I) */
        char* msgName,                             /**< (I) */
        ...                                        /**< (I) */
    );

/**
 Extracts the user arguments from the message.
*/
extern ITK_API int BMF_get_user_params( 
    METHOD_message_t  *msg ,                   /**< (I) The message method */ 
    int* ext_param_cnt,                        /**< (O) The number of parameters */
    BMF_extension_arguments_t** ext_params     /**< (OF) ext_param_cnt The user arguments */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <itk/libitk_undef.h>
#endif
