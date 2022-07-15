/*HEAD ERROR HHH SYSS */
/*==================================================================================================

                     Copyright (c) 1992-2005 UGS Corp.
                             Unpublished - All rights reserved

====================================================================================================
File description:                                                                                                              

ERROR system include file

====================================================================================================
   Date      Name                    Description of Change

20-June-1989    Hugh Stewart         Written
20-Sep-1990  Terry Ploeger     Add new func declarations.       
 2-Oct-1990  Bernard Solomon   For GNU use __BASE_FILE__ to get better error messages       
10-Oct-1990  Alan Braggins      make lprintf return int cf. printf       
15-Oct-1990  Alan Braggins     declare ERROR_special_routine_name on SPARC       
15-Oct-1990  Alan Braggins     need dummy address_of_caller on sparc       
 5-Feb-1991  Daniel Dignam     define ERROR_this_file-name for HP_68K:
 6-Feb-1991  Daniel Dignam     HP_68K port       
28-Feb-1991  Daniel Dignam     Add ERROR_set_system_log_name       
 8-Aug-1991  tim carter        HP/RISC port       
07-Feb-1992  bernard                 Initial revision of dev branch
20-Mar-1992  Tim Carter              Port to DECstation
16-Apr-1992  Hugh Stewart            declare ERROR_special_routine_name on HP
30-Apr-1992  Hugh Stewart            lower case hp9000s300 defined name
11-May-1992  Mike Abbott             Add UG headers
13-May-1992  Mike Abbott             Add UG machine-dependent header card
14-May-1992  Bernie Solomon          Use STDC signal prototype where necessary
06-Jul-1992  Bernie Solomon          Add debug handler
07-Jul-1992  Bernie Solomon          Add ERROR_reraise
07-Oct-1992  Bernie Solomon          Add ERROR_PROTECT macros etc.
07-Oct-1992  Bernie Solomon          Add
20-Oct-1992  Bernie Solomon          Make filename args const
09-Nov-1992  Bernie Solomon          Remove signal handling routines
09-Dec-1992  Mike Abbott             Add ERROR_ask_system_log
07-Jan-1993  Alan Braggins           jlint function pointer not void*
02-Dec-1992  Dennis Lavarini         Include basic.h in this header file
17-Jan-1993  Daniel Dignam           phase 8 ccr
22-Jan-1993  Mike Abbott             Add error number decoder routines
23-Jan-1993  Daniel Dignam           Should not include uguidefs.h
25-Jan-1993  Mike Abbott             Take out PROMPT (char *) to keep things clean, and comment
25-Jan-1993  Mike Abbott             Add warning about internationalisation
11-Mar-1993  Bernie Solomon          Fix for OSF port
26-Mar-1993  Bernie Solomon          Add a user signal routine so we can call KABORT for Parasolid
26-Mar-1993  Bernie Solomon          Make ERROR_decode_in_table take void *
21-Apr-1993  Bernie Solomon          Add in exception handling
07-May-1993  Alan Braggins           ERROR_generic_routine_t to use generic_routine_t
14-May-1993  Bernie Solomon          Add log file status stuff
18-May-1993  Daniel Dignam           ERROR_system_log_name_len should be longer
15-Jun-1993  Mike Reger              Removed SYS card
17-Jun-1993  Daniel Dignam           Add protoype for error_get_stack
23-Jun-1993  Daniel Dignam           IP1c integration
25-Jun-1993  Bernie Solomon          Make ERROR_ask_system_log take void
25-Jun-1993  Keith Simpson           IBM RS/6000 Port - Defined ERROR_this_file_name for IBM
                                     platform by adding IBM_AIX to an #if
02-Jul-1993  Daniel Dignam           1f CCR
29-Jul-1993  Bernie Solomon          Add ERROR_acknowledge_handled
30-Jul-1993  Bernie Solomon          Replace leading underscores in ERROR_PROTECT macros
05-Jan-1994  Daniel Dignam           ERROR_address_of_caller works on OSF as well
14-Jan-1994  Bernie Solomon          Add ERROR_EXCEPTION_PROTECT
10-Feb-1994  Brian Eschner           Remove ifdef around declaration of ERROR_special_routine_name
15-Nov-1993  Kurt Kohlhase           Add ERROR_ask_base
06-Mar-1994  Daniel Dignam           2e integration
07-Mar-1994  Daniel Dignam           Add error_cxx_demangle
27-May-1994  Bernie Solomon          Fix example in comment to have better style
                                     Add ERROR_init_module_no_log_file()
01-Jun-1994  Mark Fawcett            add a more general version of ERROR_log_file_to_stdout
09-Jun-1994  Mike Sze                Add prototype for ERROR_read_symbol_table, ERROR_save_symbol_table
24-Jun-1994  Mike Abbott             Include unidefs.h before we obsolete basic.h
31-Aug-1994  Mike Abbott             Phase 4 integration (Remove Mike Sze changes, basic.h)
18-Nov-1994  Bernie Solomon          Add ERROR_user_abort and associated code ERROR_USER_ABORT
                                     Rename ERROR_INTERNAL_ERROR as ERROR_INTERNAL_ERROR_CODE for Win NT clash
17-Mar-1995  Keith Hafen             Move to product syss
22-Mar-1995  Alasdair Mackintosh     Put correct head card into Jeeves
22-Mar-1995  Alasdair Mackintosh     Put correct head card into Jeeves
31-Mar-1995  Alasdair Mackintosh     Fix up head/class cards
14-Jul-1995  Daniel Dignam           Add ERROR_shared_library_unloaded
19-Aug-1996  Tom Slossar             Enable the suppression of error reporting
22-Aug-1996  Adrian Brown            CCR Phase 10 of V12.0
19-Sep-1996  Daniel Dignam           ip14 integration
16-Jan-1997  Adrian Brown            Fix ERROR_PROTECT to pass new cc_check variable scope check
11-Feb-1997  Bernie Solomon          Make ERROR_get_stack return a logical and document its interface
11-Feb-1997  Bernie Solomon          Make ERROR_get_stack interface return a logical and document it
14-Feb-1997  Bernie Solomon          Change for new exception & escape handling
22-Apr-1997  Bernie Solomon          Add ERROR_ask_system_log_stream to get at the FILE * by routine call
09-Sep-1997  Jack Marr               DLL breakup: make ERROR_system_log private to libsyss
18-Sep-1997  Mike Abbott             Integrate v14.0 phase 4 changes
23-Oct-1997  Bernie Solomon          lprintf clashes with Exceed V6 so rename it on WNT
11-Nov-1997  Keith Jaskot         Added missing f to lprintf #define
14-Nov-1997  Bernie Solomon          CCR time
20-Jul-1998  Adrian Brown            Resynch Jeeves and CMS
11-Aug-1998  Bernie Solomon          Reword comment on ERROR_exception as it has confused people
13-Nov-1998  Jack Marr               Move error decoder stuff to error_decode.h
16-Nov-1998  Bernie Solomon          Add extern "C" for C++ use
25-Jan-1999  Bernie Solomon          V16.0 phase 1 CCR
08-Mar-1999  Reger                   Decorate prototypes with UGEXPORT;
                                     remove VMSisms and other archaic
                     oddities
18-Mar-1999  Gary Smethers           V16 phase 5 CCR
30-Jun-1999  Jack Marr               Redo arg names to avoid conflict on WNT
08-Jul-1999  Alexandra Wagner        ip13 CCR
06-Oct-1999  Lavarini                Split the SYSSPRIVATE data into error_noexport.h
                                     Use SYSSEXPORT to decorate prototypes
29-Oct-1999  Gary Smethers           V16 phase 20 CCR
01-May-2000  Jack Marr               Revise ERROR_cxx_demangle signature
20-Jun-2000  JS                      Modified for CFI long file name project.
19-Oct-2001  Bernie Solomon          Add ERROR_set_raise_handler/ERROR_cancel_raise_handler
26-Oct-2001  Adrian Brown            Add ERROR_ask_detailed_routine_name
07-Mar-2002  Jon Runyon              Release V1804 projects into V19
16-Apr-2002  KHafen                  remove dependency on CFI
22-Nov-2002  Jack Marr               Note that lprintf is printf-like
09-Dec-2002  Jack Marr               Add const to ERROR_set_system_log arg
23-Jan-2003  Marjorie Anne Espinosa  Make timestamp function extern
02-Apr-2003  Steve Kunkee            ARCH0015a: C++ compatibility
                                     change ifdef to if on __cplusplus and
                                     CPLUSPLUS_COMPILE
03-Jun-2003  Alexandra Wagner        PR#4782592: Add ERROR_note_traceback
23-Jun-2003  Jack Marr               Remove aix-specific ERROR_cxx_demangle_ask_number_of_arguments()
NX3
17-Jul-2003  Lavarini                Split off error_datatypes.h and error_protect.h
18-Jul-2003  Lavarini                Enhance to use C++ throw/catch of class objects
26-Sep-2003  Lavarini                Add pragma 
02-Nov-2003  Lavarini                Add uft_utils.h to pragma
12-Jan-2004  Lavarini                Replace ERROR_raise_handler_t with
                                     ERROR_raise_handler_fn_p_t
19-Jan-2004  Bernie Solomon          Change the routine assertions call
21-Jan-2004  Bernie Solomon          Add ERROR_trace_back_to_log
23-Jan-2004  Lavarini                Re-implement ERROR debug handler in NX3
04-Feb-2004  KHafen                  Add support for a ui message in internal errors
04-Mar-2004  KHafen                  Remove C++ token that is no longer needed
28-Apr-2004  BJS                     Remove unimplemented version of ERROR_enter_debugger
02-Jun-2004  Bernie Solomon          Add ERROR_severe
13-Dec-2004  Nilesh Lakhotia         Added pvtrans*.h to pragma.
09-Feb-2005  Raman Garimella         Added ERROR_ask_count_of_signal_errors
13-Apr-2005  Bernie Solomon          Make ERROR_assertion_failed printf-like
03-May-2005  Lavarini                Add jam_errors.h to pragma.
11-May-2005  Nilesh Lakhotia         Delete pvtrans*.h from #pragma
13-Jul-2005  Alasdair Mackintosh     Add ERROR_vraise
$HISTORY$
==================================================================================================*/
#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

