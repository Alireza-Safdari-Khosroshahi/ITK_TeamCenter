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

#ifndef TEAMCENTER_SERVICES_CAD__2008_06_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2008_06_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_01/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2007_12/Structuremanagement.hxx>
#include <teamcenter/soa/client/model/AbsOccData.hxx>
#include <teamcenter/soa/client/model/AbsOccurrence.hxx>
#include <teamcenter/soa/client/model/AssemblyArrangement.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Form.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/MEAppearancePathNode.hxx>
#include <teamcenter/soa/client/model/PSBOMViewRevision.hxx>
#include <teamcenter/soa/client/model/PSOccurrenceThread.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>
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
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct AbsOccAttachment2;
    struct DatasetInfo;
    struct AbsOccCreateDatasetAttachmentInfo;
    struct FormInfo;
    struct AbsOccCreateFormAttachmentInfo;
    struct AbsOccDataGRMExpansionInfo;
    struct AbsOccDataInfo2;
    struct AbsOccDataPref;
    struct AbsOccInfo2;
    struct AbsOccQualifierInfo;
    struct DataOverrideInfo;
    struct AbsOccStructureDataInfo;
    struct ApnToThreadPathStruct;
    struct BoundingBox;
    struct BoundingBoxInfo;
    struct CommitDatasetFileInfo;
    struct CreateOrUpdateAbsoluteStructureInfo3;
    struct CreateOrUpdateAbsoluteStructurePref3;
    struct CreateOrUpdateAbsoluteStructureResponse2;
    struct CreateOrUpdateRelativeStructureInfo3;
    struct CreateOrUpdateRelativeStructurePref3;
    struct CreateVariantRulesInfo;
    struct CreateVariantRulesResponse;
    struct DatasetFileInfo;
    struct DatasetFileTicketInfo;
    struct DatasetOutput;
    struct DeleteRelativeStructureInfo3;
    struct ExpandPSAllLevelsInfo;
    struct ExpandPSParentData;
    struct ExpandPSAllLevelsOutput;
    struct ExpandPSAllLevelsPref;
    struct ExpandPSAllLevelsResponse2;
    struct ExpandPSData;
    struct ExpandPSNamedReferenceInfo;
    struct ExpandPSOneLevelInfo;
    struct ExpandPSOneLevelOutput;
    struct ExpandPSOneLevelPref;
    struct ExpandPSOneLevelResponse2;
    struct ExpandPSRelatedObjectInfo;
    struct GetAbsoluteStructureDataResponse;
    struct NamedReferenceObjectInfo;
    struct NameValueStruct;
    struct OptionsInfo;
    struct ReconfigureBOMWindowsInfo;
    struct ReconfigureBOMWindowsOutput;
    struct ReconfigureBOMWindowsResponse;
    struct RelatedObjectTypeAndNamedRefs;
    struct RelationAndTypesFilter;
    struct RelativeStructureChildInfo2;
    struct SaveBOMWindowsResponse;
    struct VariantRulesOutput;

    /**
     * The enum specifies the filter that needs to be applied on the output absolute occurrence
     * data that returned in the response. For example an occurrence can have overrides
     * only with qualifying BVR and overrides with both upper and qualifying BVR. Valid
     * values are: None -- When the upperQualifer is not specified all absoccdata excluding
     * ones with upper qualifiers are returned. IncludeBvrOnlyQualifyingOverrides -- When
     * an upperQualifer is specified all absoccdata that has given upper qualifier is returned.
     * IncludeBvrAndUpperQualifyingOverrides -- Brings all absoccdata that has BVR only
     * and which has upper and BVR qualifier.
     */
    enum AbsOccDataQualifierFilter{ AbsOccDataQualifierFilterNone,
                 IncludeBvrOnlyQualifyingOverrides,
                 IncludeBvrAndUpperQualifyingOverrides
                 };

    /**
     * This enumerated type identifies which BOM lines are to be processed.
     */
    enum BOMLineFilter2{ None2,
                 ExcludeOverridden2,
                 ExcludeICHistory2,
                 ExcludeGDEs2,
                 ExcludeImanItemLines2
                 };

    /**
     * This enumerated type identifies which named references will be processed in a product
     * structure one level expand operation.
     */
    enum NamedRefHandler{ UseNamedRefsList,
                 NoNamedRefs,
                 AllNamedRefs,
                 PreferredJT
                 };

    /**
     * ClientIdToAbsOccMap2
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AbsOccurrence>  > ClientIdToAbsOccMap2;

    /**
     * ClientIdToAsmArrangementMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  > > ClientIdToAsmArrangementMap;

    /**
     * ClientIdToFormMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Form>  > ClientIdToFormMap;

    /**
     * Contains an override object which is attached as the override data and a <code>relationTypeName</code>
     * to relate the <code>AbsOccData</code> to the object.
     */
    struct AbsOccAttachment2
    {
        /**
         * The object which is attached as the override data.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  overrideObject;
        /**
         * Relation name or property name to relate <code>AbsOccData</code> to object.
         */
        std::string relationTypeName;
    };

    /**
     * Contains clientId, Dataset object reference for update, Name attribute value, basisName,
     * description, Type attribute value, lastModifiedOfDataset, ID attribute value, datasetRev,
     * createNewVersion flag, namedReferencePreference, dataList, datasetFileInfos, and
     * List of NamedReferenceObjectInfos.
     */
    struct DatasetInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The dataset object reference.  This input can be null for create, but it is required
         * for update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * The dataset name attribute value.
         */
        std::string name;
        /**
         * The basis name attribute value.  This is used when the name is null or blank.
         */
        std::string basisName;
        /**
         * The dataset description attribute value.
         */
        std::string description;
        /**
         * The dataset type name.
         */
        std::string type;
        /**
         * Last modified date of the dataset.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfDataset;
        /**
         * The dataset ID attribute value.
         */
        std::string id;
        /**
         * The dataset revision attribute value.
         */
        std::string datasetRev;
        /**
         * Flag that if true signifies a new version of the dataset should be created.
         */
        bool createNewVersion;
        /**
         * The preference name which holds the list of named references to delete from one dataset
         * version to the next.
         */
        std::string namedReferencePreference;
        /**
         * The attribute name and values to set on the dataset.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::NameValueStruct > dataList;
        /**
         * List of dataset file information.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::DatasetFileInfo > datasetFileInfos;
        /**
         * List of dataset named reference information.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::NamedReferenceObjectInfo > namedReferenceObjectInfos;
    };

    /**
     * Dataset information for attaching a dataset to the absolute occurrence.
     */
    struct AbsOccCreateDatasetAttachmentInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The information used to create or update the dataset.
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::DatasetInfo datasetInfo;
        /**
         * The relation type used for the dataset attached to the absolute occurrence.
         */
        std::string relationTypeName;
        /**
         * Flag to specify whether to create, update or attach the specified dataset if the
         * supplied type and relation already exist as an override.
         */
        bool createIfFound;
    };

    /**
     * Form information for the occurrence.
     */
    struct FormInfo
    {
        /**
         * The form object reference.  This input can be null for create, but it is required
         * for update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Form>  formObject;
        /**
         * The form name attribute value.
         */
        std::string name;
        /**
         * The form description attribute value.
         */
        std::string description;
        /**
         * The form type name.
         */
        std::string formType;
        /**
         * The attributes to be set or updated on the form.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::NameValueStruct > attributes;
    };

    /**
     * Form information for attaching a form to the absolute occurrence.
     */
    struct AbsOccCreateFormAttachmentInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The information used to create or update the form.
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::FormInfo formInfo;
        /**
         * The relation type used for the form attached to the absolute occurrence.
         */
        std::string relationTypeName;
        /**
         * Flag to specify whether to create, update or attach the specified form if the supplied
         * type and relation already exist as an override.
         */
        bool createIfFound;
    };

    /**
     * Contains a relationName and secondary objects attached as a override with the given
     * relation.
     */
    struct AbsOccDataGRMExpansionInfo
    {
        /**
         * The relation name found for the override.
         */
        std::string relationName;
        /**
         * The secondary objects attached as a override with the given relation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * Detailed attribute information for the occurrence.
     */
    struct AbsOccDataInfo2
    {
        /**
         * List of attribute information to set as overrides for the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AttributesInfo > overridesToSet;
        /**
         * List of attribute names that will be unset or removed as overrides for the occurrence.
         * For example, to remove a transform override, add the attribute name for the transform
         * to this list.
         */
        std::vector< std::string > overridesToRemove;
        /**
         * Used to set the quantity as required occurrence flag.
         */
        bool asRequired;
        /**
         * Positioning information for the occurrence.
         */
        std::vector< double > occTransform;
        /**
         * List of note information for the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::OccNote > occNotes;
        /**
         * Attachments to add to the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccAttachment2 > attachments;
        /**
         * Attachments to remove from the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccAttachment2 > attachmentsToUnattach;
        /**
         * Dataset attachments to create or update for the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccCreateDatasetAttachmentInfo > datasetAttachments;
        /**
         * Form attachments to create or update for the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccCreateFormAttachmentInfo > formAttachments;
        /**
         * Client ID of the used arrangement created for this absolute occurrence.
         */
        std::string clientIdOfUsedArrangement;
        /**
         * Reference of existing used arrangement for this absolute occurrence.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  usedArr;
        /**
         * No longer used. Bounding Box information is now passed in through <code>datasetAttachments</code>.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::BoundingBoxInfo > boundingBoxInfo;
    };

    /**
     * Contains a filter that needs to be applied when expanding a GRM override and the
     * filter that needs to be applied on the data that is returned based on the qualifier.
     */
    struct AbsOccDataPref
    {
        /**
         * The filter that needs to be applied when expanding a GRM override.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelationAndTypesFilter > relationFilterInfos;
        /**
         * The filter that needs to be applied on the data that is returned based on the qualifier.
         */
        AbsOccDataQualifierFilter qualifierFilter;
    };

    /**
     * Attribute information for the occurrence.
     */
    struct AbsOccInfo2
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * Absolute occurrence object reference.  This input can be null for create.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AbsOccurrence>  absOcc;
        /**
         * Path of CAD occurrence IDs that identify or find the BOM line.
         */
        std::vector< std::string > cadOccIdPath;
        /**
         * Override data to set for the absolute occurrence.
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccDataInfo2 absOccData;
    };

    /**
     * Contains the context BVR for which the overrides are to be retrieved and an upperQualifier.
     */
    struct AbsOccQualifierInfo
    {
        /**
         * The context BVR for which the overrides are to be retrieved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  qualifyingBVR;
        /**
         * Context object of the override (such as Arrangement).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  upperQualifier;
    };

    /**
     * Contains overrideData and GRM override information.
     */
    struct DataOverrideInfo
    {
        /**
         * The AbsOccData object, which has information about qualifier, absolute ocuurence
         * and override information.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AbsOccData>  overrideData;
        /**
         * The GRM override information if the AbsOccData is of type AbsOccGRMAnchor.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccDataGRMExpansionInfo > expandedOverrides;
    };

    /**
     * Contains the list of apn and occurrence thread path that the override are applied.
     * The occurrence thread paths that are returned & dataOverrideInfo.
     */
    struct AbsOccStructureDataInfo
    {
        /**
         * The list of apn and occurrence thread path that the override are applied. The occurrence
         * thread paths that are returned for the given override are in top down order. Since
         * the operation returns unconfigured data, the client needs to match the thread paths
         * in previously expanded context with the returned ones to determine the exact override.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ApnToThreadPathStruct > occThreadPaths;
        /**
         * dataOverrideInfo
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::DataOverrideInfo dataOverrideInfo;
    };

    /**
     * Contains the appearance path node and the occurrence thread path corresponding to
     * the apn.
     */
    struct ApnToThreadPathStruct
    {
        /**
         * The appearance path node
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEAppearancePathNode>  apn;
        /**
         * The occurrence thread path corresponding to the apn
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSOccurrenceThread>  > occThreadPath;
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
     * BoundingboxInfo contains boundingbox information and dataset to which it will be
     * attached.This Dataset member corresponds to the AbsOccAttachment.overrideObject member
     * to which to apply Bounding Box information.
     */
    struct BoundingBoxInfo
    {
        /**
         * Dataset object to apply BoundingBox info to
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * List of xyz coordinate info for Dataset bounding
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::BoundingBox > boundingBoxVector;
    };

    /**
     * Contains basic information for a file to be uploaded to a dataset.
     */
    struct CommitDatasetFileInfo
    {
        /**
         * The dataset object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Flag that if true signifies a new version of the file should be created.
         */
        bool createNewVersion;
        /**
         * List of dataset file ticket information.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::DatasetFileTicketInfo > datasetFileTicketInfos;
    };

    /**
     * Input structure for createOrUpdateAbsoluteStructure.
     */
    struct CreateOrUpdateAbsoluteStructureInfo3
    {
        /**
         * Last modified date of BOM view revision (BVR) under the input <code>contextItemRev</code>.
         * This input is not required.  If this input date is different than the current last
         * modified date and the <code>overwriteForLastModDate</code> preference is false the
         * input will be ignored and processing will continue with the next input.  In this
         * scenario, error 215033 will be returned.  If the dates are different and the <code>overwriteForLastModDate</code>
         * preference is true, processing will continue with the current input.  In this scenario,
         * error 215034 will be returned.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * Item revision object reference of the context assembly to create or validate the
         * occurrence.  This is a required reference input.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextItemRev;
        /**
         * List of absolute occurrence information for the BVR qualified overrides.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccInfo2 > bvrAbsOccInfo;
        /**
         * List of assembly arrangement information for the BVR or arrangement qualified overrides.
         * This input is not required.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AssemblyArrangementInfo > arrAbsOccInfo;
    };

    /**
     * Preference structure for <code>createOrUpdateAbsoluteStructure</code>.
     */
    struct CreateOrUpdateAbsoluteStructurePref3
    {
        /**
         * Flag to check whether the BOM view revision will be updated if the input last modified
         * date is different from the current last modified date of the object in Teamcenter.
         * If false, but the <code>CreateOrUpdateAbsoluteStructureInfo3</code> <code>lastModifiedOfBVR</code>
         * input specified is different than the set modified date, partial error 215033 will
         * be returned.
         */
        bool overwriteForLastModDate;
        /**
         * The attributes that the client is synchronizing when the <code>complete</code> flag
         * is true. These are the attribute names that the client is interested in. Any override
         * properties not in this list will not be deleted when <code>complete</code> is true.
         */
        std::vector< std::string > overridesToSynchronize;
        /**
         * The relation overrides that the client is synchronizing when the <code>complete</code>
         * flag is true.  For instance if a relation filter of <b>IMAN_reference</b> relation
         * name and <code>DirectModel</code> <code>relationTypeName</code> is specified and
         * an override of type is in the existing structure but not specified in the input,
         * then it will be deleted.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelationAndTypesFilter > relationFilters;
        /**
         * Identifies the BOM line attribute that is used to identify relative occurrences to
         * update.
         */
        std::string cadOccIdAttrName;
    };

    /**
     * The response from the <code>createOrUpdateAbsoluteStructure</code> operation.
     */
    struct CreateOrUpdateAbsoluteStructureResponse2
    {
        /**
         * Map of input <code>clientId</code> to the created, updated or found absolute occurrence.
         */
        ClientIdToAbsOccMap2 absOccOutput;
        /**
         * Map of input <code>clientId</code> to the created or updated assembly arrangement.
         */
        ClientIdToAsmArrangementMap asmArrangementOutput;
        /**
         * Map of input client id to the created form.
         */
        ClientIdToFormMap formOutput;
        /**
         * Information for the created or updated dataset.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::DatasetOutput > datasetOutput;
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData</code>
         * with created or updated occurrences, arrangements, datasets or forms. Created forms
         * are added as plain objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains lastModifiedOfBVR,a parent ItemRevision object, list of type RelativeStructureChildInfo
     * and a  boolean value to specify BVR precision.
     */
    struct CreateOrUpdateRelativeStructureInfo3
    {
        /**
         * Last Modified Date of BVR.  Used for comparison with current last modified date for
         * overwrite determination.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * Object reference of the context assembly for create or update of the child occurrence,
         * required input reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * List of type RelativeStructureChildInfo
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::RelativeStructureChildInfo2 > childInfo;
        /**
         * Flag for updating the BVR to precise(true)/imprecise(false)
         */
        bool precise;
    };

    /**
     * Contains overwriteForLastModDate, continueOnError,cadOccIdAttrName and a list of
     * object types.
     */
    struct CreateOrUpdateRelativeStructurePref3
    {
        /**
         * Flag to check whether BVR needs to be modified, if input last modified date is different
         * from actual.
         */
        bool overwriteForLastModDate;
        /**
         * Flag to continue with process on encountering error.
         */
        bool continueOnError;
        /**
         * String representing the occurrence note type which holds the value for the CAD occurrence
         * id or PSOccurrenceThread uid
         */
        std::string cadOccIdAttrName;
        /**
         * List of object types that the client is interested in, such that if the overall structure
         * in Teamcenter contains object types or subtypes not in this list, that structure
         * will not be deleted if this operation is complete.
         */
        std::vector< std::string > objectTypes;
    };

    /**
     * Contains the input for creating a new <b>VariantRule</b> object and to be associated
     * with a <b>ItemRevision</b> object.
     */
    struct CreateVariantRulesInfo
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientID;
        /**
         * Refers to <b>VariantRule</b> object name.
         */
        std::string vruleName;
        /**
         * Refers to <b>VariantRule</b> object description.
         */
        std::string vruleDescription;
        /**
         * The <b>ItemRevision</b> object on which the <b>VariantRule</b> object to be created
         * and attached.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  rev;
        /**
         * The parent object tag to which the <b>VariantRule</b> object is associated. This
         * is optional and if NULL, <b>VariantRule</b> object will be associated with <b>ItemRevision</b>
         * object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * The relation used to associate the <b>VariantRule</b> object to <b>ItemRevision</b>
         * object or parent.
         */
        std::string relation;
        /**
         * Refers to a list of <code>OptionsInfo</code> struct, which has the classic variant
         * option details.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::OptionsInfo > options;
    };

    /**
     * This contains response for <code>createVariantRules</code> operation.
     */
    struct CreateVariantRulesResponse
    {
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the service and error information if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Refers to a list of <code>VariantRulesOutput</code> struct objects, which in turn
         * refers to newly created <b>VariantRule</b> objects.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::VariantRulesOutput > output;
    };

    /**
     * Contains clientId, fileName, namedReferencedName, boolean flags isText, allowReplace,
     * and boundingBoxesAvailable as well as list of BoundingBoxes.
     */
    struct DatasetFileInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The name of file to be uploaded.  Only the file name should be specified; the path
         * should not be included.
         */
        std::string fileName;
        /**
         * The name of the reference to use from the dataset to this file.  This input is required.
         */
        std::string namedReferencedName;
        /**
         * Flag that if true signifies the file is a text file.
         */
        bool isText;
        /**
         * Flag that if true signifies the file can be overwritten.
         */
        bool allowReplace;
        /**
         * Flag that if true signifies bounding box information is available.
         */
        bool boundingBoxesAvailable;
        /**
         * List of bounding boxes, which hold the bounding box coordinate information.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::BoundingBox > boundingBoxes;
    };

    /**
     * Contains basic information for a file to be uploaded to a dataset.
     */
    struct DatasetFileTicketInfo
    {
        /**
         * Member of type DatasetFileInfo.
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::DatasetFileInfo datasetFileInfo;
        /**
         * FMS ticket to use in file upload.
         */
        std::string ticket;
    };

    /**
     * Created or updated dataset and file upload information.
     */
    struct DatasetOutput
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The dataset object reference of the created or updated dataset.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Information for a file to be uploaded to a dataset.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::CommitDatasetFileInfo > commitInfo;
    };

    /**
     * Information to delete relative structures.
     */
    struct DeleteRelativeStructureInfo3
    {
        /**
         * Last modified date of BOM view revision<b> </b>under the input <code>parent</code>.
         * This input is not required.  If this input date is different than the current last
         * modified date and the <code>overwriteForLastModDate</code> input preference is false
         * the input will be ignored and processing will continue with the next input.  In this
         * scenario, error 215033 will be returned.  If the dates are different and the <code>overwriteForLastModDate</code>
         * input preference is true, processing will continue with the current input and the
         * BVR will be modified.  In this scenario, error 215034 will be returned.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * The item revision<b> </b>context assembly from which the child occurrences are to
         * be removed.  This is a required input.  An error will be returned if a valid parent
         * is not specified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * List of identifiers of the relative occurrences to be deleted. This is the CAD occurrence
         * ID or <b>PSOccurrenceThread</b> UID that uniquely identifies the occurrence under
         * a particular context item revision.
         */
        std::vector< std::string > childInfo;
    };

    /**
     * Contains parentBomLines & excludeFilter.
     */
    struct ExpandPSAllLevelsInfo
    {
        /**
         * List of parent bom lines that needs to be expanded
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > parentBomLines;
        /**
         * Filter to exclude the type of BOMLines. Valid values are: None -- Returns all information
         * about the structure. ExcludeOverridden -- Excludes structure or property values that
         * are removed by AbsOccs subsititution. ExcludeICHistory -- Excludes structure (or
         * property values?) that are configured out by ICs. ExcludeGDEs -- Excludes lines that
         * are GDEOccurrences. ExcludeNonImanItemLines -- Excludes any lines that are not ImanItemLines.
         */
        BOMLineFilter2 excludeFilter;
    };

    /**
     * Through this structure, the parent bom line , the object of the bom line and the
     * objects attached to the bom line object are returned.
     */
    struct ExpandPSParentData
    {
        /**
         * BOMline object reference of the parent
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Object that the parent represents
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectOfBOMLine;
        /**
         * List of object references attached to parent with given relation
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSRelatedObjectInfo > parentRelatedObjects;
    };

    /**
     * Structure containing ExpandPSParentData2 corresponding to the parent and a list of
     * ExpandPSData of the children
     */
    struct ExpandPSAllLevelsOutput
    {
        /**
         * ExpandPSParentData member
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSParentData parent;
        /**
         * List of ExpandPSData children found for this parent.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSData > children;
    };

    /**
     * More than one filtering criteria can be specified using this which is nothing but
     * a list of  RelationAndTypesFilter
     */
    struct ExpandPSAllLevelsPref
    {
        /**
         * Flag to check for expanding the item revision further
         */
        bool expItemRev;
        /**
         * List of the relation name and the types of objects of the given relation to return
         * along with the children
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::RelationAndTypesFilter > info;
        /**
         * List of Occurrence Types that needs to be included when the expansion of the BOM
         * takes place.
         */
        std::vector< std::string > includeOccurrenceTypes;
        /**
         * List of Occurrence Types that needs to be excluded when the expansion of the BOM
         * takes place.
         */
        std::vector< std::string > excludeOccurrenceTypes;
    };

    /**
     * A list of ExpandPSAllLevelsOutput2 so that a set of parent BOMLines can be expanded.
     */
    struct ExpandPSAllLevelsResponse2
    {
        /**
         * List of ExpandPSAllLevelsOutput1 which contains ExpandPSParentData and list of ExpandPSData
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSAllLevelsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. For this service, all objects
         * are returned to the plain objects group. Error information will also be returned
         * mapped to input object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Through this structure, the child bom line , the object of the bom line and the object
     * attached to the bom line object are returned.
     */
    struct ExpandPSData
    {
        /**
         * BOMline object reference of the children
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Object that the child represents
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectOfBOMLine;
        /**
         * List of objects attached to children with given relation
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSRelatedObjectInfo > relatedObjects;
    };

    /**
     * This structure is used to identify the reference object corresponding to the named
     * reference.
     */
    struct ExpandPSNamedReferenceInfo
    {
        /**
         * type of reference object.
         */
        std::string namedReferenceType;
        /**
         * name of reference object.
         */
        std::string namedReferenceName;
        /**
         * Object reference corresponding to the named reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  referenceObject;
        /**
         * FMS ticket used to retrieve the file in cases where referenceObject is a file.
         */
        std::string fileTicket;
    };

    /**
     * Contains the parent BOM lines whose children are to be expanded.
     */
    struct ExpandPSOneLevelInfo
    {
        /**
         * List of parent BOM lines to be expanded.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > parentBomLines;
        /**
         * A filter used to identify the type of BOM lines to exclude. Valid values are: None
         * -- Returns all information about the structure. ExcludeOverridden -- Excludes structure
         * or property values that are removed by AbsOccs subsititution. ExcludeICHistory --
         * Excludes structure that are configured out by ICs. ExcludeGDEs -- Excludes lines
         * that are GDEOccurrences. ExcludeImanItemLines -- Excludes lines that are ImanItemLines.
         */
        BOMLineFilter2 excludeFilter;
    };

    /**
     * Used to return a parent bomline and its related data, and a list of bomlines and
     * related data that share that parent.
     */
    struct ExpandPSOneLevelOutput
    {
        /**
         * parent data member
         */
        Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSParentData parent;
        /**
         * list of children returned for the parent
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSData > children;
    };

    /**
     * Contains a list of filtering criteria (RelationAndTypesFilter) used in a product
     * structure expand operation.
     */
    struct ExpandPSOneLevelPref
    {
        /**
         * Flag indicating whether to return related object(s).
         */
        bool expItemRev;
        /**
         * List of the relation name and the related object types to return along with the children.
         * If no RelationAndTypesFilter is supplied (info is empty), and expItemRev is true,
         * then all related object types are to be accepted.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::RelationAndTypesFilter > info;
        /**
         * List of Occurrence Types that needs to be included when the expansion of the BOM
         * takes place.
         */
        std::vector< std::string > includeOccurrenceTypes;
        /**
         * List of Occurrence Types that needs to be excluded when the expansion of the BOM
         * takes place.
         */
        std::vector< std::string > excludeOccurrenceTypes;
    };

    /**
     * Is the response object returned in a product structure one level expand operation.
     */
    struct ExpandPSOneLevelResponse2
    {
        /**
         * List of ExpandPSOneLevelOutput structures.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSOneLevelOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. For this service, all objects
         * are returned to the plain objects group. Error information will also be returned.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure associates a related object, named references and reference objects.
     */
    struct ExpandPSRelatedObjectInfo
    {
        /**
         * The resulting related object by following a relation specified in the ExpandPSOneLevelPref
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  relatedObject;
        /**
         * List of named reference and reference object of relatedObject.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSNamedReferenceInfo > namedRefList;
    };

    /**
     * Contains list of overrides and serviceData.
     */
    struct GetAbsoluteStructureDataResponse
    {
        /**
         * List of overrides
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccStructureDataInfo > overrides;
        /**
         * Contains populated plain object list and partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains clientId, Object reference, namedReferenceName, typeName and dataNameValuePairs.
     */
    struct NamedReferenceObjectInfo
    {
        /**
         * Unique identifier to track the related object.
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
         * List of NameValueStruct.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::NameValueStruct > dataNameValuePairs;
    };

    /**
     * Contains name and list of value strings.
     */
    struct NameValueStruct
    {
        /**
         * Attribute name to set
         */
        std::string name;
        /**
         * Attribute value to set
         */
        std::vector< std::string > values;
    };

    /**
     * This contains classic variant option information.
     */
    struct OptionsInfo
    {
        /**
         * Refers to classic variant option name.
         */
        std::string optionName;
        /**
         * Refers to classic variant option value.
         */
        std::string optionValue;
        /**
         * Refers to the <b>ItemRevision</b> object on which the classic variant options are
         * defined.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  assocRev;
    };

    /**
     * This contains the list of <b>BOMWindow</b> objects and corresponding corresponding
     * <b>RevisionRule</b> object and <b>VariantRule</b> object or <b>StoredOptionSet</b>
     * object information.
     */
    struct ReconfigureBOMWindowsInfo
    {
        /**
         * Used to track the object(s) created
         */
        std::string clientID;
        /**
         * The <b>BOMWindow</b> object which needs to be reconfigured.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
        /**
         * Refers to an <b>VariantRule</b> object or <b>StoredOptionSet</b> object information.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectForConfigure;
        /**
         * Refers to an <code>RevisionRuleConfigInfo</code> struct object.
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::RevisionRuleConfigInfo revRuleConfigInfo;
    };

    /**
     * Contains updated BOMWindow along with the corresponding clientIds.
     */
    struct ReconfigureBOMWindowsOutput
    {
        /**
         * clientID
         */
        std::string clientID;
        /**
         * The reconfigured BOMWindow
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
    };

    /**
     * This contains the response for the <code>reconfigureBOMWindows</code> operation.
     */
    struct ReconfigureBOMWindowsResponse
    {
        /**
         * This contains list of <code>ReconfigureBOMWindowsOutput</code> struct object, which
         * returns the <b>BOMWindow</b> which has updated configuration.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ReconfigureBOMWindowsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the service and error information if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains a related object type and the list of its named references
     * to be processed.
     */
    struct RelatedObjectTypeAndNamedRefs
    {
        /**
         * objectTypeName
         */
        std::string objectTypeName;
        /**
         * namedReferenceNames
         */
        std::vector< std::string > namedReferenceNames;
    };

    /**
     * This structure contains a relation name and a list of related object types and its
     * named references (RelatedObjectTypeAndNamedReferences).  Together they are used to
     * filter objects passed back in a product structure expand operation.
     */
    struct RelationAndTypesFilter
    {
        /**
         * Relation name.
         */
        std::string relationName;
        /**
         * List of related object types and named references.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::RelatedObjectTypeAndNamedRefs > relatedObjAndNamedRefs;
        /**
         * An enumeration used to identify how named references will be processed. Valid values
         * are: NoNamedRefs -- No named references are to be processed. The input RelatedObjectTypeAndNamedRefs
         * will be ignored. AllNamedRefs -- All named references are to be processed. The input
         * RelatedObjectTypeAndNamedRefs will be ignored. UseNamedRefsList -- Only the named
         * references listed in the input RelatedObjectTypeAndNamedRefs struct are processed.
         * PreferredJT -- Specialized code for selecting which named references to process is
         * executed. This is intended for selecting the most appropriate JT files for visualization
         * purposes. If related object is a DirectModel, RelatedObjectTypeAndNamedReferences
         * contents will be ignored and only the preferred JT is returned. If related object
         * is not Direct Model, named reference expansion will proceed as though namedRefHandler
         * is UseNamedRefsList.
         */
        NamedRefHandler namedRefHandler;
    };

    /**
     * Contains information about the child structure.
     */
    struct RelativeStructureChildInfo2
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with the output or any
         * returned errors.
         */
        std::string clientId;
        /**
         * The CAD occurrence ID or <b>PSOccurrenceThread</b> UID is used to uniquely identify
         * the occurrence under a particular context item revision or General Design Element
         * (GDE) for update.  The <code>cadOccId</code> can be null for create.  A valid <code>cadOccId</code>
         * must be passed when this operation is called with the <code>RelativeStructureParentInfo</code>
         * <code>complete</code> input set to true. If a valid <code>cadOccId</code> is not
         * supplied when <code>complete</code> is set to true, this operation creates a new
         * occurrence and any data associated against an existing occurrence is removed/lost.
         * This parameter depends on the <code>CreateOrUpdateRelativeStructurePref</code> <code>cadOccIdAttrName</code>
         * preference for finding the existing BOM line.
         */
        std::string cadOccId;
        /**
         * The child object for the occurrence creation.  Only item revision and General Design
         * Element (GDE) are supported.  If the child occurrence exists, but the input child
         * object is different than the existing child object, the existing child will be replaced
         * by the input child.  Existing children are found referencing the occurrence found
         * by the <code>cadOccId</code> input.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  child;
        /**
         * The property information for this occurrence.
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelOccInfo occInfo;
    };

    /**
     * Contains the response for the saveBOMWindows operation.
     */
    struct SaveBOMWindowsResponse
    {
        /**
         * Any failures will be returned in the ServiceData list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This contains output data for <code>createVariantRules</code> operation.
     */
    struct VariantRulesOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * Refers to newly created <b>VariantRule</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  vrule;
    };




    /**
     * This operation creates or updates absolute occurrences on an existing relative structure.
     * The objects created or updated can include an absolute occurrence, assembly arrangement
     * and datasets and are added to the <code>ServiceData </code>as created or updated
     * objects.  Created forms are added as plain objects and updated forms are added as
     * updated objects.
     * <br>
     * <br>
     * Before creating the absolute occurrence or assembly arrangement, this operation will
     * check whether either already exists.  If the occurrence or arrangement exists but
     * the input attribute values differ from those already set, an attempt is made to update
     * the values.
     * <br>
     * This operation assumes the input is in a bottom up format such that if any failures
     * occur, the structure that is updated will still be consumable.  For example:
     * <br>
     * <br>
     * Parent assembly A and occurrence C are input into this operation along with subassembly
     * B and occurrence D.  If occurrence D is updated successfully on subassembly B but
     * an error occurs during the update of occurrence C on assembly A, the client can still
     * access subassembly B.
     * <br>
     * <br>
     * For objects of type dataset and form, this operation can create or update a new object
     * instance and attach it as an override on the absolute occurrence.  For all object
     * types, existing objects can be attached or removed as an override on the absolute
     * occurrence.
     * <br>
     * <br>
     * To help reduce the client overhead of sending all override information during a complete
     * synchronization and avoid accidental removal of overrides coming from other clients,
     * this operation allows the client to provide only the attributes it is interested
     * in syncing when the <code>complete</code> flag is set to true.  For more information
     * on complete synchronization, see the description for the <code>complete</code> input
     * parameter.
     * <br>
     * <br>
     * One parent context object is processed at a time and it is assumed that all edits
     * for a given parent context come in as one set of input.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1:
     * <br>
     * <br>
     * User adds an override to an existing assembly to create an absolute occurrence.
     * <br>
     * <br>
     * For this operation, the assembly is passed in as the <code>contextItemRev</code>
     * and the override, such as new transformation data to position a component in an assembly,
     * is passed in as the absolute occurrence.  The absolute occurrence is created and
     * a map of the input <code>clientID</code> to <b>AbsOccurrence</b> is returned in <code>absOccOutput</code>
     * and the occurrence is returned as created objects in <code>ServiceData</code>.
     * <br>
     * <br>
     * Use case 2:
     * <br>
     * <br>
     * User adds an override with a new dataset to an existing assembly to create an absolute
     * occurrence with an attached dataset.
     * <br>
     * <br>
     * For this operation, the assembly is passed in as the <code>contextItemRev</code>
     * and the override with information for the new dataset is passed in as the absolute
     * occurrence information.  The absolute occurrence and new dataset are created and
     * a map of the input <code>clientID</code> to <b>AbsOccurrence</b> is returned in <code>absOccOutput</code>
     * and the created dataset is returned in <code>datasetOutput</code>.  The occurrence
     * and dataset are returned as created objects in <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateParts, createOrUpdateRelativeStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param absOccInfos
     *        List of information related to the absolute occurrences that need to be created or
     *        updated.
     *
     * @param bomViewTypeName
     *        The BOM view (BV) type used to find the existing BOM view.
     *
     * @param complete
     *        Flag that if true signifies that the absolute occurrences represented in <code>absOccInfos</code>
     *        are the full representation of all the overrides under the input <code>contextItemRev</code>.
     *        Any other overrides that exist in Teamcenter but are not represented in the input
     *        will be removed.  This may also be referred to a complete sync of the occurrence.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         A map of input client IDs to <code>AbsOccurrence</code>, a map of input client IDs
     *         to <code>AssemblyArrangement</code>, a map of client IDs to form and a list of <code>DatasetOutput</code>,
     *         which contains datasets created by this operation.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215003: The assembly arrangement to use is not created yet.
     *         </li>
     *         <li type="disc">215004: The BOM line for the absolute occurrence was not found.
     *         </li>
     *         <li type="disc">215005: The BOM view revision (BVR) is not checked out by the current
     *         user.
     *         </li>
     *         <li type="disc">215006: The BOM view revision is checked out by another user.
     *         </li>
     *         <li type="disc">215008: A duplicate parent for the <code>contextItemRev</code> input
     *         already exists.
     *         </li>
     *         <li type="disc">215042: The Item was not found for the input <code>contextItemRev</code>.
     *         </li>
     *         <li type="disc">215043: The BOM view revision was not found for the input <code>contextItemRev</code>.
     *         </li>
     *         <li type="disc">215140: The occurrence ID path to locate the occurrence was not specified.
     *         </li>
     *         <li type="disc">215142: An override of the specified type already exists.
     *         </li>
     *         <li type="disc">215033: The input last modified date differs from actual.
     *         </li>
     *         <li type="disc">215034: The dataset or BVR was modified even when the input last
     *         modified dates was different than the current last modified data.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if an invalid BOM view type is
     *           specified in <code>bomViewTypeName</code>.
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateOrUpdateAbsoluteStructureResponse2 createOrUpdateAbsoluteStructure ( const std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateOrUpdateAbsoluteStructureInfo3 >& absOccInfos,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateOrUpdateAbsoluteStructurePref3&  pref ) = 0;

    /**
     * This is the overloaded function for Cad::_2007_12::StructureManagement::createOrUpdateRelativeStructure.
     * It differs by allowing the parent member of the structure CreateOrUpdateRelativeStructureInfo
     * to be a ModelObject instead of a strongly typed Item Revision object and makes the
     * child member of the RelativeStructureChildInfo to a ModelObject instead of strongly
     * typed Item Revision. This is to allow structures with GDE elements to be edited with
     * this service. Create or update the relative structure objects and relations for the
     * input model. The service first attempts to check for the presence of duplicate context
     * objects and then validate the existence of the structure to be created. If any of
     * the objects exist but the input attribute values that differ from those already set,
     * an attempt is made to update the values if possible. This service assumes the input
     * is in a bottom-up format such that if any failures occur, the structure that is created
     * will be consistent. No attempt is made in the service to rearrange the input and
     * process it in the correct order. As we process one parent context object at one time,
     * it is assumed that all edits for a given parent context come in as one set of input.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List of input structures that defines all the occurrence for a given parent
     *
     * @param bomViewTypeName
     *        Type of BOMView to create
     *
     * @param complete
     *        Flag that if true signifies that the structure represented in the input is the full
     *        representation of the structure under the input parent. Any other structure relations
     *        that exist in Teamcenter but are not represented here will be removed.
     *
     * @param pref
     *        Preference structure specific for this service
     *
     * @return
     *         Output is an explicit response consisting of a map of input clientId string to created
     *         or updated or found occurrence thread reference.
     *
     *
     * @exception ServiceException
     *           Service exceptions are thrown for the following error situations:
     *           <br>
     *           <br>
     *           215005: The BOM view revision (BVR) is not checked out by the current user.
     *           <br>
     *           215006: The BOM view revision is checked out by another user.
     *           <br>
     *           215009: The object type name specified in the input preference does not exist.
     *           <br>
     *           215010: The input CAD occurrence identifier does not correspond to a valid BOM line.
     *           This is an error when the complete input is false.
     *           <br>
     *           215033: The input last modified date differs from actual.
     *           <br>
     *           215034: The dataset or BVR was modified even when the input last modified dates was
     *           different than the current last modified data.
     *           <br>
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateOrUpdateRelativeStructureInfo3 >& inputs,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateOrUpdateRelativeStructurePref3&  pref ) = 0;

    /**
     * This operation deletes one or more first level children of a parent assembly.  The
     * children, or occurrences, to be deleted are specified by the CAD occurrence ID or
     * <b>PSOccurrenceThread</b> UID.  The last modified date of the BOM view revision (BVR)
     * can also be specified for comparison against the last modified date in Teamcenter
     * to ensure the occurrence has not changed outside of this client context and control
     * if the BVR is actually modified and the occurrence deleted by this operation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User deletes an existing relative occurrence from an existing assembly.
     * <br>
     * <br>
     * For this operation, the assembly is passed in as the parent and the occurrence ID
     * is passed in as the child information.  The relative occurrence is removed from the
     * parent assembly and the ID of the deleted occurrence is added to the <b>ServiceData</b>
     * list of deleted objects.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateRelativeStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List of input structures that specify the parent and first level children to be deleted.
     *
     * @param bomViewTypeName
     *        The BOM view<b> </b>(BV) type used to find the existing BOM view.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         <code>ServiceData</code><b> </b>which contains the UIDs of any deleted occurrences.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215005: The BOM view revision is not checked out by the current user.
     *         </li>
     *         <li type="disc">215006: The BOM view revision is checked out by another user.
     *         </li>
     *         <li type="disc">215040: An invalid item revision tag was specified for the parent
     *         input.
     *         </li>
     *         <li type="disc">215041: The specified parent is not an item revision.
     *         </li>
     *         <li type="disc">215042: The item was not found for the input parent.
     *         </li>
     *         <li type="disc">215043: The BOM view revision was not found for the input parent.
     *         </li>
     *         <li type="disc">215046: No occurrences were specified to be deleted.
     *         </li>
     *         <li type="disc">215047: No occurrences exist on the parent to be deleted.
     *         </li>
     *         <li type="disc">215048: The child occurrence was not found for delete.
     *         </li>
     *         <li type="disc">215033: The input last modified date differs from actual.
     *         </li>
     *         <li type="disc">215034: The dataset or BOM view revision was modified even when the
     *         input last modified dates was different than the current last modified data.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service<b> </b>Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if an invalid BOM view
     *           type is specified in <code>bomViewTypeName</code>.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteRelativeStructureResponse deleteRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::DeleteRelativeStructureInfo3 >& inputs,
        const std::string&  bomViewTypeName,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteRelativeStructurePref2&  pref ) = 0;

    /**
     * This is the overloaded function for Cad::_2007_01::StructureManagement::expandPSAllLevels.
     * The member itemRevOfBOMLine of ExpandPSData and ExpandPSParentData is renamed as
     * objectOfBOMLine and its type is changed from Item Revision to ModelObject. Also the
     * datasets and parentDatasets member of ExpandPSData and ExpandPSParentData structures
     * respectively are renamed to relatedObjects and type changed to ModelObject instead
     * of Dataset. This is to support structures with GDE elements to be returned from the
     * expansion. Finds the children at all levels given parent BOMLines. Also if required
     * gets the objects of given type and relation that are attached to the parent and children.
     * In addition to the above, the expansion of the Product Structure can be filtered
     * for a given occurrence type/s which can be included and/or excluded from the expansion.
     * In addition to the above the following additional functionality has been added: 1.
     * The operation is not limited to return related objects of dataset type only.  Expansion
     * of attached objects to the BOM line object is determined by a filtering mechanism
     * where the criteria is set by: relation name, related object type, and named references.
     * 2.  This operation allows for expansion to reference object associated to a named
     * reference.  Typically this is a file.  An FMS ticket will be returned to provide
     * access to this file. 3.  Where a named reference points to a file, this operation
     * allows for specific logic in choosing which files are returned.  This is determined
     * by the input parameter NamedRefHandler (included in the info object).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        Input of ExpandPSAllLevelsInfo which contains parent bom lines and a filter of the
     *        type of bom lines to exclude.
     *
     * @param pref
     *        of a ExpandPSAllLevelsPref which contains a list of relation name and the types of
     *        objects of the given relation to return along with the children.
     *
     * @return
     *         list of ExpandPSData which contains parent BOMLines, chilrens and object of given
     *         type and relation attached to them. All objects found are added to the ServiceData
     *         list of plain objects. Objects that fail the expansion are returned in the list of
     *         partial errors in the ServiceData
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSAllLevelsResponse2 expandPSAllLevels ( const Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSAllLevelsInfo&  info,
        const Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSAllLevelsPref&  pref ) = 0;

    /**
     * This operation will expand one level of a product structure and return the resulting
     * BOM lines. If required, it will return objects of a given relation and type that
     * are attached to the parent and child BOM lines. Additionally, if specified in the
     * preference, this will return only BOM Lines of a given particular occurrence type
     * and exclude occurrence types of a given type. This operation differs from the operation
     * Teamcenter.Soa.Cad._2007_01.StructureManagement.expandPSOneLevel in the following
     * ways: 1.  The operation is not limited to return related objects of dataset type
     * only.  Expansion of attached objects to the BOM line object is determined by a filtering
     * mechanism where the criteria is set by: relation name, related object type, and named
     * references. 2.  This operation allows for expansion to reference object associated
     * to a named reference.  Typically this is a file.  An FMS ticket will be returned
     * to provide access to this file. 3.  Where a named reference points to a file, this
     * operation allows for specific logic in choosing which files are returned.  This is
     * determined by the input parameter NamedRefHandler (included in the info object).
     * 4.  The resulting Product Structure expansion can be limited to a certain Occurrence
     * Types.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        The list of parent BOM lines to expand, a filter that describes what child BOM lines
     *        are excluded in the expansion, and a filter that describes what named references
     *        are included in the expansion.
     *
     * @param pref
     *        A flag for expanding BOM line object further and a list describing the relation name,
     *        related object type and named references that help define the expansion criteria.
     *        Also, this preference can accommodate  a list of occurrence types to include and
     *        exclude BOM Lines from the Product Structure expansion.
     *
     * @return
     *         The response contains a structure of parent BOM line and its related data, and a
     *         list of child BOM lines and related data. All objects found are added to the ServiceData
     *         list of plain objects. Objects that fail the expansion are returned in the list of
     *         partial errors in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSOneLevelResponse2 expandPSOneLevel ( const Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSOneLevelInfo&  info,
        const Teamcenter::Services::Cad::_2008_06::Structuremanagement::ExpandPSOneLevelPref&  pref ) = 0;

    /**
     * This operation retrieves the absolute occurrence override information for the given
     * qualifier. The input accepts the relation override that needs to be expanded. In
     * case of finding the overrides based on the used arrangement within the structure,
     * the client is expected to provide bvr of sub assembly in the input. ParentBVR |--(Arr1)
     * |--(Arr2) | |________childBVR1 |           |-----(Arr3) |           |-----(Arr4)
     * |           |_____________childBVR2 |                                    |----(Arr5)
     * |                                    |----(Arr6) |_____ childBVR2 |----(Arr5) |----(Arr6)
     * If Arr1 uses Arr3 which in turn uses Arr5, to determine the overrides by Arr3 and
     * Arr5 qualifier the client is expected to send childbvr1 and childbvr2 as inputs along
     * with the parentBVR.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param absOccDataQualInfos
     *        List of qualifying information for overrides
     *
     * @param absOccDataPref
     *        Preference on which relation overrides to expand and the preferred objects of type
     *        to return
     *
     * @return
     *         Contains the  overrides and service data information.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::GetAbsoluteStructureDataResponse getAbsoluteStructureData ( const std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccQualifierInfo >& absOccDataQualInfos,
        const Teamcenter::Services::Cad::_2008_06::Structuremanagement::AbsOccDataPref&  absOccDataPref ) = 0;

    /**
     * This operation creates the saved <b>VariantRule</b> objects for classic variant options.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to create <b>VariantRule</b> object and save them, which can
     * be used later for BOM variant configuration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param input
     *        This has the list of <code>CreateVariantRulesInfo</code> struct, which are used to
     *        create a new <b>VariantRule</b> object.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">215255 Unable to associate VariantRule: input VariantRule name is
     *         empty
     *         </li>
     *         <li type="disc">215256 Unable to associate VariantRule: input ItemRevision is null.
     *         </li>
     *         <li type="disc">215251 Unable to create VariantRule
     *         </li>
     *         <li type="disc">215253 Unable to associate VariantRule: input relation type name
     *         is empty.
     *         </li>
     *         <li type="disc">215254 Unable to associate VariantRule to given parent or ItemRevision.
     *         </li>
     *         <li type="disc">58007 Invalid BOM Window
     *         </li>
     *         <li type="disc">46037 Cannot find option %1$
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateVariantRulesResponse createVariantRules ( const std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::CreateVariantRulesInfo >& input ) = 0;

    /**
     * This operation takes a list of <b>BOMWindow</b> objects and updates the contents
     * of the windows (i.e. configuration) by applying the supplied <b>RevisionRule</b>
     * and variant configuration information.  If the <code>RevisionRuleEntryProps</code>::<code>unitNo</code>
     * is set to -1 then it considers default unitNo or use the input <b>RevisionRule</b>
     * object with no changes. If no value specified for <code>RevisionRuleEntryProps</code>::<code>unitNo</code>,
     * then the input <b>RevisionRule</b> object used as modified/transient rule with unitNo
     * as 0.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to reconfigure the <b>BOMWindow</b> with new or modified <b>RevisionRule</b>
     * and <b>VariantRule</b> information.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param info
     *        This contains a list of <code>ReconfigureBOMWindowsInfo</code> struct objects which
     *        has <b>BOMWindow</b> objects and corresponding <b>RevisionRule</b> object and <b>VariantRule</b>
     *        object or <b>StoredOptionSet</b> object information.
     *
     * @return
     *         A structure with a list of reconfigured <b>BOMWindow</b> objects and the Service
     *         Data object. The <code>serviceData</code> returned with objects in case of success
     *         scenario. In case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::ReconfigureBOMWindowsResponse reconfigureBOMWindows ( const std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::ReconfigureBOMWindowsInfo >& info ) = 0;

    /**
     * This operation can be used by a client developer to save any modifications made to
     * a Teamcenter product structure through its runtime artifacts. A Teamcenter product
     * structure is a persistent parent child composition and clients often deal with runtime
     * artifacts of this persistent model. The runtime artifacts are primarily represented
     * by <b>BOMLine</b> business objects and <b>BOMWindow</b> business objects along with
     * the <b>BOMLine</b> properties. Modifications to the product structure are typically
     * bulked up on the client and tracked through the <b>BOMWindow</b>. Once it is established
     * that changes to a product structure can be saved this operation can be called passing
     * in a handle to the <b>BOMWindows</b> that need to be saved.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In a typical usage of the saveBOMWindows operation, a client developer already has
     * a Teamcenter product structure loaded with the runtime artifacts created. This means
     * that the client developer has/creates handles to a <b>BOMWindow</b>, and <b>BOMLine</b>
     * business objects that are part of that <b>BOMWindow</b>. Given this pre disposition,
     * typical interaction with the client may involve addition of a new <b>BOMLine</b>
     * or removal of a <b>BOMLine</b>, creation/removal of In Structure associations etc.
     * In such cases, the changes to the product structure are tracked on the <b>BOMWindow</b>
     * and when the changes are ready to be persisted, the client developer calls the saveBOMWindows
     * operation.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateRelativeStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param bomWindows
     *        References to the <b>BOMWindow</b> business objects that need to be saved after structure
     *        modifications.
     *
     * @return
     *         This operation returns a SaveBOMWindowsResponse. The SaveBOMWindowsResponse structure
     *         contains the ServiceData. The successfully saved BOMWindow business objects are added
     *         to the updated list of the service data while any errors encountered are stored as
     *         part of the partial errors of the Service Data.
     *         <br>
     *         <br>
     *         Exceptions are returned as part of the ServiceData member of the SaveBOMWindowsResponse.
     *         Typical error scenarios encountered are:
     *         <br>
     *         <br>
     *         a) One or more BOM Windows passed in for save is a null input.
     *         <br>
     *         <ul>
     *         <li type="disc">215257  Unable to save BOMWindow: input BOMWindow is null.
     *         </li>
     *         </ul>
     *         <br>
     *         b) One of the BOM Window inputs passed in for save is not really a BOM Window type.
     *         <br>
     *         <ul>
     *         <li type="disc">46001    Invalid tag received by BOM Module.
     *         </li>
     *         </ul>
     *         <br>
     *         c) A problem occurred while performing the actual save operation although the input
     *         was valid
     *         <br>
     *         <ul>
     *         <li type="disc">215166  Failed to save BOMWindow.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Structuremanagement::SaveBOMWindowsResponse saveBOMWindows ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  >& bomWindows ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

