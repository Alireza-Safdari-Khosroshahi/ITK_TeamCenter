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

#ifndef TEAMCENTER_SERVICES_CAD_STRUCTUREMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CAD_STRUCTUREMANAGEMENTSERVICE_HXX

#include <teamcenter/services/cad/_2007_01/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2007_06/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2007_09/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2007_12/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2008_03/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2008_06/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2009_04/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2013_05/Structuremanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            class StructuremanagementService;

/**
 * Contains StructureManagement Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacadstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacadtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACADSTRONGMNGD_API StructuremanagementService
    : public Teamcenter::Services::Cad::_2007_01::Structuremanagement,
             public Teamcenter::Services::Cad::_2007_06::Structuremanagement,
             public Teamcenter::Services::Cad::_2007_09::Structuremanagement,
             public Teamcenter::Services::Cad::_2007_12::Structuremanagement,
             public Teamcenter::Services::Cad::_2008_03::Structuremanagement,
             public Teamcenter::Services::Cad::_2008_06::Structuremanagement,
             public Teamcenter::Services::Cad::_2009_04::Structuremanagement,
             public Teamcenter::Services::Cad::_2013_05::Structuremanagement
{
public:
    static StructuremanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * Finds the revision of the given item / item revision that is configured when the
     * given revision rule is used to configure the given item / item revision.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        A list of GetConfiguredItemRevisionInfo structures, each of which contain a item
     *        or item revision object and revision rule.
     *
     * @return
     *         contains a ServiceData and a list of GetConfiguredItemRevisionOutput, each of which
     *         contain the configured item revision and list of GetConfiguredItemRevisionInfo structures,
     *         each of which contain the input object and revision rule. Any failure will be returned
     *         via ServiceData with original input object mapped to error message.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_06::Structuremanagement::GetConfiguredItemRevisionResponse getConfiguredItemRevision ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::GetConfiguredItemRevisionInfo >& inputs ) = 0;

    /**
     * In the Create mode this operation creates a new option(s), with given option values,
     * and declares them against the given <b>ItemRevision</b> object. In the update mode
     * following operations can be performed with the given option
     * <br>
     * <ul>
     * <li type="disc">1.&nbsp;&nbsp;&nbsp;&nbsp;Replace the current text value for the
     * specified index with a new string from option revision.
     * </li>
     * <li type="disc">2.&nbsp;&nbsp;&nbsp;&nbsp;Add a new value to the option revision.
     * </li>
     * <li type="disc">3.&nbsp;&nbsp;&nbsp;&nbsp;Remove an existing value from the option
     * revision.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when user wants to create classic variant options for
     * a given <b>BOMLine</b> object(s). This also can be used to update an Option
     * <br>
     * <ul>
     * <li type="disc">a) adding a new value
     * </li>
     * <li type="disc">b) removing an existing value
     * </li>
     * <li type="disc">c) replace an existing value by new value.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        Refers to the list of CreateUpdateClassicOptionsInput struct, which are used to create
     *        a new variant option or update an existing variant option.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors  with serviceData with
     *         original input object(s) if any.
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module.
     *         </li>
     *         <li type="disc">215163 Option not valid.
     *         </li>
     *         <li type="disc">215162 Unable to find Item Revision.
     *         </li>
     *         <li type="disc">215160 Not a valid operation.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateClassicOptions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::CreateUpdateClassicOptionsInput >& inputObjects ) = 0;

    /**
     * This operation is to <code>create</code> or <code>update</code> (depending on the
     * Operation) a variantCondition ( which is variant expression of type load if) for
     * a <b>BOMLine</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when user wants to create a new or update an existing
     * classic variant condition for a given <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        This has the list of <code>CreateOrUpdateVariantCondInput</code> struct, which are
     *        used to create a new variant condition or update an existing variant condition.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         <li type="disc">46110 You cannot have substitutes of the top line of the BOM
     *         </li>
     *         <li type="disc">215160 Not a valid operation
     *         </li>
     *         <li type="disc">215161 Cannot find a valid Variant Expression block assosiated with
     *         this BOMLine
     *         </li>
     *         <li type="disc">215166 Failed to save BOMWindow.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of tc2007.1, use  the createOrUpdateVariantConditions2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use  the createOrUpdateVariantConditions2 operation."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateVariantConditions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::CreateOrUpdateVariantCondInput >& inputObjects ) = 0;

    /**
     * Delete option deletes the option and all the values associated with it.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        A list of DelClassicOptionsInput structures, each of which contains a bomline tag,
     *        and list of options. If the option exists then it will be deleted.
     *
     * @return
     *         ServiceData:Any failure will be returned via ServiceData with original input object
     *         mapped to error message.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteClassicOptions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::DelClassicOptionsInput >& inputObjects ) = 0;

    /**
     * This service will be used to delete the variant Condition(load_if) associated with
     * a BOMLine If the variant condition exists then it will be deleted. Failure will be
     * with client id and error message in the ServiceData.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        Consists of the clientId and the BOMLine for which we need to delete the variant
     *        Condition
     *
     * @return
     *         ServiceData
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteVariantConditions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::DeleteVariantCondInput >& inputObjects ) = 0;

    /**
     * This operation is to <code>create</code> or <code>update</code> (depending on the
     * Operation) a variantCondition ( which is variant expression of type load if) for
     * a <b>BOMLine</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when user wants to create a new or update an existing
     * classic variant condition for a given <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        This has the list of <code>CreateOrUpdateVariantCondInput</code> struct, which are
     *        used to create a new variant condition or update an existing variant condition.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         <li type="disc">46110 You cannot have substitutes of the top line of the BOM
     *         </li>
     *         <li type="disc">215160 Not a valid operation
     *         </li>
     *         <li type="disc">215161 Cannot find a valid Variant Expression block associated with
     *         this BOMLine
     *         </li>
     *         <li type="disc">215166 Failed to save BOMWindow.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateVariantConditions2 ( const std::vector< Teamcenter::Services::Cad::_2007_09::Structuremanagement::CreateOrUpdateVariantCondInput >& inputObjects ) = 0;

    /**
     * This is the overloaded function of Cad::_2007_01::StructureManagement::createOrUpdateAbsoluteStructure.
     * It takes an additional variable into the CreateOrUpdateAbsoluteStructurePref2 structure
     * to hold the last modified date of the BVR with an extra preference value to check
     * it with server modifed date to make a decision whether we want to make modification
     * on BVR. CreateOrUpdateAbsoluteStucture allows the user to find or create the absolute
     * structure network of objects and relations for the input model. The service first
     * attempts to check for the presence of duplicate context objects and then validate
     * the existence of the structure to be created. If any of the objects exist and the
     * input attribute values differ from those already set, an attempt is made to update
     * the values. Note: The following AbsOccData attributes are not supported for arrangement
     * qualified overrides. These attributes can only be overridden at the bvr level (which
     * applies to all arrangements). If these attributes are overridden in the AssemblyArrangementInfo,
     * they will be ignored. 1.child item 2.GDE object 3.instance number 4.occurrence name
     * 5.note 6.occurrence type 7.Variant instance As we process one contextItemRev object
     * at one time, it is assumed that all edits for a given contextItemRev come in as one
     * set of input.
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
     *        flag that if true signifies that the structure represented in the input is the full
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
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateAbsoluteStructureResponse createOrUpdateAbsoluteStructure ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateAbsoluteStructureInfo2 >& info,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateAbsoluteStructurePref2&  pref ) = 0;

    /**
     * This is the overloaded function of Cad::_2007_01::StructureManagement::createOrUpdateRelativeStructure.
     * It takes an additional variable into the CreateOrUpdateRelativeStructureInfo2 structure
     * to hold the last modified date of the BVR with an extra preference value to check
     * it with server modifed date to make a decision whether we want to make modification
     * on BVR. Create or update the relative structure objects and relations for the input
     * model. The service first attempts to check for the presence of duplicate context
     * objects and then validate the existence of the structure to be created. If any of
     * the objects exist but the input attribute values that differ from those already set,
     * an attempt is made to update the values if possible. This service assumes the input
     * is in a bottom-up format such that if any failures occur, the structure that is created
     * will be consistent. No attempt is made in the service to rearrange the input and
     * process it in the correct order. As we process one parent context Object at one time,
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
     *           215033: The input last modified date differs from actual.
     *           <br>
     *           215034: The dataset or BVR was modified even when the input last modified dates was
     *           different than the current last modified data.
     *           <br>
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateRelativeStructureInfo2 >& inputs,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateRelativeStructurePref2&  pref ) = 0;

    /**
     * This operation deletes assembly arrangements and all the absolute occurrence data
     * associated with the assembly arrangements.  It also deletes the relation between
     * assembly arrangements and the BOM view revision object. The last modified date of
     * the BVR can be specified for comparison against the last modified date in Teamcenter
     * to ensure the BVR that contains the arrangement has not changed outside of this client
     * context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User deletes an existing assembly arrangement from an existing assembly.
     * <br>
     * <br>
     * For this operation, the assembly is passed in as the <code>itemRev</code> and the
     * assembly arrangement is passed in through <code>arrangements</code>.  The assembly
     * arrangement is removed from the assembly, as well as the relation between the arrangement
     * and the BVR, and the UID of the deleted arrangement is added to the <b>ServiceData</b>
     * list of deleted objects.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateAbsoluteStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        List of item revisions and the assembly arrangements to delete from the found BOM
     *        view revision.
     *
     * @param bomViewTypeName
     *        The BOM view type used to find the existing BOM view object.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         <code>ServiceData</code><b> </b>which<b> </b>contains<b> </b>the UIDs of any deleted
     *         assembly arrangements.
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
     *         <li type="disc">215033: The input last modified date differs from actual.
     *         </li>
     *         <li type="disc">215034: The dataset or BOM view revision was modified even when the
     *         input last modified dates was different than the current last modified data.
     *         </li>
     *         <li type="disc">215042: The Item was not found for the input itemRev.
     *         </li>
     *         <li type="disc">215043: The BOM view revision was not found for the input itemRev.
     *         </li>
     *         <li type="disc">215044: The BOM view was not found for the item.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if an invalid BOM view type is
     *           specified in <code>bomViewTypeName</code>.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteAssemblyArrangementsResponse deleteAssemblyArrangements ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteAssemblyArrangementsInfo2 >& info,
        const std::string&  bomViewTypeName,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteAssemblyArrangementsPref&  pref ) = 0;

    /**
     * Deletes one or more first level children of a parent assembly.  This is the overloaded
     * function of Cad::_2007_01::StructureManagement::deleteRelativeStructure. It takes
     * an additional variable into the DeleteRelativeStructureInfo2 structure to hold the
     * last modified date of the BVR with an extra preference value to check it with server
     * modifed date to make a decision whether we want to make modification on BVR.
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
     *        Qualifies the specified parent item revision(s) to identify a unique BOM   view revision.
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
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteRelativeStructureResponse deleteRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteRelativeStructureInfo2 >& inputs,
        const std::string&  bomViewTypeName,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteRelativeStructurePref2&  pref ) = 0;

    /**
     * This operation is to find classic variant options defined on an <b>ItemRevision</b>
     * object(s).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user can use this operation to find all the classic variant options defined on
     * given <b>ItemRevision</b> object. The option and values can be used for configuration
     * or creating other related objects like variant conditions, constraint (defaults,
     * derived defaults and rule checks) rules or <b>VariantRule</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputRevisions
     *        This is list of <b>ItemRevision</b> object on which variant options are to be queried.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_12::Structuremanagement::ClassicOptionsResponse queryClassicOptions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  >& inputRevisions ) = 0;

    /**
     * This operation is to find a variant condition value ( load if - this is a type of
     * variant expression represents variant condition) for a <b>BOMLine</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user needs variant condition defined on the <b>BOMLine</b> object, for display
     * or editing purpose.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputBomLines
     *        This has the list of <b>BOMLine</b> objects, on which variant condition are defined.
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
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         <li type="disc">46067 Invalid variant condition clause.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Cad::_2007_12::Structuremanagement::VariantConditionResponse queryVariantConditions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& inputBomLines ) = 0;

    /**
     * Given one or more sets of product structure information containing child paths specified
     * by PS Occurrence Thread chains, this method returns the corresponding BOM Lines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        Specifies sets of product structure information each containing parent BOM line,
     *        based on a BOM Window opened by the client, and one or more child paths specified
     *        as an ordered set of PS Occurrence Thread UIDs. BOM configuration is managed by the
     *        BOM Window. Input client IDs must be unique for all input.
     *
     * @return
     *         map of input PS Occurrence Thread UIDs, specified as child paths in the input, to
     *         the corresponding BOMLines. BOMLine objects are returned as Service Data plain objects
     *         to inflate properties. Partial failures can result for each child path or product
     *         structure being evaluated and can be associated with the input by the input client
     *         ID.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_03::Structuremanagement::AskChildPathBOMLinesResponse askChildPathBOMLines ( const std::vector< Teamcenter::Services::Cad::_2008_03::Structuremanagement::AskChildPathBOMLinesInfo >& input ) = 0;

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
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1:
     * <br>
     * <br>
     * User adds an existing component to an existing assembly to create a relative occurrence.
     * <br>
     * For this operation, the assembly is passed in as the parent and the component is
     * passed in as the child.  The relative occurrence is created and a map of the input
     * <code>clientID</code> to <code>MappedReturnData</code> is returned in <code>output</code>
     * and the occurrence, BOM view and BOM view revision are returned as created objects
     * in <code>ServiceData</code>.
     * <br>
     * <br>
     * Use Case 2:
     * <br>
     * <br>
     * User wants to update the position of the child component relative to the parent assembly.
     * <br>
     * For this operation, the transform on the child occurrence information is updated
     * with the new position relative to the parent.  The assembly is passed in as the parent
     * and the component is passed in as the child.  The relative occurrence is updated
     * and a map of the <code>clientID</code> to <code>MappedReturnData</code> is returned
     * in <code>output</code> and the occurrence and BOM view revision are returned as updated
     * objects in <code>ServiceData</code>.
     * <br>
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
     *        List of input structures that specify all the children to be added to the specified
     *        parent assembly.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         A map of input clientIds to <code>MappedReturnData</code>.
     *         <br>
     *         <br>
     *         The following warning and errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215000 (error): An invalid BOM view type name was specified with
     *         the parent input.
     *         </li>
     *         <li type="disc">215005 (error): The BOM view revision (BVR) is not checked out by
     *         the current user.
     *         </li>
     *         <li type="disc">215006 (error): The BOM view revision is checked out by another user.
     *         </li>
     *         <li type="disc">215008 (error): A duplicate parent for the relative structure parent
     *         input already exists.
     *         </li>
     *         <li type="disc">215009 (error): The object type name specified in the input preference
     *         does not exist.
     *         </li>
     *         <li type="disc">215010 (warning): The input CAD occurrence identifier does not correspond
     *         to a valid BOM line.  This is a warning when the complete input is true.
     *         </li>
     *         <li type="disc">215010 (error): The input CAD occurrence identifier does not correspond
     *         to a valid BOM line.  This is an error when the complete input is false.
     *         </li>
     *         <li type="disc">215033 (error): The input last modified date differs from actual.
     *         </li>
     *         <li type="disc">215034 (error): The dataset or BVR was modified even when the input
     *         last modified dates was different than the current last modified data.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of Teamcenter 10.1, this version of createOrUpdateRelativeStructure is replaced
     *         by the _2013_05 version.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, this version of createOrUpdateRelativeStructure is replaced by the _2013_05 version."))
#endif
    virtual Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructureInfo >& inputs,
        const Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructurePref&  pref ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuremanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/cad/Cad_undef.h>
#endif

