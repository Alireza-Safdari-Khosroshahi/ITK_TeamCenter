/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright $2017.
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

#if !defined(LIBCPD0MMV) && !defined(IPLIB)
#   error IPLIB orLIBCPD0MMV is not defined
#endif

#undef CPD0MMV_API
#undef CPD0MMVEXPORT
#undef CPD0MMVGLOBAL
#undef CPD0MMVPRIVATE
