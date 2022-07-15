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

#define EXPORTLIBRARY            libtcsoaissuemanagementstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAISSUEMANAGEMENTSTRONGMNGD_API, not TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT */

#define TCSOAISSUEMANAGEMENTSTRONGMNGD_API TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT

/* Support TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoaissuemanagementstrongmngd
#   if defined(__lint)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT       __export(tcsoaissuemanagementstrongmngd)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDGLOBAL       extern __global(tcsoaissuemanagementstrongmngd)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDPRIVATE      extern __private(tcsoaissuemanagementstrongmngd)
#   elif defined(_WIN32)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDGLOBAL       extern
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT       __export(tcsoaissuemanagementstrongmngd)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDGLOBAL       extern __global(tcsoaissuemanagementstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDEXPORT
#       define TCSOAISSUEMANAGEMENTSTRONGMNGDGLOBAL       extern
#   endif
#endif

