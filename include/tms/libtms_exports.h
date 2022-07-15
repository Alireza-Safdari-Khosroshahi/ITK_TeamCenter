// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    Defines the export symbols for the TMS library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtms

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define TMS_LIBRARY_NAME libtms
#define TMS_LIBRARY_ID_NAME tms

#if IPLIB==TMS_LIBRARY_NAME
#   if defined(__lint)
#       define TMSEXPORT       __export(TMS_LIBRARY_ID_NAME)
#       define TMSGLOBAL       extern __global(TMS_LIBRARY_ID_NAME)
#       define TMSPRIVATE      extern __private(TMS_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define TMSEXPORT       __declspec(dllexport)
#       define TMSGLOBAL       extern __declspec(dllexport)
#       define TMSPRIVATE      extern
#   else
#       define TMSEXPORT
#       define TMSGLOBAL       extern
#       define TMSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TMSEXPORT       __export(TMS_LIBRARY_ID_NAME)
#       define TMSGLOBAL       extern __global(TMS_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TMSEXPORT       __declspec(dllimport)
#       define TMSGLOBAL       extern __declspec(dllimport)
#   else
#       define TMSEXPORT
#       define TMSGLOBAL       extern
#   endif
#endif
#define TMS_API TMSEXPORT
