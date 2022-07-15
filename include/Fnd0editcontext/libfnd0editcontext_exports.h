//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Fnd0editcontext

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libFnd0editcontext

#if !defined(LIBFND0EDITCONTEXT) && !defined(IPLIB)
#   error IPLIB or LIBFND0EDITCONTEXT is not defined
#endif

/* Handwritten code should use FND0EDITCONTEXT_API, not FND0EDITCONTEXTEXPORT */

#define FND0EDITCONTEXT_API FND0EDITCONTEXTEXPORT

#if IPLIB==libFnd0editcontext || defined(LIBFND0EDITCONTEXT)
#   if defined(__lint)
#       define FND0EDITCONTEXTEXPORT       __export(Fnd0editcontext)
#       define FND0EDITCONTEXTGLOBAL       extern __global(Fnd0editcontext)
#       define FND0EDITCONTEXTPRIVATE      extern __private(Fnd0editcontext)
#   elif defined(_WIN32)
#       define FND0EDITCONTEXTEXPORT       __declspec(dllexport)
#       define FND0EDITCONTEXTGLOBAL       extern __declspec(dllexport)
#       define FND0EDITCONTEXTPRIVATE      extern
#   else
#       define FND0EDITCONTEXTEXPORT
#       define FND0EDITCONTEXTGLOBAL       extern
#       define FND0EDITCONTEXTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FND0EDITCONTEXTEXPORT       __export(Fnd0editcontext)
#       define FND0EDITCONTEXTGLOBAL       extern __global(Fnd0editcontext)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FND0EDITCONTEXTEXPORT      __declspec(dllimport)
#       define FND0EDITCONTEXTGLOBAL       extern __declspec(dllimport)
#   else
#       define FND0EDITCONTEXTEXPORT
#       define FND0EDITCONTEXTGLOBAL       extern
#   endif
#endif
