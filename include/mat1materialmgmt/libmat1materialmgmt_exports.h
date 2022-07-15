//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  mat1materialmgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libmat1materialmgmt

#if !defined(LIBMAT1MATERIALMGMT) && !defined(IPLIB)
#   error IPLIB or LIBMAT1MATERIALMGMT is not defined
#endif

/* Handwritten code should use MAT1MATERIALMGMT_API, not MAT1MATERIALMGMTEXPORT */

#define MAT1MATERIALMGMT_API MAT1MATERIALMGMTEXPORT

#if IPLIB==libmat1materialmgmt || defined(LIBMAT1MATERIALMGMT)
#   if defined(__lint)
#       define MAT1MATERIALMGMTEXPORT       __export(mat1materialmgmt)
#       define MAT1MATERIALMGMTGLOBAL       extern __global(mat1materialmgmt)
#       define MAT1MATERIALMGMTPRIVATE      extern __private(mat1materialmgmt)
#   elif defined(_WIN32)
#       define MAT1MATERIALMGMTEXPORT       __declspec(dllexport)
#       define MAT1MATERIALMGMTGLOBAL       extern __declspec(dllexport)
#       define MAT1MATERIALMGMTPRIVATE      extern
#   else
#       define MAT1MATERIALMGMTEXPORT
#       define MAT1MATERIALMGMTGLOBAL       extern
#       define MAT1MATERIALMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MAT1MATERIALMGMTEXPORT       __export(mat1materialmgmt)
#       define MAT1MATERIALMGMTGLOBAL       extern __global(mat1materialmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MAT1MATERIALMGMTEXPORT      __declspec(dllimport)
#       define MAT1MATERIALMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define MAT1MATERIALMGMTEXPORT
#       define MAT1MATERIALMGMTGLOBAL       extern
#   endif
#endif
