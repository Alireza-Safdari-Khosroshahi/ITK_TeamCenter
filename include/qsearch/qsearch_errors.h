#ifndef QSEARCH_ERRORS_H
#define QSEARCH_ERRORS_H

/* Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    QSearch errors

*/


#include <common/emh_const.h>
#include <qsearch/libqsearch_exports.h>

/**
    @defgroup QSEARCH_ERRORS CONFIG Errors
    @ingroup QSEARCH
    @{
*/

/**
 * An internal error has occurred in the qsearch module: %1$. Please report this to your system administrator.
 */
#define QSEARCH_internal_error                          (EMH_QSEARCH_error_base +   1)

/**
 * The qsearch index update is disabled. This is controlled by the "QSEARCH_update_enabled" preference. Please report this to your system administrator.
 */
#define QSEARCH_update_disabled                         (EMH_QSEARCH_error_base +   2)

/**
 * The qsearch index update has reached the processing-time limit of %1$ seconds. This is controlled by the "QSEARCH_foreground_processing_time" preference. Please report this to your system administrator.
 */
#define QSEARCH_update_took_too_long                    (EMH_QSEARCH_error_base +   3)

/**
 * The qsearch index update cannot process objects of the "%1$" class. Please report this to your system administrator.
 */
#define QSEARCH_cannot_process_object_of_class          (EMH_QSEARCH_error_base +   4)

/**
 * The qsearch index update has reached the recursion limit of %1$. This is controlled by the "QSEARCH_processing_recursion_limit" preference. Please report this to your system administrator.
 */
#define QSEARCH_update_hit_recursion_limit              (EMH_QSEARCH_error_base +   5)

/**
 * The following qsearch feature is not implemented: %1$. Please report this to your system administrator.
 */
#define QSEARCH_feature_not_implemented                 (EMH_QSEARCH_error_base +   6)

/**
 * The foreground qsearch index update is disabled. This is controlled by the "QSEARCH_foreground_processing_halted" preference. Please report this to your system administrator.
 */
#define QSEARCH_foreground_update_disabled              (EMH_QSEARCH_error_base +   7)

/**
 * The index boxes are not available for the Item of ID "%1$".
 */
#define QSEARCH_no_index_boxes                          (EMH_QSEARCH_error_base +   8)

/**
 * The query "%1$" failed to execute.
 */
#define QSEARCH_query_failed                            (EMH_QSEARCH_error_base +   9)

/**
 * The query "%1$" was interrupted, because it exceeded the maximum time allowed for execution as defined in the preference "QS_MAX_QUERY_EXECUTION_TIME_FOR_BOTTOMUP".
 */
#define QSEARCH_query_interrupted                       (EMH_QSEARCH_error_base +  10)

/**
 * The search algorithm was switched to top-down because bottom-up search hit too many intermediate structure nodes.
 */
#define QSEARCH_max_allowd_ChunkStackSize_lapsed        (EMH_QSEARCH_error_base +  11)

/**
 * No Context Management license can be found. Please contact your system administrator.
 */
#define QSEARCH_no_licence_available                    (EMH_QSEARCH_error_base +  12)

/**
 * The remote qsearch does not support the version "%1$" of encoding.
 */
#define QSEARCH_remote_search_version_not_supported     (EMH_QSEARCH_error_base +  13)

/**
 * The remote qsearch was not supplied with an encoding version number. Please supply it.
 */
#define QSEARCH_remote_search_version_not_supplied      (EMH_QSEARCH_error_base +  14)

/**
 * The remote qsearch was supplied with too few strings: %1$.
 */
#define QSEARCH_remote_search_too_few_strings_supplied  (EMH_QSEARCH_error_base +  15)

/**
 * The remote qsearch has returned too few strings: %1$.
 */
#define QSEARCH_remote_search_returned_too_few_strings  (EMH_QSEARCH_error_base +  16)

/**
 * The remote qsearch could not configure the specified target part in the product context.
 */
#define QSEARCH_remote_target_part_not_configured       (EMH_QSEARCH_error_base +  17)

/**
 * The remote qsearch could not find the product "%1$" at the remote master site specified in the preference "QS_remote_master_site".
 */
#define QSEARCH_remote_product_not_found                (EMH_QSEARCH_error_base +  18)

/**
 * The remote qsearch could not find the variant rule "%1$" at the remote master site specified in the preference "QS_remote_master_site".
 */
#define QSEARCH_remote_varrule_not_found                (EMH_QSEARCH_error_base +  19)

/**
 * The remote qsearch could not find the saved query "%1$" at the remote master site specified in the preference "QS_remote_master_site".
 */
#define QSEARCH_remote_saved_qry_not_found              (EMH_QSEARCH_error_base +  20)

/**
 * The remote qsearch could not find the revision rule "%1$" at the remote master site specified in the preference "QS_remote_master_site".
 */
#define QSEARCH_remote_revrule_not_found                (EMH_QSEARCH_error_base +  21)

/**
 * The selected target lines do not contain bounding box information.
 */
#define QSEARCH_no_bounding_box_on_target_lines         (EMH_QSEARCH_error_base +  22)

/**
 * Either no user exit is defined, or no customization exists.
 */
#define QSEARCH_no_bmf_user_exit_or_customization       (EMH_QSEARCH_error_base +  23)

/**
 * The input is invalid: %1$.
 */
#define QSEARCH_invalid_input                           (EMH_QSEARCH_error_base +  24)

/**
 * This index update was prevented by another running update process.
 */
#define QSEARCH_index_update_blocked                    (EMH_QSEARCH_error_base +  25)

/**
 * This index update was interrupted by another running update process. Your changes will be indexed by this other process.
 */
#define QSEARCH_index_update_interrupted                (EMH_QSEARCH_error_base +  26)

 /**
  * Unable to perform SOLR search.
  */
#define QSEARCH_unable_to_perform_solr_search           (EMH_QSEARCH_error_base +  27)

/**
* Callback %1$ is not registered. Failed to perform search.
*/
#define QSEARCH_unable_to_find_callback                (EMH_QSEARCH_error_base +  28)

/** @} */

#include <qsearch/libqsearch_undef.h>
#endif

