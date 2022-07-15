//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  tgm0targetmgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtgm0targetmgmt

#if !defined(LIBTGM0TARGETMGMT) && !defined(IPLIB)
#   error IPLIB or LIBTGM0TARGETMGMT is not defined
#endif

/* Handwritten code should use TGM0TARGETMGMT_API, not TGM0TARGETMGMTEXPORT */

#define TGM0TARGETMGMT_API TGM0TARGETMGMTEXPORT

#if IPLIB==libtgm0targetmgmt || defined(LIBTGM0TARGETMGMT)
#   if defined(__lint)
#       define TGM0TARGETMGMTEXPORT       __export(tgm0targetmgmt)
#       define TGM0TARGETMGMTGLOBAL       extern __global(tgm0targetmgmt)
#       define TGM0TARGETMGMTPRIVATE      extern __private(tgm0targetmgmt)
#   elif defined(_WIN32)
#       define TGM0TARGETMGMTEXPORT       __declspec(dllexport)
#       define TGM0TARGETMGMTGLOBAL       extern __declspec(dllexport)
#       define TGM0TARGETMGMTPRIVATE      extern
#   else
#       define TGM0TARGETMGMTEXPORT
#       define TGM0TARGETMGMTGLOBAL       extern
#       define TGM0TARGETMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TGM0TARGETMGMTEXPORT       __export(tgm0targetmgmt)
#       define TGM0TARGETMGMTGLOBAL       extern __global(tgm0targetmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TGM0TARGETMGMTEXPORT      __declspec(dllimport)
#       define TGM0TARGETMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define TGM0TARGETMGMTEXPORT
#       define TGM0TARGETMGMTGLOBAL       extern
#   endif
#endif
