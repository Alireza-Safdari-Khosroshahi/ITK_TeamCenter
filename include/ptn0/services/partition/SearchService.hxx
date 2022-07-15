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

#ifndef PTN0_SERVICES_PARTITION_SEARCHSERVICE_HXX
#define PTN0_SERVICES_PARTITION_SEARCHSERVICE_HXX

#include <ptn0/services/partition/_2011_06/Search.hxx>
#include <ptn0/services/partition/_2012_09/Search.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <ptn0/services/partition/Partition_exports.h>

namespace Ptn0
{
    namespace Services
    {
        namespace Partition
        {
            class SearchService;

/**
 * Contains Search Services to search Model Content in an Application Model (<b>Mdl0ApplicationModel</b>)and
 * arranging them by a specific Partition Scheme (<b>Ptn0PartitionScheme</b>). This
 * Search Service provides operations that enable searching Conditional Model Elements
 * (Mdl0ConditionalElement) in a given Application Model. An Application Model could
 * be a Collaborative Design (<b>Cpd0CollaborativeDesign</b>) (in the case of CPD).
 * <br>
 * Search service provides the ability to search for Conditional Model Elements using
 * various search recipes (spatial and non spatial). Also this Search Service provides
 * ability to create Partition Search expressions (<b>Ptn0SearchPartition</b> and <b>Ptn0SearchUnassigned</b>).
 * <br>
 * <br>
 * <b>Use Cases:</b>
 * <br>
 * Search Service is used by the CPD application to implement Searching CPD Design Elements
 * (<b>Cpd0DesignElement</b>) within a Collaborative Design. However the intent for
 * Partition Search is not only to search for Conditional Model Elements, it is also
 * to arrange/group the results by Partition, so that the calling application can display
 * the results in an organized manner. The search functionality in Partition Search
 * is exactly the same compared to the Search functionality offered by AppModel Search
 * Service, except for this additional Group by Partition capability. Please refer to
 * the CPD Server Functional Specifications for detailed descriptions on Application
 * Model and Model Element Data schema.
 * <br>
 * Partition Search supports searching of Model Elements based on different Search Expressions.
 * The Search Expressions could be
 * <br>
 * <br>
 * <b>Spatial</b>
 * <br>
 * <br>
 * <ul>
 * <li type="disc"> Box Zone Expression (<b>Mdl0SearchBoxZone</b>) defines a rectangular
 * (axis aligned) box, defined in a 3d space, which could be used to find Conditional
 * Model Elements that are either inside/outside/intersecting the 3 dimensional box.
 * </li>
 * <li type="disc"> Plane Zone Expression (<b>Mdl0SearchPlaneZone</b>) defines a 3d
 * plane and the search expression could define to look for Conditional Model Elements
 * above/below/intersecting the plane.
 * </li>
 * <li type="disc"> Proximity Expression (<b>Mdl0SearchProximity</b>) used to find Conditional
 * Model Elements that are spatially nearby a given set of other Conditional Model Elements.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <b>Non Spatial</b>
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Saved Query Expression (<b>Mdl0SearchSavedQuery</b>) used to search
 * Conditional Model Elements with specific attribute values. Accepts wildcards for
 * attribute values.
 * </li>
 * <li type="disc">Include Expression (<b>Mdl0SearchSlctContent</b>) specific set of
 * Model Elements that are included as part of the search result.
 * </li>
 * <li type="disc">Exclude Expression (<b>Mdl0SearchGroup</b>) specific set of Model
 * Elements that are excluded from the search result.
 * </li>
 * <li type="disc">Partition Expression (<b>Ptn0SearchPartition</b>) Model Elements
 * that are members of a particular set of Partitions in the given Collaborative Design.
 * </li>
 * <li type="disc">Closure Query Expression Not Implemented in Teamcenter 9.1 Out of
 * scope for now.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * The above search expressions could be joined using AND/OR operators to form complex
 * Search Recipes. Also the r esults of the execution of a Search Recipe could be constrained
 * to return only a given set of object types. For e.g. the results of a Search Recipe
 * could be restricted to return only Cpd0DesignElement objects. The callers could also
 * use NOT operator to negate any of the non spatial expressions above and combine them
 * in a Search Recipe (Note that NOT is a Unary operator and it accepts only one expression
 * to negate unlike AND/OR which combines multiple expressions).
 * <br>
 * Search Service is typically used to perform the following operations:
 * <br>
 * Execute a Search Recipe: Executes a complex search recipe formed using the various
 * search expression combinations and constrained using the search scope (Application
 * Model, Search Types). The results of executing a search could be sorted using one
 * or more of the attributes of the returned object type. Also the number of objects
 * that should be returned to the caller can be controlled by setting the defaultLoadCount.
 * If the default load count is set to zero then all the results are returned in one
 * shot.
 * <br>
 * If the default load count is set to a non zero value, then the caller will be returned
 * a search cursor which could be used to get search results as and when it is required.
 * Also an active search cursor could be released by calling the stopSearch operation.
 * <br>
 * Over and above of the process of searching, the results are also grouped by Partition
 * objects based on the given input Partition Scheme.
 * <br>
 * Sample code:
 * <br>
 * Typically following is the sequence of operations to perform a Search:
 * <br>
 * 1.    Call createOrUpdateConfigurations and create a Configuration Context with a
 * valid Revision Rule (optionally with an Effectivity Rule)
 * <br>
 * 2.    Call createSearchExpressions and create the elemental search expressions
 * <br>
 * 3.    Create the Search Expression Sets to join the elemental search expressions
 * to a complex search recipe
 * <br>
 * 4.    Call executeSearch with the complex Search Expression Set. executeSearch will
 * return a default set of conditional elements (defined by the defaultLoadCount)
 * <br>
 * 5.    Call fetchNextSearchResults repeatedly to get further results based on the
 * search and each time this operation could be called with its own defaultLoadCount
 * value.
 * <br>
 * 6.    Optionally stopSearch could be called to clean up the results and this call
 * would indicate that the caller is no longer interested in getting back the remaining
 * search results.
 * <br>
 * Apart from execution of a search query, there are two operations that help the callers
 * to save a Search Recipe and enquire the contents of a persisted Search Recipe. The
 * setRecipes call saves a Search Recipe and it requires a Search Container object to
 * persist the recipe. Currently in CPD application, this could be one of either Cpd0DesignSubsetInstance
 * or Ptn0Partition o r Mdl0SubsetDefinition. The getRecipes call returns the search
 * expressions and their combinations (as Search Expression Sets) of a stored recipe.
 * <br>
 * The sample in soa_client.zip, com.teamcenter.cpdsearch.PartitionSearchServiceSOASampleTest.java
 * shows the use of Search operations for the following use case:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Execute a Search with a complex recipe (Saved Query combined with
 * Box Zone and the results restricted to <b>Cpd0DesignElement</b> objects) and return
 * the results organized by the functional partition scheme.
 * </li>
 * </ul>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * Search
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libptn0soapartitionstrongmngd.dll
 * </li>
 * <li type="disc">libptn0soapartitiontypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class PTN0SOAPARTITIONSTRONGMNGD_API SearchService
    : public Ptn0::Services::Partition::_2011_06::Search,
             public Ptn0::Services::Partition::_2012_09::Search
{
public:
    static SearchService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates Partition Search expressions (<b>Ptn0SearchPartition</b>)
     * that would be used in a Search Recipe (to perform <code>executeSearch</code> or <code>setRecipes</code>
     * call). Since Partition is an optional BMIDE template on top of the AppModel template,
     * creating Partition Search expressions are provided as part of the Partition Search
     * SOA service.
     * <br>
     * <code>createPartitionExpressions</code> is an array based operation that takes multiple
     * Partition Search expression input data and creates<code> </code>the <code>SearchExpressionResponse</code>
     * that is similar to its counterpart (<code>createSearchExpressions</code>) in the
     * <code>AppModel</code> Search service.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * There are 2 use cases supported by this operation to create the elemental search
     * expressions to find members of Partitions.
     * <br>
     * 1.<i>Create Partition Search Expressions</i>   A Partition Search expression is used
     * to first find the partition that are specified by the Search recipe and then searching
     * for the members of partitions that are of interest.
     * <br>
     * 2. <i>Create Unpartitioned Elements Search Expression</i>   Search expression used
     * to find unpartitioned elements on a given partition scheme or on all partition schemes
     * in that Collaborative Design.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createPartitionExpressions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param partitionSearchexpInput
     *        Input for the runtime partition expressions
     *
     * @return
     *         Returns the partition runtime objects of the <code>SearchExpressionResponse</code>
     *         structure
     *         <br>
     *         <code>SearchExpressionResponse</code>:Response data structure that returns the Search
     *         Expression objects created for the given Search Expression Input data structures.
     *
     * @deprecated
     *         As of Teamcenter 10, use the createPartitionExpressions operation from the _2012_09
     *         namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the createPartitionExpressions operation from the _2012_09 namespace."))
#endif
    virtual Ptn0::Services::Partition::_2011_06::Search::SearchExpressionResponse createPartitionExpressions ( const Ptn0::Services::Partition::_2011_06::Search::PartitionSearchExpressionInput&  partitionSearchexpInput ) = 0;

    /**
     * This operation creates Partition Search expressions (<b>Ptn0SearchPartition</b>)
     * that would be used in a Search Recipe (to perform executeSearch or setRecipes call).
     * Since Partition is an optional BMIDE template on top of AppModel template, creating
     * Partition Search expressions are provided as part of the Partition Search service.
     * <br>
     * createPartitionExpressions is a bulk operation that takes multiple Partition search
     * expression input data and creates SearchExpressionResponse that is similar to its
     * counterpart (createSearchExpressions) in the AppModel Search service.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * There are 2 use cases supported by this operation to create the elemental search
     * expressions to find members of Partitions.
     * <br>
     * <i>1.Create Partition Search Expressions</i>   A Partition Search expression is used
     * to first find the partition that are specified by the Search recipe and then searching
     * for the members of partitions that are of interest.
     * <br>
     * <i>2. Create Unpartitioned Elements Search Expression</i>   Search expression used
     * to find unpartitioned elements on a given partition scheme or on all partition schemes
     * in that Collaborative Design.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createPartitionExpressions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param partitionSearchexpInput
     *        Input for the runtime partition expressions
     *
     * @return
     *         Returns the partition runtime objects of the <code>SearchExpressionResponse</code>
     *         structure
     *         <br>
     *         <code>SearchExpressionResponse</code>:Response data structure that returns the Search
     *         Expression objects created for the given Search Expression Input data structures.
     *
     */
    virtual Ptn0::Services::Partition::_2012_09::Search::SearchExpressionResponse createPartitionExpressions ( const Ptn0::Services::Partition::_2012_09::Search::PartitionSearchExpressionInput&  partitionSearchexpInput ) = 0;

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
     * specified in the SearchOptions. The <code>SearchResponse</code> also contains a Search
     * Cursor object that the caller could use to fetch the next set of results by invoking
     * the <code>fetchNextSearchResults</code> call. Search options also gives the caller
     * the ability to sort the results of a search using any (one or more) of the attributes
     * proeprties of the returned objects.
     * <br>
     * The <code>PartitionScope</code> specifies the grouping by which the search results
     * should be grouped or organized. It contains a partition scheme (<b>Ptn0PartitionScheme</b>)
     * name and a flag that specifies whether the immediate partitions are the only ones
     * that need to be considered. The <code>SearchResponse</code> contains the results
     * grouped based on Partitions in which the search results have membership, in the given
     * partition scheme.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API provides the ability for searching Model Content in a given Application
     * Model. Application Model is a construct in AppModel template that defines an abstract
     * boundary in which content could be populated. The populated model content is called
     * Model Element which again is an abstract object which has some basic properties such
     * as an ID, revision Id, name and description.
     * <br>
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
     * which is part of the search recipe and organized by the search options. Also the
     * results of a search are organized by Partitions based on the input Partition Scheme.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createPartitionExpressions, fetchNextSearchResults, stopSearch
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param options
     *        defines additional search options.
     *
     * @param scope
     *        Defines Partition scope for the search results arrangement.
     *
     * @param recipe
     *        defines the search recipe
     *
     * @return
     *         defines the set of objects loaded after search and cursor to load on demand.
     *
     */
    virtual Ptn0::Services::Partition::_2012_09::Search::SearchResponse executeSearch ( const Ptn0::Services::Partition::_2012_09::Search::SearchOptions&  options,
        const Ptn0::Services::Partition::_2012_09::Search::PartitionScope&  scope,
        const Ptn0::Services::Partition::_2012_09::Search::SearchRecipe&  recipe ) = 0;

