/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the ANSI C interface to Teamcenter Engineering property messages.

    Property Messages are conceptual actions to be done on a property.
    When a Message is sent to a specific Property, the Method registered with
    that Message/Type/Property combination will be executed.
    See ITK documentation on Property Methods for further details.

    Each message has a unique set of parameters, which are defined here.
    These parameters are passed in the varargs list
    #METHOD_execute / #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.
*/

/*  */

#ifndef PROP_MSG_H
#define PROP_MSG_H

#include <common/tc_deprecation_macros.h>
#include <property/libproperty_exports.h>

/**
    @defgroup PROP_MSG Messages
    @ingroup PROP

    This section documents messages that are used to implement asking and setting property values.
    Each message is a defined action performed on a specified property type
    (e.g., ask value of a string, set value of a logical).

    <table>
    <tr><td>Methods    </td><td>A method is an implementation of a message.
                                Each of the messages documented in this section has an associated default method.
                                Calling a message that is implemented via the default method is
                                referred to as default message behavior.</td></tr>
    <tr><td>Methods ITK</td><td>In Teamcenter Engineering, default message behavior can be customized by
                                registering new methods against the message. Adding a new method to a message overrides
                                the default method each time the message is called. This is significant because
                                Teamcenter Engineering calls many of the messages documented in this section internally.
                                Therefore, modifying the default behavior of any message not only affects ITK behavior
                                but also potentially affects Workspace, PSE, etc. Go to Methods for additional information
                                about customizing default behavior using methods ITK.</td></tr>
    </table>
    @{
*/

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_string.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param char**   value    The string value of a single-valued property
*/
#define PROP_ask_value_string_msg       "PROP_ask_value_string"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_strings.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int*     num The count of values
    @param char***  values The string values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_strings_msg      "PROP_ask_value_strings"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_string_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param char**   values The string value of a multi-valued property at a particular index position
*/
#define PROP_ask_value_string_at_msg    "PROP_ask_value_string_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_string.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param const char*   value The string value on a single-valued property
*/
#define PROP_set_value_string_msg       "PROP_set_value_string"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_strings.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param char**   values One or more string values on a property
*/
#define PROP_set_value_strings_msg      "PROP_set_value_strings"

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_char.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param char*    value The char value of a single-valued property
*/
#define PROP_ask_value_char_msg         "PROP_ask_value_char"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_chars.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int*     num The count of values
    @param char**   values The char values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_chars_msg        "PROP_ask_value_chars"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_char_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param char*    values The char value of a property at a particular index position
*/
#define PROP_ask_value_char_at_msg      "PROP_ask_value_char_at"

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_date.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param date_t*  value The date value of a single-valued property
*/
#define PROP_ask_value_date_msg         "PROP_ask_value_date"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_dates.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int*     num The count of values
    @param date_t** values The date values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_dates_msg        "PROP_ask_value_dates"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_date_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param date_t*  value The date value of a multi-valued property at a particular index position
*/
#define PROP_ask_value_date_at_msg      "PROP_ask_value_date_at"

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_double.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param double*  value The double value of a single-valued property
*/
#define PROP_ask_value_double_msg       "PROP_ask_value_double"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_doubles.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int*     num The count of values
    @param double** values The double values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_doubles_msg      "PROP_ask_value_doubles"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_double_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param double*  value The double value of a multi-valued property at a particular index position
*/
#define PROP_ask_value_double_at_msg    "PROP_ask_value_double_at"

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_int.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int*     value The int value of a single-valued property
*/
#define PROP_ask_value_int_msg          "PROP_ask_value_int"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_ints.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int*     num The count of values
    @param int**    values The int values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_ints_msg         "PROP_ask_value_ints"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_int_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param int*     value The int value of a multi-valued property at a particular index position
*/
#define PROP_ask_value_int_at_msg       "PROP_ask_value_int_at"

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_logical.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param logical*  value The logical value of a single-valued property
*/
#define PROP_ask_value_logical_msg      "PROP_ask_value_logical"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_logicals.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t     prop_tag This parameter input is a NULLTAG and should not be used
    @param int*      num The count of values
    @param logical** values The logical values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_logicals_msg     "PROP_ask_value_logicals"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_logical_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param logical* value The logical value of a multi-valued property at a particular index position
*/
#define PROP_ask_value_logical_at_msg   "PROP_ask_value_logical_at"

/**
    Asks value of a single-valued property. The property cannot be an array or list.
    This message is called by #AOM_ask_value_tag.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param tag_t*   value The tag value of a single-valued property
*/
#define PROP_ask_value_tag_msg          "PROP_ask_value_tag"

/**
    Asks one or more values of a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_ask_value_tags.

    This message should use #MEM_alloc to allocate space for setting * values.
    @param tag_t     prop_tag This parameter input is a NULLTAG and should not be used
    @param int*      num The count of values
    @param tag_t**   values The tag values of a single-valued or multi-valued property
    @param logical** is_null Indicates which value(s) are null
    @param logical** is_empty Indicates which value(s) are empty
*/
#define PROP_ask_value_tags_msg         "PROP_ask_value_tags"

