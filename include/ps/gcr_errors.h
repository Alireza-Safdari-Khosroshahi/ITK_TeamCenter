/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    General Component Relation errors
*/

/*  */

#ifndef GCR_ERRORS_H
#define GCR_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

/**
    @defgroup GCR_ERRORS Errors
    @ingroup GCR
    @{
*/

#define GCR_not_initialized                        (EMH_GRM_error_base + 501)
#define GCR_internal_error                        (EMH_GRM_error_base + 502)
#define GCR_invalid_relation_type                (EMH_GRM_error_base + 503)
#define GCR_undefined_relation_type                (EMH_GRM_error_base + 504)
#define GCR_duplicate_relation_type                (EMH_GRM_error_base + 505)
#define GCR_invalid_primary_object                (EMH_GRM_error_base + 506)
#define GCR_invalid_secondary_object            (EMH_GRM_error_base + 507)
#define GCR_invalid_user_data                    (EMH_GRM_error_base + 508)
#define GCR_relation_does_not_exist                (EMH_GRM_error_base + 509)
#define GCR_relation_already_exists                (EMH_GRM_error_base + 510)
#define GCR_cannot_delete_relation                (EMH_GRM_error_base + 511)
#define GCR_cannot_delete_relation_type         (EMH_GRM_error_base + 512)
#define GCR_relation_not_allowed                (EMH_GRM_error_base + 513)
#define GCR_invalid_set_of_arguments            (EMH_GRM_error_base + 514)
#define GCR_duplicate_relations_exist           (EMH_GRM_error_base + 515)
#define GCR_invalid_relation_primary_for_type   (EMH_GRM_error_base + 516)
#define GCR_constraints_failed_creation         (EMH_GRM_error_base + 517)
#define GCR_invalid_relation                    (EMH_GRM_error_base + 518)
#define GCR_constraints_failed_deletion         (EMH_GRM_error_base + 519)
#define GCR_relation_subtype_error              (EMH_GRM_error_base + 520)

/** @} */

#endif
