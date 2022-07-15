// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that undefines the export symbols for the RBF library.

*/

#include <common/library_indicators.h>

#ifdef __lint
#   pragma uginclude only_in_error "librbf_main.c", "*.h";
#endif

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef RBF_API
#undef RBFEXPORT
#undef RBFGLOBAL
#undef RBFPRIVATE
