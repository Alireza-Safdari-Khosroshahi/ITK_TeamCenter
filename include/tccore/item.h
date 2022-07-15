/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to item data manipulation. For other
    related interfaces for say, archive, backup and change control, please
    review the related topics in the users guide and review the appropriate
    header files.

    As an example, if an ECO or other such object is attached to the item/rev
    you can retrive it using the appropriate relationship types as defined
    by the application/Teamcenter Engineering module responsible for that object.
    When you get the tag, pass it to the desired functions as defined by the application.

    Developers Note:
    An error will be returned if non-Item tags are passed into ITEM ITKs.
*/

/*  */

#ifndef ITEM_H
#define ITEM_H

#include <fclasses/tc_basic.h>
#include <tccore/workspaceobject.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup ITEM Item
    @ingroup TC
    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value         </td><td>Description                                          <td></tr>
    <tr><td>#ITEM_cant_change_uom</td><td>Item's Unit Of Measure (UOM) is not modifiable by you.
                                        This is the basic error returned on failure.
                                        Examination of the error stack will show you one of the following errors:
                                        <P>
                                        #ITEM_used_in_structure - Unit of measure cannot be modified as the Item is used
                                                                  within a structure.<br>
                                        #ITEM_rev_is_released - Unit of measure cannot be modified as a revision of the
                                                                Item has been released.        <td></tr>
    <tr><td>#ITEM_duplicate_rev  </td><td>Item already has a revision with the rev ID you gave.<td></tr>
    </table>
    @{
*/

#define ITEM_item_class_name_c          "Item"
#define ITEM_rev_class_name_c           "ItemRevision"

#define ITEM_ITEM_ID_PROP                "item_id"

#define ITEM_revise_operation           "Revise"
#define ITEM_saveas_operation           "SaveAs"
#define ITEM_cm0derivechange_operation  "Derive" /**< cm0DeriveChange used to display "Derive" Operation Type for selection in Add Deep Copy Rule dialog */

#define ITEM_copy_as_object                 "copy_as_object"
#define ITEM_copy_as_reference              "copy_as_reference"
#define ITEM_relate_to_latest               "relate_to_latest"
#define ITEM_revise_and_relate_to_latest    "revise_and_relate_to_latest"
#define ITEM_no_copy                        "no_copy"
#define ITEM_select                         "select"
#define ITEM_system_copy                    "system_copy"

#define ITEM_id_size_c                  128
#define ITEM_name_size_c                WSO_name_size_c
#define ITEM_type_size_c                32
#define ITEM_desc_size_c                240

#define PREFIX_sv_item                  "Idx0"

typedef enum ITEM_attachment_type_e
{
    ITEM_item_master_atth,

    ITEM_manifestation_atth,
    ITEM_requirement_atth,
    ITEM_specification_atth,
    ITEM_reference_atth,

    ITEM_master_data_atth,

    ITEM_bom_view_atth,  /**< Reserved for future enhancement. */
    ITEM_bvr_atth,       /**< Reserved for future enhancement. */
    ITEM_revision_atth,  /**< Reserved for future enhancement. */

    ITEM_unknown_atth
} ITEM_attachment_type_t;

typedef struct ITEM_attached_object_s
{
    tag_t                  attachment;
    ITEM_attachment_type_t attachment_type;
} ITEM_attached_object_t;

typedef struct ITEM_deepcopy_info_s
{
    tag_t component;             /**< Tag of the other side object. */
    int action;                  /**< Deep-copy action.
                                        <br/>Valid values are:
                                        <table>
                                        <tr><td>CopyAsObjectType</td><td>0</td></tr>
                                        <tr><td>CopyAsRefType</td><td>1</td></tr>
                                        <tr><td>RelateToLatestType</td><td>2</td></tr>
                                        <tr><td>ReviseAndRelateToLatestType</td><td>3</td></tr>
                                        <tr><td>DontCopyType</td><td>4</td></tr>
                                        <tr><td>Select</td><td>5</td></tr>
                                        <tr><td>SystemCopy</td><td>6</td></tr>
                                        <tr><td>ReviseObjectType</td><td>7</td></tr>
                                        <tr><td>CopyAsReferenceOrReferenceNewCopyType</td><td>8</td></tr>
                                        <tr><td>CopyAsObjectOrReferenceNewCopyType</td><td>9</td></tr>
                                        </table> */
    char* objName;               /**< New name for the copy object */
    char* relation;              /**< Name of the relation type. */
    logical is_target_primary;   /**< Whether the target BO is primary object */
    logical is_required;         /**< Whether the deep copy action is required or is overridable in client UI */
    logical copy_relations;      /**< Whether to carry forward the properties on the relation */
}  ITEM_deepcopy_info_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Initializes the Item module. It must be called before calling any other ITEM functions.
*/
extern TCCORE_API int ITEM_init_module();

extern TCCORE_API int ITEM_exit_module();

/**
    @name Item Functions
    @{
*/

/**
   Creates a new Item with the given name and identification string.

   @note For any other type than null, ensure that the type has been defined at the site (e.g. by using the @c install_types utility).

   @note This itk will not save the object: #AOM_save_with_extensions needs to be called separately to save the object.

   @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_create_item(
    const char*         item_id,    /**< (I) Item identification number. No two Items can have the same identification string.
                                        A null is allowed. If null, the system will automatically generate an Item ID. */
    const char*         item_name,  /**< (I) Item name. A common name or short description of the Item.
                                     <br/>It will also be used for as the revision's name. */
    const char*         item_type,  /**< (I) Specifies the Item type.
                                       <br/>If @c null or empty, the default type is @c Item. */
    const char*         rev_id,     /**< (I) Identification string (revision ID) of the Item Revision being created.
                                        A null is allowed. If null, the system will automatically generate a revision ID. */
    tag_t*              item,       /**< (O) Tag for identifying the Item in the current program */
    tag_t*              rev         /**< (O) Tag for identifying the Item Revision in the current program */
    );


/**
    Creates an Item in a fashion similar to #ITEM_create_item, except that pre-populated Item Master and
    Item Revision Master forms can be used.
    <br/>These forms will be used for the Item and Item Revision. They can also be #NULLTAG.

    @note This itk will not save the object: #AOM_save_with_extensions needs to be called separately to save the object.

    @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_create_item_with_masters(
    const char* item_id,                  /**< (I) Item identification number. No two Items can have the same identification
                                                   string. A null is allowed. If null, the system will automatically
                                                   generate an Item ID */
    const char* item_name,                /**< (I) Item name. A common name or short description of the Item */
    const char* item_type,                /**< (I) A null is allowed for this argument. It can be used to specify a defined
                                                   Item type */
    const char* rev_id,                   /**< (I) Identification string (revision ID) of the Item Revision being created.
                                                   A null is allowed. If null, the system will automatically generate a
                                                   revision ID */
    tag_t       item_master_form,         /**< (I) Item Master form tag that will be used for the created item. Can be
                                                   NULLTAG */
    tag_t       item_rev_master_form,     /**< (I) Item Revision Master form tag that will be used for the created item
                                                   revision. Can be NULLTAG */
    tag_t*      item,                     /**< (O) Tag for identifying the Item in the current program */
    tag_t*      rev                       /**< (O) Tag for identifying the Item Revision in the current program */
    );

/**
   Creates an Item with the specified attributes.

   <br/>After validating the input properties this ITK sets the Attribute Names
   with the corresponding Attribute values.

   @note This itk will not save the object: #AOM_save_with_extensions needs to be called separately to save the object.

   @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_create_item2 (
    const char *type_name,             /**< (I) Type of Item to be created. */
    int        n_attributes,           /**< (I) Number of input attributes. */
    char       **attribute_names,      /**< (I) n_attributes Names of input attributes.  */
    char       **attribute_values,     /**< (I) n_attributes Values for the input attributes. */
    const char *revision_id,           /**< (I) ID for the revision. */
    tag_t      *item,                  /**< (O) The created Item. */
    tag_t      *rev                    /**< (O) The created Item Revision. */
    );


/**
   Creates an Item in a fashion similar to #ITEM_create_item2 but with pre-populated Item Master and Item Revision Master
   forms.

   <br/>These forms will be used for the created Item and Item Revision. If the value for Item Master and Item Revision
   Master forms are NULL then this function creates an Item similarly to #ITEM_create_item2.

   @note This itk will not save the object: #AOM_save_with_extensions needs to be called separately to save the object.

   @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_create_item_with_masters2(
    const char *type_name,            /**< (I) Type of Item to be created */
    int        n_attributes,          /**< (I) Number of input attributes */
    char       **attribute_names,     /**< (I) n_attributes Names of input attributes */
    char       **attribute_values,    /**< (I) n_attributes Values for the input attributes */
    const char *revision_id,          /**< (I) ID for the revision */
    tag_t      item_master,           /**< (I) Item Master form that will be used for the created item */
    tag_t      item_rev_master,       /**< (I) Item Rev Master form that will be used for the created Item Rev */
    tag_t      *item,                 /**< (O) The created item. */
    tag_t      *rev                   /**< (O) The created item revision. */
    );

