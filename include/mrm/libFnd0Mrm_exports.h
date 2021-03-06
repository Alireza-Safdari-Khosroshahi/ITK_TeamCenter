/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2016
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/*
    File Description:

    The header file that defines the export symbols for the Fnd0Mrm library
 */

#include <common/library_indicators.h>



#ifdef EXPORTLIBRARY
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libFnd0Mrm

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use MRM_API, not MRMEXPORT */

#define MRM_API MRMEXPORT

/* Support ICSEXPORT for autogenerated schema/pif code only */

#if IPLIB == libFnd0Mrm
#   if defined(__lint)
#       define MRMEXPORT       __export(libFnd0Mrm)
#       define MRMGLOBAL       extern __global(libFnd0Mrm)
#       define MRMPRIVATE      extern __private(libFnd0Mrm)
#   elif defined(_WIN32)
#       define MRMEXPORT       __declspec(dllexport)
#       define MRMGLOBAL       extern __declspec(dllexport)
#       define MRMPRIVATE      extern
#   else
#       define MRMEXPORT
#       define MRMGLOBAL       extern
#       define MRMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MRMEXPORT       __export(libFnd0Mrm)
#       define MRMGLOBAL       extern __global(libFnd0Mrm)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MRMEXPORT       __declspec(dllimport)
#       define MRMGLOBAL       extern __declspec(dllimport)
#   else
#       define MRMEXPORT
#       define MRMGLOBAL       extern
#   endif
#endif
