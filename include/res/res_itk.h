/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Definition of structures and functions prototypes
    associated with RESERVATION ITK module.
*/

/*  */

/**
    @defgroup RES Reservation

    The reservation (RES) ITK functions provide check-out, check-in, transfer check-out, 
    cancel check-out, list check-out, notification list, and check-out history functionality.
    They also provide information about ImanReservation objects that are created when objects are checked out. 
    An ImanReservation object is associated with each checked out object via an IMAN_RES_checkout GRM relation.

    Not all objects can be checked out. The following classes and their sub-classes are valid for check-out:
    <UL>
    <LI>Dataset
    <LI>Folder
    <LI>Form
    <LI>Item
    <LI>ItemRevision
    <LI>PSBOMView
    <LI>PSBOMViewRevision 
    </UL>

    To use reservation ITK functions, include the res_itk.h file in the source code.

    The ImanReservation class has the following significant attributes:

    <table>
    <tr><td>Attribute            </td><td>Description                                                            </td></tr>
    <tr><td>Reason               </td><td>Descriptive character string, holding the check-out purpose.           </td></tr>
    <tr><td>Change ID            </td><td>Character string.                                                      </td></tr>
                                          In previous Teamcenter Engineering releases this was referred to as Project ID.
                                          Typically, this will be used to reference a change proposal job name.  </td></tr>
    <tr><td>Reservation Type     </td><td>Integer that indicates whether check-out is with or without export.
                                          This attribute can have the following values: <br>
                                          #RES_EXCLUSIVE_RESERVE (check-out only)<br>
                                          #RES_EXPORT_FILE (check-out with export)                               </td></tr>
    <tr><td>Export Directory Name</td><td>Character string used if a dataset is checked out with export.
                                          If so, this attribute holds the full OS directory path that
                                          the dataset was exported to.                                           </td></tr>
    <tr><td>Reservation State    </td><td>Integer that holds ImanReservation object current check-out state.
                                          This attribute can have the following values:

                                          #RES_RESERVE (state indicating associated object is checked out)<br>
                                          #RES_UNRESERVE (state indicating associated object is not checked out) </td></tr>
    <tr><td>Notification List    </td><td>VLA containing the tags of users that wish to be notified when
                                          the associated object's check-out status changes.                      </td></tr>
    <tr><td>User                 </td><td>Tag to the user that currently holds the associated object's check-out.</td></tr>
    <tr><td>Date                 </td><td>A date_t that holds the date of the current check-out.                 </td></tr>
    </table>

    @{
*/

/**
    @name Reservation states stored in the reservation object
    @{
*/
#define RES_RESERVE                 0
#define RES_UNRESERVE               1
/** @} */

/**
    Not a reservation state stored in the reservation object,
    it is used by UIF for display reasons only.
    You are advised not to use it.
 */
#define RES_RESERVE_AND_EXPORT      3

/**
    @name Reservation messages to be used with Method
    @{
*/
#define   RES_Type                  "ImanReservation"

#define   RES_checkout_msg          "RES_checkout"
#define   RES_checkin_msg           "RES_checkin"
#define   RES_cancel_checkout_msg   "RES_cancel_checkout"
#define   RES_transfer_checkout_msg "RES_transfer_checkout"
#define   RES_notification_msg      "RES_notification"
/** @} */

/**
    @name Reservation types
    @{
*/

/**
   Checkout object with export option.
*/
#define RES_EXPORT_FILE                         1
/**
 This indicates a regular long term check-out.
*/
#define RES_EXCLUSIVE_RESERVE                   2
/**
 This is used by NX/Manager to avoid remote check-out.
*/
#define RES_EXCLUSIVE_LOCAL_RESERVE             3
/** @} */

/** @if DOX_IGNORE
    Subrata PR#420726 - RES_SHORT_TERM_RESERVE is being moved in here
    from res_internal.h. It is a published reservation type now.
@endif */
#define RES_SHORT_TERM_RESERVE      5

