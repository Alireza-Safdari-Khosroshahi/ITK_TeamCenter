/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This module contains the Document Imaging (DMI) error codes

    Error Base for DMI starts from 56000
*/

/*  */

#ifndef DMI_ERRORS_H
#define DMI_ERRORS_H

#include <common/emh_const.h>
#include <dmi/libdmi_exports.h>

/**
    @defgroup DMI_ERRORS Errors
    @ingroup DMI
    @{
*/

#define DMI_internal_error              (EMH_DMI_error_base + 1)
#define DMI_type_mismatch               (EMH_DMI_error_base + 2)
#define DMI_named_reference_exist       (EMH_DMI_error_base + 3)
#define DMI_named_reference_not_found   (EMH_DMI_error_base + 4)
#define DMI_no_image                    (EMH_DMI_error_base + 5)
#define DMI_not_licensed                (EMH_DMI_error_base + 6)

/** @} */

#include <dmi/libdmi_undef.h>
#endif
