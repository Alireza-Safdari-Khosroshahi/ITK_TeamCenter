/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SAS0SVCAUTOSCHEDULING_ERRORS_H
#define SAS0SVCAUTOSCHEDULING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SAS0SVCAUTOSCHEDULING_ERRORS Errors for the Service Automated Scheduling module
    @ingroup  SAS0SVCAUTOSCHEDULING
    @{
*/

#define SAS0SVCAUTOSCHEDULING_error_base                                EMH_SAS0SVCAUTOSCHEDULING_error_base
    
/**  The Service Plans cannot be retrieved, because the provided As-Maintained BOM Line is not valid.*/
#define SAS0SVCAUTOSCHEDULING_sr_invalid_asm                            ( SAS0SVCAUTOSCHEDULING_error_base + 1 )

/**  The Service Discrepancies cannot be retrieved, because the provided As-Maintained BOM Line is not valid.*/
#define SAS0SVCAUTOSCHEDULING_dis_invalid_asm                           ( SAS0SVCAUTOSCHEDULING_error_base + 2 )

/**  The Schedule "%2$" cannot be populated, because the user "%1$" does not have write access to it.*/
#define SAS0SVCAUTOSCHEDULING_write_access_schedule                     ( SAS0SVCAUTOSCHEDULING_error_base + 3 )

/**  The Schedule "%1$" cannot be populated, because the operation requires at least one Service Requirement, Service Discrepancy or Maintenance Action.*/
#define SAS0SVCAUTOSCHEDULING_insufficient_data                         ( SAS0SVCAUTOSCHEDULING_error_base + 4 )

/**  The operation "populateServiceSchedule" has failed, because no Work Order was provided.*/
#define SAS0SVCAUTOSCHEDULING_no_work_order                             ( SAS0SVCAUTOSCHEDULING_error_base + 5 )

/**  No Schedule can be retrieved for the Work Order "%1$", possibly because the relation of type "CMHasWorkBreakdown" is deleted between the Schedule and the Work Order.*/
#define SAS0SVCAUTOSCHEDULING_no_schedule_for_wo                        ( SAS0SVCAUTOSCHEDULING_error_base + 6 )

/** The Schedule "%1$" cannot be populated, because the operation requires Physical Part information.*/
#define SAS0SVCAUTOSCHEDULING_no_physical_part                          ( SAS0SVCAUTOSCHEDULING_error_base + 7 )

/**  The "Regenerate" operation cannot be performed without Maintenance Actions.*/
#define SAS0SVCAUTOSCHEDULING_regenerate_without_ma                     ( SAS0SVCAUTOSCHEDULING_error_base + 8 )

/**  The "Regenerate" operation cannot be performed, because Job cards for the Maintenance Action "%1$" are in progress.*/
#define SAS0SVCAUTOSCHEDULING_ma_wc_inprogress                          ( SAS0SVCAUTOSCHEDULING_error_base + 9 )

/**  The user "%1$" does not belong to the discipline "%2$".*/
#define SAS0SVCAUTOSCHEDULING_person_reassign_validation_error          ( SAS0SVCAUTOSCHEDULING_error_base + 10 )

/**  The user "%1$" does not have required the Qualification "%2$".*/
#define SAS0SVCAUTOSCHEDULING_person_qualification_validation_error     ( SAS0SVCAUTOSCHEDULING_error_base + 11 )

/** @} */

#endif
