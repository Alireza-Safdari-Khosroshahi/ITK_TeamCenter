/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2013.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file lbr_itk.h
    File that contains the exposed ITKs for Library Management.
    The ITKs include ones for managing and configuring Libraries,
    adding, removing and using data from the Library, and
    searching for objects in the Library.
*/

#ifndef LBR_ITK_H
#define LBR_ITK_H

#include <tc/tc_startup.h>
#include <unidefs.h>
#include <Lbr0librarymgmt/liblbr0librarymgmt_exports.h>


/**
    @defgroup LBRMGMT Library Management

    Libraries provide control of how reusable components are managed and 
    Instantiated into Designs. Libraries are organized in a hierarchical structure 
    similar to Classification, such that a Library is composed of one or more 
    Hierarchies with each having child Nodes. This module deals with all aspects 
    related to managing the structure and configuration of Libraries, 
    using Library Elements in Designs and browsing & searching Libraries.

    To use these functions, include lbr_itk.h.
    @{
*/

/**
This value can be used for the clone_option parameter in #LBR_clone.
In case this value is set, all the children of the current object will be cloned.
*/
#define LBR_CLONE_CHILDREN           ( 1 << 0 )

/**
This value can be used for the clone_option parameter in #LBR_clone.
In case this value is set, all the configurations of the current object will be cloned.
*/
#define LBR_CLONE_CONFIGURATIONS      ( 1 << 1 )

/**
This value can be used for the clone_option parameter in #LBR_clone.
In case this value is set, all the Library Elements of the Node will be cloned.
*/
#define LBR_CLONE_ELEMENTS           ( 1 << 2 )

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Creates an instance of a Library.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_required_prop_not_set if a property required for creation (like name) was not specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_library(
    const char*     library_id,             /**< (I) The ID of the Library to create. If empty string is specified, an ID would be auto-generated. */
    const char*     library_name,           /**< (I) The name of the Library. An empty string cannot be specified. */
    const char*     library_description,    /**< (I) The description of the Library. */
    tag_t*          library                 /**< (O) The created Library instance. */
    );

/**
    Creates an instance of a Library Hierarchy.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_required_prop_not_set if a property required for creation (like name) was not specified.
    <li>#CXPOM_wrong_class if library specified is not valid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_hierarchy(
    const char*     hierarchy_id,           /**< (I) The ID of the Library Hierarchy to create. If empty string is specified, an ID would be auto-generated. */
    const char*     hierarchy_name,         /**< (I) The name of the Library Hierarchy. An empty string cannot be specified. */
    const char*     hierarchy_description,  /**< (I) The description of the Library Hierarchy. */
    tag_t           library,                /**< (I) The Library in which the Hierarchy is to be created. */
    tag_t*          hierarchy               /**< (O) The created Library Hierarchy instance. */
    );

/**
    Creates a new Library Node within a Library Hierarchy.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_required_prop_not_set if a property required for creation (like name) was not specified.
    <li>#CXPOM_wrong_class if the specified input for hierarchy, parent_node or cls_node are not of the required type.
    <li>#LBR_err_invalid_parent_node if the specified parent_node is not part of the hierarchy specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_node(
    const char*     node_id,                /**< (I) The ID of the Library Hierarchy Node to create. If empty string is specified, an ID would be auto-generated. */
    const char*     node_name,              /**< (I) The name of the Hierarchy Node. An empty string cannot be specified. */
    const char*     node_description,       /**< (I) The description of the Hierarchy Node. */
    tag_t           hierarchy,              /**< (I) The Library Hierarchy to which this node belongs. */
    tag_t           parent_node,            /**< (I) The parent Node of this Node being created. If not specified, this indicates that a �top-level� node should be created directly under the Library Hierarchy. */
    tag_t           cls_node,               /**< (I) The Classification Node reference for this Library Node. If not specified, a �General� Library Node will be created. */
    tag_t*          node                    /**< (O) The created Library Hierarchy Node instance. */
    );