/** @if DOX_IGNORE
    kulkaamo PR#6567666 - RES_SHORT_TERM_SYSTEM_RESERVE is defined
    res_internal.h. as it should not be published  Adding a note in
    res_itk.h so that same number (6) should not be used again

#define RES_SHORT_TERM_SYSTEM_RESERVE      6
@endif */

#ifndef RES_ITK_H_INCLUDED
#define RES_ITK_H_INCLUDED

#include <tc/tc_startup.h>
#include <ss/ss_const.h>
#include <tccore/workspaceobject.h>
#include <res/libres_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This function returns the count and list of objects referencing (connected to) the reservation object. 
    At present only one object is connected.
*/
extern RES_API int RES_ask_reserved_object (
    tag_t          reservation_tag,         /**< (I) */
    int*           tag_count,               /**< (O) */
    tag_t**        reserved_object_tags     /**< (OF) tag_count */
    );


/**
   Retrieves the reason attribute of the reservation object  
*/
extern RES_API int RES_ask_reason2 (
    tag_t          reservation_tag,             /**< (I) */
    char           **reason                     /**< (OF) */
    );

/**
    Queries if reservation object is set to have file(s) exported when the object is checked out.
*/
extern RES_API int RES_ask_export_on_checkout (
    tag_t          reservation_tag,     /**< (I) */
    logical*       export_flag          /**< (O) @c true if the reservation is setup to export file on checkout */
    );



/**
   Retrieves the export directory from a reservation object.
*/
extern RES_API int RES_ask_exp_directory2 (
    tag_t          reservation_tag,             /**< (I) */
    char           **directory                  /**< (OF) */
    );

/**
    Retrieves the reservation type of the reservation object  
*/
extern RES_API int RES_ask_reservation_type (
    tag_t          reservation_tag,     /**< (I) */
    int*           reservation_type     /**< (O) */
    );

/**
    This function is used to return the reservation state of a reservation object.
    The reservation_state can be one of the following states: #RES_RESERVE or #RES_UNRESERVE.
*/
extern RES_API int RES_ask_reservation_state (
    tag_t          reservation_tag,     /**< (I) */
    int*           reservation_state    /**< (O) */
    );

/**
    Allocates an array of tags and stores in the array all of the reservation objects in the database.
    
    The caller is responsible for deallocating the array of tags.
*/
extern RES_API int RES_extent_reservation (
    int*           tag_count,           /**< (O) The size of the array */
    tag_t**        reservation_tags     /**< (OF) tag_count The array of tags */
    );

/**
    Finds reservation objects that are owned by the input user.
    It is the caller's responsibility to free the array of tags passed as the output parameter by this function.
*/
extern RES_API int RES_find_reservations_by_user (
    tag_t          user_tag,            /**< (I) */
    int*           tag_count,           /**< (O) */
    tag_t**        reservation_tags     /**< (OF) tag_count */
    );

/**
    Finds reservation objects that are owned by the input group.
    It is the caller's responsibility to free the array of tags passed as the output parameters by this function.
*/
extern RES_API int RES_find_reservations_by_group (
    tag_t          group_tag,           /**< (I) */
    int*           tag_count,           /**< (O) */
    tag_t**        reservation_tags     /**< (OF) tag_count */
    );

/**
    This function returns the user and group by whom the input object is checked out.
    Note that with the 3.4 revised implementation of the reservation class,
    the group tag has lost its importance, it's the user that is important.
    We still store the group for compatibility with existing customer ITK code. 
    Note that after Iman 4.0, either the user tag or the group tag will be #NULLTAG.
    This will be the case after group checkout is implemented,
    so that either a reservation is held by a particular group (user would be #NULLTAG)
    or the reservation is held by a particular user (group will be #NULLTAG).
 */
extern RES_API int RES_who_checked_object_out (
    tag_t          object_tag,      /**< (I) */
    tag_t*         user_tag,        /**< (O) */
    tag_t*         group_tag        /**< (O) */
    );


