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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_MEASUREMENTDATAQUERYSERVICE_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_MEASUREMENTDATAQUERYSERVICE_HXX

#include <teamcenter/services/productionmanagement/_2008_03/Measurementdataquery.hxx>
#include <teamcenter/services/productionmanagement/_2008_06/Measurementdataquery.hxx>
#include <teamcenter/services/productionmanagement/_2010_04/Measurementdataquery.hxx>
#include <teamcenter/services/productionmanagement/_2011_06/Measurementdataquery.hxx>



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
            class MeasurementdataqueryService;

/**
 * The MeasurementDataQuery service exposes operations that are used to query data of
 * plant Items of type <b>MEPrPlantProcess</b>, routine items of type <b>MEInspection</b>.
 * <br>
 * <br>
 * This service provides the following use cases:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Get all plant Item IDs, names, and database links associated with
 * a plant.
 * </li>
 * <li type="disc">Get Routine Item Revisions associated with a plant item.
 * </li>
 * <li type="disc">Get the <b>DPVClusterGroup</b> information.
 * </li>
 * <li type="disc">Get the plant, program, part, and so on information from Teamcenter
 * so that a user can
 * </li>
 * </ul>
 * <br>
 * query for the required Routine Revision in standalone Teamcenter lifecycle visualization.
 * <br>
 * <ul>
 * <li type="disc">Get measurement data associated with a <b>MEInspection_Revision</b>.
 * </li>
 * <li type="disc">Get the <b>Dpv0RuleSetDataset</b> associated with a <b>MEInspection_Revision</b>.Get
 * all the <b>Dpv0RuleSetDataset</b>(s) associated with the latest released <b>Dpv0rulesetRevison</b>(s)
 * </li>
 * <li type="disc">Get the URL information of SQL Server Reporting Services server of
 * the Dimensional Planning and Validation (DPV) application.
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

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API MeasurementdataqueryService
    : public Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataquery,
             public Teamcenter::Services::Productionmanagement::_2008_06::Measurementdataquery,
             public Teamcenter::Services::Productionmanagement::_2010_04::Measurementdataquery,
             public Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery
{
public:
    static MeasurementdataqueryService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation gives a list of <b>DPVClusterGroup _Revision</b>(s) associated with
     * a routine revision. There is no direct relation between a routine revision and cluster
     * group revisions. From the routine revision, a list of <b>DPVCluster_Revision</b>(s)
     * related to it with <code>Manifestation</code> relation is obtained. Then for each
     * <b>DPVCluster</b>, the <b>DPVClusterGroup _Revision</b>  to which it is related with
     * the <b>DPVClusterGroupContent</b> relation is obtained
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In the Manufacturing Process Planner (MPP) application, a list of cluster groups
     * associated with a routine revision is displayed via a context menu in the routine
     * revision.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param routineRevs
     *        A list of routine revisions. A routine revision is an item revision of type <b>MEInspection_Revision</b>
     *
     * @return
     *         A list of cluster group revisions and the <code>ServiceData</code>. The <code>ServiceData</code>
     *         holds model objects and partial errors. No model objects are returned in this operation.
     *         Also, no specific partial error is returned by this operation and only errors from
     *         underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery::ClusterGroupInfoResponse queryClusterGroupInfo ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  >& routineRevs ) = 0;

    /**
     * The operation gets the <b>Dpv0RuleSetDataset</b> datasets associated with a <b>DPVExcel</b>
     * dataset. The <b>Dpv0RuleSetDataset</b> is a dataset attached to a <b>Dpv0rulesetRevision</b>.
     * The <b>DPVExcel</b>  dataset is attached to <b>MEInspection_Revision</b>. There is
     * a relationship <b>Dpv0CustomRoutineRuleset</b>  between <b>MEInspection_Revision</b>
     * and <b>Dpv0ruleset</b>  and based on these relations, the  <b>Dpv0RuleSetDataset</b>
     * datasets associated with a <b>DPVExcel</b> dataset are obtained.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Display the current <b>Dpv0RuleSetDataset</b> datasets associated with a <b>MEInspection_Revision</b>.
     * This information is useful prior to associating a new <b>Dpv0RuleSetDataset</b> dataset
     * to a <b>MEInspection_Revision</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param xlsxDs
     *        A DPVExcel dataset
     *
     * @return
     *         A list of  <b>Dpv0RuleSetDataset</b> datasets and the <code>ServiceData</code>. The
     *         <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery::CustomXlsbDsResponse queryCustomXlsbDs ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  xlsxDs ) = 0;

    /**
     * This operation will list all the database links to the Dimension Planning and Validation
     * (DPV) measurement databases. It is obtained from the USER_DB_LINKS and DPV_LINK_LOCATOR
     * tables.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The "<i>Send Pland ID</i>..." context menu under a plant in the Manufacturing Process
     * Planner (MPP) application displays all the available links in a dialog after it is
     * selected.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param dbType
     *        The database type of the DPV measurement database. Its possible values are "<i>ORACLE</i>",
     *        "<i>SQLSERVER</i>", and "<i>SQLSEERVERLOCAL</i>"
     *
     * @return
     *         A list of link information and a corresponding list of plant and link name combination
     *         in addition to the <code>ServiceData</code>. Each link information or <code>linkNameSet</code>
     *         includes the server hosting the measurement database, the database link name, and
     *         a user name for the measurement database. Each plant and link name combination or
     *         <code>plantLinkNameSet</code> is a combination of plant ID and link name with a comma
     *         delimiter. The ServiceData  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery::LinkNamesInfoResponse queryLinkNamesInfo ( const std::string&  dbType ) = 0;

    /**
     * List all the datasets of  type <b>Dpv0RuleSetDataset</b> associated with the latest
     * released item revisions of all <b>Dpv0ruleset</b>(s).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * List all the <b>Dpv0RuleSetDataset</b> datasets associated with the latest revisions
     * of <b>Dpv0ruleset</b> items so they can be associated with a routine revision of
     * type <b>MEInspection_Revision</b>.  The <b>Dpv0RuleSetDataset</b> contains validation
     * rules that are used to verify the <b>DPVExcel</b> dataset associated with routine
     * revisions.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @return
     *         This operation returns a list of ruleset datasets and the <code>ServiceData</code>.
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery::DpvRuleSetDsResponse queryRuleSetDataSet (  ) = 0;

    /**
     * This operation gives all the SQL Server Reporting Service (SSRS) server URLs stored
     * in Teamcenter. These values are stored as values of the <b>DPV_ccuaservice_url</b>
     * preference.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In the Manufacturing Process Planner (MPP) application, all the SSRS server URLs
     * are listed so a user can choose one of them to upload a .rdl (Report Definition Language)
     * to it.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @return
     *         A list of SSRS server URLs and the <code>ServiceData</code>. The <code>ServiceData</code>
     *         holds model objects and partial errors. No model objects are returned in this operation.
     *         Also, no specific partial error is returned by this operation and only errors from
     *         underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery::SsrsUrlInfoResponse querySsrsUrlInfo (  ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MeasurementdataqueryService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

