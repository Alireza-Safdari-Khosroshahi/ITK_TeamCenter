/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2009.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    ccdm errors

*/

#ifndef CCDM_ERRORS_H
#define CCDM_ERRORS_H

#include <common/emh_const.h>
#include <ccdm/libccdm_exports.h>

/**
    @defgroup CCDM_ERRORS CCDM Errors
    @ingroup CCDM
    @{
*/

#define CCDM_ERROR_BASE                                             EMH_CCDM_error_base
#define CCDM_GENERAL_ERROR                                          (CCDM_ERROR_BASE + 0)

#define CCDM_error_paramDef_used_in_same_structure                  (CCDM_ERROR_BASE + 1)
#define CCDM_error_used_in_Different_item_of_same_type              (CCDM_ERROR_BASE + 2)
#define CCDM_error_paramDef_not_allows_under_another_paramDef       (CCDM_ERROR_BASE + 3)

#define CCDM_create_tabledefinition_obj_failed                      (CCDM_ERROR_BASE + 4)
#define CCDM_create_table_obj_failed                                (CCDM_ERROR_BASE + 5)

#define CCDM_create_parmdefbcdrevision_obj_failed                   (CCDM_ERROR_BASE + 6)
#define CCDM_create_parmdefbitdefrevision_obj_failed                (CCDM_ERROR_BASE + 7)
#define CCDM_create_parmdefboolrevision_obj_failed                  (CCDM_ERROR_BASE + 8)
#define CCDM_create_parmdefdaterevision_obj_failed                  (CCDM_ERROR_BASE + 9)
#define CCDM_create_parmdefdblrevision_obj_failed                   (CCDM_ERROR_BASE + 10)
#define CCDM_create_parmdefhexrevision_obj_failed                   (CCDM_ERROR_BASE + 11)
#define CCDM_create_parmdefintrevision_obj_failed                   (CCDM_ERROR_BASE + 12)
#define CCDM_create_parmdefsedrevision_obj_failed                   (CCDM_ERROR_BASE + 13)
#define CCDM_create_parmdefstrrevision_obj_failed                   (CCDM_ERROR_BASE + 14)

#define CCDM_validate_parmdefbcdrevision_obj_failed                 (CCDM_ERROR_BASE + 15)
#define CCDM_validate_parmdefbitdefrevision_obj_failed              (CCDM_ERROR_BASE + 16)
#define CCDM_validate_parmdefboolrevision_obj_failed                (CCDM_ERROR_BASE + 17)
#define CCDM_validate_parmdefdaterevision_obj_failed                (CCDM_ERROR_BASE + 18)
#define CCDM_validate_parmdefdblrevision_obj_failed                 (CCDM_ERROR_BASE + 19)
#define CCDM_validate_parmdefhexrevision_obj_failed                 (CCDM_ERROR_BASE + 20)
#define CCDM_validate_parmdefintrevision_obj_failed                 (CCDM_ERROR_BASE + 21)
#define CCDM_validate_parmdefsedrevision_obj_failed                 (CCDM_ERROR_BASE + 22)
#define CCDM_validate_parmdefstrrevision_obj_failed                 (CCDM_ERROR_BASE + 23)

#define CCDM_validate_parmvalbcd_obj_failed                         (CCDM_ERROR_BASE + 24)
#define CCDM_validate_parmvalbitdef_obj_failed                      (CCDM_ERROR_BASE + 25)
#define CCDM_validate_parmvalbool_obj_failed                        (CCDM_ERROR_BASE + 26)
#define CCDM_validate_parmvaldate_obj_failed                        (CCDM_ERROR_BASE + 27)
#define CCDM_validate_parmvaldbl_obj_failed                         (CCDM_ERROR_BASE + 28)
#define CCDM_validate_parmvalhex_obj_failed                         (CCDM_ERROR_BASE + 29)
#define CCDM_validate_parmvalint_obj_failed                         (CCDM_ERROR_BASE + 30)
#define CCDM_validate_parmvalsed_obj_failed                         (CCDM_ERROR_BASE + 31)
#define CCDM_validate_parmvalstr_obj_failed                         (CCDM_ERROR_BASE + 32)

