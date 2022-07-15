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
    This file contains the error codes for the MFG module
*/

#ifndef MFG_ERRORS_H
#define MFG_ERRORS_H

#include <common/emh_const.h>
#include <mfg/libmfg_exports.h>

/**
    @defgroup MFG_ERRORS Errors
    @ingroup MFG
    @{
*/


/**
    A Manufacturing internal error occurred. Please contact your administrator.    
*/
#define MFG_internal_error                                                                                            (EMH_MFG_error_base + 1)

/**
    The node %1$ cannot be used in Time Analyis computations.    
*/
#define MFG_invalid_node_for_timeAnalysis                                                                             (EMH_MFG_error_base + 2)

/**
    Cyclic dependencies have been encountered in the flow graph of node "%1$".
*/
#define MFG_cyclic_dependencies                                                                                       (EMH_MFG_error_base + 3)

/**
    Cyclic dependencies have been encountered in the flow graph while processing the node "%1$".
*/
#define MFG_cyclic_dependencies2                                                                                      (EMH_MFG_error_base + 4)

/**
    The class definition is invalid.
*/
#define MFG_no_class_def                                                                                              (EMH_MFG_error_base + 10)

/**
    The property type is not valid.
*/
#define MFG_wrong_prop_type                                                                                           (EMH_MFG_error_base + 11)

/**
    No property is specified.
*/
#define MFG_no_prop                                                                                                   (EMH_MFG_error_base + 12)

/**
    The SM memory allocation is out of memory.
*/
#define MFG_SM_is_out_of_memory                                                                                       (EMH_MFG_error_base + 13)

/**
    The action name is already defined.
*/
#define MFG_action_name_defined                                                                                       (EMH_MFG_error_base + 14)

/**
    The dictionary is not defined.
*/
#define MFG_dictionary_not_defined                                                                                    (EMH_MFG_error_base + 15)

/**
    The Set method is not implemented in the mapper.
*/
#define MFG_set_not_imp_in_mapper                                                                                     (EMH_MFG_error_base + 16)

/**
    The Get method is not implemented in the mapper.
*/
#define MFG_get_not_imp_in_mapper                                                                                     (EMH_MFG_error_base + 17)

/**
    The Add method is not implemented in the mapper.
*/
#define MFG_add_not_imp_in_mapper                                                                                     (EMH_MFG_error_base + 18)

/**
    The Remove method is not implemented in the mapper.
*/
#define MFG_rem_not_imp_in_mapper                                                                                     (EMH_MFG_error_base + 19)

/**
    The Clean method is not implemented in the mapper.
*/
#define MFG_cln_not_imp_in_mapper                                                                                     (EMH_MFG_error_base + 20)

/**
    The given predecessor is invalid.
*/
#define MFG_Invalid_predecessor                                                                                       (EMH_MFG_error_base + 21)

/**
    The given successor is invalid.
*/
#define MFG_Invalid_Successor                                                                                         (EMH_MFG_error_base + 22)

/**
    A new Flow object cannot be created.
*/
#define MFG_flow_creation_fail                                                                                        (EMH_MFG_error_base + 23)

/**
    The selected Flow object is invalid.
*/
#define MFG_Invalid_flow                                                                                              (EMH_MFG_error_base + 24)

/**
    The object is not of type Logical Assignment.
*/
#define MFG_object_not_logical_assignment                                                                             (EMH_MFG_error_base + 25)

/**
    The requested object cannot be connected to the specified target.
*/
#define MFG_cannot_connect_requested_obj_to_specified_target                                                          (EMH_MFG_error_base + 26)

/**
    The Manufacturing type cannot be retrieved from the core type.
*/
#define MFG_cannot_get_mfg_type_from_core_type                                                                        (EMH_MFG_error_base + 27)

/**
    The object is not modifiable.
*/
#define MFG_object_is_not_modifiable                                                                                  (EMH_MFG_error_base + 28)

/**
    The node cannot be connected to the target.
*/
#define MFG_cannot_connect_node                                                                                       (EMH_MFG_error_base + 29)

/**
    The disconnect has failed.
*/
#define MFG_cannot_disconnect_node                                                                                    (EMH_MFG_error_base + 30)

/**
    The object to resolve is of wrong type.
*/
#define MFG_wrong_type_to_resolve                                                                                     (EMH_MFG_error_base + 31)

/**
    Logical Assignment '%1$' of this object could not be resolved.
*/
#define MFG_nothing_was_assigned_for_LA                                                                               (EMH_MFG_error_base + 32)

/**
    The Connect method is not implemented by this behavior.
*/
#define MFG_connect_not_implemented                                                                                   (EMH_MFG_error_base + 33)

