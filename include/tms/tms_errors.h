/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Errors for TCXML multisite functionality

====================================================================================================
   Date      Name                    Description of Change
25-Jun-2012  palkarg                 Initial Version
$HISTORY$
==================================================================================================*/

#ifndef TIE_MULTISITE_ERRORS_H
#define TIE_MULTISITE_ERRORS_H

#include <common/emh_const.h>

/**The bulk "Iman Export Record" (IXR) creation or update has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_bulk_IXR_creation_updation_failed                        (EMH_TIE_MULTISITE_error_base + 1  )

/**The "Export Commit" process has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_Export_commit_failed                                     (EMH_TIE_MULTISITE_error_base + 2  )

/**The processing callback function is not set for the TC XML based multisite operation. Please refer to the log files for details and contact your system administrator.*/
#define TIE_MS_callback_function_not_set                                (EMH_TIE_MULTISITE_error_base + 3  )

/**The "Export Record" could not be created during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_IXR_create_failed                                        (EMH_TIE_MULTISITE_error_base + 4  )

/**The "Export Record" could not be created during the TC XML based multisite operation due to an invalid value for the attribute "<attribute>"*/
#define TIE_MS_IXR_invalid_attribute                                    (EMH_TIE_MULTISITE_error_base + 5  )

/**An invalid transaction ID "%1$" was specified during the TC XML based multisite operation. Its length should be equal or less than 15 characters.*/
#define TIE_MS_invalid_transaction_id                                   (EMH_TIE_MULTISITE_error_base + 6  )

/**The database transaction has been aborted during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_transaction_aborted                                      (EMH_TIE_MULTISITE_error_base + 7  )

/**The database query has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_query_failed                                             (EMH_TIE_MULTISITE_error_base + 8  )

/**The update of the database table ROOT_OBJS_IN_TRANS_TABLE has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_rootobjs_in_transaction_id_failed                        (EMH_TIE_MULTISITE_error_base + 9  )

/**An unsupported database has been encountered during the TC XML based multisite operation. Please refer to the log files for details, and contact your system administrator.*/
#define TIE_MS_unsupported_database                                     (EMH_TIE_MULTISITE_error_base + 10  )

/**The insertion of the principal objects in the database table TRANSACTION_TABLE has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_principal_objs_in_transaction_id_failed                  (EMH_TIE_MULTISITE_error_base + 11  )

/**The update of the database table EXP_OBJ_TABLE has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_updating_export_object_table_failed                      (EMH_TIE_MULTISITE_error_base + 12  )

/**The update of the database table EXPORT_TO_SITE_TABLE has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_updating_export_site_table_failed                        (EMH_TIE_MULTISITE_error_base + 13  )

/**The update of the database table SUBSCRIPTION_TABLE has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_updating_subscription_table_failed                       (EMH_TIE_MULTISITE_error_base + 14  )

/**The update of the fast-synchronization related tables has failed during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_fast_sync_table_updation_failed                          (EMH_TIE_MULTISITE_error_base + 15  )

/**The transaction ID "%1$" could not be found during the TC XML based operation.*/
#define TIE_MS_no_transaction_id_found                                  (EMH_TIE_MULTISITE_error_base + 16  )

/**The transaction ID "%1$" already exists in the database.*/
#define TIE_MS_transaction_id_exists                                    (EMH_TIE_MULTISITE_error_base + 17  )

/**No principal object for the transaction ID "%1$" could be found during the TC XML based operation.*/
#define TIE_MS_no_principal_objs_for_transaction_found                  (EMH_TIE_MULTISITE_error_base + 18  )

/**The retrieval of the added dirty islands has failed for the transaction ID "%1$" during the TC XML based operation.*/
#define TIE_MS_retrieving_add_dirty_island_failed                       (EMH_TIE_MULTISITE_error_base + 19  )

/**The retrieval of the deleted dirty islands has failed for the transaction ID "%1$" during the TC XML based operation.*/
#define TIE_MS_retrieving_delete_dirty_island_failed                    (EMH_TIE_MULTISITE_error_base + 20  )

/**The retrieval of the modified dirty islands has failed for the transaction ID "%1$" during the TC XML based operation.*/
#define TIE_MS_retrieving_modify_dirty_island_failed                    (EMH_TIE_MULTISITE_error_base + 21  )

/**An error has been encountered during the retrieval of the fast synchronization candidates for the transaction ID "%1$" during the TC XML based operation. Please refer to the log files for more details.*/
#define TIE_MS_retrieving_fast_sync_candidates_failed                   (EMH_TIE_MULTISITE_error_base + 22  )

/**An error has been encountered during the access of the volume during the TC XML based operation. Please refer to the log files for more details. */
#define TIE_MS_volume_access_error                                      (EMH_TIE_MULTISITE_error_base + 23  )

/**An invalid input data "%1$" was found while updating the fast synchronization tables during the TC XML based operation. Please refer to the log files for details.*/
#define TIE_MS_invalid_input_data                                       (EMH_TIE_MULTISITE_error_base + 24  )

/**The save of "Iman Export Record" (IXR) has encountered partial errors during the TC XML based multisite operation. Please refer to the log files for details.*/
#define TIE_MS_IXR_bulk_save_partial_error                              (EMH_TIE_MULTISITE_error_base + 25 )

/**The conversion of the input parameters of the utility "%1$" to its representative Option Set has failed.*/
#define TIE_MS_cms_tie_option_convert_error                             (EMH_TIE_MULTISITE_error_base + 26 )

/**The input time is invalid, because it violates the expected time format "%1$".*/
#define TIE_MS_Invalid_LPD                                              (EMH_TIE_MULTISITE_error_base + 27 )

/**A callback message is received, but no corresponding storage is defined */
#define TIE_MS_callback_no_storage_defined                              (EMH_TIE_MULTISITE_error_base + 28 )

/**The import-side "Transfer Option Set" (TOS) "%1$" corresponding to the export-side TOS "%2$" is either defined empty or the defined value is not present in the database. Please check the preference "%3$".*/
#define TIE_MS_import_optset_not_found                                  (EMH_TIE_MULTISITE_error_base + 29 )

/**The post-action specified in the transfer mode "%1$" has failed. Please refer to the log files for details.*/
#define TIE_MS_Post_Action_Failed                                       (EMH_TIE_MULTISITE_error_base + 30 )

/**The parallel processing has failed because of an empty transaction value. Please refer to the log files for details.*/
#define TMS_GRID_transaction_id_empty                                   (EMH_TIE_MULTISITE_error_base + 31 )

/**The deletion of a sub-staging directory deletion has failed during parallel processing. Please refer to the log files for details.*/
#define TMS_GRID_sub_staging_dir_deletion_failed                        (EMH_TIE_MULTISITE_error_base + 32 )

/**The parallel processing has failed because no target site is provided. Please refer to the log files for details.*/
#define TMS_GRID_target_site_not_provided                               (EMH_TIE_MULTISITE_error_base + 33 )

/**A child importer process has received failures during parallel processing. Please refer to the log files for details.*/
#define TMS_GRID_child_importers_encountered_failures                   (EMH_TIE_MULTISITE_error_base + 34 )

/**The preparation for parallel processing has failed. Please refer to the log files for details.*/
#define TMS_GRID_prepare_process_failed                                 (EMH_TIE_MULTISITE_error_base + 35 )

/**The parallel export iteration has failed. Please refer to the log files for details.*/
#define TMS_GRID_iterative_export_failed                                (EMH_TIE_MULTISITE_error_base + 36 )

/**The creation of a sub-staging directory has failed during a sub-exporter processing. Please refer to the log files for details.*/
#define TMS_GRID_child_erporing_staging_directory_creation_failed       (EMH_TIE_MULTISITE_error_base + 37 )

/**Parallel Multi-Site processing does not currently support "Ownership Transfer".*/
#define TMS_GRID_Ownership_transfer_not_supported                       (EMH_TIE_MULTISITE_error_base + 38 )

/**The state of the parallel sub-export iteration has failed to correctly be updated. Please refer to the log files for details.*/
#define TMS_GRID_child_export_iteration_state_not_updated_correctly     (EMH_TIE_MULTISITE_error_base + 39 )

/**The cross-island principal object is the same as one of the top-level input objects. Please refer to the log files for details.*/
#define TMS_GRID_cross_principal_found_same_as_root                     (EMH_TIE_MULTISITE_error_base + 40 )

