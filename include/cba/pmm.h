/*==============================================================================
                Copyright (c) 2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file


    The PMM module presents a high level interface to a remote Teamcenter
    Product Master Management system.  It supports basic services for query and
    manipulation of PMM objects like Part, Line of Usage and Line of Assembly.

*/

/*  */

#ifndef PMM_H_INCLUDED
#define PMM_H_INCLUDED

#include <unidefs.h>

#include <cba/libcba_exports.h>

/**
    @defgroup PMM Product Master Management 

    This module provides implementation for all the ITKs to be used by the customers of Product Master Management.

    To use these ITK functions, include the pmm.h file in the source code.
    @{
*/




#ifdef __cplusplus
    extern "C" {
#endif

/**
   Contains the error details for a particular input that failed.
   If the input data structures contained a client ID, the client ID field will be populated
   with the client ID of the failing input.
*/
typedef struct CBA_API PMM_error_store_map_s
{
    int                 ifail;      /**< The Teamcenter ifail code corresponding to the failure */
    char                code[16];   /**< The error code returned by the Product Master Management server */
    char                *message;   /**< The error message for the failure */
    int                 clientId;   /**< The clientID corresponding to the input that failed */
    char                *subst;     /**< The substitued teamcenter error with all substitutions */
} PMM_error_store_map_t;

 /**
   Contains the query criteria for multilevel engineering breakdown
*/
typedef struct PMM_name_value_criteria_s
{
    char** entries;     /**< Query criteria entries for multilevel breakdown query */
    char** values;      /**< Query criteria values for multilevel breakdown query */
    int num_criteria;   /**< Number of query criteria's. */
}PMM_name_value_criteria_t;

 /**
   Contains the Assembly Component Tree Lines in multilevel engineering breakdown structure.
*/
typedef struct PMM_actlines_per_child_s
{
    int countOfACTLines;    /**< Count of Assembly Component Tree Lines */
    tag_t* childACTLines;   /**< Assembly Component Tree Lines per level */
}PMM_actlines_per_child_t;

 /**
   Contains the levelwise Assembly Component Tree Lines in multilevel engineering breakdown structure.
*/
typedef struct PMM_level_to_actlines_with_details_s
{
    tag_t  asmPartACTLineTag;                           /**< ACTLine for an Assembly part in the Assembly Component Tree */
    int    num_of_child_actLines_per_level;             /**< Number of child Assembly Component Tree for an Assembly part */
    PMM_actlines_per_child_t* childACTLinesPerLevel;    /**< Structure representing the  Assembly Component Tree Lines for an Assembly part */
}PMM_level_to_actlines_with_details_t;

 /**
   Contains the Assembly Component Tree multilevel engineering breakdown structure.
 */
typedef struct PMM_breakdown_output_s
{
    tag_t  bomWindowTag;                                        /**< BomWindow Tag */
    tag_t  topAsmPartACTLineTag;                                /**< ACTLine for the Assembly part on which the  multilevel engineering breakdown is performed  */
    int    num_of_level_wise_breakdown;                         /**< Number of Assembly Component Tree. One for each Assembly part in the part breakdown structure */
    PMM_level_to_actlines_with_details_t* levelWiseBreakdown;   /**< Structures containing the Assembly Component Tree in multilevel engineering breakdown */
}PMM_breakdown_output_t;



/**
    @name PMM Setup Functions
    @{
*/

/**
    Initializes the Product Master Management (PMM) module.
    This function must be called before using any other PMM module functions.
    This function will be called by the standard ITK startup code.
    The ITK programmer can ignore this function.

    @note A second call is ignored.
*/
extern CBA_API int PMM_init_module( void );

/**
    Terminates the Product Master Management (PMM) module.
    The ITK programmer can ignore this function.

    @note A second call is ignored.
*/
extern CBA_API int PMM_exit_module( void );

/** @} PMM Setup Functions */

/**
    @name PMM Utility Functions
    @{
*/

/**
    Indicates if the PMM (Product Master Management) module is configured to work with the Product Master Management (PMM) server.
*/
extern CBA_API int PMM_is_usage_enabled(
    logical        *is_enabled       /**< (O) True if the PMM module is configured to work with the PMM server */
    );

/** @} PMM Utility Functions */

/**
    @name PMM Query Functions
    @{
*/

/**
    Queries objects defined in the Product Master Management (PMM) database using the specified SQL where clause.
    Returns a list of Teamcenter proxy objects that represent the queried PMM objects.

    @returns
    <ul>
    <li>ITK_ok on success
    <li>#PMM_usage_server_error if an error has occurred in the PMM server.
    <li>#PMM_failed_to_login if the login to the PMM server has failed.
    </ul>
*/
extern CBA_API int PMM_complex_generic_query(
    char*           class_name,                   /**< (I) Name of the PMM class to which the objects belong */
    char*           where_clause,                 /**< (I) Where clause used to query the PMM objects */
    int             num_return_attribute_names,   /**< (I) Number of attributes to be returned by the query */
    char**          return_attribute_names,       /**< (I) List of attributes to be returned by the query */
    int*            num_found,                    /**< (O) Number of objects found*/
    tag_t**         proxies                       /**< (OF) num_found List of objects found */
    );


/**
    Queries objects defined in the Product Master Management (PMM) server using the specified query criteria.
    Returns a list of Teamcenter proxy objects that represent the queried PMM objects.

    @returns
    <ul>
    <li>ITK_ok on success
    <li>#PMM_usage_server_error if an error has occurred in the PMM server.
    <li>#PMM_failed_to_login if the login to the PMM server has failed.
    </ul>

*/
extern CBA_API int PMM_generic_query(
    const char*     class_name,                 /**< (I) Name of the PMM class to which the objects belong */
    int             num_criteria,               /**< (I) Number of criteria used for the query*/
    char**          criteria_names,             /**< (I) Names of the criteria used for the query */
    char**          criteria_values,            /**< (I) Values of the criteria used for the query */
    tag_t           usage_config_context,       /**< (I) Configuration Context used for the query */
    int             num_return_attribute_names, /**< (I) Number of attributes to be returned by the query */
    char**          return_attribute_names,     /**< (I) List of attributes to be returned by the query */
    int*            num_found,                  /**< (O) Number of objects found */
    tag_t**         proxies                     /**< (OF) num_found List of objects found */
    );

/**
    Executes multibreakdown query from the Product Master Management (PMM) server server against constructs
    represented by the query criteria's in TcServer and returns the top level assembly part.

    @returns
    <ul>
    <li>ITK_ok on success
    <li>#PMM_mandatory_fields_not_specified if a required input element is not specified.
    <li>#PMM_usage_server_error if an error has occurred in the PMM server.
    <li>#PMM_failed_to_login if the login to the PMM server has failed.
    <li>#PMM_part_breakdown_failed if the part breakdown operation has failed.
    </ul>
*/
extern CBA_API int PMM_multi_break_down_query(
                        PMM_name_value_criteria_t*   source_part_criteria, /**< (I) source part's criteria i.e Assembly Part on which the breakdown is performed */
                        PMM_name_value_criteria_t*   query_criteria,       /**< (I) query criteria's for line of assembly */
                        bool                         with_details,         /**< (I) set the flag as true to populate the output structure "PMM_breakdown_output_t".*/
                        int                          explosion_level,      /**< (I) The depth at which a component part is present with respect to the root assembly node.*/
                        tag_t*                       proxy,                /**< (O) Assembly part proxy object of Line Of Assembly having depth of one in the breakdown structure*/
                        PMM_breakdown_output_t*      breakdown_output      /**< (O) Structure having information like : For level x what is the Assembly part's ACTLine and its corresponding child ACTLines. */
                );

/**
    Updates the content of a BOMWindow and some BOMLines, based on the bill of
    material data retrieved from the Product Master Manager (PMM).

    @note If any error is returned (e.g. not all tags passed in as part
    of selected_bomlines are actually BOMLines, or a BOMLine update fails),
    all changes to the database are rolled back.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_usage_server_error if the PMM server reports an error.
    <li>#CXPOM_invalid_tag if the input tag is invalid.
    <li>#PMM_failed_to_find_scope if one or more of the tags given in @p selected_bomlines is null or the Scope criterion is not present on all the selected BOMLines.
    <li>#PMM_failed_to_login if the login to the PMM server has failed.
    </ul>
*/
extern CBA_API int PMM_update_ps_for_recipe(
    const tag_t         window,                         /**< (I) BOMWindow of  Product structure.*/ 
    const unsigned int  n_bom_lines,                    /**< (I) Number of BOMLines.*/   
    const tag_t*        selected_bomlines               /**< (I) n_bom_lines The BOMLines to be updated.*/
    );

/**
    Creates a study like structure called Layout Structure by setting input Layout Item Revision
    as Top Line of the structure and adding given list of input BOMLines to it.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input BOMLines tag is invalid.
    <li>#PMM_empty_input_for_add_to_layout if a required input element(selected_lines count is zero/layout_item_rev tag is null) is not specified.
    <li>#PMM_improper_precision_of_bvr_for_add_to_layout if input Item Revision already has a BOMView Revision which is of improper precision.
    </ul>
*/
extern CBA_API int PMM_add_to_layout(
    const unsigned int     n_bomlines,              /**< (I)  Number of BOMLines.*/
    const tag_t            *selected_lines,         /**< (I)  n_bomlines BOMLines.*/
    const tag_t            layout_item_rev,         /**< (I)  Layout Item Revision. */
    const char*            view_type_name,          /**< (I)  The type of BOM View to be used for Layout structure.
                                                     <ul>
                                                        <li>A View type is a site-defined classification of BOM views. You can get a list of all View types defined for an Teamcenter installation from the PS_view_type_extent function.
                                                        <li>null pointer: uses the default type of BOM View. The default View type name is defined by the PS_default_view_type_name token in the ps_tokens.h header file .
                                                     </ul>
                                                    */
    tag_t                  *layout_window,          /**< (O)  BOMWindow of Layout structure.*/
    tag_t                  *layout_top_line,        /**< (O)  Top BOMLine of Layout structure.*/
    int                    *no_of_children,         /**< (O)  Number of Layout childlines.*/
    tag_t                  **layout_childlines,     /**< (OF) Layout childlines.*/
    int                    *no_of_conflicts,        /**< (O)  Number of Conflicting lines which are not added to Layout.*/
    tag_t                  **conflicting_lines      /**< (OF) Conflicting lines which are not added to Layout.*/
    );

/** @} PMM Structure Context Object Functions */

#ifdef __cplusplus
    }
#endif

/** @} PMM_ITK group */

#include <cba/libcba_undef.h>
#endif
