/*HEAD LIBUGMATH_EXPORTS HHH UGMATH */
/*=============================================================================
            Copyright (c) 1999 Unigraphics Solutions Inc.
                      Unpublished - All rights reserved
===============================================================================
File Description:

    The header file that defines the export symbols for the
    UGMATH library

===============================================================================
Date          Name                   Description
12-Aug-1999   Reger                  Initial version
19-Oct-1999   Lavarini               Add pragma to restrict inclusion
01-Nov-1999   Lavarini               Implement WNT_STATIC_LINK switch
$HISTORY$
=============================================================================*/

#ifndef LIBUGMATH_EXPORTS_H_INCLUDED
#define LIBUGMATH_EXPORTS_H_INCLUDED

#ifdef __lint
#   pragma uginclude only_in_error "libugmath_main.c", "*.h";
#endif

#define libugmath                10016
#define EXPORTLIBRARY            libugmath

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#if IPLIB==libugmath
#   if defined(__lint)
#       define UGMATHEXPORT       __export(ugmath)
#       define UGMATHGLOBAL       extern __global(ugmath)
#       define UGMATHPRIVATE      extern __private(ugmath)
#   elif defined(_WIN32)
#       define UGMATHEXPORT       __declspec(dllexport)
#       define UGMATHGLOBAL       extern __declspec(dllexport)
#       define UGMATHPRIVATE      extern
#   else
#       define UGMATHEXPORT
#       define UGMATHGLOBAL       extern
#       define UGMATHPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define UGMATHEXPORT       __export(ugmath)
#       define UGMATHGLOBAL       extern __global(ugmath)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define UGMATHEXPORT       __declspec(dllimport)
#       define UGMATHGLOBAL       extern __declspec(dllimport)
#   else
#       define UGMATHEXPORT
#       define UGMATHGLOBAL       extern
#   endif
#endif

#endif  /*  LIBUGMATH_EXPORTS_H_INCLUDED  */
