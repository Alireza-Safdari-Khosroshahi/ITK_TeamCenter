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

#ifndef CLS0_SERVICES_CLASSIFICATIONCORE_CLASSIFICATIONSERVICE_HXX
#define CLS0_SERVICES_CLASSIFICATIONCORE_CLASSIFICATIONSERVICE_HXX

#include <cls0/services/classificationcore/_2013_05/Classification.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <cls0/services/classificationcore/ClassificationCore_exports.h>

namespace Cls0
{
    namespace Services
    {
        namespace Classificationcore
        {
            class ClassificationService;

/**
 * Contains Cls0Classification related operations.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libcls0soaclassificationcorestrongmngd.dll
 * </li>
 * <li type="disc">libcls0soaclassificationcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class CLS0SOACLASSIFICATIONCORESTRONGMNGD_API ClassificationService
    : public Cls0::Services::Classificationcore::_2013_05::Classification
{
public:
    static ClassificationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates or modifies Classification (Cls0ClassBase) objects. This operation
     * can be used to classify existing Teamcenter objects or to create standalone Classification
     * objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param classificationObjectInfos
     *        List of structures, each representing a set of properties for creation or modification
     *        of a Classification object.
     *
     * @return
     *         The newly created or updated Classification objects. These objects are also included
     *         in the respective created and updated lists in the ServiceData. The following partial
     *         errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">132604 : The given WorkspaceObject is not classifiable.
     *         </li>
     *         <li type="disc">132065 : Cannot classify a WorkspaceObject into an abstract Hierarchy
     *         Node of ID .
     *         </li>
     *         <li type="disc">132606 : Multiple classification of a given WorkspaceObject is not
     *         allowed in the specified Hierarchy Node of ID .
     *         </li>
     *         </ul>
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::CreateOrUpdateClassificationObjectsResponse createOrUpdateClassificationObjects ( const std::vector< Cls0::Services::Classificationcore::_2013_05::Classification::ClassificationObjectInfo >& classificationObjectInfos ) = 0;

    /**
     * This operation is used to Create or Update Hierarchy nodes in a given hierarchy.
     * <br>
     * The response structure for this operation will contain a list of newly created or
     * updated Hierarchy nodes along with any errors during the operation.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param hierarchyNodeDetails
     *        List of structures of Hierarchy node properties.
     *
     * @return
     *         The created / updated Hierarchy Nodes. Partial errors are returned in the ServiceData
     *         if a Hierarchy node could not created / updated for some reason.
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::CreateOrUpdateHierarchyNodesResponse createOrUpdateHierarchyNodes ( const std::vector< Cls0::Services::Classificationcore::_2013_05::Classification::HierarchyNodeDetails >& hierarchyNodeDetails ) = 0;

    /**
     * Discards the results of a Classification search that was previously started. The
     * resultSet needs to be a valid resultSet obtained from a previous operation call to
     * the operation getClassificationSearchResults. This operation should be called after
     * you are done using the results obtained from a search.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param resultSet
     *        The identifier of an existing Result Set that was obtained using a call to the operation
     *        getClassificationSearchResults.
     *
     * @return
     *         The following partial errors may be returned:
     *         <br>
     *         302701 : The ResultSet ID provided is not a valid one.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData discardClassificationSearchResults ( const std::string&  resultSet ) = 0;

    /**
     * From a Result Set that contains search results, fetch the specified number of results
     * (objects). The Result Set passed in here should be one created as a result of a Classification
     * search operation like searchClassificationObjects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param searchResultsInput
     *        Structure containing the Result Set identifier and which objects to fetch from the
     *        Result Set.
     *
     * @return
     *         The specified objects from the Result Set. Partial errors will be returned ServiceData
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::GetClassificationSearchResultsResponse getClassificationSearchResults ( const Cls0::Services::Classificationcore::_2013_05::Classification::GetClassificationSearchResultsInputInfo&  searchResultsInput ) = 0;

    /**
     * This operation gets the children along with associated Node information for all the
     * given Classification Hierarchy Nodes. If recursive is set as true in the input structure,
     * all the children up to the leafmost Nodes would be found and returned. If recursive
     * is set as false, only the first level children would be found and returned. You can
     * request for extended information about the returned Nodes by passing in predefined
     * strings in the extendInfoRequested parameter in the input structure. Example: Passing
     * in the string InstanceCount in extendInfoRequested would return the number of Classification
     * object instances of the Hierarchy Node.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param nodeInfo
     *        Structure containing the details of the Nodes for which the children need to be found.
     *
     * @return
     *         The children found for each of the input Nodes is returned in the GetChildrenResponse
     *         structure.
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::GetHierarchyNodeChildrenResponse getHierarchyNodeChildren ( const std::vector< Cls0::Services::Classificationcore::_2013_05::Classification::GetHierarchyNodeChildrenInputInfo >& nodeInfo ) = 0;

    /**
     * Gets the detailed information about the Hierarchy Nodes including information like
     * Node Type, attached Icons / Images,  etc. This information can be typically used
     * for displaying details about the node in Teamcenter user interface.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param nodes
     *        The list of Classification Hierarchy Nodes for which you need the detailed information.
     *
     * @return
     *         The detailed information about the Hierarchy Nodes including information like Node
     *         Type, attached Icons / Images, etc. This information can be typically used for displaying
     *         details about the node in Teamcenter user interface. Partial errors will be returned
     *         in ServiceData if there are any. Example:Attached dataset cannot be read.
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::GetHierarchyNodeDetailsResponse getHierarchyNodeDetails ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  >& nodes ) = 0;

    /**
     * Gets all the top-level Hierarchy Nodes of a Classification Hierarchy. Obtaining the
     * top level nodes would usually be one of the first steps while trying to fetch the
     * Classification Hierarchy. After the top level nodes are obtained, further nodes can
     * be obtained using the operation getHierarchyNodeChildren.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @return
     *         The top level Hierarchy Nodes of a Classification Hierarchy. This will not return
     *         any Partial errors.
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::GetTopLevelNodesResponse getTopLevelNodes (  ) = 0;

    /**
     * This operation allows searching for Classification Objects that match the specified
     * search criteria. The inputs specify which Hierarchy Node to search in and the Properties
     * used in the search.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Next Generation Classification application - Provides a set of features to work with
     * Classification node hierarchy and Classification data.  Application allows Classification
     * of product data-standard parts.
     *
     * @param searchInput
     *        Input structure for searching classification objects.
     *
     * @return
     *         The operation returns a string reference to a Result Set that contains the search
     *         results. The Result Set contains the Classification objects found.
     *         <br>
     *         You need to invoke the getClassificationSearchResults operation after this operation
     *         to get the actual Classification objects that were found in the search.
     *         <br>
     *
     */
    virtual Cls0::Services::Classificationcore::_2013_05::Classification::SearchClassificationObjectsResponse searchClassificationObjects ( const Cls0::Services::Classificationcore::_2013_05::Classification::SearchClassificationObjectsInputInfo&  searchInput ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ClassificationService")

};
        }
    }
}


#pragma warning ( pop )

#include <cls0/services/classificationcore/ClassificationCore_undef.h>
#endif

