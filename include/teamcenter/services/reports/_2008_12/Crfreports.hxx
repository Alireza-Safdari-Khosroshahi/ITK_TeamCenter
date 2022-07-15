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

#ifndef TEAMCENTER_SERVICES_REPORTS__2008_12_CRFREPORTS_HXX
#define TEAMCENTER_SERVICES_REPORTS__2008_12_CRFREPORTS_HXX

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
            namespace _2008_12
            {
                class Crfreports;

class TCSOAREPORTSSTRONGMNGD_API Crfreports
{
public:

    struct GenerateReportsCriteria;
    struct GenerateReportsResponse;
    struct TransientFileInfo;
    struct TransientFileTicketInfo;

    /**
     * Criteria needed to retrieve report definitions or generate report definition ids.
     * At least one of the optional parameters must be included.
     */
    struct GenerateReportsCriteria
    {
        /**
         * The client identifier for routing purposes.
         */
        std::string clientId;
        /**
         * The Report Definition ID.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ReportDefinition>  rdTag;
        /**
         * Designates the name of the report given the report definition is not supplied.
         */
        std::string reportName;
        /**
         * The report style sheet ID (optional). If no report style is provided, then the report
         * will be displayed in xml format to the end user.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  stylesheetTag;
        /**
         * The name of the stylesheet if known
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
         * The name of containing <b>Dataset</b> (optional). If the dataset name is provided,
         * then it will save the generated report as a <b>Dataset</b> in Teamcenter database,
         * otherwise will not.
         */
        std::string datasetName;
        /**
         * A list of strings containing the Names in a series of Name/Value pairs used to specify
         * additional criteria (optional).
         */
        std::vector< std::string > criteriaNames;
        /**
         * A list of strings containing the Values in a series of Name/Value pairs used to specify
         * additional criteria (optional).
         */
        std::vector< std::string > criteriaValues;
        /**
         * The uid for the context <b>Dataset</b>
         */
        std::string datasetCtxUID;
        /**
         * The <b>Dataset</b> context id.
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
    };

    /**
     * The Response object from generateReports operation.
     */
    struct GenerateReportsResponse
    {
        /**
         * It is for future use, may be null.
         */
        std::vector< std::string > transientFileReadTickets;
        /**
         * A list of TransientFileTicketInfo object(s) for retrieving generated report file.
         * The TransientFileTicketInfo object includes the file name, ticket information.
         */
        std::vector< Teamcenter::Services::Reports::_2008_12::Crfreports::TransientFileTicketInfo > transientFileTicketInfos;
        /**
         * The ServiceData which includes the failure information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
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
        Teamcenter::Services::Reports::_2008_12::Crfreports::TransientFileInfo transientFileInfo;
        /**
         * FMS file ticket
         */
        std::string ticket;
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
     *        A GenerateReportCriteria structure which contains the report definition id, the report
     *        style information, the context objects, the query criteria, and the dataset name.
     *
     * @return
     *         The GenerateReportsResponse object which contains the ticket for the report created.
     *         Failure will be returned in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Reports::_2008_12::Crfreports::GenerateReportsResponse generateReports ( const std::vector< Teamcenter::Services::Reports::_2008_12::Crfreports::GenerateReportsCriteria >& inputs ) = 0;


protected:
    virtual ~Crfreports() {}
};
            }
        }
    }
}

#include <teamcenter/services/reports/Reports_undef.h>
#endif

