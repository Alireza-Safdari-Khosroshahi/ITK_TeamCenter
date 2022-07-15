/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the ITK Function declarations for the ICS Module
*/

/*  */

#ifndef I_ICS_HXX
#define I_ICS_HXX

#include <pom/pom/pom.h>
#include <sa/sa.h>
#include <ics/ics_enquiry.h>
#include <ics/ics_errors.h>
#include <sa/sa.h>
#include <common/tc_deprecation_macros.h>
#include <ics/libics_exports.h>

/**
    @defgroup ICS Classification System (ICS)

    Classification of your company's product data - standard parts, technology data, manufacturing equipment -
    saves time by making component data easier to find and retrieve and reduces costs by allowing you to
    reuse existing parts and consolidate and/or eliminate duplicate or out-dated parts.
    Teamcenter Classification is used to create and maintain a hierarchical classification structure
    based on the attribute values of your Teamcenter workspace objects.

    You will use ICS-ITK to:

    <UL>
    <LI>Add items to the classification hierarchy
    <LI>Classify workspace objects
    <LI>Find and retrieve Instances of objects
    <LI>Modify the attribute values of classification Instances
    <LI>Delete instances from the classification hierarchy
    </UL>
    @{
*/

typedef enum {
    ICS_type_unknown,
    ICS_type_group,
    ICS_type_class,
    ICS_type_class_attr,
    ICS_type_view,
    ICS_type_view_attr,
    ICS_type_unctdict,
    ICS_type_stxt,
    ICS_type_data,
    ICS_type_abstract_class,
    ICS_type_storrage_class
} ICS_type_t;

