/*
 * ==================================================
 * Copyright 2016.
 * Siemens Product Lifecycle Management Software Inc.
 * All Rights Reserved.
 * ==================================================
*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBIMAGECOMPRESSION) && !defined(IPLIB)
#   error IPLIB or LIBIMAGECOMPRESSION is not defined
#endif

#undef IMAGECOMPRESSION_API
#undef IMAGECOMPRESSIONEXPORT
#undef IMAGECOMPRESSIONGLOBAL
#undef IMAGECOMPRESSIONPRIVATE
