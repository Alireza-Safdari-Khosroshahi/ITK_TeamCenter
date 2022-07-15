/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    GRM errors
*/

/*  */

#ifndef GRM_ERRORS_H
#define GRM_ERRORS_H

#include <common/emh_const.h>
/**
    @defgroup GRM_ERRORS Errors
    @ingroup GRM
    @{
*/

/** The Generic Relationship Management (GRM) module is not initialized. Please report this error to your system administrator. */
#define GRM_not_initialized                     (EMH_GRM_error_base + 1)

/** The following Generic Relationship Management (GRM) internal error has occurred: %1$. */
#define GRM_internal_error                      (EMH_GRM_error_base + 2)

/** The provided Relation type "%1$" is invalid. */
#define GRM_invalid_relation_type               (EMH_GRM_error_base + 3)

/** No Relation type is provided. */
#define GRM_undefined_relation_type             (EMH_GRM_error_base + 4)

/** An already existing Relation type is provided. */
#define GRM_duplicate_relation_type             (EMH_GRM_error_base + 5)

/** The primary object in the Relation is invalid. */
#define GRM_invalid_primary_object              (EMH_GRM_error_base + 6)

/** The secondary object in the Relation is invalid. */
#define GRM_invalid_secondary_object            (EMH_GRM_error_base + 7)

/** Invalid user data is provided for the Relation. */
#define GRM_invalid_user_data                   (EMH_GRM_error_base + 8)

/** The Relation "%1$" does not exist. */
#define GRM_relation_does_not_exist             (EMH_GRM_error_base + 9)

/** A "%1$" relation was not created between "%2$" and "%3$", because it already exists. */
#define GRM_relation_already_exists             (EMH_GRM_error_base + 10)

/** The Relation "%1$" cannot be deleted. */
#define GRM_cannot_delete_relation              (EMH_GRM_error_base + 11)

/** The Relation type "%1$" cannot be deleted. */
#define GRM_cannot_delete_relation_type         (EMH_GRM_error_base + 12)

/** The provided Relation is not allowed. */
#define GRM_relation_not_allowed                (EMH_GRM_error_base + 13)

/** The set of arguments provided to the function "%1$" is invalid. Please report this error to your system administrator. */
#define GRM_invalid_set_of_arguments            (EMH_GRM_error_base + 14)

/** The operation has failed, because two or more objects have duplicate Relations. */
#define GRM_duplicate_relations_exist           (EMH_GRM_error_base + 15)

/** The Relation "%1$" is not valid for primary objects of type "%2$". Please refer to the syslog file for more information. */
#define GRM_invalid_relation_primary_for_type   (EMH_GRM_error_base + 16)

/**  The Copy Stable ID for the Relation "%1$" between the object "%2$" and the object "%3$" cannot be empty. */
#define GRM_empty_copy_stable_id  (EMH_GRM_error_base + 17)

/** The Copy Stable ID "%1$" already exists for the object "%2$" and the Relation "%3$".*/
#define GRM_duplicate_copy_stable_relation  (EMH_GRM_error_base + 18)

/**Objects cannot have relations on themselves.*/
#define GRM_self_related                        (EMH_GRM_error_base + 19)

/** @} */

#endif
