/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
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

#if !defined(LIBSSF0SERVICEFORECASTING) && !defined(IPLIB)
#   error IPLIB orLIBSSF0SERVICEFORECASTING is not defined
#endif

#undef SSF0SERVICEFORECASTING_API
#undef SSF0SERVICEFORECASTINGEXPORT
#undef SSF0SERVICEFORECASTINGGLOBAL
#undef SSF0SERVICEFORECASTINGPRIVATE
