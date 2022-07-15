/*==============================================================================
                Copyright (c) 2003-2005,2008 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the ANSI C interface to Teamcenter Engineering property
    descriptors. These provide the definition of a property. The interface for
    actual instances of a property is defined in imanproperty.h
*/

/*  */

#ifndef PROPERTYDESCRIPTOR_H
#define PROPERTYDESCRIPTOR_H

#include <unidefs.h>

#include <property/libproperty_exports.h>

/**
    @defgroup PROPDESC Descriptors
    @ingroup PROP

    A property is a piece of information about an object of a particular type.
    A property descriptor defines (i.e., is the name of) a property.
    The interface for actual instances of a property is defined in imanproperty.h
    @{
*/

/**
    Defines the different types of properties that are supported
*/
typedef enum PROP_type_e{
    PROP_unknown,               /**< Property type is Unknown */
    PROP_attribute,             /**< Based on a POM Attribute (int, string, ...) */
    PROP_reference,             /**< Based on a POM Reference */
    PROP_relation,              /**< Based on an ImanRelation */
    PROP_compound,              /**< Based on a property from another Type */
    PROP_runtime,               /**< Based on a computed value */
    PROP_operationinput,        /**< Based on the source property on a BO */
    PROP_backward_reference,    /**< Based on a reference attribute on another type */
    PROP_table                  /**< Based on a reference attribute on a TableRow type */
} PROP_type_t;

/**
    Defines the different types of values a property might hold
*/
typedef enum PROP_value_type_e{
    PROP_untyped,               /**< No Value type */
    PROP_char,                  /**< Value is a single character */
    PROP_date,                  /**< Value is a date */
    PROP_double,                /**< Value is a double */
    PROP_float,                 /**< Value is a float */
    PROP_int,                   /**< Value is an integer */
    PROP_logical,               /**< Value is a logical */
    PROP_short,                 /**< Value is a short */
    PROP_string,                /**< Value is a character string */
    PROP_typed_reference,       /**< Value is a typed reference */
    PROP_untyped_reference,     /**< Value is an untyped reference */
    PROP_external_reference,    /**< Value is an external reference */
    PROP_note,                  /**< Value is a note */
    PROP_typed_relation,        /**< Value is a typed relation */
    PROP_untyped_relation       /**< Value is an untyped relation */
} PROP_value_type_t;

/**
    Defines the protection types that might be on a property
*/
typedef enum PROP_protection_e{
    PROP_write,                  /**< Property can be written to and read */
    PROP_read,                   /**< Property can be read, but not written to */
    PROP_write_only_if_null      /**< Property can be written to only if the existing value is null or empty */
} PROP_protection_t;

/**
    Defines the property rule name value pair structure
    NOTE:  Duplicate of RULE_val_t structure defined internally only in the businessrule.hxx
*/
typedef struct PRULE_val_s
{
  char* name;
  char* value;
  int   num_of_children;
  struct PRULE_val_s* children;
} PRULE_val_t;

/** OperationInput Dialog Field Type */
typedef enum PROP_field_type_e
{
    PROP_field_unknown,
    PROP_simple_property,
    PROP_compound_object,
    PROP_compound_relation
} PROP_field_type_t;

/**
    Defines the LOV attachment category information
*/
typedef enum PROP_lov_attach_category_e{
    PROP_lov_no_attaches,   /**< No attachments*/
    PROP_lov_istrue_attaches, /**< Only isTrue condition is attached*/
    PROP_lov_session_attaches, /**< Only Session Based Conditions are attached*/
    PROP_lov_object_based_attaches /**< One or More Object Based Conditions are attached*/
} PROP_lov_attach_category_t;

/**
    Defines the property validation status for each attribute
    NOTE:  This is needed since multiple attributes can exist and status for each is needed
*/

typedef enum PROP_valid_e {
    PROP_valid_id,    /**< valid property */
    PROP_invalid_id,  /**< invalid property */
    PROP_override_id, /**< modified property */
    PROP_duplicate_id /**< duplicate property */
} PROP_valid_t;

