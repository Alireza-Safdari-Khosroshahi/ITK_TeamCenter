/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Content Management errors

*/

#ifndef CONTMGMT_ERRORS_H
#define CONTMGMT_ERRORS_H

#include <common/emh_const.h>

#include <contmgmt/libcontmgmt_exports.h>

/**
    @defgroup CONTMGMT_ERRORS CONTMGMT Errors
    @ingroup CONTMGMT
    @{
*/

#define CONTMGMT_ERROR_BASE                               EMH_CONTMGMT_error_base

/**
    An error "%1$" has occurred in the Content Management Module.
*/
#define CONTMGMT_GENERAL_ERROR                           (CONTMGMT_ERROR_BASE + 0)

/**
    A language, a graphic priority list or a Translation Office with the same name "%1$" already exists in the database. It must be unique.
*/
#define CONTMGMT_uniqueness_check_failed                 (CONTMGMT_ERROR_BASE + 1)

/**
    The target object is not a Translation Order Revision.
*/
#define CONTMGMT_target_not_translation_order             (CONTMGMT_ERROR_BASE + 2)

/**
    No email address is defined for the Translation Office "%1$". Please contact your system administrator to add an email address to the Translation Office.
*/
#define CONTMGMT_email_not_found                         (CONTMGMT_ERROR_BASE + 3)

/**
    No Translation Delivery Revision is related to the Translation Order Revision. Please create a Translation Delivery.
*/
#define CONTMGMT_translation_delivery_not_found                (CONTMGMT_ERROR_BASE + 4)

/** @} */

#include <contmgmt/libcontmgmt_undef.h>

#endif

