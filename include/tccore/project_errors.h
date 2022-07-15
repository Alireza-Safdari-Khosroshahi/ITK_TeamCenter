/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef PROJECT_ERRORS_H
#define PROJECT_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup PROJECT_ERRORS Project Errors
    @ingroup PROJ
    @{
*/

#define PROJECT_internal_error                 (EMH_PROJECT_error_base + 1)
#define PROJECT_invalid_id                     (EMH_PROJECT_error_base + 2)
#define PROJECT_user_is_not_privileged         (EMH_PROJECT_error_base + 3)
#define PROJECT_fail_to_find_project           (EMH_PROJECT_error_base + 4)
#define PROJECT_invalid_member_tag             (EMH_PROJECT_error_base + 5)
#define PROJECT_invalid_object                 (EMH_PROJECT_error_base + 6)
#define PROJECT_invalid_project_id             (EMH_PROJECT_error_base + 7)
#define PROJECT_unknown_project_id             (EMH_PROJECT_error_base + 8)
#define PROJECT_non_workspaceobject            (EMH_PROJECT_error_base + 9)
#define PROJECT_unique_id_required             (EMH_PROJECT_error_base + 10)
#define PROJECT_invalid_admin_member_tag       (EMH_PROJECT_error_base + 11)
#define PROJECT_am_insufficient_privilege      (EMH_PROJECT_error_base + 12)
#define PROJECT_admin_required                 (EMH_PROJECT_error_base + 13)
#define PROJECT_assign_to_proj_denied          (EMH_PROJECT_error_base + 14)
#define PROJECT_remove_from_proj_denied        (EMH_PROJECT_error_base + 15)
#define PROJECT_not_member                     (EMH_PROJECT_error_base + 16)
#define PROJECT_not_member_general             (EMH_PROJECT_error_base + 17)
#define PROJECT_access_rules_absent            (EMH_PROJECT_error_base + 18)

/* Errors related to program context to restrict data creation in program context */
#define DATA_creation_restricted_to_program_context     (EMH_PROJECT_error_base + 19)
#define DATA_creation_restricted_to_current_project     (EMH_PROJECT_error_base + 20)
#define DATA_creation_restricted_to_active_project      (EMH_PROJECT_error_base + 21)
#define DATA_creation_restricted_to_program_security    (EMH_PROJECT_error_base+ 22)

/* Errors related to remove user from project */
#define PROJECT_remove_member_denied    (EMH_PROJECT_error_base+ 23)

/* Error  related to restrict deletion of project if it contains data */
#define PROJECT_is_referenced           (EMH_PROJECT_error_base + 24)


/* Errors  related to validation of project names*/
#define PROJECT_invalid_name                     (EMH_PROJECT_error_base + 25)
#define PROJECT_unique_name_required             (EMH_PROJECT_error_base + 26)

#define PROJECT_sameas_objowningprogram_required        (EMH_PROJECT_error_base + 27)

/**
 *  Error message to indicate that there are no project team members specified 
 *  while creating or modifying a project.
 */
#define PROJECT_no_project_team_members                 (EMH_PROJECT_error_base + 28)

/**
 *  Error message to indicate that there are no project team administrators specified 
 *  while creating or modifying a project.
 */
#define PROJECT_no_project_team_administrators          (EMH_PROJECT_error_base + 29)

/**
 *  Error message to indicate that the object submitted to the PROJ_copy_project and 
 *  PROJ_assign_team_members ITK APIs is not a valid project object.
 */
#define PROJECT_not_a_valid_project                     (EMH_PROJECT_error_base + 30)

/**
 *  Error message to indicate that an invalid object is submitted to add as project team administrator.
 *  User object is the valid object for team administrators.
 */
#define PROJECT_invalid_admin_or_priv_member_tag        (EMH_PROJECT_error_base + 31)

/**
 *  Error message to indicate that an invalid object is submitted to add as project team member.
 *  A group or group member object is the valid object for project team member.
 */
#define PROJECT_invalid_member_encountered              (EMH_PROJECT_error_base + 32)
/**
* The object cannot be removed from the owning project.
*/
#define PROJECT_remove_object_invalid                   (EMH_PROJECT_error_base + 33)

/**
* The name "%2$" of the object of type "%1$" contains at least one of the following invalid characters: '.', '%', '*', '@'.
*/
#define PROJECT_name_contains_invalid_character          (EMH_PROJECT_error_base + 34)

/**
* The attribute name given in the filter cannot be empty.
*/
#define PROJECT_empty_attribute_name                     (EMH_PROJECT_error_base + 35)

/**
* The attribute value given in the filter cannot be empty.
*/
#define PROJECT_empty_attribute_value                      (EMH_PROJECT_error_base + 36)

/**
* The user "%1$" must be an administrator of "%2$" to perform this operation.
*/
#define PROJECT_user_not_administrator                     (EMH_PROJECT_error_base + 37)

/**
*  The following Project members must also be Program members: %1$.
*/
#define PROJECT_all_members_not_available                  (EMH_PROJECT_error_base + 38)

/**
* A child Project cannot be changed to a Program.
*/
#define PROJECT_program_security_true_not_allowed          (EMH_PROJECT_error_base + 39)

/**
* The Program "%1$" cannot be changed to a Project because it contains children.
*/
#define PROJECT_program_security_false_not_allowed         (EMH_PROJECT_error_base + 40)

/**
*  A child Project cannot be created under "%1$" because it is not a Program.
*/
#define PROJECT_parent_not_program                         (EMH_PROJECT_error_base + 41)

/**
* The objects could not be assigned to projects under multiple programs because the "owning program" value is not set on all of them. Please correct this condition and try again.
*/
#define PROJECT_multiple_owning_program                    (EMH_PROJECT_error_base + 42)

/**
*  The Programs could not be removed because some of their child projects are still assigned to objects. Children projects must be removed before their parents.
*/
#define PROJECT_children_assigned_to_objects               (EMH_PROJECT_error_base + 43)

/**
* The Project "%1$" cannot be removed from the Program because the Program-Project hierarchy is referenced in data.
*/
#define PROJECT_hierarchy_referenced                       (EMH_PROJECT_error_base + 44)

/**
* The Project Team cannot be inherited because the Project "%1$" has no parent.
*/
#define PROJECT_team_inheritance_not_allowed               (EMH_PROJECT_error_base + 45)

/**
* A Session Program must be selected for the strict program hierarchical mode.
*/
#define PROJECT_session_program_not_selected               (EMH_PROJECT_error_base + 46)

/**
* %1$ out of %2$ objects were updated with the provided project(s).
*/
#define PROJECT_partial_success                            (EMH_PROJECT_error_base + 47)

/**
* "%1$" was assigned to projects.
*/
#define PROJECT_single_assign_success                      (EMH_PROJECT_error_base + 48)

/**
* %1$ out of %2$ selections were assigned to projects.
*/
#define PROJECT_multiple_assign_success                    (EMH_PROJECT_error_base + 49)

/**
* "%1$" could not be assigned to projects for the following reason: %2$
*/
#define PROJECT_assign_failure                            (EMH_PROJECT_error_base + 50)

/**
* "%1$" was removed from projects.
*/
#define PROJECT_single_remove_success                      (EMH_PROJECT_error_base + 51)

/**
* %1$ of %2$ selections were removed from projects.
*/
#define PROJECT_multiple_remove_success                    (EMH_PROJECT_error_base + 52)

/**
* "%1$" could not be removed from projects for the following reason: %2$
*/
#define PROJECT_remove_failure                             (EMH_PROJECT_error_base + 53)

/**
* "%1$" is a replica object and is not checked out locally by the current user.
*/
#define PROJECT_replica_not_local_co                       (EMH_PROJECT_error_base + 54)

/**
* The propagated projects cannot be removed from the "%1$" because the projects are not assigned explicitly.
*/
#define PROJECT_cannot_remove_propagated                       (EMH_PROJECT_error_base + 55)

/**
 * The member "%1$" is already in the Project Team "%2$".
 */
#define PROJECT_member_already_in_project_team                 (EMH_PROJECT_error_base + 56)

/**
 * The member "%1$" is not in the Project Team "%2$".
 */
#define PROJECT_member_not_in_project_team                     (EMH_PROJECT_error_base + 57)

/**
 * The User "%1$" is not a member in the Project Team "%2$".
 */
#define PROJECT_user_not_member_in_project_team                (EMH_PROJECT_error_base + 58)

/**
 * The User "%1$" is already a % 2$ in Project Team "%3$".
 */
#define PROJECT_user_already_privileged_in_project_team        (EMH_PROJECT_error_base + 59)

/**
 * The User "%1$" is not a % 2$ in Project Team "%3$".
 */
#define PROJECT_user_not_privileged_in_project_team            (EMH_PROJECT_error_base + 60)

 /**
  * The Project "%1$" is not active.
  */
#define PROJECT_not_active                                     (EMH_PROJECT_error_base + 61)

/**
 * The Program "%1$" is not active.
 */
#define PROGRAM_not_active                                     (EMH_PROJECT_error_base + 62)

/** @} */

#include <tccore/libtccore_undef.h>
#endif
