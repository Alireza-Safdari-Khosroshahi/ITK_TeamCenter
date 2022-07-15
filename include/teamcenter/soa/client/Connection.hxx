// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_CONNECTION_HXX
#define TEAMCENTER_SOA_CLIENT_CONNECTION_HXX

//
// This check is for ABI in the SOA header files to ensure SOA client applications can be built without an ABI break.
// SOA dependent modules must use this compile flag to prevent run time crash in SOA applications on VC9.
// This is a VC9 requirement for passing stl objects between binaries. Without this flag the stl objects
// will get corrputed while being passed between binaries and will cause the crash.
// SOA uses this compile flag, so the dependent binaries must also use this flag.
//
#ifndef SKIP_SOA_SECURE_SCL_CHECK
# ifdef _WIN32
#  ifdef _SECURE_SCL
#   if _SECURE_SCL != 0
#    error _SECURE_SCL must be defined as 0 for STL ABI
#   endif
#  else
#   define _SECURE_SCL 0
#  endif
# endif
#endif

#include <string>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ExceptionHandler.hxx>
#include <teamcenter/soa/client/CredentialManager.hxx>
#include <teamcenter/soa/client/ModelManager.hxx>
#include <teamcenter/soa/client/ClientMetaModel.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/RequestListener.hxx>
#include <teamcenter/soa/client/EventSharer.hxx>
#include <teamcenter/soa/client/ObjectPropertyPolicyManager.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>
#include <teamcenter/soa/common/Version.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Net
    {
        namespace TcServerProxy
        {
            namespace Client
            {
                class CredentialProvider;
                class TSPSession;

            }
            namespace Admin
            {
                class Environment;
                class EnvironmentInfo;
            }
        }
    }
}

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            class SessionManager;
            class ModelManagerImpl;
            class NotifyRequestListeners;


class TCSOACLIENTMNGD_API Connection
{
public:

    enum Option
    {
        OPT_USE_COMPRESSION,
        OPT_SERVER_TIMEOUT,
        OPT_SERVER_REASSIGNMENT,
        HTTP_PROXY_HOST,
        HTTP_PROXY_USERID,
        HTTP_PROXY_PASSWD,
        OPT_CRYPTO_SYSTEMTYPE,
        OPT_IIOP_SERVER_IOR,        // Deprecated use OPT_IIOP_PDI_SERVER_IOR
        OPT_RESERVED_CURL,
        OPT_IIOP_PDI_SERVER_IOR,
        OPT_IIOP_TC_SERVER_IOR,
        OPT_SSL_CA_FILE,
        OPT_WEBSEAL_FORM_URL,
        OPT_SSO_LOGIN_URL,
        OPT_SHARED_EVENTS,
        OPT_SHARED_DISCRIMINATOR,
        TCCS_ENV_NAME,
        TCCS_USE_CALLBACK,
        TCCS_HOST_URL,
        TCCS_SESSION_ID,
        OPT_SSL_CLIENT_CERT_FILE,
        OPT_SSL_CLIENT_KEY_FILE,
        OPT_SSL_CLIENT_KEY_PASSWORD,
        OPT_USE_CLIENT_META_MODEL_CACHE,
        OPT_CLIENT_ENCODING
    };

    enum Protocol
    {
        HTTP,
        TCCS,
        IIOP
    };

    enum Binding
    {
        REST,
        SOAP
    };

    enum LoggingLevel
    {
        LEVEL_OFF,
        LEVEL_ERROR,
        LEVEL_WARN,
        LEVEL_INFO,
        LEVEL_DEBUG
    };

    /**
     * Add a RequestListener to the service call stack.
     * Each listener that is added, will recieve a callback for each service
     * request send and received. The callback will have information about the
     * service request, name of the service and operation, the XML document .etc.
     *
     * @param listener  Instance of the RequestListener interface.
     *
     */
    static void addRequestListener( Teamcenter::Soa::Client::RequestListener* listener );

    /**
     * Remove the RequestListener from the service call stack/
     *
     * @param listener Instance of t he RequestListner to remove.
     *
     */
    static void removeRequestListener( Teamcenter::Soa::Client::RequestListener* listener );

