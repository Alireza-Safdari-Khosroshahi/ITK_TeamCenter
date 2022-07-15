/*=============================================================================
           Copyright (c) 1994 Electronic Data Systems Corporation
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H+++  File description:


    File   : method_errors.h
    Module : imancore
===============================================================================
H:::  History:
 date       name        description of change
08-Apr-1994 reed             Created
24-Jun-1994  Vic Nidoy               Add error base
14-Jul-1994  Vic Nidoy               Remove METHOD_object_of_wrong_class
20-Jul-1994  Boma Koko               Promoted from idm_main to main
16-Apr-2002  Sanjay Patel,,,         Adding method table manipulation errors
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
22-Nov-2002  Tim Baverstock          Normalise inclusion
$HISTORY$
H---=========================================================================*/

#ifndef METHOD_ERRORS_H
#define METHOD_ERRORS_H

#ifndef EMH_CONST_H
#include <common/emh_const.h>
#endif
#include <tccore/libtccore_exports.h>

#define METHOD_internal_error       (EMH_METHOD_error_base + 1)
#define METHOD_invalid_type         (EMH_METHOD_error_base + 2)
#define METHOD_already_registered   (EMH_METHOD_error_base + 3)
#define METHOD_invalid_position     (EMH_METHOD_error_base + 4)
#define METHOD_no_methods_to_remove (EMH_METHOD_error_base + 5)
#define METHOD_no_methods_to_move   (EMH_METHOD_error_base + 6)
#define METHOD_no_pre_conditions    (EMH_METHOD_error_base + 7)
#define METHOD_no_pre_actions       (EMH_METHOD_error_base + 8)
#define METHOD_no_post_actions      (EMH_METHOD_error_base + 9)

#include <tccore/libtccore_undef.h>
#endif