/**
    Saves an Item in the database.
    <br/>The ITK will check for Multi Field Key and Unique attribute violations before saving the Item.

    @returns
    <ul>
    <li>#ITK_ok on success</li>
    <li>#ITEM_duplicate_id if any of the following has happened:
            <ul>
            <li>if @p item violates Multi-field Key validation. The second error on the error stack will be #TCCORE_object_violates_mfk_property
            <li>if @p item violates Multi-field Key and Unique attribute validations have failed. The second error on the error stack will be #TCCORE_inst_violates_unique_property_and_mfk_property
            <li>if @p item violates Unique attribute validation. The second error on the error stack will be #TCCORE_inst_violates_unique_property.
            </ul>
    </li>
    </ul>
*/
extern TCCORE_API int ITEM_save_item(
    tag_t               item    /**< (I) Tag for identifying the Item to be saved */
    );

/**
    Deletes an Item from the database.
    <br/>Additionally, it will delete all Item revisions and remove all attachments.
    <br/>The attached objects will not be deleted, except for the Item and revision master forms.
*/
extern TCCORE_API int ITEM_delete_item(
    tag_t               item    /**< (I) Tag for identifying the Item in the current program */
    );

/**
    Retrieves the list of all the Items in the database.
*/
extern TCCORE_API int ITEM_extent  (
    int*                count,      /**< (O) Total number of Items in the database */
    tag_t**             item_list   /**< (OF) count List of tags for all the Items in the database */
    );


/**
    Retrieves an Item from the value of its Item ID ("item_id") or Part Identifier ("fnd0PartIdentifier") property.
    <br/>The search can be done using:
    <ul>
    <li>the value of the property Item ID ("item_id"):
    <ul><li>if the value of the preference "TC_MFK_DEFAULT_DOMAIN" is specified, the search is executed against the domain specified in the preference. By default,
    the search is executed against the "Item" class.
    @code
        Item  MultiFieldKey=Item{item_id}
          |
          |____ ChItem01  MultiFieldKey=ChItem01{item_id,attr01}
          |         |
          |         |____ ChItem0101  MultiFieldKey=ChItem01{item_id,attr01}
          |
          |____ ChItem02  MultiFieldKey=Item{item_id}
          |         |
          |         |____ ChItem0201  MultiFieldKey=Item{item_id}
          |
          |____ ChItem03  MultiFieldKey=ChItem01{item_id,attr01}
                    |
                    |____ ChItem0301  MultiFieldKey=ChItem01{item_id,attr01}
    @endcode
    For example, if the value of the preference "TC_MFK_DEFAULT_DOMAIN" is set to "ChItem01", the Item search for the input Item ID will be restricted to the Item types,
    "ChItem01", "ChItem0101", "ChItem03" and "ChItem0301".</li>
    <li>If the value of the preference "TC_MFK_DEFAULT_DOMAIN" is set to "Item", the Item search for the input Item ID will be restricted to the Item types,
    "Item", "ChItem02" and "ChItem0201".</li></ul>
    <br/></li>
    <li>the value of its property Part Identifier ("fnd0PartIdentifier").</li>
    </ul>

    @note To find Items using MultiField keys, use #ITEM_find_items_by_key_attributes instead.
    @note To find Item Revisions using MultiField keys and Revision ID, use #ITEM_find_item_revs_by_key_attributes instead.
    <br/><br/>In both cases, the search is case insensitive and the value cannot contain any wild card.
    <br/>For searching using a specific context, use the #ITEM_find_item_in_idcontext function.

    @returns
    <ul>
    <li>#ITK_ok on success                  if no match is found, @p item will be #NULLTAG.
    <li>#ITEM_multiple_items_returned       if more than one match is found. In this case, use the #ITEM_find function.
    <li>#ITEM_duplicate_ids_found           if more than one match is found for the search executed on the "Item" class.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_item(
    const char*         search_id,        /**< (I) Either the ID ("item_id") or the Part Identifier ("fnd0PartIdentifier") of the Item to find */
    tag_t*              item              /**< (O) The matching Item */
    );


/**
    Searches the database for all Items with IDs that match the given string.
    <br/>Wildcards may be used. The search will always be case insensitive.
    <ul>
    <li>Id in Context = NO: Case insensitive search with wildcards in item_id.
    <li>Id in Context = YES: Case insensitive search with wildcards in item_id.
                        If you want to find in a single context, use new function #ITEM_find_in_idcontext.
                        Providing null tag as context tag, this function will find an item with given id in
                        all contexts as well as item_id.
    </ul>
*/
extern TCCORE_API int ITEM_find(
    const char*         item_id,    /**< (I) String to match IDs against */
    int*                n_items,    /**< (O) Number of matching Items found */
    tag_t**             item_tags   /**< (OF) n_items Array of tags of found Items */
    );


/**
    Searches the database for all Items and retrieves a list of Items identified by the
    given attribute name/value pairs. The attributes must be of the Item class, which are defined in the MultiFieldKey Constant.

    <br/>Additionally, the attribute "object_type" and its value carrying the Item type internal name can be input for a finer search.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_items_by_key_attributes(
    int             n_attributes,       /**< (I) Number of attributes */
    const char**    attribute_names,    /**< (I) n_attributes Attribute Names */
    const char**    attribute_values,   /**< (I) n_attributes Attribute Values */
    int*            n_items,            /**< (O) Number of matching Items found */
    tag_t**         items               /**< (OF) n_items The matching Items */
    );


/**
    Searches the database for all Items and retrieves a list of Items
    identified by the given string containing attribute-value pairs in the format @c attr_1=value1,attr_2=value2,...,attr_n=value_n

    <br/>The attributes must be of the Item class, which are defined in the MultiFieldKey
    Constant. For COTS Item, the default key attribute is "item_id". This attribute must be used as input to the ITK.
    However, other attributes can still be used as inputs as long as they are defined as MultiFieldKey attributes.

    <br/>Additionally, the attribute "object_type" and its value bearing the Item type internal name can be input for a finer search.

    <br/>The default delimiter and separator used in the attribute-value pairs are "," and "=". However,
    user can define own delimiter and separator using the preference "TC_KEY_STRING_DELIMITER_VALUES".

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITEM_illegal_parameter     if @p av_string is input with wrong format.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_items_by_string(
    const char*     av_string,      /**< (I) Delimited Item attribute-value pair string */
    int*            n_items,        /**< (O) Number of matching Items found */
    tag_t**         items           /**< (OF) n_items The matching Items */
    );


/**
    Searches the database for all Item Revisions and retrieves a list of Item Revisions
    identified by the given attribute name/value pairs. The attributes must be of the Item class, which are defined in the MultiFieldKey Constant.

    <br/>For COTS Item, the default key attribute is "item_id". This attribute must be used as input to
    the ITK. However, other attributes can still be used as inputs as long as they are defined as
    MultiFieldKey attributes.

    <br/>Additionally, the attribute "object_type" and its value bearing the Item type internal name can be input for a finer search.

    <br/>For more information, see Business Modeler IDE Guide -&gt; Creating business rules-&gt; Multifield keys.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_item_revs_by_key_attributes(
    int             n_attributes,           /**< (I) Number of attributes */
    const char**    attribute_names,        /**< (I) n_attributes Attribute Names */
    const char**    attribute_values,       /**< (I) n_attributes Attribute Values */
    const char*     revision_id,            /**< (I) Item Revision ID */
    int*            n_item_revisions,       /**< (O) Number of matching Item Revisions found */
    tag_t**         item_revisions          /**< (OF) n_item_revisions The matching Item Revisions */
    );