/*  <DJL> 26-Sep-2003
*   The header files in the pragma are necessary for the most part because
*   these header files define macros that raise errors or write to the system
*   log.  The header om.h is the exception; error.h needs to be removed from
*   om.h.
*/
/*  <DJL> 03-May-2005
*   Add jam_errors.h to pragma.  This is necessary because the JA/JAX functions
*   use the ERROR macros/functions, and they are picking up error.h because it is 
*   currently included in om.h.  I have changed jam_errors.h so that JA/JAX functions
*   can pick up error.h without depending on error.h being included in om.h.
*/
#ifdef __lint
#   pragma uginclude only_in_error "assert.h","cerr.h","debug_macros.h",\
    "dss_regen_context_datatypes.h","dss_trace.h","error_noexport.h",\
    "fa_error_codes.h","fcp.h","git_internal.h","gr_opman.h","jam_errors.h","rdebug.h",\
    "sf_map_lp_kit.h","sf_mm_internal.h","sim_error.h","stl_stdpccts.h",\
    "sv_error.h","tol_feat_internal_datatypes.h","uft_rl_tests.h",\
    "uft_rte_tests.h","uft_utils.h","ugfont.h","*_definitions.h",\
    "*.c","*.cpp","*.cxx","om.h";
#endif

#include <stdarg.h>
#include <stdio.h>

