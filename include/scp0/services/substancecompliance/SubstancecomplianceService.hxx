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

#ifndef SCP0_SERVICES_SUBSTANCECOMPLIANCE_SUBSTANCECOMPLIANCESERVICE_HXX
#define SCP0_SERVICES_SUBSTANCECOMPLIANCE_SUBSTANCECOMPLIANCESERVICE_HXX

#include <scp0/services/substancecompliance/_2012_09/Substancecompliance.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <scp0/services/substancecompliance/SubstanceCompliance_exports.h>

namespace Scp0
{
    namespace Services
    {
        namespace Substancecompliance
        {
            class SubstancecomplianceService;

/**
 * Substance Compliance service is meant to query vendor data related to Substance Compliance
 * check.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libscp0soasubstancecompliancestrongmngd.dll
 * </li>
 * <li type="disc">libscp0soasubstancecompliancetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class SCP0SOASUBSCMPLSTRONGMNGD_API SubstancecomplianceService
    : public Scp0::Services::Substancecompliance::_2012_09::Substancecompliance
{
public:
    static SubstancecomplianceService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SubstancecomplianceService")

};
        }
    }
}


#pragma warning ( pop )

#include <scp0/services/substancecompliance/SubstanceCompliance_undef.h>
#endif

