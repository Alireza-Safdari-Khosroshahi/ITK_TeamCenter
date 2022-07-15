/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2009.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SERVICEPLANNING_ERRORS_H
#define SERVICEPLANNING_ERRORS_H

#include <common/emh_const.h>
#include <serviceplanning/libserviceplanning_exports.h>

/**
    @defgroup SERVICEPLANNING_ERRORS Errors
    @ingroup SERVICEPLANNING
    @{
*/

#define SERVICEPLANNING_error_base                                              EMH_SERVICEPLANNING_error_base

/**
 *    Single Level Requires/Satisfies relation allowed error
 */
#define SSP0_only_single_level_relation_allowed_error                           (SERVICEPLANNING_error_base + 1)

/**
    Invalid Frequency Expression error
*/
#define SSP0_invalid_frequency_expression                                        (SERVICEPLANNING_error_base + 2)

/**
 *  Resolves relation not allowed error
 */

#define SSP0_missing_partfaultcode_relation                                     (SERVICEPLANNING_error_base + 3)


/**
 *  PartFault relation deletion not allowed if Resolves relation exists error
 */

#define SSP0_resolves_relation_exists                                           (SERVICEPLANNING_error_base + 4)

/**
 *  The operation can be performed in context of service plan.
 */
#define SSP0_not_in_context_of_servicePlan                                      (SERVICEPLANNING_error_base + 5)

/**
 *  The source context is different than neutral product for service plan.
 */
#define SSP0_source_context_different_than_plan_context                         (SERVICEPLANNING_error_base + 6)

/**
 *  The Service Requirement cannot have more than one target part.
 */
#define SSP0_multiple_meassign_not_allowed                                      (SERVICEPLANNING_error_base + 7)

/**
 *  The Work Card has related Characteristics Definitions.
 *  Therefore Part Movements cannot be defined for the Work Card
 */
#define SSP0_work_card_has_char_definitions                                     (SERVICEPLANNING_error_base + 8)

/**
 *  Part Movements are defined for the Work Card.
 *  Therefore Characteristics Definition cannot be related to the Work Card
 */
#define SSP0_work_card_has_part_movements                                       (SERVICEPLANNING_error_base + 9)

/**
 *  Service Requirement is not of type Upgrade.
 */
#define SSP0_not_upgrade_type_requirement                                       (SERVICEPLANNING_error_base + 10)

/**
 *  Upgrade type Work Card already exist for Service Requirement.
 */
#define SSP0_upgrade_workcard_already_exists                                     (SERVICEPLANNING_error_base + 11)

/**
 *  Cannot move the Work Card.
 */
#define SSP0_workcard_cannot_be_moved                                           (SERVICEPLANNING_error_base + 12)

/**
 *  Assign Parts relation deletion not allowed if Resolves relation exists error
 */
#define SSP0_assign_parts_relation_exists                                       (SERVICEPLANNING_error_base + 13)

 /**
  *  No service requirement resolves the given fault &quot;%1$&quot; of  &quot;%2$&quot;. Please contact your administrator for further assistance.
  */
#define SSP0_no_service_requirement_resolves_the_fault_code                     (SERVICEPLANNING_error_base + 14)

/** @} */

#include <serviceplanning/libserviceplanning_undef.h>

#endif
