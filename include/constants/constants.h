/* @<COPYRIGHT_START>@
 ===============================================
 Copyright 2007 UGS Corp. All Rights Reserved.
 ===============================================
 @<COPYRIGHT_END>@ */


/**
    @file

    This file defines constants and external ITK API for the CONSTANTS module.

*/


#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <tc/tc_startup.h>
#include <constants/libconstants_exports.h>

/**
    @defgroup CONSTANTS Constants
    @{
*/


/**
    @name CONSTANTS Enumerations
    @{
*/


typedef enum CONSTANTSDataType_e
{
    StringDataType=0,
    ListDataType=1,
    BooleanDataType=2
} CONSTANTSDataType_t;

/** @} */

#define PROPERTY_CONST_REQUIRED         "Required"
#define PROPERTY_CONST_VISIBLE          "Visible"
#define PROPERTY_CONST_ENABLED          "Enabled"
#define PROPERTY_CONST_INITIALVALUE     "InitialValue"
#define PROPERTY_CONST_COMPLEXPROPERTY  "ComplexProperty"
#define PROPERTY_CONST_MODIFIABLE       "Modifiable"
#define PROPERTY_CONST_COPYFROMORIGINAL "CopyFromOriginal"
#define PROPERTY_CONST_TRIM_ZEROS       "Fnd0TrimZeroes"
#define PROPERTY_CONST_IS_FORMATTABLE   "Fnd0IsFormattable"

/** Property constant to determine if time editing is presented in UI for date property */
#define PROPERTY_CONST_IS_TIME_ENABLED  "Fnd0EnableTimeForDateProperty"

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Check if the Global constant is single or multi valued.
*/
extern CONSTANTS_API int CONSTANTS_is_global_constant_multivalued(
           const char*              constant_name,     /**< (I) The constant name for which the information is desired. */
           logical*                 is_multi_valued    /**< (O)  The value returned here will be "true" if the constant is multivalued, and "false" otherwise. */
       );

/**
    Get the Global constant value.
*/
extern CONSTANTS_API int CONSTANTS_get_global_constant_value(
           const char*              constant_name,     /**< (I) The constant name for which the information is desired. */
           char **                  value              /**< (OF) The current value of the Global Constant. */
       );

/**
    Get the Global constant values.
*/
extern CONSTANTS_API int CONSTANTS_get_global_constant_values(
           const char*              constant_name,     /**< (I) The constant name for which the information is desired. */
           int*                     n_values,          /**< (O) The number of values being returned. */
           char***                  values             /**< (OF) A pointer to the list of values. */
       );

/**
    Get the constant Value for the type object.
*/
extern CONSTANTS_API int CONSTANTS_get_type_constant_value(
       const char*                   constant_name,      /**< (I) The constant name for which the information is desired. */
       const char*                   type_name,          /**< (I) The business object name for which the constant information is desired. */
       char**                        value               /**< (OF) The current value of the constant. */
       );


/**
    Get the constant Value for a specific property for the type object.
*/
extern CONSTANTS_API int CONSTANTS_get_property_constant_value(
       const char*                   constant_name,      /**< (I) The constant name for which the information is desired. */
       const char*                   type_name,          /**< (I) The business object name for which the constant information is desired. */
       const char*                   property_name,      /**< (I) The property on the business object for which the constant information is desired. */
       char**                        value               /**< (OF) The current value of the constant. */
       );

/**
    Finds the type by type constant value for the type object.

    @returns #ITK_ok always
*/
extern CONSTANTS_API int CONSTANTS_find_type_by_type_constant_value(
       const char*                   type_constant_name,      /**< (I) The type constant name for which the information is desired. */
       const char*                   attached_value,          /**< (I) The attached value for which the constant information is desired. */
       char**                        target_type_name         /**< (OF) The target type name of the constant. */
       );

#ifdef __cplusplus
}
#endif

/** @} */

#include <constants/libconstants_undef.h>
#endif /* CONSTANTS_H */