/**
    structure to return property validation status to caller
*/
typedef struct PROP_values_stat_s {
  char* attr_name;      /**< property name */
  PROP_valid_t status;  /**< property validation status */
} PROP_values_stat_t;


#ifdef __cplusplus
    extern "C"{
#endif

/**
    Asks name of a property.
*/
extern PROPERTY_API int PROPDESC_ask_name(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    char**              name        /**< (OF) The name of the property */
    );

/**
    Asks display name of a property.
*/
extern PROPERTY_API int PROPDESC_ask_display_name(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    char**              disp_name   /**< (OF) The display name of the property */
    );


/**
    Sets the display name of a property.
*/
extern PROPERTY_API int PROPDESC_set_display_name(
    tag_t               prop_tag,   /**< (I) The tag of the property */
    const char*         disp_name   /**< (I) The new display name of the property */
    );

/**
    Asks the initial value (if any defined in a property rule) for the given property descriptor.
*/
extern PROPERTY_API int PROPDESC_ask_prule_init_value(
    tag_t               prop_tag,        /**< (I) The property descriptor tag */
    char**              prule_init_value /**< (OF) Initial value (if any) specified on the property rule */
    );

/**
    Describes all of the properties from a property rule.
*/
extern PROPERTY_API int PROPDESC_describe_prule(
    tag_t               prop_tag,        /**< (I) The property descriptor tag */
    PRULE_val_t**       argList          /**< (OF) Structure of Property Rule property name/value pairs */
    );

/**
    Free memory for all members of the PRULE_val_t structure.
*/
extern PROPERTY_API void PROPDESC_free_prule_struct(
    PRULE_val_t**       argList          /**< (I/O) Structure of Property Rule property name/value pairs */
    );

/**
    Asks the type that the property descriptor defines.
*/
extern PROPERTY_API int PROPDESC_ask_object_type(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    tag_t*              type_tag    /**< (O) The tag of the type */
    );

/**
   Retrieves the LOV associated with the specified property.
*/
extern PROPERTY_API int PROPDESC_ask_lov(
    tag_t               prop_tag,   /**< (I) The property */
    tag_t*              lov_tag     /**< (O) The LOV associated with the property */
    );


/**
    Determines if the property has to be enabled in the UI
*/
extern PROPERTY_API int PROPDESC_is_enabled(
    tag_t               prop_tag,    /**< (I) */
    logical*            enable_flag    /**< (O) */
    );


/**
   Retrieves the property type.
*/
extern PROPERTY_API int PROPDESC_ask_property_type(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    PROP_type_t*        proptype,   /**< (O) The property type of the property */
    char**              proptype_n  /**< (OF) The name of the property type */
    );

/**
    Retrieves the value type of a property.
*/
extern PROPERTY_API int PROPDESC_ask_value_type(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    PROP_value_type_t*  valtype,    /**< (O) The value type of the property */
    char**              valtype_n   /**< (OF) The name of the value type */
    );

/**
    Asks maximum number of elements for a property.
*/
extern PROPERTY_API int PROPDESC_ask_max_num_elements(
    tag_t               prop_desc_tag,       /**< (I) The tag of the property descriptor */
    int*                maxnumelem      /**< (O) The maximum number of elements for the property.
                                            Will be 1 for a single-valued property, -1 for a list property and
                                            a positive integer for an array property. */
    );

/**
    Asks maximum string length for a property. The property must be type #PROP_string.
*/
extern PROPERTY_API int PROPDESC_ask_max_string_length(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    int*                maxstrlen   /**< (O) The maximum string length of the property value */
    );

/**
    Asks default protection of a property.
*/
extern PROPERTY_API int PROPDESC_ask_protection(
    tag_t               prop_desc_tag,       /**< (I) The tag of the property descriptor */
    PROP_protection_t*  protection      /**< (O) The default protection for the property.
                                             See #PROP_protection_t for additional information about protections. */
    );


/**
    Determines whether the property is formattable.
    <br>A property meets the formattable criteria if:
    <ol>
    <li>The property constant Fnd0IsFormattable is true
    <li>The property doesn't have any LOV attachment
    <li>The property is attached with a fomatter
    </ol>
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor when the input tag is not a valid property tag
    </ul>
*/
extern PROPERTY_API int PROPDESC_is_formattable(
    tag_t               prop_tag,      /**< (I) Tag of the property descriptor */
    logical*            is_formattable /**< (O) The formattable status: true if the property value can be formatted, false otherwise. */
    );

/**
    Determines the value of the logical property constant "Fnd0EnableTimeForDateProperty" for the specified property.
    <br>The constant helps determine if time value in a date property is to be displayed when editing objects of the type where the property belongs.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor when the input tag is not a valid property tag
    </ul>
*/
extern PROPERTY_API int PROPDESC_is_time_enabled (
    tag_t               prop_tag,       /**< (I) Tag of the property descriptor */
    logical*            time_enabled    /**< (O) The time enablement status: true if the time can be presented, false otherwise. */
    );

/**
    Determines if a property can be validated, that is if a "user-exit" or "name-rule" rule is available to validate the property.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Error code on failure
    </ul>
*/
extern PROPERTY_API int PROPDESC_is_validatable(
    tag_t               prop_tag,           /**< (I) Tag of the property descriptor */
    logical*            validatable_flag    /**< (O) The validation status: true if the property can be validated, false otherwise. */
    );

extern PROPERTY_API int PROPDESC_ask_lov_attach_dep_order(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    int*                order       /**< (O) The order at which the property is attached to the LOV
                                         The default is 0 (the whole LOV)  */
    );

extern PROPERTY_API int PROPDESC_is_lov_desc_attach(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    logical*            verdict     /**< (O) whether the property is attached to the value description of the LOV */
    );

extern PROPERTY_API int PROPDESC_ask_lov_attach_parent_number(
    tag_t               prop_desc_tag,   /**< (I) The tag of the property descriptor */
    int*                n_parent    /**< (O) The parent number for lov-property attachment if found */
    );

extern PROPERTY_API int PROPDESC_ask_lov_interdependents(
    tag_t               prop_tag,   /**< (I) */
    tag_t*              lov_tag,    /**< (O) */
    int*                n_props,   /**< (O)  number of interdependent property descriptors*/
    tag_t**             props,     /**< (OF) n_props interdependent property descriptors*/
    int**               orders,    /**< (OF) n_props orders for each interdepenent LOV property attachment*/
    int**               n_parents, /**< (OF) n_props n_parent for each interdepenent LOV property attachment*/
    logical**           descAttaches /**< (OF) n_props descAttach flag for each interdepenent LOV property attachment*/
    );

extern PROPERTY_API int PROPDESC_is_copyfromoriginal(
    tag_t               propDescTag,   /**< (I) */
    logical*            isCopyFromOriginal    /**< (O) */
    );

/**
    Retrieves the applicable enumerated validation status for each input property:
    #PROP_valid_id , #PROP_invalid_id , #PROP_override_id , #PROP_duplicate_id .

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_null_input_not_allowed if a null input tag is received
    <li>#PROP_invalid_prop_type if the input property type is invalid
    </ul>
*/
extern PROPERTY_API int PROPDESC_validate_values(
    int                 num_of_prop_desc_tags, /**< (I) Number of property descriptors */
    tag_t*              prop_desc_tags,        /**< (I) Corresponding property descriptor tags */
    tag_t               oprn_input_tag,        /**< (I) Operation input object */
    int                 operation_type,        /**< (I) For future use, pass -1 for now */
    logical*            is_unique,             /**< (O) If the given input makes up unique MFK */
    PROP_values_stat_t** values_status         /**< (OF) num_of_prop_desc_tags Validation status list for input properties */
    );

/**
    Determines if a property is attached with any of static string LOVs.
*/
extern PROPERTY_API int PROPDESC_is_lov_localizable(
    tag_t               propDescTag,     /**< (I) */
    logical*            isLOVLocalizable /**< (O) */
    );

/**
    Retrieves the auto-assign information such as naming rules for a property of the given type.
    <br>If the property is item_revision_id and a revision naming rule is attached to it then no patterns are returned.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_error_autogenerate if invalid values are provided as input.
    <li>#NR_invalid_rule_suffix  if an invalid value is provided as rule suffix.
    <li>#PROP_not_autoassignable if the given property is not auto assignable.
    </ul>
*/
extern PROPERTY_API int PROPDESC_get_auto_assign_info(
    tag_t               prop_desc_tag,       /**< (I)  The tag of the property descriptor for which the auto assign information is requested */
    char*               rule_suffix,         /**< (I)  The string that determines whether baseline action is performed. 'PDR' is passed in case of Baseline action and an empty string in all other cases */
    logical*            is_autoassignable,   /**< (O)  The auto assign flag */
    int*                n_patterns,          /**< (O)  number of Patterns the Naming Rule contains */
    char***             pattern_strings,     /**< (OF) n_patterns Pattern string for each pattern defined for Naming Rule. This string array is packed and should be freed by caller by calling SM_free or MEM_free. */
    logical**           has_counter,         /**< (OF) n_patterns Specifies if each pattern has a counter. */
    char**              last_selected_pattern/**< (OF) The pattern that is previously selected for the given type, property combination */
    );

/**
    Retrieves the revision naming rule information attached to the given type.
    <br>If there is no revision naming rule attached but a Naming Rule is attached to item_revision_id then the revision naming rule is returned as null.
    <br>If Naming Rule is also not attached then the parent type revision naming rule is returned.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITEM_invalid_object        if the item revision tag is invalid.
    <li>#NR_invalid_prop_for_rev_nr if an invalid property is used for querying the Revision Naming Rule information.
    </ul>
*/
extern PROPERTY_API int PROPDESC_get_next_rev_options(
    tag_t               prop_desc_tag,       /**< (I)  The tag of the property descriptor for which the Revision Naming Rule information is requested */
    tag_t               item_rev_tag,        /**< (I)  The tag of the Item Revision for which the Revision Naming Rule information is requested. NULLTAG should be passed in case of new Item creation */
    int*                n_formats,           /**< (O)  number Revision Naming Rule formats which is always 3(initial, secondary, supplemental). 0 if no revision naming rule is attached */
    int**               rev_formats,         /**< (OF) n_formats Revision format for each Revision Naming Rule format of initial, secondary, supplemental revisions in the same order.If no format is defined then 0 is returned. */
    char***             rev_options,         /**< (OF) n_formats Revision option for each next avilable revision ID of initial, secondary, supplemental revisions in the same order. An empty string is returned if the revision type is not applicable. This string array is packed and should be freed by caller by calling SM_free or MEM_free */
    char***             rev_descs,           /**< (OF) n_formats Revision description for each revision type description of initial, secondary, supplemental revisions in the same order. An empty string is returned if the revision description is not defined. This string array is packed and should be freed by caller by calling SM_free or MEM_free */
    char**              excluded_letters     /**< (OF) The excluded letters that are not to be used in revision Id�s */
    );

/**
    Retrieves the next ID based on the User Exits or Naming rules.
    <br>If there is a Customer User Exit defined for a property then it is given priority over the Naming rule.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_source_object_missing if an invalid source tag is provided.
    <li>#NR_invalid_rule_suffix     if an invalid values is provided as rule suffix.
    <li>#PROP_error_autogenerate    if invalid values are provided as input.
    <li>#PROP_not_autoassignable    if the given property is not auto assignable.
    </ul>
*/
extern PROPERTY_API int PROPDESC_generate_next_values(
    int                                    n_prop_desc_tags,       /**< (I)  The number of the property descriptor tags whose values are to be generated */
    tag_t*                                 prop_desc_tags,         /**< (I)  Property descriptor tags whose values are to be generated */
    char**                                 pattern_strings,        /**< (I)  Pattern strings selected for each respective property in prop_desc_tags. Empty string if no pattern is selected */
    char*                                  rule_suffix,            /**< (I)  The string that determines whether baseline action is performed. 'PDR' is passed in case of Baseline action and an empty string in all other cases */
    char*                                  basis_name,             /**< (I)  A string that is passed from the application to form the basis of the Dataset, Form, Folder  name . This input is only required  during  Dataset, Form, Folder  creation and save as operation . If basisName is not specified then the Dataset, Form, Folder  name is generated based on its parent object */
    tag_t                                  operation_in_tag,       /**< (I)  The operation input tag */
    tag_t                                  source_tag,             /**< (I)  The object that is being Revised/SaveAs or the parent object during  Dataset, Form, Folder creation.It is optional in case of  Dataset, Form, Folder creation */
    tag_t                                  relation_type,          /**< (I)  The relationship type between the  dataset and its owning Item revision.This input is only required  during Dataset creation and save as . This may not be specified if the relationship type is not known */
    logical**                              is_modifiable_flags,    /**< (OF) n_prop_desc_tags For each property in prop_desc_tags specifies if the user can modify the generated value in the user Interface */
    char***                                next_values,            /**< (OF) n_prop_desc_tags Next value for each property in prop_desc_tags containing the value generated based on User Exit or Naming Rule configured on the property */
    int**                                  error_codes             /**< (OF) n_prop_desc_tags Error code for each property in prop_desc_tags containing the error encountered during the auto generation of its value */
    );

/**
    Generates the next IDs in bulk based on the User Exits or Naming rules.
    <br/>If a Customer User Exit defined for a property, it is given priority over the Naming rule.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor    if @p prop_desc is #NULLTAG or an invalid property descriptor.
    <li>#NR_invalid_qunatity_value  if @p quantity is 0.
    <li>#NR_invalid_rule_suffix     if @p basis_name is @c "itemrevision_id" and @p rule_suffix is neither @c "PDR" nor an empty string.
    <li>#PROP_error_autogenerate    if @p pattern is null pointer or if @p rule_suffix is @c "PDR" but @p basis_name is not @c "itemrevision_id".
    <li>#PROP_not_autoassignable    if no Naming Rule is assigned to the property represented by @p prop_desc.
    </ul>
*/
extern PROPERTY_API int PROPDESC_generate_next_values_in_bulk(
    const tag_t                                     prop_desc,              /**< (I)  The property descriptor tag whose value to be generated */
    const unsigned int                              quantity,               /**< (I)  Number of ID's of the specified type to be created */
    const char*                                     pattern,                /**< (I)  Pattern  selected for each respective property in @p prop_desc. 
                                                                                <br/>If an empty string is provided, no pattern is selected. */
    const char*                                     rule_suffix,            /**< (I)  The string that determines whether baseline action is performed. 'PDR' is passed in case of Baseline action and an empty string in all other cases */
    const char*                                     basis_name,             /**< (I)  A string that is passed from the application to form the basis of the Dataset, Form, Folder  name . This input is only required  during  Dataset, Form, Folder  creation and save as operation . If basisName is not specified then the Dataset, Form, Folder  name is generated based on its parent object */
    const tag_t                                     operation_input,        /**< (I)  The operation input. This can be #NULLTAG or obtained through #TCTYPE_construct_create_input.
                                                                                 <br/>At the current time, only the creation is supported. If an non-creation value is provided, no error is returned but no values are generated. */
    const tag_t                                     source,                 /**< (I)  The object being Revised/Saved As or the parent object during the creation of a Dataset, Form or Folder.
                                                                                 <br/>It is optional in case of the creation of a Dataset, Form or Folder. */                                                                            
    const tag_t                                     relation_type,          /**< (I)  The relationship type between the Dataset and its owning Item revision. 
                                                                                 <br/>This input is only required during Dataset creation and the Save As operation.
                                                                                 <br/>This may not be specified if the relationship type is not known. */                                                                            
    logical*                                        is_modifiable,          /**< (O)  The value of the "is_modifiable" flag for @p prop_desc, which specifies if the user can modify the generated value in the user interface. */
    char***                                         next_values             /**< (OF) quantity Generated values based on the User Exit or Naming Rule configured for the property represented by @p prop_desc.
                                                                                 <br/>This array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
);

/**
    Retrieves the next ID based on the User Exits, or Naming Rules, or using the Context based string.
    <ul>
    <li>If a context based string is provided, the ID is generated using the dynamic Naming Rule pattern.
        <br/>Currently, the context based ID generation does not support any User Exits.
    <br/>The input pattern containing dynamic characters (U, u, D) is required to generate the context based ID. It can not be NULL or empty.</li>
    <li>If no context string is provided, the ID is generated using the Naming Rule or the user exists.</li>
    <li>If a Customer User Exit is defined for the property, it is given priority over the Naming Rule.</li>
    </ul>

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_source_object_missing if an invalid source tag is provided.
    <li>#NR_invalid_rule_suffix     if an invalid values is provided as rule suffix.
    <li>#PROP_error_autogenerate    if invalid values are provided as input.
    <li>#PROP_not_autoassignable    if the given property is not auto assignable.
    <li>#NR_invalid_context_pattern_length if the provided context name is invalid, because its length must match the dynamic string length in the pattern
    <li>#NR_invalid_context_pattern_char if the provided context name is invalid, because its case must match the one of the dynamic characters (U/u/D) in the pattern
    </ul>
*/
extern PROPERTY_API int PROPDESC_generate_next_values_for_properties(
    int                                    n_prop_desc_tags,       /**< (I)  The number of the property descriptor tags whose values are to be generated */
    const tag_t*                           prop_desc_tags,         /**< (I)  Property descriptor tags whose values are to be generated */
    const char**                           pattern_strings,        /**< (I)  Pattern strings selected for each respective property in prop_desc_tags. Empty string if no pattern is selected */
    const int*                             n_context_names,        /**< (I)  n_prop_desc_tags Number of user provided context names for each property */
    const char***                          context_names,          /**< (I)  n_context_names Array of context names used to generate ID for each property. */
    const char*                            rule_suffix,            /**< (I)  The string that determines whether baseline action is performed. 'PDR' is passed in case of Baseline action and an empty string in all other cases */
    const char*                            basis_name,             /**< (I)  A string that is passed from the application to form the basis of the Dataset, Form, Folder  name . This input is only required  during  Dataset, Form, Folder  creation and save as operation . If basisName is not specified then the Dataset, Form, Folder  name is generated based on its parent object */
    tag_t                                  operation_in_tag,       /**< (I)  The operation input tag */
    tag_t                                  source_tag,             /**< (I)  The object that is being Revised/SaveAs or the parent object during  Dataset, Form, Folder creation.It is optional in case of  Dataset, Form, Folder creation */
    tag_t                                  relation_type,          /**< (I)  The relationship type between the  dataset and its owning Item revision.This input is only required  during Dataset creation and save as . This may not be specified if the relationship type is not known */
    logical**                              is_modifiable_flags,    /**< (OF) n_prop_desc_tags For each property in prop_desc_tags specifies if the user can modify the generated value in the user Interface */
    char***                                next_values,            /**< (OF) n_prop_desc_tags Next value for each property in prop_desc_tags containing the value generated based on User Exit or Naming Rule configured on the property 
                                                                            <br> This array is packed, which means that only the container needs to be freed through a call to #MEM_free.*/
    int**                                  error_codes             /**< (OF) n_prop_desc_tags Error code for each property in prop_desc_tags containing the error encountered during the auto generation of its value */
    );

/**
    Retrieves a sequential number of next IDs values, as would be generated by a bulk creation, for a particular pattern in
    the Naming Rule attached to the given property of a business object.

    This ITK is a generalized ITK for generating next IDs in case of :
    <ul>
    <li>next item IDs
    <li>next revision IDs
    <li>next revision IDs generated from the pattern in the alternate rule
    <li>next alternate IDs generated from the pattern in rule
    <li>next dataset IDs
    <li>next dataset revision IDs
    <li>for any property's next values on a type.
    </ul>

   This ITK generates the next IDs corresponding to the input pattern of a Naming Rule that is attached to the property.

   If no input pattern is matched, the next IDs will be generated using the first pattern of the Naming Rule.
   <br>If the next_ids array is returned as NULL, either no Naming Rule is defined, or a Naming Rule without any counters is
   defined for the given input.

   When the input parameter "type_name" is empty, the input parameters "preferred_type_name", "default_type_name" and
   "parent_tag" are used for next alternate IDs generation. If "rule_suffix" and "base_rev_id" parameters are supplied,
   the next revision IDs are generated from the pattern in the alternate rule. If "ds_id" parameter is supplied and the
   input property is "rev", the next available ID in the Naming Rule counter is set from latest revision id of the "ds_id" dataset.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#NR_autogen_not_set, if no counters are set with the given Naming Rule.
   <li>#NR_no_counters_found, if no counters are found with the given Naming Rule.
   </ul>
*/
extern PROPERTY_API int PROPDESC_next_values_in_bulk(
    const char* type_name,           /**< (I) Teamcenter internal type name, i.e. "Item" */
    int quantity,                    /**< (I) Number of ID of the specified type to be created */
    const char* prop_name,           /**< (I) Property internal name, i.e. "item_id", "item_revision_id", "object_name" */
    const tag_t item_tag,            /**< (I) The tag of the parent type used in next alternate revision ID*/
    const char* ds_id,               /**< (I) Dataset ID to be used for resetting next available ID */
    const char* preferred_type_name, /**< (I) Preferred type name used in case of next alternate ID */
    const char* default_type_name,   /**< (I) Default type name used in case of next alternate ID */
    const tag_t parent_tag,          /**< (I) Used in case of next alternate ID */
    const char* rule_suffix,         /**< (I) Used in case of next revision ID generated from the pattern in the alternate rule */
    const char* base_rev_id,         /**< (I) Used in case of next revision ID generated from the pattern in the alternate rule */
    const char* pattern,             /**< (I) The input Naming Rule Pattern for which the next id is to be generated */
    char***     next_ids             /**< (OF) quantity Array of generated next IDs */
    );

/**
    For a given object and property, retrieves the source object from which the property is derived.

    For example, for a given runtime line item and its property, this ITK retrieves the underlying object (e.g. Item) whose the line�s property is derived.

    This ITK supports the following property types :
    <ul>
    <li>Configured Runtime Properties
    <li>Compound Properties
    </ul>
    For any other property type, this ITK will simply set the source object as the input object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property tag is invalid
    <li>#ITK_internal_error      if the object tag is invalid
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_source_object(
    tag_t               object_tag,    /**< (I) The tag of the object */
    tag_t               prop_desc_tag,      /**< (I) The tag of the property descriptor */
    tag_t*              source_obj_tag /**< (O) The tag of the source object */
    );

/**
    Retrieves the base property descriptor (i.e. the top most ancestor) of the given property.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property tag is invalid
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_base_descriptor(
    tag_t               prop_desc_tag,      /**< (I) The tag of the property descriptor */
    tag_t*              base_prop_tag, /**< (O) The tag of the base property descriptor */
    tag_t*              base_type_tag  /**< (O) The tag of the type of the base property descriptor */
    );

