// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.




#ifndef TEAMCENTER_SOA_CLIENT_SESSIONMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_SESSIONMANAGER_HXX

#include <string>
#include <set>
#include <new>

#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>

#include <teamcenter/soa/client/Connection.hxx>
#include <teamcenter/soa/client/ExceptionHandler.hxx>
#include <teamcenter/soa/client/CanceledOperationException.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/internal/ServiceStub.hxx>
#include <teamcenter/soa/client/internal/PolicyManager.hxx>
#include <teamcenter/soa/client/internal/Sender.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/SoaException.hxx>
#include <teamcenter/schemas/soa/_2006_09/clientcontext/RequestHeader.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class TCSOACLIENTMNGD_API SessionManager: public ExceptionHandler
{
public:
    SessionManager( Connection* connection,
                    const std::string& hostPath,
                    CredentialManager* credentials,
                    Connection::Protocol protocol,
                    Connection::Binding bind,
                    bool useCompression );

    ~SessionManager();

    const std::string& getHostPath() const      { return m_hostPath; }
    CredentialManager* getCredentialManager()   { return m_creds; }
    Connection::Protocol getProtocol()const     { return m_proto; }
    Connection::Binding getBinding() const      { return m_bind; }




    void setSender( Teamcenter::Soa::Client::Sender* sender );
    Teamcenter::Soa::Client::Sender* getSender();
    Teamcenter::Soa::Client::Sender* getAlternateSender(const std::string& altBinding);

    Teamcenter::Soa::Client::PolicyManager* getPolicyManager();

    void registerService( const std::string& svcName, ServiceStub* svc );
    Teamcenter::Soa::Client::ServiceStub* getService( const std::string& svcName );

    void login();
    void logout();
    void login ( Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException& exception );


    void setExceptionHandler( ExceptionHandler* handler );
    ExceptionHandler* getExceptionHandler(  );

    static Teamcenter::Soa::Client::SessionManager* getSessionManager( Teamcenter::Soa::Client::Connection* c );

    void initializeLocaleTimeZone();

    void setOption( Connection::Option optionName, const std::string& value);
    std::string getOption( Connection::Option optionName );
    std::string getOptionConst( Connection::Option optionName ) const;

    std::string getServerVersion() const;

    std::string getLocale() const ;
    std::string getSiteLocale() const;


    void setState(const std::string& name, bool value);
    void setState(const std::string& name, const std::string& value);
    void setState(const std::string& name, int value);

    std::string getStringState( const std::string& name)const;
    std::map<std::string,std::string> getStateMap();

    std::string constructRequestEnvelope( const std::string& requestString );

    void validateUser(const std::string& port, const std::string& method, const std::string& args);
    void cacheStateInformation( const std::string& service, const std::string& method, const std::string& args, const std::string& response );
    void pushRequestId();
    void popRequestId() const;
    void resetServer();
    const std::string& getUserID() const;

    // Set the Forward Proxy Credential Provider
    void setProxyCredentialProvider ( Teamcenter::Net::TcServerProxy::Client::CredentialProvider* credProvider);

    //Retrieve the Forward Proxy Credential Provider
    const Teamcenter::Net::TcServerProxy::Client::CredentialProvider* getProxyCredentialProvider() const;

    // Retrieve the TSP Session info
    Teamcenter::Net::TcServerProxy::Client::TSPSession* getTSPSession();
 
    // Set the TSP Session info    
    void setTSPSession(Teamcenter::Net::TcServerProxy::Client::TSPSession* tspSession);

    std::string modifyInput(const std::string& port, const std::string& method, const std::string& args) const;    //Shared Session

    /**
     * Get a unique address for the server.  For 4-tier, this is simply the host path.
     * For 2-tier, it's the IOR since "per-client" ImR could start multiple local servers.
     * @return address to identify the server
     */
    std::string getServerAddress();
 
    virtual void handleException( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InternalServerException& ise );
    virtual void handleException( Teamcenter::Soa::Client::CanceledOperationException& coe );
  
    static std::string STATE_LOCALE;
    static std::string STATE_TIMEZONE;

    static std::string STATE_LOGCORRELATION_ID;

    static std::string STATE_BYPASSFLAG;
    static std::string STATE_ROLE;
    static std::string STATE_GROUP;
    static std::string STATE_GROUPMEMBER;
    static std::string STATE_CURRENT_PROJECT;
    static std::string STATE_WORK_CONTEXT;
    static std::string STATE_REFRESH_POM;
    static std::string STATE_OBJ_PROP_POLICY;
    static std::string STATE_CURRENT_DISPLAY_RULE;
    static std::string STATE_ALLOW_PAGING;
    static std::string STATE_SERVER_ID;
    static std::string STATE_BASE_SCHEMA_VERSION;

    static std::string STATE_CLIENT_ID;
    static std::string STATE_CLIENT_VERSION;
    static std::string STATE_CLIENT_IP_ADDRESS;

    static int   connectionCount;

    SOA_CLASS_NEW_OPERATORS

private:
    friend class Connection;
    SessionManager(); // do not allow use of default
    SessionManager( const SessionManager& right);
    SessionManager& operator = ( const SessionManager& right);

    void constructHeader(Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestHeader>& header);

    bool checkEnvelope( const std::string& xmlIn )const;
    void setSerializedUserName( const std::string& userId );
    void  getServerInfo();
    std::string checkForPartialErrors(const Teamcenter::Soa::Client::ServiceData&  serData) const;
    const std::map< std::string, std::string >&  getStringStateMap() const;
    const std::map< std::string, int >&  getIntegerStateMap()const;
    const std::map< std::string, bool >& getBooleanStateMap()const;
    bool isEmpty(std::string name) const;
    bool isSharedUsField(const std::string& name) const;
    bool isSharedRccField(const std::string& name) const;
    void setSharedSessionState();
    void removeSharedFieldsFromContext();
    void registerWithTcMEM();

    typedef std::map< std::string, Teamcenter::Soa::Client::ServiceStub* > ServiceMap;




    const Teamcenter::Net::TcServerProxy::Client::CredentialProvider* m_proxyCredentialProvider;
    Teamcenter::Net::TcServerProxy::Client::TSPSession* m_tspSession;
    std::string m_hostPath;
    CredentialManager* m_creds;
    Connection::Protocol m_proto;
    Connection::Binding m_bind;
    ExceptionHandler*  m_exceptionHandler;
    Connection*     m_connection;
    std::string     usrId;
    std::string     conId;
    int             reqId;
    std::string     serializedUserId;
    std::string     m_serverVersion;
    std::string     hostName;
    bool            clientIsRegisterd;
    bool            sentIP;
    std::string     clientID;
    std::string     locale;
    std::string     siteLocale;
    Teamcenter::Soa::Client::Sender* m_restSender;
    Teamcenter::Soa::Client::PolicyManager *m_policyManager;
    ServiceMap m_serviceStubs;
    std::map< Connection::Option, std::string>  options;
    std::map< Connection::Option, std::string > overrideOptions;
    std::map< std::string, std::string >  m_contextStringMap;
    std::map< std::string, int >  m_contextIntMap;
    std::map< std::string, bool >  m_contextBooleanMap;
    bool  m_clearPolicyForServerReAssign;
    bool  checkServerVersion;
    bool  useEnvelope;
    bool  enablePartialRCC;
    bool  firstRelogin;
    std::set<std::string> m_licenseTokens;
    std::string           loginDescrimator;
    bool registeredTcMEM;
    
    Teamcenter::Soa::Client::NotifyRequestListeners* m_notifier;


    static std::vector<std::string> sharedUsFields;
    static std::vector<std::string> sharedRccFields;
    static bool firstPass;


    static Teamcenter::Soa::Common::Version partialRCCServer;
     //Constants needed for resetting US state after reassignment.
    static const std::string USER_SESSION_ROLE;
    static const std::string USER_SESSION_GROUP;
    /**Project */
    static const std::string USER_SESSION_PROJECT;
    /**WorkContext */
    static const std::string USER_SESSION_WORKCTX;
    /**Volume */
    static const std::string USER_SESSION_VOLUME;
    /**Local Volume */
    static const std::string USER_SESSION_LOCAL_VOLUME;
    /**GroupMember */
    static const std::string USER_SESSION_GROUPMEMBER;
    /**BypassFlag */
    static const std::string USER_SESSION_BYPASSFLAG;
    /**organization*/
    static const std::string USER_SESSION_ORGANIZATION;
    /**DisplayRule*/
    static const std::string USER_SESSION_DISPLAYRULE;
    /**Locale*/
    static const std::string USER_SESSION_LOCALE;

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
