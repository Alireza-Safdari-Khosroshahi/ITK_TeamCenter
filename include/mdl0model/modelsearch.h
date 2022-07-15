/*
// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2010.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Declarations of all Search ITK calls in AppModel
*/

#ifndef APPMODEL_MODELQUERY_H
#define APPMODEL_MODELQUERY_H

#include <unidefs.h>
#include <mdl0model/modelsearch_types.h>
#include <mdl0model/libmdl0model_exports.h>

/**
    @defgroup MODELSEARCH ModelSearch

    ModelSearch allows users to search for Model Elements in the context of an Application Model<br/>
    This is a APS (Advanced PLM Services) level functionality that is utilized by 4GD (4th generation Design)
    to implement the searching of Design Elements and Partitions.<br/>
    <br/>
    The set of ITK functions in this file provides the ability for customers to create APS based Search Recipes
    and execute them in a custom module.<br/>
    <br/>
    To create search recipes programmatically, developers should first create the corresponding elemental search expressions
    like (Saved Query, Box Zone, Plane Zone, Proximity). Then Group search expressions could be created using these
    elemental expression tags.<br/>
    <br/>
    This search expression could be executed to get the results or could be saved using the set and get recipe functions.<br/>
    <br/>
    For example to create a Group Search Recipe that finds Design Elements in a application model that have a name starting
    with "pipe" and is inside a box zone with diagonal coordinates as (0.5, 0.3, 0.0) and (2.0, 1.0, 0.5) (in meters), following
    will be the code snippet:<br/>
    @code
    #include <modelsearch.h>

    ::
    ::

    char ** entries;
    char ** values;
    int num_entries = 1;
    int ifail = ITK_ok;
    tag_t saved_query = NULLTAG;
    tag_t box_expr = NULLTAG;
    tag_t group_expr = NULLTAG;
    int   num_des = 0;
    tag_t  *des = NULL;

    entries = (char **)MEM_alloc( num_entries * sizeof( char * ) );
    values = (char **)MEM_alloc( num_entries * sizeof( char * ) );
    entries[0] = (char *)MEM_string_copy( "name" );
    values[0] = (char *)MEM_string_copy( "pipe*" );
    ifail = MODELSEARCH_create_saved_query_expression( "FindDesignElementQuery", num_entries, entries, values, &saved_query );

    if ( ifail == ITK_ok )
    {
        double  box_coordinates[6];
        box_coordinates[0] = 0.5; // min x
        box_coordinates[1] = 0.3; // min y
        box_coordinates[2] = 0.0; // min z
        box_coordinates[3] = 2.0; // max x
        box_coordinates[4] = 1.0; // max y
        box_coordinates[5] = 0.5; // max z
        ifail = MODELSEARCH_create_box_zone_expression( box_coordinates, Inside, &box_expr );
    }

    if ( ifail == ITK_ok )
    {
        tag_t group_exprs[2];

        group_exprs[0] = saved_query;
        group_exprs[1] = box_expr;
        ifail = MODELSEARCH_create_group_expression( And, 2, group_exprs, &group_expr );
    }

    if ( ifail == ITK_ok )
    {
        ifail = MODELSEARCH_execute_search( cd_tag, config_context, group_expr, false, true, &num_des, &des );
    }

    // results of the search are in the array variable des of size num_des
    @endcode
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
Creates a boxzone search definition tag that could be executed to find the elements inside/outside/intersecting the box.
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_box_operator if the boxOperator is not between 0 to 4 (as described in modelsearch_types.h)
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_box_zone_expression(
  const double*     box_coordinates,    /**< (I) Array of double precision numbers defining the coordinates of the bounding box */
  Mdl0BoxOperator_t box_operator,       /**< (I) Box operator. Valid values are Inside, Outside, BoxIntersect, InsideOrIntersects, OutsideOrIntersects */
  tag_t*            box_expression      /**< (O) Tag of the search expression representing this bounding box recipe */
  );

/**
Creates a Plane Zone search definition tag that could be executed to find the elements above/below/intersecting the plane.
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_plane_operator if the planeOperator is not between 0 to 4 (as described in modelsearchtypes.h)
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_plane_zone_expression(
  const double*        plane_coordinates,  /**< (I) Array of double precision numbers defining a point on the plane and the vector */
  Mdl0PlaneOperator_t  plane_operator,     /**< (I) Plane zone operator. Valid values are PlaneAbove, PlaneBelow, PlaneIntersects, PlaneAboveOrIntersects, PlaneBelowOrIntersects */
  tag_t*               plane_expression    /**< (O) Tag of the plane search defintion */
  );

