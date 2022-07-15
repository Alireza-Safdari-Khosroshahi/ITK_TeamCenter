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

#ifndef PTN0_SERVICES_PARTITION__2012_09_SEARCH_HXX
#define PTN0_SERVICES_PARTITION__2012_09_SEARCH_HXX

#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/Mdl0ApplicationModel.hxx>
#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>
#include <teamcenter/soa/client/model/Mdl0SearchCursor.hxx>
#include <teamcenter/soa/client/model/Mdl0SearchDef.hxx>
#include <teamcenter/soa/client/model/Ptn0Partition.hxx>
#include <teamcenter/soa/client/model/Ptn0PartitionScheme.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <ptn0/services/partition/Partition_exports.h>

namespace Ptn0
{
    namespace Services
    {
        namespace Partition
        {
            namespace _2012_09
            {
                class Search;

class PTN0SOAPARTITIONSTRONGMNGD_API Search
{
public:

    struct ConfigurationDetail;
    struct ExpressionResponse;
    struct PartitionGroup;
    struct PartitionQueryExpression;
    struct PartitionScope;
    struct UnassignedQueryExpression;
    struct PartitionSearchExpressionInput;
    struct SearchCursor;
    struct SearchExpression;
    struct SearchExpressionResponse;
    struct SearchExpressionSet;
    struct SearchOptions;
    struct SearchScope;
    struct SearchRecipe;
    struct SearchResponse;
    struct StopSearchResponse;

    /**
     * Defines whether configuration has to be done for Partitions only or all objects.The
     * values could be <i>Universal</i> or <i>Partition</i>.
     */
    enum ConfigurationFor{ Universal,
                 Partition
                 };

    /**
     * Boolean operator to combine multiple search expressions. Following are the valid
     * AND, OR, NOT
     */
    enum SearchOperator{ And,
                 Or,
                 Not
                 };

    /**
     * <code>SortOrder</code> defines the order in which the results are sorted (Ascending
     * or Descending), based on the attributes used for the sort.
     */
    enum SortOrder{ Ascending,
                 Descending
                 };

    /**
     * Configuration mapping for various configuration object types.
     */
    struct ConfigurationDetail
    {
        /**
         * Configuration Context having configuration data (<b>RevsionRule</b> and <b>EffectivityRule</b>).
         * <br>
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
        /**
         * Input ConfigurationFor structure.
         */
        ConfigurationFor configurationFor;
    };

    /**
     * Expression Response data structure
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
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Data structure that returns the Partition groups for the members returned by the
     * Search
     */
    struct PartitionGroup
    {
        /**
         * Flag to indicate whether the Partition in the structure is a root partition (Partition
         * that does not have any parent partitions) or not.
         */
        bool isRootPartition;
        /**
         * Defines the vector of members (model elements) that have membership in this Partition.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > members;
        /**
         * Reference to the Partition object (<b>Ptn0Partition</b>) represented in this <code>PartitionGroup</code>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  partition;
        /**
         * Child partition groups (vector of <code>PartitionGroup</code> objects) for this Partition
         * object along with their grouped members.
         */
        std::vector< Ptn0::Services::Partition::_2012_09::Search::PartitionGroup > childPartitionGroups;
    };

    /**
     * search expression structure for proximity search
     */
    struct PartitionQueryExpression
    {
        /**
         * Search Criteria specifying the specific Partitions
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  partitionObjectExpression;
        /**
         * Search Criteria specifying partition item revisions whose partition instances should
         * be included
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  partitionItemRevExpression;
        /**
         * Flag to include child partitions in hierarchical partition structure
         */
        bool includeChildPartitions;
        /**
         * Client ID to track response with request
         */
        std::string clientid;
    };

    /**
     * Defines Partition scope for the search results arrangement. <code>PartitionScope</code>
     * has a partition scheme name by which the results should be organized by and a flag
     * that indicates whether immediate partitions should be considered or to consider the
     * whole partition breakdown structure while returning back the partition groups
     */
    struct PartitionScope
    {
        /**
         * Input partition scheme within which the partition results are required.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  scheme;
        /**
         * Flag to indicate whether only Immediate hierarchy of Partition to members are required.
         * Setting this flag to false, will return all the Partition hierarchy till the root.
         */
        bool isOnlyImmediateGroupsReqd;
    };

    /**
     * Search for unassigned model elements - Elements not assigned to a partition of given
     * scheme names.
     */
    struct UnassignedQueryExpression
    {
        /**
         * list of <b>Ptn0PartitionScheme</b> names in which the unassigned search should be
         * performed.
         */
        std::vector< std::string > partitionSchemeNames;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Input for creating Partition Search Expression Objects
     */
    struct PartitionSearchExpressionInput
    {
        /**
         * <code>PartitionQueryExpression</code> structures that define search expressions to
         * search for Partition objects in an Application Model.
         */
        std::vector< Ptn0::Services::Partition::_2012_09::Search::PartitionQueryExpression > partitionQueryExpressions;
        /**
         * data structure that defines the list of partition schemes where it is required to
         * find the unassigned model elements.
         */
        Ptn0::Services::Partition::_2012_09::Search::UnassignedQueryExpression unassignedQueryExpression;
    };

