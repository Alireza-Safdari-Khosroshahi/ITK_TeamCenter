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

#ifndef TEAMCENTER_SERVICES_CAD__2008_03_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2008_03_DATAMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_01/Datamanagement.hxx>
#include <teamcenter/services/cad/_2007_12/Datamanagement.hxx>
#include <teamcenter/soa/client/model/CadAttrMappingDefinition.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
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
            namespace _2008_03
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct CadAttrMappingDefinitionInfo;
    struct DatasetInfo3;
    struct MappedDatasetAttrPropertyInfo;
    struct PartInfo3;
    struct ResolveAttrMappingsInfo;
    struct ResolveAttrMappingsResponse;

    /**
     * ResolveAttrMappingsOutputMap
     */
    typedef std::map< std::string, MappedDatasetAttrPropertyInfo > ResolveAttrMappingsOutputMap;

    /**
     * Contains unique <code>clientId</code> and <code>CadAttributeMappingDefinition</code>
     * object reference associated with the resolved property object.
     */
    struct CadAttrMappingDefinitionInfo
    {
        /**
         * Unique client side identifier. This is a required input parameter If the <code>ClientId</code>
         * is not provided or not unique a partial error is reported and the property for the
         * particular <code>CADAttrMappingDefinition</code> will not resolved.
         */
        std::string clientId;
        /**
         * <b>CadAttributeMappingDefinition</b> object reference associated with the resolved
         * property object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CadAttrMappingDefinition>  cadAttrMappingDefinition;
    };

    /**
     * The DatasetInfo3 struct represents all of the data necessary to construct the dataset
     * object. The basic attributes that are required are passed as named elements in the
     * struct. All other attributes are passed as name/value pairs in the AttributeInfo
     * struct. The extraObject field allows for the creation of an object(s) that will be
     * related to this newly created Dataset.
     */
    struct DatasetInfo3
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
         * Basis Name attribute value, used when the name is null or blank
         */
        std::string basisName;
        /**
         * Description attribute value
         */
        std::string description;
        /**
         * Type attribute value
         */
        std::string type;
        /**
         * Last Modified Date of dataset
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfDataset;
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
         * Flag to indicate whether DatasetInfo should be used for mapping attributes or for
         * create.
         */
        bool mapAttributesWithoutDataset;
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
        std::vector< Teamcenter::Services::Cad::_2007_12::Datamanagement::NamedReferenceObjectInfo2 > namedReferenceObjectInfos;
    };

    /**
     * Contains resolved object and property name along with <b>CadAttrMappingDefinition</b>
     * object reference associated with the resolved property object.
     */
    struct MappedDatasetAttrPropertyInfo
    {
        /**
         * <b>CadAttrMappingDefinition</b> object reference associated with the resolved property
         * Object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CadAttrMappingDefinition>  cadAttrMappingDefinition;
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
     * The PartInfo3 struct is the main input to the createOrUpdateParts service. This structure
     * refers to the Item, ItemRevision, and one or more Dataset structures used to create
     * those objects.
     */
    struct PartInfo3
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
         * List of DatasetInfo3
         */
        std::vector< Teamcenter::Services::Cad::_2008_03::Datamanagement::DatasetInfo3 > datasetInput;
    };

    /**
     * Contains dataset, item revision and list of <code>CadAttrMappingDefinition</code>
     * object references to use to resolve the mapping.
     */
    struct ResolveAttrMappingsInfo
    {
        /**
         * <b>Dataset</b> object reference to use as starting point to get mapped attribute
         * values.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * <b>ItemRevision</b> object reference helps resolve ambiguity in the mapping traversal
         * for the dataset or can be the starting point for the traversal as well.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * List of CadAttrMappingDefinitionInfo objects
         */
        std::vector< Teamcenter::Services::Cad::_2008_03::Datamanagement::CadAttrMappingDefinitionInfo > mappingDefinitionInfos;
    };

    /**
     * Holds the response for resolveAttrMappings. The processing of the input is as follows
     * :
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Process the ResolveAttrMappingsInfo first. This will validate
     * the dataset and item revision inputs are valid. If this validation fails, then an
     * error will be returned with the index of the ResolveMappinsInfo being the identifier
     * with the error.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Process the list of CadAttrMappingDefinitionInfo. If this
     * results in an error then the identifier for the error will be the clientId specified
     * in the CadAttributeMappingDefinition.
     * <br>
     * When processing the output, if a key with thte clientId is not found, the application
     * should first look for an error with an identifier of the cleintId. If no error is
     * found then the index of the input that contained the clientId should be found.
     * <br>
     */
    struct ResolveAttrMappingsResponse
    {
        /**
         * Member of type <code>ResolveAttrMappingsOutputMap</code>. This is a map containing
         * the successfully mapped property information. The keys are the input <code>clientIds</code>
         * and the values are the output <code>MappedDatasetAttrPropertyInfo</code> structures.
         */
        ResolveAttrMappingsOutputMap resolvedMappingsMap;
        /**
         * Service data contains any partial errors and exceptions. The objects holding the
         * mapped attributes, resulting from successfully resolved mappings, are returned as
         * plain objects. The mapped attribute properties are returned as <code>ServiceData</code>
         * properties.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * CreateOrUpdateParts allows the user to create or update a set of parts using Items,
     * Item Revisions, Datasets and ExtraObjects and also changes the ownership of the newly
     * created object to the user/group supplied. If the user supplies a valid Item object
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
     *        A list of PartInfo3 structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual.
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2008_03::Datamanagement::PartInfo3 >& info,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;

    /**
     * Retrieves CAD attribute mapped properties for item revisions or datasets.  Attribute
     * Mapping is a scheme whereby Teamcenter attributes can be retrieved or set via a defined
     * path to the attribute from the starting object, usually a dataset.  For example,
     * a mapped attribute can be defined in the client integration with a particular name
     * ATTR1.  Using Teamcenter attribute mapping, the customizer can define a path named
     * ATTR1 from a starting point item revision type or dataset type to the actual attribute
     * that holds the value for ATTR1. The client integration then can access the attribute
     * using the attribute mapping title ATTR1 and the starting point object.
     * <br>
     * For more information about Attribute Mapping including examples with syntax, please
     * consult the "Configuring attribute mapping section" of the Application Administration
     * Guide in Teamcenter Online Help.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user performs a File Open operation on an existing Teamcenter dataset.  The client
     * integration has defined an attribute mapping in Teamcenter for that Dataset type.
     * The resolveAttrMappings call performed as a part of the File Open, sends the mapping
     * definition, defined by the mapping title, and the Dataset as input.  The operation
     * traverses from the input Dataset to the mapped property which in this case resides
     * on the Datasets parent Item Revision.  The operation will return the item revision
     * and the mapped property name such that the client integration can retrieve the property
     * value from the item revision.  The value is then displayed in the attribute data
     * for the dataset in the client integration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        An array of ResolveAttrMappingsInfo structures each containing a <b>Dataset</b> object
     *        reference, an optional item revision, and a list of corresponding CAD Attribute Mapping
     *        Definitions to be resolved for the dataset.
     *
     * @return
     *         contains the resolved objects, properties, and failure information This service can
     *         return errors from utilities and also defines its own errors. The errors this service
     *         can return are:
     *         <br>
     *         215119 No Dataset or Item Revision specified
     *         <br>
     *         215074 Invalid Dataset
     *         <br>
     *         215075 Invalid Item Revision
     *         <br>
     *         215076 Invalid CadAttrMappingDefinitionInfo object
     *         <br>
     *         215200 No clientId specified
     *         <br>
     *         215201 Duplicate clientId specified
     *         <br>
     *
     */
    virtual Teamcenter::Services::Cad::_2008_03::Datamanagement::ResolveAttrMappingsResponse resolveAttrMappings ( const std::vector< Teamcenter::Services::Cad::_2008_03::Datamanagement::ResolveAttrMappingsInfo >& info ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

