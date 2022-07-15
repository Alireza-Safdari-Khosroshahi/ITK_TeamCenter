/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the ANSI C interface to Teamcenter Engineering property
    messages and access functions.

    Property Messages are conceptual actions to be done on a property.
    When a Message is sent to a specific Property, the Method registered with
    that Message/Type/Property combination will be executed. See ITK
    documentation on Property Methods for further details.

    Each message has a unique set of parameters, which are defined here. These
    parameters are passed in the varargs list
    #METHOD_execute / #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.
*/

/*  */

#ifndef AOM_PROP_H_INCLUDED
#define AOM_PROP_H_INCLUDED

#include <unidefs.h>
#include <property/propdesc.h>
#include <property/prop_msg.h>
#include <common/tc_deprecation_macros.h>

#include <tccore/libtccore_exports.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
    @defgroup AOM_PROP Property
    @ingroup AOM

    Property METHOD utility Prototypes
    These are meant to be used from Property METHODS, only!!

    These are to assign the value into the property after
    validation and/or alteration has occured

    @{
*/

/**
    Asks display name of a property.
*/
extern TCCORE_API int AOM_ask_prop_names(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    int*                prop_count,     /**< (O) The number of properties associated with the object instance. */
    char***             prop_names      /**< (OF) prop_count The array of property names.
                                                  Iterate through the output array and call MEM_free on each element to de-allocate 
                                                  the nested memory block and then free the memory pointed by itself using MEM_free. */
    );

/**
     ITK returns the displayable prop names sorted by property display name 
*/
extern TCCORE_API int AOM_ask_sorted_prop_names(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    int*                prop_count,     /**< (O) The number of properties associated with the object instance. */
    char***             prop_names      /**< (OF) prop_count The array of property names.
                                                  Iterate through the output array and call MEM_free on each element to de-allocate 
                                                  the nested memory block and then free the memory pointed by itself using MEM_free. */
    );
/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_string_msg. To customize the behavior of this function,
    register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_string(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    const char*         value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_strings_msg if the property is multi-valued or 
    #PROP_set_value_string_msg if this property is single-valued.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_strings(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values to be set. */
    char**              values          /**< (I) num Actual values being set on the property.
                                                This must be a list or array of constant characters. 
                                                If the property is an array, the number of values passed in must 
                                                equal the size of the array. */
    );

/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_string_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_string_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_string_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    const char*          value          /**< (I) Actual value being set on the property. */
    );

/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_date_msg. 
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_date(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    date_t              value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_dates_msg if the property is multi-valued or 
    #PROP_set_value_date_msg if this property is single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_dates(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values to be set. */
    const date_t*       values          /**< (I) Actual values being set on the property. 
                                            This must be a list or array of constant characters.
                                            If the property is an array, the number of values passed in must
                                            equal the size of the array. */
    );

/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_date_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_date_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_date_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    date_t              value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_double_msg. 
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_double(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    double              value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_doubles_msg if the property is multi-valued or 
    #PROP_set_value_double_msg if this property is single-valued.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_doubles(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values to be set. */
    const double*       values          /**< (I) Actual values being set on the property.
                                                This must be a list or array of constant characters. 
                                                If the property is an array, the number of values passed in must
                                                equal the size of the array. */
    );


/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_double_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_double_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_double_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    double              value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_int_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_int(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_ints_msg if the property is multi-valued or 
    #PROP_set_value_int_msg if this property is single-valued.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_ints(
    tag_t               object,        /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,     /**< (I) A property name of the object instance. */
    int                 num,           /**< (I) Number of values to be set. */
    const int*          values         /**< (I) Actual values being set on the property.
                                            This must be a list or array of constant characters.
                                            If the property is an array, the number of values passed in must
                                            equal the size of the array. */
    );

/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_int_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_int_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_int_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    int                 value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_logical_msg. 
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_logical(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    logical             value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_logicals_msg if the property is multi-valued or 
    #PROP_set_value_logical_msg if this property is single-valued.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_logicals(
    tag_t               object,            /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,         /**< (I) A property name of the object instance. */
    int                 num,               /**< (I) Number of values to be set. */
    const logical*      values             /**< (I) Actual values being set on the property.
                                                    This must be a list or array of constant characters.
                                                    If the property is an array, the number of values passed in must
                                                    equal the size of the array. */
    );

/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_logical_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_logical_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_logical_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    logical             value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_tag_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_tag(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    tag_t               value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_tags_msg if the property is multi-valued or 
    #PROP_set_value_tag_msg if this property is single-valued.
    To customize the behavior of this function, register a method against one of these messages.
    <br/>In case of BackwardReference properties, existing property values that are not available in the 
    input values will be deleted. 
*/
extern TCCORE_API int AOM_set_value_tags(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values to be set. */
    const tag_t*        values          /**< (I) Actual values being set on the property.
                                                This must be a list or array of constant characters.
                                                If the property is an array, the number of values passed in must
                                                equal the size of the array. */
    );

/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_tag_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_tag_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
    <br/>In case of BackwardReference properties, existing value at the specified index will be deleted. 
*/
extern TCCORE_API int AOM_set_value_tag_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    tag_t               value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets value on a single-valued property.

    This function uses #PROP_set_value_char_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_set_value_char(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    char                value           /**< (I) Actual value being set on the property. */
    );

