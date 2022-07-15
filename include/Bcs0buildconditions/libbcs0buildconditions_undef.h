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

#if !defined(LIBBCS0BUILDCONDITIONS) && !defined(IPLIB)
#   error IPLIB orLIBBCS0BUILDCONDITIONS is not defined
#endif

#undef BCS0BUILDCONDITIONS_API
#undef BCS0BUILDCONDITIONSEXPORT
#undef BCS0BUILDCONDITIONSGLOBAL
#undef BCS0BUILDCONDITIONSPRIVATE
