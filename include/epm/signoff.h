/*
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2014
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
==================================================*/

/**
    @file

    This header file contains constants used throughout the Signoff class.
    It also contains the prototypes for the ITK functions for the Signoff class.

    See the ITK manual for more detailed documentation.
*/

/*  */

#ifndef SIGNOFF_H
#define SIGNOFF_H

#include <epm/epm.h>
#include <epm/libepm_exports.h>

/**
    @defgroup SIGNOFF Signoff
    @ingroup EPM

    A Signoff contains the decision and any relevant comments that a user makes for an authorization.
    The user is identified via a group member object,
    because the correct user must play a particular role in the group for which the authorization takes place.
    All of the signoffs for an authorization are collected in a signoff list.

    Signoff is not a subclass of WorkspaceObject, so WSOM functions will not work with signoffs.
    AOM functions work with signoffs.
    @{
*/

/**
    @name Signoff origin

    Indicate where a Signoff object is derived from
    @{
*/
#define SIGNOFF_ORIGIN_PROFILE              0
#define SIGNOFF_ORIGIN_ADHOC_USER           1
#define SIGNOFF_ORIGIN_ADHOC_RESOURCEPOOL   2
#define SIGNOFF_ORIGIN_ALIASLIST            3
#define SIGNOFF_ORIGIN_ADHOC_ALL_RESOURCEPOOL 4
#define SIGNOFF_ORIGIN_UNDEFINED            9999
/** @} */

/** Signoff type */
typedef enum signoff_type_e
{
    SIGNOFF_GROUPMEMBER  = 0,
    SIGNOFF_RESOURCEPOOL = 1,
    SIGNOFF_UNDEFINED = 9999
} SIGNOFF_TYPE_t;


/** Signoff type */
typedef enum signoff_action_e
{
    SIGNOFF_REVIEW  = 1,
    SIGNOFF_ACKNOWLEDGE = 2,
    SIGNOFF_NOTIFY = 3,
    SIGNOFF_ACTION_UNDEFINED = 9999
} SIGNOFF_ACTION_t;

/**
    @name Signoff decision
    @{
*/
#define SIGNOFF_APPROVE_DECISION               "Approve"
#define SIGNOFF_REJECT_DECISION                "Reject"
#define SIGNOFF_NO_DECISION                    "No Decision"
#define SIGNOFF_ACKNOWLEDGED_DECISION          "Acknowledge"
#define SIGNOFF_NOT_ACKNOWLEDGED_DECISION      "Not Acknowledge"
/** @} */

/**
    @name Signoff mandate
    @{
*/
#define SIGNOFF_DECISON_OPTIONAL               "Optional"
#define SIGNOFF_DECISON_REQUIRED_MODIFIABLE    "RequiredModifiable"
#define SIGNOFF_DECISON_REQUIRED_UNMODIFIABLE  "RequiredUnmodifiable"
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif


/**
    This function allocates an array of tags and stores in the array all signoffs in the database.
    The array of tags is pointed to by signoffs. The size of the array is stored in signoff_count.
    The client is responsible for freeing the array of signoffs.
    Use #MEM_free to free the memory pointed to by signoffs.
*/
extern EPM_API int EPM_signoff_extent(
    int*           n_instances,        /**< (O) Number of signoffs */
    tag_t**        instances           /**< (OF) n_instances Array of signoff tags */
    );



/**
    Initializes the signoff attributes for a newly created instance of a subclass of signoff.
*/
extern EPM_API int EPM_initialize_signoff(
    tag_t          signoff,             /**< (I) Signoff to be initialized */
    tag_t          group_member         /**< (I) Group member associated with the signoff */
    );

/**
    Removes specified reviewers from the list of reviewers for the given release level of the given release type.
    If this release level is already started then this must be called before all of the required reviewers have been added.
*/
extern EPM_API int EPM_remove_signoffs(
    tag_t          task_tag,            /**< (I) The review task or the acknowledge task */
    int            n_groupmembers,      /**< (I) Count of group members */
    tag_t*         groupmembers         /**< (I) Group members whose signoffs are to be removed */
    );