/**The main exporter process could not notify the successful transfer of a payload file to the target site. Please refer to the log files for details.*/
#define TMS_GRID_payload_completion_notification_had_failure            (EMH_TIE_MULTISITE_error_base + 41 )

/**The sub-exporter process "%1$" has encountered a failure during the creation of a payload file. Please refer to the log files for details.*/
#define TMS_GRID_serialization_exception                                (EMH_TIE_MULTISITE_error_base + 42 )

/**The communication between parent and child processes has failed. Please refer to the log files for details.*/
#define TMS_GRID_child_parent_communucator_encountered_error            (EMH_TIE_MULTISITE_error_base + 43 )

/**The parallel sub-export iteration has failed. Please refer to the log files for details.*/
#define TMS_GRID_child_exporter_iteration_failed                        (EMH_TIE_MULTISITE_error_base + 44 )

/** The value "%1$" provided for the parallelization is invalid. Please use "-h" for help or refer to utility documentation for details.*/
#define TMS_GRID_parameter_incorrect                                    (EMH_TIE_MULTISITE_error_base + 45 )

/** Some dependent objects of migrating objects have not been migrated. Please refer to the importer log files for details.*/
#define TMS_MS_GO_migration_dependent_obj_not_migrated                  (EMH_TIE_MULTISITE_error_base + 46 )

/** Some migrating administrative objects do not exist at the remote site. Please refer to the importer log files for details.*/
#define TMS_MS_GO_migration_missing_obj_in_db                           (EMH_TIE_MULTISITE_error_base + 47 )

/** Some dependencies of the migrating administrative objects found at the remote site do not exist in the XML file. Please refer to the importer log files for details.*/
#define TMS_MS_GO_migration_dependent_obj_in_db_missing_in_xml          (EMH_TIE_MULTISITE_error_base + 48 )

/** Some dependencies of the migrating administrative objects in the XML file do not exist as dependent objects of these migrating objects at the remote site. Please refer to the importer log files for details.*/
#define TMS_MS_GO_migration_dependent_obj_extra_in_xml                  (EMH_TIE_MULTISITE_error_base + 49 )

/** Some dependencies of migrating administrative objects in the XML file exist at the remote site but not as dependent objects of the migrating objects. Please refer to the importer log files for details.*/
#define TMS_MS_GO_migration_dependent_obj_not_match                     (EMH_TIE_MULTISITE_error_base + 50 )

/** Some importing administrative objects exist at the remote site but have not been migrated. Please refer to the importer log files for details.*/
#define TMS_MS_GO_obj_existing_but_not_migrated                         (EMH_TIE_MULTISITE_error_base + 51 )

/** An error occurred during traversal of principal object "%1$". This usually occurrs when data being replicated us also undergoing modifications at the same time. Please redo the operation for the failed object.*/
#define TMS_MS_object_got_wip_error_during_traveral                      (EMH_TIE_MULTISITE_error_base + 52 )

/** Island ID "%1$" encountered error during traversal.*/
#define TMS_MS_island_got_wip_error_during_traveral                      (EMH_TIE_MULTISITE_error_base + 53 )


/** An error occurred during serialization while processing principal object "%1$". This usually occurrs when data being replicated us also undergoing modifications at the same time. Please redo the operation for the failed object.*/
#define TMS_MS_object_got_wip_error_during_serialization                 (EMH_TIE_MULTISITE_error_base + 54 )

/** Island ID "%1$" encountered error during serialization.*/
#define TMS_MS_island_got_wip_error_during_serialization                 (EMH_TIE_MULTISITE_error_base + 55 )

/** No cached BOM information can be found for synchronizing the input configured BOM. Please do initial export with the same configuration first.*/
#define TMS_cached_bom_sync_no_initial_export_info                       (EMH_TIE_MULTISITE_error_base + 56 )

/** Master site has ProjectObjectRelation(POR) objects with Propagation Group as "No Group". Migrate the "No Group" PORs using migrate_propagation_data utility. Please refer documentation for more information. */
#define TMS_MS_island_got_no_group_propagation_error                     (EMH_TIE_MULTISITE_error_base + 57 )

#endif