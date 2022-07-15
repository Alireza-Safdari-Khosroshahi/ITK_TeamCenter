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

#ifndef CLS0_SERVICES_CLASSIFICATIONCORE__2013_05_CLASSIFICATION_HXX
#define CLS0_SERVICES_CLASSIFICATIONCORE__2013_05_CLASSIFICATION_HXX

#include <teamcenter/soa/client/model/Cls0ClassBase.hxx>
#include <teamcenter/soa/client/model/Cls0HierarchyNode.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <cls0/services/classificationcore/ClassificationCore_exports.h>

namespace Cls0
{
    namespace Services
    {
        namespace Classificationcore
        {
            namespace _2013_05
            {
                class Classification;

class CLS0SOACLASSIFICATIONCORESTRONGMNGD_API Classification
{
public:

    struct ClassificationObjectInfo;
    struct CreateOrUpdateClassificationObjectsResponse;
    struct CreateOrUpdateHierarchyNodesResponse;
    struct FilterExpression;
    struct GetClassificationSearchResultsInputInfo;
    struct GetClassificationSearchResultsResponse;
    struct GetHierarchyNodeChildrenInputInfo;
    struct GetHierarchyNodeChildrenResponse;
    struct GetHierarchyNodeDetailsResponse;
    struct GetTopLevelNodesResponse;
    struct HierarchyNodeDetails;
    struct NameValueStruct;
    struct SearchClassificationObjectsInputInfo;
    struct SearchClassificationObjectsResponse;
    struct SortOrder;

    /**
     * Lists the supported types of Hierarchy nodes. Values can be used in an operation
     * where a Node type is requried.
     */
    enum HierarchyNodeType{ HierarchyNode_Group,
                 HierarchyNode_Master,
                 HierarchyNode_Reference
                 };

    /**
     * The map contains key-value pairs where the key refers to the Hierarchy Node (Cls0HierarchyNode)
     * and the value contains the list of Children of that Hierarchy Node (list of HierarchyNodeDetails).
     * There will be one entry in this map for every input Hierarchy Node for which the
     * children were to be fetched. If recursive is set as true, the map will also contain
     * entries for each child node that is not a leaf node.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode> , std::vector< HierarchyNodeDetails > > ChildrenMap;

    /**
     * The map stores for each Hierarchy Node, the relevant Hierarchy Node details (Cls0HierarchyNode
     * / HierarchyNodeDetails). There will be one entry in this map for every input Hierarchy
     * Node for which the detailed information was asked.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode> , HierarchyNodeDetails > NodeDetailsMap;

    /**
     * This structure provides the input information to be used to create or modify Classification
     * (Cls0ClassBase) object.
     */
    struct ClassificationObjectInfo
    {
        /**
         * Reference of the Cls0ClassBase  to update with the supplied object details. For create
         * mode of this operation, this parameter will be empty.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0ClassBase>  objectToUpdate;
        /**
         * ID for the Classification Object.This parameter is only used when creating a new
         * Classification Object.
         */
        std::string objectId;
        /**
         * The name for this Classification Object.
         */
        std::string objectName;
        /**
         * The description for this Classification Object.
         * <br>
         * This is an optional parameter and an empty string can be passed in.
         */
        std::string objectDesc;
        /**
         * The Cls0HierarchyNode where this Classification Object should be created.
         * <br>
         * This parameter is only used when creating a new Classification Object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  nodeRef;
        /**
         * The BusinessObject that is being classified.
         * <br>
         * This parameter can be empty which indicates that a standalone Classification Object
         * should be created.
         * <br>
         * This parameter is only used when creating a new Classification Object.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  classifiedObjectRef;
        /**
         * The list of Classification property names and values that should be set for the Classification
         * Object.
         * <br>
         * This parameter can be empty which indicates that no properties should be set or that
         * the Classification Object does not have any properties.
         */
        std::vector< Cls0::Services::Classificationcore::_2013_05::Classification::NameValueStruct > propValues;
    };

