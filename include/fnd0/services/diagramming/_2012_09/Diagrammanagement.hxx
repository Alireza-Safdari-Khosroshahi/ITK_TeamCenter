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

#ifndef FND0_SERVICES_DIAGRAMMING__2012_09_DIAGRAMMANAGEMENT_HXX
#define FND0_SERVICES_DIAGRAMMING__2012_09_DIAGRAMMANAGEMENT_HXX

#include <fnd0/services/diagramming/_2011_06/Diagrammanagement.hxx>
#include <teamcenter/soa/client/model/Fnd0DiagramTmplRevision.hxx>
#include <teamcenter/soa/client/model/TransferMode.hxx>


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
            namespace _2012_09
            {
                class Diagrammanagement;

class FND0SOADIAGRAMMINGSTRONGMNGD_API Diagrammanagement
{
public:

    struct CreateOrUpdateTemplateInputInfo1;

    /**
     * This  map contains the property name and its value for a Diagram Template
     */
    typedef std::map< std::string, std::string > DiagramTemplatePropNamevsPropValueMap;

    /**
     * CreateOrUpdateTemplateInputInfo1 structure represents the parameters required to
     * create a diagram template.
     */
    struct CreateOrUpdateTemplateInputInfo1
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
         * A map of property names and values (string/string). Valid keys are<i> Description</i>,
         * <i>Name</i>, <i>templateName</i> and <i>ID</i>.
         */
        DiagramTemplatePropNamevsPropValueMap propNamevsPropValueMap;
        /**
         * If true, the interface shapes will not be shown on the created diagram.
         */
        bool hidePorts;
    };




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


protected:
    virtual ~Diagrammanagement() {}
};
            }
        }
    }
}

#include <fnd0/services/diagramming/Diagramming_undef.h>
#endif

