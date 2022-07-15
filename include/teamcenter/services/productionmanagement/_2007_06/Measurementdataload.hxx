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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_06_MEASUREMENTDATALOAD_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_06_MEASUREMENTDATALOAD_HXX



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
            namespace _2007_06
            {
                class Measurementdataload;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataload
{
public:

    struct AttrLimits;
    struct FtrActual;
    struct Limit;
    struct LimitInsertResponse;
    struct LogData;
    struct LogInsertResponse;
    struct MeasmtData;
    struct MeasmtLoadResponse;
    struct NewEventInfo;
    struct TraceEvent;
    struct UpdateEventResponse;

    /**
     * The AttrLimits structure is used to give the reject or spec limits for a attribute
     */
    struct AttrLimits
    {
        /**
         * UID of the feature to which the attribute or <code>ftrattCode</code> belongs
         */
        std::string ftrUid;
        /**
         * Feature attribute code
         */
        std::string ftrattCode;
        /**
         * Lower specification limit for the attribute or <code>ftrattCode</code>
         */
        double lsl;
        /**
         * Upper specification limit for the attribute or <code>ftrattCode</code>
         */
        double usl;
    };

    /**
     * The FtrActual structure is used to give details of measurement made for an attribute
     */
    struct FtrActual
    {
        /**
         * ID of the feature
         */
        std::string ftrUid;
        /**
         * Name of the feature
         */
        std::string ftrName;
        /**
         * Feature attribute code
         */
        std::string ftrattCode;
        /**
         * The measured value for the feature attribute for a given measurement event
         */
        double actualValue;
    };

    /**
     * The Limit structure is used to give the reject or spec limit information
     */
    struct Limit
    {
        /**
         * Item ID of the plant. This is used to identify the measurement database
         */
        std::string plantId;
        /**
         * Item ID of the routine
         */
        std::string routineId;
        /**
         * Revision of the routine
         */
        std::string routineRev;
        /**
         * Device type of the measurement event, such as '<i>CMM</i>', '<i>Vision</i>' and '<i>Hand
         * Held</i>'
         */
        std::string deviceType;
        /**
         * Creation time in "dd-mon-yy HH24:MI:SS" format
         */
        std::string creationTime;
        /**
         * Success or failure of limit insertion. Fails even if one of the limit insertions
         * fail
         */
        bool success;
        /**
         * List of attribute specification limits
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::AttrLimits > ftrLimits;
    };

    /**
     * The LimitInsertResponse structure is used to return the status of insertions
     */
    struct LimitInsertResponse
    {
        /**
         * The  Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The LogData structure is used to give event data to be inserted
     */
    struct LogData
    {
        /**
         * Event date time in "dd-mon-yy HH24:MI:SS" format
         */
        std::string eventTime;
        /**
         * Upload time in "dd-mon-yy HH24:MI:SS" format
         */
        std::string uploadTime;
        /**
         * Item id of the plant
         */
        std::string plantId;
        /**
         * Device identifier for the measurement event
         */
        std::string deviceId;
        /**
         * Job sequence number or label for the measurement event
         */
        std::string jsn;
        /**
         * Item ID of type "<b>InspectionDevice</b>" for the parsing script that processes the
         * measurement event data
         */
        std::string scriptId;
        /**
         * Script revision of the <code>scriptId</code>
         */
        std::string scriptRev;
        /**
         * Item ID of the routine
         */
        std::string routineId;
        /**
         * Name of the routine
         */
        std::string routineName;
        /**
         * Feature label pertaining to the <code>errorCode</code>
         */
        std::string fileName;
        /**
         * URL of device that measures the routine for the measurement event
         */
        std::string urlToDevice;
        /**
         * Feature Name
         */
        std::string featureName;
        /**
         * Attribute code pertaining to the <code>errorCode</code>
         */
        std::string attributeId;
        /**
         * Error code for the measurement event
         */
        int errorCode;
        /**
         * Error message for the measurement event
         */
        std::string errorMessage;
        /**
         * Failure code for the measurement event
         */
        int iFail;
    };

    /**
     * The LogInsertResponse structure is used to return the status of insertions
     */
    struct LogInsertResponse
    {
        /**
         * Service Data object with the error messages for the failed insertions
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The MeasmtData structure is used to give event data to be inserted
     */
    struct MeasmtData
    {
        /**
         * Build label of the measurement event
         */
        std::string buildLabel;
        /**
         * Event type of the measurement event
         */
        std::string eventType;
        /**
         * Event execution date time in "dd-mon-yy HH24:MI:SS" format
         */
        std::string eventDateTime;
        /**
         * Vehicle program name associated with the measurement event
         */
        std::string vehicleProgram;
        /**
         * Phase name associated with the measurement event
         */
        std::string phaseName;
        /**
         * Item ID of the plant associated with the measurement event
         */
        std::string plantId;
        /**
         * Revision of the routine associated with the measurement event
         */
        std::string routineId;
        /**
         * Revision of the routine
         */
        std::string routineRev;
        /**
         * Device type of the measurement event such as '<i>CMM</i>', '<i>Vision</i>' an '<i>Hand
         * Held</i>'
         */
        std::string deviceType;
        /**
         * Part name of the measurement event
         */
        std::string partName;
        /**
         * Device identifier of the measurement device
         */
        std::string device;
        /**
         * Shift number ('<i>0</i>', '<i>1</i>', '<i>2</i>', '<i>3</i>' or '<i>4</i>') of the
         * measurement event.
         * <br>
         * "0" means shift information is not given. "1" means morning, "2" means afternoon,
         * "3" means evening and "4" means night shifts
         * <br>
         */
        int shiftNumber;
        /**
         * Event execution time in UTC. Date format "dd-mon-yy HH24:MI:SS"
         */
        std::string utcTime;
        /**
         * Shift day time in "dd-mon-yy HH24:MI:SS" format
         */
        std::string shiftDay;
        /**
         * List of feature actual information including feature attribute codes and corresponding
         * measured values for one measurement event
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::FtrActual > ftrInput;
        /**
         * List of trace code values for one measurement event
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::TraceEvent > traceInput;
    };

    /**
     * The MeasmtLoadResponse structure is used to return the event sys id and error information
     */
    struct MeasmtLoadResponse
    {
        /**
         * A list of  event system IDs corresponding to each <code>MeasmtData</code> provided
         * in the input
         */
        std::vector< std::string > eventSysId;
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The NewEventInfo structure is used to give the reject or spec limits for a attribute
     */
    struct NewEventInfo
    {
        /**
         * Item  ID of the plant of type <b>MEPrPlantProcess</b>. The plant information is used
         * to determine in which measurement database the <code>eventSysId</code> is stored
         */
        std::string plantId;
        /**
         * The event system ID of the measurement event
         */
        std::string eventSysId;
        /**
         * Column of the value to be modified in the <code>DIS_MEASMT_EVENT</code> table
         */
        std::string columnName;
        /**
         * The value to be set in the column identied by the <code>columnName</code> for the
         * <code>eventSysId</code>
         */
        std::string newValue;
    };

    /**
     * The TraceEvent structure is used to give details of event trace information
     */
    struct TraceEvent
    {
        /**
         * Trace code for a measurement event,  fo rexample, '<i>Operator</i>'
         */
        std::string traceCode;
        /**
         * The value of the traceCode for the measurement event, for example, '<i>Mike</i>'
         * for a traceCode of '<i>Operator</i>'
         * <br>
         */
        std::string eventTraceCodeValue;
    };

    /**
     * The UpdateEventResponse structure is used to return the status of insertions
     */
    struct UpdateEventResponse
    {
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation inserts trace codes and the corresponding values into the measurement
     * database, given the measurement event sys ID and plant item ID.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The external Extraction Transfer and Load (ETL) application adds the trace codes
     * and corresponding values to the measurement database after adding measurement event
     * and feature attribute values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param plantId
     *        The plant item ID to which the measurement event or <code>eventSysId</code> belongs.
     *        The plant ID information is used to identify the measurement database to which the
     *        trace code information is to be added
     *
     * @param eventSysId
     *        The measurement event for which the <code>eventTraceval</code> is to be added
     *
     * @param eventTraceval
     *        A structure that includes trace codes and corresponding event trace code values for
     *        the measurement event or <code>eventSysId</code>
     *
     * @return
     *         This operation returns '<i>0</i>' for success and '<i>1</i>' for failure.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual bool insertEventTrace ( const std::string&  plantId,
        const std::string&  eventSysId,
        const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::TraceEvent >& eventTraceval ) = 0;

    /**
     * Inserts the given set of feature actual values into the measurement database for
     * a measurement event. This operation is used to add measurement data for a single
     * measurement event.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * External applications, such as Extraction Transfer and Load (ETL), use this operation
     * to store feature actual data into the measurement database for a measurement event.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param plantId
     *        The <code>plant ID</code> to which the routine corresponding to measurement event
     *        or <code>eventSysID</code> belongs. This information is used by the operation to
     *        decide which measurement database should be used to enter the event data
     *        <br>
     *
     * @param eventSysId
     *        ID for the measurement event
     *
     * @param featureActuals
     *        The measured values for feature attribute for a measurement event or <code>eventSysId</code>
     *        <br>
     *
     * @return
     *         This operation returns '<i>0</i>' for success and '<i>1</i>' for failure.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual bool insertFeatureActuals ( const std::string&  plantId,
        const std::string&  eventSysId,
        const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::FtrActual >& featureActuals ) = 0;

    /**
     * Inserts the given set of specification limit data for a feature attribute.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An external application, such as Extraction Transfer and Load (ETL), uses this operation
     * to insert the given set of specification limit data for a feature attribute.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param targetTable
     *        A string that should be either '<i>SPECLIMIT</i>' (for inserting specification limits)
     *        or                                    '<i>REJECTLIMIT</i>' (for inserting reject
     *        limits)
     *        <br>
     *
     * @param limitInput
     *        A list used to give the reject or specification  limit information
     *
     * @return
     *         The ServiceData  holds model objects and partial errors. No model objects are returned
     *         in this operation. Also, no specific partial error is returned by this operation
     *         and only errors from underlying subsystems are returned.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::LimitInsertResponse insertLimitData ( const std::string&  targetTable,
        const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::Limit >& limitInput ) = 0;

    /**
     * This operation inserts the log data into the measurement database. The log data has
     * error and warning messages pertaining to a measurement event.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * External application, such as Extraction Transfer and Load (ETL), insert measurement
     * data into measurement database using other operations in the <code>MeasurementDataLoad</code>
     * service. The log information is entered into the <code>DPV_LOG_INFO</code> table
     * of measurement database for every event whether the data insertion was successful
     * or not
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * insertMeasurementData
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param logInput
     *        A list of log values for a measurement event
     *
     * @return
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::LogInsertResponse insertLogData ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::LogData >& logInput ) = 0;

    /**
     * This operation inserts the given measurement data including event parameters, measured
     * feature attribute values and trace code information. It returns event system IDs
     * on successful completion of the insertions. This inserts all the feature attribute
     * measurement values pertaining to several measurement events in bulk.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used by external application such as Extraction Transaction and
     * Load (ETL) to insert measurement data into measurement database.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param rawdata
     *        The measurement data including event parameters, measured feature attribute values
     *        and trace code information
     *
     * @return
     *         A list Event system IDs corresponding to each <code>MeasmtData</code> provided in
     *         the input and the <code>ServiceData</code>. The <code>ServiceData</code>  holds model
     *         objects and partial errors. No model objects are returned in this operation. Also,
     *         no specific partial error is returned by this operation and only errors from underlying
     *         subsystems are returned.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::MeasmtLoadResponse insertMeasurementData ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::MeasmtData >& rawdata ) = 0;

    /**
     * This operation updates the Active column value of the <code>DIS_MEASMT_EVENT</code>
     * table  to '<i>1</i>' (active) or '<i>0</i>' (inactive) for  the given event information.
     * The event information contains the <code>plantId</code> and <code>eventSysId</code>.
     * The <code>plantId</code> is used to identify the external measurement database that
     * contains the events for the plant.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used by external application, such as Extraction Transfer and Load
     * (ETL) to update a column value in <code>DIS_MEASMT_EVENT</code> table with the given
     * input event information.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param eventInfo
     *        A structure with <code>plantId</code>  for the measruement event, the <code>eventSysId</code>
     *        of the event, the <code>columnName</code> to be modified, and the value to be set
     *        for the <code>columnNam</code>e
     *        <br>
     *
     * @return
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::UpdateEventResponse updateEventColumn ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload::NewEventInfo >& eventInfo ) = 0;


protected:
    virtual ~Measurementdataload() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

