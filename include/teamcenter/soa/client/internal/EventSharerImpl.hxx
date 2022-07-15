// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

/**
    @file
    methods are for accessing TCCS/TcMEM shared events
*/

/*  */
#ifndef  TEAMCENTER_SOA_CLIENT_EVENTSHARERIMPL_HXX
#define  TEAMCENTER_SOA_CLIENT_EVENTSHARERIMPL_HXX

#include <new>
#include <iostream>
#include <vector>
#include <set>


#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/CredentialManager.hxx>
#include <teamcenter/soa/client/EventSharer.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ServiceData.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/RefId.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InvalidUserException.hxx>
#include <teamcenter/soa/client/internal/TypeImpl.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    //FWD for TcMEMConnection
    namespace Net
    {
        namespace TcModelEventManager
        {
            namespace Client
            {
                class TcMEMConnection;
            }
        }
    }

    namespace Soa
    {
        namespace Client
        {
            class ModelManagerImpl;

            class TCSOACLIENTMNGD_API EventSharerImpl : public Teamcenter::Soa::Client::EventSharer
{
public:
    /**
     * Only want constructor called by framework
     */
    explicit EventSharerImpl( Teamcenter::Soa::Client::Connection* connection);

    virtual ~EventSharerImpl();

    /**
     * This method contacts TCCS to determine if event sharing is functioning.
     * It can be called even if the user has not yet logged in.  If event sharing
     * was previously not working (e.g. TCCS down), this method will retry and if
     * event sharing is now available, it will (re)establish this user with it.
     * If this attempt to (re)establish fails, SessionHandler.handleException will be invoked,
     * assuming the application has registered one with the Connection.
     *
     * @return whether event sharing via TCCS is operational
     */
    virtual bool isEventSharingFunctioning();

    /**
     * This published method makes call to TcMEM to see whether there
     * are other clients sharing this server
     * @return whether TcMEM list of clients > 1
     */
    virtual bool isServerShared();

    /**
     * This method can be called by application clients that wish to "poll"
     * for shared events rather than wait for next service call to obtain them.
     */
    virtual void processSharedEvents();

    /**
     * This internal method relies on last call to TcMEM to know
     * (to support optimization where just talked to TcMEM so cache up-to-date)
     * whereas published API will contact TcMEM to check.
     * @return whether cached list of clients > 1
     */
    bool isServerSharedCached() const;

    /**
     * Register the current client with the TCCS event sharing system.
     * This is invoked by the soa framework when a sharing client logs in.
     *
     * @param user user that has logged in
     * @param discr discriminator used for login
     * @param clientId the unique ID that the connection has assigned to this client
     */
    void registerWithTcMEM( const std::string& user, const std::string& discr, std::string& clientId, std::string& locale );

    /**
     * Unregister the current client from the TCCS event sharing system
     * This is invoked by the soa framework when a sharing client logs out.
     */
    void unregisterTcMEM();

    /**
     * If sharing a server and events, get any events queued for this client.
     * This is invoked by the SOA Framework to get events from TCCS sharing system.
     *
     * @return null if sharing disabled or not registered with TcMEM
     */
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> getSharedEvents();

    /**
     * If sharing a server and events, push this client's events to TcMEM
     * This is invoked by the SOA Framework to put events to the TCCS sharing system.
     *
     * @param wireServiceData the ServiceData returned from the server
     * @return true if actually pushed objects to TcMEM (updating client list)
     * @unpublished
     */
    bool pushSharedEvents( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> wireServiceData );

    /**
     * Logging method for displaying activity prefixed by LogCorrelationId.
     * Logs at info level.
     * @param msg message to print
     */
    void info( const std::string& msg ) const;

    /**
     * Logging method for displaying activity prefixed by LogCorrelationId.
     * Logs at debug level.
     * @param msg message to print
     */
    void debug( const std::string& msg ) const;

    void addSharedSessionHandler( Teamcenter::Soa::Client::SessionHandler* handler );
    void removeSharedSessionHandler( Teamcenter::Soa::Client::SessionHandler* handler );

    SOA_CLASS_NEW_OPERATORS

private:

    EventSharerImpl(): connection(0), modelManagerImpl(0), sharedEventsEnabled(false), isTcmemReg(false), tcmem(0), sharedClientList(), clientId("AnonyClient"), cmuser(""), cmdiscr(""), locale(""), m_sessionHandlers(){}

    /**
     * strip off unneeded or undesired objects
     */
    void cullDataObjects( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> serviceData );

    void filterUnwantedObjects( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> serviceData );

    // Determine subset that are Runtime objects, but not UserSession which is special
    std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> > getRuntimeObjects( std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> > eventObjs );

    std::set<std::string> getUids( std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> > eventObjs ) const;

    /**
     * Invoke the handler registered for session/TCCS issues
     * @param e
     */
    void invokeHandler( const std::string &msg );

    /** UserSession */
    static const std::string RUNTIME_BUSINESS_OBJECT;

    Teamcenter::Soa::Client::Connection* connection;
    Teamcenter::Soa::Client::ModelManagerImpl* modelManagerImpl;
    bool sharedEventsEnabled;
    bool isTcmemReg;
    Teamcenter::Net::TcModelEventManager::Client::TcMEMConnection* tcmem;
    std::vector<std::string> sharedClientList;
    std::string clientId;
    std::string cmuser;
    std::string cmdiscr;
    std::string locale;
    std::set< Teamcenter::Soa::Client::SessionHandler* > m_sessionHandlers;
};
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
