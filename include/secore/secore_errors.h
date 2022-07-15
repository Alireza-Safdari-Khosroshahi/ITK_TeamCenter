/*==============================================================================
                Copyright (c) 2006 UGS Corporation
                   Unpublished - All Rights Reserved
================================================================================

    @file

    Define error codes used with SECORE module.

==============================================================================*/

#ifndef SECORE_ERRORS_H
#define SECORE_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif
#include <secore/libsecore_exports.h>

/**
    @defgroup SECORE_ERRORS SECORE Errors
    @ingroup SECORE
    @{
*/

/**
    This error means a user is trying to moveup the selected Requirement which has
    no top sibling.
 */
#define SECORE_moveup_not_allowed                       (EMH_SECORE_error_base + 1)

/**
    This error means a user is trying to moveup the selected Requirement which has
    no next  sibling.
 */
#define SECORE_movedown_not_allowed                     (EMH_SECORE_error_base + 2)

/**
    This error means a user is trying to promote the selected Requirement which
    already occupy top level and no top sibling
 */
#define SECORE_promote_not_allowed                      (EMH_SECORE_error_base + 3)

/**
    This error means a user is trying to demote the selected Requirement which has
    no top sibling.
 */
#define SECORE_demote_not_allowed                       (EMH_SECORE_error_base + 4)

/**
    This error means a user is trying to Enter an invalid Number.
 */
#define SECORE_edit_not_allowed                         (EMH_SECORE_error_base + 5)

/**
    Some of the objects in the BOM window were modified in another session.
    Please select the top line and refresh the BOM window.
 */
#define SECORE_move_refresh_required                    (EMH_SECORE_error_base + 6)

/**
    Module level errors - ALLOCATING 20 positions
 */

/**
    Error for Overwrite Condition
 */
#define SECORE_overwrite_detected                       (EMH_SECORE_error_base + 21)

/**
    The requested operation cannot be completed because the runtime object "%1$" is not of type "%2$".
 */
#define SECORE_invalid_tag_nulltag                      (EMH_SECORE_error_base + 22)

/**
    No callback of type "%1$" is registered. Please report this issue to your system administrator.
 */
#define SECORE_callback_not_registered                  (EMH_SECORE_error_base + 23)

/**
    The recipe should have at least one entry. Please report this issue to your system administrator.
 */
#define SECORE_invalid_recipe_length                    (EMH_SECORE_error_base + 24)

/** @} */

#include <secore/libsecore_undef.h>
#endif
