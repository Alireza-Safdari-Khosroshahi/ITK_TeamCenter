// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_CLIENTMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_CLIENTMANAGER_HXX

#include <string>
#include <vector>
#include <set>
#include <map>
#include <new>

#ifdef WNT
    #include <winsock2.h>
    #include <windows.h>
    #include <psapi.h>
#else
#endif


#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * This class keeps tracks of SOA Client applications running on the current client host.
 * Each Connection/SessionManager instance will register itself with this class. Information
 * for the Connection/SessionManager will be persisted to the file
 * %user.home%/Teamcenter/SOA/activeClients.properties. Entries in this file will have this format:
 * <pre>
 * applicationName.pid.sessionCount=hostName.pid.sessionCount
 * Teamcenter.5638.01=cyi6p203.5638.01
 * NxManager.4231.01=cyi6p203.4321.01
 * </pre>
 * The clientID (hostName.pid.sessionCount) is also sent to the server to be used to track
 * client session using the TcServer instance. It is only when each unique client has sent
 * the SessionSerivce.logout request is the TcServer actually terminated.
 * When the client application sends the SessionService.logout request it will unregister itself
 * from the ClientManager, and thus the activeClients.properties will have a list of Applications
 * that are currently running.<br>
 *
 * If an application crashes or is killed before sending the SessionService.logout request to the server
 * it will leave a dangling entry in the activeClients.properties, also the TcServer will not terminate
 * as it never received the logout request. When that application is started again it will register itself,
 * but this time the clientId from the dangling session will be used and thus the server will not see this as a
 * second client but a continuation of the client that was killed.<br>
 *
 * This management does not affect client sessions that do not attempt to share a TcServer instance.  While they
 * are still registered here, the clientId is more or less ignored by a server that only receives a single clientId
 * and does not matter what that value is.
 *
 */
class TCSOACLIENTMNGD_API ClientManager
{
public:
    struct ClientInfo
    {
        /** The name of the client host machine*/
        std::string mHostName;
        /** A guess at the name of the containing application*/
        std::string mAppName;
        /** The Process ID of this application */
        int    mPid;
        /** IP Address of client host */
        std::string mIpAddress;
        /** Client ID */
        std::string mClientId;
        /** Connection Count */
        int    mCount;


        ClientInfo();
        ClientInfo( const ClientInfo& right); 

    };

    ~ClientManager();
    SOA_CLASS_NEW_OPERATORS

    /**
     * Reserve a Id this Connection/SessionManager instance.
     *
     * @return The ClientID associated with this session. May be taken from a orphaned instance.
     */
     static ClientInfo reserveClientId();

    /**
     * Register this Connection/SessionManager instance.
     *
     * @param clientId The Client ID of the session to unregister (Id from registerClient)
     *
     */
    static void registerClient( const std::string& clientId );
 
    /**
     * Unregister this Connection/SessionManager instance.
     * @param clientId The Client ID of the session to unregister (Id from registerClient)
     */
    static void unregisterClient( const std::string& clientId );

    /**
     * Get a list of active clients and the clientIds for each
     * @return  A map of applicationName.pid.sessionCount/hostName.pid.sessionCount
     */
    static std::map<std::string,std::string> getActiveClients();

    /**
     * Get the information about this client application
     * @return Client Application information
     */
    static ClientInfo getClientInfo();

    /**
     * Empty out the list of Active Clients
     */
    static void clearClientList();

private:



#ifdef WNT
typedef std::set<int>             PidList;
#else
typedef std::map<int,std::string> PidList;
#endif

    ClientManager();

    ClientInfo reserverThisClientId();
    void registerThisClient( const std::string& clientId );
    void unregisterThisClient( const std::string& clientId );
    void readActiveClients( bool releaseLock);
    void writeActiveClients();

    static ClientInfo  getThisClientInfo();
    static PidList collectAllPIDs();
    static std::string executeCommand( const std::string& command );
    static std::string getHostName();
    static std::string getIpAddress();

    bool openFileWithLock( const std::string& propertyFile, const std::string& mode);
    void readLines( std::vector<std::string>& lines );
    void unLockFile();


    static std::string getActiveCientsFilePath();

    static       int           sConnectionCount;

#ifdef WNT
    HANDLE          mFileHandle;
    PidList         mPids;
#else
    FILE             *mFileHandle;
    PidList          mPids;
#endif
    std::map<std::string,std::string>       mActiveClients;
    bool             mSafeToWrite;

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

