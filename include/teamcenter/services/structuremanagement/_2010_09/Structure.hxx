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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_09_STRUCTURE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_09_STRUCTURE_HXX

#include <teamcenter/services/structuremanagement/_2008_06/Structure.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/TC_Project.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2010_09
            {
                class Structure;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structure
{
public:

    struct ProjectInfo;
    struct DuplicateInputInfo2;
    struct NewItemInfo2;
    struct ValidateStructureItemIdsInfo2;
    struct ValidateStructureItemIdsResponse2;

    /**
     * Dependency Types
     */
    enum DependencyType2{ NoDep,
                 Drawing,
                 PartFamilyMaster,
                 PartFamilyMember,
                 Required,
                 AllDep,
                 ExcludeFromBom
                 };

    /**
     * OldItemIds mapped to the NewItemInfo2 structure.
     */
    typedef std::map< std::string, NewItemInfo2 > DuplicateIdMap2;

    /**
     * Project Information for Structure Clone
     */
    struct ProjectInfo
    {
        /**
         * Flag that indicates if assigning projects
         */
        bool assign;
        /**
         * Flag that indicates if project needs validation
         */
        bool validate;
        /**
         * Vector of user selected projects
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  > projects;
    };

    /**
     * Input for Duplicate2 SOA API
     */
    struct DuplicateInputInfo2
    {
        /**
         * The top <b>BOMLine</b> or selected <b>BOMLine</b> of the structure to be cloned.
         * The user can select a sub assembly from the original structure to clone.  This input
         * cannot be NULL.  If it is the duplicate dialog will not come up at all.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topLine;
        /**
         * A map of oldItemId and NewItemInfo structure. The newItemInfo is made up of the proposed
         * new ItemId and the proposed new ItemName
         */
        DuplicateIdMap2 duplicateIdMap;
        /**
         * The pattern to form a new ItemId
         */
        Teamcenter::Services::Structuremanagement::_2008_06::Structure::DefaultNaming defaultName;
        /**
         * The user selected projects to add the duplicated <b>Item</b> objects to
         */
        Teamcenter::Services::Structuremanagement::_2010_09::Structure::ProjectInfo projects;
        /**
         * Whether to rename the cad files or not
         */
        bool renameCadFile;
        /**
         * The list of dependency types.  This defines the cad traversal.
         */
        std::vector< DependencyType2 > options;
        /**
         * A bitmap for duplicate option. 1 means smart selection.
         */
        int duplicateOption;
    };

    /**
     * The proposed new ItemIds and new ItemNames.
     */
    struct NewItemInfo2
    {
        /**
         * The proposed new ItemId
         */
        std::string newItemId;
        /**
         * The proposed new ItemName
         */
        std::string newItemName;
    };

    /**
     * Input to ValidateStructureItemIds2. It contains the top <b>BOMLine</b>, map of oldItemId
     * to NewItemInfo(NewItemId, NewItemName), default naming pattern and list of dependency
     * types specified by the user.
     */
    struct ValidateStructureItemIdsInfo2
    {
        /**
         * Top <b>BOMLine</b> or the selected bom line of the structure or sub structure to
         * be cloned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topLine;
        /**
         * Map of OldItemIDs to  NewItemInfo2 that contains the proposed New ItemId and New
         * ItemName.
         */
        DuplicateIdMap2 inputMap;
        /**
         * Pattern to form a new ItemId.
         */
        Teamcenter::Services::Structuremanagement::_2008_06::Structure::DefaultNaming defaultName;
        /**
         * List of user defined projects to which the duplicated <b>Item</b> objects will be
         * added.
         */
        Teamcenter::Services::Structuremanagement::_2010_09::Structure::ProjectInfo projects;
        /**
         * List of dependency types.
         */
        std::vector< DependencyType2 > options;
    };

    /**
     * The response from ValidateStructureItemIds, containing a map of OldItemID to <code>NewItemInfo</code>,
     * list of <b>ItemRevision</b> objects failed validation and a <code>ServiceData</code>
     * object.
     */
    struct ValidateStructureItemIdsResponse2
    {
        /**
         * Map of OldItemID to <code>NewItemInfo</code> that contains the proposed New ItemId
         * and New ItemName
         */
        DuplicateIdMap2 clonedIdMap;
        /**
         * <code>ServiceData</code> object.  The error stack will contain those <b>ItemRevision</b>
         * objects that failed cloning and the reason.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Provides set-based pack/unpack functionality. When recursive option is selected,
     * all loaded substructures of the selected lines will also be packed or unpacked.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">User calls the operation with some lines to pack them, the lines
     * will be packed.
     * </li>
     * <li type="disc">User calls the operation with root line to unpack the whole structure,
     * all loaded packed lines in the structure will be unpacked.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param lines
     *        The lines that need to be packed. If pack all option is selected, the children of
     *        the lines will be packed.
     *
     * @param flag
     *        0:pack the lines 1:unpack the lines 2:pack all lines 3:unpack all lines
     *
     * @return
     *         No specific errors are returned by this operation.
     *         <br>
     *         <br>
     *         Note:
     *         <br>
     *         <ul>
     *         <li type="disc">All referenced properties will be excluded from return to improve
     *         scalability.
     *         </li>
     *         <li type="disc">When number of lines to be unpacked is more than that preference
     *         <b>BOM_unpack_all_chunk_size</b> specifies, the related objects will not be returned
     *         in <code>ServiceData</code> to improve scalability.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData packOrUnpack ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& lines,
        int flag ) = 0;

    /**
     * This operation will create a duplicate (clone) of the input structure from its top
     * level down or a selected sub assembly.
     * <br>
     * Depending on the user action, all or some of the original structure is duplicated
     * and the rest is referenced.  The user has the option to de-select a sub assembly
     * or leaf <b>Item</b> on the duplicate dialog.  Those <b>Item</b> objects that are
     * not selected in the duplicate dialog will not be cloned but referenced from the original
     * structure.
     * <br>
     * The user can define a specific naming pattern for the ItemIds of the duplicated (cloned)
     * structure.  The user can define specific ItemIds for individually selected <b>ItemRevision</b>
     * objects or a default naming pattern for the duplicated structure.   The default pattern
     * can be defined by adding prefixes, suffixes or replacing part of the original name
     * with a different pattern.  The user can also choose to allow the system to assign
     * default ids.
     * <br>
     * If project(s) have been passed in as input, the cloned structure is assigned to that
     * project(s).  By default the projects to which the top <b>BOMLine</b> in the duplicate
     * dialog belongs and to which the user has access, is used to populate the project
     * list.  The user has the option to modify that list based on which projects are available
     * to that user.
     * <br>
     * All of the structure dependent data of the input structure like datasets and attachments
     * are copied to the duplicated structure based on the Business Modeler IDE deep copy
     * rules for <code>SaveAs</code>.  The duplicate operation internally uses <code>SaveAs</code>
     * at every level of the structure; therefore it uses the <code>SaveAs</code> deep copy
     * rules.
     * <br>
     * If the structure being cloned is a Requirements Manager structure, tracelink GRMs
     * are handled based on the deep copy rules set for ReqRev for <code>SaveAs</code>.
     * 
     * <br>
     * Target&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * ReqRev
     * <br>
     * Relation&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * FND_TraceLink&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * <br>
     * Attached Type&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ReqRev
     * <br>
     * Operation&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SaveAs
     * <br>
     * Action&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * CopyAsReference
     * <br>
     * Condition
     * <br>
     * Direction&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * IsTargetPrimary= false
     * <br>
     * <br>
     * CAD specific attachments and relations are copied based on the transfer mode defined
     * for the Business Modeler IDE global constant <b>StructureCloneTransferModes</b>.
     * The transfer mode contains dependent closure rules for expansion and cloning.  The
     * value for the closure rules is added by the installed CAD system.
     * <br>
     * For e.g. The closure rule defined for IPEM ProE integration (<b>ipemSCloneClosureRule</b>)
     * looks like this:
     * <br>
     * <b>TYPE.ProPrt:CLASS.ItemRevision:RELATIONP2S.IPEM_master_dependency:PROCESS:PartFamilyMaster:R,
     * TYPE.ProAsm:CLASS.ItemRevision:RELATIONP2S.IPEM_master_dependency:PROCESS:PartFamilyMaster:R,
     * TYPE.ProPrt:CLASS.ItemRevision:RELATIONS2P.IPEM_master_dependency:PROCESS+TRAVERSE:PartFamilyMember,</b>
     * <br>
     * <br>
     * <b>Note</b>: The difference between the three operations <code>duplicate</code>,
     * <code>duplicate2</code> and <code>duplicate3</code> are the following:
     * <br>
     * <code>duplicate</code> and <code>duplicate2</code>
     * <br>
     * - In <code>duplicate</code> the input top <b>BOMLine</b> is the top <b>BOMLine</b>
     * of the original configured structure in Structure Manager.  In <code>duplicate2</code>
     * the input top <b>BOMLine</b> is the selected <b>BOMLine</b> from the configured structure
     * in Structure Manager or Systems Engineering.  i.e. the user can select to clone a
     * sub-assembly of the original structure.
     * <br>
     * - The input for <code>duplicate2</code> includes project(s).  The cloned structure
     * is assigned to those project(s).  <code>duplicate</code> does not have project(s)
     * as input.
     * <br>
     * <br>
     * <code>duplicate2</code> and <code>duplicate3</code>
     * <br>
     * - <code>duplicate3</code> was created as a result of the Multi Field Key (MFK ) project.
     * The difference between <code>duplicate2</code> and <code>duplicate3</code> is that
     * in <code>duplicate2</code> is that the input and output had a <code>DuplicateIdMap2</code>
     * whereas to align with the MFK project, <code>duplicate3</code> has a <code>DuplicateIdStructure</code>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case1: Simple Clone</b>
     * <br>
     * A user has an assembly which does not have cad dependencies nor does it belong to
     * a specific project(s).  The user wants to duplicate the entire structure with a specific
     * naming pattern for the ItemIds.  The naming pattern is a prefix "<b>test_".</b>
     * <br>
     * The user invokes the duplicate operation by passing in the top <b>BOMLine</b> of
     * the structure to be cloned, and the naming pattern for the new structure.  The result
     * is a new structure with the following naming pattern for the ItemIds -> <b>test</b>_OriginalItemId.
     * <br>
     * <br>
     * <b>Use case2: CAD Clone</b>
     * <br>
     * A user has an assembly structure which has cad dependencies.  The user wants to start
     * a new product with a similar structure and cad dependencies.  The expansion and cloning
     * rules have been defined in the Business Modeler IDE global constant <b>StructureCloneTransferModes</b>.
     * <br>
     * The user invokes the duplicate operation by passing in the top <b>BOMLine</b> of
     * the structure to be cloned.
     * <br>
     * The user selects the cad dependency option Part Family Master.  The expansion and
     * cloning will be done based on the closure rules defined for Part Family Master in
     * the CAD closure rules.
     * <br>
     * The "<code>Rename Cad Files</code>" will be passed to the CAD integration in a callback.
     * If the "<code>Rename Cad Files</code>", is set to true by the user, the cad files
     * need to be renamed by the cad integration.
     * <br>
     * The result will be a duplicated structure with the expected cad dependencies and
     * it will open in the CAD tool without any errors.
     * <br>
     * <br>
     * <b>Use case3: Requirements Manager (Systems Engineering) Clone:</b>
     * <br>
     * The user has a requirements manager structure with internal and/or external tracelink
     * GRMs that need to be copied to the cloned structure.  The user defines a set of projects
     * to which the newly cloned structure should belong.  The user does not want to clone
     * the entire structure only a sub-assembly.
     * <br>
     * The precondition to this operation, is that the deep copy rules for <code>SaveAs</code>
     * have been setup correctly
     * <br>
     * The user invokes the duplicate operation by passing in the selected <b>BOMLine</b>
     * of the sub structure to be cloned.  The projects to which the cloned structure should
     * belong are passed in as input.  The naming rule for the ItemId is passed in.
     * <br>
     * The result is a requirement manager structure with the tracelink relations pointing
     * to the correct objects in the new structure.  And the newly cloned structure belongs
     * to the defined projects for which the user has permissions.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure Clone - Structure Clone component
     *
     * @param inputs
     *        A list of <code>DuplicateInputInfo2</code> - A struct that contains the information
     *        needed to duplicate (clone) an assembly structure.
     *
     * @return
     *         The top <b>ItemRevision</b> for the cloned structure and the <code>ServiceData</code>
     *         object with the list of <b>ItemRevision</b> objects that failed cloning.
     *         <br>
     *         <br>
     *         . The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">46002&nbsp;&nbsp;&nbsp;&nbsp;Invalid tag received by BOM Module.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_06::Structure::DuplicateResponse duplicate2 ( const std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structure::DuplicateInputInfo2 >& inputs ) = 0;

    /**
     * This operation is designed to expand structures one level at a time and get structure
     * dependent data. When it is flagged for smart selection, it will try to solve the
     * uncertain smart selection by expansion, in which case only qualified <b>ItemRevision</b>
     * objects will be returned. This operation is used by the duplicate (clone) structure
     * feature.  The dependencies have been defined to allow duplication of CAD dependent
     * structure.  The <code>expandOrUpdateDuplicateItems2</code>  operation uses Business
     * Modeler IDE global constant <b>StructureCloneTransferModes</b> to determine which
     * of the cad specific attachments and relationships can be expanded. This constant
     * defines the transfer modes containing dependent closure rules for expansion and cloning.
     * The value for the closure rules is added by the installed CAD system.
     * <br>
     * <br>
     * <b>Note</b>: The difference between <code>expandOrUpdateDuplicateItems</code>, <code>expandOrUpdateDuplicateItems2</code>
     * and <code>expandOrUpdateDuplicateItems3</code> is as follows:
     * <br>
     * <br>
     * Difference in <code>expandOrUpdateDuplicateItems</code> and <code>expandOrUpdateDuplicateItems2</code>
     * <br>
     * -&nbsp;&nbsp;&nbsp;&nbsp;We allow the user to select a sub assembly for duplication.
     * There is a performance problem that was uncovered.  Even though a sub assembly is
     * sent for duplication, traversal on the server side was happening from the top <b>BOMLine</b>
     * of the structure.  To improve the performance we get a BOB object.
     * <br>
     * <br>
     * -&nbsp;&nbsp;&nbsp;&nbsp;The smart selection logic was added to decide whether to
     * clone or reference an <b>Item</b> in a structure based on the project that the top
     * line of the original structure belongs to.  This smart selection logic is bottom
     * up, so if a child is selected based on project assignment, the parent will be selected,
     * no matter whether the parent belongs to the top item project assignment or not.
     * <br>
     * <br>
     * Difference in <code>expandOrUpdateDuplicateItems2</code> and <code>expandOrUpdateDuplicateItems3</code>
     * <br>
     * The mandatory flag is passed back to the client.  When a cad option has been flagged
     * with a mandatory flag, a <b>"R</b>" predicate in the closure rules, that option will
     * come up in the Duplicate Dialog pre-checked and its selected status will be un-changeable.
     * This will prevent the user from un-checking those <b>ItemRevision</b> objects that
     * were added in to make the structure cad consistent.  That is if a family table member
     * in the assembly structure has been selected for duplication, then automatically include
     * all its masters from the referenced <b>ItemRevision</b> all the way to the top master.
     * Including the masters automatically will only happen if the CAD closure rules are
     * defined with a predicate <b>"R</b>" that says this CAD relation is mandatory for
     * duplication.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1</b>: selectionOption is 0 and the original structure has cad data:
     * <br>
     * The user sends in a structure for expansion, it will be expanded one level at a time
     * and all dependent data will be returned based on the input and the value of the defined
     * closure rule.  The input consists of the <b>BOMLine</b> for expansion and <b>ItemRevision</b>
     * objects on which to perform the expansion,  the dependency types, and the selectionOption.
     * The <b>ItemRevision</b> objects could be null, in which case the <b>ItemRevision</b>
     * object(s) gotten from the expansion of the <b>BOMLine</b> are used.  The dependency
     * types are checked against the definition in the closure rules to determine  what
     * dependent data is expanded.
     * <br>
     * <br>
     * <b>Use case 2</b>: selectionOption is 1 and the original structure has no cad data
     * <br>
     * The user sends in a structure for expansion, it will be expanded one level at a time
     * and all dependent data will be returned based on the input.  In this case no closure
     * rule may be defined, since the structure has no cad data.   The input consists of
     * the <b>BOMLine</b> for expansion and <b>ItemRevision</b> objects on which to perform
     * the expansion,  the dependency types, and the selectionOption.  The <b>ItemRevision</b>
     * objects could be null, in which case the <b>ItemRevision</b> object(s) gotten from
     * the expansion of the <b>BOMLine</b> are used.  Since the selectionOption is 1, the
     * input lines will be checked based on the top <b>BOMLine</b> object's project assignments.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure Clone - Structure Clone component
     *
     * @param opInput
     *        Contains the <b>BOMLine</b> objects, list of <b>ItemRevision</b> objects and list
     *        of Dependency types
     *
     * @param selectionOption
     *        When the value is 1, the system will check the input lines based on the top <b>BOMLine</b>
     *        item's project assignment. If any child belongs to the project, then the parent <b>BOMLine</b>
     *        will be returned otherwise the parent <b>BOMLine</b> will not be returned. When the
     *        value is 0, the operation will do expansion only.
     *
     * @return
     *         The BOM structure <b>ItemRevision</b> or a part family master <b>ItemRevision</b>
     *         and its related data which consists of the related object which is an <b>ItemRevision</b>
     *         and the GRM relationship used to find the related data; and the <code>ServiceData</code>
     *         object.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">46002&nbsp;&nbsp;&nbsp;&nbsp;Invalid tag received by BOM Module.
     *         </li>
     *         <li type="disc">65001&nbsp;&nbsp;&nbsp;&nbsp;Invalid tag received by BOB Module.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_06::Structure::ExpandOrUpdateDuplicateItemsResponse expandOrUpdateDuplicateItems2 ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_06::Structure::ExpandOrUpdateDuplicateItemsInfo >& opInput,
        int selectionOption ) = 0;

    /**
     * This operation is called as part of the duplicate/clone operation.  It will validate
     * the un-validated ItemIds and user selected projects that will be used to clone(duplicate)
     * an assembly structure.   All portions of the structure that are displayed in the
     * duplicate dialog have been validated by the client.
     * <br>
     * <br>
     * Note: The differences between the three operations <code>validateStructureItemIds</code>,
     * <code>validateStructureItemIds2</code> and <code>validateStructureItemIds3</code>
     * are the following:
     * <br>
     * - In <code>validateStructureItemIds</code> the input is the top <b>BOMLine</b> of
     * the original configured structure in Structure Manager.  In <code>validateStructureItemIds2</code>
     * the input is the selected <b>BOMLine</b> of the configured structure in Structure
     * Manager or Systems Engineering.  i.e. the user can select to clone a sub-assembly
     * of the original structure or the entire assembly.  The input for <code>validateStructureItemIds2</code>
     * includes project(s).  The cloned structure is assigned to those project(s).  <code>validateStructureItemIds</code>
     * did not have projects as input.
     * <br>
     * <br>
     * - <code>validateStructureItemIds3</code> was created as a result of the Multi Field
     * Key(MFK) project.  The difference between <code>validateStructureItemIds2</code>
     * and <code>validateStructureItemIds3</code> is that in <code>validateStructureItemIds2</code>
     * the input and output have a <code>DuplicateIdMap2</code> whereas to align with the
     * MFK project, <code>validateStructureItemIds3</code> has a <code>DuplicateIdStructure</code>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user sends in a structure for validation of the new ItemIds.  The input to this
     * operation is the top <b>BOMLine</b> or the selected <b>BOMLine</b>, a map of old
     * ItemIds to new ones for those <b>Item</b> objects that are already validated, the
     * default naming scheme and a list of user defined projects to which the duplicated
     * items will be added.  Based on the structure traversal, the input map, and the naming
     * scheme this operation validates whether the proposed names for the un-validated <b>Item</b>
     * objects are valid and whether the user can add the new structure to the list of user
     * defined projects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure Clone - Structure Clone component
     *
     * @param inputs
     *        A list of structure <code>ValidateStructureItemIdsInput2</code> that contains the
     *        information needed for validation before a duplicate operation would be performed.
     *
     * @return
     *         A map of OldItemID to NewItemInfo that contains the proposed New ItemId and New ItemName
     *         and the <code>ServiceData</code> object.  The error stack will contain those <b>ItemRevision</b>
     *         objects that failed cloning and the reason.
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">46002&nbsp;&nbsp;&nbsp;&nbsp;Invalid tag received by BOM Module.
     *         </li>
     *         <li type="disc">46138&nbsp;&nbsp;&nbsp;&nbsp;The BOMLine does not have an item revision.
     *         </li>
     *         <li type="disc">48161&nbsp;&nbsp;&nbsp;&nbsp;Multiple Items were found for the given
     *         key values.
     *         </li>
     *         <li type="disc">214090&nbsp;&nbsp;&nbsp;&nbsp;Test of ServiceException
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2010_09::Structure::ValidateStructureItemIdsResponse2 validateStructureItemIds2 ( const std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structure::ValidateStructureItemIdsInfo2 >& inputs ) = 0;


protected:
    virtual ~Structure() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