/*<KDH> 16-Apr-2002
  WARNING: Do not add any other UG headers to this file, as the IMAN ITK releases
  error.h with their product.
*/

/* <JLM> 13-May-98
   Moved error decoder stuff to error_decode.h and error_decode_privileged.h
   as a facet of the effort to eliminate nesting of error_bases.h.  In order 
   to avoid having to edit many of the routines that included error.h to get 
   at the prototypes now in error_decode.h, we include that here, although
   it should be included directly if needed.  QAZ/cc_check warnings will 
   help nudge us in that direction.

   The prototypes for actually registering error codes are in 
   error_decode_privileged.h, which may not be nested.
 */
  
#include <error_datatypes.h> 
#include <error_decode.h> 
#include <error_protect.h> 

/* The following must be the last include file */
#include <libsyss_exports.h>

/* ERROR_init_module

   Initialises error handling system. It is best if this is called
   as early on in a run as possible.
*/
extern SYSSEXPORT void ERROR_init_module(void);
extern SYSSEXPORT void ERROR_exit_module(void);

/* <Haiming Gu> 03-Dec-2010
   The following section of typedef and functions allows the libsyss comsumer
   to define its own print_log and use the same upon proper initialization - this
   can be done by invoking ERROR_set_print_log_replacement in the consumer code.
   Additionally, an int argument (default to 1, meaning true) can be passed into
   ERROR_set_print_log_replacement to decide if print_log should preserve the legacy
   log entries, prior to making additional log.
*/
typedef void (*ERROR_print_log_fn_t) (const char *type, const char *file_name, int line_number, const char *message);
extern SYSSEXPORT void ERROR_set_print_log_replacement(ERROR_print_log_fn_t function, int do_legacy);

