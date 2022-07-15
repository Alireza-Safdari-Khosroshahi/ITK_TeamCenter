/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    OBJIO ITK error codes
*/

/*  */

#ifndef OBJIO_ERRORS_H
#define OBJIO_ERRORS_H

#include <common/emh_const.h>
#include <archive/libarchive_exports.h>

/**
    @defgroup OBJIO_ERRORS Errors
    @ingroup OBJIO
    @{
*/

#define OBJIO_ERROR_BASE                         EMH_OBJIO_error_base

/** Type not yet supported */
#define OBJIO_unsupported_type                   (OBJIO_ERROR_BASE + 1)

/** Wrong type for this operation */
#define OBJIO_wrong_type                         (OBJIO_ERROR_BASE + 2)

/** Directory not a valid import/export directory */
#define OBJIO_invalid_dir_contents               (OBJIO_ERROR_BASE + 3)

/** Invalid attribute_flag */
#define OBJIO_invalid_attribute_flag             (OBJIO_ERROR_BASE + 4)

/** Something OO occurred */
#define OBJIO_internal_error                     (OBJIO_ERROR_BASE + 5)

/** Tag is not a BIER */
#define OBJIO_invalid_tag                        (OBJIO_ERROR_BASE + 6)

/** Tag is not a site */
#define OBJIO_invalid_site                       (OBJIO_ERROR_BASE + 7)

/** Attempt to re-use an existing import/export directory for export */
#define OBJIO_cannot_reuse_dir                   (OBJIO_ERROR_BASE + 8)

/** Attempt to use a non-existent directory for import */
#define OBJIO_dir_not_found                      (OBJIO_ERROR_BASE + 9)

#define OBJIO_unable_to_import                   (OBJIO_ERROR_BASE + 10)
#define OBJIO_unable_to_export                   (OBJIO_ERROR_BASE + 11)

#define OBJIO_export_remote_failure              (OBJIO_ERROR_BASE + 12)

#define OBJIO_async_multiple_objects             (OBJIO_ERROR_BASE + 13)
#define OBJIO_async_in_progress                  (OBJIO_ERROR_BASE + 14)
#define OBJIO_async_start_failed                 (OBJIO_ERROR_BASE + 15)
#define OBJIO_unable_to_produce_report           (OBJIO_ERROR_BASE + 16)
#define OBJIO_invalid_sync_option                (OBJIO_ERROR_BASE + 17)
#define OBJIO_unable_to_import_distrib_comp      (OBJIO_ERROR_BASE + 18)
#define OBJIO_sst_unable_reassert_remote_ownership      (OBJIO_ERROR_BASE + 19)
#define OBJIO_sst_unable_to_delete_remote_aux_objects   (OBJIO_ERROR_BASE + 20)
#define OBJIO_sst_did_not_claim_ownership               (OBJIO_ERROR_BASE + 21)
#define OBJIO_background_export_dir_no_access           (OBJIO_ERROR_BASE + 22)

/**
    The system cannot determine if the Variant Expression with a UID of "%1$" has been modified since the last export.
*/
#define OBJIO_unable_to_sync                            (OBJIO_ERROR_BASE + 23)

/**
    The operation has failed because it tried to create a stub object of class "%1$" and UID "%2$". Include this object during import/export operation to avoid this error.
*/
#define OBJIO_object_cannot_be_stubbed                  (OBJIO_ERROR_BASE + 24)

/** The following dependent objects have mixed ownership of local and replica objects: %1$. */ 
#define OBJIO_mixed_ownership                           (OBJIO_ERROR_BASE + 25)

/** The following objects are part of a workflow at the site "%1$": %2$. */ 
#define OBJIO_is_part_of_workflow                       (OBJIO_ERROR_BASE + 26)

/** The following dependent objects are checked-out at the site "%1$": %2$. */ 
#define OBJIO_is_checked_out                            (OBJIO_ERROR_BASE + 27)

/** The current user does not have sufficient privileges to perform this operation. */
#define OBJIO_insufficient_privileges                   (OBJIO_ERROR_BASE + 28)

/** A local object has been provided instead of a remote object. */
#define OBJIO_invalid_object_type                       (OBJIO_ERROR_BASE + 29)

/** The Form object "%1$" cannot be deleted, because it is referenced by a "Master" relation. */
#define OBJIO_ref_iman_master_form                      (OBJIO_ERROR_BASE + 30)

/** The supplied number of dependent objects (%1$) is fewer than the internal evaluation count (%2$). */
#define OBJIO_few_dependent_object_count                (OBJIO_ERROR_BASE + 31)

/** The status of the objects cannot be "%1$" since the current site itself is an archive site. */
#define OBJIO_invalid_archive_site                      (OBJIO_ERROR_BASE + 32)

/** The  "%1$" option is not allowed for replica deletion of 4GD objects. */
#define OBJIO_invalid_4gdobject_option                  (OBJIO_ERROR_BASE + 33)

/** The "Remote Import" operation has failed because one or more selected objects is already archived. */
#define OBJIO_archived_object                           (OBJIO_ERROR_BASE + 34)

/** The remote export to a site designated as archive location is not permitted. */
#define OBJIO_export_not_permitted                      (OBJIO_ERROR_BASE + 35)

/** No archived objects can be found with the specified restore criterion. */
#define OBJIO_no_archived_objects_found                 (OBJIO_ERROR_BASE + 36)

