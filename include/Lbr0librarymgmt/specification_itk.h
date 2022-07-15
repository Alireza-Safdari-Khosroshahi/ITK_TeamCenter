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
    @file specification_itk.h

    This file implements the Specifications Management related ITK functions.
*/

#ifndef SPECIFICATION_ITK_H
#define SPECIFICATION_ITK_H

#include <Lbr0librarymgmt/specification_datatypes.h>

#include <tc/tc_startup.h>
#include <unidefs.h>

#include <Lbr0librarymgmt/liblbr0librarymgmt_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    Creates a Specification object instance in specified Library.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_library if invalid library tag is specified.
    <li>#LBR_err_empty_specification_name if empty string is specified for name.
    <li>#LBR_err_specification_id_not_unique if the ID specified already exists.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_specification(
    tag_t        library,               /**< (I) The Library tag */
    const char   *specification_id,     /**< (I) The Specification ID */
    const char   *specification_name,   /**< (I) The Specification name */
    const char   *specification_desc,   /**< (I) The Specification description */
    const char   *discipline,           /**< (I) The Specification discipline */
    logical      child_rule_override,   /**< (I) The child rule override flag  */
    tag_t        *specification         /**< (O) The Specification tag */
    );

/**
    Creates a Specification model object.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_missing_parameter if necessary parameter not specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_specification_model_object(
    const char *model_object_id,        /**< (I) The Model Object ID */
    const char *model_object_name,      /**< (I) The Model Object name */
    const char *model_object_desc,      /**< (I) The Model Object description */
    tag_t      *model_object            /**< (O) The Model Object tag */
    );

/**
    Creates Specification Rule instance in the given Specification.
    <br>Optionally, the rule could be added to a Library node, if specified.
    <br>The rule created will not be saved immediately. It is recommended to call AOM_save on the
    Specification object (for which this rule is being created), which will take care of saving all
    the newly created Specification Rules.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_specification_rule_id_not_unique if the rule ID specified already exists.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_specification_rule(
    tag_t                           specification,          /**< (I) The Specification object's tag for which the rule is being created.*/
    const char                      *rule_id,               /**< (I) The Specification Rule unique identifier. If specified empty, it will be auto-generated*/
    const char                      *rule_name,             /**< (I) The Specification Rule name.*/
    const char                      *rule_desc,             /**< (I) The Specification Rule description */
    LBR_specification_rule_type_t   rule_type,              /**< (I) The Specification Rule Type. Allowed values are-
                                                                        <ul>
                                                                        <li>#LBR_SPEC_RULE_TYPE_specification - The general rule. These rules are used to form the constraints based on which the design components
                                                                        will be searched. The type is used for creating the global rules and the node rules (rules pertaining to specific nodes).
                                                                        <li>#LBR_SPEC_RULE_TYPE_action - The Rule representing the constraints specified for specific actions (defined by Action Sets). These rules are created for Action Sets.
                                                                        <li>#LBR_SPEC_RULE_TYPE_interface_constraint - The type to create rules representing "Interface Constraints", also called as "Branch Compatibility").
                                                                        </ul>
                                                            */
    tag_t                           library_node,           /**< (I) The tag of the Library node to which the rule will be attached. For global rules, the library node must be specified as null. */
    logical                         is_active,              /**< (I) If set to true, this flag denotes that the Specification Rule will participate in filtering mechanism */
    const char                      *rule_set_id,           /**< (I) The Rule Set ID. The rule set ID will be used to group two or more rules together.*/
    tag_t                           *specification_rule     /**< (O) The unique handle for the Specification Rule created */
    );

/**
    Sets the source or target attribute criteria (characteristic filters) for the Specification Rule specified.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification_rule if the tag specified is null or invalid.
    <li>#LBR_err_invalid_attribute_expression_criteria if the attribute criteria is invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_set_specification_rule_criteria(
    tag_t       specification_rule,   /**< (I) The Specification Rule tag */
    logical     is_target_criteria,   /**< (I) If true, indicates target criteria to be set, else source criteria */
    const char  *attr_id,             /**< (I) The Attribute ID */
    const char  *attr_expression      /**< (I) The Attribute expression */
    );

