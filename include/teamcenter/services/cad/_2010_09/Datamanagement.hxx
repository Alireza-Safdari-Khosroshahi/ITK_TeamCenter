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

#ifndef TEAMCENTER_SERVICES_CAD__2010_09_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2010_09_DATAMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_12/Datamanagement.hxx>
#include <teamcenter/services/cad/_2008_06/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ImanVolume.hxx>


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
            namespace _2010_09
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct DatasetFileInfo;
    struct DatasetInfo;
    struct PartInfo;

    /**
     * Holds the basic info for a file to be uploaded to a <b>Dataset</b>.
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
         * Flag to indicate <code>BoundingBoxes</code> are available.
         */
        bool boundingBoxesAvailable;
        /**
         * Destination volume into which the file will be uploaded. If null tag the current
         * default volume of the user will be used.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanVolume>  destinationVolume;
        /**
         * List of <code>BoundingBoxes</code>.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::BoundingBox > boundingBoxes;
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
        std::vector< Teamcenter::Services::Cad::_2010_09::Datamanagement::DatasetFileInfo > datasetFileInfos;
        /**
         * List of NamedReferenceObjectInfos
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::NamedReferenceObjectInfo > namedReferenceObjectInfos;
        /**
         * The dataset tool for the dataset. If not specified then the default tool will be
         * used.
         */
        std::string datasetTool;
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
        std::vector< Teamcenter::Services::Cad::_2010_09::Datamanagement::DatasetInfo > datasetInput;
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
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2010_09::Datamanagement::PartInfo >& partInput,
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

