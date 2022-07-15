// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

/**
    TccsTransport is used to send SOA service requests
    using TCCS process.
*/

#ifndef TEAMCENTER_SOA_CLIENT_TCCSTRANSPORT_HXX
#define TEAMCENTER_SOA_CLIENT_TCCSTRANSPORT_HXX

#include <string>
#include <new>
#include <teamcenter/soa/client/internal/Transport.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter { namespace Net { namespace TcServerProxy { namespace Client { class TSPSession; }}}}

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
                /**Application Header for Service name included with every request from client */
                static const std::string  HEADER_SERVICE_NAME = "Service-Name";
              
                /**Application Header for Environment name */
                static const std::string  HEADER_ENV_NAME = "Env-Name";

                /** Application Header for Operation name is included with every request from client */
                static const std::string  HEADER_OP_NAME = "Operation-Name";

                /** Application Header indicating use of compression in TcServerProxy and is included with every request from client */
                static const std::string  HEADER_USE_COMP  = "Use-Compression";
                
                /** Application Header for Log Correlation ID */
                static const std::string  HEADER_LOG_CORR_ID = "Log-Correlation-ID";

                /** Application Header indicating environment to be used for submitting HTTP request */
                static const std::string  HEADER_USE_CALLBACK = "Use-Callback";

                /**Application Header containing locale */
                static const std::string  HEADER_LOCALE = "Locale";

                /**Response Header containing session ID */
                static const std::string  RESPONSE_HEADER_SESSIONID = "ResponseSessionID";

                /** Header for arbitrary server URL that client applications could use */
                static const std::string  HEADER_SERVER_URL = "Server-Url";

                /**Application Header containing session ID */
                static const std::string  HEADER_SESSIONID = "SessionID";

                /**Response Header denoting whether Response is compressed */
                static const std::string  RESPONSE_HEADER_COMPRESSION = "ResponseHeaderCompression";

                class TCSOACLIENTMNGD_API TccsTransport : public Transport
                {
                public:
                    
                    SOA_CLASS_NEW_OPERATORS
                    explicit TccsTransport(  Teamcenter::Soa::Client::SessionManager *sessionManager );
                    ~TccsTransport();

                   virtual void sendRequest( const std::string& port, const std::string& method, const std::string& args, const std::string& servletURI, std::string& responseString );

                protected:
                    Teamcenter::Soa::Client::SessionManager* m_sessionManager;

                private:
                    TccsTransport(); // don't allow use of default  
                    
                    void* lateLoadObj;
                    static unsigned refCount;
                };

}}} // namespace


#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
