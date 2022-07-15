// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_XMLRESTSENDER_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_XMLRESTSENDER_HXX

#include <teamcenter/soa/client/internal/Sender.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/client/internal/NotifyRequestListeners.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class TCSOACLIENTMNGD_API XmlRestSender : public Sender
{
public:
    
    explicit XmlRestSender(  Teamcenter::Soa::Client::SessionManager *sessionManager, 
        Teamcenter::Soa::Client::Transport *transport,
        Teamcenter::Soa::Client::NotifyRequestListeners *notifier);
    ~XmlRestSender();

    // used to handle XML formatted SOA messages.
    virtual void invoke( const std::string& port, const std::string& method, const std::string& args, Teamcenter::Soa::Common::Xml::SAXToNodeParser& parser );

    SOA_CLASS_NEW_OPERATORS

protected:
    XmlRestSender() : m_notifier(0){}

    // notifier for request/response listener invocation
    Teamcenter::Soa::Client::NotifyRequestListeners *m_notifier;

private:
    
    virtual void retryInvoke( const std::string& port, const std::string& method, const std::string& args, Teamcenter::Soa::Common::Xml::SAXToNodeParser& parser );
};


        }}}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif