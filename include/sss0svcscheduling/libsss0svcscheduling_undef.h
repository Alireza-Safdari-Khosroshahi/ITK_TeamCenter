//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBSSS0SVCSCHEDULING) && !defined(IPLIB)
#   error IPLIB orLIBSSS0SVCSCHEDULING is not defined
#endif

#undef SSS0SVCSCHEDULING_API
#undef SSS0SVCSCHEDULINGEXPORT
#undef SSS0SVCSCHEDULINGGLOBAL
#undef SSS0SVCSCHEDULINGPRIVATE