/**
    Asks value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_ask_value_tag_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param tag_t*   value The tag value of a multi-valued property at a particular index position
*/
#define PROP_ask_value_tag_at_msg       "PROP_ask_value_tag_at"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_string_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      position The position of value
    @param const char*   value The character string value of a multi-valued property at a particular index position
*/
#define PROP_set_value_string_at_msg    "PROP_set_value_string_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_char.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param char     value The char value on a single-valued property
*/
#define PROP_set_value_char_msg         "PROP_set_value_char"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_chars.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param const char*    values The values of a multi-valued property from a list of char values
*/
#define PROP_set_value_chars_msg        "PROP_set_value_chars"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_char_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param char     value The char value at a particular index position of a multi-valued property
*/
#define PROP_set_value_char_at_msg      "PROP_set_value_char_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_date.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param date_t   value The value of a property from a date value
*/
#define PROP_set_value_date_msg         "PROP_set_value_date"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_dates.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param const date_t*    values The values of a multi-valued property from a list of date values
*/
#define PROP_set_value_dates_msg        "PROP_set_value_dates"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_date_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param date_t   value The date value at a particular index position of a multi-valued property
*/
#define PROP_set_value_date_at_msg      "PROP_set_value_date_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_double.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param double   value The value of a property from a double value
*/
#define PROP_set_value_double_msg       "PROP_set_value_double"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_doubles.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param const double*    values The values of a multi-valued property from a list of double values
*/
#define PROP_set_value_doubles_msg      "PROP_set_value_doubles"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_double_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      position The position of value
    @param double   value The double value at a particular index position of a multi-valued property
*/
#define PROP_set_value_double_at_msg    "PROP_set_value_double_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_int.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      value The value of a property from a int value
*/
#define PROP_set_value_int_msg          "PROP_set_value_int"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_ints.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param const int*    values The values of a multi-valued property from a list of int values
*/
#define PROP_set_value_ints_msg         "PROP_set_value_ints"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_int_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param int      value The int value at a particular index position of a multi-valued property
*/
#define PROP_set_value_int_at_msg       "PROP_set_value_int_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_logical.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param logical  value The value of a property from a logical value
*/
#define PROP_set_value_logical_msg      "PROP_set_value_logical"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_logicals.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param const logical*    values The values of a multi-valued property from a list of logical values
*/
#define PROP_set_value_logicals_msg     "PROP_set_value_logicals"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_logical_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      pos The position of value
    @param logical      value The logical value at a particular index position of a multi-valued property
*/
#define PROP_set_value_logical_at_msg   "PROP_set_value_logical_at"

/**
    Sets value on a single-valued property.
    This message is called by #AOM_set_value_tag.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param tag_t    value The value of a property from a tag value
*/
#define PROP_set_value_tag_msg          "PROP_set_value_tag"

/**
    Sets one or more values on a property.
    The property can be single-valued or multi-valued (i.e., array or list).
    This message is called by #AOM_set_value_tags.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      num The count of values
    @param const tag_t*    values The values of a multi-valued property from a list of tag values
*/
#define PROP_set_value_tags_msg         "PROP_set_value_tags"

/**
    Sets value of a multi-valued (i.e., list or array) property at a particular index position.
    The property can be single-valued if position = 0.
    This message is called by #AOM_set_value_tag_at.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      position The position of value
    @param tag_t    value The tag value at a particular index position of a multi-valued property
*/
#define PROP_set_value_tag_at_msg       "PROP_set_value_tag_at"

/**
    Indicates whether a property can be modified by the user.
    Is called by #AOM_is_modifiable, or whenever an attempt is made to set the value of a property.

    A default method for this message is registered for properties automatically.
    The default checks if the property descriptor is set to #PROP_write and if
    the user has permission to write to the object the property instance is describing.

    A programmer can register a post-action to the default method that does additional checks or
    a programmer can register a method for this message that does a different set of checks altogether.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param logical*  value The value indicating whether a property can be modified by the user
*/
#define PROP_is_modifiable_msg          "PROP_is_modifiable"

/**
    @deprecated #PROP_UIF_ask_value_msg deprecated in Teamcenter 11.1. Use #PROP_ask_displayable_values_msg instead.

    Asks display value of any type of property.
    This message is called by #AOM_UIF_ask_value and determines the way a particular property type is
    displayed in Workspace, PSE, Properties dialog box and Objects dialog box.

    @note This method is responsible for insuring that the ask method corresponding to the
    fundamental value type of the property is not circumvented.
    For example if the value type of the property is #PROP_int, then #AOM_ask_value_int should be used.
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param char**   d_value The display value of a property
*/
#define PROP_UIF_ask_value_msg          "PROP_UIF_ask_value"
TC_DEPRECATED_PREPROCESSOR("11.1", PROP_UIF_ask_value_msg, "PROP_ask_displayable_values_msg" )

