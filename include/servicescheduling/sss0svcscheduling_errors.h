/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2011.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SSS0SVCSCHEDULING_ERRORS_H
#define SSS0SVCSCHEDULING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SSS0SVCSCHEDULING_ERRORS Errors
    @ingroup SSS0SVCSCHEDULING
    @{
*/

#define SSS0SVCSCHEDULING_error_base                           EMH_SSS0SVCSCHEDULING_error_base 

/**   Part movement exists for the Job activity.*/
#define SSS0SVCSCHEDULING_partmovement_exists                        (SSS0SVCSCHEDULING_error_base + 1)

/**   the Job Card is marked for upgrade.*/
#define SSS0SVCSCHEDULING_upgrade_typeof_jobcard                     (SSS0SVCSCHEDULING_error_base + 2)

/**   Characteristic values can be recorded only for leaf level job card or job task.*/
#define SSS0SVCSCHEDULING_child_exists                               (SSS0SVCSCHEDULING_error_base + 3)

/** Duplicate Product Physical Part is not allowed on Service Work Order.*/
#define SSS0SVCSCHEDULING_duplicate_physical_part                    (SSS0SVCSCHEDULING_error_base + 4)

/** The Asset Configuration is already updated for the Job Activity.*/
#define SSS0SVCSCHEDULING_configuration_already_updated              (SSS0SVCSCHEDULING_error_base + 5)

/** Configuration update is not allowed on Job Activity that has subtasks (child tasks).*/
#define SSS0SVCSCHEDULING_parent_activity_update_config_not_allowed  (SSS0SVCSCHEDULING_error_base + 6)

/** Duplicate Company Location is not allowed on Service Work Order.*/
#define SSS0SVCSCHEDULING_duplicate_company_location                 (SSS0SVCSCHEDULING_error_base + 7)

/** Duplicate Company Contact is not allowed on Service Work Order.*/
#define SSS0SVCSCHEDULING_duplicate_company_contact                  (SSS0SVCSCHEDULING_error_base + 8)

/** The Job Activity cannot be completed because the condition has not been met.*/
#define SSS0SVCSCHEDULING_jobactivity_completion_not_allowed         (SSS0SVCSCHEDULING_error_base + 9)

/** The Job Activity "%1$" cannot be completed, because it contains an incomplete Part Movement.*/
#define SSS0SVCSCHEDULING_partmovement_validation_error              (SSS0SVCSCHEDULING_error_base + 10)

/** @} */

#endif
