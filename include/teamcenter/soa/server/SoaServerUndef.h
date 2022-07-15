/*=============================================================================
                Copyright (c) 1999 Unigraphics Solutions Inc.
                             All rights reserved
===============================================================================
File Description:

     The header file that undefines the export symbols for the
     TCSOASERVER library

===============================================================================
Date          Name                   Description
19-Dec-2005  Ron Marchi              initial version
$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef TCSOASERVER_API
#undef TCSOASERVEREXPORT
#undef TCSOASERVERGLOBAL
#undef TCSOASERVERPRIVATE

