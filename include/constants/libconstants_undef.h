// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2007 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that undefines the export symbols for the CONSTANTS library.

*/

#include <common/library_indicators.h>

#ifdef __lint
#   pragma uginclude only_in_error "libconstants_main.c", "*.h";
#endif

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CONSTANTS_API
#undef CONSTANTSEXPORT
#undef CONSTANTSGLOBAL
#undef CONSTANTSPRIVATE
