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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_06_STRUCTURE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_06_STRUCTURE_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


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
            namespace _2008_06
            {
                class Structure;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structure
{
public:

    struct DefaultNaming;
    struct DuplicateInputInfo;
    struct DuplicateResponse;
    struct ExpandOrUpdateDuplicateItemsInfo;
    struct ExpandOrUpdateDuplicateItemsOutput;
    struct ExpandOrUpdateDuplicateItemsResponse;
    struct NewItemInfo;
    struct RelatedItemsInfo;
    struct ValidateStructureItemIdsInfo;
    struct ValidateStructureItemIdsResponse;

    /**
     * Dependency Types
     */
    enum DependencyType{ NoDep,
                 Drawing,
                 PartFamilyMaster,
                 PartFamilyMember,
                 Required,
                 AllDep,
                 ExcludeFromBom
                 };

    /**
     * OldItemIds mapped to the NewItemInfo structure.
     */
    typedef std::map< std::string, NewItemInfo > DuplicateIdMap;

    /**
     * prefix/suffix/replace-with/autoAssign to form new Item IDs.
     */
    struct DefaultNaming
    {
        /**
         * auto assign new item IDs.
         */
        bool autogen;
        /**
         * substring to be prefixed to the old item ID to form a new item ID.
         */
        std::string prefix;
        /**
         * substring to be sufficed to the old item ID to form a new item ID.
         */
        std::string suffix;
        /**
         * substring to be replaced from the old item ID by another substring to form a new
         * item ID.
         */
        std::string from;
        /**
         * substring to replace with a substring from the old item ID to form a new item ID.
         */
        std::string to;
    };

    /**
     * Input for Duplicate SOA API
     */
    struct DuplicateInputInfo
    {
        /**
         * The top <b>BOMLine</b> of the structure to be cloned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topLine;
        /**
         * A map of oldItemId and NewItemInfo structure.  The newItemInfo is made up of the
         * proposed new ItemId and the proposed new ItemName.
         */
        DuplicateIdMap clonedIdMap;
        /**
         * A pattern to form a new ItemId.
         */
        Teamcenter::Services::Structuremanagement::_2008_06::Structure::DefaultNaming defaultName;
        /**
         * Whether to rename the CAD files or not.
         */
        bool renameCadFile;
        /**
         * A list of dependency types. This defines the cad traversal.
         */
        std::vector< DependencyType > options;
    };

    /**
     * response from the Duplicate SOA.
     */
    struct DuplicateResponse
    {
        /**
         * Top <b>ItemRevision</b> of the Cloned structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  clonedItemRev;
        /**
         * <code>ServiceData</code> object - The service data object consists of the   top <b>ItemRevision</b>
         * of the cloned structure.  The error stack will contain those <b>ItemRevision</b>
         * objects that failed cloning and the reason.  Those <b>ItemRevision</b> objects that
         * fail to get cloned are referenced.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>ExpandOrUpdateDuplicateItemsInfo</code> contains the <b>BOMLine</b> objects,
     * list of <b>ItemRevision</b> objects and list of Dependency types.
     */
    struct ExpandOrUpdateDuplicateItemsInfo
    {
        /**
         * If it is not null, expand it and get its dependencies based on the depTypes.  The
         * <b>BOMLine</b> can be any line in the structure that the user picks for expansion.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomline;
        /**
         * The <b>ItemRevision</b> objects to perform search dependencies on. If empty, the
         * <b>ItemRevision</b> objects to be used will be from the expansion of the <b>BOMLine</b>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  > itemRevs;
        /**
         * The dependency types to use for the operation.
         */
        std::vector< DependencyType > depTypes;
    };

    /**
     * The <code>ExpandOrUpdateDuplicateItemsOutput</code> represents the collection of
     * all related data objects with the structure <b>ItemRevision</b> object(s) or part
     * family masters <b>ItemRevision</b> object(s).
     */
    struct ExpandOrUpdateDuplicateItemsOutput
    {
        /**
         * The BOM structure <b>ItemRevision</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  object;
        /**
         * List of all dependent objects that are related to the object.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_06::Structure::RelatedItemsInfo > relatedObjInfo;
    };

    /**
     * The <code>ExpandOrUpdateDuplicateItemsResponse</code> structure represents the the
     * results of the structure dependent data search.
     */
    struct ExpandOrUpdateDuplicateItemsResponse
    {
        /**
         * List of <code>ExpandOrUpdateDuplicateItemsOutput</code> which contains information
         * about the BOM structure <b>ItemRevision</b> to its related data relationships.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_06::Structure::ExpandOrUpdateDuplicateItemsOutput > outputs;
        /**
         * The error information will be recorded here.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The proposed new ItemIds and new ItemNames.
     */
    struct NewItemInfo
    {
        /**
         * The proposed new ItemId.
         */
        std::string newItemId;
        /**
         * The proposed new ItemName.
         */
        std::string newItemName;
    };

    /**
     * The RelatedItemsInfo represents the dependent data found and how it is related to
     * a structure <b>ItemRevision</b>. RelatedItemsInfo also can represent a family table
     * member to a family table master.
     */
    struct RelatedItemsInfo
    {
        /**
         * An <b>ItemRevision</b>  - it is the related data.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  relObj;
        /**
         * The GRM relationship used to find the related data.
         */
        std::string relationshipName;
        /**
         * The cad dependency types to use for the operation.
         */
        DependencyType depType;
    };

    /**
     * Input to ValidateStructureItemIds. It contains top BOM line, map of oldItemId to
     * NewItemInfo(NewItemId, NewItemName), default naming pattern and list of dependency
     * types specified by the user.
     */
    struct ValidateStructureItemIdsInfo
    {
        /**
         * Top <b>BOMLine</b> of the structure to be cloned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topLine;
        /**
         * Map of oldItemId and NewItemInfo structure.
         */
        DuplicateIdMap inputMap;
        /**
         * The pattern to form new ItemIds.
         */
        Teamcenter::Services::Structuremanagement::_2008_06::Structure::DefaultNaming defaultName;
        /**
         * A list of dependency types.
         */
        std::vector< DependencyType > options;
    };

    /**
     * Response from <code>ValidateStructureItemIds</code>, containing map of OldItemID
     * to <code>NewItemInfo</code>, list of <b>ItemRevision</b> objects that failed validation
     * and the <code>ServiceData</code> object.
     */
    struct ValidateStructureItemIdsResponse
    {
        /**
         * A map of OldItemID to NewItemInfo that contains the proposed New ItemId and New ItemName.
         */
        DuplicateIdMap clonedIdMap;
        /**
         * <code>ServiceData</code> object.  The error stack will contain those <b>ItemRevision</b>
         * objects that failed cloning and the reason.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation will create a duplicate (clone) of the input structure from its top
     * level down.
     * <br>
     * Depending on the user action, all or some of the original structure is duplicated
     * and the rest is referenced.  The user has the option to de-select a sub assembly
     * or leaf <b>Item</b> on the duplicate dialog.  Those <b>Item</b> objects that are
     * not selected in the duplicate dialog will not be cloned but referenced from the original
     * structure.
     * <br>
     * <br>
     * The user can define a specific naming pattern for the ItemIds of the duplicated (cloned)
     * structure.  The user can define specific ItemIds for individually selected <b>ItemRevision</b>
     * objects or a default naming pattern for the duplicated structure.   The default pattern
     * can be defined by adding prefixes, suffixes or replacing part of the original name
     * with a different pattern.  The user can also choose to allow the system to assign
     * default ids.
     * <br>
     * <br>
     * All of the structure dependent data of the input structure like datasets and attachments
     * are copied to the duplicated structure based on the Business Modeler IDE deep copy
     * rules for <code>SaveAs</code>.  The duplicate operation internally uses <code>SaveAs</code>
     * at every level of the structure; therefore it uses the <code>SaveAs</code> deep copy
     * rules.
     * <br>
     * <br>
     * CAD specific attachments and relations are copied based on the transfer mode defined
     * for the Business Modeler IDE global constant <b>StructureCloneTransferModes</b>.
     * The transfer mode contains dependent closure rules for expansion and cloning.  The
     * value for the closure rules is added by the installed CAD system.
     * <br>
     * <br>
     * For e.g. The closure rule defined for IPEM ProE integration (<b>ipemSCloneClosureRule</b>)
     * looks like this:
     * <br>
     * <br>
     * <b>TYPE.ProPrt:CLASS.ItemRevision:RELATIONP2S.IPEM_master_dependency:PROCESS:PartFamilyMaster:R,
     * TYPE.ProAsm:CLASS.ItemRevision:RELATIONP2S.IPEM_master_dependency:PROCESS:PartFamilyMaster:R,
     * TYPE.ProPrt:CLASS.ItemRevision:RELATIONS2P.IPEM_master_dependency:PROCESS+TRAVERSE:PartFamilyMember,
     * </b>
     * <br>
     * <br>
     * <b>Note</b>: The difference between the three operations <code>duplicate</code>,
     * <code>duplicate2</code> and <code>duplicate3</code> are the following:
     * <br>
     * <br>
     * <code>duplicate</code> and <code>duplicate2</code>
     * <br>
     * - In <code>duplicate</code> the input top <b>BOMLine</b> is the top <b>BOMLine</b>
     * of the original configured structure in Structure Manager.  In <code>duplicate2</code>
     * the input top <b>BOMLine</b> is the selected <b>BOMLine</b> from the configured structure
     * in Structure Manager or Systems Engineering.  i.e. the user can select to clone a
     * sub-assembly of the original structure.
     * <br>
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
     * whereas to align with the MFK project, <code>duplicate3</code> has a <code>DuplicateIdStructure</code>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case1: Simple Clone</b>
     * <br>
     * A user has an assembly which does not have cad dependencies nor does it belong to
     * a specific project(s).  The user wants to duplicate the entire structure with a specific
     * naming pattern for the ItemIds.  The naming pattern is a prefix <b>"test_</b>".
     * <br>
     * <br>
     * The user invokes the duplicate operation by passing in the top <b>BOMLine</b> of
     * the structure to be cloned, and the naming pattern for the new structure.  The result
     * is a new structure with the following naming pattern for the ItemIds -> <b>test_</b>OriginalItemId.
     * <br>
     * <br>
     * <b>Use case2: CAD Clone</b>
     * <br>
     * A user has an assembly structure which has cad dependencies.  The user wants to start
     * a new product with a similar structure and cad dependencies.  The expansion and cloning
     * rules have been defined in the Business Modeler IDE global constant <b>StructureCloneTransferModes</b>
     * <br>
     * The user invokes the duplicate operation by passing in the top <b>BOMLine</b> of
     * the structure to be cloned.
     * <br>
     * The user picks the cad dependency option "<code>Part Families Masters</code>".  The
     * expansion and cloning will be done based on the closure rules defined for Part Family
     * Master in the CAD closure rules.
     * <br>
     * The <code>"Rename Cad Files</code>" will be passed to the CAD integration in a callback.
     * If the <code>"Rename Cad Files</code>", is set to true by the user, the cad files
     * need to be renamed by the cad integration.
     * <br>
     * The result will be a duplicated structure with the expected cad dependencies and
     * it will open in the CAD tool without any errors.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure Clone - Structure Clone component
     *
     * @param inputs
     *        A list of <code>DuplicateInputInfo</code>, the struct that contains the information
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
    virtual Teamcenter::Services::Structuremanagement::_2008_06::Structure::DuplicateResponse duplicate ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_06::Structure::DuplicateInputInfo >& inputs ) = 0;

    /**
     * This operation is called as part of the duplicate functionality.   It expands the
     * structure one level at a time and gets structure dependent data. The dependencies
     * have been defined to allow duplication of CAD dependent structure.  The <code>expandOrUpdateDuplicateItems</code>
     * operation uses Business Modeler IDE global constant <b>StructureCloneTransferModes</b>
     * to determine which of the cad specific attachments and relationships can be expanded.
     * This constant defines the transfer modes containing dependent closure rules for expansion
     * and cloning.  The value for the closure rules is added by the installed CAD system.
     * <br>
     * <br>
     * Note: The difference between <code>expandOrUpdateDuplicateItems</code>, <code>expandOrUpdateDuplicateItems2</code>
     * and <code>expandOrUpdateDuplicateItems3</code> are as follows:
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
     * The user sends in a structure for expansion, it will be expanded one level at a time
     * and all dependent data will be returned based on the input and the value of the closure
     * rules defined.  The input consists of the <b>BOMLine</b> for expansion, the <b>ItemRevision</b>
     * objects on which to perform the expansion, and the dependency types.  The <b>ItemRevision</b>
     * objects could be null, in which case the <b>ItemRevision</b> object(s) gotten from
     * the expansion of the <b>BOMLine</b> are used.  The dependency types are checked against
     * the definition in the closure rules to determine what dependent data is expanded.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure Clone - Structure Clone component
     *
     * @param infos
     *        It contains the <b>BOMLine</b> objects, list of <b>ItemRevision</b> objects and list
     *        of Dependency types
     *
     * @return
     *         The BOM structure <b>ItemRevision</b> and its related data which consists of the
     *         related object (an <b>ItemRevision</b>) and the GRM relationship used to find the
     *         related data; and the <code>ServiceData</code> object.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">46002&nbsp;&nbsp;&nbsp;&nbsp;Invalid tag received by BOM Module.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_06::Structure::ExpandOrUpdateDuplicateItemsResponse expandOrUpdateDuplicateItems ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_06::Structure::ExpandOrUpdateDuplicateItemsInfo >& infos ) = 0;

    /**
     * This operation will validate the un-validated ItemIds that will be used to clone(duplicate)
     * an assembly structure.  All portions of the structure that are displayed in the duplicate
     * dialog have been validated by the client.
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
     * The user sends in a structure for validation of the new ItemIds .  The input to this
     * operation is the top <b>BOMLine</b>, a map of old ItemIds to new ones for those <b>Item</b>
     * objects that are already validated, and the default naming scheme.  Based on the
     * structure traversal, the input map, and the naming scheme this operation validates
     * whether the proposed names for the un-validated <b>Item</b> objects are valid.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure Clone - Structure Clone component
     *
     * @param inputs
     *        List of structure ValidateStructureItemIdsInput that contains the information needed
     *        for validation before a duplicate operation  can be performed.
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
    virtual Teamcenter::Services::Structuremanagement::_2008_06::Structure::ValidateStructureItemIdsResponse validateStructureItemIds ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_06::Structure::ValidateStructureItemIdsInfo >& inputs ) = 0;


protected:
    virtual ~Structure() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

