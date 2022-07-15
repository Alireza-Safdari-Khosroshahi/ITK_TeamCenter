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
    @file librarymgmt_errors.h

    LBR0LIBRARYMGMT Error Codes Declaration

*/

#ifndef LBR0LIBRARYMGMT_ERRORS_H
#define LBR0LIBRARYMGMT_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <Lbr0librarymgmt/liblbr0librarymgmt_exports.h>

#define LBR0LIBRARYMGMT_ERROR_BASE                  EMH_LBR0LIBRARYMGMT_error_base

#define LBR0LIBRARYMGMT_GENERAL_ERROR_BASE          LBR0LIBRARYMGMT_ERROR_BASE
#define LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE          LBR0LIBRARYMGMT_ERROR_BASE + 100
#define LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE         LBR0LIBRARYMGMT_ERROR_BASE + 300
#define LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE           LBR0LIBRARYMGMT_ERROR_BASE + 500
#define LBR0LIBRARYMGMT_LBRSEARCH_ERROR_BASE        LBR0LIBRARYMGMT_ERROR_BASE + 700

/**
@defgroup LBR0LIBRARYMGMT_ERRORS All Errors for Library Management and Specification Management functionality
*/

/************************************************************************/
/* General errors                                                       */
/************************************************************************/
/**
@defgroup LBR0LIBRARYMGMT_GENERAL General Errors for Library Management
@ingroup LBR0LIBRARYMGMT_ERRORS
@{
*/

/** A mandatory parameter "%1$" in the function "%2$" has not been supplied. Please contact your system administrator to report this error. */
#define LBR_err_missing_parameter                   ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 1 )

/** A mandatory output parameter "%1$" in the function "%2$" has not been supplied. Please contact your system administrator to report this error. */
#define LBR_err_missing_mandatory_output_param      ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 2 )

/** The object type input parameter has not been supplied. Please report this error to your system administrator.*/
#define LBR_err_missing_object_type                 ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 3 )

/** The current user is not authorized to perform this operation. Please use the Authorization module to grant access to "Library Management" for the required Group or Role. */
#define LBR_err_not_authorized                      ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 4 )

/** A mandatory command parameter has not been supplied. Please contact your system administrator to report this error. */
#define LBR_err_missing_mandatory_command_param     ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 5 )

/** One or more invalid input parameters have been specified for the command. Please contact your system administrator to report this error. */
#define LBR_err_invalid_command_param               ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 6 )

/** At least one property should be specified for creation of a Membership Rule. Please contact your system administrator to report this error. */
#define LBR_err_missing_property_value              ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 7 )

/** The current user does not have sufficient privileges to perform the "%1$" operation on the object "%2$" of type "%3$". Please contact your system administrator to report this error. */
#define LBR_err_insufficient_privilege              ( LBR0LIBRARYMGMT_GENERAL_ERROR_BASE + 8 )

/** @} */

/************************************************************************/
/* Library Management errors                                            */
/************************************************************************/
/**
@defgroup LBR0LIBRARYMGMT_LBRMGMT Errors for Library Management functionality
@ingroup LBR0LIBRARYMGMT_ERRORS
@{
*/

/** The specified Library "%1$" is invalid. Please provide a valid Library instance. */
#define LBR_err_invalid_library                     ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 1 )

/** The specified Library Hierarchy "%1$" is invalid. Please provide a valid Library Hierarchy instance. */
#define LBR_err_invalid_hierarchy                   ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 2 )

/** The specified Library Node "%1$" is invalid. Please provide a valid Library Node instance. */
#define LBR_err_invalid_library_node                ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 3 )

/** The specified Classification Node "%1$" is invalid. Please provide a valid Classification Node instance. */
#define LBR_err_invalid_classification_node         ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 4 )

/** The specified parent Library Node "%1$" is invalid. Please provide a valid Library Node instance. */
#define LBR_err_invalid_parent_node                 ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 5 )

