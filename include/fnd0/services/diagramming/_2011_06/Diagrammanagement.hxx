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

#ifndef FND0_SERVICES_DIAGRAMMING__2011_06_DIAGRAMMANAGEMENT_HXX
#define FND0_SERVICES_DIAGRAMMING__2011_06_DIAGRAMMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Fnd0DiagramRevision.hxx>
#include <teamcenter/soa/client/model/Fnd0DiagramTmplRevision.hxx>
#include <teamcenter/soa/client/model/Fnd0ShapeRelation.hxx>
#include <teamcenter/soa/client/model/ImanRelation.hxx>
#include <teamcenter/soa/client/model/TransferMode.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <fnd0/services/diagramming/Diagramming_exports.h>

namespace Fnd0
{
    namespace Services
    {
        namespace Diagramming
        {
            namespace _2011_06
            {
                class Diagrammanagement;

class FND0SOADIAGRAMMINGSTRONGMNGD_API Diagrammanagement
{
public:

    struct CreateDiagramInputInfo;
    struct CreateDiagramOutput;
    struct CreateDiagramResponse;
    struct CreateOrUpdateTemplateInputInfo;
    struct CreateOrUpdateTemplateOuput;
    struct CreateOrUpdateTemplateResponse;
    struct DiagramMembers;
    struct GetDiagramMembersInputInfo;
    struct GetDiagramMembersOutput;
    struct GetDiagramMembersResponse;
    struct OpenDiagramInputInfo;
    struct OpenDiagramOutput;
    struct OpenDiagramResponse;
    struct RelationsOnDiagram;
    struct SaveDiagramInputInfo;
    struct SaveDiagramOutput;
    struct SaveDiagramResponse;

    /**
     * A Map that holds the collection of object UID for the object that appears on diagram
     * as key vs the ID of the Shape that this object represent on diagram as value.
     */
    typedef std::map< std::string, int > ObjectUIDVsShapeID;

    /**
     * This  map contains the property name and its value.
     */
    typedef std::map< std::string, std::string > PropNamevsPropValueMap;

    /**
     * The parameters required to create a diagram.
     */
    struct CreateDiagramInputInfo
    {
        /**
         * Teamcenter business object for which a Visio diagram will be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedObject;
        /**
         * If true, the created Visio diagram will be opened upon creation.
         */
        bool openDiagram;
        /**
         * A map of property names and values (string/string). Valid keys are <i>Description</i>,
         * <i>Name</i>, <i>templateName</i> and <i>ID</i>.
         */
        PropNamevsPropValueMap propNamevsValueMap;
    };

    /**
     * <code>CreateDiagramOutput</code> structure represents the output parameters as a
     * result of creating a diagram.
     */
    struct CreateDiagramOutput
    {
        /**
         * A list of FMS tickets to the diagram stencils files associated with the diagram template.
         */
        std::vector< std::string > diagramTmplFileTickets;
        /**
         * The FMS ticket to the diagram's property map file associated with the diagram template.
         */
        std::string diagMappingFileTicket;
        /**
         * The newly created Diagram Revision object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DiagramRevision>  diagramRev;
        /**
         * A list of diagram members, each element holds the primary object, the shape relation
         * object, the persistent object, the type of the object and a Boolean to indicate if
         * user has manually removed this object's shape from the diagram.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::DiagramMembers > diagramMembers;
        /**
         * A list of relations on the created diagram. Each element holds the relation object,
         * the shape relation object, the primary and secondary objects of the relation, the
         * type of the relation object and a Boolean to indicate if user has manually removed
         * this object's shape from the diagram.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::RelationsOnDiagram > relationsOnDiagram;
        /**
         * The Application Domain name of the diagram.
         */
        std::string appDomain;
    };

