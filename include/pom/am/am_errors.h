/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file
    
    This include file contains all the error codes which may be returned by AM
*/

/** @if DOX_IGNORE
    Error code definitions

    We now also add the textual descriptions that go into the help system.
    These follow the 'Cause'/'Action' format as below. The text from help
    and the error message (defined in am_errors.uih) can also be found in
    the IMAN User Guide; appendix G(?) "Error Messages".

    The am_errors.uih should also be updated when an error is added here.
    The line to add follows the error_525xxx format as below. Note: should
    the error base ever change then this file can be easily changed with
    a global edit, but it is vital that the pom encapsulation (error handling)
    be recompiled and the UIH file and doc's be updated from this copy.

    I have also purged the obsolete error codes for V2.3, I recommend that
    obsoleted codes be recorded in this comment for one point release.

    Generate the help file (if there are any changes) for the release via;
    Note: the two blank lines before the command and the lack of leading
    spaces is significant to avoid picking up this text. Also the '.'
    within the sed after the '*' - is there to avoid closing the comment.

    These errors are obsolete and should not be removed from the code.

    AM_not_loaded
    AM_acl_is_locked

    The error messages are still useful here - but the uil info is now editted
    directly into /vobs/src/lang/code/am_errors.uih

    more +/XXX am_errors.h | sed "s/^[^ ].*.//" > am_errors.help
@endif */

/*  */

