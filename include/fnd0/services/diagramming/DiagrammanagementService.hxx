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

#ifndef FND0_SERVICES_DIAGRAMMING_DIAGRAMMANAGEMENTSERVICE_HXX
#define FND0_SERVICES_DIAGRAMMING_DIAGRAMMANAGEMENTSERVICE_HXX

#include <fnd0/services/diagramming/_2011_06/Diagrammanagement.hxx>
#include <fnd0/services/diagramming/_2012_09/Diagrammanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <fnd0/services/diagramming/Diagramming_exports.h>

namespace Fnd0
{
    namespace Services
    {
        namespace Diagramming
        {
            class DiagrammanagementService;

/**
 * The DiagramManagement service provides operations to manage diagrams for Teamcenter
 * business objects (<b>WorkspaceObject</b>/ <b>ItemRevision</b>/ <b>Folder</b>/ <b>BOMLine</b>).
 * The operations in this service allow creation, saving and opening of saved diagrams.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libfnd0soadiagrammingstrongmngd.dll
 * </li>
 * <li type="disc">libfnd0soadiagrammingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class FND0SOADIAGRAMMINGSTRONGMNGD_API DiagrammanagementService
    : public Fnd0::Services::Diagramming::_2011_06::Diagrammanagement,
             public Fnd0::Services::Diagramming::_2012_09::Diagrammanagement
{
public:
    static DiagrammanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates a Visio Diagram for a Teamcenter object (<b>WorkspaceObject/
     * ItemRevision/ Folder/ BOMLine</b>) using a Diagram Template. The objects and relations
     * shown on the diagram are gathered by executing the Transfer Mode and Relation Rule
     * specified on the diagram template. Relation Rule specifies the relations to be shown
     * between the objects.
     * <br>
     * Only those objects appear on the diagram for which there is a Visio Shape in the
     * stencil and there is mapping defined between the Shape and the Teamcenter object
     * in the mapping xml file. Mapping file has details about how to define the mappings.
     * <br>
     * While creating a diagram, if user selects the "Open Diagram" option, the diagram
     * object is created on the server and all the necessary information is returned in
     * the response which is utilized to open the Visio diagram. If user does not select
     * the option, then just the diagram object is created.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can select a Teamcenter object in RAC and create a Visio diagram for the same
     * by selecting a Diagram Domain and a Diagram Template.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateTemplate, createOrUpdateTemplate
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Diagram Management - Diagram Management
     *
     * @param inputData
     *        The required information to create a diagram for the selected object.
     *
     * @return
     *         The created diagram objects are returned along with the Service data elements. If
     *         there are any issues while creating a diagram, error code 267012 is returned.
     *
     */
    virtual Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateDiagramResponse createDiagram ( const std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateDiagramInputInfo >& inputData ) = 0;

    /**
     * createOrUpdateTemplate provides the ability to either create a new diagram template
     * or modify an existing diagram template.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Diagram Management - Diagram Management
     *
     * @param inputData
     *        Input Information for createOrUpdateTemplate
     *
     * @return
     *         CreateOrUpdateTemplateResponse that contains the diagram template revision object.
     *
     * @deprecated
     *         As of Teamcenter 10, use the createOrUpdateTemplate operation from the 2012_09 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the createOrUpdateTemplate operation from the 2012_09 namespace."))
#endif
    virtual Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateOrUpdateTemplateResponse createOrUpdateTemplate ( const Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateOrUpdateTemplateInputInfo&  inputData ) = 0;

    /**
     * This operation retrieves the specific types of members of the diagram based on its
     * membership types. Following are the types of members apart from the ones that appear
     * on the diagram as a result of transfer mode traversal and relationship rules.
     * <br>
     * <ul>
     * <li type="disc">User Added - The objects which are added to the diagram by the user.
     * E.g. an Item object which is copied from Teamcenter and then pasted on to the diagram.
     * </li>
     * <li type="disc">User Omitted - The objects which are deleted by the user from the
     * diagram. E.g. user can remove an object from the diagram only. The object is removed
     * from the diagram and not from database. It can be retrieved and again shown on the
     * diagram.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * None.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Diagram Management - Diagram Management
     *
     * @param inputData
     *        holds the required information to get the specific types of diagram members.
     *
     * @return
     *         A list of objects and relations to be shown on the diagram along with the <code>ServiceData</code>
     *         is returned.
     *
     */
    virtual Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::GetDiagramMembersResponse getDiagramMembers ( const std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::GetDiagramMembersInputInfo >& inputData ) = 0;

