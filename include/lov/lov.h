/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef LOV_H
#define LOV_H

#include <pom/pom/pom_tokens.h>
#include <unidefs.h>
#include <property/prop.h>
#include <property/propdesc.h>
#include <tccore/tc_msg.h>
#include <lov/liblov_exports.h>

/**
    @defgroup LOV List of Values (LOV)

    List of Values (LOV) functions allow lists of pre-defined values to be created and associated with properties.
    These LOVs can be displayed to users at run-time to assist them with field entries.

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value           </td><td>Description                                           </td></tr>
    <tr><td>#LOV_detach_error      </td><td>Unable to detach the list of values from the property.</td></tr>
    <tr><td>#LOV_invalid_lov_name  </td><td>Name cannot be NULL.                                  </td></tr>
    <tr><td>#LOV_invalid_type      </td><td>Invalid LOV type.                                     </td></tr>
    <tr><td>#LOV_invalid_usage     </td><td>Invalid usage for this LOV. LOV must be either
                                            #LOV_Suggestions or #LOV_Exhaustive_list.             </td></tr>
    <tr><td>#LOV_invalid_value_type</td><td>Invalid value type. Valid types are #PROP_typed_reference, #PROP_untyped_reference,
                                            #PROP_external_reference, #PROP_typed_relation.       </td></tr>
    <tr><td>#LOV_no_create         </td><td>Failed to create the LOV.                             </td></tr>
    </table>

    @{
*/

#define LOV_root_class_name_c       "ListOfValues"
#define LOV_integer_class_name_c    "ListOfValuesInteger"
#define LOV_double_class_name_c     "ListOfValuesDouble"
#define LOV_char_class_name_c       "ListOfValuesChar"
#define LOV_string_class_name_c     "ListOfValuesString"
#define LOV_date_class_name_c       "ListOfValuesDate"
#define LOV_tag_class_name_c        "ListOfValuesTag"
#define LOV_filter_class_name_c     "ListOfValuesFilter"
#define LOV_dynamic_class_name_c    "Fnd0ListOfValuesDynamic"

#define LOV_name_size_c             32
#define LOV_desc_size_c             240
#define LOV_type_size_c             32
#define LOV_value_desc_size_c       256
#define LOV_classification_name_size_c       32

#define LOV_integer_c               PROP_int
#define LOV_double_c                PROP_double
#define LOV_char_c                  PROP_char
#define LOV_string_c                PROP_string
#define LOV_date_c                  PROP_date
#define LOV_tag_c                   PROP_untyped_reference

/**
    Defines the different restriction rules of LOV that are supported
*/
typedef enum LOV_usage_e
{
    LOV_Unknown,                /**< Unknown                             */
    LOV_Exhaustive_list,        /**< LOV is a exhaustive list            */
    LOV_Suggestions,            /**< LOV is suggestions                  */
    LOV_Ranges,                 /**< LOV is ranges                       */
    LOV_Upper_bound             /**< upper boundary of this enumerate    */
} LOV_usage_t;

/**
    Attached Types
*/
typedef enum LOV_attached_type_e
{
    LOV_Unused,         /**< Unknown                                      */
    LOV_Attribute,      /**< Reference by an attribute (int, string, ...) */
    LOV_Property        /**< Reference by a property                      */
} LOV_attached_type_t;

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Gets the lists of all the list of values in the database.
*/
extern LOV_API int LOV_extent(
    int*           n_lovs,  /**< (O) The number of the lists of values in the database */
    tag_t**        lov      /**< (OF) n_lovs The list of tags for all the LOVs in the database */
    );

/**
    Gets all LOVs with the specified name.
*/
extern LOV_API int LOV_find(
    const char*    lov_name,    /**< (I) The name of the LOV */
    int*           n_lovs,      /**< (O) The number of the found lists of values */
    tag_t**        lov          /**< (OF) n_lovs The tags of the found LOV */
    );

/**
    Gets LOV that is attached to specified property.
    If the returned lov is #NULLTAG, specified property does not have an LOV.
*/
extern LOV_API int LOV_find_attached_prop(
    const char*    type_name,   /**< (I) The name of the Teamcenter Engineering type to which property belongs */
    const char*    prop_name,   /**< (I) Property name to which the LOV is attached */
    tag_t*         lov          /**< (O) Unique identifier (tag) of the LOV instance */
    );


/**
    Retrieves the name of an LOV.
*/
extern LOV_API int LOV_ask_name2(
    tag_t          lov,                             /**< (I) Unique identifier (tag) of the LOV instance */
    char           **lov_name                       /**< (OF) The name of an LOV */
    );


