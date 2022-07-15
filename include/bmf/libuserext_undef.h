/*=============================================================================
            Copyright (c) 2004 UGS Inc.
            Unpublished - All rights reserved
===============================================================================
File Description:

    The header file that undefines the export symbols for the
    userext library
 */
#include <common/library_indicators.h>

#ifdef __lint
#   pragma uginclude only_in_error "libuserext_main.c", "*.h";
#endif

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef USER_EXT_DLL_API
#undef USEREXTEXPORT
#undef USEREXTGLOBAL
#undef USEREXTPRIVATE
