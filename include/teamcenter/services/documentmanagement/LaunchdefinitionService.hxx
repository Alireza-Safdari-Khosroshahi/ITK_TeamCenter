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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_LAUNCHDEFINITIONSERVICE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_LAUNCHDEFINITIONSERVICE_HXX

#include <teamcenter/services/documentmanagement/_2010_04/Launchdefinition.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/documentmanagement/DocumentManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Documentmanagement
        {
            class LaunchdefinitionService;

/**
 * The Application Launcher (AppLauncher) uses a launch definition XML as input to launch
 * appropriate external applications. The LaunchDefinition service provides operations
 * to gather the data and build the launch definition XML string in the Teamcenter system.
 * The launch definition XML string contains information for list of supported tools,
 * business data and tool preferences.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoadocumentmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoadocumentmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API LaunchdefinitionService
    : public Teamcenter::Services::Documentmanagement::_2010_04::Launchdefinition
{
public:
    static LaunchdefinitionService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LaunchdefinitionService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

