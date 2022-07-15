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

#ifndef SCP0_SERVICES_SUBSTANCECOMPLIANCE__2012_09_SUBSTANCECOMPLIANCE_HXX
#define SCP0_SERVICES_SUBSTANCECOMPLIANCE__2012_09_SUBSTANCECOMPLIANCE_HXX

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <scp0/services/substancecompliance/SubstanceCompliance_exports.h>

namespace Scp0
{
    namespace Services
    {
        namespace Substancecompliance
        {
            namespace _2012_09
            {
                class Substancecompliance;

class SCP0SOASUBSCMPLSTRONGMNGD_API Substancecompliance
{
public:

    struct ExemptionDetails;
    struct FailedItemDetails;
    struct SubstanceComplianceStatusData;
    struct SubstanceComplianceSummary;
    struct SubstanceComplianceSummaryResponse;

    /**
     * ExemptionDetails contain Exemption with its expiry date related to a Complinace result
     * object
     */
    struct ExemptionDetails
    {
        /**
         * Exemption object, part of a Regulation, related to a Complinace result object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  exemption;
        /**
         * Expiry date of the Exemption for a given Complinace result object
         */
        Teamcenter::Soa::Common::DateTime expiryDate;
    };

    /**
     * Details of the failed ItemRev with failure reason
     */
    struct FailedItemDetails
    {
        /**
         * Reference to the failed Item
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  failedItem;
        /**
         * Failure Reason for the corresponding Part
         */
        std::string failureReason;
    };

    /**
     * SubstanceComplianceStatusData contains Complinace result status with number of parts
     * with the given status, e.g. if an assembly has some BOMLines with status FAIL, some
     * has status PASS, some Contional Fail etc. then each of SubstanceComplianceStatusData
     * represents status and number of parts with the given status
     */
    struct SubstanceComplianceStatusData
    {
        /**
         * Compliance status e.g. 0, 1 in int format
         */
        int status;
        /**
         * Equaivalent display name of Compliance status e.g. PASS, FAIL in String format
         */
        std::string statusDisplayName;
        /**
         * Number of parts with the given status
         */
        int numOfParts;
    };

    /**
     * SubstanceComplianceSummary contains Regulation information, related Substance Compliance
     * result for the given regulation, related exemption details and list of SubstanceComplianceStatusData
     * which contains Complinace result status with number of parts with the given status.
     */
    struct SubstanceComplianceSummary
    {
        /**
         * Regulation object against which Summary is generated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  regulation;
        /**
         * Related Substance Compliance result for the given regulation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  substanceCmplResult;
        /**
         * List of Exemptions with its expiry date related to a Complinace result object
         */
        std::vector< Scp0::Services::Substancecompliance::_2012_09::Substancecompliance::ExemptionDetails > exemptionsDetails;
        /**
         * List of SubstanceComplianceStatusData which contains Complinace result status with
         * number of parts with the given status, e.g. if an assembly has some BOMLines with
         * status FAIL, some has status PASS, some Contional Fail etc.
         */
        std::vector< Scp0::Services::Substancecompliance::_2012_09::Substancecompliance::SubstanceComplianceStatusData > substanceComplianceStatusData;
        /**
         * List of failed items with its details related to the current compliance summary.
         */
        std::vector< Scp0::Services::Substancecompliance::_2012_09::Substancecompliance::FailedItemDetails > failedItemsDetails;
    };

    /**
     * Response that contains list of SubstanceComplianceSummary which contains Regulation
     * information, related Substance Compliance result for the given regulation, related
     * exemption details, list of SubstanceComplianceStatusData which contains Complinace
     * result status with number of parts with the given status and service data.
     */
    struct SubstanceComplianceSummaryResponse
    {
        /**
         * List of SubstanceComplianceSummary information related to ItemRevision(s) or BOMLine(s)
         */
        std::vector< Scp0::Services::Substancecompliance::_2012_09::Substancecompliance::SubstanceComplianceSummary > substanceComplianceSummaries;
        /**
         * serviceData related to SubstanceComplianceSummaryResponse
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Method to query Substance Compliance summary data related to ItemRevision(s) or BOMLine(s).
     * Response to this call return substanceComplianceSummaries, which contains Regulation
     * information, related Substance Compliance result for the regulation, related exemption
     * details that contain applicable exemption with its expiry date and list of SubstanceComplianceStatusData
     * which contains Complinace result status with number of parts with the given status.
     *
     * @param objs
     *        References of ItemRevision(s) or BOMLine(s) for which Substance Complinace Summary
     *        information is/are sought.
     *
     * @return
     *         Response that contains list of SubstanceComplianceSummary which contains Regulation
     *         information, related Substance Compliance result for the given regulation, related
     *         exemption details, list of SubstanceComplianceStatusData which contains Complinace
     *         result status with number of parts with the given status and service data.
     *
     */
    virtual Scp0::Services::Substancecompliance::_2012_09::Substancecompliance::SubstanceComplianceSummaryResponse getSubstanceComplianceSummary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objs ) = 0;


protected:
    virtual ~Substancecompliance() {}
};
            }
        }
    }
}

#include <scp0/services/substancecompliance/SubstanceCompliance_undef.h>
#endif

