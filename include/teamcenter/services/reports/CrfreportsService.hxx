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

#ifndef TEAMCENTER_SERVICES_REPORTS_CRFREPORTSSERVICE_HXX
#define TEAMCENTER_SERVICES_REPORTS_CRFREPORTSSERVICE_HXX

#include <teamcenter/services/reports/_2007_01/Crfreports.hxx>
#include <teamcenter/services/reports/_2008_06/Crfreports.hxx>
#include <teamcenter/services/reports/_2008_12/Crfreports.hxx>
#include <teamcenter/services/reports/_2010_04/Crfreports.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/reports/Reports_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Reports
        {
            class CrfreportsService;

/**
 * The CrfReports service provides operations to manage the Summary reports/Item reports/Custom
 * reports . CRF stands for Common Report Framework. The operations in this service
 * allow creating report definition, loading report definition, generating reports by
 * user inputs, generating report definition id for new report definition, generate
 * URL for TcRA operations. Teamcenter provides three types reports based on the queries.
 * User can create Summary Report, Custom Report, and Item Report by CrfReports service.
 * <br>
 * <br>
 * The CrfReports service can be used for supporting following use-cases:
 * <br>
 * <ul>
 * <li type="disc">Create Summary Report/Custom Report/Item Report.
 * </li>
 * <li type="disc">Load the report definition by input criteria.
 * </li>
 * <li type="disc">Generate Summary Report/Custom Report/Item Report.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoareportsstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoareportstypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAREPORTSSTRONGMNGD_API CrfreportsService
    : public Teamcenter::Services::Reports::_2007_01::Crfreports,
             public Teamcenter::Services::Reports::_2008_06::Crfreports,
             public Teamcenter::Services::Reports::_2008_12::Crfreports,
             public Teamcenter::Services::Reports::_2010_04::Crfreports
{
public:
    static CrfreportsService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Creates a report definition with the specified properties.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param reportProperties
     *        The report properties for the report definition.
     *
     * @return
     *         The report definition and the ServiceData.
     *
     */
    virtual Teamcenter::Services::Reports::_2007_01::Crfreports::CreateReportDefinitionResponse createReportDefinition ( const Teamcenter::Services::Reports::_2007_01::Crfreports::ReportProperties&  reportProperties ) = 0;

    /**
     * Generates report (Summary Report/Custom Report/Item Report) using the specified criteria
     * and the selected report style sheet. The report can be displayed with the selected
     * report style. The report style is used to define how to display the report result
     * in UI to end user. The report can optionally be saved as a <b>Dataset</b> in the
     * Teamcenter database. The generated report is saved in the FMS transient volume and
     * an FMS ticket is returned.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can generate one report (Summary Report/Custom Report/Item Report) by selecting
     * one report definition and then inputs criteria for the report query, selects one
     * report style sheet, and inputs the dataset name for the report if user would like
     * to save the report as a dataset in Teamcenter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param inputCriteria
     *        The report definition id, style sheet information, context objects and the query
     *        criteria, for the desired report,  and an optional dataset name to save the report
     *        in the Teamcenter database.
     *
     * @param applicationId
     *        For future use, may be null
     *
     * @return
     *         The FMS ticket information for the generated report.
     *
     */
    virtual Teamcenter::Services::Reports::_2007_01::Crfreports::GenerateReportResponse generateReport ( const Teamcenter::Services::Reports::_2007_01::Crfreports::GenerateReportCriteria&  inputCriteria,
        const std::string&  applicationId ) = 0;

    /**
     * Generates new report definition id(s) based upon the specified report criteria. This
     * operation is used when user creates new report definition; the report definition
     * id is generated by this operation. Multiple report definition id generation is not
     * supported currently.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User creates a new report definition from the New Report wizard. User presses the
     * button to generate the report definition id for the new report definition. This operation
     * will be triggered to generate the report definition id and assign to the new report
     * definition.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param inputCriteria
     *        A list of ReportsCriteria structures which includes the report category information.
     *
     * @return
     *         The response object which contains the report definition id generated.
     *         <br>
     *         Failure will be returned in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Reports::_2007_01::Crfreports::GenerateReportDefintionIdsResponse generateReportDefintionIds ( const std::vector< Teamcenter::Services::Reports::_2007_01::Crfreports::ReportsCriteria >& inputCriteria ) = 0;

    /**
     * Retrieves a set of report definitions that meet the specified criteria.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Document set of user level use cases, should describe how user interacts with this
     * operation to accomplish the goal.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param inputCriteria
     *        A vector of ReportsCriteria2 structures.
     *
     * @return
     *         A vector of ReportDefinitionObjects containing report definition ID's.
     *
     * @deprecated
     *         As of Tc 8, use the getReportDefinitions operation from the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the getReportDefinitions operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Services::Reports::_2007_01::Crfreports::GetReportDefinitionsResponse getReportDefinitions ( const std::vector< Teamcenter::Services::Reports::_2007_01::Crfreports::ReportsCriteria >& inputCriteria ) = 0;

    /**
     * Retrieves a set of report definitions that meet the specified criteria.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Document set of user level use cases, should describe how user interacts with this
     * operation to accomplish the goal.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param inputCriteria
     *        A vector of ReportsCriteria structures
     *
     * @return
     *         A vector of ReportDefinitionObjects containing report definition ID's.
     *
     */
    virtual Teamcenter::Services::Reports::_2007_01::Crfreports::GetReportDefinitionsResponse getReportDefinitions ( const std::vector< Teamcenter::Services::Reports::_2008_06::Crfreports::ReportsCriteria2 >& inputCriteria ) = 0;

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
     *        A GenerateReportCriteria structure which contains the report definition id, the report
     *        style information, the context objects, the query criteria, and the dataset name.
     *
     * @return
     *         The GenerateReportsResponse object which contains the ticket for the report created.
     *         Failure will be returned in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Reports::_2008_12::Crfreports::GenerateReportsResponse generateReports ( const std::vector< Teamcenter::Services::Reports::_2008_12::Crfreports::GenerateReportsCriteria >& inputs ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CrfreportsService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/reports/Reports_undef.h>
#endif

