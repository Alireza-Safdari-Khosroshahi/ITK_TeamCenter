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

#ifndef TEAMCENTER_SERVICES_CONTMGMTBASE_CONTENTMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CONTMGMTBASE_CONTENTMANAGEMENTSERVICE_HXX

#include <teamcenter/services/contmgmtbase/_2011_06/Contentmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/contmgmtbase/ContMgmtBase_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Contmgmtbase
        {
            class ContentmanagementService;

/**
 * This service adds operations required by content management to perform operations
 * specific to content management.  These operations allow the user to perform some
 * of the basic functions of content management: compose, decompose, translation import/export
 * and import graphics.
 * <br>
 * These SOAs would allow a user to:
 * <br>
 * <ul>
 * <li type="disc">Import a set of graphics.
 * </li>
 * <li type="disc">Import an XML document that references these graphics
 * </li>
 * <li type="disc">Compose the XML document for editing
 * </li>
 * <li type="disc">Decompose the edited XML document which updates the content management
 * items in the database
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacontmgmtbasestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacontmgmtbasetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACONTMGMTBASESTRONGMNGD_API ContentmanagementService
    : public Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement
{
public:
    static ContentmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Create composed XML, and also get the Schemas/DTDs, graphics and other information.
     * During the composition, if it is determined a property needs to be mapped from the
     * topic to the content, the function uses the applicable attribute mapping object to
     * insert the topic property into the xml element or attribute.  Specific functions
     * within the xml attribute mapping are performed against the applicable attribute.
     * The xml attribute map also provides namespace prefixes that are used in the attributes
     * defined in the map.  This allows the attribute mapping to be defined with prefixes
     * that do not need to be the same as those defined for the topic itself. If the requesting
     * function uses a tool that requires processing instruction, the compose function inserts
     * the processing instruction into the content.  The format of the instruction conforms
     * to the current xml standard for processing instructions.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Open for View, Edit, or Publish</b>
     * <br>
     * This document can be used by many different functions such as, preview, edit, publish,
     * or just a snapshot in time.  These functions determine which revision rule to pass
     * to the compose function.  The resulting content, when applicable, is validated against
     * an xml schema or DTD.  Multiple DTDs and xml schemas are available in the system
     * at any time.  The compose function provides all the applicable schema files along
     * with the composed content for the function requesting the content.
     * <br>
     * <br>
     * <b>Use case 2: Export Document</b>
     * <br>
     * The user may export a document from the database.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * decomposeContent
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param input
     *        Compose input structure.
     *
     * @return
     *         A composed XML document created from the XML fragments in the <b>DC_TopicRevisions</b>
     *         that make up the entire document.  Possible partial errors are:
     *         <br>
     *         <ul>
     *         <li type="disc">CONTMGMTBASE_GENERAL_ERROR 239100: An error has occurred in the Content
     *         Management Base module
     *         </li>
     *         <li type="disc">CONTMGMTBASE_Xml_to_sgml_exception 239124: An exception was detected
     *         while converting XML to SGML
     *         </li>
     *         <li type="disc">CONTMGMTBASE_transform_error 239108: The Xalan transformer has failed
     *         to execute the procedure.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Possible partial errors are:
     *           <br>
     *           <b>CONTMGMTBASE_GENERAL_ERROR</b> 239100 An error has occurred in the Content Management
     *           Base module.
     *           <br>
     *           <b>CONTMGMTBASE_Xml_to_sgml_exception</b> 239124 An exception was detected while
     *           converting XML to SGML.
     *           <br>
     *           <b>CONTMGMTBASE_transform_error</b> 239108 The Xalan transformer has failed to execute
     *           the procedure.
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::ComposeResponse composeContent ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::ComposeInput >& input ) = 0;

    /**
     * The operation creates a <b>Ctm0BOMWindow</b> used in the publication structure editor.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user wants to create a BOM window to hold a Content Management topic.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param inputs
     *        A list of BomWindowInfo structures.
     *
     * @return
     *         Returns the BomWindowResponse structure. Possible partial error is:
     *         <br>
     *         <ul>
     *         <li type="disc">CONTMGMTBASE_GENERAL_ERROR 239100: An error has occurred in the Content
     *         Management Base module
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Possible partial error is:
     *           <br>
     *           <b>CONTMGMTBASE_GENERAL_ERROR</b> 239100 An error has occurred in the Content Management
     *           Base module.
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::BomWindowResponse createBomWindow ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::BomWindowInfo >& inputs ) = 0;

    /**
     * The decompose operation breaks up the XML based on its schema into smaller XML segments.
     * The XML segments are then stored as <b>Datasets</b> that are attached to <b>DC_Topic</b>
     * or <b>DC_Publication</b> objects in Teamcenter. If an XML is decomposed for the first
     * time, for example through the import operation, then new <b>DC_Topic</b> or <b>DC_Publication</b>
     * objects are created to hold the <b>Datasets</b>. Otherwise the <b>Datasets</b> attached
     * to existing objects are updated with any new content.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Edit and Save</b>
     * <br>
     * After the user finishes editing a document created with a composeContent call, user
     * can save the changes back into Teamcenter Content Management.
     * <br>
     * To save the changes they can call decomposeContent with a keyValueArgs entry Type
     * = Save_from_edit.This will decompose the edited document, compare it with the original
     * composed document and update the database with any changes.
     * <br>
     * <b>Use case 2:  Import or receive a translation</b>
     * <br>
     * After a topic has been translated, user can import the translation in to Teamcenter
     * Content Management.
     * <br>
     * To import a translation the user can call this operation with a keyValueArgs entry
     * Type = Translation_receive.  This will add or update a translation in the entered
     * language for the Topic that was translated.
     * <br>
     * <b>Use case 3:  Import an XML Document</b>
     * <br>
     * Users can import a new Topic or Publication into Teamcenter Content Management.
     * <br>
     * To import a new Topic or Publication into the database, the user can call decomposeContent
     * with a keyValueArgs entry Type = Import.
     * <br>
     * <b>Use case 4: Import DITA map</b>
     * <br>
     * Users can import a DITA Map into Teamcenter Content Management.
     * <br>
     * To import a new DITA map into the database, the user can call decomposeContent with
     * a keyValueArgs entry Type = ImportDitaMap.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * composeContent
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param inputs
     *        A vector of DecomposeInput structs. Each item in the vector represents an XML file
     *        that will be decomposed. See DecomposeInput for more details.
     *
     * @return
     *         A list of <b>ItemRevisions</b> representing the newly created or updated root Topics
     *         or Publications for each of the xml that is decomposed is returned. The DecomposeOutput
     *         struct holds the <b>ItemRevisions</b> that are returned. The ServiceData element
     *         is used to hold the status of the operation and any errors encountered during the
     *         operation.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::DecomposeResponse decomposeContent ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::DecomposeInput >& inputs ) = 0;

    /**
     * This operation creates a <b>GraphicOption</b>, <b>DCt_GrphcTrnsltn</b>, <b>Graphic</b>
     * and Image <b>Dataset</b> for the input image so the user can use these to reference
     * graphics in xml content in Teamcenter Content Management.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user can import images to be used by Teamcenter Content Management.  This operation
     * will import an image, create a <b>GraphicOption</b>, a <b>DCt_GrphcTrnsltn</b> and
     * a <b>Graphic</b> for the image.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param inputs
     *        A vector of ImportGraphicInput structs.
     *
     * @return
     *         An ImportGraphicResponse object holding a list of ImportGraphicOutput objects containing
     *         any status or error messages from the operation along with a ServiceData object is
     *         returned.
     *
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::ImportGraphicResponse importGraphicOption ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::ImportGraphicInput >& inputs ) = 0;

    /**
     * For client side publishing, this operation prepares data for publishing.  The client
     * is required to download the returned file (zip file includes the composed XML, schemas,
     * style sheet, and\or graphics) and then invoke the publishing tool.   For server side
     * publishing, a Dispatcher Request will be created to publish the data.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Users can use the preparePublish operation to create their own client side publishing.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param inputs
     *        A vector of PreparePublishRequestArgs containing the publish input information.
     *
     * @return
     *         <code>PreparePublishResponse</code> structure that includes a vector of <code>PreparePublishResult</code>
     *         objects and a <code>ServiceData</code> element. The <code>PreparePublishResult</code>
     *         contains a file ticket that is used by the client to download a zip file that includes
     *         the composed XML, schemas, style sheet, and\or graphics if called using client side
     *         publish. Any failure will be returned with the client id mapped to an error message
     *         in the ServiceData list. Possible partial errors are:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">239100: An error has occurred in the Content Management Base module
     *         </li>
     *         <li type="disc">239124: An exception was detected while converting XML to SGML
     *         </li>
     *         <li type="disc">239108: The Xalan transformer has failed to execute the procedure
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::PreparePublishResponse preparePublish ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::PreparePublishRequestArgs >& inputs ) = 0;

    /**
     * Perform operations specific to preparing translations for delivery.  Allows a user
     * to create a <b>TranslatnDelvry</b> and relate it to <b>TranslationOrder</b>.  Creates
     * the <b>DCt_Translation</b> object and relate to <b>DC_TopicRevision</b> or <b>DC_PublicationRevision</b>.
     * If multiple languages are chosen, then multiple translations are generated, each
     * with a one to one relation with a <b>DC_TopicRevision</b> or <b>DC_PublicationRevision</b>.
     * A folder structure is created to save the composed and decomposed xml files for
     * each language.  Zip the folder structure and save as <b>Dataset</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user wants to setup a topic and it's children to be translated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param input
     *        A list of Translation Delivery input structures.
     *
     * @return
     *         Vector of output objects representing objects that were created. Possible partial
     *         errors are:
     *         <br>
     *         <ul>
     *         <li type="disc">CONTMGMTBASE_GENERAL_ERROR 239100: An error has occurred in the Content
     *         Management Base module
     *         </li>
     *         <li type="disc">CONTMGMTBASE_UnableToFindTranslationObject 239140: Unable to find
     *         the translation object
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::TranslationDeliveryResponse prepareTranslationDelivery ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::TranslationDeliveryInput >& input ) = 0;

    /**
     * This operation saves the published output to Teamcenter as a <b>Dataset</b> attached
     * to either a <b>DC_ComposedDocRevision</b> or a <b>DC_ReviewerDocRevision</b>.  The
     * published output file must be uploaded to Teamcenter volume first in order to obtain
     * the FMS write ticket for the input for this operation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Users can use the savePublishOutput operation to save their own published files to
     * Teamcenter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param inputs
     *        A vector of SavedPublishInput containing the input information.
     *
     * @return
     *         The return is <code>SavePublishOutputResponse</code> structure to indicate failures
     *         when saving the published dataset. Any failures will be returned with the client
     *         id mapped to an error message in the <code>ServiceData</code> list. Any failures
     *         will be returned with the client id mapped to an error message in the <code>ServiceData</code>
     *         list. Possible partial errors are:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">239100: An error has occurred in the Content Management Base module
     *         </li>
     *         <li type="disc">239124: An exception was detected while converting XML to SGML
     *         </li>
     *         <li type="disc">239108: The Xalan transformer has failed to execute the procedure
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::SavePublishOutputResponse savePublishOutput ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::SavePublishInput >& inputs ) = 0;

    /**
     * This operation creates a <b>Ctm0BOMLine</b> and set the top line of the <b>Ctm0BOMWindow</b>
     * to the newly created <b>Ctm0BOMLine</b>. It is used by the publication structure
     * editor.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user wants to populate the window created with createBomWindow with a topic.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Content Management - New Content Management module that provides the capability to
     * create/reuse/manage compound documents based on SGML/XML in Tc.
     *
     * @param inputs
     *        SetBomWindowTopLineInfo structure
     *
     * @return
     *         Returns the SetBomWindowTopLineResponse structure. Possible partial error is:
     *         <br>
     *         <ul>
     *         <li type="disc">CONTMGMTBASE_GENERAL_ERROR 239100: An error has occurred in the Content
     *         Management Base module
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Possible partial error is:
     *           <br>
     *           <b>CONTMGMTBASE_GENERAL_ERROR</b> 239100 An error has occurred in the Content Management
     *           Base module.
     */
    virtual Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::SetBomWindowTopLineResponse setBomWindowTopLine ( const std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::SetBomWindowTopLineInfo >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ContentmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/contmgmtbase/ContMgmtBase_undef.h>
#endif