/** The specified object "%1$" is invalid. The supported objects are Library, Hierarchy and Library Node. */
#define LBR_err_invalid_configured_object           ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 6 )

/** The specified object "%1$" is invalid for deletion. The supported objects are Library, Hierarchy and Library Node. */
#define LBR_err_invalid_object_to_delete            ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 7 )

/** The specified Library with ID "%1$" cannot be found. Please provide the ID of an existing Library. */
#define LBR_err_library_not_found                   ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 11 )

/** The specified Library Hierarchy with ID "%1$" cannot be found. Please provide the ID of an existing Library Hierarchy. */
#define LBR_err_hierarchy_not_found                 ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 12 )

/** The specified Library Node with ID "%1$" cannot be found. Please provide the ID of an existing Library Node. */
#define LBR_err_node_not_found                      ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 13 )

/** The specified General Library Node with ID "%1$" cannot be a child node of Classifying Library Node with ID "%2$". Please specify a valid Classifying Library Node or choose a different parent node. */
#define LBR_err_invalid_child_library_node          ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 14 )

/** The specified child Library Node with ID "%1$" does not have a parental reference. */
#define LBR_err_orphaned_library_node               ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 15 )

/** The Membership Rule evaluation is not supported for an abstract Library Node since abstract nodes cannot have Library Elements. */
#define LBR_err_invalid_member_rule_evaluation      ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 16 )

/** The specified Membership Rule "%1$" is invalid. Only Classification Membership Rules are supported. */
#define LBR_err_invalid_member_rule                 ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 17 )

/** The Membership Rules currently work with Classification properties only and hence not supported for non-Classifying Library Nodes. */
#define LBR_err_member_rule_not_supported           ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 18 )

/** The specified Membership Rule with name "%1$" cannot be found. Please provide the name of an existing Membership Rule. */
#define LBR_err_rule_not_found                      ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 19 )

/** The Library with ID "%1$" cannot be deleted, because it is referenced. Please delete the content first, or invoke the delete operation again on this Library, using the "Recursive Delete" option. */
#define LBR_err_library_delete_failed               ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 21 )

/** Internal error. You are attempting a Classification related operation on a non-Classifying Library Node "%1$". Please contact your system administrator to resolve this issue. */
#define LBR_err_not_a_classifying_node              ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 31 )

/** The specified Context "%1$" cannot be assigned to the specified Library "%2$", because this Library is already associated to other Context(s). Either remove the Context(s) from the said Library, or set this context with Ownership as false. */
#define LBR_err_library_already_associated          ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 32 )

/** The specified Context "%1$" cannot own the specified Library "%2$", because this Library is already owned by  another Context "%3$. Please remove the current ownership and retry this operation. */
#define LBR_err_library_already_owned               ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 33 )

/** The specified Context with ID "%1$" cannot be found. Please provide the ID of an existing Context. */
#define LBR_err_context_not_found                   ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 34 )

/** The specified Library "%1$" is not associated to the Context "%2$". */
#define LBR_err_library_not_assigned_to_context     ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 35 )

/** The specified Node "%1$" already has the Representation for the specified Intent "%2$". Please provide another Intent. */
#define LBR_err_already_has_intent_representation   ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 36 )

/** The Classification Node "%1$" of the specified source Library Node is different from the Classification Node "%2$" of this Library Node. Both of these should point to the same Classification Node. */
#define LBR_err_invalid_source_classification_node  ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 37 )

/** This change is not allowed since the Library Node "%1$" contains Library Elements. Please delete all Library Elements and retry this operation.*/
#define LBR_err_node_has_elements                   ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 38 )

/** The creation of the Classifying Library Node "%1$" has failed, because it does not structurally match the Classification Node Hierarchy. Please refer to the "Creating a Library Node Hierarchy" section in Teamcenter documentation for more details. */
#define LBR_err_node_not_matching_cls               ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 39 )

/** The specified clone option "%1$" is invalid. Please refer to the "Cloning a Library" section in Teamcenter documentation for all valid clone options. */
#define LBR_err_invalid_clone_option                ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 40 )

