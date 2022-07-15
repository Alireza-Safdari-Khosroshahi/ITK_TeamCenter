/*
* Copyright 2020 Siemens Digital Industries Software
* ==================================================
* Copyright $2010.
* Siemens Product Lifecycle Management Software Inc.
* All Rights Reserved.
* ==================================================
* Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    CondValidation Error Codes Declaration

*/
/*

*/

#ifndef PTN0PARTITION_ERRORS_H
#define PTN0PARTITION_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

#define PTN0PARTITION_ERROR_BASE                                   EMH_PTN0PARTITION_error_base
/**
 * An internal error has occurred in the partition module. Please report this error to your system administrator.
 */
#define PTN0PARTITION_internal_error                               ( EMH_PTN0PARTITION_error_base + 1 )
/**
 * One or more selected objects cannot be added or replaced as members of the target Partition because they are of invalid types. Only Model Elements or their subtypes are allowed.
 */
#define PTN0PARTITION_invalid_member_input                         ( EMH_PTN0PARTITION_error_base + 2 )
/**
 * One or more selected objects cannot be added or replaced as children or parents of the target Partition because they have different Scheme type or Model Context. Only Partitions of same Scheme and Model Context as that of the target Partition are allowed.
 */
#define PTN0PARTITION_invalid_scheme_or_model_partition            ( EMH_PTN0PARTITION_error_base + 3 )
/**
 * A Partition Item of type &quot;%1$&quot; already exists with the given Item ID &quot;%2$&quot;.
 */
#define PTN0PARTITION_duplicate_partition_item                     ( EMH_PTN0PARTITION_error_base + 4 )
/**
 * One or more selected objects cannot be added or replaced on the target Partition because they are of invalid types. Only Partitions are allowed.
 */
#define PTN0PARTITION_wrong_input_supplied                         ( EMH_PTN0PARTITION_error_base + 5 )
/**
 * A Partition of type &quot;%1$&quot; cannot be created within a Scheme of type &quot;%2$&quot;.
 */
#define PTN0PARTITION_invalid_schemetype                           ( EMH_PTN0PARTITION_error_base + 6 )
/**
 * The Partition Item Revision &quot;%1$&quot; cannot be set to the adhoc Partition with ID &quot;%2$&quot; because a duplicate Partition \n with same partition ID, scheme type and source object already exists.
 */
#define PTN0PARTITION_duplicate_source_object                      ( EMH_PTN0PARTITION_error_base + 7 )
/**
 * The selected Scheme cannot be removed because it is being referenced by one or more Partitions in the current model.
 */
#define PTN0PARTITION_scheme_is_referenced                         ( EMH_PTN0PARTITION_error_base + 8 )
/**
 * The current user does not have the requested &quot;%1$&quot; access privilege on the object &quot;%2$&quot; to be able to update the Partition.
 */
#define PTN0PARTITION_no_access_privilege                          ( EMH_PTN0PARTITION_error_base + 9 )
/**
 * The Partition object cannot be deleted because it contains at least one child Partition. Please delete all child Partitions first.
 */
#define PTN0PARTITION_can_not_delete                               ( EMH_PTN0PARTITION_error_base + 10 )
/**
 * A Partition of Scheme type &quot;%1$&quot; already exists with the given Partition ID &quot;%2$&quot; in the current model.
 */
#define PTN0PARTITION_duplicate_adhoc_partition                    ( EMH_PTN0PARTITION_error_base + 11 )
/**
 * The Partition Search Recipe should have either a valid Partition Search Criteria or a valid Partition Item Revision Criteria. This Partition Recipe has no valid search criteria.
 */
#define PTN0PARTITION_search_has_no_valid_criteria                 ( EMH_PTN0PARTITION_error_base + 12 )
/**
 * The add operation could not be performed because following Partition(s) are already children of target Partition: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_duplicate_children                           ( EMH_PTN0PARTITION_error_base + 13 )
/**
 * One or more members to add are already members of the target Partition.
 */
#define PTN0PARTITION_duplicate_members                            ( EMH_PTN0PARTITION_error_base + 14 )
/**
 * The add operation could not be performed because following parent Partition(s) are already parent of the target Partition: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_duplicate_parents                            ( EMH_PTN0PARTITION_error_base + 15 )
/**
 * The Partition Item Revision of the Formal Partition cannot be changed once a Formal Partition is created. You are trying to change the Partition Item Revision &quot;%1$&quot; of the Formal Partition with Partition ID &quot;%2$&quot;.
 */
#define PTN0PARTITION_cannot_change_source_object                  ( EMH_PTN0PARTITION_error_base + 16 )
/**
 * The selected Formal Partition cannot be saved because a Partition of Scheme type &quot;%1$&quot; and source object &quot;%2$&quot; already exists with the given Partition ID &quot;%3$&quot; in the current model.
 */