extern SYSSEXPORT int  ERROR_needLegacyLog();
extern SYSSEXPORT void ERROR_doAdditionalLog(const char *type, const char *file_name, int line_number, const char *message);

typedef void (*ERROR_display_fn_t) ( const int ifail, const int type, const char* message);
extern SYSSEXPORT void ERROR_register_display_fn(ERROR_display_fn_t);

/*  ERROR_init_module_no_log_file

    <BJS> 27-May-94
    Initialise the ERROR module so that you can set error handlers
    but the log file isn't open yet. Errors will go to stderr in this
    case. A subsequent call to ERROR_init_module will complete the
    initialisation and open the log file.
*/
extern SYSSEXPORT void ERROR_init_module_no_log_file(void);

/* ERROR_set_traceback

   Sets a flag (static to error.c) used to toggle whether to do a traceback
   or not on an error. The initial state of this flag is true.
*/
extern SYSSEXPORT void ERROR_set_traceback(logical state);

/* ERROR_ask_traceback

   Returns the flag value set by ERROR_set_traceback.
*/
extern SYSSEXPORT logical ERROR_ask_traceback(void);

/*  <BJS> 14-May-93
    Routines to ask and set the current log file status
*/

extern SYSSEXPORT void ERROR_set_log_file_status(ERROR_log_file_status_t status);
extern SYSSEXPORT ERROR_log_file_status_t ERROR_ask_log_file_status(void);


/*  ERROR_ask_signal_code

    Returns the last signal code raised by the OS as an offset
    from ERROR_sig_base. The last signal can be found in ERROR_ask_failure_code
*/

extern SYSSEXPORT int ERROR_ask_signal_code(void);


/* ERROR_note

   Generates a warning message. Note this is totally transparent
   to the user of the system.

   Prints suitable information somewhere.

   It will only produce a traceback if checking is turned on.

   Returns.
*/
extern SYSSEXPORT void ERROR_note(const char *file_name, int line_number,
                       const char *control_string, ...);

/* ERROR_note_traceback

   Generates a warning message. Note this is totally transparent
   to the user of the system.

   Prints suitable information somewhere.

   It will produce a traceback independent of the checking level.

   PLEASE ONLY USE IF YOU ABSOLUTELY,POSITIVELY,DEFINITELY WANT
   A TRACEBACK TO APPEAR IN CUSTOMER VERSIONS! Otherwise use 
   ERROR_note.

   Returns.
*/
extern SYSSEXPORT void ERROR_note_traceback(const char *file_name, int line_number,
                       const char *control_string, ...);

/* ERROR_vnote

   like ERROR_note but takes a va_list
*/
extern SYSSEXPORT void ERROR_vnote(const char *file_name, int line_number,
                        const char *control_string, va_list args);

