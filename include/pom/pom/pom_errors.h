/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This include file contains all the error codes which may be returned by POM

    @note Do not produce any \#defines for macros in this file. The defines
    here are used in generating the 'filter_out_pom_tokens' mangler.
*/

/*  */

#ifndef POM_ERRORS_H_INCLUDED
#define POM_ERRORS_H_INCLUDED

#include <common/emh_const.h>

/**
    @defgroup POM_ERRORS Errors
    @ingroup POM
    @{
*/

/** Success */
#define POM_ok                              0

#define POM_error_base                      EMH_POM_error_base
#define ERROR_ENQ_base                      EMH_POM_error_base+1000

/**
    Access control list on an instance prevents access
*/
#define POM_access_denied                   (POM_error_base + 1)

/**
    Operation is System Administrator feature only.
    Ask a system administrator to perform the required action.
*/
#define POM_insufficient_privilege          (POM_error_base + 2)

/**
    Attempt to read, modify, load, save, delete, or otherwise access
    an instance of an application protected class,
    without using the interface defined by that application,
    or to create, modify, or delete such a class.
*/
#define POM_applic_not_privileged           (POM_error_base + 3)

/**
    Serious internal error, could not roll back - internal state may be invalid.
    Advise logout and restart as soon as possible.
*/
#define POM_irrecoverable_error             (POM_error_base + 4)

/**
    The operation may work in a future version, but not yet.
    This may refer to an operation being available in a particular context,
    for example defining an attribute not being possible once the class has been saved.
    Check for availability of feature in later release.
*/
#define POM_op_not_supported                (POM_error_base + 5)

/**
    The memory subsystem reports no memory available.
    Check modules initialized correctly,
    machine is configured with enough space and application is freeing space.
*/
#define POM_out_of_memory                   (POM_error_base + 6)

/**
    Attempt to use a function that requires POM startup.
    This is performed by #ITK_init_module (or #ITK_auto_login).
    Many functions require a caller to be authenticated, by login, before they can function.
*/
#define POM_start_not_yet_called            (POM_error_base + 7)

/**
    A DB timeout occurred. This implies competition for resources from another user.
    Retry function. If timeouts persist adjust the timeout preferences
    TC_max_number_of_retries and TC_retry_time to automatically retry.
*/
#define POM_timeout_occurred                (POM_error_base + 8)

/**
    Anything not covered by a more specific error code.
    May be caused by -
    <ul>
    <li>Error returned from another module called by POM.
    <li>Corrupt environment e.g. schema file and database out of sync.
    <li>Access violation when dereferencing an invalid pointer given as an argument to POM.
    <li>Programming error within POM.
    </ul>
    Please report this error with journal file and trace files if available.
*/
#define POM_internal_error                  (POM_error_base + 9)

/**
    The attribute_id does not refer to an existing attribute,
    or the attribute is not defined on the specified class.
*/
#define POM_invalid_attr_id                 (POM_error_base + 20)

/**
    The class_id does not refer to an existing class.
    Check where the class id tag is being derived from.
*/
#define POM_invalid_class_id                (POM_error_base + 21)

/**
    The class or attribute descriptor is not the sum of valid class or attribute properties,
    or includes mutually exclusive tokens.

    If customization code has not been recompiled since the last release,
    check whether the descriptor values have changed.
    Check the combination and values of the descriptor.
*/
#define POM_invalid_descriptor              (POM_error_base + 22)

/**
    The enquiry_id does not refer to an existing enquiry.
    Check whether the enquiry has been deleted or if the create enquiry failed.
*/
#define POM_invalid_enquiry_id              (POM_error_base + 23)

/**
    The tag given is not a valid tag.
    Possibly due to an earlier error not having been handled,
    uninitialized data or unloaded/deleted or otherwise invalid references.
    Check where the reference was obtained from and the validity of same in this operation.
*/
#define POM_invalid_tag                     (POM_error_base + 24)

/**
    The tag is a valid tag, but is not the tag of a user.
    Find the tag of the user required for this operation.
*/
#define POM_invalid_user_tag                (POM_error_base + 25)

/**
    The tag is a valid tag, but is not the tag of a group.
    Find the tag of the group required for this operation.
*/
#define POM_invalid_group_tag               (POM_error_base + 26)

/**
    The; class, attribute, group or user name does not follow the naming rules -
    i.e. printable and length restrictions. See manual for limits.
*/
#define POM_invalid_name                    (POM_error_base + 27)

/**
    The number specified is not a valid markpoint id.
    Maybe used (i.e. rollback performed) or forgotten (ie. freed up as obsolete).
*/
#define POM_invalid_markpoint               (POM_error_base + 28)

/**
    The string contains non-printing characters.
*/
#define POM_invalid_string                  (POM_error_base + 29)

/**
    The token is not recognized, or not valid in the context used.
    If customization code has not been recompiled since the last release,
    check whether the token values have changed.
    Check the combination and values of the token.
*/
#define POM_invalid_token                   (POM_error_base + 30)

/**
    The logical has a value other than true or false.
    Check caller is picking up the correct definitions for macros defining true and false.
*/
#define POM_invalid_logical                 (POM_error_base + 31)

/**
    The date is not a possible date. Check calling code.

    @note Null dates are only allowed in attributes with property #POM_null_is_valid.
*/
#define POM_invalid_date                    (POM_error_base + 32)

/**
    A value is invalid in some way not covered above.
    Check error messages in trace file for source of error.
*/
#define POM_invalid_value                   (POM_error_base + 33)

/**
    There is some reference to a now non-existent instance in the archive being restored.
    Restore a different subset of instances from the archive or
    first restore the absent instance from another archive.
*/
#define POM_invalid_archive_tag             (POM_error_base + 34)

/**
    The string is too long.
    See manual for limits.
 */
#define POM_string_too_long           (POM_error_base + 35)

/**
    The schema cannot be modified without explicit call to POM_start_modify or POM_modify_schema.

    @note These calls may fail if user is not a system administrator or the schema is in use
    (i.e. active sessions exist).

    Use POM_start_modify or POM_modify_schema if you wish to change the schema.
*/
#define POM_schema_not_modifiable           (POM_error_base + 40)

/**
    A class with this name exists.
    Check whether class has already been defined or there is a name clash with an existing application.
*/
#define POM_duplicate_name                  (POM_error_base + 41)

/**
    The class given as superclass is uninheritable.
    Ensure that superclasses of new classes do not have the property #POM_uninheritable_class.
*/
#define POM_class_is_uninheritable          (POM_error_base + 42)

/**
    Class of an instance in archive file does not exist in the DB/schema.
    Check that the schema has not been changed since the archive was created.
*/
#define POM_archive_invalid_class           (POM_error_base + 43)

/**
    POM_save_class has already been called for this class.
    POM_save_class should only be called once for any class.
*/
#define POM_class_already_saved             (POM_error_base + 50)

