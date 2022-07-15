/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter event manager errors
*/

/*  */

#ifndef TCEVENTMGR_ERRORS_H
#define TCEVENTMGR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCEVENTMGR_ERRORS Errors
    @ingroup TCEVENTMGR
    @{
*/

#define TCEVENTMGR_internal_error                                (EMH_EVENTMGR_error_base + 0)
#define TCEVENTMGR_failed_to_retrieve_inprocess_subscriptions    (EMH_EVENTMGR_error_base + 1)
#define TCEVENTMGR_failed_to_process_inprocess_subscriptions     (EMH_EVENTMGR_error_base + 2)
#define TCEVENTMGR_failed_to_process_event                       (EMH_EVENTMGR_error_base + 3)
#define TCEVENTMGR_invalid_queue                                 (EMH_EVENTMGR_error_base + 4)
#define TCEVENTMGR_invalid_status                                (EMH_EVENTMGR_error_base + 5)
#define TCEVENTMGR_invalid_relation                              (EMH_EVENTMGR_error_base + 6)
#define TCEVENTMGR_invalid_secondary_object                      (EMH_EVENTMGR_error_base + 7)
#define TCEVENTMGR_target_not_of_same_type                       (EMH_EVENTMGR_error_base + 8)

/** @} */

#endif
