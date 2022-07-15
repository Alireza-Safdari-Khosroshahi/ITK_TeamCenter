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

#ifndef TEAMCENTER_SERVICES_REPORTS__2007_06_CUBEREPORTS_HXX
#define TEAMCENTER_SERVICES_REPORTS__2007_06_CUBEREPORTS_HXX

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
            namespace _2007_06
            {
                class Cubereports;

class TCSOAREPORTSSTRONGMNGD_API Cubereports
{
public:

    struct ConstructReportURLResponse;
    struct TcRAReportsCriteria;

    /**
     * The response object from constructReportURL operation.
     */
    struct ConstructReportURLResponse
    {
        /**
         * The URL string for the TcRA servlet.
         */
        std::string url;
        /**
         * The ServiceData which contains the error stack.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Criteria needed to retrieve the URL for the specified TcRA operation.
     */
    struct TcRAReportsCriteria
    {
        /**
         * It designates desired TcRA report definition operation, e.g. retrieve, view, edit,
         * delete or set permission.
         */
        std::string messageName;
        /**
         * The report definition ID.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  reportDefinition;
        /**
         * A list of ID's representing context object(s) (required for item reports).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextObjects;
    };




    /**
     * Constructs the servlet URL required by clients to process the TcRA report definition
     * operation (retrieve, view, edit, delete or set permission) specified. The report
     * definition ID, context objects, message name is required to get this URL.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User retrieves/views/edits/deletes/sets permission for one TcRA report, this operation
     * will generate the corresponding URL for the TcRA operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param inputCriteria
     *        A TcRAReportsCriteria structure which includes the report definition ID info, the
     *        context objects, the number of the context objects, the message name.
     *
     * @return
     *         Contains the URL string for the eQube servlet. Failure will be returned in the ServiceData.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Reports::_2007_06::Cubereports::ConstructReportURLResponse constructReportURL ( const Teamcenter::Services::Reports::_2007_06::Cubereports::TcRAReportsCriteria&  inputCriteria ) = 0;


protected:
    virtual ~Cubereports() {}
};
            }
        }
    }
}

#include <teamcenter/services/reports/Reports_undef.h>
#endif

