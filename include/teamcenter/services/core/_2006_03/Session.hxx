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

#ifndef TEAMCENTER_SERVICES_CORE__2006_03_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2006_03_SESSION_HXX

#include <teamcenter/soa/client/model/GroupMember.hxx>
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
            namespace _2006_03
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct GetAvailableServicesResponse;
    struct GetGroupMembershipResponse;
    struct GetSessionGroupMemberResponse;
    struct LoginResponse;
    struct PreferencesResponse;
    struct PrefSetting;

    /**
     * List of available services and operations.
     */
    struct GetAvailableServicesResponse
    {
        /**
         * List of available services
         */
        std::vector< std::string > serviceNames;
    };

    /**
     * Info from <code>getGroupMembership</code> operation.
     */
    struct GetGroupMembershipResponse
    {
        /**
         * A list of all the valid <b>GroupMember</b> objects for the current session`s <b>User</b>.
         * A <b>GroupMember</b> holds identifiers for a <b>User</b>, <b>Group</b>, and <b>Role</b>
         * and represents that the user belongs to a group with the particular role.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GroupMember>  > groupMembers;
        /**
         * The plain list has all the <b>GroupMembers</b>, <b>Groups</b> and <b>Roles</b> for
         * this <b>User</b>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Information returned from the <code>getSessionGroupMember</code> service operation.
     */
    struct GetSessionGroupMemberResponse
    {
        /**
         * The <b>GroupMember</b> object which represents the logged in user's, <b>Group</b>,
         * and Role for the current session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GroupMember>  groupMember;
        /**
         * The <b>GroupMember</b> object is included in the plain list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The  <b>User</b> and <b>GroupMember</b> objects for the user of this session. Partial
     * errors are returned in the <code>ServiceData</code> when the authentication is successful
     * but requested role is not supported.
     */
    struct LoginResponse
    {
        /**
         * The <b>User</b> of this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * The <b>GroupMember</b> of this session.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::GroupMember>  groupMember;
        /**
         * The <b>GroupMember</b> and <b>User</b> are added to the plain object list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Info from get/setPreferences
     */
    struct PreferencesResponse
    {
        /**
         * The requested preference name/values.
         */
        Teamcenter::Soa::Client::Preferences preferences;
        /**
         * Any partial errors that may occur when filling this request.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Info for setting preferences
     */
    struct PrefSetting
    {
        /**
         * The scope in which the preferences are to be set, "all", "site", "user", "group",
         * or "role".
         */
        std::string prefScope;
        /**
         * The name of the preference.
         */
        std::string prefName;
        /**
         * The array of values for this perference.
         */
        std::vector< std::string > prefValues;
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


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