/**
    Creates a Library Node Hierarchy using a source Classification Node. 
    <br/>For each Node from the Classification hierarchy, starting with classification_node, 
    a corresponding Classifying Node in the Library is created.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_hierarchy if the specified input for hierarchy is not of the right type.
    <li>#LBR_err_invalid_classification_node if the specified input for classification_node is not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_node_hierarchy(
    tag_t           hierarchy,              /**< (I) The Library Hierarchy under which the Node hierarchy is to be created. */
    tag_t           parent_node,            /**< (I) The parent Node under which the new Node hierarchy will be created. */
    tag_t           classification_node     /**< (I) The Classification Node which will be used as the source top Node for the new Node hierarchy. */
    );

/**
    Deletes the specified Library Management object.
    <br/>Only the following objects can be deleted using this ITK: Library, Hierarchy, Node.

    @returns
    <ul>
    <li>#ITK_ok on success.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_delete(
    tag_t           object_tag,             /**< (I) The object to be deleted. */
    logical         delete_content,         /**< (I) Indicates whether to delete all content recursively. */
    logical         continue_on_error       /**< (I) Indicates whether to continue deleting if an error is encountered for some object. */
    );

/**
    Adds an object (typically an image) as a "Representation" of a Library Node.
    <br/>An "intent" can be specified while creating this representation, that can be later used to retrieve the intent-specific representation.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the specified input for library_node is not of the right type.
    <li>#LBR_err_already_has_intent_representation if the specified Library Node already has the Representation for the specified intent.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_representation(
    tag_t           library_node,           /**< (I) The Library Node for which the object should be added as the "Representation". */
    const char*     intent,                 /**< (I) The "intent" of the Representation. Ex: "Logical Block". This can be any user-defined string. */
    tag_t           object,                 /**< (I) The object to add as the Representation */
    tag_t*          relation                /**< (O) The created Representation relation */
    );

/**
    Retrieves an object (typically an image) as a "Representation" of a Library Node or a Library Element.
    <br/>Retrieving the representation from a Library Element fetches it from its Owning Node.
    <br/>Retrieving the representation from a Library Node fetches the object from the Node, if available.
    <br/>If no representation with the given intent is available on the Node, all ancestor Nodes are searched.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the specified input for object is not of the required types.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_representation(
    tag_t           object,                 /**< (I) The object ( Library Node or Library Element ) for which the "Representation" object is required. */
    const char*     intent,                 /**< (I) The "intent" of the Representation. Ex: "Logical Block". This can be any user-defined string. */
    tag_t*          representation          /**< (O) The object as the Representation. */
    );

/**
    Creates a "General Option" for Library Management. 

    <br/>General Options are used to configure the behavior of a Library for various aspects. 
    <br/>For example: configure what types of objects are allowed to be added to the Library using 
    a General Option with option_id: "AllowedMemberTypes".

    <br/>The list of valid option_id's is configured using an out-of-the-box LOV "Lbr0ValidGeneralOptions".
    The object provided in the parameter @p configured_object should be of one of the following types: Library, Hierarchy, Node. 

    <br/>General Options can be defined at any level in the Library hierarchy structure.
    Options defined at a higher level are inherited by all descendant levels, until overridden.
    <br/>For example: defining AllowedMemberTypes at the Library level means that this will apply for the entire Library.
    <br/>Overriding this option at a Node level means that the overridden values are applicable to that Node and all its descendants only.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_required_prop_not_set if a property required for creation (like option_id) was not specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_general_option(
    tag_t           configured_object,      /**< (I) The Object for which this General Option applies. */
    const char*     option_id,              /**< (I) The unique Id of the option. */
    int             num_values,             /**< (I) The number of values for the option. */
    const char**    values,                 /**< (I) num_values The values for the option. */
    const char*     description,            /**< (I) The description for this General Option.*/
    tag_t*          general_option          /**< (O) The created General Option. */
    );

/**
    Sets the General Option for the specified object.
    <br/>The list of valid option_id's is configured using an out-of-the-box LOV "Lbr0ValidGeneralOptions".
    <br/>The object provided in the parameter @p configured_object should be of one of the following types: Library, Hierarchy, Node. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_configured_object if the configured_object is not a valid one.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_set_general_options(
    tag_t           configured_object,      /**< (I) The object for which the option applies. */
    const char*     option_id,              /**< (I) The unique Id of the option. */
    int             num_values,             /**< (I) The number of values for the option. */
    const char**    values,                 /**< (I) num_values The values for the option. */
    const char*     description             /**< (I) The description of the general option. */
    );