#define CCDM_copy_parmdefbcdrevision_obj_failed                     (CCDM_ERROR_BASE + 33)
#define CCDM_copy_parmdefbitdefrevision_obj_failed                  (CCDM_ERROR_BASE + 34)
#define CCDM_copy_parmdefboolrevision_obj_failed                    (CCDM_ERROR_BASE + 35)
#define CCDM_copy_parmdefdaterevision_obj_failed                    (CCDM_ERROR_BASE + 36)
#define CCDM_copy_parmdefdblrevision_obj_failed                     (CCDM_ERROR_BASE + 37)
#define CCDM_copy_parmdefhexrevision_obj_failed                     (CCDM_ERROR_BASE + 38)
#define CCDM_copy_parmdefintrevision_obj_failed                     (CCDM_ERROR_BASE + 39)
#define CCDM_copy_parmdefsedrevision_obj_failed                     (CCDM_ERROR_BASE + 40)
#define CCDM_copy_parmdefstrrevision_obj_failed                     (CCDM_ERROR_BASE + 41)

#define CCDM_create_parmvalbcdrevision_obj_failed                   (CCDM_ERROR_BASE + 42)
#define CCDM_create_parmvalbitdefrevision_obj_failed                (CCDM_ERROR_BASE + 43)
#define CCDM_create_parmvalboolrevision_obj_failed                  (CCDM_ERROR_BASE + 44)
#define CCDM_create_parmvaldaterevision_obj_failed                  (CCDM_ERROR_BASE + 45)
#define CCDM_create_parmvaldblrevision_obj_failed                   (CCDM_ERROR_BASE + 46)
#define CCDM_create_parmvalhexrevision_obj_failed                   (CCDM_ERROR_BASE + 47)
#define CCDM_create_parmvalintrevision_obj_failed                   (CCDM_ERROR_BASE + 48)
#define CCDM_create_parmvalsedrevision_obj_failed                   (CCDM_ERROR_BASE + 49)
#define CCDM_create_parmvalstrrevision_obj_failed                   (CCDM_ERROR_BASE + 50)



#define CCDM_get_tablecell_obj_failed                               (CCDM_ERROR_BASE + 51)
#define CCDM_set_tabledata_obj_failed                               (CCDM_ERROR_BASE + 52)

#define CCDM_validate_parmgrpdef_obj_failed                         (CCDM_ERROR_BASE + 53)

#define CCDM_error_min_max_intial_values_not_in_range               (CCDM_ERROR_BASE + 54)
#define CCDM_error_min_max_intial_tables_size_differ                (CCDM_ERROR_BASE + 55)
#define CCDM_error_get_table_cells_values_failed                    (CCDM_ERROR_BASE + 56)
#define CCDM_error_denominator_or_numerator_should_not_be_zero      (CCDM_ERROR_BASE + 57)
#define CCDM_error_invalid_issigned                                 (CCDM_ERROR_BASE + 58)
#define CCDM_error_not_in_range                                     (CCDM_ERROR_BASE + 59)
#define CCDM_error_insufficient_increment                           (CCDM_ERROR_BASE + 60)
#define CCDM_rounding_error                                         (CCDM_ERROR_BASE + 61)
#define CCDM_error_resolution_not_equal_to_calculatedresolution     (CCDM_ERROR_BASE + 62)
#define CCDM_error_invalid_valid_value                              (CCDM_ERROR_BASE + 63)
#define CCDM_error_validvalue_not_match_with_initialvalue           (CCDM_ERROR_BASE + 64)
#define CCDM_error_validvalue_and_initialvalue_tables_size_differ   (CCDM_ERROR_BASE + 65)

#define CCDM_error_set_resolution_denominator_failed                (CCDM_ERROR_BASE + 66)
#define CCDM_error_set_resolution_numerator_failed                  (CCDM_ERROR_BASE + 67)
#define CCDM_error_set_is_signed_failed                             (CCDM_ERROR_BASE + 68)
#define CCDM_error_set_initial_values_failed                        (CCDM_ERROR_BASE + 69)
#define CCDM_error_set_max_values_failed                            (CCDM_ERROR_BASE + 70)
#define CCDM_error_set_min_values_failed                            (CCDM_ERROR_BASE + 71)
#define CCDM_error_set_valid_values_failed                          (CCDM_ERROR_BASE + 73)

#define CCDM_deserialize_tablecell_obj_failed                       (CCDM_ERROR_BASE + 74)
#define CCDM_deserialize_parmdefrevision_obj_failed                 (CCDM_ERROR_BASE + 75)