/**
    The attribute descriptor included #POM_has_initial_value but no such initial value has been specified.
    Set an initial value before saving the class.
*/
#define POM_attr_initial_not_set            (POM_error_base + 52)

/**
    The attribute descriptor included #POM_has_lowerbound but no such bound has been specified.
    Set a lower bound before saving the class.
*/
#define POM_attr_lowerb_not_set             (POM_error_base + 53)

/**
    The attribute descriptor included #POM_has_upperbound but no such bound has been specified.
    Set a upper bound before saving the class.
*/
#define POM_attr_upperb_not_set             (POM_error_base + 54)

/**
    Cannot delete class with subclasses.
    First delete all subclasses.
*/
#define POM_class_has_subclasses            (POM_error_base + 60)

/**
    Cannot delete class that has instances.
    Delete all instances before deleting the class.
*/
#define POM_class_is_instantiated           (POM_error_base + 61)

/**
    Cannot delete class that is named in typed reference attribute.
    There may be several other classes with typed reference attributes which
    require any references to be an instance of the cited class
    (or a subclass of same) as a type-checking integrity test.
*/
#define POM_class_referenced                (POM_error_base + 62)

/**
    The class is instantiated in a loaded archive,
    the instances of class fn will not find any inst's in this case
    (otherwise you would get #POM_class_is_instantiated).
    The error comes from OM_delete_class.
    Unload the archives instantiating the class before deleting the class.
*/
#define POM_instantiated_in_archive         (POM_error_base + 63)

/**
    The array length specified is less than 1 or too large,
    (and is not -1 indicating a variable length array)
    Check that array length is correct for required attribute size
    (scalar, fixed length or variable length).
*/
#define POM_invalid_length                  (POM_error_base + 70)

/**
    The attribute type is not a valid token.
    Check the type tokens have not changed since the last compilation of source and are valid tokens.
*/
#define POM_invalid_attrtype                (POM_error_base + 71)

/**
    Bounds are not defined for all attribute types.
    You can not set a bound on an attribute unless its descriptor included
    #POM_has_lowerbound or #POM_has_upperbound when first defined.
    Check the manual for attribute bound restrictions.
*/
#define POM_attr_cant_have_bound            (POM_error_base + 72)

/**
    Once a class has been instantiated, bounds may not be tightened
    (Because existing instances may be outside the new bounds).
*/
#define POM_cant_increase_lowerb            (POM_error_base + 73)

/**
    Once a class has been instantiated, bounds may not be tightened
    (Because existing instances may be outside the new bounds).
*/
#define POM_cant_decrease_upperb            (POM_error_base + 74)

/**
    The lower bound must be smaller than the upper bound,
    and any initial value must be between them
    Check that the lower bound is smaller than the upper bound,
    and the initial value is within that range.
*/
#define POM_invalid_bounds                  (POM_error_base + 75)

/**
    The class must be saved in the DB before an index can be applied.
    Save the class before indexing.
*/
#define POM_class_not_yet_saved             (POM_error_base + 80)

/**
    An index in this set of attributes already exists.
    Avoid redundant reindexing, or drop index before regenerating.
*/
#define POM_attr_set_has_index              (POM_error_base + 81)

/**
    Index names must be unique within a given class.
    Check whether index has already been defined.
*/
#define POM_index_already_in_class          (POM_error_base + 82)

/**
    Transient attributes can not be indexed.
    Transient attributes values are not stored in the database hence they cannot be indexed.
    Avoid transient attributes in index definitions.
*/
#define POM_transient_not_indexable         (POM_error_base + 83)

/**
    Note attributes can not be indexed.
    Check manual for restrictions.
*/
#define POM_note_not_indexable              (POM_error_base + 84)

/**
    Array attributes may not be indexed.
    Check manual for restrictions.
*/
#define POM_array_not_indexable             (POM_error_base + 85)

/**
    All attributes in an index must be defined in a single class,
    it is not possible to include some inherited attributes.
    Avoid indexing over two classes.
    Create the index in the class in which the attributes are defined.
*/
#define POM_inherited_not_indexable         (POM_error_base + 86)

/**
    There are instances which already use the same value for this attribute (set).
    Eliminate duplicates before applying unique index.
*/
#define POM_create_unique_index_fail        (POM_error_base + 87)

/**
    There is no index of the specified name in this class.
    Check if index has already been deleted.
*/
#define POM_index_not_in_class              (POM_error_base + 90)

/**
    If a class is declared to be uninstantiable,
    it is not possible to create instances of that class
    (or to load instances of a subclass of this class).
    Check that the classes that are to be populated do not
    have the property #POM_uninstantiable_class.
*/
#define POM_class_is_uninstantiable         (POM_error_base + 100)

/**
    You must have a current group set before creating instances.
    Set your current group via #POM_login or #POM_set_group.
*/
#define POM_no_current_group                (POM_error_base + 101)

/**
    An object must be loaded as an instance of its own class,
    or a superclass of that class.
    Check the class of the instance to be loaded vs. the class hierarchy.
*/
#define POM_class_not_a_superclass          (POM_error_base + 102)

/**
    The instance is already loaded.
    Avoid redundant load via test #POM_is_loaded or refresh via #POM_refresh_instances.
*/
#define POM_inst_already_loaded             (POM_error_base + 103)

/**
    Instance can not be saved until all attributes are set.
    Check the trace file for which attributes are empty.
*/
#define POM_inst_has_empty_attr             (POM_error_base + 105)

/**
    The instance duplicates the values of an existing instance in an attribute or
    set of attributes which were declared to be uniquely valued.
    Check whether index should be unique.
*/
#define POM_inst_violates_unique            (POM_error_base + 106)

/**
    The instance contains references to instances not in the database.
    Where a number of newly created or undeleted instances reference each other,
    the referenced instances must be saved first,
    or (if interreferencing) they must all be saved at once.
*/
#define POM_inst_references_unsaved         (POM_error_base + 107)

/**
    Instances to be loaded together must be of the same class.
    To load instances of differing class at the same time use #POM_load_instances_any_class.
*/
#define POM_insts_in_diff_classes           (POM_error_base + 108)

/**
    An instance may not be loaded for modify by two different sessions,
    nor may it be deleted while loaded.
    Check that the other session has finished with the instance and retry.
    If there are no other active users, the clearlocks program may need to be run
    (see system administrator).
*/
#define POM_inst_in_use                     (POM_error_base + 109)

/**
    An instance may not be deleted while referenced by other instances or class variables.
    Remove all references to the instance to be deleted.
*/
#define POM_inst_referenced                 (POM_error_base + 110)

/**
    Instance not loaded.
    Load the instance for this operation.
*/
#define POM_inst_not_loaded                 (POM_error_base + 111)

