/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef TCSOACOMMON_API
#undef TCSOACOMMONEXPORT
#undef TCSOACOMMONGLOBAL
#undef TCSOACOMMONPRIVATE
