/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

#ifndef FDP0FOURDPLANNING_ERRORS_H_INCLUDED
#define FDP0FOURDPLANNING_ERRORS_H_INCLUDED


#include <common/emh_const.h>

/**
    @defgroup FDP0FourDPlanning_ERRORS 4D Planning Errors
    @ingroup FourDPlanning
    @{
*/

/** The creation of a relation between the Process "%1$" and the Task "%2$" has failed. Please check the Teamcenter server syslog file for more information. */
#define FDP0FOURDPLANNING_create_process_to_task_relation_failed           (EMH_FDP0FOURDPLANNING_error_base + 1)

/** The deletion of a relation between the Process "%1$" and the Task "%2$" has failed. Please check the Teamcenter server syslog file for more information. */
#define FDP0FOURDPLANNING_delete_process_to_task_relation_failed            (EMH_FDP0FOURDPLANNING_error_base + 2)

/** An error has occurred while trying to create an intermediate file. Please contact your system administrator for possible volume access issues. **/
#define FDP0FOURDPLANNING_automatic_process_creation_file_open_error        (EMH_FDP0FOURDPLANNING_error_base + 3)

/** The automatic process creation has failed for the "%1$" Process. Please check the Teamcenter server syslog file for more information. **/
#define FDP0FOURDPLANNING_automatic_process_creation_failed                 (EMH_FDP0FOURDPLANNING_error_base + 4)

/** The start 4D search has failed. Please check the Teamcenter server syslog file for more information. **/
#define FDP0FOURDPLANNING_start_fourd_failed                                (EMH_FDP0FOURDPLANNING_error_base + 5)

/** The next 4D search has failed. Please check the Teamcenter server syslog file for more information. **/
#define FDP0FOURDPLANNING_next_fourd_failed                                 (EMH_FDP0FOURDPLANNING_error_base + 6)

/** The stop 4D search has failed. Please check the Teamcenter server syslog file for more information. **/
#define FDP0FOURDPLANNING_stop_fourd_failed                                 (EMH_FDP0FOURDPLANNING_error_base + 7)

/** The property "%1$" is not editable because the Process "%2$" is associated with a Task. **/
#define FDP0FOURDPLANNING_non_editable_property_work_estimate               (EMH_FDP0FOURDPLANNING_error_base + 8)

/** The format for the value "%1$" is invalid. Please enter a value in the format "[xd][ ][yh][ ][zm]" with x, y, z respectively the number of days, hours, minutes. Examples are "8h", "2d", "30m", "4h 30m". **/
#define FDP0FOURDPLANNING_invalid_property_value_work_estimate              (EMH_FDP0FOURDPLANNING_error_base + 9)

/** The process with schedule task comparison has failed. Please check the Teamcenter server syslog file for more information. */
#define FDP0FOURDPLANNING_propagate_compare_process_with_schedule_task      (EMH_FDP0FOURDPLANNING_error_base + 10)

/** The propagate schedule changes has failed. Please check the Teamcenter server syslog file for more information. */
#define FDP0FOURDPLANNING_propagate_schedule_changes_failed                 (EMH_FDP0FOURDPLANNING_error_base + 11)

/** @} */

#endif 
