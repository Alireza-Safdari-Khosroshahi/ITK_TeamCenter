/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef MDL0_SERVICES_MODELCORE__2011_06_SEARCH_HXX
#define MDL0_SERVICES_MODELCORE__2011_06_SEARCH_HXX

#include <teamcenter/soa/client/model/ClosureRule.hxx>
#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/ImanQuery.hxx>
#include <teamcenter/soa/client/model/Mdl0ApplicationModel.hxx>
#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>
#include <teamcenter/soa/client/model/Mdl0SearchCursor.hxx>
#include <teamcenter/soa/client/model/Mdl0SearchDef.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            namespace _2011_06
            {
                class Search;

class MDL0SOAMODELCORESTRONGMNGD_API Search
{
public:

    struct BoxZoneExpression;
    struct BoxZoneExpressionInput;
    struct ClosureQueryExpression;
    struct ClosureQueryExpressionInput;
    struct ConfigOutput;
    struct ConfigResponse;
    struct ConfigurationData;
    struct ConfigurationDetail;
    struct ExpressionResponse;
    struct ModelElementInput;
    struct PlaneZone;
    struct PlaneZoneExpression;
    struct PlaneZoneExpressionInput;
    struct ProximityExpression;
    struct ProximitySearchExpressionInput;
    struct SearchScope;
    struct SearchExpression;
    struct SearchExpressionSet;
    struct SearchRecipe;
    struct RecipeData;
    struct RecipeResponse;
    struct SavedQueryExpression;
    struct SavedQueryExpressionInput;
    struct SearchBox;
    struct SearchCursor;
    struct SearchExpressionInput;
    struct SearchExpressionResponse;
    struct SearchOptions;
    struct SearchResponse;
    struct StopSearchResponse;

    /**
     * Operator for box zone expressions
     */
    enum BoxOperator{ Inside,
                 Outside,
                 Intersects,
                 InsideOrIntersects,
                 OutsideOrIntersects
                 };

    /**
     * Various configuration types.
     */
    enum ConfigurationFor{ Universal,
                 Partition
                 };

    /**
     * There are 5 different operators to search using a plane zone. Essentially searching
     * above or below or intersecting the plane as the name of the operator suggests.
     */
    enum PlaneZoneOperator{ Plane_above,
                 Plane_below,
                 Plane_intersects,
                 Plane_aboveOrIntersects,
                 Plane_belowOrIntersects
                 };

    /**
     * Boolean operator to combine multiple search expressions
     */
    enum SearchOperator{ And,
                 Or,
                 Not
                 };

    /**
     * <code>SortOrder</code> defnes the order in which the results are sorted (Ascending
     * or Descending) ) based on the attributes used for the sort
     */
    enum SortOrder{ Ascending,
                 Descending
                 };

    /**
     * Expression to search in Box Zone
     */
    struct BoxZoneExpression
    {
        /**
         * A list of 3D box coordinate definitions. Even though the structure is specifying
         * a list of boxes, the current implementation processes only one Box (first one) and
         * the list is just for future expansion purposes.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::SearchBox > searchBoxes;
        /**
         * specifies the search operation i.e. inside or outside or intersecting the box.
         */
        BoxOperator boxOperator;
    };

    /**
     * Box Zone Expression Input Structure
     */
    struct BoxZoneExpressionInput
    {
        /**
         * Box zone expression, contains the definition of the coordinates to a spatial 3D box.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::BoxZoneExpression boxZoneExpression;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Elemental Closure Query Expression - No Implementation in Tc9
     */
    struct ClosureQueryExpression
    {
        /**
         * Reference to the <b>ClosureRule</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ClosureRule>  closureRule;
        /**
         * Reference to the <b>Mdl0SearchDef</b> object that represents the rest of the search
         * expression.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  searchCriteria;
    };

    /**
     * Closure Query Expression Input Data Structure - NO IMPLEMENTATION in Tc9
     */
    struct ClosureQueryExpressionInput
    {
        /**
         * Search Expression representing the closure rule.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::ClosureQueryExpression closureExpression;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Output Data Structure for Configuration Data
     */
    struct ConfigOutput
    {
        /**
         * Configuration Context Object Reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
        /**
         * Client ID to track response with request
         */
        std::string clientid;
    };

    /**
     * Response for a <code>createOrUpdateConfigurations</code> operation. Returns runtime
     * configuration objects
     */
    struct ConfigResponse
    {
        /**
         * Service data for any error information. Following are possible partial errors in
         * the <code>ServicData</code> structure:
         * <br>
         * <ul>
         * <li type="disc"><code>MDL0MODEL_invalid_revision_rule_clause (278030)</code>  The
         * revision rule used to create a <b>ConfigurationContext</b> object has invalid clauses
         * (clauses not valid for CPD application).
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Configuration Context output structure. Contains the reference to the Configuration
         * Context object reference and the corresponding client id to match up the input.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ConfigOutput > configContext;
    };

    /**
     * Configuration Input Data structure that is used to create or modify a configuration
     * context object
     */
    struct ConfigurationData
    {
        /**
         * Run time Config object that carries the configuration data
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
        /**
         * Revision Rule that carries revision and effectivity configuration
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revisionRule;
        /**
         * Variant Rule (Tc9 -  No Operation) for future use
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  variantRule;
        /**
         * Client ID for tracking configuration response
         */
        std::string clientid;
    };

    /**
     * Configuration mapping for various configuration object types.
     */
    struct ConfigurationDetail
    {
        /**
         * Configuration type.This could be <code>Universal</code> or <code>Partition</code>.
         */
        ConfigurationFor configurationFor;
        /**
         * Configuration Context having configuration data(Revsion Rule and Effectivity Rule).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
    };

    /**
     * Expression Response structure that carries the search expressions created in the
     * server
     */
    struct ExpressionResponse
    {
        /**
         * Reference to the <b>Mdl0SearchDef</b> object which is the search expression object
         * created based on the input expression type information.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  searchDef;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.t
         */
        std::string clientid;
    };

    /**
     * Model Element Input Data Structure. Special case for ModelElement input is the creation
     * of Empty Expression. If the set of Model Elements is empty then createSearchExpressions
     * will create an Empty Expression (Mdl0SearchDef object)
     */
    struct ModelElementInput
    {
        /**
         * Reference to the list of <b>Mdl0ModelElement</b> objects used to create the select
         * content search expression.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > modelElements;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Coordinates for a Plane Zone
     */
    struct PlaneZone
    {
        /**
         * X-Value
         */
        double xvalue;
        /**
         * Y-Value
         */
        double yvalue;
        /**
         * Z-Value
         */
        double zvalue;
        /**
         * distance vector normal to the plane.
         */
        double displacement;
    };

    /**
     * Expression to model Plane Zone Search
     */
    struct PlaneZoneExpression
    {
        /**
         * Definition of the 3D plane.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::PlaneZone planeZone;
        /**
         * The operation type i.e. Search above the plane or below the plane or intersecting
         * the plane.
         */
        PlaneZoneOperator planeZoneOperator;
    };

    /**
     * Plane Zone Input Structure
     */
    struct PlaneZoneExpressionInput
    {
        /**
         * 3D plane expression around which the spatial search is performed.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::PlaneZoneExpression planeZoneExpression;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * search expression structure for proximity search
     */
    struct ProximityExpression
    {
        /**
         * List of target Model Elements whose proximity is searched.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > targetElements;
        /**
         * A floating point number specifying the distance to search. This number has to be
         * a positive number.
         */
        double distance;
        /**
         * A select content Search expression that references a set of target model elements.
         * This is an alternative way of specifying the target. Either of <code>targetElements</code>
         * vector or the <code>targetElement</code> object is expected to be populated in this
         * structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  targetElement;
    };

    /**
     * Proximity Expression Input - Request Structure
     */
    struct ProximitySearchExpressionInput
    {
        /**
         * Proximity Search Expression. Contains reference to the target elements whose proximity
         * is searched and the distance to search.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::ProximityExpression proximityExpression;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Scope for this Search (Model and type of Search)
     */
    struct SearchScope
    {
        /**
         * Application Model that scopes this search
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  model;
        /**
         * Type of Search   can restrict object types returned in the final search result
         */
        std::vector< std::string > searchType;
        /**
         * Subset or Subset Instance or Partition for which the search needs to be executed.
         * When the recipe container is specified, there is no need to specify the recipe (search
         * expression set) separately.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  recipeContainer;
    };

    /**
     * Group of search expressions (or <b>Mdl0SearchDef</b> objects) used in a search recipe
     */
    struct SearchExpression
    {
        /**
         * Reference to the list of Search Expression Objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  > searchExpressions;
        /**
         * true shape object flag (true or false).
         */
        bool doTrushapeRefinement;
    };

    /**
     * Building block to build complex search expressions
     */
    struct SearchExpressionSet
    {
        /**
         * List of search expressions combined by the search operator.
         */
        SearchOperator searchOperator;
        /**
         * Search Expressions to be executed. In case of more than one a OR operator is assumed
         * between these expressions.Either one of the properties  will be populated i.e. <code>searchOperator</code>
         * and <code>searchExpressionSets</code> or the <code>searchExpression</code>, in a
         * structure.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::SearchExpression searchExpression;
        /**
         * List of search expressions combined by the search operator.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::SearchExpressionSet > searchExpressionSets;
    };

    /**
     * Recipe for executing the Search
     */
    struct SearchRecipe
    {
        /**
         * Scope of Search  Model, search types
         */
        Mdl0::Services::Modelcore::_2011_06::Search::SearchScope scope;
        /**
         * Configuration Information  Revision Rule, Effectivity Rule
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ConfigurationDetail > configDetails;
        /**
         * Expression set to be evaluated  search criteria
         */
        Mdl0::Services::Modelcore::_2011_06::Search::SearchExpressionSet searchExpression;
    };

    /**
     * This data structure associates a search recipe to its recipe container. It is used
     * to save search recipes against a recipe container.
     */
    struct RecipeData
    {
        /**
         * Object reference to a recipe container. This object could be either of
         * <br>
         * <ul>
         * <li type="disc"><b>Mdl0SubsetDefinition</b>
         * </li>
         * <li type="disc"><b>Cpd0DesignSubsetInstance</b>
         * </li>
         * <li type="disc"><b>Ptn0Partition</b>
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  recipeContainer;
        /**
         * Associated Search Recipe. The Search Recipe is defined by the SearchRecipe data structure,
         * which has the following contents:
         * <br>
         * <ul>
         * <li type="disc"><code>scope</code>   Scope of the Search (Application Model, search
         * types).
         * </li>
         * <li type="disc"><code>configDetails</code>   Configuration information used in the
         * search (<b>Revision Rule and Effectivity Rule</b>).
         * </li>
         * <li type="disc"><code>searchExpression</code>   Top level <code>SearchExpressionSet</code>
         * that could be any level deep and defines a complex search recipe by combining the
         * elemental Search Expressions created by <code>createSearchExpressions</code> operation.
         * </li>
         * </ul>
         */
        Mdl0::Services::Modelcore::_2011_06::Search::SearchRecipe recipe;
    };

    /**
     * Response for a Get Recipe Call. Returns the search recipe attached to a <b>RecipeContainer</b>.
     */
    struct RecipeResponse
    {
        /**
         * Service Data for error information. The following are errors thrown by the <code>getRecipes</code>
         * operation in the <code>ServiceData</code> structure:
         * <br>
         * <code>Mdl0Model_invalid_recipe_container (278017)</code>   The recipe container object
         * passed as input is not a valid recipe container object. The recipe container has
         * to be one of <b>Mdl0SubsetDefinition</b>, <b>Ptn0Partition</b> or <b>Cpd0DesignSubsetInstance</b>.
         * <br>
         * <code>MDL0MODEL_invalid_recipe_to_load (278027)</code>  The recipe container object
         * has a search recipe that is not a valid object. The search criteria objects are of
         * class <b>ApprSearchCriteria</b> (and its subtypes) and if these are combined in a
         * fashion that is not readable by the CPD application then this error would be thrown
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Recipe Data for the given <b>RecipeContainer</b> objects. The <code>RecipeData</code>
         * structure returns the following information:
         * <br>
         * <ul>
         * <li type="disc"><code>recipeContainer</code>  The reference to the <b>RecipeContainer</b>
         * object from which the recipe is retrieved .
         * </li>
         * <li type="disc"><code>recipe</code>   The <code>SearchRecipe</code> data structure
         * that returns the scope, configuration details and the search expression set that
         * represents the stored search recipe.
         * </li>
         * </ul>
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::RecipeData > searchRecipes;
    };

    /**
     * Expression for searching with a Saved Query
     */
    struct SavedQueryExpression
    {
        /**
         * Reference to a <b>ImanQuery</b> object that represents a saved query.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanQuery>  savedQuery;
        /**
         * List of entries specified in the saved query for which the values are populated.
         */
        std::vector< std::string > entries;
        /**
         * List of values for the specified entries and the values may have wild card entries
         * as well.
         */
        std::vector< std::string > values;
    };

    /**
     * Saved query Expression Input Data Structure
     */
    struct SavedQueryExpressionInput
    {
        /**
         * Search expression for a saved query search.
         */
        Mdl0::Services::Modelcore::_2011_06::Search::SavedQueryExpression savedQueryExpression;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Search Box data strcture
     */
    struct SearchBox
    {
        /**
         * X Minimum
         */
        double xmin;
        /**
         * Y Minimum
         */
        double ymin;
        /**
         * Z Minimum
         */
        double zmin;
        /**
         * X Maximum
         */
        double xmax;
        /**
         * Y Maximum
         */
        double ymax;
        /**
         * Z Maximum
         */
        double zmax;
        /**
         * NOT Implemented as of now. For future use to define rotated 3D boxes.
         */
        std::vector< double > transform;
    };

    /**
     * Search Cursor data structure for getting the next set of search results.
     */
    struct SearchCursor
    {
        /**
         * Search Cursor Object Reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchCursor>  cursor;
        /**
         * Count of Next set of objects to be loaded
         */
        int loadCount;
    };

    /**
     * Input Data Structure to create the Group of Elemental Search Expressions
     */
    struct SearchExpressionInput
    {
        /**
         * Input for creating Proximity Search Expressions. Contains reference to a set of <code>ModelElements</code>
         * (that are targets) and the proximity distance.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ProximitySearchExpressionInput > proximitySearchExpressions;
        /**
         * input for creating box zone search expressions. Contains the Min and Max coordinated
         * of a test Box definition.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::BoxZoneExpressionInput > boxZoneExpressions;
        /**
         * input for creating plane zone search expressions. Contains a point in the plane and
         * the normal vector definition.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::PlaneZoneExpressionInput > planeZoneExpressions;
        /**
         * input for creating saved query search expressions. Contains reference to a stored
         * saved query object and a coordinated list of entries and values to be used in the
         * saved query. Some queries may contain empty list for entries and values (depends
         * on the definition of the Saved Query). Wildcards are accepted for values in the Saved
         * Query.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::SavedQueryExpressionInput > savedQueryExpressions;
        /**
         * Closure Query Expression  that traverses results using a closure rule  Not implemented
         * in Tc9.1.0.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ClosureQueryExpressionInput > closureQueryExpression;
        /**
         * References to elements to be included into the search results. The server creates
         * a Search Expression for this input as well, so that it could be combined with other
         * search expressions in a search recipe.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ModelElementInput > includeElements;
        /**
         * Reference to elements that should be explicitly excluded in the search results. Again
         * a search expression is returned for the exclude elements so that it could be combined
         * with other search expressions in a search recipe.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ModelElementInput > excludeElements;
    };

    /**
     * Response data structure that returns the Search Expression objects created for the
     * given Search Expression Input data structures.
     */
    struct SearchExpressionResponse
    {
        /**
         * Service Data for any error information. Any malformed input expressions will result
         * in an ITK error being returned in the service data. Following errors are possible
         * partial errors returned in the <code>ServiceData</code>:
         * <br>
         * <ul>
         * <li type="disc"><code>Mdl0Model_invalid_box_operator</code> (278010)   Invalid box
         * zone operator in the box zone expression input structure.
         * </li>
         * <li type="disc"><code>Mdl0Model_invalid_plane_operator</code> (278015)   Invalid
         * plane zone operator in the plane zone expression input structure.
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of <code>ExpressionResponse</code> structures that has the search expression
         * object embedded. Each <code>ExpressionResponse</code> structure consists of a reference
         * to an <b>Mdl0SearchDef</b> object and the corresponding clientid (based on the clientid
         * of input data).
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ExpressionResponse > expressions;
    };

    /**
     * Search Options for a given Search (loadcount and sorting)
     */
    struct SearchOptions
    {
        /**
         * List of persistent properties of the class being searched based on which the results
         * will be sorted
         */
        std::vector< std::string > sortAttributes;
        /**
         * Number of objects returned by this search. The rest of them could be retrieved by
         * calling <code>fetchNextSearchResults</code>. A <code>defaultLoadCount</code> of zero
         * will return all the results found.
         */
        int defaultLoadCount;
        /**
         * order in which results are sorted   Ascending or Descending.
         */
        SortOrder sortOrder;
    };

    /**
     * Response SOA Structure for results
     */
    struct SearchResponse
    {
        /**
         * The next list of objects returned by the <code>fetchNextSearchResults</code> operation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > modelElements;
        /**
         * This flag will be true if there are no more search results for this <code>executeSearch</code>
         * operation.
         */
        bool finished;
        /**
         * An integer value specifying the number of objects returned so far for this <code>executeSearch</code>
         * operation
         */
        int elementsDone;
        /**
         * An integer value specifying the estimated number of objects that still are potentially
         * results of this search.
         */
        int estimatedElementsLeft;
        /**
         * Search cursor object that tracks the search results. This object is used to get the
         * next set of results for this <code>executeSearch</code> operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchCursor>  searchCursor;
        /**
         * Service Data for any error information. Typically this will contain errors about
         * any malformed search recipes. E.g. an invalid proximity target (an object without
         * geometrical information)
         * <br>
         * Following are some of the error codes that may be populated as partial errors in
         * the <code>ServiceData</code> object:
         * <br>
         * <ul>
         * <li type="disc"><code>MDL0MODEL_invalid_proximity_target (278033)</code>   A spatial
         * proximity search recipe that has no valid proximity targets. The target element has
         * no bounding box populated in the database.
         * </li>
         * <li type="disc"><code>MDL0MODEL_invalid_trueshape_object (278034)</code>  A spatial
         * proximity search recipe that has targets without a valid trueshape object. This error
         * is thrown when the tso_flag is set to true in the input <code>SearchExpressionSet</code>.
         * </li>
         * <li type="disc"><code>MDL0MODEL_invalid_revision_rule_clause (278030)</code>  The
         * revision rule used to create a <b>ConfigurationContext</b> object has invalid clauses
         * (clauses not valid for CPD application).
         * </li>
         * <li type="disc"><code>MDL0MODEL_invalid_set_of_sort_attributes (278028)</code>  The
         * Sort options has a sort attribute that is not valid for the current search. The sort
         * attribute should be an attribute of the objects found in the search. The database
         * query does not support runtime or compound properties as sort attributes.
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response Data for StopSearch Operation
     */
    struct StopSearchResponse
    {
        /**
         * A Boolean flag with true value indicating the successful deletion of the search cursor
         * and removal of server memory allocated by the search operation.
         */
        bool finished;
        /**
         * Service Data for any error information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation creates a configuration context (<b>ConfigurationContext</b>) object
     * (or updates a configuration context object). In CPD, the configuration information
     * is kept track using a Configuration Context object. This object is not persisted
     * in the Database. It is just created and kept alive until the session is active and
     * destroyed when the user logs out.
     * <br>
     * A configuration context keeps track of the Revision Rule (with any attached Effectivity
     * Conditions) (and in the future would keep track of variant rule as well) created/used
     * by a client session. In Teamcenter 9.1.0, minor revisioning is not supported in CPD.
     * When minor revisioning is introduced in Teamcenter 10.1.0, then the configuration
     * context will also serve the purpose of allocating a cparam for the corresponding
     * Revision Rule used by the client session.
     * <br>
     * cparam is an object used by the POM revisioning framework to configure the correct
     * minor revision of a reviseable object being used.
     * <br>
     * A configuration context created could be used by the caller during <code>executeSearch</code>
     * or any other operation that requires the revision and effectivity configuration settings.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the use case of creating and maintaining configuration context
     * objects with different Revision and Effectivity configurations. Also in the future,
     * this will be extended to keep track of cparam objects to pick the correct minor revision
     * (historical revision) of the object.  The configuration context objects thus created
     * are used during execution of a CPD search operation or other operations such <code>getMembers</code>
     * on a partition.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateConfigurations
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param configData
     *        Input data structure to create configuration context objects with associated Revision
     *        Rule and other configuration conditions.
     *
     * @return
     *         Returns ConfigResponse data structure.This operation returns runtime configuration
     *         context objects.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::ConfigResponse createOrUpdateConfigurations ( const std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ConfigurationData >& configData ) = 0;

    /**
     * This operation creates the elemental search expressions that could be combined using
     * logical operators to build up a complex search recipe in CPD application. The <code>createSearchExpressions</code>
     * operation could be used to create multiple search expressions at the same time. The
     * following types of expressions could be created by this operation
     * <br>
     * <ul>
     * <li type="disc">Bounding Box Expression (<b>Mdl0SearchBoxZone</b>)
     * </li>
     * <li type="disc">Plane Zone Expression (<b>Mdl0SearchPlaneZone</b>)
     * </li>
     * <li type="disc">Proximity Expression (<b>Mdl0SearchProximity</b>)
     * </li>
     * <li type="disc">Saved Query Expression (<b>Mdl0SearchSavedQuery</b>)
     * </li>
     * <li type="disc">Include Content Expression (<b>Mdl0SearchSlctContent</b>)
     * </li>
     * <li type="disc">Exclude Content Expression (<b>Mdl0SearchGroup</b>)
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The <code>createSearchExpressions</code> is a required operation before an <code>executeSearch</code>
     * or <code>setRecipes</code> call is made. This operation creates the runtime Search
     * Definition objects based on the input search expression data structures. The intent
     * of this operation is to create all the individual elemental search expressions so
     * that they could be combined using logical operators (AND/OR/NOT) to create a complex
     * search recipe.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createSearchExpressions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param searchExpInput
     *        Search Expression Input Structure
     *
     * @return
     *         SearchExpressionResponse data structure that returns the Search Expression objects
     *         created for the given Search Expression Input data structures.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::SearchExpressionResponse createSearchExpressions ( const Mdl0::Services::Modelcore::_2011_06::Search::SearchExpressionInput&  searchExpInput ) = 0;

    /**
     * Operation that executes a search based on an input Search Recipe and returns the
     * list of Model Elements (<b>Mdl0ModelElement</b>) back to the caller. Search Recipe
     * could be a complex expression set that combines multiple simpler search terms (both
     * spatial and non spatial) in a logical sequence.
     * <br>
     * Search is always executed within the scope of an Application Model and all the Model
     * Elements returned belong to the given Application Model. <code>executeSearch</code>
     * operation uses the configuration information given in the recipe to configure the
     * results of a search (Both Revision and Effectivity Configurations).
     * <br>
     * The results of a search are returned one set at a time based on the <code>defaultLoadCount</code>
     * specified in the <code>SearchOptions</code>. The <code>SearchResponse</code> also
     * contains a Search Cursor object that the caller could use to fetch the next set of
     * results by invoking the <code>fetchNextSearchResults</code> call. Search options
     * also gives the caller the ability to sort the results of a search using any (one
     * or more) of the attributes of the returned objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API provides the ability for searching Model Content in a given Application
     * Model. Application Model is a construct in AppModel template that defines an abstract
     * boundary in which content could be populated. The populated model content is called
     * Model Element which again is an abstract object which has some basic attributes such
     * as an ID, revision Id, name and description.
     * <br>
     * CPD has specialized the Application Model to be a Collaborative Design and the Model
     * Element to be a Design Element. In this context, the <code>executeSearch</code> API
     * provides the ability to Search for Design Elements in a Collaborative Design using
     * various Search terms (combined together as a Search Recipe).
     * <br>
     * The Search term could be spatial (searching for objects in a 3d space specified by
     * a bounding box or a 3d plane or proximity to another Design Element) or an attribute
     * term (Saved Query searching for Design Elements with specific attribute values/patterns)
     * or a partition term (Searching for membership in specific segments of a Collaborative
     * Design).
     * <br>
     * The results of the execute search operation could be constrained by the search scope
     * which is part of the search recipe and organized by the search options.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getConfigurableProducts, getEffectivityConditions, fetchNextSearchResults, stopSearch
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param recipe
     *        Recipe for executing the search
     *
     * @param options
     *        Search Options for a given Search (load count and sorting)
     *
     * @return
     *         Returns the <code>SearchResponse</code> object
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::SearchResponse executeSearch ( const Mdl0::Services::Modelcore::_2011_06::Search::SearchRecipe&  recipe,
        const Mdl0::Services::Modelcore::_2011_06::Search::SearchOptions&  options ) = 0;

    /**
     * This operation gets the next set of Model Elements from a previously executed search
     * results. The results returned will be based on the load count specified in the <code>SearchCursor</code>
     * input structure. This API returns the same response structure as that of <code>executeSearch</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API is used in conjunction with <code>executeSearch</code> operation. executeSearch
     * operation is a prerequisite for invoking <code>fetchNextSearchResults</code>. The
     * search cursor returned by the <code>executeSearch</code> is used to call <code>fetchNextSearchResults</code>
     * operation. This operation could be called repeatedly by the caller, until all the
     * search results are returned.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * fetchNextSearchResults
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param searchCursor
     *        <code>searchCursor</code>  Search Cursor Data Structure Input. This data structure
     *        has 2 parameters
     *        <br>
     *        <ul>
     *        <li type="disc"><code>cursor</code>  A runtime object identifier that keeps track
     *        of the Search results and the corresponding indexes as of where the caller has consumed
     *        the results
     *        </li>
     *        <li type="disc"><code>loadCount</code>  An integer number that specifies the number
     *        of objects to be fetched from the Search result set. If the <code>loadCount</code>
     *        is zero (or more than the number of objects left in the result set) then all the
     *        remaining objects in the result set is returned.
     *        </li>
     *        </ul>
     *
     * @return
     *         Returns the <code>SearchResponse</code> structure
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::SearchResponse fetchNextSearchResults ( const Mdl0::Services::Modelcore::_2011_06::Search::SearchCursor&  searchCursor ) = 0;

    /**
     * This operation retrieves the stored recipe against a set of recipe container objects.
     * The persistent objects used to store the search recipe in Teamcenter are objects
     * that do not have lifecycle by itself, so they are always associated to objects that
     * exhibit the <b>RecipeContainer</b> behavior. In the current CPD application there
     * are three objects that exhibit <b>RecipeContainer</b> behavior. They are
     * <br>
     * <ul>
     * <li type="disc"><b>Mdl0SubsetDefinition</b>:  object to store a search recipe (without
     * the results)
     * </li>
     * <li type="disc"><b>Ptn0Partition</b>:   A dynamic partition that executes the search
     * recipe to find its members
     * </li>
     * <li type="disc"><b>Cpd0DesignSubsetInstance</b>:  A realization object that takes
     * a subset of a Collaborative Design and instantiates into a Workset.
     * </li>
     * </ul>
     * <br>
     * The retrieved recipe from the recipe container is translated to the data structures
     * defined in the Search SOA service and then it is presented back to the caller.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the use case of retrieving a stored search recipe from Teamcenter
     * DB against a recipe container object. The retrieved recipe could be reexecuted by
     * calling <code>executeSearch</code> operation.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getRecipes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param recipeContainers
     *        reference to <b>RecipeContainer</b> Objects. The input vector could contain any Teamcenter
     *        object that exhibits a <b>RecipeContainer</b> behavior.
     *
     * @return
     *         Returns the recipes in the <code>RecipeResponse</code> data structure
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::RecipeResponse getRecipes ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& recipeContainers ) = 0;

    /**
     * This operation saves a search recipe as persistent objects in Teamcenter. The stored
     * recipe could be retrieved using getRecipes operation. This is a bulk operation, i.e.
     * it can store multiple complex search recipes in a single call.
     * <br>
     * The persistent objects used to store the search recipe in Teamcenter are objects
     * that do not have lifecycle by itself, so they are always associated to objects that
     * exhibit the <b>RecipeContainer</b> behavior. In the current CPD application there
     * are three objects that exhibit <b>RecipeContainer</b> behavior. They are
     * <br>
     * <ul>
     * <li type="disc"><b>Mdl0SubsetDefinition</b>  object to store a search recipe (without
     * the results)
     * </li>
     * <li type="disc"><b>Ptn0Partition</b>   A dynamic partition that executes the search
     * recipe to find its members
     * </li>
     * <li type="disc"><b>Cpd0DesignSubsetInstance</b>   A realization object that takes
     * a subset of a Collaborative Design and instantiates into a Workset.
     * </li>
     * </ul>
     * <br>
     * Note that the recipe is deleted when its container object is deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The <code>setRecipes</code> operation is used to save search recipes against a Recipe
     * Container object. Apart from capturing the logical combination of search expressions,
     * the <code>setRecipes</code> also stores the current configuration conditions against
     * the <b>RecipeContainer</b> object (Revision Rule and Effectivity Rule), except in
     * the case of <b>Ptn0Partition</b> object. <b>Ptn0Partition</b> object does not provide
     * a persistence mechanism for the configuration conditions and it uses the configuration
     * set in the current CPD application.
     * <br>
     * The search recipes are stored as <b>ApprSearchCriteria</b> objects in Teamcenter
     * and <b>ApprSearchCriteria</b> object hierarchy has a subclass to store each Search
     * expression separately.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * convertEffectivityExpressions, createOrUpdateConfigurations, createSearchExpressions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param recipeInputs
     *        Recipe Data that should be set for specific Container Objects
     *
     * @return
     *         Returns Service Data object. If the recipe is stored successfully in the database
     *         against the recipe container, then there will be no errors captured in the <code>ServiceData</code>
     *         data structure.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setRecipes ( const std::vector< Mdl0::Services::Modelcore::_2011_06::Search::RecipeData >& recipeInputs ) = 0;

    /**
     * This operation stops further loading of objects from a previously executed search
     * and clears all the memory allocated for the search operation. It deletes the search
     * cursor and the list of Model Elements that are kept track by the Search cursor from
     * the Server Memory.
     * <br>
     * The <code>stopSearch</code> does not unload any previously loaded Model Elements.
     * Also there is no locking or unlocking performed by the <code>stopSearch</code> operation.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When a search is executed in CPD and the search returns a large set of objects. The
     * server process keeps the results of a search using a search cursor object. At each
     * <code>fetchNextSearchResults</code> operation, the results are further filtered and
     * returned in batches specified by the load count. However if the caller is not interested
     * in consuming the search results further, then a <code>stopSearch</code> could be
     * called to release all the resources allocated for that search operation. This includes
     * dropping the runtime search cursor object and the list of Model Elements kept track
     * by the cursor.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * executeSearch, fetchNextSearchResults
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param searchCursor
     *        Search Cursor for stopping the search
     *
     * @return
     *         Returns <code>stopSearchResponse</code> data structure.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::StopSearchResponse stopSearch ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchCursor>  searchCursor ) = 0;


protected:
    virtual ~Search() {}
};
            }
        }
    }
}

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

