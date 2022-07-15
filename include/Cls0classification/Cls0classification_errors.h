/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

/**
    @file

    Cls0classification Error Codes Declaration

*/

#ifndef CLS0CLASSIFICATION_ERRORS_H
#define CLS0CLASSIFICATION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CLS0CLASSIFICATION_ERRORS_H CLS Errors
    @ingroup CLS
    @{
*/

#define CLS0CLASSIFICATION_ERROR_BASE                               EMH_CLS0CLASSIFICATION_error_base


/**
    @name Parameter validation errors
    @{
 */
#define CLS0CLASSIFICATION_GENERAL_ERROR_BASE                       CLS0CLASSIFICATION_ERROR_BASE

/** An internal error has occurred in the Classification application. Please refer to the syslog file for additional information. */
#define CLS_err_internal_error                                      ( CLS0CLASSIFICATION_ERROR_BASE + 1 )

/** The mandatory parameter "%1$" in the function "%2$" has not been supplied. Please contact your system administrator to report this error. */
#define CLS_err_missing_parameter                                   ( CLS0CLASSIFICATION_ERROR_BASE + 2 )

/** A null reference was specified when expecting a non-null reference. */
#define CLS_err_null_tag_param                                      ( CLS0CLASSIFICATION_ERROR_BASE + 3 )

/** A mandatory output parameter "%1$" in the function "%2$" has not been supplied. Please contact your system administrator to report this error. */
#define CLS_err_missing_mandatory_output_param                      ( CLS0CLASSIFICATION_ERROR_BASE + 4 )

/** The given object type "%1$" is not a valid Classification object type. */
#define CLS_err_invalid_object_type                                 ( CLS0CLASSIFICATION_ERROR_BASE + 5 )

/** The search criteria property "%1$" was not specified. */
#define CLS_err_missing_search_criteria_prop                        ( CLS0CLASSIFICATION_ERROR_BASE + 6 )

/** The search criteria value "%1$" was not specified. */
#define CLS_err_missing_search_criteria_value                       ( CLS0CLASSIFICATION_ERROR_BASE + 7 )

/** The specified Classification class %1$ cannot be found. */
#define CLS_err_class_not_found                                     ( CLS0CLASSIFICATION_ERROR_BASE + 8 )

/** The specified Context with ID "%1$" cannot be found. */
#define CLS_err_context_not_found                                   ( CLS0CLASSIFICATION_ERROR_BASE + 9 )

/** The specified Hierarchy node with ID "%1$" cannot be found. */
#define CLS_err_node_not_found                                      ( CLS0CLASSIFICATION_ERROR_BASE + 10 )

/** The specified Hierarchy view with ID "%1$" cannot be found. */
#define CLS_err_hierarchy_view_not_found                            ( CLS0CLASSIFICATION_ERROR_BASE + 11 )

/** The object type input parameter has not been supplied. Please report this error to your system administrator.*/
#define CLS_err_missing_object_type                                 ( CLS0CLASSIFICATION_ERROR_BASE + 12 )

/** The specified object with ID "%1$" cannot be found. */
#define CLS_err_missing_classification_object                       ( CLS0CLASSIFICATION_ERROR_BASE + 13 )

/** The specified operation "%1$" is not supported on the given object type "%2$" at this time. */
#define CLS_err_operation_not_supported                             ( CLS0CLASSIFICATION_ERROR_BASE + 14 )

/** The supplied Hierarchy element type "%1$" is not supported. Please use an element of one of the following types or sub-types: %2$. */
#define CLS_err_hierarchy_element_unknown                           ( CLS0CLASSIFICATION_ERROR_BASE + 15 )

/** The specified file "%1$" cannot be opened, either because it does not exist, or it is being used by another process. */
#define CLS_err_opening_file                                        ( CLS0CLASSIFICATION_ERROR_BASE + 16 )

/** The specified upgrade path "%1$" is not supported for the current version. */
#define CLS_err_unsupported_upgrade_path                            ( CLS0CLASSIFICATION_ERROR_BASE + 17 )

/** Not able to parse the object. */
#define CLS_err_parse_json_object                                   ( CLS0CLASSIFICATION_ERROR_BASE + 18 )

/** The selected functionality cannot be used because the BMIDE template "%1$" is not deployed. */
#define CLS_err_missing_template                                    ( CLS0CLASSIFICATION_ERROR_BASE + 19 )

/** An invalid classification definition type was specified. */
#define CLS_invalid_classification_definition                       ( CLS0CLASSIFICATION_ERROR_BASE + 20 )

/** The value provided is invalid: %1$. Please refer to the syslog for more details. */
#define CLS_err_invalid_value                                       ( CLS0CLASSIFICATION_ERROR_BASE + 99 )

/** @} */

/**
   @name Context errors
   @{
*/
#define CLS0CLASSIFICATION_CONTEXT_ERROR_BASE                       ( CLS0CLASSIFICATION_ERROR_BASE + 100 )

/** The Context ID was not specified. */
#define CLS_err_missing_context_id                                  ( CLS0CLASSIFICATION_CONTEXT_ERROR_BASE + 1 )

/** The Context name was not specified. */
#define CLS_err_missing_context_name                                ( CLS0CLASSIFICATION_CONTEXT_ERROR_BASE + 2 )

/** A required reference to the containing Context was not specified. */
#define CLS_err_missing_context                                     ( CLS0CLASSIFICATION_CONTEXT_ERROR_BASE + 3 )

/** The default Classification Context with ID "%1$" cannot be deleted. */
#define CLS_err_context_cannot_delete_default                       ( CLS0CLASSIFICATION_CONTEXT_ERROR_BASE + 4 )

/** The Context with ID "%1$" cannot be saved because it would violate the uniqueness criteria. Please specify unique values. */
#define CLS_err_context_violates_uniqueness                         ( CLS0CLASSIFICATION_CONTEXT_ERROR_BASE + 5 )

/** The Context with ID "%1$" cannot be deleted, because it contains Hierarchy views. Please delete these Hierarchy views first, or invoke the delete operation again on this Context, using the "Recursive Delete" option. */
#define CLS_err_context_cannot_delete_views_exist                   ( CLS0CLASSIFICATION_CONTEXT_ERROR_BASE + 6 )

/** @} */

/**
   @name Hierarchy scheme errors
   @{
*/
#define CLS0CLASSIFICATION_SCHEME_ERROR_BASE                        ( CLS0CLASSIFICATION_ERROR_BASE + 200 )

/** The Scheme name is not specified. */
#define CLS_err_missing_scheme_name                                 ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 1 )

/** A required reference to the containing Context is not specified. */
#define CLS_err_missing_context_tag                                 ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 2 )

/** The specified Scheme cannot be found. */
#define CLS_err_scheme_not_found                                    ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 3 )

/** A required reference to the configuration Scheme was not specified. */
#define CLS_err_scheme_missing_hierarchy_scheme             ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 4 )

/** The default Classification Scheme of Type "%1$" cannot be deleted. */
#define CLS_err_scheme_cannot_delete_default                        ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 5 )

/** The Scheme of Type "%1$" cannot be saved because it would violate the uniqueness criteria. Please specify unique values. */
#define CLS_err_scheme_violates_uniqueness                          ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 6 )

/** A required reference to the classification scheme was not specified. Please report this error to your system administrator. */
#define CLS_err_missing_scheme                                      ( CLS0CLASSIFICATION_SCHEME_ERROR_BASE + 7 )

/** @} */

/**
   @name Hierarchy view errors
   @{
*/
#define CLS0HIERARCHY_VIEW_ERROR_BASE                               ( CLS0CLASSIFICATION_ERROR_BASE + 300 )

/** The Hierarchy view ID was not specified. */
#define CLS_err_missing_hierarchy_view_id                           ( CLS0HIERARCHY_VIEW_ERROR_BASE + 1 )

/** The Hierarchy view name was not specified. */
#define CLS_err_missing_hierarchy_view_name                         ( CLS0HIERARCHY_VIEW_ERROR_BASE + 2 )

/** An invalid Hierarchy view reference was specified. */
#define CLS_err_invalid_hierarchy_view                              ( CLS0HIERARCHY_VIEW_ERROR_BASE + 3 )

/** A required reference to the Hierarchy view was not specified. */
#define CLS_err_missing_hierarchy_view                              ( CLS0HIERARCHY_VIEW_ERROR_BASE + 4 )

/** A Hierarchy view with ID "%1$" could not be created. Please refer to the syslog file for additional information. */
#define CLS_err_hierarchy_view_creation_failed                      ( CLS0HIERARCHY_VIEW_ERROR_BASE + 5 )

/** The default Hierarchy view with ID "%1$" cannot be deleted. */
#define CLS_err_hierarchy_view_cannot_delete_default                ( CLS0HIERARCHY_VIEW_ERROR_BASE + 6 )

/** The Hierarchy view with ID "%1$" cannot be saved because it would violate the uniqueness criteria. Please specify unique values. */
#define CLS_err_hierarchy_view_violates_uniqueness                  ( CLS0HIERARCHY_VIEW_ERROR_BASE + 7 )

/** The Hierarchy view with ID "%1$" cannot be deleted, because it contains Hierarchy nodes. Please delete these Hierarchy nodes first, or invoke the delete operation again on this Hierarchy view, using the "Recursive Delete" option. */
#define CLS_err_hierarchy_view_cannot_delete_nodes_exist            ( CLS0HIERARCHY_VIEW_ERROR_BASE + 8 )

/** @} */

/**
   @name Hierarchy node errors
   @{
*/
#define CLS0HIERARCHY_NODE_ERROR_BASE                               ( CLS0CLASSIFICATION_ERROR_BASE + 400 )

/** The Hierarchy node ID was not specified. */
#define CLS_err_hierarchy_node_id_unspecified                       ( CLS0HIERARCHY_NODE_ERROR_BASE + 1 )

/** The Hierarchy node name was not specified. */
#define CLS_err_hierarchy_node_name_unspecified                     ( CLS0HIERARCHY_NODE_ERROR_BASE + 2 )

/** No parental reference is specified for the Hierarchy node with ID "%1$". Please specify either a parent Hierarchy node or Hierarchy view if this is a top-level node. */
#define CLS_err_orphaned_hierarchy_node                             ( CLS0HIERARCHY_NODE_ERROR_BASE + 3 )

/** An invalid parent node was specified for the Hierarchy node with ID "%1$". Please specify a parent node of type defined in the associated scheme. */
#define CLS_err_invalid_parent_node                                 ( CLS0HIERARCHY_NODE_ERROR_BASE + 4 )

/** Conflicting parental references are specified for the Hierarchy node with ID "%1$". Please specify only one parental reference. */
#define CLS_err_conflicting_parents                                 ( CLS0HIERARCHY_NODE_ERROR_BASE + 5 )

/** A circular ancestor lineage is defined for the Hierarchy node with ID "%1$". Please specify parental references that do not result in a circular lineage. */
#define CLS_err_circular_parental_lineage                           ( CLS0HIERARCHY_NODE_ERROR_BASE + 6 )

/** The specified Hierarchy node with ID "%1$" cannot be added as a child of the parent Hierarchy node with ID "%2$", because it is marked as a leaf node. */
#define CLS_err_cannot_add_child_to_parent_node                     ( CLS0HIERARCHY_NODE_ERROR_BASE + 7 )

/** The specified attachment type "%1$" is invalid for the Hierarchy node with ID "%2$". */
#define CLS_err_node_unknown_attachment_type                        ( CLS0HIERARCHY_NODE_ERROR_BASE + 8 )

/** The Hierarchy node with ID "%1$" cannot be saved because it would violate the uniqueness criteria. Please specify unique values. */
#define CLS_err_node_violates_uniqueness                            ( CLS0HIERARCHY_NODE_ERROR_BASE + 9 )

/** The specified node characteristic does not exist. */
#define CLS_err_unknown_characteristic                              ( CLS0HIERARCHY_NODE_ERROR_BASE + 10 )

/** A storage class was specified for the Group node with ID "%1$". A Group node cannot be associated with a storage class. Please create a Group node without specifying the storage class. */
#define CLS_err_storage_specified_for_group_node                    ( CLS0HIERARCHY_NODE_ERROR_BASE + 11 )

/** The associated storage class of ID "%1$" has already been consumed by the Master node of ID "%2$". Please specify a storage class that is not already consumed by any Master node. */
#define CLS_err_master_node_storage_already_used                    ( CLS0HIERARCHY_NODE_ERROR_BASE + 12 )

/** The creation of hierarchy nodes of type "%1$" is not supported. */
#define CLS_err_node_type_not_supported                             ( CLS0HIERARCHY_NODE_ERROR_BASE + 13 )

/** The master node namespace was not specified. */
#define CLS_err_master_node_namespace_unspecified                   ( CLS0HIERARCHY_NODE_ERROR_BASE + 14 )

/** The parent node is of type "%1$" which cannot accept Hierarchy nodes of type "%2$". Please specify a child node of one of these types: %3$.*/
#define CLS_err_cannot_add_unsupported_child_to_parent_node         ( CLS0HIERARCHY_NODE_ERROR_BASE + 15 )

/** @} */

/**
   @name Classification object (data) errors
   @{
*/
#define CLS0CLASSIFICATION_DATA_ERROR_BASE                          ( CLS0CLASSIFICATION_ERROR_BASE + 600 )

/** The Classification object ID is not specified. */
#define CLS_err_classification_object_id_unspecified                ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 1 )

/** The Classification object name is not specified. */
#define CLS_err_classification_object_name_unspecified              ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 2 )

/** A required Hierarchy node reference is not specified. */
#define CLS_err_missing_hierarchy_node_tag                          ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 3 )

/** The specified Workspace Object "%1$" of type "%2$" is not classifiable. Please verify that the preference "%3$" contains this type of Workspace Object. */
#define CLS_err_workspce_object_not_classifiable                    ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 4 )

/** The specified Object "%1$" of type "%2$" cannot be classified into the Hierarchy node with ID "%3$" because this node is abstract. */
#define CLS_err_cannot_classify_to_abstract_node                    ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 5 )

/** Multiple classification of the given Object "%1$" of type "%2$" is not allowed in the specified Hierarchy node with ID "%3$". Please verify the value of the 'Multiple Classification' characteristic for the specified node. */
#define CLS_err_multiple_classification_not_allowed                 ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 6 )

/** Please use an object ID or a name which can be used to uniquely identify for classification. The provided information "%1$" does not work out. */
#define CLS_err_object_to_classify_not_unique                       ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 7 )

/** The specified Object "%1$" of type "%2$" cannot be classified into the Hierarchy node with ID "%3$", because this node is a Group node. Please specify a Master node to classify an Object. */
#define CLS_err_cannot_classify_to_group_node                       ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 8)

/** The specified Object "%1$" of type "%2$" cannot be classified into the Hierarchy node with ID "%3$", because this node is a Reference node. Please specify a Master node to classify an Object. */
#define CLS_err_cannot_classify_to_reference_node                   ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 9)

/** The specified Workspace Object with name "%1$" cannot be found. */
#define CLS_err_workspace_object_not_found                          ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 10 )

/** The specified Item with ID "%1$" cannot be found. */
#define CLS_err_item_not_found                                      ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 11 )

/** The operation has failed, because a Classification object reference is required and not specified. */
#define CLS_err_missing_classification_object_tag                   ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 12 )

/** The specified Workspace object "%1$" is invalid, because it is not an Item or Item Revision. */
#define CLS_err_invalid_workspace_object_tag                        ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 13 )

/** A standalone object with the given ID "%1$" already exists. Please specify another ID to create a standalone object or specify a Workspace Object if you want to connect it to the existing Classification object with this ID. */
#define CLS_err_duplicate_standalone_object                         ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 14 )

/** "%1$" cannot be classified into the Hierarchy node of ID "%2$" because no storage class is attached to this node. */
#define CLS_err_cannot_classify_to_node_without_storage             ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 15 )

/** "%1$" cannot be classified using Classification Standard Taxonomy (CST) because the object is already classified as "%2$" in the ICS/SML Classification system. */
#define CLS_err_cannot_classify_in_cst_due_to_sml_classification    ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 16 )

/** The object "%1$" is already migrated and in released status.*/
#define CLS_err_already_migrated_and_released                       ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 17 )

/** A namespace has not been specified for the migration. Please assign a namespace in the "CST_default_namespace" preference.*/
#define CLS_err_migration_missing_namespace                         ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 18 )

/** A status has not been specified for the migration. Please assign a status in the "CST_default_migration_status" preference.*/
#define CLS_err_migration_missing_status                            ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 19 )

/** The object "%1$" is already migrated using namespace "%2$" and therefore cannot be migrated using the namespace "%3$".*/
#define CLS_err_object_already_migrated_in_different_namespace      ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 20 )

/** The status defined in "CST_default_migration_status" is invalid. Valid values are "Develop" and "Released". */
#define CLS_err_migration_preference_wrong                          ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 21 )

/** "%1$" cannot be classified because no master node is attached with the storage class "%2$". Please contact your system administrator. */
#define CLS_err_cannot_classify_to_storage_without_master_node      ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 22 )

/** Some partial errors have occurred. Refer to the result information for each object. */
#define CLS_err_partial_errors_for_request                           ( CLS0CLASSIFICATION_DATA_ERROR_BASE + 23 )

/** @} */

/**
   @name Search and enquiry errors
   @{
*/
#define CLS0CLASSIFICATION_SEARCH_ERROR_BASE                        ( CLS0CLASSIFICATION_ERROR_BASE + 700 )

/** A Classification search result set could not be found. */
#define CLS_err_result_set_not_found                                ( CLS0CLASSIFICATION_SEARCH_ERROR_BASE + 1 )

/** The Classification search cannot be performed, because the specified search expression "%1$" contains unsupported date format. Please specify the value in the following format: "%2$". */
#define CLS_err_search_unsupported_date_format                      ( CLS0CLASSIFICATION_SEARCH_ERROR_BASE + 2 )

/** The Classification search cannot be performed, because the specified property "%1$" does not belong to the storage class with ID "%2$" associated with the node. Please specify the property which belongs to a storage class associated with the node. */
#define CLS_err_search_property_not_of_storage_class                ( CLS0CLASSIFICATION_SEARCH_ERROR_BASE + 3 )

/** The Search index %1$ is out of range. Please specify a value between 1 and %2$.*/
#define CLS_err_search_index_out_of_range                           ( CLS0CLASSIFICATION_SEARCH_ERROR_BASE + 4 )

/** @} */

/**
   @name Node Image errors
   @{
*/
#define CLS0CLASSIFICATION_NODE_IMAGE_BASE                          ( CLS0CLASSIFICATION_ERROR_BASE + 800 )

/** An internal error has occurred when working with the Hierarchy node image "%1$". Please refer to the syslog for additional details. */
#define CLS_err_image_internal_error                                ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 1 )

/** A Hierarchy node is not specified for this relation. */
#define CLS_err_image_missing_node                                  ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 2 )

/** An image dataset is not specified for this relation. */
#define CLS_err_image_missing_image_dataset                         ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 3 )

/** A relation type is not specified for this node image attachment. */
#define CLS_err_image_missing_relation_type                         ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 4 )

/** The specified image index of "%1$" is not valid. Please select another index. */
#define CLS_err_image_index_not_valid                               ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 5 )

/** The specified image index of "%1$" is already used. Please select another index. */
#define CLS_err_image_index_conflict                                ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 6 )

/** A primary image already exists for this Hierarchy node with ID "%1$". */
#define CLS_err_image_primary_already_exists                        ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 7 )

/** A primary image does not exist for this Hierarchy node with ID "%1$". */
#define CLS_err_image_primary_does_not_exist                        ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 8 )

/** The existing association between the given Hierarchy node with ID "%1$" and its image "%2$" cannot be changed. */
#define CLS_err_image_cannot_change                                 ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 9 )

/** The primary image cannot be unassigned. This can only be achieved implicitly when another image is assigned as the new primary. */
#define CLS_err_cannot_unassign_primary                             ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 10 )

/** The specified image "%1$" is not attached to the given Hierarchy node with ID "%2$". */
#define CLS_err_image_not_attached_to_node                          ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 11 )

/** A primary image cannot be removed while secondary images are still associated with the given Hierarchy node with ID "%1$". Please remove the secondary images or assign a new primary image before proceeding. */
#define CLS_err_image_cannot_remove_primary_b4_secondary            ( CLS0CLASSIFICATION_NODE_IMAGE_BASE + 12 )

/** @} */


/**
   @name Cls0NodeIcon errors
   @{
*/
#define CLS0CLASSIFICATION_NODE_ICON_BASE                           ( CLS0CLASSIFICATION_ERROR_BASE + 850 )

/** An internal error has occurred when working with the Hierarchy node icon "%1$". Please refer to the syslog for additional details. */
#define CLS_err_icon_internal_error                                 ( CLS0CLASSIFICATION_NODE_ICON_BASE + 1 )

/** The specified Hierarchy node with ID "%1$" has more than one icon attached. Please contact your system administrator to resolve this conflict. */
#define CLS_err_icon_multiple_icons_for_node                        ( CLS0CLASSIFICATION_NODE_ICON_BASE + 2 )

/** The existing association between the given Hierarchy node with ID "%1$" and its icon "%2$" cannot be changed. */
#define CLS_err_icon_cannot_change                                  ( CLS0CLASSIFICATION_NODE_ICON_BASE + 3 )

/** @} */

/**
    @name Runtime type errors
    @{
*/
#define CLS0CLASSIFICATION_RUNTIME_TYPE_BASE                        ( CLS0CLASSIFICATION_ERROR_BASE + 900 )

/** Required 'Type name' parameter not supplied when creating Runtime type in "%1$". */
#define CLS_err_runtime_type_missing_type_name                      ( CLS0CLASSIFICATION_RUNTIME_TYPE_BASE + 1 )

/** Parent type tag not provided for creation of the specified specified type "%1$". */
#define CLS_err_runtime_missing_parent_type_ref                     ( CLS0CLASSIFICATION_RUNTIME_TYPE_BASE + 2 )

/** The required "Class name" parameter was not provided when creating the runtime type "%1$". */
#define CLS_err_runtime_type_missing_class_name                     ( CLS0CLASSIFICATION_RUNTIME_TYPE_BASE + 3 )

/** @} */

/**
    @name License errors
    @{
*/
#define CLS0CLASSIFICATION_LICENSE_BASE                             ( CLS0CLASSIFICATION_ERROR_BASE + 950 )

/** The required "Classification User" license is missing or not installed. Please contact your system administrator. */
#define CLS_err_user_license_missing                                ( CLS0CLASSIFICATION_LICENSE_BASE + 1 )

/** The required "Eclass User" license is missing or not installed. Please contact your system administrator. */
#define CLS_err_eclass_license_missing                              ( CLS0CLASSIFICATION_LICENSE_BASE + 2 )

/**
    @}
*/

/**
    @}
*/

#endif
