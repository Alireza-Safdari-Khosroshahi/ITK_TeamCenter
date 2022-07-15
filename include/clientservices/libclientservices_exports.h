//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    Defines the export symbols for the clientservices library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY                                   libclientservices

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CLIENTSERVICES_LIBRARY_NAME                     libclientservices
#define CLIENTSERVICES_LIBRARY_ID_NAME                  clientservices

#if IPLIB==CLIENTSERVICES_LIBRARY_NAME
#   if defined(__lint)
#       define CLIENTSERVICESEXPORT                     __export(CLIENTSERVICES_LIBRARY_ID_NAME)
#       define CLIENTSERVICESGLOBAL                     extern __global(CLIENTSERVICES_LIBRARY_ID_NAME)
#       define CLIENTSERVICESPRIVATE                    extern __private(CLIENTSERVICES_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CLIENTSERVICESEXPORT                     __declspec(dllexport)
#       define CLIENTSERVICESGLOBAL                     extern __declspec(dllexport)
#       define CLIENTSERVICESPRIVATE                    extern
#   else
#       define CLIENTSERVICESEXPORT
#       define CLIENTSERVICESGLOBAL                     extern
#       define CLIENTSERVICESPRIVATE                    extern
#   endif
#else
#   if defined(__lint)
#       define CLIENTSERVICESEXPORT                     __export(CLIENTSERVICES_LIBRARY_ID_NAME)
#       define CLIENTSERVICESGLOBAL                     extern __global(CLIENTSERVICES_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CLIENTSERVICESEXPORT                     __declspec(dllimport)
#       define CLIENTSERVICESGLOBAL                     extern __declspec(dllimport)
#   else
#       define CLIENTSERVICESEXPORT
#       define CLIENTSERVICESGLOBAL                     extern
#   endif
#endif

#define CLIENTSERVICES_API CLIENTSERVICESEXPORT
