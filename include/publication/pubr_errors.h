/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Errors for the PublicationRecord Class
*/

/*  */

#ifndef PUBR_ERRORS_H
#define PUBR_ERRORS_H

#include <common/emh_const.h>
#include <publication/libpublication_exports.h>

/**
    @defgroup PUBR Publication Record
*/

/**
    @defgroup PUBR_ERRORS Publication Record Errors
    @ingroup PUBR
    @{
*/
/** Error when PublicationRecord class could not be initialized. */
#define PUBR_no_initialize_class                    (EMH_PUBR_error_base + 1)

/** Error when PublicationRecord could not be created. */
#define PUBR_no_create                              (EMH_PUBR_error_base + 2)

/** Error when object could not be published. */
#define PUBR_no_publish                             (EMH_PUBR_error_base + 3)

/** Error when PublicationRecord not found for a given object. */
#define PUBR_no_such_record                         (EMH_PUBR_error_base + 4)

/** Error when object of given type is not publishable. */
#define PUBR_invalid_type                           (EMH_PUBR_error_base + 5)

/** Error when not able to load published information for object. */
#define PUBR_no_load_remote_object                  (EMH_PUBR_error_base + 6)

/** Error when not able list properties of published object. */
#define PUBR_no_properties                          (EMH_PUBR_error_base + 7)

/** Error when the requesting site is not the owning site. */
#define PUBR_not_owning_site                        (EMH_PUBR_error_base + 8)

/** Error when objects of this class are not publishable. */
#define PUBR_not_publishable_class                  (EMH_PUBR_error_base + 9)

/** Error when object could not be unpublished. */
#define PUBR_no_unpublish                           (EMH_PUBR_error_base + 10)

/** Error when the object was unpublished but audit record was not created. */
#define PUBR_no_audit_record                        (EMH_PUBR_error_base + 11)

/** Error when the object was unpublished but audit record was not deleted. */
#define PUBR_audit_record_not_deleted               (EMH_PUBR_error_base + 12)

/** Error when object with the same class and id is already published. */
#define PUBR_id_and_class_not_unique                (EMH_PUBR_error_base + 13)

/** Error when user has no read access to the publication record. */
#define PUBR_no_read_access                         (EMH_PUBR_error_base + 14)

/** Error when user trying to publish to more than 10 ODS'es. */
#define PUBR_max_ods_count_exceeded                 (EMH_PUBR_error_base + 15)

/** Error when object is not published to the given ODS site(s). */
#define PUBR_not_published_to_ods                   (EMH_PUBR_error_base + 16)

/** Error when publishing is not permitted at this site. */
#define PUBR_no_publishing_from_site                (EMH_PUBR_error_base + 17)

/** Error when user does not have Publish privilege on object. */
#define PUBR_no_publish_priv_on_obj                 (EMH_PUBR_error_base + 18)

/** Error when publishing a replica within same hub group. */
#define PUBR_no_publish_replica_to_same_hub_group   (EMH_PUBR_error_base + 19)

/** Error when  unpublishing a remote object. */
#define PUBR_no_unpublish_remote                    (EMH_PUBR_error_base + 20)

/** Error when object with the same multifield key values is already published. */
#define PUBR_mfk_not_unique                         (EMH_PUBR_error_base + 21)

/** Error when object is published user cannot check-out object. */
#define PUBR_cannot_checkout_po                     (EMH_PUBR_error_base + 22)

/** @} */

#include <publication/libpublication_undef.h>
#endif
