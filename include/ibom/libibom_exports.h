/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    The header file that defines the export symbols for the Index BOM library

*/
#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libibom

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define IBOM_LIBRARY_NAME  libibom
#define IBOM_LIBRARY_ID_NAME ibom

#if IPLIB==IBOM_LIBRARY_NAME
#   if defined(__lint)
#       define IBOMEXPORT       __export(IBOM_LIBRARY_ID_NAME)
#       define IBOMGLOBAL       extern __global(IBOM_LIBRARY_ID_NAME)
#       define IBOMPRIVATE      extern __private(IBOM_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define IBOMEXPORT       __declspec(dllexport)
#       define IBOMGLOBAL       extern __declspec(dllexport)
#       define IBOMPRIVATE      extern
#   else
#       define IBOMEXPORT
#       define IBOMGLOBAL       extern
#       define IBOMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define IBOMEXPORT       __export(IBOM_LIBRARY_ID_NAME)
#       define IBOMGLOBAL       extern __global(IBOM_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define IBOMEXPORT       __declspec(dllimport)
#       define IBOMGLOBAL       extern __declspec(dllimport)
#   else
#       define IBOMEXPORT
#       define IBOMGLOBAL       extern
#   endif
#endif
#define IBOM_API IBOMEXPORT