/**
   Checks out the input object. 
   The other arguments set attributes in the ImanReservation object that is created as a result of a check-out.
*/
extern RES_API int RES_checkout2 (
    tag_t      object_tag,                      /**< (I) Object being checked out */
    const char *reason,                         /**< (I) The reservation reason. */
    const char *change_id,                      /**< (I) The System change_id/project_id. This can be passed as a NULL pointer. */
    const char *dir_name,                       /**< (I) The export directory for the checked-out object. */
    int        reservation_type                 /**< (I) This should be set to #RES_EXCLUSIVE_RESERVE for regular check-out,
                                                         or set to #RES_EXPORT_FILE for check-out with export (datasets only). */
    );

/**
Checks out @p object for @p user. If @p user is #NULLTAG it will checkout @p object for the logged in user.
The other arguments set attributes in the ImanReservation object that is created as a result of a check-out.

@returns
<ul>
<li>#ITK_ok on success
<li>#RES_NO_OBJECT_TO_RESERVE if @p object is #NULLTAG
<li>#RES_OBJECT_IS_RESERVED if @p object is already reserved
<li>#RES_UNSUPPORTED_TYPE if @p object does not support reservation
<li>#RES_INVALID_RESERVATION_TYPE if @p reservation_type is invalid
<li>#AM_invalid_tag if @p user is invalid
<li>#POM_access_denied if @p user has no write access to @p object
<li>#RES_RESERVE_TO_OTHER_SITE if @p object is checked out to another site
</ul>
*/
extern RES_API int RES_checkout_for_user(
    tag_t      object,                            /**< (I) The object being checked out. */
    const char *reason,                           /**< (I) The reservation reason. */
    const char *change_id,                        /**< (I) The system change_id/project_id. This can be passed as a NULL pointer. */
    const char *dir_name,                         /**< (I) The export directory for the checked-out object. */
    int        reservation_type,                  /**< (I) This should be set to #RES_EXCLUSIVE_RESERVE for regular check-out,
                                                           or set to #RES_EXPORT_FILE for check-out with export (only for datasets). */
    tag_t      user                               /**< (I) The user for which the object is being checked-out. It can be #NULLTAG. */
);

/**
    Checks in the input object.
*/
extern RES_API int RES_checkin (
    tag_t          obj_tag      /**< (I) Object being checked out */
    );

/**
    Cancels the check-out of the input object.
    Cancel check-out is only valid for datasets,
    and it causes the dataset to be restored to its precheck-out state.
    copy_flag is used to specify whether the current modified dataset is to be saved or not. 
    If copy_flag is true, then the current state of the dataset will be copied to
    the user's Newstuff folder only if the dataset has been versioned (modified) since it was checked out.
    If copy_flag is false, then no copy will be made.
*/
extern RES_API int RES_cancel_checkout (
    tag_t          object_tag,      /**< (I) Object being checked out */
    logical        copy_flag        /**< (I) Indicates whether a modified dataset should be saved,
                                        before its contents are restored to its pre check-out state. */
    );

/**
    Transfers the check-out of the object to the input user and group.
    Currently the group tag is not important and we allow it to be set to #NULLTAG. 
    The group tag may become more significant in a later release if we implement group check-outs.
*/
extern RES_API int RES_transfer_checkout (
    tag_t          object_tag,  /**< (I) Unique identifier (tag) of object whose check-out
                                    (reservation object) is being transferred */
    tag_t          user_tag,    /**< (I) Unique identifier (tag) of new user to receive object check-out
                                    (exclusive write access) */
    tag_t          group_tag    /**< (I) This argument is not currently significant,
                                    and #NULLTAG is the recommended value */
    );

/**
    This function provides a list of all the object tags of the object that a user currently has checked out.
    Only system administrators will be allowed to list the check-outs of another user.
*/
extern RES_API int RES_list_checkout (
    tag_t          user_tag,    /**< (I) Unique identifier (tag) of user whose checked-out objects is to be listed */
    int*           tag_count,   /**< (O) Number of objects that user has in list */
    tag_t**        object_tags  /**< (OF) tag_count VLA of object tags, memory must be freed by the function caller */
    );

/**
    This function determines if a object is checked out.
*/
extern RES_API int RES_is_checked_out (
    tag_t          object_tag,      /**< (I) Unique identifier (tag) of object that you're inquiring on */
    logical*       is_reserved      /**< (O) @c true if object is checked out, otherwise @c false. */
    );

