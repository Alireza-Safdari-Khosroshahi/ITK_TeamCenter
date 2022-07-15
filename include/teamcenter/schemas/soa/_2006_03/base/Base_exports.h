/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtcsoacommon

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use BASE_API, not BASEEXPORT */

#define BASE_API BASEEXPORT

/* Support BASEEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoacommon
#   if defined(__lint)
#       define BASEEXPORT       __export(tcsoacommon)
#       define BASEGLOBAL       extern __global(tcsoacommon)
#       define BASEPRIVATE      extern __private(tcsoacommon)
#   elif defined(_WIN32)
#       define BASEEXPORT       __declspec(dllexport)
#       define BASEGLOBAL       extern __declspec(dllexport)
#       define BASEPRIVATE      extern
#   else
#       define BASEEXPORT
#       define BASEGLOBAL       extern
#       define BASEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define BASEEXPORT       __export(tcsoacommon)
#       define BASEGLOBAL       extern __global(tcsoacommon)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define BASEEXPORT      __declspec(dllimport)
#       define BASEGLOBAL       extern __declspec(dllimport)
#   else
#       define BASEEXPORT
#       define BASEGLOBAL       extern
#   endif
#endif