/**
    The Part cannot be assigned because the relation is invalid.
*/
#define MFG_part_assignment_wrong_relation                                                                            (EMH_MFG_error_base + 34)

/**
    The Logical Assignment object does not contain any search criteria.
*/
#define MFG_logical_assign_without_criteria                                                                           (EMH_MFG_error_base + 35)

/**
    The attribute '%1$' does not exist.
*/
#define MFG_missing_attribute                                                                                         (EMH_MFG_error_base + 36)

/**
    The Search criteria does not contain the '%1$' property.
*/
#define MFG_missing_search_criteria_attribute                                                                         (EMH_MFG_error_base + 37)

/**
    Nothing was assigned for this Logical Assignment object.
*/
#define MFG_non_assigned_object                                                                                       (EMH_MFG_error_base + 38)

/**
    Content of Process Partition should contain only processes.
*/
#define MFG_Process_Partition_content_condition                                                                       (EMH_MFG_error_base + 39)

/**
    Sub-elements of Process Partition should contain only Process Partition.
*/
#define MFG_Process_Partition_sub_element_condition                                                                   (EMH_MFG_error_base + 40)

/**
    The given closure rule is invalid.
*/
#define MFG_invalid_closure_rule                                                                                      (EMH_MFG_error_base + 41)

/**
    The selected Flow is implicit and cannot be removed.
*/
#define MFG_cannot_remove_implicit_flow                                                                               (EMH_MFG_error_base + 42)

/**
    The Flow between two selected objects already exists.
*/
#define MFG_flow_between_two_objects_already_exists                                                                   (EMH_MFG_error_base + 43)

/**
    The type &quot;%1$&quot; is not supported for this operation.
*/
#define MFG_unsupported_type                                                                                          (EMH_MFG_error_base + 44)

/**
    The default implementation will be used for this field.
*/
#define MFG_perform_default_implementation                                                                            (EMH_MFG_error_base + 45)

/**
    The comparison functionality is not implemented for this field.
*/
#define MFG_compare_not_implemented                                                                                   (EMH_MFG_error_base + 46)

/**
    The propagation functionality is not implemented for this field.
*/
#define MFG_propagate_not_implemented                                                                                 (EMH_MFG_error_base + 47)

/**
    The handler is already defined for this field.
*/
#define MFG_handler_already_defined                                                                                   (EMH_MFG_error_base + 48)

/**
    There must be at least one source and one target for comparison.
*/
#define MFG_compared_objects_empty                                                                                    (EMH_MFG_error_base + 49)

/**
    The following objects were not propagated, because propagation from multiple sources is not allowed: &quot;%1$&quot;.
*/
#define MFG_multiple_sources_propagation                                                                              (EMH_MFG_error_base + 50)

/**
    The object &quot;%1$&quot; is not modifiable and was not propagated.
*/
#define MFG_object_not_modifiable                                                                                     (EMH_MFG_error_base + 51)

/**
    The property &quot;%1$&quot; is not modifiable and was not propagated.
*/
#define MFG_property_not_modifiable                                                                                   (EMH_MFG_error_base + 52)

/**
    The property &quot;%1$&quot; could not be set for the following reason: 
    %2$
*/
#define MFG_property_not_propagated                                                                                   (EMH_MFG_error_base + 53)

/**
    The predecessor and the successor are not from the same context
*/
#define MFG_predecessor_successor_from_different_contexts                                                             (EMH_MFG_error_base + 54)

/**
    The node &quot;%1$&quot; cannot be used in &quot;Line Balancing&quot; computations.
*/
#define MFG_invalid_node_for_lineBalancing                                                                            (EMH_MFG_error_base + 55)

/**
    One or more of the objects cannot be pasted to the target.
*/
#define MFG_cannot_paste_object_to_target                                                                             (EMH_MFG_error_base + 56)

/**
    The propagation of the assignments has failed because the source and the target contain a different number of objects.
*/
#define MFG_different_number_of_assigned_objects_propagation                                                          (EMH_MFG_error_base + 57)

/**
    The Flow object &quot;%1$&quot; will not be propagated, because this object has a structure specific predecessor.
*/
#define MFG_structure_specific_predecessor_in_target                                                                  (EMH_MFG_error_base + 58)

/**
    The Assignment &quot;%1$&quot; could not be propagated to the object &quot;%2$&quot;.
*/
#define MFG_assignment_propagation_failed                                                                             (EMH_MFG_error_base + 59)

/**
    The Relation type of &quot;%1$&quot; cannot be replaced because more than one Relation type is selected.
*/
#define MFG_cannot_replace_relation_type                                                                              (EMH_MFG_error_base + 60)

