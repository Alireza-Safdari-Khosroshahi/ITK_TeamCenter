/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Validation Contract errors

*/

#ifndef CRT0VALIDATIONCONTRACT_ERRORS_H
#define CRT0VALIDATIONCONTRACT_ERRORS_H

#include <common/emh_const.h>


/**
    @defgroup CRT0VALIDATIONCONTRACT_ERRORS Validation Contract Errors
    @ingroup CRT0VALIDATIONCONTRACT
    @{
*/

#define VC_ERROR_BASE                                               EMH_VC_error_base

/**
   The Analysis Request Package "%1$" is invalid, because either the XML contains a syntax error or it does not confirm to the Analysis Request schema (which can be found in the dataset Crt0ContractPkgSchema). The validation error message is: %2$
*/
#define VC_invalid_contract_package_syntax_or_schema                (VC_ERROR_BASE + 1)

/**
   The Analysis Request Package "%1$" is invalid, because the specified Teamcenter business object "%2$" does not exist.
*/
#define VC_invalid_contract_package_bus_obj                         (VC_ERROR_BASE + 2)

/**
   The Analysis Request Package "%1$" is invalid, because the specified property "%2$" for the Teamcenter business object "%3$" in section "%4$" does not exist.
*/
#define VC_invalid_contract_package_bus_obj_prop                    (VC_ERROR_BASE + 3)

/**
   The following exception has occurred during the initialization of the XML reader for the Analysis Request Package "%1$": %2$
*/
#define VC_error_during_xml_reader_init                             (VC_ERROR_BASE + 4)

/**
   No Analysis Request Package is associated to the Analysis Definition object "%1$".
*/
#define VC_no_contract_package                                      (VC_ERROR_BASE + 5)

/**
   The Analysis Request Package "%1$" is invalid, because the property "%3$" is duplicated in the section "%2$".
*/
#define VC_invalid_contract_package_duplicate_prop                  (VC_ERROR_BASE + 6)

/**
   An Analysis Request Definition with the name "%1$" already exists. Please provide a unique Analysis Request Definition name.
*/
#define VC_duplicated_vcdef_name_error                              ( VC_ERROR_BASE + 7 )

/**
   The license "%1$" for the Analysis Request module is not available. Please contact the system administrator.
*/
#define VC_validate_license_failed                                  ( VC_ERROR_BASE + 8 )

/**
   The Analysis Request Package "%1$" is invalid, because the specified quantity %2$ is invalid for the Teamcenter business object "%3$".
*/
#define VC_invalid_contract_package_quantity                        ( VC_ERROR_BASE + 9 )

/**
   The Analysis Request Package "%1$" is invalid, because the group "%2$" has a duplicate section "%3$".
*/
#define VC_invalid_contract_package_duplicate_section               (VC_ERROR_BASE + 10)

/**
   The object "%1$" cannot be added to the Analysis Request, because it has already been added to it.
*/
#define VC_cannot_add_since_previously_added                        (VC_ERROR_BASE + 11)

/**
   The preference "PLE_DisabledDefnStatusList" does not contain any value. Add a list of release statuses to it.
*/
#define VC_disabled_defn_status_pref_no_values                      (VC_ERROR_BASE + 12)

/**
   The Analysis Request was not created because "%1$" has not been released.
*/
#define VC_cannot_create_since_not_a_usable_definition              (VC_ERROR_BASE + 13)

/*
    The Analysis Request was not created because “%1$” is not of type Analysis Definition.
*/
#define VC_cannot_create_since_wrong_configuration                  (VC_ERROR_BASE + 14)

/**
   The Analysis Request was not created because "%1$" has not been released.
*/
#define VC_cannot_create_since_no_usable_definition_for_rev         (VC_ERROR_BASE + 15)

/**
   The preference "PLE_EnabledDefnStatusList" does not contain any value. Add a list of release statuses to it.
*/
#define VC_enabled_defn_status_pref_no_values                       (VC_ERROR_BASE + 16)

/**
   The value "%2$" for the property "%1$" cannot be changed, because objects have already been added to the Analysis Request.
*/
#define VC_cannot_change_since_already_inuse                        (VC_ERROR_BASE + 17)

/**
   "%1$" cannot be modified in the "%2$" state.
*/
#define VC_modification_not_allowed                                 (VC_ERROR_BASE + 18)

/**
  A Study with name "%1$" cannot be created, because the Analysis Request "%2$" already has a Study with the same name.
*/
#define VC_cannot_create_study_with_same_name                       (VC_ERROR_BASE + 19)

