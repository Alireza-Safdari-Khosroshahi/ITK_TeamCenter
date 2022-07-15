/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
 
/** 
    @file 
 
    The header file that defines the export symbols for the CCDM library
 
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#error ExportLibrary is defined to be EXPORTLIBRARY
#endif

#define EXPORTLIBRARY            libccdm

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CCDM_LIBRARY_NAME libccdm
#define CCDM_LIBRARY_ID_NAME ccdm

/* Handwritten code should use CCDM_API, not CCDMEXPORT */

#define CCDM_API CCDMEXPORT

/* Support CCDMEXPORT for autogenerated schema/pif code only */

#if IPLIB==CCDM_LIBRARY_NAME
#   if defined(__lint)
#       define CCDMEXPORT       __export(CCDM_LIBRARY_ID_NAME)
#       define CCDMGLOBAL       extern __global(CCDM_LIBRARY_ID_NAME)
#       define CCDMPRIVATE      extern __private(CCDM_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CCDMEXPORT       __declspec(dllexport)
#       define CCDMGLOBAL       extern __declspec(dllexport)
#       define CCDMPRIVATE      extern
#   else
#       define CCDMEXPORT
#       define CCDMGLOBAL       extern
#       define CCDMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CCDMEXPORT       __export(CCDM_LIBRARY_ID_NAME)
#       define CCDMGLOBAL       extern __global(CCDM_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CCDMEXPORT       __declspec(dllimport)
#       define CCDMGLOBAL       extern __declspec(dllimport)
#   else
#       define CCDMEXPORT
#       define CCDMGLOBAL       extern
#   endif
#endif