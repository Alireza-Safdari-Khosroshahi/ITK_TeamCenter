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

#ifndef TEAMCENTER_SERVICES_VISUALIZATION__2011_02_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VISUALIZATION__2011_02_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/VisStructureContext.hxx>
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
                class Structuremanagement;

class TCSOAVISUALIZATIONSTRONGMNGD_API Structuremanagement
{
public:

    struct CreateVisSCInfo;
    struct CreateVisSCOutput;
    struct CreateVisSCResponse;
    struct CreateVisSCsFromBOMsInfo;
    struct CreateVisSCsFromBOMsOutput;
    struct CreateVisSCsFromBOMsResponse;

    /**
     * Input structure used for creating <b>VisStrucutreContext</b> objects based on the
     * given inputs.
     */
    struct CreateVisSCInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * A reference to an existing <b>ConfigurationContext</b> object that contains a portion
         * of the configuration to be used by the output <b>VisStructureContext</b> object.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
        /**
         * Object reference of type <b>BOMView</b> or <b>BOMViewRevision</b> that is the topline
         * of the configuration.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  topLine;
        /**
         * List of UID chain strings representing  the occurrences to be included in the structure
         * recipe. If not supplied then the output <b>VisStructureContext</b> object will not
         * have its
         * <br>
         * occurrence<b>_list</b> property set. This will be interpreted as the top line was
         * selected <b>BOMLine</b> for this configuration recipe.
         * <br>
         */
        std::vector< std::string > occurrencesList;
        /**
         * <b>IMANFile</b> reference to the PLMXML static representation of the structure, (optional).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  staticStructureFile;
    };

    /**
     * The output structure that contains the references to the created <b>VisStructureContext</b>
     * object along with the corresponding <code>clientId</code>.
     */
    struct CreateVisSCOutput
    {
        /**
         * The unique string supplied by the caller used to match the output to the supplied
         * input.
         */
        std::string clientId;
        /**
         * <b>VisStructureContext</b> object that records the configuration recipe based on
         * the input configuration objects
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VisStructureContext>  structureRecipe;
    };

    /**
     * Response structure for the <code>createVisSC</code> operation.
     */
    struct CreateVisSCResponse
    {
        /**
         * List of <code>CreateVisSCOutput</code> structures containing the <b>VisStructureContext</b>
         * objects created based on the input configuration objects.
         * <br>
         */
        std::vector< Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure used for creating <b>VisStrucutreContext</b> objects based on the
     * given <b>BOMWindows</b> and specific occurrenses within those <b>BOMWindows</b>.
     */
    struct CreateVisSCsFromBOMsInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * List of <b>BOMLines</b> representing  the occurrences to be included in the structure
         * recipe.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > occurrencesList;
        /**
         * <b>IMANFile</b> reference to the PLMXML static representation of the structure. If
         * not supplied then the associated property of the <b>VisStructureContext</b> will
         * not be set. [optional]
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  staticStructureFile;
    };

    /**
     * The output structure that contains the references to the created <b>VisStructureContext</b>
     * objects along with the corresponding <code>clientId</code>.
     */
    struct CreateVisSCsFromBOMsOutput
    {
        /**
         * The unique string supplied by the caller used to match the output to the supplied
         * input.
         */
        std::string clientId;
        /**
         * <b>VisStructureContext</b> object that records the configuration recipe of the <b>BOMWindow</b>
         * that contains the input <b>BOMLines</b>
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VisStructureContext>  structureRecipe;
    };

    /**
     * Response structure for the <code>createVisSCsFromBOMs</code> operation.
     */
    struct CreateVisSCsFromBOMsResponse
    {
        /**
         * List of <code>CreateVisSCsFromBOMsOutput</code> structures containing the <b>VisStructureContext</b>
         * object that records the configuration recipe of the <b>BOMWindow</b> from which the
         * input <b>BOMLines</b> belong.
         * <br>
         */
        std::vector< Teamcenter::Services::Visualization::_2011_02::Structuremanagement::CreateVisSCsFromBOMsOutput > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/visualization/Visualization_undef.h>
#endif

