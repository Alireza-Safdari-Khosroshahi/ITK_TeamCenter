/*HEAD LIBMCI0MFGCHARACTERISTICS_EXPORTS HHH MCI0MFGCHARACTERISTICS */
// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 20013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
File Description:

     The header file that undefines the export symbols for the
     MCI0MFGCHARACTERISTICS library

===============================================================================
Date          Name                                    Description
23-May-2013   Naveen Amesar                   Initial creation
$HISTORY$
============================================================================*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef MCI0MFGCHARACTERISTICS_API
#undef MCI0MFGCHARACTERISTICSEXPORT
#undef MCI0MFGCHARACTERISTICSGLOBAL
#undef MCI0MFGCHARACTERISTICSPRIVATE

