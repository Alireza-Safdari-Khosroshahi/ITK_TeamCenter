/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file for Access control stuff.
*/

/*  */

#ifndef AM_INCLUDED
#define AM_INCLUDED

/** @if DOX_IGNORE
    (HMK) 4-Sep-1994
    Force cc_check's dependency analysis to always assume
    am.h is needed so it never warns to remove it.
@endif */
#ifdef __lint
    #pragma uginclude needed
#endif

#include <unidefs.h>
#include <pom/am/am_errors.h>

#include <sa/libsa_exports.h>

/**
    @defgroup AM Access Manager (AM)

    For security reasons, each persistent object manipulated by an object manager should have an associated Access Control List (ACL).
    The Access Manager (AM) module is designed to manipulate such lists and has been generalized so that it can deal with
    objects from different modules without incurring too great a performance cost.
    An access control list is a sequenced list of accessor/permission pairings.

    The ITK programmer should avoid using the AM functions to alter the protection of an object directly.
    For example, when you change the protection of a dataset, if it is rev0, both rev0 and the latest version need to be updated.
    If you use the AM call, you must know which version of the dataset needs to be changed.

    The valid accessor types that can appear within an ACL are:

    <ul>
    <li>user
    <li>role + group*
    <li>group
    <li>role
    <li>world access
    </ul>

    These compound accessors are represented by the tag of a "compound accessor" through the AM tag based ITK.
    #POM_delete_accessor and #POM_ask_accessor_instances are provided to manipulate these.

    @note  The creation of accessors is demand driven by find. The only supported generic accessor at present is role in group.
    The AM regards any role possessed by the current user within the current group to be combined with
    current group to provide a list of current "role in group" accessors.

    The importance of these accessor types within an ACL is ordered based upon how discriminating that type is.
    A "user" entry, since it affects a single Teamcenter Engineering user, has a higher "priority" than
    an entry specifying a role or a group. The actual priority ordering is:

    <ol>
    <li>user (highest)
    <li>role + group
    <li>role, group
    <li>world (lowest)
    </ol>

    The access allowed on an object is determined by finding the entry (or entries) in the ACL with the
    highest priority that correspond to the current Teamcenter Engineering user.
    All entries for the same priority are added together to obtain total access allowed to this user.
    Access specified at lower priorities are ignored. If there are no entries that correspond to the current user
    (current group or users roles within that group) then no access is assumed.

    @{
*/

#define AM_acl_name_len       128
#define AM_rule_name_len       32
#define AM_rule_arg_len       128
#define AM_priv_name_len       32
#define AM_named_tag_name_len  32

#define AM_MODE_UNSET          0
#define AM_MODE_ALL_GROUPS     (1 << 0)
#define AM_MODE_RULES          (1 << 1)

#define AM_ACLClassName        "AM_ACL"
#define AM_REASONPropertyName  "reason"

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @name Named ACL Functions
    @{
*/

/**
    Finds the Named ACL with the specified name.
*/
SA_API int AM_find_acl(
    const char*     acl_name,   /**< (I) Name of ACL. */
    tag_t*          acl_id      /**< (O) Tag of ACL. */
    );

/**
    Lists the names of all Named ACLs.
*/
SA_API int AM_list_acls(
    int*        n_acls,     /**< (O) Number of ACLs found. */
    tag_t**     acl_ids     /**< (OF) n_acls Tags of ACLs found. */
    );

/**
    Creates a Named ACL using the specified name.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_create_acl(
    const char*     acl_name,   /**< (I) Name specified to created ACL. */
    tag_t*          acl_id      /**< (O) Tag of ACL to be created. */
    );

/**
    This function can be used to save either a named ACL or an objects ACL.
    When called on a named ACL, it saves any changes made to that ACL.
    When called on an object, it saves any edits to the ACL on the object, and also saves the object itself.

    @note The current user must be a Teamcenter Engineering system administrator to save a named ACL;
    any user can save an object ACL.
*/
SA_API int AM_save_acl(
    tag_t  acl_id   /**< (I) Tag of ACL to be saved. */
    );

/**
    Unloads the specified Named ACL.
*/
SA_API int AM_unload_acl(
    tag_t  acl_id   /**< (I) Tag of ACL to be unloaded. */
    );

/**
    Deletes the specified Named ACL.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_delete_acl(
    tag_t  acl_id   /**< (I) Tag of ACL to be deleted. */
    );

/**
    Sets the name of the specified Named ACL.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_set_acl_name(
    tag_t           acl_id,     /**< (I) Tag of ACL. */
    const char*     acl_name    /**< (I) New name for ACL. */
    );

/**
    Finds the name of the specified Named ACL.
*/
SA_API int AM_ask_acl_name(
    tag_t       acl_id,     /**< (I) */
    char**      acl_name    /**< (OF) Name of ACL. */
    );

/**
    Finds the display name of the specified Named ACL.
*/
SA_API int AM_ask_acl_display_name(
    tag_t       acl_id,             /**< (I) */
    char**      acl_display_name    /**< (OF) Display Name of ACL. */
    );

SA_API int AM_set_default_acl_flag(
    tag_t  acl_id   /**< (I) */
    );

SA_API int AM_set_acl_flag(
    tag_t           acl_id,     /**< (I) */
    const char*     acl_flag    /**< (I) */
    );