/**
    Sets one or more values on a property.

    This function uses #PROP_set_value_chars_msg if the property is multi-valued or 
    #PROP_set_value_char_msg if this property is single-valued.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_chars(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values to be set. */
    const char*         values          /**< (I) Actual values being set on the property.
                                                This must be a list or array of constant characters.
                                                If the property is an array, the number of values passed in must
                                                equal the size of the array. */
    );

/**
    Sets value on a multi-valued (i.e., list or array) property at a specified index position.
    
    This function uses #PROP_set_value_char_at_msg. 
    If the property is single-valued and the index position = 0, #PROP_set_value_char_msg will be called instead.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_set_value_char_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an array of
                                                size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    char                value           /**< (I) Actual value being set on the property. */
    );

/**
    Asks value of a single-valued property.

    This function uses #PROP_ask_value_string_msg. 
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_string(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    char**              value           /**< (OF) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).

    This function uses #PROP_ask_value_strings_msg if multi-valued and #PROP_ask_value_string_msg if single-valued.
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_strings(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    char***             values          /**< (OF)num Actual values of the property. This must be a list or array 
                                                of constant chars. If the property is an array, the number of 
                                                values passed in must equal the size of the array.
                                                Iterate through the output array and call MEM_free on each element to de-allocate 
                                                the nested memory block and then free the memory pointed by itself using MEM_free. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position. 
    The property can be single-valued if position = 0.

    This function uses #PROP_ask_value_string_at_msg if the property is multi-valued or 
    #PROP_ask_value_string_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_string_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    char**              value           /**< (OF) Actual value of the property at the specified index position. */
    );

/**
    Asks value of a single-valued property.
    
    This function uses #PROP_ask_value_date_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_date(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    date_t*             value           /**< (O) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).
    
    This function uses #PROP_ask_value_dates_msg if multi-valued and #PROP_ask_value_date_msg if single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_dates(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    date_t**            values          /**< (OF) num Actual values of the property. This must be a list or array of
                                                constant chars. If the property is an array, the number of values
                                                passed in must equal the size of the array. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    
    This function uses #PROP_ask_value_date_at_msg if the property is multi-valued or 
    #PROP_ask_value_date_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_date_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    date_t*             value           /**< (O) Actual value of the property at the specified index position. */
    );

/**
    Asks value of a single-valued property.
    
    This function uses #PROP_ask_value_double_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_double(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    double*             value           /**< (O) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).
    
    This function uses #PROP_ask_value_doubles_msg if multi-valued and #PROP_ask_value_double_msg if single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_doubles(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    double**            values          /**< (OF) num Actual values of the property. This must be a list or array of
                                                constant chars. If the property is an array, the number of values
                                                passed in must equal the size of the array. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    
    This function uses #PROP_ask_value_double_at_msg if the property is multi-valued or 
    #PROP_ask_value_double_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_double_at(
    tag_t               object,            /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,         /**< (I) A property name of the object instance. */
    int                 position,          /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    double*             value              /**< (O) Actual value of the property at the specified index position. */
    );

/**
    Asks value of a single-valued property.
    
    This function uses #PROP_ask_value_int_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_int(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                value           /**< (O) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).
    
    This function uses #PROP_ask_value_ints_msg if multi-valued and #PROP_ask_value_int_msg if single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_ints(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    int**               values          /**< (OF) num Actual values of the property. This must be a list or array of
                                                constant chars. If the property is an array, the number of values
                                                passed in must equal the size of the array. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    
    This function uses #PROP_ask_value_int_at_msg if the property is multi-valued or 
    #PROP_ask_value_int_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_int_at(
    tag_t               object,            /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,         /**< (I) A property name of the object instance. */
    int                 position,          /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    int*                value              /**< (O) Actual value of the property at the specified index position. */
    );

/**
    Asks value of a single-valued property.
    
    This function uses #PROP_ask_value_logical_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_logical(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    logical*            value           /**< (O) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).
    
    This function uses #PROP_ask_value_logicals_msg if multi-valued and #PROP_ask_value_logical_msg if single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_logicals(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    logical**           values          /**< (OF) num Actual values of the property. This must be a list or array of
                                                constant chars. If the property is an array, the number of values
                                                passed in must equal the size of the array. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    
    This function uses #PROP_ask_value_logical_at_msg if the property is multi-valued or 
    #PROP_ask_value_logical_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_logical_at(
    tag_t               object,            /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,         /**< (I) A property name of the object instance. */
    int                 position,          /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    logical*            value              /**< (O) Actual value of the property at the specified index position. */
    );

