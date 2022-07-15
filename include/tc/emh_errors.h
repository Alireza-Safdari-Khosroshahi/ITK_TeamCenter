/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error Message Handler errors
*/

/*  */

#ifndef EMH_ERRORS_H
#define EMH_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EMH_ERRORS Errors
    @ingroup EMH
    @{
*/

/** Tried to modify error chain */
#define EMH_MODEBLOCK       (EMH_EMH_error_base + 1)

/** Out of memory */
#define EMH_NOMEMORY        (EMH_EMH_error_base + 2)

/** Can't destroy error block */
#define EMH_NODESERR        (EMH_EMH_error_base + 3)

/** Error list is NULL */
#define EMH_NOERRORS        ERROR_ERRORSTORE_NOERRORS

/** Status block not found */
#define EMH_SBNOTFOUND      (EMH_EMH_error_base + 5)

/** Too many arguments */
#define EMH_TOOMANYARGS     (EMH_EMH_error_base + 6)

/** No error blocks available */
#define EMH_NOEBLOCK        (EMH_EMH_error_base + 7)

/** No error has been set */
#define EMH_NO_ERROR        (EMH_EMH_error_base + 8)

/** Invalid tag */
#define EMH_INV_TAG         (EMH_EMH_error_base + 9)

/** @if DOX_IGNORE
    Error message is "%1$" so we can put in our own string
@endif */
#define EMH_GENERIC_ERROR   (EMH_EMH_error_base + 10)

/** @if DOX_IGNORE
    Used in AOS ITKAOS_xxx_less_than tests when the limit is over-generous
@endif */
#define EMH_AOS_LIMIT_TOO_BIG (EMH_EMH_error_base + 11)

/** @if DOX_IGNORE
    Error 20 because EMH is 2000 so the error 2020 is recognisable
    (and unfortunately common) in our tests
@endif */

/**
    Used by AOS to mark the stack to catch people who go
    return ERROR_store_ask_last_ifail() without justification
*/
#define EMH_AOS_EMPTY_STACK (EMH_EMH_error_base + 20)

/** @} */

#endif