SA_API int AM_ask_acl_flag(
    tag_t  acl_id,      /**< (I) */
    char** acl_flag     /**< (OF) */
    );

SA_API int AM_list_acls_by_type(
    int*            n_acls,     /**< (O) */
    tag_t**         acl_ids,    /**< (OF) n_acls */
    const char*     acl_flag    /**< (I) */
    );

/** @} */

/**
    @name Access Control Entry Functions
    @{
*/

/**
    List all accessors that have one or more privileges granted or revoked within the specified Named ACL.
*/
SA_API int AM_list_accessors(
    tag_t       acl_id,         /**< (I) Tag of ACL. */
    int*        n_accessors,    /**< (O) Number of accessors in ACL. */
    tag_t**     accessors       /**< (OF) n_accessors Tags of accessors. */
    );

/**
    Edits the specified Named ACL or object ACL, granting the specified privilege to the specified accessor.
    If the accessor previously had no privileges granted or revoked within the ACL,
    the accessor is added to the list of accessors within the ACL.

    @note You should save any edits to an ACL by calling #AM_save_acl as follows:

    If you are editing an object ACL, call #AM_save_acl on the object whose ACL has been edited.

    If you are editing a named ACL, call #AM_save_acl on the named ACL itself.
*/
SA_API int AM_grant_privilege(
    tag_t  acl_id,          /**< (I) Tag of ACL. */
    tag_t  accessor_id,     /**< (I) Tag of accessor. */
    tag_t  privilege        /**< (I) Tag of privilege. */
    );

/**
    Edits the specified Named ACL or object ACL, revoking the specified privilege for the specified accessor.
    If the accessor previously had no privileges granted or revoked within the ACL,
    the accessor is added to the list of accessors within the ACL.

    @note You should save any edits to an ACL by calling #AM_save_acl as follows:

    If you are editing an object ACL, call #AM_save_acl on the object whose ACL has been edited.

    If you are editing a named ACL, call #AM_save_acl on the named ACL itself.
*/
SA_API int AM_revoke_privilege(
    tag_t  acl_id,          /**< (I) Tag of ACL. */
    tag_t  accessor_id,     /**< (I) Tag of accessor. */
    tag_t  privilege        /**< (I) Tag of privilege. */
    );

/**
    Edits the specified Named ACL or object ACL, un-setting the specified privilege for the specified accessor.
    If the accessor has no remaining privileges granted or revoked within the ACL,
    the accessor is removed from the list of accessors within the ACL.

    @note You should save any edits to an ACL by calling #AM_save_acl as follows:

    If you are editing an object ACL, call #AM_save_acl on the object whose ACL has been edited.

    If you are editing a named ACL, call #AM_save_acl on the named ACL itself.
*/
SA_API int AM_unset_privilege(
    tag_t  acl_id,          /**< (I) Tag of ACL. */
    tag_t  accessor_id,     /**< (I) Tag of accessor. */
    tag_t  privilege        /**< (I) Tag of privilege. */
    );

/**
    Lists each privilege that is granted or revoked for the specified accessor in the specified Named ACL.
    Any privilege that is neither listed as granted nor as revoked is thus known to be unset.
*/
SA_API int AM_list_accessor_privileges(
    tag_t       acl_id,         /**< (I) Tag of ACL. */
    tag_t       accessor_id,    /**< (I) Tag of accessor. */
    int*        n_granted,      /**< (O) Number of granted privileges. */
    tag_t**     granted,        /**< (OF) n_granted Tags of granted privileges. */
    int*        n_revoked,      /**< (O) Number of revoked privileges. */
    tag_t**     revoked         /**< (OF) n_revoked Tags of revoked privileges. */
    );

/**
    Checks if the current user has the specified privilege on the specified object and also
    evaluates the reason why the privilege is granted or revoked.
    The rule tree is traversed to determine whether the privilege is granted or not.
    The verdict is set to true if the privilege is granted, and to false if the privilege is revoked.

    The path through the rule tree to the node that resulted in the verdict,
    is presented in the form of an array of rules and their arguments.
    Also provided is the Named ACL that resulted in the verdict and the accessor that applied within that ACL.

    The acl and accessor tags are then null and there is one rule/argument returned with value of
    rule = "A.M." and argument = "Object ACL".
*/
SA_API int AM_evaluate_privilege(
    tag_t           object,         /**< (I) Tag of object instance to be checked. */
    const char*     privilege,      /**< (I) Choices are READ,WRITE,DELETE,CHANGE,PROMOTE,DEMOTE,COPY,CHANGE_OWNER,
                                             PUBLISH,SUBSCRIBE,EXPORT,IMPORT,TRANSFER_OUT,TRANSFER_IN,WRITE_ICOS,ASSIGN_TO_PROJECT,
                                             REMOVE_FROM_PROJECT,REMOTE_CICO,UNMANAGE,IP_ADMIN,ITAR_ADMIN,CICO,Administer_ADA_Licenses,
                                             TRANSLATION,MARKUP,BATCH_PRINT,DIGITAL_SIGN,ADD_CONTENT,REMOVE_CONTENT,IP_Classifier,ITAR_Classifier,VOID_DIGITAL_SIGN. */
    logical*        verdict,        /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    int*            n_rules,        /**< (O) Number of rules and arguments. */
    char***         rules,          /**< (OF) n_rules Array containing the names of all rules evaluated to arrive at the verdict. */
    char***         args,           /**< (OF) n_rules Array of arguments for the rules. */
    tag_t*          acl,            /**< (O) Tag of the ACL used to arrive at the verdict. */
    tag_t*          accessor        /**< (O) Tag of the accessor that applied within the ACL. */
    );

