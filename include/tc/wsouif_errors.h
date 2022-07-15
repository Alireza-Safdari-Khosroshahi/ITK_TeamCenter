/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Define error codes used with WSOUIF.
*/

/*  */

#ifndef WSOUIF_ERRORS_H
#define WSOUIF_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup WSOUIF_ERRORS WSOUIF Errors
    @ingroup TC
    @{
*/

#define  WSOUIF_invalid_owner                  (EMH_WSOUIF_error_base + 1)
#define  WSOUIF_invalid_group                  (EMH_WSOUIF_error_base + 2)
#define  WSOUIF_folder_create                  (EMH_WSOUIF_error_base + 3)
#define  WSOUIF_invalid_object_type            (EMH_WSOUIF_error_base + 4)
#define  WSOUIF_find_access_denied             (EMH_WSOUIF_error_base + 5)
#define  WSOUIF_object_not_found               (EMH_WSOUIF_error_base + 6)
#define  WSOUIF_invalid_role                   (EMH_WSOUIF_error_base + 7)
#define  WSOUIF_no_matching_owner_name         (EMH_WSOUIF_error_base + 8)
#define  WSOUIF_no_name_entered                (EMH_WSOUIF_error_base + 9)
#define  WSOUIF_ambiguous_group                (EMH_WSOUIF_error_base + 10)

/** @} */

#endif
