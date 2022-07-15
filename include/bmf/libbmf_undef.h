/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that undefines the export symbols for the BMF library
 */

#include <common/library_indicators.h>

#ifdef __lint
#   pragma uginclude only_in_error "libbmf_main.c", "*.h";
#endif

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef BMF_API
#undef BMFEXPORT
#undef BMFGLOBAL
#undef BMFPRIVATE