/**
    Creates a revision of the Specification object.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#MDL0MODEL_object_has_no_status if the Specification object does not have a status.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_revise_specification(
    tag_t       specification,              /**< (I) The Specification tag */
    tag_t*      revised_specification       /**< (O) The tag of the revised Specification */
    );

/**
    Creates a copy of the Specification object.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_specification_id_not_unique if the ID specified already exists.
    <li>#LBR_err_empty_specification_name if empty string is specified for name.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_copy_specification(
    tag_t         specification,          /**< (I) The Specification tag      */
    const char    *new_spec_id,           /**< (I) The New Specification ID   */
    const char    *new_spec_name,         /**< (I) The New Specification name */
    tag_t         *new_specification      /**< (O) The New Specification tag  */
    );

/**
    Creates an Application Data instance in the Specification.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_application_data_id_not_unique if the ID specified already exists.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_application_data(
    tag_t           specification,      /**< (I) The Specification Rule tag */
    const char      *app_data_id,       /**< (I) The ApplicationData identifier */
    const char      *app_data_name,     /**< (I) The name for Application data object */
    const char      *app_data_desc,     /**< (I) The description for Application data object */
    logical         is_global,          /**< (I) Flag to specify if ApplicationData is global  */
    const char      *usage,             /**< (I) The Usage string. E.g. ‘Report in BOM’ */
    int             num_data_entries,   /**< (I) The number of data entries. */
    const char      **data_names ,      /**< (I) The data names  */
    const char      **data_values ,     /**< (I) The data values */
    tag_t           *application_data   /**< (O) The ApplicationData object created. */
    );

/**
    Creates an Action Definition instance.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_action_definition_id_not_unique if the ID specified already exists.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_action_definition(
    tag_t       specification,          /**< (I) The Specification for which the ActionDefinition is being created */
    const char  *action_def_id,         /**< (I) The unique ID of the ActionDefinition object */
    const char  *action_def_name,       /**< (I) The name for the ActionDefinition object */
    const char  *action_def_desc,       /**< (I) The description */
    int         quantity,               /**< (I) The quantity of the post-placement parts */
    int         num_selection_rules,    /**< (I) The number of Selection Rules */
    tag_t       *selection_rules,       /**< (I) The list of Specification Rules to be used as selection rules*/
    tag_t       *action_definition      /**< (O) The tag of the ActionDefinition object created */
    );

/**
    Creates an Action Set instance in the specified Specification.
    <br>Action sets provide definition for the compatibility between parts, based on the connection types.
    <br>They are also used to represent Generic post placement.
    <br>It is recommended to call AOM_save on the Specification object (for which this action set is being created), which will take care of saving all the newly created action set objects.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_action_set_id_not_unique if the ID specified already exists.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_create_action_set(
    tag_t                   specification,          /**< (I) The Specification for which the ActionSet is being created */
    const char              *action_set_id,         /**< (I) The ActionSet's identifier */
    const char              *action_set_name,       /**< (I) The name for the ActionSet object */
    const char              *action_set_desc,       /**< (I) The description for the ActionSet object */
    LBR_action_set_type_t   action_set_type,        /**< (I) The ActionSet type. Allowed values are -
                                                        <ul>
                                                        <li>#LBR_ACTION_SET_TYPE_post_placement - Action Set representing post placement.
                                                        <li>#LBR_ACTION_SET_TYPE_connection_compatibility - Action Set representing connection compatibility.
                                                        </ul>
                                                    */
    const char              *src_connection_type,   /**< (I) The source connection type. */
    const char              *trgt_connection_type,  /**< (I) The target connection type */
    int                     num_action_defs,        /**< (I) The number of ActionDefinition objects */
    tag_t                   *action_definitions,    /**< (I) The tags of the ActionDefinition objects to be associated with ActionSet being created */
    tag_t                   *action_set             /**< (O) The tag of the ActionSet object created */
    );

/**
    Deletes the Specification object.
    <br>The boolean flag detach_from_libraries is used to determine whether to detach the Specification from its associated libraries before deleting the object.
    <br>If specified as false, and if the Specification has associated libraries, then user will not be able to delete the Specification.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#POM_inst_referenced if the instance is referenced.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_delete_specification(
    tag_t       specification,          /**< (I) The Specification Rule tag */
    logical     detach_from_libraries   /**< (I) True value allow user to delete associations with libraries */
    );

