//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Cip0controlinspplan

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libCip0controlinspplan

#if !defined(LIBCIP0CONTROLINSPPLAN) && !defined(IPLIB)
#   error IPLIB or LIBCIP0CONTROLINSPPLAN is not defined
#endif

/* Handwritten code should use CIP0CONTROLINSPPLAN_API, not CIP0CONTROLINSPPLANEXPORT */

#define CIP0CONTROLINSPPLAN_API CIP0CONTROLINSPPLANEXPORT

#if IPLIB==libCip0controlinspplan || defined(LIBCIP0CONTROLINSPPLAN)
#   if defined(__lint)
#       define CIP0CONTROLINSPPLANEXPORT       __export(Cip0controlinspplan)
#       define CIP0CONTROLINSPPLANGLOBAL       extern __global(Cip0controlinspplan)
#       define CIP0CONTROLINSPPLANPRIVATE      extern __private(Cip0controlinspplan)
#   elif defined(_WIN32)
#       define CIP0CONTROLINSPPLANEXPORT       __declspec(dllexport)
#       define CIP0CONTROLINSPPLANGLOBAL       extern __declspec(dllexport)
#       define CIP0CONTROLINSPPLANPRIVATE      extern
#   else
#       define CIP0CONTROLINSPPLANEXPORT
#       define CIP0CONTROLINSPPLANGLOBAL       extern
#       define CIP0CONTROLINSPPLANPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CIP0CONTROLINSPPLANEXPORT       __export(Cip0controlinspplan)
#       define CIP0CONTROLINSPPLANGLOBAL       extern __global(Cip0controlinspplan)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CIP0CONTROLINSPPLANEXPORT      __declspec(dllimport)
#       define CIP0CONTROLINSPPLANGLOBAL       extern __declspec(dllimport)
#   else
#       define CIP0CONTROLINSPPLANEXPORT
#       define CIP0CONTROLINSPPLANGLOBAL       extern
#   endif
#endif
