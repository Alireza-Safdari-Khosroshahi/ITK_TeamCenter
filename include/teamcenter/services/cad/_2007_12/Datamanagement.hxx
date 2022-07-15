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

#ifndef TEAMCENTER_SERVICES_CAD__2007_12_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2007_12_DATAMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_01/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
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
            namespace _2007_12
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct CreateOrUpdatePartsPref;
    struct DatasetInfo2;
    struct NamedReferenceObjectInfo2;
    struct PartInfo2;

    /**
     * Input structure for CreateOrUpdatePartsPref
     */
    struct CreateOrUpdatePartsPref
    {
        /**
         * Flag to check whether dataset needs to be modified, if input last modified date is
         * different from actual.
         */
        bool overwriteForLastModDate;
    };

    /**
     * The DatasetInfo2 struct represents all of the data necessary to construct the dataset
     * object. The basic attributes that are required are passed as named elements in the
     * struct. All other attributes are passed as name/value pairs in the AttributeInfo
     * struct. The extraObject field allows for the creation of an object(s) that will be
     * related to this newly created Dataset.
     */
    struct DatasetInfo2
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
         * Preference name which holds the list of named references to delete from one Dataset
         * version to the next
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
     * Contains information for object named references to apply to the Dataset.
     */
    struct NamedReferenceObjectInfo2
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
         * The reference type name from the dataset to this object, must be either AE_ASSOCIATION
         * or AE_PART_OF.
         */
        std::string namedReferenceType;
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
     * The PartInfo2 struct is the main input to the createOrUpdateParts service. This structure
     * refers to the Item, ItemRevision, and one or more Dataset structures used to create
     * those objects.
     */
    struct PartInfo2
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
         * List of DatasetInfo2
         */
        std::vector< Teamcenter::Services::Cad::_2007_12::Datamanagement::DatasetInfo2 > datasetInput;
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
     *        A list of PartInfo2 structures
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
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2007_12::Datamanagement::PartInfo2 >& info,
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

