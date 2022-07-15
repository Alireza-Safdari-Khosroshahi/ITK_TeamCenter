/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK wrappers for the TceventType class methods
*/

/*  */

#ifndef TCEVENTTYPE_H
#define TCEVENTTYPE_H

#include <tc/tc_startup.h>
#include <common/emh_const.h>
#include <sub_mgr/tceventtype_errors.h>
#include <tc/tc_macros.h>
#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup TCEVENTTYPE Event Type
    @ingroup SUBSCRIPTION
    @{
*/

#define MAX_TCEVENTTYPE_ID_LEN         32
#define MAX_TCEVENTTYPE_ATTR_STRLEN    240

#ifdef __cplusplus
extern "C"{
#endif


/**
   Retrieves the event type.
 */
extern SUB_MGR_API int TCEVENTTYPE_ask_eventtype_id2(
    tag_t              eventType,                                   /**< (I) */
    char               **eventTypeId                                /**< (OF) */
    );

extern SUB_MGR_API int TCEVENTTYPE_find(
    const char*        eventTypeId,     /**< (I) */
    tag_t*             eventType        /**< (O) */
    );

extern SUB_MGR_API int TCEVENTTYPE_ask_user_has_access_to_eventtype(
    tag_t              eventTypeToCheck,    /**< (I) */
    logical*           verdict              /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sub_mgr/libsub_mgr_undef.h>
#endif