/**
    For a given property, retrieves the display values of the attached LOV.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property tag is invalid
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_display_values_from_LOV_attachments(
    tag_t               prop_desc_tag,      /**< (I) The tag of the property descriptor */
    int                 n_values,      /**< (I) Number of requested values */
    const char**        values,        /**< (I) n_values Values internal names */
    char***             display_values /**< (OF) n_values Display values. <br>This string array is packed and must be freed using #MEM_free */
    );

/**
    Asks the field type that the property descriptor defines. It is useful for operation descriptor property.
    <br>
    The field type could be either of the following:
    <ul>
    <li>PROP_field_unknown</li>
    <li>PROP_simple_property</li>
    <li>PROP_compound_object</li>
    <li>PROP_compound_relation</li>
    </ul>

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property tag is invalid
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_field_type(
    tag_t               prop_desc_tag,         /**< (I) The tag of the property descriptor */
    PROP_field_type_t*  field_type        /**< (O) The field type of the property descriptor */
    );

/**
    Asks the compound object type that the compound property descriptor defines.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property tag is invalid
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_compound_object_type(
    tag_t               prop_desc_tag,            /**< (I) The tag of the property descriptor */
    tag_t*              compound_type_tag    /**< (O) The tag of the compound type */
    );

/**
    Retrieves the immediate parent property descriptor of the given property.
    <br>Immediate parent is the material or source from which property descriptor is derived.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property tag is invalid
    <li>#NULLTAG if the given property is a base property (i.e. the top most ancestor).
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_parent_descriptor(
    tag_t               prop_desc_tag,        /**< (I) The tag of the property descriptor */
    tag_t*              parent_prop_tag, /**< (O) The property descriptor tag for the immediate parent */
    tag_t*              parent_type_tag  /**< (O) The type of the property descriptor tag for the immediate parent */
    );

