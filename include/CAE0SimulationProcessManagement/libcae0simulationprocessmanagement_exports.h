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

Filename: libcae0simulationprocessmanagement_exports.h
Module  : CAE0SimulationProcessManagement
Description: This file contains the declaration for the Dispatch Library  CAE0SimulationProcessManagement

====================================================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libCAE0SimulationProcessManagement

#if !defined(LIBCAE0SIMULATIONPROCESSMANAGEMENT) && !defined(IPLIB)
#   error IPLIB or LIBCAE0SIMULATIONPROCESSMANAGEMENT is not defined
#endif

/* Handwritten code should use CAE0SIMULATIONPROCESSMANAGEMENT_API, not CAE0SIMULATIONPROCESSMANAGEMENTEXPORT */

#define CAE0SIMULATIONPROCESSMANAGEMENT_API CAE0SIMULATIONPROCESSMANAGEMENTEXPORT

#if IPLIB==libCAE0SimulationProcessManagement || defined(LIBCAE0SIMULATIONPROCESSMANAGEMENT)
#   if defined(__lint)
#       define CAE0SIMULATIONPROCESSMANAGEMENTEXPORT       __export(CAE0SimulationProcessManagement)
#       define CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL       extern __global(CAE0SimulationProcessManagement)
#       define CAE0SIMULATIONPROCESSMANAGEMENTPRIVATE      extern __private(CAE0SimulationProcessManagement)
#   elif defined(_WIN32)
#       define CAE0SIMULATIONPROCESSMANAGEMENTEXPORT       __declspec(dllexport)
#       define CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL       extern __declspec(dllexport)
#       define CAE0SIMULATIONPROCESSMANAGEMENTPRIVATE      extern
#   else
#       define CAE0SIMULATIONPROCESSMANAGEMENTEXPORT
#       define CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL       extern
#       define CAE0SIMULATIONPROCESSMANAGEMENTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CAE0SIMULATIONPROCESSMANAGEMENTEXPORT       __export(CAE0SimulationProcessManagement)
#       define CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL       extern __global(CAE0SimulationProcessManagement)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CAE0SIMULATIONPROCESSMANAGEMENTEXPORT      __declspec(dllimport)
#       define CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL       extern __declspec(dllimport)
#   else
#       define CAE0SIMULATIONPROCESSMANAGEMENTEXPORT
#       define CAE0SIMULATIONPROCESSMANAGEMENTGLOBAL       extern
#   endif
#endif
