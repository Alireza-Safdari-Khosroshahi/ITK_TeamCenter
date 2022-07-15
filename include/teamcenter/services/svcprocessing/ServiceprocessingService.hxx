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

#ifndef TEAMCENTER_SERVICES_SVCPROCESSING_SERVICEPROCESSINGSERVICE_HXX
#define TEAMCENTER_SERVICES_SVCPROCESSING_SERVICEPROCESSINGSERVICE_HXX

#include <teamcenter/services/svcprocessing/_2009_06/Serviceprocessing.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/svcprocessing/SvcProcessing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Svcprocessing
        {
            class ServiceprocessingService;

/**
 * ServiceProcessing service
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoasvcprocessingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoasvcprocessingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASVCPROCESSINGSTRONGMNGD_API ServiceprocessingService
    : public Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing
{
public:
    static ServiceprocessingService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation sets the status of the transaction element based on the <code>SetTxnStatusInfo</code>
     * supplied. The <code>SetTxnStatusInfo</code> contains information for properties such
     * as <code>clientId</code> and <code>data</code>. The value of the approval attribute
     * is obtained and the corresponding transaction element status is set by calling the
     * operation <code>setTxnElementStatus</code>.  This operation utilizes the input information
     * which consists of the approval value, the transaction element type and name. The
     * operation performs validations to ensure that all conditions are met and an attempt
     * to approve an object that is already approved throws an appropriate error message
     * to the user.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Processing - This Component is intended to identify all Operations and Services
     * under Service Processing.
     *
     * @param info
     *        Input parameter that represents data encompassing information about the
     *        <br>
     *        element name, element type and approval process.
     *        <br>
     *
     * @return
     *         <code>SetTxnStatusResponse</code> which contains the client id and status of the
     *         approval operation. Any failure will be returned in the standard<code> Service Data</code>
     *         under partial errors based on validations performed. Following are some error(s)
     *         returned:
     *         <br>
     *         <ul>
     *         <li type="disc">246002:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *         of type <i>object_type</i> with transaction id <i>id</i> is already approved.
     *         </li>
     *         <li type="disc">246004:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A remote object
     *         cannot be approved.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing::SetTxnStatusResponse setTxnElementStatus ( const std::vector< Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing::SetTxnStatusInfo >& info ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServiceprocessingService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/svcprocessing/SvcProcessing_undef.h>
#endif

