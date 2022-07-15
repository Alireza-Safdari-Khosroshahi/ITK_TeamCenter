/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2010.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
     @file
     This file contains error messages for ContractManagement.


*/

#ifndef CONTRACTMANAGEMENT_ERRORS_H
#define CONTRACTMANAGEMENT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CONTRACTMANAGEMENT_ERRORS CONTRACTMANAGEMENT Errors
    @ingroup CONTRACTMANAGEMENT
    @{
*/

/** The given Contract is invalid. Please specify a correct Contract. */
#define CONTRACTMANAGEMENT_invalid_contract                 (EMH_CONTRACTMANAGEMENT_error_base + 0)

/** The Contract cannot be deleted since a Data Requirement Item is associated to it. */
#define CONTRACTMANAGEMENT_contract_has_dri                 (EMH_CONTRACTMANAGEMENT_error_base + 1)

/** The value provided in the "%1$" field does not match the Item ID of the object mentioned in the "%2$" field. */
#define CONTRACTMANAGEMENT_id_ref_mismatch                  (EMH_CONTRACTMANAGEMENT_error_base + 2)

/** The current user does not have sufficient privileges to generate the Contract Event Schedule. */
#define CONTRACTMANAGEMENT_under_privilege_to_gen_con_event_sch                     (EMH_CONTRACTMANAGEMENT_error_base + 3)

/** A Contract Event Schedule already exists for the Contract Revision "%1$". */
#define CONTRACTMANAGEMENT_contract_event_schedule_exist                            (EMH_CONTRACTMANAGEMENT_error_base + 4)

/** The current user does not have sufficient privileges to generate the Submittal Delivery Schedule. */
#define CONTRACTMANAGEMENT_under_privilege_to_gen_sub_del_sch                       (EMH_CONTRACTMANAGEMENT_error_base + 5)

/** No Schedule is generated for the Data Requirement Item "%1$", because this object is not impacted. */
#define CONTRACTMANAGEMENT_dri_not_impacted                                         (EMH_CONTRACTMANAGEMENT_error_base + 6)

/** The Data Requirement Item Revision "%1$" does not contain any Submittal Delivery Events. Please add some Submittal Delivery Events to it. */
#define CONTRACTMANAGEMENT_dri_has_no_sub_del_events                                (EMH_CONTRACTMANAGEMENT_error_base + 7)

/** No Submittal Delivery Event is selected for "%1$". */
#define CONTRACTMANAGEMENT_no_sub_del_event_selected                                (EMH_CONTRACTMANAGEMENT_error_base + 8)

/** The input vector is invalid. It does not contain Data Requirement Item or Contract Object. */
#define CONTRACTMANAGEMENT_invalid_input_vector                                     (EMH_CONTRACTMANAGEMENT_error_base + 9)

/** The "SiteTimeZone" preference is not set. it is required for the Schedule Manager application to work properly. */
#define CONTRACTMANAGEMENT_sitetimezone_pref_not_set                                (EMH_CONTRACTMANAGEMENT_error_base + 10)

/** The start and end dates for the Submittal Delivery Events of "%1$" are in the past. */
#define CONTRACTMANAGEMENT_all_sub_del_events_past_dated                            (EMH_CONTRACTMANAGEMENT_error_base + 11)

/** The Event List "%1$" was not saved because the start date cannot be after the end date. */
#define CONTRACTMANAGEMENT_startdate_cannotbe_after_enddate                         (EMH_CONTRACTMANAGEMENT_error_base + 12)

/** The Event List "%1$" was not saved because the end date is beyond the contract event schedule finish date. */
#define CONTRACTMANAGEMENT_enddate_cannotbe_after_contract_finishdate               (EMH_CONTRACTMANAGEMENT_error_base + 13)

/** The Event List "%1$" was not saved because the recurrence end date is beyond the contract event schedule finish date. */
#define CONTRACTMANAGEMENT_recurrence_enddate_cannotbe_after_contract_finishdate    (EMH_CONTRACTMANAGEMENT_error_base + 14)

/** The Submittal delivery schedule was not generated because no align task is set. */
#define CONTRACTMANAGEMENT_no_aligntask_set_to_gen_sub_del_sch                      (EMH_CONTRACTMANAGEMENT_error_base + 15)

/** The Submittal delivery schedule was not generated because no process template is set. */
#define CONTRACTMANAGEMENT_no_process_template_set_to_gen_sub_del_sch               (EMH_CONTRACTMANAGEMENT_error_base + 16)

/** The Event List "%1$" was not saved because there is no Schedule Task attached to Event. */
#define CONTRACTMANAGEMENT_no_schedule_task_attached_to_event                       (EMH_CONTRACTMANAGEMENT_error_base + 17)

/** The Event List "%1$" was not saved because the seleted Schedule Task is already attached to another Event in this Event List. Please select a Schedule Task which is not attached to any Event in this Event List. */
#define CONTRACTMANAGEMENT_dri_has_schedule_task_attached_to_another_event          (EMH_CONTRACTMANAGEMENT_error_base + 18)

/** The contract schedule could not be replaced from the contract because submittals have been generated for one or more data requirement items assigned to the contract. You must remove all generated submittals before replacing the contract schedule. */
#define CONTRACTMANAGEMENT_schedule_has_submittals_attached                         (EMH_CONTRACTMANAGEMENT_error_base + 19)

/** Generate submittal delivery schedule could not complete because there is no contract schedule attached to the contract. */
#define CONTRACTMANAGEMENT_no_schedule_attached_to_contract                         (EMH_CONTRACTMANAGEMENT_error_base + 20)

/** The contract schedule could not be replaced because submittal events exist for one or more data requirement items. You must remove all preexisting events before replacing the contract schedule. */
#define CONTRACTMANAGEMENT_dri_has_events_attached                                  (EMH_CONTRACTMANAGEMENT_error_base + 21)
/** @} */

#endif