    /**
     * Set the logging level of the SOA Framework.
     * By default the framework will log at ERROR level to the file
     * $TEMP/soaclient_&lt;id&gt;.log. The default logging behavior can be modified pragmatically
     * with this method, or through environment variables:
     *<UL>
     * <li> TC_SOACLIENT_LOGGING          ERROR | WARN | INFO | DEBUG
     * <li> TC_SOACLIENT_LOGGING_FOLDER   Full path to where the log file should be written
     *</UL>
     * Setting and/or changing the logging pragmatically will take precedence over the above
     * environment variables.
     *
     * @param logFile   Pointer to a file to write all messages to. If NULL the
     *                  default file of $TEMP/soaclient_&lt;id&gt;.log will be used.
     * @param level     Level at which to log messages
     */
    static void setLoggingLevel( FILE* logFile, LoggingLevel level);


    /**
     * Create an instance of the Connection.
     * When a session with the server is lost (i.e. timeout), the SOA client framework will use the CredentialManager
     * to (re)authenticate the user.
     *
     * @param hostPath      Path of the server hosting the services. Use the following formats
     *                      for the different transport protocols:
     *                      <ul>
     *                      <li> Http(s):   http://host:port/application; i.e. http://abc.com:80/tc
     *                      When specifying an HTTPS host address, the Connection.setOption( Connection::OPT_SSL_CA_FILE) must
     *                      be used to configure the client for SSL decryption.
     *                      <li> IIOP:      iiop:&lt;host&gt;:&lt;port&gt;/&lt;server-id&gt; i.e. iiop:abc.com:9000/TcServer1
     *                      <li> IIOP:      The Tc Server IOR string as returned from Connection.getOption( OPT_IIOP_TC_SERVER_IOR )
     *                      <li> TCCS:      In this case hostPath is ignored and TCCS environment name provided by
     *                      <li>            using Connection->setOption ( TCCS_ENV_NAME, envName )
     *                      </ul>
     * @param credentials   Credentail manager the SOA Framework will use to (re)authenticate with the Web Tier
     *                      The instance of the CredentialManager will dictate what style of authentication
     *                      will be used, SSO or standard (user/password).
     * @param protocol       Transport protocol to use when connecting to the server, HTTP or IIOP
     * @param bind           Binding style of the service request, only REST is supported at this time.
     * @param useCompression Employ comression of the response payload accross Http.
     */
    Connection( const std::string& hostPath,
                Teamcenter::Soa::Client::CredentialManager* credentials,
                Protocol protocol = IIOP,
                Binding bind = REST,
                bool useCompression = true );

    /**
     * Create an instance of the Connection using a file with serialized conneciton objects.
     *
     * @param credentialManager   Credentail manager the SOA Framework will use to (re)authenticate with the Web Tier
     *                            The instance of the CredentialManager will dictate what style of authentication
     *                            will be used, SSO or standard (user/password).
     * @param fileName input file containing serialized connection objects.
     */
    Connection( Teamcenter::Soa::Client::CredentialManager* credentialManager, const std::string& fileName);

    ~Connection();

    /**
     * @return Returns the hostPath.
     */
    const std::string& getHostPath() const;

    /**
     * @return Returns the sessionManager.
     */
    CredentialManager* getCredentialManager();

    /**
     * @return Returns the protocol.
     */
    Protocol getProtocol() const;

    /**
     * @return Returns the binding.
     */
    Binding getBinding() const;



    /**
     * Set the handler for processing Exceptions.
     *
     * All service requests may throw an InternalServerException. This is typically
     * due to communication errors, marshaling errors, or configuration errors, that
     * may occur anywhere between the client stub and the server skeleton.  The SOA
     * Framework will invoke the handler when an InternalServerException is returned
     * from a service request.<br>
     *
     *
     * By default the DefaultExceptionHandler is used. This handler
     * simply prints an error message to the console and exits from the application.
     * It is strongly recommended that applications implement their own ExceptionHandler
     *
     * @param handler   Exception Handler for InternalServerException and related
     */
    void setExceptionHandler( Teamcenter::Soa::Client::ExceptionHandler* handler );

    /**
     * Returns the current InternalServerException handler used by this Connection.
     *
     * @return  The ExceptionHandler
     */
    ExceptionHandler* getExceptionHandler(  );


