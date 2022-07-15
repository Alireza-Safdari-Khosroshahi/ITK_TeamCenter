/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2014.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    This file contains the error codes for the LGT module
*/

#ifndef LGT_ERRORS_H
#define LGT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup LGT_ERRORS Logistics Errors
    @ingroup LGT
    @{
*/

/**
    The logistic BOP (Bill Of Processes) "%1$" is not linked with any plant BOP.
*/
#define LGT_logistic_bop_not_linked_to_any_plant_bop                                                                      (EMH_LOGISTICS_error_base + 1)
/**
    The logistic BOP (Bill Of Processes) "%1$" is linked to the following plant BOPs, but none of them are loaded: %2. Please load them and try again.
*/
#define LGT_no_plant_bop_linked_to_logistic_bop_are_loaded                                                                (EMH_LOGISTICS_error_base + 2)
/**
    The logistic BOP (Bill Of Processes) "%1$" is linked to more than one plant BOPs, and some of them are not loaded: %2$. Please load them and try again.
*/
#define LGT_some_plant_bops_linked_to_logistic_bop_are_not_loaded                                                         (EMH_LOGISTICS_error_base + 3)
/**
    No station can be found for the Plant Structure "%1$", because it is not loaded.
*/
#define LGT_some_of_plant_strucure_loaded                                                                                 (EMH_LOGISTICS_error_base + 4)
/**
    No station can be found, because none of the relevant Plant Structures are loaded.
*/
#define LGT_no_plant_structure_is_loaded                                                                                  (EMH_LOGISTICS_error_base + 5)
/**
    The logistic BOP (Bill Of Processes) "%1$" is not linked to any plant structure.
*/
#define LGT_logistic_bop_not_linked_to_any_plant                                                                          (EMH_LOGISTICS_error_base + 6)
/**
    The logistic BOP (Bill Of Processes) "%1$" is linked to multiple plant structures: %2$.
*/
#define LGT_logistic_bop_linked_to_multiple_plants                                                                        (EMH_LOGISTICS_error_base + 7)
/**
    The logistic BOP (Bill Of Processes) "%1$" is not linked to the Plant Structure "%2$".
*/
#define LGT_logistic_bop_not_linked_to_plant_structure                                                                    (EMH_LOGISTICS_error_base + 8)
/**
    The selected item "%1$" does not contain any part families
*/
#define LGT_selected_item_does_not_contain_any_part_families                                                              (EMH_LOGISTICS_error_base + 9)
/**
    The part families do not contain any supply chains . Please create supply chain and Try again.
*/
#define LGT_part_families_does_not_contain_any_inplant_supply_chain                                                       (EMH_LOGISTICS_error_base + 10)
/**
    In plant supply chain "%1$" does not have a container requirement. Container assignment is ignored for this supply chain.
*/
#define LGT_inplant_supply_chain_not_have_container_requirement                                                           (EMH_LOGISTICS_error_base + 11)
/**
   The In Plant Supply Chain "%1$" does not have any provision process. The container assignment is ignored for this supply chain.
*/
#define LGT_inplant_supply_chain_does_not_have_provision_process                                                          (EMH_LOGISTICS_error_base + 12)
/**
    The In Plant Supply Chain "%1$" does not have station assigned to provision process. The container assignment is ignored for this supply chain.
*/
#define LGT_inplant_supply_chain_does_not_have_station_assigned_to_provision_process                                      (EMH_LOGISTICS_error_base + 13)
/**
    The container assignment has failed for the In Plant Supply Chain "%1$", because the Logisitic Provision area is not available under the Station "%2$" and it cannot be created there because the user does not have the write access on the BOM View Revision (BVR) of that Station.
*/
#define LGT_logisitic_provision_area_cannot_be_created_as_user_doesnot_have_write_access_on_bvr_of_station_line           (EMH_LOGISTICS_error_base + 14)
/**
    The In Plant Supply Chain "%1$" container assignment has failed, because the user does not have the write access on the BOM View Revision (BVR) of the Logisitic Provision Area "%2$".
*/
#define LGT_user_doesnot_have_write_access_on_bvr_of_logistic_provision_area_line                                         (EMH_LOGISTICS_error_base + 15)
/**
    The In Plant Supply Chain "%1$" container assignment is successful. %3$ containers have successfully been assigned to the Logistic Provision Area "%2$".
*/
#define LGT_inplant_supply_chain_container_assignment_succeeded_for_Logisitic_provision_area_assigned                     (EMH_LOGISTICS_error_base + 16)
/**
   The In Plant Supply Chain "%1$" container assignment is successful. %3$ containers have successfully been deleted from the Logisitic Provision Area "%2$".
*/
#define LGT_inplant_supply_chain_container_assignment_succeeded_for_Logisitic_provision_area_deleted                      (EMH_LOGISTICS_error_base + 17)
/**
   The In Plant Supply Chain "%1$" container assignment under the supply chain failed as  user doesnt have the write access on BOM View Revision (BVR) of In plant supply chain. 
*/
#define LGT_user_doesnot_have_write_access_on_bvr_of_inplant_supply_chain                                                 (EMH_LOGISTICS_error_base + 18)
/**
   The In Plant Supply Chain "%1$" container assignment is successful. %3$ containers have successfully been assigned to the In Plant Supply Chain "%2$".
*/
#define LGT_inplant_supply_chain_container_assignment_under_the_supply_chain_succeeded_assigned                           (EMH_LOGISTICS_error_base + 19)
/**
   The In Plant Supply Chain "%1$" container assignment is successful. %3$ containers have successfully been deleted from the In Plant Supply Chain "%2$".
*/
#define LGT_inplant_supply_chain_container_assignment_under_the_supply_chain_succeeded_deleted                            (EMH_LOGISTICS_error_base + 20)
/**
    The container assignment command has succeeded for all the In Plant Supply Chains. Please refer to the log for more details.
*/
#define LGT_container_assignment_command_succeeded_for_all_in_plant_supply_chains                                         (EMH_LOGISTICS_error_base + 21)
/**
    The container assignment command has succeeded for some of the In Plant Supply Chains. Please refer to the log for more details.
*/
#define LGT_container_assignment_command_succeeded_for_some_in_plant_supply_chains                                        (EMH_LOGISTICS_error_base + 22)
/**
    The container assignment command has failed for all In Plant Supply Chains. Please refer to the log for more details.
*/
#define LGT_container_assignment_command_failed_for_all_in_plant_supply_chains                                            (EMH_LOGISTICS_error_base + 23)
/**
    No part under the hierarchy of the BOM Line "%1$" is consumed by the associated Plant Bill Of Processes (BOP).
*/
#define LGT_no_part_found_in_any_plant_bop                                                                                (EMH_LOGISTICS_error_base + 24)
/**
    No candidate station could be found for the parts in the hierarchy of the BOM Line "%1$", because none of the Process Areas in the associated Plant Bill of Processes (BOP) is assigned a Work Area.
*/
#define LGT_no_station_found_in_any_plant_bop                                                                             (EMH_LOGISTICS_error_base + 25)
/**
    Work Areas can only be connected to Logistics Processes within the Logistics BOP.
*/
#define LGT_workarea_cannot_connect_non_logistic_process                                                                      (EMH_LOGISTICS_error_base + 26)
/**
   @}
*/
#endif