/**
    Signoffs can be assigned to GroupMember objects OR ResourcePool objects that have no user tag.
    As this ITK can be used to cycle through the reviewers returned and get decisions etc,
    the release level ITK has been modified to tolerate ResourcePool Objects.
    However in your own code you must not assume you will get a groupmember tag and
    should accommodate the possibility of a ResourcePool tag being returned.
    A common error is that code tries to get the user tag from the returned tag and
    a ResourcePool object has no user tag.
    There is safer ITK to use instead now that is explicit about the type of reviewer assigned to the signoff objects.
    The safer alternative is to get the Signoff object attachments via the #EPM_ask_attachments found in epm.h and
    then ask each Signoff object returned, what type it is via the #EPM_ask_signoff_member found in signoff.h.
    That way you know whether the reviewer is a GroupMember or ResourcePool and make the appropriate subsequent calls.
*/
extern EPM_API int EPM_ask_reviewers(
    tag_t          task_tag,                /**< (I) Workflow task */
    int*           count,                   /**< (O) Count of signoffs obtained */
    tag_t**        groupmembers             /**< (OF) count Group members associated with the signoffs */
    );


/**
    Returns the tag of the resource pool associated with a signoff object.
*/
extern EPM_API int EPM_ask_signoff_resource_pool(
    tag_t          signoff,              /**< (I) Signoff object */
    tag_t*         resource_pool         /**< (O) Resource pool associated with the signoff object */
    );

/**
    This method will only return GroupMember assignments and will not return ResourcePool assignments as they have no user tag.
    It is intended for functionality that needs to skip the ResourcePool signoff assignments,
    such as mail notification.
    The safer alternative is to get the Signoff object attachments via the
    #EPM_ask_attachments found in epm.h and then ask each Signoff object returned,
    what type it is via the #EPM_ask_signoff_member found in signoff.h.
    That way you know whether the reviewer is a GroupMember or ResourcePool and make the appropriate subsequent calls.
*/
extern EPM_API int EPM_ask_task_reviewers_group_member(
    const tag_t    task_tag,            /**< (I) Workflow task */
    int*           group_member_count,  /**< (O) Count of group members associated as signoffs for the task */
    tag_t**        group_members        /**< (OF) group_member_count Group members associated as signoffs for the task */
    );

/**
    This method will only return ResourcePool assignments and will not return GroupMembers assignments.
    The safer alternative is to get the Signoff object attachments via the
    #EPM_ask_attachments found in epm.h and then ask each Signoff object returned,
    what type it is via the #EPM_ask_signoff_member found in signoff.h.
    That way you know whether the reviewer is a GroupMember or ResourcePool and make the appropriate subsequent calls.
*/
extern EPM_API int EPM_ask_task_reviewers_resource_pool(
    const tag_t    task_tag,            /**< (I) Workflow task */
    int*           res_pool_count,      /**< (O) Count of resource pools associated as signoffs for the task */
    tag_t**        res_pool_tags        /**< (OF) res_pool_count Resource pools associated as signoffs for the task */
    );

/**
    This method will only return GroupMember assignment's user tags and will not return
    ResourcePool assignments as they have no user tag.
    It is intended for functionality that needs to skip the ResourcePool signoff assignments,
    such as mail notification. The safer alternative is to get the Signoff object attachments via the
    #EPM_ask_attachments found in epm.h and then ask each Signoff object returned,
    what type it is via the #EPM_ask_signoff_member found in signoff.h.
    That way you know whether the reviewer is a GroupMember or ResourcePool
    and make the appropriate subsequent calls.
*/
extern EPM_API int EPM_ask_task_reviewers_users(
    const tag_t    task_tag,    /**< (I) Workflow task */
    int*           user_count,  /**< (O) Count of users associated as signoffs for the task */
    tag_t**        users        /**< (OF) user_count Users associated as signoffs for the task */
    );

