/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Messages are general actions e.g. save, delete.
    When a Message is sent to a specific Type or instance of a Type,
    then the Method registered with that Message/Type combination will be executed.
    See ITK documentation on Methods for further details.

    Each message has a unique set of parameters, which are defined here.
    These parameters are passed in the varargs list of #METHOD_execute / #METHOD_execute_using,
    and received in the varargs list of action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h.
*/

/*  */

#ifndef LOV_MSG_H
#define LOV_MSG_H

#include <lov/liblov_exports.h>


/**
    @defgroup LOV_MSG Messages
    @ingroup LOV
    @{
*/


/**
    Asks the list of values of an LOV.
    Is called by the LOV_ask_values_\<type\> and 
    anywhere Teamcenter wants to know the list of values of a specified LOV.
    A default method for this message is registered for all LOVs automatically.
    Returning the value is done by using #MEM_alloc to allocate
    space for * values and setting that space to the desired value.

    For example,
    LOV with integer values
    @param tag_t      lov         Unique identifier (tag) of the LOV instance.
    @param int*       n_values    The number of returned values.
    @param int**      values      Values in the LOV.

    LOV with double values
    @param tag_t      lov         Unique identifier (tag) of the LOV instance.
    @param int*       n_values    The number of returned values.
    @param double**   values      Values in the LOV.

    LOV with char values
    @param tag_t      lov         Unique identifier (tag) of the LOV instance.
    @param int*       n_values    The number of returned values.
    @param char**     values      Values in the LOV.

    LOV with string values
    @param tag_t      lov         Unique identifier (tag) of the LOV instance.
    @param int*       n_values    The number of returned values.
    @param char***    values      Values in the LOV.

    LOV with date values
    @param tag_t      lov         Unique identifier (tag) of the LOV instance.
    @param int*       n_values    The number of returned values.
    @param date_t**   values      Values in the LOV.

    LOV with tag values
    @param tag_t      lov         Unique identifier (tag) of the LOV instance.
    @param int*       n_values    The number of returned values.
    @param tag_t**    values      Values in the LOV.
*/
#define LOV_ask_values_msg              "LOV_ask_values"


/**
    Verifies that an LOV value is valid.
    It is called by the LOV_is_value_valid_\<type\> and
    anywhere Teamcenter wants to verify the value with a specified LOV.
    A default method for this message is registered for all LOVs automatically.

    For example,
    LOV with integer values
    @param tag_t            lov         Unique identifier (tag) of the LOV instance.
    @param int              value       The value to be verified.
    @param logical*         answer      Returns TRUE if valid and FALSE if not valid.

    LOV with double values
    @param tag_t            lov         Unique identifier (tag) of the LOV instance.
    @param double           value       The value to be verified.
    @param logical*         answer      Returns TRUE if valid and FALSE if not valid.

    LOV with char values
    @param tag_t            lov         Unique identifier (tag) of the LOV instance.
    @param char             value       The value to be verified.
    @param logical*         answer      Returns TRUE if valid and FALSE if not valid.

    LOV with string values
    @param tag_t            lov         Unique identifier (tag) of the LOV instance.
    @param const char*      value       The value to be verified.
    @param logical*         answer      Returns TRUE if valid and FALSE if not valid.

    LOV with date values
    @param tag_t            lov         Unique identifier (tag) of the LOV instance.
    @param date_t           value       The value to be verified.
    @param logical*         answer      Returns TRUE if valid and FALSE if not valid.

    LOV with tag values
    @param tag_t            lov         Unique identifier (tag) of the LOV instance.
    @param tag_t            value       The value to be verified.
    @param logical*         answer      Returns TRUE if valid and FALSE if not valid.
*/
#define LOV_is_valid_msg                "LOV_is_valid"


/**
    Gets the number of values in an LOV.
    This message is called by #LOV_ask_num_of_values.
    @param tag_t    lov         Unique identifier (tag) of the LOV instance
    @param int*     length      The number of values
*/
#define LOV_ask_num_of_values_msg       "LOV_ask_num_of_values"



/**
    Converts an LOV to a list of strings. 
    This message is called by LOV_ask_disp_values_\<type\> and
    anywhere Teamcenter wants to know the list of string values of a specified LOV.
    This message should use #MEM_alloc to allocate space for setting ** disp_values.

    For example,
    LOV with integer values
    @param tag_t            lov             Unique identifier (tag) of the LOV instance.
    @param LOV_usage_t      lov_usage       Usage of the LOV.
    @param int              n_values        Number of values to be converted.
    @param const int*       values          Values in the LOV.
    @param const logical*   is_null         Indicates which value(s) are null.
    @param const logical*   is_empty        Indicates which value(s) are empty.
    @param char***          disp_values     The converted string values.

    LOV with double values
    @param tag_t            lov             Unique identifier (tag) of the LOV instance.
    @param LOV_usage_t      lov_usage       Usage of the LOV.
    @param int              n_values        Number of values to be converted.
    @param const double*    values          Values in the LOV.
    @param const logical*   is_null         Indicates which value(s) are null.
    @param const logical*   is_empty        Indicates which value(s) are empty.
    @param char***          disp_values     The converted string values.

    LOV with char values
    @param tag_t            lov             Unique identifier (tag) of the LOV instance.
    @param LOV_usage_t      lov_usage       Usage of the LOV.
    @param int              n_values        Number of values to be converted.
    @param const char*      values          Values in the LOV.
    @param const logical*   is_null         Indicates which value(s) are null.
    @param const logical*   is_empty        Indicates which value(s) are empty.
    @param char***          disp_values     The converted string values.

    LOV with string values
    @param tag_t            lov             Unique identifier (tag) of the LOV instance.
    @param LOV_usage_t      lov_usage       Usage of the LOV.
    @param int              n_values        Number of values to be converted.
    @param const char**     values          Values in the LOV.
    @param const logical*   is_null         Indicates which value(s) are null.
    @param const logical*   is_empty        Indicates which value(s) are empty.
    @param char***          disp_values     The converted string values.

    LOV with date values
    @param tag_t            lov             Unique identifier (tag) of the LOV instance.
    @param LOV_usage_t      lov_usage       Usage of the LOV.
    @param int              n_values        Number of values to be converted.
    @param const date_t*    values          Values in the LOV.
    @param const logical*   is_null         Indicates which value(s) are null.
    @param const logical*   is_empty        Indicates which value(s) are empty.
    @param char***          disp_values     The converted string values.

    LOV with tag values
    @param tag_t            lov             Unique identifier (tag) of the LOV instance.
    @param LOV_usage_t      lov_usage       Usage of the LOV.
    @param int              n_values        Number of values to be converted.
    @param const tag_t*     values          Values in the LOV.
    @param const logical*   is_null         Indicates which value(s) are null.
    @param const logical*   is_empty        Indicates which value(s) are empty.
    @param char***          disp_values     The converted string values.
*/
#define LOV_ask_disp_values_msg         "LOV_ask_disp_values"


/**
    Asks the list of value descriptions of an LOV.
    A default method for this message is registered for all LOVs automatically.
    This message is called by #LOV_ask_value_descriptions.
    @param tag_t            lov_tag         Unique identifier (tag) of the LOV instance.
    @param int*             n_values        Number of values returned.
    @param char***          desc_strings    The converted string values.
    @param logical**        is_null         Indicates which value(s) are null.
    @param logical**        is_empty        Indicates which value(s) are empty.
*/
#define LOV_ask_value_desc_msg              "LOV_ask_value_descriptions"


/** @} */

#include <lov/liblov_undef.h>
#endif
