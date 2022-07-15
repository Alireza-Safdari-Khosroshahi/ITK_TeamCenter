/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter action errors
*/

/*  */

#ifndef TCACTION_ERRORS_H
#define TCACTION_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup TCACTION_ERRORS Action Errors
    @ingroup SUBSCRIPTION
    @{
*/

#define TCACTION_class_not_initialized    (EMH_ACTION_error_base + 0)
#define TCACTION_internal_error           (EMH_ACTION_error_base + 1)
#define TCACTION_invalid_action_object    (EMH_ACTION_error_base + 2)

/** @} */

#include <sub_mgr/libsub_mgr_undef.h>
#endif
