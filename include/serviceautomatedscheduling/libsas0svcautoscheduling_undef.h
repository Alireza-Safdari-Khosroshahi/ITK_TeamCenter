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

#if !defined(LIBSAS0SVCAUTOSCHEDULING) && !defined(IPLIB)
#   error IPLIB orLIBSAS0SVCAUTOSCHEDULING is not defined
#endif

#undef SAS0SVCAUTOSCHEDULING_API
#undef SAS0SVCAUTOSCHEDULINGEXPORT
#undef SAS0SVCAUTOSCHEDULINGGLOBAL
#undef SAS0SVCAUTOSCHEDULINGPRIVATE
