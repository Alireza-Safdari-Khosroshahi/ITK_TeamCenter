/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
   @file

   GMS Errors
*/

#ifndef GMS_ERRORS_H
#define GMS_ERRORS_H

#include <common/emh_const.h>


/**
    @defgroup GMS_ERRORS Errors
    @ingroup GMS
    @{
*/

#define GMS_ERROR_BASE                                 EMH_GMS_error_base

#define GMS_invalid_input                              (EMH_GMS_error_base+1)


/**
    The specified object is locked for modification, Site ownership can not transfer on
    this object
*/
#define GMS_fail_to_xfer_ownership                     (EMH_GMS_error_base+2)

/**
    The specified object is locked for modification, can not set ownership transfer pending
    state on this object
*/
#define GMS_fail_to_set_ownership_xfer_pending_state   (EMH_GMS_error_base+3)

/**
    The specified object is not in ownership transfer pending state hence can not set new
    owning site on this object
*/
#define GMS_no_ownership_xfer_pending_state            (EMH_GMS_error_base+4)

/**
    Error while setting new owning site on specified object
*/
#define GMS_fail_to_set_new_owning_site                (EMH_GMS_error_base+5)

/**
    Error while logging to Global Services
*/
#define GMS_fail_to_login_to_global_services           (EMH_GMS_error_base+6)

/**
    Error while invoking Global Services Method
*/
#define GMS_fail_to_invoke_global_services_method      (EMH_GMS_error_base+7)


/**
    Error while encountering a null source site id
*/
#define GMS_invalid_source_site                        (EMH_GMS_error_base+30)

/**
    Error while encountering a null target site id
*/
#define GMS_invalid_target_site                        (EMH_GMS_error_base+31)

/**
    Error while encountering a invalid dataset name
*/
#define GMS_invalid_offline_dataset_name               (EMH_GMS_error_base+32)

/**
    Error while encountering a invalid dataset type
*/
#define GMS_invalid_offline_dataset_type               (EMH_GMS_error_base+33)

/**
    Error if there are Zero target sites
*/
#define GMS_zero_target_sites                          (EMH_GMS_error_base+34)

/**
    Error if root volume directory is NULL
*/
#define GMS_invalid_root_path                          (EMH_GMS_error_base+35)

/**
    The given "TC_APPLICATION" attribute value is not Offline GMS in the container
*/
#define GMS_invalid_briefcase_container                (EMH_GMS_error_base+36)

/**
    Unable to modify the metadata file of the given briefcase container
*/
#define GMS_unable_to_modify_metadata_files            (EMH_GMS_error_base+37)

/**
    The following required attributes are missing from the ImanFile element: %1$.
*/
#define GMS_invalid_offline_metadata_file              (EMH_GMS_error_base+38)

/**
    Error to prevent transfer of ownership if variable not set to true
*/
#define GMS_offline_cannot_transfer_ownership          (EMH_GMS_error_base+39)

/**
    Failed to transfer ownership since required object is in user specified exclude list
*/
#define GMS_fail_to_xfer_bcz_xclude_objs               (EMH_GMS_error_base+40)

/**
    Error invalid UID for GSID object
*/
#define GMS_invalid_uid                                (EMH_GMS_error_base+41)

/**
    GMS feature is not available
*/
#define GMS_gms_feature_not_available                  (EMH_GMS_error_base+42)

/**
    GMS invalid gsidentity tag
*/
#define GMS_invalid_gsidentity_tag                     (EMH_GMS_error_base+43)

/**
    GMS fail to create import record
*/
#define GMS_fail_to_create_import_record               (EMH_GMS_error_base+44)

/**
    Transaction ID for the Site Transfer operation is empty
*/
#define GMS_transaction_id_empty                       (EMH_GMS_error_base+45)

/**
    Site Transfer on the object with the remote site is in progress
*/
#define GMS_site_transfer_export_in_progress           (EMH_GMS_error_base+46)

/**
    Recovery is required for the Object
*/
#define GMS_recovery_required                          (EMH_GMS_error_base+47)

/**
    Site Transfer on the object succeded but failed to complete the cleanup action
*/
#define GMS_recovery_failed                            (EMH_GMS_error_base+48)

/**
    Failed to find the recovery dataset
*/
#define GMS_om_dataset_not_exists                      (EMH_GMS_error_base+49)

/**
    Found more than one recovery datasets
*/
#define GMS_om_dataset_too_many                        (EMH_GMS_error_base+50)

/**
    Transaction ID recorded on the dataset is out of sync
*/
#define GMS_om_transaction_out_of_sync                 (EMH_GMS_error_base+51)

/**
    The GSID object to process is invalid
*/
#define GMS_nothing_to_process                         (EMH_GMS_error_base+52)

/**
    FSC proxy error
*/
#define GMS_fsc_proxy_error                            (EMH_GMS_error_base+53)

/**
    More than one dataset versions exported in configured export to unmanaged site
*/
#define GMS_more_DS_vers_error                         (EMH_GMS_error_base+54)

/**
    The GRM relation for CAD dataset is missing in the XML file
*/
#define GMS_GRM_relation_error                         (EMH_GMS_error_base+55)

/**
    The Dataset type is not supported in configured export to unmanaged site
*/
#define GMS_DS_type_not_supported                      (EMH_GMS_error_base+56)

/**
    Source site defination in DB and briefcase creation type are not matching with each other,
    Therefore the briefcase import is not allowed.
 */
#define GMS_briefcase_type_import_not_allowed          (EMH_GMS_error_base+57)

 /**
    The number of values for the properties "%1$" (fnd0ImportSite), "%2$" (fnd0LastImportDate) and "%3$" (fnd0SourceUid) do not match. Please check the properties values passed to the create method for objects of type "%4$" (Fnd0AdminGSIdentity).
*/
#define GMS_admin_gsidentity_vla_size_mismatch         (EMH_GMS_error_base+58)

/**
    An empty label is not allowed for creating an object of type "%1$" (GSIdentity). Please check the value of property "%2$" (label) passed to the create method for objects of type "%1$" (GSIdentity).
*/
#define GMS_empty_label                                (EMH_GMS_error_base+59)

/**
   More than one Global Stable ID (GSID) instance was found with object_uid "%1$".
*/
#define GMS_more_gsid_found_by_object_uid              (EMH_GMS_error_base+60)

/**
   The non-Briefcase export operation does not support synchronization. Please set the "modified_objects_only" option to false, and try to export again.
*/
#define GMS_nonbcz_export_modobjs_not_allowed          (EMH_GMS_error_base+61)

/**
   The export operation has failed, because several files bear the same name: %1$. Please make the file names unique and re-try the "export" operation.
*/
#define GMS_duplicate_files                            (EMH_GMS_error_base+62)

/**
   The "export" operation has failed because the dataset file "%1$" could not be copied to the transient volume since its path would be too long. Please set the environment variable "TC_TMP_DIR" to a shorter path. The current value is: %2$.
*/
#define GMS_file_path_too_long                         (EMH_GMS_error_base+63)

/** @} */

#endif

