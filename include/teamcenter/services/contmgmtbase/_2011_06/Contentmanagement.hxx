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

#ifndef TEAMCENTER_SERVICES_CONTMGMTBASE__2011_06_CONTENTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CONTMGMTBASE__2011_06_CONTENTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/TranslationOrderRevision.hxx>
#include <teamcenter/soa/client/model/TranslatnDelvryRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/contmgmtbase/ContMgmtBase_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Contmgmtbase
        {
            namespace _2011_06
            {
                class Contentmanagement;

class TCSOACONTMGMTBASESTRONGMNGD_API Contentmanagement
{
public:

    struct BomWindowInfo;
    struct BomWindowResponse;
    struct ComposedData;
    struct ComposeInput;
    struct ComposeResponse;
    struct DecomposeInput;
    struct DecomposeOutput;
    struct DecomposeResponse;
    struct GraphicNameAndSize;
    struct ImportGraphicInput;
    struct ImportGraphicOutput;
    struct ImportGraphicResponse;
    struct LanguageTableRow;
    struct PreparePublishRequestArgs;
    struct PreparePublishResponse;
    struct PreparePublishResult;
    struct SavePublishInput;
    struct SavePublishNamedRefUploadInfo;
    struct SavePublishOutputResponse;
    struct SetBomWindowTopLineInfo;
    struct SetBomWindowTopLineResponse;
    struct TranslationDeliveryInput;
    struct TranslationDeliveryOut;
    struct TranslationDeliveryResponse;

    /**
     * boolean properties for translation delivery
     */
    typedef std::map< std::string, bool > BooleanMap;

    /**
     * The name value pairs containing the compose and decompose parameters.
     */
    typedef std::map< std::string, std::string > NameValueMap;

    /**
     * input
     */
    struct BomWindowInfo
    {
        /**
         * Unique identifier of the object.
         */
        std::string clientId;
        /**
         * Revision Rule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revisionRule;
    };

    /**
     * Response
     */
    struct BomWindowResponse
    {
        /**
         * Unique identifier that helps the client to track the object created.
         */
        std::string clientId;
        /**
         * The <b>Ctm0BOMWindow</b> object that was created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This data structure contains information about the composed data.
     */
    struct ComposedData
    {
        /**
         * Unique identifier.
         */
        std::string clientId;
        /**
         * Transient file read ticket to the compose content. The client will use the ticket
         * to download the file using FMS. Multiple files or single file will be returned as
         * a zip file.
         */
        std::string composedTransientFileReadTicket;
        /**
         * The composed meta data xml transient file read ticket. The file contains information
         * about the schema dataset, graphics dataset, compose version log transient FMS read
         * ticket, compose error log FMS read ticket, and etc.
         */
        std::string composedMetaDataReadTicket;
    };

    /**
     * Input for the compose operation
     */
    struct ComposeInput
    {
        /**
         * Unique Identifier of the object.
         */
        std::string clientId;
        /**
         * This object could be the following: <b>DC_Publication</b>, <b>DC_PublicationRevision</b>,
         * <b>DC_Topic</b>, <b>DC_TopicRevision</b>, or <b>Ctm0BOMLine</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  composableBO;
        /**
         * The revision rule that configures the publication or topic structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revisionRule;
        /**
         * The name value pairs containing the compose parameters.
         * <br>
         * Typical key value pairs:
         * <br>
         * <ul>
         * <li type="disc">language &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;English,
         * Japanese, etc
         * </li>
         * <li type="disc">styleType &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
         * defined style type name that user chooses
         * </li>
         * <li type="disc">translateVersion &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MatchTopic
         * or Latest Received
         * </li>
         * <li type="disc">composedRefVariant &nbsp;&nbsp;&nbsp;&nbsp;The defined composable
         * reference variant name that user chooses
         * </li>
         * <li type="disc">resultingFileFolder &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
         * folder path that user chooses to store the publish document
         * </li>
         * <li type="disc">resultingFileName &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
         * file name user chooses
         * </li>
         * <li type="disc">registerResult&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;true
         * or false
         * </li>
         * <li type="disc">publishToFileSystem &nbsp;&nbsp;&nbsp;&nbsp;true or false
         * </li>
         * <li type="disc">createClassName &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
         * publish document class name to create for the composed output.  For example: <b>DC_ComposedDoc</b>
         * or <b>DC_ReviewerDoc</b>.
         * </li>
         * </ul>
         */
        NameValueMap keyValueArgs;
        /**
         * Processing data variables (currently not used).
         */
        NameValueMap processingDataVars;
    };

    /**
     * Vector of compose output objects
     */
    struct ComposeResponse
    {
        /**
         * A list of composed documents.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::ComposedData > composedData;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input for the decompose operation. This holds the XML file to be decomposed and the
     * arguments in keyValueArgs that define how the XML file is decomposed. See keyValueArgs
     * for more details.
     */
    struct DecomposeInput
    {
        /**
         * Unique client identifier.
         */
        std::string clientId;
        /**
         * Transient file write ticket of the content to be decomposed.
         */
        std::string transientFileWriteTicket;
        /**
         * The name value pairs containing the decompose parameters.
         * <br>
         * <br>
         * Type: Import, Translation_receive, Save_from_edit, or ImportDitaMap
         * <br>
         * Values for Import:
         * <br>
         * <ul>
         * <li type="disc">Topic_Type: Name of the root topic type
         * </li>
         * <li type="disc">Graphic_attr_mapping: Value must match a name of a <b>DC_GraphicAttrMap</b>
         * in the DB
         * </li>
         * <li type="disc">Graphic_mode: Public_id, Import_org_name, XML_number, or Graphic_name
         * </li>
         * <li type="disc">Find_by_XML_number: True or False
         * </li>
         * <li type="disc">Overwrite_existing: True or False (only used if Find_by_XML_number
         * is True)
         * </li>
         * <li type="disc">Find_by_content: True or False
         * </li>
         * <li type="disc">Stylesheet: Name of import style sheet
         * </li>
         * </ul>
         * <br>
         * Values for Translation_receive:
         * <br>
         * <ul>
         * <li type="disc">Language_code: Value must match the isoLanguageCode of a <b>DCt_Language</b>
         * object in the DB
         * </li>
         * <li type="disc">Country_code: Value must match the isoCountryCode of a <b>DCt_Language</b>
         * object in the DB
         * </li>
         * </ul>
         * <br>
         * Values for Save_from_edit:
         * <br>
         * <ul>
         * <li type="disc">Same_translation: True or False.  If not set, assumed to be False.
         * </li>
         * <li type="disc">Item_id: Item ID of the root topic
         * </li>
         * </ul>
         * <br>
         * Values for ImportDitaMap:
         * <br>
         * <ul>
         * <li type="disc">Topic_Type: Name of the root topic type
         * </li>
         * <li type="disc">Graphic_attr_mapping: Value must match a name of a DC_GraphicAttrMap
         * in the DB
         * </li>
         * <li type="disc">Graphic_mode: Public_id, Import_org_name, XML_number, or Graphic_name
         * </li>
         * <li type="disc">Find_by_XML_number: True or False
         * </li>
         * <li type="disc">Overwrite_existing: True or False (only used if Find_by_XML_number
         * is True)
         * </li>
         * <li type="disc">Find_by_content: True or False
         * </li>
         * <li type="disc">Stylesheet: Name of import style sheet
         * </li>
         * </ul>
         */
        NameValueMap keyValueArgs;
    };

    /**
     * The DecomposeOutput struct is used to hold the data returned by the decomposeContent
     * operation.
     */
    struct DecomposeOutput
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * The root topic or publication revision of decomposed content.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  topicRevision;
    };

    /**
     * Return value for the decompose operation. It contains decompose output as well as
     * ServiceData which contains partial errors.
     */
    struct DecomposeResponse
    {
        /**
         * A vector of Decomposed Output structs.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::DecomposeOutput > descomposeOutput;
        /**
         * Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains Graphic Name, Path and Size information.
     */
    struct GraphicNameAndSize
    {
        /**
         * Graphic name and path.
         */
        std::string name;
        /**
         * Size in bytes of graphic file specified by <i>name</i>.
         */
        std::string size;
        /**
         * Transient file write ticked of the content.
         */
        std::string transientFileWriteTicket;
    };

    /**
     * Import Graphic Structure, contains: Graphic Name/Path and Size, Graphic Attribute
     * Mapping name, Graphic Usage, Graphic Class name and Language.
     */
    struct ImportGraphicInput
    {
        /**
         * Client Id
         */
        std::string clientId;
        /**
         * Name of the Graphic Attribute Mapping in the database.
         */
        std::string graphicAttrMapping;
        /**
         * List of Graphic usages, separated by comma.
         */
        std::string graphicUsages;
        /**
         * Graphic Class Name.  Either <i>Graphic</i> or <i>S1000D Graphic</i>.
         */
        std::string graphicClassName;
        /**
         * Name of the <b>DCt_Language</b> object in the database.
         */
        std::string language;
        /**
         * Path, graphic name and size of the graphic imported.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::GraphicNameAndSize > nameAndSize;
        /**
         * Define Overwrite mode.  Either <i>Skip</i>,<i> keep</i>, <i>merge</i> or <i>overwrite</i>.
         */
        std::string overwriteMode;
    };

    /**
     * Structure of Import Graphic Output.
     */
    struct ImportGraphicOutput
    {
        /**
         * Client Id
         */
        std::string clientId;
        /**
         * Error message if there was a problem.
         */
        std::string errorMessage;
    };

    /**
     * Structure of Import Graphic Response.
     */
    struct ImportGraphicResponse
    {
        /**
         * Return output response
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::ImportGraphicOutput > outPut;
        /**
         * Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This table contains the DCt_Language object and a Boolean indicating whether a review
     * is requested.
     */
    struct LanguageTableRow
    {
        /**
         * <b>DCt_Language</b> objects to be related to <b>TranslationOrder</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  languageRef;
        /**
         * Review order flag which indicates a review of the <b>TranslationOrder</b> is requested.
         * If true, the user is expected to request a review of the translation.
         */
        bool reviewOrder;
    };

    /**
     * The PreparePublishRequestArgs structure is used to capture the information required
     * to prepare the data for publishing.
     */
    struct PreparePublishRequestArgs
    {
        /**
         * A unique string supplied by the caller.
         */
        std::string clientId;
        /**
         * The publication or topic revision to be published.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * The publish tool used to publish.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  publishTool;
        /**
         * The priority of the request.  This only applies to the server side publishing request.
         * Note: This is currently not implemented.
         */
        int priority;
        /**
         * The start time to start the request.  This only applies to the server side publishing
         * request.  Note: This is currently not implemented.
         */
        Teamcenter::Soa::Common::DateTime startTime;
        /**
         * The end time at which no new requests will be created based on interval setting.
         * If request is still processing, the request WILL be completed and will not be stopped.
         * This only applies to the server-side publishing request.
         */
        Teamcenter::Soa::Common::DateTime endTime;
        /**
         * The name value pairs (string/string) that contain the publishing parameters.  The
         * following are out of the box name value pairs.  Extra name value pairs can be passed
         * in for customization if needed.
         * <br>
         * <ul>
         * <li type="disc">compVerSel: compose version selection that is a valid revision rule
         * (Any Status; No Working, Latest Working, Working; Any Status, etc)
         * </li>
         * <li type="disc">language: name of the language to be published (English US, German,
         * Japanese, etc)
         * </li>
         * <li type="disc">styleType: the defined style type name that user chooses
         * </li>
         * <li type="disc">registerResult: saves the published output back to Teamcenter to
         * either a Composed Document or Reviewer Document
         * </li>
         * <li type="disc">transVerSel: the translation version of the topic (Latest Received,
         * Match Topic, or Received)
         * </li>
         * <li type="disc">resultingFileFolder: the folder path that user chooses to store the
         * published output (for client side publishing, must be a valid path)
         * </li>
         * <li type="disc">resultingFileName: the file name user chooses (for client side publishing,
         * can be any string)
         * </li>
         * <li type="disc">publishToFileSystem: whether or not the published output will be
         * saved to a file system (true or false)
         * </li>
         * <li type="disc">ditaFilterValues: the name(s) of DITA value filter(s)
         * </li>
         * </ul>
         */
        NameValueMap keyValueArgs;
    };

    /**
     * The response structure for preparePublish method.
     */
    struct PreparePublishResponse
    {
        /**
         * The Prepare Publish Result data.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::PreparePublishResult > dataResult;
        /**
         * The SOA Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure for preparePublish result data.
     */
    struct PreparePublishResult
    {
        /**
         * A unique string supplied by the caller.
         */
        std::string clientId;
        /**
         * A flag to indicate whether or not this is client side publishing.  Acceptable values
         * are true or false.
         */
        bool clientSidePublishing;
        /**
         * The publish meta data xml transient file read ticket.  This file contains information
         * about the tool, schema dataset, stylesheet dataset and graphics dataset.  This only
         * applies to client side publishing
         */
        std::string publishMetaDataReadTicket;
        /**
         * The composed xml transient file read ticket.  The client will use the ticket to download
         * the file using FMS.  File(s) will be returned as a zip file.  This only applies to
         * client side publishing.
         */
        std::string composedFileReadTicket;
        /**
         * The Dispatcher Request objects created.  This only applies to server side publishing.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  requestCreated;
    };

    /**
     * The SavePublishInput structure contains the information needed to save the output
     * of the published as a <b>Dataset</b> in Teamcenter and relate it to the <b>DC_ComposedDocRevision</b>
     * or <b>DC_ReviewerDocRevision</b>.
     */
    struct SavePublishInput
    {
        /**
         * A unique string supplied by the caller.
         */
        std::string clientId;
        /**
         * The <b>DC_ComposedDocRevision</b> or <b>DC_ReviewerDocRevision</b> the published
         * file is to be attached to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  composedOrReviewerDocRev;
        /**
         * A vector containing the upload information.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::SavePublishNamedRefUploadInfo > uploadInfos;
    };

    /**
     * The SavePublishNamedRefUploadInfo structure for the upload information needed to
     * create or update a dataset on a Composed Document or Reviewer Document Revision.
     */
    struct SavePublishNamedRefUploadInfo
    {
        /**
         * The file name of the published output.
         */
        std::string fileName;
        /**
         * A string to indicate the format of the published output (i.e. <b>PDF_Reference</b>,
         * <b>ZIPFILE</b>, <b>Text</b>, or <b>MSWordXPart</b>) which is appended to the <b>Dataset</b>
         * name.
         */
        std::string refName;
        /**
         * The FMS file write ticket.
         */
        std::string fileWriteTicket;
        /**
         * The <b>Dataset</b> type.
         */
        std::string datasetTypeName;
    };

    /**
     * The response structure for savePublishOutput method.
     */
    struct SavePublishOutputResponse
    {
        /**
         * The SOA service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Sets the top line of the <b>Ctm0BOMWindow</b>.
     */
    struct SetBomWindowTopLineInfo
    {
        /**
         * Unique identifier of the object.
         */
        std::string clientId;
        /**
         * The <b>Ctm0BOMWindow</b> to set.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
        /**
         * The <b>DC_Publication</b> or <b>DC_Topic</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The <b>DC_PublicationRevision</b> or <b>DC_TopicRevision</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
    };

    /**
     * response
     */
    struct SetBomWindowTopLineResponse
    {
        /**
         * Unique identifier that helps the client to track the object created.
         */
        std::string clientId;
        /**
         * The top <b>Ctm0BOMLine</b>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > topLine;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input for the prepareTranslationDelivery Operation
     */
    struct TranslationDeliveryInput
    {
        /**
         * Unique identifier of the object.
         */
        std::string clientId;
        /**
         * <b>TranslationOrderRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TranslationOrderRevision>  translationOrderRev;
        /**
         * Boolean properties for translation delivery. Keys are: Include Graphics, Include
         * Supporting Data, Deliver Composed Topic, Deliver Decomposed Topic, Include Published
         * Content.
         */
        BooleanMap booleanProps;
        /**
         * A list of LanguageTableRow objects that containt the language that the document will
         * be translated into.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::LanguageTableRow > languageRow;
    };

    /**
     * Vector of output objects representing objects that were created
     */
    struct TranslationDeliveryOut
    {
        /**
         * Unique identifier.
         */
        std::string clientId;
        /**
         * The created <b>TranslatnDelvry</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TranslatnDelvryRevision>  tranlationDeliveryRev;
    };

    /**
     * Vector of output objects representing objects that were created.
     */
    struct TranslationDeliveryResponse
    {
        /**
         * A list of created objects.
         */
        std::vector< Teamcenter::Services::Contmgmtbase::_2011_06::Contentmanagement::TranslationDeliveryOut > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Contentmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/contmgmtbase/ContMgmtBase_undef.h>
#endif