/**
    Retrieves the General Option configured for the specified object.
    <br/>The list of valid option_id's is configured using an out-of-the-box LOV "Lbr0ValidGeneralOptions".
    <br/>The object provided in the parameter @p configured_object should be of one of the following types: Library, Hierarchy, Node. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_configured_object if the configured_object is not a valid one.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_general_options(
    tag_t           configured_object,      /**< (I) The object for which the option is required. */
    const char*     option_id,              /**< (I) The unique Id of the option. */
    logical         get_derived,            /**< (I) Indicates if the option values should be fetched from "ancestor" objects in case it is not defined on the specified object. */
    int*            num_values,             /**< (O) The number of values for the option. */
    char***         option_values,          /**< (OF) num_values The values for the option. */
    tag_t*          derived_from            /**< (O) The configured object to which the option values are associated. */
    );

/**
    Assigns a Library to a Context.
    <br/>A Context can be a Project/Program or a 4GD Design Context.
    <br/>In general, a Library can be assigned to any number of contexts.
    If a Library needs to be exclusively available to only a given Context, then the is_owning parameter should be set to true.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_library_already_associated if the Library is already associated with a Context that is owning.
    <li>#LBR_err_library_already_owned if owning is passed in as true and the Library is already owned by a Context.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_assign_context(
    tag_t           library,                /**< (I) The Library to assign to the Context. */
    tag_t           context,                /**< (I) The Context to which the Library is to be assigned. */
    logical         is_owning               /**< (I) Specifies whether the Library is exclusively owned by the Context. */
    );

/**
    Removes a Library from a Context. 
    <br/>A Context can be a Project/Program or a 4GD Design Context.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_library_not_assigned_to_context if the Library is not assigned to the Context.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_remove_context(
    tag_t           library,                /**< (I) The Library to be removed from the Context. */
    tag_t           context                 /**< (I) The Context from which the Library is to be removed. */
    );

/**
    Finds the assigned Contexts for the given Library.
    <br/>This finds both Project/Program and 4GD Design Contexts assigned to the Library.
    <br/>The context information returned also says whether it is an owning context.

    @returns
    <ul>
    <li>#ITK_ok on success.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_find_assigned_contexts(
    tag_t           library,                /**< (I) The Library for which the assigned Contexts are to be found. */
    int*            context_count,          /**< (O) The count of assigned Contexts for the Library. */
    tag_t**         contexts,               /**< (OF) context_count The Contexts to which the specified Library is assigned to. */
    logical**       is_owning               /**< (OF) context_count Specifies whether the Library is owned by the Context. */
    );

/**
    Creates an instance of a Membership Rule based on Classification.
    <br/>This Membership Rule can only be created on Classifying Library Nodes (a Node that has an underlying Classification Node).
    <br/>Membership Rules allow mass population of objects to a specific Library Node by specifying a search criteria.

    <br/>The search criteria can be based on any Classification property that is defined on the underlying Classification Node.
    Multiple properties can be used for the search criteria.
    A "Match All objects" criteria can be achieved by specifying attribute_names and expression_values as "*".

    <br/>Membership Rules can be defined at any Node level in the Library hierarchy structure.
    Rules defined at a higher Node are inherited by all descendant Nodes, until overridden.
    <br/>For example: Defining a Membership Rule for Node N1 in the Node hierarchy will apply 
    to all descendant Nodes like N11, N12 etc. until any Node defines its own Membership Rules.
    <br/>Once a Node defines its own Membership Rules, it no longer inherits Rules from its ancestors.

    <br/>Membership Rules on leaf Nodes are evaluated as soon as they are created, modified or deleted.
    <br/>To explicitly evaluate Membership Rules, use #LBR_evaluate_membership_rules.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for library_node is not of the right type.
    <li>#PROP_required_prop_not_set if a property required for creation (like name) was not specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_cls_membership_rule(
    tag_t           library_node,           /**< (I) The Library Node for which the MembershipRule is created. */
    const char*     rule_name,              /**< (I) The name of the MembershipRule. */
    const char*     rule_description,       /**< (I) The description of the MembershipRule. */
    const tag_t     source_node,            /**< (I) The ID of the Source Node from which the objects should be picked. */
    int             attribute_count,        /**< (I) The number of attributes. */
    const char**    attribute_names,        /**< (I) attribute_count The attribute names. */
    const char**    expression_values,      /**< (I) attribute_count The expression values. */
    tag_t*          membership_rule         /**< (O) The created MembershipRule object. */
    );