/** Changing the referenced Classification Node for a Library Node is currently not supported. Please create a new Library Node instead. */
#define LBR_err_update_cls_node                     ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 41 )

/** The creation of the General Option (Allowed Member Type) has failed, because the specified types "1$" are not aligned with the values of the preference "ICS_classifiable_types". Please add the values "%1$" to the preference "ICS_classifiable_types", and try this operation again. */
#define LBR_err_invalid_allowed_member_types        ( LBR0LIBRARYMGMT_LBRMGMT_ERROR_BASE + 42 )

/** @} */

/************************************************************************/
/* Specification Management errors                                            */
/************************************************************************/
/**
@defgroup LBR0LIBRARYMGMT_SPECMGMT Errors for Specification Management functionality
@ingroup LBR0LIBRARYMGMT_ERRORS
@{
*/

/** The specified value "%1$" for Administrator user is invalid.Please provide a valid Administrator user. */
#define LBR_err_invalid_admin                               ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 1 )

/** The specified value "%1$" for Specification ID is either invalid or empty. Please provide a valid Specification ID. */
#define LBR_err_invalid_specification_id                    ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 2 )

/** The specified number of inputs is invalid. Please provide valid number of inputs.*/
#define LBR_err_invalid_number_of_inputs                    ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 3 )

/** The specified property "%1$" is invalid. Please provide a valid property. */
#define LBR_err_invalid_property                            ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 4 )

/** The specified property value "%1$" is invalid. Please provide a valid property value.*/
#define LBR_err_invalid_property_value                      ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 5 )

/** The Specification tag is either invalid or a NULL tag. Please provide a valid Specification tag. */
#define LBR_err_invalid_specification                       ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 6 )

/** The Specification Rule with the specified ID "%1$" already exists. Please provide a valid Specification Rule ID.*/
#define LBR_err_specification_rule_id_exists                ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 7 )

/** The specified Specification Rule type "%1$" is Invalid. Please provide a valid Specification Rule type. */
#define LBR_err_invalid_rule_type                           ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 8 )

/** The specified Specification Rule tag is either Null or Invalid. Please provide a valid Specification Rule.*/
#define LBR_err_invalid_specification_rule                  ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 9 )

/** The specified expression "%1$" in Invalid. Please provide a valid expression. */
#define LBR_err_invalid_expression                          ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 10 )

/** The specified Specification Rule ID "%1$" is invalid or empty. Please provide a valid Specification Rule ID.*/
#define LBR_err_invalid_specification_rule_id               ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 11 )

/** The Specification does not exist for the specified ID "%1$". Please provide a valid value for the ID.*/
#define LBR_err_specification_does_not_exist                ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 12 )

/** The number of specified inputs are invalid. */
#define LBR_err_compatibility_invalid_number_of_inputs      ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 13 )

/** The specified search context tag "%1$" is invalid or null. Please provide a valid search context tag.*/
#define LBR_err_invalid_search_context                      ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 14 )

/** No applicable specification rules were found. */
#define LBR_err_no_applicable_rules_found                   ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 15 )

/** The specified Library Element "%1$" is invalid. Please provide a valid Library Element. */
#define LBR_err_invalid_library_element                     ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 16 )

/** Source and Target connection types are not compatible. Please provide valid Source and Target connection types. */
#define LBR_err_no_compatibility_found                      ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 17 )

/** The specified Action Set ID "%1$" is invalid or empty.*/
#define LBR_err_invalid_action_set_id                       ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 18 )

/** The specified Action Definition ID "%1$" is invalid or empty.*/
#define LBR_err_invalid_action_definition_id                ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 19 )

/** The specified Application Data ID "%1$" is invalid or empty.*/
#define LBR_err_invalid_application_data_id                 ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 20 )

/** Invalid value "%1$" specified for Quantity. Please provide a valid Quantity value. */
#define LBR_err_invalid_quantity                            ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 21 )

