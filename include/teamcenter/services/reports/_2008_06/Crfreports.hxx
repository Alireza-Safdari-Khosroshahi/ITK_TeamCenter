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

#ifndef TEAMCENTER_SERVICES_REPORTS__2008_06_CRFREPORTS_HXX
#define TEAMCENTER_SERVICES_REPORTS__2008_06_CRFREPORTS_HXX

#include <teamcenter/services/reports/_2007_01/Crfreports.hxx>
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
            namespace _2008_06
            {
                class Crfreports;

class TCSOAREPORTSSTRONGMNGD_API Crfreports
{
public:

    struct ReportsCriteria2;

    /**
     * Criteria needed to retrieve report definitions. At least one of the optional parameters
     * must be included.
     */
    struct ReportsCriteria2
    {
        /**
         * Client identifier for routing purposes (required)
         */
        std::string clientId;
        /**
         * Report definition ID (optional)
         */
        std::string reportDefinitionId;
        /**
         * Report definition name (optional)
         */
        std::string reportDefinitionName;
        /**
         * Designates report category, e.g. item, summary or custom (optional)
         */
        std::string category;
        /**
         * Solution source of report definition, e.g. Teamcenter, TcRA (optional)
         */
        std::string source;
        /**
         * For future use, may be null
         */
        std::string status;
        /**
         * A vector of ID's representing context object(s) (required for item reports).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextObjects;
    };




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


protected:
    virtual ~Crfreports() {}
};
            }
        }
    }
}

#include <teamcenter/services/reports/Reports_undef.h>
#endif

