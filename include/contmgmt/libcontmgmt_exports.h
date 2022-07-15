//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2008.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  contmgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcontmgmt

#if !defined(LIBCONTMGMT) && !defined(IPLIB)
#   error IPLIB or LIBCONTMGMT is not defined
#endif

/* Handwritten code should use CONTMGMT_API, not CONTMGMTEXPORT */

#define CONTMGMT_API CONTMGMTEXPORT

#if IPLIB==libcontmgmt || defined(LIBCONTMGMT)
#   if defined(__lint)
#       define CONTMGMTEXPORT       __export(contmgmt)
#       define CONTMGMTGLOBAL       extern __global(contmgmt)
#       define CONTMGMTPRIVATE      extern __private(contmgmt)
#   elif defined(_WIN32)
#       define CONTMGMTEXPORT       __declspec(dllexport)
#       define CONTMGMTGLOBAL       extern __declspec(dllexport)
#       define CONTMGMTPRIVATE      extern
#   else
#       define CONTMGMTEXPORT
#       define CONTMGMTGLOBAL       extern
#       define CONTMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CONTMGMTEXPORT       __export(contmgmt)
#       define CONTMGMTGLOBAL       extern __global(contmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CONTMGMTEXPORT      __declspec(dllimport)
#       define CONTMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define CONTMGMTEXPORT
#       define CONTMGMTGLOBAL       extern
#   endif
#endif