/**
    Searches the database for all Item Revisions and retrieves a list of Item Revisions
    identified by the given string containing attribute-value pairs in the format @c attr_1=value1,attr_2=value2,...,attr_n=value_n

    <br/>The attributes must be of the Item class, which are defined in the MultiFieldKey
    Constant. For COTS Item, the default key attribute is "item_id". This attribute must be used as input to the ITK.
    However, other attributes can still be used as inputs as long as they are defined as MultiFieldKey attributes.

    <br/>Additionally, the attribute "object_type" and its value bearing the Item type internal name can be input for a finer search.

    <br/>Also, the last attribute-value pair in the string must be: rev_id=&lt;Item Revision ID&gt;.

    <br/>The default delimiter and separator used in the attribute-value pairs are "," and "=". However,
    user can define own delimiter and separator using the preference "TC_KEY_STRING_DELIMITER_VALUES".

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITEM_illegal_parameter         if @p av_string is input with wrong format.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_item_revs_by_string(
    const char*     av_string,              /**< (I) Delimited Item attribute-value pair string */
    int*            n_item_revisions,       /**< (O) Number of matching Item Revisions found */
    tag_t**         item_revisions          /**< (OF) n_item_revisions The matching Item Revisions */
    );


/**
    Searches the database for all Item Revisions and retrieves a list of Item Revisions
    identified by the given string containing attribute-value pairs.

    <br/>The attributes must be of the Item class, which are defined in the MultiFieldKey
    Constant. For COTS Item, the default key attribute is "item_id". This attribute must be used
    as input to the ITK. However, other attributes can still be used as inputs as long as they
    are defined as MultiFieldKey attributes.

    <br/>Additionally, the attribute "object_type" and its value bearing the Item type internal name can be input for a finer search.

    <br/>The input parameter av_string contains delimited Item attribute-value pairs, and must be in
    the format @c attr_1=value1,attr_2=value2,...,attr_n=value_n

    <br/>The default delimiter and separator used in the attribute-value pairs are "," and "=". However,
    user can define own delimiter and separator using the preference "TC_KEY_STRING_DELIMITER_VALUES".

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITEM_illegal_parameter     if @p av_string is input with wrong format.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_item_revs_by_string_and_revid(
    const char*     av_string,          /**< (I) Delimited Item attribute-value pair string */
    const char*     revision_id,        /**< (I) Item Revision ID */
    int*            n_item_revisions,   /**< (O) Number of matching Item Revisions found */
    tag_t**         item_revisions      /**< (OF) n_item_revisions The matching Item Revisions */
    );


extern TCCORE_API int ITEM_exists(
    int n_attributes,                /**< (I) Number of attributes */
    const char** attribute_names,    /**< (I) n_attributes Attribute Names */
    const char** attribute_values,   /**< (I) n_attributes Attribute Values */
    logical *exists                  /**< (O) @c true if exists, @c false otherwise*/
    );


/**
    Checks if an internal type(e.g. "Item", "Part" etc.) with the input attribute/value pair is unique in a multifield key (MFK) domain
    corresponding to the specified internal type name.
    <br><br>This function:
    <ol>
    <li>Obtains the MFK domain for the provided internal type name (e.g. "Item").
    <li>For each provided internal attribute for the type (e.g. "item_id"), checks if the attribute value is unique in the MFK domain.
    <li>If all the attribute values are unique, the value of the output parameter "exists" is false. Otherwise, it is true.
    </ol>

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITEM_null_inputs_not_allowed when type_name is set to NULL.
    </ul>
    If any of the values provided to the parameters "type_name", "attribute_names", "attribute_values" are invalid,
    no error will be returned and the output parameter "exists" will be false.
*/
extern TCCORE_API int ITEM_exists_in_domain(
    const char*     type_name,          /**< (I) Internal type_name. It is used to find associated MFK domain. */
    const int       n_attributes,       /**< (I) Specifies the number of attributes (or properties) for the given type, for which the uniqueness will be checked. */
    const char**    attribute_names,    /**< (I) n_attributes Internal attribute (or property) names (e.g. "item_id", "object_name")*/
    const char**    attribute_values,   /**< (I) n_attributes Internal attribute (or property) Values. These values uniqueness will be checked in MFK domain. */
    logical*        exists              /**< (O) Status of the attributes values uniqueness. The returned value will be true if the value already exists in the MFK domain, false otherwise.*/
    );


extern TCCORE_API int ITEM_rev_get_key_string(
    tag_t item_revision_tag,            /**< (I) Tag of Item  Revision */
    char ** key_string                  /**< (OF) A delimited string representing the key attr/value pairs for the Item*/
    );


/**
   Retrieves a delimited string representing the key attr/value pairs for the item.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_wrong_class if the tag corresponds to an object of a wrong class.
   <li>#POM_invalid_tag if the input tag is invalid.
   </ul>
*/
extern TCCORE_API int ITEM_ask_key_string_for_item(
    tag_t item,        /**< (I) Tag of Item */
    char **key         /**< (OF) A delimited string representing the key attr/value pairs for the Item */
  );

/**
   Retrieves the latest revision of an Item, as determined by the creation date.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_invalid_tag if the input Item tag is invalid.
   </ul>
*/
extern TCCORE_API int ITEM_ask_latest_rev(
    tag_t               item,   /**< (I) Tag of an existing Item */
    tag_t*              rev     /**< (O) Tag of the latest revision of Item */
    );

/**
    Retrieves all the Item Revisions attached to a specified Item.
    <br/>The revisions are sorted by the Item Revision creation date.
*/
extern TCCORE_API int ITEM_list_all_revs(
    tag_t               item,       /**< (I) Tag of an existing Item */
    int*                count,      /**< (O) Total number of revisions of the Item */
    tag_t**             rev_list    /**< (OF) count Tag list of all the revisions of the Item */
    );

/**
    Retrieves all the BOM Views related to the Item.
*/
extern TCCORE_API int ITEM_list_bom_views(
    tag_t               item,       /**< (I) Tag of an existing Item */
    int*                count,      /**< (O) Number of bom view found for the Item */
    tag_t**             bv_list     /**< (OF) count Tag list of all the bom views for the Item */
    );




/**
    Creates a new Item based on an existing Item.
    The initial revision of the new Item is based on the specified revision of the existing Item.
*/
extern TCCORE_API int ITEM_copy_item(
    tag_t               rev,            /**< (I) Tag of an existing revision on which to base the new Item and its initial revision */
    const char*         new_item_id,    /**< (I) Identification string (ID) of the new Item. A null is allowed.
                                            If null, the system will automatically generate an Item ID. */
    const char*         new_rev_id,     /**< (I) Identification string (revision ID) the initial revision of the new Item.
                                            A null is allowed. If null, the system will automatically generate a new revision ID. */
    tag_t*              new_item,       /**< (O) Tag of the new Item */
    tag_t*              new_rev         /**< (O) Tag of the initial revision of the new Item */
    );

/**
    Creates a new Item based on an existing Item. Similar to #ITEM_copy_item, except that you can pass pre-populated
    Item Master and Item Revision Master forms. These forms will be used for the Item and Item Revision.
    They can be #NULLTAG.

    The initial revision of the new Item is based on the specified revision of the existing Item.
*/
extern TCCORE_API int ITEM_copy_item_with_masters(
    tag_t       rev,                      /**< (I) Tag of an existing revision on which to base the new Item and its initial revision */
    const char* new_item_id,              /**< (I) Identification string (ID) of the new Item. A null is allowed.
                                            If null, the system will automatically generate an Item ID. */
    const char* new_rev_id,               /**< (I) Identification string (revision ID) the initial revision of the new Item.
                                            A null is allowed. If null, the system will automatically generate a new revision ID. */
    tag_t       item_master_form_tag,     /**< (I) Item Master form tag that will be used for the created item. Can be
                                                   NULLTAG */
    tag_t       item_rev_master_form_tag, /**< (I) Item Revision Master form tag that will be used for the created item
                                                   revision. Can be NULLTAG */
    tag_t*      new_item,                 /**< (O) Tag of the new Item */
    tag_t*      new_rev                   /**< (O) Tag of the initial revision of the new Item */
    );


/**
    Enquires the unit of measure in which quantities of this Item must be expressed.
    Units of measure are objects defined for the Teamcenter Engineering site by the system administrator.

    By default, Items have no Unit of Measure (UOM). In this case this function will give #NULLTAG.
    This implies that quantities of such Items are expressed in terms of "Each" or "Pieces".
    In other words they refer to a discrete number of component parts.
    In PSE if no specific quantity value is associated with the use of such Items,
    the default quantity is assumed to be "1 component".
*/
extern TCCORE_API int ITEM_ask_unit_of_measure(
    tag_t               item,   /**< (I) Tag of an Item */
    tag_t*              uom     /**< (O) Returns the tag of the unit of measure assigned to this Item (may be #NULLTAG) */
    );

