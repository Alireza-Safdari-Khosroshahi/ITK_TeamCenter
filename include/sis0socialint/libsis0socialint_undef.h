/*
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

#if !defined(LIBSIS0SOCIALINT) && !defined(IPLIB)
#   error IPLIB or LIBSIS0SOCIALINT is not defined
#endif

#undef SIS0SOCIALINT_API
#undef SIS0SOCIALINTEXPORT
#undef SIS0SOCIALINTGLOBAL
#undef SIS0SOCIALINTPRIVATE
