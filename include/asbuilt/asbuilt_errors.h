/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the publish identifiers of error codes that can be
    generated by this module. Obtaining and using the numeric values of these
    manifest constants is not supported. We reserve the right to change the
    actual values as necessary.
*/

/*  */

#ifndef ASBUILT_ERRORS_H
#define ASBUILT_ERRORS_H

#include <common/emh_const.h>
#include <asbuilt/libasbuilt_exports.h>

/**
    @defgroup ASBUILT_ERRORS Errors
    @ingroup ASBUILT
    @{
*/

#define ASBUILT_error_base                                                  EMH_ASBUILT_error_base

/**
    This error means the selected Item is not a valid MRO Neutral Item.
*/
#define ASBUILT_item_not_valid_neutral_item                                 (ASBUILT_error_base + 1)

/**
    This error means the selected Item is not a traceable Neutral Item.
*/
#define ASBUILT_non_traceable_item                                          (ASBUILT_error_base + 2)

/**
    This error means the selected object is not the Physical Part Revision.
*/
#define ASBUILT_item_not_physical_revision                                  (ASBUILT_error_base + 3)

/**
    This error means the specified Physical Part Usage value is not valid.
*/
#define ASBUILT_incorrect_install_usage_type                                (ASBUILT_error_base + 4)

/**
    This error means the specified Installation Date is either a future date
    or not a valid date value.
*/
#define ASBUILT_incorrect_install_date                                      (ASBUILT_error_base + 5)

/**
    This error means the selected Physical Part for installation is a serialized
    part but does not have a valid Serial Number.
*/
#define ASBUILT_empty_serial_number                                         (ASBUILT_error_base + 6)

/**
    This error means the selected Physical Part for installation is a lot
    part but does not have a valid Lot Number.
*/
#define ASBUILT_empty_lot_number                                            (ASBUILT_error_base + 7)

/**
    This error means the selected Physical Part for installation is a serialized
    lot part but does not have a valid Serial Number or Lot Number.
*/
#define ASBUILT_empty_serial_lot_number                                     (ASBUILT_error_base + 8)

/**
    This error means removal / un-installation of a Missing Physical Part
    is not allowed.
*/
#define ASBUILT_remove_missing_part_error                                   (ASBUILT_error_base + 9)

/**
    This error means a user is trying to install a deviated Physical Part
    but does not have a valid deviation set up.
*/
#define ASBUILT_allowed_deviation_not_setup                                 (ASBUILT_error_base + 10)

/**
    This error means selected action cannot be performed since the selected
    Physical Part is released.
*/
#define ASBUILT_physical_part_is_released                                   (ASBUILT_error_base + 11)

/**
    This error means AsBuilt Structure can not be released since missing
    Part is found in the AsBuilt Structure.
*/
#define ASBUILT_missing_part_found                                          (ASBUILT_error_base + 12)

/**
    This error means AsBuilt Structure can not be released since checked out
    Part is found in the AsBuilt Structure.
*/
#define ASBUILT_checkedout_part_found                                       (ASBUILT_error_base + 13)

/**
    This error means the top line cannot be replaced
*/
#define ASBUILT_top_line_cannot_be_replaced                                 (ASBUILT_error_base + 14)

/**
    The parent Physical part revision is not an AsBuilt Revision.
*/
#define ASBUILT_install_parent_part_not_asbuilt                             (ASBUILT_error_base + 15)

/**
    The child Physical Part Revision is not an AsBuilt Revision.
*/
#define ASBUILT_install_child_part_not_asbuilt                              (ASBUILT_error_base + 16)

/**
    The Physical Part Revision is not an AsBuilt Revision.
*/
#define ASBUILT_physical_revision_is_not_asbuilt                            (ASBUILT_error_base + 17)

/**
    The Physical Part has no asbuilt revisions.
*/
#define ASBUILT_physical_part_has_no_asbuilt_revisions                      (ASBUILT_error_base + 18)

/**
    Rebuild date can not be earlier than last install date
*/
#define ASBUILT_incorrect_rebuild_date                                      (ASBUILT_error_base + 19)

/**
    Rebuild date can not be future date
*/
#define ASBUILT_rebuild_date_cannot_be_future_date                          (ASBUILT_error_base + 20)

/**
    The given string &quot;%1$&quot; is not a valid UID.
*/
#define ASBUILT_invalid_uid                                                 (ASBUILT_error_base + 21)


/** @} */

#include <asbuilt/libasbuilt_undef.h>

#endif