#ifndef AM_ERRORS_H
#define AM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup AM_ERRORS Errors
    @ingroup AM
    @{
*/

/**
    Success
*/
#define AM_ok                           0


#define AM_ERROR_BASE                   EMH_AM_error_base
#define AM_min_err_code                 AM_ERROR_BASE

/**
    An internal error occurred.
*/
#define AM_internal_error               AM_ERROR_BASE + 1

/**
    Function called is not yet implemented.
*/
#define AM_not_implemented              AM_ERROR_BASE + 2

/**
    #AM_init_module has not yet been called.
*/
#define AM_not_initialised              AM_ERROR_BASE + 3

/**
    You can not remove the last occurrence of change rights in an ACL.
*/
#define AM_last_change_rights           AM_ERROR_BASE + 4

/**
    Instance has been deleted by another user.
*/
#define AM_has_been_deleted             AM_ERROR_BASE + 7

/**
    ACL is already locked for editing.
*/
#define AM_acl_is_locked                AM_ERROR_BASE + 11

/**
    ACL is not locked for editing.
*/
#define AM_acl_is_not_locked            AM_ERROR_BASE + 12

/** @} */

/**
    @name ACL tag argument checking
    @{
*/

/**
    One of the specified tags is invalid.
*/
#define AM_bad_tag                      AM_ERROR_BASE + 20

/**
    One of the specified instance tags is invalid.
*/
#define AM_bad_instance_tag             AM_ERROR_BASE + 21

/**
    Specified tag is not a valid user tag.
*/
#define AM_bad_user_tag                 AM_ERROR_BASE + 22

/**
    Specified tag is not a valid group tag.
*/
#define AM_bad_group_tag                AM_ERROR_BASE + 23

/**
    Specified tag is not a valid accessor tag.
*/
#define AM_bad_accessor_tag             AM_ERROR_BASE + 24

/**
    Specified tag is not a valid ACL tag.
*/
#define AM_bad_acl_tag                  AM_ERROR_BASE + 25

/** @} */

/**
    @name ACL access mask argument checking
    @{
*/

/**
    One of the access masks is invalid.
*/
#define AM_bad_access_mask              AM_ERROR_BASE + 30

/**
    User access mask is invalid.
*/
#define AM_bad_user_access_mask         AM_ERROR_BASE + 31

/**
    Group access mask is invalid.
*/
#define AM_bad_group_access_mask        AM_ERROR_BASE + 32

/**
    System group access mask is invalid.
*/
#define AM_bad_system_access_mask       AM_ERROR_BASE + 33

/**
    World access mask is invalid.
*/
#define AM_bad_world_access_mask        AM_ERROR_BASE + 34

/** @} */

/**
    @name ACL entry list size/position argument checking
    @{
*/

/**
    A number was specified out of its valid range.
*/
#define AM_out_of_range                 AM_ERROR_BASE + 40

/**
    Number of instances specified was less than zero.
*/
#define AM_n_instances_out_of_range     AM_ERROR_BASE + 41

/**
    A position was specified not in the range [1, length of acl].
*/
#define AM_position_out_of_range        AM_ERROR_BASE + 42

/**
    Source position was not in the range [1, length of acl].
*/
#define AM_source_out_of_range          AM_ERROR_BASE + 43

/**
    Destination position was not in the range [1, length of acl].
*/
#define AM_destination_out_of_range     AM_ERROR_BASE + 44

/**
    Block length to move was not in the range [1, length of acl].
*/
#define AM_length_out_of_range          AM_ERROR_BASE + 45

/**
    Number of accessors specified is outside the allowed limits.
*/
#define AM_n_accessors_out_of_range     AM_ERROR_BASE + 46

/**
    You do not have sufficient access rights for the attempted operation.
*/
#define AM_insufficient_access          AM_ERROR_BASE + 50

/** @} */

/**
    @name ACL editing tests
    @{
*/

/**
    An entry already exists for the specified [user/group] pair.
*/
#define AM_duplicate_entry              AM_ERROR_BASE + 60

/**
    No entry exists for the [user/group] pair.
*/
#define AM_control_does_not_exist       AM_ERROR_BASE + 61

/** @} */

/**
    @name Creating wrappers tests
    @{
*/

/**
    Specified tag is not of the correct class.
*/
#define AM_invalid_class                AM_ERROR_BASE + 70

/**
    Specified tag is not a valid tag.
*/
#define AM_invalid_tag                  AM_ERROR_BASE + 71

/**
    Specified date is not valid.
*/
#define AM_invalid_date                 AM_ERROR_BASE + 72

/**
    Specified index is not within the required range.
*/
#define AM_index_out_of_range           AM_ERROR_BASE + 73

/** @} */

/**
    @name Convert some POM errors to AM errors
    @{
*/

/**
    Cause:  POM not started

    Action: Login before using AM calls.
*/
#define AM_pom_not_started              (AM_ERROR_BASE + 80)

/**
    Cause:  POM out of memory caught in AM.

    Action: Check application is freeing used memory.
*/
#define AM_out_of_memory                (AM_ERROR_BASE + 81)

/**
    Cause:  POM timeout caught.

    Action: Retry operation, or setup automatic retries via POM.
*/
#define AM_timeout                      (AM_ERROR_BASE + 82)

/**
    Cause:  POM DB full.

    Action: See Oracle docs to extend DB space.
*/
#define AM_database_full                (AM_ERROR_BASE + 83)

/**
    Cause:  No privilege for operation.

    Action: Check with owner of object.
*/
#define AM_access_denied                (AM_ERROR_BASE + 84)

/**
    Cause: The database has been changed since you changed it, so your operation is irreversible.  

    Action: Use the inverse operation explicitly to undo these changes, e.g., remove class  to undo save class.  
*/
#define AM_db_prevents_rollback         (AM_ERROR_BASE + 85)

/**
    Cause:  Unsaved instance referenced.

    Action: Save the referenced instances before or with the instance to be saved.
*/
#define AM_inst_references_unsaved      (AM_ERROR_BASE + 86)

/**
    Cause:  Attempt to instantiate an uninstatiable class.

    Action: Check log file for source of error.
*/
#define AM_class_is_uninstantiable      (AM_ERROR_BASE + 87)

/**
    Cause:  POM failed.

    Action: Check log file for source of error.
*/
#define AM_inst_locked                  (AM_ERROR_BASE + 88)

/**
    Cause:  POM failed.

    Action: Check log file for source of error.
*/
#define AM_inst_referenced              (AM_ERROR_BASE + 89)

/**
    Cause:  POM failed.

    Action: Check log file for source of error.
*/
#define AM_inst_selected                (AM_ERROR_BASE + 90)

/**
    You are not a user of sufficient privilege for this operation. 
    Typically, user is not a Teamcenter Engineering system administrator
*/
#define AM_insufficient_privilege       (AM_ERROR_BASE + 91)

/** @} */

/**
    @name AM general tests
    @{
*/

/**
    Attempted edit would cause a duplicate name.
*/
#define AM_duplicate_name               AM_ERROR_BASE + 100

/**
    An object with the specified name could not be found.
*/
#define AM_name_not_found               AM_ERROR_BASE + 101

/** @} */

/**
    @name AM Privilege class tests
    @{
*/

/**
    A privilege with the specified offset could not be found.
*/
#define AM_offset_not_found             AM_ERROR_BASE + 110

/**
    No more privileges can be created.
*/
#define AM_exceeded_max_offset          AM_ERROR_BASE + 111

/**
    Supplied name is too long.
*/
#define AM_invalid_priv_name            AM_ERROR_BASE + 112

/** @} */

/**
    @name AM ACL class tests
    @{
*/

/**
    Specified accessor was not found within the specified ACL.
*/
#define AM_ace_not_found                AM_ERROR_BASE + 120

/**
    Specified ACL name is too long.
*/
#define AM_invalid_acl_name             AM_ERROR_BASE + 121

/**
    Cause:  The given acl type is not valid: must be either "RULETREE" or "WORKFLOW".

    Action: Correct the type.
*/
#define AM_invalid_acl_type             AM_ERROR_BASE + 125

/** @} */

/**
    @name AM Accessor tests
    @{
*/

/**
    Specified type is not a valid accessor type.
*/
#define AM_invalid_acc_type             AM_ERROR_BASE + 130

/**
    Specified accessor is not of a valid accessor class.
*/
#define AM_invalid_acc_class            AM_ERROR_BASE + 131

/** @} */

/**
    @name AM Named Tag tests
    @{
*/

/**
    Supplied name is too long.
*/
#define AM_invalid_named_tag_name       AM_ERROR_BASE + 141

/** @} */

/**
    @addtogroup AM
    @{
*/

/**
    AM is not installed.
*/
#define AM_not_installed                AM_ERROR_BASE + 160

/**
    Specified ACL is not loaded.
*/
#define AM_not_loaded                   AM_ERROR_BASE + 161

/**
    There are other users logged into the database.
*/
#define AM_non_exclusive_login          AM_ERROR_BASE + 162

/**
    Specified rule name is too long.
*/
#define AM_invalid_rule_name            AM_ERROR_BASE + 163

/**
    Specified node was not previously cut from the rule tree.
*/
#define AM_node_not_cut                 AM_ERROR_BASE + 164

/**
    Specified node has already been cut from the rule tree.
*/
#define AM_node_cut_error               AM_ERROR_BASE + 165

/**
    A root node for the rule tree already exists.
*/
#define AM_node_root_exists             AM_ERROR_BASE + 166

/**
    Specified "previous" node is not a child of the specified "parent" node.
*/
#define AM_node_inconsistent_paste      AM_ERROR_BASE + 167

/**
    Specified rule argument is too long.
*/
#define AM_invalid_rule_arg             AM_ERROR_BASE + 168

/**
    There was an error during evaluation of a rule.
*/
#define AM_rule_failed                  AM_ERROR_BASE + 169

/**
    No rule with specified name exists.
*/
#define AM_rule_not_found               AM_ERROR_BASE + 170

/**
    There was an attempt to evaluate a rule before it was registered.
*/
#define AM_rule_not_registered          AM_ERROR_BASE + 171

/**
    Cause:  Attempt to register a rule or name an ACL using a 
            reserved id.

    Action: choose another id, that is distinct from the reserved
            id's, and from any other used id's.
*/
#define AM_reserved_id                  AM_ERROR_BASE + 172

/**
    Argument listing function for this rule failed.
*/
#define AM_list_rule_args_failed        AM_ERROR_BASE + 173

/**
    Argument validation function for this rule failed.
*/
#define AM_validate_rule_arg_failed     AM_ERROR_BASE + 174

/**
    Cause:  The ACL selector function failed - caught by error handler.

    Action: check for evidence as to where the error originated in
            the journal and trace files.
*/
#define AM_acl_selector_failed          AM_ERROR_BASE + 175

/**
    Cause:  Object ACLs are only permitted on POM Application Objects.

    Action: Use a POM Application Object in cases where an Object ACL
            is required.
*/
#define AM_object_acl_on_non_pao        AM_ERROR_BASE + 176

/**
    Cause:  An obsolete old AM function is being used.

    Action: Use the rules tree and new AM functions to replace the use
            of the old AM function.
*/
#define AM_old_am_function              AM_ERROR_BASE + 177

/**
    Cause:  An attempt has been made to edit/cut/reorder the children
            of a rule tree node that is not editable.

    Action: You cannot edit the children of the node.
*/
#define AM_cannot_edit_node             AM_ERROR_BASE + 178

/**
    Cause:  The attempted find returned more than one instance.

    Action: Change the name, and re-find.
*/
#define AM_ambiguous_name               AM_ERROR_BASE + 179

/**
    Cause:  The AM rule has no implementation for your object's data manager.

    Action: check for evidence as to where the error originated in
            the journal and trace files.
*/
#define AM_no_rule_for_data_manager     AM_ERROR_BASE + 180

/**
    Cause:  The AM accessor type has no implementation for your
            object's data manager.

    Action: check for evidence as to where the error originated in
            the journal and trace files.
*/
#define AM_no_check_fn_for_data_manager AM_ERROR_BASE + 181

/**
    Cause:  A normal load/refresh function was called from within
            a rule or accessor function. This is probably the result
            of using cxpom objects from within a rule or accessor
            implementation, which is not allowed.

    Action: Rewrite the rule or accessor function to not use cxpom
            objects.
*/
#define AM_load_not_allowed_within_rule AM_ERROR_BASE + 182

/**
    Cause:  A special load/refresh function was called from outside
            a rule or accessor implementation function.

    Action: Rewrite code to use normal load/refresh functions instead of
            the special ones reserved for rule/accessor implementations.
*/
#define AM_load_not_allowed_outside_rule AM_ERROR_BASE + 183

#define AM_error_null_argument_value AM_ERROR_BASE + 184

/**
 The changes in the Access Manager rule tree have impacted the READ access of too many business objects. Please complete a full indexing of Teamcenter business data to external systems like Solr.
*/
#define AM_found_too_many_objects_for_reindex AM_ERROR_BASE + 185

/**
 The READ expression creation has failed for one or more of the given objects. Access Manager will return a default READ expression for all the objects. All the objects will be marked for re-indexing to SOLR because the READ expressions are incorrect.
*/ 
#define AM_read_expression_creation_failed   AM_ERROR_BASE + 186

/**
 An entry with the key "%1$" for the property "%2$" must be created in a custom localizable TextServer file. Please contact your system administrator.
*/ 
#define AM_no_k_am_accessor_key_found        AM_ERROR_BASE + 187

/**
 A consumer user is not allowed to perform the create operation.
*/ 
#define AM_create_not_allowed_for_consumer   AM_ERROR_BASE + 188

/**
 A consumer user is not allowed to perform the update operation.
*/ 
#define AM_update_not_allowed_for_consumer   AM_ERROR_BASE + 189

/**
 A consumer user is not allowed to perform the delete operation.
*/ 
#define AM_delete_not_allowed_for_consumer   AM_ERROR_BASE + 190


#define AM_max_err_code                      AM_ERROR_BASE + 190

/** @} */

#endif