/**
    Sets the unit of measure in which quantities of this Item must be expressed.
    Units of measure are objects defined for the Teamcenter Engineering site by the system administrator.

    By default, Items have no UOM. In this case this function will give #NULLTAG.
    This implies that quantities of such Items are expressed in terms of "Each" or "Pieces".
    In other words they refer to a discrete number of component parts.
    In PSE if no specific quantity value is associated with the use of such Items,
    the default quantity is assumed to be "1 component".
*/
extern TCCORE_API int ITEM_set_unit_of_measure(
    tag_t               item,   /**< (I) Tag of an Item */
    tag_t               uom     /**< (I) Tag of the unit of measure to be assigned to this Item (may be #NULLTAG) */
    );


/**
    Retrieves the ID of the Item.

    Id in Context = NO: Returns Item.item_id. <br>
    Id in Context = YES: Returns Item.item_id.
*/
extern TCCORE_API int ITEM_ask_id2(
    tag_t               item,                           /**< (I) Tag of an Item */
    char                **item_id                       /**< (OF) ID of an Item */
    );

/**
    Sets the ID of the Item.
    <UL>
    <LI>Id in Context = NO: Ensure case insensitive uniqueness against all Item.item_id and Identifier.id.
    <LI>Id in Context = YES: Ensure case insensitive uniqueness against all Item.item_id.
    </UL>
    Ensure case insensitive uniqueness across all Items (item_id attribute) and
    alternate identifiers of items (idfr_id attribute) if Id in Context is not implemented.
*/
extern TCCORE_API int ITEM_set_id (
    tag_t               item,       /**< (I) Tag of an Item */
    const char*         item_id     /**< (I) ID of an Item */
    );


/**
    Retrieves the name of the Item.
*/
extern TCCORE_API int ITEM_ask_name2(
    tag_t               item,                               /**< (I) Tag of an Item */
    char                **item_name                         /**< (OF) Name of an Item */
    );

/**
    This function will set the name of the Item.
*/
extern TCCORE_API int ITEM_set_name(
    tag_t               item,       /**< (I) Tag of an Item */
    const char*         item_name   /**< (I) Name of an Item */
    );

/**
   Retrieves the description of the Item.
*/
extern TCCORE_API int ITEM_ask_description2(
    tag_t               item,                               /**< (I) Tag of an Item */
    char                **item_desc                         /**< (OF) Description of an Item */
    );

/**
    Sets the description of the Item.
*/
extern TCCORE_API int ITEM_set_description(
    tag_t               item,       /**< (I) Tag of an Item */
    const char*         item_desc   /**< (I) Description of an Item */
    );



/**
    Retrieves the type of the Item.
*/
extern TCCORE_API int ITEM_ask_type2(
    tag_t               item,                               /**< (I) Tag of an Item */
    char                **item_type                         /**< (OF) Type of an Item */
    );

/** @} */

/**
    @name Item Revision Functions
    @{
*/

/**
   Creates a new revision of the specified Item
   <br/>This function creates an "initial" revision in the same state as
   the first revision you get on creating a new Item.
   <br/>To create a new revision based on an existing revision, use #ITEM_copy_rev.

   @note This itk will not save the object: #AOM_save_with_extensions needs to be called separately to save the object.

   @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_create_rev(
    tag_t               item,            /**< (I) Tag of an existing Item */
    const char*         revision_id,     /**< (I) A null is allowed. If null, the system will generate a revision ID. */
    tag_t*              revision         /**< (O) The new Item Revision in the current program. */
    );

/**
   Creates an Item Revision in a fashion similar to #ITEM_create_rev, except that a pre-populated
   Item Revision Master form can be used. This form will be used for Item Revision.

    @note This itk will not save the object: #AOM_save_with_extensions needs to be called separately to save the object.
    @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_create_rev_with_master(
    tag_t       item,                     /**< (I) An existing item */
    const char* rev_id,                   /**< (I) A null is allowed. If null, the system will generate a revision ID */
    tag_t       item_rev_master_form_tag, /**< (I) Item Revision Master form that will be used for the created item
                                                   revision.
                                                   <br/>It can be #NULLTAG.*/
    tag_t*      rev                       /**< (O) The Item Revision in the current program */
    );


/**
   Saves save an Item Revision.
*/
extern TCCORE_API int ITEM_save_rev(
    tag_t               rev     /**< (I) Tag for identifying the Item Revision to be saved */
    );

/**
    Deletes  the given revision of an Item.
    <br/>This removes all attachments to the revision.
    <br/>The attached objects themselves will not be deleted, except for the master form.
*/
extern TCCORE_API int ITEM_delete_rev(
    tag_t               rev     /**< (I) Tag for identifying the Item Revision in the current program */
    );

/**
    Retrieves the list of all the Item revisions in the database.
*/
extern TCCORE_API int ITEM_extent_rev(
    int*                count,      /**< (O) Total number of Item Revision in the database */
    tag_t**             list        /**< (OF) count List of tags for all the Item Revision in the database */
    );


/**
    Retrieves the Item Revision based on an input value, which can be:
    <ul>
    <li>the value of its property Item ID ("item_id"). If the value of the preference "TC_MFK_DEFAULT_DOMAIN" is specified, the search is executed against that domain.
    <li>the value of its property Part Identifier ("fnd0PartIdentifier").
    </ul>

    <br/>Please also refer to the documentation of #ITEM_find_item.

    <br>If tag of the item is known, then use #ITEM_find_revision for performance improvement.
    <br><br>For searching in a single id context, use the #ITEM_find_revs_in_idcontext.

    @returns
    <ul>
    <li>#ITK_ok on success                  if no match is found, @p revision will be #NULLTAG.
    <li>#ITEM_multiple_items_returned       if more than one Items are found for @p search_id.
    <li>#ITEM_duplicate_ids_found           if more than one Items are found for the search on @p search_id executed on the "Item" class.
    <li>#ITEM_duplicate_rev_ids_found       if more than one Item Revisions exist with a case-insensitive match for @p revision_id.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int ITEM_find_rev(
    const char*         search_id,          /**< (I) Either the ID ("item_id") or the Part Identifier ("fnd0PartIdentifier") of the Item to find */
    const char*         revision_id,        /**< (I) Item Revision ID */
    tag_t*              revision            /**< (O) The matching Item Revision */
    );


/**
    This function will return the tag of a specific Item Revision.
    It should be used in preference to #ITEM_find_rev when you already have the tag of the Item.

    If more than one match (case insensitive) is found, an error is returned.
    Use #ITEM_find_revisions in this case.
    <ul>
    <li>Id in Context = NO: Case insensitive search of rev_id given Item tag.
    <li>Id in Context = YES: Case insensitive search of rev_id given Item tag.
    </ul>
*/
extern TCCORE_API int ITEM_find_revision(
    tag_t               item,       /**< (I) Tag of the Item */
    const char*         rev_id,     /**< (I) Item Revision ID */
    tag_t*              rev_tag     /**< (O) Tag of the Item Revision */
    );

/**
    This function searches the database for all Item Revisions (of the given Item)
    with IDs that match the given string. Wildcards may be used.
    The search will always be case insensitive.
    <ul>
    <li>Id in Context = NO: Case insensitive search of rev_id given Item tag.
    <li>Id in Context = YES: Case insensitive search of rev_id given Item tag.
    </ul>
*/
extern TCCORE_API int ITEM_find_revisions(
    tag_t               item,       /**< (I) Tag of the Item */
    const char*         rev_id,     /**< (I) Item Revision ID */
    int*                n_revs,     /**< (O) Number of matching Revisions found */
    tag_t**             rev_tags    /**< (OF) n_revs Array of tags of found Revisions */
    );

/**
    This function will return the tag of the Item to which the revision belongs to.
*/
extern TCCORE_API int ITEM_ask_item_of_rev(
    tag_t               rev,    /**< (I) Tag of a revision */
    tag_t*              item    /**< (O) Tag of the Item of the specific revision tag */
    );

/**
    Produces a new revision based on a specified revision of the same Item.
    This is the same operation as that invoked by the SaveAs-&gt;Item Revision action in Workspace.
*/
extern TCCORE_API int ITEM_copy_rev_using(
    tag_t                   rev,                /**< (I) Tag of an existing Item */
    const char              *new_rev_id,        /**< (I) A null is allowed. If null, the system will generate a revision ID */
    const int               option_count,       /**< (I) The number of objects passed as user_options */
    ITEM_deepcopy_info_t*   user_options,       /**< (I) The deep copy options */
    tag_t                   *new_rev,           /**< (O) Tag for identifying the new Item Revision in the current program */
    int*                    count,              /**< (O) Count of deep copied objects */
    tag_t**                 deep_copied_objects /**< (OF) Tags for newly created objects during deep copy */
    );

