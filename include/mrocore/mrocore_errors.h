/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the publish identifiers of error codes that can be
    generated by this module. Obtaining and using the numeric values of these
    manifest constants is not supported. We reserve the right to change the
    actual values as necessary.
*/

/*  */

#ifndef MROCORE_ERRORS_H
#define MROCORE_ERRORS_H

#include <common/emh_const.h>


/**
    @defgroup MROCORE_ERRORS MROCORE Errors
    @ingroup MROCORE
    @{
*/

#define MROCORE_ERROR_BASE                               EMH_MROCORE_error_base


/**
    Cannot revise a Physical Part.
*/
#define MROCORE_physpart_not_revisable                                  (MROCORE_ERROR_BASE + 1)

/**
    This error means a Physical Part with given Part Number, Serial Number and
    Manufacturer Id combination already exists.
*/
#define MROCORE_physpart_already_exists                                 (MROCORE_ERROR_BASE + 2)

/**
    The Installation Time cannot be earlier than the Manufacturing Date.
*/
#define MROCORE_installation_date_error                                 (MROCORE_ERROR_BASE + 3)

/**
    This error means a Lot with specified Lot Number does not exist.
*/
#define MROCORE_no_lots_for_design_part                                 (MROCORE_ERROR_BASE + 4)

/**
    This error means that a selected Item is not serialized.
*/
#define MROCORE_neutral_part_is_not_serialized                          (MROCORE_ERROR_BASE + 5)

/**
    This error means that a validation error occured while creating a Serial
    Number Generator.
*/
#define MROCORE_serial_number_gen_validation_error                      (MROCORE_ERROR_BASE + 6)

/**
    This error means length of generated Serial Number might exceed the
    allowed length.
*/
#define MROCORE_serial_number_max_len_exceeds                           (MROCORE_ERROR_BASE + 7)

/**
    This error occurs when the generated Serial Number from the series exceeds
    the defined maximum number.
*/
#define MROCORE_serial_number_gen_exhausted                             (MROCORE_ERROR_BASE + 8)

/**
    This error means user does not have a privilege to delete a Physical Part.
*/
#define MROCORE_no_privilege_to_delete_object                           (MROCORE_ERROR_BASE + 9)

/**
    This error means that the Physical Part has child Physical Parts and
    cannot be deleted.
*/
#define MROCORE_physpart_cannot_be_deleted                              (MROCORE_ERROR_BASE + 10)

/**
    This error occurs when a user tries to edit a Physical UID.
*/
#define MROCORE_uid_already_assigned_error                              (MROCORE_ERROR_BASE + 11)

/**
    This error means Physical UID is not unique.
*/
#define MROCORE_duplicate_physpart_uid_error                            (MROCORE_ERROR_BASE + 12)

/**
    This error means "Missing" Physical Part cannot be removed from structure.
*/
#define MROCORE_remove_missing_part_error                               (MROCORE_ERROR_BASE + 13)

/**
    This error means Serial Number cannot be assigned to non-serialized
    Physical Part.
*/
#define MROCORE_part_not_serialized_error                               (MROCORE_ERROR_BASE + 14)

/**
    This error means Lot Number cannot be assigned to non-lot Physical Part.
*/
#define MROCORE_part_not_lotserialized_error                            (MROCORE_ERROR_BASE + 15)

/**
    This error means Selected Item is not of Lot type.
*/
#define MROCORE_item_not_of_lot_type                                    (MROCORE_ERROR_BASE + 16)

/**
    This error means Lot with specified LotNumber and ManufacurerId
    already exists.
*/
#define MROCORE_lot_already_exists                                      (MROCORE_ERROR_BASE + 17)

/**
    This error means Lot creation failed.
*/
#define MROCORE_lot_creation_failed                                     (MROCORE_ERROR_BASE + 18)

/**
    This error means Part Logistics information for selected Item could not
    be found.
*/
#define MROCORE_partlogistics_info_not_found                            (MROCORE_ERROR_BASE + 19)

/**
    This error means selected Item cannot be deleted since it has some
    Physical Parts realized from it.
*/
#define MROCORE_item_cannot_be_deleted_error                            (MROCORE_ERROR_BASE + 20)

/**
    This error means Unidentified (missing) physical parts cannot be deleted.
*/
#define MROCORE_cannot_delete_identified_parts_error                    (MROCORE_ERROR_BASE + 21)

