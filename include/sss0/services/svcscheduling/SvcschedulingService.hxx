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

#ifndef SSS0_SERVICES_SVCSCHEDULING_SVCSCHEDULINGSERVICE_HXX
#define SSS0_SERVICES_SVCSCHEDULING_SVCSCHEDULINGSERVICE_HXX

#include <sss0/services/svcscheduling/_2012_02/Svcscheduling.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <sss0/services/svcscheduling/SvcScheduling_exports.h>

namespace Sss0
{
    namespace Services
    {
        namespace Svcscheduling
        {
            class SvcschedulingService;

/**
 * Contains SvcScheduling services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libsss0soasvcschedulingstrongmngd.dll
 * </li>
 * <li type="disc">libsss0soasvcschedulingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class SSS0SOASVCSCHEDULINGSTRONGMNGD_API SvcschedulingService
    : public Sss0::Services::Svcscheduling::_2012_02::Svcscheduling
{
public:
    static SvcschedulingService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation will record utilization for the selected Job Activity based on the
     * input <code>RecordUtilizationInputInfo</code> supplied. A Job Activity comprises
     * of Job Cards and Job Tasks. The <code>RecordUtilizationInputInfo</code> contains
     * information for properties such as jobActivityRev, logBook, recordedAt, capturedBy,
     * propagate and valueInput that indicates the values recorded for the selected object.
     * A user can track and record utilization information based on life, observation, and
     * date characteristic definitions for the following objects:
     * <br>
     * <ul>
     * <li type="disc">Job Cards
     * </li>
     * <li type="disc">Job Tasks
     * </li>
     * <li type="disc">Physical Part
     * </li>
     * </ul>
     * <br>
     * When a user captures the utilization values for a Job Card or Job Task, the user
     * has the option of recording the characteristic definition values for the impacted
     * part related to the Job Card. If the Job Card does not have a related impacted part,
     * the physical asset related to the Job Card is used. The user recording values for
     * a physical asset will need to ensure that characteristic definitions are already
     * assigned to the related realized neutral item before the physical part was generated.
     * During execution of a Job Card or Job Task, validation ensures that the user cannot
     * record characteristic values under three conditions:
     * <br>
     * <ul>
     * <li type="disc">The selected Job Card is marked for upgrade.
     * </li>
     * <li type="disc">The Job Activity is a non leaf level Job Card or Job Task.
     * </li>
     * <li type="disc">Part Movements exist on the Job Card or Job Task.
     * </li>
     * </ul>
     * <br>
     * Execution of a Job Activity Revision validates that all characteristic definitions
     * assigned to the object are captured. A configurable condition will determine if the
     * completion of the task is not permitted and appropriate warning message is issued.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case 1: Record Collected Characteristics</b>
     * <br>
     * Record Utilization allows the user to capture characteristic values that are recorded
     * during the execution of the Job Card or Job Task. The values recorded do not need
     * to be defined as required characteristics. If the characteristics being recorded
     * are the same as a characteristic that can be recorded on the impacted physical part,
     * then that value could also be recorded on that physical part. This action can be
     * performed directly from the object or a Worklist assignment.
     * <br>
     * <b>Use Case 2: Validate Characteristics Recorded</b>
     * <br>
     * Validations are performed to ensure that all of the characteristics defined for a
     * Job Card or Job Task have been recorded prior to completion. The system can be configured
     * to either provide a warning, or prevent completion of the task if this validation
     * fails.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BOM Grading - Functionality for grading a BOM structure
     *
     * @param inputs
     *        <code>RecordUtilizationInputInfo</code> that will be used to record values for the
     *        assigned characteristics defined for the selected Job Activity or Physical Part.
     *
     * @return
     *         The objects which have the utilization values recorded are returned in <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData recordUtilization ( const std::vector< Sss0::Services::Svcscheduling::_2012_02::Svcscheduling::RecordUtilizationInputInfo >& inputs ) = 0;

    /**
     * This operation updates physical asset configuration of the impacted part on Job Activity
     * Revision based on the Part Movements and Upgrades defined on it. The configuration
     * gets updated upon the completion of the Job Activity. A Job Activity encompasses
     * of Job Card and Job Task. The user updates the physical configuration from a Job
     * Card or Job Task to perform the following tasks:
     * <br>
     * <ul>
     * <li type="disc">Execute the physical structure Part Movements related to the Job
     * Activity.
     * </li>
     * <li type="disc">Rebase the impacted physical asset for a Job Card, if the Job Card
     * is of type Upgrade.
     * </li>
     * </ul>
     * <br>
     * A Part Movement is a record of each physical part that is installed, replaced or
     * uninstalled as a result of the execution of a Job Card or Job Task. Each install
     * or uninstall of a physical part must have a unique part movement record. A user can
     * create three types of Part Movements, Uninstall, Install and Replace.
     * <br>
     * To ensure the correct physical configuration is set, validations are performed where
     * Part Movements cannot be added to a Job Activity under the following three circumstances:
     * <br>
     * <ul>
     * <li type="disc">Job Cards or Job Tasks with related assigned characteristic values.
     * </li>
     * <li type="disc">Job Cards designated as upgrades.
     * </li>
     * <li type="disc">Job Cards or Job Tasks which are not at the leaf level.
     * </li>
     * </ul>
     * <br>
     * A user can define Upgrade Job Cards to primarily handle upgrades by identifying a
     * different neutral configuration assigned to the impacted physical asset related to
     * the Job Card. If the selected Job Card does not have an impacted part, the physical
     * part defined for the Job Card is used. Update Configuration is used to rebase the
     * physical asset to a new configuration, part number or revision after the user has
     * set up an Upgrade on the Job Card. To confirm that the correct physical configuration
     * is used, validations are carried out and Upgrades cannot be defined on the Job Card
     * under the following three conditions:
     * <br>
     * <ul>
     * <li type="disc">The Job Card has Part Movements defined.
     * </li>
     * <li type="disc">The Job Card has characteristic definitions assigned.
     * </li>
     * <li type="disc">The Job Card is a non leaf level Job Activity.
     * </li>
     * </ul>
     * <br>
     * The input parameter, <code>UpdateConfigurationInputInfo</code> is supplied to the
     * operation which contains information for properties such as jobActivityRev and configUpdateDate
     * that represents the date the physical configuration was updated.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation provides the ability to update the configuration of the physical structure
     * based on the recorded Part Movement or Job Card Upgrade. This action occurs upon
     * completion and closure of the Job Card or Job Task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BOM Grading - Functionality for grading a BOM structure
     *
     * @param inputs
     *        <code>UpdateConfigurationInputInfo</code> that will be used to update the physical
     *        configuration for the defined Job Card Upgrades and Part Movements on the selected
     *        Job Activity.
     *
     * @return
     *         The objects which have the configuration values updated are returned in <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateConfiguration ( const std::vector< Sss0::Services::Svcscheduling::_2012_02::Svcscheduling::UpdateConfigurationInputInfo >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SvcschedulingService")

};
        }
    }
}


#pragma warning ( pop )

#include <sss0/services/svcscheduling/SvcScheduling_undef.h>
#endif

