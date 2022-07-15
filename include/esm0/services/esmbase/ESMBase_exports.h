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

#define EXPORTLIBRARY            libesm0soaesmbasestrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use ESM0SOAESMBASESTRONGMNGD_API, not ESM0SOAESMBASESTRONGMNGDEXPORT */

#define ESM0SOAESMBASESTRONGMNGD_API ESM0SOAESMBASESTRONGMNGDEXPORT

/* Support ESM0SOAESMBASESTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libesm0soaesmbasestrongmngd
#   if defined(__lint)
#       define ESM0SOAESMBASESTRONGMNGDEXPORT       __export(esm0soaesmbasestrongmngd)
#       define ESM0SOAESMBASESTRONGMNGDGLOBAL       extern __global(esm0soaesmbasestrongmngd)
#       define ESM0SOAESMBASESTRONGMNGDPRIVATE      extern __private(esm0soaesmbasestrongmngd)
#   elif defined(_WIN32)
#       define ESM0SOAESMBASESTRONGMNGDEXPORT       __declspec(dllexport)
#       define ESM0SOAESMBASESTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define ESM0SOAESMBASESTRONGMNGDPRIVATE      extern
#   else
#       define ESM0SOAESMBASESTRONGMNGDEXPORT
#       define ESM0SOAESMBASESTRONGMNGDGLOBAL       extern
#       define ESM0SOAESMBASESTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ESM0SOAESMBASESTRONGMNGDEXPORT       __export(esm0soaesmbasestrongmngd)
#       define ESM0SOAESMBASESTRONGMNGDGLOBAL       extern __global(esm0soaesmbasestrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ESM0SOAESMBASESTRONGMNGDEXPORT      __declspec(dllimport)
#       define ESM0SOAESMBASESTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define ESM0SOAESMBASESTRONGMNGDEXPORT
#       define ESM0SOAESMBASESTRONGMNGDGLOBAL       extern
#   endif
#endif

