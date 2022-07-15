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

#ifndef TEAMCENTER_SERVICES_REPORTS__2007_01_CRFREPORTS_HXX
#define TEAMCENTER_SERVICES_REPORTS__2007_01_CRFREPORTS_HXX

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
            namespace _2007_01
            {
                class Crfreports;

class TCSOAREPORTSSTRONGMNGD_API Crfreports
{
public:

    struct CreateReportDefinitionResponse;
    struct GenerateReportCriteria;
    struct GenerateReportDefintionIdsResponse;
    struct GenerateReportResponse;
    struct GetReportDefinitionsResponse;
    struct ReportDefinitionIdObject;
    struct ReportDefinitionObject;
    struct ReportProperties;
    struct ReportsCriteria;
    struct TransientFileInfo;
    struct TransientFileTicketInfo;

    /**
     * Response from createReportDefinition.
     */
    struct CreateReportDefinitionResponse
    {
        /**
         * report definition Tag
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  reportdefinition;
        /**
         * ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Data needed to generate a report.
     */
    struct GenerateReportCriteria
    {
        /**
         * The report definition.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  rdTag;
        /**
         * The style sheet <b>Dataset</b> . If supplied the style sheet will be applied to the
         * final generated report. If this value is left null, a plain XML file will be generated
         * for the report.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  stylesheetTag;
        /**
         * A list of context business objects for a Item Report.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextObjects;
        /**
         * The name of the containing <b>Dataset</b>. If dataset name is provided, the generated
         * report will be saved as a <b>Dataset</b> to Teamcenter with this given name.
         */
        std::string datasetName;
        /**
         * A list of criteria names  in a series of Name/Value pairs used to specify additional
         * criteria (optional).
         */
        std::vector< std::string > criteriaNames;
        /**
         * A list of criteria values in a series of Name/Value pairs used to specify additional
         * criteria (optional).
         */
        std::vector< std::string > criteriaValues;
    };

    /**
     * Response from generateReportDefintionIds.
     */
    struct GenerateReportDefintionIdsResponse
    {
        /**
         * A list of report definition identifiers.
         */
        std::vector< Teamcenter::Services::Reports::_2007_01::Crfreports::ReportDefinitionIdObject > reportdefinitionIds;
        /**
         * The ServiceData which includes the failure information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response from generateReport.
     */
    struct GenerateReportResponse
    {
        /**
         * This is for future use, may be null.
         */
        std::vector< std::string > transientFileReadTickets;
        /**
         * A list of TransientFileTicketInfo  objects for retrieving generated report file.
         * A TransientFileTicketInfo object contains the file name, the transient ticket information
         * for the generated report file.
         */
        std::vector< Teamcenter::Services::Reports::_2007_01::Crfreports::TransientFileTicketInfo > transientFileTicketInfos;
        /**
         * The ServiceData which includes the failure information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response from getReportDefinitions.
     */
    struct GetReportDefinitionsResponse
    {
        /**
         * a vector of ReportDefinitionObjects.
         */
        std::vector< Teamcenter::Services::Reports::_2007_01::Crfreports::ReportDefinitionObject > reportdefinitions;
        /**
         * A serviceData contains the data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A structure associating a report definition id with the requesting client.
     */
    struct ReportDefinitionIdObject
    {
        /**
         * clientId
         */
        std::string clientId;
        /**
         * reportDefinitionId
         */
        std::string reportDefinitionId;
    };

    /**
     * A structure associating a report definition with the requesting client.
     */
    struct ReportDefinitionObject
    {
        /**
         * client identifier for routing purposes
         */
        std::string clientId;
        /**
         * report definition Tag
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ReportDefinition>  reportdefinition;
    };

    /**
     * Properties needed to create a report definition.
     */
    struct ReportProperties
    {
        /**
         * a unique identifier for this definition, may be autogenerated or user-specified (required)
         */
        std::string rdId;
        /**
         * the report name (optional)
         */
        std::string rdName;
        /**
         * the report description (optional)
         */
        std::string rdDescription;
        /**
         * integer report type identifier, e.g. item, summary or custom (required)
         */
        int rdType;
        /**
         * class of designated report type (required for item reports)
         */
        std::string rdClass;
        /**
         * name of the containing folder for this report definition (optional)
         */
        std::string rdFolderName;
        /**
         * solution source of this definition, e.g. Teamcenter, TcRA (optional)
         */
        std::string rdSource;
        /**
         * integer for future use, may be any value
         */
        int rdState;
        /**
         * the source of the report data (required)
         */
        std::string rdQuerySource;
        /**
         * properties to include in the report (optional)
         */
        std::string rdPropertySource;
        /**
         * a vector of stylesheet Tags (optional)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > rdStylesheets;
        /**
         * a vector of strings containing the Entries in a series of Entry/Value pairs used
         * to specify additional metadata (optional)
         */
        std::vector< std::string > rdEntries;
        /**
         * a vector of strings containing the Values in a series of Entry/Value pairs used to
         * specify additional metadata (optional)
         */
        std::vector< std::string > rdValues;
    };

    /**
     * Criteria needed to retrieve report definitions or generate report definition ids.
     * At least one of the optional parameters must be included.
     */
    struct ReportsCriteria
    {
        /**
         * Client identifier for routing purposes (required).
         */
        std::string clientId;
        /**
         * Designates report category, e.g. item, summary or custom (optional).
         */
        std::string category;
        /**
         * Solution source of report definition, e.g. Teamcenter, TcRA (optional).
         */
        std::string source;
        /**
         * It is for future use, may be null.
         */
        std::string status;
        /**
         * A vector of gags representing context object(s) (required for item reports).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextObjects;
    };

    /**
     * The information required for file upload.
     */
    struct TransientFileInfo
    {
        /**
         * Absolute file path to transient volume
         */
        std::string fileName;
        /**
         * true if filetype is text
         */
        bool isText;
    };

    /**
     * TransientFileInfo with a ticket.
     */
    struct TransientFileTicketInfo
    {
        /**
         * file information structure
         */
        Teamcenter::Services::Reports::_2007_01::Crfreports::TransientFileInfo transientFileInfo;
        /**
         * FMS file ticket
         */
        std::string ticket;
    };




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


protected:
    virtual ~Crfreports() {}
};
            }
        }
    }
}

#include <teamcenter/services/reports/Reports_undef.h>
#endif