    /**
     * This operation opens a Visio Diagram created for a Teamcenter object (<b>WorkspaceObject/
     * Item Revision/ Folder/ BOMLine</b>). The objects and relations shown on the diagram
     * are gathered by executing the Transfer Mode and Relation Rule specified on the diagram
     * template. Relation Rule specifies the relations to be shown between the objects.
     * <br>
     * Only those objects appear on the diagram for which there is a Visio Shape in the
     * stencil and there is mapping defined between the Shape and the Teamcenter object
     * in the mapping xml file. Mapping file has details about how to define the mappings.
     * <br>
     * If the contents of the root object of the diagram are changed, for instance, a BOM
     * structure changes or the contents of the folder are modified, then the diagram will
     * show only the current information. This is because every time a diagram is opened,
     * Transfer mode and Relation Rules are applied.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can select a Teamcenter object and launch the open diagram dialog which shows
     * the list of all diagrams created for that object. You can select a diagram to open.
     * A Visio diagram is opened on the RAC. The content of the diagram is decided by the
     * Transfer mode and the Relation Rule.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * saveDiagram
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Diagram Management - Diagram Management
     *
     * @param inputData
     *        holds the required information to open a diagram for the selected object.
     *
     * @return
     *         All the necessary data like FMS tickets, members and relation objects for each successfully
     *         opened diagram and a Service data element is returned. If there are any issues while
     *         opening a diagram, the <code>ServiceData</code> will return the error codes.
     *
     */
    virtual Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::OpenDiagramResponse openDiagram ( const std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::OpenDiagramInputInfo >& inputData ) = 0;

    /**
     * This operation saves Visio Diagram(s) created for a Teamcenter object (<b>WorkspaceObject/
     * Item Revision/ Folder/ BOMLine</b>). When a Visio diagram is saved, a skeleton file
     * (.vdx) is created and stored as a dataset to hold all the non Teamcenter information,
     * like notes if any. A preview image of the diagram content is also stored as an image
     * data set. These <b>Dataset</b> objects are attached to the diagram object.
     * <br>
     * For the Teamcenter business objects appearing on the diagram, <b>Fnd0ShapeRelation</b>
     * objects are created with the diagram object to hold the position information so that
     * the shapes appear in their original position and format next time the diagram is
     * opened.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can create or open an existing diagram and make changes to it. You can then save
     * the diagram.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createDiagram, openDiagram
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Diagram Management - Diagram Management
     *
     * @param inputData
     *        holds the information to save a diagram created for a Teamcenter business object.
     *
     * @return
     *         A list of saved objects is returned along with the ServiceData. Error code 267018
     *         is returned in the <code>ServiceData</code> if the saving the diagram fails.
     *
     */
    virtual Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::SaveDiagramResponse saveDiagram ( const std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::SaveDiagramInputInfo >& inputData ) = 0;

    /**
     * This operation creates a Diagram Template which is used for creating diagrams for
     * Teamcenter objects. A Diagram Template is nothing but a place holder for all the
     * necessary information for creating a diagram. It holds the Application Domain which
     * defines how Teamcenter objects will appear on the diagram, Transfer Mode used for
     * traversing the given Teamcenter object, the Relation Rule used for finding out the
     * relations between the objects to be shown on the diagram, the Stencil or Visio Template
     * which has all the required shapes and the Property Map xml file which has the corresponding
     * Teamcenter object mapping.  One can also specify if the interface shapes are to be
     * hidden on the diagram created using this template. In such case, even if there are
     * interface objects associated with the objects, they are not shown on the diagram.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1:</b>
     * <br>
     * You can create a diagram template which will be used for creating diagrams. You can
     * provide all the necessary information like the Application Domain, the Transfer mode,
     * the Relation Rule, the Stencil/template and the property map file and chose if the
     * interface shapes are not to be shown on the diagram. Once user opts to hide the shapes,
     * it cannot be modified.
     * <br>
     * <br>
     * <b>Use case 2:</b>
     * <br>
     * You can select an existing template and edit it. The Description, the Relation Rule
     * can be modified.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Diagram Management - Diagram Management
     *
     * @param inputData
     *        holds the necessary information for creating a diagram template.
     *
     * @return
     *         The created or updated Diagram Template revision object and the Service Data are
     *         returned. In case of any failures, ServiceData will return the error codes.
     *
     */
    virtual Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateOrUpdateTemplateResponse createOrUpdateTemplate ( const Fnd0::Services::Diagramming::_2012_09::Diagrammanagement::CreateOrUpdateTemplateInputInfo1&  inputData ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DiagrammanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <fnd0/services/diagramming/Diagramming_undef.h>
#endif

