/*==============================================================================
  Copyright (c) 2003-2005 UGS Corporation
  Unpublished - All Rights Reserved
  ==============================================================================*/

/**
   @file

   This file contains Query ITK for general public.
*/

/*  */

#ifndef QRY_H
#define QRY_H

#include <unidefs.h>
#include <property/propdesc.h>
#include <pom/pom/pom_tokens.h>
#include <qry/libqry_exports.h>

/**
   @defgroup QRY Query

   The query ITK module provides user methods to ask and set query attributes,
   find a specific query with a specified name, find all queries in the database,
   ask for a list of user entries of a query, execute a query, set query search mode,
   and set query's display name mode.

   @warning The constants defined below specify the size of variables.
   Do not write more than this number of bytes into the buffers.

   <b>Common Return Values</b>
   <br/>#QRY_invalid_query - Specified tag is not that of a saved query object.
   <br/>#QRY_invalid_search_domain - Specified search domain is not valid.

   @{
*/

/**
   Define the symbol QRY_puid which is an attribute type supported in saved query clauses.
*/
#define QRY_puid        (POM_MAX_type_token + 3)

typedef enum QRY_domain_e {
    QRY_DOMAIN_LOCAL,
    QRY_DOMAIN_REMOTE
    /** @if DOX_IGNORE
        QRY_DOMAIN_LOCAL_TYPE
        @endif */
} QRY_domain_t;

typedef enum QRY_where_run_e {
    QRY_RUN_BY_TC,              /**< A standard query */
    QRY_RUN_BY_USER_EXIT,       /**< Calls #USER_query_execute and displays text results */
    QRY_RUN_BY_USER_QUERY,      /**< Calls #USER_execute_saved_query and displays returned objects */
    QRY_RUN_BY_KEYWORD_SEARCH,  /**< Calls user exit code that configures and uses search engine */
    QRY_RUN_BY_EINT_EXIT,       /**< Exit similar to user exit which belongs to eIntegrator */
    QRY_RUN_BY_BOM_REP,         /**< Calls internal ITKs to generate BOM report */
    QRY_RUN_BY_USAGEWC,         /**< Calls USAGEWC ITKs to return proxy objects from TcBOM */
    QRY_RUN_BY_TC_PLUS_PROCESS, /**< A standard query plus post process results */
    QRY_RUN_BY_USER_EXIT_BO,    /**< Query which returns business objects, this is user exit query but does not return runtime ( external ) objects */
    QRY_CREATED_BY_CALLBACK     /**< Calls POM enquiry created by callback */
} QRY_where_run_t;

/**
   Defines the supported values for the "search_automatic_wildcard" preference
*/
typedef enum QRY_append_wildcard_pref_e {
    QRY_no_automatic_wildcards,         /**< Do not append wildcards */
    QRY_suffix_wild_card,               /**< Append suffix wildcard */
    QRY_prefix_wild_card,               /**< Append prefix wildcard */
    QRY_prefix_and_suffix_wild_cards    /**< Append prefix and suffix wildcards */
} QRY_append_wildcard_pref_t;

/**
   Defines the supported attribute types for Saved Query clauses
*/
typedef enum QRY_attribute_type_e
{ 
    QRY_attribute_char               = POM_char,                /**< Value is a single character */
    QRY_attribute_date               = POM_date,                /**< Value is a date */
    QRY_attribute_double             = POM_double,              /**< Value is a double */
    QRY_attribute_float              = POM_float,               /**< Value is a float */
    QRY_attribute_int                = POM_int,                 /**< Value is an integer */
    QRY_attribute_logical            = POM_logical,             /**< Value is a logical */
    QRY_attribute_short              = POM_short,               /**< Value is a short */
    QRY_attribute_string             = POM_string,              /**< Value is a character string */
    QRY_attribute_typed_reference    = POM_typed_reference,     /**< Value is a typed reference */
    QRY_attribute_untyped_reference  = POM_untyped_reference,   /**< Value is an untyped reference */
    QRY_attribute_external_reference = POM_external_reference,  /**< Value is an external reference */
    QRY_attribute_note               = POM_note,                /**< Value is a note */
    QRY_attribute_relationship       = PROP_typed_relation,     /**< Value is a typed relation */
    QRY_attribute_puid               = QRY_puid                 /**< Value is a puid */
} QRY_attribute_type_t;