/**
    This error means selected Item is not a Physical Part.
*/
#define MROCORE_item_not_physical_item                                  (MROCORE_ERROR_BASE + 22)

/**
    This error occurs when Deviation Document is not sepcified while setting
    up a Physical Part Deviation.
*/
#define MROCORE_empty_deviation_document                                (MROCORE_ERROR_BASE + 23)

/**
    This error means the Deviation Authority is not set up in BMIDE.
*/
#define MROCORE_empty_deviation_doc_authority                           (MROCORE_ERROR_BASE + 24)

/**
    This error means the selected Deviation Document is not of authorized type.
*/
#define MROCORE_wrong_deviation_doc_authority                           (MROCORE_ERROR_BASE + 25)

/**
    This error means the selected BOMLine does not have a PSOccurrence.
*/
#define MROCORE_no_occurrence_on_bomline                                (MROCORE_ERROR_BASE + 26)

/**
    This error means Manufacturer Id is not specified with the Lot Number.
*/
#define MROCORE_physpart_mfgid_not_specified                            (MROCORE_ERROR_BASE + 27)

/**
    This error means the Passed in Deviation Document is not Released.
*/
#define MROCORE_deviation_doc_not_released                              (MROCORE_ERROR_BASE + 28)

/**
    This error means Maturity status not defined for Physical Part.
*/
#define MROCORE_no_maturity_status_found                                (MROCORE_ERROR_BASE + 29)

/**
    This error means serial number generation scheme is not defined for
    selected part.
*/
#define MROCORE_no_serial_number_defined                                (MROCORE_ERROR_BASE + 30)

/**
    This error means lot exist for the lot number specified in generate physical structure.
    The lot usage is equal to lot size.
*/
#define MROCORE_lot_usage_error                                         (MROCORE_ERROR_BASE + 31)

/**
    This error means lot number specified in generate physical structure is invalid.
    No such lot exists in the system.
*/
#define MROCORE_invalid_lot_error                                       (MROCORE_ERROR_BASE + 32)

/**
    This error means the current value specified while creating serial number
    generator is less than zero.
*/
#define MROCORE_ser_num_gen_invalid_current                             (MROCORE_ERROR_BASE + 33)

/**
    This error means the series maximum value specified is invalid.
    This value should be more than zero.
*/
#define MROCORE_ser_num_gen_invalid_maximum                             (MROCORE_ERROR_BASE + 34)

/**
    This error means the series increment by value specified is invalid.
    This value should be more than zero.
*/
#define MROCORE_ser_num_gen_invalid_increment                           (MROCORE_ERROR_BASE + 35)

/**
    This error means the number of characters value specified is invalid.
    This value should be more than zero.
*/
#define MROCORE_ser_num_gen_invalid_characters                          (MROCORE_ERROR_BASE + 36)

/**
    This error means the value specified for the series current is more than
    the value of series maximum.
*/
#define MROCORE_ser_num_gen_invalid_cur_max                             (MROCORE_ERROR_BASE + 37)

/**
    This error means the value specified for the lotsize is less than
    the lotusage.
*/
#define MROCORE_lotsize_less_than_lotusage                              (MROCORE_ERROR_BASE + 38)

/**
    This error means the value specified for the lotsize is less than zero
*/
#define MROCORE_lotsize_less_than_zero                                  (MROCORE_ERROR_BASE + 39)

/**
    The 'Save As' action is not allowed on the Physical Part.
*/
#define MROCORE_physpart_saveas_not_allowed                             (MROCORE_ERROR_BASE + 40)

/**
    This error means the manufacturer's org id cannot be modified
*/
#define MROCORE_mfgid_cannot_be_modified_error                          (MROCORE_ERROR_BASE + 41)

/**
    This error means the install of physical part under
    missing parent is not allowed.
*/
#define MROCORE_install_under_missing                                   (MROCORE_ERROR_BASE + 42)

/**
    This error implies parent Physical Part is released.
*/
#define MROCORE_parent_physical_part_is_released                        (MROCORE_ERROR_BASE + 43)

/**
    This error means the selected Item is not a valid MRO Neutral Item.
*/
#define MROCORE_item_not_valid_neutral_item                             (MROCORE_ERROR_BASE + 44)

/**
    This error means the selected Item is not a traceable Neutral Item.
*/
#define MROCORE_non_traceable_item                                      (MROCORE_ERROR_BASE + 45)

/**
    The Log Book has Log Entry related to it and therefore
    it cannot be deleted.
*/
#define MROCORE_logbook_cannot_be_deleted                               (MROCORE_ERROR_BASE + 46)

/**
    The Characteristic Definition already exists.
*/
#define MROCORE_duplicate_characteristic_definition                     (MROCORE_ERROR_BASE + 47)

/**
    This error means selected action cannot be performed since
    the selected Physical Part is released.
*/
#define MROCORE_physical_part_is_released                               (MROCORE_ERROR_BASE + 48)

/**
    This error means a user is trying to install a deviated Physical
    Part but does not have a valid deviation set up.
*/
#define MROCORE_allowed_deviation_not_setup                             (MROCORE_ERROR_BASE + 49)

/**
    This error means the specified Installation Date is either
    a future date or not a valid date value.
*/
#define MROCORE_incorrect_install_date                                  (MROCORE_ERROR_BASE + 50)

/**
    "%1$" was not installed because a Physical Part cannot be installed under a missing part. Please identify the missing part first.
*/
#define MROCORE_physicalpart_is_not_identified                          (MROCORE_ERROR_BASE + 51)

/**
    The Physical part revision on which installation is happening,
    is not latest.
*/
#define MROCORE_physicalpart_revision_is_not_latest                     (MROCORE_ERROR_BASE + 52)

/**
    This error means selected Physical Part Revision is not released.
*/
#define MROCORE_physical_part_revision_is_not_released                  (MROCORE_ERROR_BASE + 53)

/**
    This error means un-install action is not allowed on a top part.
*/
#define MROCORE_uninstall_not_allowed_on_top_part                       (MROCORE_ERROR_BASE + 54)

/**
    This error means repalce action is not allowed on a top part.
*/
#define MROCORE_top_line_replace_not_allowed                            (MROCORE_ERROR_BASE + 55)

/**
    This error means Rebase Date is less than effective from
    date of Physical Part Revision.
*/
#define MROCORE_rebasedate_less_than_effective_from_date                (MROCORE_ERROR_BASE + 56)

/**
    This error means the Physical Structure in BOM Window
    is not configured for today.
*/
#define MROCORE_physical_structure_not_configured_for_today             (MROCORE_ERROR_BASE + 57)

/**
    This error means Installation Date is less than effective from
    date of Physical Part Revision.
*/
#define MROCORE_installationdate_less_than_effective_from_date          (MROCORE_ERROR_BASE + 58)

/**
    This error means there is no argument defined for
    validate-for-class rule handler.
*/
#define MROCORE_no_argument_for_validate_class                          (MROCORE_ERROR_BASE + 59)

/**
    This error means there are more than one arguments defined
    for validate-for-class rule handler.
*/
#define MROCORE_multiple_arguments_for_validate_class                   (MROCORE_ERROR_BASE + 60)

/**
    This error means there is no value specified for
    validate-for-class rule handler's argument.
*/
#define MROCORE_define_value_for_validate_class_argument                (MROCORE_ERROR_BASE + 61)

/**
    This error means the selected object is not of the specified type.
*/
#define MROCORE_item_is_not_of_specified_type                           (MROCORE_ERROR_BASE + 62)

/**
    This error means invalid argument is defined for
    validate-for-class rule handler.
*/
#define MROCORE_invalid_argument_for_validate_class                     (MROCORE_ERROR_BASE + 63)

/**
    This error means Deviation is already setup between the
    selected Physical Parts.
*/
#define MROCORE_deviation_is_already_set_up                             (MROCORE_ERROR_BASE + 64)

/**
    This error means the specified recording date is either a
    future date or not a valid date value.
*/
#define MROCORE_incorrect_recording_date                                (MROCORE_ERROR_BASE + 65)

/**
    This error means the specified recorded at date
    is earlier to Physical Part effective date.
*/
#define MROCORE_incorrect_recorded_at_date                             (MROCORE_ERROR_BASE + 66)

/**
    Hierarchical Workspace Object has children hence cannot be deleted
*/
#define MROCORE_hierarchicalwso_has_children                            (MROCORE_ERROR_BASE + 67)

/**
    Deviation can not be setup with same part
*/
#define MROCORE_cannot_setup_deviation_with_itself                      (MROCORE_ERROR_BASE + 68)

