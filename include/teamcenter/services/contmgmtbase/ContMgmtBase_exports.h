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

#define EXPORTLIBRARY            libtcsoacontmgmtbasestrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOACONTMGMTBASESTRONGMNGD_API, not TCSOACONTMGMTBASESTRONGMNGDEXPORT */

#define TCSOACONTMGMTBASESTRONGMNGD_API TCSOACONTMGMTBASESTRONGMNGDEXPORT

/* Support TCSOACONTMGMTBASESTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoacontmgmtbasestrongmngd
#   if defined(__lint)
#       define TCSOACONTMGMTBASESTRONGMNGDEXPORT       __export(tcsoacontmgmtbasestrongmngd)
#       define TCSOACONTMGMTBASESTRONGMNGDGLOBAL       extern __global(tcsoacontmgmtbasestrongmngd)
#       define TCSOACONTMGMTBASESTRONGMNGDPRIVATE      extern __private(tcsoacontmgmtbasestrongmngd)
#   elif defined(_WIN32)
#       define TCSOACONTMGMTBASESTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOACONTMGMTBASESTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOACONTMGMTBASESTRONGMNGDPRIVATE      extern
#   else
#       define TCSOACONTMGMTBASESTRONGMNGDEXPORT
#       define TCSOACONTMGMTBASESTRONGMNGDGLOBAL       extern
#       define TCSOACONTMGMTBASESTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOACONTMGMTBASESTRONGMNGDEXPORT       __export(tcsoacontmgmtbasestrongmngd)
#       define TCSOACONTMGMTBASESTRONGMNGDGLOBAL       extern __global(tcsoacontmgmtbasestrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOACONTMGMTBASESTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOACONTMGMTBASESTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOACONTMGMTBASESTRONGMNGDEXPORT
#       define TCSOACONTMGMTBASESTRONGMNGDGLOBAL       extern
#   endif
#endif

