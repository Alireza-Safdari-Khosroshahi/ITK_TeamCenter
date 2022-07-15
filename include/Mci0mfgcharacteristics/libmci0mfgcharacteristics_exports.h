/*HEAD libMCI0MFGCHARACTERISTICS_EXPORTS HHH MCI0MFGCHARACTERISTICS */
// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
File Description:

     The header file that defines the export symbols for the
     MCI0MFGCHARACTERISTICS library

===============================================================================
Date          Name                   Description
23-May-2013   Naveen Amesar                   Initial creation
$HISTORY$
============================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libMci0mfgcharacteristics

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use MCI0MFGCHARACTERISTICS_API, not MCI0MCIEXPORT */

#define MCI0MFGCHARACTERISTICS_API MCI0MFGCHARACTERISTICSEXPORT

/* Support MCI0MFGCHARACTERISTICSEXPORT for autogenerated schema/pif code only */

#if IPLIB==libMci0mfgcharacteristics
#   if defined(__lint)
#       define MCI0MFGCHARACTERISTICSEXPORT       __export(Mci0mfgcharacteristics)
#       define MCI0MFGCHARACTERISTICSGLOBAL       extern __global(Mci0mfgcharacteristics)
#       define MCI0MFGCHARACTERISTICSPRIVATE      extern __private(Mci0mfgcharacteristics)
#   elif defined(_WIN32)
#       define MCI0MFGCHARACTERISTICSEXPORT       __declspec(dllexport)
#       define MCI0MFGCHARACTERISTICSGLOBAL       extern __declspec(dllexport)
#       define MCI0MFGCHARACTERISTICSPRIVATE      extern
#   else
#       define MCI0MFGCHARACTERISTICSEXPORT
#       define MCI0MFGCHARACTERISTICSGLOBAL       extern
#       define MCI0MFGCHARACTERISTICSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MCI0MFGCHARACTERISTICSEXPORT       __export(Mci0mfgcharacteristics)
#       define MCI0MFGCHARACTERISTICSGLOBAL       extern __global(Mci0mfgcharacteristics)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MCI0MFGCHARACTERISTICSEXPORT      __declspec(dllimport)
#       define MCI0MFGCHARACTERISTICSGLOBAL       extern __declspec(dllimport)
#   else
#       define MCI0MFGCHARACTERISTICSEXPORT
#       define MCI0MFGCHARACTERISTICSGLOBAL       extern
#   endif
#endif

