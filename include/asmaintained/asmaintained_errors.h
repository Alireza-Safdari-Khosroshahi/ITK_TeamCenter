/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef ASMAINTAINED_ERRORS_H
#define ASMAINTAINED_ERRORS_H

#include <common/emh_const.h>
#include <asmaintained/libasmaintained_exports.h>

/**
    @defgroup ASMAINTAINED_ERRORS ASMAINTAINED Errors
    @ingroup ASMAINTAINED
    @{
*/

#define ASMAINTAINED_error_base                                                 EMH_ASMAINTAINED_error_base

/**
    The Disposition Type object already exists.
*/
#define ASMAINTAINED_dispositiontype_already_exists                             (ASMAINTAINED_error_base + 1)

/**
   The AsMaintained Revision Rule with same name already exist.
*/
#define ASMAINTAINED_duplicate_revision_rule                                    (ASMAINTAINED_error_base + 2)

/**
    The MroDateEntry is absent in the AsMaintained Revision Rule.
*/
#define ASMAINTAINED_mro_date_entry_absent                                      (ASMAINTAINED_error_base + 3)

/**
    The MroServiceabilityEntry is absent in the AsMaintained Revision Rule.
*/
#define ASMAINTAINED_mro_serviceability_entry_absent                            (ASMAINTAINED_error_base + 4)

/**
    The MroDateEntry and MroServiceabilityEntry absent in AsMaintained Revision Rule.
*/
#define ASMAINTAINED_mro_rule_entries_absent                                    (ASMAINTAINED_error_base + 5)

/**
    The Physical Part which is getting installed is not found in a Location.
*/
#define ASMAINTAINED_physical_part_not_in_location                              (ASMAINTAINED_error_base + 6)

/**
    The Physical part revision is not an AsMaintained Revision.
*/
#define ASMAINTAINED_physicalpart_revision_is_not_asmaintained_revision         (ASMAINTAINED_error_base + 7)

/**
    The Disposition state of the Physical part is not serviceable
*/
#define ASMAINTAINED_disposition_type_is_not_serviceable                        (ASMAINTAINED_error_base + 8)

/**
    Physical Location already exists
*/
#define ASMAINTAINED_duplicate_physical_location                                (ASMAINTAINED_error_base + 9)

/**
   The disposition state of the Physical Part is same as selected disposition.
*/
#define ASMAINTAINED_selected_disposition_state_already_active                  (ASMAINTAINED_error_base + 10)

/**
    The MroDateEntry and MroServiceabilityEntry absent in AsMaintained Revision Rule.
*/
#define ASMAINTAINED_mro_revision_rule_absent                                   (ASMAINTAINED_error_base + 11)
/**
    The Disposition Start Date  cannot be earlier than previous Disposition start date.
*/
#define ASMAINTAINED_disposition_start_date_error                               (ASMAINTAINED_error_base + 12)

/**
    "%1$" was not uninstalled, because the Uninstallation Date property cannot be a future date
*/
#define ASMAINTAINED_incorrect_uninstallation_date                              (ASMAINTAINED_error_base + 13)

/**
    This error means the disposition name is not specified while uninstalling
*/
#define ASMAINTAINED_disposition_not_specified                                  (ASMAINTAINED_error_base + 14)

/**
    This error means the location name is not specified while uninstalling
*/
#define ASMAINTAINED_location_not_specified                                     (ASMAINTAINED_error_base + 15)

/**
    This error means that the physical part is already uninstalled
*/
#define ASMAINTAINED_part_already_uninstalled                                  (ASMAINTAINED_error_base + 16)

/**
    Asset Group already exists
*/
#define ASMAINTAINED_duplicate_asset_group                                      (ASMAINTAINED_error_base + 17)

/**
    The Top Line is not configured as it fails against Date Revision Rule Effectivity.
*/
#define ASMAINTAINED_physical_part_revision_is_not_effective_by_date            (ASMAINTAINED_error_base + 18)

/**
    The Top Line is not configured as it fails against Serviceability Revision Rule Effectivity.
*/
#define ASMAINTAINED_physical_part_revision_is_not_serviceable                  (ASMAINTAINED_error_base + 19)

/**
    The UnInstallation Date should be greater than its installation date
*/
#define ASMAINTAINED_uninstallation_date_is_earlier_than_installation_date     (ASMAINTAINED_error_base + 20)

