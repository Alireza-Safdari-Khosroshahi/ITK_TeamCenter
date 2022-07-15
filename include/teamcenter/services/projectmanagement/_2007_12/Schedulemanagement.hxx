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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2007_12_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2007_12_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Schedule.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/projectmanagement/ProjectManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Projectmanagement
        {
            namespace _2007_12
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct DemandProfileRequest;
    struct DemandProfileResponse;
    struct DemandProfileResponses;
    struct ItemDemand;
    struct PeriodCost;

    /**
     * This represents the input structure for calculating DemandProfile data for each schedule.
     */
    struct DemandProfileRequest
    {
        /**
         * Input schedule of which DemandProfile data will be calculated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * Start of schedule Period to calculate data (MM-YYYY).
         */
        std::string startPeriod;
        /**
         * End of schedule Period to calculate data (MM-YYYY).
         */
        std::string endPeriod;
        /**
         * Number of months in the period.
         */
        int monthsInPeriod;
        /**
         * Currency to calculate the cost (ISO 4217). (Not currently used)
         */
        std::string currency;
    };

    /**
     * This represents the output structure for calculated DemandProfile data for each shecule.
     */
    struct DemandProfileResponse
    {
        /**
         * Schedule loaded for DemandProfile data.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The active baseline of the schedule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  activeBaseline;
        /**
         * Labor demand calculated for the schedule.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::ItemDemand > laborDemand;
        /**
         * Capital Demand calculated for the schedule.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::ItemDemand > capitalDemand;
        /**
         * Expense Demand calculated for the schedule.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::ItemDemand > expenseDemand;
        /**
         * Currency used in the calculations (not currently used).
         */
        std::string currency;
    };

    /**
     * This represents the DemandProfileResponses for a schedule.
     */
    struct DemandProfileResponses
    {
        /**
         * The Demand Profile Information of one schedule.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::DemandProfileResponse > response;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * This represents the output structure to store the labor demand per resource.
     */
    struct ItemDemand
    {
        /**
         * Represents the resource id of an individual labor or resource.
         */
        std::string resourceId;
        /**
         * Represents the per period cost of an individual resource.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::PeriodCost > costs;
    };

    /**
     * This represents the output structure to store the cost vasule per period.
     */
    struct PeriodCost
    {
        /**
         * Represents the period number.
         */
        int periodNum;
        /**
         * Represents the cost calculated per each period.
         */
        std::string cost;
    };




    /**
     * Calculates the demand profile data for a schedule based on the initial input request
     * to the Application Interface..
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param requests
     *        A collection of <code>DemandProfileRequest</code>'s to calculate.
     *        <br>
     *        <code>DemandProfileRequest</code>
     *        <br>
     *        <code>struct DemandProfileRequest
     *        <br>
     *        {
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;BusinessObjectRef<Teamcenter::Schedule> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;schedule
     *        <br>
     *        string &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;startPeriod
     *        <br>
     *        string &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;endPeriod
     *        <br>
     *        int&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;monthsInPeriod
     *        <br>
     *        string&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;currency
     *        <br>
     *        }</code>
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>schedule</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        Input schedule of which demand profile data will be calculated
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>startPeriod</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        Start of schedule Period to calculate data (MM-YYYY).
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>endPeriod</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        End of schedule Period to calculate data (MM-YYYY).
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>monthsInPeriod</code>   Number of months in the period.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>currency</code> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        Currency to calculate the cost (ISO 4217). (Not currently used)
     *        <br>
     *
     * @return
     *         The demand profile information and errors. The information includes the schedule,
     *         start period, end period, and months in period.
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::DemandProfileResponses getDemandProfile ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::DemandProfileRequest >& requests ) = 0;


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

