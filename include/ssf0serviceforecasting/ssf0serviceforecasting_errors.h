/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SSF0SERVICEFORECASTING_ERRORS_H
#define SSF0SERVICEFORECASTING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SSF0SERVICEFORECASTING_ERRORS Errors for Service Forecasting module
    @ingroup SSF0SERVICEFORECASTING
    @{
*/

#define SERVICEFORECASTING_error_base                           EMH_SERVICEFORECASTING_error_base

/** The provided due date "%1$" is not a valid date. */
#define SERVICEFORECASTING_invalid_due_date                          (SERVICEFORECASTING_error_base + 1)

/** The creation of a Maintenance Action object has failed, because a Structure Context must be provided. */
#define SERVICEFORECASTING_ma_create_sc_absent                       (SERVICEFORECASTING_error_base + 2)

/** The creation of a Maintenance Action object has failed, because a Service Requirement must be provided. */
#define SERVICEFORECASTING_ma_create_sr_absent                       (SERVICEFORECASTING_error_base + 3)

/** The creation of a Maintenance Action object has failed, because a Physical Part must be provided. */
#define SERVICEFORECASTING_ma_create_physical_part_absent            (SERVICEFORECASTING_error_base + 4)

/** The current user "%1$" does not have permission to cancel or complete the Maintenance Action "%2$". */
#define SERVICEFORECASTING_ma_invalid_role                           (SERVICEFORECASTING_error_base + 5)

/** The Maintenance Action "%1$" cannot be completed or cancelled, because it is in due date extension process. */
#define SERVICEFORECASTING_ma_in_approval                            (SERVICEFORECASTING_error_base + 6)

/** The Maintenance Action "%1$" is already in due date extension process. The new process, therefore, cannot be started until the previous process has completed. */
#define SERVICEFORECASTING_duplicate_extension                       (SERVICEFORECASTING_error_base + 7)

/**  Maintenance Actions cannot be retrieved, because the provided As-Maintained BOM Line is not valid. */
#define SERVICEFORECASTING_ma_invalid_asm                            ( SERVICEFORECASTING_error_base + 8 )

/**  The Due Date extension workflow template does not exist. Please contact system administrator to create it. */
#define SERVICEFORECASTING_workflow_template_does_not_exist          ( SERVICEFORECASTING_error_base + 9 )

/**  The maintenance action "%1$" cannot be completed, because the required maintenance action "%2$" is still open. */
#define SERVICEFORECASTING_open_required_ma                          ( SERVICEFORECASTING_error_base + 10 )

/** @} */

#endif