/**
    Instance not locked.
    The instance must be loaded for modify for this operation.
    Lock the instance via #POM_load_instances or #POM_refresh_instances.
*/
#define POM_inst_not_locked                 (POM_error_base + 112)

/**
    Invalid number of instances.
    There must be at least one instance for this operation.
*/
#define POM_n_insts_out_of_range            (POM_error_base + 113)

/**
    The tag of the instance is not in the archive.
    Check that the required instance is in the archive.
*/
#define POM_inst_not_in_archive             (POM_error_base + 114)

/**
    The instance is newly created.
    Save the instance before attempting this operation.
*/
#define POM_inst_newly_created              (POM_error_base + 115)

/**
    The attribute was not selected during load.
    Refresh or reload the instance with the required attribute.
*/
#define POM_inst_selected                   (POM_error_base + 116)

/**
    The slice of an array being taken starts before the start of the array,
    or is beyond its end.
    Check that the start offset is within the array size.
*/
#define POM_start_out_of_range              (POM_error_base + 120)

/**
    The number of values is less than one, or extends beyond the length of the attribute.
    Check that the number of values requested is within the array size.
*/
#define POM_n_values_out_of_range           (POM_error_base + 121)

/**
    Attempt to set NULL where not allowed.
    Attribute requires #POM_null_is_valid.
*/
#define POM_attr_null_forbidden             (POM_error_base + 122)

/**
    The type of the attribute is incompatible with the function being used.
    e.g. #POM_set_attr_ints with a date attribute.
    Check the attribute type.
*/
#define POM_wrong_attr_type                 (POM_error_base + 123)

/**
    Attempt to reorder an array with new position off the start or end of the array.
    Check that the moving a block of values within an array will not leave empty values.
*/
#define POM_newstart_out_of_range           (POM_error_base + 124)

/**
    The value you have given is outside the bounds for this attribute.
    Check that the value is within the attribute bounds.
*/
#define POM_value_out_of_bounds             (POM_error_base + 125)

/**
    You are trying to set an attribute of a frozen instance.
    Unfreeze the instance first.
*/
#define POM_instance_is_frozen              (POM_error_base + 126)

/**
    You can't refresh an newly created, unsaved, instance.
    Save the instance before any call to refresh.
*/
#define POM_cant_refresh_new                (POM_error_base + 127)

/**
    Cannot set attribute values on instance not loaded for modify (locked).
    Lock the instance via load or refresh using the lock token #POM_modify_lock.
*/
#define POM_not_loaded_for_modify           (POM_error_base + 128)

/**
    Enquiries on different classes can not be combined unless one class is a superclass of the other.
    Check that the classes of the enquiry components is correct.
*/
#define POM_enquiries_dont_match            (POM_error_base + 130)

/**
    Invalid number of enquiries to delete.
    Check that at least one and less than #POM_MAX_ENQUIRIES
    (defined in pom.h) are being deleted in one call.
*/
#define POM_n_enquiries_out_of_range        (POM_error_base + 131)

/**
    POM is already running.
    Do not call #POM_start more than once without calling #POM_stop.
*/
#define POM_already_running                 (POM_error_base + 140)

/**
    The System Administrator has disabled logins to POM.
    See the system administrator for system availability.
*/
#define POM_logins_are_disabled             (POM_error_base + 141)

/**
    Name given is not a known group. Check that the group does exist.
*/
#define POM_unknown_group                   (POM_error_base + 142)

/**
    Name given is not a known user. Check that the user does exist.
    Either user ID or password is "invalid" or both user ID and
    password is "invalid".
*/
#define POM_invalid_account_values          (POM_error_base + 143)

/**
    The password supplied was incorrect.
    Check the password given. See system administrator.
    i.e. user ID is 'valid' but password is 'invalid'.
*/
#define POM_password_wrong                  (POM_error_base + 144)

/**
    Schema is locked while other POM sessions exist.
    Modifications to the schema require exclusive access.
    Ask the system administrator when the system will be available.
    If you were modifying the schema and the program died,
    try logging in again (as a system administrator).
*/
#define POM_schema_locked                   (POM_error_base + 145)

/**
    V6 of the POM will work only on rules-based AM databases.
    You should upgrade your database to use the rules-based AM before attempting to run V6.
    Refer to chapter 10 of the System Admin. Guide for details.
*/
#define POM_new_am_required                 (POM_error_base + 146)

/**
    Attempting to call #POM_stop with unsaved work without specifying that unsaved work should be discarded.
    Save any modified data.
    #POM_stop given an argument of true will ignore unsaved instances and hence suppress this error,
    however those changes are lost.
*/
#define POM_unsaved_stuff                   (POM_error_base + 150)

/**
    The user is not a member of the group.
    Ask the group administrator to make the user a member.
*/
#define POM_user_and_group_invalid          (POM_error_base + 151)

/**
    The pointer handed to POM_free was not to space allocated by POM. ((OF) arguments)
    Use the freeing procedure corresponding to the allocator.
*/
#define POM_cant_free_unallocated           (POM_error_base + 152)

/**
    Returned by #POM_check_reference if the specified attribute does not contain a valid reference.
    Report this error with the journal file if possible.
*/
#define POM_attr_not_a_reference            (POM_error_base + 153)

/**
    Unless a new password is being set by the System Administrator,
    the existing password must be given when setting a new one.
    Recheck the password or ask the System Administrator to change the password.
*/
#define POM_incorrect_old_password          (POM_error_base + 154)

/**
    There is no class with the name given to #POM_class_id_of_class or #POM_attr_id_of_attr
    Check the class is installed.
*/
#define POM_no_class_of_this_name           (POM_error_base + 155)

/**
    There is no attribute in the specified class with the name given to #POM_attr_id_of_attr
    Check that the class has been installed correctly.
*/
#define POM_no_attr_of_this_name            (POM_error_base + 156)

/**
    Call to #POM_identify_application with a 'false' argument which does not balance a call with 'true'
    The application must be identified 'true' before this call.
*/
#define POM_not_current_application         (POM_error_base + 157)

/**
    POM rollback is not enabled.
    Use #POM_set_env_info to enable rollback.
*/
#define POM_rollback_not_enabled            (POM_error_base + 158)

/**
    The database has been changed since you changed it, so your operation is irreversible.
    Use the inverse operation explicitly to undo these changes,
    e.g. remove class to undo save class.
*/
#define POM_db_prevents_rollback            (POM_error_base + 159)

/**
    Invalid number of levels to follow where_referenced tree in #POM_referencers_of_instance.
    Use a smaller depth of search.
*/
#define POM_n_levels_out_of_range           (POM_error_base + 160)

/**
    Invalid number of attribute_ids in #POM_describe_attrs.
    Check the number requested is at least one and less than the number of attributes present.
*/
#define POM_n_attrs_out_of_range            (POM_error_base + 161)

