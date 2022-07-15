/*HEAD LIBVISPUBLISH_EXPORTS HHH PUBLISH */
/*=============================================================================
                Copyright (c) 2004 UGS PLM Solutions
                             Unpublished - All rights reserved
===============================================================================
File Description:

     The header file that undefines the export symbols for the
     PUBLISH library

===============================================================================
Date          Name                   Description
23-Jul-2004  guthrie                 Initial
20-Sep-2004  guthrie                 Merged from P10.0.0.3 and eug_p10.0.0.4
10-Oct-2005  guthrie                 Merged VisPub to 10.0.1
$HISTORY$
60============================================================================*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef VISPUBLISH_API
#undef VISPUBLISHEXPORT
#undef VISPUBLISHGLOBAL
#undef VISPUBLISHPRIVATE

