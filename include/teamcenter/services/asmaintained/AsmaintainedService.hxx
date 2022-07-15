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

#ifndef TEAMCENTER_SERVICES_ASMAINTAINED_ASMAINTAINEDSERVICE_HXX
#define TEAMCENTER_SERVICES_ASMAINTAINED_ASMAINTAINEDSERVICE_HXX

#include <teamcenter/services/asmaintained/_2009_06/Asmaintained.hxx>
#include <teamcenter/services/asmaintained/_2010_04/Asmaintained.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/asmaintained/AsMaintained_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asmaintained
        {
            class AsmaintainedService;

/**
 * The AsMaintained service provides operations to manage as-maintained <b>PhysicalPart</b>
 * structures. As-maintained <b>PhysicalPart</b> structures can be generated for the
 * Item or subclasses of <b>Item</b> which are marked as MRO types.
 * <br>
 * The AsMaintained service can be used to support the following:
 * <br>
 * <ul>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Generate an AsMaintained Physical Part structure
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Install AsMaintained parts in the structure
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Uninstall AsMaintained parts from the structure
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Replace AsMaintained parts in the structure
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Move an AsMaintained part from one location
 * to other
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Change the disposition of an AsMaintained
 * part
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Get all open positions in an AsMaintained
 * structure in which parts can be installed
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Create BOM windows for AsMaintained parts
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Apply revision rules for AsMaintained structures
 * in the MRO BOM Window
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Search for all installable AsMaintained parts
 * in the system which can be installed in a given position in an AsMaintained structure
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Perform BOM comparison of two AsMaintained
 * structures
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Perform accountability check on two AsMaintained
 * structures
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaasmaintainedstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaasmaintainedtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAASMAINTAINEDSTRONGMNGD_API AsmaintainedService
    : public Teamcenter::Services::Asmaintained::_2009_06::Asmaintained,
             public Teamcenter::Services::Asmaintained::_2010_04::Asmaintained
{
public:
    static AsmaintainedService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation applies the revision rule specific to as-maintained structure configuration.
     * As-Maintained structures can be configured only by Date and Serviceability.
     * <br>
     * The <b>PhysicalPartRevision</b> objects have "<i>Effective From</i>" and "<i>Effective
     * To</i>" dates. If the date applied on the <b>MroBOMWindow</b> object falls in-between
     * those two dates then that revision is considered to be effective. This filter is
     * applied on the entire as-maintained structure. Once an <b>MRORevisionRule</b> is
     * applied or changed, the entire structure is updated to show the updated configuration.
     * <br>
     * Serviceability indicates whether a <b>PhysicalPart</b> object is in its useful life.
     * By default, all the Serviceable parts are configured.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        Apply MRO Revision Rule Input
     *
     * @return
     *         The top <b>AsMaintainedBOMLine</b> object which is configured as a result of application
     *         of the <b>MRORevisionrule</b> is returned in the created objects list of the <code>ServiceData</code>.
     *         Any failure will be returned with <code>clientId</code> mapped to error message in
     *         the <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242011&nbsp;&nbsp;&nbsp;&nbsp;If the <b>MRORevisionRule</b>
     *         object is not applied on the <b>MroBOMWindow</b> object
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ApplyMroRevisionRuleResponse applyMroRevisionRule ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ApplyMroRevisionRuleInputInfo >& inputData ) = 0;

    /**
     * This operation changes the disposition of an as-maintained <b>PhysicalPart</b> object.
     * When a <b>PhysicalPart</b> object is created, a default disposition <i>In-Service</i>
     * is created. It can be changed to any user specified value later on.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        The required information to change the disposition of an as-maintained <b>PhysicalPart</b>
     *        object.
     *
     * @return
     *         The <b>DispositionApplicability</b>  relation along with the <code>ServiceData</code>
     *         is returned. Any failure will be returned with <code>clientId</code> mapped to error
     *         message in the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ChangeDispositionResponse changePhysicalPartDisposition ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ChangeDispositionInfo >& input ) = 0;

    /**
     * This operation generates an as-maintained <b>PhysicalPart</b> structure for a given
     * design <b>Item</b> structure. The design structure should be first set in an <b>MroBOMWindow</b>
     * object so that <b>NeutralBOMLine</b> objects are constructed for every <b>Item</b>
     * in the structure. An as-maintained <b>PhysicalPart</b> is created for every <b>Item</b>
     * in the structure which is marked as Traceable (This value is set on the <b>PartLogisticsForm</b>
     * associated with the <b>Item</b>). All the parent/child as-maintained <b>PhysicalPart</b>
     * objects are related to each other by <b>AsMaintainedStructure</b> relation. A <b>StructureContext</b>
     * object is created with the configuration applied to the <b>MroBOMWindow</b> and saved
     * on the top <b>PhysicalPart</b> objects.
     * <br>
     * One can specify the following parameters on the <b>PartLogisticsForm</b>.
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Traceable&nbsp;&nbsp;&nbsp;&nbsp;If marked
     * true, a <b>PhysicalPart</b> will be created for the <b>Item</b>.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Serialized&nbsp;&nbsp;&nbsp;&nbsp;If marked
     * true, the created <b>PhysicalPart</b> will be marked as serialized.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Lot&nbsp;&nbsp;&nbsp;&nbsp;If marked true,
     * the created <b>PhysicalPart</b> will be marked as lot.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Preserve Quantity&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, only one <b>PhysicalPart</b> will be created irrespective of the quantity
     * specified on the design <b>Item</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * An as-maintained <b>PhysicalPart</b> structure is an imprecise structure. The parent
     * and child relation, the <b>AsMaintainedStructure</b> relation, is between the revision
     * of the parent and the item of the child.
     * <br>
     * In a <b>PhysicalPart</b> structure, if the parts are serialized and all the required
     * information like<i> Serial Number, Lot Number</i>(in case of Lot parts), <i>Manufacturer's
     * id</i> are specified, then the <b>PhysicalPart</b> object's usage is set as <i>Preferred</i>.
     * The parts which are not marked as <i>Serialized</i> or <i>Lot</i>, the default value
     * is set to <i>Preferred</i>. For the serialized or lot parts, if the <i>Serial Number
     * or Lot Number</i> is not specified, those parts are set as <i>Missing</i>. Once the
     * required information is provided, the usage is changed to Preferred.
     * <br>
     * A Business object constant defined for the Item class governs the type of <b>PhysicalPart</b>
     * object to be created during the structure generation. By default the value it set
     * to <b>PhysicalPart</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        Holds the required information to generate an as-maintained <b>PhysicalPart</b> structure
     *        for a design <b>Item</b> structure.
     *
     * @return
     *         Generated <b>PhysicalPart</b> object along with the <code>ServiceData</code> are
     *         returned. The created top <b>PhysicalPart</b> object is returned in the created objects
     *         list of the <code>ServiceData</code>. Any failure will be returned with client id
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *         Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237008 &nbsp;&nbsp;&nbsp;&nbsp;If the <b>SerialNumberGenerator</b>
     *         object could not generate a new number as it already has reached its upper limit
     *         of number generation.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237030 &nbsp;&nbsp;&nbsp;&nbsp;If SerialNumberGenerator(s)
     *         is not defined for the <b>Item</b> object.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237031&nbsp;&nbsp;&nbsp;&nbsp;If the Lot
     *         size of the specified Lot is already exhausted.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237032 &nbsp;&nbsp;&nbsp;&nbsp;If the Lot
     *         does not exist in the system.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237069 &nbsp;&nbsp;&nbsp;&nbsp;If the specified
     *         Lot has already passed its expiry date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237086&nbsp;&nbsp;&nbsp;&nbsp;If the Manufacturing
     *         Date or the Installation date of the <b>PhysicalPart</b> is specified as future date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242023&nbsp;&nbsp;&nbsp;&nbsp;If a <b>PhysicalLocation</b>
     *         object for the specified location name is not found.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::GenerateAsMaintainedStructureResponse generateAsMaintainedStructure ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::GenerateAsMaintainedStructureInfo >& input ) = 0;

    /**
     * This operation installs a <b>PhysicalPart</b> object under a parent object in a given
     * position. In the as-maintained structure, the relations are imprecise. Hence the
     * child <b>PhysicalPart</b> object will be installed under the parent <b>PhysicalPartRevision</b>
     * object. An object of <b>AsMaintainedStructure</b> will be created between the two
     * objects.
     * <br>
     * Based on the specified position, the usage will be determined by the code. Following
     * values are possible.
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Preferred&nbsp;&nbsp;&nbsp;&nbsp;If the design
     * <b>Item</b> of the child part is a part of the configured design <b>Item</b> structure
     * for the parent part.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Alternate&nbsp;&nbsp;&nbsp;&nbsp;If the design
     * Item of the child part is an Alternate of the <b>Item</b> configured in the design
     * <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Substitute&nbsp;&nbsp;&nbsp;&nbsp;If the
     * design <b>Item</b> of the child part is a Substitute of the <b>Item</b> configured
     * in the design <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Deviated&nbsp;&nbsp;&nbsp;&nbsp;If the design
     * <b>Item</b> of the child part is not a part of the <b>Item</b> configured in the
     * design <b>Item</b> structure for the parent part. A Valid deviation should be already
     * set up between the parent and the child parts.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        Holds the required information to install an as-maintained <b>PhysicalPart</b> under
     *        a parent.
     *
     * @return
     *         The <b>AsMaintainedBOMLine</b> object created for the installed <b>PhysicalPart</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with <code>clientId</code> mapped to error message in the
     *         <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237028&nbsp;&nbsp;&nbsp;&nbsp;If the Deviation
     *         Authority is not released. Without an approved/released deviation authority, a deviated
     *         part cannot be installed.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237049
     *         This error occurs when the <b>PhysicalPart</b> is getting installed as deviated,
     *         but the valid deviation is not setup.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051
     *         This error occurs when the <b>PhysicalPart</b> is not uniquely identified in
     *         the system. This check is done for the serialized <b>PhysicalPart</b>. The Part number,
     *         serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237052&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the Physical Structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237058&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if Installation Date is less than effective from date of <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242007&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242022&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPart</b> is already installed and cannot be moved.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242028&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::InstallAsmPhysicalPartResponse installAsmPhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::InstallAsmPhysicalPartInputInfo >& inputData ) = 0;

    /**
     * This operation moves the <b>PhysicalPart</b> to specified location.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        A list of structures which hold the required information to move the <b>PhysicalPart</b>
     *        from one location to another.
     *
     * @return
     *         The <b>PhysicalLocationUsage</b> object created for the moved <b>PhysicalPart</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with <code>clientId</code> mapped to error message in the
     *         <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051   This error occurs when the <b>PhysicalPart</b>
     *         is not uniquely identified in the system. This check is done for the serialized <b>PhysicalPart</b>.
     *         The Part number, serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242021&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the installation date cannot be earlier than installation date of previous
     *         location.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242022&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> is installed. Installed <b>PhysicalPart</b> cannot
     *         be moved to location using this operation.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242034&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> movement date is future date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242030&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> is already in that location.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242034&nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::MovePhysicalPartResponse movePhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::MovePhysicalPartInfo >& input ) = 0;

    /**
     * This operation replaces an as-maintained <b>PhysicalPart</b> in a structure with
     * a given as-maintained <b>PhysicalPart</b> object.  The existing as-maintained <b>PhysicalPart</b>
     * object will be removed from the structure and the new object will be installed in
     * that position. A new <b>AsMaintainedStructure</b> relation will be created between
     * the parent and the new <b>PhysicalPart</b> objects. The Installation Time specified
     * will be set as the Installation Time on the relation object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        A list of structures which hold the required information to replace the existing
     *        as-maintained <b>PhysicalPart</b> object in a structure with a new <b>PhysicalPart</b>
     *        object.
     *
     * @return
     *         The created <b>AsMaintainedBOMLine</b> object for the replacer <b>PhysicalPart</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors. Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237028&nbsp;&nbsp;&nbsp;&nbsp;If the Deviation
     *         Authority is not released. Without an approved/released deviation authority, a deviated
     *         part cannot be installed.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237049  This error occurs when the <b>PhysicalPart</b>
     *         is getting installed as deviated, but the valid deviation is not setup.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051   This error occurs when the <b>PhysicalPart</b>
     *         is not uniquely identified in the system. This check is done for the serialized <b>PhysicalPart</b>.
     *         The Part number, serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237052&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237055&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the part to replace is top <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the physical structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237058&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if Installation Date is less than effective from date of PhysicalPartRevision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237073&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the replace date is less than effective from date of PhysicalPartRevision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242007&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242014&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the disposition value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242015&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the location value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242022&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPart</b> is already installed and cannot be moved.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242028&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ReplacePhysicalPartResponse replaceAsmPhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ReplaceAsMaintainedPartInputInfo >& inputData ) = 0;

    /**
     * This operation uninstalls an as-maintained <b>PhysicalPartRevision</b> object from
     * a structure. When an as-maintained object is uninstalled from a structure, if the
     * usage is not '<i>Extra to Design</i>' a new <b>PhysicalPartRevision</b> object is
     * created in the structure in that position. A new <b>AsMaintainedBOMLine</b> is constructed
     * to represent that new part. The usage of the new part is set to <i>Missing</i> as
     * there is no actual part in that position. An object of <b>AsMaintainedStructure</b>
     * relation is created between the new part and the parent part.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        Holds the required information to un-install an as-maintained <b>PhysicalPartRevision</b>
     *        from a structure.
     *
     * @return
     *         The created <b>AMaintainedBOMLine</b> object is returned in the created objects list
     *         of the <code>ServiceData</code>. Any failure will be returned with client id mapped
     *         to error message in the <code>ServiceData</code> list of partial errors.  Following
     *         error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051   This error occurs when the <b>PhysicalPart</b>
     *         is not uniquely identified in the system. This check is done for the serialized <b>PhysicalPart</b>.
     *         The Part number, serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237054&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the top line is selected to uninstall.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the physical structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if uninstall date is less that the effective from date of the <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242013&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the uninstall date is either a future date or not a valid date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242014&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the disposition value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242015&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the location value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242016&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> is already uninstalled.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242020&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the uninstall date is less that the install date.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::UninstallPhysicalPartResponse uninstallPhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::UninstallPhysicalPartInputInfo >& inputData ) = 0;

    /**
     * This operation gets the installable <b>PhysicalPartRevision</b> based on the usage
     * name. It will get the <i>Preferred, Alternate, Substitute</i> and <i>Deviated</i>
     * <b>PhysicalPartRevision</b> for specified usage.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        The required information to search the installable Physical Parts.
     *
     * @return
     *         A list of structures with the <b>PhysicalPart</b> objects matching the criteria along
     *         with the <code>ServiceData</code> is returned. Any failure will be returned with
     *         client id mapped to error message in the <code>ServiceData</code> list of partial
     *         errors.
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SearchInstallablePhysPartResponse searchInstallablePhysPart ( const std::vector< Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SearchInstallablePhysPartInputInfo >& input ) = 0;

    /**
     * This operation will set the given object as top line for the specified <b>BOMWindow</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        The required information to set the object as top line for a <b>BOMWindow</b>.
     *
     * @return
     *         A top line  along with the <code>ServiceData</code> is returned. The <b>AsMaintainedBOMLine</b>
     *         object created is returned in the created objects list of the <code>ServiceData</code>.
     *         Any failure will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SetMroWindowTopLineResponse setMroWindowTopLine ( const std::vector< Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SetMroWindowTopLineInfo >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AsmaintainedService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/asmaintained/AsMaintained_undef.h>
#endif

