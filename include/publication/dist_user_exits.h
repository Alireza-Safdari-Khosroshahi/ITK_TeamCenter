/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the User Exits Distribution ITK interface.
*/

/*  */

#ifndef DIST_USER_EXITS_HHH
#define    DIST_USER_EXITS_HHH

#include <publication/libpublication_exports.h>

/**
    @defgroup DIST_USER_EXITS Distribution User Exits
    @ingroup PUBR
    @{
*/

#ifdef __cplusplus
extern "C" {
#endif

extern PUBLICATION_API int DIST_USER_new_revision_id (
    int                    site_id,     /**< (I) */
    const char*            item_id,     /**< (I) */
    const char*            item_type,   /**< (I) */
    logical*               modifiable,  /**< (O) */
    char**                 rev_id       /**< (OF) */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <publication/libpublication_undef.h>

#endif