    /**
     * This is the response structure that holds reference to created or modified Classification
     * (Cls0ClassBase) object.
     */
    struct CreateOrUpdateClassificationObjectsResponse
    {
        /**
         * List of references of the newly created or updated Classification Objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0ClassBase>  > classificationObjects;
        /**
         * The Service Data response.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * This is the response structure that holds references to created or updated Hierarchy
     * nodes.
     */
    struct CreateOrUpdateHierarchyNodesResponse
    {
        /**
         * The list of created or updated Hierarchy node object.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  > nodeObjects;
        /**
         * The Service Data response. The created / updated objects will be returned in the
         * Create / Update lists.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * The structure contains a Property Name and an Expression that is used during search
     * operations.
     */
    struct FilterExpression
    {
        /**
         * The Property name to filter using (Ex: Diameter).
         */
        std::string propertyName;
        /**
         * The expression for the Property (Ex: >= 10.0) An expression is of the form: <operator>
         * : used only for IS_NULL, IS_NOT_NULL <operator> <value> : used for =,!=,>,>=,<,<=
         * <value> <operator> <value> : used for range(-) valid operators are:  =,!=,>,>=,<,<=,IS_NULL,IS_NOT_NULL,-(range)
         * Each expression can also contain a tolerance value that is specified in [] brackets
         * just after the value. The tolerance can be an absolute value or a % value.
         */
        std::string expression;
    };

    /**
     * This structure specifies the details of which objects to fetch from a given Result
     * Set.
     */
    struct GetClassificationSearchResultsInputInfo
    {
        /**
         * A reference to the Result Set containing all the objects found in the search.
         */
        std::string resultSet;
        /**
         * The position in the resultSet to start fetching the objects from.
         */
        int start;
        /**
         * The number of objects to fetch from resultSet.
         */
        int numObjects;
    };

    /**
     * This is the response structure that holds the Objects being returned.
     */
    struct GetClassificationSearchResultsResponse
    {
        /**
         * List of Classification objects fetched from the Result Set.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0ClassBase>  > objects;
        /**
         * The Service Data response.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * This structure provides the input information to be used while fetching the children
     * of the given Node.
     */
    struct GetHierarchyNodeChildrenInputInfo
    {
        /**
         * The Hierarchy Node for which the children need to be obtained.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  node;
        /**
         * An optional list of filters to be applied while getting the children. In case filtering
         * is not required, pass in an empty list.
         */
        std::vector< Cls0::Services::Classificationcore::_2013_05::Classification::FilterExpression > filters;
        /**
         * Indicates whether to fetch children at all levels or only the immediate children.
         */
        bool recursive;
        /**
         * An optional list of strings that indicate the extended information to be fecthed.
         * Example: InstanceCount. If no extended information is required, pass in an empty
         * list.
         */
        std::vector< std::string > extendedInfoRequested;
    };

