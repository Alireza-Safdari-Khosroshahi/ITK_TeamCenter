/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the PIE library
 */

#ifdef __lint
#   pragma uginclude only_in_error "libpie_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libpie

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define PIE_LIBRARY_NAME libpie
#define PIE_LIBRARY_ID_NAME pie

#if IPLIB==PIE_LIBRARY_NAME
#   if defined(__lint)
#       define PIEEXPORT       __export(PIE_LIBRARY_ID_NAME)
#       define PIEGLOBAL       extern __global(PIE_LIBRARY_ID_NAME)
#       define PIEPRIVATE      extern __private(PIE_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define PIEEXPORT       __declspec(dllexport)
#       define PIEGLOBAL       extern __declspec(dllexport)
#       define PIEPRIVATE      extern
#   else
#       define PIEEXPORT
#       define PIEGLOBAL       extern
#       define PIEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PIEEXPORT       __export(PIE_LIBRARY_ID_NAME)
#       define PIEGLOBAL       extern __global(PIE_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PIEEXPORT       __declspec(dllimport)
#       define PIEGLOBAL       extern __declspec(dllimport)
#   else
#       define PIEEXPORT
#       define PIEGLOBAL       extern
#   endif
#endif
#define PIE_API PIEEXPORT
