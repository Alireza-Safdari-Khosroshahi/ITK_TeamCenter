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

#ifndef TEAMCENTER_SERVICES_MROCORE__2010_04_MROCORE_HXX
#define TEAMCENTER_SERVICES_MROCORE__2010_04_MROCORE_HXX

#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/PhysicalBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/mrocore/MROCore_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Mrocore
        {
            namespace _2010_04
            {
                class Mrocore;

class TCSOAMROCORESTRONGMNGD_API Mrocore
{
public:

    struct CreateMROBOMWindowsInfo;
    struct CreateMROBOMWindowsOutput;
    struct CreateMROBOMWindowsResponse;
    struct DuplicatePhysStructInfo;
    struct DuplicatePhysStructInputInfo;
    struct DuplicatePhysStructOutput;
    struct DuplicatePhysStructResponse;
    struct RenamePhysicalPartInputInfo;
    struct RenamePhysicalPartOutput;
    struct RenamePhysicalPartResponse;

    /**
     * Structure represents the parameters required to create a <b>MroBOMWindow</b> object.
     */
    struct CreateMROBOMWindowsInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object, required to configure the <b>MroBOMWindow</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
    };

    /**
     * Structure represents the output parameters of createMroBOMWindow operation.
     */
    struct CreateMROBOMWindowsOutput
    {
        /**
         * The <code>clientId</code> from the input CreateMROBOMWindowsInfo element. This value
         * is unchanged from the input, and can be used to identify this response element with
         * the corresponding input element.
         */
        std::string clientId;
        /**
         * The created object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
    };

    /**
     * Structures containing the created <b>MroBOMWindow</b> objects along with the <code>ServiceData</code>.
     */
    struct CreateMROBOMWindowsResponse
    {
        /**
         * A list of created <b>MroBOMWindow</b> objects.
         */
        std::vector< Teamcenter::Services::Mrocore::_2010_04::Mrocore::CreateMROBOMWindowsOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to create the root <b>PhysicalPart</b>
     * object.
     */
    struct DuplicatePhysStructInfo
    {
        /**
         * The Serial Number, required to uniquely identify a serialized <b>PhysicalPart</b>.
         */
        std::string serialNumber;
        /**
         * The Lot Number,  if the <b>PhysicalPart</b> is of Lot type.
         */
        std::string lotNumber;
        /**
         * The Manufacturer's id, required to uniquely identify a serialized <b>PhysicalPart</b>.
         */
        std::string manufacturerId;
        /**
         * The location where the <b>PhysicalPart</b> is.
         */
        std::string locationName;
        /**
         * The disposition for the <b>PhysicalPart</b>. The default disposition is In Service.
         */
        std::string dispositionType;
        /**
         * Installation Date
         */
        Teamcenter::Soa::Common::DateTime installationDate;
        /**
         * The date on which the <b>PhysicalPart</b> was manufactured.
         */
        Teamcenter::Soa::Common::DateTime manufacturingDate;
        /**
         * If <b>SerialNumberGenerators</b> are to be used to generate the Serial Numbers for
         * the <b>PhysicalPart</b> object.
         */
        bool useSrlNoGen;
        /**
         * An integer which indicates the depth of the design <b>Item</b> structure to be traversed
         * for generating the as-built <b>PhysicalPart</b> structure.
         */
        int numberOfLevels;
    };

    /**
     * Structure represents the parameters required to duplicate the physical structure.
     */
    struct DuplicatePhysStructInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object to identify the structure to duplicate.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physicalBOMLine;
        /**
         * Contains the information to create the root <b>PhysicalPart</b>. It contains the
         * information like the Serial Number, Lot Number, Manufacturer Id, Installation Date,
         * Manufacturing Date, Number of Levels etc.
         */
        Teamcenter::Services::Mrocore::_2010_04::Mrocore::DuplicatePhysStructInfo duplicatePhysStructInfo;
    };

    /**
     * Structure contains the duplicate <b>PhysicalPartRevision</b> object.
     */
    struct DuplicatePhysStructOutput
    {
        /**
         * The <code>clientId</code> from the input <code>DuplicatePhysStructInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The top level object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  physicalPartRevision;
    };

    /**
     * Structure contains the duplicated <b>PhysicalPart</b> and <code>ServiceData</code>.
     */
    struct DuplicatePhysStructResponse
    {
        /**
         * Duplicated <b>PhysicalPart</b> object.
         */
        std::vector< Teamcenter::Services::Mrocore::_2010_04::Mrocore::DuplicatePhysStructOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to rename the <b>PhysicalPartRevision</b>.
     */
    struct RenamePhysicalPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object for which its revision is renamed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physBOMLine;
        /**
         * The object to rename.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  physPartRev;
        /**
         * Part number to modify.
         */
        std::string newPartNumber;
        /**
         * Serial Number to modify.
         */
        std::string newSerialNumber;
        /**
         * The rename date.
         */
        Teamcenter::Soa::Common::DateTime renameDate;
    };

    /**
     * Structure represents the output parameters of rename <b>PhysicalPart</b> operation.
     */
    struct RenamePhysicalPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>RenamePhysicalPartInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * If the <b>PhysicalPart</b> is revised then it contains the new revision else the
         * modified revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  newPhysPartRev;
    };

    /**
     * Structures containing the new <b>PhysicalPartRevision</b> object along with the <code>ServiceData</code>.
     */
    struct RenamePhysicalPartResponse
    {
        /**
         * A list of modified objects.
         */
        std::vector< Teamcenter::Services::Mrocore::_2010_04::Mrocore::RenamePhysicalPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Mrocore() {}
};
            }
        }
    }
}

#include <teamcenter/services/mrocore/MROCore_undef.h>
#endif

