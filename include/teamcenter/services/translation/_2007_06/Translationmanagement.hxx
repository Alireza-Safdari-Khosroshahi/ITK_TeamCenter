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

#ifndef TEAMCENTER_SERVICES_TRANSLATION__2007_06_TRANSLATIONMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_TRANSLATION__2007_06_TRANSLATIONMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/translation/Translation_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Translation
        {
            namespace _2007_06
            {
                class Translationmanagement;

class TCSOATRANSLATIONSTRONGMNGD_API Translationmanagement
{
public:

    struct CreateTranslationRequestArgs;
    struct CreateTranslationRequestResponse;

    /**
     * The CreateTranslationRequestArgs struct is used to pass in multiple sets of data
     * <br>
     * to be used in a single call.  These structs are passed in the collection of
     * <br>
     * input arguments to the function createTranslationRequest.
     */
    struct CreateTranslationRequestArgs
    {
        /**
         * The primary objects for the request.  This usually refers to a dataset to translate
         * but can be any component.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > primaryObjects;
        /**
         * The secondary objects for the request.  This usually refers to the Item Revision
         * containing the primary objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaryObjects;
        /**
         * The priority to assign to the request.
         */
        int priority;
        /**
         * The provider name to process the request.
         */
        std::string providerName;
        /**
         * The translator from the above provider to translate the request.
         */
        std::string translatorName;
        /**
         * The trigger is a string that identifies who/where created this request.
         */
        std::string trigger;
        /**
         * The translator arguments to pass to the translator.  These are name value pairs like:
         * NAME=FENDER.
         */
        std::vector< std::string > translatorArgs;
    };

    /**
     * The CreateTranslationRequestResponse struct contains the requests that were created
     * as a result of the inputs specified in the CreateTranslationRequestArgs struct above.
     */
    struct CreateTranslationRequestResponse
    {
        /**
         * The Translation Request objects created.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > requestsCreated;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData svcData;
    };




    /**
     * Create a translation request within Teamcenter for use with translation services.
     * <br>
     * This operation creates a <b>ETSTranslationRequest</b> object in the Teamcenter database.&nbsp;&nbsp;&nbsp;&nbsp;
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The ETS application provides the ability to process requests in an asynchronous fashion
     * thus removing the processing burden from the clients to a provisioned machine dedicated
     * to processing these requests.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Translation Services - A set of component (scheduler; translation modules; and translators)
     * that provides distributed execution of translations across multiple machine. It has
     * capability to schedule jobs to run at specified times in an asynchronous manner.
     *
     * @param inputs
     *        - List of input structures
     *
     * @return
     *         It returns the successfully created request(s) back to the client or a NULLTAG if
     *         the creation was unsuccessful.
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Tc 8, use the createTranslationRequest operation from the DispatcherManagement
     *         service in the Core library.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the createTranslationRequest operation from the DispatcherManagement service in the Core library."))
#endif
    virtual Teamcenter::Services::Translation::_2007_06::Translationmanagement::CreateTranslationRequestResponse createTranslationRequest ( const std::vector< Teamcenter::Services::Translation::_2007_06::Translationmanagement::CreateTranslationRequestArgs >& inputs ) = 0;


protected:
    virtual ~Translationmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/translation/Translation_undef.h>
#endif

