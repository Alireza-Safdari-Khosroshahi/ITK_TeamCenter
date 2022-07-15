// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_SENDER_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_SENDER_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/client/internal/Transport.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            class  SessionManager;
            class  Sender; // forward decl

/*
 * This class is used to push and pop elements on the Log Correlation ID.
 * The contructor will push the elements on, and the destructor pop them off.
 */
class TCSOACLIENTMNGD_API RequestId
{
public:
    /**
     * Push connection Id, User, and Request Count onto the Log Correlation ID
     */
    explicit RequestId(Teamcenter::Soa::Client::Sender *sender );
    /**
     * Push a Label, connection Id, User, and Request Count onto the Log Correlation ID
     */
    RequestId( const std::string& label, Teamcenter::Soa::Client::Sender *sender );
    /**
     * Push a Label onto the Log Correlation ID
     */
    explicit RequestId( const std::string& label );
    ~RequestId();

private:
    RequestId();        // do not allow use of default
    int    m_popCount;
};

class TCSOACLIENTMNGD_API Sender
{
public:
    Sender(  Teamcenter::Soa::Client::SessionManager *sessionManager, 
        Teamcenter::Soa::Client::Transport *transport);
    SOA_CLASS_NEW_OPERATORS
    virtual ~Sender();

    virtual void invoke( const std::string& port, const std::string& method, const std::string& args, Teamcenter::Soa::Common::Xml::SAXToNodeParser& parser ) =0;
    virtual Transport* getTransport();

    // add the tunnel specific invoke variant. Return the payload as string.  Default impl will return null.
    // since the C++ logic passes the Parser directly on the invoke api, rather than returning the string, we
    // need this alternate API for the tunnel case.
    virtual std::string invokeTunnel(const std::string& port, const std::string& method, const std::string& args );
        
protected:
    friend class Teamcenter::Soa::Client::RequestId;

    Sender() : m_transport(0), m_sessionManager(0), conId("00"), reqId(0){}

    Teamcenter::Soa::Client::SessionManager* m_sessionManager;
    Teamcenter::Soa::Client::Transport*      m_transport;

    std::string     conId;
    int             reqId;
};



}}} // namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif