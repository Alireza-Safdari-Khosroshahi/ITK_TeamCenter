/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**

@file

Errors for the TCXML based Multisite operation.

====================================================================================================

Date Name Description of Change

23-Jul-2012     marothiy                Initial Version

$HISTORY$

==================================================================================================*/



#ifndef MS_TIE_ERRORS_H
#define MS_TIE_ERRORS_H

/** When/if the "DIST_" ITK is released to the customer, we'll need to include without module */
#include <common/emh_const.h>

/** Multisite TIE export failed at the pre-processing stage. */
#define MS_TIE_export_preprocessing_failed                              (EMH_MULTISITE_TIE_error_base + 1  )

/** Invalid argument encountered while TIE mode processing during multisite operation. */
#define MS_TIE_invalid_argument                                         (EMH_MULTISITE_TIE_error_base + 2  )

/** Object [&quot;%1$&quot;] is not supported for the OBJIO mode processing, only usage with -fast_export flag is supported. */
#define MS_TIE_non_objio_object                                         (EMH_MULTISITE_TIE_error_base + 3  )

/** Multisite TIE export failed at the perform export stage. */
#define MS_TIE_export_failed                                            (EMH_MULTISITE_TIE_error_base + 4  )

/** Multisite TIE export failed at the processing export results stage. */
#define MS_TIE_processing_export_results_failed                         (EMH_MULTISITE_TIE_error_base + 5  )

/** Multisite TIE bulk IXR creation or updation failed. */
#define MS_TIE_bulk_IXR_creation_updation_failed                        (EMH_MULTISITE_TIE_error_base + 6  )

/** Multisite TIE bulk IXR commit process failed. */
#define MS_TIE_IXR_commit_failed                                        (EMH_MULTISITE_TIE_error_base + 7  )

/** Multisite TIE export failed at post processing stage. */
#define MS_TIE_export_post_processing_failed                            (EMH_MULTISITE_TIE_error_base + 8  )

/** Multisite TIE commit import failed. */
#define MS_TIE_commit_export_failed                                     (EMH_MULTISITE_TIE_error_base + 9  )

/** Multisite TIE import failed at pre-processing stage. */
#define MS_TIE_import_pre_processing_failed                             (EMH_MULTISITE_TIE_error_base + 10 )

/** Multisite TIE import process failed. */
#define MS_TIE_import_process_failed                                    (EMH_MULTISITE_TIE_error_base + 11 )

/** Multisite TIE import process failed for island [&quot;%1$&quot;]. */
#define MS_TIE_import_process_failed_for_island                         (EMH_MULTISITE_TIE_error_base + 12 )

/** Multisite TIE processing import results while processing the log [&quot;%1$&quot;]. */
#define MS_TIE_processing_import_results_failed                         (EMH_MULTISITE_TIE_error_base + 13 )

/**Multisite TIE commit import failed.*/
#define MS_TIE_commit_import_failed                                     (EMH_MULTISITE_TIE_error_base + 14 )

/** Multisite TIE import failed at post processing stage. */
#define MS_TIE_import_post_processing_failed                            (EMH_MULTISITE_TIE_error_base + 15 )

/** Multisite TIE callback processing could not find the context for key[&quot;%1$&quot;]. */
#define MS_TIE_context_dir_not_stored                                   (EMH_MULTISITE_TIE_error_base + 16 )

/** Staging directory [&quot;%1$&quot;] for the given context [&quot;%2$&quot;] could not be found. */
#define MS_TIE_no_idsm_staging_dir_found                                (EMH_MULTISITE_TIE_error_base + 17 )

/** Multisite TIE IDSM server process import failed. */
#define MS_TIE_server_push_import_failed                                (EMH_MULTISITE_TIE_error_base + 18 )

/** Multisite TIE client request polling failed. */
#define MS_TIE_client_polling_failed                                    (EMH_MULTISITE_TIE_error_base + 19 )

/** Multisite TIE callback function is not set. */
#define MS_TIE_callback_function_not_set                                (EMH_MULTISITE_TIE_error_base + 20 )

/** Source site cannot be null. */
#define MS_TIE_null_source_site                                         (EMH_MULTISITE_TIE_error_base + 21 )

/** Multisite TIE import failure reported at the site [&quot;%1$&quot;]. */
#define MS_TIE_import_failure_at_site                                   (EMH_MULTISITE_TIE_error_base + 22 )

/** Multisite TIE import failures reported by some remote sites, please find details in the syslog. */
#define MS_TIE_import_failures_reported                                 (EMH_MULTISITE_TIE_error_base + 23 )

/** The object class &quot;%1$&quot; is not a supported 4th Generation Designer (4GD) class. Please check the &quot;4GD Multi-Site Support&quot; chapter of the technical documentation for a list of such supported classes. */
#define MS_TIE_4GD_unsupported_class                                    (EMH_MULTISITE_TIE_error_base + 24 )

/** The following relations are not present in the preference &quot;%2$&quot;: %1$. For each of these relations, the following steps are needed to correct the situation:
    1. Add the relation name and its option to the preference &quot;TC_cms_relation_optset_map&quot; (e.g. &quot;IMAN_reference,opt_reference_rel&quot;).
    2. Set the relation's option to true in the Multi-Site default option set using the PLM XML/TC XML Export Import Administration application in the rich client (e.g. for IMAN_reference, set &quot;opt_reference_rel&quot; to true).
    3. Add the closure rule in the Multi-Site default closure rule using the same rich client application (e.g. CLASS:WorkspaceObject:CLASS:WorkspaceObject:RELATIONP2S:IMAN_reference:SKIP:$opt_reference_rel==&quot;false&quot;).*/
#define MS_TIE_relations_not_present_in_map                             (EMH_MULTISITE_TIE_error_base + 25 )

/** An error has been encountered while reading the Synchronous Site Transfer (SST) file at the import site. Please refer to the server/IDSM logs for details. */
#define MS_TIE_read_sst_file_error_on_import                            (EMH_MULTISITE_TIE_error_base + 26 )

/** TC XML based processing has reported that no objects were processed during the "Import" operation. Please refer to the server/IDSM logs for details. */
#define MS_TIE_reports_no_processed_objects                             (EMH_MULTISITE_TIE_error_base + 27 )

/** The "Synchronous Site Transfer (SST)" operation has failed during the TC XML based multisite operation. Please ask the administrator to run the utility 'ensure_site_consistency' at the exporting site, and refer to the server/IDSM logs for details. */
#define MS_TIE_sst_transaction_fail                                     (EMH_MULTISITE_TIE_error_base + 28 )

/** The TC XML based Multi-Site import operation has failed. Please refer to the import server logs for details.*/
#define MS_TIE_client_pull_import_failed                                (EMH_MULTISITE_TIE_error_base + 29 )

/** The TC XML based Multi-Site import operation has failed to retrieve the data from the remote IDSM server. Please refer to the server/IDSM logs for details.*/
#define MS_TIE_retrieve_data_from_remote_site_failed                    (EMH_MULTISITE_TIE_error_base + 30 )

/** The root object has successfully been imported, but some or all of the distributed islands have failed to be imported. Please refer to the import server logs for details.*/
#define MS_TIE_unable_to_import_distributed_islands                     (EMH_MULTISITE_TIE_error_base + 31 )

/** Remote Check-Out operations are not supported for TC XML based Multi-Site processing.*/
#define MS_TIE_invalid_operation                                        (EMH_MULTISITE_TIE_error_base + 32 )


#endif
