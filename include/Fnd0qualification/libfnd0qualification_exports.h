/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    This file contains the declaration for the Dispatch Library  Fnd0qualification
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libFnd0qualification

#if !defined(LIBFND0QUALIFICATION) && !defined(IPLIB)
#   error IPLIB or LIBFND0QUALIFICATION is not defined
#endif

/* Handwritten code should use FND0QUALIFICATION_API, not FND0QUALIFICATIONEXPORT */

#define FND0QUALIFICATION_API FND0QUALIFICATIONEXPORT

#if IPLIB==libFnd0qualification || defined(LIBFND0QUALIFICATION)
#   if defined(__lint)
#       define FND0QUALIFICATIONEXPORT       __export(Fnd0qualification)
#       define FND0QUALIFICATIONGLOBAL       extern __global(Fnd0qualification)
#       define FND0QUALIFICATIONPRIVATE      extern __private(Fnd0qualification)
#   elif defined(_WIN32)
#       define FND0QUALIFICATIONEXPORT       __declspec(dllexport)
#       define FND0QUALIFICATIONGLOBAL       extern __declspec(dllexport)
#       define FND0QUALIFICATIONPRIVATE      extern
#   else
#       define FND0QUALIFICATIONEXPORT
#       define FND0QUALIFICATIONGLOBAL       extern
#       define FND0QUALIFICATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FND0QUALIFICATIONEXPORT       __export(Fnd0qualification)
#       define FND0QUALIFICATIONGLOBAL       extern __global(Fnd0qualification)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FND0QUALIFICATIONEXPORT      __declspec(dllimport)
#       define FND0QUALIFICATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define FND0QUALIFICATIONEXPORT
#       define FND0QUALIFICATIONGLOBAL       extern
#   endif
#endif
