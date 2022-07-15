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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_DOCUMENTTEMPLATESERVICE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_DOCUMENTTEMPLATESERVICE_HXX

#include <teamcenter/services/documentmanagement/_2007_01/Documenttemplate.hxx>



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
            class DocumenttemplateService;

/**
 * This service provides operations to retrieve names and thumbnail images of available
 * DMTemplate business objects from the server for a specific application. It is intended
 * to support a Microsoft Office style template system, where after the user chooses
 * to create a new document, the user is presented with a selection of different templates
 * that are differentiated by name and thumbnail image. Once the user selects a DMTemplate,
 * the object can be created using the DMTemplate data.
 * <br>
 * <br>
 * The getTemplate operation returns a list of DMTemplate objects that match a set of
 * given search criteria. Available search criteria are application type (e.g. Microsoft
 * Word), application version (optional), unit of length (e.g. inches or metric), template
 * type, and item type.
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

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API DocumenttemplateService
    : public Teamcenter::Services::Documentmanagement::_2007_01::Documenttemplate
{
public:
    static DocumenttemplateService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DocumenttemplateService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

