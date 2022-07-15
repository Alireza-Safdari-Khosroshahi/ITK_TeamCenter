/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains macros and function prototypes for the
    C ITK functions for Revision Anchor
*/

/*  */

#ifndef REVISIONANCHOR_H
#define REVISIONANCHOR_H

#include <unidefs.h>

#include <ae/ae_types.h>
#include <ae/libae_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup REVISIONANCHOR Revision Anchor
    @ingroup AE

    The latest current revision can be obtained with:

    @code
    { 
        int stat;
        tag_t revAnch, latest;
        int count;

        stat = AE_count_anchor_revisions (revAnch, &count); 
        if( stat == ITK_ok ) 
        {
            stat = AE_ask_anchor_revision (revAnch, count-1, &latest); 
        }
    } 
    @endcode
    @{
*/

/**
    Returns tags for all of the revision anchors in the database.
*/
extern AE_API int AE_revisionanchor_extent(
    int*          n_instances,  /**< (O) */
    tag_t**       instances     /**< (OF) n_instances */
    );


/**
    Initializes standard revision anchor attributes for a newly created instance of a subclass of revision anchor.
*/
extern AE_API int AE_initialize_rev_anchor(
    tag_t         revision_anchor,      /**< (I) */
    int           keep_n_revisions      /**< (I) */
    );

/**
    Appends a new revision to an existing revision anchor. 
    The revision anchor must be saved for the change to be in the data base.
*/
extern AE_API int AE_append_anchor_revision(
    tag_t         revision_anchor,  /**< (I) */
    tag_t         new_revision      /**< (I) */
    );

/**
    Reads information about the revisions that a revision anchor is keeping track of. 
    The revision index starts at 0.

    The highest revision returns the total number of revisions ever created. 
    This would include revisions that have since been deleted.
*/
extern AE_API int AE_ask_anchor_revision(
    tag_t         revision_anchor,  /**< (I) */
    int           revision_index,   /**< (I) */
    tag_t*        a_revision        /**< (O) */
    );

/**
    Manipulates the revision chain for an existing revision anchor.

    #AE_remove_anchor_revision removes a specific revision from the chain.
*/
extern AE_API int AE_remove_anchor_revision(
    tag_t         revision_anchor,  /**< (I) */
    tag_t         a_revision        /**< (I) */
    );

/**
    Manipulates the revision chain for an existing revision anchor.

    #AE_anchor_make_room deletes all old revisions that are not being referenced up to the keep limit.
    This makes room for another new version and still keeps the total revision count
    as high as before the new revision was appended.
*/
extern AE_API int AE_purge_anchor_revisions(
    tag_t         revision_anchor   /**< (I) */
    );

/**
    Manipulates the revision chain for an existing revision anchor.

    #AE_purge_anchor_revisions removes all unreferenced revisions except for the latest.
*/
extern AE_API int AE_anchor_make_room(
    tag_t         revision_anchor   /**< (I) */
    );

/**
    Reads information about the revisions that a revision anchor is keeping track of.
    The revision index starts at 0.

    The highest revision returns the total number of revisions ever created. 
    This would include revisions that have since been deleted.
*/
extern AE_API int AE_ask_anchor_rev_index(
    tag_t         revision_anchor,  /**< (I) */
    tag_t         a_revision,       /**< (I) */
    int*          revision_index    /**< (O) */
    );

/**
    Reads information about the revisions that a revision anchor is keeping track of.
    The revision index starts at 0.

    The highest revision returns the total number of revisions ever created. 
    This would include revisions that have since been deleted.
*/
extern AE_API int AE_count_anchor_revisions(
    tag_t         revision_anchor,  /**< (I) */
    int*          revision_count    /**< (O) */
    );

/**
    Reads information about the revisions that a revision anchor is keeping track of. 
    The revision index starts at 0.

    The highest revision returns the total number of revisions ever created.
    This would include revisions that have since been deleted.
*/
extern AE_API int AE_ask_anchor_highest_revision(
    tag_t         revision_anchor,      /**< (I) */
    int*          the_highest_revision  /**< (O) */
    );

/**
    This function will return the number of revisions that the given RevisionAnchor will keep.
*/
extern AE_API int AE_ask_anchor_keep_limit(
    tag_t         revision_anchor,      /**< (I) */
    int*          current_keep_limit    /**< (O) */
    );

/**
    Manipulates the value for keep limit for a revision anchor.
*/
extern AE_API int AE_set_anchor_keep_limit(
    tag_t         revision_anchor,  /**< (I) */
    int           new_keep_limit    /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ae/libae_undef.h>
#endif
