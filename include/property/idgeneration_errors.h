/*Copyright 2020 Siemens Digital Industries Software
 =================================================================================================
 Copyright 2013.
  Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 =================================================================================================
 Copyright 2020 Siemens Digital Industries Software
 
==================================================================================================/

File description:
   This file contains the published identifiers of error codes that can be
    generated by this module. Obtaining and using the numeric values of these
    manifest constants is not supported. We reserve the right to change the
    actual values as necessary.

    Filename: idgeneration_errors.h
    Module  : property
==================================================================================================*/

#ifndef IDGENERATIONRULEATTACH_ERRORS_H
#define IDGENERATIONRULEATTACH_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup IDGENERATION_ERROR ID Generation Rule, ID Generation Rule Attachment and Concatenation Rule objects messages
    @{
*/

#define IDGENERATION_ERROR_BASE                                 EMH_IDGENERATION_ERROR_BASE

/**
 * An error has occurred while creating the ID Generation Rule Attachment object "%1$" or setting values on its attributes. As a consequence, the object is not created. Please check the Teamcenter server syslog file, and contact your system administrator.
 */
#define IDGENERATION_RULE_ATTACH_initialize_failed                     (IDGENERATION_ERROR_BASE + 1)

/**
 * An error has occurred while creating the Concatenation Rule object "%1$" or setting values on its attributes. As a consequence, the object is not created. Please check the Teamcenter server syslog file, and contact your system administrator.
 */
#define CONCATENATION_RULE_initialize_failed                           (IDGENERATION_ERROR_BASE + 2)

/**
 * A Concatenation Rule with the name "%1$" already exists. Either use a different name, or delete the existing Concatenation Rule from the original model.
 */
#define CONCATENATION_RULE_duplicate_rule                              (IDGENERATION_ERROR_BASE + 3)

/**
 * An error has occurred while creating the ID Generation Rule object "%1$" or setting values on its attributes. As a consequence, the object is not created. Please check the Teamcenter server syslog file, and contact your system administrator.
 */
#define IDGENERATION_RULE_initialize_failed                            (IDGENERATION_ERROR_BASE + 4)

/**
 * The Concatenation Rule "%1$" cannot be validated, because no Naming Rule is associated to it. Please assign a Naming Rule.
 */
#define CONCATENATION_RULE_cannot_be_validated                         (IDGENERATION_ERROR_BASE + 5)

/**
 * The ID Generation Rule object cannot be validated as none of the Concatenation Rules associated with this ID Generation Rule has Naming Rule.
 */
#define IDGENERATION_RULE_cannot_be_validated                          (IDGENERATION_ERROR_BASE + 6)

/**
 * The ID Generator Type "%1$" is either null or not a valid subtype of Fnd0BaseIdGenerator object.
 */
#define IDGENERATOR_TYPE_not_valid                                     (IDGENERATION_ERROR_BASE + 7)

/**
 * ID Generation Rule "%1$" attached to the selected Item type is unable to generate an ID due to insufficient data provided by the user during item creation.
 */
#define IDGENERATION_RULE_data_insufficient_to_evaluate                (IDGENERATION_ERROR_BASE + 8)

/**
 * The Expression associated with the Concatenation Rule "%1$" is not valid. Please provide a valid pattern.
 */
#define CONCATENATION_RULE_expression_not_valid                        (IDGENERATION_ERROR_BASE + 9)

/**
 * The auto-assignment cannot generate an ID, because an ID Generation Rule has been configured on the property "%1$". Please contact your system administrator.
 */
#define IDGENERATION_RULE_ATTACH_no_autogen                            (IDGENERATION_ERROR_BASE + 10)

/**
 * The ID Generation Rule "%1$" attached to the Item type "%2$" is unable to generate an ID, because insufficient data has been provided during the Item creation.
 */
#define IDGENERATION_RULE_data_insufficient_to_evaluate_for_type       (IDGENERATION_ERROR_BASE + 11)
 
/** @} */

#endif

