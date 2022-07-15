/*==============================================================================
  Copyright (c) 2006,2007 UGS
  Unpublished - All Rights Reserved
  ==============================================================================*/

/**
   @file

   Import Export functions
*/

#ifndef GMS_H
#define GMS_H

#include <gms/libgms_exports.h>

/**
    @defgroup GMS Global Multi-Site
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
   This API finds modifed objects given a list of object tags.
   an object is considered as out-dated :
   If it is first time to export, no export record exists.
   If object is modified since last export.
*/
    extern GMS_API int GMS_identify_outdated_replica_objects  (
        int replicasite,               /* <I>   replica site id */
        int numOfInputObjects,         /* <I>   number of input objects to be checked for modification */
        tag_t* objList,                /* <I>   list of tags of input objects to be checked for modification */
        int* numberOfOutdatedObjects,  /* <O>   output number of tags for objects which are modified or created since last export */
        tag_t** statusObjects          /* <OF>  numberOfOutdatedObjects output list of tags for objects which are modified or created  last export */
        );

    extern GMS_API int GMS_synchronize_site (
        int  replicaSite,                /* <I> */
        int  numOfClasses,               /* <I> */
        char**  classNames,              /* <I> */
        int  numOfObjectHandles,         /* <I> */
        tag_t*  objectHandlesList,       /* <I> */
        int* numOfObjectsToExport,       /* <O> */
        tag_t** objectsToExport          /* <OF> numOfObjectsToExport */
        );


/**
   Exports objects to the briefcase.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TIE_no_sync_candidates if there are no synchronization candidates.
   <li>#GMS_nonbcz_export_modobjs_not_allowed if the non-Briefcase export operation does not support synchronization. Set the "modified_objects_only" option to false, and try to export again
   <li>#GMS_zero_target_sites if @p n_sites is 0.
   <li>#TIE_bulk_extract_invalid_sync_option if synchronization is not supported by the "Bulk Extract Briefcase Export" operation.
   <li>#TIE_bulk_extract_invalid_targetsite_option if the operation "Bulk Extract Briefcase Export" with a target site is not allowed. Remove the target site option.
   <li>#SA_not_a_system_administrator if the current user is not a system administrator
   <li>#PIE_transferoptionset_not_found if @p option_set_tag could not be found
   </ul>
*/
    extern GMS_API int GMS_export_objects_to_offline_package (
        const char *    reason,                 /**< (I) The Reason for export. This can be a null pointer.*/
        int             n_objects,              /**< (I) The number of objects to be exported.*/
        tag_t *         object_tags,            /**< (I) n_objects Objects to be exported.*/
        int             n_sites,                /**< (I) The number of sites to which objects are to be exported.*/
        tag_t *         sites,                  /**< (I) n_sites Sites to which objects are to be exported.*/
        tag_t           option_set_tag,         /**< (I) The object of type "TransferOptionSet".*/
        int             n_options,              /**< (I) The number of transfer options whose values need to different than in "TransferOptionSet".*/
        const char **   option_names,           /**< (I) n_options Options whose values need to different than in "TransferOptionSet".
                                                   <br/>Some of the valid values are:
                                                   <ul>
                                                   <li>opt_nx_ds           (true/false)</li>
                                                   <li>opt_rev_select      (latestRevisionOnly/allReleasedRevisionsOnly/ etc)</li>
                                                   <li>opt_entire_bom      (true/false)</li>
                                                   </ul>
                                                   <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
        const char **   option_values,          /**< (I) n_options Option values */
        int             n_session_options,      /**< (I) The number of session options */
        const char **   session_option_names,   /**< (I) n_session_options Session option names
                                                   <br/>Some of the valid values are:
                                                   <ul>
                                                   <li>modified_objects_only        (True/False)</li>
                                                   <li>continue_on_error            (True/False)</li>
                                                   <li>unmanaged                    (True/False)</li>
                                                   <li>offline                      (True/False)</li>
                                                   <li>transfer_site_ownership      (True/False)</li>
                                                   <li>objsForOwnXfer               (object tags)</li>
                                                   <li>offline_create_tcxml_dataset (True/False)</li>
                                                   </ul>
                                                   <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
        const char **   session_option_values,  /**< (I) n_session_options Session option values */
        tag_t *         briefcase_dataset_tag,  /**< (O) Tag of the dataset representing exported briefcase.*/
        char **         offline_file_name,      /**< (OF) File name of the exported briefcase.*/
        int  *          n_export_log_files,     /**< (O) The number of log files */
        char ***        export_log_files        /**< (OF) n_export_log_files Log files.*/
        );

    extern GMS_API int GMS_import_objects_from_offline_package (
        const char *    offline_file_name,      /* <I> */
        tag_t           option_set_tag,         /* <I> */
        int             n_options,              /* <I> */
        const char **   option_names,           /* <I> */
        const char **   option_values,          /* <I> */
        int             n_session_options,      /* <I> */
        const char **   session_option_names,   /* <I> */
        const char **   session_option_values,  /* <I> */
        char **         log_file_fmsticket,     /* <OF> */
        char **         error_file_fmsticket    /* <OF> */
        );

