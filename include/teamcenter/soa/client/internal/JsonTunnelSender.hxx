// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_JSONTUNNELSENDER_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_JSONTUNNELSENDER_HXX

#include <string>
#include <new>
#include <teamcenter/soa/client/internal/Sender.hxx>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/client/internal/Transport.hxx>
#include <teamcenter/soa/client/internal/NotifyRequestListeners.hxx>


#include <teamcenter/soa/common/xml/Utf8String.hxx>

#include <teamcenter/soa/internal/common/Monitor.hxx>
#include <teamcenter/soa/internal/common/AuthUtils.hxx>
#include <teamcenter/soa/internal/common/LogCorrelation.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>

#include <teamcenter/soa/client/RuntimeException.hxx>
#include <teamcenter/soa/client/ExceptionHandler.hxx>
#include <teamcenter/soa/client/WebSEALChallengeException.hxx>
#include <teamcenter/soa/client/internal/Logger.hxx>
#include <teamcenter/soa/client/internal/SessionManager.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InvalidUserException.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
   
class TCSOACLIENTMNGD_API JsonTunnelSender : public Sender
{
public:
        
    explicit JsonTunnelSender(  Teamcenter::Soa::Client::SessionManager *sessionManager, 
        Teamcenter::Soa::Client::Transport *transport,
        Teamcenter::Soa::Client::NotifyRequestListeners *notifier);
    ~JsonTunnelSender();

    
    virtual void invoke( const std::string& port, const std::string& method, const std::string& args, Teamcenter::Soa::Common::Xml::SAXToNodeParser& parser );

    // add the tunnel specific invoke variant. Return the payload as string.  Default impl will return null.
    virtual std::string invokeTunnel(const std::string& port, const std::string& method, const std::string& args );

    SOA_CLASS_NEW_OPERATORS

protected:

    JsonTunnelSender() : m_notifier(0){} 
    
    Teamcenter::Soa::Client::NotifyRequestListeners *m_notifier;

private:
     virtual std::string retryInvoke( const std::string& port, const std::string& method, const std::string& args);

};



}}} // namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif