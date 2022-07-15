/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that undefines the export symbols for the POM library
 */

#ifdef __lint
#   pragma uginclude only_in_error "libpom_main.c", "*.h";
#endif

#define libpom                  1010017

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef POMAPI
#undef POMEXPORT
#undef POMGLOBAL
#undef POMPRIVATE


