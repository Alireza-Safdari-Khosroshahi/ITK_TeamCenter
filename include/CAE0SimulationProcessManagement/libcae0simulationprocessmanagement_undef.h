/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/*====================================================================================================
File description:

Filename: libcae0simulationprocessmanagement_undef.h
Module  : CAE0SimulationProcessManagement
Description: This file contains the declaration for the Dispatch Library  CAE0SimulationProcessManagement

====================================================================================================*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBCAE0SIMULATIONPROCESSMANAGEMENT) && !defined(IPLIB)
#   error IPLIB or LIBCAE0SIMULATIONPROCESSMANAGEMENT is not defined
#endif

#undef CAE0SIMULATIONPROCESSMANAGEMENT_API
#undef CAE0SIMULATIONPROCESSMANAGEMENTEXPORT
#undef CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL
#undef CAE0SIMULATIONPROCESSMANAGEMENTPRIVATE
