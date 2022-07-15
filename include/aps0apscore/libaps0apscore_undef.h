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

#if !defined(LIBAPS0APSCORE) && !defined(IPLIB)
#   error IPLIB or LIBAPS0APSCORE is not defined
#endif

#undef APS0APSCORE_API
#undef APS0APSCOREEXPORT
#undef APS0APSCOREGLOBAL
#undef APS0APSCOREPRIVATE
