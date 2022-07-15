/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the prototypes for the ITK functions for the AliasList class.
*/

/*  */

#ifndef ALIASLIST_H
#define ALIASLIST_H

#include <tccore/workspaceobject.h>
#include <tc/libtc_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup ALIASLIST Alias List
    @ingroup EPM
    @{
*/

extern TC_API int MAIL_aliaslist_extent (
    int*           n_instances,     /**< (O) */
    tag_t**        instances        /**< (OF) n_instances */
    );


extern TC_API int MAIL_create_alias_list2 (
    const char     *name,                       /**< (I) */
    int            no_of_ids,                   /**< (I) */
    const char**   email_ids,                   /**< (I) */
    tag_t*         alias_list                   /**< (O) */
    );


extern TC_API int MAIL_initialize_alias_list2 (
    tag_t          alias_list,                  /**< (I) */
    const char     *name                        /**< (I) */
    );

/**
    Finds a Alias list with the given input name.

    If there is no Alias list with the specified name, 
    the value of Alias list will be #NULLTAG.

    Alias list is same as Address list in RAC.
*/
extern TC_API int MAIL_find_alias_list2 (
    const char     *name,                       /**< (I) */
    tag_t*         alias_list                   /**< (O) */
    );

extern TC_API int MAIL_add_alias_list_member (
    tag_t          alias_list,  /**< (I) */
    char*          member       /**< (I) */
    );

extern TC_API int MAIL_remove_alias_list_member (
    tag_t          alias_list,  /**< (I) */
    char*          member       /**< (I) */
    );

extern TC_API int MAIL_ask_alias_list_members (
    tag_t          alias_list,      /**< (I) */
    int*           member_count,    /**< (O) */
    char***        members          /**< (OF) member_count */
    );

extern TC_API int MAIL_delete_alias_list (
    tag_t          alias_list   /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>
#endif
