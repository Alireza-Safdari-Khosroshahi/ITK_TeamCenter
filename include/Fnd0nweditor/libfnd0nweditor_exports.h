//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Fnd0nweditor

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libFnd0nweditor

#if !defined(LIBFND0NWEDITOR) && !defined(IPLIB)
#   error IPLIB or LIBFND0NWEDITOR is not defined
#endif

/* Handwritten code should use FND0NWEDITOR_API, not FND0NWEDITOREXPORT */

#define FND0NWEDITOR_API FND0NWEDITOREXPORT

#if IPLIB==libFnd0nweditor || defined(LIBFND0NWEDITOR)
#   if defined(__lint)
#       define FND0NWEDITOREXPORT       __export(Fnd0nweditor)
#       define FND0NWEDITORGLOBAL       extern __global(Fnd0nweditor)
#       define FND0NWEDITORPRIVATE      extern __private(Fnd0nweditor)
#   elif defined(_WIN32)
#       define FND0NWEDITOREXPORT       __declspec(dllexport)
#       define FND0NWEDITORGLOBAL       extern __declspec(dllexport)
#       define FND0NWEDITORPRIVATE      extern
#   else
#       define FND0NWEDITOREXPORT
#       define FND0NWEDITORGLOBAL       extern
#       define FND0NWEDITORPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FND0NWEDITOREXPORT       __export(Fnd0nweditor)
#       define FND0NWEDITORGLOBAL       extern __global(Fnd0nweditor)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FND0NWEDITOREXPORT      __declspec(dllimport)
#       define FND0NWEDITORGLOBAL       extern __declspec(dllimport)
#   else
#       define FND0NWEDITOREXPORT
#       define FND0NWEDITORGLOBAL       extern
#   endif
#endif