/**
    Invalid number of attribute names in #POM_describe_class.
    Check the number requested is at least one and less than the number of attributes present.
*/
#define POM_n_names_out_of_range            (POM_error_base + 162)

/**
    The requested value is undefined in #POM_ask_env_info.
    Set this value if required.
*/
#define POM_no_current_value_set            (POM_error_base + 163)

/**
    The user is already a member of the given group.
    Avoid redundant call.
*/
#define POM_user_already_in_group           (POM_error_base + 164)

/**
    Attempt to enable logins when already enabled.
    Check whether logins are already enabled via #POM_ask_logins.
*/
#define POM_logins_not_disabled             (POM_error_base + 165)

/**
    The database is full.
    Extend the DB size (see DB specific manuals) or delete or archive some data in the DB.
*/
#define POM_database_full                   (POM_error_base + 166)

/**
    The DB is being installed, but there a POM already there.
    Check environment variable/logical TC_DB_CONNECT.
*/
#define POM_installed                       (POM_error_base + 167)

/**
    Can't get the schema path from POM_SCHEMA or pom_root.
    Check that the schema file is at the correct location
    (as located via environment variable/logical POM_SCHEMA or,
    if not set, the last know location written).
*/
#define POM_find_schema_failed              (POM_error_base + 168)

/**
    Can't fopen (read) the schema file.
    Check the operating system access controls on the POM_SCHEMA file.
*/
#define POM_open_schema_failed              (POM_error_base + 169)

/**
    OM_read failed - corrupt or alien format schema.
    Check the POM_SCHEMA environment variable/logical refers to a schema file.
*/
#define POM_read_schema_failed              (POM_error_base + 170)

/**
    Eim not installed yet
*/
#define POM_invalid_site_id                 (POM_error_base + 171)

/**
    During install, POM_SCHEMA environment variable/logical was not set.
    Set POM_SCHEMA to a writeable location for the install to generate the schema file at.
    This should also be visible (read access) for all potential users.
*/
#define POM_no_schema_path                  (POM_error_base + 172)

/**
    POM_SCHEMA points at existing schema during virgin install.
    Set POM_SCHEMA to refer to a location where there is not already a schema file.
    The presence implies an attempt to overwrite an existing schema file,
    possibly from another DB.
*/
#define POM_schema_exists                   (POM_error_base + 173)

/**
    Table pom_root missing (and not running in install) - or site id table missing.
    Check environment variable/logical TC_DB_CONNECT refers to an installed site.
*/
#define POM_not_installed                   (POM_error_base + 174)

/**
    Oracle server connect failed (server down, orasrv down, network problem,
    TC_DB_CONNECT environment variable wrong, etc.).
*/
#define POM_db_connect_fail                 (POM_error_base + 175)

/**
    Startup failed to record startup in the log manager.
    Check that the log files were writable.
*/
#define POM_lm_error                        (POM_error_base + 176)

/**
    Attempt to access remote/archived instance.
    Import/restore the instance.
*/
#define POM_inst_not_local                  (POM_error_base + 177)

/**
    Some problem found during the first stage of install.
    An existing (non-POM) table has used a name we require or the table create failed for some other reason.
    Please report this error with system log/journal file.
    There may be a name clash with an existing third party application installed on the DB.
*/
#define POM_install_halt                    (POM_error_base + 178)

/**
    Some error during a POM verification request.
    Data dictionary for POM may be corrupt,
    please report this error with system log/journal file.
*/
#define POM_verification                    (POM_error_base + 179)

/**
    Tag specified for 'file' is not a valid file tag.
    Create or read a file to obtain a file tag.
*/
#define POM_invalid_file_tag                (POM_error_base + 180)

/**
    The file may not be modified. Cannot modify a file that has been read.
    Obtain a new file tag via #POM_create_file.
    @note The existing read file may be overwritten (operating system access controls allowing)
    and the original instances be added to the new file.
*/
#define POM_file_is_read_only               (POM_error_base + 181)

/**
    Could not find the operating system file named.
    Check the file exists in the operating system.
*/
#define POM_file_does_not_exist             (POM_error_base + 182)

/**
    Unable to read the operating system file named.
    Check that the operating system allows you read access on the given file.
*/
#define POM_cannot_read_file                (POM_error_base + 183)

/**
    File was not written by POM_write_file(). Could be a schema file.
    Check that the file was written as an export/archive.
*/
#define POM_invalid_file_format             (POM_error_base + 184)

/**
    File contains classes that do not exist at this site.
    Ensure that the schema at the local and sending site are
    installed with the same classes/versions of software.
*/
#define POM_file_has_different_schema       (POM_error_base + 185)

/**
    Prevented from writing the operating system file.
    Check that the operating system allows you write access
    to that given directory and the existing file.
*/
#define POM_cannot_write_file               (POM_error_base + 186)

/**
    Specified instance does not exist within the file.
    Check the contents of the file via #POM_file_ask_contents.
*/
#define POM_instance_not_in_file            (POM_error_base + 187)

/**
    The file destination has not been set (or is set to the local site).
    Correct the destination site via #POM_file_set_destination.
*/
#define POM_destination_not_set             (POM_error_base + 188)

/**
    Some data has already been recorded for that instance/class combination.
*/
#define POM_data_already_stored             (POM_error_base + 189)

/**
    No data has been stored for that instance/class combination.
    No data was recorded for the instance/class combination prior to writing the file.
*/
#define POM_no_data_stored                  (POM_error_base + 190)

/**
    Cannot read this file since it was written by a newer (or possibly too old) version of POM
    Check the version of the file (supplied by #POM_read_file) against the POM version
    (see trace file header).
*/
#define POM_bad_file_version                (POM_error_base + 191)

/**
    Failed to open schema for write. Check that the file is indeed an export file.
*/
#define POM_file_open_error                 (POM_error_base + 192)

/**
    This object is a (local) copy of an object that is really
    stored at another site (or in a backup/archive file)
    This operation cannot be performed on a local copy of the data.
    Import the master copy to this site first.
*/
#define POM_inst_is_cached_copy             (POM_error_base + 193)

/**
    The TC_DB_CONNECT environment variable/logical is not set.
    Set TC_DB_CONNECT to the appropriate value for the desired site.
*/
#define POM_db_connect_info_unset           (POM_error_base + 194)

/**
    The view referred to was not known to the DB.
    Check existence of view.
*/
#define POM_no_such_view                    (POM_error_base + 195)

/**
    The user aborted the current operation.
*/
#define POM_user_quit                       (POM_error_base + 196)

/**
    The instance specified is not locked for modify by any other current sessions.
*/
#define POM_inst_not_in_use                 (POM_error_base + 197)

/**
    The schema required to load the POM object file could not be located.
    Make sure the TC_TRANSMIT_DIR environment variable is set correctly,
    and that a transmit file exists for the site/schema version
*/
#define POM_cant_find_schema_version        (POM_error_base + 198)

