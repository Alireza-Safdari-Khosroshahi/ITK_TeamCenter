/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    #JOURNAL_routine_start - logs the start of journalling for a given routine call <br>
    #JOURNAL_routine_call - logs the end of logging its arguments before calling it <br>
    #JOURNAL_routine_end - logs the end of logging return values
*/

/*  */

#ifndef  JOURNAL_INCLUDED
#define  JOURNAL_INCLUDED

#include <stdio.h>
#include <mld/libmld_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup JOURNAL Journalling

    The following functions are available if you wish to journal function calls.
    You may want to add conditional journalling switches to your program
    much like standard Teamcenter Engineering does.

    All arguments to JOURNAL functions are inputs.
    (except for JOURNAL_ask_file_name)

    To use the functions, include file journal.h.

    @code
        #include <journal/journal.h>

        int AE_ask_tool_input_formats(tag_t   tool,
                                      int*    format_count,
                                      char*** input_formats)
        {
            int retcode = ITK_ok;
            if( my_journal_switch_is_on() )
            {
                JOURNAL_routine_start ("AE_ask_tool_input_formats");
                JOURNAL_tag_in (tool);
                JOURNAL_output_argument ("format_count");
                JOURNAL_output_argument ("input_formats");
                JOURNAL_routine_call ();
                JOURNAL_comment ("You can add comments to the journal file if you want");
            }

            if( my_journal_switch_is_on() )
            {
                JOURNAL_integer_out ("format_count", *format_count);
                JOURNAL_string_array_out ("input_formats", *format_count, *input_formats);
                JOURNAL_return_value (retcode);
                JOURNAL_routine_end();
            }

            return retcode;
        }
    @endcode

    @{
*/

/**
    Code returned by #JOURNAL_set_performance_journal_level_preset when the specified performance performance level is invalid.
*/
#define JOURNAL_invalid_performance_journal_level -1

/**
    Code returned by #JOURNAL_set_performance_journal_level_preset when the performance journal level cannot be changed.
*/
#define JOURNAL_cannot_change_performance_journal_level -2


/**
    Logs the start of journalling for a given routine call.

    It is important to use this properly if you expect the
    indentation in the journal file to look correct.
*/
MLD_API void JOURNAL_routine_start (
    const char*     name    /**< (I) */
    );

/**
    Sets a proposed journal file name.  If you do not call #JOURNAL_open_file
    explicitly then a journal file will be opened with this name the first time
    you call #JOURNAL_routine_start or #JOURNAL_comment
    If you don't call this function then the journal file will be called journal_file.
    If you call this function repeatedly then each call superseds the name given by
    an earlier call.  If you call this function after the journal file has been
    opened then it will have no effect.
*/
MLD_API int JOURNAL_set_file_name (
    const char*  file_name    /**< (I) */
    );

/**
    Takes the name of the ERROR log file and sets the journal file name to be that name
    but with a .jnl extension.  If called before the error log file has been opened, or
    after the journal file has been opened then this call will have no effect.
*/
MLD_API int JOURNAL_set_file_name_from_error_log ( void );

/**
    Returns the journal file name.  If you have not yet opened the journal file then
    the name will be the one last set by #JOURNAL_set_file_name
*/
MLD_API int JOURNAL_ask_file_name (
    char**  file_name    /**< (OF) */
    );

/**
    Returns the journal file pointer.
*/
MLD_API FILE* JOURNAL_get_file_fp ( void );

/**
    Opens the journal file. If you do not call #JOURNAL_open_file,
    then the default journal file name becomes journal_file.
    The name given here will supersede any name given by #JOURNAL_set_file_name
*/
MLD_API int JOURNAL_open_file (
    const char*  file_name    /**< (I) */
    );

/**
    Print statistics gathered to date to the journal file.
*/
MLD_API int JOURNAL_print_statistics();

/**
    Reset statistics gathered to date.
*/
MLD_API int JOURNAL_reset_statistics();

/**
    Closes the journal file. If you do not call #JOURNAL_open_file,
    then the default journal file name becomes journal_file.
*/
MLD_API int JOURNAL_close_file (void);

/**
    Logs the end of logging its arguments before calling it.

    It is important to use this properly if you expect
    the indentation in the journal file to look correct.
*/
MLD_API void JOURNAL_routine_call(void);

/**
    Logs the end of logging return values.

    It is important to use this properly if you expect
    the indentation in the journal file to look correct.
*/
MLD_API void JOURNAL_routine_end(void);

/**
    Adds the specified string to the journal file as a comment.

    If you call #JOURNAL_comment after a #JOURNAL_routine_start,
    but before #JOURNAL_routine_call or #JOURNAL_routine_end
    (i.e., while it is in the middle of journalling arguments),
    it remembers the comment string and outputs it at the #JOURNAL_routine_call point
    (when the journal file starts commented out stuff again).
    Only one comment string is remembered (the last).
*/
MLD_API void JOURNAL_comment (
    const char*     comment
    );

/**
    Temporarily enables or disables journaling
    The journal file remains open, but nothing is written to the file whilst journaling is disabled
*/
MLD_API void JOURNAL_set_journaling (
    logical enable_journaling
    );

/**
    returns true if journaling is currently enabled
    (note that if the output limit has been exceeded then journaling may be enabled
     but nothing will be written to the journal file)
*/
MLD_API logical JOURNAL_is_journaling (void);


/**
    Sets the level of performance journaling.
    <br>If called before the journal file is open, this operation overrides the value
    of the TC_PERFORMANCE_ONLY_JOURNALING environment variable.
    @returns
    <ul>
    <li>0 on success
    <li>#JOURNAL_invalid_performance_journal_level if the provided value is incorrect
    <li>#JOURNAL_cannot_change_performance_journal_level if the journal file is already opened and the level cannot, therefore, be set.
    </ul>
*/
MLD_API int JOURNAL_set_performance_journal_level_preset ( 
    int level  /**< (I) The journaling level. Valid values are:
                        <ul>
                        <li>0: performance-only journaling is turned off. This is the normal full journaling.
                        <li>1: performance-only journaling, with version 1 syntax.
                        <li>2: performance-only journaling, with version 2 syntax.
                        </ul> */
    );

/**
    Returns the current level of performance journaling.
    @returns
    <ul>
    <li>0: performance-only journaling is turned off. This is the normal full journaling.
    <li>1: performance-only journaling, with version 1 syntax.
    <li>2: performance-only journaling, with version 2 syntax.
    </ul>
*/
MLD_API int JOURNAL_get_performance_journal_level ( void );

/**
    Outputs the name of an argument, but not its value. For example,
    you can use it to output the names of output arguments at the time that a function is called.
*/
MLD_API void JOURNAL_output_argument (
    const char* name    /**< (I) */
    );

/**
    Begins and ends the journal entry for a single function.
    These functions are normally used in every function.
    It is important to use these properly if you expect the indentation in the journal file to look correct.
*/
MLD_API void JOURNAL_return_value (
    int     status      /**< (I) */
    );

/**
    Outputs the names and values for arguments whose types are not known.
*/
MLD_API void JOURNAL_nyi_in (
    const void*     in      /**< (I) */
    );

/**
    Outputs the names and values for arguments whose types are not known.
*/
MLD_API void JOURNAL_nyi_array_in (
    int         length,     /**< (I) */
    const void* in          /**< (I) */
    );

/**
    Outputs the names and values for arguments whose types are not known.
*/
MLD_API void JOURNAL_nyi_out (
    const char*     name,   /**< (I) */
    const void*     out     /**< (I) */
    );

/**
    Outputs the names and values for arguments whose types are not known.
*/
MLD_API void JOURNAL_nyi_array_out (
    const char*     name,       /**< (I) */
    int             length,     /**< (I) */
    const void*     out         /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_integer_in (
    int     in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_double_in (
    double  in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_logical_in (
    logical in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_char_in (
    char    in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_string_in (
    const char*     in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_tag_in (
    tag_t   in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_date_in (
    date_t  in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_address_in (
    const void*     in      /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_integer_array_in (
    int         length,     /**< (I) */
    const int*  array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_long_long_array_in (
    int               length,     /**< (I) */
    const long long*  array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_double_array_in (
    int             length,     /**< (I) */
    const double*   array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_logical_array_in (
    int             length,     /**< (I) */
    const logical*  array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_char_array_in (
    int         length,     /**< (I) */
    const char* array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_string_array_in (
    int                  length,     /**< (I) */
    const char * const * array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_tag_array_in (
    int             length,     /**< (I) */
    const tag_t*    array       /**< (I) */
    );

/**
    Outputs the values of input arguments to a function.
*/
MLD_API void JOURNAL_date_array_in (
    int             length,     /**< (I) */
    const date_t*   array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_integer_out (
    const char* name,   /**< (I) */
    int         out     /**< (I) */
    );
/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_long_out (
    const char* name,   /**< (I) */
    long        out     /**< (I) */
    );
/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_long_long_out (
    const char* name,   /**< (I) */
    long long   out     /**< (I) */
    );


/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_double_out (
    const char* name,   /**< (I) */
    double      out     /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_logical_out (
    const char* name,   /**< (I) */
    logical     out     /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_char_out (
    const char* name,   /**< (I) */
    char        out     /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_string_out (
    const char*     name,   /**< (I) */
    const char*     out     /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_tag_out (
    const char* name,       /**< (I) */
    tag_t       out         /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_date_out (
    const char* name,       /**< (I) */
    date_t      out         /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_address_out (
    const char*     name,   /**< (I) */
    const void*     in      /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_integer_array_out (
    const char* name,       /**< (I) */
    int         length,     /**< (I) */
    const int*  array       /**< (I) */
    );
/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_long_array_out (
    const char* name,       /**< (I) */
    int         length,     /**< (I) */
    const long* array       /**< (I) */
    );
/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_long_long_array_out (
    const char*      name,       /**< (I) */
    int              length,     /**< (I) */
    const long long* array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_double_array_out (
    const char*     name,       /**< (I) */
    int             length,     /**< (I) */
    const double*   array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_logical_array_out (
    const char*     name,       /**< (I) */
    int             length,     /**< (I) */
    const logical*  array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_char_array_out (
    const char* name,       /**< (I) */
    int         length,     /**< (I) */
    const char* array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_string_array_out (
    const char *         name,       /**< (I) */
    int                  length,     /**< (I) */
    const char * const * array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_tag_array_out (
    const char*     name,       /**< (I) */
    int             length,     /**< (I) */
    const tag_t*    array       /**< (I) */
    );

/**
    Outputs names and values of the output arguments from a function.
*/
MLD_API void JOURNAL_date_array_out (
    const char*     name,       /**< (I) */
    int             length,     /**< (I) */
    const date_t*   array       /**< (I) */
    );

/**
    Flushes the journal.
*/
MLD_API void JOURNAL_flush (void);

MLD_API void JOURNAL_file_to_stream (
    int     nbytes,
    FILE*   stream
    );

/**
    DPAT was a performance analysis utility on an ancient machine.
    Basically it reported time spent in different parts of the call tree.
    Since the JOURNAL code knows how much time is spent in each journalled
    function it can collect and then report these statistics.
    Since the data collection has overheads it is not enabled by default.
    You can turn it on by setting TC_JOURNAL_DPAT (to anything)
    or by calling JOURNAL_set_dpat_on
    If it has been enabled then a report is written to the journal file
    when it is closed.
*/
MLD_API logical JOURNAL_set_dpat_on (
    logical  on_of_off    /**< (I) */
    );

/**
    Resets collected dpat data.
*/
MLD_API void JOURNAL_zero_dpat_data (void);

/**
  Returns true if dpat statistics are being collected.
    Otherwise return false.
*/
MLD_API logical JOURNAL_dpat_on_or_off (void);

/**
    Sends a report of the current dpat statistics to the given output stream.
    Does not clear the data (so you can send copies of the data to multiple files)
*/
MLD_API void JOURNAL_dpat_report (
    FILE*   stream      /**< (I) */
    );

/**
    Returns the current depth of the JOURNAL call stack
*/
MLD_API int JOURNAL_ask_call_depth (void);

/**
    Returns the number of SQL statements executed this session
*/
MLD_API int JOURNAL_ask_sql_count ( void );

/**
    Decreases the sql count by 1.
*/
MLD_API void JOURNAL_decrement_sql_count(void);

/**
    Increases the sql count by 1.
*/
MLD_API void JOURNAL_increment_sql_count(void);

/**
    Zeros out the sql count.
*/
MLD_API void JOURNAL_zero_sql_count(void);

/**
    Returns the total time spent in the database.
*/
MLD_API double JOURNAL_ask_sql_total_time (void);

/**
    Sets the time taken in the database, adds amount of time taken by current to existing count.
*/
MLD_API void JOURNAL_add_sql_total_time(double time_taken);

/**
    Zeros out the total sql time taken.
*/
MLD_API void JOURNAL_zero_sql_total_time (void);

/**
    Reports an error to the syslog if the current call depth
    is not the one supplied.
    This can be used in conjunction with JOURNAL_ask_call_depth to ensure that
    calls below this function have correctly balanced JOURNAL_routine_start/end calls
    Returns true on miss-match, false if correct.
*/
MLD_API logical JOURNAL_assert_call_depth (
    int    depth      /**< (I) */
    );

/**
    Returns information about the requested routine, captured by the journal
    system to date. All output pointers are optional - specify NULL if that
    value is not requred. Returns true if the routine is found, false otherwise.
*/
MLD_API logical JOURNAL_get_routine_stats(
    const char* routine_name,
    double* cpu_time,
    double* real_time,
    int* trip_count,
    int* call_count
    );


/** NEWPJL start */
MLD_API int JOURNAL_newpjl_get_method_id(const char* name);
MLD_API int JOURNAL_newpjl_enter(int id);
MLD_API void JOURNAL_newpjl_exit(int serial);
MLD_API void JOURNAL_newpjl_ip_request(const char* process, const char* requestName, const char* correlationId);
MLD_API void JOURNAL_newpjl_ip_response(int responseSize, int errCode, const char* correlationId);
MLD_API void JOURNAL_newpjl_start_correlation_id(const char* correlationId);
MLD_API void JOURNAL_newpjl_end_correlation_id(const char* correlationId);
MLD_API void JOURNAL_newpjl_record_stat(const char* name, const double value);
MLD_API void JOURNAL_newpjl_comment(const char* comment);
MLD_API int JOURNAL_newpjl_routine_start(int id);
/** NEWPJL end */

/** @} */

#ifdef __cplusplus
}
#endif
#include <mld/libmld_undef.h>

#endif

