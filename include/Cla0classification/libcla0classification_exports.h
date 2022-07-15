/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the declaration for the Library CLA0CLASSIFICATION

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libCla0classification

#if !defined(LIBCLA0CLASSIFICATION) && !defined(IPLIB)
#   error IPLIB or LIBCLA0CLASSIFICATION is not defined
#endif

/* Handwritten code should use CLA0CLASSIFICATION_API, not CLA0CLASSIFICATIONEXPORT */

#define CLA0CLASSIFICATION_API CLA0CLASSIFICATIONEXPORT

#if IPLIB==LIBCLA0CLASSIFICATION || defined(LIBCLA0CLASSIFICATION)
#   if defined(__lint)
#       define CLA0CLASSIFICATIONEXPORT       __export(Cla0classification)
#       define CLA0CLASSIFICATIONGLOBAL       extern __global(Cla0classification)
#       define CLA0CLASSIFICATIONPRIVATE      extern __private(Cla0classification)
#   elif defined(_WIN32)
#       define CLA0CLASSIFICATIONEXPORT       __declspec(dllexport)
#       define CLA0CLASSIFICATIONGLOBAL       extern __declspec(dllexport)
#       define CLA0CLASSIFICATIONPRIVATE      extern
#   else
#       define CLA0CLASSIFICATIONEXPORT
#       define CLA0CLASSIFICATIONGLOBAL       extern
#       define CLA0CLASSIFICATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CLA0CLASSIFICATIONEXPORT       __export(Cla0classification)
#       define CLA0CLASSIFICATIONGLOBAL       extern __global(Cla0classification)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CLA0CLASSIFICATIONEXPORT      __declspec(dllimport)
#       define CLA0CLASSIFICATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define CLA0CLASSIFICATIONEXPORT
#       define CLA0CLASSIFICATIONGLOBAL       extern
#   endif
#endif
