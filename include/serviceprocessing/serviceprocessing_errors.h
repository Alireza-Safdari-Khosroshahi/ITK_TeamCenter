/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SERVICEPROCESSING_ERRORS_H
#define SERVICEPROCESSING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SERVICEPROCESSING_ERRORS Errors
    @ingroup SERVICEPROCESSING
    @{
*/

#define SERVICEPROCESSING_error_base                                         EMH_SERVICEPROCESSING_error_base

/**
   A Service Discrepancy cannot be created without an In Progress relation to a Physical Part.
*/

#define SERVICEPROCESSING_service_discrepancy_not_related_to_physical_part  (SERVICEPROCESSING_error_base + 1)

/**
   An Activity Value Entry cannot be created without a relation to a Service Event.
*/

#define SERVICEPROCESSING_activiy_entry_value_not_related_to_service_event (SERVICEPROCESSING_error_base + 2)

/**
   A Service Discrepancy cannot be approved without a corrective action relation to a Service Event.
*/

#define SERVICEPROCESSING_sd_missing_corrective_action                     (SERVICEPROCESSING_error_base + 3)

/**
   A Service Discrepancy cannot be approved unless its corrective action's Service Event is approved.
*/

#define SERVICEPROCESSING_corrective_action_se_on_sd_not_approved          (SERVICEPROCESSING_error_base + 4)


/**
   A non-service Structure Item cannot be submitted to the Approve Service Structure workflow.
*/

#define SERVICEPROCESSING_non_service_structure_item_submitted_to_workflow (SERVICEPROCESSING_error_base + 5)

/**
   The default log book preference %1$ was not found.
*/

#define SERVICEPROCESSING_default_log_book_pref_not_found                  (SERVICEPROCESSING_error_base + 6)

/**
   The In Progress Physical Part was not found.
*/

#define SERVICEPROCESSING_in_progress_physpart_not_found                   (SERVICEPROCESSING_error_base + 7)

/**
   A Service Activity with transaction id '%1$' and activity number '%2$' already exists.
*/

#define SERVICEPROCESSING_service_activity_failed_uniqueness               (SERVICEPROCESSING_error_base + 8)

/**
   The generation of Physical Part failed.
*/

#define SERVICEPROCESSING_generate_physical_part_failed                    (SERVICEPROCESSING_error_base + 9)

/**
   The installation of Physical Part failed.
*/

#define SERVICEPROCESSING_install_physical_part_failed                     (SERVICEPROCESSING_error_base + 10)

/**
   The uninstallation of the Physical Part failed.
*/

#define SERVICEPROCESSING_uninstall_physical_part_failed                   (SERVICEPROCESSING_error_base + 11)

/**
   The Discovery Date cannot be a future date.
*/

#define SERVICEPROCESSING_discovery_date_failed_future_date                (SERVICEPROCESSING_error_base + 12)


/**
   The Physical Part %1$ to uninstall cannot be found.
*/

#define SERVICEPROCESSING_uninstall_physical_part_not_found                (SERVICEPROCESSING_error_base + 13)

/**
   The current Disposition cannnot be found.
*/

#define SERVICEPROCESSING_current_disposition_not_found                    (SERVICEPROCESSING_error_base + 14)

/**
   The Moved Part cannot be created.
*/

#define SERVICEPROCESSING_failed_to_create_moved_part_rel                  (SERVICEPROCESSING_error_base + 15)

/**
   The default location %1$ cannot be found.
*/

#define SERVICEPROCESSING_default_location_not_found                       (SERVICEPROCESSING_error_base + 16)

/**
   The parent Physical Part %1$ has no children.
*/

#define SERVICEPROCESSING_parent_physical_part_has_no_childern             (SERVICEPROCESSING_error_base + 17)

/**
   The neutral BOMLine cannot be created.
*/

#define SERVICEPROCESSING_failed_to_create_neutral_bomline                 (SERVICEPROCESSING_error_base + 18)

/**
   The AsMaintained BOMLine cannot be created.
*/

#define SERVICEPROCESSING_failed_to_create_asm_bomline                     (SERVICEPROCESSING_error_base + 19)

/**
   The user does not have an Author License to perform this action.
*/

#define SERVICEPROCESSING_user_missing_author_license                      (SERVICEPROCESSING_error_base + 20)

/**
   A Deviated physical part can not be installed unless "Is Approved Deviation" is true.  Can not continue.
*/

#define SERVICEPROCESSING_deviation_flag_incorrect                         (SERVICEPROCESSING_error_base + 21)

/**
   This Part Movement is missing a parent Physical Part for an install.  Can not continue.
*/

#define SERVICEPROCESSING_pm_missing_parent_for_install                    (SERVICEPROCESSING_error_base + 22)

/**
   This Part Movement is missing a parent Neutral Part for an install.  Can not continue.
*/

#define SERVICEPROCESSING_pm_missing_parent_neutral_for_install            (SERVICEPROCESSING_error_base + 23)

/**
   An As-Built Part can not be installed.  Can not continue.
*/

#define SERVICEPROCESSING_install_phys_rev_asbuilt_rev                     (SERVICEPROCESSING_error_base + 24)

/**
   A Physical Part without Serial Number can not be installed.  Can not continue.
*/

#define SERVICEPROCESSING_install_phys_rev_missing_sn                      (SERVICEPROCESSING_error_base + 25)

/**
   This Part Movement is missing a Physical Part for the install.  Can not continue.
*/

#define SERVICEPROCESSING_pm_missing_part_for_install                      (SERVICEPROCESSING_error_base + 26)

/**
   This Part Movement is missing a Physical Part for the install.  Can not continue.
*/

#define SERVICEPROCESSING_Deviated_Physical_Part_occupied_already          (SERVICEPROCESSING_error_base + 27)

/**
   The Service Discrepancy cannot be created because Physical Part Revision not found.
*/

#define SERVICEPROCESSING_sd_Physical_Part_Revision_not_found              (SERVICEPROCESSING_error_base + 28)


/**
   The Service Discrepancy cannot be created because Physical Part Revision not found.
*/

#define SERVICEPROCESSING_sd_plmxml_physical_part_revision_not_found       (SERVICEPROCESSING_error_base + 29)

/**
   The Service Discrepancy cannot be created because Discovery Date not found
*/

#define SERVICEPROCESSING_sd_plmxml_discovery_date_not_found               (SERVICEPROCESSING_error_base + 30)

/**
   Part Movement cannot be created because Invalid Part Movement Type
*/

#define SERVICEPROCESSING_pm_plmxml_part_movement_type_not_found           (SERVICEPROCESSING_error_base + 31)

/**
   Part Movement cannot be created because Parent Physical Part Revision not found

*/

#define SERVICEPROCESSING_pm_plmxml_physical_part_revision_not_found       (SERVICEPROCESSING_error_base + 32)

/**
   unable create Fault Code

*/

#define SERVICEPROCESSING_pm_plmxml_unable_create_fault_code               (SERVICEPROCESSING_error_base + 33)

/**
   unable create Service Discrepancy

*/

#define SERVICEPROCESSING_pm_plmxml_unable_create_service_discrepancy      (SERVICEPROCESSING_error_base + 34)

/**
   Invalid The Discovery Date

*/

#define SERVICEPROCESSING_pm_plmxml_invalid_discovery_date                 (SERVICEPROCESSING_error_base + 35)

/**
   Physical Part Revision URI not found

*/

#define SERVICEPROCESSING_plmxml_physical_part_revision_uri_not_found      (SERVICEPROCESSING_error_base + 36)

/**
   Physical Part Revision '%1$' not found
*/

#define SERVICEPROCESSING_plmxml_physical_part_revision_not_found          (SERVICEPROCESSING_error_base + 37)

/**
   Invalid Part Movemen5t Action Date
*/

#define SERVICEPROCESSING_plmxml_invalid_action_date                       (SERVICEPROCESSING_error_base + 38)

/**
    Unable to corrective action URI.
*/
#define SERVICEPROCESSING_plmxml_unable_to_resolve_corrective_action_URI   (SERVICEPROCESSING_error_base + 39)

/**
    Unable to resolve Contains URI.
*/
#define SERVICEPROCESSING_plmxml_unable_to_resolve_contains_URI            (SERVICEPROCESSING_error_base + 40)

/**
    fault code already exist.
*/
#define SERVICEPROCESSING_plmxml_fault_code_already_exist                  (SERVICEPROCESSING_error_base + 41)

/**
    part movement already exist.
*/
#define SERVICEPROCESSING_plmxml_part_movement_already_exist               (SERVICEPROCESSING_error_base + 42)

/**
    service discrepancy already exist.
*/
#define SERVICEPROCESSING_plmxml_service_discrepancy_already_exist         (SERVICEPROCESSING_error_base + 43)

/**
    part movement creation failed.
*/
#define SERVICEPROCESSING_plmxml_part_movement_creation_failed             (SERVICEPROCESSING_error_base + 44)

/**
    activity entry value creation failed.
*/
#define SERVICEPROCESSING_plmxml_activity_entry_value_creation_failed      (SERVICEPROCESSING_error_base + 45)

/**
    The Physical Part cannot be installed because the usage is occupied.
*/
#define SERVICEPROCESSING_usage_occupied                                   (SERVICEPROCESSING_error_base + 46)

/**
   The replace of the Physical Part failed.
*/
#define SERVICEPROCESSING_replace_physical_part_failed                     (SERVICEPROCESSING_error_base + 47)

/**
   The approval corrective action failed.
*/
#define SERVICEPROCESSING_failed_to_approve_correctiveAction               (SERVICEPROCESSING_error_base + 48)

/**
   The generation of Physical Part failed because the neutral part is missing.
*/

#define SERVICEPROCESSING_missing_neutral_part                             (SERVICEPROCESSING_error_base + 49)

/**
   "%1$" was not created because the Discovery Date cannot be a future date.
*/

#define SERVICEPROCESSING_unable_create_discovery_date_failed_future_date  (SERVICEPROCESSING_error_base + 50)


/** @} */

#endif
