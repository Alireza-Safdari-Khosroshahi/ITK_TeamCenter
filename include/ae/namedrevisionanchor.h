/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains macros and function prototypes of the
    C ITK functions for the NamedRevisionAnchor class.
*/

/*  */

#ifndef NAMEDREVISIONANCHOR_H
#define NAMEDREVISIONANCHOR_H

#include <ae/ae_types.h>
#include <ae/libae_exports.h>

/**
    @defgroup NAMEDREVISIONANCHOR Named Revision Anchor
    @ingroup AE
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif



extern AE_API int AE_find_nra2(
    const char    *aName,                               /**< (I) */
    int*          nFound,                               /**< (O) */
    tag_t**       aNamedRevisionAnchor                  /**< (OF) nFound */
    );

/**
    @name Instance manipulation functions
    @{
*/



extern AE_API int AE_initialize_nra2(
    tag_t         aNamedRevisionAnchor,                 /**< (I) */
    const char    *aName                                /**< (I) */
    );



extern AE_API int AE_set_nra_name2(
    tag_t         aNamedRevisionAnchor,                 /**< (I) */
    const char    *aName                                /**< (I) */
    );


extern AE_API int AE_ask_nra_name2(
    tag_t         aNamedRevisionAnchor,                 /**< (I) */
    char          **aName                               /**< (OF) */
    );

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <ae/libae_undef.h>
#endif