/**
    Retrieves the description of a list of values.
*/
extern LOV_API int LOV_ask_description2(
    tag_t          lov,                             /**< (I) Unique identifier (tag) of the LOV instance */
    char           **lov_desc                       /**< (OF) The description of a list of values */
    );


/**
    Retrieves the type of a list of values.
*/
extern LOV_API int LOV_ask_type2(
    tag_t          lov,                             /**< (I) Unique identifier (tag) of the LOV instance */
    char           **lov_type                       /**< (OF) The type of a list of values */
    );

/**
    Retrieves the usage of an LOV.
*/
extern LOV_API int LOV_ask_usage(
    tag_t          lov_tag,     /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   usage        /**< (O) The usage of this list. One of the following: <br>
                                        #LOV_Exhaustive_list <br>
                                        #LOV_Suggestions <br>
                                        #LOV_Ranges */
    );

/**
    Retrieves the value type of an LOV.
*/
extern LOV_API int LOV_ask_value_type(
    tag_t              lov_tag,        /**< (I) Unique identifier (tag) of the LOV instance */
    PROP_value_type_t* value_type      /**< (O) The type of values in list. Choose one of the following: <br>
                                             #PROP_char <br>
                                             #PROP_date <br>
                                             #PROP_double <br>
                                             #PROP_float <br>
                                             #PROP_int <br>
                                             #PROP_logical <br>
                                             #PROP_short <br>
                                             #PROP_string <br>
                                             #PROP_typed_reference <br>
                                             #PROP_untyped_reference <br>
                                             #PROP_external_reference <br>
                                             #PROP_note <br>
                                             #PROP_typed_relation <br>
                                             #PROP_untyped_relation */
    );

/**
    Retrieves the number of values in an LOV.
*/
extern LOV_API int LOV_ask_num_of_values(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    int*           length   /**< (O) The number of values */
    );

/**
    @name For integer value type
    @{
*/

/**
    Verifies that an LOV value is valid.
*/
extern LOV_API int LOV_is_value_valid_int(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    int            value,   /**< (I) The value to be verified */
    logical*       answer   /**< (O) Returns TRUE if valid and FALSE if not valid */
    );

/**
    Retrieves the lower limit for a range of values.
*/
extern LOV_API int LOV_ask_range_lower_int(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           value,       /**< (O) The values of lower limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if lower limit is null */
    logical*       is_it_empty  /**< (O) Returns TRUE if lower limit is empty */
    );

/**
    Retrieves the upper limit for a range of values.
*/
extern LOV_API int LOV_ask_range_upper_int(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           value,       /**< (O) The values of upper limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if upper limit is not set */
    logical*       is_it_empty  /**< (O) Returns TRUE if upper limit is empty */
    );

/**
    Retrieves the values in an LOV.
*/
extern LOV_API int LOV_ask_values_int(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    int**          values       /**< (OF) n_values Values in the LOV */
    );