#define CCDM_error_maxvalue_not_an_actual_increment_of_resolution   (CCDM_ERROR_BASE + 76)
#define CCDM_error_initvalue_not_an_actual_increment_of_resolution  (CCDM_ERROR_BASE + 77)
#define CCDM_error_invalid_initvalue                                (CCDM_ERROR_BASE + 78)
#define CCDM_error_invalid_minvalue                                 (CCDM_ERROR_BASE + 79)
#define CCDM_error_invalid_maxvalue                                 (CCDM_ERROR_BASE + 80)
#define CCDM_error_invalid_resolution                               (CCDM_ERROR_BASE + 81)
#define CCDM_validate_license_failed                                (CCDM_ERROR_BASE + 82)
#define CCDM_error_invalid_resolution_numerator                     (CCDM_ERROR_BASE + 83)
#define CCDM_error_invalid_resolution_denominator                   (CCDM_ERROR_BASE + 84)
#define CCDM_error_invalid_tolerance                                (CCDM_ERROR_BASE + 85)
#define CCDM_error_invalid_precision                                (CCDM_ERROR_BASE + 86)

#define CCDM_deserialize_parmdefrev_obj_failed_no_maxValue          (CCDM_ERROR_BASE + 87)
#define CCDM_deserialize_parmdefrev_obj_failed_no_validValue        (CCDM_ERROR_BASE + 88)
#define CCDM_deserialize_parmdefrev_obj_failed_no_defaultValue      (CCDM_ERROR_BASE + 89)
#define CCDM_deserialize_parmdefrev_obj_failed_no_parmDesc          (CCDM_ERROR_BASE + 90)
#define CCDM_deserialize_parmdefrev_obj_failed_no_isSigned          (CCDM_ERROR_BASE + 91)
#define CCDM_deserialize_parmdefrev_obj_failed_no_numerator         (CCDM_ERROR_BASE + 92)
#define CCDM_deserialize_parmdefrev_obj_failed_no_denominator       (CCDM_ERROR_BASE + 93)
#define CCDM_deserialize_parmdefrev_obj_failed_no_precision         (CCDM_ERROR_BASE + 94)
#define CCDM_deserialize_parmdefrev_obj_failed_no_tolerance         (CCDM_ERROR_BASE + 95)
#define CCDM_deserialize_parmdefrev_obj_failed_no_initValueStr      (CCDM_ERROR_BASE + 96)
#define CCDM_deserialize_parmgrpvalrev_obj_failed_no_masterDefRev   (CCDM_ERROR_BASE + 97)
#define CCDM_deserialize_parmval_obj_failed_no_bitdef               (CCDM_ERROR_BASE + 98)
#define CCDM_deserialize_parmval_obj_failed_no_masterParmDefRev     (CCDM_ERROR_BASE + 99)
#define CCDM_deserialize_bitval_obj_failed_no_bitDef                (CCDM_ERROR_BASE + 100)
#define CCDM_deserialize_parmdefrev_obj_failed_invalid_tablecelltype (CCDM_ERROR_BASE + 101)
#define CCDM_deserialize_parmdefrev_obj_failed_no_tabledef          (CCDM_ERROR_BASE + 102)
#define CCDM_deserialize_parmdefrev_obj_failed_no_initValue         (CCDM_ERROR_BASE + 103)
#define CCDM_deserialize_parmdefrev_obj_failed_no_minValue          (CCDM_ERROR_BASE + 104)

#define CCDM_create_parmgrpvalrevision_obj_failed                   (CCDM_ERROR_BASE + 105)

