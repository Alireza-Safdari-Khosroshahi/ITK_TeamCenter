/* @<COPYRIGHT_START>@
 ==================================================
 Copyright 2007.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 @<COPYRIGHT_END>@ */


/**
    @file

    This file defines constants and external ITK API for the CE module.

*/


#ifndef CE_H
#define CE_H

#include <pom/pom/pom.h>
#include <ce/libce_exports.h>

/**
    @defgroup CE Condition Engine (CE)
    @{
*/

/**
    @name Condition class name and property name constants
    @{
*/
#define CONDITION_class_name_c             "Condition"
#define CONDITION_condition_name_c         "condition_name"
#define CONDITION_condition_desc_c         "condition_desc"
#define CONDITION_expression_c             "expression"
#define CONDITION_secure_flag_c            "secure_flag"
#define CONDITION_parameters_c             "parameters"
/** @} */

/**
    @name ConditionParameter class name and property name constants
    @{
*/
#define CONDITIONPARAMETER_class_name_c      "ConditionParameter"
#define CONDITIONPARAMETER_parameter_name_c  "parameter_name"
#define CONDITIONPARAMETER_parameter_type_c  "parameter_type"
/** @} */

/**
    @name Condition name constants
    @{
*/
#define CE_DEFAULT_TRUE_CONDITION            "isTrue"
#define CE_DEFAULT_FALSE_CONDITION           "isFalse"
/** @} */

/**
    @name Maximum CE sizes
    @{
*/
#define CE_CONDITION_DESC_size_c           240
#define CE_CONDITION_NAME_size_c           128
#define CE_PARAMETER_DESC_size_c           240
#define CE_PARAMETER_NAME_size_c           128
#define CE_PARAMETER_TYPE_size_c           128
/** @} */

/**
    @name CE Preferences
    @{
*/
#define CE_ENABLE_DEBUG_PREF             "CE_ENABLE_DEBUG"
/** @} */

/**
    @name CE Enumerations
    @{
*/
/** @} */

/**
    @name CE Global Operation IDs
    @{
*/
#define CE_GLOBAL_OPID_INLIST            "INLIST"
#define CE_GLOBAL_OPID_MATCH             "MATCH"
/** @} */

/**
    @name ce_value dataTypes
    @{
*/
#define CE_VALUE_DATATYPE_STRING         "STRING"
#define CE_VALUE_DATATYPE_PRIMDT_STRING  "std::string"
#define CE_VALUE_DATATYPE_CHAR           "CHAR"
#define CE_VALUE_DATATYPE_PRIMDT_CHAR    "char"
#define CE_VALUE_DATATYPE_BOOLEAN        "BOOLEAN"
#define CE_VALUE_DATATYPE_PRIMDT_BOOL    "bool"
#define CE_VALUE_DATATYPE_INTEGER        "INTEGER"
#define CE_VALUE_DATATYPE_PRIMDT_INT     "int"
#define CE_VALUE_DATATYPE_PRIMDT_LONG    "long"
#define CE_VALUE_DATATYPE_DOUBLE         "DOUBLE"
#define CE_VALUE_DATATYPE_PRIMDT_DOUBLE  "double"
#define CE_VALUE_DATATYPE_FLOAT          "FLOAT"
#define CE_VALUE_DATATYPE_PRIMDT_FLOAT   "float"
#define CE_VALUE_DATATYPE_DATE           "DATE"
#define CE_VALUE_DATATYPE_PRIMDT_DATE    "date_t"
#define CE_VALUE_DATATYPE_TAG            "TAG"
#define CE_VALUE_DATATYPE_PRIMDT_TAG     "tag_t"
#define CE_VALUE_DATATYPE_UNSUPPORTED    "UNSUPPORTED"
#define CE_VALUE_DATATYPE_INVALID        "INVALID"
/** @} */

struct CE_value
{
    char     *dataType;      /**< Must initialize to 0 */
    char     *stringValue;   /**< Must initialize to 0 */
    char     charValue;      /**< Must initialize to '\\0' */
    logical  booleanValue;   /**< Must initialize to false */
    int      integerValue;   /**< Must initialize to 0 */
    long     longValue;      /**< Must initialize to 0 */
    double   doubleValue;    /**< Must initialize to 0 */
    float    floatValue;     /**< Must initialize to 0 */
    date_t   dateValue;      /**< Must initialize to NULLDATE */
    tag_t    tagValue;       /**< Must initialize to NULLTAG */

};

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Returns the condition name attribute value.
*/
extern CE_API int CE_ask_condition(
                      const tag_t  condition_tag,    /**< (I) tag of existing condition */
                      char         **condition_name  /**< (OF) condition name attribute value */
                      );

/**
    Returns the condition tag for the specified condition name attribute value.
*/
extern CE_API int CE_find_condition(
                      const char   *condition_name,  /**< (I) condition name attribute value */
                      tag_t        *condition_tag    /**< (O) tag for specified condition */
                      );

/**
   Retrieves the current user session object tag.

   @returns #ITK_ok always
*/
extern CE_API int CE_current_user_session_tag(
                      tag_t        *usersession_object_tag    /**< (O) tag for specified user session */
                      );

/**
    Execute the rules engine to evaluate the specified condition using the specified condition tag and condition parameters.

    <b>Note: </b>

    Always pass in NULLTAG for the UserSession object parameter. The Condition Engine code will automatically retrieve the UserSession object.

    The value of the tag of all objects represented in the condition signature (with the exception of UserSession for which you will pass in NULLTAG)
    must be provided in the order they are defined in the condition signature. For example, given a condition signature like
    Example Condition(Item o, ItemRevision ir, UserSession u), provide the actual tag of an Item object in the first parameter, the actual tag of
    an ItemRevision object in the second parameter, and NULLTAG for the third parameter. The "parm_count" would be 3, and the parameters would be
    loaded into the array of tags in that order.

    The CE_evaluate_condition API does not invoke the rules engine if the condition name is "isTrue" or "isFalse", so there is no need for callers
    to retrieve the condition name using the condition tag to check if the condition name is "isTrue" or "isFalse".

*/
extern CE_API int CE_evaluate_condition(
                      const tag_t  condition_tag,  /**< (I) Tag of existing condition */
                      const int    parm_count,     /**< (I) Input parameter count */
                      const tag_t  *parm_tags,     /**< (I) Array of input parameter tags */
                      logical      *result         /**< (O) Result of the condition evaluation ( true or false ) */
                      );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ce/libce_undef.h>
#endif /* CE_H */
