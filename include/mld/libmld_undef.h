// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2011.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @file
    Undefine macros related to specifying export symbols for the mld library.
*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef MLD_API
#undef MLDEXPORT
#undef MLDGLOBAL
#undef MLDPRIVATE