/**
    Checks if the current user has the specified privilege on the specified object.
    The rule tree is traversed to determine whether the privilege is granted or not.
    The verdict is set to true if the privilege is granted and to false if the privilege is revoked.

    This function also works on objects with embedded ACLs.
*/
SA_API int AM_check_privilege(
    tag_t           object,     /**< (I) Tag of object instance to be checked. */
    const char*     privilege,  /**< (I) Choices are READ,WRITE,DELETE,CHANGE,PROMOTE,DEMOTE,COPY,CHANGE_OWNER,
                                         PUBLISH,SUBSCRIBE,EXPORT,IMPORT,TRANSFER_OUT,TRANSFER_IN,WRITE_ICOS,ASSIGN_TO_PROJECT,
                                         REMOVE_FROM_PROJECT,REMOTE_CICO,UNMANAGE,IP_ADMIN,ITAR_ADMIN,CICO,Administer_ADA_Licenses,
                                         TRANSLATION,MARKUP,BATCH_PRINT,DIGITAL_SIGN,ADD_CONTENT,REMOVE_CONTENT,IP_Classifier,ITAR_Classifier,VOID_DIGITAL_SIGN. */
    logical*        verdict     /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    );

/**
    Checks if the specified user has the specified privilege on the specified object.
    The rule tree is traversed to determine whether the privilege is granted or not.
    The verdict is set to true if the privilege is granted and to false if the privilege is revoked.

    Note that the union of all the user's groups and roles is used and if the user is granted
    the privilege via any of these groups or roles, the verdict is specified as true.
*/
SA_API int AM_check_users_privilege(
    tag_t           user,           /**< (I) Tag of user. */
    tag_t           object,         /**< (I) Tag of object instance to be checked. */
    const char*     privilege,      /**< (I) Choices are READ,WRITE,DELETE,CHANGE,PROMOTE,DEMOTE,COPY,CHANGE_OWNER,
                                             PUBLISH,SUBSCRIBE,EXPORT,IMPORT,TRANSFER_OUT,TRANSFER_IN,WRITE_ICOS,ASSIGN_TO_PROJECT,
                                             REMOVE_FROM_PROJECT,REMOTE_CICO,UNMANAGE,IP_ADMIN,ITAR_ADMIN,CICO,Administer_ADA_Licenses,
                                             TRANSLATION,MARKUP,BATCH_PRINT,DIGITAL_SIGN,ADD_CONTENT,REMOVE_CONTENT,IP_Classifier,ITAR_Classifier,VOID_DIGITAL_SIGN. */
    logical*        verdict         /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    );

/**
    Checks if the specified user has the specified privilege on the specified object.
    The rule tree is traversed to determine whether the privilege is granted or not.
    The verdict is set to true if the privilege is granted and to false if the privilege is revoked.

    Note that the union of all the user's groups and roles is used and if the user is granted
    the privilege via any of these groups or roles, the verdict is specified as true.
*/
SA_API int AM_evaluate_users_privilege(
    tag_t           user,           /**< (I) Tag of user. */
    tag_t           object,         /**< (I) Tag of object instance to be checked. */
    const char*     privilege,      /**< (I) Choices are READ,WRITE,DELETE,CHANGE,PROMOTE,DEMOTE,COPY,CHANGE_OWNER,
                                             PUBLISH,SUBSCRIBE,EXPORT,IMPORT,TRANSFER_OUT,TRANSFER_IN,WRITE_ICOS,ASSIGN_TO_PROJECT,
                                             REMOVE_FROM_PROJECT,REMOTE_CICO,UNMANAGE,IP_ADMIN,ITAR_ADMIN,CICO,Administer_ADA_Licenses,
                                             TRANSLATION,MARKUP,BATCH_PRINT,DIGITAL_SIGN,ADD_CONTENT,REMOVE_CONTENT,IP_Classifier,ITAR_Classifier,VOID_DIGITAL_SIGN. */
    logical*        verdict,        /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    int*            n_rules,        /**< (O) Number of rules and arguments. */
    char***         rules,          /**< (OF) n_rules Array containing the names of all rules evaluated to arrive at the verdict. */
    char***         args,           /**< (OF) n_rules Array of arguments for the rules. */
    tag_t*          acl,            /**< (O) Tag of the ACL used to arrive at the verdict. */
    tag_t*          accessor        /**< (O) Tag of the accessor that applied within the ACL. */
    );

