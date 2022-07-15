/*=============================================================================
           Copyright (c) 2000 Unigraphics Solutions
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H+++  File description:

    File   : tcparameters_errors.h
    Module : tccore
===============================================================================
History:
   date         name                 description of change
21-Sep-2001  Sanjay Patel,,,         Initial Version
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splittc project
22-Nov-2002  Tim Baverstock          Normalise inclusion
13-Feb-2006  Johann Chemin-Danielson  de-Imanization
$HISTORY$
=========================================================================*/

#ifndef TCPARAMETERS_ERRORS_H
#define TCPARAMETERS_ERRORS_H

#ifndef EMH_CONST_H
#include <common/emh_const.h>
#endif
#include <tccore/libtccore_exports.h>

#define TCPARAMETERS_class_not_initialized     (EMH_PARAMETERS_error_base + 0)
#define TCPARAMETERS_internal_error            (EMH_PARAMETERS_error_base + 1)
#define TCPARAMETERS_invalid_param_count       (EMH_PARAMETERS_error_base + 2)
#define TCPARAMETERS_invalid_param_value       (EMH_PARAMETERS_error_base + 3)
#define TCPARAMETERS_invalid_param_value_len   (EMH_PARAMETERS_error_base + 4)

#include <tccore/libtccore_undef.h>
#endif /*TCPARAMETERS_ERRORS_H*/
