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

#ifndef TEAMCENTER_SERVICES_REPORTS__2010_04_CRFREPORTS_HXX
#define TEAMCENTER_SERVICES_REPORTS__2010_04_CRFREPORTS_HXX

#include <teamcenter/services/reports/_2008_12/Crfreports.hxx>
#include <teamcenter/soa/client/model/ReportDefinition.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/reports/Reports_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Reports
        {
            namespace _2010_04
            {
                class Crfreports;

class TCSOAREPORTSSTRONGMNGD_API Crfreports
{
public:

    struct GenerateReportsCriteria2;

    /**
     * The criteria object needed to generate report.
     */
    struct GenerateReportsCriteria2
    {
        /**
         * The client identifier for routing purposes (required).
         */
        std::string clientId;
        /**
         * The Report Definition ID.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ReportDefinition>  rdTag;
        /**
         * Designates the name of the report given the rdTag is not supplied.
         */
        std::string reportName;
        /**
         * The report style ID (optional).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  stylesheetTag;
        /**
         * The name of the report style if known
         */
        std::string stylesheetName;
        /**
         * A list of ID's representing context object(s) (required for item reports).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextObjects;
        /**
         * A list of uids representing context objects.
         */
        std::vector< std::string > contextObjectUIDs;
        /**
         * The name of containing <b>DataSet</b> (optional).
         */
        std::string datasetName;
        /**
         * A list of strings containing the Names in a series of Name/Value pairs used to specify
         * criteria for saved queries(optional).
         */
        std::vector< std::string > criteriaNames;
        /**
         * A list of strings containing the Values in a series of Name/Value pairs used to specify
         * criteria for saved queries(optional).
         */
        std::vector< std::string > criteriaValues;
        /**
         * The uid for the context <b>Dataset</b>.
         */
        std::string datasetCtxUID;
        /**
         * The <b>Dataset</b> context ID.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  datasetCtxObj;
        /**
         * The relation name to be used.
         */
        std::string relationName;
        /**
         * The <b>Dataset</b> type to be used.
         */
        std::string datasetType;
        /**
         * A list of strings containing the Names in a series of Name/Value pairs used to specify
         * additional criteria (optional).
         */
        std::vector< std::string > reportOptionsNames;
        /**
         * A list of strings containing the Names in a series of Name/Value pairs used to specify
         * additional criteria (optional).
         */
        std::vector< std::string > reportOptionsValues;
    };




    /**
     * Generates reports (Summary Report/Custom Report/Item Report) using the specified
     * criteria and the selected report style. The report will be displayed by the selected
     * report style at the end. If no report style is selected, then the report will be
     * displayed in xml file to the end user. If user would like to save the report as a
     * <b>Dataset</b>, it will use the provided <b>Dataset</b> name to save the report to
     * Teamcenter. After the report is generated, the report file will be uploaded to the
     * transient volumes, user can get it from the transient volumes. Multiple reports generation
     * is not supported currently.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can generate one report (Summary Report/Custom Report/Item Report) by selecting
     * one report definition and then inputs criteria for the report query, selects one
     * report style, and inputs the <b>Dataset</b> name for the report if user would like
     * to save the report as a <b>Dataset</b> in Teamcenter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param inputs
     *        The Criteria to generate the report(s) which contains the report definition id, the
     *        report style information, the context objects, the query criteria, and the <b>Dataset</b>
     *        name, etc.
     *
     * @return
     *         The GenerateReportsResponse object which contains the ticket for the report created.
     *         Failure will be returned in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Reports::_2008_12::Crfreports::GenerateReportsResponse generateReports ( const std::vector< Teamcenter::Services::Reports::_2010_04::Crfreports::GenerateReportsCriteria2 >& inputs ) = 0;


protected:
    virtual ~Crfreports() {}
};
            }
        }
    }
}

#include <teamcenter/services/reports/Reports_undef.h>
#endif

