//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//e
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  CPA0capadatamodel

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libCPA0capadatamodel

#if !defined(LIBCPA0CAPADATAMODEL) && !defined(IPLIB)
#   error IPLIB or LIBCPA0CAPADATAMODEL is not defined
#endif

/* Handwritten code should use CPA0CAPADATAMODEL_API, not CPA0CAPADATAMODELEXPORT */

#define CPA0CAPADATAMODEL_API CPA0CAPADATAMODELEXPORT

#if IPLIB==libCPA0capadatamodel || defined(LIBCPA0CAPADATAMODEL)
#   if defined(__lint)
#       define CPA0CAPADATAMODELEXPORT       __export(CPA0capadatamodel)
#       define CPA0CAPADATAMODELGLOBAL       extern __global(CPA0capadatamodel)
#       define CPA0CAPADATAMODELPRIVATE      extern __private(CPA0capadatamodel)
#   elif defined(_WIN32)
#       define CPA0CAPADATAMODELEXPORT       __declspec(dllexport)
#       define CPA0CAPADATAMODELGLOBAL       extern __declspec(dllexport)
#       define CPA0CAPADATAMODELPRIVATE      extern
#   else
#       define CPA0CAPADATAMODELEXPORT
#       define CPA0CAPADATAMODELGLOBAL       extern
#       define CPA0CAPADATAMODELPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CPA0CAPADATAMODELEXPORT       __export(CPA0capadatamodel)
#       define CPA0CAPADATAMODELGLOBAL       extern __global(CPA0capadatamodel)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CPA0CAPADATAMODELEXPORT      __declspec(dllimport)
#       define CPA0CAPADATAMODELGLOBAL       extern __declspec(dllimport)
#   else
#       define CPA0CAPADATAMODELEXPORT
#       define CPA0CAPADATAMODELGLOBAL       extern
#   endif
#endif
