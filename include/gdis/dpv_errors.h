/*==============================================================================
                Copyright (c) 2008 Seimenes UGS PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the error codes for the DPV module
*/

/*  */

#ifndef DPV_ERRORS_H
#define DPV_ERRORS_H

#include <common/emh_const.h>
#include <gdis/libgdis_exports.h>

/**
    @defgroup DPV_ERRORS DPV Errors
    @ingroup DPV
    @{
*/

/**
    The target database for the given plant is not defined. Check DPV_DB_LOCATOR and DPV_LINK_LOCATOR.
*/
#define DPV_plant_not_defined                                        (EMH_DPV_error_base + 1)
/**
    The primary key constraint is violated. Please check if there is any duplicate row.
*/
#define DPV_duplicate_row_encountered                                (EMH_DPV_error_base + 111)
/**
    The Dimensional Planning and Validation module has detected an internal error: the DPV_ai_token table does not exist in the database. 
    Please contact your site administrator to create this table by following the Technical Documentation information in 
    the chapter &quot;Define Measurement Tables&quot;.
*/
#define DPV_table_not_exist                                          (EMH_DPV_error_base + 112)
/**
    The Unique Identifier of the Plant is not available in the "DPV_DB_LOCATOR" table.
    Please contact your site administrator to create this table by following the Technical Documentation information in the chapter &quot;Define Measurement Tables&quot;.
*/
#define DPV_plant_uid_not_available                                  (EMH_DPV_error_base + 113)
/**
    The Validation Status is "failed", because the Excel validations on the provided Routine object have failed.
    Please run the static validations on that object to see the exact errors.
*/
#define DPV_excel_validation_not_met                                 (EMH_DPV_error_base + 114)
/**
    Either the provided object type "%1$" is invalid, or the query has not found any object of this type.
*/
#define DPV_object_type_not_exist                                    (EMH_DPV_error_base + 115)

/**
    The Item ID could not be retrieved for the object type "%1$". This type might be invalid.
*/
#define DPV_item_id_is_null                                          (EMH_DPV_error_base + 116)

/**
    No Excel dataset could be found under the given operation/routine "%1$".
*/
#define DPV_excel_dataset_not_found                                  (EMH_DPV_error_base + 117)

/**
    The Specification sheets are not available in the Excel sheet "%1$".
*/
#define DPV_specification_sheets_not_available                       (EMH_DPV_error_base + 118)

/**
    The provided plant ID "%1$" does not exist in the Teamcenter database.
    Please contact your site administrator for the list of valid plant IDs.
*/
#define DPV_id_does_not_exist                                        (EMH_DPV_error_base + 119)

/**
    The provided routine ID "%1$" could not be found under the plant ID "%2$".
*/
#define DPV_routine_id_not_found_under_plant                         (EMH_DPV_error_base + 120)

/**
    The provided routine revision ID "%1$" could not be found under the plant ID "%2$".
*/
#define DPV_revision_id_not_found_under_routine                      (EMH_DPV_error_base + 121)

/**
    The provided specification sheet "%1$" could not be found under the Excel sheet "%2$".
*/
#define DPV_specification_sheet_not_found                            (EMH_DPV_error_base + 122)

/**
    The Feature attribute code "%1$" could not found in the given Specification sheet "%2$".
*/
#define DPV_feature_attribute_code_not_found                         (EMH_DPV_error_base + 123)

/**
    No data could be found for the provided search criteria. Please refine the search criteria.
*/
#define DPV_data_not_found                                           (EMH_DPV_error_base + 124)

/**
    No data could be found for the provided feature attribute codes "%1$". Please refine the search criteria.
*/
#define DPV_data_not_found_for_feature_attr_codes                    (EMH_DPV_error_base + 125)

/**
    The Excel file "%1$" cannot be found.
*/
#define DPV_excel_file_not_found                                     (EMH_DPV_error_base + 126)

/**
    The creation of the XML file has failed due to errors while parsing the Excel file "%1$".
*/
#define DPV_updated_xml_file_not_prepared                            (EMH_DPV_error_base + 127)

/**
    The provided Routine Revision is invalid.
*/
#define DPV_nulltag_or_invalid_tag                                   (EMH_DPV_error_base + 128)

/** @} */

#include <gdis/libgdis_undef.h>
#endif
