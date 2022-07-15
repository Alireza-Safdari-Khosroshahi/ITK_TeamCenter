//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2013.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  ptn0partitiontemplate

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libptn0partitiontemplate

#if !defined(LIBPTN0PARTITIONTEMPLATE) && !defined(IPLIB)
#   error IPLIB or LIBPTN0PARTITIONTEMPLATE is not defined
#endif

/* Handwritten code should use PTN0PARTITIONTEMPLATE_API, not PTN0PARTITIONTEMPLATEEXPORT */

#define PTN0PARTITIONTEMPLATE_API PTN0PARTITIONTEMPLATEEXPORT

#if IPLIB==libptn0partitiontemplate || defined(LIBPTN0PARTITIONTEMPLATE)
#   if defined(__lint)
#       define PTN0PARTITIONTEMPLATEEXPORT       __export(ptn0partitiontemplate)
#       define PTN0PARTITIONTEMPLATEGLOBAL       extern __global(ptn0partitiontemplate)
#       define PTN0PARTITIONTEMPLATEPRIVATE      extern __private(ptn0partitiontemplate)
#   elif defined(_WIN32)
#       define PTN0PARTITIONTEMPLATEEXPORT       __declspec(dllexport)
#       define PTN0PARTITIONTEMPLATEGLOBAL       extern __declspec(dllexport)
#       define PTN0PARTITIONTEMPLATEPRIVATE      extern
#   else
#       define PTN0PARTITIONTEMPLATEEXPORT
#       define PTN0PARTITIONTEMPLATEGLOBAL       extern
#       define PTN0PARTITIONTEMPLATEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PTN0PARTITIONTEMPLATEEXPORT       __export(ptn0partitiontemplate)
#       define PTN0PARTITIONTEMPLATEGLOBAL       extern __global(ptn0partitiontemplate)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PTN0PARTITIONTEMPLATEEXPORT      __declspec(dllimport)
#       define PTN0PARTITIONTEMPLATEGLOBAL       extern __declspec(dllimport)
#   else
#       define PTN0PARTITIONTEMPLATEEXPORT
#       define PTN0PARTITIONTEMPLATEGLOBAL       extern
#   endif
#endif