/** The object of type "%1$" cannot be created because of issues with the required properties. */
#define OBJIO_unable_to_create                          (OBJIO_ERROR_BASE + 37)

/** The selected objects were not archived because no site is designated as an archive location. Please contact the system administrator. */
#define OBJIO_no_archive_site                           (OBJIO_ERROR_BASE + 38)

/** "%1$" cannot be restored because it was archived from another site. */
#define OBJIO_restore_not_permitted                     (OBJIO_ERROR_BASE + 39)

/** The "%1$" operation cannot be performed at the site "%2$" because the object "%3$" already exists at this site. */
#define OBJIO_object_already_exists                     (OBJIO_ERROR_BASE + 40)

/** The object "%1$" is already archived at the "%2$" site. */
#define OBJIO_object_already_archived                   (OBJIO_ERROR_BASE + 41)

/** The 4th Generation Design objects registry is not active because the preference "%1$" is not set to "true". */
#define OBJIO_obj_registry_not_active                   (OBJIO_ERROR_BASE + 42)

/** The registration is not supported for objects of type "%1$". */
#define OBJIO_obj_registration_not_supported            (OBJIO_ERROR_BASE + 43)

/** "%1$" is already registered. */
#define OBJIO_obj_already_registered                    (OBJIO_ERROR_BASE + 44)

/** "%1$" cannot be unregistered because it is not registered. */
#define OBJIO_obj_not_registered                        (OBJIO_ERROR_BASE + 45)

/** The "%1$" connection has failed during the "%2$" operation of the data at the remote site. Restart the "%3$" process and execute the "ar_recover" utility at site "%4$" using the Dataset "%5$". */
#define OBJIO_connection_failure                        (OBJIO_ERROR_BASE + 46)

/** An error has occurred while changing the ownership of the data to site "%1$". Recover the data by executing the "ar_recover" utility at site "%2$" with the Dataset "%3$". */
#define OBJIO_flipping_ownership_failure                (OBJIO_ERROR_BASE + 47)

/** An error has occurred while deleting replicas owned by site "%1$". Recover the data by executing the "ar_recover" utility at site "%2$" with the Dataset "%3$". */
#define OBJIO_delete_replica_failure                    (OBJIO_ERROR_BASE + 48)

/** An error has occurred while transferring the archived data to site "%1$". Recover the data by executing the "ar_recover" utility at site "%2$" with the Dataset "%3$".*/
#define OBJIO_transfer_ownership_failure                (OBJIO_ERROR_BASE + 49)

/** The "%1$" operation cannot be performed on the input objects because of the previous failure. Recover the data by executing the "ar_recover" utility at site "%2$" using the Dataset "%3$". */
#define OBJIO_object_in_recovery_state                  (OBJIO_ERROR_BASE + 50)

/** The export context object "%1$" cannot be retrieved because it has been deleted by another process. */
#define OBJIO_get_export_context_failure                (OBJIO_ERROR_BASE + 51)

/** The import context object "%1$" cannot be retrieved because it has been deleted by another process. */
#define OBJIO_get_import_context_failure                (OBJIO_ERROR_BASE + 52)

/** All provided objects should belong either to the same class or subclass of Item or to the same class or subclass of Application Model (Mdl0ApplicationModel). */
#define OBJIO_mixed_class_types_failure                 (OBJIO_ERROR_BASE + 53)

/** Remote objects cannot be archived. */
#define OBJIO_remote_object_type                        (OBJIO_ERROR_BASE + 54)

/** The selection contains an object of type "%1$", which is not supported. All objects must belong to the class or subclass of Item or Application Model (Mdl0ApplicationModel). */
#define OBJIO_unsupported_class_type                   (OBJIO_ERROR_BASE + 55)

/** "%1$" cannot be restored because it was not archived. */
#define OBJIO_object_not_archived                     (OBJIO_ERROR_BASE + 56)

/** The selected objects cannot be archived because the following dependent objects are undergoing a workflow at site "%1$": %2$. */ 
#define OBJIO_targets_in_workflow                      (OBJIO_ERROR_BASE + 57)

/** The selected objects cannot be archived because the following dependent objects are checked-out at site "%1$": %2$. */ 
#define OBJIO_targets_checked_out                      (OBJIO_ERROR_BASE + 58)

/** The selected objects cannot be archived because replica objects exist at site "%1$": %2$. Execute the "delete_replica" utility at site "%3$" to perform the needed cleanup, and try again. */ 
#define OBJIO_replica_cleanup_not_performed            (OBJIO_ERROR_BASE + 59)

/** The selected objects cannot be restored because some of them are locally owned by the archive site. Please execute the "ar_recover" utility with "-f=upgrade" at the archive site. */ 
#define OBJIO_restore_local_objects                    (OBJIO_ERROR_BASE + 60)

/** The latest Item Revision cannot be archived because older Item Revisions for the Item "%1$" still exist at the production site "%2$". */
#define OBJIO_cannot_archive_latest_revision           (OBJIO_ERROR_BASE + 61)

/** The older Item Revision cannot be restored because latest Item Revision "%1$" still exists at archive site "%2$". */
#define OBJIO_cannot_restore_older_revision           (OBJIO_ERROR_BASE + 62)

/** The replica deletion at a site designated as archive location is not permitted. */
#define OBJIO_replica_deletion_not_permitted         (OBJIO_ERROR_BASE + 63)


/** @} */

#include <archive/libarchive_undef.h>
#endif