/**
   Imports objects from the Offline Package and retrieves the number of newly created objects as well as their tags.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TIE_bulk_load_not_test_env if the site is not configured as a "test environment". The "Bulk Load Briefcase Import" operations can only be run in "test environment"-configured sites.
   <li>#TIE_bulk_load_invalid_bcz if an invalid briefcase is provided to the "Bulk Load Briefcase Import" operation. It must have been generated by the "Bulk Extract Briefcase Export" operation.
   <li>#TIE_bc_export_import_req_multisite_license if no Multi-Site license (key: multisite_server) is available to export to, or import from, the offline site. Please obtain the license and try again.
   <li>#GMS_briefcase_type_import_not_allowed if the source site definition in the DB and in the briefcase creation type do not match. Therefore the briefcase import is not allowed.
   </ul>
*/
    extern GMS_API int GMS_import_objects_from_offline_package_with_new_objects (
        const char *    offline_file_name,      /**< (I) Offline file name */
        tag_t           option_set_tag,         /**< (I) Optionset tag */
        int             n_options,              /**< (I) Number of options */
        const char **   option_names,           /**< (I) Array of all the option set options names and values as indicated by the user */
        const char **   option_values,          /**< (I) Option names values */
        int             n_session_options,      /**< (I) Number of session options */
        const char **   session_option_names,   /**< (I) Array of all the session option names (options which are not part of the option set) and values as indicated by the user */
        const char **   session_option_values,  /**< (I) Session option values */
        char **         log_file_fmsticket,     /**< (OF) Log file fms ticket */
        char **         error_file_fmsticket,   /**< (OF) Error file fms ticket */
        int *           n_new_objects,          /**< (O) Number of newly created objects */
        tag_t **        new_objects             /**< (OF) n_new_objects Newly created objects */
        );

/**
    Imports objects from the Offline Package and retrieves the newly created and updated objects.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TIE_bulk_load_not_test_env if the site is not configured as a "test environment". The "Bulk Load Briefcase Import" operations can only be run in "test environment"-configured sites.
    <li>#TIE_bulk_load_invalid_bcz if an invalid @p offline_file_name is provided to the "Bulk Load Briefcase Import" operation. It must have been generated by the "Bulk Extract Briefcase Export" operation.
    <li>#TIE_bc_export_import_req_multisite_license if no Multi-Site license (key: multisite_server) is available to import from the offline site.
    <li>#GMS_briefcase_type_import_not_allowed if the source site definition in the DB and in the briefcase creation type do not match. Therefore the briefcase import is not allowed.
    <li>#BCASE_unable_to_open_container if the @p offline_file_name is invalid.
    <li>#PIE_transferoptionset_not_retrieved if the @p option_set is invalid.
    </ul>
*/
extern GMS_API int GMS_import_objects_from_offline_package_with_new_and_updated_objects (
        const char *        offline_file_name,      /**< (I) Offline file name */ 
        const tag_t            option_set,             /**< (I) Optionset tag */ 
        const unsigned int  n_options,                /**< (I) Number of options */ 
        const char **        option_names,           /**< (I) n_options Names of all the options in the option set */
        const char **        option_values,          /**< (I) n_options Values of all the options in the option set */
        const unsigned int  n_session_options,      /**< (I) Number of session options */ 
        const char **        session_option_names,   /**< (I) n_session_options Names of all the session options (options which are not part of the option set) */
        const char **        session_option_values,  /**< (I) n_session_options Values of all the session options */ 
        char **                log_file_fmsticket,     /**< (OF) Log file FMS ticket */ 
        char **                error_file_fmsticket,   /**< (OF) Error file FMS ticket */ 
        int *                n_new_objects,          /**< (O) Number of newly created objects */ 
        tag_t **            new_objects,            /**< (OF) n_new_objects Newly created objects */
        int *                n_updated_objects,      /**< (O) Number of updated objects */ 
        tag_t **            updated_objects         /**< (OF) n_updated_objects Updated objects */ 
        );


#ifdef __cplusplus
}
#endif

/**
   @}
*/

#include <gms/libgms_undef.h>

#endif

