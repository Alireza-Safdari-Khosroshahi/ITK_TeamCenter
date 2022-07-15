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

#define EXPORTLIBRARY            libfnd0soacodecoveragestrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use FND0SOACODECOVERAGESTRONGMNGD_API, not FND0SOACODECOVERAGESTRONGMNGDEXPORT */

#define FND0SOACODECOVERAGESTRONGMNGD_API FND0SOACODECOVERAGESTRONGMNGDEXPORT

/* Support FND0SOACODECOVERAGESTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libfnd0soacodecoveragestrongmngd
#   if defined(__lint)
#       define FND0SOACODECOVERAGESTRONGMNGDEXPORT       __export(fnd0soacodecoveragestrongmngd)
#       define FND0SOACODECOVERAGESTRONGMNGDGLOBAL       extern __global(fnd0soacodecoveragestrongmngd)
#       define FND0SOACODECOVERAGESTRONGMNGDPRIVATE      extern __private(fnd0soacodecoveragestrongmngd)
#   elif defined(_WIN32)
#       define FND0SOACODECOVERAGESTRONGMNGDEXPORT       __declspec(dllexport)
#       define FND0SOACODECOVERAGESTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define FND0SOACODECOVERAGESTRONGMNGDPRIVATE      extern
#   else
#       define FND0SOACODECOVERAGESTRONGMNGDEXPORT
#       define FND0SOACODECOVERAGESTRONGMNGDGLOBAL       extern
#       define FND0SOACODECOVERAGESTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FND0SOACODECOVERAGESTRONGMNGDEXPORT       __export(fnd0soacodecoveragestrongmngd)
#       define FND0SOACODECOVERAGESTRONGMNGDGLOBAL       extern __global(fnd0soacodecoveragestrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FND0SOACODECOVERAGESTRONGMNGDEXPORT      __declspec(dllimport)
#       define FND0SOACODECOVERAGESTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define FND0SOACODECOVERAGESTRONGMNGDEXPORT
#       define FND0SOACODECOVERAGESTRONGMNGDGLOBAL       extern
#   endif
#endif