/**
    Asks value of a single-valued property.
    
    This function uses #PROP_ask_value_tag_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_tag(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    tag_t*              value           /**< (O) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).
    
    This function uses #PROP_ask_value_tags_msg if multi-valued and #PROP_ask_value_tag_msg if single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_tags(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    tag_t**             values          /**< (OF) num Actual values of the property. This must be a list or array of
                                                constant chars. If the property is an array, the number of values
                                                passed in must equal the size of the array. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    
    This function uses #PROP_ask_value_tag_at_msg if the property is multi-valued or 
    #PROP_ask_value_tag_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_tag_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    tag_t*              value           /**< (O) Actual value of the property at the specified index position. */
    );

/**
    Asks value of a single-valued property.
    
    This function uses #PROP_ask_value_char_msg.
    To customize the behavior of this function, register a method against this message name.
*/
extern TCCORE_API int AOM_ask_value_char(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    char*               value           /**< (O) Actual value of the property. */
    );

/**
    Asks one or more values of a property. The property can be single-valued or multi-valued (i.e., array or list).
    
    This function uses #PROP_ask_value_chars_msg if multi-valued and #PROP_ask_value_char_msg if single-valued. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_chars(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of values asked. */
    char**              values          /**< (OF) num Actual values of the property. This must be a list or array of
                                                constant chars. If the property is an array, the number of values
                                                passed in must equal the size of the array. */
    );

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    
    This function uses #PROP_ask_value_char_at_msg if the property is multi-valued or 
    #PROP_ask_value_char_msg if the property is single-valued and position = 0. 
    To customize the behavior of this function, register a method against one of these messages.
*/
extern TCCORE_API int AOM_ask_value_char_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is 
                                                an array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    char*               value           /**< (O) Actual value of the property at the specified index position. */
    );

/**
    Asks number of elements a property holds (i.e., how large is the list or array).

    A single-valued property will always return 1. An array will return the size of the array.
    A list will return the current number of elements in the list, ranging from 0 to infinity.
*/
extern TCCORE_API int AOM_ask_num_elements(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num_elem        /**< (O) Number of elements the property holds. */
    );

/**
    Asks property if it is modifiable by the user who is accessing it.

    This function uses the message #PROP_is_modifiable_msg.
    To customize the behavior, register a method against this message name.
*/
extern TCCORE_API int AOM_is_modifiable(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    logical*            mod_flag        /**< (O) Indicates whether the property is modifiable 
                                                (i.e., TRUE = modifiable, FALSE = not modifiable) */
    );

/**
    Returns the property's LOV tag if there is a LOV attached to the property.
    A NULL value is returned otherwise. It will look all the way up the Type hierarchy for any LOV association.
*/
extern TCCORE_API int AOM_ask_lov(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    tag_t*              lov_tag         /**< (O) Tag of the LOV */
    );

/**
    Returns the property type of a property. 
    Go to the property descriptor (PROPDESC) module for a description of the possible property types.
*/
extern TCCORE_API int AOM_ask_property_type(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    PROP_type_t*        proptype,       /**< (O) The property type of the property. */
    char**              proptype_n      /**< (OF) The name of the property type. */
    );

/**
    Returns the value type of a property.
    Go to the property descriptor (PROPDESC) module for a description of the possible value types.
*/
extern TCCORE_API int AOM_ask_value_type(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    PROP_value_type_t*  valtype,        /**< (O) The value type of the property. */
    char**              valtype_n       /**< (OF) The name of the value type. */
    );

/**
    Asks maximum number of elements for a property.
*/
extern TCCORE_API int AOM_ask_max_num_elements(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                maxnumelem      /**< (O) The maximum number of elements for the property.
                                                Will be 1 for a single-valued property, -1 for a list property and
                                                a positive integer for an array property. */
    );

/**
    Asks maximum string length for a property. The property must be type #PROP_string.
*/
extern TCCORE_API int AOM_ask_max_string_length(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                maxstrlen       /**< (O) The maximum string length of the property value. */
    );


/**
    Asks display name of a property.
*/
extern TCCORE_API int AOM_UIF_ask_name(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    char**              disp_name       /**< (OF) The display name of the property. */
    );

/**
    @deprecated #AOM_UIF_ask_value deprecated in Teamcenter 11.1. Use #AOM_ask_displayable_values instead

    Asks the display value of a property. Regardless of what type of property is asked, 
    this value will be returned as an MEM_alloc()ed string.

    This function uses #PROP_UIF_ask_value_msg. To customize the behavior of this function,
    register a property method, pre-action or post-action against this message name.

    A default method is registered against #PROP_UIF_ask_value_msg. The default behavior is as follows:

    <ol>
    <li>#AOM_UIF_ask_value gets a value from AOM_ask_value_\<type\>s.
    <li>If the property is a single-value string or note, it does not change what #AOM_ask_value_strings returns.
    <li>If the property is a single-value number (int, float, etc.), the number is converted to a string and returned.
    <li>If the property is a single-value tag (i.e., typed reference, typed relation, etc.) 
        the object_string of the object being referenced by the tag is returned. 
        For most objects, the object_string is its name. 
        However, Item, ItemRevision and others have special object_strings. 
        object_string is a run-time property that is displayed in the Object column of Workspace.
    <li>If the property is a single-value date, the date is returned using 
        the format identified by "DefaultDateFormat" in timelocal_locale.xml.
    <li>If the property is a single-value logical, the values for true/false identified by 
        gk_logical_true_label and gk_logical_false_label in tc_text_locale.xml are used.
    <li>If the property is multi-valued, all of the values are returned in a single string with commas separating the values. 
        The formatting described above is used for each of the property types.
    </ol>
*/
TC_DEPRECATED( "11.1", "AOM_UIF_ask_value", "AOM_ask_displayable_values" )
extern TCCORE_API int AOM_UIF_ask_value(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    char**              d_value         /**< (OF) The display value of the property. */
    );

