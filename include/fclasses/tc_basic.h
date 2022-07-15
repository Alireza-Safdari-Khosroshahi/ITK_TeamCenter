/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter basic
*/

/*  */

#ifndef TC_BASIC_H
#define TC_BASIC_H

/** @if DOX_IGNORE
    System wide constants
@endif */
#include <fclasses/tc_stdio.h>
#include <setjmp.h>
#include <unidefs.h>
#include <fclasses/libfclasses_exports.h>

/**
    @addtogroup TC
    @{
*/

#define SUCCESS     NULL
#define MDC_MAXARGS 5

/**
    Status block which is returned by some subroutines
*/
typedef struct mdc_sblock
{
    int                eim_error;           /**< Module error number */
    int                eim_errno;           /**< System error number */
    char*              emsg[MDC_MAXARGS];   /**< Alternate error message */
    struct mdc_sblock* next;                /**< Pointer to next status block */
    struct mdc_sblock* previous;            /**< Pointer to my parent */
} *mdc_status_t;

/**
    This macro is obsolescent and is only included for backwards compatability.
    Please use the == operator directly for all new code.
*/
#define tags_equal(a,b) ((a)==(b))

#ifdef PROTO
#undef PROTO
#endif
#define PROTO(params) params

/** @} */

#include <fclasses/libfclasses_undef.h>
#endif
