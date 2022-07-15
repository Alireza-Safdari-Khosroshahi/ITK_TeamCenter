// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2009.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @file
    Undefine macros related to specifying export symbols for base utilities library.
*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef BASE_UTILS_API
#undef BASE_UTILSEXPORT
#undef BASE_UTILSGLOBAL
#undef BASE_UTILSPRIVATE