/**
    The Assignment &quot;%1$&quot; cannot be propagated to the object &quot;%2$&quot; because more than one Relation type is selected.
*/
#define MFG_cannot_propogate_because_of_relation_type                                                                 (EMH_MFG_error_base + 61)

/**
    The propagation operation of &quot;%1$&quot; has failed because a different number of Logical Assignments was provided.
*/
#define MFG_cannot_propagate_because_of_deffrent_num_of_LAs                                                           (EMH_MFG_error_base + 62)

/**
    The object &quot;%1$&quot; cannot be propagated to the object &quot;%2$&quot;, because there are multiple matches in the source.
*/
#define MFG_cannot_propagate_because_of_multiple_match                                                                (EMH_MFG_error_base + 63)

/**
    The received line &quot;%1$&quot; is not a BOM Line.
*/
#define MFG_input_is_not_bomline                                                                                      (EMH_MFG_error_base + 64)

/**
    The target context &quot;%1$&quot; and source context &quot;%2$&quot; are already associated by the relation &quot;%3$&quot;.
*/
#define MFG_contexts_already_associated                                                                               (EMH_MFG_error_base + 65)

/**
    The target context &quot;%1$&quot; and source context &quot;%2$&quot; are associated through reverse direction by the relation &quot;%3$&quot;.
*/
#define MFG_contexts_are_associated_in_other_direction                                                                (EMH_MFG_error_base + 66)

/**
    No default relation exists between the target context of type &quot;%1$&quot; and the source context of type &quot;%2$&quot;.
*/
#define MFG_default_contexts_relation_not_found                                                                       (EMH_MFG_error_base + 67)

/**
    The Plant BOP and the Product BOP are not associated.
*/
#define MFG_plant_bop_product_bop_not_associated                                                                      (EMH_MFG_error_base + 68)

/**
    "%1$" is assigned to "%2$" while its successor "%3$" is assigned to "%4$" which is a predecessor of "%2$".
*/
#define MFG_precedence_constraint_violation                                                                           (EMH_MFG_error_base + 69)

/**
    One or more loops have been detected in the flow graph of the Plant BOP. The following nodes are part of the loops: %1$.
*/
#define MFG_loop_in_flow_graph                                                                                        (EMH_MFG_error_base + 70)

/**
    The class "%1$" cannot be allocated to the object of type "%2$". Please check that the value of the preference "MEAllocationLevel" is correctly set.
*/
#define MFG_allocation_level_not_allowed                                                                              (EMH_MFG_error_base + 71)

/**
    The source context is empty.
*/
#define MFG_source_context_is_empty                                                                                   (EMH_MFG_error_base + 72)

/**
    The target context is empty.
*/
#define MFG_target_context_is_empty                                                                                   (EMH_MFG_error_base + 73)

/**
    Only Plant BOP and Product BOP can be connected.
*/
#define MFG_only_plant_bop_and_product_bop_can_be_connected                                                           (EMH_MFG_error_base + 74)

/**
    Objects of type "%1$" cannot disconnect from objects of type "%2$".
*/
#define MFG_source_cannot_disconnect_from_target                                                                      (EMH_MFG_error_base + 75)

/**
    The "Copy" and "Paste" operations are not allowed within a Generic BOP (Bill Of Processes), Product BOP or Plant BOP structure context. Only the "Paste Duplicate" command is allowed.
*/
#define MFG_connect_not_allowed_in_context                                                                            (EMH_MFG_error_base + 76)

/**
    Work Areas can only be connected to Process Areas within the plant BOP.
*/
#define MFG_workarea_cannot_connect_non_process_area                                                                  (EMH_MFG_error_base + 77)

/**
    Work Areas cannot be connected as an Assign feature.
*/
#define MFG_work_area_cannot_be_connected_as_assign_feature                                                           (EMH_MFG_error_base + 78)

/**
    A Plant BOP can only be a top line.
*/
#define MFG_plant_BOP_is_only_top_line                                                                                (EMH_MFG_error_base + 79)

/**
    A Process Line cannot be connected to a Process Station.
*/
#define MFG_process_line_cannot_connect_process_station                                                               (EMH_MFG_error_base + 80)

/**
    The object "%1$" cannot connect to the Process Partition.
*/
#define MFG_class_cannot_connect_to_process_partition                                                                 (EMH_MFG_error_base + 81)

/**
    The Relation type &quot;%1$&quot; is invalid.
*/
#define MFG_invalid_relation_type                                                                                     (EMH_MFG_error_base + 82)