/**
   See user_query.c for the user-exit functions that use this structure
*/
typedef struct QRY_user_query_row_s {
    struct QRY_user_query_row_s*    next;               /**< NULL if this is the last row */
    char*                           object_string;
    logical                         might_map_to_tc;  /**< True does not promise it will map */
    char*                           values[1];
} QRY_user_query_row_t;

/**
   @name Define attribute size
   @{
*/
#define QRY_name_size_c     128
#define QRY_desc_size_c     512
#define QRY_class_size_c    32
#define QRY_clause_size_c   240
#define QRY_uid_name_size_c 32
/** @} */

/**
   @name Sort Order
   @{
*/
#define OrderAscending      1
#define OrderDescending     2
/** @} */

#ifdef __cplusplus
extern "C"{
#endif

/**
   Retrieves the name of the specified query.
*/
    extern QRY_API int QRY_ask_name2(
        tag_t          query,                   /**< (I) Tag of the saved query */
        char           **qname                  /**< (OF) Name of the saved query */
        );


/**
   Sets the name of the specified query.
   <br/>It is not saved to the database until an explicit call to #AOM_save occurs.

   @note The query name must be unique and the maximum length is 128 characters.
*/
    extern QRY_API int QRY_set_name2(
        tag_t          query,                       /**< (I) Tag of the saved query */
        const char     *qname                       /**< (I) Name of the query to be saved */
        );

/**
   Retrieves the description of the specified query.
*/
    extern QRY_API int QRY_ask_description2(
        tag_t          query,                       /**< (I) Tag of the saved query */
        char           **qdesc                      /**< (OF) Description of the saved query */
        );
    
    
/**
   Sets the description of the specified query.
   <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
   
   @note Maximum length is 512 characters.
*/
    extern QRY_API int QRY_set_description2(
        tag_t          query,                       /**< (I) Tag of the saved query */
        const char     *qdesc                       /**< (I) Description of the query to be saved */
        );
    
/**
   Retrieves the search class of the specified query.
*/
    extern QRY_API int QRY_ask_class2(
        tag_t          query,                       /**< (I) Tag of the saved query */
        char           **qclass                     /**< (OF) Search class of the saved query */
        );
    
    
/**
   Sets the search class of the specified query.
   <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
   
   @note Maximum length is 32 characters. Ensure that query clauses or the attribute-value pairs of the
   query are still valid for the new search class. Otherwise, this query can be invalidated.
*/
    extern QRY_API int QRY_set_class2(
        tag_t          query,                       /**< (I) Tag of the saved query */
        const char     *qclass                      /**< (I) Search class of the query to be saved */
        );
    
/**
   Retrieves the query clauses of a specified query
   <br/><br/>@p qclauses is a concatenated string consisting of multiple query criteria clauses defined in the Query Builder
  
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#QRY_invalid_query if the query tag is invalid
   </ul>
*/
    extern QRY_API int QRY_ask_clauses(
        tag_t          query,                       /**< (I) Tag of the saved query */
        char**         qclauses                     /**< (OF) Search clauses of the query */ 
        );

/**
   Sets the clauses of the specified query
   <br/>The change is not saved to the database until an explicit call to #AOM_save occurs
   <br/><br/>@p qclauses is a concatenated string consisting of multiple query criteria clauses. To obtain a sample valid string, export the saved query through the Query Builder in the rich client or use #QRY_ask_clauses.

   @note @p qclauses will be verified to make sure it's valid clauses

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#QRY_invalid_query if @p qclauses is invalid
   </ul>
*/
    extern QRY_API int QRY_set_clauses(
        tag_t         query,                       /**< (I) Tag of the saved query. */
        const char*   qclauses                     /**< (I) Search clauses of the query to be saved. */ 
        );


/**
   Performs a case sensitive search for the specified query name and returns its tag.
*/
    extern QRY_API int QRY_find2(
        const char     *name,                       /**< (I) Name of the query */
        tag_t*         query                        /**< (O) Tag of the saved query */
        );

/**
   Retrieves the number of saved queries and a list of saved query tags.
*/
    extern QRY_API int QRY_extent(
        int*           query_count,     /**< (O) Number of the saved queries or the size of the array */
        tag_t**        queries          /**< (OF) query_count List of saved query tags */
        );

/**
   Finds all user entries of the specified query.
*/
    extern QRY_API int QRY_find_user_entries(
        tag_t          query,           /**< (I) Tag of the saved query */
        int*           n_entries,       /**< (O) Number of user entries in this query */
        char***        entries,         /**< (OF) n_entries Array of user entries */
        char***        values           /**< (OF) n_entries Array of default values for the user entries.
                                           <br/>Each array element, values[n], specifies the default value of entries[n].
                                           <br/>A values[n] can be an empty string if there is no default value defined. */
        );

/**
   Executes the saved query with the specified user entries and returns the number of found objects and object tags.
   <br/>Use #QRY_find_user_entries to get a list of user entries.
   <br/>You do not have to have all the user entries in your entries array for execution.
   The entries array can be equal or less than the user entries found by #QRY_find_user_entries ITK.
   However, the size of the values array should be the same as the entries array so that each entry is matched with a value.
   <br/>This ITK does not check read privileges on the results.
*/
    extern QRY_API int QRY_execute(
        tag_t          query,           /**< (I) Tag of the saved query */
        int            n_entries,       /**< (I) Number of user entries in this query */
        char**         entries,         /**< (I) n_entries Array of user entries */
        char**         values,          /**< (I) n_entries Array of values for the user entries. Each array element, values[n],
                                           specifies the value of entries[n]. */
        int*           n_found,         /**< (O) Number of found objects */
        tag_t**        results          /**< (OF) n_found Found objects. */
        );

/**
   Executes the saved query with the specified user entries and returns the number of found objects and
   object tags of those objects in the database that are also in the limit_list.
   <br/>If the limit_list is null, or the limit_list_count is 0,
   the objects returned are exactly the same as those returned by #QRY_execute.

   <br/>Use #QRY_find_user_entries to get a list of user entries.
   <br/>You do not have to have all the user entries in your entries array for execution.
   The entries array can be equal or less than the user entries found by #QRY_find_user_entries ITK.
   However, the size of the values array should be the same as the entries array so that each entry is matched with a value.
   <br/>This ITK does not check read privileges on the results.

   <b>Restrictions:</b>
   This function does not work with user_exit_queries.
*/
    extern QRY_API int QRY_execute_on_list(
        tag_t          query,             /**< (I) Tag of the saved query */
        int            n_entries,         /**< (I) Number of user entries in this query */
        char**         entries,           /**< (I) n_entries Array of user entries */
        char**         values,            /**< (I) n_entries Array of values for the user entries. Each array element, values[n],
                                             specifies the value of entries[n]. */
        int            n_limits,          /**< (I) The number of objects used to limit the search. */
        tag_t*         limits,            /**< (I) n_limits The objects to limit the search */
        int*           n_found,           /**< (O) The number of objects found */
        tag_t**        results            /**< (OF) n_found The objects found in the database
                                             intersected with @p limits tags. */
        );

    extern QRY_API int QRY_execute_user_exit_query(
        tag_t                   query,          /**< (I) */
        int                     n_entries,    /**< (I) */
        char**                  entries,        /**< (I) n_entries */
        char**                  values,         /**< (I) n_entries */
        int*                    n_columns,    /**< (O) */
        char***                 results,        /**< (OF) n_columns */
        QRY_user_query_row_t**  rows            /**< (OF) */
        );

/**
   Executes the saved query at the specified site.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ODS_no_such_site if @p site_id is not a valid or not an ODS (Object Directory Services) capable site.
   <li>Potentially any other error codes in case of failure
   </ul>
*/
    extern QRY_API int QRY_execute_at_site(
        int            site_id,         /**< (I) ID of the remote site where the query will executed. The site needs to be ODS capable.
                                           <br/>If zero, the query will be executed at the default ODS site.*/
        tag_t          query,           /**< (I) Tag of the saved query */
        int            n_entries,       /**< (I) Number of user entries in this query */
        char**         entries,         /**< (I) n_entries Array of user entries */
        char**         values,          /**< (I) n_entries Array values for the user entries. Each array element, values[n],
                                           specifies the value of entries[n]. */
        int*           n_found,         /**< (O) Number of objects found */
        tag_t**        results          /**< (OF) n_found List of found objects */
        );

/**
   Retrieves the objects that meet the given search criteria.
   <br/>The order of the objects in the returned array is determined according to the given sort criteria.
   <br/>This ITK does not check read privileges on the results.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#QRY_enquiry_not_available if the query is invalid.
   <li>#QRY_not_a_number if a string is found when a number was expected. 
   <li>Potentially other errors.
   </ul>
*/
    extern QRY_API int QRY_execute_with_sort(
        tag_t          query,           /**< (I) The tag of a saved query object */
        int            n_entries,       /**< (I) The number of the user entries */
        char**         entries,         /**< (I) n_entries The array of the user entry names */
        char**         values,          /**< (I) n_entries The array of the values. Each user name in the "entries" array must
                                           have a corresponding value in the "values" array. */
        int            n_to_sort,       /**< (I) The number of the class attributes to be sorted */
        char**         keys,            /**< (I) n_to_sort The array of the names of the attributes that the found objects
                                           are to be sorted against. An attribute must be from the query target class. */
        int*           orders,          /**< (I) The array of the sort orders.
                                           The possible values of a sort order are:
                                           <ul><li>1 (Ascending Order)
                                           <li>2 (Descending Order)
                                           </ul> */
        int*           n_found,          /**< (O) The number of the found objects */
        tag_t**        results          /**< (OF) n_found The found objects */
        );

/**
   Retrieves the objects that meet the given search criteria and that are in the given limit list.
   <br/>The order of the objects in the returned array is determined according to the given sort criteria.
   <br/>This ITK does not check read privileges on the results.

   For other arguments, please see #QRY_execute_with_sort
*/
    extern QRY_API int QRY_execute_on_list_with_sort(
        tag_t          query,               /**< (I) The tag of a saved query object */
        int            n_entries,           /**< (I) The number of the user entries */
        char**         entries,             /**< (I) n_entries The array of the user entry names */
        char**         values,              /**< (I) n_entries The array of the values. Each user name in the "entries" array must have
                                               a corresponding value in the "values" array. */
        int            n_limits,            /**< (I) The length of the limit_list array */
        tag_t*         limits,              /**< (I) n_limits The tag array of the objects */
        int            n_to_sort,           /**< (I) The number of the class attributes to be sorted */
        char**         keys,                /**< (I) n_to_sort The array of the names of the attributes that the found objects are
                                               to be sorted against. An attribute must be from the query target class. */
        int*           orders,              /**< (I) The array of the sort orders.
                                               The possible values of a sort order are: 
                                               <ul>
                                               <li>1 (Ascending Order)
                                               <li>2 (Descending Order)
                                               </ul> */
        int*           n_found,             /**< (O) The number of the found objects */
        tag_t**        results              /**< (OF) n_found The found objects */
        );

/**
   Executes the query at the given site.
   <br/>The published objects that meet the given search criteria are retrieved.
   <br/>The order of the objects in the returned array is determined according to the given sort criteria.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#QRY_enquiry_not_available if the query is invalid.
   <li>#QRY_not_a_number if a string is found when a number was expected.
   <li>Potentially other query error codes.
   </ul>
*/
    extern QRY_API int QRY_execute_at_site_with_sort(
        int            site_id,         /**< (I) The site id */
        tag_t          query,           /**< (I) The tag of a remote query object */
        int            n_entries,       /**< (I) The number of the user entries */
        char**         entries,         /**< (I) n_entries The array of the user entry names */
        char**         values,          /**< (I) n_entries The array of the values. Each user name in the "entries" array must have
                                           a corresponding value in the "values" array. */
        int            n_sorting_keys,     /**< (I) The number of the PublicationRecord class attributes to be sorted */
        char**         sorting_keys,            /**< (I) n_sorting_keys The array of the names of the attributes that the found objects are to be
                                                   sorted against. An attribute must be from the PublicationRecord class. */
        int*           orders,          /**< (I) The array of the sort orders.
                                           The possible values of a sort order are: 
                                           <ul>
                                           <li>1 (Ascending Order)
                                           <li>2 (Descending Order) 
                                           </ul> */
        int*           n_found,          /**< (O) The number of the found objects */
        tag_t**        results          /**< (OF) n_found The found objects */
        );

/**
   Sets the name mode of the specified query to display real property names or to display presentation names.

   <br/>Default name mode is presentation mode. Set name_mode to TRUE for real property name,
   and set name_mode to FALSE for presentation name.
*/
    extern QRY_API int QRY_set_name_mode(
        tag_t          query,       /**< (I) Tag of the saved query */
        logical        name_mode    /**< (I) @c true for real property name, and @c false for presentation name */
        );

/**
   Sets the domain of a saved query to specified search domain.

   <b>Restrictions:</b> Remote queries can be executed only in a D-Teamcenter environment.
*/
    extern QRY_API int QRY_set_search_domain(
        tag_t          query,           /**< (I) Tag of the saved query */
        QRY_domain_t   search_domain    /**< (I) Search domain to set for the specified query.
                                           <br/>The search domain value can be one of the following:
                                           <ul>
                                           <li>#QRY_DOMAIN_LOCAL: the query will be executed at the local site against the local database.
                                           <li>#QRY_DOMAIN_REMOTE: the query will be executed at a remote site against a remote database.
                                           </ul> */
        );

/**
   Retrieves the current search domain of the specified saved query.

   <b>Restrictions:</b> Remote queries can only be executed in a D-Teamcenter environment.
*/
    extern QRY_API int QRY_ask_search_domain(
        tag_t          query,           /**< (I) Tag of the saved query */
        QRY_domain_t*  search_domain    /**< (O) Current search domain of the specified saved query.
                                           <br/>The search domain value can be one of the following:
                                           <ul>
                                           <li>#QRY_DOMAIN_LOCAL: the query will be executed at the local site against the local database.
                                           <li>#QRY_DOMAIN_REMOTE: the query will be executed at a remote site against a remote database.
                                           </ul> */
        );

    extern QRY_API int QRY_set_where_run(
        tag_t           query,      /**< (I) */
        QRY_where_run_t where_run   /**< (I) */
        );

    extern QRY_API int QRY_ask_where_run(
        tag_t               query,      /**< (I) */
        QRY_where_run_t*    where_run   /**< (O) */
        );

/**
   Retrieves full details (i.e. full details of each clause in string lists) of the specified query.

   <br/>This ITK is primarily used by Teamcenter-PC where the details are used to reconstruct a query form.
*/
    extern QRY_API int QRY_describe_query(
        tag_t          query,           /**< (I) Tag of the saved query */
        int*           n_clauses,       /**< (O) Number of clauses in this query */
        char***        attr_names,      /**< (OF) n_clauses List of attribute names.
                                           Number of list elements is the same as num_clauses. */
        char***        entry_names,     /**< (OF) n_clauses List of user entry names.
                                           Number of list elements is the same as num_clauses.
                                           For fixed entry clause, that entry name element will be a NULL string. */
        char***        logical_ops,     /**< (OF) n_clauses List of logical operators */
        char***        math_ops,        /**< (OF) n_clauses List of math operators */
        char***        values,          /**< (OF) n_clauses List of default values.
                                           Each value corresponds to each attribute.
                                           If there is no default value defined for a particular clause,
                                           that value element will be a NULL string. */
        tag_t**        lovs,            /**< (OF) n_clauses List of LOV tags.
                                           If there is no LOV that corresponds to the attribute,
                                           that @p lovs element will be 0. */
        int**          attr_types       /**< (OF) n_clauses List of attribute types */
        );

/**
   Retrieves full details for each clause of a specified query.
   <br/><br/>Each clause is a search criteria entry defined in Query Builder in the rich client.
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#QRY_invalid_query if @p qclauses is invalid
   </ul>
*/
    extern QRY_API int QRY_details(
        tag_t                   query,                          /**< (I) The query tag */
        logical                 substitute_keyword,             /**< (I) Flag of substituting keyword with real value */
        int*                    n_clauses,                      /**< (O) Number of clauses */
        char***                 attribute_names,                /**< (OF) n_clauses Attribute names. 
                                                                   <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free */
        char***                 entry_names,                    /**< (OF) n_clauses Entry L10N keys. 
                                                                   <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free */
        char***                 entry_names_display,            /**< (OF) n_clauses Entry display names. 
                                                                   <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free */
        char***                 logical_operators,              /**< (OF) n_clauses Logical operators. 
                                                                   <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free */
        char***                 math_operators,                 /**< (OF) n_clauses Math operators. 
                                                                   <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free */
        char***                 values,                         /**< (OF) n_clauses Display values. 
                                                                   <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free */
        tag_t**                 lovs,                           /**< (OF) n_clauses LOV tags */
        int**                   attached_specifiers,            /**< (OF) n_clauses The attached specifiers for the LOVs */
        int***                  dependent_indexes,              /**< (OF) n_clauses Dependent indexes. 
                                                                   <br/>The first dimension is num_clauses clauses, the second dimension is 2 indexes of clauses each
                                                                   clause depends on. 
                                                                   <br/>The returned array is not packed, which means that both the elements and the container need to be deallocated using #MEM_free.*/
        int**                   key_lov_ids,                    /**< (OF) n_clauses IDs of the key LOVs */
        int**                   attribute_types                 /**< (OF) n_clauses Types of the attributes. Possible values are defined in #QRY_attribute_type_e */ );
    
/**
   Sets the TC_ignore_case_on_search preference for the current ITK session.
   <br/>This ITK does not set the value in the preference file.
*/
    extern QRY_API int QRY_ignore_case_on_search(
        logical        ignore_case       /**< (I) Flag for case insensitive or sensitive search.
                                            If @c true, searching will be case insensitive.*/
        );

    extern QRY_API int QRY_compute_sort_preference_names(
        tag_t          query,        /**< (I) */
        char**         key_name,     /**< (OF) */
        char**         order_name,   /**< (OF) */
        char**         pkey_name,    /**< (OF) */
        char**         porder_name   /**< (OF) */
        );

/**
   Executes the saved query with the specified user entries, limited by the limit_list.
    
   <br/>If @p limits is null, or @p n_limits is 0, the limit list is ignored and the
   query is run against all data in the database.

   Returned is a list of object tags organized as tuples (subsets). The list is
   num_rows * num_cols long. Each tuple subset corresponds to one result, comprising of
   qualifying objects from multiple levels of the queried object hierarchy. The classes of
   objects that are selected to be part of the tuple subset are determined by the class names
   in the query criteria.

   <br/><br/>Example 1:
   If the query is: Find all Items where the Item Revisions have a Specification Dataset
   with name = "xyz1",
   then each tuple subset will contain: Item, qualifying Item Revision and qualifying Dataset.
   <br/>The num_cols return value will be 3. The result list will contain Item tag 0,
   Item Revision tag 0, Dataset tag 0, Item tag 1, Item Revision tag 1, Dataset tag 1
   and so on... for as many entries in the database that satisfy the query.

   <br/><br/>Example 2:
   If the query is: Find all Item Revisions that have a Specification Dataset with name = "xyz1"
   AND Form of type Item Revision Master with user_data_1 = "xyz2",
   then each tuple subset will contain: Item Revision, qualifying Dataset, qualifying Form and
   qualifying Item Revision Master. The num_cols return value will be 4. The result list
   will contain Item Revision tag 0, Dataset tag 0, Form tag 0, Item Revision Master tag 0,
   Item Revision tag 1, Dataset tag 1, Form tag 1, Item Revision Master tag 1 and so on... for
   as many entries in the database that satisfy the query.

   <br/>Use #QRY_find_user_entries to get a list of user entries.
   You do not have to have all the user entries in your entries array for execution.
   The entries array can be equal or less than the user entries found by #QRY_find_user_entries ITK.
   However, the size of the values array should be the same as the entries array so that each entry is matched with a value.

   <b>Restrictions:</b> This function does not work with user_exit_queries.
*/
    extern QRY_API int QRY_execute_tuples(
        tag_t          query,             /**< (I) Tag of the saved query */
        int            n_entries,         /**< (I) Number of user entries in this query */
        char**         entries,           /**< (I) n_entries Array of user entries */
        char**         values,            /**< (I) n_entries Array of values for the user entries. Each array element, values[n],
                                             specifies the value of entries[n]. */
        int            n_limits,          /**< (I) The number of tags in the limit_list */
        tag_t*         limits,            /**< (I) n_limits The list of object tags used to limits the search */
        int*           n_rows,            /**< (O) The number of tuples found */
        int*           n_cols,            /**< (O) The number of objects in each tuple */
        tag_t**        results            /**< (OF) n_rows*n_cols The objects found in the
                                             database intersected with @p limits tags. Its size is @c num_rows*num_cols long. */
        );

/**
   Retrieves the objects that meet the given search criteria and that are in the given limit list.
   <br/>This API also takes into account any sort preferences, where-run, and search domain, when executing
   the search.
*/
    extern QRY_API int QRY_execute_query(
        tag_t          query,             /**< (I) The saved query to execute */
        int            n_entries,         /**< (I) Number of user entries in this query */
        char**         entry_names,       /**< (I) n_entries Array of user entries */
        char**         entry_values,      /**< (I) n_entries Array of values for the user entries. Each array element, value[n],
                                             specifies the value of entries[n] */
        int            n_limites,         /**< (I) Number of tags in the limit_list */
        tag_t*         limits,            /**< (I) n_limits List of object tags used to limit the search scope */
        int            results_type,      /**< (I) An integer specifying the results type:
                                             <ul>
                                             <li>0 (flat),
                                             <li>1 (hierarchical)
                                             </ul> */
        int*           n_components,      /**< (O) Number of objects found */
        int**          hierarchical_map,  /**< (O) If the results type is specified as "hierarchical", this integer
                                             array acts as a map for the found objects to be presented in a
                                             hierarchical fashion */
        tag_t**        components         /**< (OF) n_components Array of found objects */
        );

    extern QRY_API int QRY_writeToFile(
        tag_t          query,        /**< (I) */
        char*          file_name     /**< (I) */
        );

    extern QRY_API  int QRY_readFromFile(
        char*           file_name,   /**< (I) */
        char**          query_name   /**< (OF) */
        );

/**
   Updates / deletes the FTS index of the given object. 
   <br/>It will index the object only if it is mentioned as a Type under the preference @c TC_fts_indexed_types.
*/
    extern QRY_API int QRY_update_fts_index(
        tag_t           object,         /**< (I) The tag of the object whose FTS index you want to update. */
        logical         delete_index    /**< (I) Indicates whether to delete the FTS index of the given object. */
        );


    extern QRY_API int QRY_execute_query_with_cancel_option(
        char*          query_request_id,  /**< (I)  A string representing the execute operation request */
        tag_t          query,             /**< (I) Tag of saved query to execute */
        int            n_entries,         /**< (I) Number of user entries in this query */
        char**         entry_names,       /**< (I) n_entries Array of user entries */
        char**         entry_values,      /**< (I) n_entries Array of values for the user entries. Each array element, value[n],
                                             specifies the value of entries[n] */
        int            n_limits,          /**< (I)  Number of tags in the limit_list */
        tag_t*         limits,            /**< (I) n_limits List of object tags used to limit the search scope */
        int            results_type,      /**< (I) An integer specifying the results type:
                                             <ul>
                                             <li>0 (flat),
                                             <li>1 (hierarchical) 
                                             </ul>*/
        int*           n_components,      /**< (O)  Number of objects found */
        int**          hierarchical_map,  /**< (O) If the results type is specified as "hierarchical", this integer
                                             array acts as a map for the found objects to be presented in a
                                             hierarchical fashion */
        tag_t**        components        /**< (OF) n_components Array of found objects */
        );

/**
   Finds the objects of the input class with the specified attributes & values.

   <br/><br/>Example: If the query is:
   Find all Items where object_name = "x*z1;x*z2" AND object_type="Document",

   <b>Restrictions:</b> At present operations supports = operation.
   In future this will be extened for other operations too
   <br/>This function designed to work for local queries only.
*/
    extern QRY_API int QRY_find_objects_based_on_attributes_and_values(
        char*          class_name,            /**< (I) primiary class to find the objects */
        int            n_attributes,          /**< (I) Number of user entries in this query */
        char**         names,                 /**< (I) n_attributes Array of attribute names */
        char**         operations,            /**< (I) n_attributes Array of  operations */
        char**         values,                /**< (I) n_attributes Array of values for attribute names and operations
                                                 <br/>Each array element, values[n], specifies the value 
                                                 of entries[n]. */
        char**         clauses_rules,         /**<(I) Array of values to club different clauses.
                                                 <br/>For example AND,OR etc. At present AND is assumed.
                                                 <br/>For future use only. Right now pass NULL */
        int*           n_found,               /**< (O) The number of objects found */
        tag_t**        results                /**< (OF)n_found The list of objects found 
                                                 in the database. */
        );

/**
    Executes business object query.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#QRY_no_create if any attribute passed to @p entry_names is invalid.
    <li>#TYPE_no_find_type if @p type_tag is an invalid type.
    <li>Other potential error codes.
    </ul>
*/
    extern QRY_API int QRY_execute_bus_obj_query(
    char*         request_id,              /**< (I)  A string representing the execute operation request */
    tag_t         type,                    /**< (I)  Target business object type to search*/
    int           n_entries,               /**< (I)  Number of user entries in this query */
    char**        entry_names,             /**< (I)  n_entries List of property names */
    char**        entry_values,            /**< (I)  n_entries List of property values */
    char**        entry_math_operators,    /**< (I)  n_entries List of math operators */
    char**        entry_logic_operators,   /**< (I)  n_entries List of logical operators */
    int*          n_components,            /**< (O)  Number of objects found */
    tag_t**       components               /**< (OF) n_components List of objects found */
        );

/**
    Executes business object query with sorting attributes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#QRY_no_create if failed to create the business object query.
    <li>#QRY_enquiry_not_available if any attribute passed to @p sort_attrs is invalid.
    <li>#TYPE_no_find_type if @p type is an invalid type.
    <li>Other potential error codes.
    </ul>
*/
extern QRY_API int QRY_execute_bus_obj_query_common(
    const char*         request_id,             /**< (I)  A string representing the execute operation request */
    const tag_t         type,                   /**< (I)  Target business object type to search */
    const tag_t         operation_input,        /**< (I)  Generic Operation Input object providing name-value input. */
    const int           n_entries,              /**< (I)  Number of user entries in this query */
    const char**        entry_names,            /**< (I)  n_entries List of property names */
    const char**        entry_values,           /**< (I)  n_entries List of property values */
    const char**        entry_math_opertors,    /**< (I)  n_entries List of math operators */
    const char**        entry_logic_opertors,   /**< (I)  n_entries List of logical operators */
    const int           n_sort_attrs,           /**< (I)  The number of the sorting attributes */
    const char**        sort_attrs,             /**< (I)  n_sort_attrs List of sorting attributes. The attributes must be from the target @p type. */
    const int*          sort_orders,            /**< (I)  n_sort_attrs List of sort orders.
                                                          The possible values of a sort order are: <br/>
                                                          1 (Ascending Order) <br/>
                                                          2 (Descending Order) */
    int*                n_found,                /**< (O)  Number of objects found */
    tag_t**             results                 /**< (OF) n_found List of object found. */
);

#ifdef __cplusplus
}
#endif

/** @} */
#include <qry/libqry_undef.h>
#endif