    /**
     * This contains the response from the operation that holds the Children for each of
     * the input Nodes. The ChildrenMap structure has this information.
     */
    struct GetHierarchyNodeChildrenResponse
    {
        /**
         * A map containing  information about the children of each hierarchy node.
         */
        ChildrenMap children;
        /**
         * The ServiceData response.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * This is the response structure from this operation that contains the details of the
     * Nodes. This information includes things like Node Type, attached Icons / Images,
     * etc.
     */
    struct GetHierarchyNodeDetailsResponse
    {
        /**
         * A map containing the information about each Hierarchy node.
         */
        NodeDetailsMap nodeDetails;
        /**
         * The ServiceData response.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * This is the response structure that holds the information about the top level Nodes
     * for a Hierarchy.
     */
    struct GetTopLevelNodesResponse
    {
        /**
         * A list that contains the top level Hierarchy Nodes.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  > topLevelNodes;
        /**
         * The Service Data response. The top level nodes are returned in the Plain list of
         * serviceData.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * contains detailed information about one Hierarchy Node.
     */
    struct HierarchyNodeDetails
    {
        /**
         * Reference of the Hierarchy node to update with the supplied node details. For create
         * mode of this operation, this parameter will contain a NULL.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  nodeToUpdate;
        /**
         * Node ID of this Hierarchy node.
         */
        std::string nodeId;
        /**
         * Node Name of this Hierarchy node.
         */
        std::string nodeName;
        /**
         * Node Description for this Hierarchy node.
         */
        std::string nodeDesc;
        /**
         * Refers to the type of Hierarchy node [e.g. Group / Master / Reference]
         */
        HierarchyNodeType nodeType;
        /**
         * Reference to the immediate Parent Node of node.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  parent;
        /**
         * Type name of the storage class, associated with this Hierarchy node.
         * <br>
         * A storage class can only be assigned to a Master node type of Hierarchy nodes.
         */
        std::string storageClassTypeName;
        /**
         * References the Master node associated with this Reference node.
         * <br>
         * This parameter is only valid when working with Reference nodes. Also, it is a mandatory
         * parameter for Reference nodes.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  masterNode;
        /**
         * Flag to indicate whether the Hierarchy Node is a Leaf node or not.
         */
        bool isLeafNode;
        /**
         * Sort index for this Hierarchy node amongst its peers under the common parent.
         */
        int levelSortIndex;
        /**
         * Reference to the dataset object that holds the icon for this Node.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  icon;
        /**
         * Reference to the dataset object that holds all the images for this Node.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > images;
        /**
         * Reference to the dataset object that holds all other documents attached to this Node
         * (other than icon and images). This could be Word documents, Excel sheets etc.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > attachments;
        /**
         * Indicates whether the node is Abstract or Storage (Instantiable).
         */
        bool isAbstract;
        /**
         * Indicates whether the node classifies an Assembly.
         */
        bool isAssembly;
        /**
         * Indicates if the same object can be classified multiple times in this node.
         */
        bool allowMultipleClassification;
        /**
         * Instance count of the objects classified in this node.
         */
        int instanceCount;
    };

    /**
     * This structure holds property name and values for each property.
     */
    struct NameValueStruct
    {
        /**
         * The name of the property.
         */
        std::string name;
        /**
         * The value(s) of the property.
         */
        std::vector< std::string > values;
    };

    /**
     * This structure holds all the information needed to execute a search for Classification
     * objects.
     */
    struct SearchClassificationObjectsInputInfo
    {
        /**
         * The reference to an existing classification hierarchy node.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cls0HierarchyNode>  node;
        /**
         * Vector of Property names to be used in search criteria.
         */
        std::vector< std::string > propertyNames;
        /**
         * Vector of expressions. An expression is of the form: <operator> : used only for IS_NULL,
         * IS_NOT_NULL <operator> <value> : used for =,!=,>,>=,<,<= <value> <operator> <value>
         * : used for range(-) valid operators are:  =,!=,>,>=,<,<=,IS_NULL,IS_NOT_NULL,-(range)
         * Each expression can also contain a tolerance value that is specified in [] brackets
         * just after the value. The tolerance can be an absolute value or a % value.
         */
        std::vector< std::string > expressions;
        /**
         * For specifying certain search options. These options can be combined. Example: Whether
         * to find instances of only given node or all Children nodes as well o SEARCH_HIERARCHICAL
         * o SEARCH_COUNT_ONLY
         */
        int options;
        /**
         * Specifies the sort parameters to use while sorting the search results.
         */
        std::vector< Cls0::Services::Classificationcore::_2013_05::Classification::SortOrder > sortOrder;
    };

    /**
     * This is the response structure that holds information about the search results.
     */
    struct SearchClassificationObjectsResponse
    {
        /**
         * The number of objects found that match the search criteria.
         */
        int numRows;
        /**
         * Reference to a Result Set containing the objects found in the search. This is a reference
         * to a single object. Subsequent to this operation call, you need to call the getClassificationSearchResults
         * passing in this value to get the actual objects returned in the search operation.
         */
        std::string resultSet;
        /**
         * The Service Data response.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * This structure contains information about the Property name to be used for sorting
     * and the kind of sorting needed (Ascending / Descending).
     */
    struct SortOrder
    {
        /**
         * Specifies whether to do an Ascending or Descending sort.
         */
        bool ascendingSort;
        /**
         * Specifies the Property on which to sort by.
         */
        std::string sortProperty;
    };




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


protected:
    virtual ~Classification() {}
};
            }
        }
    }
}

#include <cls0/services/classificationcore/ClassificationCore_undef.h>
#endif

