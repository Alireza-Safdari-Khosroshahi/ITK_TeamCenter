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

#ifndef TEAMCENTER_SERVICES_CAE_SIMULATIONPROCESSMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CAE_SIMULATIONPROCESSMANAGEMENTSERVICE_HXX

#include <teamcenter/services/cae/_2009_10/Simulationprocessmanagement.hxx>
#include <teamcenter/services/cae/_2011_06/Simulationprocessmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/cae/Cae_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cae
        {
            class SimulationprocessmanagementService;

/**
 * The <i>SimulationProcessManagement</i> service provides operations for launching
 * simulation tools that can include preprocessors, solvers, postprocessors, and other
 * tools to perform custom actions. It is pre-requisite that the <b>Simulation Administrator</b>
 * or user with <b>DBA</b> privileges must configure the simulation tool and store it
 * in <i>XML</i> format as a named reference with the <b>Dataset</b> name specified
 * in the preference <i>CAE_simulation_tool_config_dsname</i>.
 * <br>
 * The <i>SimulationProcessManagement</i> service provides following operations:
 * <br>
 * <ul>
 * <li type="disc"><b>Launching pre-configured simulation tool</b>
 * </li>
 * </ul>
 * <br>
 * The <i>launchSimulationTool</i> operation will launch the simulation tool as per
 * the pre-defined configuration on the given input <b>ItemRevision</b> objects. The
 * configuration contains details about the tool launch type (local or remote), rules
 * to navigate from the primary input object to the output object through a combination
 * of relationships, output objects (<b>ItemRevision</b> and <b>Dataset</b>) creation
 * settings, and naming pattern for each of the output objects (<b>Item</b>, <b>ItemRevision</b>,
 * or <b>Dataset</b>) that are created during the tool launch. Temporary files that
 * are created during simulation tool launch will be stored in the specified output
 * directory.
 * <br>
 * <ul>
 * <li type="disc"><b>Importing simulation tool launch output data in Teamcenter</b>
 * </li>
 * </ul>
 * <br>
 * The <i>importSimulationObjects</i> operation is an internal operation to import the
 * output files generated from the execution of simulation tool launch process into
 * Teamcenter objects (<b>Item</b>, <b>ItemRevision</b>, and <b>Dataset</b>). The output
 * files will be picked from the specified output directory and based on the pre-configured
 * output rules and <b>ItemRevision</b> and <b>Dataset</b> creation settings; they will
 * be imported as Teamcenter objects.
 * <br>
 * <ul>
 * <li type="disc"><b>Notifying the pre-configured users by sending e-mail notifications
 * after execution of simulation tool launch</b>
 * </li>
 * </ul>
 * <br>
 * The <i>notifyUser</i> operation is an internal operation to notify the users and
 * groups specified in the simulation tool configuration after execution of simulation
 * tool launch by sending e-mail notifications. The notification will contain the details
 * of the launch relative to its success or failure and will also contain information
 * about the newly created objects if any.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacaestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacaetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACAESTRONGMNGD_API SimulationprocessmanagementService
    : public Teamcenter::Services::Cae::_2009_10::Simulationprocessmanagement,
             public Teamcenter::Services::Cae::_2011_06::Simulationprocessmanagement
{
public:
    static SimulationprocessmanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation will launch the simulation tool as per the pre-defined configuration.
     * The configuration contains details about the tool launch type, export and import
     * rules for the files, notification, and cleanup. The inputs to the operation will
     * be an array of <i>InputObjectStructure</i>, each containing one or more <b>ItemRevision</b>
     * objects, name of the tool to be launched and the launch type. The launch type could
     * be "<i>LOCAL</i>" or "<i>REMOTE</i>". Based on the input values of parameters <i>itemCreationOption</i>
     * and <i>datasetCreationOption</i>, <b>ItemRevision</b> and <b>Dataset</b> objects
     * will be created or modified.
     * <br>
     * <br>
     * It is pre-requisite that the <b>Simulation Administrator</b> or user with <b>DBA</b>
     * privileges must configure the simulation tool and store it in <i>XML</i> format as
     * a named reference with the <b>Dataset</b> name specified in the preference <i>CAE_simulation_tool_config_dsname</i>.
     * <br>
     * <br>
     * To use this operation, the user should have either a <b>simulation_author</b> or
     * <b>rtt_author</b> license.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case 1: Launch Simulation Tool with "As_Needed" Item Creation Option</b>
     * <br>
     * When this operation is executed with <b>Item</b> creation setting "<i>As_Needed</i>",
     * no new Teamcenter <b>Item</b> will be created if there exists one as per the process
     * output configuration. If found none, new <b>Item</b> will be created as per the process
     * output configuration.
     * <br>
     * <br>
     * <b>Use Case 2: Launch Simulation Tool with "Always" Item Creation Option</b>
     * <br>
     * When this operation is executed with <b>Item</b> creation setting "<i>Always</i>",
     * new Teamcenter <b>Item</b> objects will be created as per the process output configuration.
     * <br>
     * <br>
     * <b>Use Case 3: Launch Simulation Tool with "Never" Item Creation Option</b>
     * <br>
     * When this operation is executed with <b>Item</b> creation setting "<i>Never</i>"
     * and if no existing <b>Item</b> is found as per the process output configuration,
     * no new Teamcenter <b>Item</b> objects will be created.
     * <br>
     * <br>
     * <b>Use Case 4: Launch Simulation Tool with "As_Needed" Dataset Creation Option</b>
     * <br>
     * When this operation is executed with <b>Dataset</b> creation setting "<i>As Needed</i>",
     * no new Teamcenter <b>Dataset</b> will be created if there exists one as per the process
     * output configuration. If found none, new <b>Dataset</b> will be created as per the
     * process output configuration.
     * <br>
     * <br>
     * <b>Use Case 5: Launch Simulation Tool with "Always" Dataset Creation Option</b>
     * <br>
     * When this operation is executed with <b>Dataset</b> creation setting "<i>Always</i>",
     * new Teamcenter <b>Dataset</b> objects will be created as per the process output configuration.
     * <br>
     * <br>
     * <b>Use Case 6: Launch Simulation Tool with "Never" Dataset Creation Option</b>
     * <br>
     * When this operation is executed with <b>Dataset</b> creation setting "<i>Never</i>"
     * and if no existing <b>Dataset</b> is found as per the process output configuration,
     * no new Teamcenter <b>Dataset</b> objects will be created.
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
     * @param itemCreationOption
     *        Specifies <b>Item</b> creation option. It can be either "<i>As Needed</i>", "<i>Always</i>"
     *        or "<i>Never</i>". This parameter is optional. If no value is provided, default Item
     *        creation setting in the process configuration will be used.
     *
     * @param datasetCreationOption
     *        Specifies <b>Dataset</b> creation option. It can be either "<i>As Needed</i>", "<i>Always</i>"
     *        or "<i>Never</i>". This parameter is optional. If no value is provided, default <b>Dataset</b>
     *        creation setting in the process configuration will be used.
     *
     * @param plmxmlExportFileName
     *        Name of the <i>PLMXML</i> file to be exported the simulation tool launch framework.
     *        This is optional. If no value is provided, file name specified in the process configuration
     *        will be used.
     *
     * @param workingDirectory
     *        The directory where the current job runs and generates the output files.
     *
     * @param runtimeArguments
     *        List of runtime arguments and their values. The argument and values are represented
     *        by a single string separated by token "::" Example: To pass -fem -dat=blk as an argument,
     *        the user should pass [fem::, dat::blk] as a string vector. This is optional.
     *
     * @return
     *         Returns <b>true</b> is the tool is successfully launched, else returns <b>false</b>.
     *
     */
    virtual bool launchSimulationTool ( const std::vector< Teamcenter::Services::Cae::_2009_10::Simulationprocessmanagement::InputObjectsStructure >& inputObjects,
        const std::string&  toolName,
        const std::string&  launchType,
        const std::string&  itemCreationOption,
        const std::string&  datasetCreationOption,
        const std::string&  plmxmlExportFileName,
        const std::string&  workingDirectory,
        const std::vector< std::string >& runtimeArguments ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SimulationprocessmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/cae/Cae_undef.h>
#endif

