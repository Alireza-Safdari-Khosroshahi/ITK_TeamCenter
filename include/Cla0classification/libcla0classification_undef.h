/* LIBCLA0CLASSIFICATIONPRIVATE
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBCLA0CLASSIFICATION) && !defined(IPLIB)
#   error IPLIB or LIBCLA0CLASSIFICATION is not defined
#endif

#undef LIBCLA0CLASSIFICATION_API
#undef LIBCLA0CLASSIFICATIONEXPORT
#undef LIBCLA0CLASSIFICATIONGLOBAL
#undef LIBCLA0CLASSIFICATION
