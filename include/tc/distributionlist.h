/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the prototypes for the ITK functions for the DistributionList class.
*/

/*  */

#ifndef DISTRIBUTIONLIST_H
#define DISTRIBUTIONLIST_H

#include <tccore/workspaceobject.h>
#include <tc/libtc_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup DISTRIBUTIONLIST Distribution List
    @ingroup TC
    @{
*/

extern TC_API int MAIL_distributionlist_extent(
    int*           n_instances,     /**< (O) */
    tag_t**        instances        /**< (OF) n_instances */
    );


/**
    Creates a new distribution list.
*/
extern TC_API int MAIL_create_distribution_list2 (
    const char     *name,                               /**< (I) */
    const char     *description,                        /**< (I) */
    tag_t*         distribution_list                    /**< (O) */
    );


/**
    Initializes a distribution list.
    You call this function immediately after creating an instance of a subclass of distribution_list.
*/
extern TC_API int MAIL_initialize_distribution_list2 (
    tag_t          distribution_list,                   /**< (I) */
    const char     *name,                               /**< (I) */
    const char     *description                         /**< (I) */
    );


/**
    Finds a distribution list with the given input name.

    If there is no distribution list with the specified name, 
    the value of distribution list will be #NULLTAG.
*/
extern TC_API int MAIL_find_distribution_list2 (
    const char     *name,                       /**< (I) */
    tag_t*         distribution_list            /**< (O) */
    );

/**
    Adds a group, user, groupmember, or distribution list to an existing distribution list.
*/
extern TC_API int MAIL_add_dist_list_member (
    tag_t          distribution_list,   /**< (I) */
    tag_t          member               /**< (I) */
    );

/**
    Removes a user, group, groupmember, or distribution list from a distribution list.
*/
extern TC_API int MAIL_remove_dist_list_member (
    tag_t          distribution_list,   /**< (I) */
    tag_t          member               /**< (I) */
    );

/**
    Returns an array of all of the members of a distribution list. 
    You can free the space used by members with #MEM_free.
*/
extern TC_API int MAIL_ask_dist_list_members (
    tag_t          distribution_list,   /**< (I) */
    int*           member_count,        /**< (O) */
    tag_t**        members              /**< (OF) member_count */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>
#endif
