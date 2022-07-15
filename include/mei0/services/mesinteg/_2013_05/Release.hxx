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

#ifndef MEI0_SERVICES_MESINTEG__2013_05_RELEASE_HXX
#define MEI0_SERVICES_MESINTEG__2013_05_RELEASE_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mei0/services/mesinteg/MESInteg_exports.h>

namespace Mei0
{
    namespace Services
    {
        namespace Mesinteg
        {
            namespace _2013_05
            {
                class Release;

class MEI0SOAMESINTEGSTRONGMNGD_API Release
{
public:

    struct UnitEffectivityInfo;
    struct ApplyReleaseStatusToLinesInputData;
    struct CreatedBopWindowInfo;
    struct ReleaseCandidatesDeltaReleaseInfo;
    struct ReleaseCandidatesFullReleaseInfo;
    struct CreateReleaseUpdatePackageInputData;
    struct CreateReleaseUpdatePackageResponse;
    struct FindReleaseCandidatesInputData;
    struct FindReleaseCandidatesResponse;
    struct IsUpdateAllowedResponse;
    struct OpenPreviousReleasedVersionResponse;
    struct PreviousReleaseInfo;

    /**
     * Map of Business Object to Vecotr of Business Object
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > MapBOtoBOVec;

    /**
     * Unit effectivity details.
     */
    struct UnitEffectivityInfo
    {
        /**
         * The Effectivity end item.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endItem;
        /**
         * The Effectivity end item revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endItemRev;
        /**
         * The order ID which is saved on the Effectivity object.
         */
        int orderId;
    };

    /**
     * Release status details to be applied to the lines.
     */
    struct ApplyReleaseStatusToLinesInputData
    {
        /**
         * The Mfg0BvrProcess and Mfg0BvrOperation to be traversed.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > roots;
        /**
         * The ReleaseStatus to be created from the string.
         */
        std::string releaseStatus;
        /**
         * The input parameters in order to create the Effectivity object.
         */
        Mei0::Services::Mesinteg::_2013_05::Release::UnitEffectivityInfo unitEffectivityInfo;
        /**
         * True to expend below the structure from the roots to the leaves, otherwise use only
         * the root object.
         */
        bool isRecursive;
    };

    /**
     * The configuration details of the BOP window and the top line information.
     */
    struct CreatedBopWindowInfo
    {
        /**
         * The context of the BOPWindow.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * The top line of the BOPWindow.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };

    /**
     * Information about Release Candidates.
     */
    struct ReleaseCandidatesDeltaReleaseInfo
    {
        /**
         * A list of Mfg0BvrProcess and  Mfg0BvrOperation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > releaseCandidatesFromReleaseStatus;
        /**
         * The key will be the IncrementalChange and the value is the list of Mfg0BvrProcess
         * and Mfg0BvrOperation affected by.
         */
        MapBOtoBOVec releaseCandidatesWithIncrementalChange;
    };

    /**
     * The structure has the additional information in case that the user exports the entire
     * structure and not just a delta export.
     */
    struct ReleaseCandidatesFullReleaseInfo
    {
        /**
         * The Mei0ExecutionPlan (Derives from CCObject) to be exported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  executionPlan;
        /**
         * A list of sites to export the data.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetSites;
    };

    /**
     * A vector of objects that holds all the release candidates objects and ICs for the
     * created workflow.
     */
    struct CreateReleaseUpdatePackageInputData
    {
        /**
         * Information about Release Candidates.
         */
        Mei0::Services::Mesinteg::_2013_05::Release::ReleaseCandidatesDeltaReleaseInfo deltaReleaseinfo;
        /**
         * The structure has the additional information in case that the user exports the entire
         * structure and not just a delta export.
         */
        Mei0::Services::Mesinteg::_2013_05::Release::ReleaseCandidatesFullReleaseInfo fullReleaseInfo;
        /**
         * True in case that a full release update, false in case of a delta release
         */
        bool fullReleaseUpdate;
        /**
         * The EPMTaskTemplate to be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  workflowTemplate;
        /**
         * The Mei0ReleaseUpdateToMesInfo form or any other customized form with the export
         * additional information to be attached to the workflow.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  infoForm;
    };

    /**
     * The results of the created workflow
     */
    struct CreateReleaseUpdatePackageResponse
    {
        /**
         * The list of created EPMJob.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > workflows;
        /**
         * The list of errors Partial Errors are returned in the ServiceData:  286520:   A full
         * export had not been created primary to releasing an update. 286523:   Cannot have
         * more than a single BOPWindow configured in the structure. 286524: The EPMTaskTemplate
         * does not exist. 286525: The object is not valid to be export, the object ID and name
         * will be supplied.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The input structure contains the data we need in order to find the release candidates
     * Lines or ICs for release and Release to the MES system
     */
    struct FindReleaseCandidatesInputData
    {
        /**
         * The context of the BOP window.Currently will be passed as NULL from the client.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * A list of Mfg0BvrProcess and Mfg0BvrOperation to be traversed.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > releaseCandidatesRoots;
        /**
         * Whether to check the incremental changes or not.
         */
        bool checkIncrementalChange;
    };

    /**
     * The results of the calculation for finding the release candidates lines from Item
     * Revisions and from ICs.
     */
    struct FindReleaseCandidatesResponse
    {
        /**
         * A list of the release candidate's information.
         */
        std::vector< Mei0::Services::Mesinteg::_2013_05::Release::ReleaseCandidatesDeltaReleaseInfo > releaseCandidatesInformationList;
        /**
         * Including partial errors These errors will be returned in the serviceData as partial
         * errors:- 286520:   A full export had not been created primary to releasing an update.
         * 286523:   Cannot have more than a single BOPWindow configured in the structure. 286525:
         * The object is not valid to be export, the object ID and name will be supplied.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response.
     */
    struct IsUpdateAllowedResponse
    {
        /**
         * A list of structures which contains the information regarding the previous release
         * and export for the same Mei0ExecutionPlan object.
         */
        std::vector< Mei0::Services::Mesinteg::_2013_05::Release::PreviousReleaseInfo > previousReleaseInformationList;
        /**
         * The list of errors Partial Errors are returned in the ServiceData: 286523: Cannot
         * have more than a single BOPWindow configured in the structure.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * OpenPreviousReleasedVersionResponse
     */
    struct OpenPreviousReleasedVersionResponse
    {
        /**
         * The returned CreatedBopWindowInfo.
         */
        std::vector< Mei0::Services::Mesinteg::_2013_05::Release::CreatedBopWindowInfo > createdWindowInfo;
        /**
         * These errors will be returned in the serviceData as partial errors. 286520:&nbsp;&nbsp;&nbsp;&nbsp;A
         * full export had not been created primary to releasing an update. 286523:Cannot have
         * more than a single BOPWindow configured in the structure.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains the information regarding the previous release and export which had already
     * done for the same Mei0ExecutionPlan object.
     */
    struct PreviousReleaseInfo
    {
        /**
         * The AppInterface used for the previous export.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  appInterface;
        /**
         * The Boolean result of this operation. Is true if the RequestObject was found otherwise
         * false.
         */
        bool isAllowed;
    };




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


protected:
    virtual ~Release() {}
};
            }
        }
    }
}

#include <mei0/services/mesinteg/MESInteg_undef.h>
#endif

