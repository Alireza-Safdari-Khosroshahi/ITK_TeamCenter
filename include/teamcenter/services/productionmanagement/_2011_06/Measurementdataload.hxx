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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2011_06_MEASUREMENTDATALOAD_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2011_06_MEASUREMENTDATALOAD_HXX



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
            namespace _2011_06
            {
                class Measurementdataload;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataload
{
public:

    struct CreateLinkNameInfoResponse;
    struct PopulateLinkTablesResponse;

    /**
     * It has a partial errors object giving error information, if any
     */
    struct CreateLinkNameInfoResponse
    {
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * It has a partial errors object giving error information, if any
     */
    struct PopulateLinkTablesResponse
    {
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Measurementdataload() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

