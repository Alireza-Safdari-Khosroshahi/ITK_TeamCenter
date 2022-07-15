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

#ifndef PTN0_SERVICES_PARTITION__2011_06_SEARCH_HXX
#define PTN0_SERVICES_PARTITION__2011_06_SEARCH_HXX

#include <teamcenter/soa/client/model/Mdl0SearchDef.hxx>


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
            namespace _2011_06
            {
                class Search;

class PTN0SOAPARTITIONSTRONGMNGD_API Search
{
public:

    struct ExpressionResponse;
    struct PartitionQueryExpression;
    struct UnassignedQueryExpression;
    struct PartitionSearchExpressionInput;
    struct SearchExpressionResponse;

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
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Input data structure to create a partition search expression (<b>Ptn0SearchPartition</b>)
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
         * Client ID to track response with request
         */
        std::string clientid;
    };

    /**
     * Search for unassigned model elements  Elements not assigned to a partition of given
     * scheme names.
     */
    struct UnassignedQueryExpression
    {
        /**
         * list of <b>Ptn0PartitionScheme</b> names in which the search needs to be performed
         * to find the unassigned model elements. This could be a wild card character (*), which
         * means that the model elements that should be found are not assigned to any partition
         * in any of the schemes in that Application Model.
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
         * A <code>PartitionQueryExpression</code> has a <code>partitionObjectExpression</code>
         * and a <code>partitionItemRevExpression</code>. Both of these are Search Expression
         * objects. Either one or both could be specified that would find partition objects
         * and the Partition Query Expression is to resolve to the members of those partitions.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Search::PartitionQueryExpression > partitionQueryExpressions;
        /**
         * This data structure carries a list of partition scheme names and creates a search
         * expression that finds all members (Model Elements) that are not partitioned using
         * those schemes. If the schemes contain a wild card, then the search is done for model
         * elements that are not partitioned in any of the partition schemes, in that application
         * model.
         */
        Ptn0::Services::Partition::_2011_06::Search::UnassignedQueryExpression unassignedQueryExpression;
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
         * partial errors returned in the ServiceData:
         * <br>
         * <ul>
         * <li type="disc"><code>PTN0PARTITION_search_has_no_valid_criteria (280012)</code>
         * When the Partition Search input has neither partition criteria nor an Partition
         * Item Revision criteria specified, then this error is thrown.
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of ExpressionResponse structures that has the search expression object embedded.
         * Each <code>ExpressionResponse</code> structure consists of a reference to an <b>Mdl0SearchDef</b>
         * object and the corresponding clientid (based on the clientid of input data).
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Search::ExpressionResponse > expressions;
    };




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


protected:
    virtual ~Search() {}
};
            }
        }
    }
}

#include <ptn0/services/partition/Partition_undef.h>
#endif