    /**
     * This operation gets the next set of Model Elements from a previously executed search
     * results. The results returned will be based on the load count specified in the <code>SearchCursor</code>
     * input structure. This API returns the same response structure as that of <code>executeSearch</code>.
     * <br>
     * The results obtained by <code>fetchNextSearchResults</code> are again arranged by
     * Partition based on the <i>PartitionScope</i> specified.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API is used in conjunction with <code>executeSearch</code> operation. <code>executeSearch</code>
     * operation is a prerequisite for invoking <code>fetchNextSearchResults</code>. The
     * search cursor returned by the executeSearch is used to call <code>fetchNextSearchResults</code>
     * operation. This operation could be called repeatedly by the caller, until all the
     * search results are returned. The <code>fetchNextSearchResults</code> in Partition
     * Search Service is introduced mainly to organize the search results by Partition over
     * and above of the functionality provided in the <code>AppModel</code> Search Service.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * fetchNextSearchResults
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param searchCursor
     *        Data structure that keeps track of the list of objects returned by a search.
     *
     * @param partitionScope
     *        Defines Partition scope for the search results arrangement. <i>PartitionScope</i>
     *        has a partition scheme name by which the results should be organized by and a flag
     *        that indicates whether immediate partitions should be considered or to consider the
     *        whole <i>partition breakdown</i> structure while returning back the partition groups
     *
     * @return
     *         Returns the Search Response structure
     *
     */
    virtual Ptn0::Services::Partition::_2012_09::Search::SearchResponse fetchNextSearchResults ( const Ptn0::Services::Partition::_2012_09::Search::SearchCursor&  searchCursor,
        const Ptn0::Services::Partition::_2012_09::Search::PartitionScope&  partitionScope ) = 0;

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
     * fetchNextSearchResults
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param searchCursor
     *        A runtime object identifier that keeps track of the Search results and the corresponding
     *        indexes as of where the caller has consumed the results. Invoking stopSearch on this
     *        object deletes this object.
     *
     * @return
     *         Returns stopSearchResponse data structure
     *
     */
    virtual Ptn0::Services::Partition::_2012_09::Search::StopSearchResponse stopSearch ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchCursor>  searchCursor ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SearchService")

};
        }
    }
}


#pragma warning ( pop )

#include <ptn0/services/partition/Partition_undef.h>
#endif

