/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
/** @if HISTORY_SECTION
====================================================================================================
25-Dec-2010  Manish Dwivedi       Error codes for DebugMonitor
16-Sep-2010  Avani Kondragunta       Error codes for soacad
$HISTORY$
==================================================================================================
@endif */

#ifndef SOADEBUGMONITOR_ERRORS_H
#define SOADEBUGMONITOR_ERRORS_H

/**
    @file

    Errors for the soa debug monitor services


*/

#include <common/emh_const.h>

/**
    @defgroup SOADEBUGMONITOR_ERRORS SOA Debug Monitor Errors
    @ingroup SOADEBUGMONITOR
    @{
*/

/** DebugLogging Service (0 - 19) */
#define SOADEBUGMONITOR_invalid_checking_level            (EMH_SOADEBUGMONITOR_error_base +   0 )
#define SOADEBUGMONITOR_sql_logging                       (EMH_SOADEBUGMONITOR_error_base +   1 )
#define SOADEBUGMONITOR_logging_levels                    (EMH_SOADEBUGMONITOR_error_base +   2 )
#define SOADEBUGMONITOR_module_status                     (EMH_SOADEBUGMONITOR_error_base +   3 )
#define SOADEBUGMONITOR_invalid_module_list               (EMH_SOADEBUGMONITOR_error_base +   4 )
#define SOADEBUGMONITOR_invalid_logging_level             (EMH_SOADEBUGMONITOR_error_base +   5 )
#define SOADEBUGMONITOR_unabletoget_lock                  (EMH_SOADEBUGMONITOR_error_base +   6 )
#define SOADEBUGMONITOR_invalid_tao_level                 (EMH_SOADEBUGMONITOR_error_base +   7 )
#define SOADEBUGMONITOR_invalid_root_logging_level        (EMH_SOADEBUGMONITOR_error_base +   8 )
#define SOADEBUGMONITOR_unsupported_tao_level_5           (EMH_SOADEBUGMONITOR_error_base +   9 )
#define SOADEBUGMONITOR_invalid_performance_journal_level (EMH_SOADEBUGMONITOR_error_base +  10 )
#define SOADEBUGMONITOR_cannot_change_performance_journal_level (EMH_SOADEBUGMONITOR_error_base +  11 )

/** DebugMonitor Service (20 - 49) */
#define SOADEBUGMONITOR_configuration_reload_error        (EMH_SOADEBUGMONITOR_error_base +   20 )
#define SOADEBUGMONITOR_metric_configuration_set_error    (EMH_SOADEBUGMONITOR_error_base +   21 )

/** PerformanceMonitor Service (50 - 69) */
#define SOADEBUGMONITOR_profiling_couldnot_be_started     (EMH_SOADEBUGMONITOR_error_base +   50 )
#define SOADEBUGMONITOR_invalid_mode                      (EMH_SOADEBUGMONITOR_error_base +   51 )

/** User message: %1$. The property %2$ for the object %3$ contains an expected value of %4$, but its actual value is %5$. */
#define SOADEBUGMONITOR_different_prop_value              (EMH_SOADEBUGMONITOR_error_base +   52 )

/** The test is not able to restore the database, because no mark point was set. */
#define SOADEBUGMONITOR_markpoint_not_set                 (EMH_SOADEBUGMONITOR_error_base +   53 )

/** Reactive Logging invalid variable entries. (70 - 78) */
#define SOADEBUGMONITOR_invalid_journal_value               (EMH_SOADEBUGMONITOR_error_base +   70 )
#define SOADEBUGMONITORinvalid_journalperformanceonly_value (EMH_SOADEBUGMONITOR_error_base +   71 )
#define SOADEBUGMONITOR_invalid_journalmodules_value        (EMH_SOADEBUGMONITOR_error_base +   72 )
#define SOADEBUGMONITOR_invalid_performance_logging         (EMH_SOADEBUGMONITOR_error_base +   73 )

/** The file "%1$" cannot be read nor written. */
#define SOADEBUGMONITOR_cannot_open_file                    (EMH_SOADEBUGMONITOR_error_base +   74 )

/** No email ID is specified in the preference "TC_reactive_logging_notification_list" to enable sending notifications. */
#define SOADEBUGMONITOR_mail_notification_pref_val_undefined (EMH_SOADEBUGMONITOR_error_base +   75 )

/** No FMS ticket can be created to download the files. */
#define SOADEBUGMONITOR_fmsticket_create_failed             (EMH_SOADEBUGMONITOR_error_base +   76 )

/** The input argument is either null or empty. */
#define SOADEBUGMONITOR_input_value_is_null                 (EMH_SOADEBUGMONITOR_error_base +   77 )

/** The log files could not be zipped due to an unknown error. Check the Teamcenter syslog for more information. */
#define SOADEBUGMONITOR_unable_to_zip_files                 (EMH_SOADEBUGMONITOR_error_base +   78 )

/** @} */

#endif

