/* Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software */

/*====================================================================================================
File description:

    Filename: contmgmts1000d40.h
    Module  : Contmgmts100d40
    Description: Contmgmts100d40 error codes
====================================================================================================*/


#ifndef BREXCHECK_ERRORS_H
#define BREXCHECK_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup BREX_CHECK_ERRORS Content Management Base Errors
    @ingroup CONTMGMTBASE
    @{
*/

#define CONTMGMTS1000D40_ERROR_BASE                                                         EMH_CONTMGMTS1000D_error_base + 100

/**
    An error has occurred in the Content Management S1000D40 module. Please contact your administrator.
*/
#define CONTMGMTS1000D40_general_error                                                      (CONTMGMTS1000D40_ERROR_BASE + 0)

/**
    An error has occurred while validating the BREX rule &quot;%1$&quot;.
*/
#define CONTMGMTS1000D40_rule_validation_error                                              (CONTMGMTS1000D40_ERROR_BASE + 1)

/**
    Parsing the S1000D version 4.0/4.1 BREX rules has failed. Make sure &quot;%1$&quot; is a valid BREX XML file.
*/
#define CONTMGMTS1000D40_v4bdm_rule_processor_error                                         (CONTMGMTS1000D40_ERROR_BASE + 2)

/**
    Parsing the S1000D version 3.0 BREX rules has failed. Make sure &quot;%1$&quot; is a valid BREX XML file.
*/
#define CONTMGMTS1000D40_v3bdm_rule_processor_error                                         (CONTMGMTS1000D40_ERROR_BASE + 3)

/**
    An unexpected exception has occurred while validating the BREX rule: &quot;%1$&quot;. Please correct the rule in the BREX XML file.
*/
#define CONTMGMTS1000D40_rule_xpath_evaluation_error                                        (CONTMGMTS1000D40_ERROR_BASE + 4)

/**
    Parsing the BREX Data Module file &quot;%1$&quot; has failed. Make sure it is a valid BREX XML file.
*/
#define CONTMGMTS1000D40_brexdm_processor_error                                             (CONTMGMTS1000D40_ERROR_BASE + 5)

/**
    Evaluating the XPath &quot;%1$&quot; has failed. Please correct the XPath in the BREX XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_xpath_get_error                                                    (CONTMGMTS1000D40_ERROR_BASE + 6)

/**
    The BREX data module &quot;%1$&quot; cannot be found in the database. Please import this data module into Content Management.
*/
#define CONTMGMTS1000D40_brexdmc_path_error                                                 (CONTMGMTS1000D40_ERROR_BASE + 7)

/**
    The range value &quot;%1$&quot; could not be parsed into multiple tokens. Please correct this range value in the BREX XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_v4bdm_split_allowedvalue_error                                     (CONTMGMTS1000D40_ERROR_BASE + 8)

/**
    The starting range value &quot;%1$&quot; in token &quot;%2$&quot; is invalid. Please correct this range value in the BREX XML file &quot;%3$&quot;.
*/
#define CONTMGMTS1000D40_v4bdm_missing_allowedvalue_startrange                              (CONTMGMTS1000D40_ERROR_BASE + 9)

/**
    The ending range value &quot;%1$&quot; in token &quot;%2$&quot; is invalid. Please correct this range value in the BREX XML file &quot;%3$&quot;.
*/
#define CONTMGMTS1000D40_v4bdm_missing_allowedvalue_endrange                                (CONTMGMTS1000D40_ERROR_BASE + 10)

/**
    The XPath query &quot;%1$&quot; failed to find an object path. Please correct the XPath in the BREX XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_v4bdm_missing_objectpath                                           (CONTMGMTS1000D40_ERROR_BASE + 11)

/**
    The object rule element &quot;%1$&quot; does not contain the token &quot;%2$&quot;. Please correct the BREX XML file &quot;%3$&quot;.
*/
#define CONTMGMTS1000D40_v3bdm_missing_objectpath                                           (CONTMGMTS1000D40_ERROR_BASE + 12)

/**
    The rule &quot;%1$&quot; was omitted but is valid for schema &quot;%2$&quot;. Please correct the BREX XML file &quot;%3$&quot;.
*/
#define CONTMGMTS1000D40_rule_schema_omitted                                                (CONTMGMTS1000D40_ERROR_BASE + 13)

/**
    Could not find the BREX reference for data module &quot;%1$&quot;. Please correct the BREX reference in the data module &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_reference_extract_error                                            (CONTMGMTS1000D40_ERROR_BASE + 14)

/**
    The data module &quot;%1$&quot; cannot be found in the database. Please import this data module into Content Management.
*/
#define CONTMGMTS1000D40_invalid_datamodule_file                                             (CONTMGMTS1000D40_ERROR_BASE + 15)

/**
    The range value &quot;%1$&quot; is not in the format (text prefix + number). Please correct the range in the BREX XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_invalid_naming_range                                                (CONTMGMTS1000D40_ERROR_BASE + 16)

/**
    The input file ticket is empty.
*/
#define CONTMGMTS1000D40_missing_file                                                        (CONTMGMTS1000D40_ERROR_BASE + 17)

/**
    The input type is invalid. The type must be either 'DMRL' or 'SNS'.
*/
#define CONTMGMTS1000D40_invalid_file_type                                                   (CONTMGMTS1000D40_ERROR_BASE + 18)

/**
    The line &quot;%1$&quot; is invalid. Please correct the input data module parameters on this line in the file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_invalid_csv_data                                                    (CONTMGMTS1000D40_ERROR_BASE + 19)

/**
    The line &quot;%1$&quot; is invalid. Please correct the input elements. &quot;%2$&quot; elements were expected and &quot;%3$&quot; elements were found in the file &quot;%4$&quot;.
*/
#define CONTMGMTS1000D40_invalid_csv_data_elements                                           (CONTMGMTS1000D40_ERROR_BASE + 20)

/**
    The regular expression &quot;%1$&quot; is invalid. Please correct the regular expression in the BREX XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_invalid_regular_expression                                           (CONTMGMTS1000D40_ERROR_BASE + 21)

/**
    The BREX XML file is invalid. Please correct the BREX XML file &quot;%1$&quot;.
*/
#define CONTMGMTS1000D40_invalid_xml                                                          (CONTMGMTS1000D40_ERROR_BASE + 22)

/**
    The BREX XML file contains an unknown element &quot;%1$&quot;. Please correct the BREX XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_invalid_xml_element                                                  (CONTMGMTS1000D40_ERROR_BASE + 23)

/**
    Unable to create a Standard Numbering System object for element &quot;%1$&quot;. Please correct the input XML file &quot;%2$&quot;.
*/
#define CONTMGMTS1000D40_create_failed                                                        (CONTMGMTS1000D40_ERROR_BASE + 24)

/**
    No relation could be created between the object &quot;%1$&quot; to the object &quot;%2$&quot;.  Please verify that the relationship is valid and that the access permissions are correct.
*/
#define CONTMGMTS1000D40_paste_failed                                                         (CONTMGMTS1000D40_ERROR_BASE + 25)

/**
    A Business Object of an invalid type is passed in. The object must be a Data Module List object.
*/
#define CONTMGMTS1000D40_bad_input                                                            (CONTMGMTS1000D40_ERROR_BASE + 26)
  
/**
    The creation of the Data Dispatch Note has failed. Please contact your administrator.
*/
#define CONTMGMTS1000D40_topic_create_failed                                                  (CONTMGMTS1000D40_ERROR_BASE + 27)

/**
    The language &quot;%1$&quot; cannot be found.
*/
#define CONTMGMTS1000D40_find_language_error                                                  (CONTMGMTS1000D40_ERROR_BASE + 28)

/**
    A valid BREX reference was not found in the file &quot;%1$&quot;. Please edit the data module's XML file and add a valid BREX reference.
*/
#define CONTMGMTS1000D40_brex_ref_not_found                                                   (CONTMGMTS1000D40_ERROR_BASE + 29)

/**
    The BREX validation has failed for the file &quot;%1$&quot;. Refer to the BREX validation log for more details.
*/
#define CONTMGMTS1000D40_brex_validation_failed                                               (CONTMGMTS1000D40_ERROR_BASE + 30)


/** @} */

#endif
