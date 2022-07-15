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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2007_01_DOCUMENTTEMPLATE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2007_01_DOCUMENTTEMPLATE_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2007_01
            {
                class Documenttemplate;

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API Documenttemplate
{
public:

    struct FileTicket;
    struct GetTemplateInput;
    struct GetTemplateOutput;
    struct GetTemplatesResponse;

    /**
     * The FileTicket struct.
     */
    struct FileTicket
    {
        /**
         * The file name.
         */
        std::string fileName;
        /**
         * The FMS download ticket.
         */
        std::string ticket;
    };

    /**
     * This structure defines the list of search criteria used to find the appropriate DMTemplates
     * for the calling application.
     */
    struct GetTemplateInput
    {
        /**
         * The name of the calling application.
         */
        std::string application;
        /**
         * The version of the application. Optional.
         */
        std::string version;
        /**
         * An application defined type value for different templates.
         */
        std::string templateType;
        /**
         * The measurement units that the application uses.
         */
        std::string templateUnits;
        /**
         * The item Type to be created using the template files.
         */
        std::string createItemType;
        /**
         * The named reference name for the thumbnail file.
         */
        std::string nameReferenceName;
        /**
         * The relation to the thumbnail dataset.
         */
        std::string relation;
    };

    /**
     * The GetTemplateOutput struct.
     */
    struct GetTemplateOutput
    {
        /**
         * The document template revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  templateRev;
        /**
         * The document template name.
         */
        std::string templateName;
        /**
         * The thumbnail dataset associated with the template.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * The file ticket for the FMS download of the thumbnail file.
         */
        Teamcenter::Services::Documentmanagement::_2007_01::Documenttemplate::FileTicket fileTicket;
    };

    /**
     * The GetTemplateOutput struct.
     */
    struct GetTemplatesResponse
    {
        /**
         * The list of references to struct GetTemplateOutput.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2007_01::Documenttemplate::GetTemplateOutput > output;
        /**
         * The Service Data. Partial errors and failures are updated and returned through this
         * object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is intended to support applications with a Microsoft Office style
     * template system, where the user chooses to create a new document, and the application
     * presents the user with a selection of different templates to use to create the document.
     * The calling application inputs its search criteria, and getTemplates returns the
     * list of DMTemplate objects that match the criteria. The DMTemplate is a business
     * object that is used to control the template files provided during Create.
     * <br>
     * <br>
     * The search criteria are:
     * <br>
     * <ul>
     * <li type="disc">The name of the calling application. DMTemplate objects are application
     * specific.
     * </li>
     * <li type="disc">The version number of the calling application. Optional.
     * </li>
     * <li type="disc">The desired measurement type; e.g. inches or metric. Used for CAD
     * applications.
     * </li>
     * <li type="disc">The type of Item that will be created using the DMTemplate file.
     * </li>
     * <li type="disc">An application defined type value.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The operation returns a list of DMTemplate names and thumbnail images that can be
     * used by the application to present a choice to the user. Once the user selects a
     * DMTemplate to use in the creation of the new object, the application can get the
     * files for the selected DMTemplate using the expandPrimaryObjects operation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Get a list of templates for creating a new object.</b>
     * <br>
     * <br>
     * The user decides to create a new ItemRevision in a CAD application. The application
     * calls this operation and receives a list of template names and thumbnails to display
     * to the user. The user selects a template and the application retrieves the template
     * files using the expandPrimaryObjects operation. The application then creates the
     * new ItemRevision and attaches copies of the template files.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * expandPrimaryObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param input
     *        The search parameters for the application specific DMTemplate objects.
     *
     * @return
     *         A vector of GetTemplateOutput structures (which contain the DMTemplateRevision, the
     *         template name, a dataset that has the thumbnail image file, and the FileTicket structure
     *         which has the file name and file ticket for the thumbnail). Any failure will be returned
     *         with a client id and an error message in the ServiceData.
     *         <br>
     *         <br>
     *         There are no specific errors associated with this service. Any errors returned in
     *         the ServiceData come from the query operation.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2007_01::Documenttemplate::GetTemplatesResponse getTemplates ( const Teamcenter::Services::Documentmanagement::_2007_01::Documenttemplate::GetTemplateInput&  input ) = 0;


protected:
    virtual ~Documenttemplate() {}
};
            }
        }
    }
}

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