#ifdef __cplusplus
extern "C"{
#endif

/*  */

/**
    This function must be called immediately after all ICS activity is complete.
*/
extern ICS_API int ICS_exit_module ( );

extern ICS_API int ICS_init_hooks ( );

/**
    @name Group/Class/View Functions

    <b>Common Return Values:</b>
    <table>
    <tr><td>#ICS_invalid_class   </td><td>Class tag passed is not a valid tag</td></tr>
    <tr><td>#ICS_invalid_class_id</td><td>Id passed is not a valid Id.       </td></tr>
    <tr><td>#ICS_invalid_tag     </td><td>Tag passed is not a valid tag      </td></tr>
    <tr><td>#ICS_invalid_view    </td><td>View tag passed is not a valid tag </td></tr>
    <tr><td>#ICS_invalid_view_id </td><td>View id passed is not a valid ID   </td></tr>
    </table>
    @{
*/

/**
    This function gets the top class of the classification hierarchy.
*/
extern ICS_API int ICS_ask_top_class (
    tag_t*         topClass              /**< (O) Top class tag */
    );

/**
    Function to get the tag of the Group/Class identified by the given ID string.

    <b>Restrictions:</b>

    This function can be used only for Groups and Classes. <br>
    Note: this function returns SML_ERR_NO_INSTANCE_FOUND if the class does not exist
*/
extern ICS_API int ICS_find_class (
    const char*    groupOrClassId,         /**< (I) Id of the Group or the Class. */
    tag_t*         groupOrClass            /**< (O) Tag of the passed Group or Class. */
    );

/**
    This function will get the id and name for a given group/class/view.
*/
extern ICS_API int ICS_ask_id_name (
    tag_t          groupOrClassOrView,        /**< (I) Tag of the group/class/view */
    char**         id,                        /**< (OF) Id of the given group/class/view */
    char**         name                       /**< (OF) Name of the given group/class/view */
    );

/**
    This function will get the tag of the view given the view ID and class tag. <br>
    Note: this function returns SML_ERR_NO_INSTANCE_FOUND if the class does not exist
*/
extern ICS_API int ICS_find_view (
    tag_t          theClass,            /**< (I) Tag of the class */
    const char*    viewId,              /**< (I) View id */
    tag_t*         view                 /**< (O) Tag of the view */
    );

/**
    This function gets the children given the group or class tag.

    <b>Restrictions:</b>

    This function can be used only for Groups and Classes.
*/
extern ICS_API int ICS_ask_children (
    tag_t          groupOrClass,    /**< (I) Tag of the group or class */
    int*           nChildren,       /**< (O) Number of children beneath the group or class */
    tag_t**        children         /**< (OF) nChildren Children tags beneath the given group or class */
    );

extern ICS_API int ICS_ask_parent (
    tag_t          theChid,     /**< (I) */
    tag_t*         theParent    /**< (O) */
    );

/**
    @deprecated #ICS_ask_instances deprecated in Teamcenter 11.2.2. Use #ICS_ico_search instead.

    This function gets all the classification records from the database
    (ICO's - Teamcenter Classification Object) under the given class/view combination.
    Refer to ICS_search_instances() to search for instances satisfying a specific search criteria.

    <b>Restrictions:</b>

    Since the instances are associated only with the views and the views belong to a specific class,
    this function can be used only for a particular view/class combination.
*/
TC_DEPRECATED("11.2.2","ICS_ask_instances","ICS_ico_search")
extern ICS_API int ICS_ask_instances (
    tag_t          theClass,        /**< (I) Tag of the class */
    tag_t          view,            /**< (I) Tag of the view belonging to the given class */
    int*           nInstances,      /**< (O) Number of instances found under the class/view combination */
    tag_t**        instances        /**< (OF) nInstances Array of instance tags */
    );


/**
    @deprecated #ICS_ask_instance_count deprecated in Teamcenter 11.2.2. Use #ICS_ico_search_count instead.
*/
TC_DEPRECATED("11.2.2","ICS_ask_instance_count","ICS_ico_search_count")
extern ICS_API int ICS_ask_instance_count (
    const char*    ClassOrViewId,   /**< (I) */
    int*           nInstances       /**< (O) */
    );

/**
    @deprecated #ICS_search_instances deprecated in Teamcenter 11.2.2. Use #ICS_ico_search instead.

    This function searches for the classification records in the database for the given
    class/view combination and satisfying the given search criteria (queries).
    If the queries passed are null, this function behaves similar to ICS_ask_instances().

    <b>Restrictions:</b>

    Since the instances are associated only with the views and the views belong to a specific class,
    this function can be used only for a particular view/class view combination.
*/
TC_DEPRECATED("11.2.2","ICS_search_instances","ICS_ico_search")
extern ICS_API int ICS_search_instances (
    tag_t          theClass,            /**< (I) Tag of the class */
    tag_t          view,                /**< (I) Tag of the view belonging to the given class */
    int            nAttributes,         /**< (I) Number of attributes defined in the view */
    int*           attributeUncts,      /**< (I) UNCT's of the attributes defined in the view */
    char**         queries,             /**< (I) Search criteria (commonly used are \>, \>=, \<, \<=) */
    int*           nInstances,          /**< (O) Number of instances satisfying the search criteria and
                                            belonging to the given class/view combination */
    tag_t**        instances            /**< (OF) nInstances Array of instance tags found */
    );

/**
    @deprecated #ICS_search_object_ids deprecated in Teamcenter 11.2.2. Use #ICS_ico_search instead.

    Object Id refers to the unique id associated with a classification record (ICO) in the Classification System.
    This function searches for the classification records in the database based on the given query
    and belonging to the given class/view combination.

    <b>Restrictions:</b>

    Since the instances are associated only with the views and the views belong to a specific class,
    this function can be used only for a particular view/class view combination.
*/
TC_DEPRECATED("11.2.2","ICS_search_object_ids","ICS_ico_search")
extern ICS_API int ICS_search_object_ids (
    tag_t          theClass,        /**< (I) Tag of the class */
    tag_t          view,            /**< (I) Tag of the view belonging to the given class */
    char*          query,           /**< (I) Query */
    int*           nInstances,      /**< (O) Number of instances satisfying the search criteria and
                                        belonging to the given class/view combination */
    tag_t**        instances        /**< (OF) nInstances Array of instance tags found */
    );

/**
    This function gets the attributes for the given class or view.

    <b>Restrictions:</b>

    This function cannot be used for groups, as attributes are not defined at group level,
    but defined at class level.
    A view defined below a class inherits some or all of these attributes.
*/
extern ICS_API int ICS_ask_attributes (
    tag_t          classOrView,     /**< (I) Tag of the class or view */
    int*           nAttributes,     /**< (O) Number of attributes defined for the given class or view */
    tag_t**        attributeList    /**< (OF) nAttributes Array of attribute tags */
    );

/**
    @deprecated #ICS_describe_view deprecated in Teamcenter 11.4. Use #ICS_view_describe_view instead.

    Returns the definition of a view given the view tag.

    <b>Restrictions:</b>

    This function can only be used with views.
*/
TC_DEPRECATED("11.4","ICS_describe_view","ICS_view_describe_view")
extern ICS_API int ICS_describe_view (
    tag_t          view,                    /**< (I) Tag of the view */
    int*           nAttributes,             /**< (O) Number of attributes defined for the given view */
    int**          theAttrIDs,              /**< (OF) nAttributes IDs of the attributes */
    int**          theAttrFormats,          /**< (OF) nAttributes Formats of the attributes*/
    char***        theAttrAnnotations,      /**< (OF) nAttributes Annotations of the attributes*/
    char***        theAttrNames,            /**< (OF) nAttributes Names of the attributes*/
    char***        theAttrShortNames,       /**< (OF) nAttributes Short names of the attributes */
    char***        theAttrUnits,            /**< (OF) nAttributes Units of the attributes
                                                (NULL if no unit is defined for the attribute) */
    char***        theUserData1,            /**< (OF) nAttributes  the user data 1 property of the attributes */
    char***        configField,             /**< (OF) nAttributes  */
    char***        theUserData2,            /**< (OF) nAttributes  the user data 2 property of the attributes */
    int**          theFlags                 /**< (OF) nAttributes  the flags of the attributes*/
    );


extern ICS_API int ICS_describe_config_field (
    const char*    configFieldString,   /**< (I) */
    int*           multiField,          /**< (O) */
    logical*       horizontal,          /**< (O) */
    logical*       vertical,            /**< (O) */
    logical*       separator,           /**< (O) */
    logical*       arrow,               /**< (O) */
    logical*       button,              /**< (O) */
    logical*       wide,                /**< (O) */
    logical*       mandatoryFlag,       /**< (O) */
    logical*       protectedFlag,       /**< (O) */
    logical*       uniqueFlag           /**< (O) */
    );

extern ICS_API int ICS_create_view_attributes (
    tag_t          view,                /**< (I) */
    int            nAttributes,         /**< (I) */
    const char**   attributeNames,      /**< (I) */
    tag_t**        attributes           /**< (OF) nAttributes */
    );

extern ICS_API int ICS_create_class_attributes (
    tag_t          theClass,        /**< (I) */
    int            nAttributes,     /**< (I) */
    int*           unctNumbers,     /**< (I) */
    tag_t**        attributes       /**< (OF) nAttributes */
    );

extern ICS_API int ICS_create_view (
    tag_t          theClass,    /**< (I) */
    const char*    viewId,      /**< (I) */
    const char*    viewName,    /**< (I) */
    tag_t*         newView      /**< (O) */
    );

/** @} */

/**
    @name Attribute Functions

    <b>Common Return Values:</b>
    <table>
    <tr><td>#ICS_invalid_attribute   </td><td>UNCT name cannot be NULL.         </td></tr>
    <tr><td>#ICS_invalid_format      </td><td>Invalid format (cannot be 0).     </td></tr>
    <tr><td>#ICS_invalid_attribute_id</td><td>Invalid UNCT number (cannot be 0).</td></tr>
    </table>
    @{
*/

/**
    This function creates a new UNCT (attribute).
    The UNCT number given is an integer that uniquely identifies an attribute in the classification system.
    An UNCT number once created can be used in any class/view definition subject to the condition that
    it can be used only once in a particular class/view definition.
*/
extern ICS_API int ICS_create_unct (
    int            unctNo,      /**< (I) UNCT number that uniquely identifies an attribute */
    const char*    unctName,    /**< (I) Attribute name */
    const char*    shortName,   /**< (I) Attribute short name */
    const char*    unctUnit,    /**< (I) Attribute unit */
    int            unctFormat   /**< (I) Attribute format */
    );

/**
    This function gets the UNCT definition given the UNCT number.
*/
extern ICS_API int ICS_describe_unct (
    int            unctNo,      /**< (I) UNCT number that uniquely identifies an attribute */
    char**         unctName,    /**< (OF) Attribute name */
    char**         shortName,   /**< (OF) Attribute short name */
    char**         unctUnit,    /**< (OF) Attribute unit */
    int*           unctFormat   /**< (O) Attribute format */
    );

/**
    A format defines the type of value that is stored for the attribute.
    This function gets the type of format, modifiers, and the overall length of the formatted value.

    The first digit of a positive format number defines what types of values are expected in the field
    and controls the format of the value. The format number can be up to five digits in length. <br>

    The following figure explains the meaning of the digit in the format number:

    --------------------- <br>
    | 1 | 2 | 3 | 4 | 5 |  <br>
    --------------------- <br>

    <ul>
    <li> digit 5 and 4: Number overall
    <li> digit 3:
        <ul>
        <li> If using real: Number after decimal point
        <li> If using string:
            <ul>
            <li> 0 = Print characters in upper- and lowercase
            <li> 1 = Print all characters in uppercase
            <li> 2 = Print all characters in lowercase
            </ul>
        </ul>
    <li> digit 2:
        <ul>
        <li> 0 = Force positive number
        <li> 1 = Accept and diplay either + or -
        <li> 2 = Accept + or - but display - sign only
        </ul>
    <li> digit 1:
        <ul>
        <li> 0 = String
        <li> 1 = Integer
        <li> 2 = Real
        <li> 3 = Date
            <ul>
            <li> 30000: YYYYMMDDHHMMSS (internal represent)
            <li> 30001: YYMMDDHHMMSS
            <li> 30002: DDMMYYYYHHMMSS
            <li> 30003: DDMMYYHHMMSS
            <li> 30004: DD.MM.YYYY HH:MM:SS
            <li> 30005: DD.MM.YY HH:MM:SS
            <li> 30006: DD.MM.YYYY
            <li> 30007: DD.MM.YY
            <li> 30008: YYMMDD
            <li> 30009: YYYYMMDD
            <li> 30011: MM/DD/YY HH:MM:SS
            <li> 30011: MM/DD/YY
            </ul>
        <li> 4 = Time Range
            <ul>
            <li> 40000: ssssssss (internal represent)
            <li> 40001: HH:MM:SS
            <li> 40002: DD:HH:MM:SS
            </ul>
        </ul>
    </ul>

    For example: If the format passed is 20509, this function returns:

    formatType - 2 <br>
    modifier1  - 0 <br>
    modifier2  - 5 <br>
    length     - 09

    <b>Restrictions:</b>
    This function can only be used on positive formats (> 0).
    If a negative format is passed, this function returns -1 for all output parameters.
    A negative format indicates an attribute with a pop-up list of values.
*/
extern ICS_API int ICS_describe_format (
    int            format,          /**< (I) Format */
    int*           formatType,      /**< (O) An integer that identifies the type (i.e. integer/real/string/date) */
    int*           modifier1,       /**< (O) */
    int*           modifier2,       /**< (O) */
    int*           length           /**< (O) Length */
    );

/**
    This function gets the pop-up definition for a negative format.
    A negative format indicates an attribute with pop-up list of values.
    A pop-up list of values can be associated with an attribute such that
    when a user clicks the down arrow in the attribute field,
    a list of legal values for that attribute is displayed.
    Pop-up lists are used when an attribute has a finite set of legal values.
    The pop-up list is more efficient than manual entry because it
    eliminates the need for the user to memorize the legal values.
    Pop-up lists also enforce consistency.
    Each of the values in the pop-up list is identified by a keyword (optionId) and a value (optionValue).

    Refer to Teamcenter Classification Administration Help for additional information on formats.

    <b>Restrictions:</b>

    This function can only be used on negative formats (< 0),
    as pop-up list of values are associated only with negative formats.
*/
extern ICS_API int ICS_get_popup_definition (
    int            format,          /**< (I) Format */
    int*           count,           /**< (O) Count of the list of values for this format */
    char***        optionIds,       /**< (OF) count Keywords for each of the pop-up list of values */
    char***        optionValues     /**< (OF) count Values for each of the pop-up list of values */
    );

/** @} */

/**
    @name ICO Functions

    <b>Common Return Values:</b>
    <table>
    <tr><td>#ICS_cannot_classify_wso         </td><td>The workspace object cannot be classified              </td></tr>
    <tr><td>#ICS_empty_resource_id           </td><td>Object id (Resource Id) cannot be empty                </td></tr>
    <tr><td>#ICS_find_relation_failed        </td><td>Given workspace object does not have any objects
                                                      associated with it by the relation IMAN_classification.</td></tr>
    <tr><td>#ICS_ico_does_not_exist          </td><td>No classification object exists for the given workspace object
                                                      or the classification object has been deleted for
                                                      this workspace object.                                 </td></tr>
    <tr><td>#ICS_invalid_class               </td><td>Invalid class (cannot be #NULLTAG)                     </td></tr>
    <tr><td>#ICS_invalid_ico                 </td><td>Invalid classification object (cannot be #NULLTAG)     </td></tr>
    <tr><td>#ICS_invalid_view                </td><td>Invalid view (cannot be #NULLTAG)                      </td></tr>
    <tr><td>#ICS_invalid_wso                 </td><td>Invalid workspace object (cannot be #NULLTAG)          </td></tr>
    <tr><td>#ICS_relation_type_does_not_exist</td><td>Relation type (IMAN_classification) does not exist     </td></tr>
    <tr><td>#ICS_wso_already_classified      </td><td>The workspace object has already been classified       </td></tr>
    <tr><td>#ICS_wso_does_not_exist          </td><td>The given classification object is not associated with
                                                      any workspace object                                   </td></tr>
    <tr><td>#ICS_wso_not_classified          </td><td>The given workspace object has not been classified     </td></tr>
    </table>
    @{
*/

/**
    This function checks whether the given workspace object has been classified or not.
*/
extern ICS_API int ICS_is_wsobject_classified (
    tag_t          wsObject,        /**< (I) Workspace object */
    logical*       isClassified     /**< (O) True if classified, False if not */
    );

extern ICS_API int ICS_is_wsobject_classifiable (
    tag_t          wsObject,            /**< (I) */
    logical*       isClassifiable       /**< (O) */
    );

/**
    This function classifies the given workspace object, i.e. it associates the workspace object with
    the given classification object using the IMAN_classification relation.
    The classification object should be created using ICS_create_classification_object() prior to using this function.
    To set the attributes for the classification object, refer to ICS_set_values_for_classification_obj().
*/
extern ICS_API int ICS_classify_wsobject (
    tag_t          wsObject,                /**< (I) Workspace object */
    tag_t          classificationObject     /**< (I) Classification object */
    );

/**
    This function removes the relation (IMAN_classification relation) between the given
    workspace object and the associated classification object.
    The classification object also gets deleted.
    Once the classification object has been deleted, there is no way to retrieve it.

    If you don't want the ICO to be deleted, take a look at ICS_delete_reference_to_ico().

    Refer to ICS_delete_reference_to_wsobject() to delete only the relation between the
    workspace object and the classification object.
*/
extern ICS_API int ICS_remove_classification (
    tag_t          wsObject     /**< (I) Workspace object */
    );

/**
    This function deletes the reference (identified by the IMAN_classification relation)
    between the given workspace object and the associated classification object.

    @note This does not delete the classification object.
    Refer to ICS_remove_classification() to delete the classification object as well as the relation.
*/
extern ICS_API int ICS_delete_reference_to_wsobject (
    tag_t          wsObject     /**< (I) Workspace object */
    );

/**
    This function deletes the reference (identified by the IMAN_classification relation)
    between the given classification object and the associated workspace object.

    It doesn't remove the ICO. Be careful while using this routine,
    as the ICO doesn't get deleted, and exists as a standalone ICO.
*/
extern ICS_API int ICS_delete_reference_to_ico (
    tag_t          classificationObject     /**< (I) Classification object */
    );

/**
    This function deletes the given classification object from the classification system as long as
    it is not referenced by other objects. Deletion of the classification object can be done in two ways:

    <ul>
    <li>Using ICS_remove_classification() passing the workspace object,
        which deletes the relation as well as the associated classification object.
    <li>Using ICS_delete_reference_to* () first to delete the reference.
        Use ICS_delete_classification_object() passing the classification object to delete the classification object.
    </ul>
*/
extern ICS_API int ICS_delete_classification_object (
    tag_t          classificationObject     /**< (I) Classification object */
    );

/**
    For the given classification object, this function gets the associated workspace object if
    the classification object is associated with a workspace object.
*/
extern ICS_API int ICS_ask_classified_wsobject (
    tag_t          classificationObject,    /**< (I) Classification object */
    tag_t*         classifiedWSObject       /**< (O) Associated workspace object tag if an association exists else #NULLTAG */
    );

/**
    For the given workspace object,
    this function gets the associated classification object if the workspace object is classified.
*/
extern ICS_API int ICS_ask_classification_object (
    tag_t          wsObject,                /**< (I) Workspace object */
    tag_t*         classificationObject     /**< (O) Associated classification object tag if the given
                                                workspace object is classified. #NULLTAG if not classified */
    );

/**
    This creates a new classification object given the object id, view/class tag, and the workspace object.

    If ws_object is not #NULLTAG, the ICO will classify this object.
    In this case the object_id will be ignored, but the Id of the ws_object will be used as the ICO id.

    If ws_object is #NULLTAG, an ICO will be created with object_id as it's id.

    NOTE: If you want to create an ICO for classes which support both unit systems please use ICS_ico_create (ics2.h).
    This functions creates only metric ICOs.
*/
extern ICS_API int ICS_create_classification_object (
    tag_t          ws_object,             /**< (I) Workspace object */
    const char*    object_id,             /**< (I) Id for the classification object */
    tag_t          view_or_class_tag,     /**< (I) View tag or class tag to which the classification object should belong */
    tag_t*         classification_object  /**< (O) Classification object tag */
    );

/**
    This function gets the class to which the given classification object belongs.
*/
extern ICS_API int ICS_ask_class_of_classification_obj (
    tag_t          classificationObject,    /**< (I) Classification object tag */
    tag_t*         theClass                 /**< (O) Class tag to which the classification object belongs */
    );

/**
    This function gets the view to which the given classification object belongs.
*/
extern ICS_API int ICS_ask_view_of_classification_obj (
    tag_t          classificationObject,    /**< (I) Classification object tag */
    tag_t*         view                     /**< (O) View tag to which the classification object belongs */
    );

/**
    This function gets the object id given the classification object.
*/
extern ICS_API int ICS_ask_classification_object_id (
    tag_t          classificationObject,    /**< (I) Classification object tag */
    char**         objectId                 /**< (OF) Classification object id */
    );

/**
    This function gets the classification object tag given the object id, class and view to which it belongs.
*/
extern ICS_API int ICS_ask_classification_instance_tag (
    tag_t          theClass,                /**< (I) Class to which the classification object belongs */
    tag_t          theView,                 /**< (I) View to which the classification object belongs */
    char*          classificationObjectId,  /**< (I) Classification object id */
    tag_t*         classificationInstance   /**< (O) Classification object tag */
    );

/**
    This function gets the class and view Id to which the classification object belongs.
*/
extern ICS_API int ICS_ask_cid_sid_of_classification_obj (
    tag_t          classificationObject,    /**< (I) Classification object tag */
    char**         classId,                 /**< (OF)  */
    char**         viewId                   /**< (OF)  */
    );

/**
    This function gets the name-value pairs of the attributes for the given classification object.
*/
extern ICS_API int ICS_ask_attributes_of_classification_obj (
    tag_t          classificationObject,    /**< (I) Classification object tag */
    int*           nAttributes,             /**< (O) Number of attributes */
    char***        attributeNames,          /**< (OF) nAttributes Attribute names */
    char***        attributeValues          /**< (OF) nAttributes Attribute values */
    );

/**
    For ICO's <br>
    Please note: - KeyLov attributes returns only the key <br>
                 - If attributeName is an Integer it will be used as attribute ID for the search <br>
                 - If the attributeName is not unique in the class, the first match which are accessible through the user specific view will be returned. <br>

    For efficiency reasons please use ICS_ico_ask_attributes() defined in ics2.h
*/
extern ICS_API int ICS_ask_attribute_value (
    tag_t          classificationObject,    /**< (I) */
    const char*    attributeName,           /**< (I) */
    char**         attributeValue           /**< (OF) */
    );

/**
    Function to get the complete details about a classification object.
*/
extern ICS_API int ICS_describe_classification_object (
    tag_t          classificationObject,    /**< (I) Classification object tag */
    tag_t*         view,                    /**< (O) View tag to which the classification object belongs */
    int*           nAttributes,             /**< (O) Number of attributes for the classification object */
    int**          unctNumbers,             /**< (OF) nAttributes UNCT numbers of the attributes */
    int**          unctFormats,             /**< (OF) nAttributes Formats of the attributes */
    char***        attributeNames,          /**< (OF) nAttributes Attribute names */
    char***        attributeValues,         /**< (OF) nAttributes Attribute values */
    char***        units                    /**< (OF) nAttributes Attribute units */
    );

/**
    For ICO's
*/
extern ICS_API int ICS_set_values_for_classification_obj (
    tag_t          classificationObject,    /**< (I) */
    int            nAttributes,             /**< (I) */
    const char**   attributeNames,          /**< (I) */
    const char**   attributeValues          /**< (I) */
    );

/**
    Function to get the type of the object passed. Type can be one of the following:

    <table>
    <tr><td>#ICS_type_group     </td><td>#ICS_type_class    </td><td>#ICS_type_view</td></tr>
    <tr><td>#ICS_type_class_attr</td><td>#ICS_type_view_attr</td><td>#ICS_type_unctdict</td></tr>
    <tr><td>#ICS_type_stxt      </td><td>#ICS_type_data     </td><td>#ICS_type_unknown</td></tr>
    </table>
*/
extern ICS_API int ICS_ask_type (
    tag_t          object,      /**< (I) Object tag */
    int*           objectType   /**< (O) Object type */
    );

/** @} */

/**
    For Group / Class / View
*/
extern ICS_API int ICS_ask_image (
    tag_t          groupOrClassOrView,      /**< (I) */
    tag_t*         datasetTag               /**< (O) */
    );


extern ICS_API int ICS_save_ico_by_rtico(
    tag_t          attrSyncTag      /**< (I)  Tag of the ico runtime ico */
    );

extern ICS_API int ICS_cancel_ico_by_rtico(
    tag_t          objTag   /**< (I) Tag of the ics runtimeIco object  */
    );

extern ICS_API int ICS_classid_is_valid(
    char*          cid,     /**< (I) ClassID */
    char*          sid,     /**< (I) SubclassID */
    logical*       valid    /**< (O) Flag to indicate the validity */
    );

extern ICS_API int ICS_is_tag_ics_runtime_obj(
    tag_t          obj,                 /**< (I) */
    logical*       is_an_ics_rt_obj     /**< (O) */
    );

/**
    This function receives the new Workspace object, an Item/ItemRev/Dataset, created from the UG/Manager,
    it fires a component creation event to notify the Teamcenter Portal.
*/
extern ICS_API int ICS_receive_obj_created_from_nxmgr(
    tag_t          item_tag,        /**< (I) The tag to the newly created Item or the original Item. */
    tag_t          itemrev_tag,     /**< (I) The tag to the newly created ItemRev object or the ItemRev
                                        object where the newly created dataset is attached.. */
    tag_t          dataset_tag,     /**< (I) The tag to the newly created dataset object or the dataset
                                        object attached under the newly created Item or ItemRev. */
    int            creation_type    /**< (I) The integer flag indicating what type of object is created,
                                        1 means a new Item is created, 2 means a new ItemRev is created,
                                        3 means a new dataset is created. */
    );

#if 0
extern ICS_API int ICS_sendObjects(
    char           theSite[SML_LONG_SITE_NAME_SIZE + 1],     /**< (I) */
    int            theObjectCount,                  /**< (I) */
    tag_t*         theObjectTags                    /**< (I) */
    );
#endif
/*
**  Ensure all Classification hierarchy objects are synchronized to all or the given sites.
**  If no sites are given all sites will be synchronized
*/
extern ICS_API int ICS_share_pending( int theSitesCount, const char** theSites, int theverbosity );


/*-----------------------------------------------------------------------------
 The enums for the Object Types
 Wherever applicable, Multiple Object types can be combined
   using the '|' (bitwise OR) operator
-----------------------------------------------------------------------------*/
typedef enum ICS_objectType_s
{
    ICS_ObjectType_unknown    = 0,
    ICS_ObjectType_keylov     = ( 1 << 0 ),
    ICS_ObjectType_attribute  = ( 1 << 1 ),
    ICS_ObjectType_class      = ( 1 << 2 ),
    ICS_ObjectType_view       = ( 1 << 3 ),
    ICS_ObjectType_instance   = ( 1 << 4 ),
    ICS_ObjectType_userclass  = ( 1 << 5 ),
    ICS_ObjectType_all        = (( 1 << 0 ) |
                                 ( 1 << 1 ) |
                                 ( 1 << 2 ) |
                                 ( 1 << 3 ) |
                                 ( 1 << 4 ) |
                                 ( 1 << 5 ) ),
    ICS_ObjectType_max
} ICS_objectType_t, *ICS_ObjectType_p_t;

/**
    @name XML Import/Export Functions

    The following ITK functions are used to support the XML import and export of Classification data.
    @{
*/

/**
    Enums for Export Options. Currently this is applicable only to 'Class' objects.
    When export functions are called for an object of type class,
    these options can be given in the Export-Options parameter.
    If necessary, these options can be combined using '|' (bitwise OR) operator.
*/
typedef enum
{
    ICS_xmlexport_this              = 0,
    ICS_xmlexport_parent            = ( 1 << 1  ),  /**< 1 */
    ICS_xmlexport_parentview        = ( 1 << 2  ),  /**< (#ICS_xmlexport_parent \<\< 1) + #ICS_xmlexport_parent */
    ICS_xmlexport_subclass          = ( 1 << 3  ),  /**< (#ICS_xmlexport_parent \<\< 2) */
    ICS_xmlexport_subclassview      = ( 1 << 4  ),  /**< (#ICS_xmlexport_subclass \<\< 1) + #ICS_xmlexport_subclass */
    ICS_xmlexport_Hierarchy         = ( 1 << 5  ),  /**< (#ICS_xmlexport_subclass \<\< 2 ) + #ICS_xmlexport_parent */
    ICS_xmlexport_parentinstance    = ( 1 << 6  ),  /**< (#ICS_xmlexport_subclass \<\< 3) + #ICS_xmlexport_parent */
    ICS_xmlexport_subclassinstance  = ( 1 << 7  ),  /**< (#ICS_xmlexport_subclass \<\< 4) + #ICS_xmlexport_subclass */
    ICS_xmlexport_instancexml       = ( 1 << 8  ),  /**< (#ICS_xmlexport_subclass \<\< 5) */
    ICS_xmlexport_instanceschema    = ( 1 << 9  ),  /**< (#ICS_xmlexport_subclass \<\< 6) */
    ICS_xmlexport_usermode          = ( 1 << 10 )

} ICS_xmlExport_Option_t;

/**
    Enum for Hook Events
*/
typedef enum
{
    ICS_xml_hook_create  = 1,   /**< When any in-CLASS object is created in Import */
    ICS_xml_hook_update  = 2,   /**< When any in-CLASS object is updated in Import */
    ICS_xml_hook_export = 3     /**< When any in-CLASS object is exported */

} ICS_xml_hook_id_t, *ICS_xml_hook_id_p_t;

/**
    Enum for Types of exits for calling Hook-functions
*/
typedef enum
{
    ICS_xml_hook_pre  = 1,       /**< Before any Hook Event */
    ICS_xml_hook_post  = 2,      /**< After any Hook Event */
    ICS_xml_hook_cancel  = 3     /**< On cancelling between 'pre' and 'post' exits */
} ICS_xml_hook_type_t, *ICS_xml_hook_type_p_t;

/**
    This reports a failure for the specific object.
    In case of a pre hook the import/export for the current object is canceled.
*/
#define ICS_xml_hook_cancel_object  1

/**
    This reports a failure for the whole import/export operation.
    The whole subsequent operation is canceled for this functionality.
*/
#define ICS_xml_cancel      2

/**
    The signature of any user defined hook function.
    The parameters are passed with the actual values when this functions is
    invoked by the XML Import/Export for the specified Hook Event Exits
*/
typedef int (*ICS_xml_hook_t)(
    ICS_xml_hook_id_t    theHookId,
    ICS_xml_hook_type_t  preOrPost,
    int                  theObjectType,
    const char*          theObjectId
    );

/**
    This function registers the given hook function for the subsequent calls to #ICS_xml_import / #ICS_xml_export functions.
    This given function theHookFn will be registered for the specified operation theHookId.
    The registered hook functions are called before and after the specified operation.

    This function can be used to register separate hook functions for each of the operations mentioned in #ICS_xml_hook_id_t.

    If the value for theHookFn is NULL, then this function will reset and clear the previously registered
    hook function for the given theHookId event.

    Always returns #ITK_ok
*/
extern ICS_API int ICS_xml_register_hook(
    ICS_xml_hook_id_t  theHookId,     /**< (I) The specific event for which the hook function is registered */
    ICS_xml_hook_t     theHook        /**< (I) The user-defined function that is to be registered as the hook function */
    );

/**
    This function imports the Classification data from a specific XML file into Teamcenter.
    The XML file should contain the Classification data in a format that complies with
    the Classification XML schema definition file, in-class.xsd, located in the TC_DATA directory.

    <b>Restrictions:</b>

    This method will validate the given XML file against the in-class.xsd schema file,
    and fails if the content of the XML file is invalid.
*/
extern ICS_API int ICS_xml_import(
    const char*    theXMLFileName,          /**< (I) The file path of the XML file */
    int            theObjectTypeFilter,     /**< (I) Integer that specifies the object types to be considered for the import.
                                                This could be the combination of one or more types
                                                defined in the enum #ICS_objectType_t.
                                                It could also be #ICS_ObjectType_all to import any type of object */
    logical        theUpdateFlag,           /**< (I) Flag that enables the import to update existing objects.
                                                If TRUE, the method will try to update the object if it already exists.
                                                If FALSE, it will ignore importing any data for the existing objects */
    logical        theRelatedCreationFlag   /**< (I) Allows the function to create related Teamcenter objects
                                                for the imported Classification objects */
    );

/**
    This function get the Teamcenter in-CLASS objects and export the in-CLASS objects
    definition data to the XML file in the specified physical location
*/
extern ICS_API int ICS_xml_export(
    const char*       theXMLFileName,       /**< (I) The XML File to be generated */
    ICS_objectType_t  nObjType,             /**< (I) Type of the given Object */
    const char*       theId,                /**< (I) ID of the given object */
    int               theObjectTypeFilter,  /**< (I) Integer representing the combination of the types of objects for export<br>
                                                     Possible values for "theObjectTypeFilter" are:<br>
                                                     ICS_ObjectType_keylov | ICS_ObjectType_attribute | ICS_ObjectType_class<br>
                                                     | ICS_ObjectType_view | ICS_ObjectType_instance <br>
                                                     ICS_ObjectType_userclass<br>
                                                     ICS_ObjectType_all */
    int               theExportOptions      /**< (I)Integer representing export Options. <br>
                                                     Currently this is applicable only to 'Class' objects in "theObjectTypeFilter". <br>
                                                     When export functions are called for an object of type class,<br>
                                                     these options can be given in the Export-Options parameter.<br>
                                                     If necessary, these options can be combined using '|' (bitwise OR) operator.<br>
                                                     Possible values for "theExportOptions" are:<br>
                                                     ICS_xmlexport_this <br>
                                                     ICS_xmlexport_parent <br>
                                                     ICS_xmlexport_parentview <br>
                                                     ICS_xmlexport_subclass <br>
                                                     ICS_xmlexport_subclassview <br>
                                                     ICS_xmlexport_Hierarchy <br>
                                                     ICS_xmlexport_parentinstance <br>
                                                     ICS_xmlexport_subclassinstance <br>
                                                     ICS_xmlexport_instancexml <br>
                                                     ICS_xmlexport_instanceschema */
     );

#if 0
/**
    To Export in-CLASS object by their tags

    Not implemented now
*/
extern ICS_API int ICS_xml_export(
    const char*    theXMLFileName,          /**< (I) */
    int            n_objectsToExport,       /**< (I) */
    tag_t*         theObjectsToExport,      /**< (I) */
    int            theObjectTypeFilter      /**< (I) */
    );
#endif

/**
    This function returns the children of the given class
    in form of an XML element or document
*/
extern ICS_API int ICS_xml_ask_children(
    const char*    theParentId,     /**< (I) */
    int            theLevelCount,   /**< (I) */
    logical        theAdminMode,    /**< (I) */
    int            theSortOption,   /**< (I) */
    logical        theXMLOption,    /**< (I) */
    char**         theChildren      /**< (OF) */
    );

/** @} */

/**
    This function returns the ICOs with ID theIcoId.
*/
ICS_API int ICS_ask_instances_by_id(
    const char* theIcoId,           /**< (I) */
    int*        theCount,           /**< (O) */
    tag_t**     theInstanceTags     /**< (OF) theCount */
    );

/**
    This function returns the formatted value for the given format.
-----------------------------------------------------------------------------*/
extern ICS_API int ICS_format_value(
    int            howToFormat,         /**< (I) Possible values for howToFormat are:
                                                <ol>
                                                <li>format external search string to internal
                                                <li>format value from external to internal
                                                <li>format internal value to external
                                                <li>to format a search string back to external
                                                </ol> */
    int            theFormat,           /**< (I) */
    const char*    theMinValue,         /**< (I) */
    const char*    theMaxValue,         /**< (I) */
    const char*    theValue,            /**< (I) */
    char**         theFormattedValue    /**< (OF) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ics/libics_undef.h>
#endif
