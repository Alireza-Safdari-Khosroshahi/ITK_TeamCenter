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

#ifndef TEAMCENTER_SERVICES_MROCORE_MROCORESERVICE_HXX
#define TEAMCENTER_SERVICES_MROCORE_MROCORESERVICE_HXX

#include <teamcenter/services/mrocore/_2009_06/Mrocore.hxx>
#include <teamcenter/services/mrocore/_2010_04/Mrocore.hxx>
#include <teamcenter/services/mrocore/_2012_02/Mrocore.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/mrocore/MROCore_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Mrocore
        {
            class MrocoreService;

/**
 * The MROCore service provides operations to manage MRO <b>PhysicalPart</b> structures
 * and <b>Item</b> objects which are marked as MRO types.
 * <br>
 * The MROCore service can be used to support the following:
 * <br>
 * <ul>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Create BOM windows.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Get the Lots for the Neutral Item.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Name the Occurrence for the Neutral Item.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Rebase the Physical Part.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Rename the Physical Part.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Record utilization for physical Part.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Display Utilization for Physical Part.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Duplicate the Physical Structure.
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Setup Deviation.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamrocorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamrocoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMROCORESTRONGMNGD_API MrocoreService
    : public Teamcenter::Services::Mrocore::_2009_06::Mrocore,
             public Teamcenter::Services::Mrocore::_2010_04::Mrocore,
             public Teamcenter::Services::Mrocore::_2012_02::Mrocore
{
public:
    static MrocoreService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation allows rebasing the <b>PhysicalPartRevision</b> associated with the
     * <b>PhysicalBOMLine</b> to the Neutral <b>ItemRevision</b> associated with the <b>NeutralBOMLine</b>.
     * It also saves <b>StructureContext</b> associated with the Neutral Structure, with
     * <b>PhysicalPartRevision</b>. You can rebase the <b>PhysicalPartRevision</b> to the
     * different revision of the <b>Item</b> than the existing.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param inputData
     *        Structures which holds the required information to rebase the <b>PhysicalPartRevision</b>.
     *
     * @return
     *         Structures comprising of modified <b>PhysicalBOMLine</b>  along with the <code>ServiceData</code>
     *         is returned. Any failure will be returned with <code>clientId</code> mapped to error
     *         message in the <code>ServiceData</code> list of partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237044&nbsp;&nbsp;&nbsp;&nbsp;If the <b>Item</b>
     *         is not a valid MRO neutral <b>Item</b>. This error is thrown if the Business Object
     *         Constant "<i>IsMRONeutralType</i>" is not set to "true" for the <b>Item</b>'s class
     *         in BMIDE.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237052&nbsp;&nbsp;&nbsp;&nbsp;The <b>PhysicalPartRevision</b>
     *         for which the rebase action is performed is not latest.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs when the <b>PhysicalPart</b> is not uniquely identified in the system. This
     *         check is done for the serialized <b>PhysicalPart</b>. The Part number, serial number
     *         and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237053&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs when the <b>PhysicalPartRevision</b> is not released.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237056&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs when the rebase date is less than the effective from date of <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs when the Physical Structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Mrocore::_2009_06::Mrocore::RebasePhysPartResponse rebasePhysicalPart ( const std::vector< Teamcenter::Services::Mrocore::_2009_06::Mrocore::RebasePhysPartInputInfo >& inputData ) = 0;

    /**
     * This operation records the utilization for the <b>PhysicalPart</b>. <b>Utilization</b>
     * can be recorded for the <b>CharacteristicsDefinition</b> associated to neutral <b>Item</b>
     * for which the <b>PhysicalPart</b> is realized from.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param info
     *        Structures which hold the required information to record the utilization for the
     *        <b>PhysicalPart</b>.
     *
     * @return
     *         The <b>LogEntry</b> created for the recording is returned as output. Any failure
     *         will be returned with <code>clientId</code> mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc"> 237051                                       This error occurs when
     *         the <b>PhysicalPart</b> is not uniquely identified in the system. This check is done
     *         for the serialized <b>PhysicalPart</b>. The Part number, serial number and Manufacturing
     *         id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237065&nbsp;&nbsp;&nbsp;&nbsp;The error occurs
     *         if the recording date is either a future date or not a valid date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237066 &nbsp;&nbsp;&nbsp;&nbsp;The error
     *         occurs If the recorded at date is earlier to <b>PhysicalPartRevision</b> effective
     *         date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237092 &nbsp;&nbsp;&nbsp;&nbsp;The error
     *         occurs if the utilization already exists for the specified <b>CharacteristicsDefinition</b>
     *         at specified time for a <b>PhysicalPart</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Mrocore::_2009_06::Mrocore::RecordUtilizationResponse recordUtilization ( const std::vector< Teamcenter::Services::Mrocore::_2009_06::Mrocore::RecordUtilizationInputInfo >& info ) = 0;

    /**
     * This operation creates <b>MroBOMWindow</b> and applies the <b>RevisionRule</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param input
     *        A list of structures which hold the required information to create <b>BOMwindows</b>.
     *
     * @return
     *         The created <b>BOMWindow</b> is returned in the created objects list of the <code>ServiceData</code>.
     *         Any failure will be returned with <code>clientId</code> mapped to error message in
     *         the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Services::Mrocore::_2010_04::Mrocore::CreateMROBOMWindowsResponse createMROBOMWindows ( const std::vector< Teamcenter::Services::Mrocore::_2010_04::Mrocore::CreateMROBOMWindowsInfo >& input ) = 0;

    /**
     * This operation duplicates the physical structure. <b>PhysicalBOMLine</b> is provided
     * to identify the structure to duplicate and the <i>Serial Number, Lot Number, Manufacturer
     * Id, Installation Date, Manufacturing Date, Number of Levels</i> etc. is provided
     * to create the top <b>PhysicalPart</b> object. If the global constant <i>ReuseAuthorizedDeviation</i>
     * is set to true then the deviation authority is reused in the duplicated structure.
     * The structure below the <b>PhysicalPart</b> with usage as "<i>Extra to Design</i>"
     * is not duplicated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param inputData
     *        Structures which hold the information to duplicate the Physical Structure like <b>PhysicalBOMLine</b>
     *        and structure <i>DuplicatePhysStructInfo</i> which holds the information <i>Serial
     *        Number, Lot Number, Manufacturer Id, Installation Date, Manufacturing Date, Number
     *        of Levels</i> etc.
     *
     * @return
     *         The duplicated <b>PhysicalPartRevision</b> is returned along with <code>ServiceData</code>.
     *         Any failure will be returned with <code>clientId</code> mapped to error message in
     *         the <code>ServiceData</code> list of partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when specified Installation Date for a <b>PhysicalPart</b> is
     *         earlier than its Manufacturing Date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237030&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when serial number generation scheme is not defined for selected
     *         part.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237031&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when the lot size for a specified <b>Lot</b> is exhausted and
     *         no more physical part can exist for that <b>Lot</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237032&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when the lot number specified is invalid and no such Lot exists
     *         in the system.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when the <b>PhysicalPart</b> is not uniquely identified in the
     *         system. This check is done for the serialized <b>PhysicalPart</b>. The<i> Part number,
     *         serial number and Manufacturing id</i> is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237069&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when the <b>Lot</b><i> Expiration Date</i> for <b>Lot</b> is
     *         earlier than manufacturing date while assigning the <b>Lot</b> to the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237075&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when The <i>Serial Number</i> once assigned to a <b>PhysicalPart</b>
     *         cannot be unset, it can be changed.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237086&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         This error occurs when duplicating the structure if the <i>Manufacturing dat</i>e
     *         specified is greater than the current date.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Mrocore::_2010_04::Mrocore::DuplicatePhysStructResponse duplicatePhysicalStructure ( const std::vector< Teamcenter::Services::Mrocore::_2010_04::Mrocore::DuplicatePhysStructInputInfo >& inputData ) = 0;

    /**
     * This operation renames the <b>PhysicalPart</b> by modifying the modifying either
     * Serial Number or Part Number or both. If the <b>PhysicalPart</b> is not as-built
     * <b>PhysicalPart</b> and the <b>PhysicalPartRevision</b> is released then the <b>PhysicalPart</b>
     * is revised otherwise the latest <b>PhysicalPartRevision</b> is updated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param inputInfo
     *        Structures which hold the required information to rename the <b>PhysicalPart</b>.
     *
     * @return
     *         The new <b>PhysicalPartRevision</b> is returned in case of the <b>PhysicalPartRevision</b>
     *         is released otherwise modified <b>PhysicalPartRevision</b> is returned. Any failure
     *         will be returned with <code>clientId</code> mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051
     *         This error occurs when the <b>PhysicalPart</b> is not uniquely identified in
     *         the system. This check is done for the serialized <b>PhysicalPart</b>. The Part number,
     *         serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237052
     *         This error occurs when the <b>PhysicalPartRevision</b> to rename is not latest.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237048
     *         This error occurs when the <b>PhysicalPartRevision</b> is as-built revision and
     *         is released.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237090
     *         This error occurs when the date specified is less than the effective from date
     *         of <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237091
     *         This error occurs when the date specified is either a future date or not a valid
     *         date.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Mrocore::_2010_04::Mrocore::RenamePhysicalPartResponse renamePhysicalPart ( const std::vector< Teamcenter::Services::Mrocore::_2010_04::Mrocore::RenamePhysicalPartInputInfo >& inputInfo ) = 0;

    /**
     * This operation gets the utilization data till the date specified for a <b>PhysicalPart</b>.
     * The data is represented by <b>Utilization</b> object. <b>Utilization</b> object contains
     * the information like Characteristic Name, Characteristic Unit, Time Since New, Last
     * Recorded Value etc.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param inputInfo
     *        The information to capture the utilization data for a <b>PhysicalPart</b>.
     *
     * @return
     *         The list of <b>Utilization</b> object containing the utilization data for <b>PhysicalPart</b>
     *         is returned along with the <code>ServiceData</code>. Any failure will be returned
     *         with <code>clientId</code> mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Mrocore::_2012_02::Mrocore::DisplayUtilizationResponse displayUtilization ( const std::vector< Teamcenter::Services::Mrocore::_2012_02::Mrocore::DisplayUtilizationInfo >& inputInfo ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MrocoreService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/mrocore/MROCore_undef.h>
#endif

