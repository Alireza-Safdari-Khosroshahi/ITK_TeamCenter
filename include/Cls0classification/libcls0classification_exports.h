//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Cls0classification

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libCls0classification

#if !defined(LIBCLS0CLASSIFICATION) && !defined(IPLIB)
#   error IPLIB or LIBCLS0CLASSIFICATION is not defined
#endif

/* Handwritten code should use CLS0CLASSIFICATION_API, not CLS0CLASSIFICATIONEXPORT */

#define CLS0CLASSIFICATION_API CLS0CLASSIFICATIONEXPORT

#if IPLIB==libCls0classification || defined(LIBCLS0CLASSIFICATION)
#   if defined(__lint)
#       define CLS0CLASSIFICATIONEXPORT       __export(Cls0classification)
#       define CLS0CLASSIFICATIONGLOBAL       extern __global(Cls0classification)
#       define CLS0CLASSIFICATIONPRIVATE      extern __private(Cls0classification)
#   elif defined(_WIN32)
#       define CLS0CLASSIFICATIONEXPORT       __declspec(dllexport)
#       define CLS0CLASSIFICATIONGLOBAL       extern __declspec(dllexport)
#       define CLS0CLASSIFICATIONPRIVATE      extern
#   else
#       define CLS0CLASSIFICATIONEXPORT
#       define CLS0CLASSIFICATIONGLOBAL       extern
#       define CLS0CLASSIFICATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CLS0CLASSIFICATIONEXPORT       __export(Cls0classification)
#       define CLS0CLASSIFICATIONGLOBAL       extern __global(Cls0classification)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CLS0CLASSIFICATIONEXPORT      __declspec(dllimport)
#       define CLS0CLASSIFICATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define CLS0CLASSIFICATIONEXPORT
#       define CLS0CLASSIFICATIONGLOBAL       extern
#   endif
#endif