     /**
     * @return Returns the ModelManager.
     */
    Teamcenter::Soa::Client::ModelManager* getModelManager();

    /**
     * Gets map<key, value> with client's session state data.
     * Keys for the Map: logCorrelationID, timezone, baseSchemaVersion,
     *                   timezone-dst, allowPaging, clientVersion, groupMember.
     * All keys may not always be used.
     * @return Map with client session state, key-value pairs of strings.
     */
    std::map<std::string, std::string> getClientSessionState();

    /**
     * Set the Proxy Credential Provider
     * This method sets the ProxyCredentialProvider
     *
     * @param provider  The Proxy Credential Provider
     */
    void setProxyCredentialProvider( Teamcenter::Net::TcServerProxy::Client::CredentialProvider *provider);

    /**
     * Retrieve the Proxy Credential Provider
     * this method returns the Proxy Credential Provider set by client
     *
     * @return The Proxy Credential Provider
     */
    const Teamcenter::Net::TcServerProxy::Client::CredentialProvider* getProxyCredentialProvider() const ;

    /**
     * Retrieves the instance of TSP Session
     *
     * @return The TSP Session .
     */
    Teamcenter::Net::TcServerProxy::Client::TSPSession* getTSPSession() ;

    /**
     * Returns the Current Object Property Policy.
     * This is Policy last set by the SessionService.setObjectPropertyPolicy() service.
     *
     * @return The name of the Object Property Policy.
     * @deprecated As of 10.0, use the ObjectPropertyPolicyManager.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use the ObjectPropertyPolicyManager."))
#endif
    std::string getCurrentObjectPropertyPolicy()const;

    /**
     * Returns the Previous Object Property Policy.
     * This is Policy in place before the last call to the SessionService.setObjectPropertyPolicy() service.
     *
     * @return The name of the Object Property Policy.
     * @deprecated As of 10.0, use the ObjectPropertyPolicyManager.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use the ObjectPropertyPolicyManager."))
#endif
    std::string getPreviousObjectPropertyPolicy() const;

    /**
     * Sets the Object Property Policy.
     * If the named policy has previously been set through a SessionService::setObjectPropertyPolicy,
     * this call will simply ensure that this policy be used on subsequent service requests.
     * If the named policy has not been set before, then this call to SessionService::setObjectPropertyPolicy
     * which will ensure that the named policy is valid.
     *
     * @param policyName    Name of the policy.
     *
     * @throws ServiceExcpetion if the named policy has not been used before and is not valid.
     * @deprecated As of 10.0, use the ObjectPropertyPolicyManager.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use the ObjectPropertyPolicyManager."))
#endif
    void setObjectPropertyPolicy( const std::string& policyName );


    /**
     * Sets the Object Property Policy for service reqeust made on this thread.<br>
     *
     * The policy set by this method will override a policy set through setObjectPropertyPolicy  or
     * SessionService.setObjectPropertyPolicy which apply the policy to any request made in this session.
     * Use the clearObjectPropertyPolicyPerThread method to remove a thread based policy and revert
     * to the session based policy.
     *
     *
     * If the named policy has previously been set through a SessionService.setObjectPropertyPolicy,
     * this call will simply ensure that this policy be used on subsequent service requests.
     * If the named policy has not been set before, then this call to SessionService.setObjectPropertyPolicy
     * which will ensure that the named policy is valid.
     *
     * @param policyName    Name of the policy.
     *
     * @throws ServiceException if the named policy has not been used before and is not valid.
     * @deprecated As of 10.0, use the ObjectPropertyPolicyManager.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use the ObjectPropertyPolicyManager."))
#endif
    void setObjectPropertyPolicyPerThread( const std::string& policyName );


    /**
     * Clears the Object Property Policy set for this thread.<br>
     *
     * Once this method is called the policy applied to service requests on this thread will revert to the
     * policy defined by for the session.

     *
     *
     * If the named policy has previously been set through a SessionService.setObjectPropertyPolicy,
     * this call will simply ensure that this policy be used on subsequent service requests.
     * If the named policy has not been set before, then this call to SessionService.setObjectPropertyPolicy
     * which will ensure that the named policy is valid.
     *
     * @deprecated As of 10.0, use the ObjectPropertyPolicyManager.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use the ObjectPropertyPolicyManager."))
#endif
    void clearObjectPropertyPolicyPerThread( );



    /**
     * Gets the version of the client libraries
     * @return the client version
     */
    Teamcenter::Soa::Common::Version getClientVersion() const;


