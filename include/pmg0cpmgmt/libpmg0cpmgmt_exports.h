/*
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2017.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
//@file
/This file contains the declaration for the Dispatch Library  pmg0cpmgmt
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libpmg0cpmgmt

#if !defined(LIBPMG0CPMGMT) && !defined(IPLIB)
#   error IPLIB or LIBPMG0CPMGMT is not defined
#endif

/* Handwritten code should use PMG0CPMGMT_API, not PMG0CPMGMTEXPORT */

#define PMG0CPMGMT_API PMG0CPMGMTEXPORT

#if IPLIB==libpmg0cpmgmt || defined(LIBPMG0CPMGMT)
#   if defined(__lint)
#       define PMG0CPMGMTEXPORT       __export(pmg0cpmgmt)
#       define PMG0CPMGMTGLOBAL       extern __global(pmg0cpmgmt)
#       define PMG0CPMGMTPRIVATE      extern __private(pmg0cpmgmt)
#   elif defined(_WIN32)
#       define PMG0CPMGMTEXPORT       __declspec(dllexport)
#       define PMG0CPMGMTGLOBAL       extern __declspec(dllexport)
#       define PMG0CPMGMTPRIVATE      extern
#   else
#       define PMG0CPMGMTEXPORT
#       define PMG0CPMGMTGLOBAL       extern
#       define PMG0CPMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PMG0CPMGMTEXPORT       __export(pmg0cpmgmt)
#       define PMG0CPMGMTGLOBAL       extern __global(pmg0cpmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PMG0CPMGMTEXPORT      __declspec(dllimport)
#       define PMG0CPMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define PMG0CPMGMTEXPORT
#       define PMG0CPMGMTGLOBAL       extern
#   endif
#endif
