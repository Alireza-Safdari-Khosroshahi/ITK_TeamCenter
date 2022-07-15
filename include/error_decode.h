/*HEAD ERROR_DECODE HHH SYSS */
/*CLASS ERROR */
/*==============================================================================

          Copyright (c) 1998,1999 Unigraphics Solutions Inc.
                   Unpublished - All rights reserved

================================================================================
File description: 
    Function prototypes for the named module or functional area.

================================================================================
   Date      Name                   Description of Change
13-Nov-1998  Jack Marr              Move contents from error.h
18-Nov-1998  Jack Marr              Add ERROR_OK from error_bases.h
25-Jan-1999  Adrian Brown            Create in Jeeves
08-Mar-1999  Reger                  Decorate prototypes with UGEXPORT;
                                    include unidefs.h for UGEXPORT
18-Mar-1999  Gary Smethers           V16 phase 5 CCR
12-Oct-1999  Lavarini               Use SYSSEXPORT to decorate prototypes
29-Oct-1999  Gary Smethers           V16 phase 20 CCR
NX 2
08-Jul-2002  Lavarini               Add ERROR_ask_fail_message()
28-Jul-2005  BJS                    Provide out of memory code registration mechanism
$HISTORY$
==============================================================================*/

#ifndef ERROR_DECODE_H_INCLUDED
#define ERROR_DECODE_H_INCLUDED

#include <libsyss_exports.h>

/*  <MRA> 11-Jan-93
    Routines written to decode error numbers into useful strings.
    See error_decode.c for details.

    <JLM> 13-Nov-98
    Prototypes for registration functions and types moved to 
    error_decode_privileged.h.
*/

extern SYSSEXPORT char * ERROR_decode(int code);

/* <KEK> 15-Nov-93
   Return the error base of the given error code.  Returns 0 if no error base
   is found or if the error is an internal error.
*/
extern SYSSEXPORT int ERROR_ask_base(int code);

/* <DJL> 08-Jul-2002
   This function was renamed from ASSY_get_fail_message().  There needs to
   be more standardized method of getting error messages.  The return 
   char * is NOT freed after use.  This function calls both ERROR_decode()
   and CFI_decode_error().
*/
extern SYSSEXPORT char * ERROR_ask_fail_message ( int code );

//  <BJS> 25-Jul-2005
//  Register a given error code as signifying out of memory of some sort.
extern SYSSEXPORT void ERROR_register_out_of_memory_code(int code);

//  <BJS> 25-Jul-2005
//  Test if a given error code is some sort of out of memory code
extern SYSSEXPORT logical ERROR_is_out_of_memory_code(int code);

/* <JLM> 18-Nov-98  Add the ubiquitous ERROR_OK */

#define ERROR_OK 0

#undef EXPORTLIBRARY

#endif   /* ERROR_DECODE_H_INCLUDED */
