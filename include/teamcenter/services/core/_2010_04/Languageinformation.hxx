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

#ifndef TEAMCENTER_SERVICES_CORE__2010_04_LANGUAGEINFORMATION_HXX
#define TEAMCENTER_SERVICES_CORE__2010_04_LANGUAGEINFORMATION_HXX



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
            namespace _2010_04
            {
                class Languageinformation;

class TCSOACORESTRONGMNGD_API Languageinformation
{
public:

    struct FullTranslationStatus;
    struct Language;
    struct LanguageResponse;
    struct TranslationStatusResponse;

    /**
     * Defines the status of a translation: master language, approved, pending, in-review
     * and invalid.
     */
    enum TranslationStatus{ TranslationStatusMaster,
                 TranslationStatusApproved,
                 TranslationStatusPending,
                 TranslationStatusInReview,
                 TranslationStatusInvalid
                 };

    /**
     * Fully defines a translation status: its associated enumeration, display name and
     * description.
     */
    struct FullTranslationStatus
    {
        /**
         * TranslationStatus associated with the status
         */
        TranslationStatus status;
        /**
         * Display name of the status
         */
        std::string statusName;
        /**
         * Description of the status
         */
        std::string statusDescription;
    };

    /**
     * Contains information about a language
     */
    struct Language
    {
        /**
         * The name of the desired locale. The valid locale name should be in the format as
         * outlined in the Java Standard Language (i.e. <i>en_US</i> for English, United States).
         */
        std::string languageCode;
        /**
         * The localized language name
         */
        std::string languageName;
    };

    /**
     * Information about the list of languages
     */
    struct LanguageResponse
    {
        /**
         * An ordered list of languages
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Languageinformation::Language > languageList;
        /**
         * Any partial errors that may occur when filling this request
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response associated to some LanguageInformation operation calls
     */
    struct TranslationStatusResponse
    {
        /**
         * List of all the full translation statuses
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Languageinformation::FullTranslationStatus > fullTranslationStatuses;
        /**
         * The <code>ServiceData</code>.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Languageinformation() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