#define PTN0PARTITION_duplicate_saveas_partition                   ( EMH_PTN0PARTITION_error_base + 17 )
/**
 * The selected Adhoc Partition cannot be saved because a Partition of Scheme type &quot;%1$&quot; already exists with the given Partition ID &quot;%2$&quot; in the current model.
 */
#define PTN0PARTITION_duplicate_saveas_adhoc_partition             ( EMH_PTN0PARTITION_error_base + 18 )
/**
 * The selected Member cannot be deleted because it is participating in one or more Partitions which control the memberships. Please delete all such Partitions first.
 */
#define PTN0PARTITION_cannot_delete_member                         ( EMH_PTN0PARTITION_error_base + 19 )

/**
 * The selected Partition cannot be deleted because it has one or more Members which control their membership. Please delete all such members first.
 */
#define PTN0PARTITION_delete_partition_not_owning_memberships      ( EMH_PTN0PARTITION_error_base + 20 )

/**
 * The dynamic content cannot be retrieved from the selected Partition because the Partition does not contain any Search Recipe.
 */
#define PTN0PARTITION_has_no_recipe_to_get_members                 ( EMH_PTN0PARTITION_error_base + 21 )

/**
 * The dynamic content cannot be removed from the selected Partition because the Partition does not contain any Search Recipe.
 */
#define PTN0PARTITION_has_no_recipe_to_delete_dynamic_members      ( EMH_PTN0PARTITION_error_base + 22 )

/**
 * The Unassigned Partition Recipe type is not supported for the &quot;Save&quot; operation.
 */
#define PTN0PARTITION_unsupported_recipe_type_in_save              ( EMH_PTN0PARTITION_error_base + 23 )

/**
 * The check-out operation is not supported for Realized Partition objects.
 */
#define PTN0PARTITION_realized_object_not_checkoutable             ( EMH_PTN0PARTITION_error_base + 24 )

/**
 * The following child Partitions could not be added: %1$. The total number of failed child Partition(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_add_failed_for_one_or_more_children          ( EMH_PTN0PARTITION_error_base + 25 )

/**
 * The following child Partitions could not be removed: %1$. The total number of failed child Partition(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_remove_failed_for_one_or_more_children       ( EMH_PTN0PARTITION_error_base + 26 )

/**
 * The following parent Partitions could not be removed: %1$. The total number of failed parent Partition(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_remove_failed_for_one_or_more_parents        ( EMH_PTN0PARTITION_error_base + 27 )

/**
 * The following parent Partitions could not be added: %1$. The total number of failed parent Partition(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_add_failed_for_one_or_more_parents           ( EMH_PTN0PARTITION_error_base + 28 )

/**
 * The following Partition Members could not be removed: %1$. The total number of failed Members(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_remove_failed_for_one_or_more_members        ( EMH_PTN0PARTITION_error_base + 29 )

/**
 * The following Partition Members could not be added: %1$. The total number of failed Members(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_add_failed_for_one_or_more_members           ( EMH_PTN0PARTITION_error_base + 30 )

/**
 * The following Partition Members do not have access privilege: %1$. The total number of failed Members(s) is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_access_failure_for_one_or_more_members       ( EMH_PTN0PARTITION_error_base + 31 )

/**
 * The child Partition(s) %1$ could not be removed, because they have realization link associated. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_cannot_remove_children                       ( EMH_PTN0PARTITION_error_base + 32 )

/**
* The update operation could not be performed, because the object "%1$" could not be modified. Please check the Teamcenter server syslog file for more information.
*/
#define PTN0PARTITION_object_not_modifiable                        ( EMH_PTN0PARTITION_error_base + 33 )

/**
* The operation could not be performed, because an invalid input object is supplied. Please check the Teamcenter server syslog file for more information.
*/
#define PTN0PARTITION_invalid_input                                ( EMH_PTN0PARTITION_error_base + 34 )

/**
 * The operation could not be performed, because the current user does not have the needed &quot;%1$&quot; access privilege on the object &quot;%2$&quot;.
 */
#define PTN0PARTITION_access_denied                                ( EMH_PTN0PARTITION_error_base + 35 )

/**
 * The specified action code &quot;%1$&quot; is not supported with the content persistence mode &quot;%2$&quot;.
 */
#define PTN0PARTITION_unsupported_action_code                      ( EMH_PTN0PARTITION_error_base + 36 )

/**
* The Business Object &quot;%1$&quot; cannot be created in the replicated model &quot;%2$&quot;.
*/
#define PTN0PARTITION_cannot_create_object_in_replica              ( EMH_PTN0PARTITION_error_base + 37 )