/**
    The Manufacturing features cannot be copied from the BOM "%1$" to the BOM "%2$", because they are not linked.
*/
#define MFG_cannot_copy_mfgs                                                                                          (EMH_MFG_error_base + 83)

/**
    Propagation in this direction is not supported.
*/
#define MFG_propagation_direction_not_supported                                                                       (EMH_MFG_error_base + 84)

/**
    Propagation between unconnected structures is not supported.
*/
#define MFG_propagation_between_unconnected_not_supported                                                             (EMH_MFG_error_base + 85)

/**
    Propagation between the structure types &quot;%1$&quot; and &quot;%2$&quot; is not supported. 
*/
#define MFG_invalid_propagation_between_specific_structure                                                            (EMH_MFG_error_base + 86)

/**
    The object "%1$" cannot be connected directly under the Plant BOP root line.
*/
#define MFG_cannot_connect_directly_under_Plnat_BOP_root_line                                                         (EMH_MFG_error_base + 87)

/**
    The propagation of the flows has failed because the source and the target contain a different number of objects.
*/
#define MFG_different_number_of_flow_objects_propagation                                                              (EMH_MFG_error_base + 88)

/**
    The propagation of the hierarchy has failed because the source and the target contain a different number of objects.
*/
#define MFG_different_number_of_hierarchy_objects_propagation                                                         (EMH_MFG_error_base + 89)

/**
    The predecessor &quot;%1$&quot; of the object &quot;%2$&quot; will not be propagated, because it does not exist in the target.
*/
#define MFG_predecessor_does_not_exist_in_the_target                                                                  (EMH_MFG_error_base + 90)

/**
    A flow cannot be created between a tree node and a root node.
*/
#define MFG_cannot_create_flow_with_root                                                                              (EMH_MFG_error_base + 91)

/**
    A flow cannot be created between two objects that are not siblings.
*/
#define MFG_cannot_create_flow_between_not_siblings                                                                   (EMH_MFG_error_base + 92)

/**
    The action would have created a circular structure, which is not permitted.
*/
#define MFG_illegal_attempt_to_create_circular_structure                                                              (EMH_MFG_error_base + 93)

/**
    The source object "%1$" cannot be connected to the target object "%2$". 
*/
#define MFG_cannot_connect_object_to_target_detailed                                                                  (EMH_MFG_error_base + 94)

/**
    The workflow process cannot be started.
*/
#define MFG_cannot_start_workflow                                                                                     (EMH_MFG_error_base + 95)

/**
    The input parameters for the rule handler validations are incorrect.
*/
#define MFG_wrong_action_handler_params                                                                               (EMH_MFG_error_base + 96)

/**
    A Collaboration Context object must be added to the workflow attachments.
*/
#define MFG_cc_missing_from_attachments                                                                               (EMH_MFG_error_base + 97)

/**
    An execution plan must contain a process structure.
*/
#define MFG_process_missing_from_cc                                                                                   (EMH_MFG_error_base + 98)

/**
    A fatal error was thrown after invoking the validation check. Please check the validation check interface in the registered library.
*/
#define MFG_validation_check_fatal_error                                                                              (EMH_MFG_error_base + 99)

/**
    The system cannot find the registered validation check.
*/
#define MFG_no_registered_validation_check_for_this_name                                                              (EMH_MFG_error_base + 100)

/**
    Steps cannot be shared between several operations.
*/
#define MFG_cannot_share_step                                                                                         (EMH_MFG_error_base + 101)

/**
    Data mismatch detected. The following structure roots were loaded when the configuration was captured
    and are not currently loaded:%1$To ensure the results are correct, please load all the structure roots and apply the configuration again.
*/
#define MFG_apply_config_data_mismatch                                                                                (EMH_MFG_error_base + 102)

/**
    
*/
#define MFG_description_and_search_criteria_empty                                                                     (EMH_MFG_error_base + 103)
/**
    The provided object type is invalid. Only an object of type "Process Area" , "Partition" , "Process" , "Operation" or one of their derived types is allowed.
*/
#define MFG_disconnect_from_origin_invalid_object_type                                                                (EMH_MFG_error_base + 104)
/**
    The provided reference object type is invalid. An object of type "Product BOP" is expected, or the "Product BOP" is not associated with the given "Plant BOP".
*/
#define MFG_automatic_allocate_invalid_object_refernce                                                                (EMH_MFG_error_base + 105)
/**
    The provided source object type is invalid. Only an object of type "Product BOP" is expected.
*/
#define MFG_automatic_allocate_invalid_object_source                                                                  (EMH_MFG_error_base + 106)
/**
    The provided target object type is invalid. Only an object of type "Plant BOP" is expected.
*/
#define MFG_automatic_allocate_invalid_object_target                                                                  (EMH_MFG_error_base + 107)
/**
    An error has occurred during automatic allocation. Please check syslog for more information.
*/
#define MFG_automatic_allocate_allocation_error                                                                       (EMH_MFG_error_base + 108)
/**
    An error has occurred while trying to create an intermediate file. Please contact your system administrator for possible volume access issues.
*/
#define MFG_automatic_allocate_file_open_error                                                                        (EMH_MFG_error_base + 109)

