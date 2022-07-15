//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2013.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Mci0mfgcharacteristicsbvr

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libMci0mfgcharacteristicsbvr

#if !defined(LIBMCI0MFGCHARACTERISTICSBVR) && !defined(IPLIB)
#   error IPLIB or LIBMCI0MFGCHARACTERISTICSBVR is not defined
#endif

/* Handwritten code should use MCI0MFGCHARACTERISTICSBVR_API, not MCI0MFGCHARACTERISTICSBVREXPORT */

#define MCI0MFGCHARACTERISTICSBVR_API MCI0MFGCHARACTERISTICSBVREXPORT

#if IPLIB==libMci0mfgcharacteristicsbvr || defined(LIBMCI0MFGCHARACTERISTICSBVR)
#   if defined(__lint)
#       define MCI0MFGCHARACTERISTICSBVREXPORT       __export(Mci0mfgcharacteristicsbvr)
#       define MCI0MFGCHARACTERISTICSBVRGLOBAL       extern __global(Mci0mfgcharacteristicsbvr)
#       define MCI0MFGCHARACTERISTICSBVRPRIVATE      extern __private(Mci0mfgcharacteristicsbvr)
#   elif defined(_WIN32)
#       define MCI0MFGCHARACTERISTICSBVREXPORT       __declspec(dllexport)
#       define MCI0MFGCHARACTERISTICSBVRGLOBAL       extern __declspec(dllexport)
#       define MCI0MFGCHARACTERISTICSBVRPRIVATE      extern
#   else
#       define MCI0MFGCHARACTERISTICSBVREXPORT
#       define MCI0MFGCHARACTERISTICSBVRGLOBAL       extern
#       define MCI0MFGCHARACTERISTICSBVRPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MCI0MFGCHARACTERISTICSBVREXPORT       __export(Mci0mfgcharacteristicsbvr)
#       define MCI0MFGCHARACTERISTICSBVRGLOBAL       extern __global(Mci0mfgcharacteristicsbvr)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MCI0MFGCHARACTERISTICSBVREXPORT      __declspec(dllimport)
#       define MCI0MFGCHARACTERISTICSBVRGLOBAL       extern __declspec(dllimport)
#   else
#       define MCI0MFGCHARACTERISTICSBVREXPORT
#       define MCI0MFGCHARACTERISTICSBVRGLOBAL       extern
#   endif
#endif
