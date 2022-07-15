/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
 
/** 
    @file 
 
    The header file that defines export symbols for the variabilityadaptor library.
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libvariabilityadaptor

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define VARIABILITYADAPTOR_API VARIABILITYADAPTOREXPORT

#if IPLIB==libvariabilityadaptor
#   if defined(__lint)
#       define VARIABILITYADAPTOREXPORT       __export(libvariabilityadaptor)
#       define VARIABILITYADAPTORGLOBAL       extern __global(libvariabilityadaptor)
#       define VARIABILITYADAPTORPRIVATE      extern __private(libvariabilityadaptor)
#   elif defined(_WIN32)
#       define VARIABILITYADAPTOREXPORT       __declspec(dllexport)
#       define VARIABILITYADAPTORGLOBAL       extern __declspec(dllexport)
#       define VARIABILITYADAPTORPRIVATE      extern
#   else
#       define VARIABILITYADAPTOREXPORT
#       define VARIABILITYADAPTORGLOBAL       extern
#       define VARIABILITYADAPTORPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define VARIABILITYADAPTOREXPORT       __export(libvariabilityadaptor)
#       define VARIABILITYADAPTORGLOBAL       extern __global(libvariabilityadaptor)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define VARIABILITYADAPTOREXPORT      __declspec(dllimport)
#       define VARIABILITYADAPTORGLOBAL       extern __declspec(dllimport)
#   else
#       define VARIABILITYADAPTOREXPORT
#       define VARIABILITYADAPTORGLOBAL       extern
#   endif
#endif