/**
    Sets one or more values of a property using a display value as input. 
    This function will work for any property type, accepts string values as input, 
    then calls the appropriate AOM_set_value_\<type\>s command.

    This function uses #PROP_UIF_set_value_msg. 
    To customize the behavior of this function, register a property method, pre-action, or post-action against this message name.

    A default method is registered against #PROP_UIF_set_value_msg. The default behavior is as follows:

    <OL>
    <LI>If the property is multi-valued, it will parse the string at the commas then convert the values to the appropriate type.
    <LI>If the property is a string or note, no conversion of the value is done.
    <LI>If the property is one of the number types (int, double, etc.), 
        the input value will be converted from string to the appropriate type.
    <LI>If the property is a tag, an attempt will be made to convert the string passed in into a valid tag.
    <LI>If the property is a date, the format described by DefaultDateFormat in timelocal_locale.xml 
        will be used to convert the date from a string to a date_t.
    <LI>If the property is a logical, the values for true/false identified by gk_logical_true_label and 
        gk_logical_false_label in tc_text_locale.xml will be used to convert the string to a logical.
    <LI>Upon successful conversion, as described above, AOM_set_value_\<type\>s will be called, passing in the converted value(s).
    </OL>
*/
extern TCCORE_API int AOM_UIF_set_value(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    const char*         value           /**< (I) The display value used to set the new value of the property. */
    );

/**
    Asks descriptor for a property.
*/
extern TCCORE_API int AOM_ask_descriptor(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    tag_t*              descriptor      /**< (O) The descriptor for the property. */
    );

extern TCCORE_API int AOM_UIF_validate_display_value(
    tag_t               object,         /**< (I) The tag of the object */
    const char*         prop_name,      /**< (I) A property name of the given object identified by object */
    const char*         val,            /**< (I) */
    logical*            flag            /**< (O) */
    );

/**
    Asks for the ImanRelations used by a Relation property.
    This is to enable the programmer to use the GRM ITK calls on those relations.

    This can only be used for properties of property type #PROP_relation.

    The reason there are multiple relation_tags for a single relation property is because a relation property
    represents a particular relation type on a particular type. 
    An object of a particular type may be related to several objects through a particular relation type, 
    each using a separate ImanRelation.

    For example, an ItemRevision might have two datasets related to it through a relationship or type specification.
    Each dataset is related to the ItemRevision using a separate ImanRelation instance.
*/
extern TCCORE_API int AOM_ask_relations(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int*                num,            /**< (O) Number of relation_tags returned. */
    tag_t**             relation_tags   /**< (OF) num The tags for the ImanRelations used by the property. */
    );

/**
    Converts the specified tag of an object from a tag_t to a string representation. The string is MEM_alloc()ed.

    Note: 
    The output of AOM_tag_to_string contains alphanumeric characters as well as the dollar sign (\$) and underscore (_).
    Therefore, if this string is to be parsed by a UNIX shell, you should enclose it in single quotes (') to ensure 
    that it will be interprepted properly.
*/
extern TCCORE_API int AOM_tag_to_string(
    tag_t               the_tag,    /**< (I) The tag of an object in Teamcenter Engineering. */
    char**              the_string  /**< (OF) A string representing the tag. */
    );

/**
    Converts the representation of the tag of an object from a string to a tag_t.
*/
extern TCCORE_API int AOM_string_to_tag(
    const char*         the_string,     /**< (I) The string representation of the tag of an object in Teamcenter Engineering. */
    tag_t*              the_tag         /**< (O) A tag_t representation of the tag. */
    );