/**
    Returns the Specification object tag for the specified Specification ID.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_multiple_objects if multiple objects are found.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_find_specification(
    const char  *specification_id,          /**< (I) The Specification ID */
    const char  *config_context_name,       /**< (I) The Configuration Context name, to search a specific revision of a Specification */
    tag_t       *specification              /**< (O) The Specification tag */
    );

/**
    Returns the Specification Element object tag for the specified Specification Element ID, type and the Specification.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_multiple_objects if multiple objects are found.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_find_specification_element(
    tag_t                            specification,                 /**< (I) The Specification tag */
    const char                       *specification_element_id,     /**< (I) The Specification Element ID  */
    LBR_specification_element_type_t specification_element_type,    /**< (I) The type of the Specification Element.
                                                                        <br>Allowed values are -
                                                                        <ul>
                                                                        <li>#LBR_SPEC_ELEM_TYPE_specification_rule - SpecificationRule,
                                                                        <li>#LBR_SPEC_ELEM_TYPE_action_set - ActionSet,
                                                                        <li>#LBR_SPEC_ELEM_TYPE_action_definition - ActionDefinition,
                                                                        <li>#LBR_SPEC_ELEM_TYPE_application_data - ApplicationData.
                                                                        </ul>
                                                                    */
    tag_t                            *specification_element         /**< (O) The Specification Element tag */
    );

/**
    Shares the Specification object in the specified library.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library if invalid library tag is specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_attach_spec_to_library(
    tag_t       specification,    /**< (I) The Specification tag */
    tag_t       library           /**< (I) The Library tag */
    );

/**
    Un-shares a Specification object from a library (specified as input)

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library if invalid library tag is specified.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_detach_spec_from_library(
    tag_t       specification,    /**< (I) The Specification tag */
    tag_t       library           /**< (I) The Library tag */
    );

/**
    Sets the 'in-session' Search context.
    <br>Returns the tag of the search context object which can be used as input for Search operations.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library if invalid library tag is specified.
    <li>#LBR_err_invalid_library_element if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_set_search_context(
    tag_t       specification,              /**< (I) The tag of the Specification */
    tag_t       source_member,              /**< (I) The tag of the Source member. Can be specified as NULL. */
    int         num_src_expressions,        /**< (I) The number of source expressions */
    const char  **src_attrs,                /**< (I) The list of attribute IDs */
    const char  **src_expressions,          /**< (I) The list of expression values */
    tag_t       target_node,                /**< (I) The target node. */
    tag_t       *search_context             /**< (O) The tag of the search context object. */
    );

/**
    Gets the details from the context object.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_search_context if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_search_context_details(
    tag_t       search_context,             /**< (I) The tag of the search context object. */
    tag_t       *specification,             /**< (O) The tag of the Specification */
    tag_t       *source_member,             /**< (O) The tag of the Source member */
    int         *num_src_expressions,       /**< (O) The number of source expressions */
    char        ***src_attrs,               /**< (OF) num_src_expressions The list of attribute IDs */
    char        ***src_expressions,         /**< (OF) num_src_expressions The list of expression values */
    tag_t       *target_node                /**< (O) The target node ID */
    );

/**
    Adds an existing Specification Rule to a Library node.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification_rule if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_attach_specification_rule_to_node(
    tag_t   specification_rule,     /**< (I) The unique handle for the Specification Rule */
    tag_t   library_node,           /**< (I) The Library node on which the rule needs to be added */
    logical is_active               /**< (I) Flag to denote if Specification Rule is participating in filtering mechanism during search */
    );

/**
    Removes an existing Specification Rule from a Library node.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification_rule if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_detach_specification_rule_from_node(
    tag_t   specification_rule, /**< (I) The unique handle for the Specification Rule */
    tag_t   library_node        /**< (I) The Library node on which the rule needs to be removed */
    );

