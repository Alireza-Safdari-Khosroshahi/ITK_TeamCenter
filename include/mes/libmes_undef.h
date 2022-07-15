/*HEAD LIBCMTMES_EXPORTS HHH CMTMES */
/*=============================================================================
                Copyright (c) 2008 Unigraphics Solutions Inc.
                             Unpublished - All rights reserved
===============================================================================
File Description:

     The header file that undefines the export symbols for the
     CMTMES library

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

#undef MES_API
#undef CMTMESEXPORT
#undef CMTMESGLOBAL
#undef CMTMESPRIVATE

