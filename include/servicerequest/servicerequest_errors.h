/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2009.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SERVICEREQUEST_ERRORS_H
#define SERVICEREQUEST_ERRORS_H

#include <common/emh_const.h>
#include <servicerequest/libservicerequest_exports.h>

/**
    @defgroup SERVICEREQUEST_ERRORS Errors
    @ingroup SERVICEREQUEST
    @{
*/

#define SERVICEREQUEST_error_base                        EMH_SERVICEREQUEST_error_base

/**
   The user does not have an Author License to perform this action.
*/

#define SERVICEREQUEST_user_missing_author_license  (SERVICEREQUEST_error_base + 1)

/**
    The Service catalog cannot be created without relation to a Neutral Part.
*/
#define SERVICEREQUEST_service_catalog_not_related_to_neutral_part  (SERVICEREQUEST_error_base + 2)

/**
    The Service catalog invalid name.
*/
#define SERVICEREQUEST_service_catalog_invalid_name  (SERVICEREQUEST_error_base + 3)

/**
    The Service Offering invalid name.
*/
#define SERVICEREQUEST_service_offering_invalid_name  (SERVICEREQUEST_error_base + 4)

/**
    The Service Offering invalid offering number.
*/
#define SERVICEREQUEST_service_offering_invalid_offering_number  (SERVICEREQUEST_error_base + 5)

/**
    The Service Offering cannot be created without relation to a Sewrvice Catalog.
*/
#define SERVICEREQUEST_service_offering_not_related_to_service_catalog  (SERVICEREQUEST_error_base + 6)

/**
    A remote object cannot be rolled up.
*/
#define SERVICEREQUEST_rollup_invalid_on_remote_object  (SERVICEREQUEST_error_base + 7)

/**
    A remote object cannot be canceled.
*/
#define SERVICEREQUEST_cancel_invalid_on_remote_object  (SERVICEREQUEST_error_base + 8)

/**
      Can not CANCEL an object that is already canceled.
*/

#define SERVICEREQUEST_can_not_cancel_object_that_is_already_canceled (SERVICEREQUEST_error_base + 9)

/**
      Condition evaluation failed.
*/

#define SERVICEREQUEST_condition_evaluation_failed (SERVICEREQUEST_error_base + 10)

/**
      Missing requested activities
*/

#define SERVICEREQUEST_missing_requested_activities (SERVICEREQUEST_error_base + 11)

/**
      A Delegate Service Request with open Requested Activities can not be canceled.
*/

#define SERVICEREQUEST_cant_cancel_delegate_while_ra_is_open (SERVICEREQUEST_error_base + 12)

/**
      Duplicate Physical Part.
*/

#define SERVICEREQUEST_duplicate_physical_part (SERVICEREQUEST_error_base + 13)

/**
      Invalid Physical Part Selected.
*/

#define SERVICEREQUEST_invalid_physical_part_asbuilt (SERVICEREQUEST_error_base + 14)

/**
    A remote object cannot be rolled up.
*/
#define SERVICEREQUEST_rollup_invalid_access  (SERVICEREQUEST_error_base + 15)

/** @} */

#include <servicerequest/libservicerequest_undef.h>

#endif
