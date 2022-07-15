/*HEAD LIBSYSS_EXPORTS HHH SYSS */
/*=============================================================================
            Copyright (c) 1999-2003 Unigraphics Solutions Inc.
                      Unpublished - All rights reserved
===============================================================================
File Description:

    The header file that defines the export symbols for the
    SYSS library

===============================================================================
Date          Name                   Description
01-Oct-1999   Lavarini               Initial version
19-Oct-1999   Lavarini               Add pragma to restrict inclusion
29-Oct-1999   Gary Smethers          V16 phase 20 CCR
01-Nov-1999   Lavarini               Implement WNT_STATIC_LINK switch
NX3
16-Jul-2003   Lavarini               Add "*.hxx" to the pragma
$HISTORY$
=============================================================================*/

#ifndef LIBSYSS_EXPORTS_H_INCLUDED
#define LIBSYSS_EXPORTS_H_INCLUDED

#ifdef __lint
#   pragma uginclude only_in_error "libsyss_main.c", "*.h", "*.hxx";
#endif

#define libsyss                  10017
#define EXPORTLIBRARY            libsyss

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#if IPLIB==libsyss
#   if defined(__lint)
#       define SYSSEXPORT       __export(syss)
#       define SYSSGLOBAL       extern __global(syss)
#       define SYSSPRIVATE      extern __private(syss)
#   elif defined(_WIN32)
#       define SYSSEXPORT       __declspec(dllexport)
#       define SYSSGLOBAL       extern __declspec(dllexport)
#       define SYSSPRIVATE      extern
#   else
#       define SYSSEXPORT
#       define SYSSGLOBAL       extern
#       define SYSSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SYSSEXPORT       __export(syss)
#       define SYSSGLOBAL       extern __global(syss)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SYSSEXPORT       __declspec(dllimport)
#       define SYSSGLOBAL       extern __declspec(dllimport)
#   else
#       define SYSSEXPORT
#       define SYSSGLOBAL       extern
#   endif
#endif

#endif  /*  LIBSYSS_EXPORTS_H_INCLUDED  */