/**
    This method will only return GroupMember assignment's user tags and
    will not return ResourcePool assignments as they have no user tag.
    It is intended for functionality that needs to skip the ResourcePool signoff assignments,
    such as mail notification.
    The safer alternative is to get the Signoff object attachments via the #EPM_ask_attachments
    found in epm.h and then ask each Signoff object returned,
    what type it is via the #EPM_ask_signoff_member found in signoff.h.
    That way you know whether the reviewer is a GroupMember or ResourcePool and
    make the appropriate subsequent calls.
*/
extern EPM_API int EPM_ask_task_undecided_reviewers_users(
    const tag_t    task_tag,        /**< (I) Workflow task */
    int*           user_count,      /**< (O) Count of users associated with undecided signoffs for the task */
    tag_t**        users            /**< (OF) user_count Users associated with undecided signoffs for the task */
    );

/** This method returns unassigned accessors for the task */
extern EPM_API int EPM_ask_unassigned_reviewer_types(
    tag_t          task_tag,                /**< (I) Workflow task */
    int*           count,                   /**< (O) Count of unassigned accessors */
    tag_t**        unassigned_accessors     /**< (OF) count Unassigned accessors */
    );


/** Get accessor for the signoffs */
extern EPM_API int EPM_ask_signoff_accessor(
    tag_t          signoff,             /**< (I) Signoff */
    tag_t*         acc                  /**< (O) Accessor for the signoff */
    );

/** Get accessor for the signoffs */
extern EPM_API int EPM_set_signoff_accessor(
    tag_t          signoff,             /**< (I) Signoff */
    tag_t          acc                  /**< (I) Accessor for the signoff */
    );


/**
    Sets the signoff decision and comments for a signoff.
    The decision value must be #EPM_approve_decision for approval/authorize,
    #EPM_reject_decision for reject or #EPM_no_decision for no decision.
    Values are declared in signoff.h.

    @warning We do not recommend using this function since the decision will not be recorded in the audit file.
    The audit file will be the only record of signoff decisions after the job is deleted.

    <b>Restrictions:</b> The ITK program must have logged into the POM as the owner of this signoff in order for this function to work.
*/
extern EPM_API int EPM_set_signoff_decision(
    tag_t                 signoff,                           /**< (I) Signoff */
    EPM_signoff_decision_t decision,                          /**< (I) Signoff decision to be set */
    const char            *comments                          /**< (I) Signoff comments */
    );


/**
    Sets the signoff decision and comments for a signoff of a secure review task.
    The decision value must be #EPM_approve_decision for approval/authorize,
    #EPM_reject_decision for reject or #EPM_no_decision for no decision.
    Values are declared in signoff.h.

    <b>Restrictions:</b> The ITK program must have logged into the POM as the user assigned this signoff in order for this function to work.
*/
extern EPM_API int EPM_set_secure_signoff_decision3(
    tag_t                 signoff,                           /**< (I) The tag of the signoff */
    EPM_signoff_decision_t decision,                         /**< (I) Decision associated with the signoff */
    const char            *comments,                         /**< (I) Comments to be recorded along with the action */
    const char            *password                          /**< (I) Password of current user performing the action */
    );


/**
    Retrieves the decision, comments and decision date for a signoff.

*/
extern EPM_API int EPM_ask_signoff_decision(
    tag_t                  signoff,                           /**< (I) Signoff */
    EPM_signoff_decision_t* decision,                         /**< (O) Existing decision for the signoff.
                                                               <br/>The values are:
                                                              <ul>
                                                              <li>#EPM_approve_decision if the decision is approval,
                                                              <li>#EPM_reject_decision if decision is rejection
                                                              <li>#EPM_no_decision if no decision is given.
                                                              </ul>*/
    char                   **comments,                        /**< (OF) Existing signoff comments */
    date_t*                decision_date                      /**< (O) Date of the signoff decision */
    );