/**
    Get the details of the specified Specification Rule.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification_rule if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_describe_specification_rule(
    tag_t   specification_rule,          /**< (I)    The Specification Rule for which the detailed info is being asked for. */
    char    **specification_rule_name,   /**< (OF)   The Specification Rule name. */
    char    **specification_rule_desc,   /**< (OF)   The Specification Rule description. */
    int     *rule_type,                  /**< (O)    The Specification Rule Type. */
    char    **library_node_id,           /**< (OF)   The ID of the library node the Specification Rule is associated with. */
    logical *is_active,                  /**< (O)    Flag indicating if the Specification Rule is active. */
    char    **rule_set_id,               /**< (OF)   The rule set ID of the Specification Rule. */
    char    **src_attr_id,               /**< (OF)   The source attribute unique ID. */
    char    **src_attr_expression,       /**< (OF)   The source attribute expression. */
    char    **trgt_attr_id,              /**< (OF)   The target attribute unique ID. */
    char    **trgt_attr_expression       /**< (OF)   The target attribute expression. */
    );

/**
    Gets the Specification Rules based on properties.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_number_of_inputs if the number of inputs is incorrect.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_specification_rules(
    tag_t         specification,                /**< (I)  The Specification to which the Rules being searched belong to. */
    int           num_properties,               /**< (I)  The count of the properties used for filtering */
    const char    **prop_names,                 /**< (I)  Valid Specification Rule properties used for filtering. */
    const char    **prop_values,                /**< (I)  Property values used for filtering. Wild cards could be used. */
    int           *num_specification_rules,     /**< (O)  Count of Specification Rules found. */
    tag_t         **specification_rules         /**< (OF) num_specification_rules The matching Specification Rules found. */
    );

/**
    Gets all the Rule set IDs for the Specification Rules, in the given Specification.
    <br>If Library node is not specified, then all rule sets from all the Specification Rules
    in the given Specification will be returned.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_ask_rule_set_ids(
    tag_t   specification,      /**< (I)  The Specification to which the Rule sets belong to. */
    tag_t   library_node,       /**< (I)  The Library node for which the rule sets are being searched. */
    int     *num_rule_set_ids,  /**< (O)  The number of rule set IDs found.*/
    char    ***rule_set_ids     /**< (OF) num_rule_set_ids The Rule set IDs found.*/
    );

/**
    Gets the source or target attribute criteria, for the specified Specification Rule.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification_rule if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_specification_rule_criteria(
    tag_t           specification_rule,     /**< (I)  The Specification Rule tag. */
    logical         is_target_criteria,     /**< (I)  The criteria.'False' indicates Source criteria and 'True' indicates target criteria. */
    char            **attr_id,              /**< (OF) The attribute ID. */
    char            **attr_expression       /**< (OF) The attribute expression.*/
    );

/**
    Gets the details about the Specification identified by the input Specification tag.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_describe_specification(
    tag_t       specification,          /**< (I)  The unique handle for the Specification. */
    char        **spec_name,            /**< (OF) The name of the Specification. */
    char        **spec_id,              /**< (OF) The Identifier of the Specification object. */
    char        **spec_desc,            /**< (OF) The Specification description. */
    tag_t       **spec_administrators,  /**< (OF) The list of users or groups in charge of administrating the Specification. */
    int         *num_libraries,         /**< (O)  The number of libraries this Specification is associated with. */
    tag_t       **libraries             /**< (OF) num_libraries The libraries this Specification is associated with. */
    );

/**
    Copies a Specification Rule to a new Specification, or to a new node in same Specification.

    @returns
    <ul>
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_specification_rule if the tag specified is null or invalid.
    <li>#LBR_err_specification_rule_id_not_unique if the Rule ID specified already exists.
    <li>#LBR_err_invalid_rule_type_for_copy if the Rule type is not supported.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_copy_specification_rule(
    tag_t       specification_rule,       /**< (I)  The Specification Rule being copied. */
    tag_t       target_specification,     /**< (I)  The Specification to which the Rule is being copied to. */
    const char  *new_rule_id,             /**< (I)  The ID for the new rule. If specified empty, it will be auto-generated. */
    tag_t       target_library_node,      /**< (I)  The library node to which the rule is intended to be added. */
    const char  *new_rule_set_id,         /**< (I)  The new rule set ID for the new rule. */
    tag_t       *new_specification_rule   /**< (O)  The tag of the new rule created. */
    );

