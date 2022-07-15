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

#ifndef TEAMCENTER_SERVICES_CAD__2008_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2008_06_DATAMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_01/Datamanagement.hxx>
#include <teamcenter/services/cad/_2007_12/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
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
            namespace _2008_06
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct AttributeInfo;
    struct BoundingBox;
    struct CommitDatasetFileInfo;
    struct CreateOrUpdatePartsOutput;
    struct CreateOrUpdatePartsResponse;
    struct DatasetFileInfo;
    struct DatasetFileTicketInfo;
    struct DatasetInfo;
    struct DatasetOutput;
    struct ExpandFolderForCADPref2;
    struct ExpandFoldersForCADOutput2;
    struct ExpandFoldersForCADResponse2;
    struct ExtraObjectInfo;
    struct ItemInfo;
    struct ItemRevInfo;
    struct NamedReferenceObjectInfo;
    struct PartInfo;

    /**
     * This structure allows the caller define or update named attributes. The name member
     * represents the property name for the related object and the value is the value to
     * set.
     */
    struct AttributeInfo
    {
        /**
         * Text for attribute name
         */
        std::string name;
        /**
         * Text for attribute value
         */
        std::vector< std::string > values;
    };

    /**
     * Holds the boundingbox co-ordinates  information.
     */
    struct BoundingBox
    {
        /**
         * BoundingBox x-coordinate min value in double
         */
        double xmin;
        /**
         * BoundingBox y-coordinate min value in double
         */
        double ymin;
        /**
         * BoundingBox z-coordinate min value in double
         */
        double zmin;
        /**
         * BoundingBox x-coordinate max value in double
         */
        double xmax;
        /**
         * BoundingBox y-coordinate max value in double
         */
        double ymax;
        /**
         * BoundingBox z-coordinate max value in double
         */
        double zmax;
    };

    /**
     * Holds the basic info for a file to be uploaded to a dataset.
     */
    struct CommitDatasetFileInfo
    {
        /**
         * <code>Dataset</code> object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Flag to create new version ( TRUE ) or not ( FALSE ).
         */
        bool createNewVersion;
        /**
         * A list of <code>DatasetFileTicketInfos</code> which contains file ticket information
         * for the dataset file.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::DatasetFileTicketInfo > datasetFileTicketInfos;
    };

    /**
     * Contains the output response structure for createOrUpdateParts operation.
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
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::DatasetOutput > datasetOutput;
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
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
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
        /**
         * Flag to indicate BoundingBoxes are available.
         */
        bool boundingBoxesAvailable;
        /**
         * List of BoundingBoxes.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::BoundingBox > boundingBoxes;
    };

    /**
     * Holds the basic info for a file to be uploaded to a dataset.
     */
    struct DatasetFileTicketInfo
    {
        /**
         * Member of type DatasetFileInfo.
         */
        Teamcenter::Services::Cad::_2008_06::Datamanagement::DatasetFileInfo datasetFileInfo;
        /**
         * ID of ticket.
         */
        std::string ticket;
    };

    /**
     * The DatasetInfo struct represents all of the data necessary to construct the dataset
     * object. The basic attributes that are required are passed as named elements in the
     * structure. All other attributes are passed as name/value pairs in the AttributeInfo
     * structure. The extraObject field allows for the creation of an object(s) that will
     * be related to this newly created Dataset.
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
         * basisName
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
         * lastModifiedOfDataset
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
         * Can be null, defaulted
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
         * version to the next
         */
        std::string namedReferencePreference;
        /**
         * List of AttributeInfos for attributes
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > attrList;
        /**
         * List of AttributeInfos for mapped attributes. Mapped atributes are attributes that
         * are applied to other objects. Refere to the ITK manual for a definition of attribute
         * mapping.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > mappingAttributes;
        /**
         * List of ExtraObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::ExtraObjectInfo > extraObject;
        /**
         * List of DatasetFileInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::DatasetFileInfo > datasetFileInfos;
        /**
         * List of NamedReferenceObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::NamedReferenceObjectInfo > namedReferenceObjectInfos;
    };

    /**
     * Contains created/updated dataset.
     */
    struct DatasetOutput
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * <b>Dataset</b> object reference of the created/updated dataset
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * List of <code>CommitDatasetFileInfos</code>
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::CommitDatasetFileInfo > commitInfo;
        /**
         * List of <code>ExtraObjectOutputs</code> for the extra objects
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectOutput > extraObjs;
        /**
         * List of <code>ExtraObjectOutputs</code> for the named references
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExtraObjectOutput > namedRefObjs;
    };

    /**
     * Contains a list of <code>RelationAndTypesFilter</code>, number of latest revisions
     * for further filtering and a flag to check whether item revision needs to be expanded
     * and list of other object types to return from the folder contents.
     */
    struct ExpandFolderForCADPref2
    {
        /**
         * Flag to specify if the datasets attached to the item revisions are to be returned.
         * If set to TRUE then all datasets owned by each item revision will be returned with
         * the item revision.
         */
        bool expItemRev;
        /**
         * The number of revisions under an item that should be considered for further filtering.
         * If there are 5 versions of an item and this option is set to 2 then versions 4 and
         * 5 will be processed. 0 = do not return any item revisions. minus 1 = return all item
         * revisions.
         */
        int latestNRevs;
        /**
         * A list of <code>RelationAndTypesFilter2</code> structures to select the datasets
         * under an item revision to return. If empty then all dataset will be returned.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::RelationAndTypesFilter2 > info;
        /**
         * A list of object types. Any objects in any input folder that are of the type in this
         * list will also be returned.
         */
        std::vector< std::string > contentTypesFilter;
    };

    /**
     * Contains the folder expanded and the results of expanding the folder based on the
     * input preference.
     */
    struct ExpandFoldersForCADOutput2
    {
        /**
         * The folder that was expanded.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  inputFolder;
        /**
         * A list of folders contained by the input folder.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  > fstlvlFolders;
        /**
         * A list of <code>ExpandFolderForCADItemOutput</code> which has information about the
         * items in the folder.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADItemOutput > itemsOutput;
        /**
         * A list of <code>ExpandFolderForCADItemRevOutput</code> which has information about
         * the item revisions in the folder.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADItemRevOutput > itemRevsOutput;
        /**
         * A list of objects in the folder that are a type listed in the <code>contentTypesFilter</code>
         * input.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > contents;
    };

    /**
     * Contains the response for <code>ExpandFoldersForCAD</code> operation.
     */
    struct ExpandFoldersForCADResponse2
    {
        /**
         * A list of <code>ExpandFoldersForCADOutput2</code> which has information about the
         * input folder and folders, items and item revisions output found under this folder
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::ExpandFoldersForCADOutput2 > output;
        /**
         * Contains the folders, items, items revisions, datasets, and other object types in
         * the list of plain objects.
         * <br>
         * Error information returned is identified by the folder tag sent to the service and
         * will include system errors plus errors generated by this service :
         * <br>
         * 7007 : Input folder is invalid.
         * <br>
         * 215121 : Object passed in is not a folder.
         * <br>
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
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > attrNameValuePairs;
    };

    /**
     * the ItemInfo structure represents all of the data necessary to construct the item
     * object. The basic attributes that are required are passed as named elements in the
     * structure. All other attributes are passed as name/value pairs in the AttributeInfo
     * structure. The extraObject field allows for the creation of an object(s) that will
     * be related to this newly created Item.
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
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > attrList;
        /**
         * List of ExtraObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::ExtraObjectInfo > extraObject;
        /**
         * Folder to attach Item to, if null then default used
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * the ItemRevInfo structure represents all of the data necessary to construct the item
     * revision object. The basic attributes that are required are passed as named elements
     * in the struct. All other attributes are passed as name/value pairs in the AttributeInfo
     * structure. The extraObject field allows for the creation of an object(s) that will
     * be related to this newly created Item Revision.
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
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > attrList;
        /**
         * List ofr ExtraObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::ExtraObjectInfo > extraObject;
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
         * Object reference of the object for update, null for create.
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
         * The reference type name from the dataset to this object, must be either AE_ASSOCIATION
         * or AE_PART_OF.
         */
        std::string namedReferenceType;
        /**
         * Type of the object to be created. Required for object creation only.
         */
        std::string typeName;
        /**
         * List of attribute information.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::AttributeInfo > attrNameValuePairs;
    };

    /**
     * The PartInfo struct is the main input to the createOrUpdateParts service for boundingbox.
     * This structure refers to the Item, ItemRevision, and one or more Dataset structures
     * used to create those objects.
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
        Teamcenter::Services::Cad::_2008_06::Datamanagement::ItemInfo itemInput;
        /**
         * Member of type ItemRevInfo
         */
        Teamcenter::Services::Cad::_2008_06::Datamanagement::ItemRevInfo itemRevInput;
        /**
         * List of DatasetInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::DatasetInfo > datasetInput;
    };




    /**
     * CreateOrUpdateParts allows the user to update or create a set of parts using Items,
     * Item Revisions, and Datasets and save the boudingbox information related to these
     * objects. The service first attempts to validate the existence of the Item, Item Revision,
     * and Dataset. If the Item and Item Revision already exist, but the Dataset does not,
     * then only the Dataset is created. If the Dataset exists, a new version will be added
     * to the existing series. If any of the objects exist but the input attribute values
     * that differ from those already set, attempts are made to update the values if possible.
     * If the boundingbox information exists it saves that information on that particular
     * dataset else it willnot save the boudingbox information. If no item object reference
     * or item revision object references are specified then a new item and item revision
     * and related objects will be created. All objects created and updated will be returned
     * in the ServiceData. All partial errors will contain the clientIDs for all items related
     * to the error message, i.e. if a dataset encounters an error, then the ID for that
     * erro will be the item client ID concantentated with the item revision id contantenated
     * with the dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param partInput
     *        A list of PartInfo structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::PartInfo >& partInput,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;

    /**
     * The purpose of this service is to provide the contents of a folder that a CAD integration
     * typically needs in one service call as opposed to multiple expand calls. This service
     * is specifically for folder expansion and will only return items, item revisions and
     * folders that are contained in the input folder. Other types of objects ( forms, datasets,
     * etc.. ) that are contained directly under the input folder can be returned if their
     * type is specified in the preference. The service will also return the item revisions
     * and datasets for the items found in the folder and datasets found for the item revisions
     * found directly under the folder. The item revisions returned, are controlled thru
     * an input <code>latestNRevs</code> specifying how many latest revisions should be
     * sent to output. The items, item revisions and datasets returned can be filtered thru
     * an input preference of a list of relation names and dataset types filter.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A CAD application needs to know what objects in the database are relative to the
     * cad application. The CAD application can get the contents of the home folder and
     * display to the user. If the user then selects a subfolder of home then the application
     * can expand that folder to get to the desired data. This service will return objects
     * that the cad application understands such as subfolders, items, item revisions and
     * datasets and other objects of the type the application specifies in the input filter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param folders
     *        A list of folders to expand.
     *
     * @param pref
     *        Filter and expand preferences
     *
     * @return
     *         Contains a list of <code>ExpandFoldersForCADOutput</code> structures  (which contain
     *         information about the input  folder, and filtered folder contents viz. folders, items,
     *         item revisions and objects of specified type). Any error messages are in the <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::ExpandFoldersForCADResponse2 expandFoldersForCAD ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  >& folders,
        const Teamcenter::Services::Cad::_2008_06::Datamanagement::ExpandFolderForCADPref2&  pref ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

