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

#define EXPORTLIBRARY            libfnd0soadebugmonitorstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use FND0SOADEBUGMONITORSTRONGMNGD_API, not FND0SOADEBUGMONITORSTRONGMNGDEXPORT */

#define FND0SOADEBUGMONITORSTRONGMNGD_API FND0SOADEBUGMONITORSTRONGMNGDEXPORT

/* Support FND0SOADEBUGMONITORSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libfnd0soadebugmonitorstrongmngd
#   if defined(__lint)
#       define FND0SOADEBUGMONITORSTRONGMNGDEXPORT       __export(fnd0soadebugmonitorstrongmngd)
#       define FND0SOADEBUGMONITORSTRONGMNGDGLOBAL       extern __global(fnd0soadebugmonitorstrongmngd)
#       define FND0SOADEBUGMONITORSTRONGMNGDPRIVATE      extern __private(fnd0soadebugmonitorstrongmngd)
#   elif defined(_WIN32)
#       define FND0SOADEBUGMONITORSTRONGMNGDEXPORT       __declspec(dllexport)
#       define FND0SOADEBUGMONITORSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define FND0SOADEBUGMONITORSTRONGMNGDPRIVATE      extern
#   else
#       define FND0SOADEBUGMONITORSTRONGMNGDEXPORT
#       define FND0SOADEBUGMONITORSTRONGMNGDGLOBAL       extern
#       define FND0SOADEBUGMONITORSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FND0SOADEBUGMONITORSTRONGMNGDEXPORT       __export(fnd0soadebugmonitorstrongmngd)
#       define FND0SOADEBUGMONITORSTRONGMNGDGLOBAL       extern __global(fnd0soadebugmonitorstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FND0SOADEBUGMONITORSTRONGMNGDEXPORT      __declspec(dllimport)
#       define FND0SOADEBUGMONITORSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define FND0SOADEBUGMONITORSTRONGMNGDEXPORT
#       define FND0SOADEBUGMONITORSTRONGMNGDGLOBAL       extern
#   endif
#endif
