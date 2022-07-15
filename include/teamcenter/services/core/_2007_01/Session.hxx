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

#ifndef TEAMCENTER_SERVICES_CORE__2007_01_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2007_01_SESSION_HXX

#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/ImanVolume.hxx>
#include <teamcenter/soa/client/model/POM_imc.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
#include <teamcenter/soa/client/model/TC_Project.hxx>
#include <teamcenter/soa/client/model/TC_WorkContext.hxx>
#include <teamcenter/soa/client/model/User.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2007_01
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct GetTCSessionInfoResponse;
    struct MultiPreferencesResponse;
    struct ReturnedPreferences;
    struct ScopedPreferenceNames;
    struct TextInfo;

    /**
     * ExtraInfo
     */
    typedef std::map< std::string, std::string > ExtraInfo;

    /**
     * Data structure representing the different current user's Teamcenter session information.
     */
    struct GetTCSessionInfoResponse
    {
        /**
         * The version of the server.
         */
        std::string serverVersion;
        /**
         * Path to the root folder of the transient volume.
         */
        std::string transientVolRootDir;
        /**
         * True if the server is operating in V7 mode.
         */
        bool isInV7Mode;
        /**
         * This element is not to be used anymore and always returns a -1.
         */
        int moduleNumber;
        /**
         * The <b>User</b> object for this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * The <b>Group</b> object for this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group;
        /**
         * The <b>Role</b> object for this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  role;
        /**
         * The <b>ImanVolume</b> object for this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanVolume>  tcVolume;
        /**
         * The <b>Project</b> object for this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_Project>  project;
        /**
         * The <b>WorkContext</b> object for this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TC_WorkContext>  workContext;
        /**
         * The site object for this session
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_imc>  site;
        /**
         * True if bypass is enabled.
         */
        bool bypass;
        /**
         * True if journaling is enabled.
         */
        bool journaling;
        /**
         * True if application journaling is enabled.
         */
        bool appJournaling;
        /**
         * True if sec journaling is enabled.
         */
        bool secJournaling;
        /**
         * True if administration journaling is enabled.
         */
        bool admJournaling;
        /**
         * True if the user is privileged.
         */
        bool privileged;
        /**
         * True if the Part BOM Usage is enabled.
         */
        bool isPartBOMUsageEnabled;
        /**
         * True if the Subscription Manager is enabled.
         */
        bool isSubscriptionMgrEnabled;
        /**
         * textInfos
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Session::TextInfo > textInfos;
        /**
         * Map of kev/value pairs (string/string). The following keys are returned:
         * <br>
         * <ul>
         * <li type="disc"><i>TcServerID</i>  &nbsp;&nbsp;&nbsp;&nbsp;Unique ID of this Teamcenter
         * server instance.&nbsp;&nbsp;&nbsp;&nbsp;
         * </li>
         * <li type="disc"><i>systemType</i>&nbsp;&nbsp;&nbsp;&nbsp;Type of server, always 'Teamcenter'
         * </li>
         * <li type="disc"><i>syslogFile</i>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
         * absolute path of the system log file (.syslog) on the server host.
         * </li>
         * <li type="disc"><i>Hostname</i>&nbsp;&nbsp;&nbsp;&nbsp;   The host name of the machine
         * hosting the Teamcenter server process.
         * </li>
         * <li type="disc"><i>TCServerLocale</i>&nbsp;&nbsp;&nbsp;&nbsp;The locale of the Teamcenter
         * server.
         * </li>
         * <li type="disc"><i>currentOrganization</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
         * user's current <b>Organization</b>. The business object instance is in the ServiceData
         * plain list
         * </li>
         * <li type="disc"><i>loginGroupOrganization</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
         * user's login <b>Organization</b>. The business object instance is in the ServiceData
         * plain list
         * </li>
         * <li type="disc"><i>currentChangeNotice</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
         * user's current <b>ChangeNotice</b> The business object instance is in the ServiceData
         * plain list
         * </li>
         * <li type="disc"><i>locationCodePref</i>&nbsp;&nbsp;&nbsp;&nbsp;The preferred location
         * code.
         * </li>
         * </ul>
         */
        ExtraInfo extraInfo;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Multiple Preferences Response
     */
    struct MultiPreferencesResponse
    {
        /**
         * List of Returned Preferences
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Session::ReturnedPreferences > preferences;
        /**
         * The successful Object ids, partial errors and failures
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Info for one preference
     */
    struct ReturnedPreferences
    {
        /**
         * The preference name.
         */
        std::string name;
        /**
         * The scope of the preference, "all", "site", "user", "group", or "role".
         */
        std::string scope;
        /**
         * The values for the perference.
         */
        std::vector< std::string > values;
    };

    /**
     * Info for getPreferences
     */
    struct ScopedPreferenceNames
    {
        /**
         * The scope of the preference, "all", "site", "user", "group", or "role".
         */
        std::string scope;
        /**
         * The names of the perferences.
         */
        std::vector< std::string > names;
    };

    /**
     * Text Information
     */
    struct TextInfo
    {
        /**
         * Real Name
         */
        std::string realName;
        /**
         * Display Name
         */
        std::string displayName;
    };




    /**
     * Get preference values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param requestedPrefs
     *        vector of PrefSetting structures, which specify the scope name for each of the preferences
     *        to be set.
     *
     * @return
     *         A PreferencesResponse structure. The preference names and values are returned in
     *         the preferences element. If no preference with the given name exists, no error is
     *         raised and no value is returned. Any other errors are returned in the serviceData
     *         element. ServiceException thrown if the named policy does not exist or if there are
     *         errors in setting this policy.
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 10, use the getPreferences operation from the PreferenceManagement
     *         service in the Administration library.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the getPreferences operation from the PreferenceManagement service in the Administration library."))
#endif
    virtual Teamcenter::Services::Core::_2007_01::Session::MultiPreferencesResponse getPreferences ( const std::vector< Teamcenter::Services::Core::_2007_01::Session::ScopedPreferenceNames >& requestedPrefs ) = 0;

    /**
     * This operation gets information about the current user's Teamcenter session. This
     * will return more detail session information than the login service operation including
     * <b>User</b>, <b>Group</b>, Role, <b>Site</b>, <b>Volume</b>, <b>Project</b>, and
     * <b>WorkContext</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @return
     *         Details about the current user's Teamcenter session information. All returned business
     *         objects are included plain list of the <code>ServiceData</code>.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2007_01::Session::GetTCSessionInfoResponse getTCSessionInfo (  ) = 0;

    /**
     * Sets the current object property policy. The business logic of a service operation
     * determines what business objects are returned, while the object property policy determines
     * which properties are returned on each business object instance. This allows the client
     * application to determine how much or how little data is returned based on how the
     * client application uses those returned business objects. The policy is applied uniformly
     * to all service operations.
     * <br>
     * By default, all applications use the <i>Default</i> object property policy, defined
     * on the Teamcenter server <code>$TC_DATA/soa/policies/default.xml. </code>It is this
     * policy that is applied to all service operation responses until the client application
     * changes the policy. Siemens PLM Software strongly recommends that all applications
     * change the policy to one applicable to the client early in the session.
     * <br>
     * The object property policy is set to the policy named in the file <code>$TC_DATA/soa/policies/<policyName>.xml
     * </code>The reserved policy name "<i>Empty</i>", will enforce a policy that only returns
     * minimum data required for each object (UID and type name).The object property policy
     * will stay in affect for this session until changed by another call to <code>setObjectPRopertyPolicy</code>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param policyName
     *        The name of the policy file without the <code>.xml </code>extension. The file must
     *        exist on the Teamcenter server volume at <code>$TC_DATA\soa\policies\<policyName>.xml.</code>
     *
     * @return
     *         True if the object property policy is successfully set to the named policy.
     *
     *
     * @exception ServiceException
     *           If the named policy does not exist or there are errors parsing the XML file (error
     *           code 214104).
     */
    virtual bool setObjectPropertyPolicy ( const std::string&  policyName ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

