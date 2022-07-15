/*=============================================================================
            Copyright (c) 2004 UGS Inc.
            Unpublished - All rights reserved
===============================================================================
File Description:

    The header file that undefines the export symbols for the
    userext library
 */
#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libuserext_main.c", "*.h";
#endif

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define EXPORTLIBRARY            libuserext

#define USER_LIBRARY_NAME libuserext
#define USER_EXT_DLL_API USEREXTEXPORT

#if IPLIB==USER_LIBRARY_NAME
#   if defined(__lint)
#       define USEREXTEXPORT       __export(USER_EXT_LIBRARY_ID_NAME)
#       define USEREXTGLOBAL       extern __global(USER_EXT_LIBRARY_ID_NAME)
#       define USEREXTPRIVATE      extern __private(USER_EXT_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define USEREXTEXPORT       __declspec(dllexport)
#       define USEREXTGLOBAL       extern __declspec(dllexport)
#       define USEREXTPRIVATE      extern
#   else
#       define USEREXTEXPORT
#       define USEREXTGLOBAL       extern
#       define USEREXTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define USEREXTEXPORT       __export(USER_EXT_LIBRARY_ID_NAME)
#       define USEREXTGLOBAL       extern __global(USER_EXT_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define USEREXTEXPORT       __declspec(dllimport)
#       define USEREXTGLOBAL       extern __declspec(dllimport)
#   else
#       define USEREXTEXPORT
#       define USEREXTGLOBAL       extern
#   endif
#endif