    /**
     * Data structure that keeps track of the list of objects returned by a search.
     */
    struct SearchCursor
    {
        /**
         * A runtime object identifier that keeps track of the Search results and the corresponding
         * indexes as of where the caller has consumed the results
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  cursor;
        /**
         * An integer number that specifies the number of objects to be fetched from the Search
         * result set. If the <code>loadCount</code> is zero (or more than the number of objects
         * left in the result set) then all the remaining objects in the result set is returned.
         */
        int loadCount;
    };

    /**
     * Group of search expressions (or <b>Mdl0SearchDef</b> objects) used in the search
     * recipe
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
         * <code>PTN0PARTITION_search_has_no_valid_criteria (280012)</code>  When the Partition
         * Search input has neither partition criteria nor an Partition Item Revision criteria
         * specified, then this error is thrown.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of <code>ExpressionResponse</code> structures that has the search expression
         * object embedded. Each <code>ExpressionResponse</code> structure consists of a reference
         * to an <b>Mdl0SearchDef</b> object and the corresponding clientid (based on the clientid
         * of input data).
         */
        std::vector< Ptn0::Services::Partition::_2012_09::Search::ExpressionResponse > expressions;
    };

    /**
     * Building block to build complex search expressions.
     */
    struct SearchExpressionSet
    {
        /**
         * List of search expressions combined by the search operator.
         */
        SearchOperator searchOperator;
        /**
         * Search Expressions to be executed. In case of more than one a OR operator is assumed
         * between these expressions.
         */
        Ptn0::Services::Partition::_2012_09::Search::SearchExpression searchExpression;
        /**
         * List of search expressions combined by the search operator.
         */
        std::vector< Ptn0::Services::Partition::_2012_09::Search::SearchExpressionSet > searchExpressionSets;
    };

    /**
     * Search Options for a given Search (loadcount and sorting)
     */
    struct SearchOptions
    {
        /**
         * List of persistent attributes of the class being searched based on which the results
         * will be sorted
         */
        std::vector< std::string > sortAttributes;
        /**
         * Number of objects returned by this search. The rest of them could be retrieved by
         * calling <code>fetchNextSearchResults</code>.A defaultLoadCount of zero will return
         * all the results found.
         */
        int defaultLoadCount;
        /**
         * order in which results are sorted   Ascending or Descending.
         */
        SortOrder sortOrder;
    };

    /**
     * Defines the scope of a given search  Application model, type of objects to be returned
     * and optionally the recipe container.
     */
    struct SearchScope
    {
        /**
         * Application Model that scopes this search
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  model;
        /**
         * Type of Search  can restrict object types returned in the final search result
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
     * Recipe for performing a Search
     */
    struct SearchRecipe
    {
        /**
         * Scope of Search: Model, search types
         */
        Ptn0::Services::Partition::_2012_09::Search::SearchScope scope;
        /**
         * Configuration Information:  Revision Rule, Effectivity Rule
         */
        std::vector< Ptn0::Services::Partition::_2012_09::Search::ConfigurationDetail > configDetails;
        /**
         * Expression set to be evaluated : search criteria
         */
        Ptn0::Services::Partition::_2012_09::Search::SearchExpressionSet searchExpression;
    };

    /**
     * Response Data Structure for search results.
     */
    struct SearchResponse
    {
        /**
         * List of objects returned by the execute search operation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > modelElements;
        /**
         * An integer value specifying the number of objects returned so far for this execute
         * search operation
         */
        int elementsDone;
        /**
         * An integer value specifying the estimated number of objects that still are potentially
         * results of this search.
         */
        int estimatedElementsLeft;
        /**
         * This flag will be true if there are no more search results for this execute search
         * operation.
         */
        bool isFinished;
        /**
         * Search cursor object that tracks the search results. This object is used to get the
         * next set of results for this <code>executeSearch</code> operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchCursor>  searchCursor;
        /**
         * Partition for the members that are returned in the search results. Partition Groups
         * may contain complete partition breakdown or just the immediate partitions based on
         * the input <code>PartitionScope</code> specification.
         */
        std::vector< Ptn0::Services::Partition::_2012_09::Search::PartitionGroup > partitionGrps;
        /**
         * Service Data for any error information. Typically this will contain errors about
         * any malformed search recipes. E.g. an invalid proximity target (an object without
         * geometrical information)
         * <br>
         * Following are some of the error codes that may be populated as partial errors in
         * the <code>ServiceData</code> object:
         * <br>
         * <code>MDL0MODEL_invalid_proximity_target (278033)</code>   A spatial proximity search
         * recipe that has no valid proximity targets. The target element has no bounding box
         * populated in the database.
         * <br>
         * <code>MDL0MODEL_invalid_trueshape_object (278034)</code>   A spatial proximity search
         * recipe that has targets without a valid trueshape object. This error is thrown when
         * the tso_flag is set to true in the input SearchExpressionSet.
         * <br>
         * <code>MDL0MODEL_invalid_revision_rule_clause (278030)</code>   The revision rule
         * used to create a ConfigurationContext object has invalid clauses (clauses not valid
         * for CPD application).
         * <br>
         * <code>MDL0MODEL_invalid_set_of_sort_attributes (278028) </code> The Sort options
         * has a sort attribute that is not valid for the current search. The sort attribute
         * should be an attribute of the objects found in the search. The database query does
         * not support runtime or compound properties as sort attributes.
         * <br>
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
         * Service Data for any error information  e.g. invalid search cursor object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Search() {}
};
            }
        }
    }
}

#include <ptn0/services/partition/Partition_undef.h>
#endif

