/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
 
/** 
    @file 
 
    Transformer (IBOM) errors
 
*/

#ifndef TEAMCENTER_XFORMER_ERRORS_H
#define TEAMCENTER_XFORMER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup XFORMER_ERRORS Errors
    @ingroup XFORMER
    @{
*/

#define XFORMER_ERROR_BASE                          EMH_XFORMER_error_base

/**
    An internal error has occurred in the Generic Transformer module. Please contact your system administrator.
*/
#define XFORMER_internal_error                     (EMH_XFORMER_error_base + 1)

/**
    The secondary Traverse Rule is missing or invalid.
 */
#define XFORMER_invalid_secondary_traverse_rule    (EMH_XFORMER_error_base + 2)

/**
    The Traverse Rule contains the following invalid symbol pattern: "%1$".
 */
#define XFORMER_invalid_traverse_rule_syntax       (EMH_XFORMER_error_base + 3)

/**
    The Function Rule contains the following invalid symbol pattern: "%1$".
 */
#define XFORMER_invalid_function_rule_syntax       (EMH_XFORMER_error_base + 4)

/**
    The Transformer Rule function is using invalid arguments. Please check log or syslog to get the context.
 */
#define XFORMER_invalid_function_arg               (EMH_XFORMER_error_base + 5)

/**
    The Transformer Rule function is processing input data using an incorrect type.
 */
#define XFORMER_invalid_function_unit              (EMH_XFORMER_error_base + 6)

/**
    The Transformer Rule function is not declared to use the variable "%1$".
 */
#define XFORMER_symbol_undefined                   (EMH_XFORMER_error_base + 7)

/**
    The Transformer Rule function contains a redeclaration of the variable "%1$".
 */
#define XFORMER_symbol_duplicate_definition        (EMH_XFORMER_error_base + 8)

/**
    The Mapping Rule contains the following invalid symbol pattern: "%1$".
 */
#define XFORMER_invalid_mapping_rule_syntax        (EMH_XFORMER_error_base + 9)

/**
 *  The Class Hierarchy Definition contains the following invalid symbol pattern: "%1$".
 */
#define XFORMER_invalid_class_hierarchy_definition_syntax    \
                                                   (EMH_XFORMER_error_base + 10)

/**
    A parsing error of the Rule file "%1$" has happened at line %2$.
 */
#define XFORMER_invalid_rule_file                  (EMH_XFORMER_error_base + 11)

/**
    An input file must be provided to the transformer.
 */
#define XFORMER_no_input_file                      (EMH_XFORMER_error_base + 12)

/**
    The following output file cannot be opened: %1$.
 */
#define XFORMER_invalid_output_file                (EMH_XFORMER_error_base + 13)

/**
    The following error has happened when parsing the XML file "%1$": %2$
 */
#define XFORMER_xml_parse_error                    (EMH_XFORMER_error_base + 14)

/**
    The Transformer object "%1$" contains several reference IDs.
 */
#define XFORMER_duplicate_id                       (EMH_XFORMER_error_base + 15)

 /**
    The target object graph must contain a single root object.
 */
#define XFORMER_multiple_target_root_elements      (EMH_XFORMER_error_base + 16)

 /**
    The input XML file "%1$" is invalid. Please examine the XML file and correct the invalid place.
 */
#define XFORMER_invalid_xml_file                   (EMH_XFORMER_error_base + 17)

 /**
    The root element in the output XML file is undefined. Use the option "opt_target_root" to define it in the Transformer Rule.
 */
#define XFORMER_target_root_element_undefined      (EMH_XFORMER_error_base + 18)

 /**
    The attribute name/value of the object "%1$" does not match the requirement from the Traverse Rule "%2$".
 */
#define XFORMER_attr_name_value_mismatch           (EMH_XFORMER_error_base + 19)

 /**
    The following string contains an imbalanced quote: "%1$".
 */
#define XFORMER_incomplete_quote_string            (EMH_XFORMER_error_base + 20)

 /**
    The following string contains an invalid escape character: "%1$".
 */
#define XFORMER_invalid_escape                     (EMH_XFORMER_error_base + 21)

 /**
    A comma is missing in the attribute list "%1$".
 */
#define XFORMER_attr_symbol_missing                (EMH_XFORMER_error_base + 22)

 /**
    The attribute list "%1$" contains an empty string as attribute.
 */
#define XFORMER_attr_empty_string                  (EMH_XFORMER_error_base + 23)

 /**
    The class "%1$" contains a circular class hierarchy. 
 */
#define XFORMER_circular_class_hierarchy_definition    \
                                                   (EMH_XFORMER_error_base + 24)

 /**
    The generated or input transformer rule file contains an invalid syntax: "%1$". Either correct the file or contact your system administrator. 
 */
#define XFORMER_invalid_look_up_table              (EMH_XFORMER_error_base + 25)

 /**
    The function "%1$" does not exist in the library "%2$". 
 */
#define XFORMER_invalid_lib_func                   (EMH_XFORMER_error_base + 26)

 /**
    Undefined Object Type "%1$". Either correct the file or contact your system administrator.
 */
#define XFORMER_undefined_object_type              (EMH_XFORMER_error_base + 27) 

 /**
    Fail to build Function Rule "%1$". Either correct the file or contact your system administrator.
 */
#define XFORMER_fail_to_build_funcion_rule_def     (EMH_XFORMER_error_base + 28)

 /**
    Cannot open file "%1$". Either correct the file or contact your system administrator.
 */
#define XFORMER_fail_to_open_file                  (EMH_XFORMER_error_base + 29)

 /**
    Failed in import data validation. Please check log or syslog to get the context or contact your system administrator.
 */
#define XFORMER_false_to_validate_rule             (EMH_XFORMER_error_base + 30)

/**
    An invalid flow control usage is detected for "%1$". Either correct the file or contact your system administrator.
 */
#define XFORMER_invalid_flow                       (EMH_XFORMER_error_base + 31)

/**
    The following error has occurred when evaluating the function rule: %1$. Please check the log or syslog files for more information.
 */
#define XFORMER_user_error                         (EMH_XFORMER_error_base + 32)

/**
    No briefcase add-on license (key: tc_briefcase) is available. Please contact your system administrator.
 */
#define XFORMER_bb_addon_license_error             (EMH_XFORMER_error_base + 33)

 /**
    No Multi-Site license (key: multisite_server) is available. Please contact your system administrator.
 */
#define XFORMER_multisite_license_error            (EMH_XFORMER_error_base + 34)

/**
    @}
*/

#endif
