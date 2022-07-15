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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_03_MEASUREMENTDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_03_MEASUREMENTDATAQUERY_HXX



#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/productionmanagement/ProductionManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Productionmanagement
        {
            namespace _2008_03
            {
                class Measurementdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataquery
{
public:

    struct Event;
    struct EventResults;
    struct QueryActiveOrDeactiveDataResponse;
    struct SearchCriteria;

    /**
     * The Event structure is used to show the output result.
     */
    struct Event
    {
        /**
         * ID associated with the measurement event
         */
        std::string eventSysId;
        /**
         * Build label for the measurement event
         */
        std::string buildLabel;
        /**
         * The type of event such as "<i>N</i>"(Normal), "<i>H</i>"(Hold) and "<i>D</i>"(Duplicate)
         */
        std::string eventType;
        /**
         * The date and time at which the event (<code>eventSysId</code>) was measured
         */
        std::string eventDatetime;
        /**
         * The vehicle program associated with the routine
         */
        std::string vehicleProgram;
        /**
         * Phase for e.g. production and pre-production, during which the event is measured
         */
        std::string phaseName;
        /**
         * Plant ID in which the routine is measured
         */
        std::string plantId;
        /**
         * Item ID of the routine which is measured
         */
        std::string routineId;
        /**
         * Revision associated with the <code>routineId</code>
         */
        std::string routineRev;
        /**
         * Device type of the measurement event such as "CMM", "Vision" an "Hand Held"
         */
        std::string deviceType;
        /**
         * Name of the measured part
         */
        std::string partName;
        /**
         * Device used to measure the event of the routine
         */
        std::string device;
        /**
         * Shift with possible values of "<i>0</i>","<i>1</i>","<i>2</i>","<i>3</i>", or "<i>4</i>"
         */
        int shiftNumber;
        /**
         * The UTC time in "dd-mon-yy HH24:MI:SS" format
         */
        std::string utcTime;
        /**
         * Is the production day which may not be the same as calendar day for e.g. all events
         * measured after 10 pm the previous day may have the <code>shiftDay</code> of today
         */
        std::string shiftDay;
        /**
         * A value which specifies if the routine is measured with high or low frequency
         */
        std::string hiLow;
        /**
         * Specifies the active status of the event ("<i>1</i>" for active and "<i>0</i>" for
         * inactive)
         */
        int active;
    };

    /**
     * The EventResults structure is used to show the output
     */
    struct EventResults
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with the input structure
         * <br>
         */
        std::string clientId;
        /**
         * Data associated with measurement event such as device type, part name, etc
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataquery::Event > eventsSet;
    };

    /**
     * The QueryActiveOrDeactiveDataResponse structure is used to return the all column
     * of the DIS_MEASMT_EVENT table and servicedata
     */
    struct QueryActiveOrDeactiveDataResponse
    {
        /**
         * A list of event results with data associated with measurement event such as device
         * type, part name, etc
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataquery::EventResults > events;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The SearchCriteria structure is used to get active or deactive measurement data
     */
    struct SearchCriteria
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with the input structure
         */
        std::string clientId;
        /**
         * ID of the plant for the search criteria
         */
        std::string plantId;
        /**
         * ID of the routine for the search criteria
         */
        std::string routineId;
        /**
         * The start date and time associated with the search criteria
         */
        Teamcenter::Soa::Common::DateTime fromDate;
        /**
         * The end date and time associated with the search criteria
         */
        Teamcenter::Soa::Common::DateTime toDate;
        /**
         * Job Serial Number (JSN): An alphabetic and/or numeric combination that identifies
         * a collection of measurement data resulting from a specific analysis job or assembly
         * build. Such data generally  records the measured location of holes, pins, slots,
         * tabs  and surface planes for each manufactured part or assembly
         */
        std::string jsn;
        /**
         * This is string value to specify what data to get ("<i>ACTIVE</i>": active events,
         * "<i>INACTIVE</i>": inactive events, "<i>ALL</i>": active and inactive events)
         */
        std::string activeInactive;
    };




    /**
     * This operation gives the measurement event information stored in the DIS_MEASMT_EVENT
     * table.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * DPVMeasurements functionality in Teamcenter rich client can be used to display measurement
     * event values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param searchCriterion
     *        The criteria to filter for the measurement event such as plant ID, active status,
     *        build labels, from and to dates.
     *        <br>
     *
     * @return
     *         The measurement event data and the associated feature attribute measurement values,
     *         as well as, the <code>ServiceData</code>. The <code>ServiceData</code>  holds model
     *         objects and partial errors. No model objects are returned in this operation. Also,
     *         no specific partial error is returned by this operation and only errors from underlying
     *         subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataquery::QueryActiveOrDeactiveDataResponse queryActiveOrDeactiveData ( const std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataquery::SearchCriteria >& searchCriterion ) = 0;


protected:
    virtual ~Measurementdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