/**
    Asks a range of values from the specified LOV.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair will be returned.
    The upper limit and lower limit values are put in the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_values_msg when the usage is #LOV_Exhaustive_list or #LOV_Suggestions.
*/
extern LOV_API int LOV_ask_lov_int(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    int**          values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

extern LOV_API int LOV_ask_lov_int_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    int**          values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

/**
    Converts an LOV to a list of strings.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair must be set.
    The upper limit and lower limit values are used to put the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_disp_values_msg.
*/
extern LOV_API int LOV_ask_disp_values_int(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t    lov_usage,   /**< (I) Usage of the LOV */
    int            n_values,    /**< (I) Number of values to be converted */
    const int*     values,      /**< (I) n_values Values in the LOV */
    const logical* is_null,     /**< (I) n_values Indicates which value(s) are null */
    const logical* is_empty,    /**< (I) n_values Indicates which value(s) are empty */
    char***        disp_values  /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/** @} */

/**
    @name For double value type
    @{
*/

/**
    Verifies that an LOV value is valid.
*/
extern LOV_API int LOV_is_value_valid_double(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    double         value,   /**< (I) The value to be verified */
    logical*       answer   /**< (O) Returns TRUE if valid and FALSE if not valid */
    );

/**
    Retrieves the lower limit for a range of values.
*/
extern LOV_API int LOV_ask_range_lower_double(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    double*        value,       /**< (O) The values of lower limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if lower limit is null */
    logical*       is_it_empty  /**< (O) Returns TRUE if lower limit is empty */
    );

/**
    Retrieves the upper limit for a range of values.
*/
extern LOV_API int LOV_ask_range_upper_double(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    double*        value,       /**< (O) The values of upper limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if upper limit is not set */
    logical*       is_it_empty  /**< (O) Returns TRUE if upper limit is empty */
    );

/**
    Retrieves the values in an LOV.
*/
extern LOV_API int LOV_ask_values_double(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    double**       values       /**< (OF) n_values Values in the LOV */
    );

/**
    Retrieves all the values in an LOV wihout evaluation of values.
*/
extern LOV_API int LOV_ask_values_double_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    double**       values       /**< (OF) n_values Values in the LOV */
    );


/**
    Asks a range of values from the specified LOV.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair will be returned.
    The upper limit and lower limit values are put in the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_values_msg when the usage is #LOV_Exhaustive_list or #LOV_Suggestions.
*/
extern LOV_API int LOV_ask_lov_double(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    double**       values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

extern LOV_API int LOV_ask_lov_double_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    double**       values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

/**
    Converts an LOV to a list of strings.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair must be set.
    The upper limit and lower limit values are used to put the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_disp_values_msg.
*/
extern LOV_API int LOV_ask_disp_values_double(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t    lov_usage,   /**< (I) Usage of the LOV */
    int            n_values,    /**< (I) Number of values to be converted */
    const double*  values,      /**< (I) n_values Values in the LOV */
    const logical* is_null,     /**< (I) n_values Indicates which value(s) are null */
    const logical* is_empty,    /**< (I) n_values Indicates which value(s) are empty */
    char***        disp_values  /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/** @} */

/**
    @name For char value type
    @{
*/

/**
    Verifies that an LOV value is valid.
*/
extern LOV_API int LOV_is_value_valid_char(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    char           value,   /**< (I) The value to be verified */
    logical*       answer   /**< (O) Returns TRUE if valid and FALSE if not valid */
    );

/**
    Retrieves the lower limit for a range of values.
*/
extern LOV_API int LOV_ask_range_lower_char(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    char*          value,       /**< (O) The values of lower limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if lower limit is null */
    logical*       is_it_empty  /**< (O) Returns TRUE if lower limit is empty */
    );

/**
    Retrieves the upper limit for a range of values.
*/
extern LOV_API int LOV_ask_range_upper_char(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    char*          value,       /**< (O) The values of upper limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if upper limit is not set */
    logical*       is_it_empty  /**< (O) Returns TRUE if upper limit is empty */
    );

/**
    Retrieves the values in an LOV.
*/
extern LOV_API int LOV_ask_values_char(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    char**         values       /**< (OF) n_values Values in the LOV */
    );

/**
    Retrieves all the values in an LOV without evaluation of values.
*/
extern LOV_API int LOV_ask_values_char_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    char**         values       /**< (OF) n_values Values in the LOV */
    );


/**
    Asks a range of values from the specified LOV.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair will be returned.
    The upper limit and lower limit values are put in the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_values_msg when the usage is #LOV_Exhaustive_list or #LOV_Suggestions.
*/
extern LOV_API int LOV_ask_lov_char(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    char**         values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

extern LOV_API int LOV_ask_lov_char_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    char**         values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

/**
    Converts an LOV to a list of strings.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair must be set.
    The upper limit and lower limit values are used to put the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_disp_values_msg.
*/
extern LOV_API int LOV_ask_disp_values_char(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t    lov_usage,   /**< (I) Usage of the LOV */
    int            n_values,    /**< (I) Number of values to be converted */
    const char*    values,      /**< (I) n_values Values in the LOV */
    const logical* is_null,     /**< (I) n_values Indicates which value(s) are null */
    const logical* is_empty,    /**< (I) n_values Indicates which value(s) are empty */
    char***        disp_values  /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/** @} */

/**
    @name For string value type
    @{
*/

/**
    Verifies that an LOV value is valid.
*/
extern LOV_API int LOV_is_value_valid_string(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    const char*    value,   /**< (I) The value to be verified */
    logical*       answer   /**< (O) Returns TRUE if valid and FALSE if not valid */
    );

/**
    Retrieves the lower limit for a range of values.
*/
extern LOV_API int LOV_ask_range_lower_string(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    char**         value,       /**< (OF) The values of lower limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if lower limit is null */
    logical*       is_it_empty  /**< (O) Returns TRUE if lower limit is empty */
    );

/**
    Retrieves the upper limit for a range of values.
*/
extern LOV_API int LOV_ask_range_upper_string(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    char**         value,       /**< (OF) The values of upper limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if upper limit is not set */
    logical*       is_it_empty  /**< (O) Returns TRUE if upper limit is empty */
    );

/**
    Retrieves the values in an LOV.
*/
extern LOV_API int LOV_ask_values_string(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    char***        values       /**< (OF) n_values Values in the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/**
Retrieves the localized display values in an LOV.

@returns
<ul> 
<li>#ITK_ok on success</li> 
<li>#POM_invalid_tag if an invalid LOV tag is provided</li>
<li>#LOV_invalid_type if the type of an LOV is invalid</li>
<li>#LOV_invalid_usage if the usage of an LOV is invalid</li>
<li>#LOV_is_not_localized if the locale is invalid/unsupported</li>
</ul>

*/
extern LOV_API int LOV_ask_localized_values(
    tag_t                   lov_tag,                /**< (I) Unique identifier (tag) of the LOV instance. In case of hierarchy LOV, pass the child LOV tag to get the localized values. */
    const char*             locale,                 /**< (I) The locale for which the values of the LOV is requested. <br/>The format of the locale should be: "en_US" or "de_DE" or "fr_FR" etc. */
    int*                    n_values,               /**< (O) The number of returned values */
    char***                 values                  /**< (OF) n_values Values in the LOV. <br/>Call #MEM_free on the container only in order to de-allocate the memory.*/
    );

/**
Retrieves the localized display values and/or descriptions in an LOV.

@returns
<ul> 
<li>#ITK_ok on success</li> 
<li>#POM_invalid_tag if an invalid LOV tag is provided</li>
<li>#LOV_invalid_type if the type of an LOV is invalid</li>
<li>#LOV_invalid_usage if the usage of an LOV is invalid</li>
<li>#LOV_is_not_localized if the locale is invalid/unsupported</li>
</ul>

*/
extern LOV_API int LOV_ask_localized_values_descriptions (
    tag_t           lov_tag,                        /**< (I) Unique identifier (tag) of the LOV instance. In case of hierarchy LOV, pass the child LOV tag to get the localized values. */
    int             n_entries,                      /**< (I) Number of internal values and/or descriptions. */
    const char**    values_or_desc,                 /**< (I) Internal values and/or descriptions. This can contain a mixture of values and descriptions. */
    const char*     locale,                         /**< (I) The locale for which the values and/or descriptions of the LOV is requested. <br/>The format of the locale should be: "en_US" or "de_DE" or "fr_FR" etc. */
    logical         isDescription,                  /**< (I) Flag to indicate if all the entries in values_or_desc are descriptions. True if all entries are descriptions, false otherwise. */
    int*            num,                            /**< (O) Number of display values and/or descriptions. */
    char***         disp_values_desc                /**< (OF) num Display values and/or descriptions. <br/>Call #MEM_free on the container only in order to de-allocate the memory. */
    );


/**
    Retrieves the values in an String LOV without evaluation.
*/
extern LOV_API int LOV_ask_values_string_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    char***        values       /**< (OF) n_values Values in the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/**
    Retrieves the values in an Integer LOV without evaluation.
*/
extern LOV_API int LOV_ask_values_int_without_evaluation(
        tag_t                   lov_tag,                /**< (I) Unique identifier (tag) of the LOV instance */
        int*                    n_values,               /**< (O) The number of returned values */
        int**                   values                  /**< (OF) n_values Values in the LOV. */
        );

/**
    Asks a range of values from the specified LOV.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair will be returned.
    The upper limit and lower limit values are put in the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_values_msg when the usage is #LOV_Exhaustive_list or #LOV_Suggestions.
*/
extern LOV_API int LOV_ask_lov_string(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    char***        values,      /**< (OF) n_values Values in the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

extern LOV_API int LOV_ask_lov_string_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    char***        values,      /**< (OF) n_values Values in the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

/**
    Returns both display values and values, sorted by display values
*/
extern LOV_API int LOV_ask_values_display_string(
    tag_t          lov,             /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,       /**< (O) Usage of the LOV */
    int*           n_values,        /**< (O) Number of values returned */
    char***        display_values,  /**< (OF) n_values The display values for the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    char***        values           /**< (OF) n_values The values for the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/**
    Converts an LOV to a list of strings.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair must be set.
    The upper limit and lower limit values are used to put the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_disp_values_msg.
*/
extern LOV_API int LOV_ask_disp_values_string(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t    lov_usage,   /**< (I) Usage of the LOV */
    int            n_values,    /**< (I) Number of values to be converted */
    const char**   values,      /**< (I) n_values Values in the LOV */
    const logical* is_null,     /**< (I) n_values Indicates which value(s) are null */
    const logical* is_empty,    /**< (I) n_values Indicates which value(s) are empty */
    char***        disp_values  /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/** @} */

/**
    @name For date value type
    @{
*/

/**
    Verifies that an LOV value is valid.
*/
extern LOV_API int LOV_is_value_valid_date(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    date_t         value,   /**< (I) The value to be verified */
    logical*       answer   /**< (O) Returns TRUE if valid and FALSE if not valid */
    );

/**
    Retrieves the lower limit for a range of values.
*/
extern LOV_API int LOV_ask_range_lower_date(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    date_t*        value,       /**< (O) The values of lower limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if lower limit is null */
    logical*       is_it_empty  /**< (O) Returns TRUE if lower limit is empty */
    );

/**
    Retrieves the upper limit for a range of values.
*/
extern LOV_API int LOV_ask_range_upper_date(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    date_t*        value,       /**< (O) The values of upper limit */
    logical*       is_it_null,  /**< (O) Returns TRUE if upper limit is not set */
    logical*       is_it_empty  /**< (O) Returns TRUE if upper limit is empty */
    );

/**
    Retrieves the values in an LOV.
*/
extern LOV_API int LOV_ask_values_date(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    date_t**       values       /**< (OF) n_values Values in the LOV */
    );

/**
    Retrieves all the date values in an LOV without evaluation.
*/
extern LOV_API int LOV_ask_values_date_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    date_t**       values       /**< (OF) n_values Values in the LOV */
    );

/**
    Asks a range of values from the specified LOV.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair will be returned.
    The upper limit and lower limit values are put in the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_values_msg when the usage is #LOV_Exhaustive_list or #LOV_Suggestions.
*/
extern LOV_API int LOV_ask_lov_date(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    date_t**       values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

extern LOV_API int LOV_ask_lov_date_without_evaluation(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    date_t**       values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

/**
    Converts an LOV to a list of strings.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair must be set.
    The upper limit and lower limit values are used to put the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_disp_values_msg.
*/
extern LOV_API int LOV_ask_disp_values_date(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t    lov_usage,   /**< (I) Usage of the LOV */
    int            n_values,    /**< (I) Number of values to be converted */
    const date_t*  values,      /**< (I) n_values Values in the LOV */
    const logical* is_null,     /**< (I) n_values Indicates which value(s) are null */
    const logical* is_empty,    /**< (I) n_values Indicates which value(s) are empty */
    char***        disp_values  /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/** @} */

/**
    @name For tag value type
    @{
*/

/**
    Verifies that an LOV value is valid.
*/
extern LOV_API int LOV_is_value_valid_tag(
    tag_t          lov,     /**< (I) Unique identifier (tag) of the LOV instance */
    tag_t          value,   /**< (I) The value to be verified */
    logical*       answer   /**< (O) Returns TRUE if valid and FALSE if not valid */
    );

/**
    Retrieves the values in an LOV.
*/
extern LOV_API int LOV_ask_values_tag(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_values,    /**< (O) The number of returned values */
    tag_t**        values       /**< (OF) n_values Values in the LOV */
    );

/**
    Asks a range of values from the specified LOV.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair will be returned.
    The upper limit and lower limit values are put in the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_values_msg when the usage is #LOV_Exhaustive_list or #LOV_Suggestions.
*/
extern LOV_API int LOV_ask_lov_tag(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,   /**< (O) Usage of the LOV */
    int*           n_values,    /**< (O) Number of values returned */
    tag_t**        values,      /**< (OF) n_values Values in the LOV */
    logical**      is_null,     /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty     /**< (OF) n_values Indicates which value(s) are empty */
    );

/** @} */

/**
    Asks reference information from the specified LOV.

    @note Only the data type tag can contain reference information.
*/
extern LOV_API int LOV_ask_reference(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    char**         class_name,  /**< (OF) POM class name */
    char**         attr_name    /**< (OF) POM attribute name */
    );

/**
    Returns both display values and values, sorted by display values
*/
extern LOV_API int LOV_ask_values_display_tag(
    tag_t          lov,             /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   lov_usage,       /**< (O) Usage of the LOV returned */
    int*           n_values,        /**< (O) Number of values returned */
    char***        display_values,  /**< (OF) n_values The display values for the LOV. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    tag_t**        values           /**< (OF) n_values Values in the LOV. */
    );

/**
    Converts an LOV to a list of strings.
    When the usage of the LOV is #LOV_Ranges, an upper limit/lower limit pair must be set.
    The upper limit and lower limit values are used to put the values indicated by an even and odd index, respectively.

    This function uses #LOV_ask_disp_values_msg.
*/
extern LOV_API int LOV_ask_disp_values_tag(
    tag_t          lov,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t    lov_usage,   /**< (I) Usage of the LOV */
    int            n_values,    /**< (I) Number of values to be converted */
    const tag_t*   values,      /**< (I) n_values Values in the LOV */
    const logical* is_null,     /**< (I) n_values Indicates which value(s) are null */
    const logical* is_empty,    /**< (I) n_values Indicates which value(s) are empty */
    char***        disp_values  /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/**
    This ITK is for IMAN-PC and IMAN/Web and is intentionally not documented.
    We may, however, turn this ITK into public fully and document it in the future.
*/
extern LOV_API int LOV_ask_disp_values(
    tag_t          lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   usage,           /**< (O) Usage of the LOV returned */
    int*           n_values,        /**< (O) Number of values returned */
    logical**      is_null,         /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty,        /**< (OF) n_values Indicates which value(s) are empty */
    char***        value_strings    /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

extern LOV_API int LOV_ask_disp_values_without_evaluation(
    tag_t          lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   usage,           /**< (O) Usage of the LOV returned */
    int*           n_values,        /**< (O) Number of values returned */
    logical**      is_null,         /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty,        /**< (OF) n_values Indicates which value(s) are empty */
    char***        value_strings    /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );

/**
    Finds the list of properties that are attached to the specified LOV.
*/
extern LOV_API int LOV_ask_attached_properties(
    tag_t          lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_attach,        /**< (O) The number of attachments */
    char***        type_names,      /**< (OF) n_attach The name of theTeamcenter Engineering type to which the property belongs. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    char***        prop_names       /**< (OF) n_attach The name of property to be detached. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    );


/**
    return the array of the strings as the descriptions for values.
    If the usage of the LOV is #LOV_Ranges, or if no descriptions are defined, NULL array is returned.

    This function uses #LOV_ask_value_desc_msg.
*/
extern LOV_API int LOV_ask_value_descriptions(
    tag_t          lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
    LOV_usage_t*   usage,           /**< (O) Usage of the LOV returned */
    int*           n_values,        /**< (O) Number of values returned */
    char***        desc_strings,    /**< (OF) n_values The converted string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
    logical**      is_null,         /**< (OF) n_values Indicates which value(s) are null */
    logical**      is_empty         /**< (OF) n_values Indicates which value(s) are empty */
);

/**
Retrieves the localized descriptions in an LOV.

@returns
<ul> 
<li>#ITK_ok on success</li> 
<li>#POM_invalid_tag if an invalid LOV tag is provided</li>
<li>#LOV_invalid_type if the type of an LOV is invalid</li>
<li>#LOV_is_not_localized if the locale is invalid/unsupported</li>
</ul>
*/
extern LOV_API int LOV_ask_localized_descriptions(
    tag_t          lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance. In case of hierarchy LOV, pass the child LOV tag to get the localized values. */
    char*          locale,          /**< (I) The locale for which the descriptions of the LOV is requested. <br/>The format of the locale should be: "en_US" or "de_DE" or "fr_FR" etc. */
    int*           n_desc_strings,  /**< (O) The number of returned descriptions */
    char***        desc_strings     /**< (OF) n_desc_strings Descriptions in the LOV. <br/>Call #MEM_free on the container only in order to de-allocate the memory. */
);

/**
    return the array of the value indexes and their filters.
*/
extern LOV_API int LOV_ask_value_filters(
    tag_t          lov_tag,                 /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_list_of_filters,       /**< (O) Number of lists of filters returned */
    int**          list_of_filter_indices,  /**< (OF) n_list_of_filters Array of filter indices */
    tag_t**        list_of_filters          /**< (OF) n_list_of_filters Array of filter tags */
);

/**
    ask based-on-lov and shown indexes for a LOV Filter.
*/
extern LOV_API int    LOV_ask_based_on_lov_shown_indexes(
    tag_t              lov_tag,                 /**< (I)  Unique identifier (tag) of the LOV instance */
    tag_t*             based_on_lov,            /**< (O)  Based on LOV tag returned */
    logical*           all_shown,               /**< (O)  true if all the values in the base lov are shown.
                                                        In this case, all the shown indexes are returned for the base */
    int*               n_shown_indices,         /**< (O)  Number of shown indices returned */
    int**              shown_indices            /**< (OF) n_shown_indices Array of shown indices */
    );

extern LOV_API int LOV_ask_attached_properties_info(
            tag_t          lov_tag,         /**< (I) The unique identifier (tag) of the LOV instance */
            int*           n_attach,        /**< (O) The number of attachments */
            char***         type_names,     /**< (OF) n_attach The name of the Teamcenter Engineering types to which
                                                    the properties belong. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
            char***         prop_names,     /**< (OF) n_attach The names of properties to be attached. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
            int**           orders,         /**< (OF) n_attach The dependency order for each attachment */
            int**           n_parents,      /**< (OF) n_attach Parent number to be combined with the leaf value */
            logical**       desc_attach     /**< (OF) n_attach Array of description attachment flag */
);

extern LOV_API int LOV_ask_attached_properties_info_with_conditions(
            tag_t           lov_tag,        /**< (I) The unique identifier (tag) of the LOV instance */
            int*            n_attach,       /**< (O) The number of attachments */
            char***         type_names,     /**< (OF) n_attach The name of the Teamcenter Engineering types to which
                                                the properties belong. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
            char***         prop_names,     /**< (OF) n_attach The names of properties to be attached. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
            int**           orders,         /**< (OF) n_attach the dependency order for each attachment */
            int**           n_parents,      /**< (OF) n_attach parent number to be combined with the leaf value*/
            logical**       desc_attach,    /**< (OF) n_attach description attachment flag*/
            tag_t**         conditions,     /**< (OF) n_attach condition attachment */
            logical**       overrides       /**< (OF) n_attach condition attachment */

);

/**
    return the array of the dependency orders for all the attached properties.
*/
extern LOV_API int LOV_ask_attached_dependency_orders(
            tag_t          lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
            int*           n_attached,      /**< (O) Number of attached dependency orders returned */
            int**          orders           /**< (OF) n_attached Array of dependency orders */
);

/**
    return the array of the flags to indicate if each attach is a description attach.
*/
extern LOV_API int LOV_ask_attached_description_logicals(
            tag_t              lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
            int*               n_attached,      /**< (O) Number of attached descriptions returned */
            logical**          desc_attach      /**< (OF) n_attached Array of attached description flags */
);

/**
    return the array of the ints about the parent number for each attachment.
*/
extern LOV_API int LOV_ask_attached_parent_numbers(
            tag_t              lov_tag,         /**< (I) Unique identifier (tag) of the LOV instance */
            int*               n_attached,      /**< (O) Number of attached parent numbers returned */
            int**              n_parents        /**< (OF) n_attached Array of attached parent numbers */
);

/**
    Retrieves the dependency order of LOV that is attached to specified property.
    Default order is 0
*/
extern LOV_API int LOV_ask_attached_dependency_order(
    const char*    type_name,   /**< (I) The name of the Teamcenter Engineering type to which property belongs */
    const char*    prop_name,   /**< (I) Property name to which the LOV is attached */
    int*           order        /**< (O) the attach level of the LOV if found */
    );

/**
    Retrieves a flag whether the specified property is a LOV description attach.
    Default is false (LOV value attach).
*/
extern LOV_API int LOV_ask_attached_description_logical(
    const char*    type_name,   /**< (I) The name of the Teamcenter Engineering type to which property belongs */
    const char*    prop_name,   /**< (I) Property name to which the LOV is attached */
    logical*       descAttach   /**< (O) description attach of the LOV if found */
    );

/**
    Retrieves parent number for the specified property-lov attachment
    Default is 0.
*/
extern LOV_API int LOV_ask_attached_parent_number(
    const char*    type_name,   /**< (I) The name of the Teamcenter Engineering type to which property belongs */
    const char*    prop_name,   /**< (I) Property name to which the LOV is attached */
    int*           n_parent     /**< (O) parent number for lov-property attachment if found */
    );


/**
    return the array of the strings as the classifications for values.
    If the usage of the LOV is #LOV_Ranges, or if no classifications are defined, NULL array is returned.
*/
extern LOV_API int LOV_ask_value_classifications(
    tag_t          lov_tag,                  /**< (I) Unique identifier (tag) of the LOV instance */
    int*           n_classifications,        /**< (O) Number of classifications returned */
    char***        classifications           /**< (OF) n_classifications The output string values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
);

/**
    Return display values of descriptions.
*/
extern LOV_API int LOV_ask_disp_value_descriptions(
                                        tag_t           lov_tag,           /**< (I) Unique identifier (tag) of the LOV instance */
                                        int*            n_desc_strings,    /**< (O) Number of descriptions returned */
                                        char***         desc_strings,      /**< (OF) n_desc_strings Display descriptions. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
                                        logical**       is_null,           /**< (OF) n_desc_strings Indicates which value(s) are null */
                                        logical**       is_empty           /**< (OF) n_desc_strings Indicates which value(s) are empty */
);

/**
    Returns display values corresponding to internal values.
    Display value passed in can be a string or a pattern e.g (A*, AB*, *AB*).
    Input prop desc can have dynamic and static lovs attached.
    Returns input values disp_values, appended in internal_values at the end.
    If * is supplied as input, it is not processed and returned in output as it is.
    If property desc has not lov attached, input values are returned as it is.
*/
extern LOV_API int LOV_ask_values_from_disp_values_string(
                         tag_t pd_tag,              /**< (I) Property Desc Tag */
                         int n_values,              /**< (I) Number of display values */
                         const char** disp_values,  /**< (I) n_values Display values, it can be pattern */
                         int* n_internal_values,    /**< (O) Number of internal values found */
                         char*** internal_values   /**< (OF) n_internal_values internal values. Iterate through the output array and call MEM_free on each element to de-allocate the nested memory block. */
);

/**
    Given a Dynamic LOV tag, this function will retrieve the LOV definition from the database
    and return the LOV value property name, the LOV description property name and
    the filter properties for the Dynamic LOV.
*/
extern LOV_API int LOV_ask_column_names(
    tag_t          lov_tag,                     /**< (I) Unique identifier (tag) of the LOV instance */
    tag_t         *lov_value_prop_desc_tag,     /**< (O) Property Descriptor tag of the LOV Value Property */
    tag_t         *lov_descr_prop_desc_tag,     /**< (O) Property Descriptor tag of the LOV Description Property */
    int           *num_filter_props,            /**< (O) Number of property Descriptor tags of the filter properties. */
    tag_t         *filter_prop_desc_tags[]      /**< (OF) num_filter_props Property Descriptor tags of the filter properties. */
);

/**
    Given a Dynamic LOV tag and user entered search string that is used to filter the results,
    this function will return a list of objects that match the query criteria for the Dynamic LOV
    including the filter string entered by the user.
*/
extern LOV_API int LOV_execute_dynamic_lov(
    const tag_t    lov_tag,                 /**< (I) Unique identifier (tag) of the LOV instance */
    const tag_t    object_tag,              /**< (I) This is an optional argument. It represents a runtime object which will be used in the future to evaluate LOV values based on context */
    const char    *prop_name,               /**< (I) The property name for which the LOV values are being evaluated */
    const char    *filter_string,           /**< (I) The user entered string. */
    const int      max_results,             /**< (I) Maximum values the client wants to be returned from the server */
    const char    *sort_property_name,      /**< (I) Property name used to sort the results */
    const int      order,                   /**< (I) A value of 1 indicates sort property values to be in ascending order. A value of 2 indicates sort property values to be in descending order. */
    int           *num_results,             /**< (O) Number of objects that match the query criteria for the Dynamic LOV */
    tag_t        **results                  /**< (OF) num_results Objects that match the query criteria for the Dynamic LOV */
    );


/**
    Retrieves the context value for the  given operation input tag @p operation_input_tag and context property name @p context_prop_name.
    
    @returns
    <ul>
    <li>#ITK_ok on success 
    <li>#CXPOM_invalid_tag if @p operation_input_tag operation input tag is #NULLTAG
    <li>#PROP_not_found if @p context_prop_name not a valid property name. Valid contexts property names:fnd0ContextPropName
    </ul>
*/
extern LOV_API int LOV_get_string_context(
     tag_t         operation_input_tag,       /**< (I)  The tag of the operation input object. */
     const char*   context_prop_name,         /**< (I)  The name of the context property for which a value to be retrieved. */
     char**        context_prop_value         /**< (OF) Returned context property value.  */
    );

/**
    Retrieves the context value for the given operation input tag @p operation_input_tag and context property name @p context_prop_name.
    
    @returns
    <ul>
    <li>#ITK_ok on success 
    <li>#CXPOM_invalid_tag if @p operation_input_tag operation input tag is #NULLTAG
    <li>#PROP_not_found if @p context_prop_name not a valid property name. Valid contexts property names:fnd0ContextObject
    </ul>
*/
extern LOV_API int LOV_get_tag_context(
     tag_t         operation_input_tag,        /**< (I)  The tag of the operation input object. */
     const char*   context_prop_name,          /**< (I)  The name of the context property for which a value to be retrieved. */
     tag_t*        context_prop_value          /**< (O)  Returned context property value.  */
    );
/** @} LOV group */

#ifdef __cplusplus
}
#endif

#include <lov/liblov_undef.h>

#endif
