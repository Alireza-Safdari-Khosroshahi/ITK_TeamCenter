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

#ifndef TEAMCENTER_SERVICES_ASBUILT_ASBUILTSERVICE_HXX
#define TEAMCENTER_SERVICES_ASBUILT_ASBUILTSERVICE_HXX

#include <teamcenter/services/asbuilt/_2008_06/Asbuilt.hxx>
#include <teamcenter/services/asbuilt/_2009_06/Asbuilt.hxx>
#include <teamcenter/services/asbuilt/_2010_04/Asbuilt.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/asbuilt/AsBuilt_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asbuilt
        {
            class AsbuiltService;

/**
 * The <code>AsBuilt</code> service provides operations to manage as-built physical
 * part structures. As-Built physical part structures can be generated for <b>Item</b>
 * objects whose type has the value of business object constant <i>IsMRONeutralType</i>
 * set to true in BMIDE.
 * <br>
 * The <code>AsBuilt</code> service can perform the following:
 * <br>
 * <ul>
 * <li type="disc">Generate an as-built structure
 * </li>
 * <li type="disc">Install as-built parts in the structure
 * </li>
 * <li type="disc">Uninstall as-built parts from the structure
 * </li>
 * <li type="disc">Replace as-built parts in the structure
 * </li>
 * <li type="disc">Rebuilt an existing as-built structure
 * </li>
 * <li type="disc">Get all open positions in an as-built structure in which parts can
 * be installed
 * </li>
 * <li type="disc">Create BOM windows for as-built parts
 * </li>
 * <li type="disc">Search for all installable as-built parts in the system which can
 * be installed in a given position in an as-built structure
 * </li>
 * <li type="disc">Perform BOM comparison of two as-built structures
 * </li>
 * <li type="disc">Perform accountability check on two as-built structures
 * </li>
 * <li type="disc">Performa BOM comparison of an as-built and a design item structure
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaasbuiltstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaasbuilttypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAASBUILTSTRONGMNGD_API AsbuiltService
    : public Teamcenter::Services::Asbuilt::_2008_06::Asbuilt,
             public Teamcenter::Services::Asbuilt::_2009_06::Asbuilt,
             public Teamcenter::Services::Asbuilt::_2010_04::Asbuilt
{
public:
    static AsbuiltService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation generates an as-built <b>PhysicalPart</b> structure for a given design
     * <b>Item</b> structure. The design structure should be first set in an <b>MroBOMWindow</b>
     * object so that <b>NeutralBOMLine</b> objects are constructed for every <b>Item</b>
     * in the structure. An as-built <b>PhysicalPart</b> is created for every <b>Item</b>
     * in the structure which is marked as <i>Traceable</i> (This value is set on the <b>PartLogisticsForm</b>
     * associated with the <b>Item</b>). All the parent/child as-built <b>PhysicalPart</b>
     * objects are related to each other by <b>AsBuiltStructure</b> relation. A <b>StructureContext</b>
     * object is created with the configuration applied to the <b>MroBOMWindow</b> and saved
     * on the top <b>PhysicalPart</b>.
     * <br>
     * <br>
     * One can specify the following parameters on the <b>PartLogisticsForm</b>.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Traceable&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, a <b>PhysicalPart</b> will be created for the Item.
     * </li>
     * <li type="disc">Serialized&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, the created <b>PhysicalPart</b> will be marked Serialized.
     * </li>
     * <li type="disc">Lot&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, the created <b>PhysicalPart</b> will be marked as Lot.
     * </li>
     * <li type="disc">Preserve Quantity&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, only one <b>PhysicalPart</b> will be created irrespective of the Quantity
     * specified on the design <b>Item</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * An as-built <b>PhysicalPart</b> structure is a precise structure. The parent and
     * child relation, the <b>AsBuiltStructure</b> relation, is between the revisions of
     * the parent and child.
     * <br>
     * <br>
     * In a <b>PhysicalPart</b> structure, if the parts are serialized and all the required
     * information like Serial Number, Lot Number(in case of Lot parts), Manufacturer's
     * id are specified, then the <b>PhysicalPart</b> object's usage is set as <i>Preferred</i>.
     * The parts which are not marked as Serialized or Lot, the default value is set to
     * <i>Preferred</i>. For the serialized or lot parts, if the Serial or Lot Number is
     * not specified, those parts are set as <i>Missing</i>. Once the required information
     * is provided, the usage is changed to <i>Preferred</i>.
     * <br>
     * <br>
     * A Business object constant defined for the Item class governs the type of <b>PhysicalPart</b>
     * object to be created during the structure generation. By default the value it set
     * to <i>PhysicalPart</i>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createMROBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        Structures which holds the required information to generate an as-built <b>PhysicalPart</b>
     *        structure for a design <b>Item</b> structure.
     *
     * @return
     *         The created top <b>PhysicalPart</b> object is returned in the created objects list
     *         of the <code>ServiceData</code>. Any failure will be returned with <code>clientId</code>
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *         Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">237003 &nbsp;&nbsp;&nbsp;&nbsp;If  Installation Date is earlier than
     *         the Manufacturing Date of the PhysicalPart.
     *         </li>
     *         <li type="disc">237008 &nbsp;&nbsp;&nbsp;&nbsp;If the Serial Number Generator could
     *         not generate a new number as it is already reached its upper limit of number generation.
     *         </li>
     *         <li type="disc">237030 &nbsp;&nbsp;&nbsp;&nbsp;If Serial Number generator(s) is not
     *         defined for the Item object.
     *         </li>
     *         <li type="disc">237031&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the <b>Lot</b>
     *         size of the specified <b>Lot</b> is already exhausted.
     *         </li>
     *         <li type="disc">237032 &nbsp;&nbsp;&nbsp;&nbsp;If the Lot does not exist in the system.
     *         </li>
     *         <li type="disc">237069 &nbsp;&nbsp;&nbsp;&nbsp;If the specified Lot has already passed
     *         its expiry date.
     *         </li>
     *         <li type="disc">237086&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the Manufacturing
     *         Date or the Installation date of the <b>PhysicalPart</b> is specified as future date.
     *         </li>
     *         <li type="disc">238001&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the <b>Item</b>
     *         is not a valid MRO neutral item. This error is thrown if the Business Object Constant
     *         <i>"IsMRONeutralType</i>" is not set to "true" for the <b>Item</b> class in BMIDE.
     *         </li>
     *         <li type="disc">238002 &nbsp;&nbsp;&nbsp;&nbsp;If the <b>Item</b> is marked as Traceable.
     *         The values like Traceable, Serialized etc. are specified on the <b>PartLogisticsForm</b>
     *         related to the <b>Item</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::GenerateAsBuiltStructureResponse generateAsBuiltStructure ( const std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::GenerateAsBuiltStructInput >& input ) = 0;

    /**
     * This operation installs a <b>PhysicalPart</b> object under a parent object in a given
     * position. In the as-built structure, the relations are precise. Hence a revision
     * of the child <b>PhysicalPart</b> object will be installed under a revision of the
     * parent <b>PhysicalPart</b> object. An object of <b>AsBuiltStructure</b> will be created
     * between the two objects.
     * <br>
     * Based on the specified position, the usage will be determined by the code. Following
     * values are possible.
     * <br>
     * <ul>
     * <li type="disc">Preferred&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is a part of the configured design <b>Item</b>
     * structure for the parent part.
     * </li>
     * <li type="disc">Alternate&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is an <i>Alternate</i> of the <b>Item</b> configured
     * in the design <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">Substitute&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is a Substitute of the <b>Item</b> configured
     * in the design <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">Deviated&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is not a part of the Item configured in the
     * design Item structure for the parent part. A Valid deviation should be already set
     * up between the parent and the child parts.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param installPhysicalPrtInput
     *        Structures which hold the required information to install an as-built <b>PhysicalPart</b>
     *        under a parent.
     *
     * @return
     *         The <b>AsBuiltBOMLine</b> object created for the installed <b>PhysicalPartRevision</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with <code>clientId</code> mapped to error message in the
     *         <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the ServiceData.
     *         <br>
     *         <ul>
     *         <li type="disc">237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation Date is earlier
     *         than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">237028&nbsp;&nbsp;&nbsp;&nbsp;    If the Deviation Authority is not
     *         released. Without an approved/released deviation authority, a deviated part cannot
     *         be installed.
     *         </li>
     *         <li type="disc">237042 &nbsp;&nbsp;&nbsp;&nbsp;An as-built PhysicalPartRevision object
     *         cannot be installed under an as-built <b>PhysicalPartRevision</b> object whose usage
     *         is set as Missing.
     *         </li>
     *         <li type="disc">237043&nbsp;&nbsp;&nbsp;&nbsp;    If the parent <b>PhysicalPartRevision</b>
     *         object is released.
     *         </li>
     *         <li type="disc">237052&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">237058&nbsp;&nbsp;&nbsp;&nbsp;    If the Installation Date specified
     *         is earlier than the Effective From date on the <b>PhysicalPartRevision</b> object.
     *         </li>
     *         <li type="disc">238006&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPart</b> object
     *         to be installed is marked as Serialized, then the Serial Number property on that
     *         object cannot be empty.
     *         </li>
     *         <li type="disc">238008&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPart</b> object
     *         to be installed is marked as Serialized and Lot, then the Serial Number and Lot Number
     *         properties on that object cannot be empty.
     *         </li>
     *         <li type="disc">238015&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPartRevision</b>
     *         parent object is not an as-built revision.
     *         </li>
     *         <li type="disc">238016&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPartRevision</b>
     *         object to be installed is not an as-built revision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::InstallPhysicalPartResponse installPhysicalPart ( const std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::InstallPhysicalPrtInput >& installPhysicalPrtInput ) = 0;

    /**
     * This operation uninstalls an as-built <b>PhysicalPartRevision</b> object from a structure.
     * When an as-built object is uninstalled from a structure, a new <b>PhysicalPartRevision</b>
     * object is created in the structure in that position. A new <b>AsBuiltBOMLine</b>
     * object is constructed to represent that new part. The usage of the new part is set
     * to <i>Missing</i> as there is no actual part in that position (If the uninstalled
     * part is Extra to Design, the <i>Missing</i> part is not created). An object of <b>AsBuiltStructure</b>
     * relation is created between the new part and the parent part.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param removePhPartInput
     *        Structures which holds the required information to un-install an as-built <b>PhysicalPartRevision</b>
     *        from a structure.
     *
     * @return
     *         The created <b>AsBuiltBOMLine</b> object is returned in the created objects list
     *         of the <code>ServiceData</code>. Any failure will be returned with client id mapped
     *         to error message in the <code>ServiceData</code> list of partial errors.  Following
     *         error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">237043    If the parent <b>PhysicalPartRevision</b> object is released.
     *         </li>
     *         <li type="disc">237052    If the <b>PhysicalPartRevision</b> object is not the latest
     *         revision.
     *         </li>
     *         <li type="disc">238009    If the action attempts to remove a <b>PhysicalPartRevision</b>
     *         for which the usage is set to <i>Missing</i>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::UnInstallPhysicalPartResponse unInstallPhysicalPart ( const std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::RemoveLineInput >& removePhPartInput ) = 0;

    /**
     * This operation replaces an as-built <b>PhysicalPartRevision</b> in a structure with
     * a given as-built <b>PhysicalPartRevision</b> object.  The existing as-built <b>PhysicalPartRevision</b>
     * object will be removed from the structure and the new object will be installed in
     * that position. A new <b>AsBuiltStructure</b> relation will be created between the
     * parent and the new <b>PhysicalPartRevision</b> objects. The <i>Installation</i> Time
     * specified will be set as the Installation Time on the relation object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * installPhysicalPart
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param inputData
     *        ReplaceAsBuiltPartInputInfo structure object which contains the required information
     *        for replace action
     *
     * @return
     *         The created <b>AsBuiltBOMLine</b> object for the replacer <b>PhysicalPart</b> object
     *         is returned in the created objects list of the <code>ServiceData</code>. Any failure
     *         will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.  Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">237073&nbsp;&nbsp;&nbsp;&nbsp;    If the <i>Replace Date</i> is earlier
     *         than the <i>Effective From Date</i> of the <b>PhysicalPartRevision</b> object.
     *         </li>
     *         <li type="disc">238014 &nbsp;&nbsp;&nbsp;&nbsp;If the action tries to replace the
     *         top line.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2009_06::Asbuilt::ReplaceAsBuiltPartResponse replaceAsBuiltPart ( const std::vector< Teamcenter::Services::Asbuilt::_2009_06::Asbuilt::ReplaceAsBuiltPartInputInfo >& inputData ) = 0;

    /**
     * This operation generates a new as-built <b>PhysicalPart</b> structure based on an
     * existing as-built structure. This activity is known as <i>Rebuilding</i>. The new
     * <b>PhysicalPart</b> objects created are linked to the design <b>Item</b> objects
     * of the parts in the existing as-built structure, with <b>PhysicalRealization</b>
     * relation object. New <b>AsBuiltStructure</b> relation objects are created between
     * the <b>PhysicalPartRevision</b> objects in the new structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        A list of <b>AsBuiltBOMLine</b> objects to rebuild an AsBuilt structure.
     *
     * @return
     *         The created top Physical Part object is returned in the created objects list of the
     *         <code>ServiceData</code>. Any failures will be returned with <code>clientId</code>
     *         mapped to the partial error.
     *         <br>
     *         <ul>
     *         <li type="disc">237051&nbsp;&nbsp;&nbsp;&nbsp;If the revision of the parent <b>PhysicalPart</b>
     *         object is not identified. A PhysicalPart object is said to be identified when it
     *         has all the required information like <i>Serial Number</i>, <i>Lot Number</i> (in
     *         case of Lot parts) and the <i>Manufacturer's id</i>.
     *         </li>
     *         <li type="disc">237052&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">237053&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not released.
     *         </li>
     *         <li type="disc">238019&nbsp;&nbsp;&nbsp;&nbsp;If the <i>Rebuild Date</i> specified
     *         is earlier than the <i>Installation Date</i> of any of the objects in the AsBuilt
     *         structure.
     *         </li>
     *         <li type="disc">238020&nbsp;&nbsp;&nbsp;&nbsp;If the Rebuild Date is specified as
     *         a future date.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::RebuildAsBuiltStructureResponse rebuildAsBuiltStructure ( const std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::RebuildAsBuiltStructureInfo >& input ) = 0;

    /**
     * This operation returns all the <b>PhysicalPartRevision</b> objects which can be installed
     * in a given position in an as-built structure.  Following are the lists of installable
     * objects returned based on the position selected.
     * <br>
     * <ul>
     * <li type="disc">Preferred Parts&nbsp;&nbsp;&nbsp;&nbsp;All the preferred revision
     * objects
     * </li>
     * <li type="disc">Alternate Parts &nbsp;&nbsp;&nbsp;&nbsp;All the revision objects
     * realized from the Alternate parts of the design <b>Item</b> object
     * </li>
     * <li type="disc">Substitute Parts &nbsp;&nbsp;&nbsp;&nbsp;All the revision objects
     * realized from the Substitute parts of the design <b>Item</b> object
     * </li>
     * <li type="disc">Deviated Parts &nbsp;&nbsp;&nbsp;&nbsp;All the revision objects which
     * have allowed deviations set up
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * MOIN
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        Structures which hold the required information to query all the installable as-built
     *        <b>PhysicalPartRevision</b> objects.
     *
     * @return
     *         A list of <b>PhysicalPart</b> objects matching the search criteria along with the
     *         <code>ServiceData</code> is returned. Any failure will be returned with <code>clientId</code>
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SearchInstallablePhysPartResponse searchInstallablePhysPart ( const std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SearchInstallablePhysPartInputInfo >& input ) = 0;

    /**
     * This operation sets a given <b>PhysicalPart</b> object as the top line in the given
     * <b>MroBOMWindow</b> object by constructing an object of <b>AsBuiltBOMLine</b>. If
     * the object is an as-built <b>PhysicalPartRevision</b>, then it is directly set as
     * the top line. If the object is a <b>PhysicalPart</b>, then the latest <i>as-built
     * revision</i> of the object is queried and set as the top line. It is possible for
     * a <b>PhysicalPart</b> object to have <i>as-built revisions</i> and non <i>as-built
     * revisions</i>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createMROBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        Structure which holds the required information to set an as-built <b>PhysicalPart</b>
     *        or <b>PhysicalPartRevision</b> as the top line in a <b>MroBOMWindow</b> object.
     *
     * @return
     *         The created top <b>AsBuiltBOMLine</b> object is returned in the created objects list
     *         and the <b>MroBOMWindow</b> object is returned in the updated objects list of the
     *         <code>ServiceData</code>. Any failure will be returned with <code>clientId</code>
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *         Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">238017    If the object is not an as-built <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">238018    If the object is a <b>PhysicalPart</b> and has no revisions
     *         marked as <i>as-built revision</i>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SetMroWindowTopLineResponse setMroWindowTopLine ( const std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SetMroWindowTopLineInfo >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AsbuiltService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/asbuilt/AsBuilt_undef.h>
#endif