/**
    Produces a new revision based on a specified revision of the same Item.
    This is the same operation as that invoked by the SaveAs-&gt;Item Revision action in Workspace.
*/
extern TCCORE_API int ITEM_copy_rev(
    tag_t               rev,            /**< (I) Tag of an existing Item */
    const char*         new_rev_id,     /**< (I) A null is allowed. If null, the system will generate a revision ID */
    tag_t*              new_rev_tag     /**< (O) Tag for identifying the new Item Revision in the current program */
    );

/**
    Produces a new revision based on a specified revision of the same Item. Similar to #ITEM_copy_rev, except that
    you can pass pre-populated Item Revision Master form. This form will be used for Item Revision. It can be #NULLTAG.

    This is the same operation as that invoked by the SaveAs-&gt;Item Revision action in Workspace.
*/
extern TCCORE_API int ITEM_copy_rev_with_master(
    tag_t       rev,                      /**< (I) Tag of an existing Item Revision */
    const char* new_rev_id,               /**< (I) A null is allowed. If null, the system will generate a revision ID */
    tag_t       item_rev_master_form_tag, /**< (I) Item Revision Master form tag that will be used for the created item
                                                   revision. Can be NULLTAG */
    tag_t*      new_rev_tag               /**< (O) Tag for identifying the new Item Revision in the current program */
    );

/** @} */

/**
    @name Item Baseline Functions
    @{
*/

/**
    This ITK creates a Baseline Revision for the input Item Revision only. BOMView Revisions attached to the ItemRevision
    will be copied forward to the new baseline Revision as per deep copy rules.
    If the baseline_rev_id is empty, then the ITK would generate a Baseline Revision ID using the
    #USER_new_revision_id_from_alt_rule ("PDR", , , , ,) user_exit.
    The description entered would be set as the description of the Baseline Revision.
    Once the creation of the Baseline Revision is completed,
    the Baseline Revision would undergo the release process as given by the rel_proc_name.
*/
extern TCCORE_API int ITEM_baseline_rev(
    tag_t               rev,                    /**< (I) Item Revision that needs to be Baselined */
    const char*         new_rev_id,             /**< (I) The Revision Id of the Baseline Item Revision */
    const char*         desc,                   /**< (I) Description that needs to be set on the Baseline Item Revision */
    const char*         rel_proc_name,          /**< (I) Name of the Release Procedure through which
                                                        the Baseline Revision should under go */
    const char*         jobName,                /**< (I) Name of the Job */
    const char*         jobDescription,         /**< (I) Description of the Job */
    tag_t*              new_rev_tag,            /**< (O) Item Revision Tag of the Baseline Revision created */
    int*                deepCopiedObjCount,     /**< (O) */
    tag_t**             deepCopiedObjs          /**< (OF) deepCopiedObjCount */
    );

/**
    This ITK creates a does a dryrun of baseline creation for the input Item Revision.
    It does not create the baseline but runs through all the pre-conditions, user error checks
    And places the results in the filename pointed by the logFileName, which is placed at the location
    pointed to, by the fullLogFileName.
    If there is any error, the ITK returns the error code, which on the top of the error stack.
*/
extern TCCORE_API int ITEM_dryrun_baseline( tag_t      rev, /**< (I)  Item Revision that needs to be Baselined */
                       const char *rel_proc_name,             /**< (I)  Name of the Release Procedure through which the Baseline Revision should under go */
                       char **logFileName,                    /**< (OF) Name of the LogFile Generated */
                       char **fullLogFileName                 /**< (OF) FullPath of the output logfile, including the logfilename */
                     );

/**
    This ITK returns the base item revision with which the baseline_rev is having the IMAN_baseline relation.
    If no revision is found, i.e., the input baseline_rev is not a Baseline Revision,
    then #NULLTAG is returned as the base_rev.
*/
extern TCCORE_API int ITEM_rev_find_base_rev(
    tag_t               baseline_rev,   /**< (I) The Baseline Item Revision Tag */
    tag_t*              base_rev        /**< (O) The base Revision of the given Baseline Item Revision */
    );

/**
    This ITK lists all the various Baseline Revisions that the base_rev has with the given
    baseline release status (baselineStatusName).
    If an empty baselineStatusName is sent, then it lists all the Baseline Revisions for the given base revision.
    The memory for the baseline_revs is allocated by the ITK and needs to be MEM_free()d.
*/
extern TCCORE_API int ITEM_rev_list_baselineRevs(
    tag_t               base_rev,               /**< (I) Tag of the Item Revision for which the list of Baselines is requested */
    const char*         baselineStatusName,     /**< (I) The release status name of the Baseline Revisions that are requested.
                                                        If empty, then all the Baseline Revisions are returned. */
    int*                n_revs,                 /**< (O) Number of Baseline Revisions matching the specified criteria. */
    tag_t**             baseline_revs           /**< (OF) n_revs The list of memory allocated Baseline Revisions */
    );

/** @} */



/**
    Retrieves all BOMView Revisions associated to the Item Revision.
*/
extern TCCORE_API int ITEM_rev_list_bom_view_revs(
    tag_t               rev,    /**< (I) Item Revision tag */
    int*                count,  /**< (O) Number of BOM Views attached to the Item Revision */
    tag_t**             bvrs    /**< (OF) count BOMView revisions for the Item Revision */
    );

/**
    Retrieves all the BOMViewRevision,
    including GDE BOMViewRevisions, for a given Item Revision.
*/
extern TCCORE_API int ITEM_rev_list_all_bom_view_revs(
    tag_t               rev,    /**< (I) Tag of the item revision under which the GDE BomViewRevision should be created */
    int*                count,  /**< (O) Number of BOM Views Revision attached to the above Item Revision */
    tag_t**             bvrs    /**< (OF) count Tags of BOMView Revisions (including GDE BOMViewRevisions) for the Item Revision */
    );

/**
    Removes the (PS) BOMViewRevision from the Item Revision and deletes it. If that leaves the
    corresponding BOMView with no BOMViewRevisions, then the BOMView is removed from the Item and
    deleted too.
*/
extern TCCORE_API int ITEM_rev_delete_bvr(
    tag_t  rev,    /**< (I) Item Revision tag */
    tag_t  bvr     /**< (I) BOMViewRevision tag */
    );




/**
    Retrieves the ID of the Item Revision.
    <ul>
    <li>Id in Context = NO: Returns ItemRevision.rev_id
    <li>Id in Context = YES: Returns ItemRevision.rev_id
    </ul>
*/
extern TCCORE_API int ITEM_ask_rev_id2(
    tag_t               rev,                        /**< (I) Tag of an Item Revision */
    char                **rev_id                    /**< (OF) ID of the Item Revision */
    );

/**
    Sets the ID of the Item Revision.
    <ul>
    <li>Id in Context = NO: Ensure case insensitive uniqueness of rev_id among all peer revisions of  given ItemRevision.
    <li>Id in Context = YES: Ensure case insensitive uniqueness of rev_id among all peer revisions of  given ItemRevision.
    </ul>
*/
extern TCCORE_API int ITEM_set_rev_id(
    tag_t               rev,    /**< (I) Tag of an Item Revision */
    const char*         rev_id  /**< (I) ID of the Item Revision */
    );


/**
   Retrieves the name of the Item Revision.
*/
extern TCCORE_API int ITEM_ask_rev_name2(
    tag_t               rev,                            /**< (I) Tag of an Item Revision */
    char                **rev_name                      /**< (OF) Name of the Item Revision */
    );

/**
   Sets the name of the Item Revision.
*/
extern TCCORE_API int ITEM_set_rev_name(
    tag_t               rev,        /**< (I) Tag of an Item Revision */
    const char*         rev_name    /**< (I) Name of the Item Revision */
    );


/**
   Retrieves the description of the Item Revision.
*/
extern TCCORE_API int ITEM_ask_rev_description2(
    tag_t               rev,                            /**< (I) Tag of an Item Revision */
    char                **rev_desc                      /**< (OF) Description of an Item */
    );

/**
   Sets the description of the Item Revision.
*/
extern TCCORE_API int ITEM_set_rev_description(
    tag_t               rev,        /**< (I) Tag of an Item Revision */
    const char*         rev_desc    /**< (I) Description of an Item */
    );


/**
   Retrieves the type of the Item Revision.
*/
extern TCCORE_API int ITEM_ask_rev_type2(
    tag_t               rev,                            /**< (I) Tag of an Item Revision */
    char                **rev_type                      /**< (OF) Type of an Item Revision */
    );

