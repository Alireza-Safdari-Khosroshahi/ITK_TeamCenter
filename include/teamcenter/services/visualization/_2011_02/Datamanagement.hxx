/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_VISUALIZATION__2011_02_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VISUALIZATION__2011_02_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/visualization/Visualization_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Visualization
        {
            namespace _2011_02
            {
                class Datamanagement;

class TCSOAVISUALIZATIONSTRONGMNGD_API Datamanagement
{
public:

    struct IdInfo;
    struct ServerInfo;
    struct SessionInfo;
    struct UserAgentDataInfo;
    struct VVITicketsResponse;

    /**
     * Map of key-value name pair.
     */
    typedef std::map< std::string, std::string > KeyValueMap;

    /**
     * This structure holds the information about the objects that will be launched to the
     * viewer.
     */
    struct IdInfo
    {
        /**
         * A required parameter that references the object to be launched. If needed, launched
         * object will be resolved by the server to a launch able object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  id;
        /**
         * An optional object reference of the Item containing launch able object. If this is
         * not known, the server will attempt to identify the parent if it can.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * An optional object reference of the <b>ItemRevision</b> containing launchable object.
         * If this is not known, the server will attempt to identify if it can.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * An optional parameter references the type of launch action. This controls the action
         * the viewer will perform when it opens the object. The actions supported are one of
         * following: <code>Open</code>, <code>Insert</code>, <code>Merge</code> or <code>Interop</code>.
         * <code>Open</code> will open the object in a new window.  <code>Insert</code> will
         * insert the object into the current window that has focus.  <code>Merge</code> will
         * attempt to merge a pruned product structure with one that is already open if it can.
         * <code>Interop</code> will present a dialog that lets the user select the launch
         * action.
         */
        std::string operation;
        /**
         * An optional parameter referencing the additional information of launched objects
         * in form of key/value pair (if any).
         */
        KeyValueMap idAdditionalInfo;
    };

    /**
     * This structure holds the basic information for Teamcenter Visualization to connect
     * to the server.
     */
    struct ServerInfo
    {
        /**
         * A required parameter referencing the protocol type for connection to the server.
         * Use http for standard 4 tier connections, and iiop for 2 tier deployments.
         */
        std::string protocol;
        /**
         * A required parameter referencing the URL to connect to the server.
         */
        std::string hostpath;
        /**
         * A required parameter referencing the servermode that controls how the connection
         * to the server is made: 2 for two tier. 4 for four tier.
         */
        int servermode;
        /**
         * An optional parameter referencing the additional  information of the server in form
         * of key/value pair (if any).
         */
        KeyValueMap serverAdditionalInfo;
    };

    /**
     * This structure holds the information about the session information of the client
     * application from where the launch operation was initiated.
     */
    struct SessionInfo
    {
        /**
         * Client/Server session discriminator to connect to existing specified session.  This
         * allows the viewer application to share an existing server process session with the
         * client that initiated the launch. If this is not specified, the viewer will present
         * a login prompt.
         */
        std::string sessionDescriminator;
        /**
         * An optional parameter referencing the additional information of the session in form
         * of key/value pair (if any).
         */
        KeyValueMap sessionAdditionalInfo;
    };

    /**
     * This structure holds the information about the client application that initiated
     * the launch.
     */
    struct UserAgentDataInfo
    {
        /**
         * An optional parameter referencing the client who initiates the launch.
         */
        std::string userApplication;
        /**
         * An optional parameter referencing the version of the client that initiated launch.
         */
        std::string userAppVersion;
        /**
         * An optional parameter referencing the additional information of client application
         * in form of key/value pair (if any).
         */
        KeyValueMap userAdditionalInfo;
    };

    /**
     * Used to return information from the <code>createLaunchFile</code> operation. The
     * structure holds the <code>serviceData</code> object and a FMS transient read ticket
     * corresponding to the launch file (VVI or VFZ).
     */
    struct VVITicketsResponse
    {
        /**
         * The FMS transient read ticket of the launch file (VVI or VFZ) generated for the objects
         * that can be launched. The file will be placed in the transient file volume and the
         * caller will need to download it from there with the ticket sent by the service.
         */
        std::string ticket;
        /**
         * SOA Framework object containing error information. In cases where objects cannot
         * be launched, error message, codes will be mapped to respective object id in the list
         * of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This service generates a VVI file which is used to launch Teamcenter Visualization
     * viewers with selected objects from Teamcenter and preserve a two way communication
     * link between the viewer and the server.  These files are not intended to be permanent
     * and should be generated with each launch.  For example, the VVI format is not guaranteed
     * to be supported if the server or viewer is updated.  VFZ files are used if more than
     * one object is launched at a time.
     * <br>
     * <br>
     * This operation requires the Teamcenter File Management System (FMS) to be installed
     * (including FCC and transient volumes) for retrieval of the VVI file from the transient
     * file volume.  This operation generates the launch file (VFZ or VVI), stores it in
     * the FMS transient volume, and returns the FMS ticket.  The client that initiated
     * this operation is responsible for downloading the transient file (VVI or VFZ) with
     * the transient ticket from transient volume to a local file system. Transient (VVI
     * or VFZ) file is then consumed by the Teamcenter Visualization client.  The viewer
     * will then establish the server connection and load the object(s) specified in the
     * VVI file.  Launch on multiple objects will generate a VFZ file (zip of all the vvi
     * files) and transient ticket of VFZ file would be sent to client.
     * <br>
     * <br>
     * This service supports launch on Teamcenter persistent objects like <b>Dataset</b>,
     * <b>Item</b>, <b>ItemRevision</b>, <b>BOMViewRevision</b>, <b>BOMView</b>. It also
     * supports launch of selected <b>BOMLines</b> of a configured structure from Structure
     * Manager or <b>BOPLines</b> from Manufacturing Process Planner, but in this case the
     * caller must first create a <b>VisStructureContext</b> object (See Dependency section
     * for operation to use).  Valid launch object types and behavior such as priority order
     * can be configured with the Teamcenter Preferences <b>VMU_Datasets</b>, <b>VMU_FileSearchOrder</b>
     * and <b>VMU_RelationSearchOrder</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the mechanism of visualizing Teamcenter specific objects
     * in Teamcenter Visualization client. There are several steps to support this mechanism.
     * <br>
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;The client application that initiates the launch will provide:
     * <br>
     * <br>
     * A vector of IdInfo objects that contains one or more pieces of information about
     * Teamcenter objects that needs to be visualized in the viewer (e.g., If <b>Dataset</b>
     * is launched, then information about its <b>Item</b>, <b>ItemRevision</b> and type
     * of operation, including any additional information can be provided). Note: In case
     * launch of Teamcenter runtime objects like BOMLines from Structure Manager or BOPLines
     * from Manufacturing Process Planner, it is the responsibility of the client to create
     * <b>VisStructureContext</b> object and provide <b>VisStructureContext</b> as the object
     * to be laud (See Dependency section for operation to use).
     * <br>
     * <b>SessionInfo</b> object contains session relevant information for Teamcenter Visualization
     * to connect to the session (e.g., session discriminator and any other additional session
     * relevant key value pair)
     * <br>
     * <b>ServerInfo</b> object contains server information for Teamcenter Visualization
     * to connect to the server. (e.g., protocol, server URL, connection mode of the server
     * and any other additional server relevant key value pair)
     * <br>
     * UserAgentDataInfo object contains client application information who initiated the
     * launch. (e.g., application name, application version, and any other additional client
     * application relevant key value pair).
     * <br>
     * <br>
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;After gathering the necessary information as listed in
     * step 1, client application then invokes the <code>DataManagementService::createLaunchFile</code>
     * operation to obtain an FMS read ticket for the launch file (VVI or VFZ), that has
     * relevant information for visualizing Teamcenter persistent or runtime objects.
     * <br>
     * <br>
     * See the Dependencies section below for details.
     * <br>
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;Use a File Management System (FMS) Application Programmatic
     * Interface (API) to download the transient file (VVI or VFZ) from transient volume.
     * <br>
     * <br>
     * Check the documentation for each API to determine how to react to download failures.
     * <br>
     * <br>
     * Use Case References:
     * <br>
     * This operation is used in conjunction with other <code>FileManagementService</code>
     * service operations, <code>Visualization</code> service operations, FccProxy and the
     * FileManagementUtility. Please consult the documentation for each of these available
     * operations for details on the requirements, usage, and environments in which they
     * should be used.
     * <br>
     * <br>
     * Visualization operations for creating the <b>VisStructureContext</b> from clients
     * that initiate the launch of Teamcenter runtime objects like <b>BOMLines</b> from
     * Structure Manager or <b>BOPLines</b> from Manufacturing Process Planner.
     * <br>
     * <br>
     * <code>Teamcenter::Soa::Internal::Visualization::_2011_02:: StructureManagement::CreateVisSCsFromBOMsResponse
     * createVisSCsFromBOMs</code>
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Teamcenter Visualization - Application to allow view and markup of multicad product
     * structure that has a jt representation.
     *
     * @param idInfos
     *        A vector of <code>IdInfo</code> structures which holds information about Teamcenter
     *        objects that need to be visualized in Teamcenter Visualization. For example, if a
     *        <b>Dataset</b> is launched, then information about its <b>Item</b>, <b>ItemRevision</b>
     *        and type of operation, including any additional information can be provided.
     *
     * @param serverInfo
     *        A <code>ServerInfo</code> structure object containing server information for the
     *        viewer to connect to the server.  Contains protocol, server URL, connection mode
     *        of the server and any other additional server relevant key value pair
     *
     * @param userDataAgentInfo
     *        A <code>UserAgentDataInfo</code> structure object containing information about client
     *        that initiated the launch (e.g., application name, application version , and any
     *        other additional client application relevant key value pair)
     *
     * @param sessionInfo
     *        A <code>SessionInfo</code> structure object containing session information for the
     *        viewer to connect to the session.  Includes the session discriminator and any other
     *        additional session relevant key value pair.
     *
     * @return
     *         This operation returns a <code>VVITicketsResponse</code> object which holds a <code>serviceData</code>
     *         object and a FMS transient read ticket corresponding to the launch file (VVI or VFZ).
     *         See the structure description for more information.
     *         <br>
     *         <br>
     *         This operation throws no errors internally.  However, errors thrown from the following
     *         internal PLM system calls may be caught and added to the serviceData error stack:
     *         <br>
     *         <code>VIS__createLaunchFile</code>
     *         <br>
     *         <br>
     *         For objects that cannot be launched, appropriate failure codes will be added to <code>serviceData</code>
     *         for those respective objects and an FMS transient read ticket, for the launch file,
     *         representing the objects that can be launched.
     *
     */
    virtual Teamcenter::Services::Visualization::_2011_02::Datamanagement::VVITicketsResponse createLaunchFile ( const std::vector< Teamcenter::Services::Visualization::_2011_02::Datamanagement::IdInfo >& idInfos,
        const Teamcenter::Services::Visualization::_2011_02::Datamanagement::ServerInfo&  serverInfo,
        const Teamcenter::Services::Visualization::_2011_02::Datamanagement::UserAgentDataInfo&  userDataAgentInfo,
        const Teamcenter::Services::Visualization::_2011_02::Datamanagement::SessionInfo&  sessionInfo ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/visualization/Visualization_undef.h>
#endif