/**
 * The current user does not have sufficient access privileges to re-parent Partition object. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_failed_no_access_privilege          ( EMH_PTN0PARTITION_error_base + 38 )

/**
 * The re-parenting operation could not be performed because of the following Partition(s) having realization link associated: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_failed_realized_partition           ( EMH_PTN0PARTITION_error_base + 39 )

/**
 * The re-parenting operation could not be performed because following Partition(s) are already children of target Partition: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_failed_duplicate_children           ( EMH_PTN0PARTITION_error_base + 40 )

/**
 * The re-parenting operation could not be performed because following child Partition(s) scheme or model doesn't match with target Partition scheme or model: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_invalid_scheme_or_model_partition   ( EMH_PTN0PARTITION_error_base + 41 )

/**
 * The child Partition(s) %1$ could not be added, because they have realization link associated. Please check the Teamcenter server syslog file for more information.
 */
 #define PTN0PARTITION_cannot_add_children                         ( EMH_PTN0PARTITION_error_base + 42 )

/**
 * The following parent Partition(s) could not be removed, because realization links are associated to them: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_remove_failed_for_realized_parent            ( EMH_PTN0PARTITION_error_base + 43 )

/**
 * The following parent Partition(s) could not be added, because realization links are associated to them: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_add_failed_for_realized_parent               ( EMH_PTN0PARTITION_error_base + 44 )

/**
 * The re-parenting operation could not be performed because of the following inactive source Partition(s): %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_inactive_partition                  ( EMH_PTN0PARTITION_error_base + 45 )

/**
 * The re-parenting operation could not be performed because the target Partition %1$ is inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_to_inactive_partition               ( EMH_PTN0PARTITION_error_base + 46 )

/**
 * The add operation could not be performed because of the following inactive source Partition(s): %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_add_inactive_partition                       ( EMH_PTN0PARTITION_error_base + 47 )

/**
 * The add operation could not be performed because the target Partition %1$ is inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_add_to_inactive_partition                    ( EMH_PTN0PARTITION_error_base + 48 )

/**
* The selected Partition "%1$" could not be activated, because its following parent Partitions are inactive: %2$.
*/
#define PTN0PARTITION_cannot_activate_inactive_child               ( EMH_PTN0PARTITION_error_base + 49 )

/**
* The selected Workspace Objects "%1$" could not be activated/deactivated using the workflow process, because they are not Partition objects.
*/
#define PTN0PARTITION_invalid_target_objects                       ( EMH_PTN0PARTITION_error_base + 50 )

/**
* Invalid scheme type "%1$" is supplied as primary Partition Scheme for model type "%2$"; Please check the Teamcenter server syslog for more information.
*/
#define PTN0PARTITION_invalid_primary_scheme_type                  ( EMH_PTN0PARTITION_error_base + 51 )

/**
 * The selected child Partition(s) %1$ could not be removed, because they are inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_remove_inactive_partition                    ( EMH_PTN0PARTITION_error_base + 52 )

/**
 * The "Add Parent" operation could not be performed, because the selected child Partition "%1$" is inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_update_parent_add_inactive_child             ( EMH_PTN0PARTITION_error_base + 53 )

/**
 * The "Add Parent" operation could not be performed, because of the following inactive parent Partition(s): %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_update_parent_add_to_inactive_parent         ( EMH_PTN0PARTITION_error_base + 54 )

/**
 * The "Remove Parent" operation could not be performed, because the selected child Partition "%1$" is inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_update_parent_remove_inactive_child          ( EMH_PTN0PARTITION_error_base + 55 )

/**
 * The "Create/Edit Recipe" operation could not be performed, because the selected Partition "%1$" is inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_cannot_edit_recipe_inactive_partition        ( EMH_PTN0PARTITION_error_base + 56 )

/**
 * The "Load Dataset" operation has failed. Please check the error details for more information.
 */
#define PTN0PARTITION_load_dataset_failed                          ( EMH_PTN0PARTITION_error_base + 57 )

/**
 * The following Partitions cannot be deleted, because they contain realization links: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_delete_failed_realized_partition             ( EMH_PTN0PARTITION_error_base + 58 )

/**
 * The "Cut/Remove Member" operation could not be performed, because the parent Partition "%1$" is inactive. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_remove_member_from_inactive_partition        ( EMH_PTN0PARTITION_error_base + 59 )

/**
 * The Partition Mapping between "%1$" and "%2$" cannot be created. Please select Partitions from different schemes and the same Application Model.
 */
#define PTN0PARTITION_invalid_mapping_input                        ( EMH_PTN0PARTITION_error_base + 60 )

/**
 * Partition Mapping creation is not allowed between Schemes "%1$" and "%2$".
 */
