/*
 * ==================================================
 * Copyright 2016.
 * Siemens Product Lifecycle Management Software Inc.
 * All Rights Reserved.
 * ==================================================
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libimagecompression

#if !defined(LIBIMAGECOMPRESSION) && !defined(IPLIB)
#   error IPLIB or LIBIMAGECOMPRESSION is not defined
#endif

/* Handwritten code should use IMAGECOMPRESSION_API, not IMAGECOMPRESSIONEXPORT */

#define IMAGECOMPRESSION_API IMAGECOMPRESSIONEXPORT

#if IPLIB==libimagecompression || defined(LIBIMAGECOMPRESSION)
#   if defined(__lint)
#       define IMAGECOMPRESSIONEXPORT       __export(imagecompression)
#       define IMAGECOMPRESSIONGLOBAL       extern __global(imagecompression)
#       define IMAGECOMPRESSIONPRIVATE      extern __private(imagecompression)
#   elif defined(_WIN32)
#       define IMAGECOMPRESSIONEXPORT       __declspec(dllexport)
#       define IMAGECOMPRESSIONGLOBAL       extern __declspec(dllexport)
#       define IMAGECOMPRESSIONPRIVATE      extern
#   else
#       define IMAGECOMPRESSIONEXPORT
#       define IMAGECOMPRESSIONGLOBAL       extern
#       define IMAGECOMPRESSIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define IMAGECOMPRESSIONEXPORT       __export(imagecompression)
#       define IMAGECOMPRESSIONGLOBAL       extern __global(imagecompression)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define IMAGECOMPRESSIONEXPORT      __declspec(dllimport)
#       define IMAGECOMPRESSIONGLOBAL       extern __declspec(dllimport)
#   else
#       define IMAGECOMPRESSIONEXPORT
#       define IMAGECOMPRESSIONGLOBAL       extern
#   endif
#endif
