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

#ifndef TEAMCENTER_SERVICES_CORE_DISPATCHERMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_DISPATCHERMANAGEMENTSERVICE_HXX

#include <teamcenter/services/core/_2008_06/Dispatchermanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class DispatchermanagementService;

/**
 * This service provides the method for creating a Dispatcher Request object within
 * Teamcenter.  The Dispatcher Request objects are used with the Dispatcher application
 * for performing asynchronous operations such as translations, workflow updates, etc.
 * where distributed processing is preferred.
 * <br>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API DispatchermanagementService
    : public Teamcenter::Services::Core::_2008_06::Dispatchermanagement
{
public:
    static DispatchermanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Create a <b>DispatcherRequest</b> within Teamcenter for use with Dispatcher Management
     * Services.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The Dispatcher Management application provides the ability to process requests in
     * an asynchronous fashion thus removing the processing burden from the clients to provisioned
     * machine dedicated to processing these requests.  There are quite a few services,
     * within Teamcenter and other applications that use this application.
     * <br>
     * <br>
     * Here are a few examples:
     * <br>
     * <ul>
     * <li type="disc">Asynchronous Processing (if configured)
     * </li>
     * <li type="disc">NXtoPVDirect (provided with NX)
     * </li>
     * <li type="disc">PreviewService
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Dispatcher - A set of component (scheduler; translation modules; and translators)
     * that provides distributed execution of translations across multiple machine. It has
     * capability to schedule jobs to run at specified times in an asynchronous manner.
     *
     * @param inputs
     *        holds the values needed to create the <b>DispatcherRequest</b>.
     *
     * @return
     *         It returns the successfully created <b>DispatcherRequest</b>(s) back to the client
     *         or a NULLTAG if the creation was unsuccessful.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Dispatchermanagement::CreateDispatcherRequestResponse createDispatcherRequest ( const std::vector< Teamcenter::Services::Core::_2008_06::Dispatchermanagement::CreateDispatcherRequestArgs >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DispatchermanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