/**
Creates a proximity search definition based on the distance (in meters) and the target elements.
@returns
<ul>
<li>#ITK_ok on success.
<li>#MDL0MODEL_invalid_proximity_distance if the distance exceeds the maximum prescribed Proximity distance
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_proximity_expression(
  int          num_target_elements, /**< (I) Number of target elements for the proximity expression */
  const tag_t* target_elements,     /**< (I) Tag of the target elements */
  double       distance,            /**< (I) Distance (in meters) around the target elements that needs to be searched */
  tag_t*       proximity_expression /**< (O) Tag of the Proximity search expression */
  );

/**
Creates a proximity search definition based on the distance (in meters) and the target query expression.
@returns
<ul>
<li>#ITK_ok on success.
<li>#MDL0MODEL_invalid_proximity_distance if the distance exceeds the maximum prescribed Proximity distance
<li>#MDL0MODEL_internal_error if the if the @p target_expression is invalid 
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_proximity_expression_from_target_expression(
  tag_t        target_expression,    /**< (I) Target search expression */
  double       distance,             /**< (I) Distance (in meters) around the target elements return from target expression that needs to be searched */
  tag_t*       proximity_expression  /**< (O) Tag of the Proximity search expression */
  );


/**
Creates a saved query search definition using the name of the saved query and the corresponding entries and values.
@returns
<ul>
<li>#ITK_ok on success.
<li>#QRY_not_found if the specified Saved query name could not be found
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_saved_query_expression(
  const char*    name,                  /**< (I) Name of the saved query */
  int            num_entries,           /**< (I) Number of entries and values populated in the saved query */
  const char**   entries,               /**< (I) Array of entry names (of size num_entries) */
  const char**   values,                /**< (I) Array of entry values (of size num_entries) */
  tag_t*         saved_query_expression /**< (O) Tag of Saved Query search expression */
  );

/**
Set specified properties on the search expression.
All the properties are optional
The properties for which values are specified will be set on the search expression
@returns
<ul>
<li>#ITK_ok on success.
<li>#TYPE_invalid_type_name if the return type is not valid.
<li>#MDL0MODEL_invalid_root_type if the root type is not valid.
<li>#MDL0MODEL_invalid_input if Search Expression is not valid.
<li>#MDL0MODEL_invalid_input if root type or traversal key or return type is null string.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_set_properties_on_expression(
    tag_t         search_expression,    /**< (I) Tag of Saved Query search expression.*/
    const char*   rootType,             /**< (I) (Optional) The root type to be set on search expression.*/
    const char*   traversalKey,         /**< (I) (Optional) The traversal key to be set on search expression.*/
    const char*   returnType            /**< (I) (Optional) The return yype to be on search expression.*/
);

/**
Creates a Result type search definition using the array of the result type names.
@returns
<ul>
<li>#ITK_ok on success.
<li>#MDL0MODEL_internal_error if the number of search_types is zero or if it has invalid search types
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_result_type_expression(
  int           num_types,             /**< (I) Number of search types */
  const char**  search_types,          /**< (I) Array of search type names (of size num_types) */
  tag_t*        result_type_expression /**< (O) Tag of ResultType search expression */
  );

/**
Creates an include content search definition using the target elements.<br/>
Search results obtained from execution of this expression will always include contents which belongs to the input target elements.
@returns
<ul>
<li>#ITK_ok always.
</ul>
@note If invalid tags are provided, no error is returned but an error will arise when the expression is then used.
*/
extern MDL0MODEL_API int MODELSEARCH_create_include_content_expression(
  int          num_target_elements,     /**< (I) Number of target elements for the include content expression */
  const tag_t* target_elements,         /**< (I) num_target_elements Tags of the target elements */
  tag_t*       include_expression       /**< (O) Tag of include content search expression */
  );

/**
Creates an exclude content search definition using the target elements.<br/>
Search results obtained from execution of this expression will always exclude contents which belongs to input target elemnts.
@returns
<ul>
<li>#ITK_ok always.
</ul>
@note If invalid tags are provided, no error is returned but an error will arise when the expression is then used.
*/
extern MDL0MODEL_API int MODELSEARCH_create_exclude_content_expression(
  int          num_target_elements,     /**< (I) Number of target elements for the exclude content expression */
  const tag_t* target_elements,         /**< (I) num_target_elements Tags of the target elements */
  tag_t*       exclude_expression       /**< (O) Tag of exclude content search expression */
  );