#define PTN0PARTITION_unsupported_mapping_scheme                   ( EMH_PTN0PARTITION_error_base + 61 )

/**
 * The following owning Partitions could not be "Unmapped", because Realization Links are associated to them: %1$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_unmap_failed_realized_mapping                ( EMH_PTN0PARTITION_error_base + 62 )

/**
 * The operation could not be performed, because the parent Partition "%1$" is configured with change context and the membership type is owned by the Partition. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_unsupported_in_change_context                ( EMH_PTN0PARTITION_error_base + 63 )

/**
 * The operation "%1$" is not supported for Partitions with "Partition Owned Membership" in space.
 */
#define PTN0PARTITION_operation_not_supported_in_space             ( EMH_PTN0PARTITION_error_base + 64 )

/**
 * The Partition is not valid for the current configuration.
 */
#define PTN0PARTITION_partition_not_configured                     ( EMH_PTN0PARTITION_error_base + 65 )

/**
 * @deprecated #PTN0PARTITION_partition_has_no_content deprecated in Teamcenter 12.1. Use #PTN0PARTITION_object_to_expand_is_invalid_with_changed_configuration instead.
 */
#define PTN0PARTITION_partition_has_no_content                     ( EMH_PTN0PARTITION_error_base + 66 )
TC_DEPRECATED_PREPROCESSOR( "12.1", PTN0PARTITION_partition_has_no_content, "PTN0PARTITION_object_to_expand_is_invalid_with_changed_configuration" ) 

/**
 * "%1$" is invalid for expansion with given configuration or not in search recipe result.
 */
#define PTN0PARTITION_object_to_expand_is_invalid_with_changed_configuration  ( EMH_PTN0PARTITION_error_base + 66 )

/**
 * One or more selected Partition objects cannot be processed because they are either from different Models or different Partition Schemes. Only Partitions from the same Model and Scheme are allowed.
 */
#define PTN0PARTITION_invalid_input_partitions_supplied            ( EMH_PTN0PARTITION_error_base + 67 )

/**
 * The total number of inputs processed successfully is %1$ out of %2$. Please check the Teamcenter server syslog file for
 more information. Please report this error to your system administrator.
 */
#define PTN0PARTITION_where_partitioned_in_bulk_failed            ( EMH_PTN0PARTITION_error_base + 68 )

/**
 * The object is not a dynamic partition. There is no recipe to replay to update its memberships.
 */
#define PTN0PARTITION_invalid_partition_not_dynamic                ( EMH_PTN0PARTITION_error_base + 69 )

 /**
 * The input source object line for membership creation does not belong to the product "%1$".
 */
#define PTN0PARTITION_invalid_source_bomline_for_member_creation   ( EMH_PTN0PARTITION_error_base + 70 )

 /**
 * The "%1$" operation is not valid on "%2$".
 */
#define PTN0PARTITION_operation_not_valid   ( EMH_PTN0PARTITION_error_base + 71 )

 /**
 * BOM Lines cannot be added as a members of multiple Partitions in the scheme type %1$.
 */
#define PTN0PARTITION_cannot_add_same_bomline_in_multiple_partitions   ( EMH_PTN0PARTITION_error_base + 72 )

/**
 * The following Partitions and Members could not be reparented: %1$. The total number of failed Members and Partitions is %2$. Please check the Teamcenter server syslog file for more information.
 */
#define PTN0PARTITION_reparent_failed_for_members_or_children          ( EMH_PTN0PARTITION_error_base + 73 )

/**
 * Only BOM Lines directly under the top line can be added as members of a Partition where the membership is owned by the member of the Partition.
 */
#define PTN0PARTITION_cannot_create_member_owned_membership            ( EMH_PTN0PARTITION_error_base + 74 )

/**
* Product top line not provided.
*/
#define PTN0PARTITION_product_topline_not_found         ( EMH_PTN0PARTITION_error_base + 75 )

/**
* Scheme not provided.
*/
#define PTN0PARTITION_scheme_not_found         ( EMH_PTN0PARTITION_error_base + 76 )

/**
* "%1$" was not added to "%2$" due to a restriction in a Partition rule.
*/
#define PTN0PARTITION_add_failed_closure_rule_evaluated_to_skip        ( EMH_PTN0PARTITION_error_base + 77 )

/**
* Source BOM Line could not be found using the provided inputs.
*/
#define PTN0PARTITION_source_bom_line_not_found                        ( EMH_PTN0PARTITION_error_base + 78 )

/**
 * The "%1$" operation could not be performed because following Member(s) are already children of selected target: "%2$".
 */
#define PTN0PARTITION_duplicate_members_under_target                           ( EMH_PTN0PARTITION_error_base + 79 )

#endif