    /**
     * Gets the version of the server.
     * This method only returns meaningfull data after an session has been established
     * with the server (SessionService.login reqeust has been sent).
     * If the client has not logged into the server yet, a value of 0.0.0.0 will be returned.
     * All versions of the TcEngineering 2005.1 server will be reported as 2005.1.0 as this
     * server does not return version information.
     *
     * @return the server version
     */
    Teamcenter::Soa::Common::Version getServerVersion() const;


    /**
     * Get the locale of the session, as set by the SessionService.login service operation
     * @return  The locale
     */
    std::string getLocale() const;


    /**
     * Get the default site locale.
     * @return  The default site locale
     */
    std::string getSiteLocale() const;


    /**
     * Set the value of a connection option.
     *<table border="2" cellpadding="2" cellspacing="0">
     * <tr>
     *   <td valign="top"><b>Option</b></td>
     *   <td valign="top"><b>Description</b></td>
     *   <td align="center" valign="top"><b>Default Value</b></td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_USE_COMPRESSION</td>
     *   <td valign="top">Use GZip compression on the service response.</td>
     *   <td align="center" valign="top">true</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SERVER_TIMEOUT</td>
     *   <td valign="top">The maximum time in seconds
     *   that you allow the transfer operation to take. A timeout value of zero is
     *   interpreted as an infinite timeout</td>
     *   <td align="center" valign="top">0</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SERVER_REASSIGNMENT</td>
     *   <td valign="top">Option to enable server reassignment notification
     *   Error code = 214016.  Notification is through an InternalServerException.
     *   This feature only work for 4-Tier. Upon notification, the client will reestablish
     *   dynamic object property policy if property policy is currently enforced.</td>
     *   <td align="center" valign="top">false</td>
     * </tr>
     * <tr>
     *   <td valign="top">HTTP_PROXY_HOST</td>
     *   <td valign="top">Host name and port for the proxy server "host:port".</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">HTTP_PROXY_USERID</td>
     *   <td valign="top">User ID for proxy server.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">HTTP_PROXY_PASSWD</td>
     *   <td valign="top">User password for proxy server.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_CRYPTO_SYSTEMTYPE</td>
     *   <td valign="top">The encryption type in a HTTPS/SSL connection. May be
     *   "FIPS" or "Domestic".</td>
     *   <td align="center" valign="top">Domestic</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SSL_CA_FILE</td>
     *   <td valign="top">The path for the SSL CA file. This option is only valid
     *   when connecting with an HTTPS server. For any HTTPS communication to
     *   succeed, this option must be set, and the referenced file must
     *   contain an entry for the certificate on the target server.
     *   The CA file contains certificates in PEM format. The file can contain
     *   one or more CA certificates identified by
     * <pre>
     *  -----BEGIN CERTIFICATE-----
     *  ... (CA certificate in base64 encoding) ...
     *  -----END CERTIFICATE-----
     * </pre>
     *   Before, between, and after the certificates text is allowed which can be used
     *   for descriptions of the certificates.
     *   Note: A system environment variable "TEAMCENTER_SSL_CERT_FILE" can be used
     *         instead of OPT_SSL_CA_FILE option.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>

     * <tr>
     *   <td valign="top">OPT_SSL_CLIENT_CERT_FILE</td>
     *   <td valign="top">Path to a Client Certificate file.
     *   This is required only for 2-Way SSL (Mutual Authentication), the file must
     *   must be in PEM format. The client must be configured for standard SSL (OPT_SSL_CA_FILE),
     *   and also be configured with a private key (OPT_SSL_CLIENT_KEY_FILE) </td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SSL_CLIENT_KEY_FILE</td>
     *   <td valign="top">Path to a Client Private Key file.
     *   This is required only for 2-Way SSL (Mutual Authentication), the file must
     *   must be in PEM format. The client must be configured for standard SSL (OPT_SSL_CA_FILE),
     *   and also be configured with a client certificate (OPT_SSL_CLIENT_CERT_FILE). The
     *   password for the private key is configured with the OPT_SSL_CLIENT_KEY_PASSWORD option</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SSL_CLIENT_KEY_PASSWORD</td>
     *   <td valign="top">Password for the Client Key (OPT_SSL_CLIENT_KEY_FILE)</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_WEBSEAL_FORM_URL</td>
     *   <td valign="top">Webseal URL.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SSO_LOGIN_URL</td>
     *   <td valign="top">The SOA client framework will automatically authenticate
     *                    against a WebSEAL server if the client applications uses the
     *                    SsoCredentials class. For applications that use their own
     *                    CredentialManager for SSO, this option must be set when deployed
     *                    in a WebSEAL environment </td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SHARED_EVENTS</td>
     *   <td valign="top">All client applications that set this option to true, and are
     *   running on the same client host will share a single instance of the %Teamcenter
     *   server. </td>
     *   <td align="center" valign="top">"false"</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_SHARED_DISCRIMINATOR</td>
     *   <td valign="top"> This option will override the session discriminator argument on the
     *   SessionService.login request</td>
     *   <td align="center" valign="top">"false"</td>
     * </tr>
     * <tr>
     *   <td valign="top">TCCS_USE_CALLBACK</td>
     *   <td valign="top">Specify whether calllback to client
     *   is needed when Forward Proxy challenge comes up</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">TCCS_ENV_NAME</td>
     *   <td valign="top">Specify which TCCS environment name to use.
     *   This is one of the envrionments available in TCCS configuration.
     *   TCCS will use the data such as server and sso url associated with this environment.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">TCCS_HOST_URL</td>
     *   <td valign="top">Arbitrary URL specified by client application.
     *   Client application intending for TCCS to use this server URL must specify this option.
     *   TCCS will use this URL instead of the one specified in TCCS configuration.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">TCCS_SESSION_ID</td>
     *   <td valign="top">Arbitrary Sesion Id specified by client application. Client
     *   application intending to do self session management can choose to use this option to specify
     *   the session Id. TCCS will use this session Id to communicate.</td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_USE_CLIENT_META_MODEL_CACHE</td>
     *   <td valign="top">By default the Meta Model data (Teamcenter::Soa::Client::Type) is
     *   downloaded from the server as need. By setting this option to true, the Meta Model infomation
     *   is pulled from cached files in FMS. This feature requires a %Teamcenter 9.0 or newer server. If
     *   connecting to an older server this option is ignored. The cached files are compressed and require
     *   the unzip executable be in the system PATH.</td>
     *   <td align="center" valign="top">"false"</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_CLIENT_ENCODING</td>
     *   <td valign="top">Specifies the encoding in which the client will send and recieve string data.
     *   If this option is blank (""), the data is assumed to be in Code Page of the client host machine.
     *   The encoding value is case-insensitive and ignores the delimiters '-', '_', and ' ' (dash,
     *   underscore, and space). "UTF8", "utf-8", "Utf8" and "Utf_8" are all equivalent  </td>
     *   <td align="center" valign="top">""</td>
     * </tr>
     *</table>
     *

     * @param optionName    Name of the option
     * @param value         Value of the option
     */
    void setOption( Option optionName, const std::string& value);