extern EPM_API int EPM_delegate_signoff(
    tag_t          signoff,                            /**< (I) Signoff */
    tag_t          new_group_member_to_delegate_to,    /**< (I) New signoff delegate */
    logical        add_audit                           /**< (I) Update audit if true */
    );


/** Check if the signoff objects group/role matches current logged in group/role */
extern EPM_API int EPM_compare_role_and_group(
    tag_t          signoff,         /**< (I) Signoff object */
    logical*       match            /**< (O) true if current group/role matches signoff's group/role */
    );

/**
    Creates a new signoff from a member, origin type and origin profile.
*/
extern EPM_API int EPM_create_signoff(
    tag_t          member,          /**< (I) Group member. */
    int            origin_type,     /**< (I) Signoff origin indicating where a Signoff object is derived from:
                                       <table>
                                       <tr><td>#SIGNOFF_ORIGIN_PROFILE</td><td>0</td></tr>
                                        <tr><td>#SIGNOFF_ORIGIN_ADHOC_USER</td><td>1</td></tr>
                                        <tr><td>#SIGNOFF_ORIGIN_ADHOC_RESOURCEPOOL</td><td>2</td></tr>
                                        <tr><td>#SIGNOFF_ORIGIN_ALIASLIST</td><td>3</td></tr>
                                        <tr><td>#SIGNOFF_ORIGIN_ADHOC_ALL_RESOURCEPOOL</td><td>4</td></tr>
                                        </table> */
    tag_t          origin_profile,  /**< (I) The object that the signoff is created from. This can #NULLTAG. */
    tag_t*         signoff          /**< (O) New signoff. */
    );

/**
    Creates a new signoff for a task, given the task tag,
    groupmember or resourcepool tag, signoff profile as inputs.
    <br/>This function deals with "Profile Signoff" when
    #EPM_create_adhoc_signoff deals with "Adhoc Signoffs".
    <br/>These 2 new functions will replace the #EPM_create_signoff in V7.0.2.
*/
extern EPM_API int EPM_create_profile_signoff(
    tag_t          task,              /**< (I) The Select Signoff task. */
    tag_t          member,            /**< (I) Groupmember tag or resourcepool. */
    tag_t          signoff_profile,   /**< (I) Suggest the signoff profile it satisfies by passing
                                         an appropriate Signoff Profile. */
    tag_t*         signoff           /**< (O) The new signoff. */
    );

/**
    Creates new adhoc signoffs for a task, given the task tag, a member tag
    (can be a groupmember tag, or a resourcepool tag or an aliastlist tag) as inputs.
    <br/>This function deals with "Adhoc Signoff" when
    #EPM_create_profile_signoff deals with "Profile Signoffs".
    <br/>These 2 new functions will replace the #EPM_create_signoff in V7.0.2.
*/
extern EPM_API int EPM_create_adhoc_signoff(
    tag_t          task,           /**< (I) The Select Signoff or Perform Signoff task. */
    tag_t          member,         /**< (I) The groupmember, resourcepool or aliaslist */
    int*           n_signoffs,     /**< (O) The number of signoffs created
                                        (this can be 0 to any number, depending on @p member). */
    tag_t**        signoffs        /**< (OF) n_signoffs The array of new signoffs. */
    );

/**
    Retrieves the member associated with a signoff object.
*/
extern EPM_API int EPM_ask_signoff_member(
    tag_t            signoff,        /**< (I) The signoff object. */
    tag_t*           member,         /**< (O) The group member or the resource pool. */
    SIGNOFF_TYPE_t*  member_type     /**< (O) The signoff member type. This can be: <ul>
                                            <li>#SIGNOFF_GROUPMEMBER
                                            <li>#SIGNOFF_RESOURCEPOOL
                                            <li>#SIGNOFF_UNDEFINED
                                            </ul> */
    );

