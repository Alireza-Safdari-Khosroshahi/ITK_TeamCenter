// @<COPYRIGHT_START>@
// ==================================================
// Copyright 2007.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that undefines the export symbols for the CE library.

*/

#include <common/library_indicators.h>

#ifdef __lint
#   pragma uginclude only_in_error "libce_main.c", "*.h";
#endif

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CE_API
#undef CEEXPORT
#undef CEGLOBAL
#undef CEPRIVATE
