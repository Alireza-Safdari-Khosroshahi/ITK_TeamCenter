/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa workflow services

*/

/** @if HISTORY_SECTION
====================================================================================================
 Date       Name                    Description of Change
23-Mar-2007  Stan Sharpe            Initial Creation
$HISTORY$
==================================================================================================
@endif */

#ifndef SOAWORKFLOW_ERRORS_H
#define SOAWORKFLOW_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAWORKFLOW_ERRORS TCWS Errors
    @ingroup SOAWORKFLOW
    @{
*/

/** workflow Integration Services error code definitions */

/** NOTE: The error numbers assigned in this file must match those in the soaworkflow_errors.xml file **/

/** Workflow Service (0 - 9) **/

/**
    The Item is not a workspace object.
*/
#define SOAWORKFLOW_not_workspace_object                            (EMH_SOAWORKFLOW_error_base +   0 )

/**
    The tag for the "Date Released" attribute of the "Release Status" object could not be retrieved.
*/
#define SOAWORKFLOW_rs_could_not_get_date_released                  (EMH_SOAWORKFLOW_error_base +   1 )

/**
    The tag for the "Date Released" attribute of the "Workspace Object" object could not be retrieved.
*/
#define SOAWORKFLOW_wo_could_not_get_date_released                  (EMH_SOAWORKFLOW_error_base +   2 )

/**
    The tag for the "Released Status List" attribute of the "Workspace Object" object could not be retrieved.
*/
#define SOAWORKFLOW_wo_could_not_get_release_status_list            (EMH_SOAWORKFLOW_error_base +   3 )

/**
    The required object is not provided.
*/
#define SOAWORKFLOW_NULLTAG                                         (EMH_SOAWORKFLOW_error_base +   4 )

/**
    The responsible party is not provided.
*/
#define SOAWORKFLOW_NULL_RESPONSIBLE_PARTY                          (EMH_SOAWORKFLOW_error_base +   5 )

/**
    An invalid signoff attachment is provided for the given task.
*/
#define SOAWORKFLOW_INVALID_ATTACHMENT                              (EMH_SOAWORKFLOW_error_base +   6 )

/**
    The task is invalid.
*/
#define SOAWORKFLOW_INVALID_TASK                                    (EMH_SOAWORKFLOW_error_base +   7 )

/**
    The signoff action is invalid.
*/
#define SOAWORKFLOW_INVALID_SIGNOFF_ACTION                          (EMH_SOAWORKFLOW_error_base +   8 )

/**
    The signoff origin type is invalid.
*/
#define SOAWORKFLOW_INVALID_ORIGIN_TYPE                             (EMH_SOAWORKFLOW_error_base +   9 )

/**
    An internal error has occurred.
*/
#define SOAWORKFLOW_INTERNAL_ERROR                                  (EMH_SOAWORKFLOW_error_base +   10 )

/**
    The signoff profile cannot be set for a notify task.
*/
#define SOAWORKFLOW_NOTIFY_PROFILE                                  (EMH_SOAWORKFLOW_error_base +   11 )

/**
    The signoff member is invalid.
*/
#define SOAWORKFLOW_INVALID_SIGNOFF_MEMBER                          (EMH_SOAWORKFLOW_error_base +   12 )

/**
    The signoff is not provided.
*/
#define SOAWORKFLOW_NULL_SIGNOFF_OBJECT                             (EMH_SOAWORKFLOW_error_base +   13 )

/**
    An incorrect password is provided for the secure task.
*/
#define SOAWORKFLOW_INCORRECT_PASS_FOR_SECURE_TASK                  (EMH_SOAWORKFLOW_error_base +   14 )

/**
    The creation of workflow process has failed.
*/
#define SOAWORKFLOW_CREATE_PROCESS                                  (EMH_SOAWORKFLOW_error_base +   15 )

/**
    The process assignment list could not be assigned.
*/
#define SOAWORKFLOW_ASSIGN_ASSIGNMENTLIST                           (EMH_SOAWORKFLOW_error_base +   16 )

/**
    Applying the template changes to the active processes has failed.
*/
#define SOAWORKFLOW_APPLY_TEMPLATE_CHANGES                          (EMH_SOAWORKFLOW_error_base +   17 )

/**
    The workflow templates could not be found. Please contact your system administrator.
*/
#define SOAWORKFLOW_ERROR_QUERY_TEMPLATES                           (EMH_SOAWORKFLOW_error_base +   18 )

/**
    The target resource "%1$" cannot be the same as the user.
*/
#define SOAWORKFLOW_OOO_USER_ERROR                                  (EMH_SOAWORKFLOW_error_base +   19 )

/**
    The user "%1$" is out of the office between the dates "%2$" and "%3$". Please select another user for these dates.
*/
#define SOAWORKFLOW_DELEGATEE_OOO_ERROR                             (EMH_SOAWORKFLOW_error_base +   20 )

/**
    The start date "%1$" cannot be earlier than the current date. Please set the start date again.
*/
#define SOAWORKFLOW_OOO_STARTDATE_ERROR                             (EMH_SOAWORKFLOW_error_base +   21 )

/**
    The start date "%1$" cannot be later than the end date "%2$". Please set the start date again.
*/
#define SOAWORKFLOW_OOO_STARTDATE_ENDDATE_ERROR                     (EMH_SOAWORKFLOW_error_base +   22 )

/**
    The end date "%1$" cannot be earlier than the current date. Please set the end date again.
*/
#define SOAWORKFLOW_OOO_ENDDATE_ERROR                               (EMH_SOAWORKFLOW_error_base +   23 )

/**
    The operation to set the surrogate has failed for the user "%1$", with surrogate value "%2$", start date "%3$", and end date "%4$".
*/
#define SOAWORKFLOW_SET_SURROGATE_ERROR                             (EMH_SOAWORKFLOW_error_base +   24 )


/**
   The transfer of check-out has failed for the following target objects: %1$.
*/
#define SOAWORKFLOW_ERROR_TRANSFER_OF_CHECKOUTS                     (EMH_SOAWORKFLOW_error_base +   25 )

/**
   An error has occurred while setting the values for the property "%1$" on the object "%2$".
*/
#define SOAWORKFLOW_SET_PROPERTY_VALUES_ERROR                       (EMH_SOAWORKFLOW_error_base +   26 )

/**
    The user "%1$" is out of the office starting %2$. Please select another user for these dates.
*/
#define SOAWORKFLOW_DELEGATEE_OOO_NO_ENDDATE_ERROR                  (EMH_SOAWORKFLOW_error_base +   27 )

/**
    "%1$" was not added because duplicates are not allowed.
*/
#define SOAWORKFLOW_duplicate_reviewers_error                       (EMH_SOAWORKFLOW_error_base +   28 )

/**
    %1$ out of %2$ users were not added because duplicates are not allowed.
*/
#define SOAWORKFLOW_duplicate_reviewers_count_error                 (EMH_SOAWORKFLOW_error_base +   29 )

/**
    "%1$" was not added
*/
#define SOAWORKFLOW_duplicate_reviewer_name_error                   (EMH_SOAWORKFLOW_error_base +   30 ) 

/**
    Please specify either the update or the copy operation for updating or copying the Process Assignment List "%1$".
*/
#define SOAWORKFLOW_incorrect_operation_error                       (EMH_SOAWORKFLOW_error_base +   31 ) 

/** @} */


#endif