/**
    Retrieves the variant expression block associated with the specified Item Revision.
*/
extern TCCORE_API int ITEM_ask_rev_variants(
    tag_t               rev,                        /**< (I) Tag of an Item Revision */
    tag_t*              variant_expression_block    /**< (O) Tag of the variant expression block */
    );

/**
    Sets the variant expression block associated with the specified Item Revision.
    <br/>A #NULLTAG block clears the currently set value.
*/
extern TCCORE_API int ITEM_set_rev_variants(
    tag_t               rev,                        /**< (I) Tag of an Item Revision */
    tag_t               variant_expression_block    /**< (I) Tag of the variant expression block */
    );

extern TCCORE_API int ITEM_create_ic_baseline_rev(
    tag_t               rev,                /**< (I) */
    tag_t               bom_window,         /**< (I) */
    const char*         copy_rules_key,     /**< (I) */
    const char*         name,               /**< (I) */
    const char*         desc,               /**< (I) */
    const char*         id,                 /**< (I) */
    const char*         rev_id,             /**< (I) */
    tag_t*              new_rev             /**< (O) */
    );

/**
    @name Deep Copy Functions
    @{
*/

/**
   Performs the Deep copy of the attachments Based on the deep copy rules specified
    using the Business Modeler deep copy rule application.
    <br/>This ITK will get the rules from the database and then, after processing them, performs the deep copy operation.
*/
extern TCCORE_API int ITEM_perform_deepcopy(
    tag_t               new_item_rev ,      /**< (I) The Item Revision Tag to which attachments to be deep copied */
    char*               operation,          /**< (I) The Type of operation: <br>
                                                    #ITEM_revise_operation <br>
                                                    #ITEM_saveas_operation */
    tag_t               parent_item_rev,    /**< (I) The Item Revision through which is revised to create the new_item_rev */
    int*                count,              /**< (O) Number of deep copied objects */
    tag_t**             deepcopiedobjects   /**< (OF) count Array of deep copied objects */
    );

extern TCCORE_API int ITEM_perform_deepcopy_using2(
    tag_t               new_item_rev ,      /**< (I) The Item Revision Tag to which attachments to be deep copied */
    char*               operation,          /**< (I) The Type of operation: <br>
                                                    #ITEM_revise_operation <br>
                                                    #ITEM_saveas_operation */
    tag_t               parent_item_rev,    /**< (I) The Item Revision through which is revised to create the new_item_rev */
    const int           option_count,       /**< (I) */
    const tag_t         *obj_tags,          /**< (I) Tags of the objects that need to be copied or not be copied */
    const char**        copy_types,         /**< (I) Copy options such as strings defined by ITEM_copy_as_object, ITEM_no_copy */
    const char**        obj_names,          /**< (I) User supplied names for the objects */
    const char**        relation_types,     /**< (I) Names of the relation types */
    const char**      copy_relations,     /**< (I) relation_count Carry forward the Properties on the Relation */
    int*                count,              /**< (O) Number of deep copied objects */
    tag_t**             deepcopiedobjects   /**< (OF) count Array of deep copied objects */
    );

/** @} */

extern TCCORE_API int ITEM_perform_deepcopy_using(
    tag_t               new_item_rev ,      /**< (I) The Item Revision Tag to which attachments to be deep copied */
    char*               operation,          /**< (I) The Type of operation: <br>
                                                    #ITEM_revise_operation <br>
                                                    #ITEM_saveas_operation */
    tag_t               parent_item_rev,    /**< (I) The Item Revision through which is revised to create the new_item_rev */
    const int           option_count,       /**< (I) */
    const tag_t         *obj_tags,          /**< (I) Tags of the objects that need to be copied or not be copied */
    const char**        copy_option,        /**< (I) Copy options such as strings defined by ITEM_copy_as_object, ITEM_no_copy */
    const char**        option_names,        /**< (I) User supplied names for the objects */
    const char**        relation_types,      /**< (I) Names of the relation types */
    int*                count,              /**< (O) Number of deep copied objects */
    tag_t**             deepcopiedobjects   /**< (OF) count Array of deep copied objects */
    );

/**
    Modular options are scoped by an item id.
    This function helps translate MVL text to subsitute new item id
        (this helps in scenarios like SaveAs where options in new structure
        should be scoped by new item id)
    Along with MVL text, an ItemRevision also has references to PSOption objects.
    These references should also mimic the scoping by Item, hence copies of
    PSOption objects are created for the new revision (to_rev).
*/
extern TCCORE_API int ITEM_translate_rev_mvl(
    tag_t               from_rev,       /**< (I) */
    tag_t               to_rev,         /**< (I) */
    int                 n_modules,      /**< (I) */
    char**              from_modules,   /**< (I) n_modules */
    char**              to_modules      /**< (I) n_modules */
    );

extern TCCORE_API int ITEM_rev_ask_effectivity_mappings(
    tag_t itemrev,                         /**< (I) */
    int *n,                                /**< (O) */
    tag_t **mappings                       /**< (OF) n */
    );

typedef struct ITEM_attached_object_tag_s
{
    tag_t attachment;
    tag_t attachment_type;
} ITEM_attached_object_tag_t;

/**
   Creates a GDE BOMViewRevision of a BOMView, with no occurrences.
   <br/>The created GDEBOMViewRevision is made an attribute of the specified parent Item Revision. This Item Revision
   must be a revision of the Item that is the parent of the view_type.

   <br/>The new BOMView Revision is not saved: it can be saved to the database using #AOM_save.

   @note The parent Item Revision is modified and must also be saved
   @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int ITEM_rev_create_gde_bvr (
    tag_t               item_rev_tag,   /**< (I) Tag of the item revision under which the GDE BomViewRevision should be created */
    tag_t               view_type,      /**< (I) Tag of the view_type to be associated with the new GDE BomViewRevision */
    tag_t*              gde_bvr_tag     /**< (O) Tag of the newly created GDE BomViewRevision */
    );

/**
   Retrieves the GDE BOMViewRevision of the specified view_type for a given Item Revision.
*/
extern TCCORE_API int ITEM_rev_ask_gde_bvr (
    tag_t               item_rev_tag,   /**< (I) Tag of the item revision under which the GDE BomViewRevision should be created */
    tag_t               view_type,      /**< (I) Tag of the view_type to be associated with the new GDE BomViewRevision */
    tag_t*              gde_bvr_tag     /**< (O) Tag of the GDE BomViewRevision.
                                                If no GDE BOMViewRevision is found #NULLTAG is returned. */
    );


/**
    Determines whether or not an item has any item revisions that are modules.
*/
extern TCCORE_API int ITEM_ask_has_module(
    tag_t               item,       /**< (I) The item being queried */
    logical*            is_module   /**< (O) True if the item has a module, otherwise false */
    );

/**
    Determines whether or not an item revision has a module.
*/
extern TCCORE_API int ITEM_rev_ask_has_module(
    tag_t               item_rev,       /**< (I) The item rev being queried */
    logical*            is_module   /**< (O) True if the item rev has a module, otherwise false */
    );


/**
    @name VI Functions
    @{
*/
/**
    Determines whether or not an item is a variant item.
*/
extern TCCORE_API int ITEM_ask_is_vi(
    tag_t               item,   /**< (I) The item being queried */
    logical*            is_vi   /**< (O) True if the item is a variant item, otherwise false */
    );

/**
    Provides the saved configuration stored within a variant item.
    <br/>The saved configuration describes how a variant item instantiates the generic component it originates from.
*/
extern TCCORE_API int ITEM_vi_ask_sos(
    tag_t               item,       /**< (I) The item being queried */
    tag_t*              db_sos      /**< (O) The VI’s saved configuration (stored option set).
                                        #NULLTAG if the item is not a VI */
    );

/**
    Provides the module stored within a variant item.
    <br/>A variant item’s module is the generic component it instantiates.
*/
extern TCCORE_API int ITEM_vi_ask_generic_component(
    tag_t               item,               /**< (I) The item being queried */
    tag_t*              module_item_rev     /**< (O) The VI’s generic component (module).
                                                #NULLTAG if the item is not a VI. */
    );

/**
    States whether or not a link is maintained between a variant item and its generic component.
    <br/>A linked VI cannot have structure changes made to it if those changes make it
    fundamentally different to the generic structure it instantiates.
*/
extern TCCORE_API int ITEM_vi_ask_is_linked_to_generic(
    tag_t               item,       /**< (I) The item being queried */
    logical*            is_linked   /**< (O) True if the item is a VI that maintains a link to its generic component, <br>
                                           false if the item is not a VI or if it is a VI that
                                           does not require structure validation */
    );

