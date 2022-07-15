//===============================================================================
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


/**
    @file

    This file contains the error codes for the MES module
*/

/*  */

#ifndef MES_ERRORS_H
#define MES_ERRORS_H

#include <common/emh_const.h>
#include <mes/libmes_exports.h>

/**
    @defgroup MES_ERRORS MES Errors
    @ingroup MES
    @{
*/
/** The initialization of a Business Object has failed. */
#define MES_initialization_failed            (EMH_CMTMES_error_base + 1)
/** The standard text functionality is not supported for the target object. */
#define MES_NoSTXFunctionalityError          (EMH_CMTMES_error_base + 2)
/** The work instructions functionality is not supported for the target object. */
#define MES_NoWIFunctionalityError           (EMH_CMTMES_error_base + 3)
/** The work instruction document cannot be loaded for the target object "%1$". */
#define MES_invalid_target_object_to_load_error      (EMH_CMTMES_error_base + 4)
/** The work instruction document cannot be saved for the target object "%1$". */
#define MES_invalid_target_object_to_save_error      (EMH_CMTMES_error_base + 5)
/** @} */
#include <mes/libmes_undef.h>
#endif
