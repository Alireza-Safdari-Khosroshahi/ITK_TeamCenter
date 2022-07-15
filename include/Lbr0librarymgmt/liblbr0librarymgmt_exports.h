/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2013.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the declaration for the Dispatch Library  Lbr0librarymgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libLbr0librarymgmt

#if !defined(LIBLBR0LIBRARYMGMT) && !defined(IPLIB)
#   error IPLIB or LIBLBR0LIBRARYMGMT is not defined
#endif

/* Handwritten code should use LBR0LIBRARYMGMT_API, not LBR0LIBRARYMGMTEXPORT */

#define LBR0LIBRARYMGMT_API LBR0LIBRARYMGMTEXPORT

#if IPLIB==libLbr0librarymgmt || defined(LIBLBR0LIBRARYMGMT)
#   if defined(__lint)
#       define LBR0LIBRARYMGMTEXPORT       __export(Lbr0librarymgmt)
#       define LBR0LIBRARYMGMTGLOBAL       extern __global(Lbr0librarymgmt)
#       define LBR0LIBRARYMGMTPRIVATE      extern __private(Lbr0librarymgmt)
#   elif defined(_WIN32)
#       define LBR0LIBRARYMGMTEXPORT       __declspec(dllexport)
#       define LBR0LIBRARYMGMTGLOBAL       extern __declspec(dllexport)
#       define LBR0LIBRARYMGMTPRIVATE      extern
#   else
#       define LBR0LIBRARYMGMTEXPORT
#       define LBR0LIBRARYMGMTGLOBAL       extern
#       define LBR0LIBRARYMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define LBR0LIBRARYMGMTEXPORT       __export(Lbr0librarymgmt)
#       define LBR0LIBRARYMGMTGLOBAL       extern __global(Lbr0librarymgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define LBR0LIBRARYMGMTEXPORT      __declspec(dllimport)
#       define LBR0LIBRARYMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define LBR0LIBRARYMGMTEXPORT
#       define LBR0LIBRARYMGMTGLOBAL       extern
#   endif
#endif
