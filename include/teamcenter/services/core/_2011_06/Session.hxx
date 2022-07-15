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

#ifndef TEAMCENTER_SERVICES_CORE__2011_06_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2011_06_SESSION_HXX

#include <teamcenter/schemas/soa/_2011_06/metamodel/TypeSchema.hxx>
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
            namespace _2011_06
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct ClientCacheInfo;
    struct Credentials;
    struct Feature;
    struct LoginResponse;

    /**
     * A map of FMS file tickes, the key is the name of the file, and the value is the FMS
     * ticket.
     */
    typedef std::map< std::string, std::string > CacheTickets;

    /**
     * Name/Value pairs of data related to the server. The following keys are valid:  Version,
     * HostName, LogFile, Locale, TcServerID.
     */
    typedef std::map< std::string, std::string > ServerInfo;

    /**
     * Data for the requested cached features.
     */
    struct ClientCacheInfo
    {
        /**
         * The list of  features.
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Session::Feature > features;
        /**
         * Errors are return for features that do not exist or if there are other errors in
         * getting data for a given service. The client ID in the partial error will be that
         * of the feature name.
         */
        Teamcenter::Soa::Client::PartialErrors partialErrors;
    };

    /**
     * The credentials needed to authenticate a user.
     */
    struct Credentials
    {
        /**
         * The user's Teamcenter user name.
         */
        std::string user;
        /**
         * The user's Teamcenter password or SSO token.
         */
        std::string password;
        /**
         * The group ID for this session. If blank (""), the user's default group is assumed.
         */
        std::string group;
        /**
         * The role the user is performing in the group. If blank (""), the user's default role
         * in the group is assumed.
         */
        std::string role;
        /**
         * The locale to be used by the Teamcenter server process for this session. If blank
         * (""), the server's default locale will be used.
         */
        std::string locale;
        /**
         * Client defined identifier for this session. This argument is ignored when the client
         * application is deployed in a 2Tier environment (IIOP communication).
         */
        std::string descrimator;
    };

    /**
     * Information for a single client cache feature.
     */
    struct Feature
    {
        /**
         * Name of the feature,  <i>ClientMetaModel</i> or <i>TextData</i>.
         */
        std::string name;
        /**
         * A map of <b>Dataset</b> names and FMS tickets (string/string) for each <b>Dataset</b>
         * that makes up the client cache feature.
         */
        CacheTickets cacheTickets;
    };

    /**
     * Basic information about the server and  partial errors are returned when the authentication
     * is successful but requested <code>role</code> or <code>locale</code> is not supported.
     */
    struct LoginResponse
    {
        /**
         * Name/Value pairs (string/string) of data related to the server. The following keys
         * are valid:
         * <br>
         * <ul>
         * <li type="disc"><i>Version</i>         The version of the Teamcenter server.
         * </li>
         * <li type="disc"><i>HostName</i>     The name of the Teamcenter server's host machine.
         * </li>
         * <li type="disc"><i>LogFile</i>         The full path of the Teamcenter server's log
         * file.
         * </li>
         * <li type="disc"><i>Locale</i>          The locale of this session.
         * </li>
         * <li type="disc"><i>TcServerID</i>    The unique ID of this instance of the Teamcenter
         * server.
         * </li>
         * </ul>
         */
        ServerInfo serverInfo;
        /**
         * Partial errors or warnings resulting from the login attempt.
         */
        Teamcenter::Soa::Client::PartialErrors partialErrors;
    };




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


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