/*  ERROR_escape

    <BJS> 10-Feb-97
    Generate an ESCAPE event which isn't caught be error handlers.
    Only for use by CLINK and so on in UG. So no message arguments.
*/

extern SYSSEXPORT void ERROR_escape(const char *file_name, int line_number, int exception_code_);

/*  ERROR_exception

    <BJS> 11-Aug-98
    This is identical to ERROR_raise but does not produce a traceback in the log file
*/

extern SYSSEXPORT void ERROR_exception(const char *file_name, int line_number, int exception_code_,
                            const char *control_string, ...);

/* ERROR_raise

   Raise an error condition which will get returned through the procedural
   interface as a failure_code code. This has a subsiduary string message which
   is a standard printf control string and arguments.
   The recovery algorithm is as follows. Note that if called with no handlers
   set up it changes to a ERROR_collapse.

   Print suitable information somewhere.

   while (handler stack not empty)
     { Take top handler off stack.
       Note current handler stack height.
       Call handler with result of ERROR_ask_failure_code as argument.
       if (handler has changed the stack height)
         { Note this error somewhere.
           if (stack has grown)
             { Reset stack to value before calling handler
               i.e. ignore extra handlers.
             }
           else
             { Continue calling the
               handler on the current top of the stack.
             }
         }
     }

   None of the handlers caught it properly all we can do is
   change the call to an ERROR_collapse.
*/
extern SYSSEXPORT void ERROR_raise(const char *file_name, int line_number, int failure_code,
                        const char *control_string, ...);

/* ERROR_vraise

   Version of ERROR_raise that takes a va_list

*/
extern SYSSEXPORT void ERROR_vraise (const char *file_name, int line_number, int failure_code, const char *control_string, va_list ap);

/* ERROR_severe

   Raise a severe error condition.
   This has a subsiduary string message which is a standard printf control string and 
   arguments.
   The recovery algorithm is as follows. Note that if called with no handlers
   set up it changes to a ERROR_collapse.

   Print suitable information somewhere.

   while (handler stack not empty)
     { Take top handler off stack.
       Note current handler stack height.
       Call handler with result of ERROR_ask_failure_code as argument.
       if (handler has changed the stack height)
         { Note this error somewhere.
           if (stack has grown)
             { Reset stack to value before calling handler
               i.e. ignore extra handlers.
             }
           else
             { Continue calling the
               handler on the current top of the stack.
             }
         }
     }

   If none of the handlers caught it properly all we can do is
   change the call to an ERROR_collapse.
*/
extern SYSSEXPORT void ERROR_severe(const char *file_name, int line_number, int failure_code,
                        const char *control_string, ...);

/* ERROR_internal

   Raise an internal error condition which will get returned through the procedural
   interface as specially-defined failure code generated from inside this function. 

   This is equivalent to ERROR_severe being called with ERROR_INTERNAL_ERROR_CODE.
*/
extern SYSSEXPORT void ERROR_internal(const char *file_name, int line_number, const char *control_string, ...);

/*  <BJS> 8-Jan-2004
    Special routine for assertion failures.
    <BJS> 13-Apr-2005
    Made to take format string and substitutions
*/
extern SYSSEXPORT void ERROR_assertion_failed(const char *file_name, int line_number, const char *format, ...);

/* ERROR_collapse

   Prints suitable information somewhere.
   Then calls exit(EXIT_FAILURE).

   Note this routine should only be called in desperate circumstances.
*/
extern SYSSEXPORT void ERROR_collapse(const char *file_name, int line_number,
                           const char *control_string, ...);

/* ERROR_vcollapse

   like ERROR_collapse but takes a va_list
*/
extern SYSSEXPORT void ERROR_vcollapse(const char *file_name, int line_number,
                            const char *control_string, va_list args);

/*  <BJS> 18-Nov-94
    Generate a user abort exception (well its really an error
    so ERROR_PROTECT catches it).
*/

extern SYSSEXPORT void ERROR_user_abort(const char *file_name, int line_number);

