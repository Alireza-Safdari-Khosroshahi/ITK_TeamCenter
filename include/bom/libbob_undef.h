// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@

/** 
    @file 

    Undefine exports for libbob.
*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef BOB_API
#undef BOBEXPORT
#undef BOBGLOBAL
#undef BOBPRIVATE

