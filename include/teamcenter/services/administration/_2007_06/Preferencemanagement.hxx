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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2007_06_PREFERENCEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2007_06_PREFERENCEMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            namespace _2007_06
            {
                class Preferencemanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Preferencemanagement
{
public:

    struct Context;
    struct PreferenceDefinition;
    struct PreferenceInfo;
    struct PreferencesInfo;
    struct PreferencesSetInput;

    /**
     * Represents the preference context values.
     */
    struct Context
    {
        /**
         * Context name for the values.
         * <br>
         * <br>
         * The default one is "<i>Teamcenter</i>". It can also be set to be used with NXManager,
         * by setting the <b>TC_Application</b> environment variable to <i>UGMAN</i>.
         * <br>
         */
        std::string contextName;
        /**
         * List of values applicable for the context.
         */
        std::vector< std::string > value;
    };

    /**
     * The PreferenceDefinition structure represents the definition for a preference in
     * Teamcenter.
     */
    struct PreferenceDefinition
    {
        /**
         * Name of the preference.
         */
        std::string preferenceName;
        /**
         * Category of the preference.
         */
        std::string preferenceCategory;
        /**
         * Description of the preference.
         */
        std::string preferenceDescription;
        /**
         * Scope of the preference. It can be "USER", "ROLE", "GROUP" or "SITE".
         */
        std::string preferenceScope;
        /**
         * Type of the preference. It can be "STRING", "LOGICAL", "INTEGER", "DOUBLE" or "DATE".
         */
        std::string preferenceType;
        /**
         * Specifies if this preference takes multiple values.
         */
        bool isArray;
        /**
         * Specifies if this preference is enabled.
         */
        bool isDisabled;
    };

    /**
     * Holds the complete information about a preference: its definition is captured in
     * the <b>PreferenceDefinition</b> structure, and its values in the list of <b>Context</b>
     * structures.
     * <br>
     */
    struct PreferenceInfo
    {
        /**
         * A structure holding the definition of the preference.
         */
        Teamcenter::Services::Administration::_2007_06::Preferencemanagement::PreferenceDefinition preferenceDefinition;
        /**
         * A list of <b>Context</b> structures, each representing the values for a given context.
         */
        std::vector< Teamcenter::Services::Administration::_2007_06::Preferencemanagement::Context > contextInformation;
    };

    /**
     * Contains a list of <b>PreferenceInfo</b> structures.
     */
    struct PreferencesInfo
    {
        /**
         * List of <b>PreferenceInfo</b> structure.
         */
        std::vector< Teamcenter::Services::Administration::_2007_06::Preferencemanagement::PreferenceInfo > prefsInfo;
    };

    /**
     * Input to be provided for setting preferences.
     */
    struct PreferencesSetInput
    {
        /**
         * Location of the preference.
         */
        std::string preferenceScope;
        /**
         * Preferences to be set.
         */
        Teamcenter::Services::Administration::_2007_06::Preferencemanagement::PreferencesInfo inputPrefs;
        /**
         * Object to which the preferences have to be assigned.
         * <br>
         * This can be a User, Role or Group. If no value is specified, preferences are set
         * for the current session based on the scope.
         * <br>
         * To be able to set preferences for the site, the user must be a system administrator.
         * <br>
         * To be able to set preferences for a group or a role, the user must be group administrator
         * or a system administrator.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };




    /**
     * Sets the values for session or non-session preferences.
     * <br>
     * <br>
     * Session preferences are preferences as seen from the current logged-in user.
     * <br>
     * Non-session preferences are preferences that are normally not accessible to the current
     * logged-in user.
     * <br>
     * <br>
     * To set a non-session preference, a target object must be specified in the <code>PreferencesSetInput</code>
     * structure. For user preferences, only the value of preference is stored in the database.
     * The description of user preference is never stored in the database.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param setPrefInput
     *        Details of the preferences to be set.
     *
     * @return
     *         Success is defined by the Partial Errors list in the service data object returned.
     *         Only Pass/Fail is returned in the error list. &lt;br /&gt;&lt;br /&gt;The error stack
     *         can contain the following error: &lt;br /&gt;&lt;ul&gt;&lt;ul&gt;&lt;li type=&quot;disc&quot;&gt;1713:
     *         if the scope parameter of the <code>PreferencesSetInput</code> structure is set to
     *         &quot;&lt;b&gt;SITE&lt;/b&gt;&quot; and an object is added to the structure.&lt;/li&gt;&lt;li&gt;1771:
     *         If one of the values is incompatible with a preference of type Integer.&lt;/li&gt;&lt;li&gt;1772:
     *         If one of the values is incompatible with a preference of type Double.&lt;/li&gt;&lt;li&gt;1773:
     *         If one of the values is incompatible with a preference of type Date.&lt;/li&gt;&lt;li&gt;1774:
     *         If one of the values is incompatible with a preference of type Logical.&lt;/li&gt;&lt;/ul&gt;&lt;/ul&gt;
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Teamcenter 10, use the setPreferences2 or setPreferencesDefinition operations.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the setPreferences2 or setPreferencesDefinition operations."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData setPreferences ( const std::vector< Teamcenter::Services::Administration::_2007_06::Preferencemanagement::PreferencesSetInput >& setPrefInput ) = 0;


protected:
    virtual ~Preferencemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

