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

#ifndef TEAMCENTER_SERVICES_VISUALIZATION_STRUCTUREMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_VISUALIZATION_STRUCTUREMANAGEMENTSERVICE_HXX

#include <teamcenter/services/visualization/_2011_02/Structuremanagement.hxx>
#include <teamcenter/services/visualization/_2013_05/Structuremanagement.hxx>



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
            class StructuremanagementService;

/**
 * This service provides operations that abstract the complexities of BOM system structure
 * configuration from the visualization client integrations.  Launching of selected
 * occurrences from a configured structure into visualization is an example use case
 * that is enabled by these services.  Another example is storage of a visualization
 * session that records what configured structure needs to be opened in order to restore
 * the session to its previous state.
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement
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

class TCSOAVISUALIZATIONSTRONGMNGD_API StructuremanagementService
    : public Teamcenter::Services::Visualization::_2011_02::Structuremanagement,
             public Teamcenter::Services::Visualization::_2013_05::Structuremanagement
{
public:
    static StructuremanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation takes a list of <b>ConfigurationContext</b>/top line object pairs
     * and creates a <b>VisStructureContext</b> object based on that input. The user may
     * optionally supply a list of occurrences in the form of UID chains and a file reference
     * for the static PLMXML representation of the configuration. If an occurrence list
     * or a static structure file are supplied they will be set as properties on the <b>VisStructureContext</b>
     * object. The list of occurrences can be used to populate/expand any <b>BOMWindows</b>
     * that are subsequently created using the output <b>VisStructureContext</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When the user desires to create a single persistent object that records a particular
     * configuration recipe and the caller already has the component objects that make up
     * the configuration. This case might occur if the configuration elements of a <b>BOMWindow</b>
     * were captured but the <b>BOMWindow</b> was then deleted. This is often the case when
     * using the Teamcenter Thin Client.
     * <br>
     * <br>
     * <br>
     * The createVisSC operation requires input configuration objects and their top lines.
     * Therefore, these objects must have been obtained based on some previous configuration
     * scenario.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Teamcenter Visualization - Application to allow view and markup of multicad product
     * structure that has a jt representation.
     *
     * @param info
     *        This argument specifies the <b>ConfigurationContext</b>/top line object pairs used
     *        to populate  a newly created <b>VisStructureContext</b> object. It also may contain
     *        an optional list of occurrence UID chain strings and <b>IMANFile</b> reference to
     *        a PLMXML static representation of the configuration.
     *        <br>
     *
     * @return
     *         The response contains a list of <code>CreateVisSCOutput</code> structures, which
     *         contain the <b>VisStructureContext</b> object that records the configuration recipe.
     *
     */
    virtual Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCResponse createVisSC ( const std::vector< Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCInfo >& info ) = 0;

    /**
     * This operation takes a list of <b>BOMLines</b> (the occurrences list) and returns
     * the <b>VisStructureContext</b> objects representing the configuration state of the
     * <b>BOMWindow</b> (referred to as the configuration recipe). This configuration includes:
     * <br>
     * <ul>
     * <li type="disc">The occurrence UID chains for the input/selected <b>BOMLines</b>
     * up to but not including the top line.
     * </li>
     * <li type="disc">Optional <b>IMANFile</b> reference to the PLMXML static representation
     * of the <b>BOMWindow</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * This service supports both the interoperation of selected <b>BOMLines</b> from the
     * Teamcenter Rich Client to Teamcenter Visualization and also the capture/persistence
     * of the configuration recipe for a particular <b>BOMWindow</b>. The occurrence list
     * records the selected <b>BOMLines</b> at the time of interoperation and can be used
     * in later operations to populate/expand a BOMWindow with those same occurrences.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When the user desires to create a persistent object that records the configuration
     * recipe of a particular <b>BOMWindow</b>. The resulting <b>VisStructureContext</b>
     * object would assumedly be used to later reconstruct a <b>BOMWindow</b> with the same
     * configuration recipe and the recorded occurrence chains would be used to populate/expand
     * the constructed <b>BOMWindow</b> with specific <b>BOMLines</b>. For example, this
     * operation is used when sending selected <b>BOMLines</b> from the Structure Manager
     * to Teamcenter Visualization and also to capture the configuration recipe for storage
     * in Vis Sessions.
     * <br>
     * <br>
     * Visualization pruned launch use case
     * <br>
     * <ul>
     * <li type="disc">User opens a structure in Structure Manager (SM)/Multi Structure
     * Manager (MSM)/Manufacturing Process Planner (MPP), and configures it
     * </li>
     * <li type="disc">User selects some lines they want to send to visualization as a pruned
     * structure
     * </li>
     * <li type="disc">System calls createVisSCsFromBOMs to record the selected lines and
     * the configuration of the BOM to send
     * </li>
     * </ul>
     * <br>
     * <br>
     * The createVisSCsFromBOMs operation is called with input <b>BOMLines</b> from an existing
     * <b>BOMWindow</b>. Therefore, the <b>BOMWindow</b> must have already been created
     * and populated with at least a top line.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Teamcenter Visualization - Application to allow view and markup of multicad product
     * structure that has a jt representation.
     *
     * @param info
     *        The desired <b>BOMLines</b> to be included in the configuration recipe. It is expected
     *        that these <b>BOMLines</b> all come from the same <b>BOMWindow</b>. Any
     *        <br>
     *        <b>BOMLine</b> that does not come from the same <b>BOMWindow</b> as the first <b>BOMLine</b>
     *        in the list is ignored. The parent <b>BOMWindow</b> will be used to obtain the recipe
     *        information.
     *        <br>
     *
     * @return
     *         The <b>VisStructureContext</b> objects representing the configuration state of the
     *         BOMWindows to whichthe input BOMLines belong. This operation throws no errors internally.
     *         However, errors thrown from the use of other internal PLM system calls may be caught
     *         and added to the serviceData error stack.
     *         <br>
     *         <br>
     *         Return Codes:
     *         <br>
     *         <ul>
     *         <li type="disc">   134030: A failure has occurred while attempting to create the
     *         <b>VisStructureContext</b> object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCsFromBOMsResponse createVisSCsFromBOMs ( const std::vector< Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCsFromBOMsInfo >& info ) = 0;

    /**
     * This operation takes a list of <b>BOMLines</b> (the occurrences list) and returns
     * the<b> VisStructureContext</b> objects representing the configuration state of the
     * <b>BOMWindow</b> (referred to as the configuration recipe). This configuration includes:
     * <br>
     * <ul>
     * <li type="disc">The occurrence UID chains for the input/selected <b>BOMLines</b>
     * up to but not including the top line.
     * </li>
     * <li type="disc">Optional <b>IMANFile</b> reference to the PLMXML static representation
     * of the <b>BOMWindow</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * This service supports both the interoperation of selected <b>BOMLines</b> from the
     * Teamcenter Rich Client to Teamcenter Visualization and also the capture/persistence
     * of the configuration recipe for a particular <b>BOMWindow</b>. The occurrence list
     * records the selected <b>BOMLines</b> at the time of interoperation and can be used
     * in later operations to populate/expand a <b>BOMWindow</b> with those same occurrences.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When the user desires to create a persistent object that records the configuration
     * recipe of a particular <b>BOMWindow</b>. The resulting <b>VisStructureContext</b>
     * object would assumedly be used to later reconstruct a <b>BOMWindow</b> with the same
     * configuration recipe and the recorded UID occurrence chains would be used to populate/expand
     * the constructed <b>BOMWindow</b> with specific <b>BOMLines</b>. For example, this
     * operation is used when sending selected <b>BOMLines</b> from the Structure Manager
     * to Teamcenter Visualization and also to capture the configuration recipe for storage
     * in Vis Sessions.
     * <br>
     * <br>
     * Visualization pruned launch use case
     * <br>
     * <ul>
     * <li type="disc">User opens a structure in Structure Manager (SM)/Multi Structure
     * Manager (MSM)/Manufacturing Process Planner (MPP), and configures it
     * </li>
     * <li type="disc">User selects some lines they want to send to visualization as a pruned
     * structure
     * </li>
     * <li type="disc">System calls createVisSCsFromBOMs to record the selected lines and
     * the configuration of the BOM to send
     * </li>
     * </ul>
     * <br>
     * <br>
     * Visualization session save use case
     * <br>
     * <ul>
     * <li type="disc">1.&nbsp;&nbsp;&nbsp;&nbsp;User performs Visualization pruned launch
     * use case and loads occurrences into visualization
     * </li>
     * <li type="disc">2.&nbsp;&nbsp;&nbsp;&nbsp;User creates some authored visualization
     * content (e.g. snapshots, motions, etc)
     * </li>
     * <li type="disc">3.&nbsp;&nbsp;&nbsp;&nbsp;User saves session to Teamcenter
     * </li>
     * <li type="disc">4.&nbsp;&nbsp;&nbsp;&nbsp;System calls createRecipesFromBOMs operation
     * to capture the configuration and any pruning information as a <b>VisStructureContext</b>
     * object.  UID of object returned.
     * </li>
     * <li type="disc">5.&nbsp;&nbsp;&nbsp;&nbsp;System writes the <b>VisStructureContext</b>
     * object reference into the visualization session data
     * </li>
     * <li type="disc">6.&nbsp;&nbsp;&nbsp;&nbsp;System saves the visualiation session dataset
     * to Teamcenter, and relates it to the <b>VisStructureContext</b> object created by
     * the service
     * </li>
     * </ul>
     * <br>
     * <br>
     * Visualization Technical Illustration and 3D Markup save use cases
     * <br>
     * Similar to session save use case, except saving a different data type.  Uses this
     * service to create the recipe for the authored visualization data in the Teamcenter
     * data model.
     * <br>
     * <br>
     * Use Case Dependencies:
     * <br>
     * The createVisSCsFromBOMs operation is called with input <b>BOMLines</b> from an existing
     * BOM Window. Therefore, the <b>BOMWindow</b> must have already been created and populated
     * with at least a top line.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Teamcenter Visualization - Application to allow view and markup of multicad product
     * structure that has a jt representation.
     *
     * @param info
     *        The desired <b>BOMLines</b> to be included in the configurationrecipe. It is expected
     *        that these <b>BOMLines</b> all come from the same <b>BOMWindow</b>. Any  <b>BOMLine</b>
     *        that does not come from the same <b>BOMWindow</b> as the first <b>BOMLine</b> in
     *        the list is ignored. The parent <b>BOMWindow</b> will be used to obtain the recipe
     *        information.
     *        <br>
     *
     * @param options
     *        The list of desired options the caller wishes to provide to the service. This list
     *        of options is represented by a map of string option names to string option values.
     *        The key <i>IncludeChildNodes</i> may be supplied with a value of <i>true</i> or <i>false</i>.
     *        If false, indicates that if there is a provided assembly node <b>BOMLine</b> in the
     *        input then its child nodes whould not be included in any <b>BOMLine</b> expansion.
     *
     * @return
     *         The <b>VisStructureContext</b> objects representing the configuration state of the
     *         BOMWindows to whichthe input BOMLines belong. This operation throws no errors internally.
     *         However, errors thrown from the use of other internal PLM system calls may be caught
     *         and added to the serviceData error stack.
     *         <br>
     *         <br>
     *         Return Codes:
     *         <br>
     *         <ul>
     *         <li type="disc">   134030: A failure has occurred while attempting to create the
     *         <b>VisStructureContext</b> object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCsFromBOMsResponse createVisSCsFromBOMs ( const std::vector< Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCsFromBOMsInfo >& info,
        const OptionKeyToOptionValueMap&  options ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuremanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/visualization/Visualization_undef.h>
#endif