/**
    The Product Bill Of Processes (BOP) and the Generic BOP are not associated. 
*/
#define MFG_product_bop_generic_bop_not_associated                                                                    (EMH_MFG_error_base + 110)

/**
    Connections are allowed only between a Plant BOP (Bill Of Processes) and a Product BOP, or between a Product BOP and a Generic BOP. 
*/
#define MFG_only_plant_bop_product_bop_or_product_bop_generic_bop_can_be_connected                                    (EMH_MFG_error_base + 111)

/**
    Error indicating that the tools could not be found from the Work Area.
*/

#define MFG_FailureInFindingToolsFromWorkArea                                                                         (EMH_MFG_error_base + 112)

/**
    Error indicating that the tools could not be found from the Classification root.
*/
#define MFG_FailureInFindingToolsFromClassification                                                                   (EMH_MFG_error_base + 113)

/**
    Tool requirements can be resolved manually only if they do not contain search criteria.
*/
#define MFG_tr_with_searchcriteria_manual_resolve_disallowed                                                          (EMH_MFG_error_base + 114)

/**
    Invalid parent line was received.
*/
#define MFG_invalid_parent                                                                                            (EMH_MFG_error_base + 115)

/**
    The tool requirement resolution action is not supported in a Generic BOP (Bill Of Processes) or a Product BOP. Tool requirements can be resolved only in a Plant BOP.
*/
#define MFG_invalid_context_for_toolrequirement_resolve                                                               (EMH_MFG_error_base + 116)

/**
    The tool requirement does not have search criteria. The candidate tools cannot be obtained.
*/
#define MFG_tr_search_criteria_unavailable                                                                            (EMH_MFG_error_base + 117)

/**
    This operation is not allowed in the context of Plant BOP (Bill Of Processes).
*/
#define MFG_operation_disallowed_in_plant                                                                             (EMH_MFG_error_base + 118)

/**
    The relation direction "%1$" is invalid. The value must be 0, 1 or 2.
 */
#define MFG_invalid_relation_direction                                                                                (EMH_MFG_error_base + 119)

/**
    An invalid object is assigned to the %1$ property. This property only accepts objects of type %2$.
*/
#define MFG_invalid_type_in_property_assignment                                                                       (EMH_MFG_error_base + 120)

/**    
    The disconnect operation has failed because the current user does not have write access to the object "%1$".
*/
#define MFG_disconnect_from_origin_failed                                                                             (EMH_MFG_error_base + 121)

/**
    The addition of connected parts to "%1$" has failed for the following reason: %2$
 */
#define MFG_connected_parts_not_added                                                                                 (EMH_MFG_error_base + 122)

/**
    The connected part "%1$" could not be propagated, because its equivalent was not found in the target structure.
 */
#define MFG_connected_part_not_propagated                                                                             (EMH_MFG_error_base + 123)

/**
    The connected part "%1$" could not be propagated, because it appears a different number of times in the source and target structures.
 */
#define MFG_diff_number_of_connected_parts_propagation                                                                (EMH_MFG_error_base + 124)

/**
    The Tool requirement "%1$" cannot be resolved with the object "%2$".
*/
#define MFG_incorrect_object_resolved_to_tr                                                                           (EMH_MFG_error_base + 125)

/**
    The target object "%1$" cannot be modified, because the user does not have write access.
*/
#define MFG_user_can_not_modify_target                                                                                (EMH_MFG_error_base + 126)

/**
    The operation has failed, because the source structure "%1$" and the target structure "%2$" need to be associated using the command "Link/Associate".
*/
#define MFG_source_target_not_associated                                                                              (EMH_MFG_error_base + 127)

/**
    The Automatic Weld Assignment operation has failed, because no value is specified for the preference "%1$".
*/
#define MFG_automatic_weld_assignment_preference_error                                                                (EMH_MFG_error_base + 128)

/**
    The Automatic Weld Assignment operation has failed. Please check the Teamcenter server syslog file for more information.
*/
#define MFG_automatic_weld_assignment_failed                                                                          (EMH_MFG_error_base + 129)

/**
    The Clean Dynamic Assembly Tree operation has failed. Please check the Teamcenter server syslog file for more information.
*/
#define MFG_clean_dynamic_ipa_failure                                                                                 (EMH_MFG_error_base + 130)

