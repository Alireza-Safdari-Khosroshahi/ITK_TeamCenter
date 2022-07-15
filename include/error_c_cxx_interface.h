/*HEAD ERROR_C_CXX_INTERFACE HHH SYSS */
/*===============================================================================

                  Copyright (c) 2003-2004 UGS Corp.
                        Unpublished - All rights reserved

=================================================================================
File description:

    This header file serves the purpose of providing an interface between the
    Error_Exception.hxx header file and *.c file that may include it.  The
    reason for this is primarily for QAZ so that *.c files that need to include
    Error_Exception.hxx will pass QAZ.
    
    So, if __lint is not defined, this header simply includes Error_Exception.hxx
    if the C++ compiler is active.

    If __lint is defined, than this header re-defines all the macros from
    Error_Exception.hxx that *.c files make use of.  Since some of those macros
    represent what use to be functions that can now only be used in an
    ERROR_PROTECT block, those are defined as function pointers within the
    ERROR_PROTECT block so that QAZ will generate an error if it encounters a
    function like ERROR_reraise outside of an ERROR_PROTECT block.

=================================================================================
   Date      Name                    Description of Change
NX3
02-Jul-2003  Lavarini                Split from error.h
04-Sep-2003  Jack Marr               Add qaz pragmas to flag bad calls
30-Sep-2003  Lavarini                ERROR_ask_last_error() is a function that can
                                     be called from anywhere
07-Oct-2003  Lavarini                Add param.h to pragma
17-Oct-2003  Lavarini                Add error_finally.h to pragma
27-Oct-2003  Lavarini                Add more enquiry functions for last failure
17-Nov-2004  Jack Marr               Fix redefinition error due to __lint block
03-Dec-2004  Lavarini                Convert ERROR functions to macros
$HISTORY$
===============================================================================*/

#ifndef ERROR_C_CXX_INTERFACE_H_INCLUDED
#define ERROR_C_CXX_INTERFACE_H_INCLUDED

#ifdef __lint
#   pragma uginclude only_in_error "abort.h","error_protect.h","error_top.h",\
                                   "error_escape.h","error_uf_protect.h",\
                                   "ui_dispatch.h","frust_protect.h","param.h",\
                                   "error_finally.h";
#endif

#include <error_datatypes.h>
#include <libsyss_exports.h>

//  The C++ header file is only included if the file being compile is
//  using the C++ compiler.  This was done specifically so that om.h
//  could continue to include error.h and rm_entity_tables.c will compile.
#if defined(__cplusplus)
#   include <Error_Exception.hxx>
#endif

//  Determine if the last exception is a valid failure exception.
//  This function will return false if an exception has not yet been thrown, or
//  if the last exception was an Escape exception.  This function will return
//  true otherwise.
extern SYSSEXPORT logical ERROR_is_last_failure ( void );

//  Return the error code of the last exception that was thrown.
//  This function will raise an Internal exception if an exception has not yet
//  been thrown, or if the last exception was an Escape exception.
extern SYSSEXPORT int ERROR_ask_last_failure_code ( void );

//  Determine if the last exception has been acknowledged.
//  This function will raise an Internal exception if an exception has not yet
//  been thrown, or if the last exception was an Escape exception.
extern SYSSEXPORT logical ERROR_is_last_failure_acknowledged ( void );

//  Return information pertaining to the last exception that was thrown.
//  This function will raise an Internal exception if an exception has not yet
//  been thrown, or if the last exception was an Escape exception.
extern SYSSEXPORT void ERROR_ask_last_error (
    char        filename[257],          // <O>
                                        // Name of file where the exception was thrown.
    int        *line_number,            // <O>
                                        // Line number in file where exception was thrown.
    char        message[1024]           // <O>
                                        // The message that was written to the syslog when
                                        // the exception was thrown.
);

#undef EXPORTLIBRARY

#endif /* ERROR_C_CXX_INTERFACE_H_INCLUDED */