/**
    Assigns value to a single-valued property. 
    The property cannot be an array or list.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_string(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    const char*         value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_string_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    const char*         value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued 
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_strings(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    char**              values          /**< (I) Actual values assigned to the property.
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Assigns value to a single-valued property. The property cannot be an array or list.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_date(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    date_t              value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_date_at(
    tag_t               object,            /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,         /**< (I) A property name of the object instance. */
    int                 position,          /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    date_t              value              /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_dates(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    const date_t*       values          /**< (I) Actual values assigned to the property. 
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Assigns value to a single-valued property. The property cannot be an array or list.

    This function is intended to be called from within an AOM_set_value method in order to 
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_double(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    double              value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_double_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    double              value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_doubles(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    const double*       values          /**< (I) Actual values assigned to the property. 
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Assigns value to a single-valued property. The property cannot be an array or list.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_int(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_int_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    int                 value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued 
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_ints(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    const int*          values          /**< (I) Actual values assigned to the property. 
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Assigns value to a single-valued property. The property cannot be an array or list.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_logical(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    logical             value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_logical_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    logical             value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued 
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_logicals(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    const logical*      values          /**< (I) Actual values assigned to the property.
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Assigns value to a single-valued property. The property cannot be an array or list. 

    This function is intended to be called from within an AOM_set_value method in order to 
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_tag(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    tag_t               value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_tag_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    tag_t               value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued 
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_tags(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    const tag_t*        values          /**< (I) Actual values assigned to the property.
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Assigns value to a single-valued property. The property cannot be an array or list. 

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_char(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    char                value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns value to a multi-valued (i.e., list or array) property at a specified index position. 
    The property can be single-valued if position = 0.

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_char_at(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 position,       /**< (I) The position of the specified property in an array or list.
                                                The first position is 0. For example, if the property is an
                                                array of size 3 and the third value in the array is to be modified,
                                                then position = 2. */
    char                value           /**< (I) Actual value assigned to the property. */
    );

/**
    Assigns one or more values to a property. The property can be single-valued or multi-valued 
    (i.e., array or list).

    This function is intended to be called from within an AOM_set_value method in order to
    store a value in a property after all customized validation and derivation has been completed.
*/
extern TCCORE_API int AOM_assign_chars(
    tag_t               object,         /**< (I) Unique identifier of the object instance. */
    const char*         prop_name,      /**< (I) A property name of the object instance. */
    int                 num,            /**< (I) Number of values assigned. */
    const char*         values          /**< (I) Actual values assigned to the property.
                                                This must be a list or array of characters. If the property is an array,
                                                the number of values passed must equal the size of the array. */
    );

/**
    Returns true if the property value is null or empty. 

    If check_zero_length is true, also return true if the length of the string value is 0.

*/
extern TCCORE_API int AOM_is_null_empty(
    tag_t                   object,             /**< (I) Unique identifier of the object instance. */
    const char *            prop_name,          /**< (I) A property name of the object instance. */
    logical                 check_zero_length,  /**< (I) Indicates if also to check out 0-length string */
    logical*                is_null_empty       /**< (O) Indicates whether the property value is null or empty */ 
    );


/**
    Sets localized value on a single-valued string property. 
*/
extern TCCORE_API int AOM_UIF_set_localized_value_string(
    tag_t           object,               /**< (I) Unique identifier of the object instance. */
    const char*     prop_name,            /**< (I) A property name of the object instance. */
    const char *    locale,               /**< (I) The locale for which the property value is being set */
    const char*     value,                /**< (I) locale specific value being set on the property. */
    char            localization_status,  /**< (I) localization status of the property value, as defined in the textserver.h*/
    logical         master                /**< (I) specifies if the locale specified as input is the master locale. */
    );

/**
    Sets localized value on a single-valued or multi-valued string property. 
*/
extern TCCORE_API int AOM_UIF_set_localized_value_strings(
    tag_t        object,            /**< (I) Unique identifier of the object instance. */
    const char*  prop_name,         /**< (I) A property name of the object instance. */
    const char * locale,            /**< (I) The locale of the property values */
    int          num,               /**< (I) Number of values to be set. */
    const char** values,            /**< (I) num of locale specific values being set on the property.
                                            This must be a list or array of constant characters.
                                            If the property is an array, the number of values passed in must
                                            equal the size of the array. */
    char*        localization_statuses, /**< (I) list of localization statuses each applicable to the corresponding property value in the array */
    logical      master                 /**< (I) specifies if the locale specified as input is the master locale. */
    );

/**
    Sets value on a multi-valued string property at a specified index position.
    This does not overwrite the VLA.
*/
extern TCCORE_API int AOM_UIF_set_localized_value_string_at(
    tag_t        object,             /**< (I) Unique identifier of the object instance. */
    const char*  prop_name,          /**< (I) A property name of the object instance. */
    const char*  locale,             /**< (I) The locale of the property value */
    int          position,           /**< (I) The position of the specified property in an array or list  */
    const char*  value,              /**< (I) locale specific value being set on the property. */
    char         localization_status,/**< (I) localization status of the property value  */
    logical      master              /**< (I) specifies if the locale specified as input is the master locale. */
    );

/**
    Asks value of a single-valued string property
*/
extern TCCORE_API int AOM_UIF_ask_localized_value_string(
    tag_t        object,             /**< (I) Unique identifier of the object instance. */
    const char*  prop_name,          /**< (I) A property name of the object instance. */
    const char*  locale,             /**< (I) The locale of the property value */
    char**       value,              /**< (OF) value of the property. */
    char*        localization_status,/**< (O) localization status of the property value. */
    logical*     master              /**< (O) specifies if the locale specified as input is the master locale. */
    );

