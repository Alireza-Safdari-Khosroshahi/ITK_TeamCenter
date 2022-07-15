/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa query services


*/

/** @if HISTORY_SECTION
====================================================================================================
27-Sep-2006  Ashok C                 Error codes for soaquery
$HISTORY$
==================================================================================================
@endif */

#ifndef SOAQUERY_ERRORS_H
#define SOAQUERY_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAQUERY_ERRORS TCWS Errors
    @ingroup SOAQUERY
    @{
*/

/** CAD Integration Services error code definitions */

/** NOTE: The error numbers assigned in this file must match those in the soaquery_errors.xml file
          EMH_SOAQUERY_error_base == 217000 **/

/** saveQueryCriterias */

/** Invalid Query Criteria definition : Search Name not specified. */
#define SOAQUERY_Search_Name_not_specified                  (EMH_SOAQUERY_error_base +   0 )
/** Invalid Query Criteria definition : Mismatch of keys and values size. */
#define SOAQUERY_Keys_Value_not_specified                   (EMH_SOAQUERY_error_base +   1 )
/** Invalid Query Criteria definition : keys and, or values not specified. */
#define SOAQUERY_Mismatch_of_keys_values_size               (EMH_SOAQUERY_error_base +   2 )
/** No valid Query Criteria to reorder, after removing invalid Names from the reorder list. */
#define SOAQUERY_No_valid_qc_to_save                        (EMH_SOAQUERY_error_base +   3 )
/** The input list of Query Criterias has different number of entries from the MySavedSearches list. */
#define SOAQUERY_reorder_size_mismatch                      (EMH_SOAQUERY_error_base +   4 )
/** MySavedSearches list is empty. */
#define SOAQUERY_MySavedSearches_empty                      (EMH_SOAQUERY_error_base +   5 )
/** Invalid input vector size. */
#define SOAQUERY_Invalid_input_vector_size                  (EMH_SOAQUERY_error_base +   6 )
/** Input argument not specified. */
#define SOAQUERY_Input_argument_not_specified               (EMH_SOAQUERY_error_base +   7 )
/** %1$ - SavedQueryCriteria does not exist in MySavedSearches list. */
#define SOAQUERY_SQC_not_found_in_mysavedsearches           (EMH_SOAQUERY_error_base +   8 )
/** %1$ - SavedQueryCriteria is missing from the input list. */
#define SOAQUERY_SQC_not_found_in_input_list                (EMH_SOAQUERY_error_base +   9 )
/** Save failed for : %1$. */
#define SOAQUERY_Save_failed_for                            (EMH_SOAQUERY_error_base +   10 )
/** Delete failed for : %1$. */
#define SOAQUERY_Delete_failed_for                          (EMH_SOAQUERY_error_base +   11 )
/** Retrieve failed for : %1$. */
#define SOAQUERY_Retrieve_failed_for                        (EMH_SOAQUERY_error_base +   12 )
/** Unsupported query type. */
#define SOAQUERY_Unsupported_Query_Type                     (EMH_SOAQUERY_error_base +   13 )
/** Find objects by class and attributes failed for : %1$. */
#define SOAQUERY_failed_find_objects                        (EMH_SOAQUERY_error_base +   14 )
/** The saved Search cannot be deleted based on the name: multiple saved Searches were found for the given name. */
#define SOAQUERY_multiple_savedsearch_found_for_given_name  (EMH_SOAQUERY_error_base +   15 )
/** The search provider name "%1$" is invalid, because no business object exists with this search provider name. */
#define SOAQUERY_invalid_search_provider_name               (EMH_SOAQUERY_error_base +   16 )
/** The search has failed to perform. */
#define SOAQUERY_perform_search_failed                      (EMH_SOAQUERY_error_base +   17 )
/** An invalid object is passed in the parameter "groupedObjectsMapList". Please report this error to your system administrator. */
#define SOAQUERY_invalid_object_in_grouped_objects_map_list (EMH_SOAQUERY_error_base +   18 )

/** @} */


#endif