/**
    The "%1$" operation has failed because of internal errors. Please check the Teamcenter server syslog file for more information.
*/
#define MFG_show_dynamic_ipa_failure                                                                                  (EMH_MFG_error_base + 131)

/**
    The "%1$" operation has failed, because multiple configuring structures are defined for the Process Structure "%2$". Please define a single configuring structure and try again.
*/
#define MFG_show_dynamic_ipa_multiple_structures                                                                      (EMH_MFG_error_base + 132)

/**
    The process resources action is not supported in a Generic BOP (Bill Of Processes) or a Product BOP. Process resources can be retrieved only in a Plant BOP.
*/
#define MFG_invalid_context_for_process_resource                                                                      (EMH_MFG_error_base + 131)

/**
    An invalid value is provided for the preference "%1$" used to retrieve process resource related information. Valid values are "Process", "Operation" and "ProcessAndOperation".
*/
#define MFG_invalid_object_preference_for_process_resource                                                            (EMH_MFG_error_base + 132)

/**
    The Create/Update Dynamic Assembly Tree operation has failed, because the selected process(es) do not have predecessors.
*/ 
#define MFG_show_dynamic_ipa_no_predecessors                                                                          (EMH_MFG_error_base + 133)

/**
    The "%1$" operation has failed, because no Dynamic Assembly Tree node is related to the current configuring structure "%2$".
*/
#define MFG_show_dynamic_ipa_nothing_to_clean                                                                         (EMH_MFG_error_base + 134)

/**
    The "%1$" operation has failed, because there are no consumed lines from the current configuring structure "%2$". Please select the correct configuring structure.
*/
#define MFG_show_dynamic_ipa_no_consumed_lines                                                                        (EMH_MFG_error_base + 135)

/**
    The "%1$" operation is not supported on the structure "%2$", because it is either a Generic BOP or a Product BOP. The operation is supported only for normal BOP and Plant BOP.
*/
#define MFG_show_dynamic_ipa_not_supported                                                                            (EMH_MFG_error_base + 136)

/**
    The "%1$" operation has failed, because the preference "MEDynamicIPAOccurrenceTypes" is not set correctly. Please refer to the Technical Documentation for more information.
*/
#define MFG_show_dynamic_occ_type_pref_missing                                                                        (EMH_MFG_error_base + 137)

/**
    Process resources cannot be allocated to another process resource.
*/
#define MFG_cannot_allocate_process_resources_to_another_process_resource                                             (EMH_MFG_error_base + 138)

/**
    The Automatic Weld Assignment operation has failed, because invalid value is specified for the preference "%1$".
*/
#define MFG_automatic_weld_assignment_preference_value_error                                                          (EMH_MFG_error_base + 139)

/**
    The object "%1$" is of type "%2", which is not supported.
*/
#define MFG_repopulate_dynamic_ipa_not_supported                                                                      (EMH_MFG_error_base + 140)

/**
    The object "%1$" does not have any Dynamic In Process Assembly nodes. First, create Dynamic In Process Assembly nodes, and then try again.
*/
#define MFG_repopulate_dynamic_ipa_object_without_dipas                                                               (EMH_MFG_error_base + 141)

/**
    The update cannot be done, because there are no Dynamic In Process Assembly nodes in the structure for the configured product structure. First, create Dynamic In Process Assembly nodes, and then try again.
*/
#define MFG_no_dipa_nodes_to_update                                                                                   (EMH_MFG_error_base + 142)

/**
    The object "%1$" cannot be unassociated from the process resource "%2$", because it is associated to the process resource as a part of the object "%3$".
    This action is ignored. 
*/
#define MFG_cannot_unassociate_object                                                                                 (EMH_MFG_error_base + 143)

/**
    The object "%1$" cannot be associated to the process resource "%2$", because its parent "%3$" is associated to another process resource "%4$".
    Please move "%1$" out of the hierarchy of "%3$", and then repeat the step.
*/
#define MFG_associated_to_process_resource_as_part_of_parent                                                          (EMH_MFG_error_base + 144)

/**
    The job could not be executed as scheduled, most likely because a problem with the Dispatcher infrastructure or "Asynchronous Service Translator" installation has occurred. 
    Details are not available. Logical Assignment resolve job cannot be scheduled until the installed processes are running and configured properly.
*/
#define MFG_sync_not_working                                                                                          (EMH_MFG_error_base + 145)

/**
    The "%1$" operation has failed, because the preference "MEDynamicIPARemoveOccTypes" is not set correctly. Please refer to the Technical Documentation for more information.
*/
#define MFG_remove_dynamic_occ_type_pref_missing                                                                      (EMH_MFG_error_base + 146)

