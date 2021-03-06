/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2019.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the export declarations for the library Rzc0rlzcm

    This file should be obsoleted once the autogenerated version is created in out/meta/Rzc0rlzcm folder.
    The autogenerated version will be generated after any metamodel operation is defined or overridden
    in the Rzc0rlzcm template.

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libRzc0rlzcm

#if !defined(libRzc0rlzcm) && !defined(IPLIB)
#   error IPLIB or libRzc0rlzcm is not defined
#endif

/* Handwritten code should use RZC0RLZCM_API, not RZC0RLZCMEXPORT */

#define RZC0RLZCM_API RZC0RLZCMEXPORT

#if IPLIB==libRzc0rlzcm || defined(libRzc0rlzcm)
#   if defined(__lint)
#       define RZC0RLZCMEXPORT       __export(Rzc0rlzcm)
#       define RZC0RLZCMGLOBAL       extern __global(Rzc0rlzcm)
#       define RZC0RLZCMPRIVATE      extern __private(Rzc0rlzcm)
#   elif defined(_WIN32)
#       define RZC0RLZCMEXPORT       __declspec(dllexport)
#       define RZC0RLZCMGLOBAL       extern __declspec(dllexport)
#       define RZC0RLZCMPRIVATE      extern
#   else
#       define RZC0RLZCMEXPORT
#       define RZC0RLZCMGLOBAL       extern
#       define RZC0RLZCMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define RZC0RLZCMEXPORT       __export(Rzc0rlzcm)
#       define RZC0RLZCMGLOBAL       extern __global(Rzc0rlzcm)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define RZC0RLZCMEXPORT      __declspec(dllimport)
#       define RZC0RLZCMGLOBAL       extern __declspec(dllimport)
#   else
#       define RZC0RLZCMEXPORT
#       define RZC0RLZCMGLOBAL       extern
#   endif
#endif
