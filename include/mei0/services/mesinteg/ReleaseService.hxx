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

#ifndef MEI0_SERVICES_MESINTEG_RELEASESERVICE_HXX
#define MEI0_SERVICES_MESINTEG_RELEASESERVICE_HXX

#include <mei0/services/mesinteg/_2013_05/Release.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mei0/services/mesinteg/MESInteg_exports.h>

namespace Mei0
{
    namespace Services
    {
        namespace Mesinteg
        {
            class ReleaseService;

/**
 * Release
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmei0soamesintegstrongmngd.dll
 * </li>
 * <li type="disc">libmei0soamesintegtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class MEI0SOAMESINTEGSTRONGMNGD_API ReleaseService
    : public Mei0::Services::Mesinteg::_2013_05::Release
{
public:
    static ReleaseService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation collects all the Mfg0BvrProcess and Mfg0BvrOperation recursively from
     * the configured structure and adds a ReleaseStatus object to the non-released objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MES Integration Services Component - MES Integration Services Component supports
     * the integration with the SIT systems and general MES systems.
     *
     * @param input
     *        Release status details to be applied to the lines.
     *
     * @return
     *         The list of Mfg0BvrProcess and Mfg0BvrOperation which failed to update the ReleaseStatus
     *         will be returned in the plain object list. The following partial errors are returned
     *         in case invalid parameters are passed to the service:
     *         <br>
     *         286540: If an object with multiple effectivities is passed to the operation.
     *         <br>
     *         286541: If the provided release status cannot be applied to the object.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData applyReleaseStatusToLines ( const std::vector< Mei0::Services::Mesinteg::_2013_05::Release::ApplyReleaseStatusToLinesInputData >& input ) = 0;

    /**
     * The operation creates the workflow ReleaseUpdateToMes which exports the released
     * candidate objects to the MES system.  It is a preliminary to call the operation findReleaseCandidates
     * before calling the createReleaseUpdatePackage operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MES Integration Services Component - MES Integration Services Component supports
     * the integration with the SIT systems and general MES systems.
     *
     * @param input
     *        A vector of objects that holds all the release candidates objects and ICs for the
     *        created workflow.
     *
     * @return
     *         The results of the created workflow
     *
     */
    virtual Mei0::Services::Mesinteg::_2013_05::Release::CreateReleaseUpdatePackageResponse createReleaseUpdatePackage ( const std::vector< Mei0::Services::Mesinteg::_2013_05::Release::CreateReleaseUpdatePackageInputData >& input ) = 0;

    /**
     * The operation returns all the Mfg0BvrProcess and Mfg0BvrOperation candidates to be
     * exported to the MES system. The candidate objects will be captured in one out of
     * the two ways: 1. By a new release status Mei0PendingRelease or the status defined
     * within the preference Mei0PendingReleaseStatus added to the revision.  2. Any change
     * that was done within the incremental change which is configured in the structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MES Integration Services Component - MES Integration Services Component supports
     * the integration with the SIT systems and general MES systems.
     *
     * @param input
     *        The input structure contains the data we need in order to find the release candidates
     *        Lines or ICs for release and Release to the MES system
     *
     * @return
     *         The results of the calculation for finding the release candidates lines from Item
     *         Revisions and from ICs.
     *
     */
    virtual Mei0::Services::Mesinteg::_2013_05::Release::FindReleaseCandidatesResponse findReleaseCandidates ( const std::vector< Mei0::Services::Mesinteg::_2013_05::Release::FindReleaseCandidatesInputData >& input ) = 0;

    /**
     * The operation checks if a delta update is allowed for the Mei0ExecutionPlan.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MES Integration Services Component - MES Integration Services Component supports
     * the integration with the SIT systems and general MES systems.
     *
     * @param executionPlans
     *        The Mei0ExecutionPlan to be checked.
     *        <br>
     *        This object derives from an MECollaborationContext object.
     *
     * @return
     *         These errors will be returned in the serviceData as partial errors. 286523: Cannot
     *         have more than a single BOPWindow configured in the structure.
     *
     */
    virtual Mei0::Services::Mesinteg::_2013_05::Release::IsUpdateAllowedResponse isUpdateAllowed ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& executionPlans ) = 0;

    /**
     * This operation returns the correlative structure which had been released and exported
     * for the existing Mei0ExecutionPlan.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MES Integration Services Component - MES Integration Services Component supports
     * the integration with the SIT systems and general MES systems.
     *
     * @param executionPlans
     *        The Mei0ExecutionPlan which had been exported.
     *
     * @return
     *         Response
     *
     */
    virtual Mei0::Services::Mesinteg::_2013_05::Release::OpenPreviousReleasedVersionResponse openPreviousReleasedVersion ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& executionPlans ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ReleaseService")

};
        }
    }
}


#pragma warning ( pop )

#include <mei0/services/mesinteg/MESInteg_undef.h>
#endif

