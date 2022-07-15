/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */


/**
    @file soawireharness_errors.h

    Errors for the soa wire harness services
*/

#ifndef SOAWIREHARNESS_ERRORS_H
#define SOAWIREHARNESS_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAWIREHARNESS_ERRORS Errors
    @ingroup SOAWIREHARNESS
    @{
*/
#define SOAWIREHARNESS_input_context_is_nulltag                             (EMH_SOAWIREHARNESS_error_base + 0)

#define SOAWIREHARNESS_input_name_is_nullstring                             (EMH_SOAWIREHARNESS_error_base + 1)

#define SOAWIREHARNESS_failed_to_create_route_object                        (EMH_SOAWIREHARNESS_error_base + 2)

#define SOAWIREHARNESS_failed_to_set_display_data                           (EMH_SOAWIREHARNESS_error_base + 3)

#define SOAWIREHARNESS_failed_to_set_reallength_data                        (EMH_SOAWIREHARNESS_error_base + 4)

#define SOAWIREHARNESS_failed_to_set_representedlength_data                 (EMH_SOAWIREHARNESS_error_base + 5)

#define SOAWIREHARNESS_failed_to_associate_route_objects                    (EMH_SOAWIREHARNESS_error_base + 6)

#define SOAWIREHARNESS_failed_to_set_cross_section                          (EMH_SOAWIREHARNESS_error_base + 7)

#define SOAWIREHARNESS_failed_to_set_node_position                          (EMH_SOAWIREHARNESS_error_base + 8)

#define SOAWIREHARNESS_failed_to_set_curve_data                             (EMH_SOAWIREHARNESS_error_base + 9)

#define SOAWIREHARNESS_unable_to_delete_route_objects                       (EMH_SOAWIREHARNESS_error_base + 10)

#define SOAWIREHARNESS_failed_to_delete_all_route_objects                   (EMH_SOAWIREHARNESS_error_base + 11)

#define SOAWIREHARNESS_failed_to_delete_route_object                        (EMH_SOAWIREHARNESS_error_base + 12)

#define SOAWIREHARNESS_input_wire_object_is_nulltag                         (EMH_SOAWIREHARNESS_error_base + 13)

#define SOAWIREHARNESS_failed_to_set_length_data_on_wire_instance           (EMH_SOAWIREHARNESS_error_base + 14)

#define SOAWIREHARNESS_failed_to_set_properties_on_wire_instance            (EMH_SOAWIREHARNESS_error_base + 15)

#define SOAWIREHARNESS_failed_to_set_color_data_on_wire_object              (EMH_SOAWIREHARNESS_error_base + 16)

#define SOAWIREHARNESS_unable_to_get_wire_data                              (EMH_SOAWIREHARNESS_error_base + 17)

#define SOAWIREHARNESS_failed_to_get_wire_length_data                       (EMH_SOAWIREHARNESS_error_base + 18)

#define SOAWIREHARNESS_failed_to_get_wire_properties                        (EMH_SOAWIREHARNESS_error_base + 19)

#define SOAWIREHARNESS_failed_to_get_wire_color_data                        (EMH_SOAWIREHARNESS_error_base + 20)

#define SOAWIREHARNESS_unable_to_delete_wire_data                           (EMH_SOAWIREHARNESS_error_base + 21)

#define SOAWIREHARNESS_failed_to_delete_wire_length_data                    (EMH_SOAWIREHARNESS_error_base + 22)

#define SOAWIREHARNESS_failed_to_delete_wire_properties                     (EMH_SOAWIREHARNESS_error_base + 23)

#define SOAWIREHARNESS_failed_to_delete_wire_color_data                     (EMH_SOAWIREHARNESS_error_base + 24)

#define SOAWIREHARNESS_unable_to_associate_segments_to_protection           (EMH_SOAWIREHARNESS_error_base + 25 )

#define SOAWIREHARNESS_failed_to_associate_segments_to_protection           (EMH_SOAWIREHARNESS_error_base + 26 )

#define SOAWIREHARNESS_failed_to_set_protection_area_data                   (EMH_SOAWIREHARNESS_error_base + 27 )

#define SOAWIREHARNESS_unable_to_get_protection_data                        (EMH_SOAWIREHARNESS_error_base + 28 )

#define SOAWIREHARNESS_failed_to_get_protection_data                        (EMH_SOAWIREHARNESS_error_base + 29 )

#define SOAWIREHARNESS_unable_to_remove_protection_data                     (EMH_SOAWIREHARNESS_error_base + 30 )

#define SOAWIREHARNESS_failed_to_remove_segments                            (EMH_SOAWIREHARNESS_error_base + 31 )

#define SOAWIREHARNESS_failed_to_remove_protection_data                     (EMH_SOAWIREHARNESS_error_base + 32 )

#define SOAWIREHARNESS_failed_to_create_form                                (EMH_SOAWIREHARNESS_error_base + 33 )

#define SOAWIREHARNESS_failed_to_update_property                            (EMH_SOAWIREHARNESS_error_base + 34 )

#define SOAWIREHARNESS_failed_to_create_route_location                      (EMH_SOAWIREHARNESS_error_base + 35 )

#define SOAWIREHARNESS_failed_to_add_object_into_container                  (EMH_SOAWIREHARNESS_error_base + 36 )

#define SOAWIREHARNESS_input_harness_parent_is_nulltag                      (EMH_SOAWIREHARNESS_error_base + 37 )

#define SOAWIREHARNESS_harness_internal_error                               (EMH_SOAWIREHARNESS_error_base + 38 )

#define SOAWIREHARNESS_invalid_harness_child_type                           (EMH_SOAWIREHARNESS_error_base + 39 )

#define SOAWIREHARNESS_internal_while_creating_bv_bvr                       (EMH_SOAWIREHARNESS_error_base + 40 )

#define SOAWIREHARNESS_failed_to_create_harness_structure                   (EMH_SOAWIREHARNESS_error_base + 41 )

#define SOAWIREHARNESS_invalid_child_occurrence                             (EMH_SOAWIREHARNESS_error_base + 42 )

#define SOAWIREHARNESS_failed_to_add_child_bomline                          (EMH_SOAWIREHARNESS_error_base + 43 )

#define SOAWIREHARNESS_failed_to_update_occ_properties                      (EMH_SOAWIREHARNESS_error_base + 44 )

#define SOAWIREHARNESS_invalid_viewtype                                     (EMH_SOAWIREHARNESS_error_base + 45 )


/** @} */

#endif

