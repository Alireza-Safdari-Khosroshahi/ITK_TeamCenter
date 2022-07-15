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

#ifndef TEAMCENTER_SERVICES_CORE_SESSIONSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_SESSIONSERVICE_HXX

#include <teamcenter/services/core/_2006_03/Session.hxx>
#include <teamcenter/services/core/_2007_01/Session.hxx>
#include <teamcenter/services/core/_2007_06/Session.hxx>
#include <teamcenter/services/core/_2007_12/Session.hxx>
#include <teamcenter/services/core/_2008_03/Session.hxx>
#include <teamcenter/services/core/_2008_06/Session.hxx>
#include <teamcenter/services/core/_2009_04/Session.hxx>
#include <teamcenter/services/core/_2010_04/Session.hxx>
#include <teamcenter/services/core/_2011_06/Session.hxx>
#include <teamcenter/services/core/_2012_02/Session.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class SessionService;

/**
 * The <code>Session</code> service exposes operations used to manage a client session
 * with the Teamcenter server. All client sessions must start with a <code>login</code>
 * operation and end with a <code>logout</code> operation. Throughout the client session,
 * the <code>Session</code> service may be used to change state such as <b>Group</b>,
 * <b>Role</b>, and object property policy.
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

class TCSOACLIENTMNGD_API SessionService
    : public Teamcenter::Services::Core::_2006_03::Session,
             public Teamcenter::Services::Core::_2007_01::Session,
             public Teamcenter::Services::Core::_2007_06::Session,
             public Teamcenter::Services::Core::_2007_12::Session,
             public Teamcenter::Services::Core::_2008_03::Session,
             public Teamcenter::Services::Core::_2008_06::Session,
             public Teamcenter::Services::Core::_2009_04::Session,
             public Teamcenter::Services::Core::_2010_04::Session,
             public Teamcenter::Services::Core::_2011_06::Session,
             public Teamcenter::Services::Core::_2012_02::Session
{
public:
    static SessionService* getService( Teamcenter::Soa::Client::Connection* );


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
     * @param prefScope
     *        The scope in which the preferences are to be searched,                     "all",
     *        "site", "user", "group", or "role".
     *
     * @param prefNames
     *        A vector of the names of the desired preferences.
     *
     * @return
     *         A PreferencesResponse structure. The preference names and values are returned in
     *         the preferences element. If no preference with the given name exists, no error is
     *         raised and no value is returned. Any other errors are returned in the serviceData
     *         element.
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of tceng2005sr1, use the getPreferences operation from the _2007_01 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tceng2005sr1, use the getPreferences operation from the _2007_01 namespace."))
#endif
    virtual Teamcenter::Services::Core::_2006_03::Session::PreferencesResponse getPreferences ( const std::string&  prefScope,
        const std::vector< std::string >& prefNames ) = 0;

    /**
     * Set preference values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param settings
     *        vector of PrefSetting structures, which specify the scope, name, and value(s) for
     *        each of the preferences to be set.
     *
     * @return
     *         A PreferencesResponse structure. The preferences element returns the new values of
     *         preferences which were successfully set. The serviceData element returns any partial
     *         errors encountered while setting specific preference values.
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 10, use the setPreferences operation from the PreferenceManagement
     *         service in the Administration library.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the setPreferences operation from the PreferenceManagement service in the Administration library."))
#endif
    virtual Teamcenter::Services::Core::_2006_03::Session::PreferencesResponse setPreferences ( const std::vector< Teamcenter::Services::Core::_2006_03::Session::PrefSetting >& settings ) = 0;

    /**
     * This operation returns a list of services and service operations that this Teamcenter
     * server instance supports. This is useful for client applications that expose different
     * functionality based on the version of the Teamcenter server it is connecting to.
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
     *         A list of available services. Each entry is the port value from the WSDL and has
     *         the format of:
     *         <br>
     *         <ul>
     *         <li type="disc">Core-2006-03-DataManagement
     *         </li>
     *         <li type="disc">Core-2006-03-FileManagement
     *         </li>
     *         <li type="disc">Core-2006-03-Session
     *         </li>
     *         <li type="disc">Core-2007-01-DataManagement
     *         </li>
     *         <li type="disc">Core-2007-01-FileManagement
     *         </li>
     *         <li type="disc">Core-2007-01-ManagedRelations
     *         </li>
     *         <li type="disc">Core-2007-01-Session
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         As of Teamcenter server 2007.1 MP3 the list will contain both service and operation
     *         names. Each operation will have the format of:
     *         <br>
     *         <ul>
     *         <li type="disc">Core-2006-03-DataManagement
     *         </li>
     *         <li type="disc">Core-2006-03-DataManagement.createFolders
     *         </li>
     *         <li type="disc">Core-2006-03-DataManagement.createItems
     *         </li>
     *         <li type="disc">Core-2006-03-DataManagement.createDatasets
     *         </li>
     *         <li type="disc">Core-2006-03-FileManagement
     *         </li>
     *         <li type="disc">Core-2006-03-FileManagement.getFileReadTickets
     *         </li>
     *         <li type="disc">Core-2006-03-FileManagement.getDatasetWriteTickets
     *         </li>
     *         <li type="disc">Core-2006-03-Session
     *         </li>
     *         <li type="disc">Core-2006-03-Session.login
     *         </li>
     *         <li type="disc">Core-2006-03-Session.logout
     *         </li>
     *         <li type="disc">Core-2006-03-Session.getAvailableServices
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Session::GetAvailableServicesResponse getAvailableServices (  ) = 0;

    /**
     * Get the valid groups and roles for the current user.
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
     *         A list of all the valid <b>GroupMember</b> objects for the current session`s <b>User</b>.
     *         A <b>GroupMember</b> holds identifiers for a <b>User</b>, <b>Group</b>, and <b>Role</b>
     *         and represents that the user belongs to a group with the particular role. Each <b>Group</b>
     *         and <b>Role</b> are also added to the plain list of the <code>ServiceData</code>.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2006_03::Session::GetGroupMembershipResponse getGroupMembership (  ) = 0;

    /**
     * Get the <b>Group</b> and <b>Role</b> for the current session. The group and role
     * are set at login, either to default values or as specified by the input arguments
     * to the login operation. The group and role can be changed at any time throughout
     * the session through the <code>setSessionGroupMember</code> or <code>setUserSessionState</code>
     * operations.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setSessionGroupMember
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
     *         This contains the <b>GroupMember</b> object which represents the logged in user`s,
     *         <b>Group</b>, and <b>Role</b> for the current session. The <b>GroupMember</b> object
     *         is included in the <code>ServiceData</code> plain list.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2006_03::Session::GetSessionGroupMemberResponse getSessionGroupMember (  ) = 0;

    /**
     * Authenticates the user's credentials and initialize a Teamcenter session for this
     * client. The operation will throw an <code>InvalidCredentialsException</code> if the
     * <code>username</code>, <code>password</code> or <code>group</code> is not valid.
     * <br>
     * When the client application is deployed to a 4Tier environment (communication through
     * HTTP or TCCS) the login operation also contributes to the assignment of a Teamcenter
     * server instance to the client session. The Teamcenter architecture varies from other
     * client server architectures in that there is a dedicated instance of the Teamcenter
     * server per client application. However, there are use cases where it is desirable
     * for a single user to have multiple desktop applications running and each sharing
     * a single instance of a Teamcenter server. This is controlled through the following
     * elements:
     * <br>
     * <ul>
     * <li type="disc"><code>hostPath</code>&nbsp;&nbsp;&nbsp;&nbsp;From the Connection
     * class constructor, this specifies  the address (URI) the Teamcenter server is hosted
     * on.
     * </li>
     * <li type="disc"><code>username</code>&nbsp;&nbsp;&nbsp;&nbsp;From this login operation,
     * this specifies the user's Teamcenter user name.
     * </li>
     * <li type="disc"><code>sessionDiscriminator</code>&nbsp;&nbsp;&nbsp;&nbsp;From this
     * login operation, this identifies the client session.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The <code>hostPath</code> argument determines the server machine that the client
     * connects to. Once there, the pool manager on that host uses the <code>username</code>
     * and <code>sessionDiscriminator</code> arguments of the logon request to determine
     * which Teamcenter server instance to assign the client to. If the pool manager has
     * an existing Teamcenter server instance with the <code>username</code>/<code>sessionDiscriminator</code>
     * key, the client is assigned to that existing instance of the Teamcenter server, and
     * therefore sharing the server with another client; otherwise, a new instance of the
     * Teamcenter server is used. There are a few general scenarios for the <code>sessionDiscriminator</code>
     * argument:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Blank &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on to
     * Teamcenter using two or more client applications using a blank <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/ ), all of those clients are assigned to the same
     * Teamcenter server instance. These client applications can be running on the same
     * or different client hosts.
     * </li>
     * <li type="disc">Constant &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on
     * to Teamcenter using two or more client applications using a constant or fixed <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/<i>MyApp</i> ), those clients are assigned to
     * the same Teamcenter server instance. This is similar to the blank <code>sessionDiscriminator</code>
     * argument; the difference is that only multiple instances of the client application
     * using <i>myApp</i> started by <i>jdoe</i> share the same Teamcenter server instance.
     * </li>
     * <li type="disc">Unique &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on using
     * a unique random-generated string (for example, <i>jdoe</i>/<i>akdk938lakc</i>), the
     * client application will be assigned to a dedicated instance of the Teamcenter server.
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The scenario you use depends on how your client application is used in the integrated
     * environment. The most common case is the unique <code>sessionDiscriminator</code>
     * value.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param username
     *        The user's Teamcenter user name.
     *
     * @param password
     *        The user's Teamcenter password.
     *
     * @param group
     *        The group ID for this session. If empty (""), the user's default group is assumed.
     *
     * @param role
     *        The role the user is performing in the group. If empty (""), the user's default role
     *        in the group is assumed.
     *
     * @param sessionDiscriminator
     *        Client defined identifier for this session. This argument is ignored when the client
     *        application is deployed in a 2Tier environment (IIOP communication).
     *
     * @return
     *         The  <b>User</b> and <b>GroupMember</b> objects for the user of this session.
     *         <br>
     *
     *
     * @exception InvalidCredentialsException
     *           When the credentials supplied are invalid or the requested locale is not allowed.
     *           
     *           <br>
     *           <ul>
     *           <li type="disc">515143:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515144:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515142:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to an invalid
     *           <code>group</code>.
     *           </li>
     *           </ul>
     * @deprecated
     *         As of Teamcenter 10, use the login operation from the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the login operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Services::Core::_2006_03::Session::LoginResponse login ( const std::string&  username,
        const std::string&  password,
        const std::string&  group,
        const std::string&  role,
        const std::string&  sessionDiscriminator ) = 0;

    /**
     * Authenticates the user using Single-Sign-On (SSO) credentials and initialize a Teamcenter
     * session for this client. The <code>username</code> and <code>ssoCredentials</code>
     * arguments must be obtained from Teamcenter's Security Services. The <code>SsoCredentials</code>
     * class offers a simple API to get these values. The operation will throw an <code>InvalidCredentialsException</code>
     * if the <code>username</code>, <code>ssoCredentials</code> or group is not valid.
     * <br>
     * When the client application is deployed to a 4Tier environment (communication through
     * HTTP or TCCS) the login operation also contributes to the assignment of a Teamcenter
     * server instance to the client session. The Teamcenter architecture varies from other
     * client server architectures in that there is a dedicated instance of the Teamcenter
     * server per client application. However, there are use cases where it is desirable
     * for a single user to have multiple desktop applications running and each sharing
     * a single instance of a Teamcenter server. This is controlled through the following
     * elements:
     * <br>
     * <ul>
     * <li type="disc"><code>hostPath</code>&nbsp;&nbsp;&nbsp;&nbsp;From the Connection
     * class constructor, this specifies  the address (URI) the Teamcenter server is hosted
     * on.
     * </li>
     * <li type="disc"><code>username</code>&nbsp;&nbsp;&nbsp;&nbsp;From this login operation,
     * this specifies the user's Teamcenter user name.
     * </li>
     * <li type="disc"><code>sessionDiscriminator</code>&nbsp;&nbsp;&nbsp;&nbsp;From this
     * login operation, this identifies the client session.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The <code>hostPath</code> argument determines the server machine that the client
     * connects to. Once there, the pool manager on that host uses the <code>username</code>
     * and <code>sessionDiscriminator</code> arguments of the logon request to determine
     * which Teamcenter server instance to assign the client to. If the pool manager has
     * an existing Teamcenter server instance with the <code>username</code>/<code>sessionDiscriminator</code>
     * key, the client is assigned to that existing instance of the Teamcenter server, and
     * therefore sharing the server with another client; otherwise, a new instance of the
     * Teamcenter server is used. There are a few general scenarios for the sessionDiscriminator
     * argument:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Blank &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on to Teamcenter
     * using two or more client applications using a blank <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/ ), all of those clients are assigned to the same
     * Teamcenter server instance. These client applications can be running on the same
     * or different client hosts.
     * </li>
     * <li type="disc">Constant &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on to Teamcenter
     * using two or more client applications using a constant or fixed <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/<i>MyApp</i> ), those clients are assigned to
     * the same Teamcenter <code>server</code> instance. This is similar to the blank sessionDiscriminator
     * argument; the difference is that only multiple instances of the client application
     * using myApp started by jdoe share the same Teamcenter server instance.
     * </li>
     * <li type="disc">Unique &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on using a unique
     * random-generated string (for example, <i>jdoe</i>/<i>akdk938lakc</i>), the client
     * application will be assigned to a dedicated instance of the Teamcenter server.
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The scenario you use depends on how your client application is used in the integrated
     * environment. The most common case is the unique <code>sessionDiscriminator</code>
     * value.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param username
     *        The user's Teamcenter username.
     *
     * @param ssoCredentials
     *        The user's Teamcenter SSO credentials. This should have been obtained from Teamcenter
     *        Security Services.
     *
     * @param group
     *        The group id for this session. If blank (""), the user's default group is assumed.
     *
     * @param role
     *        The role the user is performing in the group. If blank (""), the user's default role
     *        in the group is assumed.
     *
     * @param sessionDiscriminator
     *        Client defined identifier for this session. This argument is ignored when the client
     *        application is deployed in a 2Tier environment (IIOP communication).
     *
     * @return
     *         The  <b>User</b> and <b>GroupMember</b> objects for the user of this session. Partial
     *         Errors are returned in the <code>ServiceData</code> when the authentication is successful
     *         but requested role is not supported:
     *         <br>
     *         <ul>
     *         <li type="disc">214102: &nbsp;&nbsp;&nbsp;&nbsp;The login is accepted, however the
     *         requested <code>role</code> is not valid, and the default role will be used.
     *         </li>
     *         </ul>
     *
     *
     * @exception InvalidCredentialsException
     *           When the credentials supplied are invalid or the requested locale is not allowed.
     *           
     *           <br>
     *           <ul>
     *           <li type="disc">515143:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>ssoCredentials</code>
     *           </li>
     *           <li type="disc">515144:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>ssoCredentials</code>
     *           </li>
     *           <li type="disc">515142:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to an invalid
     *           <code>group</code>.
     *           </li>
     *           </ul>
     * @deprecated
     *         As of Teamcenter 10, use the loginSSO operation from the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the loginSSO operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Services::Core::_2006_03::Session::LoginResponse loginSSO ( const std::string&  username,
        const std::string&  ssoCredentials,
        const std::string&  group,
        const std::string&  role,
        const std::string&  sessionDiscriminator ) = 0;

    /**
     * Logout and terminate the Teamcenter session. If the Teamcenter server is being shared
     * with multiple client applications, it will not be terminated until each client has
     * issued the <code>logout</code>.
     * <br>
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
     *         Any system error encountered while terminating the Teamcenter server instance are
     *         reported to the client through partial errors.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData logout (  ) = 0;

    /**
     * Set the <b>Group</b> and <b>Role</b> for the current session. The group and role
     * are set at login, either to default values or as specified by the input arguments
     * to the login operation. The group and role can be changed at any time throughout
     * the session through this operation or the <code>setUserSessionState</code> operations.
     * The <code>getSessionGroupMember</code> will return the current group and roll.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getSessionGroupMember
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param groupMember
     *        The desired <b>GroupMember</b> for the current session.  The <b>GroupMember</b> defines
     *        the <b>Group</b> and <b>Role</b> for the session.
     *
     * @return
     *         The <b>GroupMember</b> is returned in the plain list, and will have the <code>group</code>
     *         and <code>role</code> property values returned in addition to any properties defined
     *         in the object property policy.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData setSessionGroupMember ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GroupMember>  groupMember ) = 0;

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

    /**
     * By Default the service operations will retrieve property value data straight from
     * the POM. When <code>refresh</code> is set to true, a refresh will be done on business
     * objects before getting any property data. This will update the POM with fresh data
     * from the database. The refresh is only applied to business objects that are actually
     * being returned by a service operation. This applies only to database objects, and
     * is not applied to runtime objects.  This is applied to all subsequent service requests
     * from the same client. If multiple clients are sharing the same Teamcenter server
     * session the refresh POM state is applied per client. Setting this to true will have
     * a performance impact but will grantee all property values returned are up-to-date.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param refresh
     *        If true, the business objects are refreshed before getting property values, if false
     *        the properties are retrieved from the POM without checks to the database.
     *
     * @return
     *         True is always returned.
     *
     */
    virtual bool refreshPOMCachePerRequest ( bool refresh ) = 0;

    /**
     * Set the ID display rule for the session and optionally set it in the database.  The
     * business objects from the <code>identifiableObjects</code> list are expanded using
     * the new ID display rule and returned. The rule is applied to all business objects
     * process throughout the rest of the session.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param identifiableObjects
     *        A list of business objects for which the new ID display rule has to be re-evaluated.
     *
     * @param displayRule
     *        The ID display rule that is to be used for evaluation.
     *
     * @param setRuleAsCurrentInDB
     *        If true then the ID display rule will be set for the current user in the database.
     *
     * @return
     *         If the requested <code>displayRule</code> is invalid, partial error 214312 is returned,
     *         and none of the  <code>identifiableObjects</code> are processed.  Otherwise each
     *         <code>identifiableObjects</code> is expanded with the new ID display rule and returned
     *         in the plain list of the <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setAndEvaluateIdDisplayRule ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& identifiableObjects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdDispRule>  displayRule,
        bool setRuleAsCurrentInDB ) = 0;

    /**
     * Set the desired user session state values.  To clear a field's value, pass an empty
     * string "" as the value. Failure to set a particular state value will result in a
     * Partial Error with the clientId set to the name of the state property. State values
     * can be per client session or per server session. Client session state is kept separate
     * for each client application sharing the same Teamcenter server session, while server
     * session state is shared with all client application sharing the Teamcenter server
     * session. Valid keys for the session state pairs are:
     * <br>
     * <ul>
     * <li type="disc"><i>groupMember</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired
     * <b>GroupMember</b> (server session).
     * </li>
     * <li type="disc"><i>currentProject</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired
     * <b>Project</b> (server session).
     * </li>
     * <li type="disc"><i>workContext</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired
     * <b>WorkContext</b> (server session).
     * </li>
     * <li type="disc"><i>currentOrganization</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
     * desired <b>Organization</b> (server session).
     * </li>
     * <li type="disc"><i>refreshPOM</i> &nbsp;&nbsp;&nbsp;&nbsp;'1' (true) to refresh business
     * objects in the POM before returning property values. This ensures property data is
     * up-to-date, but is a performance hit (client session).
     * </li>
     * <li type="disc"><i>maxOperationBracketTime</i>&nbsp;&nbsp;&nbsp;&nbsp;Time (seconds)
     * to bracket to limit a  POM refresh (client session).
     * </li>
     * <li type="disc"><i>maxOperationBracketInactiveTime</i>  Time (seconds) to bracket
     * to limit a  POM refresh (client session).
     * </li>
     * <li type="disc"><i>currentChangeNotice</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
     * desired <b>ChangeNotice</b> (server session).
     * </li>
     * <li type="disc"><i>clientVersion</i>&nbsp;&nbsp;&nbsp;&nbsp;The version of the client
     * (client session).
     * </li>
     * <li type="disc"><i>locale</i>&nbsp;&nbsp;&nbsp;&nbsp;The locale of the session (server
     * session).
     * </li>
     * <li type="disc"><i>volume</i> &nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired <b>Volume</b>
     * (server session).
     * </li>
     * <li type="disc"><i>objectPropertyPolicy</i>&nbsp;&nbsp;&nbsp;&nbsp;The name of the
     * desired object property policy.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param pairs
     *        A list of name/value pairs of state properties to set.
     *
     * @return
     *         A partial error for any state value that was not set. The 'clientId' of the partial
     *         error is set to the name of the state variable.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setUserSessionState ( const std::vector< Teamcenter::Services::Core::_2007_12::Session::StateNameValue >& pairs ) = 0;

    /**
     * Performs Teamcenter Flexlm license related operations, depending on the input parameters.
     * <br>
     * <br>
     * The low level actions are:
     * <br>
     * <br>
     * 1.  ILM__init_module: Initializes the license module (if it has not already been
     * initialized).
     * <br>
     * 2.  ILM__leave_module: Deallocates a license of the given module. If the user had
     * N free licenses for this module, (N plus one) will be left after this call.
     * <br>
     * 3.  ILM__check_module: Checks to see if the user has bought the specified module
     * and returns the number of purchased licenses.
     * <br>
     * 4.  ILM__enter_module: Allocates one license of the given module. If the user has
     * bought N licenses for this module, (N minus one) will be left after this call.
     * <br>
     * 5.  ILM__exit_module: Leaves the module.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Licensing - Provides the capability to assign and monitor licenses such that the
     * users (an individual; a system; a module etc.) of teamcenter can be limited to use
     * the capabilities that they have privileges for
     *
     * @param featureKey
     *        A string corresponding to the product as listed in the license file (e.g. teamcenter_author)
     *
     * @param action
     *        A string corresponding to the desired action. Valid values are:
     *        <br>
     *        1.   init: Performs the ILM__init_module action (connect to the license server).
     *        <br>
     *        2.   release: Performs the ILM__leave_module action.
     *        <br>
     *        3.   check: Performs the ILM__check_module action.
     *        <br>
     *        4.   exit: Performs the ILM__exit_module action.
     *        <br>
     *        5.   get: Performs the ILM__check_module and ILM__enter_module actions in this order.
     *        <br>
     *        6.   init_get: Performs the ILM__init_module, ILM__check_module and ILM__enter_module
     *        actions in this order.
     *        <br>
     *        7.   release_exit: Performs the ILM__leave_module and ILM__exit_module actions in
     *        this order.
     *        <br>
     *
     * @return
     *         contains a ServiceData (ConnectResponse.serviceData), and number of licenses avaliable.
     *         Any failure will be returned via ServiceData with error message.
     *
     */
    virtual Teamcenter::Services::Core::_2008_03::Session::ConnectResponse connect ( const std::string&  featureKey,
        const std::string&  action ) = 0;

    /**
     * This operation retrieves the saved Favorites containers and Favorites objects for
     * the current session user.  You can use Favorites to track containers and objects
     * you access frequently, such as folders, parts or forms.
     * <br>
     * <br>
     * If errors are encountered, partial results are returned. Partial errors are returned
     * with client IDs reflecting the index value of the saved Favorite. A service exception
     * is thrown if an error is encountered that is not related to a specific Favorite container
     * or Favorite object.
     * <br>
     * <br>
     * Any Teamcenter object that is returned as a Favorite object is added to <code>ServiceData</code>
     * plain objects.  For example, if an item exists in the list of Favorite objects, the
     * object tag value for that item will be returned in the <code>ServiceData</code> list
     * of plain objects.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User logs in and selects their saved Favorites.
     * <br>
     * <br>
     * The Favorites view in the client application is populated with the Favorites containers
     * and objects returned from this operation.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setFavorites
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         Hierarchical Favorite containers and Favorite objects previously saved for the current
     *         session user.
     *         <br>
     *         <br>
     *         The following error originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214335: &nbsp;&nbsp;&nbsp;&nbsp;Get favorites failure.  The error
     *         text contains information detailing the specific error.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           <code>Service Exception</code>&nbsp;&nbsp;&nbsp;&nbsp;Thrown if the retrieval
     *           of saved favorites fails for the current user, the favorites preference value is
     *           missing a field or if the favorites object for the specified ID is not found.
     * @deprecated
     *         As of Teamcenter 8.2, use the getShortcuts operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the getShortcuts operation."))
#endif
    virtual Teamcenter::Services::Core::_2008_03::Session::FavoritesResponse getFavorites (  ) = 0;

    /**
     * This operation saves new favorite containers and favorite objects for the current
     * session user.
     * <br>
     * <br>
     * Any partial errors encountered during this operation are returned using the <code>clientID</code>
     * specified by the caller. A service exception is thrown if an error is encountered
     * that is not related to a specific favorite container or favorite object.  You can
     * use favorites to track containers and objects you access frequently, such as folders,
     * parts or forms.  For example, the Newstuff folder could be added as a container to
     * the list of favorites.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User saves a container to their favorites list.
     * <br>
     * <br>
     * For this operation, the list of all current favorites for the user and the list containing
     * the container the user desires to add are supplied as input and the new container
     * is added to the list of saved favorites in Teamcenter.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        The information required to establish a new set of saved favorites for the current
     *        session user.
     *
     * @return
     *         <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         The following error originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214352: &nbsp;&nbsp;&nbsp;&nbsp;Set favorites failure.  The error
     *         text contains information detailing the specific error.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           <code>Service Exception</code>&nbsp;&nbsp;&nbsp;&nbsp;Thrown if an empty or invalid
     *           container or object input parameter is specified or the list of current favorites
     *           specified is no longer current.
     */
    virtual Teamcenter::Soa::Client::ServiceData setFavorites ( const Teamcenter::Services::Core::_2008_03::Session::FavoritesInfo&  input ) = 0;

    /**
     * Get the localized text string for each input key from the info array. The input key
     * must correspond to a key defined in the Text Server. If the input array is empty,
     * the returned array will also be empty.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param info
     *        A list of Text Server key names.
     *
     * @return
     *         An array Text Server key/localized value pairs. Any errors encountered while looking
     *         up a given Text Server key will be returned as a partial error with the key name
     *         attached to the partial error.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Session::GetDisplayStringsResponse getDisplayStrings ( const std::vector< std::string >& info ) = 0;

    /**
     * Authenticates the user`s credentials and initialize a Teamcenter session for this
     * client. The operation will throw an <code>InvalidCredentialsException</code> if the
     * <code>username</code>, <code>password</code> or <code>group</code> is not valid.
     * <br>
     * When the client application is deployed to a 4Tier environment (communication through
     * HTTP or TCCS) the <code>login</code> operation also contributes to the assignment
     * of a Teamcenter server instance to the client session. The Teamcenter architecture
     * varies from other client server architectures in that there is a dedicated instance
     * of the Teamcenter server per client application. However, there are use cases where
     * it is desirable for a single user to have multiple desktop applications running and
     * each sharing a single instance of a Teamcenter server. This is controlled through
     * the following elements:
     * <br>
     * <ul>
     * <li type="disc"><code>hostPath</code>&nbsp;&nbsp;&nbsp;&nbsp;From the Connection
     * class constructor, this specifies  the address (URI) the Teamcenter server is hosted
     * on.
     * </li>
     * <li type="disc"><code>username</code>&nbsp;&nbsp;&nbsp;&nbsp;From this login operation,
     * this specifies the user`s Teamcenter user name.
     * </li>
     * <li type="disc"><code>sessionDiscriminator</code>&nbsp;&nbsp;&nbsp;&nbsp;From this
     * login operation, this identifies the client session.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The <code>hostPath</code> argument determines the server machine that the client
     * connects to. Once there, the pool manager on that host uses the <code>username</code>
     * and <code>sessionDiscriminator</code> arguments of the <code>logon</code> request
     * to determine which Teamcenter server instance to assign the client to. If the pool
     * manager has an existing Teamcenter server instance with the <code>username</code>/<code>sessionDiscriminator</code>
     * key, the client is assigned to that existing instance of the Teamcenter server, and
     * therefore sharing the server with another client; otherwise, a new instance of the
     * Teamcenter server is used. There are a few general scenarios for the <code>sessionDiscriminator</code>
     * argument:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Blank &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on to
     * Teamcenter using two or more client applications using a blank <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/ ), all of those clients are assigned to the same
     * Teamcenter server instance. These client applications can be running on the same
     * or different client hosts.
     * </li>
     * <li type="disc">Constant &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on
     * to Teamcenter using two or more client applications using a constant or fixed <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/<i>MyApp</i> ), those clients are assigned to
     * the same Teamcenter server instance. This is similar to the blank <code>sessionDiscriminator</code>
     * argument; the difference is that only multiple instances of the client application
     * using <i>myApp</i> started by <i>jdoe</i> share the same Teamcenter server instance.
     * </li>
     * <li type="disc">Unique &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on using
     * a unique random generated string (for example, <i>jdoe</i>/<i>akdk938lakc</i>), the
     * client application will be assigned to a dedicated instance of the Teamcenter server.
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The scenario you use depends on how your client application is used in the integrated
     * environment. The most common case is the unique <code>sessionDiscriminator</code>
     * value.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param username
     *        The user`s Teamcenter user name. This is case insensitive (<i>jdoe</i> or <i>JDOE</i>)
     *
     * @param password
     *        The user`s Teamcenter password.
     *
     * @param group
     *        The group ID for this session. If null, the user`s default group is assumed.
     *
     * @param role
     *        The role the user is performing in the group. If null, the user`s default role in
     *        the group is assumed.
     *
     * @param locale
     *        The locale to be used by the Teamcenter server process for this session. If null,
     *        the server`s default locale will be used.
     *
     * @param sessionDiscriminator
     *        Client defined identifier for this session. This argument is ignored when the client
     *        application is deployed in a 2Tier environment (IIOP communication).
     *
     * @return
     *         The  <b>User</b> and <b>GroupMember</b> objects for the user of this session. Partial
     *         Errors are returned in the <code>ServiceData</code> when the authentication is successful
     *         but requested role or locale is not supported:
     *         <br>
     *         <ul>
     *         <li type="disc">214102: &nbsp;&nbsp;&nbsp;&nbsp;The login is accepted, however the
     *         requested role is not valid, and the default role will be used.
     *         </li>
     *         <li type="disc">128003: &nbsp;&nbsp;&nbsp;&nbsp;The logon is accepted. However, data
     *         entry should be done using certain locales, as specified by the <b>TC_language_data_entry</b>
     *         preference. The details of the data entry are returned in the error message.
     *         </li>
     *         <li type="disc">128004:&nbsp;&nbsp;&nbsp;&nbsp;The logon is accepted. However, data
     *         entry should only contain characters that belong to the encoding of the database
     *         instance. The information is in the error message.
     *         </li>
     *         </ul>
     *
     *
     * @exception InvalidCredentialsException
     *           When the credentials supplied are invalid or the requested locale is not allowed.
     *           
     *           <br>
     *           <ul>
     *           <li type="disc">515143:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515144:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515142:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to an invalid
     *           <code>group</code>.
     *           </li>
     *           <li type="disc">128001: The logon was refused due to conflict with the encoding of
     *           the database instance.
     *           </li>
     *           <li type="disc">128002:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to missing
     *           localization.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Core::_2006_03::Session::LoginResponse login ( const std::string&  username,
        const std::string&  password,
        const std::string*  group,
        const std::string*  role,
        const std::string*  locale,
        const std::string&  sessionDiscriminator ) = 0;

    /**
     * Authenticates the user using Single-Sign-On (SSO) credentials and initialize a Teamcenter
     * session for this client. The <code>username</code> and <code>ssoCredentials</code>
     * arguments must be obtained from Teamcenter's Security Services. The <code>SsoCredentials</code>
     * class offers a simple API to get these values. The operation will throw an <code>InvalidCredentialsException</code>
     * if the <code>username</code>, <code>ssoCredentials</code> or <code>group</code> is
     * not valid.
     * <br>
     * When the client application is deployed to a 4Tier environment (communication through
     * HTTP or TCCS) the login operation also contributes to the assignment of a Teamcenter
     * server instance to the client session. The Teamcenter architecture varies from other
     * client server architectures in that there is a dedicated instance of the Teamcenter
     * server per client application. However, there are use cases where it is desirable
     * for a single user to have multiple desktop applications running and each sharing
     * a single instance of a Teamcenter server. This is controlled through the following
     * elements:
     * <br>
     * <code>hostPath</code>&nbsp;&nbsp;&nbsp;&nbsp;From the Connection class constructor,
     * this specifies  the address (URI) the Teamcenter server is hosted on.
     * <br>
     * <code>username</code>&nbsp;&nbsp;&nbsp;&nbsp;From this login operation, this specifies
     * the user's Teamcenter user name.
     * <br>
     * <code>sessionDiscriminator</code>&nbsp;&nbsp;&nbsp;&nbsp;From this login operation,
     * this identifies the client session.
     * <br>
     * <br>
     * The <code>hostPath</code> argument determines the server machine that the client
     * connects to. Once there, the pool manager on that host uses the <code>username</code>
     * and <code>sessionDiscriminator</code> arguments of the login request to determine
     * which Teamcenter server instance to assign the client to. If the pool manager has
     * an existing Teamcenter server instance with the <code>username</code>/<code>sessionDiscriminator</code>
     * key, the client is assigned to that existing instance of the Teamcenter server, and
     * therefore sharing the server with another client; otherwise, a new instance of the
     * Teamcenter server is used. There are a few general scenarios for the <code>sessionDiscriminator</code>
     * argument:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Blank &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on to Teamcenter
     * using two or more client applications using a blank sessionDiscriminator argument
     * (for example, <i>jdoe</i>/ ), all of those clients are assigned to the same Teamcenter
     * server instance. These client applications can be running on the same or different
     * client hosts.
     * </li>
     * <li type="disc"><code>Constant</code> &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs
     * on to Teamcenter using two or more client applications using a constant or fixed
     * sessionDiscriminator argument (for example, <i>jdoe</i>/<i>MyApp</i> ), those clients
     * are assigned to the same Teamcenter server instance. This is similar to the blank
     * <code>sessionDiscriminator</code> argument; the difference is that only multiple
     * instances of the client application using myApp started by jdoe share the same Teamcenter
     * server instance.
     * </li>
     * <li type="disc">Unique &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on using a unique
     * random-generated string (for example, <i>jdoe</i>/<i>akdk938lakc</i>), the client
     * application will be assigned to a dedicated instance of the Teamcenter server.
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The scenario you use depends on how your client application is used in the integrated
     * environment. The most common case is the unique <code>sessionDiscriminator</code>
     * value.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param username
     *        The user's Teamcenter username.
     *
     * @param ssoCredentials
     *        The user's Teamcenter SSO credentials. This should have been obtained from Teamcenter
     *        Security Services.
     *
     * @param group
     *        The group id for this session (optional). If NULL, the user's default group is assumed.
     *
     * @param role
     *        The role the user is performing in the group (optional). If NULL, the user's default
     *        role in the group is assumed.
     *
     * @param locale
     *        The locale to be used by the Teamcenter server process for this session (optional).
     *        If NULL, the server's default locale will be used.
     *
     * @param sessionDiscriminator
     *        Client defined identifier for this session. This argument is ignored when the client
     *        application is deployed in a 2Tier environment (IIOP communication).
     *
     * @return
     *         The  <b>User</b> and <b>GroupMember</b> objects for the user of this session. Partial
     *         Errors are returned in the <code>ServiceData</code> when the authentication is successful
     *         but requested role or locale is not supported:
     *         <br>
     *         <ul>
     *         <li type="disc">214102: &nbsp;&nbsp;&nbsp;&nbsp;The login is accepted, however the
     *         requested <code>role</code> is not valid, and the default role will be used.
     *         </li>
     *         <li type="disc">128003: &nbsp;&nbsp;&nbsp;&nbsp;The logon is accepted. However, data
     *         entry should be done using certain locales, as specified by the <b>TC_language_data_entry</b>
     *         preference. The details of the data entry are returned in the error message.
     *         </li>
     *         <li type="disc">128004:&nbsp;&nbsp;&nbsp;&nbsp;The login is accepted. However, data
     *         entry should only contain characters that belong to the encoding of the database
     *         instance. The information is in the error message.
     *         </li>
     *         </ul>
     *
     *
     * @exception InvalidCredentialsException
     *           When the credentials supplied are invalid or the requested locale is not allowed.
     *           
     *           <br>
     *           <ul>
     *           <li type="disc">515143:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515144:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515142:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to an invalid
     *           <code>group</code>.
     *           </li>
     *           <li type="disc">128001: The logon was refused due to conflict with the encoding of
     *           the database instance.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Core::_2006_03::Session::LoginResponse loginSSO ( const std::string&  username,
        const std::string&  ssoCredentials,
        const std::string*  group,
        const std::string*  role,
        const std::string*  locale,
        const std::string&  sessionDiscriminator ) = 0;

    /**
     * Sets the current object property policy. The business logic of a service operation
     * determines what business objects are returned, while the object property policy determines
     * which properties are returned on each business object instance.  This allows the
     * client application to determine how much or how little data is returned based on
     * how the client application uses those returned business objects. The policy is applied
     * uniformly to all service operations.
     * <br>
     * By default, all applications use the <i>Default</i> object property policy, defined
     * on the Teamcenter server <code>$TC_DATA/soa/policies/default.xml.</code> It is this
     * policy that is applied to all service operation responses until the client application
     * changes the policy. Siemens PLM Software strongly recommends that all applications
     * change the policy to one applicable to the client early in the session.
     * <br>
     * The object property policy will stay in affect for this session until changed by
     * another call to <code>setObjectPRopertyPolicy</code>. The current policy can be modified
     * with calls to <code>updatObjectPropertyPolicy</code>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * updateObjectPropertyPolicy
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param policy
     *        The object property policy.
     *
     * @return
     *         Unique ID for this object property policy. This ID is used on subsequent calls to
     *         <code>updateObjectPropertyPolicy</code>.
     *
     */
    virtual std::string setObjectPropertyPolicy ( const Teamcenter::Soa::Common::ObjectPropertyPolicy&  policy ) = 0;

    /**
     * Start an operation bracket.  An operation bracket is a period of execution in which
     * any object will need to be refreshed in the server from the database only once.
     * This allows the client to avoid unnecessary database operations that the server might
     * perform redundantly if underlying code accesses the same object multiple times.
     * The client will use the return value to call the <code>stopOperation</code> operation
     * to indicate the end of the bracket.  Brackets may be nested or overlapped.  A bracket
     * should start and end within the scope of a single client function and should not
     * span a user interaction.  By default, each service operation starts and stops its
     * own operation bracket.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * stopOperation
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
     *         The Operation Identifier assigned to the operation, to be used to stop the operation
     *         bracket.
     *
     */
    virtual std::string startOperation (  ) = 0;

    /**
     * Stop an operation bracket, in which objects need to be refreshed only once.  See
     * <code>startOperation</code>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * startOperation
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param opId
     *        The operation identifier assigned to the operation and returned by the <code>startOperation</code>
     *        request.
     *
     * @return
     *         true
     *
     */
    virtual bool stopOperation ( const std::string&  opId ) = 0;

    /**
     * This operation takes an input structure which contains a scope value and vector of
     * preference names. The return type of this operation is the MultiPreferencesResponse2
     * structure whose elements are the ServiceData and the vector of ReturnedPreferences2
     * structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param preferenceNames
     *        The input structure, the object of which would ahve 2 input parameters of scope and
     *        the preference names.
     *
     * @return
     *         This structure is used to return Preference
     *
     * @deprecated
     *         As of Teamcenter 10, use the getPreferences operation from the PreferenceManagement
     *         service in the Administration library.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the getPreferences operation from the PreferenceManagement service in the Administration library."))
#endif
    virtual Teamcenter::Services::Core::_2010_04::Session::MultiPreferenceResponse2 getPreferences2 ( const std::vector< Teamcenter::Services::Core::_2007_01::Session::ScopedPreferenceNames >& preferenceNames ) = 0;

    /**
     * This operation gets the sections and corresponding content in Left Hand Navigation
     * task pane given the section name and the corresponding preference name for the current
     * session user. The preference name is the key to look up section content stored in
     * preference.&nbsp;&nbsp;&nbsp;&nbsp;In the rich client, the LHN sections are Quick
     * Links, Open Items, History, Favorites and I Want To. The user can organize Teamcenter
     * data in these sections during runtime, which is persisted in the preference. The
     * Quick Links section provides a quick access point to the user`s home folder, work
     * list, favorite Web links, projects, saved searches, and View Markup. The Open Items
     * section lists Teamcenter components currently opened in the active perspective. The
     * History section lists Teamcenter components opened before, but currently closed.
     * The Favorites section contains the Favorites container and Teamcenter components
     * the user added there for quick access. The I Want To section contains commands configured
     * by default or configured by the user.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user logs in to the rich client and retrieves Quick Links, Open Items, History,
     * Favorites and I Want To task pane section for Left Hand Navigation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * RAC Views Viewer - Rich client views and viewer framework components extending from
     * eclipse jface viewer and view extension.
     *
     * @param shortcutInputs
     *        A map of the key representing the  section name in the left hand navigation and the
     *        value representing the preference name that needs to be looked up to get the content.
     *        For example,  Key =QuickLinksSection, Value = MyTeamcenterQuicklinksection;  Key
     *        = FavoritesSection, value= My Favorites . Valid keys in the map are QuickLinksSection,
     *        HistorySection, FavoritesSection, IWantToSection, OpenItemsSection. Valid values
     *        for these keys in the map could be MyFavorites, HistoryList, QuickLinksSection, MyQuicklinkSection,
     *        OpenItemSection, etc.
     *
     * @return
     *         A hierarchical Favorites tree structure list and map of LHNSectionComponent with
     *         corresponding section name.
     *         <br>
     *         A partial error may be encountered in getShortcutsResponse if the preference name
     *         or  preference value is invalid or a problem happens during preference retrieving
     *         from the Preference ITK call or preference value converting to Teamcenter object
     *         from POM_string_to_tag  referenced in the operation
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;1700 (error code): &nbsp;&nbsp;&nbsp;&nbsp;Retrieve preference
     *         error.  The preference cannot be found.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;515024 (error code): The given tag does not exist in the
     *         database or is not a persistent object tag.
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if there is an empty or invalid section name.
     */
    virtual Teamcenter::Services::Core::_2010_04::Session::GetShortcutsResponse getShortcuts ( const LHNShortcutInputs&  shortcutInputs ) = 0;

    /**
     * This operation returns information required to maintain a client cache. The Teamcneter
     * server maintains a set of <b>Datasets</b> with static or near static data that is
     * pertainant to a client application.  This static data can be downloaded through FMS
     * to the cleint host one time, and available for each subsequent client session, thus
     * improving the overall performance of the client application. These Datasets are updated
     * as part of the deploy process from the BMIDE. The cleint cache consits of serveral
     * features, each of these features can be used independnatly of each other. The following
     * features are available:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">ClientMetaModel :The is the client side version of the server`s Meta
     * Model. This includes type descriptions, property descriptions, List Of Values data,
     * and Dataset tool data. The use of the ClientMetaModel cache replaces the need to
     * use the getTypeDescriptions  service calls. By setting the <code>Connection.setOption(OPT_USE_CLIENT_META_MODEL_CACHE,
     * true)</code>, the SOA client framework will use the cache for Client  Meta Model
     * data. The SOA client framework takes care of calling this service opeation and FMS
     * to populate the cache. This feature includes the Dataset:<i>Types, Lov</i>, <i>ToolsData</i>,<i>
     * types_local</i> (one for each locale i.e types_en_US), <i>lov_local</i> (one for
     * each locale i.e lov_en_US).
     * </li>
     * <li type="disc">TextData: This contains the localized string available in the Teamcenter
     * server's Text Server. Using the localized data from this cache replaces the need
     * to call the getDisplayStrings service operation.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param features
     *        Names of features to return<i>, All</i> to return data for all features. Available
     *        features are <i>ClientMetaModel</i> and <i>TextData</i>.
     *
     * @return
     *         Feature descriptions
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Session::ClientCacheInfo getClientCacheData ( const std::vector< std::string >& features ) = 0;

    /**
     * Get the Meta data for the named Business Model object types. This includes type and
     * property descriptions and LOV information.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param typeNames
     *        List of Business Model Object type names.
     *
     * @return   TypeSchema
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeSchema> getTypeDescriptions ( const std::vector< std::string >& typeNames ) = 0;

    /**
     * Authenticates the user's credentials and initialize a Teamcenter session for this
     * client. The operation will throw an <code>InvalidCredentialsException</code> if the
     * <code>username</code>, <code>password</code> or <code>group</code> is not valid.
     * <br>
     * When the client application is deployed to a 4Tier environment (communication through
     * HTTP or TCCS) the login operation also contributes to the assignment of a Teamcenter
     * server instance to the client session. The Teamcenter architecture varies from other
     * client server architectures in that there is a dedicated instance of the Teamcenter
     * server per client application. However, there are use cases where it is desirable
     * for a single user to have multiple desktop applications running and each sharing
     * a single instance of a Teamcenter server. This is controlled through the following
     * elements:
     * <br>
     * <ul>
     * <li type="disc">hostPath&nbsp;&nbsp;&nbsp;&nbsp;From the Connection class constructor,
     * this specifies  the address (URI) the Teamcenter server is hosted on.
     * </li>
     * <li type="disc">username&nbsp;&nbsp;&nbsp;&nbsp;From this login operation, this specifies
     * the user's Teamcenter user name.
     * </li>
     * <li type="disc">sessionDiscriminator&nbsp;&nbsp;&nbsp;&nbsp;From this login operation,
     * this identifies the client session.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The <code>hostPath</code> argument determines the server machine that the client
     * connects to. Once there, the pool manager on that host uses the <code>username</code>
     * and <code>sessionDiscriminator</code> arguments of the login request to determine
     * which Teamcenter server instance to assign the client to. If the pool manager has
     * an existing Teamcenter server instance with the <code>username</code>/<code>sessionDiscriminator</code>
     * key, the client is assigned to that existing instance of the Teamcenter server, and
     * therefore sharing the server with another client; otherwise, a new instance of the
     * Teamcenter server is used. There are a few general scenarios for the <code>sessionDiscriminator</code>
     * argument:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Blank &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on to
     * Teamcenter using two or more client applications using a blank <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/ ), all of those clients are assigned to the same
     * Teamcenter server instance. These client applications can be running on the same
     * or different client hosts.
     * </li>
     * <li type="disc">Constant &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on
     * to Teamcenter using two or more client applications using a constant or fixed <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/<i>MyApp</i> ), those clients are assigned to
     * the same Teamcenter server instance. This is similar to the blank <code>sessionDiscriminator</code>
     * argument; the difference is that only multiple instances of the client application
     * using <i>myApp</i> started by <i>jdoe</i> share the same Teamcenter server instance.
     * </li>
     * <li type="disc">Unique &nbsp;&nbsp;&nbsp;&nbsp;If the user <i>jdoe</i> logs on using
     * a unique random-generated string (for example<i>, jdoe</i>/<i>akdk938lakc</i>), the
     * client application will be assigned to a dedicated instance of the Teamcenter server.
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The scenario you use depends on how your client application is used in the integrated
     * environment. The most common case is the unique <code>sessionDiscriminator</code>
     * value.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param credentials
     *        The user's Teamcenter credentials
     *
     * @return
     *         Basic information about the server and Partial Errors are returned when the authentication
     *         is successful but requested role or locale is not supported:
     *         <br>
     *         <ul>
     *         <li type="disc">214102: &nbsp;&nbsp;&nbsp;&nbsp;The login is accepted, however the
     *         requested role is not valid, and the default role will be used.
     *         </li>
     *         <li type="disc">128003: &nbsp;&nbsp;&nbsp;&nbsp;The logon is accepted. However, data
     *         entry should be done using certain locales, as specified by the <b>TC_language_data_entry</b>
     *         preference. The details of the data entry are returned in the error message.
     *         </li>
     *         <li type="disc">128004:&nbsp;&nbsp;&nbsp;&nbsp;The logon is accepted. However, data
     *         entry should only contain characters that belong to the encoding of the database
     *         instance. The information is in the error message.
     *         </li>
     *         </ul>
     *
     *
     * @exception InvalidCredentialsException
     *           When the credentials supplied are invalid or the requested locale is not allowed.
     *           
     *           <br>
     *           <ul>
     *           <li type="disc">515143:&nbsp;&nbsp;&nbsp;&nbsp; The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>.
     *           </li>
     *           <li type="disc">515144:&nbsp;&nbsp;&nbsp;&nbsp; The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>.
     *           </li>
     *           <li type="disc">515142:&nbsp;&nbsp;&nbsp;&nbsp; The logon was refused due to an invalid
     *           <code>group</code>.
     *           </li>
     *           <li type="disc">128001: The logon was refused due to conflict with the encoding of
     *           the database instance.
     *           </li>
     *           <li type="disc">128002:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to missing
     *           localization.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Core::_2011_06::Session::LoginResponse login ( const Teamcenter::Services::Core::_2011_06::Session::Credentials&  credentials ) = 0;

    /**
     * Authenticates the user using Single-Sign-On (SSO) credentials and initialize a Teamcenter
     * session for this client. The <code>username</code> and <code>password</code> arguments
     * must be obtained from Teamcenter's Security Services. The <code>SsoCredentials</code>
     * class offers a simple API to get these values. The operation will throw an <code>InvalidCredentialsException</code>
     * if the <code>user</code>, <code>password</code> or <code>group</code> is not valid.
     * <br>
     * When the client application is deployed to a 4Tier environment (communication through
     * HTTP or TCCS) the login operation also contributes to the assignment of a Teamcenter
     * server instance to the client session. The Teamcenter architecture varies from other
     * client server architectures in that there is a dedicated instance of the Teamcenter
     * server per client application. However, there are use cases where it is desirable
     * for a single user to have multiple desktop applications running and each sharing
     * a single instance of a Teamcenter server. This is controlled through the following
     * elements:
     * <br>
     * <ul>
     * <li type="disc"><code>hostPath</code>&nbsp;&nbsp;&nbsp;&nbsp;From the Connection
     * class constructor, this specifies  the address (URI) the Teamcenter server is hosted
     * on.
     * </li>
     * <li type="disc"><code>username</code>&nbsp;&nbsp;&nbsp;&nbsp;From this login operation,
     * this specifies the user's Teamcenter user name.
     * </li>
     * <li type="disc"><code>sessionDiscriminator</code>&nbsp;&nbsp;&nbsp;&nbsp;From this
     * login operation, this identifies the client session.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The <code>hostPath</code> argument determines the server machine that the client
     * connects to. Once there, the pool manager on that host uses the <code>username</code>
     * and <code>sessionDiscriminator</code> arguments of the logon request to determine
     * which Teamcenter server instance to assign the client to. If the pool manager has
     * an existing Teamcenter server instance with the <code>username</code>/<code>sessionDiscriminator</code>
     * key, the client is assigned to that existing instance of the Teamcenter server, and
     * therefore sharing the server with another client; otherwise, a new instance of the
     * Teamcenter server is used. There are a few general scenarios for the sessionDiscriminator
     * argument:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Blank &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on to Teamcenter
     * using two or more client applications using a blank <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe</i>/ ), all of those clients are assigned to the same
     * Teamcenter server instance. These client applications can be running on the same
     * or different client hosts.
     * </li>
     * <li type="disc">Constant &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on to Teamcenter
     * using two or more client applications using a constant or fixed <code>sessionDiscriminator</code>
     * argument (for example, <i>jdoe/MyApp</i> ), those clients are assigned to the same
     * Teamcenter server instance. This is similar to the blank <code>sessionDiscriminator</code>
     * argument; the difference is that only multiple instances of the client application
     * using myApp started by jdoe share the same Teamcenter server instance.
     * </li>
     * <li type="disc">Unique &nbsp;&nbsp;&nbsp;&nbsp;If the user jdoe logs on using a unique
     * random-generated string (for example, <i>jdoe</i>/<i>akdk938lakc</i>), the client
     * application will be assigned to a dedicated instance of the Teamcenter server.
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The scenario you use depends on how your client application is used in the integrated
     * environment. The most common case is the unique <code>sessionDiscriminator</code>
     * value.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param credentials
     *        The user's Teamcenter credentials.
     *
     * @return
     *         Basic information about the server and Partial Errors are returned when the authentication
     *         is successful but requested role or locale is not supported:
     *         <br>
     *         <ul>
     *         <li type="disc">214102: The login is accepted, however the requested <code>role</code>
     *         is not valid, and the default role will be used.
     *         </li>
     *         <li type="disc">128003: The logon is accepted. However, data entry should be done
     *         using certain locales, as specified by the <b>TC_language_data_entry</b> preference.
     *         The details of the data entry are returned in the error message.
     *         </li>
     *         <li type="disc">128004:&nbsp;&nbsp;&nbsp;&nbsp;The logon is accepted. However, data
     *         entry should only contain characters that belong to the encoding of the database
     *         instance. The information is in the error message.
     *         </li>
     *         </ul>
     *
     *
     * @exception InvalidCredentialsException
     *           When the credentials supplied are invalid or the requested locale is not allowed.
     *           
     *           <br>
     *           <ul>
     *           <li type="disc">515143:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515144:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to invalid
     *           <code>username</code> or <code>password</code>
     *           </li>
     *           <li type="disc">515142:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to an invalid
     *           <code>group</code>.
     *           </li>
     *           <li type="disc">128001: &nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to conflict
     *           with the encoding of the database instance.
     *           </li>
     *           <li type="disc">128002:&nbsp;&nbsp;&nbsp;&nbsp;The logon was refused due to missing
     *           localization.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Core::_2011_06::Session::LoginResponse loginSSO ( const Teamcenter::Services::Core::_2011_06::Session::Credentials&  credentials ) = 0;

    /**
     * Update the named policy, adding and removing the named properties. This operation
     * only applies to object property policies that have been defined on the client side.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setObjectPropertyPolicy
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param policyID
     *        The ID of the policy to update. This is the ID that is returned from the <code>setObjectPropetyPolicy</code>
     *        operation.
     *
     * @param addProperties
     *        List of properties to add to the named policy.  If the property already exists in
     *        the policy, the flags (i.e. <code>excludeUiValues</code>) from the input will take
     *        precedence over the flags on the existing property.
     *
     * @param removeProperties
     *        List of properties to remove from the named policy. If a source <code>PolicyType</code>
     *        defines a type without properties, the whole type is removed.
     *
     * @return
     *         The policy ID, will be the same as the input ID.
     *
     *
     * @exception ServiceException
     *           If the named policy does not exist in the server's memory (error code 214106).
     */
    virtual std::string updateObjectPropertyPolicy ( const std::string&  policyID,
        const std::vector< Teamcenter::Soa::Common::PolicyType >& addProperties,
        const std::vector< Teamcenter::Soa::Common::PolicyType >& removeProperties ) = 0;

    /**
     * Register desired level for server state as used by the Server Manager to control
     * server timeout. Note that an attempt to register at LEVEL_STATELESS is ignored since
     * this is the default level when no registrations are in effect. To move from a higher
     * level to the stateless level the <code>unregister</code> operation should be used
     * to delete the earlier registration. Note that it is possible to be registered at
     * more than one level and there may be multiple registrations at each level.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * unregisterState
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param level
     *        Desired server state: "<i>Edit</i>" or "<i>Read</i>"
     *
     * @return
     *         If registration succeeds a registry index (greater than 0) is returned, and can be
     *         supplied to <code>unregister</code> operation to undo this registration.  If no registration
     *         occurs, zero is returned.
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Session::RegisterIndex registerState ( const std::string&  level ) = 0;

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
     * The object property policy is set to the policy named in the file <code>$TC_DATA/soa/policies/<policyName>.xml</code>
     * The reserved policy name "<i>Empty</i>", will enforce a policy that only returns
     * minimum data required for each object (UID and type name).The object property policy
     * will stay in affect for this session until changed by another call to <code>setObjectPRopertyPolicy</code>.
     * The full policy is returned where the client application can modify it throughout
     * the session via calls to <code>updatObjectPropertyPolicy</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * updateObjectPropertyPolicy
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
     *        The name of the policy file without the .xml extension. The file must exist on the
     *        Teamcenter server volume at <code>$TC_DATA\soa\policies\<policyName>.xml</code>.
     *
     * @param useRefCounting
     *        When set to true, the policy will not remove a property value until there is a matching
     *        number of removes and adds in subsequent calls to <code>updateObjectPropertyPolicy</code>
     *
     * @return
     *         The policy ID and full definition of the object property policy. This ID is used
     *         on subsequent calls to <code>updateObjectPropertyPolicy</code>.
     *
     *
     * @exception ServiceException
     *           If the named policy does not exist or there are errors parsing the XML file (error
     *           code 214104).
     */
    virtual Teamcenter::Services::Core::_2012_02::Session::SetPolicyResponse setObjectPropertyPolicy ( const std::string&  policyName,
        bool useRefCounting ) = 0;

    /**
     * Remove the specified registration.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * registerState
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param index
     *        Index returned by previous call to <code>registerState</code>.
     *
     * @return
     *         True
     *
     */
    virtual bool unregisterState ( int index ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SessionService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