/* ERROR_ask_statistics

   Returns statistics as to how many notes, errors (from ERROR_(v)raise) and
   internal errors (from ERROR_(v)internal) have been raised.
   Note there is no point in having a value for collapses!

*/
extern SYSSEXPORT void ERROR_ask_statistics(int *number_of_notes, int *number_of_raises, int *number_of_internals);

/* ERROR_ask_count_of_signal_errors

Returns a count of the number of signal errors that 
were raised during a session

*/
extern SYSSEXPORT int ERROR_ask_count_of_signal_errors( void );

/* ERROR_log_file_to_stdout

   debugging routines:
     - copies up to the last 4000 characters of log file to stdout
     - copies up to the last <nbytes> characters of log file to <stream>
*/
extern SYSSEXPORT void ERROR_log_file_to_stdout(void);
extern SYSSEXPORT void ERROR_log_file_to_stream (int nbytes, FILE * stream);
extern SYSSEXPORT void ERROR_set_log_file_stream(FILE* stream);
/* ERROR_set_note_handler

   sets up a routine that is called every time an ERROR_note is provoked
*/
extern SYSSEXPORT void ERROR_set_note_handler(ERROR_note_handler_t note_handler);

/* ERROR_cancel_note_handler

   clears the routine that is called every time an ERROR_note is provoked

   essentially calls ERROR_set_note_handler(NULL);
*/
extern SYSSEXPORT void ERROR_cancel_note_handler(void);

/*  ERROR_set_raise_handler

    <BJS> 19-Oct-01
    Set up a handler to be called before any error is raiseed. Different
    from ERROR_set_handler in that the handler is persistent and never
    automatically cancelled. Can be use e.g. so Fusion can dump
    extra info in the syslog on errors.
    Returns an id for the set up handler so it can be removed.
*/
extern SYSSEXPORT ERROR_raise_handler_id_t ERROR_set_raise_handler
(
    ERROR_raise_handler_fn_p_t raise_handler
);

/*  ERROR_cancel_raise_handler

    <BJS> 19-Oct-01 
    Cancel a previously set up raise handler.
*/
extern SYSSEXPORT void ERROR_cancel_raise_handler(ERROR_raise_handler_id_t id);

/*  <BJS> 26-Mar-93
    Routines to manipulate user suppliable signal routine. 
    Is simply  called with the signal number and may return to
    faulting code (e.g. for ^C) or continue fault handling
*/

extern SYSSEXPORT void ERROR_set_signal_handler(ERROR_signal_fn_t signal_fn);
extern SYSSEXPORT ERROR_signal_fn_t ERROR_ask_signal_handler(void);

/*  <BJS> 06-Jul-92
    These routines allow you to set up one and only one debug handler
    or enquire what the current debug handler is. If there is a debug handler
    then this is called before any other handlers.

    If there is no debug handler then ERROR_ask_debug_handler returns NULL
    for the handler.
*/

extern SYSSEXPORT ERROR_debug_handler_t ERROR_set_debug_handler ( const ERROR_debug_handler_t *pHandler );

/*  <DRD> 28-Feb-1991

    Allow people to set the system log name
*/
extern SYSSEXPORT void ERROR_set_system_log(const char *name);

/*  <MRA> 09-Dec-1992
    I now need to be able to ask what the system log name has been set to.
    The returned value points to the internal string, so must not be
    SM_free'd or overwritten.  No space need be allocated for it by the
    caller either.  WARNING: a call to ERROR_set_system_log after the
    log has been created and written to has no effect on the log, but will
    change the value returned by this routine.
*/
extern SYSSEXPORT char *ERROR_ask_system_log(void);

/*
To be decided:

how do we generate failure_codes.
system vs user failures. <TP> partially covered by ERROR_internal etc.
suitable information somewhere - clarify.
how do signals fit in.
how do interrupts fit in.
*/

/*  <BJS> 23-Oct-97
    This is pretty ugly. With Exceed V6 we have a clash
    with 'lprintf' as a symbol so we get link problems. 
    For expediency I am just renaming the symbol via a macro.
*/
#ifdef WNT
#define lprintf ERROR_lprintf
#endif

