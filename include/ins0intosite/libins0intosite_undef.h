/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
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

#if !defined(LIBINS0INTOSITE) && !defined(IPLIB)
#   error IPLIB or LIBINS0INTOSITE is not defined
#endif

#undef INS0INTOSITE_API
#undef INS0INTOSITEEXPORT
#undef INS0INTOSITEGLOBAL
#undef INS0INTOSITEPRIVATE
