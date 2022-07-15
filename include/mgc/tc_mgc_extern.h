/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This declaration is currently needed for libuser_exits,
    and hence has to pretend to be an ITK call.
*/

/*  */

#ifndef TC_MGC_EXTERN_H
#define TC_MGC_EXTERN_H

#include <mgc/libmgc_exports.h>

/**
    @defgroup MGC Mentor Integration
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

extern MGC_API int TC_MGC__is_mgc_object (
    tag_t          obj_tag,             /**< (I) */
    tag_t*         mgc_item_tag,        /**< (O) */
    tag_t*         mgc_item_rev_tag,    /**< (O) */
    logical*       answer               /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <mgc/libmgc_undef.h>

#endif
