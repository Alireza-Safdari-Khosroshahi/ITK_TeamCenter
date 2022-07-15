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

#ifndef TEAMCENTER_SERVICES_CAD__2013_05_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2013_05_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_01/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2009_04/Structuremanagement.hxx>
#include <teamcenter/soa/client/model/AssemblyArrangement.hxx>
#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/PSBOMView.hxx>
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
            namespace _2013_05
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct CreateOrUpdateRelativeStructureInfo4;
    struct CreateWindowsInfo2;
    struct MoveInfo;
    struct OccThreadEquivalent;
    struct RelOccInfo;
    struct RelativeStructureChildInfo3;

    /**
     * This enum identifies the type of data being sent by the client to identify the child
     * occurrence information in the parent assembly.
     * <br>
     * The values for this enum are:
     * <br>
     * <ul>
     * <li type="disc"><code>OccurrenceThread</code>    Occurrence thread UID is used to
     * identify the child occurrence in the parent assembly.
     * </li>
     * <li type="disc"><code>CadOccId</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * CAD occurrence ID is used to identify the child occurrence in the parent assembly.
     * </li>
     * <li type="disc"><code>ClientId</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * The <code>RelativeStructureChildInfo3::clientId</code> is used to represent the
     * occurrence in the parent assembly.
     * </li>
     * </ul>
     */
    enum OccThreadIdType{ OccurrenceThread,
                 CadOccId,
                 ClientId
                 };

    /**
     * String map
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * Contains the data for creating or updating the relative product structure for a item
     * revision. It includes the information about the parent and its object and a list
     * of type <code>RelativeStructureChildInfo3</code> that describes the first level children
     * and their occurrence information.
     */
    struct CreateOrUpdateRelativeStructureInfo4
    {
        /**
         * Object reference of the context assembly for create or update of the child occurrence,
         * required input reference.
         */
        Teamcenter::Services::Cad::_2009_04::Structuremanagement::RelativeStructureParentInfo parentInfo;
        /**
         * List of child info structures for creating the occurrences or updating the occurrence
         * attributes. If no child objects are specified and <code>RelativeStructureParentInfo</code>
         * <code>complete</code> is true, all existing child objects will be removed. If no
         * child objects are specified and <code>RelativeStructureParentInfo</code> <code>complete</code>
         * is false, the input is ignored.
         */
        std::vector< Teamcenter::Services::Cad::_2013_05::Structuremanagement::RelativeStructureChildInfo3 > childInfo;
    };

    /**
     * Main input structure that defines <b>Item</b> or <b>ItemRevision</b> of the top line
     * in the <b>BOMWindow</b>. In the input, either revRuleConfigInfo object and objectsForConfigure
     * object(variant rules or saved option set) or configContext object is required.
     */
    struct CreateWindowsInfo2
    {
        /**
         * Identifier that helps the client to track the objects created.
         */
        std::string clientId;
        /**
         * <b>Item</b> object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * <b>ItemRevision</b> object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * <b>PSBOMView</b> object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  bomView;
        /**
         * Structure with information about RevisionRuleConfigInfo
         */
        Teamcenter::Services::Cad::_2007_01::Structuremanagement::RevisionRuleConfigInfo revRuleConfigInfo;
        /**
         * List of variant rules or single stored option set object to set on this window
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsForConfigure;
        /**
         * Active assembly arrangement of this BOMWindow
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  activeAssemblyArrangement;
        /**
         * ConfigurationContext object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
        /**
         * Mapping for window property and respective value that needs to be set on window.
         * User need to populate this map with following property string values as key and true
         * or false as value, which will be set or unset on the window
         * <br>
         * <br>
         * Valid property values are
         * <br>
         * <br>
         * <i>&nbsp;&nbsp;&nbsp;&nbsp;show_unconfigured_variants
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;show_unconfigured_changes
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;show_suppressed_occurrences
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;is_packed_by_default
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;show_out_of_context_lines
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;fnd0show_uncnf_occ_eff
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;fnd0bw_in_cv_cfg_to_load_md</i>
         * <br>
         */
        StringMap bomWinPropFlagMap;
    };

    /**
     * This structure represents the information for moving a single occurrence from its
     * current parent assembly to its target parent assembly in the context of a higher
     * level assembly.
     */
    struct MoveInfo
    {
        /**
         * The item revision of the common parent assembly where this move is occurring. Only
         * ItemRevision type is supported for now.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  commonParent;
        /**
         * The item revision of the source assembly from where the occurrence is being moved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceAssembly;
        /**
         * The occurrence thread path of the BOM line to be moved. The occurrence thread path
         * is in a bottom up list. The first entry in the list should be occurrence to be moved
         * and the last entry should be the occurrence thread for the common parent.
         */
        std::vector< std::string > occThreadPathToBeMoved;
        /**
         * The occurrence thread path of the target parent. The thread path is a bottom up list.
         * The first entry in the list is the target parent assembly and the last entry in the
         * list the common parent for the move.
         */
        std::vector< Teamcenter::Services::Cad::_2013_05::Structuremanagement::OccThreadEquivalent > occThreadPathTargetParent;
    };

    /**
     * This structure identifies the child occurrence in the parent assembly. This structure
     * can identify an child occurrence that are already existing in Teamcenter as well
     * as the child occurrences that are not yet created in Teamcenter.
     */
    struct OccThreadEquivalent
    {
        /**
         * The item revision of the parent assembly. Only item revisions are allowed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * Type of child identifier.
         */
        OccThreadIdType idType;
        /**
         * The identifier for the occurrence as specified by the <code>idType</code> member.
         * The types of identifiers that can be used are the occurrence thread path, CAD occurrence
         * Id and client Id. In cases where an occurrence with the specified identifier value
         * does not exist in Teamcenter, the corresponding occurrence will be created.
         */
        std::string id;
        /**
         * flag to indicate if this occurrence is new in the parent assembly.
         */
        bool isNew;
    };

    /**
     * This structure contains the list of attributes information, a flag to specify if
     * the quantity is to be set as required, occurrence transform and occurrence notes
     * information for the occurrence.
     * <br>
     * The <code>MoveInfo</code> structure contains details on the moving an occurrence
     * from its current parent to a new target parent.
     */
    struct RelOccInfo
    {
        /**
         * Name and value pairs for the attribute information to set or update on the occurrence
         * specified in the form of BOM line property names. For example, the BOM line occurrence
         * name property could be specified with the attrsToSet name as bl_occurrence_name and
         * the value as the occurrence name.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AttributesInfo > attrsToSet;
        /**
         * Flag to specify that the quantity is as required. The default value is FALSE.
         */
        bool asRequired;
        /**
         * Positioning information for the occurrence. This needs to be ordered in the standard
         * matrix format.
         */
        std::vector< double > occTransform;
        /**
         * Note information for the occurrence.
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::OccNote > occNotes;
        /**
         * Optional data specifying the occurrence to be moved and the parent to which to be
         * moved to.
         */
        Teamcenter::Services::Cad::_2013_05::Structuremanagement::MoveInfo moveInfo;
    };

    /**
     * This structure contains information for the child node of a relative structure
     */
    struct RelativeStructureChildInfo3
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure. If clientId is not provided
         * then it can be difficult to align the input with the output or any returned errors.
         */
        std::string clientId;
        /**
         * The name of the BOM view type of the child to be added to the parent <b>BOMViewRevision</b>.
         * If not specified, the <code>bomViewTypeName</code> specified in the input preference
         * <code>CreateOrUpdateRelativeStructurePref</code> will be used as the default. For
         * example, this can be used in a mult-CAD usage, where a <b>JTView</b> of a child originally
         * created in a different CAD system needs to be added to a parent in NX, where the
         * default view type is <b>view</b>.
         */
        std::string childBomViewTypeName;
        /**
         * The CAD occurrence ID or <b>PSOccurrenceThread</b> UID is used to uniquely identify
         * the occurrence under a particular context item revision or General Design Element
         * (GDE) for update. The <code>cadOccId</code> can be null for create. A valid cadOccId
         * must be passed when this operation is called with the <code>RelativeStructureParentInfo</code>
         * <code>complete</code> input set to true. If a valid <code>cadOccId</code> is not
         * supplied when <code>complete</code> is set to true, this operation creates a new
         * occurrence and any data associated against an existing occurrence is removed/lost.
         * This parameter depends on the <code>CreateOrUpdateRelativeStructurePref</code> <code>cadOccIdAttrName</code>
         * preference for finding the existing BOM line
         */
        std::string cadOccId;
        /**
         * The child object for the occurrence creation. Only <b>ItemRevision</b> and <b>GeneralDesignElement</b>
         * (GDE) are supported. If the child occurrence exists, but the input child object is
         * different than the existing child object, the existing child will be replaced by
         * the input child. Existing children are found referencing the occurrence found by
         * the <code>cadOccId</code> input
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  child;
        /**
         * The property information to set or updated for this occurrence. The optional <code>moveInfo</code>
         * structure specifies if this occurrence is being moved to a new parent assembly.
         */
        Teamcenter::Services::Cad::_2013_05::Structuremanagement::RelOccInfo occInfo;
    };




    /**
     * This operation creates or updates the relative structure for the input parent assembly
     * and child components.  The objects created or updated by this operation include a
     * BOM view (BV), BOM view revision (BVR) and occurrence data (<b>PSOccurrence</b>,
     * <b>PSOccurrenceThread</b>).
     * <br>
     * 
     * <br>
     * Before creating the relative structure objects and relations, this operation will
     * check that the structure to be created does not already exist.  If the occurrence
     * exists but the input attribute values differ from those already set, an attempt is
     * made to update the values.
     * <br>
     * <br>
     * This operation assumes the input is in a bottom up format such that if any failures
     * occur, the structure that is created will still be consumable.  For example:
     * <br>
     * <br>
     * Parent assembly A, subassembly B and child C are input into this operation.  If the
     * relative structure for subassembly B and child C is created successfully but an error
     * occurs during the creation of the structure for assembly A and subassembly B, the
     * client can still access the subassembly B, child C relative structure.
     * <br>
     * <br>
     * No attempt is made in the operation to rearrange the input and process it in the
     * correct order. One parent context object is processed at one time and it is assumed
     * that all edits for a given parent context come in as one set of input.
     * <br>
     * <br>
     * This operation can also perform structure move operations. The move operation is
     * performed within the context of the lowest common parent. Along with moving the occurrence
     * from one parent to a new parent, any absolute occurrence data present in the original
     * occurrence will also be moved to the new occurrence. The input for the move operation
     * is specified in the <code>MoveInfo</code> substructure of <code>RelOccInfo</code>.
     * The <code>MoveInfo</code> data is specified in the context of the <code>RelativeStructureChildInfo3</code>.
     * Each <code>RelativeStructureChildInfo3</code> will allow specifying only moving of
     * one instance only. In cases where there are multiple instances of the same occurrence,
     * <code>MoveInfo</code> has to be specified for each instance. In such cases, each
     * instance data will be specified in its own <code>RelativeStructureChildInfo3</code>
     * structure. However, the <code>child</code> object is specified only once per occurrence.
     * For the other instances of the same occurrence, the <code>child</code> object in
     * the <code>RelativeStructureChildInfo3</code> is specified as NULL.
     * <br>
     * <br>
     * In the following example, to move Part_P1 (instance 1) to SubAssembly_B (instance
     * 1), create a new occurrence of Part_P1 under SubAssembly_B. After this add, SubAssembly_B
     * (instance 1) will have a child  Part_P1 (instance 1) and SubAssembly_B (instance
     * 2) will have a child  Part_P1 (instance 2). Specify the move from the occurrence
     * of Part_P1 (instance 1) under SubAssembly_C to the Part_P1 (instance 1) under SubAssembly_B
     * (instance 1).  And similarly for the instance 2.
     * <br>
     * <br>
     * Move Example:
     * <br>
     * Assembly_A
     * <br>
     * |
     * <br>
     * |-->SubAssembly_B  (instance 1)
     * <br>
     * |
     * <br>
     * |-->SubAssembly_B  (instance 2)
     * <br>
     * |
     * <br>
     * |-->SubAssembly_C
     * <br>
     * |       |
     * <br>
     * |       |-->Part_P1    (instance 1)
     * <br>
     * |
     * <br>
     * |-->SubAssembly_C
     * <br>
     * |       |
     * <br>
     * |       |-->Part_P1    (instance 2)
     * <br>
     * <br>
     * <br>
     * To move "Part_P1" from SubAssembly_C to Sub_Assembly_B:
     * <br>
     * <code>relStrInfo4s</code><code>[</code><code>0</code><code>] = new </code><code>CreateOrUpdateRelativeStructureInfo4</code><code>();
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>parentInfo</code><code>
     * = new </code><code>RelativeStructureParentInfo</code><code>();
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>parentInfo.parent</code><code>
     * = </code><code>SubAssembly_B_ItemRev</code><code>;
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>
     * = new </code><code>RelativeStructureChildInfo3</code><code>[</code><code>1</code><code>];
     * <br>
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>]
     * = new </code><code>RelativeStructureChildInfo3</code><code>();
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>clientId</code><code>
     * = "</code><code>Add_Part_P1_to_SubAssembly_B</code><code>";
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].child
     * = </code><code>Part_P1</code><code>;
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>occInfo</code><code>
     * = new </code><code>RelOccInfo</code><code>();
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>occInfo.moveInfo</code><code>
     * = new </code><code>MoveInfo</code><code>();
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>occInfo.moveInfo.commonParent</code><code>
     * = </code><code>Assembly_A_ItemRev</code><code>;
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>occInfo.moveInfo.sourceAssembly</code><code>
     * = </code><code>SubAssembly_C_ItemRev</code><code>;
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>occInfo.moveInfo.occThreadPathToBeMoved</code><code>
     * = </code><code>occThreadPathToBeMoved</code><code>;
     * <br>
     * </code><code>relStrInfo4s</code><code>[</code><code>0</code><code>].</code><code>childInfo</code><code>[</code><code>0</code><code>].</code><code>occInfo.moveInfo.occThreadPathTargetParent</code><code>
     * = </code><code>targetParentOccThr</code><code>;</code>
     * <br>
     * <br>
     * relStrInfo4s[0].childInfo[1] = new RelativeStructureChildInfo3();
     * <br>
     * relStrInfo4s[0].childInfo[1].clientId = "Add_Part_P1_instance_2_to_SubAssembly_B";
     * <br>
     * relStrInfo4s[0].childInfo[1].child = NULL;   // For the second instance, set child
     * to NULL
     * <br>
     * relStrInfo4s[0].childInfo[1].occInfo = new RelOccInfo();
     * <br>
     * relStrInfo4s[0].childInfo[1].occInfo.moveInfo = new MoveInfo();
     * <br>
     * relStrInfo4s[0].childInfo[1].occInfo.moveInfo.commonParent = Assembly_A_ItemRev;
     * <br>
     * relStrInfo4s[0].childInfo[1].occInfo.moveInfo.sourceAssembly = SubAssembly_C_ItemRev;
     * <br>
     * relStrInfo4s[0].childInfo[1].occInfo.moveInfo.occThreadPathToBeMoved = occThreadPathToBeMoved;
     * <br>
     * relStrInfo4s[0].childInfo[1].occInfo.moveInfo.occThreadPathTargetParent = targetParentOccThr;
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1:
     * <br>
     * <br>
     * User adds an existing component to an existing assembly to create a relative occurrence.
     * <br>
     * For this operation, the assembly is passed in as the parent and the component is
     * passed in as the child. The relative occurrence is created and a map of the input
     * <code>clientID</code> to <code>MappedReturnData</code> is returned in output and
     * the occurrence, BOM view and BOM view revision are returned as created objects in
     * <code>ServiceData</code>.
     * <br>
     * <br>
     * Use Case 2:
     * <br>
     * <br>
     * User wants to update the position of the child component relative to the parent assembly.
     * <br>
     * For this operation, the transform on the child occurrence information is updated
     * with the new position relative to the parent. The assembly is passed in as the parent
     * and the component is passed in as the child. The relative occurrence is updated and
     * a map of the <code>clientID</code> to <code>MappedReturnData</code> is returned in
     * <code>output</code> and the occurrence and BOM view revision are returned as updated
     * objects in <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateParts, createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List of input structures that defines all the occurrence for a given parent.
     *
     * @param pref
     *        Preference structure specific for this service.
     *
     * @return
     *         A map of input clientIds to MappedReturnData.
     *         <br>
     *         <br>
     *         The following warning and errors originate from this operation:
     *         <br>
     *         <br>
     *         215000 (error): An invalid BOM view type name was specified with the parent and or
     *         child input.
     *         <br>
     *         215005 (error): The BOM view revision (BVR) is not checked out by the current user.
     *         <br>
     *         215006 (error): The BOM view revision is checked out by another user.
     *         <br>
     *         215008 (error): A duplicate parent for the relative structure parent input already
     *         exists.
     *         <br>
     *         215009 (error): The object type name specified in the input preference does not exist.
     *         <br>
     *         215010 (warning): The input CAD occurrence identifier does not correspond to a valid
     *         BOM line.  This is a warning when the complete input is true.
     *         <br>
     *         215010 (error): The input CAD occurrence identifier does not correspond to a valid
     *         BOM line.  This is an error when the complete input is false.
     *         <br>
     *         215011 (error): The source node data for the "move" operation cannot be null. Please
     *         report this error to your system administrator.
     *         <br>
     *         215012 (error): The target parent data for the "move" operation cannot be null. Please
     *         report this error to your system administrator.
     *         <br>
     *         215013 (error): The BOM Line corresponding to the input Occurrence Thread Equivalent
     *         ID could not be found.
     *         <br>
     *         <br>
     *         215033 (error): The input last modified date differs from actual.
     *         <br>
     *         215034 (error): The dataset or BVR was modified even when the input last modified
     *         dates was different than the current last modified data.
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
     */
    virtual Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2013_05::Structuremanagement::CreateOrUpdateRelativeStructureInfo4 >& inputs,
        const Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructurePref&  pref ) = 0;

    /**
     * Creates a list of window and sets the respective input <b>ItemRevision</b> as the
     * top line. This operation can be used to set multiple saved variant rules or single
     * stored option set to the window. It can be used to set certain window property, if
     * sent as a part of input. It can be used to create the <b>BOMLine</b> for input to
     * Expand Product Structure services.  All <b>BOMLines</b> under this window are unpacked.
     * To use the Teamcenter default unitNo or use your input RevisionRule with no changes,
     * you must set unitNo to -1 in RevisionRuleEntryProps::unitNo.  If it is not specified,
     * your input rule will function as a modified/transient revision rule with a unitNo
     * of 0.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation creates a list of window and sets the respective input Item revision
     * as the top line. This operation can be used to set multiple saved variant rules or
     * single stored option set to the window.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param info
     *        list of objects containing window creation information
     *
     * @return
     *         Output is the created <b>BOMWindow</b> object and top line <b>BOMLine</b> object
     *         representing the item or item revision.
     *         <br>
     *         <br>
     *         This may return following partial error.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">46001   Invalid  input is received from input structure CreateWindowsInfo2
     *         </li>
     *         <li type="disc">215295  Multiple stored option set is not allowed in the input.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateBOMWindowsResponse createBOMWindows2 ( const std::vector< Teamcenter::Services::Cad::_2013_05::Structuremanagement::CreateWindowsInfo2 >& info ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

