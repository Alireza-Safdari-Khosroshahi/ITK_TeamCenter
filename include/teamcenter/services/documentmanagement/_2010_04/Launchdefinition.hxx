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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2010_04_LAUNCHDEFINITION_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2010_04_LAUNCHDEFINITION_HXX

#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/documentmanagement/DocumentManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Documentmanagement
        {
            namespace _2010_04
            {
                class Launchdefinition;

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API Launchdefinition
{
public:

    struct LaunchDefinitionResponse;
    struct LDSelectedInputInfo;
    struct SsoInfo;
    struct ServerInfo;
    struct SessionInfo;
    struct UserAgentDataInfo;

    /**
     * Key value map.
     */
    typedef std::map< std::string, std::string > KeyValueMap;

    /**
     * Return data for the laucnh definition.
     */
    struct LaunchDefinitionResponse
    {
        /**
         * Launch defintion XML string
         */
        std::string xmlLaunchDef;
        /**
         * The Service Data. Partial errors and failures are updated and returned through this
         * object
         */
        Teamcenter::Soa::Client::ServiceData svcData;
    };

    /**
     * Launch definition selected input information.
     */
    struct LDSelectedInputInfo
    {
        /**
         * The id can be an <b>Item</b>, an <b>ItemRevision</b> business object, a <b>Dataset</b>
         * business object or a markup control object.  It is required.  If empty, invalid object
         * error is returned
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  id;
        /**
         * Related item to input id.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * Related ItemRevision to the input id.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * Related markup control object (related to the markup through MarkupContextRelation).
         * The control object is determined based on the business object constant Fnd0MarkupControlObject
         * set to true.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  controlObj;
        /**
         * There are 3 possible values for this element. MARKUP, VIEW, EDIT.  Example, MARKUP
         * is for View/Markup action.  VIEW and EDIT is for View/Open action on an office dataset
         * business object.
         */
        std::string requestMode;
        /**
         * This is the map of additional information in the form of key value pair strings.
         * This can be empty.
         */
        KeyValueMap additionalInfo;
    };

    /**
     * The information for SSO.
     */
    struct SsoInfo
    {
        /**
         * The login service Uniform resource locator (Url).
         */
        std::string loginServiceUrl;
        /**
         * The application Id of the Teamcenter server in this Single Sign On(SSO) environment.
         */
        std::string appId;
    };

    /**
     * Server Information.
     */
    struct ServerInfo
    {
        /**
         * http or iiop (Protocol type for connection to the server). http is for four tier
         * and iiop is for two tier deployment
         */
        std::string protocol;
        /**
         * The host path
         */
        std::string hostPath;
        /**
         * Single character. 2 for two tier. 4 for four tier.  This is to support the VIS legacy
         * ITK
         */
        std::string serverMode;
        /**
         * If client uses Single Sign On(SSO) to connect to server, then this should be set
         * to true. Otherwise, false
         */
        bool useTccs;
        /**
         * If client uses SSO to connect to server, then this should be set to true. Otherwise,
         * false
         */
        bool useSso;
        /**
         * Teamcenter client communication system (TCCS) environment name
         */
        std::string tccsEnvironment;
        /**
         * SSO information
         */
        Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition::SsoInfo ssoInfo;
        /**
         * This is the map of additional information in the form of key value pair strings
         */
        KeyValueMap additionalInfo;
    };

    /**
     * Session information.
     */
    struct SessionInfo
    {
        /**
         * Client Server session discriminator to connect existing specified session.
         */
        std::string descriminator;
        /**
         * This is the map of additional information in the form of key value pair strings.
         */
        KeyValueMap additionalInfo;
    };

    /**
     * User application information.
     */
    struct UserAgentDataInfo
    {
        /**
         * Client who initiates the VVI launch. The VVI file contains the information necessary
         * for the stand alone viewer to open the file.
         */
        std::string userApplication;
        /**
         * Version of the client.
         */
        std::string userAppVersion;
        /**
         * This is the map of additional information in the form of key value pair strings.
         */
        KeyValueMap additionalInfo;
    };




    /**
     * The Application Launcher (AppLauncher) uses a launch definition XML as input to launch
     * appropriate external applications. This operation gathers the data and builds the
     * launch definition XML string. It contains information for list of supported tools,
     * business data and tool preferences. The definition XML is based on the list of <code>LDSelectedInputInfo</code>
     * structure ( contains <b>WorkspaceObject</b>, related <b>Item</b>, related <b>ItemRevision</b>,
     * related control <b>WorkspaceObject</b> business object, request mode and additional
     * information in the form of key value pair strings), structure of server information
     * <code>ServerInfo</code> where the operation is initiated, structure of the session
     * information <code>SessionInfo</code> of the client from where the operation is initiated,
     * and structure of client information <code>UserAgentDataInfo</code> from where the
     * operation is initiated.
     * <br>
     * The required input data from the <code>LDSelectedInputInfo</code> structure is the
     * <b>WorkspaceObject</b> business object (normally this input is the subtype of <b>WorkspaceObject</b>
     * business object such as <b>Item</b> business object or <b>ItemRevision</b> business
     * object or <b>Dataset</b> business object).&nbsp;&nbsp;&nbsp;&nbsp;The input structures
     * for server, session, and client information can be empty.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case1:  <b>View/Markup action from client</b>
     * <br>
     * When a user selects an <b>Item</b> or an <b>ItemRevision</b> or a <b>Dataset</b>
     * and performs View/Markup action in the client, the system will invoke the <code>getLaunchDefinition</code>
     * operation.
     * <br>
     * Use case2:  <b>Office client open</b>
     * <br>
     * When a user performs open action on an MSWord <b>Dataset</b> and the client is configured
     * to use AppLauncher for open, the system will invoke the <code>getLaunchDefinition</code>
     * operation.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param operation
     *        Operation keys such as View/Markup, OfficeOpen
     *
     * @param selectedInputs
     *        The input list of structures of  <b>Item</b>/<b>ItemRevision</b>/<b>Dataset</b>/Control
     *        Object. Gathering the launch data and building launch definition XML are based on
     *        it
     *
     * @param serverInfo
     *        The server information where the operation is inititated.  This structure can be
     *        empty
     *
     * @param sessionInfo
     *        The current session information where the operation is initiated.  This structure
     *        can be empty
     *
     * @param userAgentData
     *        The client information from where the operation is initiated.  This structure can
     *        be empty
     *
     * @return
     *         the launch definition XML string and service data.
     *         <br>
     *         Following are some possible errors return in the <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">262010&nbsp;&nbsp;&nbsp;&nbsp;The XMLDocument for launch definition
     *         could not be created
     *         </li>
     *         <li type="disc">262012&nbsp;&nbsp;&nbsp;&nbsp;No tool was found. The launch definition
     *         cannot be built without a tool.
     *         </li>
     *         <li type="disc">262013&nbsp;&nbsp;&nbsp;&nbsp;No Dataset was found for the View/Markup
     *         of Item Revision.
     *         </li>
     *         <li type="disc">262014&nbsp;&nbsp;&nbsp;&nbsp;No Dataset was found. The launch definition
     *         cannot be built without a Dataset.
     *         </li>
     *         <li type="disc">262015&nbsp;&nbsp;&nbsp;&nbsp;The Tool type name is not configured
     *         as a View/Markup capable Tool type.
     *         </li>
     *         <li type="disc">262016&nbsp;&nbsp;&nbsp;&nbsp;No Tool type is set in the TCViewMarkupApplicationPref
     *         preference.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition::LaunchDefinitionResponse getLaunchDefinition ( const std::string&  operation,
        const std::vector< Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition::LDSelectedInputInfo >& selectedInputs,
        const Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition::ServerInfo&  serverInfo,
        const Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition::SessionInfo&  sessionInfo,
        const Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition::UserAgentDataInfo&  userAgentData ) = 0;


protected:
    virtual ~Launchdefinition() {}
};
            }
        }
    }
}

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