    /**
     * Get the value of a connection option.
     * All valid options from setOptions, plus the following are valid input arguments
     *
     *<table border="2" cellpadding="2" cellspacing="0">
     * <tr>
     *   <td valign="top"><b>Option</b></td>
     *   <td valign="top"><b>Description</b></td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_IIOP_PDI_SERVER_IOR</td>
     *   <td valign="top">Value of the PDI Server IOR.
     *                    This option is only valid if with an IIOP connection.</td>
     * </tr>
     * <tr>
     *   <td valign="top">OPT_IIOP_TC_SERVER_IOR</td>
     *   <td valign="top">Value of the Tc Server IOR.
     *                    This IOR may be used as the 'hostPath' in the Connection constructor.
     *                    This option is only valid if with an IIOP connection.</td>
     * </tr>
     *</table>
     *
     * @param optionName    Name of the option
     * @return The value of the option.
     */
    std::string getOption( Option optionName);

     /**
     * Serialize and output connection object values to a named file.
     *
     * @param filePath    Full path of the output file
     */
    void serialize( const std::string& filePath );

    /**
     * Returns the Object Property Policy Manager.
     * @return The Object Property Policy Manager.
     */
    Teamcenter::Soa::Client::ObjectPropertyPolicyManager* getObjectPropertyPolicyManager() const;