/**
Creates a group expression using other search definitions. Group operator is a boolean operator that combines these expression accordingly.
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_group_operator if the group operator is invalid or there is invalid number of expressions.
<li>#Mdl0Model_invalid_usage_of_unary_not_predicate if multiple expressions are passed with a NOT operator.
<li>#Mdl0Model_invalid_sub_expression_for_not_expression in case where Not operator is used with other than IN list expressions.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_group_expression(
  Mdl0Operator_t  group_operator,            /**< (I) Operator. Valid values are And, Or, Not. Combines the expression tags accordingly */
  int             num_exprs,                 /**< (I) Number of expressions to combine */
  const tag_t*    exprs,                     /**< (I) Expression tags to combine into a group expression */
  tag_t*          group_expr                 /**< (O) Tag of the group expression object */
  );

/**
Creates a group expression using other search definitions. Group operator is a boolean operator that combines these expression accordingly.
The specified @p group_name is set while constructing the group expression.
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_group_operator if the @p group_operator is invalid or there is invalid number of expressions.
<li>#Mdl0Model_invalid_usage_of_unary_not_predicate if multiple expressions are passed with a NOT operator.
<li>#Mdl0Model_invalid_sub_expression_for_not_expression in case where Not operator is used with other than IN list expressions.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_group_expression_with_name(
  Mdl0Operator_t  group_operator,            /**< (I) Operator. Valid values are And, Or, Not. Combines the expression tags accordingly */
  const char*     group_name,                /**< (I) Group Name string to specify name of group expresison */
  int             num_exprs,                 /**< (I) Number of expressions to combine */
  const tag_t*    exprs,                     /**< (I) num_exprs Expression tags to combine into a group expression */
  tag_t*          group_expr                 /**< (O) Tag of the group expression object */
  );

/**
Creates a option set expression using the specified @p names and @p values.
<br/>If the invalid @p transfer_option_set is specified, no error is returned but an error will arise when the @p option_set_expression is then used.
@returns
<ul>
<li>#ITK_ok always.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_option_set_expression(
  tag_t          transfer_option_set,     /**< (I) Tag of the transfer option set */
  int            num_names,               /**< (I) Number of names and values populated in the option set expression */
  const char**   names,                   /**< (I) num_names Array of names */
  const char**   values,                  /**< (I) num_names Array of name values */
  tag_t*         option_set_expression    /**< (O) Tag of Option Set search expression */
  );

/**
Creates a saved query search definition using the name of the saved query, corresponding entries and values and traversal information.
<br/>If no traversal information is supplied, the behavior is identical to #MODELSEARCH_create_saved_query_expression.
<br/>Saved Query search expressions can be created without supplying any search filter criteria i.e. n_entries = 0, entries = 0, values = 0
@returns
<ul>
<li>#ITK_ok on success.
<li>#QRY_not_found if the specified Saved query name could not be found
<li>#MDL0MODEL_invalid_root_type if the specified root_type is not a valid Teamcenter Type
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_saved_query_expression_with_traversal_info(
  const char*           query_name,              /**< (I) Saved query name */
  const unsigned int    n_entries,               /**< (I) Number of properties on which saved query search criteria specified */
  const char**          entries,                 /**< (I) n_entries List of properties on which saved query search criteria specified */
  const char**          values,                  /**< (I) n_entries List of values specified for the corresponding properties of the saved query */
  const char*           root_type,               /**< (I) The type from which traversal has to start. It can be any valid Teamcenter type */
  const char*           traversal_key,           /**< (I) Unique identifier to traverse from the root_type to the next member in the traversal hop */
  tag_t*                saved_query_expression   /**< (O) Tag of Saved Query search expression */
  );

/**
Creates a composite search definition using a composite search type and the corresponding search definitions that needs to be combined
@returns
<ul>
<li>#ITK_ok on success.
<li>#MDL0MODEL_invalid_composite_search_type if the specified composite search type is not valid type
<li>#MDL0MODEL_invalid_composite_search_defs if the list of expressions to combine is empty
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_composite_search_expression(
  const char*           composite_search_type,          /**< (I) Type of the Composite Search. Valid values are "bom_properties_based_de_search", "bom_properties_based_pu_search" */
  const unsigned int    n_expressions,                  /**< (I) Number of expressions to combine */
  const tag_t*          expressions,                    /**< (I) n_expressions List of expressions to combine */
  tag_t*                composite_search_expression     /**< (O) Tag of Composite Search Expression */
  );

