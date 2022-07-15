/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2018.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/
/**
   @file
    Teamcenter has implemented Participant functionality to allow addition/removal of participants (users) in different category
    to the Workspace object which can be later be helpful while assigning different tasks to the participants through action-handlers.
    */


#ifndef TEAMCENTER_PARTICIPANT_H
#define TEAMCENTER_PARTICIPANT_H

#include <unidefs.h>
#include <Fnd0Participant/libFnd0Participant_exports.h>

/**
    @defgroup PARTICIPANT Participant
    @ingroup TC
    @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
   Adds a single participant to a Workspace object.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PARTICIPANT_invalid_wso                 if @p wso is not a valid object and/or not of type of WorkspaceObject.
   <li>#PARTICIPANT_invalid_participant         if @p participant is not a valid object and/or not of type of Participant.
   <li>#PARTICIPANT_is_not_allowable            if @p participant is of participant type not supported for @p wso.
   <li>#PARTICIPANT_is_not_assignable           if @p bypass_assignable_check is false and current logged in user doesn't have access to assign @p participant of participant type to @p wso.
   <li>#PARTICIPANT_single_participant_allowed  if @p wso already has one participant as @p participant is of single user participant type.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_add_participant(
    const tag_t wso,                          /**< (I)  The Workspace Object for which the participant needs to be added. */
    const logical bypass_assignable_check,    /**< (I)  Flag to decide whether bypass assignable type check. */
    const tag_t participant                   /**< (I)  The participant to add. */
);

/**
   Adds multiple participants to a Workspace object.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PARTICIPANT_invalid_wso                 if @p wso is not a valid object and/or not a type of WorkspaceObject.
   <li>#PARTICIPANT_invalid_assignee            if @p assignee_list contains invalid objects and/or are not a valid assignees (i.e. not of type GroupMember nor ResourcePool).
   <li>#PARTICIPANT_invalid_participant_type    if @p participant_types_list contains NULLTAG.
   <li>#PARTICIPANT_is_not_allowable            if @p participant_types_list contains object of type not supported for @p wso.
   <li>#PARTICIPANT_is_not_assignable           if @p bypass_assignable_check is false and current logged in user doesn't have access to assign @p participant_types_list to @p wso.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_add_participants(
    const tag_t  wso,                               /**< (I)  The Workspace Object for which the participants needs to be added. */
    const logical bypass_assignable_check,          /**< (I)  Flag to decide whether bypass assignable type check. */
    const int    n_assignees,                       /**< (I)  Number of assignees (Group member). */
    const tag_t* assignee_list,                     /**< (I)  n_assignees List of assignees (Group member). */
    const tag_t* participant_types_list,            /**< (I)  n_assignees List of participant type. */
    tag_t** participant_list                        /**< (OF) n_assignees List of added participants to a WorkspaceObject. */
);

/**
   Removes a single participant from a Workspace object.

   @returns
   <ul>
   <li>#ITK_ok on success, or if @p participant is not a valid object or is not present in @p wso.
   <li>#PARTICIPANT_invalid_wso if @p wso is not a valid object and/or not of type of WorkspaceObject.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_remove_participant(
    const tag_t wso,                          /**< (I)  The Workspace Object for which the participant needs to be removed. */
    const tag_t participant                   /**< (I)  The participant to remove. */
);

/**
   Removes multiple participants from a Workspace object.

   @returns
   <ul>
   <li>#ITK_ok on success, or if @p participant_list are not valid objects or are not present in @p wso.
   <li>#PARTICIPANT_invalid_wso if @p wso is not a valid object and/or not of type of WorkspaceObject.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_remove_participants(
    const tag_t  wso,                         /**< (I)  The Workspace Object for which the participants needs to be removed. */
    const int    n_participants,              /**< (I)  Number of participants to remove. */
    const tag_t* participant_list             /**< (I)  n_participants List of participants to remove. */
);

/**
   Updates multiple participants to a Workspace object.
   <br/>It removes the exisiting participants from the WorkspaceObject and adds new participants.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PARTICIPANT_invalid_wso                 if @p wso is not a valid object and/or not a type of WorkspaceObject.
   <li>#PARTICIPANT_invalid_assignee            if @p assignee_list contains invalid objects and/or are not a valid assignees (i.e. not of type GroupMember nor ResourcePool).
   <li>#PARTICIPANT_invalid_participant_type    if @p participant_types_list contains NULLTAG.
   <li>#PARTICIPANT_is_not_allowable            if @p participant_types_list contains object of type not supported for @p wso.
   <li>#PARTICIPANT_is_not_assignable           if @p bypass_assignable_check is false and current logged in user doesn't have access to assign @p participant_types_list to @p wso.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_update_participants(
    const tag_t   wso,                        /**< (I)  The Workspace Object for which the participants needs to be updated. */
    const logical bypass_assignable_check,    /**< (I)  Flag to decide whether bypass assignable type check. */
    const int     n_assignees,                /**< (I)  Number of assignees (Group member). */
    const tag_t*  assignee_list,              /**< (I)  n_assignees List of assignees (Group member). */
    const tag_t*  participant_types_list,     /**< (I)  n_assignees List of participant types. */
    tag_t** participant_list                  /**< (OF) n_assignees List of updated participants to a WorkspaceObject. */
);

/**
   Sets multiple participants to a Workspace object.
   <br/>It removes the exisiting participants from the WorkspaceObject and adds new participants.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#TYPE_unknown_type if @p wso is not a valid object and/or not of type of WorkspaceObject.
   <li>#TYPE_unknown_type if @p participant_list contains invalid objects and/or are not of type of Participant.
   </ul>
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PARTICIPANT_invalid_wso                 if @p wso is not a valid object and/or not of type of WorkspaceObject.
   <li>#PARTICIPANT_invalid_participant         if @p participant_list contains invalid object and/or not of type of Participant.
   <li>#PARTICIPANT_is_not_allowable            if @p participant_list contains object of participant type not supported for @p wso.
   <li>#PARTICIPANT_is_not_assignable           if @p bypass_assignable_check is false and current logged in user doesn't have access to assign @p participant_list contains object of participant type to @p wso.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_set_participants(
    const tag_t  wso,                        /**< (I)  The Workspace Object for which the participants needs to be set. */
    const logical bypass_assignable_check,   /**< (I)  Flag to decide whether bypass assignable type check. */
    const int    n_participants,             /**< (I)  Number of participants to set. */
    const tag_t* participant_list            /**< (I)  n_participants List of participants to set. */
);

/**
   Asks participants of a Workspace object.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PARTICIPANT_invalid_wso if @p wso is not a valid object and/or not of type of WorkspaceObject.
   <li>#TYPE_unknown_type       if @p participant_type contains invalid objects and/or are not of type of Participant.
   </ul>
*/
extern PARTICIPANT_API int PARTICIPANT_ask_participants(
    const tag_t wso,                        /**< (I)  The Workspace Object for which the participants needs to be asked. */
    const tag_t participant_type,           /**< (I)  Type of participant to retrieve.<br/>It should be a subtype of the Participant class
                                                      (e.g. "ProposedResponsibleParty", "ProposedReviewer"). */
    int*    n_participants,                 /**< (O)  Number of participants. */
    tag_t** participant_list                /**< (OF) n_participants List of participants of a WorkspaceObject. */
);

#ifdef __cplusplus
}
#endif

/**
@}
*/
#include <Fnd0Participant/libFnd0Participant_undef.h>
#endif
