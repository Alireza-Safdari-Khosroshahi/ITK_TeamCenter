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

#ifndef TEAMCENTER_SERVICES_VISUALIZATION_DATAMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_VISUALIZATION_DATAMANAGEMENTSERVICE_HXX

#include <teamcenter/services/visualization/_2011_02/Datamanagement.hxx>
#include <teamcenter/services/visualization/_2013_05/Datamanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/visualization/Visualization_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Visualization
        {
            class DatamanagementService;

/**
 * This library contains a set of service operations that perform server side business
 * logic for the visualization integrations.  These operations help interrogate and
 * manipulate the Teamcenter data model for visualization data, and aid with integrating
 * visualization enabled client applications with Teamcenter in a consistent way.  There
 * are operations that help launch visualization given an object reference (e.g. <code>createLaunchFile</code>).
 * There are operations that help load and save Product Views (e.g. <code>getSnapshot3DInfo</code>,
 * <code>createSnapshot3D</code>, etc).  There are operations for creating and updating
 * markups and visualization sessions.   There are operations for handling product structure
 * and configuration recipes (the <code>StructureManagement</code> operations).
 * <br>
 * <br>
 * Nearly all of these are internal operations, used by the various internal PLM client
 * applications and visualization integrations (embedded and standalone).  However,
 * there are 3 exceptions to this, the following visualization operations were made
 * public:
 * <br>
 * <ul>
 * <li type="disc"><code>createLaunchFile</code>
 * </li>
 * <li type="disc"><code>createBOMSFromRecipes</code>
 * </li>
 * <li type="disc"><code>createVisSC</code>
 * </li>
 * </ul>
 * <br>
 * These operations can be used by customers to integrate an external visualization
 * application or custom PLMVis based viewer with data stored and maintained in Teamcenter.
 * The most common use case where this is needed is shop floor visualization.
 * <br>
 * <br>
 * These operations are used by all the visualization integrations provided today, for
 * example: 1) integrated standalone visualization, 2) visualization embedded in the
 * RAC, and 3) visualization embedded in the Thin Client.  Use of these services ensures
 * consistent behavior and code reuse across the various visualization enabled client
 * applications of Teamcenter.
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * SpatialStructureManagement, StructureManagement, DataManagement, StructureManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoavisualizationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoavisualizationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAVISUALIZATIONSTRONGMNGD_API DatamanagementService
    : public Teamcenter::Services::Visualization::_2011_02::Datamanagement,
             public Teamcenter::Services::Visualization::_2013_05::Datamanagement
{
public:
    static DatamanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This service generates a VVI file which is used to launch Teamcenter Visualization
     * viewers with selected objects from Teamcenter and preserve a two way communication
     * link between the viewer and the server.  This operation can return the VVI type information
     * as a string buffer or as a read file ticket to a vvi/vfz file in the FMS transient
     * file volume. NOTE: VVI and VFZ files are not intended to be persisted and should
     * be generated with each launch of visualization. For example, the VVI format is not
     * guaranteed to be supported if the server or viewer is updated. VFZ files are used
     * if more than one object is launched at a time, while VVI files are used for single
     * objects. The client can retrieve the VVI/VFZ launch file information via string buffer
     * or through the transient file volume. This is controlled by setting the hasTransientVolume
     * flag of the SessionInfo2 input structure.  With the hasTransientVolume flag set to
     * false, the launch info returns a vvi string buffer for each launch object or as a
     * stream of vvi string buffers for multiple launch objects.  Using the API in this
     * way can avoid setup and use of the FMS system directly by the calling client.  It
     * is the responsibility of the client to decipher the response data structure.  For
     * example, the vvi string buffer(s) can be written out as a vvi or vfz file on the
     * client and passed to visualization, or the string buffer can be passed directly to
     * embedded visualization if using the PLMVis toolkit.  With the hasTransientVolume
     * flag set to true, the operation requires the Teamcenter File Management System (FMS)
     * to be installed (including FCC and transient volumes) for retrieval of the VVI file
     * from the transient file volume. This operation generates the launch file (VFZ or
     * VVI), stores it in the FMS transient volume, and returns the FMS ticket. The client
     * that initiated this operation is responsible for downloading the transient file (VVI
     * or VFZ) with the transient ticket from transient volume to a local file system. The
     * transient (VVI or VFZ) file is consumed by the Teamcenter Visualization client. The
     * viewer will then establish the server connection and load the object(s) specified
     * in the VVI file.  Launch on multiple objects will generate a VFZ file (zip of all
     * the vvi files) and transient ticket of VFZ file would be sent to client. This service
     * supports launch on Teamcenter persistent objects like Dataset, Item, ItemRevision,
     * BOMViewRevision, BOMView. It also supports launch of selected BOMLines of a configured
     * structure from Structure Manager or BOPLines from Manufacturing Process Planner,
     * but in this case the caller must first create a VisStructureContext object. Valid
     * launch object types and behavior such as priority order can be configured with the
     * Teamcenter Preferences VMU_Datasets, VMU_FileSearchOrder and VMU_RelationSearchOrder.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Teamcenter Visualization - Application to allow view and markup of multicad product
     * structure that has a jt representation.
     *
     * @param idInfos
     *        A list of Teamcenter objects and related information that need to be visualized in
     *        Teamcenter Visualization. For example, if a Dataset is launched, then information
     *        about its Item, ItemRevision and type of operation, including any additional information
     *        can be provided.
     *
     * @param serverInfo
     *        Server information for the viewer to connect to the server. Contains protocol, server
     *        URL, connection mode of the server and any other additional server relevant key value
     *        pair.
     *
     * @param userDataAgentInfo
     *        The information about the client that initiated the launch (e.g., application name,
     *        application version, and any other additional client application relevant key value
     *        pair).
     *
     * @param sessionInfo
     *        The session information for the viewer to connect to the session. Includes the session
     *        discriminator and any other additional session relevant key value pair.
     *
     * @return
     *         VVI file data as a string buffer or FMS file ticket for the request objects. The
     *         following partial errors may be returned: 208031: Launch request is not valid. 208013:
     *         The selected object is invalid for the launch operation; 208012: Launch file generation
     *         failed.
     *
     */
    virtual Teamcenter::Services::Visualization::_2013_05::Datamanagement::LaunchInfoResponse createLaunchInfo ( const std::vector< Teamcenter::Services::Visualization::_2013_05::Datamanagement::IdInfo2 >& idInfos,
        const Teamcenter::Services::Visualization::_2011_02::Datamanagement::ServerInfo&  serverInfo,
        const Teamcenter::Services::Visualization::_2011_02::Datamanagement::UserAgentDataInfo&  userDataAgentInfo,
        const Teamcenter::Services::Visualization::_2013_05::Datamanagement::SessionInfo2&  sessionInfo ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/visualization/Visualization_undef.h>
#endif

