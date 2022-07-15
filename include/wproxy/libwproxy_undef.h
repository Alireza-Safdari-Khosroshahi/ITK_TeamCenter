// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/**
    @file

    Undefines the export symbols for the WPROXY library

*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef WPROXY_API
#undef WPROXYEXPORT
#undef WPROXYGLOBAL
#undef WPROXYPRIVATE
