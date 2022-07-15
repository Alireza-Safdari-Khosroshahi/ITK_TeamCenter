/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2018.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/


#ifndef TEAMCENTER_PARTICIPANT_ERRORS_H
#define TEAMCENTER_PARTICIPANT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup PARTICIPANT_ERRORS Errors
    @ingroup PARTICIPANT
    @{
*/

/** Only one participant is allowed for participant type "%1$".*/
#define PARTICIPANT_single_participant_allowed                  ( EMH_PARTICIPANT_error_base + 1 )

/** "%1$" is not a valid Participant type.*/
#define PARTICIPANT_invalid_participant_type                    ( EMH_PARTICIPANT_error_base + 2 )

/** "%1$" is not a valid assignee.*/
#define PARTICIPANT_invalid_assignee                            ( EMH_PARTICIPANT_error_base + 3 )

/** "%1$" is not a Workspace Object.*/
#define PARTICIPANT_invalid_wso                                 ( EMH_PARTICIPANT_error_base + 4 )

/** "%1$" is not a Participant.*/
#define PARTICIPANT_invalid_participant                         ( EMH_PARTICIPANT_error_base + 5 )

/** The Participant type "%1$" is not allowed for Workspace Objects of type "%2$".*/
#define PARTICIPANT_is_not_allowable                            ( EMH_PARTICIPANT_error_base + 6 )

/** The Participant type "%1$" is not assignable to Workspace Objects of type "%2$" for the current user.*/
#define PARTICIPANT_is_not_assignable                           ( EMH_PARTICIPANT_error_base + 7 )

/** Participants could not be reassigned. Please check the Teamcenter server syslog file for more information.*/
#define PARTICIPANT_failed_to_reassign_participants             ( EMH_PARTICIPANT_error_base + 8 )

/** The Participant of type "%1$" could not be reassigned to the object "%2$".*/
#define PARTICIPANT_failed_to_reassign_participant_for_type     ( EMH_PARTICIPANT_error_base + 9 )

/** @} */
#endif
