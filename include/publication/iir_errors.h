/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Errors for the ItemIDRecord Class
*/

/*  */

#ifndef IIR_ERRORS_H
#define IIR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup IIR_ERRORS Errors
    @ingroup IIR
    @{
*/

#define IIR_no_initialize_class         (EMH_IIR_error_base + 1)
#define IIR_no_create                   (EMH_IIR_error_base + 2)
#define IIR_unique_constraint_violated  (EMH_IIR_error_base + 3)
#define IIR_item_already_registered     (EMH_IIR_error_base + 4)
#define IIR_item_not_registered         (EMH_IIR_error_base + 5)
#define IIR_invalid_item_id_arg         (EMH_IIR_error_base + 6)
#define IIR_only_admin_can_unregister   (EMH_IIR_error_base + 7)
#define IIR_registry_not_active         (EMH_IIR_error_base + 8)
#define IIR_registry_not_available      (EMH_IIR_error_base + 9)
#define IIR_invalid_path                (EMH_IIR_error_base + 10)
#define IIR_item_already_registered_mfk (EMH_IIR_error_base + 11)
#define IIR_item_not_registered_mfk     (EMH_IIR_error_base + 12)

/** @} */

#endif
