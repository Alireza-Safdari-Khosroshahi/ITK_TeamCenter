/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Access Manager Conversion functions
*/

/*  */

#ifndef AM_CONVERSION_H
#define AM_CONVERSION_H

#include <sa/libsa_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup AM_CONVERSION Conversion
    @ingroup AM
    @{
*/

SA_API tag_t AM_read_priv (void);

SA_API tag_t AM_write_priv (void);

SA_API tag_t AM_delete_priv (void);

SA_API tag_t AM_change_priv (void);

SA_API tag_t AM_copy_priv (void);

SA_API tag_t AM_promote_priv (void);

SA_API tag_t AM_demote_priv (void);

SA_API void AM_priv_exit (void);

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif

