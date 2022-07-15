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

#ifndef TEAMCENTER_SERVICES_CAD__2007_01_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2007_01_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/AbsOccurrence.hxx>
#include <teamcenter/soa/client/model/AssemblyArrangement.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/CFMOverrideEntry.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/PSBOMView.hxx>
#include <teamcenter/soa/client/model/PSOccurrenceThread.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
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
            namespace _2007_01
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct AbsOccAttachment;
    struct AbsOccDataInfo;
    struct AbsOccInfo;
    struct AssemblyArrangementInfo;
    struct AttributesInfo;
    struct CloseBOMWindowsResponse;
    struct RevisionRuleEntryProps;
    struct RevisionRuleConfigInfo;
    struct CreateBOMWindowsInfo;
    struct CreateBOMWindowsOutput;
    struct CreateBOMWindowsResponse;
    struct CreateOrUpdateAbsoluteStructureInfo;
    struct CreateOrUpdateAbsoluteStructurePref;
    struct CreateOrUpdateAbsoluteStructureResponse;
    struct CreateOrUpdateRelativeStructureInfo;
    struct CreateOrUpdateRelativeStructurePref;
    struct CreateOrUpdateRelativeStructureResponse;
    struct DeleteAssemblyArrangementsInfo;
    struct DeleteAssemblyArrangementsResponse;
    struct DeleteRelativeStructureInfo;
    struct DeleteRelativeStructurePref;
    struct DeleteRelativeStructureResponse;
    struct ExpandPSAllLevelsInfo;
    struct ExpandPSParentData;
    struct ExpandPSAllLevelsOutput;
    struct ExpandPSAllLevelsPref;
    struct ExpandPSAllLevelsResponse;
    struct ExpandPSData;
    struct ExpandPSOneLevelInfo;
    struct ExpandPSOneLevelOutput;
    struct ExpandPSOneLevelPref;
    struct ExpandPSOneLevelResponse;
    struct GetRevisionRulesResponse;
    struct GetVariantRulesResponse;
    struct OccNote;
    struct OverrideInfo;
    struct RelationAndTypesFilter;
    struct RelOccInfo;
    struct RelativeStructureChildInfo;
    struct RevisionRuleInfo;

    /**
     * BOMLineFilter
     */
    enum BOMLineFilter{ BOMLineFilterNone,
                 ExcludeOverridden,
                 ExcludeICHistory,
                 ExcludeGDEs,
                 ExcludeNonImanItemLines
                 };

    /**
     * ClientIdToAbsOccMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AbsOccurrence>  > ClientIdToAbsOccMap;

    /**
     * ClientIdToAsmArrMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  > ClientIdToAsmArrMap;

    /**
     * ClientIdToPSOccurrenceThreadMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSOccurrenceThread>  > ClientIdToPSOccurrenceThreadMap;

    /**
     * ConfigureAttrStatusMap
     */
    typedef std::map< std::string, bool > ConfigureAttrStatusMap;

    /**
     * ItemRevisionToVariantRulesMap
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  > > ItemRevisionToVariantRulesMap;

    /**
     * Contains a dataset object reference with the JT override data and a relationTypeName
     * to relate AbsOccData to Dataset.
     */
    struct AbsOccAttachment
    {
        /**
         * Dataset object reference with the JT override data
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Relation/property to relate AbsOccData to Dataset
         */
        std::string relationTypeName;
    };

    /**
     * Contains list of AttributesInfo for overrides to set, list of attribute names to
     * unset/remove the overrides, a boolean flag, occTransform which contains the positioning
     * information for the occurrence, list of note information for the occurrence, list
     * of AbsOccAttachment for the attachments, list of the AbsOccAttachment to unattach,
     * client id of the used arrangement for this absolute occurrence and a reference of
     * used arrangement for this absolute occurrence.
     */
    struct AbsOccDataInfo
    {
        /**
         * List of AttributesInfo for overrides to set
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AttributesInfo > overridesToSet;
        /**
         * List of attribute names to unset/remove the overrides for on the occurrence, for
         * example to remove a transform override, add the attribute name for the transform
         * to this list.
         */
        std::vector< std::string > overridesToRemove;
        /**
         * Used to the set the quantity as required occurrence flag
         */
        bool asRequired;
        /**
         * Positioning information for the occurrence
         */
        std::vector< double > occTransform;
        /**
         * List of note information for the occurrence
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::OccNote > occNotes;
        /**
         * List of AbsOccAttachment for the attachments
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AbsOccAttachment > attachments;
        /**
         * List of the AbsOccAttachment to unattach
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AbsOccAttachment > attachmentsToUnattach;
        /**
         * Client id of the used arrangement for this absolute occurrence, if arrangement is
         * yet to be created
         */
        std::string clientIdOfUsedArrangement;
        /**
         * Reference of used arrangement for this absolute occurrence if arrangement has already
         * been created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  usedArr;
    };

    /**
     * Attribute information for the occurrence
     */
    struct AbsOccInfo
    {
        /**
         * Identifier that helps the client track the object(s) created
         */
        std::string clientId;
        /**
         * AbsOccurrence object reference , may be null for create
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AbsOccurrence>  absOcc;
        /**
         * List of IDs of the cad occurrences
         */
        std::vector< std::string > cadOccIdPath;
        /**
         * Member of AbsOccDataInfo
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::AbsOccDataInfo absOccData;
    };

    /**
     * Structure with arrangement qualified override information for the occurrence.
     */
    struct AssemblyArrangementInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The assembly arrangement object reference.  This input can be null for create, but
         * it is required for update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  arrangement;
        /**
         * The name of the arrangement.
         */
        std::string name;
        /**
         * Flag to specify whether <code>arrangement</code> is the default arrangement.
         */
        bool isDefault;
        /**
         * The arrangement description.
         */
        std::string description;
        /**
         * The UID required for create.
         */
        std::string externalUid;
        /**
         * List of absolute occurrence information for the BOM view revision qualified overrides.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AbsOccInfo > absOccInfo;
    };

    /**
     * Name and value data to be set as attributes on the related object.
     */
    struct AttributesInfo
    {
        /**
         * The attribute name.
         */
        std::string name;
        /**
         * The value to set for the attribute.
         */
        std::string value;
    };

    /**
     * Contains a serviceData containing objects that were deleted.
     */
    struct CloseBOMWindowsResponse
    {
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. For this service, ServiceData
         * contains BOM window and top line.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This contains information about the <b>RevisionRule</b> Entry Properties.
     */
    struct RevisionRuleEntryProps
    {
        /**
         * Refers to the unit number of <b>RevisionRule</b> object.
         */
        int unitNo;
        /**
         * Refers to the date of <b>RevisionRule</b> object.
         */
        Teamcenter::Soa::Common::DateTime date;
        /**
         * Refers to a flag to indicate that the date is today on <b>RevisionRule</b> object.
         */
        bool today;
        /**
         * Refers to <b>Item</b> and indicates end item for <b>RevisionRule</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  endItem;
        /**
         * Refers to <b>ItemRevision</b> and indicates end item revision for <b>RevisionRule</b>
         * object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  endItemRevision;
        /**
         * Refers to a list of <code>OverrideInfo</code> struct.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::OverrideInfo > overrideFolders;
    };

    /**
     * This contains the <b>RevisionRule</b> object configuration information.
     */
    struct RevisionRuleConfigInfo
    {
        /**
         * Identifier that helps the client track the object(s) created
         */
        std::string clientId;
        /**
         * The <b>RevisionRule</b> object used for configuration of this <b>BOMWindow</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
        /**
         * Refers to <code>RevisionRuleEntryProps</code> struct object.
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::RevisionRuleEntryProps props;
    };

    /**
     * main input structure that defines item or item revision of the top line in the BOM
     * window
     */
    struct CreateBOMWindowsInfo
    {
        /**
         * Identifier that helps the client track the object(s) created
         */
        std::string clientId;
        /**
         * Item object reference for which BOM window needs to create
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * ItemRevision object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * PSBOMView object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  bomView;
        /**
         * Structure with information about the RevisionRuleConfigInfo
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::RevisionRuleConfigInfo revRuleConfigInfo;
        /**
         * Tag for Variant rule or option set to use on this BOM window
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectForConfigure;
        /**
         * Active assembly arrangement of this BOM window
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  activeAssemblyArrangement;
    };

    /**
     * The output structure that contains the created BOMWindow object and top line BOMLine
     * object representing the item or item revision.
     */
    struct CreateBOMWindowsOutput
    {
        /**
         * Identifier that helps the client track the object(s) created
         */
        std::string clientId;
        /**
         * Object reference for the BOMWindow created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
        /**
         * Oject reference for the BOMLine created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
    };

    /**
     * Contains list of CreateBOMWindowsOutput which contains created BOMWindow object and
     * top line BOMLine object representing the item or item revision along with the client
     * id and a serviceData containing objects that were created/deleted.
     */
    struct CreateBOMWindowsResponse
    {
        /**
         * List of CreateBOMWindowsOutput which contains created BOMWindow object and top line
         * BOMLine object representing the item or item revision along with the client id
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateBOMWindowsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. For this service, ServiceData
         * contains BOM window and top line.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains item revision object reference of the context assembly to create/validate
     * the occurrence, list of AbsOccInfo for bvr qualified overrides and a list of AssemblyArrangementInfo
     * for bvr/arrangement qualified overrides.
     */
    struct CreateOrUpdateAbsoluteStructureInfo
    {
        /**
         * ItemRevision object reference of the context assembly to create/validate the occurrence,
         * required reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextItemRev;
        /**
         * List of AbsOccInfo for bvr qualified overrides
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AbsOccInfo > bvrAbsOccInfo;
        /**
         * List of AssemblyArrangementInfo for bvr/arrangement qualified overrides, may be null
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AssemblyArrangementInfo > arrAbsOccInfo;
    };

    /**
     * Contain cadOccIdAttrName which identifies the BOMLine attribute that is used to identify
     * relative occurrences to update.
     */
    struct CreateOrUpdateAbsoluteStructurePref
    {
        /**
         * Identifies the BOMLine attribute that is used to identify relative occurrences to
         * update.
         */
        std::string cadOccIdAttrName;
    };

    /**
     * Contains response for createOrUpdateAbsoluteStructure operation.
     */
    struct CreateOrUpdateAbsoluteStructureResponse
    {
        /**
         * Map of input clientId for the absolute occurrence to created/updated/found absolute
         * occurrence
         */
        ClientIdToAbsOccMap absOccOutput;
        /**
         * Map of input client id to created/updated/found AssemblyArrangement
         */
        ClientIdToAsmArrMap asmArrOutput;
        /**
         * The ServiceData contains any other created (AbsOccData, AbsOccDataQualifier), updated
         * (like BVR), relevant related, or deleted objects from this operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains a parent ItemRevision object, list of type RelativeStructureChildInfo and
     * a boolean value for whether the BVR should be set to precise.
     */
    struct CreateOrUpdateRelativeStructureInfo
    {
        /**
         * ItemRevision object reference for which the context assembly is created or updated,
         * required reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parent;
        /**
         * List of type RelativeStructureChildInfo
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelativeStructureChildInfo > childInfo;
        /**
         * Flag for updating the BVR to precise(true)/imprecise(false)
         */
        bool precise;
    };

    /**
     * Contains cadOccIdAttrName and a list of item types.
     */
    struct CreateOrUpdateRelativeStructurePref
    {
        /**
         * String representing the occurrence note type which holds the value for the CAD occurrence
         * id or PSOccurrenceThread uid
         */
        std::string cadOccIdAttrName;
        /**
         * List of item types that the client is interested in, such that if the overall structure
         * in Teamcenter contains structure relating to other item types or subtypes not in
         * this list, that structure will not be deleted if this operation is complete.
         */
        std::vector< std::string > itemTypes;
    };

    /**
     * The response for createOrUpdateRelativeStructure operation.
     */
    struct CreateOrUpdateRelativeStructureResponse
    {
        /**
         * Member of type ClientIdToPSOccurrenceThreadMap
         */
        ClientIdToPSOccurrenceThreadMap output;
        /**
         * Mwmber of type Teamcenter::Soa::Server::ServiceData serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains ItemRevision object reference and list of AssemblyArrangement.
     */
    struct DeleteAssemblyArrangementsInfo
    {
        /**
         * ItemRevision object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * List of AssemblyArrangement object references to be deleted
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  > arrangements;
    };

    /**
     * The response for the <code>deleteAssemblyArrangements</code> operation.
     */
    struct DeleteAssemblyArrangementsResponse
    {
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData</code>
         * with deleted assembly arrangements. Assembly arrangement UIDs will be returned as
         * deleted objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains parent item revision and list of child information structures.
     */
    struct DeleteRelativeStructureInfo
    {
        /**
         * ItemRevision object reference for the context assembly from which children are to
         * be removed
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parent;
        /**
         * List of identifiers of the relative occurrences to be deleted. This is the CAD occurrence
         * id or PSOccurrenceThread uid to uniquely identify the occurrence under a particular
         * context Item Revision
         */
        std::vector< std::string > childInfo;
    };

    /**
     * Contains cadOccIdAttrName.
     */
    struct DeleteRelativeStructurePref
    {
        /**
         * BOMLine attribute name that contains the CAD occurrence identifier.
         */
        std::string cadOccIdAttrName;
    };

    /**
     * The response for <code>deleteRelativeStructure</code> operation.
     */
    struct DeleteRelativeStructureResponse
    {
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData
         * </code>with updated context BVR objects and the deleted relative occurrences. CAD
         * occurrence IDs or <b>PSOccurrenceThread</b> UIDs will be returned as deleted objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains parent BOMLines to expand and an exclude filter to specify children to exclude.
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
         * property values) that are configured out by ICs. ExcludeGDEs -- Excludes lines that
         * are GDEOccurrences. ExcludeNonImanItemLines -- Excludes any lines that are not ImanItemLines.
         */
        BOMLineFilter excludeFilter;
    };

    /**
     * Through this structure, the parent bom line , the item revision of the bom line and
     * the datasets attached to the bom line item revision are returned.
     */
    struct ExpandPSParentData
    {
        /**
         * BOMline object reference of the parent
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * ItemRevision object reference of parent
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevOfBOMLine;
        /**
         * List of Dataset object references attached to parent
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > parentDatasets;
    };

    /**
     * Contains ExpandPSParentData corresponding to the parent and a list of ExpandPSData
     * of the children
     */
    struct ExpandPSAllLevelsOutput
    {
        /**
         * ExpandPSParentData member
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSParentData parent;
        /**
         * List of ExpandPSData children found for this parent.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSData > children;
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
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelationAndTypesFilter > info;
    };

    /**
     * A list of ExpandPSAllLevelsOutput so that a set of parent bom lines can be expanded.
     */
    struct ExpandPSAllLevelsResponse
    {
        /**
         * List of ExpandPSAllLevelsOutput which contains ExpandPSParentData and list of ExpandPSData
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSAllLevelsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. For this service, all objects
         * are returned to the plain objects group. Error information will also be returned.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Through this structure, the child bom line , the item revision of the bom line and
     * the datasets attached to the bom line item  revision are returned.
     */
    struct ExpandPSData
    {
        /**
         * BOMline object reference of the children
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * ItemRevision object reference of children
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevOfBOMLine;
        /**
         * List of Dataset object references attached to children
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > datasets;
    };

    /**
     * Contains parent BOMLines to expand and an exclude filter to specify children to exclude.
     */
    struct ExpandPSOneLevelInfo
    {
        /**
         * List of parent bom lines that needs to be expanded
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > parentBomLines;
        /**
         * Filter to exclude the type of BOMLines. Valid values are: None -- Returns all information
         * about the structure. ExcludeOverridden -- Excludes structure or property values that
         * are removed by AbsOccs subsititution. ExcludeICHistory -- Excludes structure that
         * are configured out by ICs. ExcludeGDEs -- Excludes lines that are GDEOccurrences.
         * ExcludeNonImanItemLines -- Excludes any lines that are not ImanItemLines.
         */
        BOMLineFilter excludeFilter;
    };

    /**
     * Structure containing ExpandPSParentData corresponding to the parent and a list of
     * ExpandPSData of the children
     */
    struct ExpandPSOneLevelOutput
    {
        /**
         * ExpandPSParentData member
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSParentData parent;
        /**
         * List of ExpandPSData children found for this parent.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSData > children;
    };

    /**
     * More than one filtering criteria can be specified using this which is nothing but
     * a list of  RelationAndTypesFilter
     */
    struct ExpandPSOneLevelPref
    {
        /**
         * Flag to check for expanding the item revision further
         */
        bool expItemRev;
        /**
         * List of RelationAndTypesFilters that contain the relation names and the types of
         * objects of the given relation.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelationAndTypesFilter > info;
    };

    /**
     * A ExpandPSOneLevelResponse containing the return for this operation.
     */
    struct ExpandPSOneLevelResponse
    {
        /**
         * List of ExpandPSOneLevelOutput which contains ExpandPSParentData and list of ExpandPSData
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSOneLevelOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information. For this service, all objects
         * are returned to the plain objects group. Error information will also be returned.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains the response for getRevisionRules operation.
     */
    struct GetRevisionRulesResponse
    {
        /**
         * List of RevisionRuleInfo which contains Revision rule, configure attribute status
         * along with override information
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RevisionRuleInfo > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains the response for getVariantRules operation.
     */
    struct GetVariantRulesResponse
    {
        /**
         * Holds map of itemRevision to list of VariantRules.
         */
        ItemRevisionToVariantRulesMap inputItemRevToVarRules;
        /**
         * The ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains note type and note text information for the occurrence note.
     */
    struct OccNote
    {
        /**
         * The type of the occurrence note to set.
         */
        std::string noteType;
        /**
         * The text for the occurrence note.
         */
        std::string noteText;
    };

    /**
     * This contains information about the override RevisionRule Entry.
     */
    struct OverrideInfo
    {
        /**
         * Refers to the <b>CFMOverrideEntry</b> of <b>RevisionRule</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CFMOverrideEntry>  ruleEntry;
        /**
         * Refers to the <b>Folder</b> of override rule entry of <b>RevisionRule</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * This consists of a string which indicates the relation name and a list of strings
     * which indicate the object types. An object that falls under these input criteria
     * is returned along with the children.
     */
    struct RelationAndTypesFilter
    {
        /**
         * Relation name
         */
        std::string relationName;
        /**
         * List of the relation name types
         */
        std::vector< std::string > relationTypeNames;
    };

    /**
     * Contains information about the relative occurrence.
     */
    struct RelOccInfo
    {
        /**
         * Name and value pairs for the attribute information to set or update on the occurrence
         * specified in the form of BOM line property names.  For example, the BOM line occurrence
         * name property could be specified with the <code>attrsToSet</code> <code>name</code>
         * as <i>bl_occurrence_name</i> and the <code>value</code> as the occurrence name.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AttributesInfo > attrsToSet;
        /**
         * Flag to specify that the quantity is as required.  The default is FALSE.
         */
        bool asRequired;
        /**
         * Positioning information for the occurrence.  This needs to be ordered in the standard
         * matrix format.
         */
        std::vector< double > occTransform;
        /**
         * Note information for the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::OccNote > occNotes;
    };

    /**
     * Contains clientId, cadOccId, an item revision and occurrence information structure.
     */
    struct RelativeStructureChildInfo
    {
        /**
         * Identifier that helps the client track the object(s) created
         */
        std::string clientId;
        /**
         * This is the CAD occurrence id or PSOccurrenceThread uid to uniquely identify the
         * occurrence under a particular context Item Revision, can be null for create. A valid
         * cadOccId must be passed when the calling the service with complete = true. If a valid
         * cadOccId is not supplied when complete = true, the service creates new occurrences
         * and any data associated against the old occurrence is lost.
         */
        std::string cadOccId;
        /**
         * Item Revision for the PSOccurrence creation, required reference, if the precise flag
         * is false, then the Item will be obtained from the Item Revision and used
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  child;
        /**
         * Member of type RelOccInfo.
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelOccInfo occInfo;
    };

    /**
     * Contains the revisionRule object reference, a map of string attribute to boolean
     * flag to indicate the configurable and a list of override information.
     */
    struct RevisionRuleInfo
    {
        /**
         * RevisionRule object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
        /**
         * A map of string attribute to boolean flag to indicate the configurable attribute
         * has values on it and information about override folder.
         */
        ConfigureAttrStatusMap hasValueStatus;
        /**
         * List of override information
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::OverrideInfo > overrideFolders;
    };




    /**
     * Closes a BOMWindow.  Must be used to close the BOMWindow created during Create BOM
     * Window after calls to Expand Product Structure services are complete.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param bomWindows
     *        The BOMWindow to close
     *
     * @return
     *         the uids of the BOMWindow.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CloseBOMWindowsResponse closeBOMWindows ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  >& bomWindows ) = 0;

    /**
     * Creates a BOMWindow and sets the input Item Revision as the top line.  Can be used
     * to create the BOMLine for input to Expand Product Structure services.  All BOMLines
     * under this window are unpacked.  To use the Teamcenter default unitNo or use your
     * input RevisionRule with no changes, you must set unitNo to -1 in RevisionRuleEntryProps::unitNo.
     * If it is not specified, your input rule will function as a modified/transient revision
     * rule with a unitNo of 0.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        Input is an item or item Revision object
     *
     * @return
     *         Output is the created BOMWindow object and top line BOMLine object representing the
     *         item or item revision
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateBOMWindowsResponse createBOMWindows ( const std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateBOMWindowsInfo >& info ) = 0;

    /**
     * CreateOrUpdateAbsoluteStucture allows the user to find or create the absolute structure
     * network of objects and relations for the input model. The service first attempts
     * to check for the presence of duplicate context objects and then validate the existence
     * of the structure to be created. If any of the objects exist and the input attribute
     * values differ from those already set, an attempt is made to update the values. Note:
     * The following AbsOccData attributes are not supported for arrangement qualified overrides.
     * These attributes can only be overridden at the bvr level (which applies to all arrangements).
     * If these attributes are overridden in the AssemblyArrangementInfo, they will be ignored.
     * 1.child item 2.GDE object 3.instance number 4.occurrence name 5.note 6.occurrence
     * type 7.Variant instance As we process one contextItemRev object at one time, it is
     * assumed that all edits for a given contextItemRev come in as one set of input.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        List of input structures that defines all the occurrence for a given parent
     *
     * @param bomViewTypeName
     *        Type of BOMView
     *
     * @param complete
     *        Flag that if true signifies that the structure represented in the input is the full
     *        representation of the structure under the input parent. Any other structure relations
     *        that exist in Teamcenter but are not represented here will be removed. Upper and
     *        lower qualified (including arrangements) absolute occurrence overrides will not be
     *        implicitly deleted or removed.  Please use the deleteAssemblyArrangements operation.
     *
     * @param pref
     *        preference structure specific for this service
     *
     * @return
     *         Output is an explicit response consisting of a map of input clientId for the absolute
     *         occurrence to created/updated/ found absolute occurrence and map of input client
     *         id to created/updated/found AssemblyArrangement.
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if an invalid BOM view type is specified in bomViewTypeName.
     *           <br>
     * @deprecated
     *         As of tc2007, use the createOrUpdateAbsoluteStructure operation from the  207_12
     *         namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the createOrUpdateAbsoluteStructure operation from the  207_12 namespace."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateAbsoluteStructureResponse createOrUpdateAbsoluteStructure ( const std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateAbsoluteStructureInfo >& info,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateAbsoluteStructurePref&  pref ) = 0;

    /**
     * Create or update the relative structure objects and relations for the input model.
     * The service first attempts to check for the presence of duplicate context objects
     * and then validate the existence of the structure to be created. If any of the objects
     * exist but the input attribute values that differ from those already set, an attempt
     * is made to update the values if possible. This service assumes the input is in a
     * bottom-up format such that if any failures occur, the structure that is created will
     * be consistent. No attempt is made in the service to rearrange the input and process
     * it in the correct order. As we process one parent context object at one time, it
     * is assumed that all edits for a given parent context come in as one set of input.
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
     *        representation of the structure under the input parent.  Any other structure relations
     *        that exist in Teamcenter but are not represented here will be removed.
     *
     * @param pref
     *        Preference structure specific for this service
     *
     * @return
     *         Output is an explicit response consisting of a map of input clientId string to created/updated/found
     *         occurrence thread reference.
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
     *           <br>
     * @deprecated
     *         As of tc2007, use the createOrUpdateRelativeStructure operation from the 2007_12
     *         namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the createOrUpdateRelativeStructure operation from the 2007_12 namespace."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateRelativeStructureInfo >& inputs,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateRelativeStructurePref&  pref ) = 0;

    /**
     * Deletes assembly arrangements and all the absolute occurrence data associated with
     * the assembly arrangements, it also delete the relation between assembly arrangements
     * and bvr.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        Input is bvr and list of assembly arrangements to delete
     *
     * @param bomViewTypeName
     *        The BOM view type name
     *
     * @return
     *         the uids of the deleted assembly arrangements.
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if an invalid BOM view type is specified in bomViewTypeName.
     *           <br>
     * @deprecated
     *         As of tc2007, use the deleteAssemblyArrangements operation from the 2007_12 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the deleteAssemblyArrangements operation from the 2007_12 namespace."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteAssemblyArrangementsResponse deleteAssemblyArrangements ( const std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteAssemblyArrangementsInfo >& info,
        const std::string&  bomViewTypeName ) = 0;

    /**
     * Deletes one or more first level children of a parent assembly.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List input of structures that defines the parent and first level children to be deleted.
     *
     * @param bomViewTypeName
     *        Qualifies the specified parent item revision(s) to identify a unique BOM view revision.
     *
     * @param pref
     *        Preference structure specific for this service
     *
     * @return
     *         The ServiceData contains the UIDs of any deleted occurrences
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if an invalid BOM view type is specified in bomViewTypeName.
     *           <br>
     * @deprecated
     *         As of tc2007, use the deleteRelativeStructure operation from the 2007_12 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the deleteRelativeStructure operation from the 2007_12 namespace."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteRelativeStructureResponse deleteRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteRelativeStructureInfo >& inputs,
        const std::string&  bomViewTypeName,
        const Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteRelativeStructurePref&  pref ) = 0;

    /**
     * Finds the chilren at all levels given parent bomlines. Also if required gets the
     * objects of given type and relation that are attached to the parent and children
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        of  ExpandPSAllLevelsInfo which contains parent bom lines and a filter of the type
     *        of bom lines to exclude.
     *
     * @param pref
     *        of a ExpandPSAllLevelsPref which contains a list of relation name and the types of
     *        objects of the given relation to return along with the children.
     *
     * @return
     *         list of ExpandPSData which contains parent bomlines, chilrens and datasets of given
     *         type and relation attached to them. All Object ids that were successfully found are
     *         added to ServiceData. Objects/object ids that failed the find are returned in a list
     *         of failures in the ServiceData
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSAllLevelsResponse expandPSAllLevels ( const Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSAllLevelsInfo&  input,
        const Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSAllLevelsPref&  pref ) = 0;

    /**
     * Finds the first level chilren of given parent bomlines. Also if required gets the
     * objects of given type and relation that are attached to the parent and children
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        of  ExpandPSOneLevelInfo which contains parent bom lines and a filter of the type
     *        of bom lines to exclude.
     *
     * @param pref
     *        of a ExpandPSOneLevelPref which contains a list of relation name and the types of
     *        objects of the given relation to return along with the children.
     *
     * @return
     *         list of ExpandPSData which contains parent bomlines, chilrens and datasets of given
     *         type and relation attached to them. All Object ids that were successfully found are
     *         added to ServiceData.  Objects/object ids that failed the find are returned in a
     *         list of failures in the ServiceData
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSOneLevelResponse expandPSOneLevel ( const Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSOneLevelInfo&  input,
        const Teamcenter::Services::Cad::_2007_01::Structuremanagement::ExpandPSOneLevelPref&  pref ) = 0;

    /**
     * The GetRevisionRules service gets all the persistent revision rules in the database.
     * It along with the revision rules returns its runtime configuration properties status
     * of being fixed or not.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         RevisionRulesResponse which contains RevisionRuleInfo. RevisionRuleInfo has the revision
     *         rule , a map of string attribute to boolean flag to indicate the configurable attribute
     *         has values on it and information about override folder
     *
     *
     * @exception ServiceException
     *           ServiceException Thrown if the system fails retreiving the list of revision rules.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::GetRevisionRulesResponse getRevisionRules (  ) = 0;

    /**
     * The GetVariantRules service gets all the variant rules in the database for the given
     * Item Revision.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param itemRevs
     *        List of object references of ItemRevisions to get variant rules for
     *
     * @return
     *         GetVariantRulesResponse which contains a map of input Item Revision to list of to
     *         list of Variant Rule objects for that Item Revision
     *
     *
     * @exception ServiceException
     *           ServiceException Thrown if the there are no ItemRevision objects input.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::GetVariantRulesResponse getVariantRules ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  >& itemRevs ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

