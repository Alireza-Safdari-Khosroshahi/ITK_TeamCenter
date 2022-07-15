/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
     @file
     This file contains error messages for FinishManagement.


*/

#ifndef FNSHMGMT_ERRORS_H
#define FNSHMGMT_ERRORS_H

#include <common/emh_const.h>
#include <fsh0fnshmgmt/libfsh0fnshmgmt_exports.h>

/**
    @defgroup FINISHMANAGEMENT_ERRORS Errors
    @ingroup FINISHMANAGEMENT
    @{
*/


/**
   An item of type Finish Group cannot be added to the "Finish Items" property of a Finish Group Revision. Please select items of type Finish.
*/
#define FNSHMGMT_invalid_finish             (EMH_FNSHMGMT_error_base + 0)

/**
   Duplicate items of type Finish are added to the "Finish Items" property.
*/
#define FNSHMGMT_duplicate_finish           (EMH_FNSHMGMT_error_base + 1)

/** @} */

#include <fsh0fnshmgmt/libfsh0fnshmgmt_undef.h>

#endif
