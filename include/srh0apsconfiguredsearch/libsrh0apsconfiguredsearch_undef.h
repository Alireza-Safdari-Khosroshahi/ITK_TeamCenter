/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBSRH0APSCONFIGUREDSEARCH) && !defined(IPLIB)
#   error IPLIB orLIBSRH0APSCONFIGUREDSEARCH is not defined
#endif

#undef SRH0APSCONFIGUREDSEARCH_API
#undef SRH0APSCONFIGUREDSEARCHEXPORT
#undef SRH0APSCONFIGUREDSEARCHGLOBAL
#undef SRH0APSCONFIGUREDSEARCHPRIVATE