/**
    The transmit directory schema required to load the POM object file could not be located.
    Make sure the TC_TRANSMIT_DIR environment variable is set correctly.
*/
#define POM_transmit_dir_not_set            (POM_error_base + 199)

/**
    Could not write a transmit file for schema evolution.
    Make sure the TC_TRANSMIT_DIR environment variable is set correctly
    (specifically to refer to a writeable directory,
    in which the current transmit file has not already been written - see system log for details).
*/
#define POM_cant_write_transmit_file        (POM_error_base + 200)

/**
    Could not read object file due to bad format.
    The file was exported prior to V3.2.
*/
#define POM_bad_file_format                 (POM_error_base + 201)

/**
    The class of the given tag is not in the local DB schema.
    Thus the reference is a stub from an imported instance that referenced data only available at that site.
    To be able to find the class of that data look at the stub (POM_stub) this contains the class textually.
    If the class is created then basic functions such as class of instance will be able to give the correct info.
    To be able to load the data requires importing that object from the remote site.
*/
#define POM_class_is_remote                 (POM_error_base + 202)

/**
    The file has already been loaded in this session.
    Unload the file, if you want to read it again. Otherwise use the already loaded file.
*/
#define POM_file_already_loaded             (POM_error_base + 203)

/**
    A POM_scan is currently in progress
    Complete the existing scan before attempting a second one
*/
#define POM_already_scanning                (POM_error_base + 204)

/**
    A POM_scan is not currently in progress
    This error is used to signal that a scan has just completed,
    otherwise it implies that either no scan has been started or
    a scan of a class with no instances has been requested.
*/
#define POM_not_scanning                    (POM_error_base + 205)

/**
    The current POM_scan has a different name from the one supplied
    Complete the original scan before starting on the new one.
*/
#define POM_scan_wrong_name                 (POM_error_base + 206)

/**
    There is no space left on the file system you are attempting to write to.
    This may be from export, archive or schema write.
    Choose an alternative file system with sufficient space.
*/
#define POM_disk_full                       (POM_error_base + 207)

/**
    The operating system access control on the directory in
    which you are attempting to write a file cannot be opened.
    Run the program as an operating system user with sufficient
    privilege to write to the given directory,
    or choose another directory to which you do have access.
*/
#define POM_os_access_denied                (POM_error_base + 208)

/**
    There has been some unexpected failure in the RDBMS.
    i.e. something other than DB full, connect failed, etc.
    This may be a result of configuration issues
    (offline tablespace or insufficient rollback space).
    In severe cases this may be due to a real problem in the DB or env.
    See the trace file for information on the DB error -
    for Oracle these typically start ORA-xxxx followed by some explanatory text.
*/
#define POM_rdbms_error                     (POM_error_base + 209)

/**
    The ownership could not be reset upon import.
    Either the original owner does not exist at this site/anymore
    (and no option to default has been set)
    or the ownership given as a mapping could not be used.
    There are several options that can be set via #POM_set_env_info.
    These allow one of four modes to be used upon import.

    First: you can always reset the ownership to a given user/group.

    Second: you can use that same ownership only when the original ownership cannot be maintained.

    Third: you can default to the current login user/group.

    And lastly: you can assert that this code be raised if the original ownership cannot be maintained.

    Which ever one you picked, if it caused this error, try again with one of the other more forgiving modes.
*/
#define POM_import_ownership                (POM_error_base + 210)

/**
    The API has been disabled; this error will be returned from all POM calls until it has been re-enabled.
    Call #POM_set_env_info to reset the #POM_disable_api state.
*/
#define POM_api_disabled                    (POM_error_base + 211)

/**
    An unsaved instance cannot be added to an export file.
    There may be edits, such as location,
    which could result in an instance becoming modifiable at two sites simultaneously.
    This also ensures that the snapshot of the instance is taken when
    it is in a consistent state and thus more likely to be usable upon import.
    Save any edits before exporting the instance.
*/
#define POM_unsaved_unexportable            (POM_error_base + 212)

/**
    An operation was attempted upon a given instance during the delete of same.
    Some operations, such as refresh, are not allowed during this sensitive operation.
    Others, such as asking the attributes are fine.
    Avoid operations on the instance that would affect its state with respect to locking.
*/
#define POM_bad_op_during_delete            (POM_error_base + 213)

/**
    Attempt to transfer an instance when the files destination implies an archive is being done.
    Only transfer when moving data between sites.
*/
#define POM_transfer_not_allowed            (POM_error_base + 214)

/**
    The operation attempted is blocked by the existence of another process logged in.
    Check that there are no dead processes (clearlocks) or
    that everyone logs out until the operation is completed.
*/
#define POM_process_blocks_op               (POM_error_base + 215)

/**
    The attempt to acknowledge an error code that represents a case that should always keep a log -
    such as internal error. Only acknowledge expected errors.
    Some, such as internal error, may be recoverable,
    but should be reported and will result in the log being kept. Even if acknowledged.
*/
#define POM_cannot_acknowledge_error        (POM_error_base + 216)

/**
    The attempt to acknowledge an error failed because either there has been no POM error,
    or the last error (ERROR) was not a POM error,
    or the error code you want to acknowledge was not the last POM error.
    Check that the error being ack'd came from a POM call.
*/
#define POM_acknowledge_error_failed        (POM_error_base + 217)

/**
    Pattern or name given matches more than one group.
    Check that the pattern or name is correct.
*/
#define POM_ambiguous_group                 (POM_error_base + 218)

/**
    You may not attempt to create a cyclic group structure
    (for example, one where "a" is "b"'s parent and "b" is "a"'s parent).
    Check that you are trying to create the group structure that you intended to create.
*/
#define POM_group_cycles_not_allowed        (POM_error_base + 219)

/**
    You are trying to convert a string to a numeric value, example, to_number(attr).
    Check that attr does not hold value that are non numeric.
*/
#define POM_invalid_number                  (POM_error_base + 220)

/**
    You are trying to manilupate an object locked by a process that does not exit,
    Some one has run clearlocks under your feet. Close the session and run clearlock -verbose.
*/
#define POM_invalid_process                 (POM_error_base + 221)

/**
    You are trying to define an index on attribute(s) that are already indexed,
    Drop the index and rerun the upgrade again.
*/
#define POM_duplicate_index                 (POM_error_base + 222)

/**
    Your POM_SCHEMA file does not correspond to your database
    Either find the correct file or run install -regen_schema_file to build a correct schema file
*/
#define POM_schema_file_mismatch            (POM_error_base + 223)

/* <TPD> 24-Mar-2010 PR6317380 Remove APB.
   POM_data_modified is an error code possibly previously used for APB.
   Since the variable is not named for an APB purpose, we leave it in.
 */
/**
    APB cannot optimize part loading on structures that have been modified
    Calling code should revert to the traditional loading method

*/
#define POM_data_modified                   (POM_error_base + 224)

