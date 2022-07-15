/*=============================================================================
           Copyright (c) 2004 UGS PLM Solutions
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H  File description:

    This file contains all the publish error numbers.

    File   : publish_errors.h
    Module : publish 
===============================================================================
H:::  History:
 date       name        description of change
19-Jul-2004  guthrie                 initial
23-Jul-2004  guthrie                 initial
20-Sep-2004  guthrie                 Merged from P10.0.0.3 and eug_p10.0.0.4
29-Nov-2004  guthrie                 Fixed error
10-Oct-2005  guthrie                 Merged VisPub to 10.0.1
$HISTORY$
H---=========================================================================*/

#ifndef PUBLISH_ERRORS_H
#define PUBLISH_ERRORS_H

#include <common/emh_const.h>

#include <vispublish/libvispublish_exports.h>

#define PUBLISH_invalid_primary                        (EMH_PUBLISH_error_base + 1)
#define PUBLISH_invalid_secondary                      (EMH_PUBLISH_error_base + 2)

#include <vispublish/libvispublish_undef.h>
#endif
