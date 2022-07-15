// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2010.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

/**
    @file

    This interface is used for invoking methods involving shared events
    TCCS must be running for the methods to succeed.

*/
/*  */

#ifndef TEAMCENTER_SOA_CLIENT_EVENTSHARER_HXX
#define TEAMCENTER_SOA_CLIENT_EVENTSHARER_HXX
#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API EventSharer
{
public:
    virtual ~EventSharer(){};

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
    virtual bool isEventSharingFunctioning() = 0;
    
    /**
     * @return whether this server is currently being shared
     * with at least one other client
     */
    virtual bool isServerShared() = 0;

    /**
     * This method can be called by application clients that wish to "poll"
     * for shared events rather than wait for next service call to obtain them.
     * If there are problems accessing the TCCS event sharing system,
     * SessionHandler.handleException will be invoked,
     * assuming the application has registered one with the Connection.
     */
    virtual void processSharedEvents() = 0;

};
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
