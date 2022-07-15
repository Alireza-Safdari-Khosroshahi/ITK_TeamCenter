/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2016.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Branching abd Versioning Error Codes Declaration

*/

#ifndef BHV0BRANCHFOUNDATION_ERRORS_H
#define BHV0BRANCHFOUNDATION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup BHV0BRANCHFOUNDATION_ERRORS Errors for the Branching and Versioning Error Codes Declaration solution
    @ingroup BHV0BRANCHFOUNDATION
    @{
*/

/** The license "%1$" for the Branching and Versioning module is not available. Please contact your system administrator.*/
#define BHV0BRANCHFOUNDATION_validate_license_failed                           (EMH_BHV0BRANCHFOUNDATION_error_base + 1)

/** "%1$" is not allowed because it already exists under the root branch "%2$". */
#define BHV0BRANCHFOUNDATION_branch_already_exists_for_BO                      (EMH_BHV0BRANCHFOUNDATION_error_base + 2)

/** "%1$" was not published because it is checked-out. */
#define BHV0BRANCHFOUNDATION_cannot_pushish_obj                                (EMH_BHV0BRANCHFOUNDATION_error_base + 3)

/** "%1$" was not branched out because it is either checked-out or not released. */
#define BHV0BRANCHFOUNDATION_cannot_branch_out_obj                             (EMH_BHV0BRANCHFOUNDATION_error_base + 4)

/** "%1$" was not added to the branch "%2$" because it is an invalid type. */
#define BHV0BRANCHFOUNDATION_invalid_obj_type                                  (EMH_BHV0BRANCHFOUNDATION_error_base + 5)

/** "%1$" was not added to the branch "%2$" because it is in another branch. */
#define BHV0BRANCHFOUNDATION_obj_already_exists_in_another_branch              (EMH_BHV0BRANCHFOUNDATION_error_base + 6)

/** "%1$" was not added to the branch "%2$" because it is already in the branch. */
#define BHV0BRANCHFOUNDATION_obj_already_exists_in_same_branch                 (EMH_BHV0BRANCHFOUNDATION_error_base + 7)

/** "%1$" was not added to the branch "%2$" because it is checked-out. */
#define BHV0BRANCHFOUNDATION_obj_checked_out                                   (EMH_BHV0BRANCHFOUNDATION_error_base + 8)

/** "%1$" was not added to the branch "%2$" because of a system error */
#define BHV0BRANCHFOUNDATION_add_contents_failed                               (EMH_BHV0BRANCHFOUNDATION_error_base + 9)

/** "%1$" cannot be created because it already exists in the database */
#define BHV0BRANCHFOUNDATION_branch_already_exists_in_database                 (EMH_BHV0BRANCHFOUNDATION_error_base + 10)

/** The input Version object cannot be empty.*/
#define BHV0BRANCHFOUNDATION_invalid_version_object                            (EMH_BHV0BRANCHFOUNDATION_error_base + 11)

/** The input Branch object cannot be empty.*/
#define BHV0BRANCHFOUNDATION_invalid_branch_object                             (EMH_BHV0BRANCHFOUNDATION_error_base + 12)

/** "%1$" was not promoted. Only the latest Head version can be promoted.*/
#define BHV0BRANCHFOUNDATION_version_object_not_valid                          (EMH_BHV0BRANCHFOUNDATION_error_base + 13)

/** "%1$" was not promoted. Versions on the root branch cannot be promoted because there is no parent branch to promote to.*/
#define BHV0BRANCHFOUNDATION_no_valid_branches_to_promote                      (EMH_BHV0BRANCHFOUNDATION_error_base + 14)

/** "%1$" was not checked-in because "%2$" is a root branch. */
#define BHV0BRANCHFOUNDATION_checkin_fail_owning_branch_is_root_branch         (EMH_BHV0BRANCHFOUNDATION_error_base + 15)

/** "%1$" was not checked-in because it is not a Head version. */
#define BHV0BRANCHFOUNDATION_checkin_fail_object_not_head_version              (EMH_BHV0BRANCHFOUNDATION_error_base + 16)

/** "%1$" was not checked-in because you do not have the authorization access. */
#define BHV0BRANCHFOUNDATION_checkin_fail_unauthorized_access                  (EMH_BHV0BRANCHFOUNDATION_error_base + 17)

/** "%1$" was not checked-in because it is not checked-out. */
#define BHV0BRANCHFOUNDATION_checkin_fail_object_not_checked_out               (EMH_BHV0BRANCHFOUNDATION_error_base + 18)

/** "%1$" was not checked-in because of a system error. */
#define BHV0BRANCHFOUNDATION_checkin_fail_system_error                         (EMH_BHV0BRANCHFOUNDATION_error_base + 19)

/** The operation cannot be performed because the selected branch type "%1$" is invalid. */
#define BHV0BRANCHFOUNDATION_invalid_branch_type                               (EMH_BHV0BRANCHFOUNDATION_error_base + 20)

/** "%1$" was not promoted because it is not a Head version. */
#define BHV0BRANCHFOUNDATION_promote_fail_object_not_head_version              (EMH_BHV0BRANCHFOUNDATION_error_base + 21)

/** "%1$" was not promoted because "%2$" is a root branch. */
#define BHV0BRANCHFOUNDATION_promote_fail_owning_branch_is_root_branch         (EMH_BHV0BRANCHFOUNDATION_error_base + 22)

/** The input Branch name cannot be empty. */
#define BHV0BRANCHFOUNDATION_empty_branch_name                                 (EMH_BHV0BRANCHFOUNDATION_error_base + 23)

/** "%1$" was not created because the comment type "%2$" does not exist in the database. */
#define BHV0BRANCHFOUNDATION_non_exist_comment_type                            (EMH_BHV0BRANCHFOUNDATION_error_base + 24)

/** "%1$" was not created because the comment type "%2$" is invalid. It must be either "%3$" (Bhv0BranchComment) or any of its sub-types. */
#define BHV0BRANCHFOUNDATION_invalid_comment_type                              (EMH_BHV0BRANCHFOUNDATION_error_base + 25)

/** "%1$" was not created because the property "%2$" is invalid. */
#define BHV0BRANCHFOUNDATION_invalid_bo_property                               (EMH_BHV0BRANCHFOUNDATION_error_base + 26)

/** "%1$" was not checked-out because "%2$" is a root branch. */
#define BHV0BRANCHFOUNDATION_checkout_fail_owning_branch_is_root_branch        (EMH_BHV0BRANCHFOUNDATION_error_base + 27)

/** "%1$" was not checked-out in "%2$" because it is not a Head version. */
#define BHV0BRANCHFOUNDATION_checkout_fail_object_not_head_version             (EMH_BHV0BRANCHFOUNDATION_error_base + 28)

/** "%1$" was not checked-out in "%2$" because it is not a released version. */
#define BHV0BRANCHFOUNDATION_checkout_fail_object_not_released                 (EMH_BHV0BRANCHFOUNDATION_error_base + 29)

/** "%1$" was not checked-out in "%2$" because it is already checked-out. */
#define BHV0BRANCHFOUNDATION_checkout_fail_already_checked_out                 (EMH_BHV0BRANCHFOUNDATION_error_base + 30)

/** "%1$" was not checked-out because you do not have the authorization access. */
#define BHV0BRANCHFOUNDATION_checkout_fail_unauthorized_access                 (EMH_BHV0BRANCHFOUNDATION_error_base + 31)

/** "%1$" was not checked-out in "%2$" because of a system error. */
#define BHV0BRANCHFOUNDATION_checkout_fail_system_error                        (EMH_BHV0BRANCHFOUNDATION_error_base + 32)

/** "%1$" was not promoted because "%2$" is not an ancestor branch. */
#define BHV0BRANCHFOUNDATION_promote_fail_target_branch_not_ancestor           (EMH_BHV0BRANCHFOUNDATION_error_base + 33)

/** "%1$" was not promoted to "%2$" because it has already been promoted. */
#define BHV0BRANCHFOUNDATION_promote_fail_already_promoted                     (EMH_BHV0BRANCHFOUNDATION_error_base + 34)

/** "%1$" was not added to "%2$" because "%2$" is not a parent branch. */
#define BHV0BRANCHFOUNDATION_add_fail_source_branch_not_ancestor               (EMH_BHV0BRANCHFOUNDATION_error_base + 35)

/** "%1$" was not added to "%2$" because the object is not released.*/
#define BHV0BRANCHFOUNDATION_add_fail_content_not_released                     (EMH_BHV0BRANCHFOUNDATION_error_base + 36)

/** The check-out of "%1$" could not cancelled because "%2$" is a root branch. */
#define BHV0BRANCHFOUNDATION_cancel_checkout_fail_owning_branch_is_root_branch (EMH_BHV0BRANCHFOUNDATION_error_base + 37)

/** The check-out of "%1$" could not be cancelled because it is not a Head version. */
#define BHV0BRANCHFOUNDATION_cancel_checkout_fail_object_not_head_version      (EMH_BHV0BRANCHFOUNDATION_error_base + 38)

/** The check-out of "%1$" could not be cancelled because the current user has no authorization access on the object. */
#define BHV0BRANCHFOUNDATION_cancel_checkout_fail_unauthorized_access          (EMH_BHV0BRANCHFOUNDATION_error_base + 39)

/** The check-out of "%1$" could not be cancelled because it is not checked-out. */
#define BHV0BRANCHFOUNDATION_cancel_checkout_fail_object_not_checked_out       (EMH_BHV0BRANCHFOUNDATION_error_base + 40)

/** The check-out of "%1$" could not be cancelled because of a system error. Please refer to the Teamcenter syslog file for more information. */
#define BHV0BRANCHFOUNDATION_cancel_checkout_fail_system_error                 (EMH_BHV0BRANCHFOUNDATION_error_base + 41)

/** The merge operation was not performed because "%1$" is not in "%2$" */
#define BHV0BRANCHFOUNDATION_merge_fail_object_and_its_branch_mismatch         (EMH_BHV0BRANCHFOUNDATION_error_base + 42)

/** "%1$" was not merged with "%2$" because "%3$" is neither a child nor a sibling branch.*/
#define BHV0BRANCHFOUNDATION_merge_fail_target_branch_not_child_or_sibling     (EMH_BHV0BRANCHFOUNDATION_error_base + 43)

/** "%1$" was not merged with "%2$" because "%3$" is not a Head version. Only the latest Head version can be merged.*/
#define BHV0BRANCHFOUNDATION_merge_fail_object_not_head_version                (EMH_BHV0BRANCHFOUNDATION_error_base + 44)

/** "%1$" was not merged with "%2$" because "%3$" is either checked-out or not released. Only the released version can be merged.*/
#define BHV0BRANCHFOUNDATION_merge_fail_object_not_released                    (EMH_BHV0BRANCHFOUNDATION_error_base + 45)

/** "%1$" was not merged with "%2$" because they are not identical objects.*/
#define BHV0BRANCHFOUNDATION_merge_fail_not_same_context_identifier            (EMH_BHV0BRANCHFOUNDATION_error_base + 46)

/** "%1$" was not merged with "%2$" because the current user has no authorization access to "%3$". */
#define BHV0BRANCHFOUNDATION_merge_fail_unauthorized_access                    (EMH_BHV0BRANCHFOUNDATION_error_base + 47)

/** "%1$" was not merged with "%2$" because of a system error. Please refer to the Teamcenter syslog file for more information. */
#define BHV0BRANCHFOUNDATION_merge_fail_system_error                           (EMH_BHV0BRANCHFOUNDATION_error_base + 48)

/** "%1$" was not published because it is released.*/
#define BHV0BRANCHFOUNDATION_publish_fail_released                             (EMH_BHV0BRANCHFOUNDATION_error_base + 49)

/** "%1$" under "%2$" was not merged into "%3$" under "%4$" because "%1$" is derived from "%2$". This is not a meaningful merge operation. */
#define BHV0BRANCHFOUNDATION_merge_fail_target_derived_from_source             (EMH_BHV0BRANCHFOUNDATION_error_base + 50)

/** "%1$" was not merged with "%2$" because "%3$" is not a parent, child or sibling branch.*/
#define BHV0BRANCHFOUNDATION_merge_fail_target_branch_not_parent_or_child_or_sibling  (EMH_BHV0BRANCHFOUNDATION_error_base + 51)

/** "%1$" was not merged with "%2$" because "%3$" is a root branch. */
#define BHV0BRANCHFOUNDATION_merge_fail_target_branch_root_branch              (EMH_BHV0BRANCHFOUNDATION_error_base + 52)

/** The selected operation cannot be performed because the comment type "%1$" does not exist in the database. */
#define BHV0BRANCHFOUNDATION_operation_non_exist_comment_type                  (EMH_BHV0BRANCHFOUNDATION_error_base + 53)

/** The operation cannot be performed because because the comment type "%1$" is invalid. It must be either "%2$" (Bhv0BranchComment) or any of its sub-types. */
#define BHV0BRANCHFOUNDATION_operation_invalid_comment_type                    (EMH_BHV0BRANCHFOUNDATION_error_base + 54)

/** "%1$" was not added to "%2$" because it already exists in "%3$" under the same root branch.*/
#define BHV0BRANCHFOUNDATION_obj_already_exists_current_context                (EMH_BHV0BRANCHFOUNDATION_error_base + 55)

/** "%1$" was not added to "%2$" because objects of this type cannot be added to a branch. */
#define BHV0BRANCHFOUNDATION_invalid_obj_type_not_allowed                      (EMH_BHV0BRANCHFOUNDATION_error_base + 56)

/** The operation cannot be performed on "%1$" because its branch type is "%2$". Please select a normal branch.*/
#define BHV0BRANCHFOUNDATION_not_normal_branch_for_operation                   (EMH_BHV0BRANCHFOUNDATION_error_base + 57)

/** The selected objects were not added because "%1$" is a root branch. */
#define BHV0BRANCHFOUNDATION_add_fail_target_branch_is_root_branch             (EMH_BHV0BRANCHFOUNDATION_error_base + 58)

/** "%1$" was not added to "%2$" because an object with the same name under the same path already exists under the root branch "%3$".*/
#define BHV0BRANCHFOUNDATION_obj_with_name_under_path_already_exists_in_root   (EMH_BHV0BRANCHFOUNDATION_error_base + 59)

/** "%1$" was not promoted to "%2$" because "%1$" is either checked-out or not released in "%2$". */
#define BHV0BRANCHFOUNDATION_promote_fail_target_obj_checked_out_or_not_released    (EMH_BHV0BRANCHFOUNDATION_error_base + 60)

/** "%1$" was not promoted to "%2$" because it is either checked-out or not released. */
#define BHV0BRANCHFOUNDATION_promote_fail_source_obj_checked_out_or_not_released    (EMH_BHV0BRANCHFOUNDATION_error_base + 61)

/** The promote operation was not performed because "%1$" is not in "%2$". */
#define BHV0BRANCHFOUNDATION_promote_fail_object_and_its_branch_mismatch       (EMH_BHV0BRANCHFOUNDATION_error_base + 62)

/** "%1$" was not promoted to "%2$" because it already exists in "%2$".*/
#define BHV0BRANCHFOUNDATION_promote_fail_object_already_exist                 (EMH_BHV0BRANCHFOUNDATION_error_base + 63)

/** "%1$" was not added because its type "%2$" is excluded as per the preference "BHV0_BranchContent_AllowedTypes". */
#define BHV0BRANCHFOUNDATION_add_fail_obj_type_restricted_in_pref              (EMH_BHV0BRANCHFOUNDATION_error_base + 64)

/** "%1$" was not added because its type "%2$" is not specified in the preference "BHV0_BranchContent_AllowedTypes". */
#define BHV0BRANCHFOUNDATION_add_fail_obj_type_not_included_in_pref            (EMH_BHV0BRANCHFOUNDATION_error_base + 65)

/** "%1$" was not merged to "%2$" because it is not available in this target branch.*/
#define BHV0BRANCHFOUNDATION_merge_fail_object_not_available_target            (EMH_BHV0BRANCHFOUNDATION_error_base + 66)

/** "%1$" was not merged to "%2$" because it already exists in "%2$".*/
#define BHV0BRANCHFOUNDATION_merge_fail_object_already_exist                   (EMH_BHV0BRANCHFOUNDATION_error_base + 67)

/** "%1$" was not merged to "%2$" because it is the first version in "%3$". Source version object cannot be first version.*/
#define BHV0BRANCHFOUNDATION_merge_fail_source_first_version                   (EMH_BHV0BRANCHFOUNDATION_error_base + 68)

/** "%1$" is not a valid criterion to retrieve the branch candidates information. */
#define BHV0BRANCHFOUNDATION_invalid_branch_info_criteria                      (EMH_BHV0BRANCHFOUNDATION_error_base + 69)

/** "%1$" was not obsoleted because it is not in "%2$" */
#define BHV0BRANCHFOUNDATION_obsolete_fail_object_and_its_branch_mismatch      (EMH_BHV0BRANCHFOUNDATION_error_base + 70)

/** "%1$" was not obsoleted because "%2$" is a root branch. */
#define BHV0BRANCHFOUNDATION_obsolete_fail_owning_branch_is_root_branch        (EMH_BHV0BRANCHFOUNDATION_error_base + 71)

/** "%1$" was not obsoleted in "%2$" because object is not a Head version. */
#define BHV0BRANCHFOUNDATION_obsolete_fail_object_not_head_version             (EMH_BHV0BRANCHFOUNDATION_error_base + 72)

/** "%1$" was not obsoleted in "%2$" because object is not a released version. */
#define BHV0BRANCHFOUNDATION_obsolete_fail_object_not_released                 (EMH_BHV0BRANCHFOUNDATION_error_base + 73)

/** "%1$" was not obsoleted in "%2$" because object is already obsoleted. */
#define BHV0BRANCHFOUNDATION_obsolete_fail_object_already_obsoleted            (EMH_BHV0BRANCHFOUNDATION_error_base + 74)

/** "%1$" was not obsoleted in "%2$" because object is not in any other branch. */
#define BHV0BRANCHFOUNDATION_obsolete_fail_object_not_in_any_other_branch      (EMH_BHV0BRANCHFOUNDATION_error_base + 75)

/** "%1$" was not obsoleted because the current user has no authorization access to "%2$". */
#define BHV0BRANCHFOUNDATION_obsolete_fail_unauthorized_access                 (EMH_BHV0BRANCHFOUNDATION_error_base + 76)

/** "%1$" was not obsoleted in "%2$" because of a system error. Please check the syslog file for more information. */
#define BHV0BRANCHFOUNDATION_obsolete_fail_system_error                        (EMH_BHV0BRANCHFOUNDATION_error_base + 77)

/** "%1$" was not promoted to "%2$" because it is obsolete in "%2$".*/
#define BHV0BRANCHFOUNDATION_promote_fail_object_is_obsolete_in_target         (EMH_BHV0BRANCHFOUNDATION_error_base + 78)

/** "%1$" was not promoted to "%2$" because the target branch "%2$" has no version history for "%1$", which is obsolete in the source branch "%3$".*/
#define BHV0BRANCHFOUNDATION_promote_fail_object_obsolete_in_source_and_absent_in_target     (EMH_BHV0BRANCHFOUNDATION_error_base + 79)

/** "%1$" was not promoted to "%2$" because it is obsolete in branch "%3$", which is below the target branch "%2$" and above the source branch "%4$".*/
#define BHV0BRANCHFOUNDATION_promote_fail_object_obsolete_in_target_hierarchy            (EMH_BHV0BRANCHFOUNDATION_error_base + 80)

/** "%1$" was not checked-out in "%2$" because it is obsoleted. */
#define BHV0BRANCHFOUNDATION_checkout_fail_object_obsolete                     (EMH_BHV0BRANCHFOUNDATION_error_base + 81)

/** "%1$" was not checked-in in "%2$" because it is obsoleted. */
#define BHV0BRANCHFOUNDATION_checkin_fail_object_obsolete                      (EMH_BHV0BRANCHFOUNDATION_error_base + 82)

/** The merge operation was not performed because "%1$" is obsoleted in the source branch "%2$". */
#define BHV0BRANCHFOUNDATION_merge_fail_object_obsolete_source                 (EMH_BHV0BRANCHFOUNDATION_error_base + 83)

/** The merge operation was not performed because "%1$" is obsoleted in the target branch "%2$". */
#define BHV0BRANCHFOUNDATION_merge_fail_object_obsolete_target                 (EMH_BHV0BRANCHFOUNDATION_error_base + 84)

/** %1$" was not added to "%2$" because multiple revisions of the same Item cannot be added to a branch. */
#define BHV0BRANCHFOUNDATION_add_fail_multiple_revisions                       (EMH_BHV0BRANCHFOUNDATION_error_base + 85)

/**"%1$" was not created because there are no valid contents to create the baseline. */
#define BHV0BRANCHFOUNDATION_baseline_empty_error                              (EMH_BHV0BRANCHFOUNDATION_error_base + 86)

/** "%1$" was not promoted to "%2$" because it is the first version and its origin is not in "%3$". */
#define BHV0BRANCHFOUNDATION_promote_fail_source_first_version_not_origin      (EMH_BHV0BRANCHFOUNDATION_error_base + 87)
        
/** @} */

#endif
