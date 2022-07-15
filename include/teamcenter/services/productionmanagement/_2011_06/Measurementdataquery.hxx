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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2011_06_MEASUREMENTDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2011_06_MEASUREMENTDATAQUERY_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


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
                class Measurementdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataquery
{
public:

    struct ClusterGroupInfoResponse;
    struct CustomXlsbDsResponse;
    struct DpvRuleSetDsResponse;
    struct LinkNameResults;
    struct LinkNamesInfoResponse;
    struct SsrsUrlInfoResponse;

    /**
     * The return structure consists of vector of business objects(cluster group rev). And
     * it has a partial errors object giving error information, if any
     */
    struct ClusterGroupInfoResponse
    {
        /**
         * A list of <b>DPVClusterGroup _Revision</b>(s)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  > clusterGroupInfoSet;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure consists of xlsb dataset  which is with the DPVExcel dataset  and
     * a partial errors object giving error information, if any.
     */
    struct CustomXlsbDsResponse
    {
        /**
         * A list of Dpv0RuleSetDataset datasets
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > customXlsbDs;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure consists of Vector of Ruleset Datasets  and a partial errors object
     * giving error information, if any.
     */
    struct DpvRuleSetDsResponse
    {
        /**
         * A list of objects that includes all the <b>Dpv0RuleSetDataset</b> datasets associated
         * with the latest revision of all the <b>Dpv0ruleset(s)</b> for which the user logged
         * in has read privileges
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > dpvRuleSetDsSet;
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure conists of link name , user name and host name in it.
     */
    struct LinkNameResults
    {
        /**
         * The measurement database link name. This information is obtained from the  USER_DB_LINKS
         * and DPV_LINK_LOCATOR tables.
         */
        std::string linkName;
        /**
         * A user name for the measurement database. This information is obtained from the USER_DB_LINKS
         * and DPV_LINK_LOCATOR tables.
         */
        std::string userName;
        /**
         * Host name of the measurement database's server. This information is obtained from
         * the USER_DB_LINKS and DPV_LINK_LOCATOR tables.
         */
        std::string hostName;
    };

    /**
     * This structure constis of one vector of structure and one vector of strigs. In vector
     * of structures; the structure consists of user name,link name and host name(db name).
     * In vector of strings; the string is combination of plant id and link name with ,(comma)
     * delimiter.And it has a partial errors object giving error information, if any
     */
    struct LinkNamesInfoResponse
    {
        /**
         * A list consisting of measurement database links,  the hosting servers, and a user
         * name for each measurement database
         * <br>
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2011_06::Measurementdataquery::LinkNameResults > linkNameSet;
        /**
         * A list of plant and link name combinations with "," (comma) delimiter in the format
         * of
         * <br>
         * "plant_id,link_name,current_db" For e.g. "GMO00001,link1,ORACLE"
         * <br>
         * <br>
         * <br>
         * <br>
         * <br>
         */
        std::vector< std::string > plantLinkNameSet;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure consists of Vector which consists strings of Sql Server Reporing Service(SSRS)
     * urls and it has a partial errors object giving error information, if any
     */
    struct SsrsUrlInfoResponse
    {
        /**
         * A list of strings consisting of SSRS server URLs
         */
        std::vector< std::string > ssrsrUrlSet;
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Measurementdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