/**
    Unlinks a variant item from its generic component.
    <br/>An unlinked VI can have structure that is different from its generic component.

    <br/><b>Restrictions:</b>
    This action is not possible if the item is not a variant item
    <br/>This action is permanent and not reversible.
    As soon as a VI is unlinked, this new VI state is saved to the database.
    It is not possible to unlink a VI and then relink it.
*/
extern TCCORE_API int ITEM_vi_unlink_from_generic(
    tag_t               item    /**< (I) The variant item that is to be unlinked */
    );

/**
    Searches for variant items for the given generic component based on a set of option value criteria.
    <br/>Criteria for different options are ANDed together (e.g. "option1 = 5 and option2 = 10").
    <br/>Criteria for the same option are ORed together (e.g. "option1 = 5 or option1 = 8").
*/
extern TCCORE_API int ITEM_vi_find(
    tag_t               generic_item_rev,   /**< (I) The generic component */
    int                 n,                  /**< (I) Number of search criteria.
                                                    Setting n to 0 will return all VIs of the generic component. */
    tag_t*              items,              /**< (I) n Array of items against which the following options are defined */
    char**              options,            /**< (I) n Array of options that are being queried */
    int*                ops,                /**< (I) n Array of query operators. Defined in bom_tokens.h: <br>
                                                    #BOM_DB_SOS_OP_LIKE - Like (string matching with wildcards) <br>
                                                    #BOM_DB_SOS_OP_NOT_LIKE - Not like <br>
                                                    #BOM_DB_SOS_OP_EQ - Equals <br>
                                                    #BOM_DB_SOS_OP_NE - Not equals <br>
                                                    #BOM_DB_SOS_OP_LT - Less than <br>
                                                    #BOM_DB_SOS_OP_GT - Greater than <br>
                                                    #BOM_DB_SOS_OP_LTEQ - Less than or equal <br>
                                                    #BOM_DB_SOS_OP_GTEQ - Greater than or equal <br>
                                                    #BOM_DB_SOS_OP_IN - Inside range <br>
                                                    #BOM_DB_SOS_OP_OUT - Outside range */
    int*                valueTypes,         /**< (I) n Array of option value type definitions. Defined in bom_tokens.h: <br>
                                                    #BOM_DB_SOS_LOGICAL <br>
                                                    #BOM_DB_SOS_INTEGER <br>
                                                    #BOM_DB_SOS_DOUBLE <br>
                                                    #BOM_DB_SOS_STRING */
    char**              lowValues,          /**< (I) n Array of values to match. Passed as strings,
                                                    converted internally to previously defined value type. */
    char**              highValues,         /**< (I) n Array of upper bound values when using range operators */
    int*                n_matches,          /**< (O) Number of matching VIs found */
    tag_t**             matches             /**< (OF) n_matches Array of matching VI's */
    );

/** @} */

/**
    Retrieves all the items that have the given alternate id in context.
    <br/>Uses case-insensitive search and allows wildcards in id.
    <br/>If @p id_context is null, it assumes a search across all alternate identifiers of Items in any context as well as Items.
*/
extern TCCORE_API int ITEM_find_in_idcontext (
    const char*         id,             /**< (I) ID to be searched for. May include wild cards. */
    tag_t               id_context,     /**< (I) An ID Context or #NULLTAG */
    int*                n_items,        /**< (O) Number of items for the given ID and ID Context */
    tag_t**             item_tags       /**< (OF) n_items The found Items. */
    );

/**
    Similar to #ITEM_find_in_idcontext except if more than one item found, it returns an error.
*/
extern TCCORE_API int ITEM_find_item_in_idcontext (
    const char*         id,             /**< (I) ID to be searched for. May include wild cards. */
    tag_t               id_context,     /**< (I) An IdContext or #NULLTAG */
    tag_t*              item_tag        /**< (O) The found Item. */
    );

/**
    Retrieves all tags of supplemental revisions (Identifiers) based on Inputs:
    <ul>
    <li>the value of its property Item id ("item_id") in the specified ID context.
    <li>the value of its property Item Revision Id ("rev_id") in the specified ID context.
    </ul>
    <br>The search is case-insensitive and allows wildcards in IDs.
    <br>If the parameter "idcontext_tag" is set to #NULLTAG, the search is carried out across all alternate identifiers of Items as well as in Items themselves.
*/
extern TCCORE_API int ITEM_find_revs_in_idcontext (
    const char*         id,             /**< (I) Id for an item */
    const char*         rev_id,         /**< (I) Id for an item revision */
    tag_t               idcontext_tag,  /**< (I) Tag of an IdContext or #NULLTAG */
    int*                num_revs,       /**< (O) Number of item revisions with the given id, rev_id, and IdContext */
    tag_t**             rev_tags        /**< (OF) num_revs An array of tags to supplemental revisions (Identifiers) */
    );

/**
    Checks if any item exists with the given ID.
    <br/>If ID in Context is not implemented,
    it checks for Items as well as all alternate identifiers of Items.
    <br/>If it is implemented, it checks only the Items.
*/
extern TCCORE_API int ITEM_id_exists(
    const char*         id,         /**< (I) Id for an item */
    logical*            verdict     /**< (O) TRUE if an Item exists, otherwise FALSE */
    );

/**
    Retrieves all objects that have the given ID.
    <br/>If "Id In Context" is not implemented,
    the Items and alternate Identifiers are searched and retrieved.
    <br/>Otherwise, only Items are searched and retrieved.
*/
extern TCCORE_API int ITEM_id_owners (
    const char*         id,         /**< (I) Id for an object */
    int*                num_objs,   /**< (O) Number of objects for the given id */
    tag_t**             obj_tags    /**< (OF) num_objs An array of tags to Items and/or Alternate Identifiers */
    );

/**
    @name ITEM Exclude List
    @{
*/

extern TCCORE_API void ITEM_free_exclude_list();

extern TCCORE_API void ITEM_build_exclude_list(
    int                  array_length,  /**< (I) */
    tag_t*               exclude_array  /**< (I) */
    );

extern TCCORE_API void ITEM_get_exclude_list(
    int*                 count,         /**< (O) */
    tag_t**              exclude_list   /**< (OF) count */
    );

/** @} */



/**
   Retrieves the Item Master form type of an Item type.
*/
extern TCCORE_API int ITEM_ask_master_form_type(
    const char * itemType,    /**< (I) Item type */
    char ** formType          /**< (OF) Item Master form type */
    );

/**
   Retrieves the Item Revision Master form type of an Item type.
*/
extern TCCORE_API int ITEM_ask_rev_master_form_type(
    const char * itemType,    /**< (I) Item type */
    char ** formType          /**< (OF) Item Revision Master form type */
    );

    extern TCCORE_API int ITEM_rev_vi_rev_find(
        tag_t generic_item_rev,      /**< (I) */
        int n,                       /**< (I) */
        tag_t *items,                /**< (I) n */
        char **options,              /**< (I) n */
        int *ops,                    /**< (I) n */
        int *valueTypes,             /**< (I) n */
        char **lowValues,            /**< (I) n */
        char **highValues,           /**< (I) n */
        int *n_matches,              /**< (O) */
        tag_t **matches              /**< (OF) n_matches */
        );

    extern TCCORE_API int ITEM_vi_rev_ask_linked_generic_component(
        tag_t         variant_item_rev,   /**< (I) */
        tag_t*        module_item_rev     /**< (O) */
        );

    extern TCCORE_API int ITEM_rev_vi_revise_and_update(
        tag_t         bom_line,           /**< (I) */
        tag_t         generic_item_rev,   /**< (I) */
        tag_t         old_variant_item_rev,   /**< (I) */
        tag_t*        new_variant_item_rev    /**< (O) */
        );

