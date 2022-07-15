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

#ifndef TEAMCENTER_SERVICES_REPORTS_CUBEREPORTSSERVICE_HXX
#define TEAMCENTER_SERVICES_REPORTS_CUBEREPORTSSERVICE_HXX

#include <teamcenter/services/reports/_2007_06/Cubereports.hxx>



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
            class CubereportsService;

/**
 * The CubeReports Service provides operation to support for TcRA reports. Currently
 * only one service operation is provided. The operation constructs the servlet URL
 * required by clients to process the TcRA report definition operation (retrieve, view,
 * edit, delete or set permission) specified.
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

class TCSOAREPORTSSTRONGMNGD_API CubereportsService
    : public Teamcenter::Services::Reports::_2007_06::Cubereports
{
public:
    static CubereportsService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CubereportsService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/reports/Reports_undef.h>
#endif

