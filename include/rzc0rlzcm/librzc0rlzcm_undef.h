/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2019
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

#if !defined(LIBRZC0RLZCM) && !defined(IPLIB)
#   error IPLIB or LIBRZC0RLZCM is not defined
#endif

#undef RZC0RLZCM_API
#undef RZC0RLZCMEXPORT
#undef RZC0RLZCMGLOBAL
#undef RZC0RLZCMPRIVATE
