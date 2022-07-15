//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBCLS0CLASSIFICATION) && !defined(IPLIB)
#   error IPLIB orLIBCLS0CLASSIFICATION is not defined
#endif

#undef CLS0CLASSIFICATION_API
#undef CLS0CLASSIFICATIONEXPORT
#undef CLS0CLASSIFICATIONGLOBAL
#undef CLS0CLASSIFICATIONPRIVATE
