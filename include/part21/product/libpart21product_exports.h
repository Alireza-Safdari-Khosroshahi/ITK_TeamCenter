/*================================================================================

                           Copyright 2013.
              Siemens Product Lifecycle Management Software Inc.
                        All Rights Reserved.
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the STEP library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libpart21product

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use PART21PRODUCT_API, not PART21PRODUCTEXPORT */

#define PART21PRODUCT_API PART21PRODUCTEXPORT

/* Support PART21PRODUCTEXPORT for autogenerated schema/pif code only */

#if IPLIB==libpart21product
#   if defined(__lint)
#       define PART21PRODUCTEXPORT       __export(part21product)
#       define PART21PRODUCTGLOBAL       extern __global(part21product)
#       define PART21PRODUCTPRIVATE      extern __private(part21product)
#   elif defined(_WIN32)
#       define PART21PRODUCTEXPORT       __declspec(dllexport)
#       define PART21PRODUCTGLOBAL       extern __declspec(dllexport)
#       define PART21PRODUCTPRIVATE      extern
#   else
#       define PART21PRODUCTEXPORT
#       define PART21PRODUCTGLOBAL       extern
#       define PART21PRODUCTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PART21PRODUCTEXPORT       __export(part21product)
#       define PART21PRODUCTGLOBAL       extern __global(part21product)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PART21PRODUCTEXPORT      __declspec(dllimport)
#       define PART21PRODUCTGLOBAL       extern __declspec(dllimport)
#   else
#       define PART21PRODUCTEXPORT
#       define PART21PRODUCTGLOBAL       extern
#   endif
#endif

