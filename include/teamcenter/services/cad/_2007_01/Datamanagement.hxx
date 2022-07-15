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

#ifndef TEAMCENTER_SERVICES_CAD__2007_01_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2007_01_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/CadAttrMappingDefinition.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/ImanRelation.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/ListOfValues.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            namespace _2007_01
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct AttributeInfo;
    struct PropDescriptor;
    struct AttrMappingInfo;
    struct CommitDatasetFileInfo;
    struct CreateOrUpdatePartsOutput;
    struct CreateOrUpdatePartsResponse;
    struct CreateOrUpdateRelationsInfo;
    struct CreateOrUpdateRelationsOutput;
    struct CreateOrUpdateRelationsPref;
    struct CreateOrUpdateRelationsResponse;
    struct DatasetFileInfo;
    struct DatasetFileTicketInfo;
    struct DatasetInfo;
    struct DatasetOutput;
    struct ExpandFolderForCADPref;
    struct ExpandFoldersForCADItemOutput;
    struct ExpandFoldersForCADItemRevOutput;
    struct ExpandFoldersForCADOutput;
    struct ExpandFoldersForCADResponse;
    struct ExpandGRMRelationsData;
    struct ExpandGRMRelationsOutput;
    struct ExpandGRMRelationsPref;
    struct ExpandGRMRelationsResponse;
    struct ExpandPrimaryObjectsData;
    struct ExpandPrimaryObjectsOutput;
    struct ExpandPrimaryObjectsPref;
    struct ExpandPrimaryObjectsResponse;
    struct ExtraObjectInfo;
    struct ExtraObjectOutput;
    struct GenerateAlternateIdsProperties;
    struct GenerateAlternateIdsResponse;
    struct GetAllAttrMappingsResponse;
    struct GetAttrMappingsForDatasetTypeCriteria;
    struct GetAttrMappingsForDatasetTypeOutput;
    struct GetAttrMappingsForDatasetTypeResponse;
    struct GetAvailableTypesResponse;
    struct ItemInfo;
    struct ItemRevInfo;
    struct MappedDatasetAttrProperty;
    struct NamedReferenceObjectInfo;
    struct PartInfo;
    struct RelationAndTypesFilter2;
    struct ResolveAttrMappingsForDatasetInfo;
    struct ResolveAttrMappingsForDatasetOutput;
    struct ResolveAttrMappingsForDatasetResponse;

    /**
     * Map of string class names to vector of type string values (string, vector).
     */
    typedef std::map< std::string, std::vector< std::string > > ClassToTypesMap;

    /**
     * Map of integer index of the input to vector of string alternate id values (string,
     * vector).
     */
    typedef std::map< int, std::vector< std::string > > IndexToAltId;

    /**
     * This structure allows the caller to define or update named attributes. The name member
     * represents the property name for the related object and the value is the value to
     * set.
     */
    struct AttributeInfo
    {
        /**
         * Text for Attribute Name
         */
        std::string name;
        /**
         * Text for Attribute Value
         */
        std::string value;
    };

    /**
     * The PropDescriptor struct describes information about the Teamcenter property
     */
    struct PropDescriptor
    {
        /**
         * Name of the property
         */
        std::string propName;
        /**
         * Display name of the property
         */
        std::string displayName;
        /**
         * Default value for the property
         */
        std::string defaultValue;
        /**
         * Value type for the property in integer form: PROP_untyped (0) No Value PROP_char
         * (1) Value is a single character PROP_date (2) Value is a date PROP_double (3) Value
         * is a double PROP_float (4) Value is a float PROP_int (5) Value is an integer PROP_logical
         * (6) Value is a logical PROP_short (7) Value is a short PROP_string (8) Value is a
         * character string PROP_typed_reference (9) Value is a typed reference PROP_untyped_reference
         * (10) Value is an untyped reference PROP_external_reference (11) Value is an external
         * reference PROP_note (12) Value is a note PROP_typed_relation (13) Value is a typed
         * relation PROP_untyped_relation (14) Value is an untyped relation
         */
        int propValueType;
        /**
         * Type for the property in integer form: PROP_unknown (0) Property type is Unknown
         * PROP_attribute (1)  Based on a POM Attribute (int, string, ...) PROP_reference (2)
         * Based on a POM Reference PROP_relation (3) Based on an ImanRelation PROP_compound
         * (4) Based on a property from another Type PROP_runtime (5) Based on a computed value
         */
        int propType;
        /**
         * isDisplayable
         */
        bool isDisplayable;
        /**
         * Specifies whether the property is an array or single value
         */
        bool isArray;
        /**
         * ListOfValues object attached to the property (if any)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
        /**
         * Specifies whether the property is required
         */
        bool isRequired;
        /**
         * Specifies whether the property is enabled
         */
        bool isEnabled;
        /**
         * Specifies whether the property is modifiable
         */
        bool isModifiable;
        /**
         * attachedSpecifier
         */
        int attachedSpecifier;
        /**
         * maxLength
         */
        int maxLength;
        /**
         * interdependentProps
         */
        std::vector< std::string > interdependentProps;
    };

    /**
     * Contains CadAttrMappingDefinition object reference and the PropDescriptor structure
     * used in the response of get attribute mapping operations.
     */
    struct AttrMappingInfo
    {
        /**
         * CadAttrMappingDefinition object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CadAttrMappingDefinition>  cadAttrMappingDefinition;
        /**
         * PropDescriptor structure containing property information for mapping definition property.
         */
        Teamcenter::Services::Cad::_2007_01::Datamanagement::PropDescriptor propDesc;
    };

    /**
     * Holds the basic info for a file to be uploaded to a dataset.
     */
    struct CommitDatasetFileInfo
    {
        /**
         * Dateset object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Flag to create new version ( TRUE ) or not ( FALSE ).
         */
        bool createNewVersion;
        /**
         * A list of DatasetFileTicketInfos.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::DatasetFileTicketInfo > datasetFileTicketInfos;
    };

    /**
     * Intermediate level output structure for createOrUpdateParts operation.
     */
    struct CreateOrUpdatePartsOutput
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Item object reference of the created/updated item
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * ItemRevision object reference of the created/updated item revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * List of DatasetOutputs
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::DatasetOutput > datasetOutput;
        /**
         * List of ExtraObjectOutputs for the item extra objects
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectOutput > extraItemObjs;
        /**
         * List of ExtraObjectOutputs for the item revision extra objects
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectOutput > extraItemRevObjs;
    };

    /**
     * Holds the response for createOrUpdateParts
     */
    struct CreateOrUpdatePartsResponse
    {
        /**
         * List of CreateOrUpdatePartsOutputs.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains input information for <code>createdOrUpdateRelations</code> operation.
     */
    struct CreateOrUpdateRelationsInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Realtion of interest, required for create or update
         */
        std::string relationType;
        /**
         * object reference of primary object of interest, required for create or update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * object reference of secondary object of interest, required for create or update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondaryObject;
        /**
         * <b>ImanRelation</b> object reference of existing relation, used for update if provided
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  relation;
        /**
         * object reference to an object that can be attached to the relation (optional)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  userData;
    };

    /**
     * Contains the output response structure for <code>createdOrUpdateRelations</code>
     * operation.
     */
    struct CreateOrUpdateRelationsOutput
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * <b>ImanRelation</b> object reference of relation created or updated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  relation;
    };

    /**
     * Contains a list of RelationAndTypesFilter structures for other side object filtering.
     */
    struct CreateOrUpdateRelationsPref
    {
        /**
         * A list of <code>RelationAndTypesFilter2</code>
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::RelationAndTypesFilter2 > info;
    };

    /**
     * Contains the response for <code>createOrUpdateRelations</code>
     */
    struct CreateOrUpdateRelationsResponse
    {
        /**
         * A list of <code>CreateOrUpdateRelationsOutput</code>
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsOutput > output;
        /**
         * The SOA framework object containing objects that were created or updated by the service
         * and error information. Errors are identified by the <code>clientID</code> which is
         * supplied in the input data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the basic info for a file to be uploaded to a dataset.
     */
    struct DatasetFileInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Name of file to be uploaded.  Filename only, should not contain path to filename.
         */
        std::string fileName;
        /**
         * Named Reference relation to file.
         */
        std::string namedReferencedName;
        /**
         * Flag to indicate if file is text ( TRUE ) or binary (FALSE ).
         */
        bool isText;
        /**
         * Flag to indicate if file can be overwritten ( TRUE ) or not ( FALSE ).
         */
        bool allowReplace;
    };

    /**
     * Holds the basic info for a file to be uploaded to a dataset.
     */
    struct DatasetFileTicketInfo
    {
        /**
         * Member of type DatasetFileInfo.
         */
        Teamcenter::Services::Cad::_2007_01::Datamanagement::DatasetFileInfo datasetFileInfo;
        /**
         * ID of ticket.
         */
        std::string ticket;
    };

    /**
     * Contains all of the data necessary to construct the dataset object. The basic attributes
     * that are required are passed as named elements in the structure. All other attributes
     * are passed as name/value pairs in the AttributeInfo structure. The extraObject field
     * allows for the creation of an object(s) that will be related to this newly created
     * Dataset.
     */
    struct DatasetInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Dataset object reference for update, null for creation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Name attribute value
         */
        std::string name;
        /**
         * Description attribute value
         */
        std::string description;
        /**
         * Type attribute value
         */
        std::string type;
        /**
         * ID attribute value
         */
        std::string id;
        /**
         * Revision attribute value
         */
        std::string datasetRev;
        /**
         * Required input, may not be null, not defaulted
         */
        std::string itemRevRelationName;
        /**
         * Flag to create new version ( TRUE ) or not (FALSE )
         */
        bool createNewVersion;
        /**
         * Preference name which holds the list of named references to delete from one Dataset
         * version to the next.
         */
        std::string namedReferencePreference;
        /**
         * List of AttributeInfos for attributes
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttributeInfo > attrList;
        /**
         * List of AttributeInfos for mapped attributes. Mapped atributes are attributes that
         * are applied to other objects. Refere to the ITK manual for a definition of attribute
         * mapping.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttributeInfo > mappingAttributes;
        /**
         * List of ExtraObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectInfo > extraObject;
        /**
         * List of DatasetFileInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::DatasetFileInfo > datasetFileInfos;
        /**
         * List of NamedReferenceObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::NamedReferenceObjectInfo > namedReferenceObjectInfos;
    };

    /**
     * Structure contains created/updated dataset objects.
     */
    struct DatasetOutput
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Dataset object reference of the created/updated dataset
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * List of CommitDatasetFileInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::CommitDatasetFileInfo > commitInfo;
        /**
         * List of ExtraObjectOutputs for the extra objects
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectOutput > extraObjs;
        /**
         * List of ExtraObjectOutputs for the named references
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectOutput > namedRefObjs;
    };

    /**
     * Contains list of RelationAndTypesFilter, number of latest revisions for further filtering
     * and a flag to check whether item revision needs to be expanded.
     */
    struct ExpandFolderForCADPref
    {
        /**
         * Flag to specify if item revisions are to be expanded ( TRUE ) or not ( FALSE ) if
         * found as other side objects.
         */
        bool expItemRev;
        /**
         * The number of latest revisions under an Item that should be considered for further
         * filtering
         */
        int latestNRevs;
        /**
         * A list of RelationAndTypesFilter2
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::RelationAndTypesFilter2 > info;
    };

    /**
     * Contains the item expanded and the list of item revisions for the item.
     */
    struct ExpandFoldersForCADItemOutput
    {
        /**
         * An item that is in the input folder.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  outputItem;
        /**
         * A list of <code>ExpandFolderForCADItemRevOutput</code> which contains information
         * about any item revisions that belong to item as specified by <code>latestNRevs</code>.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADItemRevOutput > itemRevsOutput;
    };

    /**
     * Contains the item revision expanded and the results of expanding the item revision.
     */
    struct ExpandFoldersForCADItemRevOutput
    {
        /**
         * An item revision that is in the input folder.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  outputItemRevs;
        /**
         * A list of datasets related to the item revision as specified by the input filter.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > outputDatasets;
    };

    /**
     * Contains the output data for ExpandFoldersForCAD operation.
     */
    struct ExpandFoldersForCADOutput
    {
        /**
         * Folder object reference of the folder of interest
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  inputFolder;
        /**
         * A list of Folder object references in the input folder
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  > fstlvlFolders;
        /**
         * A list of ExpandFoldersForCADItemOutput for the item
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADItemOutput > itemsOutput;
        /**
         * A list of ExpandFoldersForCADItemRevOutput for the item revision
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADItemRevOutput > itemRevsOutput;
    };

    /**
     * Contains the response for ExpandFoldersForCAD operation.
     */
    struct ExpandFoldersForCADResponse
    {
        /**
         * A list of ExpandFoldersForCADOutput which has information about the input folder
         * and folders, items and itemRevs output found under this folder
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADOutput > output;
        /**
         * SOA framework object containing objects that were created, deleted, or updated by
         * the Service, plain objects, and service errors/failure information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains a list of related objects and the relation name used to relate to the input
     * object.
     */
    struct ExpandGRMRelationsData
    {
        /**
         * A list of object references of objects the object of interest is related to.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > otherSideObjects;
        /**
         * The name of the relation used to relate the object of interest to the other otherSideObjects
         */
        std::string relationName;
    };

    /**
     * Contains the output data for ExpandGRMRelations operation.
     */
    struct ExpandGRMRelationsOutput
    {
        /**
         * The object reference of the object of interest
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputObject;
        /**
         * List of ExpandGRMRelationsData
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandGRMRelationsData > otherSideObjData;
    };

    /**
     * Contains a list of RelationAndTypesFilter and a flag to check whether item revision
     * needs to be expanded.
     */
    struct ExpandGRMRelationsPref
    {
        /**
         * Flag to specify if item revisions are to be expanded ( TRUE ) or not ( FALSE ) if
         * found as other side objects.
         */
        bool expItemRev;
        /**
         * List of RelationAndTypesFilter2
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::RelationAndTypesFilter2 > info;
    };

    /**
     * Top level response structure for ExpandGRMRelations operations.
     */
    struct ExpandGRMRelationsResponse
    {
        /**
         * A list of ExpandGRMRelationsOutput which has information about the input object and
         * it's filtered related object list
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandGRMRelationsOutput > output;
        /**
         * SOA framework object containing objects that were created, deleted, or updated by
         * the Service, plain objects, and service errors/failure information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains a list of related objects and the relation name or property used to relate
     * to the input object.
     */
    struct ExpandPrimaryObjectsData
    {
        /**
         * A list of object references of objects the object of interest is related to.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > otherSideObjects;
        /**
         * The name of the relation used to relate the object of interest to the other otherSideObjects
         */
        std::string relationName;
    };

    /**
     * Contains the output data for ExpandPrimaryObjects operation.
     */
    struct ExpandPrimaryObjectsOutput
    {
        /**
         * The object reference of the object of interest
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputObject;
        /**
         * List of ExpandPrimaryObjectsData
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandPrimaryObjectsData > otherSideObjData;
    };

    /**
     * Contains list of RelationAndTypesFilter and a flag to check whether item revision
     * needs to be expanded .
     */
    struct ExpandPrimaryObjectsPref
    {
        /**
         * Flag to specify if item revisions are to be expanded ( TRUE ) or not ( FALSE ) if
         * found as other side objects.
         */
        bool expItemRev;
        /**
         * List of RelationAndTypesFilter2
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::RelationAndTypesFilter2 > info;
    };

    /**
     * Contains the response structure for ExpandPrimaryObjects operation.
     */
    struct ExpandPrimaryObjectsResponse
    {
        /**
         * A list of ExpandPrimaryObjectsOutput
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandPrimaryObjectsOutput > output;
        /**
         * SOA framework object containing objects that were found by the service and service
         * errors/failure information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Form objects that can be created or updated and related to an item, item revision
     * or dataset.
     */
    struct ExtraObjectInfo
    {
        /**
         * Object reference for existing object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Name of the relation type to the parent object
         */
        std::string relationTypeName;
        /**
         * Object Type name
         */
        std::string typeName;
        /**
         * List of AttributeInfos.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttributeInfo > attrNameValuePairs;
    };

    /**
     * <b>Form</b> objects that can be created or updated and related to an item, item revision
     * or dataset.
     */
    struct ExtraObjectOutput
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Object reference of the created/updated object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };

    /**
     * Holds the input structure of <code>GenerateAlternateIdsProperties</code>
     */
    struct GenerateAlternateIdsProperties
    {
        /**
         * Object reference of the id context used to generate the alternate id of that context
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  idContext;
        /**
         * Pattern type used to generate the alternate id of that pattern
         */
        std::string pattern;
        /**
         * Type of the alternate id to generate
         */
        std::string altIdType;
        /**
         * Object reference of the parent alternate id
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentAltId;
        /**
         * Number of the alternate id to be generated.
         */
        int count;
    };

    /**
     * Holds the response for <code>generateAlternateIds</code>
     */
    struct GenerateAlternateIdsResponse
    {
        /**
         * Key is the index of the input, data is a list of alternate IDs generated.
         */
        IndexToAltId inputIndexToAltId;
        /**
         * Service data contains any partial errors and exceptions. No objects are created,
         * deleted, modified or returned by this service.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains the response for getAllAttrMappings operation.
     */
    struct GetAllAttrMappingsResponse
    {
        /**
         * A list of AttrMappingInfo
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttrMappingInfo > attrMappingInfos;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. CadAttrMappingDefinition objects
         * are returned as plain objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input criteria for the data returned from the <code>getAttrMappingsForDatasetType</code>
     * operation.
     */
    struct GetAttrMappingsForDatasetTypeCriteria
    {
        /**
         * The type name of a dataset.  This input is required.
         */
        std::string datasetTypeName;
        /**
         * The type name of an item.  This input is optional.
         */
        std::string itemTypeName;
        /**
         * The input flag indicating that the mappings to be returned are for a specific dataset
         * type and item type combination when the value is true.
         */
        bool exact;
    };

    /**
     * Contains the output data for the <code>getAttrMappingsForDatasetType</code> operation.
     */
    struct GetAttrMappingsForDatasetTypeOutput
    {
        /**
         * The dataset and item type criteria used to find the attribute mapping definitions.
         */
        Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAttrMappingsForDatasetTypeCriteria criteria;
        /**
         * The list of attribute mapping information that matches the <code>criteria</code>.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttrMappingInfo > attrMappingInfos;
    };

    /**
     * The response from the <code>getAttrMappingsForDatasetType</code> operation.
     */
    struct GetAttrMappingsForDatasetTypeResponse
    {
        /**
         * A list of input dataset and item type criteria and the found attribute mapping definitions.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAttrMappingsForDatasetTypeOutput > output;
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData</code>
         * plain objects with <code>CadAttrMappingDefinition</code> objects and property descriptor
         * LOV objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the response for <code>getAvailableTypes</code>, which the map of input objects
     * (class names) and for each input object, the object references of found Types (NULL,
     * if none found), along with the <code>ServiceData</code>.
     */
    struct GetAvailableTypesResponse
    {
        /**
         * Map where the key is the class type and the value is a list of strings representing
         * the types available for the class.
         */
        ClassToTypesMap inputClassToTypes;
        /**
         * Contains objects that are returned by the service, and error information. The actual
         * type objects are returned as <code>PlainObjects</code>. This service does not define
         * any of its own errors, but will return any errors from the subsystem in the list
         * of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The ItemInfo struct represents all of the data necessary to construct the item object.
     * The basic attributes that are required are passed as named elements in the struct.
     * All other attributes are passed as name/value pairs in the AttributeInfo struct.
     * The extraObject field allows for the creation of an object(s) that will be related
     * to this newly created Item.
     */
    struct ItemInfo
    {
        /**
         * Item object reference for update, can be null for creation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * ID for create, generated if null
         */
        std::string itemId;
        /**
         * Type, default is Item if null
         */
        std::string itemType;
        /**
         * Name, defaulted to id if null
         */
        std::string name;
        /**
         * Description, can be null
         */
        std::string description;
        /**
         * List of AttributeInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttributeInfo > attrList;
        /**
         * List of ExtraObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectInfo > extraObject;
        /**
         * Folder to attach Item to, if null then default used
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * The ItemRevInfo structure represents all of the data necessary to construct the item
     * revision object. The basic attributes that are required are passed as named elements
     * in the struct. All other attributes are passed as name/value pairs in the AttributeInfo
     * struct. The extraObject field allows for the creation of an object(s) that will be
     * related to this newly created Item Revision.
     */
    struct ItemRevInfo
    {
        /**
         * ItemRevision object reference, null for creation, otherwise update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * ID, if null then generated
         */
        std::string revId;
        /**
         * List of AttributeInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttributeInfo > attrList;
        /**
         * List ofr ExtraObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectInfo > extraObject;
    };

    /**
     * Contains the found resolved object and property name mapped to specific input values.
     */
    struct MappedDatasetAttrProperty
    {
        /**
         * The CadAttrMappingDefinition object title. This is generally the client application
         * attribute display name.
         */
        std::string attrTitle;
        /**
         * The Teamcenter defined type name of a dataset.
         */
        std::string datasetTypeName;
        /**
         * The Teamcenter defined type name of an item
         */
        std::string itemTypeName;
        /**
         * Object reference of object holding mapped attribute value
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  resolvedObject;
        /**
         * The property name of the mapped object holding the attribute value of interest resulting
         * from evaluation of a dataset CAD attribute mapping definition.
         */
        std::string resolvedPropertyName;
    };

    /**
     * Contains information regarding named refernce type value, Object reference, Object
     * type name and list of Attribute infos.
     */
    struct NamedReferenceObjectInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Object reference of the object for update, null for create
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The Named Reference from the dataset to this object, required. NamedReference values
         * are defined for each Dataset type. The customer can add more values as needed. To
         * get a current list of valid Named Reference values the programmer can either use
         * BMIDE or can call the SOA Core service getDatasetTypeIno.
         */
        std::string namedReferenceName;
        /**
         * Type of the object to be created. Required for object creation only.
         */
        std::string typeName;
        /**
         * List of AttributeInfos.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::AttributeInfo > attrNameValuePairs;
    };

    /**
     * The PartInfo struct is the main input to the createOrUpdateParts service. This struct
     * refers to the Item, ItemRevision, and one or more Dataset structures used to create
     * those objects.
     */
    struct PartInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Member of type ItemInfo
         */
        Teamcenter::Services::Cad::_2007_01::Datamanagement::ItemInfo itemInput;
        /**
         * Member of type ItemRevInfo
         */
        Teamcenter::Services::Cad::_2007_01::Datamanagement::ItemRevInfo itemRevInput;
        /**
         * List of DatasetInfos
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::DatasetInfo > datasetInput;
    };

    /**
     * Structure contains relation name and vector of related object types of interest,
     * which will used for filtering purpose.
     */
    struct RelationAndTypesFilter2
    {
        /**
         * The name of the relation of interest.
         */
        std::string relationName;
        /**
         * A list of related object types of interest.
         */
        std::vector< std::string > objectTypeNames;
    };

    /**
     * Contains dataset, item revision and list of <code>CadAttrMappingDefinition</code>
     * object references to be used in the resolve.
     */
    struct ResolveAttrMappingsForDatasetInfo
    {
        /**
         * <b>Dataset</b> object reference for which to get mapped attribute values.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * <b>ItemRevision</b> object reference, helps resolve ambiguity in the mapping traversal.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * List of <code>CadAttrMappingDefinition</code> object references
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CadAttrMappingDefinition>  > cadAttrMappingDefinitions;
    };

    /**
     * Contains the output data for <code>resolveAttrMappingsForDataset</code>.
     */
    struct ResolveAttrMappingsForDatasetOutput
    {
        /**
         * Dataset object reference for which mapped attribute property information is desired.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * A list of <code>MappedDatasetAttrProperty</code>
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::MappedDatasetAttrProperty > mappedProperties;
    };

    /**
     * Contains the response for <code>resolveAttrMappingsForDataset</code>.
     */
    struct ResolveAttrMappingsForDatasetResponse
    {
        /**
         * A list of <code>ResolveAttrMappingsForDatasetOutput</code>
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ResolveAttrMappingsForDatasetOutput > output;
        /**
         * <code>ServiceData</code> contains any partial errors and exceptions.
         * <br>
         * The objects holding the mapped attributes, resulting from successfully resolved mappings,
         * are returned as plain objects.
         * <br>
         * The mapped attribute properties are returned as <code>ServiceData</code> properties.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * CreateOrUpdateParts allows the user to create or update a set of parts using Items,
     * Item Revisions, Datasets and ExtraObjects. If the user supplies a valid Item object
     * reference without specifying a valid item revision object reference or id, then only
     * the item will be updated. If the user specifies a valid item object reference with
     * a null item revision object reference and a non-null revision id, then a new item
     * revision will be created and attached to the item with no relations from the new
     * item revision to the previous item revision. If the user specifies a valid item object
     * reference and a valid item revision object reference, then the item and item revision
     * and related objects will be updated. If no item object reference or item revision
     * object references are specified then a new item and item revision and related objects
     * will be created. All objects created and updated will be returned in the ServiceData.
     * All partial errors will contain the clientIDs for all items related to the error
     * message, i.e. if a dataset encounters an error, then the ID for that erro will be
     * the item client ID concantentated with the item revision id contantenated with the
     * dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of PartInfo structures
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     * @deprecated
     *         As of tc2007, use the createOrUpdateParts operation from the _2007_12 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the createOrUpdateParts operation from the _2007_12 namespace."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::PartInfo >& info ) = 0;

    /**
     * <code>createOrUpdateRelations</code> creates or updates GRM relations between existing
     * objects in Teamcenter. If the <code>complete</code> flag is set and a filter is supplied,
     * then any relation types that exist for primary objects in the info that are listed
     * in the filter, but the relations are not sent in the input, those relations will
     * be deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user wishes to relate two objects in Teamcenter. The user specifies the primary
     * and secondary objects, the type of relation to be created and any optional data the
     * user wants added to the relation.
     * <br>
     * The user wishes to modify the user data on the relationship between two objects.
     * The user specifies the primary and secondary objects and the existing relationship.
     * The user also specifies the new user data to be placed on the relationship.
     * <br>
     * The user wishes to relate two objects in Teamcenter and remove any existing relationships
     * between the objects. The user specifies the primary and secondary objects, the type
     * of relation to be created and any optional data the user wants added to the relation.
     * The user also sets the <code>complete</code> option to true to delete the existing
     * relationships that pass the supplied filter, but does not send those existing relationships
     * in the input.  For example, there is an item revision and a dataset related with
     * an IMAN_specification relationship in Teamcenter and the user wants to change this
     * to an IMAN_Rendering relationship. The user can specify the item revision and the
     * dataset, specify the new relationship is IMAN_Rendering and set the <code>complete</code>
     * flag. With the filter specifying the relation type of IMAN_specification and the
     * object type as dataset. This will delete the current relationship and create the
     * new one.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of <code>CreateOrUpdateRelationsInfo</code>
     *
     * @param complete
     *        A flag to check whether any existing relations that pass the filter needs to be deleted.
     *
     * @param pref
     *        A list of <code>RelationAndTypesFilter2</code> structure.
     *
     * @return
     *         Relations that were successfully created or updated are returned in the <code>CreateOrUpdateRelationsResponse</code>.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsResponse createOrUpdateRelations ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsInfo >& info,
        bool complete,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsPref&  pref ) = 0;

    /**
     * The purpose of this service is to provide the contents of a folder that a CAD integration
     * typically needs in one service call as opposed to multiple expand calls. This service
     * is specifically for Folder expansion and will only return Items, Item Revisions and
     * Folders that are contained in the input Folder. Other types of objects (Forms, Datasets,
     * etc...) that are contained directly under the input folder will not be returned.
     * The service will also return the Item Revisions and Datasets for the Items found
     * in the folder and Datasets found for the Item Revisions found directly under the
     * folder. The Item Revisions returned, are controlled thru an input latestNRevs specifying
     * how many latest revisions should be sent to output. The Items, Item Revisions and
     * Datasets returned can be filtered thru an input preference of a list of relation
     * names and dataset types filter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param folders
     *        A list of input TcEng folders
     *
     * @param pref
     *        Filter and expand preferences
     *
     * @return
     *         contains a list of ExpandFoldersForCADOutput structures (which contain information
     *         about the input TcEng folder, and filtered folder contents viz. folders, items and
     *         itemRevs). Failures and error message are in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADResponse expandFoldersForCAD ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  >& folders,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFolderForCADPref&  pref ) = 0;

    /**
     * Returns the secondary objects related to the input object for the given list of relation
     * names and other side object types filter. If no relation names or other side objects
     * types are provided in the input, then all related objects will be returned. In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned. Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned. However this additional expansion is controlled through the expItemRev
     * flag.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param objects
     *        A list of object references of objects of interest
     *
     * @param pref
     *        A ExpandGRMRelationsPref structure
     *
     * @return
     *         contains a list of ExpandGRMRelationsOutput structures (which contain information
     *         about the input TcEng Object, filtered Otherside related objects and the relationName
     *         they are related). Failures and error message are in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandGRMRelationsResponse expandGRMRelations ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandGRMRelationsPref&  pref ) = 0;

    /**
     * Returns the secondary objects related to the input object for the given list of relation
     * names and other side object types filter. If no relation names or other side objects
     * types are provided in the input, then all related objects will be returned. In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned. Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned. However this additional expansion is controlled through the expItemRev
     * flag.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param objects
     *        A list of input TcEng object references and filter and expand preferences
     *
     * @param pref
     *        A ExpandPrimaryObjectsPref structure
     *
     * @return
     *         contains a list of ExpandPrimaryObjectsOutput structures (which contain information
     *         about the input TcEng Object, filtered Otherside related objects and the relation/property
     *         Name they are related). Failures and error message are in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandPrimaryObjectsResponse expandPrimaryObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandPrimaryObjectsPref&  pref ) = 0;

    /**
     * Generate a list of alternate ids. An alternate id is a displayable id for an <b>Item</b>
     * or <b>ItemRevision</b> that is controlled by the user via display rules. The client
     * creates <b>Identifiers</b> that contain the various alternate ids to be displayed.
     * Each <b>Identifier</b> is controlled by a display rule. When a display rule is active
     * then the appropriate alternate id is displayed.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The client defines several alternate ids for a part. One alternate id is for the
     * manufacturer of the part( this would be their part number ), another would be for
     * a customer ( their part number ) and maybe one for a second customer ( again, another
     * part number ). This service allows the client to invoke the user exit USER_new_alt_id.
     * This exit will be called once for each count specified in the input using the data
     * passed in as parameters.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getContextsAndIdentifierTypes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        A list of <code>GenerateAlternateIdsProperties</code>.
     *
     * @return
     *         Contains the map of index to list of ids generated. The index refers to the input
     *         data in the input list.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GenerateAlternateIdsResponse generateAlternateIds ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::GenerateAlternateIdsProperties >& input ) = 0;

    /**
     * Retrieves all CAD attribute mapping definitions. Additionally, if a CadAttributeMappingDefinition
     * object has a path that includes a GRM or NR part, the associated PropertyDescriptor
     * and any attached ListOfValues objects will be returned.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         contains only failure information
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if any Teamcenter subsystem errors occur during the
     *           retrieval of all attribute mappings, finding the dataset type or finding the attribute
     *           mapping type.
     * @deprecated
     *         As of Teamcenter 9, use the getAllAttrMappings2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the getAllAttrMappings2 operation."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAllAttrMappingsResponse getAllAttrMappings (  ) = 0;

    /**
     * This operation retrieves the CAD attribute mapping definitions for one or more dataset
     * type and item type combinations.  If a <code>CadAttributeMappingDefinition</code>
     * object has a path that includes a Generic Relationship Manager (GRM) or named reference
     * part, the associated property descriptor and any attached <code>ListOfValues</code>
     * (LOV) objects will be returned.
     * <br>
     * <br>
     * Since this operation returns existing Teamcenter attribute mappings, please reference
     * the Teamcenter help section on creating attribute mappings.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to have attribute mappings defined in Teamcenter.
     * <br>
     * <br>
     * For this operation, the dataset object type is passed as input. The client application
     * uses the list of returned attribute mapping definitions to present the CAD attributes
     * to the user that correspond to the correct Teamcenter attributes.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of dataset and item types used to get a specific set of attribute mapping
     *        definitions from the all of the attribute mapping definitions in Teamcenter.
     *
     * @return
     *         The requested CAD attribute mapping definitions for the specified dataset type.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215070:  Unknown dataset type name specified.
     *         </li>
     *         <li type="disc">215071:  Unknown item type name specified.
     *         </li>
     *         <li type="disc">215073:  The operation failed to get the list of attribute mapping
     *         definitions for the specifed types.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if any Teamcenter subsystem errors
     *           occur during the retrieval of all attribute mappings.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAttrMappingsForDatasetTypeResponse getAttrMappingsForDatasetType ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAttrMappingsForDatasetTypeCriteria >& info ) = 0;

    /**
     * Finds types implemented by the given input class name.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User selects File New Item and is presented with a list of creatable item types.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param classes
     *        A list of the classes to return subtypes for
     *
     * @return
     *         Contains the map of input class names and for each input class name, the object references
     *         of found types (NULL, if none found). Failure will be returned via <code>ServiceData</code>
     *         with original input class string mapped to error message.
     *
     * @deprecated
     *         As of tc2007, use the getAvailabelTypes operation from the Core DataManagement service.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the getAvailabelTypes operation from the Core DataManagement service."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAvailableTypesResponse getAvailableTypes ( const std::vector< std::string >& classes ) = 0;

    /**
     * Retrieves CAD attribute mapped properties for one or more datasets.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User does a FileOpen of Teamcenter Item or Dataset (CAD Part).  CAD properties mapped
     * to Teamcenter attribute values are shown in the Part attribute display.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        An array of <code>ResolveAttrMappingsForDatasetInfo</code> structures each containing
     *        a <b>Dataset</b> object reference, an optional item revision, and a list of corresponding
     *        CAD Attribute Mapping Definitions to be resolved for the dataset. The optional item
     *        revision is recommended for improved performance in cases where resolution of the
     *        mapping string would otherwise require a relation query to find the item revision.
     *
     * @return
     *         Contains the resolved objects and properties. In addition to errors that may be returned
     *         from the Teamcenter subsystem, the following errors originate from this operation:
     *         <br>
     *         215074 : The Dataset supplied is invalid..
     *         <br>
     *         215075 : The Item Revision supplied is invalid.
     *         <br>
     *         215076 : The CadAttrMappingDefinition is invalid.
     *         <br>
     *         215077 : Failed to get the Attribute Mapping Title.
     *         <br>
     *         215078 : Failed to get the Attribute Mapping Dataset Type.
     *         <br>
     *         215079 : Failed to get the Attribute Mapping Dataset Type name.
     *         <br>
     *         215080 : Failed to get the Attribute Mapping Item Type.
     *         <br>
     *         215081 : Failed to get the Attribute Mapping Item Type name.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ResolveAttrMappingsForDatasetResponse resolveAttrMappingsForDataset ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ResolveAttrMappingsForDatasetInfo >& info ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

