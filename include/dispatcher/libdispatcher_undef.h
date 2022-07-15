/*==================================================================================================
         Copyright (c) 2003 Electronic Data Systems Corporation
               Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                           HOLDER.
====================================================================================================
File description:   This header file undefines the export symbols for the
                    DISPATCHER library

      Filename:   libets_undef.h
      Module  :   DISPATCHER

====================================================================================================
   Date     Name               Description of Change
21-Sep-2004  peschell                initial version
22-Sep-2004  peschell                Comment out include of library_exports.h, does not exist for 8.1.1 and does not contribute anything
25-Oct-2005  peschell                add module to include statements and enable library_indicators include
$HISTORY$
==================================================================================================*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef DISPATCHER_API
#undef DISPATCHEREXPORT
#undef DISPATCHERGLOBAL
#undef DISPATCHERPRIVATE

