/*Copyright 2020 Siemens Digital Industries Software
**==================================================
**Copyright $2010.
**Siemens Product Lifecycle Management Software Inc.
**All Rights Reserved.
**==================================================
**Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file modelsearch_types.h

    This file contains the definition of data structures used by MODELSEARCH calls

*/

#ifndef __INCLUDED_MODELSEARCH_TYPES_H__
#define __INCLUDED_MODELSEARCH_TYPES_H__

#include <unidefs.h>

/**
    Determines which Search type is used.
*/
typedef enum Mdl0SearchType_s
{
    EmptySearch = 0,    /**< A place holder search type. */
    ResultType,         /**< Search type used to filter search results based on Result Type. */
    SelectedContent,    /**< Search type used to filter search results based on selected content. */
    Group,              /**< Search type used to combine multiple search terms using AND/OR/NOT operator. */
    SavedQuery,         /**< Search type used to filter search results based on property values. */
    Proximity,          /**< Search type used to perform Proximity search. */
    BoxZone,            /**< Search type used to perform Box Zone search. */
    PlaneZone,          /**< Search type used to perform Plane Zone search. */
    PartitionSearch,    /**< Search type used to perform search in the selected partitions. */
    Closure,            /**< Search type used to get secondary object from the primary search results by applying closures. */
    UnassignedPartition,/**< Search type used to search the contents that are not assigned to any partition. */
    OptionSet,          /**< Search type to identify set of additional search options. */
    GeometricConstraint,/**< Search type used to search for Geometric constraints of the given elements. */
    Composite,          /**< Search type used to treat multiple search terms as single search term. The search terms are combined using AND operator. */
    IncludeAll,         /**< Search type used to get all the elements under a model object. */
    Classification,     /**< Search type used to search for Classification of the given elements. */
    AspectSearch        /**< Search type used to perform search base on Aspect. */
}Mdl0SearchType_t;

/**
    Enumerated list of Boolean operators to Group sub expressions in a group expression
*/
typedef enum Mdl0Operator_s
{
    And = 0,
    Or,
    Not
}Mdl0Operator_t;

/**
    List of BOX Zone Operators
*/
typedef enum Mdl0BoxOperator_s
{
    Inside = 0,
    Outside,
    BoxIntersect,
    InsideOrIntersects,
    OutsideOrIntersects
}Mdl0BoxOperator_t;

/**
    List of Plane Zone Operators
*/
typedef enum Mdl0PlaneOperator_s
{
    PlaneAbove = 0,
    PlaneBelow,
    PlaneIntersects,
    PlaneAboveOrIntersects,
    PlaneBelowOrIntersects
}Mdl0PlaneOperator_t;

/**
    List of Sort Orders
*/
typedef enum Mdl0SortOrder_e
{
    Ascending,
    Descending
}Mdl0SortOrder_t;

/**
    Defines the various export modes.
*/
typedef enum Mdl0ExportMode_e
{
    BACKGROUNDMODE,  /**< The export will be done asynchronously in new Teamcenter session and the ITK returns immediately. 
                     <br/>When the background export is done, a TC mail is sent to the logged-in user, 
                     which contains the location of the dataset which contains the MS Excel file. */
    BLOCKINGMODE,    /**< The export will be done synchronously in a separate process. 
                     <br/>The ITK waits for the export to complete and will not return 
                     any run error (except issue with creating a new Teamcenter server process). 
                     <br/>The information about the newly created dataset that contains the MS Excel 
                     only provided through a TC mail sent upon completion. */
    INPROCESSMODE    /**< The export will be done synchronously in the current Teamcenter session. 
                     <br/>The ITK waits for the export to complete and retrieves the newly created dataset 
                     that contains the MS Excel.
                     <br/>No TC mail is sent. */
} Mdl0ExportMode_t;

/**
    Defines whether configuration has to be done for Partitions only (@c PartitionConfiguration) or all objects (@c UniversalConfiguration).
*/
typedef enum Mdl0ConfigurationFor_e
{
    UniversalConfiguration,
    PartitionConfiguration
} Mdl0ConfigurationFor_t;