/**
    Searches Specification objects based on the filtering criteria specified.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library if the tag specified is invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_specifications(
    tag_t         library,                  /**< (I)  The Library in which the Specifications are searched for. */
    const char    *config_context_name,     /**< (I)  The Configuration Context name, to search a specific revision of a Specification. */
    int           num_props,                /**< (I)  The number of properties specified for filtering. */
    const char    **prop_names,             /**< (I)  The internal names of properties used as filter for searching. */
    const char    **prop_values,            /**< (I)  The values of the properties used as filter for searching. */
    int           *num_specifications,      /**< (O)  The count of matching Specifications found based on the filters. */
    tag_t         **specifications          /**< (OF) num_specifications The unique handles for the Specification objects found. */
    );


/**
    Searches Action Set objects in the given Specification, based on criteria specified.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_number_of_inputs if the number of inputs is incorrect.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_action_sets(
    tag_t         specification,        /**< (I)  The Specification to which the action sets being searched. */
    int           num_props,            /**< (I)  The count of the properties used for filtering. */
    const char    **prop_names,         /**< (I)  Valid properties used for filtering. */
    const char    **prop_values,        /**< (I)  Property values used for filtering.  */
    int           *num_action_sets,     /**< (O)  Count of Action Sets found. */
    tag_t         **action_sets         /**< (OF) num_action_sets The matching action set objects found. */
    );

/**
    Searches Action Definition objects in the given Specification, based on criteria specified.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_number_of_inputs if the number of inputs is incorrect.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_application_data(
    tag_t         specification,                /**< (I)  The Specification to which the Application Data objects being searched belong to. */
    int           num_props,                    /**< (I)  The count of the properties used for filtering. */
    const char    **prop_names,                 /**< (I)  Valid properties used for filtering. */
    const char    **prop_values,                /**< (I)  Property values used for filtering.  */
    int           *num_app_data_objects,        /**< (O)  The count of Application Data objects found. */
    tag_t         **app_data_objects            /**< (OF) num_app_data_objects The matching Application Data objects found. */
    );

/**
    Searches Action Set objects in the given Specification, based on criteria specified.
    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_action_set if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_action_definitions(
    tag_t         action_set,                   /**< (I)  The ActionSet to which the Action Definition objects being searched are associated to. */
    int           *num_action_definitions,      /**< (O)  Count of Action Definition objects found.. */
    tag_t         **action_definitions          /**< (OF) num_action_definitions The matching Action Definition objects found. */
    );

/**
    Returns all the libraries where specified Specification is shared.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_associated_libraries(
    tag_t       specification,          /**< (I)  The unique handle for the shared Specification. */
    int         *num_libraries,         /**< (O)  The count of Library objects sharing specified Specification. */
    tag_t       **libraries             /**< (OF) num_libraries The list of Library objects sharing the specified Specification. */
    );

/**
    Searches the applicable Specification Rules for the given search context.<br>
    The search context defines info such as the Specification to be used, and target node on which
    the search has to be performed.<br>
    <BR>Use #LBR_set_search_context() to set the search context.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_search_context if the tag specified is null or invalid.
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_element if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_search_applicable_spec_rules(
    tag_t      search_context,              /**< (I) The tag of the search context object. */
    int        *num_specification_rules,    /**< (O) The number of applicable Specification Rules found */
    tag_t      **specification_rules        /**< (OF) num_specification_rules The tags of the applicable Specification Rules */
    );

/**
    Creates the generic post-placement data definition in the given specification.
    <br>The data is used to search the components to be post-placed in design, on selection of a particular component.
    <br>@note The data is stored as a combination of ActionSet, ActionDefinition, and SpecificationRule in the database.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    <li>#LBR_err_generic_post_placement_exists if the post-placement definition already exists between the source and target nodes.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_set_post_placement_data(
    tag_t       specification,       /**< (I) The tag of the Specification object.*/
    tag_t       source,              /**< (I) The tag of the source node object. */
    tag_t       target,              /**< (I) The tag of the target node object. */
    int         quantity,            /**< (I) The required number of post placement parts. */
    int         num_of_expression,   /**< (I) The number of attributes and expressions. */
    const char  **attrs,             /**< (I) The attributes. */
    const char  **exprs              /**< (I) The expressions. */
    );