/**
    Updates an instance of a Membership Rule based on Classification with attribute names and expression values.

    Membership Rules on leaf Nodes are evaluated as soon as they are created, modified or deleted.
    <br/>To explicitly evaluate Membership Rules, use #LBR_evaluate_membership_rules.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for library_node is not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_update_cls_membership_rule(
    tag_t           library_node,           /**< (I) The Library Node to which the Membership Rule belongs. */
    tag_t           membership_rule,        /**< (I) The Membership Rule to be updated. */
    int             attribute_count,        /**< (I) The number of attributes. */
    const char**    attribute_names,        /**< (I) attribute_count The attribute names. */
    const char**    expression_values       /**< (I) attribute_count The expression values. */
    );

/**
    Deletes a Membership Rule from the given Library Node.

    Membership Rules on leaf Nodes are evaluated as soon as they are created, modified or deleted.
    <br/>To explicitly evaluate Membership Rules, use #LBR_evaluate_membership_rules.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for library_node is not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_delete_membership_rule(
    tag_t           library_node,           /**< (I) The Library Node to which the Membership Rule belongs. */
    tag_t           membership_rule         /**< (I) The Membership Rule to be deleted. */
    );

/**
    Evaluates the Membership Rules for the given Library Node.
    <br/>In general, a Membership Rule evaluation will either add or remove Teamcenter objects (say Items) from the Library Node.
    <br/>In the context of a Library, a Teamcenter object is represented using an object called "Library Element".
    <br/>The Membership Rule evaluation thus either creates or deletes Library Elements (that reference the Teamcenter objects).

    <br/>Evaluation of a Membership Rule involves the following steps:
    <ol>
    <li>Find all matching Teamcenter objects (say Items) that match the search criteria on the Rule. 
        Exclude the objects which are already on the Node. Create CreateObjectsList.
    <li>Find all objects from the Node that now no longer meet the search criteria on the Rule. Create DeleteObjectsList.
    <li>Delete all the objects (Library Elements) from DeleteObjectsList. Note that the actual Teamcenter object remains intact.
    <li>Create Library Elements for all objects from CreateObjectsList.
    </ol>

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for library_node is not of the right type.
    <li>#LBR_err_invalid_member_rule_evaluation if the Library Node is an abstract Node.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_evaluate_membership_rules(
    tag_t           library_node            /**< (I) The Library Node. */
    );

/**
    Sets display values for a Property on OperationInput.
    <br>This is typically used during operations like Publish when additional properties are to be passed in.
    <br>Use the #TCTYPE_construct_operationinput to create a #TCTYPE_OPERATIONINPUT_ANY input and then
    use this method to set the properties on the input.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#METAFRAMEWORK_generic_accessory_fail, if the Property display value cannot be found.
   </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_set_OperationInput_Value(
    tag_t           operation_input,        /**< (I) The Operation Input for which the property is to be set. */
    const char*     property_name,          /**< (I) The Property name on the input object. */
    int             num_values,             /**< (I) The number of Property values. 1 indicates a single valued property. */
    const char**    property_values         /**< (I) The Property value(s) for the Property being set. */
    );

