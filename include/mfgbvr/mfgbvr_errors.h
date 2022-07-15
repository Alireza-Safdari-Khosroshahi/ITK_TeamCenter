/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2009.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file
    This file contains the error codes for the MFGBVR module
*/

#ifndef MFGBVR_ERRORS_H
#define MFGBVR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup MFGBVR_ERRORS Errors
    @ingroup MFGBVR
    @{
*/

/**
    An internal MFGBVR error has occurred. Please contact your system administrator.
*/
#define MFGBVR_internal_error                                                (EMH_MFGBVR_error_base + 1)

/**
    A null object was passed to the MFGBVRConnectionCommand::disconnect method.
*/
#define MFGBVR_disconnect_got_NULL_object                                    (EMH_MFGBVR_error_base + 2)

/**
    A root partition was not found in the CreateInput parameters. Please contact your system administrator.
*/
#define MFGBVR_root_partition_was_not_found_in_CreateInput                   (EMH_MFGBVR_error_base + 3)

/**
    The object cannot be created because no target is specified.
*/
#define MFGBVR_cannot_create_an_object_without_a_target                      (EMH_MFGBVR_error_base + 4)

/**
    The part assignment is illegal. Please use the correct workflow to assign parts.
*/
#define MFGBVR_illegal_part_assignments                                      (EMH_MFGBVR_error_base + 5)

/**
    The part cannot be assigned to the provided target. Please use the correct workflow to assign parts.
*/
#define MFGBVR_part_cannot_be_assigned_to_target                             (EMH_MFGBVR_error_base + 6)

/**
    The relation "Mfg0MEResolvedAssignmentRel" cannot be found. Please contact your system administrator.
*/
#define MFGBVR_Mfg0MEResolvedAssignmentRel_relation_not_found                (EMH_MFGBVR_error_base + 7)

/**
    The assignment type of this Logical Assignment is illegal. This is a data corruption, please contact your system administrator.
*/
#define MFGBVR_Illegal_assignment_type                                       (EMH_MFGBVR_error_base + 8)

/**
    The search criteria of this Logical Assignment is illegal. This is a data corruption, please contact your system administrator.
*/
#define MFGBVR_search_criteria_is_illegal                                    (EMH_MFGBVR_error_base + 9)

/**
    The search criteria object could not be instantiated. Please contact your system administrator.
*/
#define MFGBVR_SearchCriteriaAttribute_cannot_be_instantiated                (EMH_MFGBVR_error_base + 10)

/**
    The received Logical Assignment object is not under the received line. Please contact your system administrator.
*/
#define MFGBVR_received_LA_is_not_under_received_line                        (EMH_MFGBVR_error_base + 11)

/**
    The provided parent line is invalid. Please contact your system administrator.
*/
#define MFGBVR_invalid_parent                                                (EMH_MFGBVR_error_base + 12)

/**
    The provided line is invalid. Please contact your system administrator.
*/
#define MFGBVR_invalid_node                                                  (EMH_MFGBVR_error_base + 13)

/**
    The Occurrence does not have an occurrence thread.
*/
#define MFGBVR_occurrence_does_not_have_occurrence_thread                    (EMH_MFGBVR_error_base + 14)

/**
    The target node does not have a BOM View Revision.
*/
#define MFGBVR_target_node_does_not_have_BVR                                 (EMH_MFGBVR_error_base + 15)

/**
    The Occurrence does not exist in the target node.
*/
#define MFGBVR_occurrence_does_not_exist_in_target_node                      (EMH_MFGBVR_error_base + 16)

/**
    The Occurrence does not have Absolute Path Node.
*/
#define MFGBVR_occurrence_does_not_have_APN                                  (EMH_MFGBVR_error_base + 17)

/**
    The object does not have a revision.
*/
#define MFGBVR_obj_does_not_have_revision                                    (EMH_MFGBVR_error_base + 18)

/**
    The relation "Mfg0MEProductLAssignmentRel" is not found. Please contact your system administrator.
*/
#define MFGBVR_Mfg0MEProductLAssignmentRel_relation_not_found                (EMH_MFGBVR_error_base + 19)

/**
    The relation "IMAN_MEAppearance" is not found. Please contact your system administrator
*/
#define MFGBVR_IMAN_MEAppearance_relation_not_found                          (EMH_MFGBVR_error_base + 20)

/**
    The assignment type "%1$" is invalid for this object.
*/
#define MFGBVR_assignment_type_invalid_for_obj                               (EMH_MFGBVR_error_base + 21)

/**
    The assignment type "%1$" does not exist.
*/
#define MFGBVR_assignment_type_does_not_exist                                (EMH_MFGBVR_error_base + 22)

/**
    The initialization of the new object has failed. Please contact your system administrator.
*/
#define MFGBVR_initialize_failed                                             (EMH_MFGBVR_error_base + 23)

/**
    The creation of the new object has failed. Please contact your system administrator.
*/
#define MFGBVR_creation_failed                                               (EMH_MFGBVR_error_base + 24)

/**
    A part could not be assigned because of an internal error. Please contact your system administrator.
*/
#define MFGBVR_assign_part_failed                                            (EMH_MFGBVR_error_base + 25)

/**
    The relation "IMAN_MEView" is not found. Please contact your system administrator.
*/
#define MFGBVR_IMAN_MEView_relation_not_found                                (EMH_MFGBVR_error_base + 26)

/**
    The loaded Item Revision is different from the selected Item Revision.
*/
#define MFGBVR_another_revision_configured                                   (EMH_MFGBVR_error_base + 27)

/**
    No Item Revision is found as per the target configuration.
*/
#define MFGBVR_no_revision_found_as_per_configuration                        (EMH_MFGBVR_error_base + 28)

/**
    The structure has been loaded using the default revision rule. The root cause is: %1$
*/
#define MFGBVR_structure_loaded_with_default_revision_rule                   (EMH_MFGBVR_error_base + 29)

/**
    A loop has been detected in the flow graph of the Plant BOP. The path is: %1$
*/
#define MFGBVR_loop_in_precedence_graph                                      (EMH_MFGBVR_error_base + 30)

/**
    A loop has been detected in the graph of precedence constraints.
*/
#define MFGBVR_cycle_in_precedence_graph                                     (EMH_MFGBVR_error_base + 31)

/**
    No configured revision is found for the top line item &quot;%1$&quot;.
    Please change the default revision rule, or choose a specific revision, in order to see the required structure.
*/
#define MFGBVR_no_configured_revision                                        (EMH_MFGBVR_error_base + 32)

/**
    The Appearance Group does not refer to an Appearance Path Root.
*/
#define MFGBVR_AppGroup_without_APR                                          (EMH_MFGBVR_error_base + 33)

/**
    Service name is defined.
*/
#define MFGBVR_service_name_is_defined                                       (EMH_MFGBVR_error_base + 34)

/**
    The Tool Requirement name cannot be empty.
*/
#define MFGBVR_tool_requirement_empty_name                                   (EMH_MFGBVR_error_base + 35)

/**
    The relation of type "Mfg0METoolRequirementRel" is not found. Please contact your system administrator.
*/
#define MFGBVR_Mfg0METoolRequirementRel_relation_not_found                   (EMH_MFGBVR_error_base + 36)
/**
    Please load the plant structure in order to search for the candidate tools in the consumed Work Area.
*/
#define MFGBVR_WorkArea_window_not_loaded                                    (EMH_MFGBVR_error_base + 37)
/**
    An error has occurred with the provided reference object. Either its type is invalid (the type "Product BOP" is expected), or the object is not associated with the given "Plant BOP".
*/
#define MFGBVR_automatic_allocate_invalid_object_refernce                    (EMH_MFGBVR_error_base + 38)
/**
    The provided source object type is invalid. Only an object of type "Product BOP" is expected.
*/
#define MFGBVR_automatic_allocate_invalid_object_source                      (EMH_MFGBVR_error_base + 39)
/**
    The provided target object type is invalid. Only an object of type "Plant BOP" is expected.
*/
#define MFGBVR_automatic_allocate_invalid_object_target                      (EMH_MFGBVR_error_base + 40)
/**
    The structure has been loaded without any closure rule. The root cause is: %1$.
*/
#define MFGBVR_structure_loaded_without_closure_rule                         (EMH_MFGBVR_error_base + 41)

/**
    A failure has occurred during the creation of a "%1$" relation between the objects "%2$" and "%3$". Please contact your system
administrator.
*/
#define MFGBVR_failed_to_create_relation                                     (EMH_MFGBVR_error_base + 42)

/**
    A failure has occurred during the deletion of the "%1$" relation between the objects "%2$" and "%3$". Please contact your system
administrator.
*/
#define MFGBVR_failed_to_delete_relation                                     (EMH_MFGBVR_error_base + 43)

/**
    A failure has occurred while saving the "%1$" relation between "%2$" and "%3$". Please contact your system administrator.
*/
#define MFGBVR_failed_to_save_relation                                       (EMH_MFGBVR_error_base + 44)

/**
    A failure has occurred while retrieving the objects linked to "%1$" through the "%2$" relation. Please contact your system
administrator.
*/
#define MFGBVR_failed_to_list_secondaries                                    (EMH_MFGBVR_error_base + 45)

/**
    The relation type "%1$" is not defined. Please contact your system administrator.
*/
#define MFGBVR_undefined_relation_type                                       (EMH_MFGBVR_error_base + 46)

/**
    The occurrence note type "%1$" is not defined. Please contact your system administrator.
*/
#define MFGBVR_undefined_occurrence_note_type                                (EMH_MFGBVR_error_base + 47)

/**
    The Plant Bill Of Process (BOP) "%1$" is linked to multiple Product BOPs. Please select one of the Product BOPs as context.

*/
#define MFGBVR_multiple_linked_product_bops                                  (EMH_MFGBVR_error_base + 48)

/**
    The Product Bill Of Process (BOP) "%1$" and the Plant BOP "%2$" are not linked.

*/
#define MFGBVR_product_bop_is_not_linked                                     (EMH_MFGBVR_error_base + 49)

/**
    No Product Bill Of Process (BOP) is associated with the Plant BOP "%1$".

*/
#define MFGBVR_no_product_bop_is_associated                                  (EMH_MFGBVR_error_base + 50)

/**
    The objects "%1$" and "%2$" are already related by the relation "%3$".

*/
#define MFGBVR_objects_already_related                                       (EMH_MFGBVR_error_base + 51)

/**
    The occurrence type "%1$" does not exist.
*/
#define MFGBVR_undefined_occurrence_type                                     (EMH_MFGBVR_error_base + 52)

/**
    The object "%1$" is already associated to the process resource "%2$". This action is ignored.
*/
#define MFGBVR_already_associated_to_same_process_resource                   (EMH_MFGBVR_error_base + 53)

/**
    The action has failed, because the Plant Structure "%1$" is not loaded.
*/
#define MFGBVR_plant_structure_not_loaded                                    (EMH_MFGBVR_error_base + 54)

/**
    The color can be set only on resources assigned from a Plant Structure.
*/
#define MFGBVR_cannot_set_color_on_resource                                  (EMH_MFGBVR_error_base + 55)

/**
    The objects are exported to the remote site without ownership transfer, because the Closure Rule "%1$" does not exist or does not evaluate to return any node.

*/
#define MFGBVR_objects_exported_without_ot                                   (EMH_MFGBVR_error_base + 56)

/**
    At least one value specified for the preference "MERuleForBriefcaseExport" is invalid. Please read the documentation of the preference and correct accordingly.

*/
#define MFGBVR_invalid_value_for_preference                                  (EMH_MFGBVR_error_base + 57)

/**
    The Bill Of Equipment structure creation has failed because the mapped object type for "%1$" is not defined in the preference "MEBOPToBOEObjectTypeMap".

*/
#define MFGBVR_create_boe_no_mapping_available                               (EMH_MFGBVR_error_base + 58)

/**
The Bill of Equipment structure creation has failed because the input root lines do not represent Plant Bill Of Process structures.

*/
#define MFGBVR_invalid_plant_bop_input                                       (EMH_MFGBVR_error_base + 59)

/**
    The dataset "%1$" provided by the preference "MEBOPToBOEObjectTypeMap" has no named reference associated with it.

*/
#define MFGBVR_BOPToBOE_no_mapping_xml                                       (EMH_MFGBVR_error_base + 60)

/**
    The dataset "%1$" provided by the preference "MEBOPToBOEObjectTypeMap" does not exist.

*/
#define MFGBVR_BOPToBOE_no_dataset                                           (EMH_MFGBVR_error_base + 61)

/**
    The input objects "%1$" and "%2$" cannot be linked because no mapping is available between the input types "%3$", "%4$" in the preference "MEBOPToBOEObjectTypeMap".

*/
#define MFGBVR_link_boe_no_mapping_available                                 (EMH_MFGBVR_error_base + 62)

/**
    The input Plant Bill Of Process object "%1$" and Bill of Equipment object "%2$" cannot be linked because their toplines are not linked.

*/
#define MFGBVR_link_boe_toplines_not_linked                                  (EMH_MFGBVR_error_base + 63)

/**
    The input objects "%1$" and "%2$" cannot be linked because the input Plant Bill Of Process top line "%1$" is already linked to another Bill Of Equipment structure "%3$".

*/
#define MFGBVR_link_plant_bop_already_linked                                 (EMH_MFGBVR_error_base + 64)

/**
    The input objects "%1$" and "%2$" cannot be linked because their types "%3$" and "%4$" are not compatible. Please refer to the preference "MEBOPToBOEObjectTypeMap" for type mapping.

*/
#define MFGBVR_link_object_types_not_compatible                              (EMH_MFGBVR_error_base + 65)

/**
    The input objects "%1$" and "%2$" cannot be linked. Please check the Teamcenter server syslog file for more information.

*/
#define MFGBVR_link_failed_for_input_objects                                 (EMH_MFGBVR_error_base + 66)

/**
    The input objects "%1$" and "%2$" cannot be synchronized because they are not linked.

*/
#define MFGBVR_sync_input_objects_not_linked                                 (EMH_MFGBVR_error_base + 67)

/**
    The input objects "%1$" and "%2$" cannot be synchronized. Please check the Teamcenter server syslog file for more information.

*/
#define MFGBVR_sync_failed_for_input_objects                                 (EMH_MFGBVR_error_base + 68)

/**
    The selected input objects "%1$" and "%2$" are already linked.

*/
#define MFGBVR_link_input_objects_already_linked                             (EMH_MFGBVR_error_base + 69)

/**
    The "%1$" structure was created with some errors. Please check the Teamcenter server syslog file for more information.

*/
#define MFGBVR_target_structure_created_with_errors                          (EMH_MFGBVR_error_base + 70)

/**
     The Bill Of Process structure creation has failed because the type "%1$" of the input object "%2$" is not defined in the preference "MEBOPToBOEObjectTypeMap".

*/
#define MFGBVR_create_bop_no_mapping_available                               (EMH_MFGBVR_error_base + 71)

/**
Structures cannot be exported partially.

*/
#define MFGBVR_partial_export_not_allowed                                    (EMH_MFGBVR_error_base + 72)

/**
    The input objects "%1$" and "%2$" cannot be synchronized because their types "%3$" and "%4$" are not compatible. Please refer to the preference "MEBOPToBOEObjectTypeMap" for type mapping.

*/
#define MFGBVR_sync_object_types_not_compatible                              (EMH_MFGBVR_error_base + 73)

/**
    The object "%1$" cannot be assigned because of the following error: %2$
*/
#define MFGBVR_assign_object_failed                                          (EMH_MFGBVR_error_base + 74)

/**
    There are no studies to propagate in the Collaboration Context "%1$".
*/
#define MFGBVR_no_studies_to_propagate_in_cc                                 (EMH_MFGBVR_error_base + 75)

/**
    The input context "%1$" is invalid. Context should be root line in the structure.
*/
#define MFG_physical_attachment_invalid_context                              (EMH_MFGBVR_error_base + 76)

/**
    The input scope "%1$" is invalid. Scope should be either work area, under the given context, study, or process. 
*/
#define MFG_physical_attachment_invalid_scope                                (EMH_MFGBVR_error_base + 77)

/**
    The property "%1$" does not exist for relation "%2$".
*/
#define MFG_physical_attachment_invalid_property_name                        (EMH_MFGBVR_error_base + 78)

/**
    The value "%1$" provided for property "%2$" is not valid for relation "%3$".
*/
#define MFG_physical_attachment_invalid_property_value                        (EMH_MFGBVR_error_base + 79)

/**
    An error occurred while deleting a relation "%1$" between the source "%2$" and target "%3$". Please check the Teamcenter server syslog file for more information.
*/
#define MFG_physical_attachment_relation_delete_failed                        (EMH_MFGBVR_error_base + 80)

/**
    The connector information is not defined for the input object "%1$".
*/
#define MFG_physical_attachment_connector_not_present                         (EMH_MFGBVR_error_base + 81)

/**
    The property "%1$" does not exist for the object "Mfg0MEConnectorTableRow".
*/
#define MFG_physical_attachment_invalid_connector_property_name               (EMH_MFGBVR_error_base + 82)

/**
    The value "%1$" provided for property "%2$" is not valid for the object "Mfg0MEConnectorTableRow".
*/
#define MFG_physical_attachment_invalid_connector_property_value              (EMH_MFGBVR_error_base + 83)

/**
    No flow object can be reconstructed from the input recipe "%1$". The flow object might have got deleted in another server session. Please refresh the structure and try the scenario again.
*/
#define MFG_no_reconstructed_flow                                             (EMH_MFGBVR_error_base + 84)

/**
    The input dataset is not of type "Mfg0OccKinematicsInfo".
*/
#define MFG_kinematics_invalid_dataset_type                                   (EMH_MFGBVR_error_base + 85)

/**
    The input BOM Line does not represent a resource occurrence. The BOM Line should represent an occurrence of "Mfg0MEResourceRevision" or "ItemRevision" in the Bill of Equipment structure.
*/
#define MFG_kinematics_invalid_input_bomline_type                             (EMH_MFGBVR_error_base + 86)

/**
The twin structure creation has failed because the provided root line is neither the top node of a Plant Bill of Equipment nor of a Plant Bill Of Process structure.
*/
#define MFGBVR_invalid_create_twin_input                                      (EMH_MFGBVR_error_base + 87)

/**
    The associated Plant Bill Of Process structure already exists for the given input Bill of Equipment line.
*/
#define MFGBVR_associated_plantbop_already_exist                              (EMH_MFGBVR_error_base + 88)

/**
    The associated Bill Of Equipment structure already exists for the given input Plant Bill of Process line.
*/
#define MFGBVR_associated_plant_already_exist                                 (EMH_MFGBVR_error_base + 89)

/**
The twin structure synchronization has failed because the provided line is neither the node of a Plant Bill of Equipment nor of a Plant Bill Of Process structure.
*/
#define MFGBVR_invalid_sync_twin_input                                        (EMH_MFGBVR_error_base + 90)

/**
    The associated Plant Bill Of Process line does not exist for the given input "%1$" Bill of Equipment line.
*/
#define MFGBVR_associated_plantbop_does_not_exist                             (EMH_MFGBVR_error_base + 91)

/**
    The associated Bill Of Equipment line does not exist for the given input "%1$" Plant Bill of Process line.
*/
#define MFGBVR_associated_plant_does_not_exist                                (EMH_MFGBVR_error_base + 92)

/** @} */

#endif