/**
@returns
<ul>
<li>#ITK_ok on success.
<li>#MDL0MODEL_invalid_proximity_target where proximity search is used with invalid proximity targets (missing bounding box for proximity targets).
<li>#MDL0MODEL_invalid_trushape_data_target where proximity targets are missing trushape data and the applyTrushape flag is true.
<li>#MDL0MODEL_not_expression_cannot_be_root in case where a search execution is attempted with a recipe having the Not group as the root expression.
<li>#MDL0MODEL_invalid_saved_query_in_search where a Saved query recipe has a class that is not valid for this search (e.g. a saved query that searches for non-4GD objects).
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_execute_search(
  tag_t       application_model,      /**< (I) Tag of the application model (or any relevant application model) */
  tag_t       config_context,         /**< (I) Tag of configuration context that has the associated revision rule and other configuration conditions */
  tag_t       search_recipe,          /**< (I) Tag of the search definition object */
  logical     apply_trushape,         /**< (I) Flag indicating whether to perform Trushape filtering or not */
  logical     load_results,           /**< (I) Flag indicating whether to load the search results or not */
  int*        num_objects,            /**< (O) Number of objects returned by the search */
  tag_t**     model_elements          /**< (OF) num_objects Array of tags returned by the search */
  );

/**
Executes a search in an Application Model for the given Configuration Context using the search recipe in the
search container object. The returned objects are model elements in the Application Model. The results
could be automatically loaded based on the loadElements flag.
The return codes are:
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_group_operator if any of the operators are invalid.
<li>#Mdl0Model_invalid_usage_of_unary_not_predicate if a NOT operator is used with multiple search expressions.
<li>#MDL0MODEL_invalid_revision_rule_clause if the supplied revision rule contains a clause that is not accepted by 4GD.
<li>#MDL0MODEL_invalid_proximity_target if the proximity search has a target without a bounding box.
<li>#MDL0MODEL_invalid_trushape_data_target if the proximity search has a target without a TSO and tso filter is enabled.
<li>#MDL0MODEL_invalid_proximity_distance if the proximity search has a distance greater than 1000000000000000.0 meters.
<li>#MDL0MODEL_invalid_ConfigurationContext if the given Configuration Context tag has been deleted or lost (due to a server restart).
<li>#Mdl0Model_invalid_recipe_container if the search container object does not have an associated recipe container behavior.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_execute_search_by_container(
  tag_t       search_container,         /**< (I) Tag of the search container (subset or partition) */
  tag_t       config_context,           /**< (I) Tag of the Configuration Context */
  logical     load_elements,            /**< (I) Flag indicating whether the search results should be loaded or not */
  int*        number_of_elements,       /**< (O) Number of objects found */
  tag_t**     model_elements            /**< (OF) number_of_elements Tag of the objects found */
  );

/**
Sets the search recipe on a search container and persist in the Teamcenter database.
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_recipe_container if the container object does not exhibit the recipe container behavior.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_set_recipe_on_container(
  tag_t       application_model,      /**< (I) Tag of the application model (or any relevant application model) */
  tag_t       config_context,         /**< (I) Tag of configuration context that has the associated revision rule and other configuration conditions */
  tag_t       search_recipe,          /**< (I) Tag of the search definition object */
  logical     apply_trushape,         /**< (I) Flag indicating whether to perform Trushape filtering or not */
  tag_t       container               /**< (I) Tag of the search container on which the search recipe needs to be set */
  );

/**
Retrieves the recipe context (application model) and config context from specified  @p container
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_recipe_container if the container object does not exhibit the recipe container behavior.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_get_configuration_from_container(
  const tag_t container,              /**< (I) Tag of the search container */
  tag_t*      application_model,      /**< (O) Tag of the application model */
  tag_t*      config_context          /**< (O) Tag of the configuration context attached to the container */  
  );


/**
Retrieves the search recipe from a search container that was persisted in the Teamcenter database.
@returns
<ul>
<li>#ITK_ok on success.
<li>#Mdl0Model_invalid_recipe_container if the container object does not exhibit the recipe container behavior.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_get_recipe_from_container(
  tag_t       container,              /**< (I) Tag of the search container */
  tag_t*      application_model,      /**< (O) Tag of the application model (or the application model) */
  tag_t*      config_context,         /**< (O) Tag of the configuration context attached to the container */
  tag_t*      search_recipe,          /**< (O) Tag of the search definition object */
  logical*    apply_trushape          /**< (O) Flag indicating trushape filtering option */
  );

/**
Retrieves the configuration context for a given revision rule.
@returns
<ul>
<li>#ITK_ok on success.
<li>#POM_invalid_tag if the input tag is invalid.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_configuration_context(
  const char*   revision_rule,                  /**< (I) Revision rule string */
  tag_t*        configuration_context           /**< (O) Configuration context */
  );

