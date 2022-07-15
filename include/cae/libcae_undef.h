/*HEAD LIBCAE_EXPORTS HHH CAE */
/*=============================================================================
                Copyright (c) 1999 Unigraphics Solutions Inc.
                             Unpublished - All rights reserved
===============================================================================
File Description:

     The header file that undefines the export symbols for the
     CAE library

===============================================================================
Date          Name                   Description
09-May-2004   Charles Cheng          Initial creation.
03-Jun-2004  chengc                  New release
$HISTORY$
============================================================================*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CAE_API
#undef CAEEXPORT
#undef CAEGLOBAL
#undef CAEPRIVATE