/**
    The assembly "%1$" cannot be fully removed from Dynamic In Process Assembly nodes because it was not present earlier in the Dynamic In Process Assembly. Please make necessary corrections for the assembly being removed.
*/
#define MFG_dynamic_assembly_not_fully_removed                                                                        (EMH_MFG_error_base + 147)

/**
    The creation of the Dataset has failed, because of internal errors.
*/
#define MFG_dataset_creation_failed                                                                                   (EMH_MFG_error_base + 148)

/**
   No attachments are found for the node "%1$".
*/
#define MFG_no_attachment_lines_found                                                                                 (EMH_MFG_error_base + 149)

/**
    The operation "configureMultipleStructures" has failed because of internal errors. Please check the Teamcenter server syslog file for more information and report this error to your system administrator.
*/
#define MFG_configure_multiple_structures_failed                                                                      (EMH_MFG_error_base + 150)

/**
    The "%1$" operation has failed, because the selected processes do not have any predecessors. The predecessors may have been configured out or changed.
*/
#define MFG_dynamic_ipa_no_predecessors                                                                               (EMH_MFG_error_base + 151)

/**
    The "%1$" operation has failed, because no process structures are currently loaded. Please load the process structures for which the operation is to be performed in Shared Study.
*/
#define MFG_dynamic_ipa_no_process_structure                                                                          (EMH_MFG_error_base + 152)

/**
    The "%1$" operation has failed, because multiple occurrences of the selected processes are found.
*/
#define MFG_dynamic_ipa_multiple_process_occurrences                                                                  (EMH_MFG_error_base + 153)

/**
    The target object has an invalid type.
*/
#define MFG_invalid_target_type                                                                                       (EMH_MFG_error_base + 154)

/**
    The "%1$" operation has failed, because multiple configuring structures are defined for the Process Structure "%2$". Please define a single configuring structure and try again.
*/
#define MFG_dynamic_ipa_multiple_configuring_structures                                                               (EMH_MFG_error_base + 155)

/**
    The "%1$" operation has failed, because no configuring structure is defined for the Process Structure "%2$". Please define a single configuring structure and try again.
*/
#define MFG_dynamic_ipa_no_configuring_structure                                                                      (EMH_MFG_error_base + 156)

/**
    The Classification search criteria contain an attribute that does not exist in the database. It is likely that the "Tool Requirement" class was imported from the remote site and that the attributes of the "Classification" class failed to import. Ensure that the database contains all the needed attributes as specified in the search criteria of "Tool Requirement" object.
*/
#define MFG_classification_search_attribute_not_found                                                                 (EMH_MFG_error_base + 157)

/**
    The "%1$" operation has failed, because the preference "MEDynamicIPATraversalClosureRule" is not set correctly. Please refer to the Technical Documentation for more information.
*/
#define MFG_dynamic_ipa_closure_rule_pref_missing                                                                     (EMH_MFG_error_base + 158)
 
/**
    "Copy and Paste" of the object "%1$" has failed. These operations are not allowed within a Generic BOP (Bill Of Processes), Product BOP or Plant BOP structure context unless the source object is Operation type and it has no parent object. Use the "paste duplicate" command instead.
*/
#define MFG_cannot_be_pasted_as_it_has_parent                                                                         (EMH_MFG_error_base + 159)

/**
    The creation of a Dynamic In Process Assembly is not allowed, because the structure is cyclic.
*/
#define MFG_dynamic_ipa_illegal_creation_on_cyclic_structure                                                          (EMH_MFG_error_base + 160)

/**
    The "%1$" operation is not allowed, because the station has a Persistent In Process Assembly.
*/
#define MFG_dynamic_ipa_illegal_creation_as_station_has_persistent_ipa                                                (EMH_MFG_error_base + 161)

/**
The Create Collaboration Planning Context (CPC) job could not be executed in the background, most likely because of a problem with the "Asynchronous Service Translator" installation or with the Dispatcher infrastructure.
*/
#define MFG_cpc_async_connection_not_working                                                                          (EMH_MFG_error_base + 162)

/**
    The "%1$" operation has failed, because the input is invalid.
*/
#define MFG_dynamic_ipa_invalid_input                                                                                 (EMH_MFG_error_base + 163)

/**
    The "%1$" operation has failed, because the preference "%2$" is not set correctly. Please refer to the Technical Documentation for more information.
*/
#define MFG_dynamic_ipa_preference_missing                                                                            (EMH_MFG_error_base + 164)

