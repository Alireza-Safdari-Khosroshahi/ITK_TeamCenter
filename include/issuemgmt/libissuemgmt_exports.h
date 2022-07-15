//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  issuemgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libissuemgmt

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use ISSUEMGMT_API, not ISSUEMGMTEXPORT */

#define ISSUEMGMT_API ISSUEMGMTEXPORT

#if IPLIB==libissuemgmt
#   if defined(__lint)
#       define ISSUEMGMTEXPORT       __export(issuemgmt)
#       define ISSUEMGMTGLOBAL       extern __global(issuemgmt)
#       define ISSUEMGMTPRIVATE      extern __private(issuemgmt)
#   elif defined(_WIN32)
#       define ISSUEMGMTEXPORT       __declspec(dllexport)
#       define ISSUEMGMTGLOBAL       extern __declspec(dllexport)
#       define ISSUEMGMTPRIVATE      extern
#   else
#       define ISSUEMGMTEXPORT
#       define ISSUEMGMTGLOBAL       extern
#       define ISSUEMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ISSUEMGMTEXPORT       __export(issuemgmt)
#       define ISSUEMGMTGLOBAL       extern __global(issuemgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ISSUEMGMTEXPORT      __declspec(dllimport)
#       define ISSUEMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define ISSUEMGMTEXPORT
#       define ISSUEMGMTGLOBAL       extern
#   endif
#endif