/**
    Publishes (adds) the given objects to the specified Library Node.
    <br/>This creates a new Library Element for each input object that was successfully published.
    <br/>Objects can be published to either a Classifying Library Node or a General Library Node.
    <br/>Classification and Element Properties can be optionally passed in using OperationInputs.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the specified input for library_node is not of the right type.
    <li>#LBR_err_publish_failed if the publish failed for one or more objects. Specific errors are returned in failed_errors.
    </ul>

    Possible error codes in failed_errors:
    <ul>
    <li>#LBR_err_object_already_published if the object is already published to the Library Node.
    <li>#LBR_err_classified_object_already_published if the object is already published to the Classifying Library Node.
    <li>#LBR_err_object_type_not_allowed if the object is not an allowed type to be published on the Node.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_publish_objects_to_library(
    tag_t           library_node,           /**< (I) The Library Node where the objects will be published. */
    int             num_objects,            /**< (I) The number of objects to Publish to the Library Node. */
    const tag_t*    objects,                /**< (I) The objects to Publish to the Library Node. */
    const tag_t*    cls_properties,         /**< (I) The OperationInputs containing property names and values to be used during the creation of the Classification Objects. */
    const tag_t*    element_properties,     /**< (I) The OperationInputs containing property names and values to be used during the creation of the Library Elements. */
    logical         do_bulk,                /**< (I) Indicates whether publish should use a �Bulk� approach that skips workflows. Currently unused. */
    int*            num_elements,           /**< (O) The number of newly created Library Elements. */
    tag_t**         elements,               /**< (OF) num_elements The reference to the newly created Library Elements. */
    int*            num_failed,             /**< (O) The number of objects that failed to be Published. */
    tag_t**         failed_objects,         /**< (OF) num_failed Objects that failed to be Published. */
    int**           failed_errors           /**< (OF) num_failed Error codes corresponding to the failed objects. */
    );

/**
    Retracts (removes) the given Library Elements / Objects from the specified Library Node.
    <br/>This operation deletes the Library Elements, but not the Object referenced by it.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the specified input for library_node is not of the right type.
    <li>#LBR_err_retract_failed if the retract failed for one or more objects. Specific errors are returned in failed_errors.
    </ul>

    Possible error codes in failed_errors:
    <ul>
    <li>#LBR_err_element_is_instantiated if the element being retracted is instantiated in one or more Designs.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_retract_objects_from_library(
    tag_t           library_node,           /**< (I) The Library Node from which the Library Elements / Objects are to be retracted. */
    int             num_objects,            /**< (I) The number of objects to Retract from the Library Node. */
    const tag_t*    objects,                /**< (I) The Library Elements or Objects to Retract from the Library Node. */
    logical         delete_cls_objects,     /**< (I) Indicates whether Classification Object should also be deleted. */
    logical         do_bulk,                /**< (I) Indicates whether retract should use a �Bulk� approach that skips workflows. Currently unused. */
    int*            num_failed,             /**< (O) The number of objects that failed to be retracted. */
    tag_t**         failed_objects,         /**< (OF) num_failed Objects that failed to be retracted. */
    int**           failed_errors           /**< (OF) num_failed Error codes corresponding to the failed objects. */
    );

/**
    Finds all the 4GD Designs in which the given Library Element is Instantiated.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the specified input for library_element is not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_find_where_instantiated(
    tag_t           library_element,        /**< (I) The Library Element whose 'Where Instantiated' information is needed. */
    int*            num_designs,            /**< (O) The number of Designs in which the Library Element is Instantiated. */
    tag_t**         designs                 /**< (OF) num_designs The Designs in which the Library Element is Instantiated. */
    );

/**
    Finds all the Design Elements that are registered as Instantiations of the given Library Element.
    <br/>This ITK is dependent on the CPD0 template being installed.
    If the CPD0 template is not installed, the error #LBR_err_requires_cpd will be returned.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the specified input for library_element is not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_find_instantiations(
    tag_t           library_element,        /**< (I) The Library Element whose Instantiations are to be found. */
    int*            num_design_elements,    /**< (O) The number of Designs Elements found that are Instantiations of the given Library Element. */
    tag_t**         design_elements         /**< (OF) num_design_elements The Design Elements that are Instantiations of the given Library Element. */
    );