/**
    User password authentication exit requires a key/secret pair to validate the exits implementation.
    The exit must be able to produce the secret from the supplied key.
*/
#define POM_no_exit_key_set                 (POM_error_base + 225)

/**
    User password authentication exit failed validation check.
    The exit must be able to produce the secret from the supplied key.
*/
#define POM_bad_pass_exit                   (POM_error_base + 226)

/**
    User password authentication exit failed.
    The exit raised an error - see syslog for details.
*/
#define POM_pass_exit_failure               (POM_error_base + 227)

/**
    DB server procedure raised an error.
    Possibly due to argument mismatch between caller and server code.
    Or server procedure failed to compile.
    Check the system log for the DB specific error code raised.
*/
#define POM_db_procedure_error              (POM_error_base + 228)

/**
    Some one is already editing the schema.
    Wait until  the schema is editable.
*/
#define POM_schema_not_editable             (POM_error_base + 229)

/**
    An error was reported by the TEXT module.
    Correct the invalid text string being passed to POM, or change the locale to make it a valid string.
*/
#define POM_bad_internationalised_string    (POM_error_base + 230)

/**
    My pm_process_list table entry has vanished.
    Stop running clearlocks asserting that live processes are dead
*/
#define POM_i_am_a_zombie_process           (POM_error_base + 231)

/**
    Usage of a character in a string that is not in the current locale
    Set the correct locale for your character
*/
#define POM_invalid_locale_character        (POM_error_base + 232)

/**
    An attribute type change between transmit and current schema.
    Ensure attributes are defined with common types across sites.
    See syslog for specific attributes involved.
*/
#define POM_unsupported_conversion          (POM_error_base + 233)

/**
    The procedure or package is not usable.
    Check it was installed, and if so that it compiled both package and package body.
*/
#define POM_procedure_not_installed         (POM_error_base + 236)

/**
    User error raised in server side procedure.
    Check syslog and/or use POM_ask_last_procedure_error for more details.
*/
#define POM_procedure_user_exception        (POM_error_base + 237)

/**
    A single sign-on operation failed.
    There is apparently connectivity to the Identity Service so it is likely a system config problem.
    (e.g. Wrong AppID causing token validation failure or some other TcSS configuration error).
*/
#define POM_tcsso_config                    (POM_error_base + 238)

/**
    Trying to modify the database after the session has been set read-only.
    Probably caused by a session losing its database connection and
    then being deleted from the database session records.
    This will be noted in the log file so confirm the cause there.
*/
#define POM_session_set_read_only           (POM_error_base + 239)

/**
    A single sign-on operation failed.
    Check syslog for message from TC SSO library - maybe config
    (e.g. can't contact the SSO service or Engineering application not setup on the service).
*/
#define POM_tcsso_error                     (POM_error_base + 240)

/**
    A single sign-on operation failed.
    The individual User's account has an apparent configuration or status problem.
    (e.g. Active Directory User Account Control Error or UserID not allowed for this AppID).
*/
#define POM_tcsso_user_config               (POM_error_base + 241)

/**
    After calling POM_start_schema_edit you are in "schema edit mode" until you
    call POM_cancel_schema_edits or POM_save_schema_edits.  Whilst in this mode
    calls to POM_save_class are not allowed
*/
#define POM_in_schema_edit_mode             (POM_error_base + 242)

/**
    The SQL statement was cancelled by the user
*/
#define POM_query_cancelled                 (POM_error_base + 243)

/**
    An invalid value was specified for license_level. It must be in the range
    0 ... POM_license_level_max.
*/
#define POM_invalid_license_level           (POM_error_base + 244)

/**
    The number of active Author users (%1$) exceeds the number of purchased licenses (%2$).
*/
#define POM_insufficient_licenses_author    (POM_error_base + 245)

/**
    The number of active Consumer users (%1$) exceeds the number of purchased licenses (%2$).
*/
#define POM_insufficient_licenses_consumer  (POM_error_base + 246)

/**
    New group belongs to a different organization
*/
#define POM_owning_org_different            (POM_error_base + 247)

/**
    New error message for change password when sso is enabled
*/
#define POM_password_implemented_externally (POM_error_base + 248)

/**
    Asking about deferred save objects without calling POM_set_deferred_save first
*/
#define POM_not_in_deferred_save (POM_error_base + 249)

/**
    Calling POM_set_deferred_save twice
*/
#define POM_already_in_deferred_save (POM_error_base + 250)

/**
    The maximum number of SQLs a given ITK call should not execeed.
*/
#define POM_number_of_sql_limit_exceeded (POM_error_base + 251)

/**
    instance is out of sync with it VLA.
*/
#define POM_invalid_instance (POM_error_base + 252)

/**
    instance had been locked, but someone has removed your lock.
*/
#define POM_instance_no_longer_locked (POM_error_base + 253)

/**
    The number of active Occasional Users (%1$) exceeds the number of purchased licenses (%2$).
*/
#define POM_insufficient_licenses_occasional    (POM_error_base + 254)

/**
    The number of active Viewer users (%1$) exceeds the number of purchased licenses (%2$).
*/
#define POM_insufficient_licenses_viewer    (POM_error_base + 255)

/**
    The component id was not found in the recipe table.
*/
#define POM_component_id_not_found    (POM_error_base + 256)

/**
    Invalid cparam mode.
*/
#define POM_invalid_cparam_mode    (POM_error_base + 257)

/**
    No labels defined for label based configuration.
*/
#define POM_no_cparam_label_defined    (POM_error_base + 258)

/**
    Invalid date defined for date based configuration.
*/
#define POM_no_cparam_date_defined    (POM_error_base + 259)

/**
    The instances should be instances of a Versionable class.
*/
#define POM_instance_not_versionable         (POM_error_base + 260)

/**
    One or more instances does not have the label attached.
*/
#define POM_instance_not_labeled           (POM_error_base + 261)

/**
    One of the instances already has this label attached to one
    of its versions.
*/
#define POM_instance_already_labeled       (POM_error_base + 262)

/**
    This instance did not configure to any version on loading
    or enquiry.
*/
#define POM_configured_to_no_version      (POM_error_base + 263)

/**
    This instance configured to a deleted version on loading
    or enquiry.
*/
#define POM_configured_to_deleted_version  (POM_error_base + 264)

/**
    Too many cparam labels defined.
*/
#define POM_cparam_label_limit_exceeded    (POM_error_base + 265)

/**
  The owning class of an typed reference attribute is not versionable.
*/
#define POM_owning_class_not_versionable      (POM_error_base + 266)

/**
  The reference class of typed reference attribute is not versionable.
*/
#define POM_reference_class_not_versionable      (POM_error_base + 267)

/**
    Versioning is not enabled.
*/
#define POM_versioning_not_enabled                 (POM_error_base + 268)