/**
    Manages global alternates
*/
    extern TCCORE_API int ITEM_ask_has_global_alternates(
        tag_t    item,                 /**< (I)  Tag of the selected item */
        logical* has_global_alternates /**< (O) Whether the item has global alternates */
        );


    extern TCCORE_API int ITEM_rev_sequence_make_immune (
        tag_t   item_rev_tag  /**< (I) */
        );

    extern TCCORE_API int ITEM_rev_purge_sequences (
        tag_t   item_rev_tag /**< (I) */
  );

    extern TCCORE_API int ITEM_rev_sequence_is_latest (
        tag_t         item_rev_tag,    /**< (I) */
        logical*      is_latest        /**< (O) */
        );

    extern TCCORE_API int ITEM_rev_sequence_remove_immunity (
        tag_t   item_rev_tag /**< (I) */
        );

    extern TCCORE_API int ITEM_rev_restore_previous_sequence (
        tag_t   item_rev_tag /**< (I) */
        );

    /**
      Retrieves a list of all global alterantes for the specified item.
    */
    extern TCCORE_API int ITEM_list_related_global_alternates(
        tag_t    item,           /**< (I)  Tag of the selected item */
        int*     n_objs,         /**< (O)  number of related global alternates for the item */
        tag_t**  related_objs    /**< (OF) n_objs Array of related global alternates */
        );

    extern TCCORE_API int ITEM_add_related_global_alternates(
        tag_t    item,           /**< (I)  Tag of the selected item */
        int      n_objs,         /**< (I)  number of global alternate items to be added*/
        tag_t*   added_objs      /**< (I)  Array of related global alternates to be added*/
        );

    extern TCCORE_API int ITEM_remove_related_global_alternates(
        tag_t    item,           /**< (I)  Tag of the selected item */
        int      n_objs,         /**< (I)  number of global alternate items to be removed*/
        tag_t*   removed_objs    /**< (I)  Array of related global alternates to be removed*/
        );

    /**
       Makes the specified global alternate the preferred global alternate  for the
       specified item.
    */
    extern TCCORE_API int ITEM_prefer_global_alternate(
        tag_t    item,           /**< (I)  Tag of the selected item */
        tag_t    preferred_item  /**< (I) Tag of the preferred global alternate */
        );

    /**
       Checks to see if the given item rev has already been baselined during the current
       baseline operation
    */
    extern TCCORE_API int ITEM_rev_has_been_baselined_during_current_operation(
        tag_t          item_rev,            /**< (I) Tag of the item rev that needs to be checked */
        logical        *verdict,            /**< (O) If the given item rev has been baselined returns TRUE else FALSE */
        tag_t          *new_item_rev        /**< (O) Tag of the baselined item rev if verdict is TRUE */
        );

    /**
       @deprecated #ITEM_rev_set_participants deprecated in Teamcenter 11.6. Use #PARTICIPANT_set_participants instead.
    */
    TC_DEPRECATED( "11.6", "ITEM_rev_set_participants", "PARTICIPANT_set_participants" )
    extern TCCORE_API int ITEM_rev_set_participants(
        tag_t item_rev,                     /**< (I)  Tag of the item rev to which participants need to be added */
        int participant_count,              /**< (I)  Number of participants */
        tag_t * participant_list            /**< (I)  List of participants */
        );

    /**
       @deprecated #ITEM_rev_ask_participants deprecated in Teamcenter 11.6. Use #PARTICIPANT_ask_participants instead.
    */
    TC_DEPRECATED( "11.6", "ITEM_rev_ask_participants", "PARTICIPANT_ask_participants" )
    extern TCCORE_API int ITEM_rev_ask_participants(
        tag_t item_rev,                     /**< (I)  Tag of the item rev whose participants to get */
        tag_t participant_type,             /**< (I)  Type of participant to retrieve.<br/>It should be a subtype of the Participant class
                                               (e.g."ProposedResponsibleParty", "ProposedReviewer"). */
        int * participant_count,            /**< (O)  Number of participants */
        tag_t ** participant_list           /**< (OF) List of participants for the item rev */
        );

    /**
       @deprecated #ITEM_rev_add_participant deprecated in Teamcenter 11.6. Use #PARTICIPANT_add_participant instead.
    */
    TC_DEPRECATED( "11.6", "ITEM_rev_add_participant", "PARTICIPANT_add_participant" )
    extern TCCORE_API int ITEM_rev_add_participant(
        tag_t item_rev,                     /**< (I)  Tag of the item rev to which participant needs to be added */
        tag_t participant                   /**< (I)  Tag of the participant to add */
        );

    /**
       @deprecated #ITEM_rev_remove_participant deprecated in Teamcenter 11.6. Use #PARTICIPANT_remove_participant instead.
    */
    TC_DEPRECATED( "11.6", "ITEM_rev_remove_participant", "PARTICIPANT_remove_participant" )
    extern TCCORE_API int ITEM_rev_remove_participant(
        tag_t item_rev,                     /**< (I)  Tag of the item rev from which participant needs to be removed */
        tag_t participant                   /**< (I)  Tag of the participant to remove */
        );


    extern TCCORE_API int ITEM_rev_rename_cad_file(
        logical *status                   /**< (O) flag to indicate if cad files need to be renamed */
        );

    extern TCCORE_API int ITEM_rev_get_cloned_item_rev(
        tag_t old_item_rev,                 /**< (I) item rev to be checked */
        tag_t *cloned_item_rev              /**< (O) if cloned return the cloned item rev */
        );

    /**
       Checks whether the input item is a Product Item by checking all properties defined in
       the PortalDesignContextProductItemProperties preference.
    */
    extern TCCORE_API int ITEM_is_product_item(
        tag_t          item,                /**< (I) The item tag to be checked */
        logical*       is_product_item      /**< (O) TRUE if the item is a product item */
        );

    /**
       Generates a revision id for an item or an item type.
    */
    extern TCCORE_API int ITEM_new_revision_id(
        tag_t item,      /**< (I) Tag of an existing Item */
        tag_t item_type, /**< (I) Tag the type of the item*/
        logical* mod,    /**< (O) Boolean value specifying if the system user has the right to modify (TRUE) the value.
                            Otherwise, attempts to change the returned string (FALSE)
                            will be prevented at the user interface. */
        char** id        /**< (O) ID of the latest base revision of the Item */
        );

    extern TCCORE_API int ITEM_rev_is_immune(
        tag_t        itemRevisionTag,        /**< (I) The item revision tag to be checked */
        logical*    isImmune                 /**< (O) TRUE if the item revision sequence is immune */
        );

    /**
       Generates Item IDs in bulk during a "Save As" operation.
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CXPOM_invalid_tag if any member of @p items is #NULLTAG.
       <li>#ITEM_invalid_object if any member of @p items is Invalid tag.
       <li>#PROP_not_found if any member of @p items is not an Item.
       </ul>
    */
    extern TCCORE_API int USER_new_item_ids_for_saveas(
        const  int          n_items,              /**< (I)  Number of objects provided as input.*/
        const tag_t*        items,                /**< (I)  n_items The Items required to generate ids. */
        logical**           is_modifiable,        /**< (OF) quantity Indicates if the generated IDs are modifiable. */
        char***             ids                   /**< (OF) n_items The array of generated IDs.
                                                     <br/>The array is packed, which means that the memory is to be deallocated by calling
                                                     #MEM_free on the container only.*/

        );

    /**
       Generates Item IDs in bulk during a "Save As" operation.
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CXPOM_invalid_tag if any member of @p items is #NULLTAG.
       <li>#ITEM_invalid_object if any member of @p items is Invalid tag.
       <li>#PROP_not_found if any member of @p items is not an Item.
       </ul>
    */
    extern TCCORE_API int USER_new_item_ids_for_saveas2(
        const tag_t*        operation_input,      /**< (I)  List of Operation Inputs.*/
        const  int          n_items,              /**< (I)  Number of Items.*/
        const tag_t*        items,                /**< (I)  n_items The Items required to generate IDs. */
        logical**           is_modifiable,        /**< (OF) Indicates if the generated IDs are modifiable. */
        char***             ids                   /**< (OF) n_items The array of generated IDs.
                                                     <br/>The array is packed, which means that the memory is to be deallocated by calling
                                                     #MEM_free on the container only.*/

        );

    /**
       @deprecated #ITEM_rev_update_participants deprecated in Teamcenter 11.6. Use #PARTICIPANT_update_participants instead.

       Update participants for the provided Item Revision. This function will create a participant object(s)
       based on the @p participant_type_list and @p assignee_list.

       <br/>The update operation is rolled back in case of error.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#POM_invalid_value if invalid values of assignees are passed.
       <li>#TYPE_unknown_type if invalid participant types are passed.
       </ul>
    */
    TC_DEPRECATED( "11.6", "ITEM_rev_update_participants", "PARTICIPANT_update_participants" )
    extern TCCORE_API int ITEM_rev_update_participants(
        tag_t   item_rev,                   /**< (I)  Tag of the item rev for which participant(s) needs to be added */
        int     assignee_count,             /**< (I)  Number of assignees */
        tag_t*  assignee_list,              /**< (I)  assignee_count List of assignees */
        tag_t*  participant_types_list,     /**< (I)  assignee_count List of assignee types */
        tag_t** participant_list            /**< (OF) assignee_count List of participants */
        );

#ifdef __cplusplus
}
#endif
/** @} */
#include <tccore/libtccore_undef.h>

#endif