/**
    Checks if the given set of accessors has the specified privilege on the specified object.
    <br/>Accessor is a combination of user, groups, roles, etc.
    <br/>The rule tree is traversed to determine whether the privilege is granted or not.
    <br/>The verdict is set to true if the privilege is granted and to false if the privilege is revoked.
 @returns
    <ul>
    <li>#ITK_ok on success</li>
    <li>#AM_invalid_tag if any of the given tags is invalid.</li>
    <li>#AM_name_not_found if an invalid @p privilege is specified</li>
    </ul>
*/
SA_API int AM_evaluate_accessors_privilege(
    int             n_accessors,    /**< (I) Number of accessors. */
    const tag_t*    accessors,      /**< (I) n_accessors Array containing the tags of the accessors. */
    tag_t           object,         /**< (I) Tag of object instance to be checked. */
    const char*     privilege,      /**< (I) Choices are READ, WRITE, DELETE, CHANGE, PROMOTE, DEMOTE, COPY,
                                            IMPORT, EXPORT, TRANSFER_IN and TRANSFER_OUT. */
    logical*        verdict,        /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    int*            n_rules,        /**< (O) Number of rules and arguments. */
    char***         rules,          /**< (OF) n_rules Array containing the names of all rules evaluated to arrive at the verdict. 
                                              <br>The array is packed. */
    char***         args,           /**< (OF) n_rules Array of arguments for the rules.  
                                              <br>The array is packed. */
    tag_t*          acl,            /**< (O) Tag of the ACL used to arrive at the verdict. */
    tag_t*          accessor        /**< (O) Tag of the accessor that applied within the ACL. */
    );

/** @} */

/**
    @name Utility Functions
    @{
*/

/**
    Evaluates and returns the effective ACL on the specified object.

    In effect this function uses the rule tree to build up a compound ACL that describes
    the combined effect on the object of the ACLs in the rule tree.
*/
SA_API int AM_get_effective_acl(
    tag_t  object,          /**< (I) Tag of the object. */
    tag_t* eff_acl_tag,     /**< (O) Tag of the object's effective ACL. */
    int*   length           /**< (O) Number of entries in the effective ACL. */
    );

/**
    Returns details of an entry in the specified effective ACL.
    Both the tag of the accessor and lists of granted and revoked privileges are found for the entry with specified index.
*/
SA_API int AM_effective_acl_line(
    tag_t       eff_acl_tag,    /**< (I) Tag of the effective ACL. */
    int         index,          /**< (I) Index of the required ACL entry. */
    tag_t*      source_acl,     /**< (O) */
    tag_t*      accessor,       /**< (O) Tag of the accessor. */
    int*        n_granted,      /**< (O) Number of granted privileges. */
    tag_t**     granted,        /**< (OF) n_granted Tags of granted privileges. */
    int*        n_revoked,      /**< (O) Number of revoked privileges. */
    tag_t**     revoked         /**< (OF) n_revoked Tags of revoked privileges. */
    );

/**
    Frees the information stored for an effective ACL.

    Any call to #AM_get_effective_acl should be followed eventually
    with a call to this routine, as the memory is then freed.
*/
SA_API int AM_free_effective_acl(
    tag_t  eff_acl_tag      /**< (I) Tag of the object's effective ACL. */
    );

/**
 * Retrieves the cumulative read expression by concatenating the given read expressions into one string.
 *  
 * @returns
 * <ul>
 * <li>#ITK_ok always as there is no business logic involved apart from concatenating the given read expressions into one combined read expression.
 * </ul>
 */
SA_API int AM_get_combined_read_expression( 
    int     count,                  /**< (I)  Number of read expressions. */  
    const char**  read_expressions, /**< (I)  count Read expressions. */ 
    char**  cumulative_re           /**< (OF) Cumulative read expression.  */  
    );

/**
    Retrieves the read expressions for the requested objects.
    <br/><br/>Read expressions are abstracts of access rules that influence the "READ" privilege
    on objects. 
    <br/>A read expression contains unresolved session dependent information, and therefore 
    it will need to be resolved based on the given session information in order to derive the 
    "READ" privilege on the object.
    <br/>Read expressions are used to enforce security on Teamcenter objects in external clients 
    outside Teamcenter.
    <br/>For each entry in the input "objs" array, the matching read expression is returned 
    in the "read_expressions" array.
    <br/>If a tag is invalid, its associated read expressions will be empty and the ITK
    will proceed with the remaining tags. 
    <br/><br/>Session information from the AM_ask_session_info API will be used while 
    evaluating the read expressions at the external system. Session values for a given 
    term in read expression will be identified using the session information key in the term.
    Session values and the values in the read expressions are compared using the 
    comparison operator in the read expression term to derive the READ privilege.
    <br/><br/>A sample term in read expression looks like this: CAAval1,val2,val3+
    <br/>Where:
    <ul>
    <li>C : Comparison operator. First character in the term is always comparison operator.</li>
    <li>AA: Session information key. Session information key is always 2 characters length.
    <br/>This key is used to find the session information for the term.</li>
    <li>val1,val2,val3: Set of values which will be compared with corresponding session values
    using the comparison operator.</li>
    <li>+: Is the verdict for the READ privilege. + indicates the privilege is granted. - indicates the privilege is denied.</li>
    </ul> 
 @returns
    <ul>
    <li>#ITK_ok on success</li>
    <li>#AM_invalid_tag if any of the given tags is invalid.</li>
    </ul>
*/
SA_API int AM_ask_read_expressions(
    int         count,           /**< (I) Number of objects. */
    const tag_t*      objs,            /**< (I) count Array of input object tags. */
    char***     read_expressions /**< (OF) count Array of read expressions for the requested objects. This parameter is a packed array. Only call #MEM_free on the container, not its elements */
    );