/** Invalid  or null Action Definition tag specified. Please provide a valid Action Definition tag. */
#define LBR_err_invalid_action_definition                   ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 22 )

/** Invalid or null Action Set tag specified. Please provide a valid Action Set tag.*/
#define LBR_err_invalid_action_set                          ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 23 )

/** Invalid or null Application Data tag specified. */
#define LBR_err_invalid_application_data                    ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 24 )

/** The Specification with ID "%1$" cannot be saved because it would violate the uniqueness criteria.*/
#define LBR_err_specification_id_not_unique                 ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 26 )

/** The Specification rule with ID "%1$" cannot be saved because it would violate the uniqueness criteria.*/
#define LBR_err_specification_rule_id_not_unique            ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 27 )

/** The Action Set with ID "%1$" cannot be saved because it would violate the uniqueness criteria.*/
#define LBR_err_action_set_id_not_unique                    ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 28 )

/** The Action Definition with ID "%1$" cannot be saved because it would violate the uniqueness criteria.*/
#define LBR_err_action_definition_id_not_unique             ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 29 )

/** The Application Data with ID "%1$" cannot be saved because it would violate the uniqueness criteria.*/
#define LBR_err_application_data_id_not_unique              ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 30 )

/** The Specification name cannot be specified as empty. Please provide a valid, non-empty string.*/
#define LBR_err_empty_specification_name                    ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 31 )

/** The search returned multiple objects for the ID "%1$". Please specify a valid key.*/
#define LBR_err_multiple_objects                            ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 32 )

/** The specified input "%1$" is invalid. Please specify a valid input.*/
#define LBR_err_invalid_input                               ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 33 )

/** The specified attribute id and corresponding expression value combination for the given Specification Rule is invalid. Please specify the valid values.*/
#define LBR_err_invalid_attribute_expression_criteria       ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 34 )

/** The specified node id is null, empty or invalid */
#define LBR_err_invalid_node_id                             ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 35 )

/** The type "%1$" specified for ActionSet is invalid. Please provide a valid ActionSet Type */
#define LBR_err_invalid_action_set_type                     ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 36 )

/** The specified object with ID "%1$" and type "%2$" was not found. Please specify a valid object ID and type.*/
#define LBR_err_object_not_found                            ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 37 )

/** The type "%1$" specified for ActionDefinition is invalid. Please provide a valid ActionDefinition Type */
#define LBR_err_invalid_action_definition_type              ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 38 )

/** The copy operation on the specification rule "%1$" failed. Only specification rule of type 'Specification' can be copied. */
#define LBR_err_invalid_rule_type_for_copy                  ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 39 )

/** The specification rule "%1$" cannot be associated to an action definition. Only a specification rule of type "Action" can be associated to the action definition. */
#define LBR_err_invalid_rule_type_for_action_definition     ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 40 )

/** The specification object with the ID "%1$" is not associated to the library "%2$". */
#define LBR_err_invalid_library_specification_relation      ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 41 )

/** The specification "%1$" cannot be attached to the library "%2$" because the current user does not have write access to the library.*/ 
#define LBR_err_lib_spec_rel_no_access_for_create           ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 42 )

/** The specification "%1$" cannot be detached from the library "%2$" because the current user does not have write access to the library.*/ 
#define LBR_err_lib_spec_rel_no_access_for_delete           ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 43 )

/** The specified attribute "%1$" is invalid. Please specify a valid ID of an existing dictionary attribute. */
#define LBR_err_invalid_attribute                           ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 44 )

/** The date format of the attribute with ID "%1$" is currently not supported for specification rules. Please use an attribute having one of the following formats: list, string, integer, real. */
#define LBR_err_unsupported_attribute_format                ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 45 )

/** The post-placement definition already exists between the nodes "%1$" and "%2$". */
#define LBR_err_generic_post_placement_exists               ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 46 )