/**
    Retrieves the reference type as defined for a reference property.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_reference_type(
    tag_t property_descriptor,            /**< (I) The property descriptor for the reference property. */
    tag_t *ref_type                       /**< (O) The reference type. */
    );

/**
    Retrieves the attached ID Generation Rule for a given property descriptor. 
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor if the property descriptor @p pd is invalid. 
    </ul>
*/
extern PROPERTY_API int PROPDESC_get_id_generation_rule_info(
    tag_t prop_desc_tag,                /**< (I) The tag of the property descriptor. */
    tag_t* idgen_rule        /**< (O) The tag of ID Generation Rule associated with the given property descriptor. */
    );
    
/**
    Retrieves the referenced property values for a given referenced property from a list of objects of the same type.
    @note If the execution fails for one of the objects, the processing continues for the remaining objects.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_not_found if the given property descriptor tag is invalid.
    <li>#PROP_not_found if input objects are not of same type.
    <li>Potentially other errors
    </ul>
*/    
extern PROPERTY_API int PROPDESC_get_referenced_properties_in_bulk(
    const unsigned int n_objects,                                         /**< (I) Number of input objects */
    const tag_t* objects,                                                 /**< (I) n_objects Input objects */
    const char* property_name,                                            /**< (I) Property internal name */
    int** n_values,                                                       /**< (OF) n_objects The number of values for the property for each object. */
    tag_t*** values                                                       /**< (OF) n_values The values. <br/>The returned array is not packed, which means that both the elements and the container need to be deallocated using #MEM_free. */
    );    

