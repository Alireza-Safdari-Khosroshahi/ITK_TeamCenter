//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  fsh0fnshmgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libfsh0fnshmgmt

#if !defined(LIBFSH0FNSHMGMT) && !defined(IPLIB)
#   error IPLIB or LIBFSH0FNSHMGMT is not defined
#endif

/* Handwritten code should use FSH0FNSHMGMT_API, not FSH0FNSHMGMTEXPORT */

#define FSH0FNSHMGMT_API FSH0FNSHMGMTEXPORT

#if IPLIB==libfsh0fnshmgmt || defined(LIBFSH0FNSHMGMT)
#   if defined(__lint)
#       define FSH0FNSHMGMTEXPORT       __export(fsh0fnshmgmt)
#       define FSH0FNSHMGMTGLOBAL       extern __global(fsh0fnshmgmt)
#       define FSH0FNSHMGMTPRIVATE      extern __private(fsh0fnshmgmt)
#   elif defined(_WIN32)
#       define FSH0FNSHMGMTEXPORT       __declspec(dllexport)
#       define FSH0FNSHMGMTGLOBAL       extern __declspec(dllexport)
#       define FSH0FNSHMGMTPRIVATE      extern
#   else
#       define FSH0FNSHMGMTEXPORT
#       define FSH0FNSHMGMTGLOBAL       extern
#       define FSH0FNSHMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FSH0FNSHMGMTEXPORT       __export(fsh0fnshmgmt)
#       define FSH0FNSHMGMTGLOBAL       extern __global(fsh0fnshmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FSH0FNSHMGMTEXPORT      __declspec(dllimport)
#       define FSH0FNSHMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define FSH0FNSHMGMTEXPORT
#       define FSH0FNSHMGMTGLOBAL       extern
#   endif
#endif
