/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file tc_date.h
    @brief Date utility functions

    This file contains the constants, data structures and function
    prototypes for working with the date utility.
*/

/*  */

#ifndef TC_DATE_H
#define TC_DATE_H

#include <unidefs.h>
#include <fclasses/libfclasses_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    @defgroup DATE Date
    @ingroup TC

    This section contains date utility functions.  It describes a number of utility functions for
    creating, duplicating, and manipulating date.
    @{
*/

/**
    Unpicks a string containing a date and time into its components.
    The string must be formatted according the the template specified in the format_string argument;
    this template is the same as would be passed to the ANSI C strftime routine,
    except only the bB d H I mM S w yY conversions are implemented.

    Returns #PROP_invalid_date_format if unsuccessful.
*/
extern FCLASSES_API int DATE_string_to_date(
    const char*         date_str,       /**< (I) Specified date string */
    const char*         format_str,     /**< (I) Format to describe how to interpret the date */
    int*                month,          /**< (O) */
    int*                day,            /**< (O) */
    int*                year,           /**< (O) */
    int*                hour,           /**< (O) */
    int*                minute,         /**< (O) */
    int*                second          /**< (O) */
    );

/**
    Converts a date_t structure into a text representation.
    The date is formatted according to the specified format string.
    The format string is the one defined for the ANSI C strftime function
    except that the following conversions are not implemented:

    aA cC e h j n p rR tT uU V xX y Z %

    In other words, the following conversions are implemented:

    bB d H I mM S w yY

    Returns #PROP_invalid_date_format if unsuccessful.
*/
extern FCLASSES_API int DATE_date_to_string(
    date_t              date_struct,    /**< (I) Supplied date_t structure */
    const char*         format_str,     /**< (I) Desired date format */
    char**              date_str        /**< (OF) Date in a textual representation */
    );

/**
    Converts a string date to a date_t structure. It assumes the format of the input string
    to be dd-mmw-yyyy hh:mm:ss (e.g. 24-Aug-1991 09:09:56)
 
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_not_a_date if unsuccessful.
    </ul>
*/
extern FCLASSES_API int DATE_string_to_date_t(
    char*               date,           /**< (I) date in string format */
    logical*            date_is_valid , /**< (O) is date valid or not */
    date_t*             the_dt          /**< (O) date_t structure */
    );

/**
    Converts a string date to an ISO date_t structure. It assumes the format of the input string
    to be yyyy-mm-ddThh:mm:ss (e.g. 2018-03-02T19:33:59)

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_not_a_date if unsuccessful.
    </ul>
*/
extern FCLASSES_API int DATE_convert_iso_date_to_date_t(
    const char*         date_string,        /**< (I) date in string format */
    date_t*             date_structure      /**< (O) ISO date */
    );

/**
    Retrieves the localized default date format, as specified by the entry "DefaultDateFormat" in the localization file.
    <br>If the value is not found, the date format is set to "%d-%b-%y %H:%M".

    @returns
    <ul>
    <li>#ITK_ok always
    </ul>
*/
extern FCLASSES_API int DATE_default_date_format(
    char**              date_str        /**< (OF) Date in a textual representation */
    );

/**
Retrieves the date format as a string.
<br><br>The string format can be used in #DATE_string_to_date for instance.

@returns
<ul>
<li>#ITK_ok on success.
<li>#PROP_invalid_date_format if the date format cannot be retrieved. 
</ul>
*/
extern FCLASSES_API int DATE_get_internal_date_string_format(
    char**              format_str        /**< (OF) Date format*/
    );

/**
    Converts a formatted string date to a #date_t structure.
    <br>If the input 'format_str' parameter is NULL or blank, the format of the input string
    needs to be in the format "yyyy-mm-dd hh:mm:ss" (e.g. 1991-04-24 09:09:56).

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_date_format if the format is invalid
    <li>#PROP_invalid_minute if the string date minute field is invalid
    <li>#PROP_invalid_second if the string date second field is invalid
    <li>Potentially other errors
    </ul>

    Please use #DATE_convert_formatted_string_to_date API instead, in the following fashion:
    @code
    // Using the same parameter as for DATE_convert_format_date_to_date_t 
    DATE_convert_formatted_string_to_date(date, format_str, false, true, date_structure);
    @endcode
*/
extern FCLASSES_API int DATE_convert_format_date_to_date_t(
    const char*         date,           /**< (I) Date in string format */
    const char*         format_str,     /**< (I) Supplied date format */
    date_t*             date_structure  /**< (O) The #date_t structure */
    );


/**
    Converts, possibly in a stringent manner, a formatted string date to a #date_t structure.

    <br/>The stringent check enforces that all the parameters in the @p format input format 
    have found a match in the input string @p date, for the conversion to be considered successful. 
    <ul>
    <li>If it is turned on and any parameter is missing, an error #PROP_date_incomplete_conversion
    is returned, and the @p date_structure date is populated with the information that could have been extracted.
    <li>Otherwise, no error is reported even if the conversion is partial.
    <br/>Note that this is the case when passing a string "1999" and a format "%Y-%m-%d %H:%M": the ITK would then
    return #ITK_ok and only the year (1999) is extracted in the output date_t structure.
    </ul>
    
    <br>If the parameter @p format is NULL or blank, the format used for the input string
    depends on the value for the parameter @p localized_default_format.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_date_incomplete_conversion if the @p stringent_check parameter is true and 
    the conversion partially failed.
    <li>#PROP_invalid_date_format if the input date is not in the provided format
    <li>Potentially other errors
    </ul>
*/
extern FCLASSES_API int DATE_convert_formatted_string_to_date(
    const char*         date,                     /**< (I) Date in string format */
    const char*         format,                   /**< (I) Supplied date format */
    logical             localized_default_format, /**< (I) Used in case the parameter @p format is invalid, to decide whether to use:
                                                     <ul>
                                                     <li>true: the localized date format as accessible through #DATE_default_date_format, 
                                                     <li>false: the static format "%Y-%m-%d %H:%M:%S" (e.g. 1991-04-24 09:09:56).
                                                     </ul> */
    logical             stringent_check,          /**< (I) Activates stringent check */
    date_t*             date_structure            /**< (O) The converted date */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <fclasses/libfclasses_undef.h>
#endif