/**
    This operation searches for Library Elements in a given Library that match the specified search criteria.
    <br/>It returns a ResultSet containing the result objects.
    <br/>The results for the search can be obtained using a call to #LBR_get_search_result.
    <br/>Additional criteria for search based on specification information can be specified using the specification search context.
    #LBR_set_search_context() can be used to set the search context. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for library_node is not of the right type.
    <li>#POM_no_attr_of_this_name if any of the property names specified is not a valid one.
    <li>#LBR_err_invalid_search_context if the library_node and the target node specified in specification search context are different.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_search_library_elements(
    tag_t           library_node,           /**< (I) The Library Node for which the search is to be performed. */
    int             property_count,         /**< (I) Number of properties specified for the search criteria. */
    const char**    property_names,         /**< (I) property_count Property names to be used in the search criteria. These can be Classification or Library Element properties. */
    const char**    expressions,            /**< (I) property_count Search expressions for each of the properties specified in property_names. */
    int             options,                /**< (I) Specifies search options which control certain search aspects. See ics2.h for all the valid search options. */
    int             order_property_count,   /**< (I) Number of properties to be used in sorting the result. */
    const char**    order_property_names,   /**< (I) order_property_count The property names to be used in sorting the result. */
    int*            sort_order,             /**< (I) order_property_count Sort order for each of the specified properties in order_property_names. */
    tag_t           spec_search_context,    /**< (I) The specification search context to be used as an additional search criteria. */
    int*            num_rows,               /**< (O) Number of Library Elements found. */
    char**          result_set              /**< (OF) The obtained ResultSet. */
    );

/**
    Gets specified number of objects from the search ResultSet.
    <br/>The ResultSet passed in should be one created as a result of a call to a search operation like #LBR_search_library_elements.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CLS_err_result_set_not_found if the specified result_set is not a valid one.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_search_result(
    const char*     result_set,             /**< (I)  The ResultSet to discard. */
    int             start_position,         /**< (I)  The position in the Result Set to start fetching the objects from. */
    int             num_objects,            /**< (I)  The number of objects to fetch from the ResultSet. */
    int*            num_fetched_objects,    /**< (O)  The number of objects fetched. If lesser than num_objects, it could be that the end of the Result Set has been reached.*/
    tag_t**         objects                 /**< (OF) num_fetched_objects The number of objects fetched from the query */
    );

/**
    Finds the available Libraries in Teamcenter.
    <br/>Filtering can be done based on the Context assigned or properties of the Library like ID, Name etc.
    If no filtering is specified, all the Libraries in Teamcenter are returned.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_no_attr_of_this_name if any of the property names specified is not a valid one.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_search_libraries(
    tag_t           design_context,         /**< (I) The Project/Program or Design Context. */
    int             property_count,         /**< (I) The number of properties for filtering. */
    const char**    poperty_names,          /**< (I) property_count The names of properties used as filter for searching. */
    const char**    property_values,        /**< (I) property_count The values of properties used as filter for searching. */
    int*            libraries_count,        /**< (O) The count of the Libraries found that match the criteria. */
    tag_t**         libraries               /**< (OF) libraries_count The Libraries matching the criteria. */
    );

/**
    Finds the Library Management objects of the given Business Object type using the provided MFK keys and values.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_unknown_type if the specified bo_name is not a valid one.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_find_by_MFK_attributes(
    const char*     bo_name,                /**< (I) The Business Object type name. */
    int             num_attributes,         /**< (I) The number of MFK attributes. */
    const char**    attribute_names,        /**< (I) num_attributes The MFK attribute names. */
    const char**    attribute_values,       /**< (I) num_attributes The MFK attribute values. */
    int*            num_objects,            /**< (O) The number of objects found. */
    tag_t**         objects                 /**< (OF) num_objects The objects found. */
    );

/**
    Retrieves all the children objects of an object.
    <br/>Invoking this on a Library will return the Hierarchies as children.
    <br/>Similarly, invoking it on a Hierarchy will return all the top level Nodes as children.
    <br/>Invoking this for a Node will return all the child Library Nodes.

    @returns
    <ul>
    <li>#ITK_ok on success.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_children(
    tag_t           object,                 /**< (I) The object for which the children need to be obtained.*/
    int*            child_count,            /**< (O) The number of children found.*/
    tag_t**         children                /**< (OF) child_count The children found.*/
    );

/**
    Gets all the members of a Library Node.
    <br/>The members of a Node are the Library Elements.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if configuration_context tag is invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_node_members(
    tag_t           configuration_context,  /**< (I) Input Configuration Context for filtering Library Elements. Currently unused.*/
    tag_t           library_node,           /**< (I) The Library Node for which the members need to be obtained.*/
    int*            members_count,          /**< (O) The number of members found.*/
    tag_t**         members                 /**< (OF) members_count The members found.*/
    );

