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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_MEASUREMENTDATALOADSERVICE_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_MEASUREMENTDATALOADSERVICE_HXX

#include <teamcenter/services/productionmanagement/_2007_06/Measurementdataload.hxx>
#include <teamcenter/services/productionmanagement/_2011_06/Measurementdataload.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/productionmanagement/ProductionManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Productionmanagement
        {
            class MeasurementdataloadService;

/**
 * The MeasurementDataLoad service exposes operations that are used to load the measurement
 * data into database tables, as well as, populate database link information.
 * <br>
 * <br>
 * This service provides the following use cases:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">External client applications, such as Extraction Transfer and Load
 * (ETL), load the measurement data including feature actuals, event trace, specification
 * limits data, and event log data.
 * </li>
 * <li type="disc">The Manufacturing Process Planner application in the rich client
 * interface is used to store the database links into measurement databases of the Dimensional
 * Planning and Validation (DPV) application.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaproductionmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaproductionmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API MeasurementdataloadService
    : public Teamcenter::Services::Productionmanagement::_2007_06::Measurementdataload,
             public Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataload
{
public:
    static MeasurementdataloadService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation will create database links to external databases, in the Teamcenter
     * database. The link names will be stored in the USER_DB_LINKS system table of the
     * Teamcenter database. The external databases store measurement data for the Dimensional
     * Planning and Validation (DPV) application. The link names are used to store the measurement
     * data and query measurement data from measurement database by external applications,
     * such as Extraction Transaction and Load (ETL) and Teamcenter lifecycle visualization.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In the Manufacturing Process Planner application in the Teamcenter rich client, the
     * send plant ID context menu under a <b>MEPrPlantProcessRevision</b> object is used
     * to gather measurement database name, measurement database user name, measurement
     * database password, and link name. Then, this operation is used to create the database
     * link.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param linkName
     *        The link name for the external database, <code>dbName</code>
     *        <br>
     *        <br>
     *
     * @param userName
     *        User name for the external database, <code>dbName</code>
     *
     * @param passWord
     *        Password for the <code>userName</code> for the external database, <code>dbName</code>
     *
     * @param dbName
     *        The external database name to which a link is created
     *
     * @return
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataload::CreateLinkNameInfoResponse createLinkNames ( const std::string&  linkName,
        const std::string&  userName,
        const std::string&  passWord,
        const std::string&  dbName ) = 0;

    /**
     * This operation will populate the DPV_DB_LOCATOR and DPV_LINK_LOCATOR  tables in the
     * Teamcenter database. DPV_DB_LOCATOR table has plant ID(s) and database name(s). One
     * plant ID can belong to only one database. DPV_LINK_LOCATOR  table has database names
     * and corresponding database links.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Database links are used by external applications such as Extraction Transfer and
     * Load (ETL) and standalone Teamcenter lifecycle visualization to insert data into,
     * as well as, query from measurement databases.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param plantId
     *        The plant ID
     *
     * @param dbName
     *        The database name that will be entered into DPV_DB_LOCATOR and DPV_LINK_LOCATOR tables
     *        <br>
     *
     * @param userName
     *        The user name of the user in the measurement database. The user name is prepended
     *        to the database name
     *        <br>
     *
     * @param linkName
     *        The link name of the measurement database. It will be entered in the DPV_LINK_LOCATOR
     *        table
     *        <br>
     *
     * @param targetDbType
     *        The target database type to be entered in the DPV_LINK_LOCATOR table. It can be '<i>ORACLE</i>','<i>
     *        SQLSERVER</i>' OR '<i>SQLSERVERLOCAL</i>'
     *        <br>
     *
     * @param serverName
     *        The server that hosts the measurement database. It will be entered in the DPV_LINK_LOCATOR
     *        table
     *        <br>
     *
     * @param updateTables
     *        Based on this input the data will either inserted or updated in the tables. If this
     *        string  is '<i>No_Info</i>' then the data will be inserted. If the string is '<i>Update_Yes</i>'
     *        then the data will be updated in the tables
     *        <br>
     *
     * @param oldLinkName
     *        The old link name will be used to update the tables
     *
     * @return
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataload::PopulateLinkTablesResponse populateLinkTables ( const std::string&  plantId,
        const std::string&  dbName,
        const std::string&  userName,
        const std::string&  linkName,
        const std::string&  targetDbType,
        const std::string&  serverName,
        const std::string&  updateTables,
        const std::string&  oldLinkName ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MeasurementdataloadService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

