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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_06_MEASUREMENTDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_06_MEASUREMENTDATAQUERY_HXX



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
            namespace _2008_06
            {
                class Measurementdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataquery
{
public:

    struct DateTimeRange;
    struct EngineeringData;
    struct EngineeringResponse;
    struct JobRange;
    struct MeasurementsTicketResponse;
    struct SingleJob;
    struct QueryRange;
    struct Response;
    struct SearchCriteriaInfo;

    /**
     * AdditionalinfoMap
     */
    typedef std::map< std::string, std::vector< std::string > > AdditionalinfoMap;

    /**
     * AdditionalresponsesMap
     */
    typedef std::map< std::string, std::vector< std::string > > AdditionalresponsesMap;

    /**
     * MeasurementTicketMap
     */
    typedef std::map< std::string, std::string > MeasurementTicketMap;

    /**
     * The DateTimeRange structure represents the time at the beginning and end of the range.
     */
    struct DateTimeRange
    {
        /**
         * The time at the beginning of the date time range in the format "MM-DD-YYYY HH24:MI:SS"
         * <br>
         */
        std::string fromDateTime;
        /**
         * The time at the end of the date time range in the format "MM-DD-YYYY HH24:MI:SS"
         * <br>
         */
        std::string toDateTime;
    };

    /**
     * The EngineeringData structure represents all of the information about Engineering
     * data Parameters.
     */
    struct EngineeringData
    {
        /**
         * Reserved for future use
         */
        AdditionalinfoMap additionalinfo;
        /**
         * Plant item ID pertaing to a <code>routineid</code>
         */
        std::string plantid;
        /**
         * Vehicle program name associated with the <code>routineid</code>
         */
        std::string vehicleprogram;
        /**
         * The device type used to measure a routine (<code>routineid</code>), such as "<i>CMM</i>",
         * "<i>Vision</i>", and "<i>Hand Held</i>"
         */
        std::string devicetype;
        /**
         * Part name of the measurement routine (<code>routineid</code>)
         */
        std::string partnames;
        /**
         * Item ID of type <b>MEInspection</b>
         */
        std::string routineid;
        /**
         * Revision of the <code>routineid</code>
         */
        std::string routinerev;
        /**
         * Device ID used to measure the <code>routinerev</code>
         */
        std::string device;
        /**
         * The production phase of the <code>routinerev</code>
         */
        std::string phasename;
        /**
         * The measurement event type, such as "<i>N</i>" (Normal) and "<i>D</i>" (Duplicate)
         */
        std::string eventtypes;
    };

    /**
     * The EngineeringResponse structure represents the vector of responses depending on
     * the operationType.
     */
    struct EngineeringResponse
    {
        /**
         * The list of responses
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::Response > response;
        /**
         * Service Data object with any partial errors
         */
        Teamcenter::Soa::Client::ServiceData partialErrors;
    };

    /**
     * The JobRange structure represents the beginning and end of job range.
     */
    struct JobRange
    {
        /**
         * The build label of the beginning job of the job range
         */
        std::string fromJob;
        /**
         * The build label of the ending job of the job range
         */
        std::string toJob;
        /**
         * The data range within which the from and to builds need to be queried. Builds outside
         * the date range will be ignored
         * <br>
         * <br>
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::DateTimeRange dateTimeRange;
    };

    /**
     * The MeasurementsTicketResponse structure represents the mapping of client id to measurement
     * ticket
     */
    struct MeasurementsTicketResponse
    {
        /**
         * A map of input parameter <code>clientId</code>, which is the key, and the file ticket
         * to measurement file containing engineering and measurement data pertaining to the
         * <code>clientId</code>
         * <br>
         */
        MeasurementTicketMap measurementTicketsInfo;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData partialErrors;
    };

    /**
     * The SingleJob structure represents the single job
     */
    struct SingleJob
    {
        /**
         * A build label
         */
        std::string job;
        /**
         * The data range within which the job need to be queried. Builds outside the date range
         * will be ignored
         * <br>
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::DateTimeRange dateTimeRange;
    };

    /**
     * The QueryRange structure represents the user query information.
     */
    struct QueryRange
    {
        /**
         * Last number of builds
         */
        int queryLastXjobs;
        /**
         * Last number of hours
         */
        int queryLastXhrs;
        /**
         * Last number of minutes
         */
        int queryLastXmin;
        /**
         * A date time range with from and to values in the format "MM-DD-YYYY HH24:MI:SS"
         * <br>
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::DateTimeRange queryDateTimeRange;
        /**
         * A range of build labels
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::JobRange queryJobRange;
        /**
         * One build label
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::SingleJob querySingleJob;
        /**
         * This is for future use and not currently used
         */
        AdditionalinfoMap additionalinfo;
    };

    /**
     * The Response structure represents the id and displayname of each attribute that defined
     * in EngineeringData struct.
     */
    struct Response
    {
        /**
         * Reserved for future use
         */
        AdditionalresponsesMap additionalresponses;
        /**
         * Identifier of the object/information requested
         */
        std::string id;
        /**
         * Display name of the object/information requested
         */
        std::string displayname;
    };

    /**
     * The SearchCriteriaInfo structure represents the whole information about the search
     * criteria.
     */
    struct SearchCriteriaInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * associated with this input structure
         */
        std::string clientId;
        /**
         * This is primarily the <b>ItemRevision</b> of a routine. It has associated data such
         * as plant ID, vehicle program, and device ID
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::EngineeringData enggData;
        /**
         * The shift filter to be applied to the search criteria. The allowed values are between
         * '<i>0</i>' and '<i>4</i>', inclusive. Any other values will be ignored and a default
         * of '<i>0</i>' will be used instead. If the value is '<i>0</i>', it indicates measurement
         * data for all shifts
         */
        int shiftNumber;
        /**
         * The type of <code>queryRange</code> with possible values of '<i>LAST_N_JOBS</i>',
         * '<i>LAST_N_HRS</i>','<i>LAST_N_MIN</i>','<i>DATETIME_RANGE</i>','<i>JSN_RANGE</i>','<i>JSN</i>'
         */
        std::string filter;
        /**
         * A specification of a range to be applied as a <code>filter</code> for the measurement
         * data. The type of the queryRange is determined by the <code>filter</code> parameter.
         * This has the details of all possible query ranges but only the details pertaining
         * to filter parameter will be used to filter the measurement data
         */
        Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::QueryRange queryRange;
    };




    /**
     * Given a search criteria with primarily the routine revision and filter data, such
     * as last number of builds and date range, this operation gives a text file with engineering
     * data and measurement data for the routine revision.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The DPV Reporting & Analysisi client application in standalone Teamcenter lifecycle
     * visualization queries Teamcenter for engineering and measurement data of a routine
     * revision
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param request
     *        A list of <code>SearchCriteriaInfo</code> structures. This has a <code>clientId</code>
     *        key provided as an input. Also, it includes the engineering data for which a query
     *        is to be performed.  In addition,  it includes the shift and query criteria to filter
     *        the measurement data.  The clientId is a key for the remaining data in the <code>SearchCriteriaInfo</code>
     *        and is used in the output parameter to represent the complete <code>SearchCriteriaInfo</code>
     *
     * @return
     *         The return is a list of maps. Each map has the <code>clientId</code> key and a measurement
     *         ticket for the file that contains the requested engineering and measurement data.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::MeasurementsTicketResponse getMeasurementTicket ( const std::vector< Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::SearchCriteriaInfo >& request ) = 0;

    /**
     * This operation gets data pertaining to a <b>MEInspection</b> (routine) depending
     * on what is specified in the <code>operationType</code> parameter. For example, if
     * the desired data is program then the operation type should be set to '<i>Program</i>'.
     * The values are obtained by querying the measurement databases for the routines.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used by the DPV Reporting & Analysis application in standalone
     * Teamcenter lifecycle visualization to query routine data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param operationType
     *        Determines what operation will be performed.  Possible values for this are   <i>"Program</i>",<i>"DeviceType</i>",<i>"Part</i>",<i>"Routine</i>",<i>"DeviceID</i>",
     *        <i>"Phase</i>", and <i>"EventType</i>". The order of the possible values mentioned
     *        here and in the EngineeringData structure from the top upto  the <code>routineid</code>
     *        is important.The <code>additionalinfo</code> parameter is not used. For any structure
     *        element that is queried for, all the information above it should be provided. However,
     *        no input information for structure elements below the routineid parameter is required.
     *        For example, if the "<i>DeviceType</i>" information is required, the <code>plantid</code>
     *        and <code>vehicleprogram</code> information should be filled in the <code>EngineeringData</code>
     *        structure. Similarly for routineid, the plantid, vehicleprogram, devicetype, and
     *        partnames should be sent in the input. Also, as no input information for structure
     *        elements below the routineid parameter is required, for example, if the "<i>EventType</i>"
     *        is required, there is no need to specify routinerev, device or phasename
     *
     * @param request
     *        Has the different input parameters. The output parameter will be filled in based
     *        on the <code>operationType</code>. What data needs to be sent in as part of the input
     *        parameter is described under <code>operationType</code>
     *
     * @return
     *         The display name and ID of the object requested in the <code>operationType</code>
     *         and the <code>ServiceData</code>. The <code>ServiceData</code>  holds model objects
     *         and partial errors. No model objects are returned in this operation. Also, no specific
     *         partial error is returned by this operation and only errors from underlying subsystems
     *         are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::EngineeringResponse queryEngineeringParameters ( const std::string&  operationType,
        const Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery::EngineeringData&  request ) = 0;


protected:
    virtual ~Measurementdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