/**
    Asks one or more values of a string property. The property can be single-valued or multi-valued (i.e., array or list).
*/
extern TCCORE_API int AOM_UIF_ask_localized_value_strings(
    tag_t       object,                 /**< (I) Unique identifier of the object instance. */
    const char* prop_name,              /**< (I) A property name of the object instance. */
    const char* locale,                 /**< (I) The locale of the property value */
    int*        num,                    /**< (O) Number of values returned. */
    char***     values,                 /**< (OF) num values of the property. This must be a list or array of constant chars.
                                                Iterate through the output array and call MEM_free on each element to de-allocate 
                                                the nested memory block and then free the memory pointed by itself using MEM_free. */
    char**      localization_statuses,  /**< (OF) list of localization statuses each applicable to the corresponding property value in the values array. */
    logical*    master                  /**< (O) specifies if the locale specified as input is the master locale for each property value in the values array. */
    );

/**
    Asks the localized value of a string property at a particular array/list index position 
*/
extern TCCORE_API int AOM_UIF_ask_localized_value_string_at(
    tag_t       object,             /**< (I) Unique identifier of the object instance. */
    const char* prop_name,          /**< (I) A property name of the object instance. */
    const char* locale,             /**< (I) The locale of the property value */
    int         position,           /**< (I) The position of the specified property in an array or list  */
    char**      value,              /**< (OF) value of the property at the specified index position. */
    char*       localization_status,/**< (O) localization status of the property value. */
    logical*    master              /**< (O) specifies if the locale specified as input is the master locale. */
    );

typedef struct LOC_values_s
{
    int num_prop_values;
    char ** prop_values;
    logical master;
    char* localization_status_values;
} PROP_values_t;