/**
    Retrieves the origin profile (the object that the signoff is created from) from a signoff object.
*/
extern EPM_API int EPM_ask_signoff_origin_profile(
    tag_t          signoff,              /**< (I) The signoff. */
    tag_t*         origin_profile        /**< (O) Origin profile.  */
    );

/**
    Sets the origin profile of a signoff object.
*/
extern EPM_API int EPM_set_signoff_origin_profile(
    tag_t          signoff,             /**< (I) The signoff. */
    tag_t          origin_profile       /**< (I) Origin profile tag, the object that the signoff is created from. */
    );

/**
    Retrieves the origin type and the origin object, from a signoff object.
*/
extern EPM_API int EPM_ask_signoff_origin_type(
    tag_t          signoff,                  /**< (I) The signoff. */
    int*           origin,                   /**< (O) The signoff origin type, specified as below: <ul>
                                                <li>#SIGNOFF_ORIGIN_PROFILE
                                                <li>#SIGNOFF_ORIGIN_ADHOC_USER
                                                <li>#SIGNOFF_ORIGIN_ADHOC_RESOURCEPOOL
                                                <li>#SIGNOFF_ORIGIN_ADHOC_ALL_RESOURCEPOOL
                                                <li>#SIGNOFF_ORIGIN_ALIASLIST
                                                </ul>*/
    tag_t*         origin_object             /**< (O) The origin object that the signoff is created from. */
    );


extern EPM_API int EPM_ask_signoff_current_task(
    tag_t          signoff,               /**< (I) */
    tag_t*         task                   /**< (O) */
    );


/**
    Retrieves the signoff information pertaining to the last signoff that occurs on a Workspace Object.
    <br/>This works only if the TC Audit Manager is OFF.
    This information is fetched from the audit file.
*/
extern EPM_API int EPM_ask_last_signoff2(
    tag_t           ws_object,                        /**< (I) Tag of the Workspace Object */
    tag_t           release_status,                   /**< (I) Tag of the release status object */
    EPM_decision_t* decision,                         /**< (O) Decision on the object (Approved, Disapproved, No Desicion) */
    char            **signer,                         /**< (OF) Name of the person performing the last signoff */
    date_t*         signoff_date                      /**< (O) Date last signoff was performed */
    );

/**
    Retrieves the signoff information pertaining to the signoffs that occur on a Workspace Object.
    <br/>This works only if the TC Audit Manager is OFF.
    This information is fetched from the audit file.

    The user is responsible to free each string returned in the
    array individually before freeing up the array itself.
*/
extern EPM_API int EPM_ask_signoff_details(
    tag_t            ws_object,           /**< (I) The Workspace Object */
    tag_t            release_status,      /**< (I) The release status object */
    int*             n_signoffs,          /**< (O) Total number of signoffs recorded in the audit file */
    EPM_decision_t** decisions,           /**< (OF) n_signoffs Decisions on the object (Approved, Disapproved, No Decision) */
    char***          signers,             /**< (OF) n_signoffs Names of the persons performing signoffs */
    date_t**         signoff_dates        /**< (OF) n_signoffs Dates when signoffs were performed */
    );

/**
    Delegates the perform-signoff task to new signoff delegate.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_internal_error if signoff profile obtained is invalid.
    <li>#EPM_user_not_valid_performer if the current user is neither a responsible party nor an active surrogate for the task.
    </ul>
*/
extern EPM_API int EPM_delegate_signoff_with_comments(
    tag_t          signoff,                            /**< (I) Signoff */
    tag_t          new_group_member_to_delegate_to,    /**< (I) New signoff delegate */
    logical        add_audit,                          /**< (I) Update audit if true */
    const char*    user_comments                       /**< (I) Comments provided by user*/
    );

