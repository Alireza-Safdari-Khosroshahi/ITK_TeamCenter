/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    C callable functions for ICT User services
*/

/*  */

#ifndef ICT_USERSERVICE_H
#define ICT_USERSERVICE_H

#include <unidefs.h>

#include <ict/libict_exports.h>

/**
    This macro is used to ensure that symbols are
    properly exported on the windows platform.
*/
#ifdef WNT
    #ifdef USER_EXIT_IMPORT
        #define DLLAPI __declspec(dllimport)
    #else
        #define DLLAPI __declspec(dllexport)
    #endif
#else
    #define DLLAPI
#endif

/**
    @defgroup ICT_USERSERVICE ICT UserService

    You will use the UserService mechanism to specify the functions
    that you want to register in Teamcenter Engineering.
    These functions are called dynamically by the Teamcenter Engineering Client.
    @{
*/

#define USERARG_ARRAY_TYPE     100
#define USERARG_VOID_TYPE      0
#define USERARG_CHAR_TYPE      1
#define USERARG_DATE_TYPE      2
#define USERARG_DOUBLE_TYPE    3
#define USERARG_FLOAT_TYPE     4
#define USERARG_INT_TYPE       5
#define USERARG_LOGICAL_TYPE   6
#define USERARG_SHORT_TYPE     7
#define USERARG_STRING_TYPE    8
#define USERARG_TAG_TYPE       9

typedef int (*USER_function_t)(void*);

typedef struct USERSERVICE_array_s {
    int        length;
    void*      array;
} USERSERVICE_array_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
    Registers user-specified function.
*/
extern DLLAPI int USERSERVICE_register_method(
    char*           functionName,       /**< (I) Name of the user specified function */
    USER_function_t functionPtr,        /**< (I) Pointer to the user specified function */
    int             numberOfArguments,  /**< (I) Number of arguments for the user-specified function */
    int*            argumentList,       /**< (I) List of input argument types for the user-specified function */
    int             returnValueType     /**< (I) Type of the value that is returned by the user-specified function */
    );

/**
    Returns array of integer values in a structure.
*/
extern DLLAPI int USERSERVICE_return_int_array(
    const int*           array,         /**< (I) Array of integer values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of short values in a structure.
*/
extern DLLAPI int USERSERVICE_return_short_array(
    const short*         array,         /**< (I) Array of short values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of double values in a structure.
*/
extern DLLAPI int USERSERVICE_return_double_array(
    const double*        array,         /**< (I) Array of double values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of float values in a structure.
*/
extern DLLAPI int USERSERVICE_return_float_array(
    const float*         array,         /**< (I) Array of float values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of logical values in a structure.
*/
extern DLLAPI int USERSERVICE_return_logical_array(
    const logical*       array,         /**< (I) Array of logical values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of string values in a structure.
*/
extern DLLAPI int USERSERVICE_return_string_array(
    const char**         array,         /**< (I) Array of string values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of tag values in a structure.
*/
extern DLLAPI int USERSERVICE_return_tag_array(
    const tag_t*         array,         /**< (I) Array of tag values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of character values in a structure.
*/
extern DLLAPI int USERSERVICE_return_char_array(
    const char*          array,         /**< (I) Array of character values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Returns array of date values in a structure.
*/
extern DLLAPI int USERSERVICE_return_date_array(
    const date_t*        array,         /**< (I) Array of date values */
    int                  arrayLength,   /**< (I) Length of the array */
    USERSERVICE_array_t* arrayStruct    /**< (O) The structure into which the array values will be copied */
    );

/**
    Gets the integer argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_int_argument(
    int*          arg   /**< (O) Integer argument from the user argument stack */
    );

/**
    Gets the integer array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_int_array_argument(
    int*          length,   /**< (O) Size of the array */
    int**         args      /**< (OF) length Integer array argument from the user argument stack */
    );

extern DLLAPI int USERARG_get_double_argument(
    double*       arg   /**< (O) */
    );

extern DLLAPI int USERARG_get_double_array_argument(
    int*          length,   /**< (O) */
    double**      args      /**< (OF) length */
    );

/**
    Gets the string argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_string_argument(
    char**        arg   /**< (OF) Integer argument from the user argument stack */
    );

/**
    Gets the string array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_string_array_argument(
    int*          length,   /**< (O) Size of the array */
    char***       args      /**< (OF) length String array argument from the user argument stack */
    );

/**
    Gets the tag argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_tag_argument(
    tag_t*        arg   /**< (O) Tag argument from the user argument stack */
    );

/**
    Gets the tag array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_tag_array_argument(
    int*          length,   /**< (O) Size of the array */
    tag_t**       args      /**< (OF) length Tag argument from the user argument stack */
    );

/**
    Gets the logical argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_logical_argument(
    logical*      arg   /**< (O) Logical argument from the user argument stack */
    );

/**
    Gets the string argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_logical_array_argument(
    int*          length,   /**< (O) */
    logical**     args      /**< (OF) length Logical array argument from the user argument stack */
    );

/**
    Gets the float argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_float_argument(
    float*        arg   /**< (O) Float argument from the user argument stack */
    );

/**
    Gets the float array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_float_array_argument(
    int*          length,   /**< (O) Size of the array */
    float**       arg       /**< (OF) length Float array argument from the user argument stack */
    );

/**
    Gets the short argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_short_argument(
    short*        arg   /**< (O) Short argument from the user argument stack */
    );

/**
    Gets the short array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_short_array_argument(
    int*          length,   /**< (O) Size of the array */
    short**       arg       /**< (OF) length Short array argument from the user argument stack */
    );

/**
    Gets the character argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_char_argument(
    char*         arg   /**< (O) Character argument from the user argument stack */
    );

/**
    Gets the character array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_char_array_argument(
    int*          length,   /**< (O) Size of the array */
    char**        arg       /**< (OF) length Integer argument from the user argument stack */
    );

/**
    Gets the date argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_date_argument(
    date_t*       arg   /**< (O) Date argument from the user argument stack */
    );

/**
    Gets the date array argument from the user argument stack.
*/
extern DLLAPI int USERARG_get_date_array_argument(
    int*          length,   /**< (O) */
    date_t**      arg       /**< (OF) length Date array argument from the user argument stack */
    );

extern DLLAPI void USERARG_reset_arguments();

#ifdef __cplusplus
}
#endif

/** @} */

#include <ict/libict_undef.h>
#endif
