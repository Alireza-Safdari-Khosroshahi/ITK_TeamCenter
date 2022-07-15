/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    EVENTTYPE errors
*/

/*  */

#ifndef TCEVENTTYPE_ERRORS_H
#define TCEVENTTYPE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCEVENTTYPE_ERRORS Errors
    @ingroup TCEVENTTYPE
    @{
*/

#define TCEVENTTYPE_class_not_initialized         (EMH_EVENTTYPE_error_base + 0)
#define TCEVENTTYPE_internal_error                (EMH_EVENTTYPE_error_base + 1)
#define TCEVENTTYPE_invalid_event_id              (EMH_EVENTTYPE_error_base + 2)
#define TCEVENTTYPE_invalid_event_baseclassname   (EMH_EVENTTYPE_error_base + 3)
#define TCEVENTTYPE_invalid_event_description     (EMH_EVENTTYPE_error_base + 4)
#define TCEVENTTYPE_does_not_exist                (EMH_EVENTTYPE_error_base + 5)
#define TCEVENTTYPE_already_exists                (EMH_EVENTTYPE_error_base + 6)
#define TCEVENTTYPE_user_insufficient_privilege   (EMH_EVENTTYPE_error_base + 7)

/** @} */

#endif