/**
    Retrieves user session information in the form of key/value pairs.
    <br/><br/>For each entry in the keys array, the corresponding entry 
    in the values array contains the value. 
    <br/>If there are multiple values for a particular kind of session 
    information, the values will be located consecutively in the arrays
    and will each have the same key.
    <br/>Session information is made available to the external clients 
    by the time Read Expressions are evaluated. 
    <br/>Session information is used while evaluating the read expressions
    in external systems to determine the READ access on Teamcenter business objects. 
 @returns
    <ul>
    <li>#ITK_ok all the time.</li>
    </ul>
*/
SA_API int AM_ask_session_info(
    int*        count,          /**< (O)  Count of key/value pairs returned. */
    char***     keys,           /**< (OF) count Array of session information key names. This parameter is a packed array. Only call #MEM_free on the container, not its elements */
    char***     values          /**< (OF) count Array of session information value strings. This parameter is a packed array. Only call #MEM_free on the container, not its elements */
    );

/** @} */

/**
    Checks if the specified Teamcenter Engineering site has the specified privilege on the specified object.
    The rule tree is traversed to determine whether the privilege is granted or not.
    The verdict is set to true if the privilege is granted and to false if the privilege is revoked.
*/
SA_API int AM_check_sites_privilege(
    tag_t           site,           /**< (I) Tag of site. */
    tag_t           object,         /**< (I) Tag of object instance to be checked. */
    const char*     privilege,      /**< (I) Choices are READ, WRITE, DELETE, CHANGE, PROMOTE, DEMOTE,
                                            COPY, IMPORT, EXPORT, TRANSFER_IN and TRANSFER_OUT. */
    logical*        verdict         /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    );

/**
    Checks if the specified vendor contact has the specified privilege on the specified object.
    <br/>The rule tree is traversed to determine whether the privilege is granted or not.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>The same errors as returned by #AM_check_privilege_in_bulk
    </ul> 
*/
SA_API int AM_check_suppliers_privilege_in_bulk (
    tag_t           vendor_contact,        /**< (I) Tag of the vendor contact. */
    int             n_objects,             /**< (I) number of object instances to be checked. */
    tag_t*          objects,               /**< (I) n_objects Array of object instances to be checked. */
    const char*     privilege,             /**< (I) Only READ is supported for Vendor Contact. */
    logical**       verdict                /**< (O) n_objects Array of logical flags specifying whether the privilege is granted or revoked for the corresponding object. */
    );

/**
    Checks if the given set of accessors (combination of user, groups, roles, etc.)
    has the specified privilege on the specified object.
    The rule tree is traversed to determine whether the privilege is granted or not.
    The verdict is set to true if the privilege is granted and to false if the privilege is revoked.
*/
SA_API int AM_check_accessors_privilege(
    int             n_accessors,    /**< (I) Number of accessors. */
    tag_t*          accessors,      /**< (I) n_accessors Array containing the tags of the accessors. */
    tag_t           object,         /**< (I) Tag of object instance to be checked. */
    const char*     privilege,      /**< (I) Choices are READ, WRITE, DELETE, CHANGE, PROMOTE, DEMOTE, COPY,
                                            IMPORT, EXPORT, TRANSFER_IN and TRANSFER_OUT. */
    logical*        verdict         /**< (O) Logical flag specifying whether the privilege is granted or revoked. */
    );

/** 
   Validates if the given set of accessors (combination of user, group, role, etc.) has the specified privilege on the specified objects. 
   <br/>The rule tree is traversed to determine whether the privilege is granted or not. 
   <br/>The verdict is set to true if the privilege is granted otherwise set to false if the privilege is revoked. 
   @returns 
   <ul> 
   <li>#ITK_ok on success</li> 
   <li>#AM_invalid_tag if any member of @p accessors or @p objects is invalid.</li>
   <li>#AM_name_not_found if an invalid @p privilege is specified</li> 
   </ul> 
*/ 
SA_API int AM_check_accessors_privilege_in_bulk(
                                                const unsigned int  n_accessors,    /**< (I) Number of accessors. */
                                                const tag_t*        accessors,      /**< (I) n_accessors Array containing the tags of the accessors. */
                                                const unsigned int  n_objects,      /**< (I) Number of object instances to check privilege for. */
                                                const tag_t*        objects,        /**< (I) n_objects Array of object instances to check privilege for. */
                                                const char*         privilege,      /**< (I) Name of the privilege. Choices are READ, WRITE, DELETE, CHANGE, PROMOTE, DEMOTE, COPY,
                                                                                             IMPORT, EXPORT, TRANSFER_IN and TRANSFER_OUT. */
                                                logical**           decisions       /**< (OF) n_instances Indicates if the privilege is granted or revoked for each object. */
    );

/**
    Removes the specified accessor entry from a Named ACL,
    meaning that all that accessor privileges are now unset within the ACL.
*/
SA_API int AM_remove_accessor(
    tag_t  acl_id,          /**< (I) Tag of ACL. */
    tag_t  accessor_id      /**< (I) Tag of accessor. */
    );

/**
    Removes all entries from a named ACL.
*/
SA_API int AM_clear_acl(
    tag_t  acl_id   /**< (I) Tag of ACL. */
    );

/**
    Removes an accessor from all Named ACLs in which it appears.
    @note Exclusive login is required for this operation.
*/
SA_API int AM_delete_accessor(
    tag_t  accessor_id      /**< (I) Tag of accessor. */
    );