/**
    The maturity report rule "%1$" is not registered. Please check the Teamcenter server syslog file for more information and report this error to your system administrator.
*/
#define MFG_maturity_report_rule_not_registered                                                                       (EMH_MFG_error_base + 165)

/**
    The maturity report rule "%1$" could not be evaluated. Please check the Teamcenter server syslog file for more information and report this error to your system administrator.
*/
#define MFG_maturity_report_rule_not_evaluated                                                                        (EMH_MFG_error_base + 166)

/**
    The "%1$" operation has failed, because no matching nodes fitting the types defined in the preference "MEDynamicIPARecursiveCreateProcessTypes" were found. Please make the necessary changes in the BOP or in the preference as per your use case and try again.
*/
#define MFG_dynamic_ipa_types_not_found                                                                               (EMH_MFG_error_base + 167)

/**
    The "Persist Dynamic Assembly Tree" operation has failed because Dynamic In Process Assemblies cannot be persisted in an alternative BOP (Bill Of Processes) context.
*/
#define MFG_dynamic_ipa_cannot_persist                                                                                (EMH_MFG_error_base + 168)

/**
Import/Export of Briefcase job could not be executed in the background, most likely because of a problem with the "Asynchronous Service Translator" installation or with the Dispatcher infrastructure. Please contact your system administrator.
*/
#define MFG_importexport_async_connection_failed                                                                      (EMH_MFG_error_base + 169)

/**
    The "Copy and Paste" operation is not allowed between "%1$" structures. Use "Paste Duplicate" command instead.
*/
#define MFG_copy_and_paste_not_allowed_between_structures                                                             (EMH_MFG_error_base + 170)

/**
    The operation "Automatic MFG Assignment" failed, because there are no consumptions or connected manufacturing features from the Product Structure.
*/
#define MFG_feature_invalid_assignment                                                                                (EMH_MFG_error_base + 171)

/**
    Operations cannot be pasted under a Process Partition. Create a Process under a Process Partition and then paste the Operation under the Process.
*/
#define MFG_operation_cannot_connect_to_process_partition                                                             (EMH_MFG_error_base + 172)

/**
    The structure "%1$" cannot be loaded because it uses classic variant data, which is incompatible with Product Configurator variant data (used in the current session). Either connect a Configurator Context to "%2$" and load the structure, or unload all the structures that use Product Configurator variant data.
*/
#define MFG_classic_variant_structure_failed_to_load                                                                  (EMH_MFG_error_base + 173)

/**
    The structure "%1$" cannot be loaded because it uses Product Configurator variant data, which is incompatible with classic variant data (used in the current session). Either connect a Configurator Context to all loaded structures, or unload all the structures that use classic variant data.
*/
#define MFG_product_configurator_variant_structure_failed_to_load                                                     (EMH_MFG_error_base + 174)

/**
    The Collaboration Context "%1$" cannot be loaded because its associated data uses mixed mode of variants, which is not supported. "%2$" contains the following structure: Classical variant data: %3$ Product Configurator variant data: %4$.
*/
#define MFG_collaboration_context_mixed_variant_structure_failed_to_load                                              (EMH_MFG_error_base + 175)

/**
    The Collaboration Context "%1$" cannot be loaded because it uses classic variant data, which is incompatible with Product Configurator variant data (used in the current session). Either connect a Configurator Context to all structures in "%2$" and load the Collaboration Context, or unload all the structures using Product Configurator variant data.
*/
#define MFG_collaboration_context_classic_variant_structure_failed_to_load                                            (EMH_MFG_error_base + 176)

/**
    The Collaboration Context "%1$" cannot be loaded because it uses Product Configurator variant data, which is incompatible with Classic variant data (used in the current session). Either connect a Configurator Context to all loaded structures, or unload all the structures using classic variant data.
*/
#define MFG_collaboration_context_product_configurator_variant_structure_failed_to_load                               (EMH_MFG_error_base + 177)

/**
    The selected structures cannot be loaded because they use a mixed mode of variants, which is not supported.
*/
#define MFG_mixed_variant_structure_failed_to_load                                                                    (EMH_MFG_error_base + 178)

/**
    The Copy and Paste operation of object "%1$" has failed because this operation is not allowed within the same structure for manufacturing features.
*/
#define MFG_cannot_copy_paste_mfg_features_within_same_structure                                                      (EMH_MFG_error_base + 179)

/**
    The resource "%1$" cannot be removed from the compound resource "%2$". Please remove the parent resource and try again.
*/
#define MFG_cannot_remove_resource_from_compound_resource                                                             (EMH_MFG_error_base + 180)

/**

   @}
*/

#include <mfg/libmfg_undef.h>
#endif
