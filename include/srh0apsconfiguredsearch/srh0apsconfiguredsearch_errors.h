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

    Advanced PLM Services Configured Search Error Codes Declaration
*/

#ifndef SRH0APSCONFIGUREDSEARCH_ERRORS_H
#define SRH0APSCONFIGUREDSEARCH_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SRH0APSCONFIGUREDSEARCH_ERRORS Advanced PLM Services Configured Search Errors
    @ingroup SRH0APSCONFIGUREDSEARCH
    @{
*/

#define EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE                                                 EMH_SRH0APSCONFIGUREDSEARCH_error_base

/**
 * An internal error has occurred in the Advanced PLM Services Configured Search (srh0apsconfiguredsearch) module: %1$. Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_internal_error                                               ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 1 )

/**
 * The requested functionality "%1$" is not yet implemented.
 */
#define SRH0APSCONFIGUREDSEARCH_functionality_not_implemented                                ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 2 )

/**
 * The definition of the search result column at index %1$ is invalid for search definitions of type "%2$".
 */
#define SRH0APSCONFIGUREDSEARCH_invalid_search_result_column                                 ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 3 )

/**
 * The sort attribute "%1$" for search results is not formatted properly. It should be formatted as follows: "className.attributeName" or "className.attributeName.columnIndex".
 */
#define SRH0APSCONFIGUREDSEARCH_improper_format_for_sort_attribute                           ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 4 )

/**
 * The provided search criterion "%1$" is invalid. Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_invalid_search_criterion                                     ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 5 )

/**
 * The provided search criterion "%1$" of type "%2$" is not used in the root search definition "%3$". Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_unused_search_criterion                                      ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 6 )

/**
 * The provided root search criterion "%1$" is empty. Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_empty_root_search_criterion                                  ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 7 )

/**
 * The provided search criterion "%1$" is empty. Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_empty_search_criterion                                       ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 8 )

/**
 * No constructor is defined for the provided search criterion "%1$". Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_constructor_not_found                                        ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 9 )

/**
 * The provided table layout is invalid, because the number of datatypes and "%1$" is different for the Search criterion "%2$". Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_invalid_table_layout                                         ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 10 )

/**
 * The search argument "%1$" is mandatory and is not found in the input. Please report this error to your system administrator.
 */
#define SRH0APSCONFIGUREDSEARCH_missing_search_argument                                      ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 11 )

/**
 * The object "%1$" of type "%2$" does not have a searchable behavior.
 */
#define SRH0APSCONFIGUREDSEARCH_object_is_not_searchable                                     ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 12 )

/**
 * Saved Query has an invalid class.
 */
#define SRH0APSCONFIGUREDSEARCH_invalid_saved_query_in_search                                ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 13 )

/**
 * The revision rule "%1$" does not have any valid clause
 */
#define SRH0APSCONFIGUREDSEARCH_no_valid_clause_in_revision_rule                             ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 14 )

/**
 * The revision rule "%1$" contains an invalid clause "%2$" 
 * for configuring major revisions in Model Context.
 */
#define SRH0APSCONFIGUREDSEARCH_invalid_revision_rule_clause                                 ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 15 )

/** 
 * The Search type "%1$" cannot be found.
 */
#define SRH0APSCONFIGUREDSEARCH_invalid_search_type                                          ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 16 )

/**
 * The configuration filter cannot be applied on the column "%1$", because it is not of type "tag".
 */
#define SRH0APSCONFIGUREDSEARCH_column_type_not_supported                                    ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 17 )

/**
 * The input data for the column "%1$" does not match the column type.
 */
#define SRH0APSCONFIGUREDSEARCH_column_type_mismatch                                         ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 18 )

 /**
 * No input data are received for the column "%1$".
 */
#define SRH0APSCONFIGUREDSEARCH_insufficient_column_data                                     ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 19 )

 /**
 * The temporary table cannot be created because of a mismatch in the number of columns and their types.
 */
#define SRH0APSCONFIGUREDSEARCH_columnNameType_mismatch                                      ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 20 )

/**
 * The provided Configuration Context is not valid.
 */
#define SRH0APSCONFIGUREDSEARCH_no_config_context_provided                                   ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 21 )

 /**
 *  The provided tag is null.
 */
#define SRH0APSCONFIGUREDSEARCH_null_tag                                                     ( EMH_SRH0APSCONFIGUREDSEARCH_ERROR_BASE + 22 )
 /**
    @}
 */

#endif
