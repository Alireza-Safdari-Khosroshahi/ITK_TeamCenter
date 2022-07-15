/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef TRANSACTIONPROCESSING_ERRORS_H
#define TRANSACTIONPROCESSING_ERRORS_H

#include <common/emh_const.h>
#include <transactionprocessing/libtransactionprocessing_exports.h>

/**
    @defgroup TRANSACTIONPROCESSING_ERRORS TRANSACTIONPROCESSING Errors
    @ingroup TRANSACTIONPROCESSING
    @{
*/

#define TRANSACTIONPROCESSING_error_base EMH_TRANSACTIONPROCESSING_error_base

/**
      Error trying to find the class id of Transaction Element class.
*/

#define TRANSACTIONPROCESSING_finding_classid_of_transaction_element_class (TRANSACTIONPROCESSING_error_base + 1)

/**
      Can not APPROVE an object that is already approved.
*/

#define TRANSACTIONPROCESSING_can_not_approve_object_that_is_already_approved (TRANSACTIONPROCESSING_error_base + 2)

/**
      Can not APPROVE a child object directly. Please approve the parent.
*/

#define TRANSACTIONPROCESSING_can_not_approve_a_child (TRANSACTIONPROCESSING_error_base + 3)

/**
      Can not APPROVE a remote object.
*/

#define TRANSACTIONPROCESSING_object_is_remote (TRANSACTIONPROCESSING_error_base + 4)

/**
      Can not create this object because the transaction id is not unique.
*/

#define TRANSACTIONPROCESSING_duplicate_transactionid (TRANSACTIONPROCESSING_error_base + 5)

/**
      The user does not have an Author License to perform this action.
*/

#define TRANSACTIONPROCESSING_user_missing_author_license (TRANSACTIONPROCESSING_error_base + 6)


/** @} */

#include <transactionprocessing/libtransactionprocessing_undef.h>

#endif
