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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_DISPATCHERMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_DISPATCHERMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ImanFile.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2008_06
            {
                class Dispatchermanagement;

class TCSOACORESTRONGMNGD_API Dispatchermanagement
{
public:

    struct CreateDispatcherRequestArgs;
    struct CreateDispatcherRequestResponse;
    struct DataFiles;
    struct KeyValueArguments;

    /**
     * The CreateDispatcherRequestArgs struct is used to pass in multiple sets of data to
     * be used in a single call.  These structs are passed in the collection of input arguments
     * to the function createDispatcherRequest.
     */
    struct CreateDispatcherRequestArgs
    {
        /**
         * The primary objects for the request.  This usually refers to a dataset to translate
         * but can be any component.
         */
        std::string providerName;
        /**
         * The secondary objects for the request.  This usually refers to the Item Revision
         * containing the primary objects.
         */
        std::string serviceName;
        /**
         * The provider name to process the request.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > primaryObjects;
        /**
         * The service from the above provider to process the request.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaryObjects;
        /**
         * The priority to assign to the request.
         */
        int priority;
        /**
         * The start time to start the request.
         */
        std::string startTime;
        /**
         * The end time at which no new requests will be created based on interval setting.
         * If request is still processing, the request WILL be completed and will not be stopped.
         */
        std::string endTime;
        /**
         * The number of times to repeat a given request.
         */
        int interval;
        /**
         * The key/value arguments for the request.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Dispatchermanagement::KeyValueArguments > keyValueArgs;
        /**
         * The key/file arguments for the request.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Dispatchermanagement::DataFiles > dataFiles;
        /**
         * The type of this request (USER SPECIFIED)
         */
        std::string type;
    };

    /**
     * The CreateDispatcherRequestResponse struct contains the requests that were created
     * as a result of the inputs specified in the CreateDispatcherRequestArgs structure
     * above.
     */
    struct CreateDispatcherRequestResponse
    {
        /**
         * The Dispatcher Request objects created.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > requestsCreated;
        /**
         * The SOA Service Data.
         */
        Teamcenter::Soa::Client::ServiceData svcData;
    };

    /**
     * This structure represents the key/file pairs that can be attached to the Dispatcher
     * Request.
     */
    struct DataFiles
    {
        /**
         * The key of the key/file pair.
         */
        std::string key;
        /**
         * file
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanFile>  file;
    };

    /**
     * This structure represents the key/value pairs that can be attached to the Dispatcher
     * Request.
     */
    struct KeyValueArguments
    {
        /**
         * The key of the key/value pair.
         */
        std::string key;
        /**
         * The value of the key/value pair.
         */
        std::string value;
    };




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


protected:
    virtual ~Dispatchermanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

