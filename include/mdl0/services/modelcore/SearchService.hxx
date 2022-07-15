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

#ifndef MDL0_SERVICES_MODELCORE_SEARCHSERVICE_HXX
#define MDL0_SERVICES_MODELCORE_SEARCHSERVICE_HXX

#include <mdl0/services/modelcore/_2011_06/Search.hxx>
#include <mdl0/services/modelcore/_2013_05/Search.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            class SearchService;

/**
 * This service provides operations that enable searching conditional model elements
 * (<b>Mdl0ConditionalElement</b>) in a given application model. An application model
 * could be a collaborative design (<b>Cpd0CollaborativeDesign</b> in the case of CPD).
 * <br>
 * <code>Search</code>  service provides the ability to search for conditional model
 * elements using various search recipes (spatial and nonspatial). Search service also
 * provides the ability to save a search recipe in the database and retrieve a previously
 * stored recipe.
 * <br>
 * <br>
 * <b>Use Cases:</b>
 * <br>
 * <code>Search</code> service is used by the CPD application to implement Searching
 * CPD Design Elements (<b>Cpd0DesignElement</b>) within a collaborative design. Search
 * is a generic search capability that could be used to search conditional model elements
 * within a given application model(<b>Mdl0ApplicationModel</b>). Please refer to the
 * CPD Server Functional Specifications for detailed descriptions on application model
 * and model element data schema.
 * <br>
 * <code>AppModel</code>  search supports searching of model elements based on different
 * search expressions. The search expressions could be
 * <br>
 * <b>Spatial</b>
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Box Zone Expression (Mdl0SearchBoxZone)</b>   defines
 * a rectangular (axis aligned) box, defined in a 3d space, which could be used to find
 * Conditional Model Elements that are either inside/outside/intersecting the 3 dimensional
 * box.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Plane Zone Expression (Mdl0SearchPlaneZone)</b>   defines
 * a 3d plane and the search expression could define to look for Conditional Model Elements
 * above/below/intersecting the plane.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Proximity Expression (Mdl0SearchProximity)</b>  used to
 * find Conditional Model Elements that are spatially nearby a given set of other Conditional
 * Model Elements.
 * <br>
 * <b>Non Spatial</b>
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Saved Query Expression (Mdl0SearchSavedQuery)</b>   used
 * to search Conditional Model Elements with specific  property values. Accepts wildcards
 * for  property values.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Include Expression (Mdl0SearchSlctContent) </b>  specific
 * set of Model Elements that are included as part of the search result.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Exclude Expression (Mdl0SearchGroup)</b>   specific set
 * of Model Elements that are excluded from the search result.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Partition Expression (Ptn0SearchPartition)  </b> Model
 * Elements that are members of a particular set of Partitions in the given Collaborative
 * Design.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>Closure Query Expression</b>  Not Implemented in Teamcenter
 * 9.1  Out of scope for now.
 * <br>
 * <br>
 * The above search expressions could be joined using <i>AND/OR</i> operators to form
 * complex<code> Search Recipes</code>. Also the results of the execution of a Search
 * Recipe could be constrained to return only a given set of object types. For e.g.
 * the results of a Search Recipe could be restricted to return only <b>Cpd0DesignElement</b>
 * objects. The callers could also use NOT <i>operator</i> to negate any of the non
 * spatial expressions above and combine them in a Search Recipe (Note that NOT is a
 * Unary operator and it accepts only one expression to negate unlike <i>AND/OR</i>
 * which combines multiple expressions).
 * <br>
 * Search Service is typically used to perform the following operations:
 * <br>
 * <b>Create Configuration Context for a CPD session:</b> A CPD client session could
 * call <code>createOrUpdateConfigurations</code> to create one or more configuration
 * context objects that hold the <b>Revision Rule</b> and <b>Effectivity Rule</b> that
 * is required to configure the results of a Search execution. These <b>configurationcontext</b>
 * objects are runtime objects that could be used repeatedly by the client throughout
 * the session (over different search operations).
 * <br>
 * <br>
 * <b>Create Search Expressions to perform a Search (or Save a Search Recipe):</b> Before
 * executing a search or saving a recipe, this is a prerequired step to create the elemental
 * search expressions (both Spatial and non Spatial).
 * <br>
 * <b>Execute a Search Recipe:</b> Executes a complex search recipe formed using the
 * various search expression combinations and constrained using the search scope (Application
 * Model, Search Types). The results of a executing a search could be sorted using the
 * one or more of the attributes properties of the returned object type. Also the number
 * of objects that should be returned to the caller can be controlled by setting the
 * defaultLoadCount. If the default load count is set to zero then all the results are
 * returned in one shot.
 * <br>
 * If the default load count is set to a non zero value, then the caller will be returned
 * a search cursor which could be used to get search results as and when it is required.
 * Also an active search cursor could be released by calling the <code>stopSearch</code>
 * operation.
 * <br>
 * Save/Retrieve a stored Search Recipe: Save and Retrieve a complex search recipe in
 * the Teamcenter database. Recipes are not independent objects and they would have
 * to be stored in an object that exhibits a RecipeContainer behavior. In CPD, There
 * are 3 objects that exhibit RecipeContainer behavior as of now. They are <b>Mdl0SubsetDefinition</b>
 * object to store a search recipe, <b>Ptn0Partition</b>  a dynamic partition that
 * finds members based on a search operation and <b>Cpd0DesignSubsetInstance</b>  object
 * that selects a subset of a Collaborative Design using a search recipe and instantiates
 * into a Workset.
 * <br>
 * <br>
 * Sample code:
 * <br>
 * Typically following is the sequence of operations to perform a Search:
 * <br>
 * 1. Call createOrUpdateConfigurations and create a Configuration Context with a valid
 * Revision Rule (optionally with an Effectivity Rule)
 * <br>
 * 2.Call createSearchExpressions and create the elemental search expressions
 * <br>
 * 3.Create the Search Expression Sets to join the elemental search expressions to a
 * complex search recipe
 * <br>
 * 4.Call executeSearch with the complex Search Expression Set. executeSearch will return
 * a default set of conditional elements (defined by the defaultLoadCount)
 * <br>
 * 5.Call fetchNextSearchResults repeatedly to get further results based on the search
 * and each time this operation could be called with its own defaultLoadCount value.
 * <br>
 * 6.&nbsp;&nbsp;&nbsp;&nbsp;Optionally stopSearch could be called to clean up the results
 * and this call would indicate that the caller is no longer interested in getting back
 * the remaining search results.
 * <br>
 * Apart from execution of a search query, there are two operations that help the callers
 * to save a Search Recipe and enquire the contents of a persisted Search Recipe. The
 * setRecipes call saves a Search Recipe and it requires a Search Container object to
 * persist the recipe. Currently in CPD application, this could be one of either <b>Cpd0DesignSubsetInstance</b>
 * or <b>Ptn0Partition</b> or <b>Mdl0SubsetDefinition</b>. The getRecipes call returns
 * the search expressions and their combinations (as Search Expression Sets) of a stored
 * recipe.
 * <br>
 * The sample in<code> soa_client.zip</code>,<b> com.teamcenter.cpdsearch.SearchServiceSOASampleTest.java</b>
 * shows the use of Search operations for the following 2 use cases:
 * <br>
 * 1.Execute a Search with a complex recipe (Saved Query combined with Box Zone and
 * the results restricted to <b>Cpd0DesignElement</b> objects)
 * <br>
 * 2.Save and Retrieve a complex recipe on a Recipe Container object
 * <br>
 * <br>
 * <br>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmdl0soamodelcorestrongmngd.dll
 * </li>
 * <li type="disc">libmdl0soamodelcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class MDL0SOAMODELCORESTRONGMNGD_API SearchService
    : public Mdl0::Services::Modelcore::_2011_06::Search,
             public Mdl0::Services::Modelcore::_2013_05::Search
{
public:
    static SearchService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation creates the elemental search expressions that could be combined using
     * logical operators to build up a complex search recipe in CPD application. The createSearchExpressions
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
     * The createSearchExpressions is a required operation before an executeSearch or setRecipes
     * call is made. This operation creates the runtime Search Definition objects based
     * on the input search expression data structures. The intent of this operation is to
     * create all the individual elemental search expressions so that they could be combined
     * using logical operators (AND/OR/NOT) to create a complex search recipe.
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
    virtual Mdl0::Services::Modelcore::_2011_06::Search::SearchExpressionResponse createSearchExpressions ( const Mdl0::Services::Modelcore::_2013_05::Search::SearchExpressionInput&  searchExpInput ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SearchService")

};
        }
    }
}


#pragma warning ( pop )

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

