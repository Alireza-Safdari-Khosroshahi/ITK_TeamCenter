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

#ifndef TEAMCENTER_SERVICES_TRANSLATION_TRANSLATIONMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_TRANSLATION_TRANSLATIONMANAGEMENTSERVICE_HXX

#include <teamcenter/services/translation/_2007_06/Translationmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/translation/Translation_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Translation
        {
            class TranslationmanagementService;

/**
 * This service provides the method for creating <b>ETSTranslationRequest</b> objects
 * within Teamcenter.  These request objects are used with the ETS application for performing
 * translations in a distributed processing environment.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoatranslationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoatranslationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOATRANSLATIONSTRONGMNGD_API TranslationmanagementService
    : public Teamcenter::Services::Translation::_2007_06::Translationmanagement
{
public:
    static TranslationmanagementService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TranslationmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/translation/Translation_undef.h>
#endif