    /**
     * <code>CreateDiagramResponse</code> structure represents the output of create diagram
     * operation.
     */
    struct CreateDiagramResponse
    {
        /**
         * A <i>list</i> of created diagrams
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateDiagramOutput > createDiagOutput;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * CreateOrUpdateTemplateInputInfo structure represents the parameters required to create
     * a diagram template.
     */
    struct CreateOrUpdateTemplateInputInfo
    {
        /**
         * If true, the Diagram Template is available for use.
         */
        bool available;
        /**
         * A list of FMS tickets to the Diagram tool specific stencils or Template files.
         */
        std::vector< std::string > tmplStencilFileTickets;
        /**
         * FMS ticket to the Property Map xml file.
         */
        std::string tmplMappingFileTicket;
        /**
         * The Transfer mode, which will be used for traversing the structure for the diagram
         * root object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  membershipRule;
        /**
         * The Relation Rule which is the list of relations between the objects shown on the
         * diagram.
         */
        std::vector< std::string > relationRule;
        /**
         * The updated template object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DiagramTmplRevision>  diagramTmplRev;
        /**
         * A map of property names and values (string/string). Valid keys are <i>Description</i>,
         * <i>Name</i>, <i>templateName</i> and <i>ID</i>.
         */
        PropNamevsPropValueMap propNamevsPropValueMap;
    };

    /**
     * <code>CreateOrUpdateTemplateOuput</code> structure represents the output parameters
     * required for creating or updating a diagram template.
     */
    struct CreateOrUpdateTemplateOuput
    {
        /**
         * The created or updated  template object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DiagramTmplRevision>  diagramTmplRev;
    };

    /**
     * <code>CreateOrUpdateTemplateResponse</code> structure represents the list of <code>CreateOrUpdateTemplateOuput</code>
     * structures as a result of creating or updating a diagram template.
     */
    struct CreateOrUpdateTemplateResponse
    {
        /**
         * A list of CreateOrUpdateTemplateOuput structures, which hold the information of created
         * templates.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::CreateOrUpdateTemplateOuput > outputs;
        /**
         * If true, the created Visio diagram will be opened on creation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>DiagramMembers</code> structure holds the details of the members shown on the
     * diagram.
     */
    struct DiagramMembers
    {
        /**
         * The primary object of the shape shown on the diagram.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * The relation object, which holds the shape information of Visio shape.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ShapeRelation>  shapeRelation;
        /**
         * The persistent object of the primary object shown on the diagram.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  persistentObject;
        /**
         * The TC type name of the object.
         */
        std::string objectTCTypeName;
        /**
         * If true, indicates that the shape was removed from the diagram by the user. Such
         * shapes can be restored.
         */
        bool isMemberOmitted;
    };

