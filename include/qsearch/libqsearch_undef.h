// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2008 Siemens Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@

/** 
    @file 

    Undefine exports for libqsearch
.
*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef QSEARCH_API
#undef QSEARCHEXPORT
#undef QSEARCHGLOBAL
#undef QSEARCHPRIVATE
