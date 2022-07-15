//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2014.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBMDL0MODELGEOMETRY) && !defined(IPLIB)
#   error IPLIB orLIBMDL0MODELGEOMETRY is not defined
#endif

#undef MDL0MODELGEOMETRY_API
#undef MDL0MODELGEOMETRYEXPORT
#undef MDL0MODELGEOMETRYGLOBAL
#undef MDL0MODELGEOMETRYPRIVATE
