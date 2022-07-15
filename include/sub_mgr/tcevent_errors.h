/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter event errors
*/

/*  */

#ifndef TCEVENT_ERRORS_H
#define TCEVENT_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup TCEVENT_ERRORS Event Errors
    @ingroup SUBSCRIPTION
    @{
*/

#define TCEVENT_class_not_initialized (EMH_EVENT_error_base + 0)
#define TCEVENT_internal_error        (EMH_EVENT_error_base + 1)

/** @} */

#include <sub_mgr/libsub_mgr_undef.h>
#endif