/* <BJS> I do not think this routine should be here
   or it should be called something else! (lprintf)
*/
/*PRINTFLIKE1*/
extern SYSSEXPORT int lprintf(const char *control_string,...);

/*  <BJS> 22-Apr-97
    ERROR_ask_system_log_stream is provided as an alternative way to
    get at ERROR_system_log but by a routine call. This makes access outside
    a NT DLL easier.
*/

extern SYSSEXPORT FILE *ERROR_ask_system_log_stream(void);

extern SYSSEXPORT void ERROR_trace_back(FILE *);

/*  <BJS> 21-Jan-2004
    Send a traceback to the log file - avoids use of FILE * outside libsyss for TCEng
*/
extern SYSSEXPORT void ERROR_trace_back_to_log(void);

extern SYSSEXPORT void ERROR_trace_set_output(FILE *);

/*  <DRD> 14-Jul-1995

    Called to inform the trace back code that a library  has been unloaded, returns true
    if everything went okay, false if it didn't
*/

extern SYSSEXPORT logical ERROR_shared_library_unloaded(void);

/*  <AB> 24-Oct-2001
    Returns the name of the given function.  The buffer needs to be
    "long enough" - whatever that means.  512 should be enough according
    to a comment from Jack Marr in error_wnt_trace_back.c.
    
    ERROR_ask_detailed_routine_name is like ERROR_routine_name except
    that it gives you a line-number if it can (currently only supported
    on Windows).  For ERROR_ask_detailed_routine_name, I've replicated
    ERROR_routine_name's rather awkward prototype for the sake of consistency
    (and because on some platforms it just calls ERROR_routine_name).
*/

extern SYSSEXPORT int ERROR_routine_name(ERROR_generic_routine_t fn, char *name);
extern SYSSEXPORT void ERROR_ask_routine_name(ERROR_generic_routine_t fn, int bufferSize, char *buffer);
extern SYSSEXPORT void ERROR_ask_detailed_routine_name(ERROR_generic_routine_t pc, int bufferSize, char *buffer);

/*  <BJS> 10-Feb-97
    ERROR_get_stack

    Return a set of PCs in the PCS array.
    MAX_DEPTH is the length of the PCS array.
    DEPTH is set to the actual number of array entries filled in and
    may be less than MAX_DEPTH (e.g. is you get to main)
    STREAM is used for printing extra messages about problems.
    The return result is true if nothing particular went wrong and false
    if we had problems unwinding the stack at some stage.

    The traceback is in the order such that the mostly deeply nested
    routine on the stack is PCS[0]. In fact PCS[0] is always an
    address in the caller of ERROR_get_stack itself.
*/

extern SYSSEXPORT logical ERROR_get_stack(FILE *stream, int max_depth, int *depth, ERROR_generic_routine_t *pcs);

/*  <DRD> 07-Mar-1994
    Add C++ demangle routine
    <JLM> 01-May-2000
    Revise signature to omit *args, require sizeof output buffer ("decoded").
    Return value is true if demangling succeeded regardless of whether result
    is truncated.  The decoded string will always be null terminated.
*/

extern SYSSEXPORT logical ERROR_cxx_demangle(const char *encoded, char *decoded, size_t buflen);

/*  <KDS> IBM RS/6000 Port - Added support for IBM_AIX    */
/*  <BDE> 09Feb94
 *  Remove  ifdef "list of all known platforms..."
 */
extern SYSSEXPORT int ERROR_special_routine_name (ERROR_generic_routine_t, char *);
extern SYSSEXPORT ERROR_generic_routine_t ERROR_address_of_caller (void);

/*  <TAS> 19-Aug-96
    This is a registered function that determines if the
    error reporting mechinism should be suppressed.
*/
extern SYSSEXPORT ERROR_suppression_fn_p_t ERROR_set_error_suppressor( ERROR_suppression_fn_p_t query_function);

extern SYSSEXPORT char * ERROR_timestamp ( void );

#undef EXPORTLIBRARY

#endif /* ERROR_H_INCLUDED */
