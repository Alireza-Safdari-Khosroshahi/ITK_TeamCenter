/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright $2010.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Define error codes used with Tc Fnd0nweditor

*/

#ifndef FND0NWEDITOR_ERRORS_H
#define FND0NWEDITOR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup FND0NWEDITOR Requirement Errors
    @ingroup FTX
    @{
*/

#define FND0NWEDITOR_module_initialization_failed        (EMH_FND0NWEDITOR_error_base + 1)
#define FND0NWEDITOR_EPM_Handler_registration_failed     (EMH_FND0NWEDITOR_error_base + 2)
#define FND0NWEDITOR_EMP_SM_handler_failed               (EMH_FND0NWEDITOR_error_base + 3)
#define FND0NWEDITOR_EMP_Gen_handler_failed              (EMH_FND0NWEDITOR_error_base + 4)
#define FND0NWEDITOR_excel_template_dataset_not_found    (EMH_FND0NWEDITOR_error_base + 5)
#define FND0NWEDITOR_TEMPLATE_duplicate_name             (EMH_FND0NWEDITOR_error_base + 6)
#define FND0NWEDITOR_no_named_reference                  (EMH_FND0NWEDITOR_error_base + 7)
#define FND0NWEDITOR_create_tmpl_failed                  (EMH_FND0NWEDITOR_error_base + 8)
#define FND0NWEDITOR_update_tmpl_failed                  (EMH_FND0NWEDITOR_error_base + 9)
#define FND0NWEDITOR_revision_association_failed         (EMH_FND0NWEDITOR_error_base + 10)
#define FND0NWEDITOR_unsupported_dataset_found           (EMH_FND0NWEDITOR_error_base + 11)
#define FND0NWEDITOR_create_Diagram_failed               (EMH_FND0NWEDITOR_error_base + 12)
#define FND0NWEDITOR_null_filename                       (EMH_FND0NWEDITOR_error_base + 13)
#define FND0NWEDITOR_invalid_Create_request              (EMH_FND0NWEDITOR_error_base + 14)
#define FND0NWEDITOR_template_not_found                  (EMH_FND0NWEDITOR_error_base + 15)
#define FND0NWEDITOR_invalid_Create_request_unknown_tool (EMH_FND0NWEDITOR_error_base + 16)
#define FND0NWEDITOR_invalid_Save_request                (EMH_FND0NWEDITOR_error_base + 17)
#define FND0NWEDITOR_Save_failed                         (EMH_FND0NWEDITOR_error_base + 18)
#define FND0NWEDITOR_open_failed                         (EMH_FND0NWEDITOR_error_base + 19)
#define FND0NWEDITOR_get_tag_failed                      (EMH_FND0NWEDITOR_error_base + 20)
#define FND0NWEDITOR_prop_not_found                      (EMH_FND0NWEDITOR_error_base + 21)
#define FND0NWEDITOR_create_instance_failed              (EMH_FND0NWEDITOR_error_base + 22)
#define FND0NWEDITOR_set_value_failed                    (EMH_FND0NWEDITOR_error_base + 23)
#define FND0NWEDITOR_get_value_failed                    (EMH_FND0NWEDITOR_error_base + 24)
#define FND0NWEDITOR_null_value_passed                   (EMH_FND0NWEDITOR_error_base + 25)
#define FND0NWEDITOR_invalid_membership_prop_value       (EMH_FND0NWEDITOR_error_base + 26)
#define FND0NWEDITOR_get_diagramMembers_failed           (EMH_FND0NWEDITOR_error_base + 27)
#define FND0NWEDITOR_multiple_root_object_found          (EMH_FND0NWEDITOR_error_base + 28)
#define FND0NWEDITOR_root_object_missing                 (EMH_FND0NWEDITOR_error_base + 29)
#define FND0NWEDITOR_ShapeXML_handling_failed            (EMH_FND0NWEDITOR_error_base + 30)

/** The action cannot be completed because either the selected object is a stub or it contains a stub.
Please select a valid object and try again. */
#define FND0NWEDITOR_stub_found                          (EMH_FND0NWEDITOR_error_base + 31)

/** An object of the specified type "%1$" could not be created, because it does not exist in the database. Please contact your system administrator to create the type in the Business Modeler IDE. */
#define FND0NWEDITOR_create_failed                       (EMH_FND0NWEDITOR_error_base + 32)

/** The input argument for the SOA operation "createAndPaste" is invalid. Valid values for the operation type argument are "createAndPaste" and "pasteOnly". Please report this error to your system administrator.*/
#define FND0NWEDITOR_invalid_input_args                  (EMH_FND0NWEDITOR_error_base + 33)

/** No objects have been provided for the paste operation. */
#define FND0NWEDITOR_no_input_object_to_paste            (EMH_FND0NWEDITOR_error_base + 34)

/** No target object has been provided for the paste operation. */
#define FND0NWEDITOR_no_target_object_to_paste           (EMH_FND0NWEDITOR_error_base + 35)

/** The paste operation has failed, because the object to paste is of type "%1$". Please select an object of type "Item", and try again. */
#define FND0NWEDITOR_invalid_object_to_paste             (EMH_FND0NWEDITOR_error_base + 36)

/** The input argument for the SOA operation "createConnectionPortsAndConnect" should be a valid BOM Line or GDE Line object from a valid and opened BOM Window. Please report this error to your system administrator.*/
#define FND0NWEDITOR_no_bom_window                       (EMH_FND0NWEDITOR_error_base + 37)

/** The input argument for the SOA operation "createConnectionPortsAndConnect" does not contain valid BOM Lines or GDE Lines, for which parents can be determined.*/
#define FND0NWEDITOR_no_common_min_parent                (EMH_FND0NWEDITOR_error_base + 38)

/** @} */

#endif