    /**
     * get the objectPropertyPolicy instance associated with the given name.
     *
     * @param name    Name of the policy to be retrived.
     * @return The acutal instance of ObjectPropertyPolicy.
     * @deprecated As of 10.0, use the ObjectPropertyPolicyManager.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use the ObjectPropertyPolicyManager."))
#endif
     Teamcenter::Soa::Common::ObjectPropertyPolicy* getObjectPropertyPolicy(const std::string name);

    /**
     * Returns vector containg list of all environments defined in TCCS configuration.
     * @return vector containing list of TCCS Environments.
     * @throws TSPException
     */
    static const std::vector < const Teamcenter::Net::TcServerProxy::Admin::Environment *> &getEnvironments();

    /**
     * Gets list of  TCCS environment matching the version expression.
     * @param expression - corresponds to version defined in TCCS environment. Mutliple versions can be specified
     * in the expression using OR separator for example '8.3|9.0'. Wild card '*' can be specified at the end of
     * input string.
     * @return Vector containing list of TCCS Environments matching the input expression.
     * @throws TSPException
     */
    static const std::vector < const Teamcenter::Net::TcServerProxy::Admin::Environment* > &getEnvsForVersion(const std::string& expression);

    /**
     * Get TCCS environment based on environment Name
     * @return const Environment* - TCCS environment object corresponding to environment Name
     * @throws TSPException
     */
    static const Teamcenter::Net::TcServerProxy::Admin::Environment* getEnvironment(const std::string& envName);

    /**
     * Gets list of  TCCS environment matching the input URL.
     * @param inURL  Corresponds to server URL defined in TCCS environment.
     * @return Vector containing list of TCCS Environments matching the input URL.
     * @throws TSPException
     */
    static const std::vector < const Teamcenter::Net::TcServerProxy::Admin::Environment* > &getEnvironmentsForURL(const std::string& inURL);



    /**
     * @return Returns the eventSharer.
     */
     Teamcenter::Soa::Client::EventSharer* getEventSharer();

    /**
     * Get a unique address for the server.  For 4-tier, this is simply the host path.
     * For 2-tier, it's the IOR since "per-client" ImR could start multiple local servers.
     * @return address to identify the server
     */
     std::string getServerAddress();

    /**
     * Get the late loaded library object for TcServerCppBinding (TCCS C++ binding library)
     * Used when client is using TCCS to communicate with server
     * @return object of the late loaded library
     */
    static void* getTSP();

    /**
     * Close the late loaded library and delete all the associated objects
     */
    static void closeTSP();

    /**
     *
     * @return the ClientDataModel
     */
    ClientDataModel* getClientDataModel();


    /**
     *
     * @return the ClientMetaModel
     */
    ClientMetaModel* getClientMetaModel();


protected:
    Connection():  m_sessionManager(0), m_modelManager(0), m_eventSharer(0) {}
    friend class SessionManager;
    friend class ModelManagerImpl;
    SessionManager* getSessionManager();

    SessionManager*   m_sessionManager;
    ModelManagerImpl* m_modelManager;
    EventSharer* m_eventSharer;

    friend class NotifyRequestListeners;

private:

    // Don't allow default and copy constructors
    Connection( const Connection& right);
    Connection& operator = ( const Connection& right);

    static void* lateLoad;
    static void* lateLoadObj;
    const std::string outSessionState() const;
    const std::string serializeOption(const Option connOpt, const std::string& optionName);
    void setSessionState( SessionManager* sessionManager, std::map<std::string,std::string>& attr ) const;
    const std::string md5Hash( std::string s ) const;
    static std::set< Teamcenter::Soa::Client::RequestListener*>   requestListners;

};
}}}//end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

