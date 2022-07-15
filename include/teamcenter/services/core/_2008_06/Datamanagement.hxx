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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_DATAMANAGEMENT_HXX

#include <teamcenter/services/core/_2006_03/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Form.hxx>
#include <teamcenter/soa/client/model/GeneralDesignElement.hxx>
#include <teamcenter/soa/client/model/GeneralDesignElementLink.hxx>
#include <teamcenter/soa/client/model/ImanRelation.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/PSBOMViewRevision.hxx>
#include <teamcenter/soa/client/model/PSConnection.hxx>
#include <teamcenter/soa/client/model/PSConnectionRevision.hxx>
#include <teamcenter/soa/client/model/Participant.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2008_06
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct AddParticipantInfo;
    struct AddParticipantOutput;
    struct AttrInfo;
    struct BOHierarchy;
    struct BOWithExclusionIn;
    struct BVROutput;
    struct ConnectionOutput;
    struct ConnectionProperties;
    struct CreateConnectionsResponse;
    struct CreateInput;
    struct CreateIn;
    struct CreateOrUpdateGDELinksResponse;
    struct CreateOrUpdateItemElementsResponse;
    struct CreateOrUpdateRelationsInfo;
    struct CreateOrUpdateRelationsOutput;
    struct CreateOrUpdateRelationsResponse;
    struct CreateOut;
    struct CreateResponse;
    struct DatasetFilter;
    struct DatasetInfo;
    struct DatasetOutput;
    struct DatasetProperties2;
    struct DatasetRelationFilter;
    struct DeepCopyData;
    struct DisplayableBOsOut;
    struct DisplayableSubBOsResponse;
    struct GDELinkInfo;
    struct ItemInfo;
    struct RevInfo;
    struct GetItemAndRelatedObjectsInfo;
    struct GetItemAndRelatedObjectsItemOutput;
    struct GetItemAndRelatedObjectsResponse;
    struct GetNextIdsResponse;
    struct GetNRPatternsWithCountersResponse;
    struct GetRevNRAttachResponse;
    struct InfoForNextId;
    struct ItemElementProperties;
    struct ItemElementsOutput;
    struct MasterFormPropertiesInfo;
    struct NamedReferenceFilter;
    struct NamedReferenceList;
    struct NameValueStruct;
    struct NRAttachInfo;
    struct NROutput;
    struct ParticipantInfo;
    struct Participants;
    struct PatternsWithCounters;
    struct PropertyNameValueInfo;
    struct RelatedObjectInfo;
    struct ReviseInfo;
    struct ReviseOutput;
    struct ReviseResponse2;
    struct RevisionOutput;
    struct RevOptionDetails;
    struct SaveAsNewItemInfo;
    struct SaveAsNewItemOutput2;
    struct SaveAsNewItemResponse2;
    struct SecondaryData;
    struct TypeAndItemRevInfo;

    /**
     * A map of enum of processing information including <code>None,  All,  Min, Ids, Rule
     * and  Nrev</code>.
     */
    enum Processing{ ProcessingNone,
                 All,
                 Min,
                 Ids,
                 Rule,
                 Nrev
                 };

    /**
     * A map of attribute name to value pairs.
     */
    typedef std::map< std::string, std::string > AttributeMap;

    /**
     * Map of bool property names to values <code>(string, bool</code>).
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * Map of bool array property names to values (<code>string, vector< bool ></code>).
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * Map of reference or relation property name to secondary <code>CreateInput</code>
     * objects (<code>string, vector<CreateInput></code>).
     */
    typedef std::map< std::string, std::vector< CreateInput > > CreateInputMap;

    /**
     * Map of date property names to values (<code>string, date</code>).
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * Map of DateTime array property names to values (<code>string, vector<DateTime></code>).
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * Map of double property names to values (<code>string, double</code>).
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * Map of double array property names to values (<code>string, vector<double></code>).
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * Map of float property names to values (<code>string, float</code>).
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * Map of float array property names to values (<code>string, vector<float></code>).
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * Map of int property names to values (<code>string, int</code>).
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * Map of int array property names to values (<code>string, vector<int></code>).
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * A map of <code>ReviseOutput</code> (<code>string, ReviseOutput</code>).
     */
    typedef std::map< std::string, ReviseOutput > ReviseOutputMap;

    /**
     * A map of the clientId from the input data to the output  from the service (<code>string,
     * SaveAsNewItemOutput2</code>)
     */
    typedef std::map< std::string, SaveAsNewItemOutput2 > SaveAsNewItemOutputMap;

    /**
     * Map of string property names to values (<code>string, string</code>).
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * Map of string array property names to values (<code>string, vector<string></code>).
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * A map of successfully processed GDE link to GeneralDesignElementLink.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GeneralDesignElementLink>  > SuccessfullyProcessedGDELinksMap;

    /**
     * Map of <b>BusinessObject</b> property names to values (<code>string, BusinessObject</code>).
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * Map of <b>BusinessObject</b> array property names to values (<code>string, vector<BusinessObject></code>).
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * <code>AddParticipantInfo</code> structure is an input for the <code>addParticipants</code>
     * operation.
     */
    struct AddParticipantInfo
    {
        /**
         * An item revision to add participants to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * Contains information to create a new participant or find an existing one.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ParticipantInfo > participantInfo;
    };

    /**
     * <code>AddParticipantOutput</code> structure contains Item Revision and the added
     * participants along with Service Data.
     */
    struct AddParticipantOutput
    {
        /**
         * List of structures containing the participants and the object to which participants
         * are added.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::Participants > participantOutput;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for specifying name value pairs.
     */
    struct AttrInfo
    {
        /**
         * The name of the attribute.
         */
        std::string name;
        /**
         * The value of the attribute.
         */
        std::string value;
    };

    /**
     * This structure contains information for a bottom up hierarchy starting with a <b>Business
     * Object</b> name and going up the hierarchy of parents up to the primary <b>Business
     * Objec</b>t.
     */
    struct BOHierarchy
    {
        /**
         * <b>Business Object</b> Name
         */
        std::string BOName;
        /**
         * Ordered list of <b>Business Object</b> parents from bottom up
         */
        std::vector< std::string > BOParents;
    };

    /**
     * Structure to hold the information about Business Object name and its exclusion list.
     */
    struct BOWithExclusionIn
    {
        /**
         * Primary Business Object name for which hierarchies of displayable Business Objects
         * are returned.
         */
        std::string boTypeName;
        /**
         * List of Business Object names to be excluded from the returned list.
         */
        std::vector< std::string > exclusionBOTypeNames;
    };

    /**
     * This structure contains bom view revision information.
     */
    struct BVROutput
    {
        /**
         * The BVR associated with the <b>ItemRevision</b> if requested.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  bvr;
        /**
         * The bvr view type.
         */
        std::string viewTypeName;
    };

    /**
     * This structure contains information for <code>createConnections</code> operation.
     */
    struct ConnectionOutput
    {
        /**
         * Identifying string from the source ConnectionProperties.
         */
        std::string clientId;
        /**
         * The newly created <b>Connection</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSConnection>  connection;
        /**
         * The initial revision for the newly created <b>ConnectionRevision</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSConnectionRevision>  connectionRev;
    };

    /**
     * Input structure for createConnections operation.  Specifies attributes for the new
     * Connection or ConnectionRevision.
     */
    struct ConnectionProperties
    {
        /**
         * A unique string supplied by the caller for each ConnectionProperties. This ID is
         * used to identify returned ConnectionOutput elements and Partial Errors associated
         * with the input ConnectionProperties, optional
         */
        std::string clientId;
        /**
         * The ID of the <b>Connection</b> to be created, optional
         */
        std::string connId;
        /**
         * The name of the <b>Connection</b> to be created, optional
         */
        std::string name;
        /**
         * The type of the <b>Connection</b> to be created. The default type is <i>Connection</i>
         */
        std::string type;
        /**
         * The ID of the initial revision of the <b>Connection</b> to be created, optional
         */
        std::string revId;
        /**
         * The description text for the <b>Connection</b> to be created, optional
         */
        std::string description;
        /**
         * Any additional attribute values to be set on the created <b>Connection</b>, <b>ConnectionRevision</b>
         * or coresponding Master Forms, optional
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::ExtendedAttributes > extendedAttributes;
    };

    /**
     * Return structure for createConnections operation
     */
    struct CreateConnectionsResponse
    {
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of created <b>Connection</b> objects and associate <b>ConnectionRevision</b>
         * in the form of ConnectionsOutput structure.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ConnectionOutput > output;
    };

    /**
     * This structure captures the inputs required for creation of a business object. This
     * is a recursive structure containing the <code>CreateInput</code>(s) for any secondary(compounded)
     * objects that might be created (e.g <b>Item</b> also creates <b>ItemRevision</b> and
     * <b>ItemMaster</b> Form, etc.)
     */
    struct CreateInput
    {
        /**
         * Business object type name
         */
        std::string boName;
        /**
         * Map of string property names to values (<code>string, string</code>)
         */
        StringMap stringProps;
        /**
         * Map of string array property names to values (<code>string, vector<string></code>)
         */
        StringVectorMap stringArrayProps;
        /**
         * Map of double property names to values (<code>string, double</code>)
         */
        DoubleMap doubleProps;
        /**
         * Map of double array property names to values (<code>string, vector<double></code>)
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map of float property names to values (<code>string, float</code>)
         */
        FloatMap floatProps;
        /**
         * Map of float array property names to values (<code>string, vector<float></code>)
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map of int property names to values (<code>string, int</code>)
         */
        IntMap intProps;
        /**
         * Map of int array property names to values (<code>string, vector<int></code>)
         */
        IntVectorMap intArrayProps;
        /**
         * Map of boolean property names to values (string, bool)
         */
        BoolMap boolProps;
        /**
         * Map of boolean array property names to values (<code>string, vector<bool></code>)
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map of DateTime property names to values (<code>string, DateTime</code>)
         */
        DateMap dateProps;
        /**
         * Map of DateTime array property names to values (<code>string, vector<DateTime></code>)
         */
        DateVectorMap dateArrayProps;
        /**
         * Map of BusinessObject property names to values (<code>string, BusinessObjec</code>t)
         */
        TagMap tagProps;
        /**
         * Map of <b>BusinessObject</b> array property names to values (<code>string, vector<BusinessObject></code>)
         */
        TagVectorMap tagArrayProps;
        /**
         * Map of reference or relation property name to secondary <code>CreateInput</code>
         * objects <code>(string, vector<CreateInput></code>)
         */
        CreateInputMap compoundCreateInput;
    };

    /**
     * The data structure contains data for <code>creation</code> operation.
     */
    struct CreateIn
    {
        /**
         * Unique client identifier. If there is an error in create, the client id in the ServiceData
         * PartialError list can be used to associate to the clientId in the input to detect
         * which object creation failed.
         */
        std::string clientId;
        /**
         * Input data for create operation. This is essentially a map of property name-value
         * pairs representing the input data for creation. It also is recursive referencing
         * secondary input data (e.g For Item creation, the primary input data is for Item and
         * secondary input data is for Item Master and ItemRevision).
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::CreateInput data;
    };

    /**
     * Create Or Update GDE Links Response
     */
    struct CreateOrUpdateGDELinksResponse
    {
        /**
         * A map containing the clientIds and the successfully created/updated <b>GeneralDesignElementLink</b>
         * objects
         */
        SuccessfullyProcessedGDELinksMap successfullyProcessedGDELinks;
        /**
         * Service data to report partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Return structure for createOrUpdateItemElements operation
     */
    struct CreateOrUpdateItemElementsResponse
    {
        /**
         * Standard ServiceData member containing created/updated objects and partial errors
         * if any
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of createItemElementsOutput
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ItemElementsOutput > output;
    };

    /**
     * The required parameters to create the relation between the primary and secondary
     * object.
     */
    struct CreateOrUpdateRelationsInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Realtion of interest, required for create or update.
         */
        std::string relationType;
        /**
         * The primary object of interest, required for create or update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * List of secondary objects per primaryObject via relation of type <code>relationType</code>.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::SecondaryData > secondaryData;
        /**
         * Instead of secondary business object in <code>secondaryData</code> and <code>primaryObject</code>,
         * this can be used, if such an object is available. This is only used if the <code>primaryObject</code>
         * is not specified. If <code>relations</code> is specified, the primaries for all of
         * them must be the same and the <code>relations</code> must have the same <code>relationType</code>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  > relations;
    };

    /**
     * This structure contains information for <code>CreateOrUpdateRelationsOutput</code>.
     */
    struct CreateOrUpdateRelationsOutput
    {
        /**
         * The unmodified value from the <code>CreateOrUpdateRelationsInfo.clientId</code>.
         * This can be used by the caller to indentify this data structure with the source input
         * data
         */
        std::string clientId;
        /**
         * The newly created relation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  > relations;
    };

    /**
     * The relations created based on the input primary, secondary and relation type information
     * and the errors that might have been encountered while creating, updating the relations.
     */
    struct CreateOrUpdateRelationsResponse
    {
        /**
         * A list of <code>CreateOrUpdateRelationsOutput</code>
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateRelationsOutput > output;
        /**
         * Standard <code>ServiceData</code> object to hold the partial errors that the operation
         * encounters.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information or create operation including unique client identifier.
     */
    struct CreateOut
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * A list of objects that were created
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * Response object for create operation containing vector of objects that were created
     * and partial errors.
     */
    struct CreateResponse
    {
        /**
         * Vector of output objects representing objects that were created.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOut > output;
        /**
         * Service Data including partial errors that are mapped to the client id from the input.
         * Created objects are also added to the created objects list in the Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure contains information for determining which datasets to return.
     */
    struct DatasetFilter
    {
        /**
         * Filter with the <code>datasetName</code> first.
         */
        bool useNameFirst;
        /**
         * An enum to specify what data to use to determine <b>Datasets</b> to return. Valid
         * values are All, Min, or None.
         */
        Processing processing;
        /**
         * Filter to select datasets with a particular named reference to a specific uid. If
         * empty then not used in filtering.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NamedReferenceFilter > nrFilters;
        /**
         * The name of the <b>Dataset</b> objects to return. If empty then not used in filtering.
         */
        std::string name;
        /**
         * The relation filters to use.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DatasetRelationFilter > relationFilters;
    };

    /**
     * Input structure that the information for determining which datasets to return. If
     * the <code>datasetUid</code> is specified, then only that dataset will be returned.
     * If the dataset does not exist then a null dataset is returned. If the <code>datasetUid</code>
     * is not specified then the dataset filter determines the datasets to return. For each
     * dataset to be returned, the <code>NamedRef</code> will determine the named reference
     * information to return. For each named reference returned that is a reference to a
     * file, an FMS read ticket will be returned if <code>ticket</code> is set.
     */
    struct DatasetInfo
    {
        /**
         * A unique string used to identify return data elements and partial errors associated
         * with this input structure.
         */
        std::string clientId;
        /**
         * The uid of the only <b>Dataset</b> to return.
         */
        std::string uid;
        /**
         * If a UID is not specified, determines the <b>Dataset</b> objects to return.
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::DatasetFilter filter;
        /**
         * Information about named references to return for each <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NamedReferenceList > namedRefs;
    };

    /**
     * Output structure for <b>Dataset</b> information
     */
    struct DatasetOutput
    {
        /**
         * A unique string used to identify return data elements and partial errors associated
         * with this input structure.
         */
        std::string clientId;
        /**
         * <b>Dataset</b> object .
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Relationship type to the dataset.
         */
        std::string relationTypeName;
        /**
         * The list of <code>NROutput</code> for the dataset if requested.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NROutput > namedReferenceOutput;
    };

    /**
     * Input structure for createDatasets operation
     */
    struct DatasetProperties2
    {
        /**
         * Identifier that helps the client to track the object(s) created, required; should
         * be unique for the input set
         */
        std::string clientId;
        /**
         * Type of the <b>Dataset</b> to be created
         */
        std::string type;
        /**
         * Name of the <b>Dataset</b> to be created
         */
        std::string name;
        /**
         * Description of the <b>Dataset</b> to be created, may be an empty string.
         */
        std::string description;
        /**
         * Name of the <b>Tool</b> used to open the created <b>Dataset</b>, may be an empty
         * string.  If it is an empty string no <b>Tool</b> will be associated to the <b>Dataset</b>
         * to be created.
         */
        std::string toolUsed;
        /**
         * Unique identifier for the <b>Dataset</b>, may be an empty string. If the preference
         * AE_datase_id_usage is ON, the id will be generated through user exit mechanism.
         */
        std::string datasetId;
        /**
         * The revision of this <b>Dataset</b>, may be an empty string.  If the preference AE_datase_id_usage
         * is ON, the rev will be generated through user exit mechanism.
         */
        std::string datasetRev;
        /**
         * Object reference of the container used to hold the created dataset, optional
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container;
        /**
         * Name of the relation type for the <b>Dataset</b> to be created, may be an empty string.
         */
        std::string relationType;
    };

    /**
     * This structure contains information for determining which datasets to consider to
     * return. The relation type and <b>Dataset</b> type will be used to produce a set of
     * datasets.
     */
    struct DatasetRelationFilter
    {
        /**
         * The relation type name specifies the relation that relates the <b>ItemRevision</b>
         * to the <b>Dataset</b>. If not specified then all.
         */
        std::string relationTypeName;
        /**
         * The type name of<b> Dataset</b> to return. If empty then all.
         */
        std::string datasetTypeName;
    };

    /**
     * The data structure holds information required to apply deep copy rules.
     */
    struct DeepCopyData
    {
        /**
         * Object on which the deep copy should be performed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  otherSideObjectTag;
        /**
         * Name of the relation that need to be deep copied.
         */
        std::string relationTypeName;
        /**
         * New name for the new copy of the object represented by the <code>otherSideObject</code>.
         * The value for the <code>newName</code> will be null if 'action' is not <code>CopyAsObject</code>
         * or <code>ReviseAndRelateToLatest</code>.
         */
        std::string newName;
        /**
         * Integer representing the action to be performed on the object represented by '<code>otherSideObjectTag</code>'.
         * <br>
         * The values for action are:
         * <br>
         * <ul>
         * <li type="disc">CopyAsObjectType = 0
         * </li>
         * <li type="disc">CopyAsRefType = 1
         * </li>
         * <li type="disc">DontCopyType =2
         * </li>
         * <li type="disc">RelateToLatest = 3
         * </li>
         * <li type="disc">ReviseAndRelateToLatest = 4
         * </li>
         * </ul>
         */
        int action;
        /**
         * Indicates whether the given <b>ItemRrevision</b> is a primary object in the relation
         * to be deep copied.
         */
        bool isTargetPrimary;
        /**
         * Indicates whether the deep information is from a mandatory deepcopy rule
         */
        bool isRequired;
        /**
         * Indicates whether the properties on the relation should be copied
         */
        bool copyRelations;
    };

    /**
     * This structure contains a list of displayable business(BO) object under a given BO
     * (displayable sub-BO hierarchy).
     */
    struct DisplayableBOsOut
    {
        /**
         * Business object name for which displayable hierarchy is returned
         */
        std::string boTypeName;
        /**
         * Hierarchy of displayable business Objects
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::BOHierarchy > displayableBOTypeNames;
    };

    /**
     * Response for getDisplayableBusinessObjects
     */
    struct DisplayableSubBOsResponse
    {
        /**
         * Vector of output objects representing displayable types during create of a BO
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DisplayableBOsOut > output;
        /**
         * Service data including partial errors that are mapped to the input BO type name
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * GDE Link Information
     */
    struct GDELinkInfo
    {
        /**
         * A unique string identifier supplied by the caller for each GDELinkInfo. This ID is
         * used to identify returned GDELink objects and Partial Errors associated with the
         * input properties.
         */
        std::string clientID;
        /**
         * Name of the GDELink to be created.
         */
        std::string name;
        /**
         * The description text for the GDELink to be created.
         */
        std::string description;
        /**
         * Type of the GDELink that needs to be created. The default type is <i>GeneralDesignElementInfoLink</i>.
         */
        std::string type;
        /**
         * Existing GDELink to update (will be null in case of creation)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GeneralDesignElementLink>  gdeLink;
        /**
         * Any additional attribute values to be set on the created GDELink.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NameValueStruct > attributes;
    };

    /**
     * This structure contains either an item id or uid. Has a flag that indicates if the
     * id is to be used first. If set then the id will be used. If the id does not resolve
     * to an item then the uid will be used. If the flag is not set then the uid will be
     * used first. If the uid does not resolve to an item then the id will be used. If no
     * matching item is found then a null entry is placed in the output list and an error
     * is returned.
     */
    struct ItemInfo
    {
        /**
         * Client Identifier generated by client to identify output
         */
        std::string clientId;
        /**
         * A flag to indicate if the id is to be used before the uid.
         */
        bool useIdFirst;
        /**
         * <b>Item</b> uid string for <b>Item</b> to retrieve.
         */
        std::string uid;
        /**
         * List of attributes and values for selecting the item. For pre TC8.1 versions only
         * one entry is supported. This entry has the name <code>item</code>_id.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::AttrInfo > ids;
    };

    /**
     * This structure contains information to determine the revisions to return.
     */
    struct RevInfo
    {
        /**
         * Client Identifier generated by client to identify output.
         */
        std::string clientId;
        /**
         * An enum to specify what data to use to determine revisions.  Valid values are All,
         * None, Nrev,Min,Rule or Ids.
         */
        Processing processing;
        /**
         * A flag to indicate if the id is to be used before the uid.
         */
        bool useIdFirst;
        /**
         * Revision uid for revision to retrieve.
         */
        std::string uid;
        /**
         * Revision id for revision to retrieve.
         */
        std::string id;
        /**
         * The number of revisions to retrieve, or the number of existing revisions, whichever
         * is smaller. The revisions returned will be the latest ones. The first one returned
         * is the oldest of the group. The last the latest.
         */
        int nRevs;
        /**
         * The revision rule to be used.
         */
        std::string revisionRule;
    };

    /**
     * Input structure for <code>GetItemAndRelatedObjects</code>. Must have a <code>clientId</code>,
     * must contain an <code>itemInfo</code> that is valid, may contain a list of information
     * about revisions to return. If any bvr names are given then the tags for the BVRs
     * will be returned.
     */
    struct GetItemAndRelatedObjectsInfo
    {
        /**
         * Client Identifier generated by client to identify output
         */
        std::string clientId;
        /**
         * Item specifications
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::ItemInfo itemInfo;
        /**
         * Revision specifications
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::RevInfo revInfo;
        /**
         * Filter used to select datasets to return.
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::DatasetInfo datasetInfo;
        /**
         * A list of a BVRs to return. optional.
         */
        std::vector< std::string > bvrTypeNames;
    };

    /**
     * This structure contains item information.
     */
    struct GetItemAndRelatedObjectsItemOutput
    {
        /**
         * Identifier of input data used to generate output.
         */
        std::string clientId;
        /**
         * <b>Item</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * List of <code>RevisionOutputs</code>. When multiple are returned, the order will
         * be oldest first to latest last.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::RevisionOutput > itemRevOutput;
    };

    /**
     * Return structure for <code>GetItemAndRelatedObjects</code> operation
     */
    struct GetItemAndRelatedObjectsResponse
    {
        /**
         * List of <code>GetItemAndRelatedObjectsItemOutput</code>
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::GetItemAndRelatedObjectsItemOutput > output;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response structure for <code>getNextIds</code> service operation.
     */
    struct GetNextIdsResponse
    {
        /**
         * List containing next Id strings generated as per the pattern.
         */
        std::vector< std::string > nextIds;
        /**
         * Standard <code>ServiceData</code> structure. It contains partial errors and failures
         * along with the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response structure for getNRPatternsWithCounters service operation.
     */
    struct GetNRPatternsWithCountersResponse
    {
        /**
         * List of structs which contain Patterns which has counters.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::PatternsWithCounters > patterns;
        /**
         * List of preferred patterns.
         */
        std::vector< std::string > preferredPattern;
        /**
         * List of conditions.
         */
        std::vector< std::string > condition;
        /**
         * Standard ServiceData structure. It contains partial errors and failures along with
         * the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response structure for getRevNRAttachDetails service operation.
     */
    struct GetRevNRAttachResponse
    {
        /**
         * List containing information about Initial Revision Type.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::RevOptionDetails > initRevDetails;
        /**
         * List containing information about Secondary Revision Type.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::RevOptionDetails > secRevDetails;
        /**
         * List containing information about Supplemental Revision Type.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::RevOptionDetails > supplRevDetails;
        /**
         * List of exluded letters.
         */
        std::vector< std::string > excludedLetters;
        /**
         * Standard ServiceData structure. It contains partial errors and failures along with
         * the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for <code>getNextIds</code> operation. It contains information about
     * the object type, property name and pattern to be used for id generation.
     */
    struct InfoForNextId
    {
        /**
         * Type Name
         */
        std::string typeName;
        /**
         * Property Name
         */
        std::string propName;
        /**
         * Pattern String
         */
        std::string pattern;
    };

    /**
     * Input structure for createOrUpdateItemElements operation
     */
    struct ItemElementProperties
    {
        /**
         * Identifier that helps the client to track the object(s) created should be unique
         * for the input set
         */
        std::string clientId;
        /**
         * Name of the ItemElement to be created
         */
        std::string name;
        /**
         * Type of the ItemElement to be created. If it is not passed, operation takes default
         * type.
         */
        std::string type;
        /**
         * Description of the ItemElement to be created
         */
        std::string description;
        /**
         * Map<String,String> containing the attributes to be modified and its values. Required
         * in case of updating an existing <i>GDE</i>.
         */
        AttributeMap itemElemAttributes;
        /**
         * ItemElement to be updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  itemElement;
    };

    /**
     * This structure contains information for <code>createOrUpdateItemElements</code> operation.
     */
    struct ItemElementsOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * <b>ItemElement</b> object that was created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GeneralDesignElement>  itemElem;
    };

    /**
     * The data structure holds information for specifying property values to be set on
     * a <b>Form</b>.
     */
    struct MasterFormPropertiesInfo
    {
        /**
         * Reference to <b>Form</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Form>  form;
        /**
         * A list of propertie names and values
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::PropertyNameValueInfo > propertyValueInfo;
    };

    /**
     * This structure contains information for determining which datasets to consider to
     * return. This specifies a list of named references and the UID referenced by the named
     * reference.
     */
    struct NamedReferenceFilter
    {
        /**
         * The name of the named reference.
         */
        std::string namedReference;
        /**
         * The unique identifier referenced.
         */
        std::string uidReferenced;
    };

    /**
     * This structure contains information determining which named reference information
     * to return. This specifies a named reference to return and a flag to specify, if the
     * named reference is to a file, to return an FMS read ticket.
     */
    struct NamedReferenceList
    {
        /**
         * Named Reference to return.
         */
        std::string namedReference;
        /**
         * If this Named Reference is to a file, include an FMS read ticket if set.
         */
        bool ticket;
    };

    /**
     * This structure contains property name and value pairs for each property.
     */
    struct NameValueStruct
    {
        /**
         * Title of the attribute like time, act_location that needs to be set
         */
        std::string name;
        /**
         * Values of the attribute to be set
         */
        std::vector< std::string > values;
    };

    /**
     * NRAttachInfo structure contains information about the object type and property name
     * for which Naming Rule information needs to be obtained.
     */
    struct NRAttachInfo
    {
        /**
         * Type Name
         */
        std::string typeName;
        /**
         * Property Name
         */
        std::string propName;
    };

    /**
     * This structure contains named reference information.
     */
    struct NROutput
    {
        /**
         * Object referenced
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  namedReference;
        /**
         * Named Reference name
         */
        std::string namedReferenceName;
        /**
         * Read ticket if referenced file and if requested.
         */
        std::string ticket;
    };

    /**
     * This structure contains information about new participant to be created or to find
     * an existing one.
     */
    struct ParticipantInfo
    {
        /**
         * The participant which can be a <b>User</b>, <b>GroupMember</b> or a <b>ResourcePool</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  assignee;
        /**
         * Participant type to be assigned or added.  List of <b>Participant</b> types provided
         * are:
         * <br>
         * <ul>
         * <li type="disc">ProposedResponsibleParty
         * </li>
         * <li type="disc">ProposedReviewer
         * </li>
         * <li type="disc">ChangeImplementationBoard
         * </li>
         * <li type="disc">ChangeReviewBoard
         * </li>
         * <li type="disc">ChangeSpecialist1
         * </li>
         * <li type="disc">ChangeSpecialist2
         * </li>
         * <li type="disc">ChangeSpecialist3
         * </li>
         * <li type="disc">Analyst
         * </li>
         * <li type="disc">Requestor
         * </li>
         * </ul>
         * <br>
         * <br>
         * Custom participant types are also allowed.
         */
        std::string participantType;
        /**
         * A unique string supplied by the caller
         */
        std::string clientId;
    };

    /**
     * <code>Participants</code> structure contains the participants to be added / removed
     * and object to which participants are to be added or removed.
     */
    struct Participants
    {
        /**
         * Item Revision to which the <b>Participant</b> objects are added/removed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * List of <b>Participant</b> objects to be added/removed.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Participant>  > participant;
    };

    /**
     * This structure holds patterns with counters.
     */
    struct PatternsWithCounters
    {
        /**
         * A list of pattern strings with counters
         */
        std::vector< std::string > patternStrings;
    };

    /**
     * This structure contains information for specifying property name value pairs.
     */
    struct PropertyNameValueInfo
    {
        /**
         * Name of the property
         */
        std::string propertyName;
        /**
         * A list of value(s) of the property
         */
        std::vector< std::string > propertyValues;
    };

    /**
     * The data structure for specifying related object information.
     */
    struct RelatedObjectInfo
    {
        /**
         * Object related to the new <b>Item</b> or <b>IitemRevision</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  relatedObject;
        /**
         * An integer representing the action that specifies the why the relatedObject as the
         * other side object while applying the deep copy rules. Valid values are : CopyAsObjectType
         * = 0, (A new copy of the object represented by otherSideObjectTag will be created
         * and while propagatring the relations) CopyAsRefType = 1, (The same object represented
         * by otherSideObjectTag will be used to propagate the relations) DontCopyType =2, (The
         * relation will not be propagated.) RelateToLatest = 3, (If the other side object is
         * an ItemRevision, then the latest version of the revision will be used while propagating
         * the relation) ReviseAndRelateToLatest = 4 (If the other side object is an Item Revision,
         * it will be revised and the newly created revision will be used while propagating
         * the relations)
         */
        int action;
        /**
         * Flag indicating whether the <code>relatedObject</code> is participating as a secondary
         * object in the relation.
         */
        bool isSecondary;
    };

    /**
     * The data structure contains the information required to create the new revision.
     * If <code>DeepCopyInfo</code> is supplied it overrides the existing relations on
     * the existing <b>ItemRevision</b>.
     */
    struct ReviseInfo
    {
        /**
         * Identifier to uniquely identify the input
         */
        std::string clientId;
        /**
         * Original <b>ItemRevision</b> object to be used for the revise operation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  baseItemRevision;
        /**
         * <b>ItemRevision</b> id string for creating new <b>ItemRevision</b> object
         */
        std::string newRevId;
        /**
         * Name string for creating new <b>Item</b>/<b>ItemRevision</b>
         */
        std::string name;
        /**
         * Description string for creating new <b>Item</b>/<b>ItemRevision</b>
         */
        std::string description;
        /**
         * List of <code>DeepCopyData</code> objects to be used for propagating the relations
         * of the <b>ItemRevision</b>. If this list is supplied, then only the relations listed
         * in this list will be carried forward to the new <b>ItemRevision</b>. No other Deep
         * Copy Rules defined in the system will get applied. Thus the <code>DeepCopyData</code>
         * in this list overrides everything defined in the system to carry forward the relations
         * of the <b>ItemRevision</b>.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DeepCopyData > deepCopyInfo;
        /**
         * The information for the new <b>ItemRevisionMaster</b> Form property values
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::MasterFormPropertiesInfo newItemRevisionMasterProperties;
    };

    /**
     * This structure contains newly created <b>ItemRevision</b> object and related objects.
     */
    struct ReviseOutput
    {
        /**
         * Newly created <b>ItemRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  newItemRev;
        /**
         * A list of <code>RelatedObjectInfo</code> which represents the new objects created
         * or the existing the objects used to propagate the relations during the deep copy.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::RelatedObjectInfo > relatedObjects;
    };

    /**
     * Return structure for revise operation.
     */
    struct ReviseResponse2
    {
        /**
         * Map whose keys are the input clientIds and output values pairs (<code>string</code>,
         * <code>ReviseOutput</code>).
         */
        ReviseOutputMap reviseOutputMap;
        /**
         * This contains the status of the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Output structure containing revision information
     */
    struct RevisionOutput
    {
        /**
         * Identifier of input data used to generate output.
         */
        std::string clientId;
        /**
         * <b>ItemRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The BVRs associated with the item revision if requested.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::BVROutput > bvrs;
        /**
         * List of <code>DatasetOutput</code>.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DatasetOutput > datasetOutput;
    };

    /**
     * This structure contain revision option details.
     */
    struct RevOptionDetails
    {
        /**
         * The next available revision option
         */
        std::string revOption;
        /**
         * Format specified for revision type.
         */
        int revFormat;
    };

    /**
     * This data structure contain existing and new object info for save as new <b>Item</b>
     * operation.
     */
    struct SaveAsNewItemInfo
    {
        /**
         * Identifier to uniquely identify the input
         */
        std::string clientId;
        /**
         * Original <b>ItemRevision</b> to be used for the <code>ItemRevisionSaveAs</code> operation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  baseItemRevision;
        /**
         * <b>Item</b> id string for creating new <b>Item</b>
         */
        std::string newItemId;
        /**
         * <b>ItemRevision</b> id string for creating new <b>ItemRevision</b>
         */
        std::string newRevId;
        /**
         * Name string for creating new <b>Item</b>/<b>ItemRevision</b>.
         */
        std::string name;
        /**
         * Description string for creating new <b>Item</b>/<b>ItemRevision</b>
         */
        std::string description;
        /**
         * List of deep copy data to be used for propagating the relations of the <b>ItemRevision</b>.
         * If this list is supplied, then only the relations listed in this list will be carried
         * forward to the new <b>ItemRevision</b>. No other Deep Copy Rules defined in the system
         * will get applied. Thus the <code>DeepCopyData</code> in this list overrides everything
         * defined in the system to carry forward the relations of the <b>ItemRevision</b>.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DeepCopyData > deepCopyInfo;
        /**
         * The properties to be set for the newly created master form of the new <b>Item</b>
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::MasterFormPropertiesInfo newItemMasterProperties;
        /**
         * The properties to be set for the newly created master form of the new <b>ItemRevision</b>
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::MasterFormPropertiesInfo newItemRevisionMasterProperties;
    };

    /**
     * The data strucutre contains newly created object inforamtiobn.
     */
    struct SaveAsNewItemOutput2
    {
        /**
         * Newly created <b>Item</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  newItem;
        /**
         * Newly created <b>ItemRevision</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  newItemRev;
        /**
         * List of newly created related objects
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::RelatedObjectInfo > relatedObjects;
    };

    /**
     * The data structure contains return information for the operation.
     */
    struct SaveAsNewItemResponse2
    {
        /**
         * Map whose keys are the input clientIds and output values pairs(<code>string</code>,
         * <code>SaveAsNewItemOutput2</code>)
         */
        SaveAsNewItemOutputMap saveAsOutputMap;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for secondary object data.
     */
    struct SecondaryData
    {
        /**
         * identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * the secondary object pointed to by the relation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondary;
        /**
         * Object associated with the relation to the above secondary object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  userData;
        /**
         * Additional attributes to be set on the relation. These are meant for any derived
         * classes of <b>TCRelation</b> with additional attributes.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NameValueStruct > properties;
    };

    /**
     * <code>TypeAndItemRevInfo</code> structure contains information about the object type
     * and revision for which Revision Naming Rule information needs to be obtained.
     */
    struct TypeAndItemRevInfo
    {
        /**
         * Type name of <b>Item</b> or <b>ItemRevision</b>.
         */
        std::string typeName;
        /**
         * <b>ItemRevision</b> object selected.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
    };




    /**
     * Operation to retrieve sub Business Object Names for a Business Object that are displayable
     * to the login user in the object creation dialog. e.g File-new, select Item, what
     * types to be displayed for Item
     *
     * @param input
     *        - a list of input objects representing the BO type names for which the displayable
     *        types are to be retrieved
     *
     * @return
     *         contains a list of BO type names to be displayed for input
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::DisplayableSubBOsResponse findDisplayableSubBusinessObjects ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::BOWithExclusionIn >& input ) = 0;

    /**
     * This operation creates a list of <b>Dataset</b> objects and creates the specified
     * relation type between created <b>Dataset</b> and input container object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param input
     *        The information needed to create  <b>Dataset</b>
     *
     * @return
     *         Created <b>Datasets</b> and update container objects will be returned in the <code>ServiceData</code>
     *         lists of created and updated objects respectively.  Any failure will be returned
     *         with client id mapped to error message in the <code>ServiceData</code> list of partial
     *         errors. The error code of the failures can be any of follows:
     *         <br>
     *         <ul>
     *         <li type="disc">214122: Name or Type of the <b>Dataset</b> to be created is not provided
     *         </li>
     *         <li type="disc">525084: User does not have write privilege to the container object
     *         </li>
     *         <li type="disc">9010:  Unable to find type of <b>Dataset</b> to be created.
     *         </li>
     *         <li type="disc">9008: Specified Tool of the <b>Dataset</b> to be created is invalid.
     *         </li>
     *         <li type="disc">89015: Fail to create relation between the container object and the<b>
     *         Dataset</b> to be created.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::CreateDatasetsResponse createDatasets2 ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DatasetProperties2 >& input ) = 0;

    /**
     * This operation returns <b>Items</b>, <b>ItemRevisions</b>, <b>Dataset</b> and <b>NamedReference</b>
     * information based on the input. Input is a list of <code>GetItemAndRelatedObjectsInfo</code>
     * structures each of which contains item uid or id, revison information and optionally
     * a list of filters to determine the datasets to be returned. For the <b>Datasets</b>
     * the client can request information about the <b>NamedReferences</b>. <b>NamedReferences</b>
     * are how <b>Data</b> files are attached to <b>Datasets</b>. The Data file is what
     * a CAD client is really interested in. The return is a <code>GetItemAndRelatedObjectsResponse</code>
     * which contains a list of <code>GetItemAndRelatedObjectsItemOutput</code> and a <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The client has an item of <b>ItemRevision</b> and needs to know what CAD data is
     * attached to the <b>ItemRevision</b>. The client fills in either the <b>Item</b> or
     * <b>ItemRevision</b> information along with the information about the types of <b>Dataset</b>
     * and <b>NamedReferences</b> the client is interested in. For the <b>NamedReferences</b>
     * the user can get the tickets which will allow the client retrieve the files attached
     * to the <b>Datasets</b>. The results of the query will give the client all the information
     * about the <b>Datasets</b> and <b>NamedReferences</b> and optional tickets.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param infos
     *        list of <code>GetItemAndRelatedObjectsInfo</code> structures.
     *
     * @return
     *         Contains found items, revisions and the datasets attached to the revision. Partial
     *         Errors will be returned as a map of input client id to error message.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetItemAndRelatedObjectsResponse getItemAndRelatedObjects ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::GetItemAndRelatedObjectsInfo >& infos ) = 0;

    /**
     * This operation provides the ability to revise the <b>ItemRevision</b> objects given
     * in the input list and carries forward relations to existing objects. When applying
     * deep copy rules, if user overridden deep copy information is provided in the input,
     * relations are propagated to the new <b>ItemRevision</b> based on that input. If no
     * deep copy information is provided in the input, the deep copy rules in the database
     * are used to propagate relations to the new <b>ItemRevision</b>.  If the input contains
     * property values for the master form, those values are set on the new <b>ItemRevision</b>
     * master form.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param info
     *        The necessary information to create the new revision
     *
     * @return
     *         This operation returns a <code>ReviseResponse2</code> structure for revise operation
     *         or errors. The following errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">214124: The Rev Properties has NULL values, the system default will
     *         be used.
     *         </li>
     *         <li type="disc">214127: Empty input values for Item master form properties.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::ReviseResponse2 revise2 ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ReviseInfo >& info ) = 0;

    /**
     * This operation provides the capability to create one or more new <b>Item</b> objects
     * based on a list of existing <b>ItemRevision</b> objects. It optionally carries forward
     * <b>ItemRevision</b> relations based on the <code>deepCopyRequired</code> flag. When
     * applying deep copy rules, if user overridden deep copy information is provided in
     * the input, then old <b>ItemRevision</b> relations are propagated to the new <b>ItemRevision</b>
     * based on the input. If no deep copy rule information is provided in the input, the
     * deep rules in the database will be applied. If user provides new property values
     * for the <b>Item</b> and <b>ItemRevision</b> master forms in the input, then these
     * will be copied to the master forms of the newly created <b>Item</b> and <b>ItemRevision</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param info
     *        The necessary information to create the new <b>Iitem</b> and <b>ItemRevision</b>
     *
     * @return
     *         A <code>SaveAsNewItemResponse2</code> structure which contains information about
     *         the new <b>Item</b>, <b>ItemRevision</b> and related objects as well as a <code>ServiceData</code>
     *         structure containing error information in the <code>PartialErrors</code> list. The
     *         following error may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">70007: Invalid object  - the requested object does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::SaveAsNewItemResponse2 saveAsNewItem2 ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::SaveAsNewItemInfo >& info ) = 0;

    /**
     * The operation generates the next id as per the input pattern in the attached Naming
     * Rule to the property of an object type. The type name, property name and pattern
     * are passed in the input structure. The input for this operation contains a  list
     * of this structure. The return structure contains the list of nextId along with the
     * service data member. In the case where no pattern is specified, a default ID will
     * be returned if the type, property combination is <b>Item</b> / item_id, <b>Dataset</b>
     * / pubr_object_id or <b>ItemRevision</b>/item_revision_id. For all other type, property
     * combinations, the operation will not generate a default ID.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is called on click of "Assign" button in create, revise and save-as
     * dialogs to generate the next available options for item and revision ids. The generated
     * values are used as input for create, revise and save-as operations.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param vInfoForNextId
     *        Contains Type Name, Property Name and pattern.
     *
     * @return
     *         List containing nextId strings generated as per the pattern. Failure for any structure
     *         in the input list is indexed correspondingly along with error details and is stored
     *         in the service data member. If there are no failures, then size of input list and
     *         size of each output list are equal. If there are any errors then the size of output
     *         list is less than size of the input list and the Service data will contain the index
     *         of the element in input list for which the error occurred along with the error details.
     *         After getting response from the operation, loop through the input list and check
     *         if there is any error against the index of that list element. If there is no error
     *         then take the next set elements in the Response lists as output for that input list
     *         element.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74009&nbsp;&nbsp;&nbsp;&nbsp;Invalid system variable in pattern <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74010&nbsp;&nbsp;&nbsp;&nbsp;Missing character after escape in pattern
     *         <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74011&nbsp;&nbsp;&nbsp;&nbsp;Missing delimiter character in pattern
     *         <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74012&nbsp;&nbsp;&nbsp;&nbsp;Rule/LOV variable <code>vInfoForNextId[index].pattern</code>
     *         is missing.
     *         </li>
     *         <li type="disc">74013&nbsp;&nbsp;&nbsp;&nbsp;LOV variable <code>vInfoForNextId[index].pattern</code>
     *         is not a string.
     *         </li>
     *         <li type="disc">74014&nbsp;&nbsp;&nbsp;&nbsp;Invalid variable type <code>X</code>
     *         in pattern <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74015&nbsp;&nbsp;&nbsp;&nbsp;Invalid character in pattern <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74016&nbsp;&nbsp;&nbsp;&nbsp;The counter value has reached its maximum
     *         for the given pattern. Please contact the system administrator to reset the counters.
     *         </li>
     *         <li type="disc">74017&nbsp;&nbsp;&nbsp;&nbsp;No counters Found.
     *         </li>
     *         <li type="disc">74018&nbsp;&nbsp;&nbsp;&nbsp;Autogen not set to create counters.
     *         </li>
     *         <li type="disc">74022&nbsp;&nbsp;&nbsp;&nbsp;The rule has nested too many times,
     *         pattern is <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74029&nbsp;&nbsp;&nbsp;&nbsp;The auto-assignment cannot generate
     *         an ID. A Naming Rule without a counter has been configured on the property <code>vInfoForNextId[index].propName</code>.
     *         Please contact your system administrator.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         Other than this, errors thrown from any of the following Teamcenter system calls
     *         may be caught and added to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">TCTYPE_find_type()
     *         </li>
     *         <li type="disc">TCTYPE_is_type_of ()
     *         </li>
     *         <li type="disc">USER_new_item_id()
     *         </li>
     *         <li type="disc">USER_new_dataset_id()
     *         </li>
     *         <li type="disc">USER_new_revision_id()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetNextIdsResponse getNextIds ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::InfoForNextId >& vInfoForNextId ) = 0;

    /**
     * This operation gives the list of Patterns which has counters along with preferred
     * patterns and conditions for the Naming Rule attached to the property of an object
     * Type. The Type name and the Property name are passed in the input structure. The
     * input for this operation contains a list of this structure. The return structure
     * contains the vector of patterns with counters, preferredPattern and condition, along
     * with the service data member.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used in create, revise or save-as dialogs to receive list of applicable
     * patterns for item and revision ids. The list of patterns returned is displayed in
     * these dialogs for user selection. After user selects a pattern and clicks "Assign"
     * button, an id is generated matching the pattern selected and populated in the corresponding
     * field's box.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param vAttachInfo
     *        Struct that contains Type Name and Property Name
     *
     * @return
     *         It returns patterns which has counters along with preferred patterns and conditions.
     *         Failure for any structure in the input vector is indexed correspondingly along with
     *         error details and is stored in the service data member. If there are no failures
     *         then input vector size and size of each output vector is equal. If there are any
     *         errors then the size of output vector is less than the input vector and the Service
     *         data will contain the index of input vector for which the error occurred along with
     *         the error details. After getting response from the operation loop through the input
     *         vector and check if there is any error against that vector element's index. If there
     *         is no error then take the next set elements in the Response vectors as output for
     *         that input vector element.
     *         <br>
     *         <br>
     *         This operation throws no errors internally. However, errors thrown from any of the
     *         following Teamcenter system calls may be caught and added to the ServiceData's error
     *         stack:
     *         <br>
     *         <ul>
     *         <li type="disc">AOM_ask_value_tag ()
     *         </li>
     *         <li type="disc">CE_ask_condition ()
     *         </li>
     *         <li type="disc">AOM_ask_value_tags ()
     *         </li>
     *         <li type="disc">PREF_ask_value_count ()
     *         </li>
     *         <li type="disc">PREF_ask_char_values ()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetNRPatternsWithCountersResponse getNRPatternsWithCounters ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NRAttachInfo >& vAttachInfo ) = 0;

    /**
     * This operation gets all the possible initial, secondary and supplemental revision
     * next Ids for an <b>ItemRevision</b> along with the available formats and the set
     * of excluded letters for revision. The Revision Type Name and the current revision
     * are passed in the input typeAndItemRevInfos structure. The input for this operation
     * contains a list of this structure. The return structure contains list of Initial
     * Revision details, Secondary Revision details, Supplemental Revision details and exclude
     * Skip letters along with the service data member.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to get the next available options for revision id for a new
     * or existing object. User can select one of the values returned by this operation
     * and use as revision id input value for create, revise or save-as operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param typeAndItemRevInfos
     *        List of <code>TypeAndItemRevInfo</code> structs which contains <b>Item</b> and <b>ItemRevision</b>
     *        type name and the revision object.
     *
     * @return
     *         The return structure, <code>GetRevNRAttachResponse</code>, contains the list of Initial
     *         Revision details, Secondary Revision details, Supplemental Revision details and exclude
     *         Skip letters along with the service data member. Failure for any structure in the
     *         input list is indexed correspondingly along with error details and is stored in the
     *         service data member. If there are no failures then input list size and size of each
     *         output list is equal. If there are any errors then the size of output lists is less
     *         than size of input list and the Service data will contain the index of element in
     *         the input list for which the error occurred along with the error details. After getting
     *         response from the operation, loop through the input list and check if there is any
     *         error against that list element's index. If there is no error then take the next
     *         set elements in the Response lists as output for that input list element.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74027&nbsp;&nbsp;&nbsp;&nbsp;The initial, secondary and supplemental
     *         revisions IDs are exhausted. You may contact your System Administrator for assistance.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         Other than this, errors thrown from any of the following Teamcenter system calls
     *         may be caught and added to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">TCTYPE_find_type()
     *         </li>
     *         <li type="disc">TCTYPE_is_type_of ()
     *         </li>
     *         <li type="disc">TypeConstantAttachImpl::findTypeByTypeConstantAttachment()
     *         </li>
     *         <li type="disc">LOV_find()
     *         </li>
     *         <li type="disc">LOV_ask_values_char()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetRevNRAttachResponse getRevNRAttachDetails ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::TypeAndItemRevInfo >& typeAndItemRevInfos ) = 0;

    /**
     * Creates the specified relation between the input objects (primary and secondary objects)
     * for each input structure. If the <code>sync</code> flag is specified, then if any
     * Generic Relationship Management (GRM) relations exist between the primary and secondary
     * objects and they are not specified in the input they will be deleted. If <code>sync</code>
     * flag is provided, the relations member of <code>CreateOrUpdateRelationsInfo</code>
     * is ignored.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: Create a relation based on the GRM rule definition.
     * <br>
     * <br>
     * One can create a relation specified by name of the relation in the input structure
     * between the primary and secondary object, when there exists a GRM rule between the
     * primary and secondary object with the given relation type.
     * <br>
     * <br>
     * Use Case 2: Update a relation based on the GRM rule definition.
     * <br>
     * <br>
     * One can update a relation specified by name of the relation in the input structure
     * between the primary and secondary object, when there exists a GRM rule between the
     * primary and secondary object with the given relation type.
     * <br>
     * <br>
     * Use Case 3: Remove a relation based on the GRM rule definition.
     * <br>
     * <br>
     * One can remove a relation by setting the sync to true and do not provide any relation
     * between the primary and secondary object in the input structure. When there exists
     * a GRM rule between the primary and secondary object with the given relation type,
     * and the sync flag is set to true, then if any GRM relations exist between the primary
     * and secondary objects and they are not specified in the input they will be deleted.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param infos
     *        A list of <code>CreateOrUpdateRelationsInfo</code> structures containing details
     *        of relationships to be created between primary and secondary objects with the given
     *        relation.
     *
     * @param sync
     *        If true then GRM relations in db and the number of secondary objects specified in
     *        the <code>input</code> will be synchronized. Note that in this case the <code>secondaryData</code>
     *        member of the <code>input</code> structure is used and not the <code>relations</code>
     *        member.
     *
     * @return
     *         A list of all the relation objects matching the primary and secondary passed in.
     *         Any failure will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateRelationsResponse createOrUpdateRelations ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateRelationsInfo >& infos,
        bool sync ) = 0;

    /**
     * Creates a list of <b>Connection</b> objects and any associated data (<b>ConnectionRevision</b>,
     * <b>ConnectionMaster</b> Form and <b>ConnectionRevision</b> Master Form) based on
     * the input properties structure. It also creates the specified relation type between
     * newly created <b>Connection</b> object and input container object. If container and
     * relation type are not supplied, none of the <b>Connection</b> objects will be related
     * to a container. If any destination to paste the newly created objects is desired
     * then it must be supplied as input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports creation of single or multiple <b>Connection</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param properties
     *        A <b>Connection</b> object is created for each ConnectionProperties in the list.
     *        The data on the ConnectionProperties is used to create initial values on the <b>Connection</b>
     *        and related objects
     *
     * @param container
     *        Object to which all the <b>Connection</b> objects created will be related to via
     *        the input relationType (Folder instance and contents relationType). If not specified
     *        the <b>Connection</b> will be created, but without a relation to a container object.
     *
     * @param relationType
     *        The name of the relation used to attach the created <b>Connection</b> objects to
     *        input container. This argument is used only when the container argument is present,
     *        optional.
     *
     * @return
     *         A <i>CreateConnectionsResponse</i> structure which contains a list of <i>ConnectionOutput</i>
     *         structures. The <i>ConnectionOutput</i> structure contains the created <b>Connection</b>
     *         and <b>ConnectionRevision</b> object. The newly created objects and the updated container
     *         object are added to the standard <i>ServiceData</i> lists of created and updated
     *         object respectively.  Any failure will be returned with client id mapped to the error
     *         message in the ServiceData list of partial errors. If the user does not have write
     *         permission to the container object, 000084 is returned as a Partial Error, the container
     *         object will be attached to the Partial Error. In this case, the <b>Connection</b>
     *         object will still be created, but will not be placed in any container.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateConnectionsResponse createConnections ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ConnectionProperties >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * Create and/or update <b>GeneralDesignElementLink</b>(<i>GDELink</i>) objects based
     * on the input properties structure. If the given <i>GDELink</i> object exists in Teamcenter
     * then the operation will be treated as an update based on the input properties structure
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports creation or updation of <i>GDELink</i> objects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param gdeLinkInfos
     *        An input of vector of structures containing values necessary to create or update
     *        the Teamcenter Model Data representing the <i>GDELink</i>. If a reference to an existing
     *        <i>GDELink</i> is supplied then an update is assumed, otherwise a new <i>GDELink</i>
     *        is created. On update the <i>GDELink</i> name and description may be changed but
     *        not the type. After the <i>GDELink</i> is created, and if for an update the property
     *        values are supplied, the <i>GDELink</i> created will be updated with the properties.
     *
     * @return
     *         A map of the clientID of the input structure and the created or updated <i>GDELink</i>
     *         objects. All Object IDs that were successfully created or updated are added to <i>ServiceData</i>.
     *         Any failure will be returned in the <i>ServiceData</i> with the error message mapped
     *         to input client id
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateGDELinksResponse createOrUpdateGDELinks ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::GDELinkInfo >& gdeLinkInfos ) = 0;

    /**
     * Allows the user to create a new <b>GeneralDesignElement</b> (<i>GDE</i>) or its subtype
     * and set its properties. In the case of existing <i>GDE</i>, user can update the properties.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used when user wants to create a <i>GDE</i> in a product structure
     * or wants to update the properties of an existing <i>GDE</i>. User has to pass unique
     * client Id, name and type when a new element has to be created. Whenever properties
     * of an existing <i>GDE</i> have to be updated the <i>itemElement</i> business object
     * and <i>itemElemAttributes</i> should be passed
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param properties
     *        This is a vector of <i>ItemElementProperties</i>. While creating a new element it
     *        shall contain a unique clientId, name and type. In the case of an existing <i>GDE</i>,
     *        this structure must contain <i>itemElemAttributes</i> to be modified and the <i>itemElement</i>
     *        whose properties have to be modified.
     *
     * @return
     *         A <i>CreateOrUpdateItemElementsResponse</i> structure contains clientId and <i>itemElement</i>
     *         business object newly created <b>GeneralDesignElement</b> object. The <i>serviceData</i>
     *         contains created/updated <i>GDE</i> and partial errors, if any, occurred during the
     *         operation.
     *         <br>
     *         <b>Partial Errors</b>
     *         <br>
     *         <i>Error Id. 214322  </i>Unable to create ItemElement: the input ItemElement name
     *         is null
     *         <br>
     *         <i>Error Id. 214323  </i>Error in creating %1$ ItemElement.
     *         <br>
     *         <i>Error Id. 214324 </i> Error in updating ItemElement properties.
     *         <br>
     *         <i>Error Id. 214325  </i>Invalid input for create or update of ItemElements
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateItemElementsResponse createOrUpdateItemElements ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ItemElementProperties >& properties ) = 0;

    /**
     * Generic operation for creation of Business Objects. This will also create any secondary(compounded)
     * objects that need to be created, assuming the CreateInput for the secondary object
     * is represented in the recursive CreateInput object e.g. <b>Item</b> is Primary Object
     * that also creates <b>Item Master</b> and <b>ItemRevision</b>. <b>ItemRevision</b>
     * in turn creates <b>ItemRevision Master</b>. The input for all these levels is passed
     * in through the recursive CreateInput object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation to create an object is invoked after obtaining user input on the fields
     * of the create dialog. This call is typically preceded by a call to Teamcenter::Soa::Core::_2008_06::PropDescriptor::getCreateDesc
     * or to the SOA Client Metamodel layer to retrieve Create Descriptor for a Business
     * Object.
     * <br>
     * <br>
     * For example, to create an Item, client will get the Create Descriptor associated
     * with the Item from the client metamodel (The associated descriptor type can be found
     * by looking at the constant value for the CreateInput constant that is attached to
     * Item). Alternatively, for clients that do not use the SOA client metamodel, the Descriptor
     * for Item can be obtained by invoking getCreateDesc operation. The descriptor information
     * can then be used to populate the Create dialog for the Business Object. Once the
     * Create dialog is populated the createObjects operation can be called to create the
     * object.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getCreateDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param input
     *        This is a vector of CreateIn objects each one of which represents the CreateInput
     *        information used to create an object. Each CreateIn object has a client id and a
     *        CreateInput object which contains the information to create the object. The client
     *        id can be used to map to any partial errors in the ServiceData information returned
     *        in the output.
     *
     * @return
     *         A list of the business objects that were created. Any failure will be returned with
     *         client id mapped to error message in the ServiceData list of partial errors. The
     *         client id in the ServiceData can be mapped to the client id in the input to the operation
     *         to detect which object creation failed. For example, the input to createObjects (which
     *         is a vector of CreateIn) may be {{ "clientId1", createInput1},{"clientId2", createInput2}}.
     *         If the ServiceData contains clientId2 in the PartialList of errors, it is known that
     *         creation of the second object failed.
     *         <br>
     *         <br>
     *         One of the possible errors returned in ServiceData is:
     *         <br>
     *         214200 - Unable to create Business Object
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateResponse createObjects ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateIn >& input ) = 0;

    /**
     * This operation creates the <b>Participant</b> objects and adds them to the input
     * Item Revision. If a <b>Participant</b> object with specified attributes already exists,
     * it is added to the Item Revision.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * For Change Management use cases, user may need to add different participants to the
     * change objects like analyst, change specialist etc. The creator of the change object
     * will assign the analyst for the change where this operation can be used.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param addParticipantInfo
     *        Contains a list of <code>ParticipantInfo</code> structures with information about
     *        participants to be added and an Item Revision to add the participants to.
     *
     * @return
     *         The operation returns a list of participants structure and service data. Each element
     *         in the list contains an <b>ItemRevision</b> and a list of <b>Participant</b> objects
     *         that were added to it.
     *         <br>
     *         If the service fails to add the participant, it returns "SOACORE_failed_to_add_participants"
     *         error code.
     *         <br>
     *         If the service fails to create the participant, it returns "SOACORE_failed_to_create_participant"
     *         error code.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::AddParticipantOutput addParticipants ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::AddParticipantInfo >& addParticipantInfo ) = 0;

    /**
     * This operation allows the user to remove <b>Participant</b> objects associated with
     * specified Item Revision. If a participant being removed is no longer associated with
     * any other objects, it gets deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used to remove the assigned <b>Participant</b> objects like
     * Analyst, Proposed Reviewers etc. from the change objects. Change creator can use
     * <code>addParticipants</code> service operation to assign an analyst or use this operation
     * to remove an assigned analyst.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param participants
     *        List of participants structures each containing a list of <b>Participant</b> objects
     *        to be removed and an Item Revision to remove the <b>Participant</b> objects from.
     *
     * @return
     *         The operation returns the service data. The updated Item Revision is added to the
     *         Updated list in the service data.
     *         <br>
     *         If the service fails to remove the participant, it returns "<code>SOACORE_failed_to_remove_participant</code>"
     *         error code.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeParticipants ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::Participants >& participants ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