/**
    The selected Lot object cannot be used because its Expiration Date is "%1$".
*/
#define MROCORE_lot_is_expired                                          (MROCORE_ERROR_BASE + 69)

/**
    The action cannot be completed because a stub was found.
*/
#define MROCORE_stub_found                                              (MROCORE_ERROR_BASE + 70)

/**
    The Allowed Deviation relation cannot be deleted because the Deviation is referenced.
*/
#define MROCORE_deviation_delete_not_allowed                            (MROCORE_ERROR_BASE + 71)

/**
    This error means Uninstallation Date is less than effective from
    date of Physical Part Revision.
*/
#define MROCORE_uninstallationdate_less_than_effective_from_date        (MROCORE_ERROR_BASE + 72)

/**
    This error means Replace Date is less than effective from
    date of Physical Part Revision.
*/
#define MROCORE_replacedate_less_than_effective_from_date               (MROCORE_ERROR_BASE + 73)

/**
    The Characteristic Definition has Characteristic Value related
    to it and therefore it cannot be deleted.
*/
#define MROCORE_chardef_cannot_be_deleted                               (MROCORE_ERROR_BASE + 74)


/**
    Serial Number once assigned to a Physical Part cannot be unset,
    it can be changed.
*/
#define MROCORE_serial_number_cannot_be_empty_error                     (MROCORE_ERROR_BASE + 75)


/**
    Manufactuing Id once assigned to a Physical Part cannot be unset,
    it can be changed.
*/
#define MROCORE_mfgid_cannot_be_empty_error                             (MROCORE_ERROR_BASE + 76)

/**
    This error implies that the value of the business constant set
    for an Item is not a valid subtype of Physical Part.
*/
#define MROCORE_invalid_physical_part_type                              (MROCORE_ERROR_BASE + 77)

/**
    This error means the specified Series Characters will not be
    sufficient to accomodate the Series Maximum number.
*/
#define MROCORE_ser_num_gen_characters_count                            (MROCORE_ERROR_BASE + 78)

/**
    The Physical Context relation cannot be deleted.
*/
#define MROCORE_physical_context_relation_cannot_be_deleted             (MROCORE_ERROR_BASE + 79)

/**
    The Physical Realization relation cannot be deleted.
*/
#define MROCORE_physical_realization_relation_cannot_be_deleted         (MROCORE_ERROR_BASE + 80)

/**
    The Installation Date cannot be earlier than the parent's
    Manufacturing Date.
*/
#define MROCORE_installdate_earlier_than_parent_mfgdate_error           (MROCORE_ERROR_BASE + 81)

/**
    The Part Logistics Form is already checked-out by an user
*/
#define MROCORE_plf_is_reserved                                         (MROCORE_ERROR_BASE + 82)

/**
    The character definition name should be alpanumeric
*/
#define MROCORE_chardef_name_is_not_alphanumeric                        (MROCORE_ERROR_BASE + 83)

/**
    Part Logisitics Form not found error.
*/
#define MROCORE_plf_not_found                                           (MROCORE_ERROR_BASE + 84)

/**
    Neutral structure modification not allowed
*/
#define MROCORE_modify_neutral_structure_prevent_error                  (MROCORE_ERROR_BASE + 85)

/**
    Manufacturing date can not be future date.
*/
#define MROCORE_date_cannot_be_future_date                              (MROCORE_ERROR_BASE + 86)

/**
    The character definition does not exist.
*/
#define MROCORE_chardef_does_not_exist                                  (MROCORE_ERROR_BASE + 88)

/**
    The date character definition is  not allowed in expression.
*/
#define MROCORE_date_chardef_not_allowed                                (MROCORE_ERROR_BASE + 89)

/**
    This error means Rename Date is less than effective from
    date of Physical Part Revision.
*/
#define MROCORE_renamedate_less_than_effective_from_date                (MROCORE_ERROR_BASE + 90)

/**
    This error means the specified rename date is either a
    future date or not a valid date value.
*/
#define MROCORE_incorrect_rename_date                                   (MROCORE_ERROR_BASE + 91)

/**
    This error means the can not record utilization for
    specified characteristic definition at specified time as
    it already exists.
*/
#define MROCORE_cannot_record_utilization                               (MROCORE_ERROR_BASE + 92)