/**
    Search Options for a given Search (loadcount and sorting)
*/
struct Mdl0SearchOption
{
    int             n_sort_attributes;  /**< Number of sorting attributes. */
    char            **sort_attributes;  /**< List of persistent attributes of the class being searched based on which the results will be sorted. */   
    int             default_load_count; /**< For future use. Number of objects returned by this search. The rest of them could be retrieved by calling <code>fetchNextSearchResults</code>.A defaultLoadCount of zero will return all the results found. */
    Mdl0SortOrder_t sort_order;         /**< Order in which results are sorted. */
};

/**
    Defines the scope of a given search  Application model, type of objects to be returned and optionally the recipe container.
*/
typedef struct Mdl0SearchScope Mdl0SearchScope;
struct Mdl0SearchScope
{  
    tag_t   model;              /**< Application Model that scopes this search. */  
    int     n_search_types;     /**< Number of object types to be searched. */
    char    **search_types;     /**< Type of Search can restrict object types returned in the final search result. */
    tag_t   search_container;   /**< For future use. Subset or Subset Instance or Partition for which the search needs to be executed. It would also be a workset where search will be executed on each subset of this workset. When the search container is specified, there is no need to specify the recipe (search expression set) separately. */
};

/**
    Configuration mapping for various configuration object types.
*/
typedef struct Mdl0ConfigurationDetail Mdl0ConfigurationDetail;
struct Mdl0ConfigurationDetail
{  
    tag_t                   config_context;     /**< Configuration Context having configuration data (<b>RevsionRule</b> and <b>EffectivityRule</b>). */   
    Mdl0ConfigurationFor_t  configuration_for;  /**< For future use. Input ConfigurationFor structure. */
};

/**
    Group of search expressions (or Mdl0SearchDef objects) used in the search recipe
*/
typedef struct Mdl0SearchExpression Mdl0SearchExpression;
struct Mdl0SearchExpression
{
    int     n_search_Expressions;       /**< Number of Search Expression objects. */   
    tag_t   *search_expressions;        /**< Reference to the list of Search Expression objects. */ 
    logical do_trushape_refinement;     /**< true shape object flag (true or false). */
};

/**
    Building block to build complex search expressions.
*/
typedef struct Mdl0SearchExpressionSet Mdl0SearchExpressionSet;
struct Mdl0SearchExpressionSet
{   
    Mdl0Operator_t          search_operator;            /**< List of search expressions combined by the search operator. */
    Mdl0SearchExpression    search_expression;          /**< Search Expressions to be executed. In case of more than one a OR operator is assumed between these expressions. */
    int                     n_search_expression_sets;   /**< Number of search expression sets. */
    Mdl0SearchExpressionSet *search_expression_sets;    /**< List of search expressions combined by the search operator. */
};

/**
    Recipe for performing a Search
*/    
struct Mdl0SearchRecipe
{
    Mdl0SearchScope         scope;              /**< Scope of Search: Model, search types. */
    int                     n_config_details;   /**< Number of configuration details. */
    Mdl0ConfigurationDetail *config_details;    /**< Configuration Information:  Revision Rule, Effectivity Rule. */
    Mdl0SearchExpressionSet search_expression;  /**< Expression set to be evaluated : search criteria. */
};

/**
    Option for export to MS Excel.
    The columns to be export for the busienss object are determined as followings:
    <ol>
    <li>If @p n_column_attribute is greater than zero, @p column_attributes will be used.
    <li>If @p n_column_attribute is less than one and @p column_attribute_preference is not null, the value defined by the preference specified by @p column_attribute_preference will be used.
    <li>If @p n_column_attribute is less than one and @p column_attribute_preference is null, the value defined by the preference @c CPDDisplayNameColumnsShownPref will be used.
    </ol>
*/
struct Mdl0ExportOption
{
    char                *application_format;            /**< Format used to export the search result. Validate value is MSExcel. */
    Mdl0ExportMode_t    mode;                           /**< Mode for export of the search result invoked with this session. */
    char                *column_attribute_preference;   /**< Preference use to specify the columns to be exported for the business object. */
    int                 n_column_attribute;             /**< Number of columns to be exported for the business objects. */
    char                **column_attributes;            /**< n_column_attribute A list of columns to be exported for the business objects. Each element of the list should be specified in the object_type.column_name format. */
};



#endif /* __INCLUDED_MODELSEARCH_TYPES_H__ */
