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

#ifndef TEAMCENTER_SERVICES_CAD__2012_09_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2012_09_DATAMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_12/Datamanagement.hxx>
#include <teamcenter/services/cad/_2008_06/Datamanagement.hxx>
#include <teamcenter/services/cad/_2010_09/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
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
            namespace _2012_09
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct CreateOrUpdateInput;
    struct DatasetInfo;
    struct ExtraObjectInfo;
    struct ItemInfo;
    struct NamedReferenceObjectInfo;
    struct PartInfo;

    /**
     * Map of boolean property names to values (string, bool).
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * Map of bool array property names to values (string, vector< bool >).
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * Map of string client ids to vector of <code>CreateOrUpdateInput</code> values (string,
     * vector).
     */
    typedef std::map< std::string, std::vector< CreateOrUpdateInput > > CreateOrUpdateInputMap;

    /**
     * Map of <b>DateTime</b> property names to values (string, < <b>DateTime</b>>).
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * Map of <b>DateTime</b> array property names to values (string, vector< <b>DateTime</b>>).
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * DoubleMap
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * Map of double array property names to values (string, vector).
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * Map of float property names to values (string, float).
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * Map of float array property names to values (string, vector).
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * Map of int property names to values (string, int).
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * IntVectorMap
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * Map of string property names to values (string, string).
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * Map of string array property names to values (string, vector).
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * Map of <b>BusinessObject</b> property names to values (string, <b>BusinessObject</b>).
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * Map of <b>BusinessObject</b> array property names to values (string, vector).
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * The <code>CreateOrUpdateInput</code> structure represents all of the data necessary
     * to construct a business object. All attributes are passed in as name/value pairs
     * for the corresponding value type map.
     * <br>
     * The <code>compoundCreateOrUpdateInput</code> field allows for the creation of a secondary
     * object(s) for the newly created primary object.
     */
    struct CreateOrUpdateInput
    {
        /**
         * Business Object type name. This field must be specified for create.
         */
        std::string boName;
        /**
         * Existing object reference. This field must be specified for update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  boReference;
        /**
         * Map containing string property values
         */
        StringMap stringProps;
        /**
         * Map containing string array property values
         */
        StringVectorMap stringArrayProps;
        /**
         * Map containing string property values
         */
        DoubleMap doubleProps;
        /**
         * Map containing string array property values
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map containing string property values
         */
        FloatMap floatProps;
        /**
         * Map containing string array property values
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map containing string property values
         */
        IntMap intProps;
        /**
         * Map containing string array property values
         */
        IntVectorMap intArrayProps;
        /**
         * Map containing string property values
         */
        BoolMap boolProps;
        /**
         * Map containing string array property values
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map containing <b>DateTime</b> property values
         */
        DateMap dateProps;
        /**
         * Map containing <b>DateTime</b> array property values
         */
        DateVectorMap dateArrayProps;
        /**
         * Map containing string property values
         */
        TagMap tagProps;
        /**
         * Map containing string array property values
         */
        TagVectorMap tagArrayProps;
        /**
         * <code>CreateOrUpdateInput</code> for secondary (compounded) objects
         */
        CreateOrUpdateInputMap compoundCreateOrUpdateInput;
    };

    /**
     * The <code>DatasetInfo</code> struct represents all of the data necessary to construct
     * the <b>Dataset</b> object. The basic attributes that are required are passed as named
     * elements in the structure. All other attributes are passed as name/value pairs in
     * the <code>AttributeInfo</code> structure: <code>attrList</code>. The extraObject
     * field allows for the creation of an object(s) that will be related to this newly
     * created <b>Dataset</b>.
     */
    struct DatasetInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * <code>CreateOrUpdateInput</code> object which contains attributes to create a <b>Dataset</b>.
         * <code>createOrUpdateInput</code> can be null for update.
         */
        Teamcenter::Services::Cad::_2012_09::Datamanagement::CreateOrUpdateInput createOrUpdateInput;
        /**
         * Basis name attribute value. When the dataset name is blank, the basis name is used
         * to call USER_new_dataset_name to generate a new name.
         */
        std::string basisName;
        /**
         * If not null, the date and time that the <b>Dataset</b> was last modified. If the
         * actual modified date and time is later, then an error is thrown.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfDataset;
        /**
         * The relation name for the <b>Dataset</b> to <b>ItemRevision</b> relation. Can be
         * null, but is required if an <b>ItemRevision</b> is specified.
         */
        std::string itemRevRelationName;
        /**
         * Flag to create new version ( TRUE ) or not (FALSE ).
         */
        bool createNewVersion;
        /**
         * Flag to indicate whether <code>DatasetInfo</code> should be used for mapping attributes
         * or for create.
         */
        bool mapAttributesWithoutDataset;
        /**
         * Preference name which holds the list of named references to delete from one <b>Dataset</b>
         * version to the next.
         */
        std::string namedReferencePreference;
        /**
         * List of <code>AttributeInfos</code> for mapped attributes. Mapped attributes are
         * attributes that are applied to other objects. Refer to the ITK manual for a definition
         * of attribute mapping.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > mappingAttributes;
        /**
         * List of <code>ExtraObjectInfos</code>, the extra objects to be created and related
         * to the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::ExtraObjectInfo > extraObject;
        /**
         * List of <code>DatasetFileInfos</code>, which holds the basic information for a file
         * to be uploaded to a <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Cad::_2010_09::Datamanagement::DatasetFileInfo > datasetFileInfos;
        /**
         * List of <code>NamedReferenceObjectInfos</code>, contains information regarding named
         * reference type value, object reference, object type name and list of attribute information
         * to set on the object.
         */
        std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::NamedReferenceObjectInfo > namedReferenceObjectInfos;
    };

    /**
     * Form objects that can be created or updated and related to an item, item revision
     * or dataset.
     */
    struct ExtraObjectInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * CreateOrUpdateInput object which contains attributes to create an extra object. createOrUpdateInput
         * can be null for update.
         */
        Teamcenter::Services::Cad::_2012_09::Datamanagement::CreateOrUpdateInput createOrUpdateInput;
        /**
         * Name of the relation type to the parent object
         */
        std::string relationTypeName;
    };

    /**
     * The <code>ItemInfo</code> structure represents all of the data necessary to construct
     * the item object. The basic attributes that are required are passed as named elements
     * in the structure. All other attributes are passed as name/value pairs in the <code>AttributeInfo</code>
     * structures: <code>attrList</code> and <code>formAttrList</code>. The <code>extraObject</code>
     * field allows for the creation of an object(s) that will be related to this newly
     * created Item.
     */
    struct ItemInfo
    {
        /**
         * <code>CreateOrUpdateInput</code> object which contains attributes to create an <b>Item</b>.
         * <code>createOrUpdateInput</code> can be null for update.
         */
        Teamcenter::Services::Cad::_2012_09::Datamanagement::CreateOrUpdateInput createOrUpdateInput;
        /**
         * List of extra objects to be used or created and related to the <b>Item</b>.
         */
        std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::ExtraObjectInfo > itemExtraObject;
        /**
         * List of extra objects to be used or created and related to the <b>Item Revision</b>.
         */
        std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::ExtraObjectInfo > itemRevisionExtraObject;
        /**
         * Folder to attach the <b>Item</b> to. If null, then the Teamcenter preference <b>WsoInsertNoSelectionsPref</b>
         * is used to get the default location.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * Contains information regarding named reference type value, object reference, object
     * type name and list of attribute information to set on the object.
     */
    struct NamedReferenceObjectInfo
    {
        /**
         * Identifier defined by client to track the related object.
         */
        std::string clientId;
        /**
         * Object that contains <code>attributes</code> to create a named reference object.
         * <code>createOrUpdateInput</code> can be null for update.
         */
        Teamcenter::Services::Cad::_2012_09::Datamanagement::CreateOrUpdateInput createOrUpdateInput;
        /**
         * The named reference from the dataset to this object and a required input. Named reference
         * name values  are defined for each dataset type. The customer can add more values
         * as needed. To get a current list of valid named reference name values the programmer
         * can either use the Business Modeler IDE or can call the Core service <code>getDatasetTypeInfo</code>.
         */
        std::string namedReferenceName;
        /**
         * The reference type name from the dataset to this object, must be either AE_ASSOCIATION
         * or AE_PART_OF.
         */
        std::string namedReferenceType;
    };

    /**
     * The <code>PartInfo</code> struct is the main input to the <code>createOrUpdateParts</code>
     * service for boundingbox. This structure refers to the item and one or more dataset
     * structures used to create those objects.
     */
    struct PartInfo
    {
        /**
         * Identifier defined by the user to track the related object.
         */
        std::string clientId;
        /**
         * Member of type <code>ItemInfo</code>.
         */
        Teamcenter::Services::Cad::_2012_09::Datamanagement::ItemInfo itemInput;
        /**
         * List of <code>DatasetInfos</code>.
         */
        std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::DatasetInfo > datasetInput;
    };




    /**
     * <code>CreateOrUpdateParts</code> allows the user to create or update a set of <b>Items</b>,
     * <b>ItemRevisions</b>, and <b>Datasets</b> (CAD concept of a Part includes these Teamcenter
     * objects). The service first attempts to validate the existence of the <b>Item</b>,
     * <b>ItemRevision</b>, and <b>Dataset</b>. If the <b>Item</b> already exist,s but the
     * <b>ItemRevision</b> does not, then a new initial <b>ItemRevision</b> is created-any
     * existing <b>ItemRevisions</b> are not revised. If the <b>Item</b> and <b>ItemRevision</b>
     * already exist, but the <b>Dataset</b> does not, then only the <b>Dataset</b> is created.
     * If the <b>Dataset</b> exists, a new version will be added to the existing series.
     * If any of the objects exist but the input attribute values that differ from those
     * already set, attempts are made to update the values if possible. If no <b>Item</b>
     * object reference or <b>ItemRevision</b> object references are specified then a new
     * <b>Item</b> and <b>ItemRevision</b> and related objects will be created. All objects
     * created and updated will be returned in the <code>ServiceData</code>. All partial
     * errors will contain the <code>clientIDs</code> for all items related to the error
     * message, i.e. if a dataset encounters an error, then the ID for that error will be
     * the item client ID concatenated with the item revision id concatenated with the dataset
     * client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to create a new CAD Part (item, item revision, and dataset). User fills
     * in the <code>CreateOrUpdateInput</code> structure with the information for the item
     * and item ievision.
     * <br>
     * <br>
     * User wants to create an item and item revision with one or more datasets. Client
     * fills in the <code>CreateOrUpdateInput</code> structure with the information for
     * the item and item revision from the user. Client also fills in one or more <code>DatasetInfos</code>
     * with the information about the datasets to create from the user. Upon return from
     * the service, the client will extract the <code>FileTickets</code> from the <code>DatasetOutputs</code>
     * and upload the data files for the datasets using FMS. Once the uploads have completed,
     * then the client will use the <code>DatasetCommitInfos</code> to attach the upload
     * files to the datasets using the Core Services <code>commitDatasetFiles</code>.
     * <br>
     * <br>
     * User wants to modify properties on an item, item revision or dataset. Client fills
     * in the <code>CreateOrUpdateInput</code> structure with the new information for the
     * item or item revision. Client fills in the new information in a <code>DatasetInfo</code>
     * structure then invokes the service using an existing item or item revision or dataset.
     * <br>
     * <br>
     * <b>User</b> wants to create or update an existing item and/or item revision with
     * User created Form object. The client fills in the necessary data to create or update
     * an item and/or item revision. The client also specifies <code>itemExtraObjectInfo</code>
     * and/or <code>itemRevisionExtraObjectInfo</code> containing the form and relation
     * to be used to attach the form to another object.
     * <br>
     * <br>
     * <b>User</b> wants to add objects to a dataset. This can be done as Extra Objects
     * or using the NamedReference feature. The user fills in the information necessary
     * to create or update a dataset. The user can then specify <code>ExtraObjectInfo</code>
     * data for attaching forms or <code>NamedReferenceObjectInfo</code> for other objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param partInput
     *        A list of <code>PartInfo</code> structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual
     *
     * @return
     *         contains a list of <code>CreateOrUpdatePartsOutput</code> structures (which contain
     *         information about the item, itemrevisions. datasets and extra objects ). Failure
     *         will be with client id and error message in the <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::PartInfo >& partInput,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