/**
Retrieves the value of @c isModifiable property constant  value for a given property.
@returns
<ul>
<li>#ITK_ok on success
<li>#PROP_not_found if @p property_descriptor is invalid.
</ul>
*/
extern PROPERTY_API int PROPDESC_is_modifiable(
    tag_t               property_descriptor,     /**< (I) The property descriptor.*/
    logical*            modifiable              /**<  (O) Indicates if @p property_descriptor is modifiable.*/
);

/**
Retrieves the value of the @c isRequired property constant for a given property.
@returns
<ul>
<li>#ITK_ok on success
<li>#PROP_not_found if @p prop_desc is invalid.
</ul>
*/
extern PROPERTY_API int PROPDESC_is_required(
    tag_t               property_descriptor,     /**< (I) The property descriptor. */
    logical*            is_required             /**<  (O) Indicates if @p property_descriptor is required.*/
);

/**
Retrieves the value of the @c isDisplayable property constant for a given property.
@returns
<ul>
<li>#ITK_ok on success
<li>#PROP_not_found if @p property_descriptor is invalid.
</ul>
*/
extern PROPERTY_API int PROPDESC_is_displayable(
tag_t               property_descriptor,          /**< (I) The property descriptor. */
logical*            is_displayable               /**<  (O) Indicates if @p property_descriptor is displayable.*/
);

/**
    Retrieves the source object for @p input_object using the property derived from @p prop_desc.
    <br/>Retrieves the underlying object for the derived line property.

    @note This API does not call POM_refresh_required. If refresh is required please use, #PROPDESC_ask_source_object

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_descriptor or #CXPOM_invalid_tag  if @p prop_desc is invalid
    <li>#CXPOM_object_deleted if @p input_object is deleted
    </ul>
*/
extern PROPERTY_API int PROPDESC_ask_source_object_no_refresh(
    tag_t               input_object,        /**< (I) The object for which source object needs to be retrieved. */
    tag_t               prop_desc,           /**< (I) The property descriptor. */
    tag_t*              source_obj           /**< (O) The source object */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <property/libproperty_undef.h>

#endif