/**
Retrieves configuration context for input revision rule and variant rule.

@returns
<ul>
<li>#ITK_ok on success.
<li>#POM_invalid_tag if the input tag is invalid.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_configuration_context_with_rule_and_variant (
  const tag_t   revision_rule,                  /**< (I) Revision rule tag */
  const tag_t   variant_rule,                   /**< (I) Variant rule tag */
  tag_t*        configuration_context           /**< (O) Configuration context */
  );

/**
Retrieves the Configuration Context for a Revision Rule and a list of Variant Rules.

@returns
<ul>
<li>#ITK_ok on success.
<li>#COLLABCTX_invalid_revision_rule if @p revision_rule is not a valid Revision Rule.
<li>#COLLABCTX_invalid_variant_rule if any Variant Rule in @p variant_rules is invalid.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_create_configuration_context_with_rule_and_variants (
  const tag_t           revision_rule,                  /**< (I) Revision rule tag */
  const unsigned int    n_variant_rules,                /**< (I) Number of variant rules */
  const tag_t*          variant_rules,                  /**< (I) n_variant_rules The Variant Rules */
  tag_t*                configuration_context           /**< (O) Configuration context */
  );

/**
 Creates an "IncludeAll" search definition that can be executed to retrieve the content of the entire model.
 @returns #ITK_ok always.

*/
extern MDL0MODEL_API int MODELSEARCH_create_include_all_expression(
  tag_t*        include_all_expression /**< (O) The created IncludeAll search expression */
  );

/**
    Sets the search recipe along with the search filter list or domain view key on a search container, and persists it in the Teamcenter database.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MDL0MODEL_missing_model_behavior if the @p application_model object is missing the model behavior.
    <li>#CXPOM_invalid_tag if the @p config_context input tag is invalid.
    <li>#MDL0MODEL_type_not_expected if the @p search_recipe object is not of type Mdl0SearchDef.
    <li>#Mdl0Model_invalid_recipe_container if the @p container object does not exhibit the recipe container behavior.
</ul>
*/
extern MDL0MODEL_API int MODELSEARCH_set_recipe_on_container_with_filters(
    const tag_t         application_model,      /**< (I) The application model (or any relevant application model). 
                                                    <br/>The object should have model behavior or NULLTAG is also allowed. */
    const tag_t         config_context,         /**< (I) The configuration context that has the associated revision rule and other configuration conditions. */
    const tag_t         search_recipe,          /**< (I) The search definition object of type Mdl0SearchDef. NULLTAG is also allowed. */
    const int           n_filter_list,          /**< (I) Number of filter list object type names. */
    const char**        filter_list,            /**< (I) n_filter_list Array of object types allowed in the search results. Objects that are not of these types will be silently discarded.
                                                    <br/>If the list is empty, any object that matches the search recipe will be included in the search results. */
    const char*         domain_view_key_name,   /**< (I) Domain view key string that refers to the preference name from which the filter type list is to be retrieved.
                                                    <br/>If an empty or invalid string is passed than this parameter is silently ignored and filter type list is not populated. */
    const logical       apply_trushape,         /**< (I) Flag indicating whether to perform Trushape filtering on search results or not. */
    const tag_t         container               /**< (I) The search container object on which the search recipe needs to be set. It should exhibit the recipe container behavior. */
  );

/**
    Retrieves the search recipe along with the search filter list and domain view key, if they exists, from a search container that was persisted in the Teamcenter database.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#Mdl0Model_invalid_recipe_container if the @p container object does not exhibit the recipe container behavior.
    </ul>
*/
extern MDL0MODEL_API int MODELSEARCH_get_recipe_from_container_with_filters(
    const tag_t     container,              /**< (I) The search container from which the recipe needs to be retrieved. It should exhibit the recipe container behavior. */
    tag_t*          application_model,      /**< (O) The application model (or any relevant application model). */
    tag_t*          config_context,         /**< (O) The configuration context attached to the container. */
    tag_t*          search_recipe,          /**< (O) The search definition object. */
    int*            n_filter_list,          /**< (O) Number of filter list object type names. */
    char***         filter_list,            /**< (OF) n_filter_list Array of object types allowed in the search results. Objects which are not of these types will be silently discarded.
                                                   <br/>If the list is empty, any object that matches the search recipe will be included in the search results.
                                                   <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    char**          domain_view_key_name,   /**< (OF) Domain view key string which refers to the preference name from which the filter type list is to be retrieved. */
    logical*        apply_trushape          /**< (O) Flag indicating whether to perform Trushape filtering on search results or not. */
  );

#ifdef __cplusplus
}
#endif

/** @} */

#include <mdl0model/libmdl0model_undef.h>
#endif