/**
    Versioning cannot be disabled because versionable classes exist in schema.
*/
#define POM_versioning_cannot_be_disabled         (POM_error_base + 269)

/**
    Both the input instances should be either non-versionable or versionable instances.
*/
#define POM_incorrect_instances_for_comparison  (POM_error_base + 270)

/**
    Tag is not a valid cparam.
*/
#define POM_invalid_cparam_tag            (POM_error_base + 271)

/**
    This action is not allowed on instances configured as private versions.
*/
#define POM_private_version               (POM_error_base + 272)

/**
    The operation is not yet supported on versionable class.
*/
#define POM_op_not_supported_versionable_class    (POM_error_base + 273)

/**
    The instance can not be modified (Historical Version/Precise Reference).
*/
#define POM_instance_not_mutable    (POM_error_base + 274)

/**
    You can only undelete a version that is currently deleted.
*/
#define POM_version_not_deleted  (POM_error_base + 275)

/**
    Promote and discard operations are only valid for instances configured as private versions.
*/
#define POM_not_private_version  (POM_error_base + 276)

/**
    It is not permitted to transfer private versions with unsaved modifications.
*/
#define POM_cant_transfer_modified_private  (POM_error_base + 277)

/**
    Multiple private edits can only be transferred if they are all held by the same user.
*/
#define POM_private_versions_of_multiple_users  (POM_error_base + 278)

/**
    Cannot save an instance in public space if it references another instance that exists only in
    private space.
*/
#define POM_inst_references_unpublished  (POM_error_base + 279)

/**
    Cannot transfer a subset of user's private edits if that results in a reference to an instance
    that exists only in another user's private space.
*/
#define POM_partial_transfer_ref_error (POM_error_base + 280)

/**
    Cannot alter user_id of user who is already logged in system.
*/
#define POM_user_already_logged_in (POM_error_base + 281)

/**
    Failed to obtain a database lock on one or more of the input instances, either due to the
    instances having been deleted or because another session has them locked.
*/
#define POM_failed_to_lock (POM_error_base + 282)

/**
    Failed to complete an operation in the time allowed. This implies that either there is
    contention for resources from other users or that the operation has too much work to do.
 */
#define POM_operation_timeout_occurred (POM_error_base + 283)

/**
    Cannot save instances that require an MFK set if key has not been set
*/
#define POM_mfk_required (POM_error_base + 284)

/**
    Cannot validate whether MFK is set
*/
#define POM_unable_to_validate_mfk_set (POM_error_base + 285)

/**
    Underlying column limited by DB platform and cannot accomodate string to max length defined in POM schema.

*/
#define POM_string_overflow (POM_error_base + 286)

/**
    Operation not supported with a cparam that does not configure latest.
*/
#define POM_cparam_not_latest  (POM_error_base + 287)

/**
    The operation is not supported with a non-versionable class.
*/
#define POM_class_not_versionable  (POM_error_base + 288)

/**
    Operation not supported for tags configured by different cparams.
*/
#define POM_mixed_cparams  (POM_error_base + 289)

/**
    Operation not supported with a cparam that does not configure private.
*/
#define POM_cparam_not_private  (POM_error_base + 290)

/**
    Error inside a callback function called from POM.
*/
#define POM_error_in_callback_function  (POM_error_base + 291)

/**
    The attribute "%1$" cannot be deleted since it has combined index "%2$" with other attributes of class "%3$".
*/
#define POM_attr_having_combined_index (POM_error_base + 292)

/**
    The scope attribute cannot be changed once it is initially set.
*/
#define POM_scope_already_set    (POM_error_base + 293)

/**
    The scope attribute cannot be changed in a private version.
*/
#define POM_scope_private_not_supported    (POM_error_base + 294)

/**
    Attaching a label to a latest version is not supported.
*/
#define POM_label_on_latest_not_supported    (POM_error_base + 295)

/**
    Promote to history is only valid for instances configured as public latest versions.
*/
#define POM_promote_to_history_requires_public_latest_version  (POM_error_base + 296)

/**
    The operation failed because it tried to create a stub reference from an attribute flagged as not allowed to reference a stub.
*/
#define POM_no_stub_ref_saved    (POM_error_base + 297)

/**
    The object cannot be locked for update or modification, because it has not been deep-copied after being checked-out. Please perform a deep copy using AOM_refresh first, and try again.
*/
#define POM_deepcopy_required_before_modify    (POM_error_base + 298)

/**
    The retrieval of the version data for the "Export" operation is not done, because the Last Export
    Dates (LED) for the provided latest history versions are not consistent with the versions of the
    same object.
*/
#define POM_inconsistent_led_provided    (POM_error_base + 299)

/**
    The patch-up information required at the importing site is missing from the blackbox,
    possibly due to the purge operation at the exporting site.
*/
#define POM_patchup_missing    (POM_error_base + 300)

/**
    The "Import" operation is not done, because the latest version to be imported is older
    than the existing latest version.
*/
#define POM_import_old_latest_failed   (POM_error_base + 301)

/**
    The "Import" operation is not done, because the latest historical or historical version to be imported
    for the object "%1$" is older than the existing latest historical or historical version.
*/
#define POM_import_old_history_failed   (POM_error_base + 302)

/**
    The "Import" operation is not done, because the existing latest version for the object "%1" is older than
    the importing latest historical or historical version.
*/
#define POM_import_latest_out_of_date   (POM_error_base + 303)

/**
    An attempt was made to access the remote or archived version of the object "%1$".
    Please import or restore the version of the object first.
*/
#define POM_version_not_local          (POM_error_base + 304)

/**
    The operation has failed due to the presence of unsaved instances.
*/
#define POM_failed_due_to_unsaved_instances   (POM_error_base + 305)

/**
    The number of active users (%1$) exceeds the number of purchased licenses (%2$).
*/
#define POM_insufficient_licenses_user (POM_error_base + 306)

/**
    The number of active administrative users (%1$) exceeds the number of purchased licenses (%2$).
*/
#define POM_insufficient_licenses_admin (POM_error_base + 307)

/**
    A database table does not exist.
*/
#define POM_table_does_not_exist (POM_error_base + 308)

/**
    No space is defined for space based configuration.
*/
#define POM_no_cparam_space_defined    (POM_error_base + 309)

/**
    The specified object is not a valid Change object.
*/
#define POM_invalid_change_object_tag (POM_error_base + 310)

/**
    Change input to the promote references one or more instances that are not targets of the promote.
    Please refer to the Teamcenter server log file for more detailed information.
*/
#define POM_change_refs_inst_not_in_promote (POM_error_base + 311)

/**
    One or more Change objects reference instances with unsupported configurations. All the
    instances must be configured as "POM_configure_latest" or "POM_configure_history_by_latest".
*/
#define POM_invalid_config_for_change (POM_error_base + 312)