#define CCDM_tableAttr_and_tableDefinition_differ                   (CCDM_ERROR_BASE + 106)
#define CCDM_tableAttr_size_incorrect                               (CCDM_ERROR_BASE + 107)
#define CCDM_error_set_tabledef_failed                              (CCDM_ERROR_BASE + 108)
#define CCDM_table_or_tableDef_empty                                (CCDM_ERROR_BASE + 109)
#define CCDM_tabledef_incorrect                                     (CCDM_ERROR_BASE + 110)
#define CCDM_validate_parmval_size_not_same_with_def                (CCDM_ERROR_BASE + 111)
#define CCDM_bitdef_size_dismatch                                   (CCDM_ERROR_BASE + 112)
#define CCDM_deserialize_parmdefrev_obj_failed_no_size              (CCDM_ERROR_BASE + 113)
#define CCDM_empty_cells                                            (CCDM_ERROR_BASE + 114)
#define CCDM_error_invalid_size                                     (CCDM_ERROR_BASE + 115)
#define CCDM_error_paramDef_not_allow_substitute                    (CCDM_ERROR_BASE + 116)
#define CCDM_error_parameters_not_assigned                          (CCDM_ERROR_BASE + 117)
#define CCDM_error_set_parmdefrevision_failed                       (CCDM_ERROR_BASE + 118)
#define CCDM_invalid_object_tag                                     (CCDM_ERROR_BASE + 119)
#define CCDM_invalid_parmgrpdefrevision_obj                         (CCDM_ERROR_BASE + 120)
#define CCDM_invalid_parmgrpdef_type                                (CCDM_ERROR_BASE + 121)
#define CCDM_error_remove_assigned_group_or_parameter               (CCDM_ERROR_BASE + 122)
#define CCDM_error_memorylayout_duplicated_startaddress             (CCDM_ERROR_BASE + 123)
#define CCDM_copy_overriderevision_obj_failed                       (CCDM_ERROR_BASE + 124)
#define CCDM_error_exist_item_rev_related                           (CCDM_ERROR_BASE + 125)
#define CCDM_error_assigned_parameters                              (CCDM_ERROR_BASE + 126)
#define CCDM_error_parameters_not_in_dictionary_or_project          (CCDM_ERROR_BASE + 127)

#define CCDM_copy_convoverriderecord_obj_failed                     (CCDM_ERROR_BASE + 128)
#define CCDM_error_invalid_parmdef_conversionrule                   (CCDM_ERROR_BASE + 129)

//Export Related messages
#define CCDM_error_to_get_parmvals_from_project                     (CCDM_ERROR_BASE + 130)
#define CCDM_error_to_get_records_from_overridecontainer            (CCDM_ERROR_BASE + 131)
#define CCDM_error_to_process_memory_content                        (CCDM_ERROR_BASE + 132)
#define CCDM_error_to_fetch_startaddress_memory_block               (CCDM_ERROR_BASE + 133)
#define CCDM_error_to_fetch_startaddress_memory_layout              (CCDM_ERROR_BASE + 134)
#define CCDM_error_to_fetch_child_blocks_from_parent_block          (CCDM_ERROR_BASE + 135)
#define CCDM_error_to_fetch_records_from_memory_blocks              (CCDM_ERROR_BASE + 136)
#define CCDM_error_to_load_blocks_or_records_of_memory_layout       (CCDM_ERROR_BASE + 137)

#define CCDM_error_parmval_obj_no_masterParmDefRev                  (CCDM_ERROR_BASE + 139)
#define CCDM_error_compute_address_of_parmval                       (CCDM_ERROR_BASE + 140)
#define CCDM_error_parmdefrev_obj_no_conversionrule                 (CCDM_ERROR_BASE + 141)
#define CCDM_error_in_process_parmval                               (CCDM_ERROR_BASE + 142)
#define CCDM_error_in_fetch_values_parmval                          (CCDM_ERROR_BASE + 143)
#define CCDM_error_in_flashfile_generation                          (CCDM_ERROR_BASE + 144)
#define CCDM_invalid_selected_object                                (CCDM_ERROR_BASE + 145)
#define CCDM_selected_objects_differ                                (CCDM_ERROR_BASE + 146)
#define CCDM_invalid_variant_rule                                   (CCDM_ERROR_BASE + 147)
#define CCDM_invalid_revision_rule                                  (CCDM_ERROR_BASE + 148)
#define CCDM_invalid_dataset_type                                   (CCDM_ERROR_BASE + 149)
#define CCDM_invalid_memory_layout                                  (CCDM_ERROR_BASE + 150)
#define CCDM_invalid_override_container                             (CCDM_ERROR_BASE + 151)
#define CCDM_generateFile_not_implemented                           (CCDM_ERROR_BASE + 152)


