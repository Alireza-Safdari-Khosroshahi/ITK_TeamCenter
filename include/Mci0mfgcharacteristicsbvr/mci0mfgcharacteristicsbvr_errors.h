/*===============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2013.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software*/

/**
    @file

    This file contains the error codes for the MCI0MFGCHARACTERISTICSBVR module
*/

/*  */

#ifndef MCI0MFGCHARACTERISTICSBVR_ERRORS_H
#define MCI0MFGCHARACTERISTICSBVR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup MCI0MFGCHARACTERISTICSBVR_ERRORS Errors
    @ingroup MCI0MFGCHARACTERISTICSBVR
    @{
*/
/** An internal error has occurred. Please contact your system administrator. */
#define MCI_internal_error                                        (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 1)
/** No value is specified for the preference "%1$". */
#define MCI_preference_empty                                      (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 2)
/** The parsing of the Dataset Named Reference XML file "%1$" has failed. Please check the syslog for more details. */
#define MCI_xml_parsing_failed                                    (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 3)
/** The Dataset Named Reference XML file "%1$" does not exist at the location pointed by the "TC_TMP_DIR" environment variable. */
#define MCI_xml_file_absent                                       (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 4)
/** The Product Manufacturing Information (PMI) XML Dataset is not attached to the line &quot;%1$&quot;. */
#define MCI_named_reference_absent                                (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 5)
/** The Form property "%1$" does not exist. Please contact your system administrator. */
#define MCI_form_prop_not_exist                                   (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 6)
/** The Form property "%1$" is not modifiable. Please contact your system administrator. */
#define MCI_form_prop_not_modifiable                              (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 7)
/** The "Import PMI" functionality did not execute successfully. No Product Manufacturing Information (PMI) was processed. */
#define MCI_import_pmi_failed                                     (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 8)
/** The "Import PMI" command did not process any Product Manufacturing Information (PMI) objects because the Dataset of type "%1$" with relation "%2$" is absent. */
#define MCI_no_pmi_to_update                                      (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 9)
/** The BOP details form for the Product Manufacturing Information (PMI) object "%1$" cannot be created. Please check the syslog for more details. */
#define MCI_unable_to_create_bopdetails_form                      (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 10)
/** The Product Manufacturing Information (PMI) Form is absent on the PMI object "%1$". Please contact your system administrator. */
#define MCI_form_absent_on_pmi                                    (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 11)
/** Only Item Revisions and Product Manufacturing Information (PMI) can be sent to the workflow. */
#define MCI_wf_attachment_type_error                              (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 12)
/** The Product Manufacturing Information (PMI) objects cannot be attached to the workflow. Please check the syslog for more details. */
#define MCI_unable_to_attach_to_wf                                (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 13)
/** The Product Manufacturing Information (PMI) object "%1$" under the line "%2$" imported from NX with status update/delete does not exist hence it has been created, and not updated/deleted. */
#define MCI_pmi_created_rather_than_modifed                       (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 14)
/** The Product Manufacturing Information (PMI) object "%1$" under the line "%2$" has been updated/deleted, and not created, because it already existed. */
#define MCI_pmi_modifed_rather_than_created                       (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 15)
/** The Product Manufacturing Information (PMI) object "%1$" under the line "%2$" has been marked as deleted, because it did not exist in the attached dataset. */
#define MCI_pmi_marked_deleted                                    (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 16)
/** The Product Manufacturing Information (PMI) object "%1$" cannot be modified, because the Parent Line "%2$" is already released. */
#define MCI_pmi_cannot_modify                                     (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 17)
/** The source object is invalid. Please contact your system administrator. */
#define MCI_source_object_null                                    (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 18)
/** The target object provided in the "Import PMI" command is invalid. Please contact your system administrator. */
#define MCI_target_object_null                                    (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 19)
/** The traversing of the following Dataset Named Reference JT file has failed: %1$. Please check the syslog for more details. */
#define MCI_jt_traverse_failed                                    (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 20)
/** The initialization of the CAD importer has failed. Please check the syslog file for more details. */
#define MCI_jt_cad_importer_init_failed                           (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 21)
/** The "Import PMI" command did not process any Product Manufacturing Information (PMI) objects because the Dataset of type "%1$" with relation "%2$" has nothing to process. */
#define MCI_no_pmi_to_process                                     (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 22)
/** An invalid object was provided to perform the import PMI. Please provide the item, process, or operation line from the structure. */
#define MCI_import_pmi_invalid_object                             (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 23)
/** An invalid object was provided as input. */
#define MCI_invalid_object                                        (EMH_MCI0MFGCHARACTERISTICSBVR_error_base + 24)

/** @} */
#endif
