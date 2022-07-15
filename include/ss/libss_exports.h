/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the SS library
 */

#define libss                    -10082

#ifdef EXPORTLIBRARY
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libss

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use SS_API, not SSEXPORT */

#define SS_API SSEXPORT

/* Support SSEXPORT for autogenerated code only */

#if IPLIB==libss
#   if defined(__lint)
#       define SSEXPORT       __export(ss)
#       define SSGLOBAL       extern __global(ss)
#       define SSPRIVATE      extern __private(ss)
#   elif defined(_WIN32)
#       define SSEXPORT       __declspec(dllexport)
#       define SSGLOBAL       extern __declspec(dllexport)
#       define SSPRIVATE      extern
#   else
#       define SSEXPORT
#       define SSGLOBAL       extern
#       define SSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SSEXPORT       __export(ss)
#       define SSGLOBAL       extern __global(ss)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SSEXPORT      __declspec(dllimport)
#       define SSGLOBAL       extern __declspec(dllimport)
#   else
#       define SSEXPORT
#       define SSGLOBAL       extern
#   endif
#endif