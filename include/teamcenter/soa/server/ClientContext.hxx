///Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_SERVER_CLIENTCONTEXT_HXX
#define TEAMCENTER_SOA_SERVER_CLIENTCONTEXT_HXX

#include <string>
#include <map>
#include <set>
#include <vector>
#include <tc/infomanager.hxx>
#include <tcgateway/tcbracketmanager.hxx>
#include <metaframework/BusinessObjectRef.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/Version.hxx>
#include <teamcenter/schemas/soa/_2006_09/clientcontext/RequestEnvelope.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ObjectPropertyPolicy.hxx>

#include <teamcenter/soa/server/SoaServerExports.h>




namespace Teamcenter{ namespace Schemas{ namespace Soa     { namespace _2006_09{ namespace Clientcontext{ class RequestHeader;}}}}}
namespace Teamcenter{ namespace Soa    { namespace Internal{ namespace Core    { namespace _2007_05     { class SessionImpl;  }}}}}
namespace Teamcenter{ namespace Soa    { namespace Internal{ namespace Core    { namespace _2008_03     { class SessionImpl;  }}}}}
namespace Teamcenter{ namespace Soa                        { namespace Core    { namespace _2006_03     { class SessionImpl;  }}}}
namespace Teamcenter{ namespace Soa                        { namespace Core    { namespace _2007_01     { class SessionImpl;  }}}}
namespace Teamcenter{ namespace Soa                        { namespace Core    { namespace _2007_06     { class SessionImpl;  }}}}
namespace Teamcenter{ namespace Soa                        { namespace Core    { namespace _2008_06     { class SessionImpl;  }}}}
namespace Teamcenter{ namespace Soa                        { namespace Core    { namespace _2007_12     { class SessionImpl;  }}}}
namespace Teamcenter{ namespace Soa                        { namespace Core    { namespace _2012_02     { class SessionImpl;  }}}}
namespace Teamcenter{ namespace Soa    { namespace Core    { class SessionImplServices; }}}
namespace Teamcenter{ namespace Soa    { namespace Core    { class AlternateIdImpl; }}}

namespace Teamcenter
{
    namespace Soa
    {
         namespace Server
         {


/**
 * The Client Context class
 */
class TCSOASERVER_API ClientContext
{
public:


    // State key names used anywhere in the server
    static std::string STATE_LOCALE;
    static std::string STATE_TIMEZONE;
    static std::string STATE_CLIENT_ACCEPTS_CHILD_EVENTS;
    static std::string STATE_CURRENT_DISPLAY_RULE;
    static std::string STATE_CLIENT_VERSION;
    static std::string STATE_TRANSPORT_BINDING;
    static std::string STATE_TRANSPORT_JSON;
    static std::string STATE_TRANSPORT_XML;
    static std::string STATE_STATELESS;


    static std::string  pushClientState(const std::string& xmlIn,   const std::string& serverID, 
                                        const std::string& service, const std::string& method, 
                                        FILE* communicationLogFile );
    static void         popClientState (const std::string& method);

    static std::string  getStringState  (const std::string& name);
    static bool         getBooleanState (const std::string& name);
    static int          getIntegerState (const std::string& name);
    static BusinessObjectRef<Teamcenter::BusinessObject> getTagState (const std::string& name);
    static void         removeCurrentClient();
    static void         removeAllClients();
    static int          getNumberOfActiveClients();

    static bool         isStateAvailable(const std::string& name);

    static std::map< std::string, std::string > * _getClientContextMap();
    static const std::string   isReqServerIDAvailable(const std::string& xmlIn);
    static std::string  getRequestBody(const std::string& envelope);
    static std::string  getRequestPropertyPolicy(const std::string& envelope);

    static bool   checkEnvelope(const std::string& xmlIn);

    // Apply the property requirements as explicitly stated by the client
    static void applyServicePropertyPolicy( const std::string &xmlIn );

private:
    friend class        Teamcenter::Soa::Internal::Core::_2007_05::SessionImpl;
    friend class        Teamcenter::Soa::Internal::Core::_2008_03::SessionImpl;
    friend class        Teamcenter::Soa::Core::_2006_03::SessionImpl;
    friend class        Teamcenter::Soa::Core::_2007_01::SessionImpl;
    friend class        Teamcenter::Soa::Core::_2007_06::SessionImpl;
    friend class        Teamcenter::Soa::Core::_2008_06::SessionImpl;
    friend class        Teamcenter::Soa::Core::_2007_12::SessionImpl;
    friend class        Teamcenter::Soa::Core::_2012_02::SessionImpl;
    friend class        Teamcenter::Soa::Core::SessionImplServices;
    friend class        Teamcenter::Soa::Core::AlternateIdImpl;
    
