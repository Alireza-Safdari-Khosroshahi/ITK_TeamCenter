/*HEAD ERROR_PROTECT HHH SYSS */
/*===============================================================================

                 Copyright (c) 2003 Unigraphics Solutions Inc.
                        Unpublished - All rights reserved

=================================================================================
File description:                                                                                                              

Header file to define the normal macros for error handling in application code.
The normal usage of these macros is described here:

            ERROR_PROTECT

                mark = set_markpoint();
                make_a_part();
                save_part(file_name);

            ERROR_RECOVER

                int code = ERROR_ask_failure_code();

                if (code == OM_err_disk_full ||
                    code == ERROR_KI_base + KI_disc_full)
                { 
                    -- perhaps we have code to try again with a --
                    -- filename on a different disk --
                   
                    ERROR_acknowledge_handled ( );
                }
                else 
                { 
                    -- other errors we can't recover from here --
                    -- undo and reraise --

                    undo_to_mark(mark);
                    ERROR_reraise();
                }

            ERROR_END

In an ERROR_RECOVER block, there are two possibilities: either the error will
be processed within the block and the error will be acknowledged, or the 
error will not be recognized within the block and it will be re-raised to the
next ERROR_RECOVER block.  For every error, these are the only two choices --
either call ERROR_reraise() or call ERROR_acknowledge_handled().  Only the
Standard exception will be allowed to pass to the line after ERROR_END, and
that will only happen if the exception has been acknowledged.


=================================================================================
   Date      Name                    Description of Change
NX3
17-Jul-2003  Lavarini                Split from error.h
19-Sep-2003  Lavarini                Add more header files to pragma
$HISTORY$
================================================================================*/

#ifndef ERROR_PROTECT_H_INCLUDED
#define ERROR_PROTECT_H_INCLUDED

#ifdef __lint
#   pragma uginclude only_in_error "csfadpmacros.hxx","error.h","*.c","*.cxx",\
                                   "*.cpp";
#endif

#include <error_c_cxx_interface.h>

#define ERROR_PROTECT       ERROR_DEFAULT_PROTECT

#define ERROR_RECOVER       ERROR_DEFAULT_RECOVER(ERROR_PROTECT_TYPE)

#define ERROR_END           ERROR_DEFAULT_END(ERROR_PROTECT_TYPE)

#endif /* ERROR_PROTECT_H_INCLUDED */
