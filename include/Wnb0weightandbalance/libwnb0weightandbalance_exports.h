//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Wnb0weightandbalance

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libWnb0weightandbalance

#if !defined(LIBWNB0WEIGHTANDBALANCE) && !defined(IPLIB)
#   error IPLIB or LIBWNB0WEIGHTANDBALANCE is not defined
#endif

/* Handwritten code should use WNB0WEIGHTANDBALANCE_API, not WNB0WEIGHTANDBALANCEEXPORT */

#define WNB0WEIGHTANDBALANCE_API WNB0WEIGHTANDBALANCEEXPORT

#if IPLIB==libWnb0weightandbalance || defined(LIBWNB0WEIGHTANDBALANCE)
#   if defined(__lint)
#       define WNB0WEIGHTANDBALANCEEXPORT       __export(Wnb0weightandbalance)
#       define WNB0WEIGHTANDBALANCEGLOBAL       extern __global(Wnb0weightandbalance)
#       define WNB0WEIGHTANDBALANCEPRIVATE      extern __private(Wnb0weightandbalance)
#   elif defined(_WIN32)
#       define WNB0WEIGHTANDBALANCEEXPORT       __declspec(dllexport)
#       define WNB0WEIGHTANDBALANCEGLOBAL       extern __declspec(dllexport)
#       define WNB0WEIGHTANDBALANCEPRIVATE      extern
#   else
#       define WNB0WEIGHTANDBALANCEEXPORT
#       define WNB0WEIGHTANDBALANCEGLOBAL       extern
#       define WNB0WEIGHTANDBALANCEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define WNB0WEIGHTANDBALANCEEXPORT       __export(Wnb0weightandbalance)
#       define WNB0WEIGHTANDBALANCEGLOBAL       extern __global(Wnb0weightandbalance)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define WNB0WEIGHTANDBALANCEEXPORT      __declspec(dllimport)
#       define WNB0WEIGHTANDBALANCEGLOBAL       extern __declspec(dllimport)
#   else
#       define WNB0WEIGHTANDBALANCEEXPORT
#       define WNB0WEIGHTANDBALANCEGLOBAL       extern
#   endif
#endif