/**
  The name of the Study "%1$" cannot be changed to "%2$", because the Analysis Request "%3$" already contains a Study with that name.
*/
#define VC_cannot_change_study_name                                 (VC_ERROR_BASE + 20)

/**
  Edits to "%1$" were not saved because "%2$" is already used as the Domain Context in another Analysis Request.
*/
#define VC_analysisrequest_duplicate_smb                            (VC_ERROR_BASE + 21)

/**
  The Analysis Request Package "%1$" is invalid because the specified Saved query "%2$" does not exist.
*/
#define VC_invalid_contract_package_saved_query                     (VC_ERROR_BASE + 22)

/**
  The Analysis Request Package "%1$" is invalid because the specified transfer mode "%2$" does not exist.
*/
#define VC_invalid_contract_package_transfer_mode                   (VC_ERROR_BASE + 23)

/**
  The Analysis Request Package "%1$" is invalid because the specified Revision Rule "%2$" does not exist.
*/
#define VC_invalid_contract_package_revision_rule                   (VC_ERROR_BASE + 24)

/**
  The Analysis Request Package "%1$" is invalid because more than one Revision Rule is specified for the recipe.
*/
#define VC_invalid_contract_package_more_revision_rule              (VC_ERROR_BASE + 25)

/**
  The Analysis Request Package "%1$" is invalid because invalid entries are specified for the recipe.
*/
#define VC_invalid_contract_package_invalid_recipe_entries          (VC_ERROR_BASE + 26)

/**
  Verification Request "%1$" not created because the current user does not have correct privileges.
*/
#define VC_create_current_user_invalid_privileges                   (VC_ERROR_BASE + 27)

/**
  Verification Request not created because specified Verification Request name not valid.
*/
#define VC_create_invalid_name                                      (VC_ERROR_BASE + 28)

/**
  Verification Request "%1$" not created because specified Verification Request type not valid.
*/
#define VC_create_invalid_type                                       (VC_ERROR_BASE + 29)

/**
  Verification Request "%1$" not created because specified element not valid.
*/
#define VC_create_invalid_element                                    (VC_ERROR_BASE + 30)

/**
  Verification Request "%1$" not created because specified element context not valid.
*/
#define VC_create_invalid_element_context                            (VC_ERROR_BASE + 31)

/**
  Verification Request "%1$" not created because specified element data not valid.
*/
#define VC_create_invalid_element_data                               (VC_ERROR_BASE + 32)

/**
  Verification Request "%1$" not created because specified Verification Request for revise not valid.
*/
#define VC_create_invalid_vr_for_revise                              (VC_ERROR_BASE + 33)

/**
  Verification Request "%1$" not created because specified parameter copy options not valid.
*/
#define VC_create_invalid_parameter_copy_option                      (VC_ERROR_BASE + 34)

/**
  Verification Request "%1$" not created because specified parameter data not valid.
*/
#define VC_create_invalid_parameter_data                             (VC_ERROR_BASE + 35)

/**
  Verification Request "%1$" not created because specified parameter direction not valid.
*/
#define VC_create_invalid_parameter_direction                        (VC_ERROR_BASE + 36)

/**
  Verification Request "%1$" not created because specified recipe not valid.
*/
#define VC_create_invalid_recipe                                     (VC_ERROR_BASE + 37)

/**
  Verification Request "%1$" not created because specified recipe data not valid.
*/
#define VC_create_invalid_recipe_data                                (VC_ERROR_BASE + 38)

/**
  Verification Request "%1$" not created because specified workflow not valid.
*/
#define VC_create_invalid_workflow                                   (VC_ERROR_BASE + 39)

/**
  Verification Request "%1$" not created because specified parent Verification Request not valid.
*/
#define VC_create_invalid_parent_vr                                  (VC_ERROR_BASE + 40)

/**
  Verification Request "%1$" not created because specified Verification Request Definition not valid.
*/
#define VC_create_invalid_vr_definition                              (VC_ERROR_BASE + 41)

/**
  Verification Request "%1$" not created because specified participant user not valid.
*/
#define VC_create_invalid_participant_user                           (VC_ERROR_BASE + 42)

/**
  Verification Request "%1$" not created because specified participant type not valid.
*/
#define VC_create_invalid_participant_type                           (VC_ERROR_BASE + 43)

/**
  Verification Request "%1$" not created because specified value "%2$" for property "%3$" not valid.
*/
#define VC_create_invalid_value_for_property                         (VC_ERROR_BASE + 44)

/**
  Verification Request "%1$" not created because specified value for "%2$" not valid.
*/
#define VC_create_invalid_input                                      (VC_ERROR_BASE + 45)


/** @} */

#endif