/**
    @name Privilege Functions
    @{
*/

/**
    Finds the privilege with the specified name.
*/
SA_API int AM_find_privilege(
    const char*     name,           /**< (I) Privilege name. */
    tag_t*          privilege_id    /**< (O) Tag of privilege found. */
    );

/**
    Finds the privilege with the specified offset.
*/
SA_API int AM_privilege_of_offset(
    int    offset,          /**< (I) Privilege offset. */
    tag_t* privilege_id     /**< (O) Tag of privilege found. */
    );

/**
    Lists all defined privileges.
*/
SA_API int AM_list_privileges(
    int*        n_privileges,       /**< (O) Number of privileges. */
    tag_t**     privilege_ids       /**< (OF) n_privileges Tags of the privileges. */
    );

/**
    Creates a privilege using the specified name.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_create_privilege(
    const char*     privilege_name,     /**< (I) Name for the privilege. */
    tag_t*          privilege_id        /**< (O) Tag of the created privilege. */
    );

/**
    Deletes the specified privilege.
    @note The current user must be a Teamcenter Engineering system administrator.

    @note Exclusive login is required for this operation.
*/
SA_API int AM_delete_privilege(
    tag_t  privilege_id     /**< (I) Tag of the privilege. */
    );

/**
    Finds the name of the specified privilege.
*/
SA_API int AM_ask_priv_name(
    tag_t  privilege_id,    /**< (I) Tag of the privilege. */
    char** privilege_name   /**< (OF) Name of the privilege. */
    );

/**
    Sets the name of the specified privilege.
*/
SA_API int AM_set_priv_name(
    tag_t           privilege_id,       /**< (I) Tag of the privilege. */
    const char*     privilege_name      /**< (I) New name of the privilege. */
    );

/**
    Finds the offset of the specified privilege.
*/
SA_API int AM_ask_priv_offset(
    tag_t  privilege_id,    /**< (I) Tag of the privilege. */
    int*   offset           /**< (O) Offset of the privilege. */
    );

/** @} */

/**
    @name Named Tag Functions
    @{
*/

/**
    Finds the named tag with the specified name.
*/
SA_API int AM_find_named_tag(
    const char*     named_tag_name,     /**< (I) Name of the named tag. */
    tag_t*          named_tag_id        /**< (O) Tag of the named tag. */
    );

/**
    Creates a named tag using the specified name.
*/
SA_API int AM_create_named_tag(
    const char*     named_tag_name,     /**< (I) Name given to created named tag. */
    tag_t*          named_tag_id        /**< (O) Tag of created named tag. */
    );

/**
    Deletes the specified named tag.
*/
SA_API int AM_delete_named_tag(
    tag_t  named_tag_id     /**< (I) Tag of named tag to be deleted. */
    );

/**
    Finds the name of the specified named tag.
*/
SA_API int AM_ask_named_tag_name(
    tag_t  named_tag_id,        /**< (I) Tag of the named tag. */
    char** named_tag_name       /**< (OF) Name of the named tag. */
    );

/**
    Sets the name of the specified named tag.
*/
SA_API int AM_set_named_tag_name(
    tag_t           named_tag_id,       /**< (I) Tag of the named tag. */
    const char*     named_tag_name      /**< (I) New name of the named tag. */
    );

/**
    Lists the names of all named tags.
*/
SA_API int AM_list_named_tags(
    int*        n_named_tags,   /**< (O) Number of named tags found. */
    tag_t**     named_tags      /**< (OF) n_named_tags Tags of named tags found. */
    );

/** @} */

/**
    @name Rule Tree Functions
    @{
*/

/**
    Finds the root of the rules tree. If the rules tree is empty, #NULLTAG is returned for the root.
*/
SA_API int AM_node_ask_root(
    tag_t* root     /**< (O) Tag of the root node of the rules tree. */
    );

/**
    Finds the parent of the specified node in the rules tree.
*/
SA_API int AM_node_ask_parent(
    tag_t  node,    /**< (I) Tag of the child rule node. */
    tag_t* parent   /**< (O) Tag of the parent rule node. */
    );

/**
    Finds the children of the specified node in the rules tree.
*/
SA_API int AM_node_ask_children(
    tag_t       node,           /**< (I) Tag of the parent node. */
    int*        no_children,    /**< (O) Number of children found. */
    tag_t**     children        /**< (OF) no_children Tags of the children found. */
    );

/**
    Finds the name of the rule on the specified node in the rules tree.
*/
SA_API int AM_node_ask_rule_name(
    tag_t  node,        /**< (I) Tag of the rule node. */
    char** rule_name    /**< (OF) Name of the rule. */
    );

/**
    Sets the rule on the specified node in the rules tree.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_set_rule_name(
    tag_t           node,       /**< (I) Tag of the rule node. */
    const char*     rule_name   /**< (I) Name of the new rule. */
    );

/**
    Finds the rule argument on the specified node in the rules tree.
*/
SA_API int AM_node_ask_rule_arg(
    tag_t  node,        /**< (I) Tag of the rule node. */
    char** rule_arg     /**< (OF) Argument for the rule. */
    );

/**
    Sets the argument for the rule on the specified node in the rules tree.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_set_rule_arg(
    tag_t           node,       /**< (I) Tag of the rule node. */
    const char*     rule_arg    /**< (I) New argument. for the rule. */
    );