/**
    Clones an instance of a Library/Hierarchy/Library Node.
    <br/>Cloning a Library creates a copy of the Library, along with all its descendants and elements (if specified).
    <br/>Cloning a Node creates a copy of the Node, along with all its descendants and elements (if specified).
    <br/>It is possible to clone a Hierarchy or a Node to the same Library or to a different one.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_required_prop_not_set if a property required for creation (like name) was not specified.
    </ul>

    Possible values that can be specified in clone_option is 0 or any combination of following:
    <ul>
    <li>#LBR_CLONE_CHILDREN In case this value is set, all the descendants of the current object will be cloned.
    <li>#LBR_CLONE_CONFIGURATIONS In case this value is set, all the configurations of the current object will be cloned.
    <li>#LBR_CLONE_ELEMENTS In case this value is set, all the Library Elements of the Node will be cloned.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_clone(
    tag_t           source_object,        /**< (I) The Object instance to be cloned. */
    int             clone_option,         /**< (I) Specifies the cloning options to use. */
    const char*     object_id,            /**< (I) The ID of the Object to create. If empty string is specified, an ID would be auto-generated. */
    const char*     object_name,          /**< (I) The name of the Library. An empty string cannot be specified. */
    const char*     object_description,   /**< (I) The description of the Object. */
    tag_t           parent_object,        /**< (I) The parent/target Object of the cloned instance. */
    tag_t           additional_props,     /**< (I) The OperationInput containing custom properties and values. It can be #NULLTAG. */
    tag_t*          cloned_object         /**< (O) The created Library instance. */
    );

/**
    Finds the available Library Nodes in Teamcenter.
    <br/>Filtering can be done based on properties of the Library like ID, Name etc.
    If no filtering is specified, all the Libraries in Teamcenter are returned.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_no_attr_of_this_name if any of the property names specified is not a valid one.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_search_library_nodes(
    int             property_count,         /**< (I) The number of properties for filtering. */
    const char**    poperty_names,          /**< (I) property_count The names of properties used as filter for searching. */
    const char**    property_values,        /**< (I) property_count The values of properties used as filter for searching. */
    int*            library_nodes_count,    /**< (O) The count of the Library nodes found that match the criteria. */
    tag_t**         library_nodes           /**< (OF) library_nodes_count The Library node objects matching the criteria. */
    );

/**
    Retrieves the Library Elements in a Library from their IDs.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_element if any element in @p library_element_ids is invalid.
    <li>#LBR_err_library_not_found if @p library_id is not found.
    <li>#LBR_err_hierarchy_not_found if @p library_hierarchy_id is not found.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_library_elements(
    const char*     library_id,                      /**< (I) The ID of Library. */
    const char*     library_hierarchy_id,            /**< (I) The ID of Library Hierarchy. */
    int             n_library_elements,              /**< (I) The number of Library Elements. */
    const char**    library_element_ids,             /**< (I) n_library_elements The IDs of the Library Elements. */
    int*            n_library_elements_found,        /**< (O) The number of the Library Elements found. */
    tag_t**         library_elements_found           /**< (OF) n_library_elements_found The Library Elements. */
    );

/**
    Retrieves the Icon Dataset object attached to @p hierarchy_node.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for hierarchy_node is null or not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_hierarchy_node_icon(
    tag_t   hierarchy_node,               /**< (I) The hierarchy node object whose icon dataset object is being accessed. This is a mandatory parameter. */
    tag_t*  icon_dataset                  /**< (O) Reference of the icon dataset object attached to hierarchy_node.*/
    );

/**
    Retrieves the Image Dataset object attached to @p hierarchy_node.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#LBR_err_invalid_library_node if the specified input for hierarchy_node is null or not of the right type.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_hierarchy_node_image(
    tag_t   hierarchy_node,             /**< (I) The hierarchy node object whose image dataset object is being accessed. This is a mandatory parameter. */
    tag_t*  image_dataset               /**< (O) Reference of the image dataset object attached to hierarchy_node. This is a mandatory parameter. */
    );

#ifdef __cplusplus
}
#endif

/**
   @}
*/

#include <Lbr0librarymgmt/liblbr0librarymgmt_undef.h>
#endif