/**
    Retrieves the details of the post-placement construct.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_post_placement_data(
    tag_t       specification,                  /**< (I) The tag of the specification. */
    tag_t       source_node,                    /**< (I) The source node. */
    int         *num_of_post_placement_data,    /**< (O) The number of matching target nodes. */
    tag_t       **target_nodes,                 /**< (OF) num_of_post_placement_data The matching target nodes. */
    tag_t       **source_nodes,                 /**< (OF) num_of_post_placement_data The matching target nodes. */
    int         **quantity,                     /**< (OF) num_of_post_placement_data The required number of post placement parts. */
    int         **num_of_expressions,           /**< (OF) num_of_post_placement_data The number of attributes and expressions. */
    char        ****attrs,                      /**< (OF) num_of_expressions Array of array of strings containing the attribute IDs configured in the post placement.<br>The caller should free the allocated memory using #MEM_free as shown below -<br>
                                                @code
                                                for( int inx = 0; inx < num_of_expressions; inx++ )
                                                {
                                                MEM_free( attrs[inx] );
                                                }
                                                MEM_free( attrs );
                                                @endcode
    */
    char        ****exprs                       /**< (OF) num_of_expressions Array of array of strings containing the attribute expressions configured in the post placement.<br>The caller should free the allocated memory using #MEM_free as shown below -<br>
                                                @code
                                                for( int inx = 0; inx < num_of_expressions; inx++ )
                                                {
                                                MEM_free( exprs[inx] );
                                                }
                                                MEM_free( exprs );
                                                @endcode */
    );

/**
    Searches the generic post-placement parts (library elements) as per the definition in the given specification.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_search_post_placement_parts(
    tag_t       specification,           /**< (I) The tag of the Specification object. */
    tag_t       library,                 /**< (I) The tag of the Library object. */
    tag_t       source_library_element,  /**< (I) The source member library element object. */
    int         *num_of_parts_found,     /**< (O) The number of the matching post placement parts. */
    tag_t       **post_placement_parts   /**< (OF) num_of_parts_found The matching post placement parts. */
    );

/**
    Searches the connection post-placement parts as defined in the given specification.
    <br>This API is used to find the post-placement parts defined for the connection compatibility.

    @returns
    <ul>
    <li>#ITK_ok if successful
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_library_node if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_search_connection_post_placement_parts(
    tag_t       specification,           /**< (I) The tag of the Specification object. */
    tag_t       library,                 /**< (I) The tag of the Library object. */
    const char  *source_connection_type, /**< (I) The source connection type. */
    const char  *target_connection_type, /**< (I) The target connection type. */
    int         *num_of_parts_found,     /**< (O) The number of the matching post placement parts. */
    tag_t       **post_placement_parts   /**< (OF) num_of_parts_found The matching post placement parts. */
    );

/**
    Sets Interface Constraints (also called as Branch Compatibility) definition data in a specification.
    <br>E.g. consider for a Specification with tag 'spec1Tag', with source attribute as 'NPS'(attribute ID: 10001) and destination
    attribute as NPS_BRANCH(attribute ID: 10002), following is the interface constraints definition -
    <table>
        <tr>
        <td> NPS </td><td> NPS_BRANCH </td>
        </tr>
        <tr>
        <td> 10 </td><td> 4 , 6 </td>
        </tr>
        <tr>
        <td> 20 </td><td> 18 </td>
        </tr>
        <tr>
        <td> 30 </td><td> 26.5 </td>
        </tr>
    </table>
    <br> It should be set as follows -
    <br> LBR_set_interface_constraint_data( spec1Tag, 0, 4, "10001", { "10","10", "20", "30" }, "10002", { "4", "6", "18",  "26.5" } );

    @returns
    <ul>
    <li>#ITK_ok if successful.
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_number_of_inputs if the number of inputs is incorrect.
    <li>#LBR_err_invalid_input if invalid input is provided.
    </ul>
*/