/**
    Finds the Named ACL on the specified node in the rules tree.
*/
SA_API int AM_node_ask_acl(
    tag_t  node,    /**< (I) Tag of the rule node. */
    tag_t* acl      /**< (O) Tag of the Named ACL. */
    );

/**
    Sets the Named ACL on the specified node in the rules tree.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_set_acl(
    tag_t  node,    /**< (I) Tag of the rule node. */
    tag_t  acl      /**< (I) Tag of the new Named ACL. */
    );

SA_API int AM_node_ask_expanded(
    tag_t       node,       /**< (I) */
    logical*    expanded    /**< (O) */
    );

SA_API int AM_node_set_expanded(
    tag_t       node,       /**< (I) */
    logical     expanded    /**< (I) */
    );

SA_API int AM_node_ask_children_editable(
    tag_t       node,       /**< (I) */
    logical*    editable    /**< (O) */
    );

SA_API int AM_node_set_children_editable(
    tag_t       node,       /**< (I) */
    logical     editable    /**< (I) */
    );

/**
    Creates a new node in the rules tree, as a child of the specified parent node and using the
    specified previous node to define its position among its sibling nodes.

    The rule name and argument must be specified. The ACL for the node can also be specified if required.
    If the ACL is specified as #NULLTAG, no ACL will be placed on the node.

    If the parent node is specified as #NULLTAG, an attempt is made to create a new root node.
    This will fail if a root node already exists.

    If the previous node is specified as #NULLTAG,
    the new node is created as the first child of the specified parent.

    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_create_node(
    const char*     rule_name,      /**< (I) Name of the rule for the new node. */
    const char*     rule_arg,       /**< (I) Rule argument for the new node. */
    tag_t           parent,         /**< (I) Parent node for the new node. */
    tag_t           prev,           /**< (I) Previous sibling node for the new node. */
    tag_t           acl,            /**< (I) ACL on the new node. */
    tag_t*          node            /**< (O) Tag of the newly created node. */
    );

/**
    Pastes the specified node into the rules tree, using the specified parent and previous nodes to define its position in the tree.

    The paste will only work if the specified node has previously been cut from the rules tree.

    If the parent node is specified as #NULLTAG, the specified node becomes the root node in the tree.
    This will fail if a root node already exists.

    If the previous node is specified as #NULLTAG, the node is pasted as the first child of the specified parent.

    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_paste(
    tag_t  node,        /**< (I) Tag of the rule node to be pasted. */
    tag_t  parent,      /**< (I) Parent node for the pasted node. */
    tag_t  prev         /**< (I) Previous sibling node for the pasted node. */
    );

/**
    Cuts the specified node from the rules tree. This node can then be pasted somewhere else in the tree.
    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_cut(
    tag_t  node     /**< (I) Tag of the rule node to be cut. */
    );

/**
    Moves the specified node in the rules tree up its list of siblings.
    It has no effect if the node is already the first sibling in the list.

    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_move_up(
    tag_t  node     /**< (I) Tag of the rule node to be moved. */
    );

/**
    Moves the specified node in the rules tree down its list of siblings.
    It has no effect if the node is already the last sibling in the list.

    @note The current user must be a Teamcenter Engineering system administrator.
*/
SA_API int AM_node_move_down(
    tag_t  node     /**< (I) Tag of the rule node to be moved. */
    );

/**
    Saves all changes to the rules tree.
*/
SA_API int AM_save_tree(void);

/**
    Unloads the rules tree from memory. All changes since the last time the tree was saved are lost.
*/
SA_API int AM_unload_tree(void);

SA_API int AM_refresh_tree(void);

SA_API int AM_tree_discard_changes(void);

SA_API int AM_tree_find_nodes(
    tag_t       parent,     /**< (I) */
    char*       ruleName,   /**< (I) */
    char*       ruleArg,    /**< (I) */
    int*        count,      /**< (O) */
    tag_t**     nodes       /**< (OF) count */
    );

/** @} */

/**
    Lists the names of all registered rules.
*/
SA_API int AM_list_rules(
    int*        no_rules,   /**< (O) Number of rules found. */
    char***     rules       /**< (OF) no_rules Names of the rules found. */
    );

/**
    Lists the valid arguments of the specified rule.
*/
SA_API int AM_list_rule_args(
    const char*     rule_name,      /**< (I) Name of the rule. */
    int*            no_args,        /**< (O) Number of arguments found. */
    char***         args            /**< (OF) no_args Names of the arguments found. */
    );

/**
    Checks whether the specified argument is valid for the specified rule,
    using the validate function registered for the rule.
*/
SA_API int AM_validate_rule_arg(
    const char*     rule_name,      /**< (I) Name of the rule. */
    const char*     rule_arg,       /**< (I) Name of the argument. */
    logical*        is_valid        /**< (O) True if the argument is valid. */
    );

/**
    Returns the type and name of the specified accessor. Examples of accessor types are User, Group, etc.
*/
SA_API int AM_accessor_info(
    tag_t  accessor,    /**< (I) Tag of the accessor. */
    char** type,        /**< (OF) Type of the accessor. */
    char** name         /**< (OF) Name of the accessor. */
    );

