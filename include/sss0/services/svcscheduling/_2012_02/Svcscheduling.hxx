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

#ifndef SSS0_SERVICES_SVCSCHEDULING__2012_02_SVCSCHEDULING_HXX
#define SSS0_SERVICES_SVCSCHEDULING__2012_02_SVCSCHEDULING_HXX

#include <teamcenter/soa/client/model/CharacteristicDefinition.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/LogBook.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <sss0/services/svcscheduling/SvcScheduling_exports.h>

namespace Sss0
{
    namespace Services
    {
        namespace Svcscheduling
        {
            namespace _2012_02
            {
                class Svcscheduling;

class SSS0SOASVCSCHEDULINGSTRONGMNGD_API Svcscheduling
{
public:

    struct CharacteristicValueInputInfo;
    struct RecordUtilizationInputInfo;
    struct UpdateConfigurationInputInfo;

    /**
     * Characteristic Value input
     */
    struct CharacteristicValueInputInfo
    {
        /**
         * Characteristics definition
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CharacteristicDefinition>  charDef;
        /**
         * Value recorded for the characteristics
         */
        double value;
        /**
         * Date Value recorded for the characteristics
         */
        Teamcenter::Soa::Common::DateTime dateValue;
        /**
         * Record on physical part
         */
        bool forPhysicalPart;
    };

    /**
     * <code>RecordUtilizationInputInfo</code> will be used to capture characteristic values
     * for the Job Activity and the Physical Part.
     */
    struct RecordUtilizationInputInfo
    {
        /**
         * A unique client identifier. This is a unique string supplied by the caller. This
         * ID
         * <br>
         * is used to identify return data elements and partial errors associated with this
         * input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Job Card Revision or Job Task Revision. The user captures and records the
         * <br>
         * characteristics values during the execution of this selected Job Card or
         * <br>
         * Job Task Revision.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  jobActivityRev;
        /**
         * Log Book. The log book is used to record the utilization information. It
         * <br>
         * represents a collection of log entries recorded against a specific physical asset
         * or utilization details for a Job Activity Revision. The selected object may have
         * more than one associated log book. A log entry denotes a record of data collected
         * about a specific object in context, such as a physical asset and recorded by a certain
         * person at a certain point of time. The log entry value is associated with a single
         * asset but may record characteristic values for several components within that asset.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::LogBook>  logBook;
        /**
         * Log entry description. It denotes the description of the logbook and the related
         * <br>
         * utilization information recorded by the log book.
         * <br>
         */
        std::string logEntryDesc;
        /**
         * Recorded Date. This parameter represents the date the utilization values were
         * <br>
         * recorded. If a user does not enter a value for the recording time, the date is set
         * from the current date/time on the server.
         * <br>
         */
        Teamcenter::Soa::Common::DateTime recordedAt;
        /**
         * The string indicating the user who captured the values for the characteristic
         * <br>
         * definitions. This parameter takes a string of upto 128 alphanumeric characters in
         * size.
         * <br>
         */
        std::string capturedBy;
        /**
         * Indicates if the values are to be propagated to its child physical parts. This
         * <br>
         * parameter takes in a true or false value.
         * <br>
         */
        bool propagate;
        /**
         * The structure indicating the values recorded.
         */
        std::vector< Sss0::Services::Svcscheduling::_2012_02::Svcscheduling::CharacteristicValueInputInfo > valueInput;
    };

    /**
     * <code>UpdateConfigurationInputInfo</code> will be used to capture the Job Activity
     * Revision and the Date of Configuration update.
     */
    struct UpdateConfigurationInputInfo
    {
        /**
         * A unique client identifier. This is a unique string supplied by the caller.
         * <br>
         * This ID is used to identify return data elements and partial errors associated with
         * this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Job Card Revision or Job Task Revision. The user updates the physical
         * <br>
         * configuration based on Part Movements and Job Card Upgrades defined on the Job Activity
         * Revision during the execution of this selected Job Card or Job Task Revision.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  jobActivityRev;
        /**
         * This parameter represents the date the physical configuration was
         * <br>
         * updated. If a user does not enter a value for this element, the date is set from
         * the current date/time on the server.
         * <br>
         */
        Teamcenter::Soa::Common::DateTime configUpdateDate;
    };




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


protected:
    virtual ~Svcscheduling() {}
};
            }
        }
    }
}

#include <sss0/services/svcscheduling/SvcScheduling_undef.h>
#endif

