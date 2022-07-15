/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the ANSI C interface to Teamcenter Engineering properties
*/

/*  */

#ifndef PROP_H
#define PROP_H

#include <unidefs.h>

#include <pom/pom/pom_tokens.h>
#include <property/propdesc.h>
#include <property/prop_msg.h>

#include <property/libproperty_exports.h>

/**
    @defgroup PROP Properties

    A property is a piece of information kept about an object of a particular type.
    @{
*/

#define PROP_NAME_DISPLAY_PREF          "PROP_Show_Actual_Names"

#define PROP_DISPLAY_PRESENTATION_NAMES 1
#define PROP_DISPLAY_ACTUAL_NAMES       2

#ifdef __cplusplus
 extern "C"{
#endif




/**
    @name Property functions that get their value from the Property Descriptor

    There is a duplicate PROPDESC_ function for each of these.
    @{
*/

/**
    Ask the type that the property defines.
*/
extern PROPERTY_API int PROP_ask_object_type(
    tag_t               prop_tag,   /**< (I) The tag of the property */
    tag_t*              type_tag    /**< (O) The tag of the type */
    );


/** @} */

/**
    @name Properties User Interface

    This section defines ITK to support specifically to support User Interface (UIF) functionality on properties.
    @{
*/


extern PROPERTY_API int PROP_UIF_is_enabled(
    tag_t               prop_tag,   /**< (I) */
    logical*            is_enabled  /**< (O) */
    );


extern PROPERTY_API int PROP_UIF_list_displayable_properties(
    tag_t               object_tag,     /**< (I) */
    int*                num,            /**< (O) */
    tag_t**             prop_tags       /**< (OF) num */
    );

extern PROPERTY_API int PROP_list_common_modifiable_properties(
    int                 object_count,   /**< (I) */
    tag_t*              object_tags,    /**< (I) */
    int*                prop_count,     /**< (O) */
    char***             prop_names      /**< (OF) prop_count */
    );

extern PROPERTY_API int PROP_is_property_localizable(
    tag_t               object_tag,      /**< (I) */
    char*               prop_name,      /**< (I) */
    logical*            is_localizable  /**< (O) */
    );

/**
    This call returns the Composite Property value for an Teamcenter Engineering component.

    A Composite Property of an object defines a path to associated objects,
    with potentially multiple levels of indirection,
    resulting in an evaluation of a regular property on that or these associated object(s).

    The syntax of a composite property is:

    [objectTypeName.][referenceProperty[(criteriaProperty=criteriaValue[,criteriaProperty=criteriaValue]):][referenceProperty[(criteriaProperty=criteriaValue[,criteriaProperty=criteriaValue])]:]]property

    where:
    <UL>
    <LI>objectTypeName is a regular Teamcenter Engineering object type name (e.g. UGMASTER).
    <LI>referenceProperty is either a typed_reference, untyped_reference, typed_relation, or an untyped_relation.
    <LI>criteriaProperty can be any valid Composite Property (recursion). 
        If specified it is taken as a criteria list in case the above referenceProperty is ambiguous.
    <LI>property is any regular Teamcenter Engineering property name.
    <LI>the notation "[" indicates optional elements, and is not part of Composite Property itself.
    </UL>
    Examples:
    <UL>
    <LI>object_type evaluates the regular property 'object_type'.
        This illustrates that each regular property is also a perfectly valid Composite Property.
    <LI>item_master_tag:product_year evaluates the property 'product_year' on the ItemRevision Master of an Item Revision.
    <LI>item_tag:item_master_tag:Project_ID evaluates the property Project_ID on the Item Master of the Item of an Item Revision.
    <LI>item_tag:IMAN_master_form(object_type=MyCustomItemForm):MyCustomProperty evaluates the property MyCustomProperty of 
        all objects in the IMAN_master_form pseudo folder of the Item of an Item Revision, 
        that have the object type "MyCustomItemForm", returning all values in a comma separated list.
    <LI>ItemRevision Master.revision_list:item_master_tag:Project_ID evaluates the property Project_ID on each
        Item Revision of a given Item. In case 3 Item Revision share the same Project ID 3200, 
        these duplicated values are shown as '3200 (x3)'.
        A list of values is separated by a comma and a blank character.
        The prefix ItemRevision Master indicates that the ultimate physical property is
        actually on an object of type ItemRevision Master.
    </UL>

    <b>Restrictions: </b>

    Each intermediate step in the chain of properties references the next related object(s) in the path. 
    Except for the last property, they must by specified by either a:
    <UL>
    <LI>typed_reference
    <LI>untyped_reference
    <LI>typed_relation
    <LI>untyped_relation
    </UL>
*/
extern PROPERTY_API int PROP_ask_composite_property(
    tag_t          component,           /**< (I) Component for which the Composite Property is to be evaluated */
    const char*    composite_property,  /**< (I) Composite Property to evaluate */
    char**         value                /**< (OF) Returned property value */
    );

/**
    This call returns an array of related Teamcenter Engineering components pointed to be a 
    Composite Property value for a given Teamcenter Engineering component.
    See also PROP_ask_composite_property().

    <b>Restrictions: </b>

    Each intermediate step in the chain of properties references the next related object(s) in the path.
    Except for the last property, they must by specified by either a
    <UL>
    <LI>typed_reference
    <LI>untyped_reference
    <LI>typed_relation
    <LI>untyped_relation
    </UL>
*/
extern PROPERTY_API int PROP_ask_composite_property_objs(
    tag_t          component,               /**< (I) Component for which the Composite Property is to be evaluated */
    const char*    composite_property,      /**< (I) Composite Property to evaluate */
    int*           n_related_components,    /**< (O) The number of returned components in related_components */
    tag_t**        related_components       /**< (OF) n_related_components The array of components pointed to by the 
                                                    Composite Property */
    );


/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <property/libproperty_undef.h>

#endif
