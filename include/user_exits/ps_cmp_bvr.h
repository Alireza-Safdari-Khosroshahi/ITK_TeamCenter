/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the prototypes for functions that find and list differences between BVR's.
    A function prototype for freeing the memory allocated is also provided.
*/

/*  */

#ifndef PS_CMP_BVR_H
#define PS_CMP_BVR_H

#include <stdio.h>
#include <unidefs.h>

/**
    @defgroup PS_CMP_BVR PS Compare BOM View Revision
    @ingroup USER_EXITS

    Basically, #SMP_PS_list_bvr_diffs builds up a list of all occurrence data of both the supplied BVRs.
    This list is ordered by sequence number, and (within that) by item/rev tag.
    qty[0] holds the quantity of the occurrence in the first BVR, and qty[1] that for the second BVR.
    Each difference element represents the number of occurrences of a single item/rev in the BVRs.

    Note that:
    <ol>
    <li>If a difference element contains the same quantity value for both BVRs,
        this is an unchanged occurrence (i.e. each BVR has the same number of occurrences of this item/rev).
    <li>If a difference element contains different quantities for each BVR,
        there have either been additional occurrences added to the second BVR compared to the first (qty[1] \> qty[0]),
        or some occurrences have been removed from the second compared to the first (qty[1] \< qty[0]).
    </ol>
    @{
*/

/**
    Used to hold the tag of the BOMline referencing the compare,
    also the windows used (this allows them to be disposed of using #SMP_PS_free_bvr_diffs)
*/
typedef struct SMP_PS_bvr_diff_s
{
    tag_t myBOMline;
    tag_t window1;
    tag_t window2;
} SMP_PS_bvr_diff_t, *SMP_PS_bvr_diff_p_t;

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Build up a list of differences between the two given BVR's
*/
extern USER_EXITS_API int SMP_PS_list_bvr_diffs(
    tag_t                 bvr_a,    /**< (I) First BVR to compare */
    tag_t                 bvr_b,    /**< (I) Second BVR to compare */
    int*                  n_diffs,  /**< (O) Number of differences returned */
    SMP_PS_bvr_diff_p_t*  diffs     /**< (OF) n_diffs List of differences */
    );

/**
    Print given list of diffs to given file
*/
extern USER_EXITS_API int SMP_PS_print_bvr_diffs(
    FILE*                 f,        /**< (I) File to which to list the diffs */
    SMP_PS_bvr_diff_p_t   diffs     /**< (I) List of differences */
    );

/**
    Print given list of diffs to given file in MRP format
*/
extern USER_EXITS_API int SMP_PS_mrp_print_bvr_diffs(
    FILE*                 f,        /**< (I) File to which to list the diffs */
    SMP_PS_bvr_diff_p_t   diffs     /**< (I) List of differences */
    );

/**
    Free all memory allocated by #SMP_PS_list_bvr_diffs for the given difference listing
*/
extern USER_EXITS_API int SMP_PS_free_bvr_diffs(
    SMP_PS_bvr_diff_p_t*  diffs     /**< (I) List of differences to free */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <user_exits/libuser_exits_undef.h>

#endif
