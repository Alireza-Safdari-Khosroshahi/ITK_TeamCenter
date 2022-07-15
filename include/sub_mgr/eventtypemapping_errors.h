/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    EVENTTYPEMAPPING errors
*/

/*  */

#ifndef EVENTTYPEMAPPING_ERRORS_H
#define EVENTTYPEMAPPING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EVENTTYPEMAPPING_ERRORS Errors
    @ingroup SUBSCRIPTION
    @{
*/

#define EVENTTYPEMAPPING_class_not_initialized         (EMH_EVENTTYPE_error_base + 0)
#define EVENTTYPEMAPPING_internal_error                (EMH_EVENTTYPE_error_base + 1)
#define EVENTTYPEMAPPING_invalid_imantype              (EMH_EVENTTYPE_error_base + 2)
#define EVENTTYPEMAPPING_already_exists                (EMH_EVENTTYPE_error_base + 3)
#define EVENTTYPEMAPPING_duplicate_eventtype           (EMH_EVENTTYPE_error_base + 4)
#define EVENTTYPEMAPPING_invalid_eventtype             (EMH_EVENTTYPE_error_base + 5)
#define EVENTTYPEMAPPING_user_insufficient_privilege   (EMH_EVENTTYPE_error_base + 6)

/** @} */

#endif
