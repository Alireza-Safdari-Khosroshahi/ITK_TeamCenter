/* Copyright 2020 Siemens Digital Industries Software
#===============================================================================
# Copyright 2019.
# Siemens Product Lifecycle Management Software Inc.
# All Rights Reserved.
#===============================================================================
# Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file
    EBM0ENTERPRISEBOM Master Error Codes Declaration
*/

#ifndef PMA0AUTOMATIONERRORS_H
#define PMA0AUTOMATIONERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EBMENT_ERRORS Errors
    @ingroup EBMENT
    @{
*/

/**
An internal error has occurred in Product Master Automation. Report this error to your system administrator.
*/
#define PMA0AUTOMATION_internal_error                                               (EMH_PMA0AUTOMATION_error_base + 1)

/**
"%1$" is not a valid option. Please refer to the help for correct usage.
*/
#define PMA0AUTOMATION_invalid_option                                               (EMH_PMA0AUTOMATION_error_base + 2)

/**
The value "%2$" is not valid for the option "%1$". Please refer to the help for correct usage.
*/
#define PMA0AUTOMATION_invalid_option_value                                         (EMH_PMA0AUTOMATION_error_base + 3)

/**
The mandatory option "%1$" is missing. Please refer to the help for correct usage.
*/
#define PMA0AUTOMATION_missing_option                                               (EMH_PMA0AUTOMATION_error_base + 4)

/**
The storage type of property "%1$" is not supported by skip nodes configuration preference Pma0_skip_node_conditions. Supported data types are String, Boolean. Please refer to the preference description.
*/
#define PMA0AUTOMATION_invalid_prop_type                                            (EMH_PMA0AUTOMATION_error_base + 5)

/**
The input BOM sources does not have a common parent. Please provide BOM sources having a common parent.
*/
#define PMA0AUTOMATION_no_common_parent                                             (EMH_PMA0AUTOMATION_error_base + 6)

/**
Provide a valid BOM target.
*/
#define PMA0AUTOMATION_no_ebom_target                                               (EMH_PMA0AUTOMATION_error_base + 7)

/**
The BOM structure cannot be generated for the input "%1$" because it is configured to be skipped using the preference "%2$" and it does not contain any unskipped parent.
*/
#define PMA0AUTOMATION_input_root_skipped                                           (EMH_PMA0AUTOMATION_error_base + 8)

/**
The creation of workflow process has failed because no attachment of Design type can be found.
*/
#define PMA0AUTOMATION_attachment_not_found                                         (EMH_PMA0AUTOMATION_error_base + 9)

/**
The target object for source object "%1$" was not created because it is not a valid type. The supported types are Part or Design.
*/
#define PMA0AUTOMATION_invalid_part_or_design                                       (EMH_PMA0AUTOMATION_error_base + 10)

/**
This action was not performed as "%1$" is not a valid Part or Design type.
*/
#define PMA0AUTOMATION_invalid_source_selection                                     (EMH_PMA0AUTOMATION_error_base + 11)

/**
The creation of workflow process has failed because the selected object is not of type Part or Design.
*/
#define PMA0AUTOMATION_invalid_target_object_type                                   (EMH_PMA0AUTOMATION_error_base + 12)

/**
"%1$" is not a valid action.
*/
#define PMA0AUTOMATION_invalid_update_action                                        (EMH_PMA0AUTOMATION_error_base + 13)

/**
The BOM structure cannot be generated under the selected target BOM "%1$" because it is configured to be skipped as specified in the preference "%2$".
*/
#define PMA0AUTOMATION_target_node_skipped                                          (EMH_PMA0AUTOMATION_error_base + 14)

/**
%1$ elements could not be processed. A detailed report "%2$" can be found in the "Newstuff" folder.
*/
#define PMA0AUTOMATION_nodes_not_processed                                          (EMH_PMA0AUTOMATION_error_base + 15)

/**
The BOM Line with Item "%1$" does not have a valid configured Item Revision.
*/
#define PMA0AUTOMATION_no_item_rev                                                  (EMH_PMA0AUTOMATION_error_base + 16)

/**
User Exit execution is skipped. The OOTB implementation must be executed.
*/
# define PMA0AUTOMATION_user_exit_skip_execution                                    (EMH_PMA0AUTOMATION_error_base + 17)

/**
The Clone Part Structure operation has failed during the validation. Please check the Teamcenter server syslog file for more information.
*/
#define PMA0AUTOMATION_part_duplicate_validation_failed                             (EMH_PMA0AUTOMATION_error_base + 101)

/**
The Clone Part Structure operation was completed with partial errors. Please check the Teamcenter server syslog file for more information. The cloned structure will need to be opened, and the levels of the structure that had errors will need to be corrected manually.
*/
# define PMA0AUTOMATION_part_clone_partial_failure                                  (EMH_PMA0AUTOMATION_error_base + 102)

/**
The Clone Part Structure operation has failed. Please check the Teamcenter server syslog file for more information.
*/
# define PMA0AUTOMATION_part_clone_failure                                          (EMH_PMA0AUTOMATION_error_base + 103)

/**
The Clone Design Structure operation has failed during the validation. Please check the Teamcenter server syslog file for more information.
*/
#define PMA0AUTOMATION_design_duplicate_validation_failed                           (EMH_PMA0AUTOMATION_error_base + 104)

/**
The Clone Design Structure operation was completed with partial errors. Please check the Teamcenter server syslog file for more information. The cloned structure will need to be opened, and the levels of the structure that had errors will need to be corrected manually.
*/
# define PMA0AUTOMATION_design_clone_partial_failure                                (EMH_PMA0AUTOMATION_error_base + 105)

/**
The Clone Design Structure operation has failed. Please check the Teamcenter server syslog file for more information.
*/
# define PMA0AUTOMATION_design_clone_failure                                        (EMH_PMA0AUTOMATION_error_base + 106)

/**
Part and Design structures are cloned with partial errors during the Alignment. The cloned structures will need to be opened, and the levels of the structure that had errors will need to be Aligned manually.
*/
# define PMA0AUTOMATION_cloned_structures_partially_aligned                         (EMH_PMA0AUTOMATION_error_base + 107)

/**
Part and Design structures are cloned but the structures are not Aligned. The cloned structures will need to be opened, and the levels of the structure need to be Aligned manually.
*/
# define PMA0AUTOMATION_cloned_structures_not_aligned                               (EMH_PMA0AUTOMATION_error_base + 108)

/** @} */
#endif
