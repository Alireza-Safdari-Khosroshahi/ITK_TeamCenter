/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the MECHATRONICS library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#error ExportLibrary is defined to be EXPORTLIBRARY
#endif

#define EXPORTLIBRARY            libmechatronics

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use MECHATRONICS_API, not MECHATRONICSEXPORT */

#define MECHATRONICS_API MECHATRONICSEXPORT

/* Support MECHATRONICSEXPORT for autogenerated schema/pif code only */

#if IPLIB==libmechatronics
#   if defined(__lint)
#       define MECHATRONICSEXPORT       __export(mechatronics)
#       define MECHATRONICSGLOBAL       extern __global(mechatronics)
#       define MECHATRONICSPRIVATE      extern __private(mechatronics)
#   elif defined(_WIN32)
#       define MECHATRONICSEXPORT       __declspec(dllexport)
#       define MECHATRONICSGLOBAL       extern __declspec(dllexport)
#       define MECHATRONICSPRIVATE      extern
#   else
#       define MECHATRONICSEXPORT
#       define MECHATRONICSGLOBAL       extern
#       define MECHATRONICSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MECHATRONICSEXPORT       __export(mechatronics)
#       define MECHATRONICSGLOBAL       extern __global(mechatronics)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MECHATRONICSEXPORT      __declspec(dllimport)
#       define MECHATRONICSGLOBAL       extern __declspec(dllimport)
#   else
#       define MECHATRONICSEXPORT
#       define MECHATRONICSGLOBAL       extern
#   endif
#endif