/**
    Gets localized property values in different locales for a set of properties on an object. Takes multiple object tags as input.
*/
extern TCCORE_API  int  AOM_UIF_ask_multiple_localized_value_strings(
    int               n_objects,    /**<(I) Number of objects */
    tag_t *           objects,      /**< (I) Unique identifier of the object instance. */
    int               n_props,      /**< (I) Number of properties. */
    const char**      prop_names,   /**< (I) Property names of the object type. */
    int               n_locales,    /**< (I) Number of locales */
    const char**      locales,      /**< (I) List of locales for which property values are to be set */
    PROP_values_t**** prop_values   /**< (OF) list of structures each with a locale specific property value.
                                              Note that the output argument is a 3 diemensional array of size, n_objects * n_props * n_locales.
                                              Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/**
    Sets localized property values in different locales for a set of properties on an object. Takes multiple objects as input.
*/
extern TCCORE_API  int  AOM_UIF_set_multiple_localized_value_strings(
    int              n_objects,   /**< (I) Number of objects. */
    tag_t *          objects,     /**< (I) Unique identifier (tag) of the object instance (same type). */
    int              n_props,     /**< (I) Number of properties. */
    const char **    prop_names,  /**< (I) Property names of the object type. */
    int              n_locales,   /**< (I) Number of locales */
    const char **    locales,     /**< (I) List of locales for which property values are set */
    PROP_values_t*** prop_values  /**< (I) list of structures each with a locale specific property value */
    );

/**
    Asks localized property values for all the supported languages on a given object.
*/
extern TCCORE_API  int  AOM_UIF_ask_translations(
    tag_t       object,                       /**< (I) Unique identifier of the object instance. */
    const char* prop_name,                    /**< (I) Property name of the object type. */
    const int   seq_num,                      /**< (I) Sequence number associated with Master Value, It correlates to the number of values for mulit-valued property */
    int  *      num_translations,             /**< (O) Number of translations for Master Value */
    char ***    translationLocales,           /**< (OF) num_translations Translation Locales - Need to pass the supported list of languages only.
                                                        Iterate through the output array and call MEM_free on each element to de-allocate 
                                                        the nested memory block and then free the memory pointed by itself using MEM_free. */
    char ***    translationValues,            /**< (OF) num_translations Translation Values
                                                        Iterate through the output array and call MEM_free on each element to de-allocate 
                                                        the nested memory block and then free the memory pointed by itself using MEM_free. */
    char ***    translationStatusNames,       /**< (OF) num_translations Translation Status Names, i.e. the full name of the status.
                                                        <br/>Valid statuses are - Master, Approved, Invalid, Pending, In-review, Ghost.
                                                        <br/>Iterate through the output array and call MEM_free on each element to de-allocate 
                                                        the nested memory block and then free the memory pointed by itself using MEM_free. */
    char ***    translationStatusDescriptions /**< (OF) num_translations Translation Status Descriptions, i.e. the description for each status.
                                                        Iterate through the output array and call MEM_free on each element to de-allocate 
                                                        the nested memory block and then free the memory pointed by itself using MEM_free. */
    );

/**
    Sets the translated values for a localizable property on a given object.
    <br/>If 2 calls are made for the same object/property/sequence with a different list of locales, the last call overwrites all that the first one would have set. 
    <br/>The caller must know if the property is single- or multi-valued. 

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_object if the @p object is invalid
    <li>#PROP_not_found if the @p prop_name is invalid
    <li>#PROP_translations_out_of_index if the @p sequence_number is negative
    <li>#PROP_not_marked_localizable if the property @p prop_name is not localizable
    <li>#TEXTSRV_ERR_unsupported_status if any of the values for @p translation_status_codes and for a valid locale is invalid. 
    </ul>
*/
extern TCCORE_API  int  AOM_UIF_set_translations(
    tag_t        object,                      /**< (I) Unique identifier of the object instance. */     
    const char * prop_name,                   /**< (I) Property name of the object type. */
    const int    sequence_number,             /**< (I) Sequence number associated with the Master value.
                                              <br/>@note No error is returned if the sequence number exceeds the number of values.
                                              <br/>So the caller must know if the property is single-valued or multi-valued.
                                              */
    int          num_translations,            /**< (I) Number of translations for the Master value */
    char **      translation_locales,         /**< (I) The list of locales (in the format ab_UV) for the translations.
                                              <br/>@note If the locale is invalid or not supported, no error is returned and 
                                              the associated translation is simply ignored */
    char **      translation_values,          /**< (I) The translated values for the Master value at index @p seq_num and for the language 
                                              specified by @p translation_locales. */
    char **      translation_status_codes     /**< (I) The translation statuses for the translations in @p translation_values. 
                                              <br/>Valid statuses codes are 'M' (Master), 'A' (Approved), 'P' (Pending), 
                                              'R' (In-Review)and 'I' (Invalid). */
    );

/**
    @deprecated #AOM_UIF_ask_values deprecated in Teamcenter 11.1. Use #AOM_ask_displayable_values instead.

    Retrieves localized property values as an array for multi-value string property
    The locale in which the property values needs to be returned is obtained from the list of preferences
*/
TC_DEPRECATED( "11.1", "AOM_UIF_ask_values", "AOM_ask_displayable_values" )
extern TCCORE_API int AOM_UIF_ask_values(
    tag_t       object,      /**< (I) Unique identifier of the object instance. */
    const char* prop_name,   /**< (I) A property name of the object instance. */
    int*        num_values,  /**< (O) The locale of the property value */
    char***     values       /**< (OF) num_values localized string values of the given multi-value property.
                                       Iterate through the output array and call MEM_free on each element to de-allocate 
                                       the nested memory block and then free the memory pointed by itself using MEM_free. */
    );

/**
    Asks the display value of a property. Regardless of what type of property is asked.
    This function uses #PROP_ask_displayable_values_msg. To customize the behavior of this function,
    register a property method, pre-action or post-action against this message name.
    A default method is registered against #PROP_ask_displayable_values_msg. The default behavior is as follows:
    <ol>
    <li>#AOM_ask_displayable_values gets a value from AOM_ask_value_\<type\>s.
    <li>If the property is a single-value string or note, it does not change what #AOM_ask_value_strings returns.
    <li>If the property is a single-value number (int, float, etc.), the number is converted to a string and returned.
    <li>If the property is a single-value tag (i.e., typed reference, typed relation, etc.) 
        the object_string of the object being referenced by the tag is returned. 
        For most objects, the object_string is its name. 
        However, Item, ItemRevision and others have special object_strings. 
        object_string is a run-time property that is displayed in the Object column of Workspace.
    <li>If the property is a single-value date, the date is returned using 
        the format identified by "DefaultDateFormat" in timelocal_locale.xml.
    <li>If the property is a single-value logical, the values for true/false identified by 
        gk_logical_true_label and gk_logical_false_label in tc_text_locale.xml are used.
    <li>In case of single valued properties, values[0] contains the actual display value. In case of empty
        or null value for @p prop_name, values[0] will contain an empty string.
    <li>If the property is multi-valued, all of the values are returned in an array in packed format.
        The formatting described above is used for each of the property types.
    </ol>    
    @note This ITK returns values array in packed format. Use #MEM_free on the container only.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_object if object is invalid
    <li>#PROP_not_found if property is not found
    </ul>    
*/
extern TCCORE_API int AOM_ask_displayable_values(
    tag_t              object,        /**< (I) The object */
    const char*        prop_name,     /**< (I) The property internal name*/
    int*               num_values,    /**< (O) Number of values */
    char***            values         /**< (OF) num_values Actual Display Values
                                         <br/> The array is packed: use #MEM_free on the container alone to free the whole memory */
    );

/**
    Deletes localized value on a single-valued/multi-valued string property. 
*/
extern TCCORE_API int AOM_UIF_delete_localized_value_string(
    tag_t           object,         /**< (I) Unique identifier of the object instance. */
    const char*     prop_name,      /**< (I) A property name of the object instance. */
    int             index,          /**< (I) Index value of the entry that needs to be deleted for multi-value property; zero for single value property */
    const char*     locale          /**< (I) The locale for which the property value is to be deleted from the VLA */
    );


/**
    Remove translations on a given property.
*/
extern TCCORE_API int AOM_UIF_clear_translations(
    tag_t           object,         /**< (I) The object */
    const char *    prop_name       /**< (I) The property */
    );

/**
    Return the master locale of a localizable property. If the property is not localizable, return error PROP_not_marked_localizable
*/
extern TCCORE_API int AOM_ask_property_master_locale(
    tag_t           object,          /**< (I) The object */
    const char *    prop_name,       /**< (I) The property */
    char**          master_locale    /**< (OF) Master locale of the property */
    );

/**
    Retrieves sorted tags based on the given property descriptor and sort order.

    This function supports numeric-based, string-based and date-based sorting.
    <br/>String-based sorting is based on property display values and sorts by lexicographical sorting.
    
    @note At the present time, this ITK only supports single property sorting.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_sort_with_too_many_properties if the given number of properties exceeds the maximum allowed of 1.
    <li>#PROP_sort_with_no_properties if no property is specified to be used for sorting.
    <li>#CXPOM_invalid_tag if any of the tags in @p pd_tags is invalid.
    </ul>
*/
extern TCCORE_API int AOM_sort_tags_by_properties ( 
    int                n_unsorted_tags,         /**< (I) Number of unsorted tags */
    const tag_t        *unsorted_tags,          /**< (I) n_unsorted_tags Input unsorted tags */
    int                n_props,                 /**< (I) Number of properties for sorting. The maximum allowed is 1. */
    const tag_t        *pd_tags,                /**< (I) n_props Input property descriptor tag for sorting */
    const int          *sort_orders,            /**< (I) n_props Sort order: 0 = ascending, 1 = descending */
    int                *n_sorted_tags,          /**< (O) Number of sorted tags */
    tag_t              **sorted_tags            /**< (OF) n_sorted_tags Output sorted tags. NULLTAGS and duplicate tags are not removed. NULLTAGS are placed at the end. */
    );



/**
    Retrieves sorted tags based on the given property descriptor and sort order.

    This function supports numeric-based, string-based and date-based sorting.
    <br/>String-based sorting is based on property display values and sorts by alhpanumeric sorting.
    
    @note At the present time, this ITK only supports single property sorting.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_sort_with_too_many_properties if the given number of properties @p n_props exceeds the maximum allowed of 1.
    <li>#PROP_sort_with_no_properties if no properties or one invalid properties are specified to be used for sorting.
    <li>#CXPOM_invalid_tag if any of the tags in @p pd_tags is invalid.
    </ul>
*/
extern TCCORE_API int AOM_alphanumeric_sort_tags_by_properties ( 
    int                n_unsorted_tags,         /**< (I) Number of unsorted tags */
    const tag_t        *unsorted_tags,          /**< (I) n_unsorted_tags Input unsorted tags */
    int                n_props,                 /**< (I) Number of properties for sorting. The maximum allowed is 1. */
    const tag_t        *pd_tags,                /**< (I) n_props Input property descriptor tag for sorting */
    const int          *sort_orders,            /**< (I) n_props Sort order: 0 = ascending, 1 or any other number is for descending */
    int                *n_sorted_tags,          /**< (O) Number of sorted tags */
    tag_t              **sorted_tags            /**< (OF) n_sorted_tags Output sorted tags. NULLTAGS and duplicate tags are not removed. NULLTAGS are placed at the end. */
    );


/**
   Sets the master locale to the new requested locale.
   <br/><br/>The newly proposed master locale must be present in the list of locales for the property.
   <br/><br/>Also, if the property is a multi-valued property, all values must be provided for the 
   targeted locale: there must be as many values in the new master locale as there are in the 
   original master locale.
   <br/><br/>Upon success:
   <ul>
   <li>the translation statuses of the "old" master locale will be changed to Approved ('A')
   <li>the translation statuses of the "new" master locale will be changed to Master ('M'), regardless of their previous values
   <li>the translation statuses of all other locales will be unscathed.
   </ul>
   
   @returns
   <ul>
   <li>#ITK_ok on success</li>
   <li>#PROP_locale_not_supported if the specified locale is not supported by the system</li>
   <li>#PROP_invalid_object if the input object is invalid</li>
   <li>#PROP_not_found if the property is not found on the specified object</li>
   <li>#PROP_not_marked_localizable if the property is not localizable</li>
   <li>#PROP_no_localized_value if the property does not contain any value for the specified locale</li>
   <li>#PROP_number_of_values_discrepancy if the property does not contain as many values for the 
   new master locale as it does for the current master locale.</li>
   <li>#PROP_invalid_translation_status if the translation status of the source locale is not 'Approved'.</li>
   </ul>
*/
extern TCCORE_API int AOM_UIF_set_property_master_locale(
    tag_t           object,         /**< (I) The object containing the property */
    const char *    prop_name,          /**< (I) The property for which the master locale is to be modified */
    char*           new_master_locale   /**< (I) The new master locale for the property */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