/**
    The installation date of the Physical Part "%1$" at this location cannot be earlier than the installation date at the source location.
*/
#define ASMAINTAINED_install_date_earlier_than_previous_location_install_date   (ASMAINTAINED_error_base + 21)

/**
    The selected Physical Part is installed and it can no be moved.
*/
#define ASMAINTAINED_selected_part_is_installed                                 (ASMAINTAINED_error_base + 22)

/**
    Physical Location with given name not found
*/
#define ASMAINTAINED_physical_location_not_found                                (ASMAINTAINED_error_base + 23)

/**
    The Top Line not configured as it fails against Status Rule Effectivity.
*/
#define ASMAINTAINED_physical_part_revision_is_not_effective_by_status          (ASMAINTAINED_error_base + 24)

/**
    Missing Physical Part Revision found in the As-Maintained Structure.
*/
#define ASMAINTAINED_missing_part_found                                         (ASMAINTAINED_error_base + 25)

/**
    The As-Maintained Structure has a Physical Part Revision checked out by a user other than who is releasing the
    As-Maintained Structure.
*/
#define ASMAINTAINED_checkedout_part_found                                      (ASMAINTAINED_error_base + 26)

/**
    Unserviceable Physical Part Revision found in the As-Maintained Structure.
*/
#define ASMAINTAINED_unserviceable_part_found                                   (ASMAINTAINED_error_base + 27)

/**
    The child Physical Part Revision is not an AsMaintained Revision.
*/
#define ASMAINTAINED_install_child_part_not_asmaintained                        (ASMAINTAINED_error_base + 28)

/**
    Physical Location already installed.
*/
#define ASMAINTAINED_physical_location_already_installed                        (ASMAINTAINED_error_base + 29)
/**
    The Physical Part is already in given location.
*/
#define ASMAINTAINED_physical_part_already_in_location                          (ASMAINTAINED_error_base + 30)

/**
    The effecive Physical Part Revision is not As-Maintained Physical Part Revision.
*/
#define ASMAINTAINED_effective_physical_part_revision_is_not_asmaintained       (ASMAINTAINED_error_base + 31)

/**
    This error means "Identified" Physical Structure cannot be deleted.
    Only missing structure can be deleted.
*/
#define ASMAINTAINED_identified_physical_structure_delete_error                 (ASMAINTAINED_error_base + 32)

/**
    Physical disposition start date can not be future date.
*/
#define ASMAINTAINED_disposition_start_date_cannot_be_future_date               (ASMAINTAINED_error_base + 33)

/**
    Physical part movement date can not be future date.
*/
#define ASMAINTAINED_phys_part_movement_date_cannot_be_future_date              (ASMAINTAINED_error_base + 34)

/**
    Cannot revise a Physical Location.
*/
#define ASMAINTAINED_physical_location_not_revisable                            (ASMAINTAINED_error_base + 35)

/**
    The Physical Location available is in physical location structure
*/
#define ASMAINTAINED_physical_location_has_children                             (ASMAINTAINED_error_base + 36)

/**
    The Physical Location Paste Error.
*/
#define ASMAINTAINED_physlocation_paste_error                                   (ASMAINTAINED_error_base + 37)

/**
    The Physical Location contains the Physical Part so cannot be deleted
*/
#define ASMAINTAINED_physlocation_contains_physpart_error                       (ASMAINTAINED_error_base + 38)

/**
    The Physical Location is in Physical Location Structure so cannot be deleted
*/
#define ASMAINTAINED_physlocation_has_parent_error                              (ASMAINTAINED_error_base + 39)

/**
    The Physical Location cannot be revised.
*/
#define ASMAINTAINED_physlocation_revise_error                                  (ASMAINTAINED_error_base + 40)

/**
    The Asset Group contains Physical Parts
*/
#define ASMAINTAINED_assetgroup_contains_physicalparts                          (ASMAINTAINED_error_base + 41)

/**
    Installation Date cannot be updated if the part was installed
    in the previous revision of the parent.
*/
#define ASMAINTAINED_installation_date_not_modifiable_error                     (ASMAINTAINED_error_base + 42)

/**
    The given string &quot;%1$&quot; is not a valid UID.
*/
#define ASMAINTAINED_invalid_uid                                                (ASMAINTAINED_error_base + 43)

/** @} */

#include <asmaintained/libasmaintained_undef.h>

#endif