/**
    Finds the tag of the accessor using the specified accessor type and name.
*/
SA_API int AM_find_accessor(
    const char*     type,   /**< (I) Type of the accessor. */
    const char*     name,   /**< (I) Name of the accessor. */
    tag_t*          acc     /**< (O) Tag of the accessor. */
    );

/**
    Lists all accessors of the specified accessor type.
*/
SA_API int AM_list_accessors_by_type(
    const char*     type,       /**< (I) Type of accessor to find. */
    int*            n_accs,     /**< (O) Number of accessors found. */
    tag_t**         accs        /**< (OF) n_accs Tags of the accessor found. */
    );

/**
    Lists the names of all accessor types.
*/
SA_API int AM_list_accessor_types(
    int*        n_types,    /**< (O) Number of accessor types found. */
    char***     types       /**< (OF) n_types Names of the accessor types found. */
    );

/**
    Lists all accessors in the current POM session context.
    This usually contains the login user plus all his/her groups and roles.
*/
SA_API int AM_list_session_accessors(
    int*        n_accessors,    /**< (O) Number of accessors found. */
    tag_t**     accessors       /**< (OF) n_accessors Tags of the accessor found. */
    );

/**
    Sets the mode of operation for the AM.

    The following modes are available:

    #AM_MODE_ALL_GROUPS - The user gains the benefit of access granted by all groups of which
                          he/she is a member and not just the current group.

    #AM_MODE_UNSET - Neither of the above.

    @note In order to achieve a combination of modes, use the '|' separator (e.g., #AM_MODE_ALL_GROUPS | #AM_MODE_UNSET).
*/
SA_API int AM_set_mode(
    int    mode     /**< (I) Mode of operation for AM. */
    );

/**
    Gives the current mode of operation for the AM.

    In order to decode the mode, use a bitwise comparison with #AM_MODE_ALL_GROUPS.
*/
SA_API int AM_ask_mode(
    int*   mode     /**< (O) Current mode. */
    );

/**
    Sets AM journalling on/off.
*/
SA_API int AM_set_journalling(
    logical     flag    /**< (I) If true, set AM journalling on; if false, set AM journalling off. */
    );

/**
    Initializes the AM module.

    @note The initialization of the module does not install the AM,
    nor does it perform any checks to see if installation is necessary.

    No AM function works if the AM module has not previously been initialized.
    Calls to #AM_init_module can be nested.
*/
SA_API int AM_init_module ( void );

/**
    May make the first check_priv call go faster
*/
SA_API void AM_preload_rule_tree ( void );

/**
    Exits the AM module. This function should not be called more times than #AM_init_module.
*/
SA_API int AM_exit_module ( void );

/**
    Checks if the current user has READ access on the specified list of objects.
    <br>The rule tree is traversed to determine whether READ privilege is granted or not.
    <br>The verdict for each objects is set to true if user has READ access granted and to false if READ access is revoked to the object.
    <br>This function also works on objects with embedded ACLs (Access Control List).
    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_tag if any tag is invalid 
   </ul>
*/
SA_API int AM_check_read_privilege_in_bulk(
    int n_objects,           /**< (I) number of objects to be checked. */
    const tag_t* objects,    /**< (I) List of tags of objects instances to be checked. */
    logical** decisions      /**< (OF) n_objects Array of logical flags specifying whether the privilege is granted or revoked for each object. */
    );

/**
    @name Statistics Functions
    @{
*/

/**
    Log Access Manager statistics to the syslog and optionally clear them.

    @note Accumulation and logging of statistics is enabled by setting the
    AM_PERFORMANCE_STATISTICS environment variable to any value.
*/
SA_API int AM_log_statistics(
    logical     clear   /**< (I) If true, clear statistics after logging them. */
    );

/** @} */

/*<AO><29-Oct-2007> added these for supporting delegation for forms/named references
 */
SA_API int AM_record_object_parent ( int n_tags, tag_t *ref_tag, tag_t parent_tag );
SA_API int AM_remove_parent_from_cache ( int n_tags, tag_t *ref_tag, tag_t parent_tag );
SA_API int AM_record_delegation_classes ( int n_strings, const char **class_names, const char *parent_class );
SA_API int AM_lookup_delegation_class ( const char *class_name, int *cid );

/**
    Checks if the current user has the specified privilege on the specified list of objects.
    <br>The rule tree is traversed to determine whether the privilege is granted or not.
    <br>The verdict is set to true if the privilege is granted and to false if the privilege is revoked.
    <br>This function also works on objects with embedded ACLs (Access Control List).
    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_tag if any tag is invalid
   </ul>
*/
SA_API int AM_check_privilege_in_bulk(
    int n_instances,                   /**< (I) number of objects to be checked. */
    const tag_t* instances,            /**< (I) List of tags of objects instances to be checked. */
    const char* privilege_name,        /**< (I) Choices are READ, WRITE, DELETE, CHANGE, PROMOTE,DEMOTE,COPY, IMPORT, EXPORT, TRANSFER_IN and TRANSFER_OUT. */
    const logical* are_loaded,         /**< (I) Indicates if the objects are already loaded. */
    logical** decisions                /**< (OF) n_instances Array of logical flag specifying whether the privilege is granted or revoked. */
    );


/** @} */

#ifdef __cplusplus
}
#endif
#include <sa/libsa_undef.h>

#endif

