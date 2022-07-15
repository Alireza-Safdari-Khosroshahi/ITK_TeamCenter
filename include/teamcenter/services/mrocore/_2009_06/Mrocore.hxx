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

#ifndef TEAMCENTER_SERVICES_MROCORE__2009_06_MROCORE_HXX
#define TEAMCENTER_SERVICES_MROCORE__2009_06_MROCORE_HXX

#include <teamcenter/soa/client/model/CharacteristicDefinition.hxx>
#include <teamcenter/soa/client/model/LogBook.hxx>
#include <teamcenter/soa/client/model/LogEntry.hxx>
#include <teamcenter/soa/client/model/NeutralBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalBOMLine.hxx>


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
            namespace _2009_06
            {
                class Mrocore;

class TCSOAMROCORESTRONGMNGD_API Mrocore
{
public:

    struct CharacteristicValueInputInfo;
    struct RebasePhysPartInputInfo;
    struct RebasePhysPartOutput;
    struct RebasePhysPartResponse;
    struct RecordUtilizationInputInfo;
    struct RecordUtilizationOutput;
    struct RecordUtilizationResponse;

    /**
     * Structure contains the value to be recorded for <b>CharacteristicsDefinition</b>.
     */
    struct CharacteristicValueInputInfo
    {
        /**
         * A object  for which the value is recorded.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CharacteristicDefinition>  charDef;
        /**
         * The value to be recorded.
         */
        double value;
        /**
         * The date value to be recorded.
         */
        Teamcenter::Soa::Common::DateTime dateValue;
    };

    /**
     * Structure represents the parameters required to rebase the <b>PhysicalPartRevision</b>.
     */
    struct RebasePhysPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object to be rebased.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physicalBOMLine;
        /**
         * The object to rebase to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::NeutralBOMLine>  neutralBOMLine;
        /**
         * The rebase date.
         */
        Teamcenter::Soa::Common::DateTime rebaseDate;
        /**
         * The structure context name with which new structure context is to be saved.
         */
        std::string contextName;
    };

    /**
     * Structure represents the output parameters of rebase operation.
     */
    struct RebasePhysPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>RebasePhysPartInputInfo</code> element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The modified object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physicalBOMLine;
    };

    /**
     * Structure represents <b>BOMWindow</b> containing the modified <b>PhysicalBOMLine</b>
     * object along with the <code>ServiceData</code>.
     */
    struct RebasePhysPartResponse
    {
        /**
         * A modified <b>PhysicalBOMLine</b> object.
         */
        std::vector< Teamcenter::Services::Mrocore::_2009_06::Mrocore::RebasePhysPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to record utilization for <b>PhysicalPart</b>.
     */
    struct RecordUtilizationInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The <b>PhysicalBOMLine</b> for which the utilization is recorded.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physBOMLine;
        /**
         * The <b>LogBook</b> where the entry of this recording is associated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::LogBook>  logBook;
        /**
         * The <b>PhysicalBOMLine</b> for which the utilization is recorded.
         */
        std::string logEntryDesc;
        /**
         * The time at which the utilization is recorded.
         */
        Teamcenter::Soa::Common::DateTime recordedAt;
        /**
         * The string indicating who captured the characteristics value.
         */
        std::string capturedBy;
        /**
         * If true, the values are propagated to child <b>PhysicalPart</b> objects.
         */
        bool propagate;
        /**
         * The structure indicating the values to be recorded.
         */
        std::vector< Teamcenter::Services::Mrocore::_2009_06::Mrocore::CharacteristicValueInputInfo > valueInput;
    };

    /**
     * Structure represents the output parameters of recordUtilization operation.
     */
    struct RecordUtilizationOutput
    {
        /**
         * The <code>clientId</code> from the input <code>RecordUtilizationInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The created object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::LogEntry>  logEntry;
    };

    /**
     * Structures containing the created <b>LogEntry</b> along with the <code>ServiceData</code>.
     */
    struct RecordUtilizationResponse
    {
        /**
         * A <b>LogEntry</b> object.
         */
        std::vector< Teamcenter::Services::Mrocore::_2009_06::Mrocore::RecordUtilizationOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Mrocore() {}
};
            }
        }
    }
}

#include <teamcenter/services/mrocore/MROCore_undef.h>
#endif

