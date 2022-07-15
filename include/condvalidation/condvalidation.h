/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2013.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This file contains the definition for Condition Validation API

*/

#ifndef TEAMCENTER_CONDVALIDATION_H
#define TEAMCENTER_CONDVALIDATION_H

#include <tcinit/tcinit.h>
#include <condvalidation/libcondvalidation_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    @defgroup CV Condition Validation

Condition Validation is used to verify Teamcenter BOM Structure against validation data objects.
<br>Each validation data object holds a list of conditions defined in BMIDE;
<br>Each condition checks properties on BOM Line, as well as item Revisions of the BOM Lines via Condition enginee.
@{
*/

/**
  CV_evaluationinfo_t holds output for CV_evaluate_bomlines ITK, it contains a pair for provided BOM Line and related
  Condition Validation object for each Condition the BOM Line is checked against.
*/
typedef struct CV_evaluationinfo_s
{
    tag_t                bom_line;                          /**< Tag of the provided BOM Line. */
    tag_t                condition_validation_result;       /**< Tag of condition validation result. */
} CV_evaluationinfo_t;

/**
  CV_bomline_condvalresults_t structure holds output for CV_find_condvalresults ITK, it contains information for provided
  BOM Line, the count of Condition Validation object, as well as list of Condition Validation objects for provided BOM Line.
*/
typedef struct CV_bomline_condvalresults_s
{
    tag_t                 bom_line;                         /**< Tag of the provided BOM Line. */
    int                   count;                            /**< Number of condition validation results. */
    tag_t*                condition_validation_results;     /**< count List of condition validation results. */
} CV_bomline_condvalresults_t;

/**
    Evaluates each part in the specified BOM Lines to check if the part could match conditions contained in the list of validation data objects.
    <br>In case of error on a BOM Line, the function stops and the output results will be empty.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CONDVALIDATION_internal_error             if condition validation internal error has occurred.
    <li>#CONDVALIDATION_fail_ask_apn               if the Absolute Path Node could not be retrieved from the BOM Line.
    <li>#CONDVALIDATION_invalid_instance_creation  if the condition scope does not match.
    <li>Potentially other errors
    </ul>

    @code
       int ifail = CV_evaluate_bomlines( num_bom_lines, bom_lines, agent_revision, n_validation_data, validation_data, &ifail_status, &count, &evaluation_information );
        for( int index=0; index<num_bom_lines; index++)
        {
            if( ifail_status[index] != ITK_ok )
            {
                [...] //Deal with the error
                continue;
            }
        }
        for( int position=0; position<count; position++ )
        {
            [...] //Use the structure "evaluation_information[position]"
        }
    @endcode
*/
extern CONDVALIDATION_API int CV_evaluate_bomlines(
    int                         n_bom_lines,                /**< (I) The number of the provided BOM Lines */
    const tag_t*                bom_lines,                  /**< (I) n_bom_lines The provided BOM Lines */
    tag_t                       agent_revision,             /**< (I) The Validation Agent Revision object */
    int                         n_validation_data,          /**< (I) The number of Validation Data objects */
    tag_t*                      validation_data,            /**< (I) n_validation_data Array of Validation Data object */
    int**                       ifail_status,               /**< (OF) n_bom_lines Status for each of the provided BOM Lines */
    int*                        n_statuses,                 /**< (O) Bucket of results for all provided BOM Lines and children BOM Lines */
    CV_evaluationinfo_t**       evaluation_information      /**< (OF) n_statuses The condition validation status for each of the provided BOM Lines  */
);

/**
    Finds out the corresponding Condition Validation Result objects for all of the sub BOM Lines under the provided BOM Lines.
    <br>In case of error on a BOM Line, the function stops and the output results will be whatever was found for the working BOM Lines.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CONDVALIDATION_fail_ask_apn               if the Appearance Path Node (APN) could not be retrieved for one of the BOM Lines.
    <li>Potentially other errors
    </ul>

    @code
       int ifail = CV_find_condition_validation_results( num_bom_lines, bom_lines, agent_revision, n_validation_data, validation_data, &ifail_status, &count, &condition_validation_results_information );
        for( int index=0; index<num_bom_lines; index++)
        {
            if( ifail_status[index] != ITK_ok )
            {
                [...] //Deal with the error
                continue;
            }
        }
        for( int position=0; position<count; position++ )
        {
            [...] //Use the structure "condition_validation_results_information[position]"
        }
    @endcode
*/
extern CONDVALIDATION_API int CV_find_condition_validation_results(
    int                             n_bom_lines,                               /**< (I) The number of the provided BOM Lines */
    const tag_t*                    bom_lines,                                 /**< (I) n_bom_lines The provided BOM Lines */
    tag_t                           agent_revision,                            /**< (I) The Validation Agent Revision object */
    int                             n_validation_data,                         /**< (I) The number of Validation Data objects  */
    tag_t*                          validation_data,                           /**< (I) n_validation_data Array of Validation Data object */
    int**                           ifail_status,                              /**< (OF) n_bom_lines Status for each of the provided BOM Lines */
    int*                            n_results,                                 /**< (O) Bucket of results for all provided BOM Lines and children BOM Lines */
    CV_bomline_condvalresults_t**   condition_validation_results_information   /**< (OF) n_results The condition validation result for each of the provided BOM Lines */
);


/**
    Updates the condition validation results. It is invoked when user updates Condition object which is linked with Condition Validation Result
    and re-check existing Condition Validation Result against Condition.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CONDVALIDATION_invalid_condition_scope           if the condition signature matches neither the format "(WorkspaceObject r) ", nor the format "(WorkspaceObject r, BOMLine o)"..
    <li>#CONDVALIDATION_empty_overridden_decision_user    if the overridden decision user is empty during the update of the Condition Validation Result object. To be updated, Condition Validation Result objects could contain information for the overridden decision user.
    <li>#CONDVALIDATION_internal_error                    if an internal condition validation error has occurred.
    <li>Potentially other errors
    </ul>
*/
extern CONDVALIDATION_API int CV_update_condition_validation_results(
    int                             n_condition_validation_results,       /**< (I) Number of condition validation results */
    tag_t*                          condition_validation_results          /**< (I) n_condition_validation_results Array of condition validation results */
);
/** @} */

#ifdef __cplusplus
}
#endif

#include <condvalidation/libcondvalidation_undef.h>

#endif