extern LBR0LIBRARYMGMT_API int LBR_set_interface_constraints_data (
    tag_t           specification,          /**< (I) The unique handle for the Specification to which the interface constraints are to be added. */
    logical         override_data_flag,     /**< (I) The flag to indicate whether to override the existing data completely(true),
                                                or add new data to the existing (false). */
    int             num_entries,            /**< (I) The number of entry sets. */
    const char      *source_attr_id,        /**< (I) The source attribute ID (e.g. the attribute ID for attribute ‘NPS’). */
    const char      **source_attr_values,   /**< (I) The source attribute value list. */
    const char      *dest_attr_id,          /**< (I) The destination attribute ID (e.g. the attribute ID for attribute ‘NPS_BRANCH’). */
    const char      **dest_attr_values      /**< (I) The destination attribute value list. */
    );

/**
    Retrieves the Interface Constraints (also called as Branch Compatibility) definition data
    in a given specification, for specified input criteria.

    @returns
    <ul>
    <li>#ITK_ok if successful.
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    <li>#LBR_err_invalid_input if the source or destination attribute ID is specified as an empty string.
    <li>#LBR_err_missing_parameter if the source or destination attribute ID is specified as null.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_compatible_constraint_values (
    tag_t           specification,              /**< (I) The unique handle for the Specification, which the interface constraints belong to. */
    const char      *source_attr_id,            /**< (I) The source attribute ID (e.g. the attribute ID for attribute ‘NPS’). Must be specified as a non-empty string. */
    const char      *source_attr_value,         /**< (I) The source attribute value. Can be specified as an empty string to search for all values for given source attribute ID */
    const char      *dest_attr_id,              /**< (I) The destination attribute value. Must be specified as a non-empty string. */
    int             *num_src_values,            /**< (O) The number of source values. */
    char            ***src_attr_values,         /**< (OF) num_src_values The array of matching source attribute values. Each of the values will be unique.
                                                            <br>The output string array is SM-packed,
                                                            hence should be freed by calling #MEM_free on the container only. */
    int             **dest_value_counts,        /**< (OF) num_src_values The array containing the count of corresponding destination values for each of the source values. */
    char            ****dest_attr_values        /**< (OF) ) num_src_values Array of array of strings containing the matching set of destination attribute values.<br>The caller should free the allocated memory using #MEM_free as shown below -<br>
                                                @code
                                                for( int inx = 0; inx < num_src_values; inx++ )
                                                {
                                                MEM_free( dest_attr_values[inx] );
                                                }
                                                MEM_free( dest_attr_values );
                                                @endcode
 */
    );

/**
    Retrieves the Interface Constraints (also called as Branch Compatibility) definition data in a given specification.
    <br>All the source and destination attribute IDs and values will be returned.

    @returns
    <ul>
    <li>#ITK_ok if successful.
    <li>#LBR_err_invalid_specification if the tag specified is null or invalid.
    </ul>
*/
extern LBR0LIBRARYMGMT_API int LBR_get_interface_constraints_data (
    tag_t     specification,           /**< (I)  The unique handle for the Specification, which the interface constraints belong to. Mandatory. */
    int       *num_entries,            /**< (O)  The number of interface constraints entries found. */
    char      ***source_attr_ids,      /**< (OF) num_entries The source attribute IDs (e.g. the attribute ID for attribute ‘NPS’).
                                                    <br>The output string array is SM-packed, hence should be freed by calling #MEM_free on the container only. */
    char      ***source_attr_values,   /**< (OF) num_entries The source attribute value list.
                                                    <br>The output string array is SM-packed, hence should be freed by calling #MEM_free on the container only. */
    char      ***dest_attr_ids,        /**< (OF) num_entries The destination attribute IDs (e.g. the attribute ID for attribute ‘NPS_BRANCH’).
                                                    <br>The output string array is SM-packed, hence should be freed by calling #MEM_free on the container only. */
    char      ***dest_attr_values      /**< (OF) num_entries The destination attribute value list.
                                                    <br>The output string array is SM-packed, hence should be freed by calling #MEM_free on the container only. */
    );



#ifdef __cplusplus
}
#endif

#include <Lbr0librarymgmt/liblbr0librarymgmt_undef.h>
#endif
