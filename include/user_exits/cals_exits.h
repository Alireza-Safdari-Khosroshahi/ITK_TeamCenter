/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    <b>IMPORTANT NOTICE</b>

    These exits have been supplied for one specific purpose only. They are not
    supported for general use, and will be obsoleted at some point in the
    future without prior notice. Please do not call or reimplement these exits
    without the agreement of UGS.
*/

/*  */

#ifndef CALS_EXITS_H
#define CALS_EXITS_H

#include <tc/tc_startup.h>

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup CALS_EXITS CALS Exits
    @ingroup USER_EXITS
    @{
*/

/**
    Called when a bvr is revised, i.e. producing a new bvr of the same bom view.
*/
extern USER_EXITS_API int CALS_revising_bvr(
    tag_t                 source_bvr,   /**< (I) */
    tag_t                 new_bvr       /**< (I) */
    );

/**
    Called when a bvr is copied, i.e. producing a bvr of a different bom view.
*/
extern USER_EXITS_API int CALS_copying_bvr(
    tag_t                 source_bvr,   /**< (I) */
    tag_t                 new_bvr       /**< (I) */
    );

/**
    Called when a bvr is saved.
*/
extern USER_EXITS_API int CALS_saving_bvr(
    tag_t                 bvr   /**< (I) */
    );

/**
    Called whenever an occurrence is being removed from the database, either
    because the parent bvr is being deleted, or because the parent bvr is being
    saved, and the occurrence has been 'cut'.
    Any objects which should also be deleted at the same time as this
    occurrence should have their tags returned on the objs_to_delete array.
    Space for this array must be provided by #MEM_alloc, and will be deleted by
    the code that calls this exit.
*/
extern USER_EXITS_API int CALS_deleting_occ(
    tag_t                 parent_bvr,       /**< (I) */
    tag_t                 occurrence,       /**< (I) */
    int*                  n_objs,           /**< (O) */
    tag_t**               objs_to_delete    /**< (OF) n_objs */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <user_exits/libuser_exits_undef.h>

#endif