/**
    This function is used to check if an object is modifiable by the login user,
    in terms of a reservation.
    An object is modifiable if it is not checked-out or
    it is checked-out by the current login user and not exported.

    @note ACL checks for the correct access are not made here,
        instead this function would supplement such an access check.
        This function returns #ITK_ok if the object is modifiable in terms of reservations.
        Otherwise, an integer error code will be returned.
*/
extern RES_API int RES_assert_object_modifiable (
    tag_t          object_tag       /**< (I) Unique identifier (tag) of object that you're inquiring on */
    );

/**
    This function returns the list of user's tags, for the users in the reservation object notification list.
*/
extern RES_API int RES_ask_notifylist (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of the
                                            reservation object that you're inquiring on */
    int*           no_users,            /**< (O) Number of user tags in the list */
    tag_t**        notifylist           /**< (OF) no_users List of user tags,
                                            memory must be freed by caller of this function */
    );

/**
    This function adds the input user to the input reservation's notification list.
*/
extern RES_API int RES_add_to_notifylist (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of reservation object that you want to update */
    tag_t          user_tag             /**< (I) Unique identifier (tag) of user to be added to the notification list */
    );

/**
    This function removes the input user from the input reservation's notification list.

    @note If the last user is removed from the notification list using this ITK call,
    then you must check if the reservation object must be deleted.
    If the reservation's state is not equal to #RES_RESERVE (use #RES_ask_reservation_state)
    and the notification list is empty (use #RES_ask_notifylist)
    then the reservation object should be deleted using #AOM_delete only.
    These checks were not internalized as it would have been misleading and against ITK standards to have
    an ITK function that modifies an object attribute,
    and have that same call in some circumstances delete the object itself.
*/
extern RES_API int RES_remove_from_notifylist (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of reservation object that you want to update */
    tag_t          user_tag             /**< (I) Unique identifier (tag) of user to be removed from the notification list */
    );

/**
    Retrieves the latest user by whom the object connected to the input reservation object is checked out.
*/
extern RES_API int RES_ask_user (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of reservation object that you're inquiring on */
    tag_t*         user_tag             /**< (O) Unique identifier (tag) of user that holds the check-out */
    );

/**
    Retrieves the latest group by whom the object connected to the input reservation object is checked out.
    With the current implementation users check out objects and so the group is not important,
    therefore this function may return a #NULLTAG for group_tag.
    In the future we may implement group check-out and the group will then become significant.
*/
extern RES_API int RES_ask_group (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of reservation object that you're inquiring on */
    tag_t*         group_tag            /**< (O) Unique identifier (tag) of group that holds the check-out */
    );

/**
    This function returns the last date of check-out for the object associated with the input reservation object.
*/
extern RES_API int RES_ask_reservation_date (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of reservation object that you're inquiring on */
    date_t*        date                 /**< (O) Date object was last checked out */
    );


/**
   Retrieves the change ID from a reservation object.
   
   @note The project_id and change_id attributes are one and the same attribute in the reservation object.
   Change IDs are not always setfor they are an optional entry on the check-out dialog box.
*/
extern RES_API int RES_ask_change_id2 (
    tag_t          reservation_tag,                 /**< (I) Unique identifier (tag) of the
                                                        reservation object that you're inquiring on */
    char           **change_id                      /**< (OF) Change ID used for check-out */
    );

/**
    Retrieves the reservation object for @p object_tag.
    @note This operation will return a #NULLTAG for @p reservation_tag (even if it is associated with @p object_tag) if the reservation state is unreserved.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_tag if @p object_tag is a #NULLTAG or not a persistent object tag.
   </ul>
*/
extern RES_API int RES_ask_reservation_object (
    tag_t          object_tag,          /**< (I) Unique identifier (tag) of object that you're inquiring on */
    tag_t*         reservation_tag      /**< (O) Unique identifier (tag) of the associated reservation object */
    );

