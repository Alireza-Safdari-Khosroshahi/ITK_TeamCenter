/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the Tcservices code


*/

/** @if HISTORY_SECTION
====================================================================================================
   Date      Name                    Description of Change

04-Apr-2005  James Foster            Errors for tcservices
$HISTORY$
==================================================================================================
@endif */

#ifndef TCSERVICES_ERRORS_H
#define TCSERVICES_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCSERVICES_ERRORS TCSERVICES Errors
    @ingroup TCSERVICES
    @{
*/

/** Attempting to use old login method. */
#define TCSERVICES_deprecated_login                               (EMH_TCSERVICES_error_base + 1)


/** @} */

#endif