/**
    The tag provided is not a valid extra data tag.
*/
#define POM_invalid_extra_data_tag    (POM_error_base + 313)

/**
    Duplicate keys are found in the extra data map.
*/
#define POM_cparam_extra_data_duplicate_keys    (POM_error_base + 314)

/**
    The "Copy" operation from one exclusive space to another exclusive space is not supported.
*/
#define POM_copy_from_exclusive_to_exclusive (POM_error_base + 315)

/**
    The "Copy" operation has failed, because the target space and the source space contain common instances.
    Please refer to the Teamcenter syslog file for further details.
*/
#define POM_has_conflicts_with_target_space (POM_error_base + 316)

/**
    The "Copy" operation has failed, because the target space and the source space are same.
    Please refer to the Teamcenter syslog file for further details.
*/
#define POM_copy_between_same_spaces (POM_error_base + 317)

/**
    The "Copy" operation has failed, because the target space or source space is empty.
    Please refer to the Teamcenter syslog file for further details.
*/
#define POM_invalid_spaces (POM_error_base + 318)

/**
    The Space "%1$" is not related to the provided configuration parameter (cparam).
*/
#define POM_space_unrelated_to_cparam (POM_error_base + 319 )

/**
    The "Transfer" operation has failed, because the target and source spaces are same.
    Please refer to the Teamcenter syslog file for further details.
*/
#define POM_transfer_between_same_spaces (POM_error_base + 320)

/**
    The instance is locked for deletion.  An instance may not be referenced or loaded
    for read, modification, or deletion when it is locked for deletion by another session.
    If your session has not locked this instance for deletion and there are no other
    active users, the clearlocks program may need to be run (see system administrator).
*/
#define POM_inst_locked_for_delete (POM_error_base + 321)

/**
    If the cycle of a sequence object (Fnd0sequence) is true, the "max_value" must be specified for increasing sequences or the "min_value" must be specified for decreasing sequences.
*/
#define POM_sequence_cycle_requires_minmax (POM_error_base + 322)

/**
  The increment for a sequence object (Fnd0sequence) cannot be zero.
*/
#define POM_sequence_zero_increment (POM_error_base + 323)

/**
   An error has occurred while reading values from a sequence. Please contact the system administrator or refer to the Teamcenter syslog file for more details.
*/
#define POM_sequence_query_error (POM_error_base + 324)

/**
    An external transaction has failed, but may succeed if it is retried. Scenarios that could lead to this error being raised include temporary loss of connection or database deadlocks. Please refer to the Teamcenter syslog file for further details.
*/
#define POM_transaction_retry (POM_error_base + 325)

/**
    An external transaction has failed and is unlikely to succeed if retried. Scenarios that could lead to this error being raised include permanent loss of connection or database full errors. Please refer to the Teamcenter syslog file for further details.
*/
#define POM_transaction_abort (POM_error_base + 326)

/**
    An operation was attempted that relies on the existence of an active transaction. Please refer to the Teamcenter syslog file for further details such as the calling function
*/
#define POM_no_transaction (POM_error_base + 327)

/**
   The requested sequence has reached its minimum or maximum limit. Please contact the system administrator or refer to the Teamcenter syslog file for more details.
*/
#define POM_sequence_limit_reached (POM_error_base + 328)

/**
    User authentication using the Teamcenter database has been disabled.
    Contact your system administrator for additional information.
*/
#define POM_db_user_authentication_disabled (POM_error_base + 329)

/**
   The given space is not valid for sharing.
*/
#define POM_invalid_space_for_sharing (POM_error_base + 330)

/**
   The operation to refer an instance in different space is not allowed by cross-space-reference callback.
*/
#define POM_invalid_cross_space_reference (POM_error_base + 331)

/**
   The callback is already registered. Please refer to the Teamcenter syslog file for further details.
*/
#define POM_callback_is_already_registered (POM_error_base + 332)

/**
   The operation cannot be completed on the given space because it has content.
*/
#define POM_space_not_empty (POM_error_base + 333)

/**
   The given space is already closed.
*/
#define POM_space_is_closed (POM_error_base + 334)

/**
   The operation is supported only for instances edited in space.
*/
#define POM_not_space_version  (POM_error_base + 335)

/**
   The operation is supported only for instances edited in an exclusive space.
*/
#define POM_not_exclusive_space_version    (POM_error_base + 336)

/**
   The operation is supported only for a cparam which shows edits made in the current edit context.
*/
#define POM_edit_context_hidden_by_cparam  (POM_error_base + 337)

/**
   The scope attribute cannot be changed.
*/
#define POM_scope_edit_not_supported       (POM_error_base + 338)

/**
   The black box data is unsupported because it is too old.
*/
#define POM_unsupported_old_black_box_data (POM_error_base + 339)

/**
   The black box data is unsupported because it is too new.
*/
#define POM_unsupported_new_black_box_data (POM_error_base + 340)

/**
   Login is required before accessing data in the requested class "%1$".
*/
#define POM_login_required                 (POM_error_base + 341)

/**
   The change-space is already staged.
*/
#define POM_space_is_staged                (POM_error_base + 342)

/**
   A versionable object cannot be edited in the active POM space.
*/
#define POM_versionable_cannot_be_edited_in_active_space (POM_error_base + 343)

/**
   A recursive cycle is detected while doing tree traversal.
 */
#define POM_recursive_cycle_detected       (POM_error_base + 344)

/**
   The change space is locked.
*/
#define POM_space_is_locked                (POM_error_base + 345)

/**
   The Lock constraint, which does not allow delete lock and reference lock on the same instance, has been violated.
*/
#define POM_lock_constraint_violated       (POM_error_base + 346)

/**
   The POM schema modification or save operations failed because dynamic schema edit mode is enabled. When "POM_regenerate_class_schema_dynamic" is invoked, the dynamic schema edit mode is enabled until an explicit call to stop or logout.
*/
#define POM_in_dynamic_schema_edit_mode    (POM_error_base + 347)

/**
This functionality is already active.  Try deactivating functionality before activating the functionality.
*/
#define POM_functionality_already_active   (POM_error_base + 348)

/**
Upgrade or patching is currently in progress. This and other functionality is not available while upgrade or patching is in progress.
*/
#define POM_upgrade_is_active              (POM_error_base + 349)

/**
The environment variables "TC_XML_ENCODING" and "UGII_UTF8_MODE" have been incorrectly set up for UTF-8 support. The variable "UGII_UTF8_MODE" must be set to "1" and the variable "TC_XML_ENCODING" must be set to "UTF-8".
*/
#define POM_mismatch_utf8_settings         (POM_error_base + 350)

/**
Read expression retry happen
*/
#define POM_read_expression_retry_happen   (POM_error_base + 351)


/**
   The highest error code used.
*/
#define POM_error_ceiling                  (POM_error_base + 351)


/** @} */

#endif
