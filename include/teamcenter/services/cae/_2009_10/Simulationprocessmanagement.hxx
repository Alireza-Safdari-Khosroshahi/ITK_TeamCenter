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

#ifndef TEAMCENTER_SERVICES_CAE__2009_10_SIMULATIONPROCESSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAE__2009_10_SIMULATIONPROCESSMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ItemRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cae/Cae_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cae
        {
            namespace _2009_10
            {
                class Simulationprocessmanagement;

class TCSOACAESTRONGMNGD_API Simulationprocessmanagement
{
public:

    struct InputObjectsStructure;

    /**
     * Structure containing selected input <b>ItemRevision</b> objects on which pre-configured
     * simulation tool needs to be launched.
     */
    struct InputObjectsStructure
    {
        /**
         * Array of selected <b>ItemRevision</b> objects on which pre-configured simulation
         * tool needs to be launched.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  > inputItemRevisions;
    };




    /**
     * This operation will launch the simulation tool as per the pre-defined configuration.
     * The configuration contains details about the tool launch type, export and import
     * rules for the files, notification, and cleanup. The inputs to the operation will
     * be an array of <i>InputObjectStructure</i>, each containing one or more <b>ItemRevision</b>
     * objects, name of the tool to be launched and the launch type. The launch type could
     * be <i>LOCAL</i> or <i>REMOTE</i>.
     * <br>
     * <br>
     * It is pre-requisite that the <b>Simulation Administrator</b> or user with <b>DBA</b>
     * privileges must configure the simulation tool and store it in <i>XML</i> format as
     * a named reference with the Dataset name specified in the preference <i>CAE_simulation_tool_config_dsname</i>.
     * <br>
     * <br>
     * To use this operation, the user should have either a <b>simulation_author</b> or
     * <b>rtt_author</b> license.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CAE Integrations - Provides custom extensions to the Tc data model to capture the
     * CAE data model; the services that provide behaviors that are specific to CAE clients
     * and the client side code that accesses the data model and services.
     *
     * @param inputObjects
     *        Array of <i>InputObjectsStructure</i>. Each <i>InputObjectsStructure</i> contains
     *        array of <b>ItemRevision</b> objects which are processed as inputs to the tool.
     *
     * @param toolName
     *        String denoting the simulation process including the complete inheritance hierarchy.
     *        The "::" should be used to create the string for processes having inheritance.
     *
     * @param launchType
     *        Launch type for the process. This can be either "<i>LOCAL</i>" or "<i>REMOTE</i>"
     *
     * @return
     *         Returns <b>true</b> if the tool is successfully launched, else returns <b>false</b>.
     *
     * @deprecated
     *         As of Teamcenter 9, use the launchSimulationTool operation from the _2011_06 namespace.
     *         The newer version supports additional parameters like PLMXML Export file name, Item
     *         and Dataset creation options
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the launchSimulationTool operation from the _2011_06 namespace. The newer version supports additional parameters like PLMXML Export file name, Item and Dataset creation options"))
#endif
    virtual bool launchSimulationTool ( const std::vector< Teamcenter::Services::Cae::_2009_10::Simulationprocessmanagement::InputObjectsStructure >& inputObjects,
        const std::string&  toolName,
        const std::string&  launchType ) = 0;


protected:
    virtual ~Simulationprocessmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cae/Cae_undef.h>
#endif