    enum ClientType
    {
        NonRccOrWSDL,       // Any request without RCC headers, could be WSDL, or any SOA client before version handshake
        FullRcc,            // Pre 9.0 Client request with RCC headers
        PartialRcc,         // 9.0 or newer Client with RCC headers
        ThinClient,         // Request comming from Thin Client (TcScript)
        JsonClient          // JSON palyload
    };

    static void         processClientContext(Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestHeader> header,
                                             const std::string& serverID,  FILE* communicationLogFile);
    static void         initializeState(  );
    static void         logStateChange( const std::string& key );
    static void         applyAllState();
    static void         applyState( const std::string& key );
    static void         disableUserSessionState( const std::vector< std::string >& names );
    static std::string  getThinClientLogCID(const std::string& xmlIn);
    static ClientContext::ClientType rccOrNonRcc( const std::string& xmlIn);
    static void         parseEnvelope(const std::string& xmlOrJsonDocument,
                                  Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestEnvelope> envelope,  
                                  Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectPropertyPolicy>&     policy,  //by reference so it can be made null inside
                                  std::string& bodyString );
    static void         applyServicePropertyPolicy( 
                                  Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectPropertyPolicy> objPropPolicy  );


    static void         setClientVersion( const std::string& clientVersion );
    static void         restoreState( const std::map< std::string, std::string >& backUpMap, FILE* communicationLogFile );
    static Teamcenter::Soa::Common::Version getClientVersion( 
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestEnvelope> requestEnv);

    static void         setStateAndClientContext( const std::string& key, bool value );
    static void         setStateAndClientContext( const std::string& key, int value );
    static void         setTagStateAndClientContext( const std::string& key, tag_t value );
    static void         setStateAndClientContext( const std::string& key, const std::string& value );
    static void         setStateAndClientContext( const std::string& key, const BusinessObjectRef<Teamcenter::BusinessObject> value );

    static void         updateClientState( const std::string& key, bool value );
    static void         updateClientState( const std::string& key, int value  );
    static void         updateClientTagState( const std::string& key, tag_t value  );
    static void         updateClientState( const std::string& key, const std::string& value );
    static void         updateClientState( const std::string& key, const BusinessObjectRef<Teamcenter::BusinessObject> value);


    static std::string getActiveClients();
    static void logActiveClients();
    static void logCurrentClient( const std::string& key );



    static std::map< std::string, std::string >  s_contextMap;
    static std::map< std::string, std::string >  s_defaultMap;
    static std::map< std::string, std::string >  s_fullRccClientMap;
    static std::map< std::string, std::string >  s_partialRccClientMap;
    static std::map< std::string, std::string >  s_nonRccClientMap;
    static std::map< std::string, std::string >  s_thinClientMap;
    static std::set< std::string >               s_disabledVariables;
    static std::set< std::string >               s_sharedRccFields;
    static std::set< std::string >               s_clientFields;
    static std::set< std::string >               s_activeClients;
    static std::string                           s_wsdlClientVersion;
    static Teamcenter::Soa::Common::Version      s_PartialRccClientVersion;
    static ClientType                            s_clientType;

// The rest of the server does not need to know these key names
    static std::string STATE_ROLE;
    static std::string STATE_GROUP;
    static std::string STATE_GROUPMEMBER;
    static std::string STATE_BYPASSFLAG;
    static std::string STATE_CURRENT_PROJECT;
    static std::string STATE_CURRENT_ORGANIZATION;
    static std::string STATE_CURRENT_CHANGE_NOTICE;
    static std::string STATE_WORK_CONTEXT;
    static std::string STATE_REFRESH_POM;
    static std::string STATE_ALLOW_PAGING;
    static std::string STATE_OBJ_PROP_POLICY;
    static std::string STATE_LOGCORRELATION_ID;
    static std::string STATE_COMBINE_BOM_PROPS;
    static std::string STATE_MAX_OPERATION_BRACKET_TIME;
    static std::string STATE_MAX_OPERATION_BRACKET_INACTIVE_TIME;
    static std::string STATE_SERVER_ID;
    static std::string STATE_BASE_SCHEMA_VERSION;
    static std::string STATE_CLIENT_ID;
    static std::string STATE_CAD_BYPASS_CHECKOUT;
    static std::string STATE_TCS_USE_CONDENSED_XML;
    static std::string STATE_PEFORMANCE_MONITOR;
    static std::string STATE_CLIENT_IP_ADDRESS;
    static std::string JSON_ENVELOPE_HEADER;
    static std::string JSON_ENVELOPE_BODY;
    static std::string JSON_ENVELOPE_STATE;
    static std::string JSON_ENVELOPE_POLICY;
};


}}} // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
