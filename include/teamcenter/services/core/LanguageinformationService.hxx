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

#ifndef TEAMCENTER_SERVICES_CORE_LANGUAGEINFORMATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_LANGUAGEINFORMATIONSERVICE_HXX

#include <teamcenter/services/core/_2010_04/Languageinformation.hxx>



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
            class LanguageinformationService;

/**
 * The <code>LanguageInformation</code> service contains operations that are used to
 * retrieve different language information relative to the Teamcenter session, or to
 * the language settings as specified in the preference values.
 * <br>
 * This language information is used for language related data by Teamcenter processes
 * (e.g. property value creation, property value display, data search, etc.).
 * <br>
 * This service fulfills the following use cases for the manipulation of language information:
 * <br>
 * <ul>
 * <li type="disc">Retrieval of all information regarding translation statuses (the
 * enumeration, localized name and description) which have been defined in the current
 * Teamcenter system.
 * </li>
 * <li type="disc">Retrieval of a list of languages that can be used for displaying
 * localized property values.
 * </li>
 * <li type="disc">Retrieval of a list of languages that can be used for localized property
 * value entries.
 * </li>
 * <li type="disc">Retrieval of a list of languages that are supported by the system
 * and can be used for property localization in the BMIDE.
 * </li>
 * <li type="disc">Retrieval of the language that can be used for search operations.
 * </li>
 * <li type="disc">Retrieval of all the languages that are supported by the system.
 * </li>
 * </ul>
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

class TCSOACORESTRONGMNGD_API LanguageinformationService
    : public Teamcenter::Services::Core::_2010_04::Languageinformation
{
public:
    static LanguageinformationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Retrieves the full set of translation statuses: their enumeration, localized name
     * and description.
     * <br>
     * Currently, the translation statuses in the Teamcenter system includes: "<i>Master</i>",
     * "<i>Approved</i>", "<i>Pending</i>", "<i>In-Review</i>", and "<i>Invalid</i>"
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model L10N framework - The framework to provide a user interface in the locale
     * of users as well as manage the product information (metadata, operation data and
     * file content) in multiple languages.
     *
     * @return
     *         A list of all the full translation statuses.
     *
     */
    virtual Teamcenter::Services::Core::_2010_04::Languageinformation::TranslationStatusResponse getAllTranslationStatuses (  ) = 0;

    /**
     * Retrieves a list of languages according to different scenarios as specified in the
     * input parameter.
     * <br>
     * All the returned language names are in the Java-standard format.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model L10N framework - The framework to provide a user interface in the locale
     * of users as well as manage the product information (metadata, operation data and
     * file content) in multiple languages.
     *
     * @param scenario
     *        Defines the type of languages list that will be returned.
     *        <br>
     *        Valid values are (case sensitive):
     *        <br>
     *        <ul>
     *        <li type="disc">"<i>displayLanguages</i>" : To retrieve an ordered list of languages
     *        that can be used for displaying localized property values.
     *        </li>
     *        <li type="disc">"<i>entryLanguage</i>":  To retrieve the language to be used for
     *        localized property value entries.
     *        </li>
     *        <li type="disc">"<i>searchLanguage</i>": To retrieve the language to use for Search
     *        operations.
     *        </li>
     *        <li type="disc">"<i>supportedLanguages</i>": To retrieve all the languages supported
     *        by the system.
     *        </li>
     *        <li type="disc">"<i>localizationLanguages</i>": To retrieve all languages supported
     *        by the system and declared as usable for property value localization in the both
     *        BMIDE Global Constant "<code>Fnd0SelectedLocales</code>" and "<code>SiteMasterLocale</code>".
     *        </li>
     *        </ul>
     *
     * @return
     *         A list of language information. The following partial errors may be returned.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">128030 Warning: When no supported locale can be found.
     *         </li>
     *         <li type="disc">214408 Error: When the provided scenario does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2010_04::Languageinformation::LanguageResponse getLanguagesList ( const std::string&  scenario ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LanguageinformationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

