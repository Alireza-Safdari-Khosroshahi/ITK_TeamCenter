/*==============================================================================
                Copyright (c) 2008 Siemens PLM Software
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

#ifndef SPECMGR_ERRORS_H
#define SPECMGR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SPECMGR_ERRORS SPECMGR Errors
    @ingroup SPECMGR
    @{
*/

#define SPECMGR_ERROR_BASE                               EMH_SPECMGR_error_base


/**
    Not supoorted action error message.
*/
#define SPECMGR_not_supported_action                   (SPECMGR_ERROR_BASE + 1)

/**
  CPSpecification delete action through IS
*/
#define SPECMGR_IS_deleted_action                     (SPECMGR_ERROR_BASE + 2)

/** @} */


#endif
