/* @<COPYRIGHT_START>@
 ===============================================
 Copyright 2006 UGS Corp. All Rights Reserved.
 ===============================================
 @<COPYRIGHT_END>@ */


/** 
    @file 

    This file defines constants and external ITK API for the RBF module.

*/


#ifndef RBF_H
#define RBF_H

#include <pom/pom/pom.h>
#include <rbf/librbf_exports.h>

/**
    @defgroup RBF Rules Based Framework (RBF)
    @{
*/
    
/**
    @name Maximum RBF sizes
    @{
*/
#define RBF_BUSINESS_ELEMENT_NAME_size_c    128
#define RBF_CATEGORY_size_c                 240
#define RBF_COLUMN_NAME_size_c              128
#define RBF_ID_size_c                       240
#define RBF_OPERAND_size_c                  240
#define RBF_PROPERTY_NAME_size_c            128
#define RBF_TYPE_NAME_size_c                128
/** @} */

#define RBF_DATE_FORMAT                     "%Y%m%d"
#define RBF_DATE_NULL                       "00000000"
#define RBF_FALSE_STRING                    "false"
#define RBF_TRUE_STRING                     "true"

/**
    @name RBF Preferences
    @{
*/
#define RBF_ENABLE_DEBUG_PREF               "RBF_ENABLE_DEBUG"
/** @} */

/**
    @name RBF Enumerations
    @{
*/
typedef enum AEPRuleType_e
{
    DecisionTableType
} AEPRuleType_t;

typedef enum RBFDataType_e
{
    StringType,
    DateType,
    DoubleType,
    FloatType,
    IntegerType,
    LogicalType,
    BusinessObjectType
} RBFDataType_t;

typedef enum RBFInput_e
{
    InPrimitive,
    InBusinessObject
} RBFInput_t;

typedef enum RBFOutput_e
{
    OutPrimitive
} RBFOutput_t;

typedef enum RBFColumn_e
{
    Input,
    Output
} RBFColumn_t;

typedef enum RBFExpressionType_e
{
    EqualTo,
    NotEqualTo,
    GreaterThan,
    GreaterThanOrEqualTo,
    LessThan,
    LessThanOrEqualTo,
    Between
} RBFExpressionType_t;
/** @} */

/**
    @name rbf_value dataTypes
    @{
*/
#define RBF_VALUE_DATATYPE_STRING         "STRING"
#define RBF_VALUE_DATATYPE_BOOLEAN        "BOOLEAN"
#define RBF_VALUE_DATATYPE_INTEGER        "INTEGER"
#define RBF_VALUE_DATATYPE_DOUBLE         "DOUBLE"
#define RBF_VALUE_DATATYPE_FLOAT          "FLOAT"
#define RBF_VALUE_DATATYPE_DATE           "DATE"
#define RBF_VALUE_DATATYPE_TAG            "TAG"
/** @} */

struct RBF_value
{
    char     *dataType;
    char     *stringValue;
    logical  booleanValue;
    int      integerValue;
    double   doubleValue;
    float    floatValue;
    date_t   dateValue;
    tag_t    tagValue;

    RBF_value()
    {
        dataType = 0;
        stringValue = 0;
        booleanValue = false;
        integerValue = 0;
        doubleValue = 0;
        floatValue = 0;
        dateValue = NULLDATE;
        tagValue = NULLTAG;
    }
};

struct RBF_name_value
{
    char       *name;
    RBF_value  value;
};

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Builds the array of name/value pair structures.
    - If the values parameter is NULL, then count and values will be initialized with a new parameter.
    - If the values parameter is not NULL (already populated), then the count will be incremented
      and values will be reallocated and a new parameter added.
*/
extern RBF_API int     RBF_build_name_value_pairs(
                           const char      *nvp_name,                           /**< (I)   */
                           const char      *nvp_data_type,                      /**< (I)   */
                           const char      *nvp_value,                          /**< (I)   */
                           int             *count,                              /**< (I/O) */
                           RBF_name_value  **values                             /**< (I/O) RBF_free_name_value */
                           );

/**
    Free the name/value pair array of structures (allocated by RBF_build_name_value_pairs).
*/
extern RBF_API void    RBF_free_name_value(
                           int             count,                               /**< (I)   */
                           RBF_name_value  **values                             /**< (I/O) */
                           );

/**
    Execute the rules engine.
*/
extern RBF_API int     RBF_execute(
                           const char      *id,                                 /**< (I)  */
                           int             in_count,                            /**< (I)  */
                           RBF_name_value  *in_values,                          /**< (I)  */
                           int             *result_count,                       /**< (O)  */
                           RBF_name_value  **result_values                      /**< (OF) RBF_free_name_value */
                           );

/** @} */

#ifdef __cplusplus
}
#endif

#include <rbf/librbf_undef.h>
#endif /* RBF_H */
