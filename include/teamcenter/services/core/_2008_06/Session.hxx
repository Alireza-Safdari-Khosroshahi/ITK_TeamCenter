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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_SESSION_HXX

#include <teamcenter/services/core/_2006_03/Session.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>


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
            namespace _2008_06
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct GetDisplayStringsOutput;
    struct GetDisplayStringsResponse;

    /**
     * The name/value pair of a Text Server key and its corresponding localized value.
     */
    struct GetDisplayStringsOutput
    {
        /**
         * The textserver key.
         */
        std::string key;
        /**
         * The localized value for the Text Server key.
         */
        std::string value;
    };

    /**
     * The response for  the <code>getDisplayStrings</code> operation.
     */
    struct GetDisplayStringsResponse
    {
        /**
         * A list Text Server key/localized value pairs.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Session::GetDisplayStringsOutput > output;
        /**
         * Partial errors with the key name attached to the partial error.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

