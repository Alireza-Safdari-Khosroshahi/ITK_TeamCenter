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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2010_04_MEASUREMENTDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2010_04_MEASUREMENTDATAQUERY_HXX



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
            namespace _2010_04
            {
                class Measurementdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataquery
{
public:

    struct Event2;
    struct EventResults2;
    struct FtrInfo;
    struct PlantResults;
    struct PlantsInfoResponse;
    struct QueryActiveOrDeactiveDataResponse2;
    struct RoutineResults;
    struct RoutinesInfoResponse;
    struct SearchCriteria2;
    struct TraceInfo;

    /**
     * This structure consists of Measurement Event information and a vector of corresponding
     * feature information.
     */
    struct Event2
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
         * The type of event, such as "<i>N</i>"(Normal), "<i>H</i>"(Hold), and "<i>D</i>"(Duplicate)
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
         * Phase  during which the event is measured (for example, production and pre-production)
         */
        std::string phaseName;
        /**
         * Plant ID in which the routine is measured
         */
        std::string plantId;
        /**
         * Item ID of the routine being measured
         */
        std::string routineId;
        /**
         * Revision associated with the <code>routineId</code>
         */
        std::string routineRev;
        /**
         * Device type of the measurement event, such as "<i>CMM</i>", "<i>Vision</i>" and "<i>Hand
         * Held</i>"
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
         * The production day that may not be the same as the calendar day (for example,  all
         * events measured after 10 pm the previous day may have the <code>shiftDay</code> of
         * today)
         */
        std::string shiftDay;
        /**
         * A value that specifies if the routine is measured with high or low frequency
         */
        std::string hiLow;
        /**
         * The active status of the event ("<i>1</i>" for active and "<i>0</i>" for inactive)
         */
        int active;
        /**
         * A list of feature information that includes all the features associated with the
         * measurement event
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::FtrInfo > ftrsData;
        /**
         * Certain tracking codes and values associated with the measurement event. For example,
         * the code could be "<i>Operator</i>" and the value could be "<i>Mike</i>"
         * <br>
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::TraceInfo > traceData;
    };

    /**
     * It will show the actual ouput of query; consists of Measurement Event information
     * along with corresponding Feature information.
     */
    struct EventResults2
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with the input structure
         * <br>
         */
        std::string clientId2;
        /**
         * Data associated with measurement event such as device type, part name, and so on
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::Event2 > eventsSet2;
    };

    /**
     * It is a string with feature information including feature name (feature_name), feature
     * attribute code (feature_att_code ) and actual measurement value (actual_value)  with
     * "."(dot) and ","(comma)
     * <br>
     * delimiters in the format "<i>feature_name</i>.<i>feature_att_code</i>,<i>actual_value</i>"
     * <br>
     */
    struct FtrInfo
    {
        /**
         * It is a string with feature information including feature name (feature_name), feature
         * attribute code (feature_att_code ) and actual measurement value (actual_value)  with
         * "."(dot) and ","(comma)
         * <br>
         * delimiters in the format "<i><feature_name>.<feature_att_code>,<actual_value></i>"
         * <br>
         */
        std::string ftrNameFtrAttCodeAval;
    };

    /**
     * This structure consits of Plant Information( Plant Id and Plant Name).
     */
    struct PlantResults
    {
        /**
         * Item ID of the plant
         */
        std::string plantId;
        /**
         * Name of the plant
         */
        std::string plantName;
    };

    /**
     * This structure consists of Vector which consists of a structure with the Plant Information(Plant
     * Id and Plant Name). And it has a partial errors object giving error information,
     * if any
     */
    struct PlantsInfoResponse
    {
        /**
         * A  list of structures that consist of plant ID and name
         * <br>
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::PlantResults > plantSet;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure is used to return the all columns of the DIS_MEASMT_EVENT table and
     * corresponding Feature info(Feature Name,Feature Attribute Code,Acutal Value) from
     * DIS_MEASMT_FTR_ACTUAL table.
     */
    struct QueryActiveOrDeactiveDataResponse2
    {
        /**
         * A list of event results with data associated with measurement event such as device
         * type, part name, and so on
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::EventResults2 > events2;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure consits of Routine Information( Routine Id,Routine Name and Routine
     * Revision).
     */
    struct RoutineResults
    {
        /**
         * Item ID of a routine
         */
        std::string routineId;
        /**
         * Name associated with the <code>routineId</code>
         */
        std::string routineName;
        /**
         * Revision of the <code>routineId</code>
         */
        std::string routineRev;
    };

    /**
     * This structure consists of Vector which consists of a structure with the Routine
     * Information(Routine Id ,Routine Name and Routine Revision). And it has a partial
     * errors object giving error information, if any
     */
    struct RoutinesInfoResponse
    {
        /**
         * A list of  structures that consists of routine item ID, name, and revision
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::RoutineResults > routineSet;
        /**
         * The  Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The SearchCriteria structure is used to get active or deactive mesurement data.
     */
    struct SearchCriteria2
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
         * build. Such data generally records the measured location of holes, pins, slots, tabs
         * and surface planes for each manufactured part or assembly
         */
        std::string jsn;
        /**
         * The string value to specify what data to get ("<i>ACTIVE</i>": active events, "<i>INACTIVE</i>":
         * inactive events, "<i>ALL</i>": active and inactive events)
         */
        std::string activeInactive;
    };

    /**
     * This structure contains the event trace information like trace code and event trace
     * code value.
     */
    struct TraceInfo
    {
        /**
         * Trace codes are information added to a measurement data file to define specific conditions
         * that apply to a particular measurement (for example, product variants, such as having
         * a sunroof or no sunroof)
         */
        std::string traceCode;
        /**
         * The value associated with the <code>traceCode</code> (usually for a measurement event
         */
        std::string traceCodeValue;
    };




    /**
     * This operation gives the measurement event information stored in the DIS_MEASMT_EVENT
     * table and the corresponding feature attribute measurement information, including
     * feature name, feature attribute code, and the actual measurement value from the DIS_MEASMT_FTR_ACTUAL
     * table.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The DPVMeasurements functionality in the Teamcenter rich client can be used to display
     * measurement event and corresponding feature attribute measurement values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param searchCriterion
     *        The criteria to filter for the measurement event, such as plant ID, active status,
     *        build labels, and from and to dates.
     *        <br>
     *
     * @return
     *         The measurement event data and the associated feature attribute measurement values,
     *         as well as the <code>ServiceData</code>. The <code>ServiceData</code>  holds model
     *         objects and partial errors. No model objects are returned in this operation. Also,
     *         no specific partial error is returned by this operation and only errors from underlying
     *         subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::QueryActiveOrDeactiveDataResponse2 queryActiveOrDeactiveData2 ( const std::vector< Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::SearchCriteria2 >& searchCriterion ) = 0;

    /**
     * This operation lists all the plants stored in the Teamcenter database based on the
     * <b>dpv_raw_data_location</b> Teamcenter preference value. Plant information includes
     * the plant item ID and name. If the <b>dpv_raw_data_location</b> preference value
     * is "0" the plant information will be obtained from the Teamcenter database, otherwise;
     * it is obtained from the "DPV_DB_LOCATOR" database table.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * External applications, such as Teamcenter lifecycle visualization, and internal applications,
     * such as <code>DPVMeasurements</code>, obtain the plant information before querying
     * for measurement data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @return
     *         This returns a list of plants and <code>ServiceData</code> object. The <code>ServiceData</code>
     *         holds model objects and partial errors. No model objects are returned in this operation.
     *         Also, no specific partial error is returned by this operation and only errors from
     *         underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::PlantsInfoResponse queryPlantsInfo (  ) = 0;

    /**
     * This operation will list information for routine revisions of type <b>MEInspection_Revision</b>
     * given a plant item ID. The routine information includes routine item ID, routine
     * name, and routine revision. If the Teamcenter <b>dpv_raw_data_location</b> preference
     * value is "0" the information is obtained from the DPV_MEASMT_EVENT (non-pom table)
     * in the Teamcenter database; otherwise, it is obtained from the DPV_MEASMT_EVENT table
     * in an external measurement database.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The standalone Teamcenter lifecycle visualization application queries for routine
     * information from Teamcenter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param plantId
     *        Plant item ID (of type <b>MEPrPlantProcess</b>) for which the routine information
     *        is requested
     *        <br>
     *
     * @return
     *         A list of routine information and <code>ServiceData</code>. Each routine information
     *         consists of routine item ID, name, and revision. The <code>ServiceData</code>  holds
     *         model objects and partial errors. No model objects are returned in this operation.
     *         Also, no specific partial error is returned by this operation and only errors from
     *         underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery::RoutinesInfoResponse queryRoutinesInfo ( const std::string&  plantId ) = 0;


protected:
    virtual ~Measurementdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

