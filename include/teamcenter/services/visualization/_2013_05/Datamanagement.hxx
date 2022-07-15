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

#ifndef TEAMCENTER_SERVICES_VISUALIZATION__2013_05_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VISUALIZATION__2013_05_DATAMANAGEMENT_HXX

#include <teamcenter/services/visualization/_2011_02/Datamanagement.hxx>
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
            namespace _2013_05
            {
                class Datamanagement;

class TCSOAVISUALIZATIONSTRONGMNGD_API Datamanagement
{
public:

    struct IdInfo2;
    struct LaunchInfoResponse;
    struct SessionInfo2;

    /**
     * Map of key-value name pair.
     */
    typedef std::map< std::string, std::string > KeyValueMap2;

    /**
     * A map containing client ids or additional Teamcenter object UID  and vviStringBuffer
     * as key/value pairs.
     */
    typedef std::map< std::string, std::string > VVIStringBufferOutputMap;

    /**
     * A Teamcenter object structure that contains the related information that need to
     * be visualized in Teamcenter Visualization.
     */
    struct IdInfo2
    {
        /**
         * The business object to be laucnhed. Launched object could be Item, ItemRevision,
         * Dataset, BOMView_Revision, BOMView. The business object will be resolved by the server
         * in some cases (e.g. Item or ItemRevision launch) to a directly launchable visualization
         * object (such as a DirectModel Dataset or BOMViewRevision).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The parent or containing Item of the launched object (object).  If this is not known,
         * the server will attempt to identify the parent if it can.  If the parent information
         * cannot be identified, this will not result in an error condition, it simply will
         * not pass the information to the visualization client which for some cases may affect
         * what features are available in the client.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The parent or containg ItemRevision of the launched object (id). If this is not known,
         * the server will attempt to identify the parent if it can.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * The type of launch action the viewer is instructed to perform (e.g. open, insert,
         * merge, etc).  If left empty, it will default to open. This controls the action the
         * viewer will perform when it opens the object. The following actions are supported:
         * 1. open - Open the object in a new window.  2. Insert - Insert the object into the
         * current window that has focus. 3. merge - Attempt to merge a pruned product structure
         * with one that is already open (and has focus) if it can. 4. Interop -Present a dialog
         * that lets the user select the launch action.
         */
        std::string operation;
        /**
         * This is a generic mechanism for putting additional key value pairs into the VVI file
         * that control viewer launch behavior.
         */
        KeyValueMap2 idAdditionalInfo;
        /**
         * This specifies the structure launch mode to open the structure object in Teamcenter
         * Visualization. The different structure launch modes that are supported are: 1. Dynamic
         * - When this mode is used, it launches the dynamic structure in Teamcenter Visualization.
         * 2. Static - When this mode is used, it launches the static structure in Teamcenter
         * Visualization. 3. Preference - This specifies that Teamcenter Visualization preference
         * is used to launch the structure. 4. Ask - This mode of launch asks user to specify
         * the launch mode.
         */
        std::string structureMode;
        /**
         * This is the UID of the launched object against which the VVI string buffer will be
         * stored.
         */
        std::string clientId;
    };

    /**
     * A response structure for the createLaunchInfo () operation.
     */
    struct LaunchInfoResponse
    {
        /**
         * The VVI file ticket to the transient volume. This member is valid only if  hasTransientVolume
         * flag is set to true in SessionInfo2.
         */
        std::string ticket;
        /**
         * The map of clientId to the VVI string buffer(stirng/string). This member is valid
         * only if hasTransientVolume flag is set to false in SessionInfo2.
         */
        VVIStringBufferOutputMap vviStrBuffersOutputMap;
        /**
         * The object containing error information. In cases where objects can't be launched,
         * error message, codes will be mapped to respective object id in the list of partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Object containing session information for the viewer to connect to the session.
     * Includes the session discriminator and any other additional session relevant key
     * value pair.
     */
    struct SessionInfo2
    {
        /**
         * Client-Server session discriminator to connect to an existing tcserver session.
         * This allows the viewer to share an existing tcserver.exe session with the launching
         * client. This should be the same as the SessionDescriminator argument of the SessionService.login
         * operaiton.  If this empty string, the viewer will present a login prompt if it does
         * not already have a session established.
         */
        std::string sessionDescriminator;
        /**
         * The additional information related to session to put in the VVI file/buffer in the
         * form of key value pair (key (string) = value(/stirng)).(Refer to Teamcenter Visualization
         * VVI documentation on acceptable additional information).
         */
        KeyValueMap2 sessionAdditionalInfo;
        /**
         * If true the VVI information is returned as a file ticket to the transient volume,
         * otherwise it is returned directly as a string.
         */
        bool hasTransientVolume;
    };




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


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/visualization/Visualization_undef.h>
#endif