    /**
     * <code>GetDiagramMembersInputInfo</code> structure represents the parameters required
     * to get specific types of members from the diagram.
     */
    struct GetDiagramMembersInputInfo
    {
        /**
         * The membership type.
         */
        int membershipType;
        /**
         * The Diagram Revision object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DiagramRevision>  diagramRevision;
        /**
         * The Diagram Root object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedObject;
    };

    /**
     * <code>GetDiagramMembersOutput</code> structure represents the output parameters.
     */
    struct GetDiagramMembersOutput
    {
        /**
         * A list of structure which holds the primary object, the shape relation object, the
         * persistent object, the type of the object and a Boolean to indicate if user has manually
         * removed this object's shape from the diagram.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::DiagramMembers > diagramMembers;
        /**
         * A list of structure which holds the relation object, the shape relation object, the
         * primary and secondary objects of the relation, the type of the relation object and
         * a Boolean to indicate if user has manually removed this object's shape from the diagram.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::RelationsOnDiagram > relationsOnDiagram;
    };

    /**
     * <code>GetDiagramMembersResponse</code> structure represents the output of the get
     * diagram members operation.
     */
    struct GetDiagramMembersResponse
    {
        /**
         * A list of <code>GetDiagramMembersOutput</code> structures.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::GetDiagramMembersOutput > outputs;
        /**
         * ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>OpenDiagramInputInfo</code> structure represents the parameters required to
     * open a diagram.
     */
    struct OpenDiagramInputInfo
    {
        /**
         * The Teamcenter object for which a Visio diagram will be created, either a Workspace
         * object or a BOM Line.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedObject;
        /**
         * The Diagram revision object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DiagramRevision>  diagramRevision;
    };

    /**
     * OpenDiagramOutput structure represents the parameters as a result of opening a diagram.
     */
    struct OpenDiagramOutput
    {
        /**
         * A list of FMS tickets to the diagram stencils files associated with the diagram template.
         */
        std::vector< std::string > diagramTmplFileTickets;
        /**
         * FMS ticket to the diagram's property map file associated with the diagram template.
         */
        std::string diagMappingFileTicket;
        /**
         * FMS ticket to the diagram's vdx file which is stored in the transient volume.
         */
        std::string diagramFileTicket;
        /**
         * A list of structure which holds the primary object, the shape relation object, the
         * persistent object, the type of the object and a Boolean to indicate if user has manually
         * removed this object's shape from the diagram.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::DiagramMembers > diagramMembers;
        /**
         * A list of structure which holds the relation object, the shape relation object, the
         * primary and secondary objects of the relation, the type of the relation object and
         * a Boolean to indicate if user has manually removed this object's shape from the diagram.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::RelationsOnDiagram > relationsOnDiagram;
        /**
         * The map of the UIDs of all the objects and the Visio unique ids of their corresponding
         * shapes (string/string).
         */
        ObjectUIDVsShapeID objectUIDvsShapeID;
        /**
         * The Application Domain name of the diagram.
         */
        std::string appDomain;
        /**
         * The root object of the diagram.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  startObject;
    };

    /**
     * <code>OpenDiagramResponse</code> structure represents the output of the open diagram
     * operation.
     */
    struct OpenDiagramResponse
    {
        /**
         * A list of OpenDiagramOutput structures.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::OpenDiagramOutput > openDiagOutput;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>RelationsOnDiagram</code> structure holds the details of the relations shown
     * on the diagram.
     */
    struct RelationsOnDiagram
    {
        /**
         * The relation object to be shown on the diagram.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  relation;
        /**
         * The relation object, which holds the shape information of Visio shape.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ShapeRelation>  shapeRelation;
        /**
         * The primary object of the relation, required to show the relation between the members.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * The secondary object of the relation, required to show the relation between the members.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondaryObject;
        /**
         * The TC type name of the relation object.
         */
        std::string relationType;
        /**
         * If true, indicates that the relation shape was removed from the diagram by the user.
         * Such shapes can be restored.
         */
        bool isRelationMemberOmitted;
    };

    /**
     * <code>SaveDiagramInputInfo</code> structure represents the parameters required to
     * save a diagram.
     */
    struct SaveDiagramInputInfo
    {
        /**
         * FMS ticket to the diagram's .vdx file to be saved.
         */
        std::string diagFileTicket;
        /**
         * FMS ticket to the diagram's preview image to be saved.
         */
        std::string diagImageFileTicket;
        /**
         * The diagram revision object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DiagramRevision>  diagramRevision;
        /**
         * The Teamcenter business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedObject;
    };

    /**
     * <code>SaveDiagramOutput</code> structure represents the output parameters as a result
     * of saving a diagram.
     */
    struct SaveDiagramOutput
    {
        /**
         * A list of Teamcenter objects, which appear on the diagram, for which shape relations
         * are created during the saving of the diagram.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > resultObjects;
    };

    /**
     * <code>SaveDiagramResponse</code> structure represents the output of the save diagram
     * operation.
     */
    struct SaveDiagramResponse
    {
        /**
         * A list of SaveDiagramOutput structures.
         */
        std::vector< Fnd0::Services::Diagramming::_2011_06::Diagrammanagement::SaveDiagramOutput > saveDiagOutput;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Diagrammanagement() {}
};
            }
        }
    }
}

#include <fnd0/services/diagramming/Diagramming_undef.h>
#endif