#define CCDM_error_parameter_not_in_breakdown                        (CCDM_ERROR_BASE + 153)
#define CCDM_error_memlayout_does_not_exist                          (CCDM_ERROR_BASE + 154)
#define CCDM_error_memlayout_update_startaddress                     (CCDM_ERROR_BASE + 155)
#define CCDM_error_memlayout_cannot_modify                           (CCDM_ERROR_BASE + 156)
#define CCDM_error_memlayout_startaddress_different                  (CCDM_ERROR_BASE + 157)
#define CCDM_error_parmdef_of_other_memlayout                        (CCDM_ERROR_BASE + 158)
#define CCDM_error_parmdef_orphan_parm                               (CCDM_ERROR_BASE + 159)
#define CCDM_error_no_ov_container_for_prj                           (CCDM_ERROR_BASE + 160)
#define CCDM_error_cannot_modify_ov_container                        (CCDM_ERROR_BASE + 161)
#define CCDM_error_cannot_modify_ov_container_record                 (CCDM_ERROR_BASE + 162)
#define CCDM_error_get_ovrcontainer_for_project                      (CCDM_ERROR_BASE + 163)
#define CCDM_error_create_ovrcontainer_for_project                   (CCDM_ERROR_BASE + 164)
#define CCDM_error_updates_allowed_only_for_FormulaConst             (CCDM_ERROR_BASE + 165)
#define CCDM_error_parameter_not_in_dictionary                       (CCDM_ERROR_BASE + 166)
#define CCDM_error_convrule_not_modifiable                           (CCDM_ERROR_BASE + 167)
#define CCDM_error_parameter_not_modifiable                          (CCDM_ERROR_BASE + 168)
#define CCDM_error_parameter_released                                (CCDM_ERROR_BASE + 169)
#define CCDM_error_convrule_not_present                              (CCDM_ERROR_BASE + 170)
#define CCDM_error_get_projects_for_memlayout                        (CCDM_ERROR_BASE + 171)
#define CCDM_error_creating_memlayout                                (CCDM_ERROR_BASE + 172)
#define CCDM_error_update_record                                     (CCDM_ERROR_BASE + 173)
#define CCDM_error_create_record                                     (CCDM_ERROR_BASE + 174)
#define CCDM_error_create_ovr_mem_record                             (CCDM_ERROR_BASE + 175)
#define CCDM_error_no_ov_container_record                            (CCDM_ERROR_BASE + 176)
#define CCDM_error_update_ovr_mem_record                             (CCDM_ERROR_BASE + 177)
#define CCDM_error_create_table_conversion_rule                      (CCDM_ERROR_BASE + 178)
#define CCDM_error_create_formula_conversion_rule                    (CCDM_ERROR_BASE + 179)
#define CCDM_error_update_ovr_formula_record                         (CCDM_ERROR_BASE + 180)
#define CCDM_error_create_convrule                                   (CCDM_ERROR_BASE + 181)
#define CCDM_error_no_associated_dictionary_to_project               (CCDM_ERROR_BASE + 182)
#define CCDM_error_on_import                                         (CCDM_ERROR_BASE + 183)
#define CCDM_error_empty_dataset                                     (CCDM_ERROR_BASE + 184)
#define CCDM_Error_Invalid_File_Type                                 (CCDM_ERROR_BASE + 185)
#define CCDM_Error_Invalid_File                                      (CCDM_ERROR_BASE + 186)
#define CCDM_import_file_type_not_supported                          (CCDM_ERROR_BASE + 187)
#define CCDM_project_without_dictionary                              (CCDM_ERROR_BASE + 188)
#define CCDM_error_get_parmdef_for_dictionary                        (CCDM_ERROR_BASE + 189)
#define CCDM_Error_Invalid_Purpose                                   (CCDM_ERROR_BASE + 190)
#define CCDM_invalid_dataset_name                                    (CCDM_ERROR_BASE + 191)
#define CCDM_error_invalid_selected_object_import_input              (CCDM_ERROR_BASE + 192)
#define CCDM_error_get_mmrecord_for_dictionary                       (CCDM_ERROR_BASE + 193)
#define CCDM_error_create_ovr_conv_rule_record                       (CCDM_ERROR_BASE + 194)
#define CCDM_values_import_not_supported                             (CCDM_ERROR_BASE + 195)
#define CCDM_variant_rule_required                                   (CCDM_ERROR_BASE + 196)
#define CCDM_abe_multiple_part_solutions                             (CCDM_ERROR_BASE + 197)
#define CCDM_error_set_offset_address_failed                         (CCDM_ERROR_BASE + 198)
#define CCDM_file_name_truncated                                     (CCDM_ERROR_BASE + 199)

/** Duplicate domain element names or values are not allowed. */
#define CCDM_duplicate_valid_values                                  (CCDM_ERROR_BASE + 200)

/** @} */

#include <ccdm/libccdm_undef.h>

#endif
