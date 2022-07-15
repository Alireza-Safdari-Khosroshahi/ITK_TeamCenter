// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    Undefines the export symbols for the TIE library

*/

#include <common/library_indicators.h>

#ifdef __lint
#   pragma uginclude only_in_error "libtie_main.c", "*.h";
#endif

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef TIE_API
#undef TIEEXPORT
#undef TIEGLOBAL
#undef TIEPRIVATE