/**
    Creates a new signoff with a requirement status.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if member is not groupmember or resourcepool.
    </ul>
*/
extern EPM_API int EPM_create_signoff_with_requirement(
    tag_t       member,                                              /**< (I) Group member. */
    int         origin_type,                                         /**< (I) Signoff origin indicating where a Signoff object is derived from:
                                                                        <table>
                                                                        <tr><td>#SIGNOFF_ORIGIN_PROFILE</td><td></td></tr>
                                                                        <tr><td>#SIGNOFF_ORIGIN_ADHOC_USER</td><td>1</td></tr>
                                                                        <tr><td>#SIGNOFF_ORIGIN_ADHOC_RESOURCEPOOL</td><td>2</td></tr>
                                                                        <tr><td>#SIGNOFF_ORIGIN_ALIASLIST</td><td>3</td></tr>
                                                                        <tr><td>#SIGNOFF_ORIGIN_ADHOC_ALL_RESOURCEPOOL</td><td>4</td></tr>
                                                                     </table>
                                                                     */
    tag_t       origin_profile,                                      /**< (I) The object that the signoff is created from. This can be #NULLTAG. */
    const char* signoff_required,                                    /**< (I) Indicates whether sign off is Optional or Required.
                                                                        <br/>If the value empty, it is Optional.
                                                                        <br/><br/>Possible values depend on the LOV @c Fnd0DecisionRequired:
                                                                        <ul>
                                                                        <li>#SIGNOFF_DECISON_OPTIONAL
                                                                        <li>#SIGNOFF_DECISON_REQUIRED_MODIFIABLE
                                                                        <li>#SIGNOFF_DECISON_REQUIRED_UNMODIFIABLE
                                                                        </ul>
                                                                     */
    tag_t*      signoff                                             /**< (O) New signoff. */
    );

/**
    Creates a new profile signoff with required status.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_duplicate_reviewer if member duplicate.
    </ul>
*/
extern EPM_API int EPM_create_profile_signoff_with_requirement(
    tag_t          task,              /**< (I) The Select Signoff task. */
    tag_t          member,            /**< (I) Groupmember or resource pool. */
    tag_t          signoff_profile,   /**< (I) Suggest the signoff profile it satisfies by passing
                                            an appropriate Signoff Profile. */
    const char*  signoff_required,    /**< (I) Indicate whether signoff is required or optional.
                                            <br/>If the value is empty, it is optional.

                                            <br/>Possible values depend on the LOV @c Fnd0DecisionRequired:
                                            <ul>
                                            <li>#SIGNOFF_DECISON_OPTIONAL
                                            <li>#SIGNOFF_DECISON_REQUIRED_MODIFIABLE
                                            <li>#SIGNOFF_DECISON_REQUIRED_UNMODIFIABLE
                                            </ul> */
    tag_t*         signoff           /**< (O) The new signoff. */
    );

/**
    Creates new adhoc signoffs with required status.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_invalid_object if task tag is NULL.
    <li>#EPM_invalid_object if member tag is NULL
    <li>#CXPOM_wrong_class if member is not groupmember or resourcepool
    </ul>
*/
extern EPM_API int EPM_create_adhoc_signoff_with_requirement (
    tag_t        task,              /**< (I) The Select Signoff task or Perform Signoff task. */
    tag_t        member,            /**< (I) The groupmember, resourcepool or aliaslist. */
    const char*  signoff_required,  /**< (I) Indicates whether signoff is required or optional.
                                       <br/>If the value is empty, it is optional.

                                       <br/>Possible values depends on the LOV @c Fnd0DecisionRequired:
                                       <ul>
                                       <li>#SIGNOFF_DECISON_OPTIONAL            
                                       <li>#SIGNOFF_DECISON_REQUIRED_MODIFIABLE 
                                       <li>#SIGNOFF_DECISON_REQUIRED_UNMODIFIABLE
                                       </ul> */
    int*         n_signoffs,        /**< (O) The number of signoffs created (it can be 0 to any number, depend on @p member). */
    tag_t**      signoffs           /**< (OF) n_signoffs The array of new signoffs. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <epm/libepm_undef.h>
#endif


