/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2013.
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

#if !defined(LIBMDO0MDO) && !defined(IPLIB)
#   error IPLIB or LIBMDO0MDO is not defined
#endif

#undef MDO0MDO_API
#undef MDO0MDOEXPORT
#undef MDO0MDOGLOBAL
#undef MDO0MDOPRIVATE