/** The Multifield key for Specification objects does not include the Specification Revision ID (fnd0RevisionId) property. As a result, creation of revisions is not supported. If you would like to enable the "revise" operation for Specification objects, please contact your administrator to add the Specification Revision ID (fnd0RevisionId) property to the Multifield key property for Specification objects. */
#define LBR_err_revise_not_allowed                          ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 47 )

/** The Multifield key for Specification objects does not include either the Specification ID (lbr0SpecificationID) or Specification Name (object_name) properties. As a result, the "saveAs" operation is not supported. If you would like to enable the "saveAs" operation for Specification objects, please contact your administrator to add the Specification ID (lbr0SpecificationID) or Specification Name (object_name) properties to the Multifield key property for Specification objects. */
#define LBR_err_saveas_not_allowed                          ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 48 )

/** The Multifield key for Library objects does not include the "Library ID" (mdl0model_id) property. As a result, the "Save As" operation for the associated Specification objects is not supported, because the deep copy rules for Specifications would fail to create a copy of the Library for the new Specification objects. If you would still like to perform the "Save As" operation on Specification objects, contact your administrator to add the "Library ID" (mdl0Model_id) property to the Multifield key property for Library objects, or un-share the Library object from the Specification object. */
#define LBR_err_library_mfk_invalid                          ( LBR0LIBRARYMGMT_SPECMGMT_ERROR_BASE + 49 )

/** @} */

/************************************************************************/
/* Library Usage errors                                                 */
/************************************************************************/
/**
@defgroup LBR0LIBRARYMGMT_LBRUSE Errors for Library usage functionality
@ingroup LBR0LIBRARYMGMT_ERRORS
@{
*/

/** The Object "%1$", classified as "%2$", is already published to the Library Node "%3$". Please choose another object to publish. */
#define LBR_err_classified_object_already_published         ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 1 )

/** The Object "%1$", is already published to the Library Node "%2$". Please choose another object to publish. */
#define LBR_err_object_already_published                    ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 2 )

/** This functionality requires the CPD0 template to be installed. Please contact your system administrator. */
#define LBR_err_requires_cpd                                ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 3 )

/** The Library Element "%1$" is Instantiated in a Design, and hence cannot be deleted. */
#define LBR_err_element_is_instantiated                     ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 4 )

/** The Object "%1$" being added to the Library Node "%2$" does not meet the AllowedMemberTypes criteria defined for the Library or Node. */
#define LBR_err_object_type_not_allowed                     ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 5 )

/** One or more objects could not be published to the Library Node "%1$". Please check the syslog for details on the specific objects that have failed. */
#define LBR_err_publish_failed                              ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 6 )

/** One or more objects have failed to be retracted from the Library Node "%1$". Please check the syslog for details on the specific objects that have failed. */
#define LBR_err_retract_failed                              ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 7 )

/** The Library Element "%1$" is not a member of the Library Node "%2$". Please choose a valid Library Element. */
#define LBR_err_element_not_member                          ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 8 )

/** The Library Element "%1$" is not a published member of the Library Node "%2$". Please choose a valid published Library Element. */
#define LBR_err_element_not_published                       ( LBR0LIBRARYMGMT_LBRUSE_ERROR_BASE + 9 )

/** @} */

/**
@defgroup LBR0LIBRARYMGMT_LBRSEARCH Errors for Library Management
@ingroup LBR0LIBRARYMGMT_ERRORS
@{
*/

/** Searches based on Classification properties are not supported for a Group node. Only Library Element properties can be used for the searches. */
#define LBR_err_invalid_group_node_cls_property             ( LBR0LIBRARYMGMT_LBRSEARCH_ERROR_BASE + 1 )

/** Searches based on Classification properties are not supported for a General Library node. Only Library Element properties can be used for the searches. */
#define LBR_err_invalid_general_node_cls_property           ( LBR0LIBRARYMGMT_LBRSEARCH_ERROR_BASE + 2 )

/** @} */

#include <Lbr0librarymgmt/liblbr0librarymgmt_undef.h>

#endif