/**
    Physical structure modification not allowed
*/
#define MROCORE_modify_physical_structure_prevent_error                 (MROCORE_ERROR_BASE + 93)

/**
    Released Deviation Authority not allowed
*/
#define MROCORE_released_deviation_not_allowed                          (MROCORE_ERROR_BASE + 94)

/**
    Neutral lines are packed.
*/
#define MROCORE_neutral_lines_packed_error                              (MROCORE_ERROR_BASE + 95)

/**
    The missing physical part has preferred children.
*/
#define MROCORE_physpart_has_preferred_children                         (MROCORE_ERROR_BASE + 96)

/**
    "%1$" was not installed under "%2$" because the quantity to be installed (%4$) is more than the expected quantity of %3$. Please change quantity to install.
*/
#define MROCORE_greater_install_quantity                                (MROCORE_ERROR_BASE + 97)

/**
    "%1$" was not assigned to "%2$" because the quantity to be installed (%4$) is more than the expected quantity of %3$. Please change the quantity to assign.
*/
#define MROCORE_greater_assign_lot_quantity                              (MROCORE_ERROR_BASE + 98)

/**
    "%1$" was not assigned to "%2$" because the quantity to be installed (%4$) does not match the expected quantity of %3$. Please update the provided quantity to match the physical part quantity, or keep the value blank.
*/
#define MROCORE_assign_lot_quantity_mismatch                             (MROCORE_ERROR_BASE + 99)

/**
    Negative values are not accepted for quantity. Please update the provided quantity to match the Physical Part quantity, or keep the value blank.
*/
#define MROCORE_negative_quantity                                        (MROCORE_ERROR_BASE + 100)

/**
   Please specify a quantity of 1 or leave the value blank, because the preserve quantity is false.
*/
#define MROCORE_quantity_not_one                                         (MROCORE_ERROR_BASE + 101)

/**
   Please specify a non-negative value as quantity. If the unit of measure is "each" or if the Design Part is defined as a Lot Part, the quantity can only be an integer value.
*/
#define MROCORE_quantity_is_double                                        (MROCORE_ERROR_BASE + 102)

/**
    The Manufacturing Date was not saved because it cannot be later than the Installation Time.
*/
#define MROCORE_manufacturing_date_error                                 (MROCORE_ERROR_BASE + 103)

/**
    "%1$" is not of type Physical BOM Line.
*/
#define MROCORE_utilization_on_invalid_object_type                       (MROCORE_ERROR_BASE + 104)

/**
    Creation failed for some of the characteristic value. Please refer to server syslog for details.
*/
#define MROCORE_creation_of_some_characteristics_failed                  (MROCORE_ERROR_BASE + 105)

/**
    Log entry has been modified by some other user. Check the updated value before modifying.
*/
#define MROCORE_invalidation_of_invalid_characteristic_error             (MROCORE_ERROR_BASE + 106)

/**
    Requested quantity cannot be more than the available size "%1$" of the lot "%2$".
*/
#define MROCORE_quantity_exceeds_available_lot_usage                     (MROCORE_ERROR_BASE + 107)

/**
    Request failed, as the action is creating/modifying the Item ID of Physical Part, violating its uniqueness. The resulting Item ID "%1$" is calculated based on the properties part number, serial number and manufacturing ID.
*/
#define MROCORE_mfk_uniqueness_violation_error_for_physical_part         (MROCORE_ERROR_BASE + 108)

/**
    The specified object type is invalid. The valid object type is Characteristic Definition.
*/
#define MROCORE_characteristic_Definition_on_invalid_object_type          (MROCORE_ERROR_BASE + 109)

/**
The specified object type is invalid. The valid object type is Characteristic Value.
*/
#define MROCORE_characteristic_Value_on_invalid_object_type               (MROCORE_ERROR_BASE + 110)

/**
The fault "%1$" does not apply to "%2$".
*/
#define MROCORE_invalid_fault_code_for_physical_part                      (MROCORE_ERROR_BASE + 111)

/**
    The String Characteristic "%1$" is not allowed in the expression.
*/
#define MROCORE_string_chardef_not_allowed                                (MROCORE_ERROR_BASE + 112)

/**
    The Boolean Characteristic "%1$" is not allowed in the expression.
*/
#define MROCORE_bool_chardef_not_allowed                                  (MROCORE_ERROR_BASE + 113)

/** @} */



#endif