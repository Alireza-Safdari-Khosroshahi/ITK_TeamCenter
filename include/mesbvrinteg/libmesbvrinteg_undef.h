/*HEAD LIBCMTMESINTEG_EXPORTS HHH CMTMESINTEG */
/*=============================================================================
                Copyright (c) 2008 Unigraphics Solutions Inc.
                             Unpublished - All rights reserved
===============================================================================
File Description:

     The header file that undefines the export symbols for the
     CMTMESINTEG library

===============================================================================
Date          Name                                    Description
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

#undef MESBVRINTEG_API
#undef CMTMESINTEGEXPORT
#undef CMTMESINTEGGLOBAL
#undef CMTMESINTEGPRIVATE