/**
    This function gets the reservation audit file associated with the specified object.
    If the object has never been checked out, no audit file exists.
    Therefore, the file_tag returned will be #NULLTAG.
*/
extern RES_API int RES_ask_audit_file(
    tag_t          object_tag,  /**< (I) Unique identifier (tag) of object being asked */
    tag_t*         file_tag     /**< (O) Unique identifier (tag) of the associated audit file object */
    );

/**
    Retrieves the audit history for the specified object.
    If the object has never been checked, out no history events exist.
    In this case the event_count will be 0 and the field arrays will be null.
    On error, the event_count will be 0 and the field_arrays will be null. 
*/
extern RES_API int RES_ask_audit_history(
    tag_t       object_tag, /**< (I) Unique identifier (tag) of auditable object. */
    int*        event_count,/**< (O) Number of events in the history field arrays. */
    char***     dates,      /**< (OF) Date and time. */
    char***     users,      /**< (OF) User information. */
    char***     actions,    /**< (OF) Reservation action. */
    char***     change_ids, /**< (OF) User change identifier. */
    char***     reasons     /**< (OF) User comment. */
    );

/**
    This function saves the reservation object.
    The reservation object used in pre Version 3.4 used a different object model than the current one.
    The old model performing an #AOM_save on the reservation led to the check-out functionality being 
    triggered for the associated object. With the new model, 
    the new reservation object is saved prior to it being associated to the check-out object via a GRM relation.

    In order to support legacy code written prior to Version 3.4,
    #AOM_save has been set up to support the old model.
    However, if you're creating new code using the new model, you should not use #AOM_save.
    It will work but it will be inefficient.
    Instead, use either this function or #POM_save_instances, 
    which will save the reservation object without triggering an extraneous check-out mechanism.
*/
extern RES_API int RES_save_reservation (
    tag_t          reservation_tag,     /**< (I) Unique identifier (tag) of reservation object that you're updating */
    logical        whether_to_unload    /**< (I) Logical flag indicating whether or not the system should unload */
    );

/**
    Initializes all the Reservation messages: 
    RES_checkout_msg, RES_checkin_msg, RES_cancel_checkout_msg, RES_transfer_checkout_msg and RES_notification_msg are initiliazed.
*/
extern RES_API int RES_init_module ();

/** @} */

/**
    @name Utility Functions

    These are utility functions that support Remote CICO funtionality which allow checkouts on replica objects
    @{
*/

extern RES_API int RES_list_remote_checkout( 
    tag_t          remote_site,     /**< (I) */
    const char*    remote_user,     /**< (I) */
    const char*    remote_group,    /**< (I) */
    int*           tag_count,       /**< (O) */
    tag_t**        object_tags      /**< (OF) tag_count */
    );

extern RES_API int RES_list_replica_checkout( 
    tag_t          remote_site,         /**< (I) */
    tag_t          local_user_tag,      /**< (I) */
    tag_t          local_group_tag,     /**< (I) */
    int*           tag_count,           /**< (O) */
    tag_t**        object_tags          /**< (OF) tag_count */
    );

extern RES_API int RES_is_checked_out_by_remote_user( 
    tag_t          object_tag,      /**< (I) */
    logical*       is_reserved      /**< (O) */
    );

extern RES_API int RES_is_checked_out_replica( 
    tag_t          object_tag,      /**< (I) */
    logical*       is_reserved      /**< (O) */
    );

extern RES_API int RES_ask_remote_user_and_group( 
    tag_t          reservation_tag,     /**< (I) */
    char**         remote_user,         /**< (OF) */
    char**         remote_group         /**< (OF) */
    ); 

extern RES_API int RES_ask_remote_site( 
    tag_t          reservation_tag,     /**< (I) */
    tag_t*         remote_site          /**< (O) */
    );

/**
* This function determines if an object is checkoutable or not.
* @return
**/
extern RES_API int RES_is_checkoutable(
    tag_t          object_tag,      /**< (I) Tag of a selected object */
    logical*       is_checkoutable  /**< (O) Indicates if object is checkoutable or not */
    );
/** @} */

#ifdef __cplusplus
}
#endif

#include <res/libres_undef.h>

#endif