/**
    Sets the value of any type of property using a display value as input.
    This message is called by #AOM_UIF_set_value and is used for setting the value of
    a property from some function that deals with display values.
    Internally, Teamcenter Engineering calls this when the user sets a value from the
    Properties dialog box, Workspace or PSE.

    @note This method is responsible for insuring that the set method corresponding to
    the fundamental value type of the property is not circumvented.
    For example, if the value type of the property is #PROP_int,
    AOM_set_value_int should be used.
    
    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param const char*  value The value of a property from a string, regardless of the fundamental property value type
*/
#define PROP_UIF_set_value_msg          "PROP_UIF_set_value"

/**
    Validate Value of a Property as a char by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param char     value    The value to be validated
    @param logical* verdict  Indicates if value is settable
*/
#define PROP_validate_lov_char_msg      "PROP_validate_lov_char"

/**
    Validate Value of a Property as a date by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param date_t   value    The value to be validated
    @param logical* verdict  Indicates if value is settable
*/
#define PROP_validate_lov_date_msg      "PROP_validate_lov_date"

/**
    Validate Value of a Property as a double by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param double   value    The value to be validated
    @param logical* verdict  Indicates if value is settable
*/
#define PROP_validate_lov_double_msg    "PROP_validate_lov_double"

/**
    Validate Value of a Property as a int by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param int      value    The value to be validated
    @param logical* verdict  Indicates if value is settable
*/
#define PROP_validate_lov_int_msg       "PROP_validate_lov_int"

/**
    Validate Value of a Property as a logical by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param logical  value    The value to be validated
    @param logical* verdict  Indicates if value is settable
*/
#define PROP_validate_lov_logical_msg   "PROP_validate_lov_logical"

/**
    Validate Value of a Property as a string by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param char*    value    The value to be validated
    @param logical* verdict  Indicates if value is settable
*/
#define PROP_validate_lov_string_msg    "PROP_validate_lov_string"

/**
    Validate Value of a Property as a tag by LOV

    @param tag_t    prop_tag This parameter input is a NULLTAG and should not be used
    @param tag_t    value    The value to be validated
    @param logical* verdict  Tndicates if value is settable
*/
#define PROP_validate_lov_tag_msg       "PROP_validate_lov_tag"

/**
    @deprecated #PROP_ask_lov_chars_msg deprecated in Teamcenter 11.3.

    Ask allowable values as chars which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param char**       values   The allowable values
*/
#define PROP_ask_lov_chars_msg          "PROP_ask_lov_chars"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_chars_msg, "" )

/**
    @deprecated #PROP_ask_lov_dates_msg deprecated in Teamcenter 11.3.

    Ask allowable values as dates which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param date_t**     values   The allowable values
*/
#define PROP_ask_lov_dates_msg          "PROP_ask_lov_dates"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_dates_msg, "" )

/**
    @deprecated #PROP_ask_lov_doubles_msg deprecated in Teamcenter 11.3.

    Ask allowable values as doubles which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param double**     values   The allowable values
*/
#define PROP_ask_lov_doubles_msg        "PROP_ask_lov_doubles"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_doubles_msg, "" )

/**
    @deprecated #PROP_ask_lov_ints_msg deprecated in Teamcenter 11.3.

    Ask allowable values as ints which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param int**        values   The allowable values
*/
#define PROP_ask_lov_ints_msg           "PROP_ask_lov_ints"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_ints_msg, "" )

/**
    @deprecated #PROP_ask_lov_logicals_msg deprecated in Teamcenter 11.3.

    Ask allowable values as logicals which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param logical**    values   The allowable values
*/
#define PROP_ask_lov_logicals_msg       "PROP_ask_lov_logicals"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_logicals_msg, "" )

/**
    @deprecated #PROP_ask_lov_strings_msg deprecated in Teamcenter 11.3.

    Ask allowable values as strings which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param char***      values   The allowable values
*/
#define PROP_ask_lov_strings_msg        "PROP_ask_lov_strings"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_strings_msg, "" )

/**
    @deprecated #PROP_ask_lov_tags_msg deprecated in Teamcenter 11.3.

    Ask allowable values as tags which are able to set into this property

    @param tag_t        prop_tag This parameter input is a NULLTAG and should not be used
    @param LOV_usage_t* usage    The usage of allowable values
    @param int*         n_values The count of allowable values
    @param tag_t**      values   The allowable values
*/
#define PROP_ask_lov_tags_msg           "PROP_ask_lov_tags"
TC_DEPRECATED_PREPROCESSOR("11.3", PROP_ask_lov_tags_msg, "" )

/**
    Asks display value of any type of property.
    This message is called by #AOM_ask_displayable_values and determines the way a particular property type is
    displayed in Workspace, PSE, Properties dialog box and Objects dialog box.

    @param tag_t         prop_tag    This parameter input is a NULLTAG and should not be used
    @param int*          num_values  The count of values
    @param char***       values      The display values of the property
*/
#define PROP_ask_displayable_values_msg  "PROP_ask_displayable_values"


/** @} */

#include <property/libproperty_undef.h>

#endif
