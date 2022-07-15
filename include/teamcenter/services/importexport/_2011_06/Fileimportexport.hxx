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

#ifndef TEAMCENTER_SERVICES_IMPORTEXPORT__2011_06_FILEIMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_IMPORTEXPORT__2011_06_FILEIMPORTEXPORT_HXX

#include <teamcenter/services/importexport/_2008_06/Fileimportexport.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ImanRelation.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/importexport/ImportExport_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Importexport
        {
            namespace _2011_06
            {
                class Fileimportexport;

class TCSOAIMPORTEXPORTSTRONGMNGD_API Fileimportexport
{
public:

    struct DatasetInfo;
    struct ExportToApplicationInputData2;
    struct ExportToApplicationResponse1;
    struct FileMetaData;
    struct GetExportTemplateResponse1;
    struct GetTemplateInput;
    struct ImportExportOptions;
    struct ImportFromApplicationInputData2;
    struct ImportFromApplicationOutputData;
    struct ImportFromApplicationResponse1;
    struct MarkupReqInput;
    struct MarkupReqOutput;
    struct MarkupReqResponse;
    struct MarkupReqUpdateInput;
    struct MarkupReqUpdateResponse;

    /**
     * This map contains the key as clientId to the <code>MarkupReqOutput</code> structure.
     * The <code>MarkupReqOutput</code> structure contains the created Markup <b>Datatset</b>
     * and the <b>GRM</b> relation on the created markup <b>Dataset</b> and the <b>FullText</b>.
     */
    typedef std::map< std::string, MarkupReqOutput > MarkupReqOutputMap;

    /**
     * This map will hold the name value pair of input. The map stores the "ApplicationDomain"
     * as key and value of the key specific to the domain.
     */
    typedef std::map< std::string, std::string > NameValueMap;

    /**
     * This map contains information about the template type and the name of the templates.
     * Template type can be <b>SpecTemplate</b> and <b>ObjectTemplate</b>. For each template
     * type the name of the templates in the database is queried and returned to the user.
     */
    typedef std::map< std::string, std::vector< std::string > > TemplateTypeVsTemplates;

    /**
     * This structure contains the markup dataset information like name, type, tool information
     * specified by client.
     */
    struct DatasetInfo
    {
        /**
         * The tool used to open the created <b>Dataset</b>.
         */
        std::string tool;
        /**
         * The type of the <b>Dataset</b> to be created.
         */
        std::string datasetType;
        /**
         * The name of the markup <b>Dataset</b> to be created.
         */
        std::string datasetName;
        /**
         * The description of the markup <b>Dataset</b> to be created.
         */
        std::string datasetDesc;
    };

    /**
     * The ExportToApplicationInputData2 structure represents all of the data necessary
     * to export selected objects to specific application like <b>MSWord</b> and <b>MSExcel</b>.
     */
    struct ExportToApplicationInputData2
    {
        /**
         * lThe list of Teamcenter business objects to export.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToExport;
        /**
         * The list of attributes to export.
         */
        std::vector< std::string > attributesToExport;
        /**
         * The application format such as "<code>MSWordXML</code>", "<code>MSWordXMLLive</code>","<code>MSExcel</code>"
         * and "<code>MSExcelLive</code>","<code>MSExcelReimport</code>","<code>StructureOnly</code>","<code>StructureWithContents</code>","<code>MSWordXMLLiveMarkupFN</code>",
         * "<code>MSWordXMLFN</code>","<code>MSWordXMLLiveFN</code>"
         * <br>
         * <br>
         * Supported application format for this operation
         * <br>
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordXML</b> &nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Workspace objects to static <b>MSWord</b> application.
         * </li>
         * <li type="disc"><b>MSExcel</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for exporting
         * Teamcenter objects to static <b>MSExcel</b>  application.
         * </li>
         * <li type="disc"><b>CSV</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for exporting
         * Teamcenter objects in a comma separated file format used for audit purpose.
         * </li>
         * <li type="disc"><b>MSExcelLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Teamcenter objects to Live <b>MSExcel</b>  application.
         * </li>
         * <li type="disc"><b>MSExcelReimport</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for exporting Teamcenter objects to <b>MSExcel</b>  application for reimport purpose.
         * </li>
         * <li type="disc"><b>MSExcelLiveBulkMode</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for exporting Teamcenter objects to <b>MSExcel</b>  application for Bulk Live
         * mode so that user can make all the property changes and save all the changes to Teamcenter
         * on click of "Save to Teamcenter" button.
         * </li>
         * <li type="disc"><b>MSWordXMLLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting objects of type <b>WorkspaceObject</b> to Live  <b>MSWord</b> application.
         * </li>
         * <li type="disc"><b>StructureOnly</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Workspace objects to MSWord without its  contents.(only object_name property
         * value exported to MSWord)
         * </li>
         * <li type="disc"><b>StructureWithContents</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for exporting <b>WorkspaceObject</b> to <b>MSWord</b> Live and so that user
         * can modify its contents and save them back to Teamcenter.
         * </li>
         * <li type="disc"><b>MSWordXMLLiveMarkupFN</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for exporting Markups to <b>MSWord</b> Live using FindNo as sorting key.
         * </li>
         * <li type="disc"><b>MSWordXMLLiveMarkup</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for exporting Markups to <b>MSWord</b> Live.
         * </li>
         * <li type="disc"><b>MSWordXMLFN</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting <b>WorkspaceObject</b> to static <b>MSWord</b> using FindNo as sorting
         * key.
         * </li>
         * <li type="disc"><b>MSWordXMLLiveFN</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for exporting <b>WorkspaceObject</b> to Live <b>MSWord</b> application using FindNo
         * as sorting key.
         * </li>
         * </ul>
         */
        std::string applicationFormat;
        /**
         * The name of the <b>MSWord/MSExcel</b> template
         */
        std::string templateId;
        /**
         * Type of export template.
         */
        std::string templateType;
        /**
         * The runtime object template override which is association of objectTemplate for a
         * Business object type for a chosen <b>SpecTemplate</b>.
         */
        std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::TemplateOverride > objectTemplateOverride;
        /**
         * The options to be considered during the export process like "<b>CheckOutObjects</b>"
         */
        std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportExportOptions > exportOptions;
    };

    /**
     * ExportToApplicationResponse structure represents the output of export to application
     * operation.  It has information about file ticket for the exported file generated
     * at the server and the single markup file sent to the client.
     */
    struct ExportToApplicationResponse1
    {
        /**
         * The transient file read tickets for the exported file.
         */
        std::vector< std::string > transientFileReadTickets;
        /**
         * The transient file read tickets for the generated markup file during Export to Word
         * and when the application format is "<b>MSWordXMLLiveMarkup</b>" or "<b>MSWordXMLLiveMarkupFN</b>"
         * <br>
         */
        std::vector< std::string > markupXMLReadTickets;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the information about file path, The key will contain "FilePath"
     * and data will contain the physical file path of the file to be used for the purpose
     * of import/export.
     * <br>
     */
    struct FileMetaData
    {
        /**
         * Placeholder for a string called "FilePath".
         */
        std::string key;
        /**
         * Physical file path of the file for import/export to Teamcenter.
         */
        std::string data;
    };

    /**
     * This structure contains the information about the export templates that are queried
     * from database. If there is any error during the querying of export templates from
     * the database or if there is any error during the operation, then it is added as part
     * of ServiceData.
     */
    struct GetExportTemplateResponse1
    {
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The object type of template as key and a vector of template names as the value.
         * <br>
         */
        TemplateTypeVsTemplates outputTmplNames;
        /**
         * This parameter is not being used.
         */
        std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ConfiguredTemplate > configuredSpecTemplates;
        /**
         * This parameter is not being used.
         */
        std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ConfiguredTemplate > configuredObjectTemplates;
    };

    /**
     * This structure contains information about the templates to be queried from Teamcenter
     * database. It will contain additional information in the form of name-value pair to
     * store the information about the application domain.
     */
    struct GetTemplateInput
    {
        /**
         * The type of template like "<b>SpecTemplate</b>", "<b>ObjectTemplate</b>" and "<b>ExcelTemplate</b>"
         * <br>
         */
        std::string templateType;
        /**
         * The name value pair to store information about the application domain.
         */
        NameValueMap nameValueMap;
    };

    /**
     * This structure contains additional options required to pass during the Import\Export
     * operations. importOptions: This structure is used for providing the import or export
     * options depending on the mode of operation. This is key/value pair.
     * <br>
     * Following are the available options used during importing data to Teamcenter
     * <br>
     * <ul>
     * <li type="disc">UnCheckOutObjects - Performs uncheckout operation
     * </li>
     * <li type="disc">SyncTeamcenter - Synchronize Teamcenter data with document
     * </li>
     * <li type="disc">FeedbackRequired - Runs SOA in "feedback" mode, so check conflicting
     * objects
     * </li>
     * <li type="disc">SyncDocument - Synchronize document with Teamcenter
     * </li>
     * <li type="disc">ReviseAllObjects - Revise option (not used)
     * </li>
     * <li type="disc">ReviseOverwriteObjects - Revise option for "modified" objects after
     * export
     * </li>
     * <li type="disc">IgnoreCheckoutObjects - Ignore checked out objects and save remaining
     * objects.
     * </li>
     * <li type="disc">CheckInObjects - Check in objects
     * </li>
     * <li type="disc">UnCheckOutObjects - UnCheckout objects
     * </li>
     * </ul>
     * <br>
     * Following are the available options used during exporting data to Teamcenter
     * <br>
     * <ul>
     * <li type="disc">ShowTransferModeWarning - to show warning if secondary objects are
     * exported to Word Live with structure editing.
     * </li>
     * <li type="disc">CheckOutObjects - Checkout objects.
     * </li>
     * </ul>
     */
    struct ImportExportOptions
    {
        /**
         * The option name can be as below
         * <br>
         * <ul>
         * <li type="disc">UnCheckOutObjects
         * </li>
         * <li type="disc">SyncTeamcenter
         * </li>
         * <li type="disc">FeedbackRequired
         * </li>
         * <li type="disc">SyncDocument
         * </li>
         * <li type="disc">ReviseAllObjects
         * </li>
         * <li type="disc">ReviseOverwriteObjects
         * </li>
         * <li type="disc">IgnoreCheckoutObjects
         * </li>
         * <li type="disc">CheckInObjects
         * </li>
         * </ul>
         */
        std::string option;
        /**
         * The option's value can be as below
         * <br>
         * <ul>
         * <li type="disc">UnCheckOutObjects
         * </li>
         * <li type="disc">SyncTeamcenter
         * </li>
         * <li type="disc">FeedbackRequired
         * </li>
         * <li type="disc">SyncDocument
         * </li>
         * <li type="disc">ReviseAllObjects
         * </li>
         * <li type="disc">ReviseOverwriteObjects
         * </li>
         * <li type="disc">IgnoreCheckoutObjects
         * </li>
         * <li type="disc">CheckInObjects
         * </li>
         * </ul>
         */
        std::string value;
    };

    /**
     * The ImportFromApplicationInputData2 structure represents all of the data necessary
     * to import a specification into Teamcenter or import templates to Teamcenter.
     */
    struct ImportFromApplicationInputData2
    {
        /**
         * The file ticket of the. docx file to be imported into Teamcenter.
         */
        std::string transientFileWriteTicket;
        /**
         * The application format such as "<code>MSWordXML</code>","<b>MSWordXMLLive</b>", "<b>MSWordXMLOverWriteCheck</b>",
         * "<b>MSWordSpecTemplate</b>", "<b>MSWordObjTemplate</b>", "<b>MSExcelTemplate</b>"
         * and "<b>MSWordSetContent</b>"
         * <br>
         * <br>
         * Supported application formats for this operation
         * <br>
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordXML</b> &nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * importing a <b>MSWord</b> document to Teamcenter.
         * </li>
         * <li type="disc"><b>MSWordXMLLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * importing a Live <b>MSWord</b> document to
         * </li>
         * </ul>
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Teamcenter.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordXMLExisting</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for importing a  <b>MSWord</b> document and
         * </li>
         * </ul>
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;create
         * a Specification within an existing chosen Specification.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordSetContent</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for importing a  Live <b>MSWord</b> document to
         * </li>
         * </ul>
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Teamcenter.
         * This format is used by the embedded viewer to
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set
         * the rich text of <b>SpecElement</b> and to set the properties on the
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>SpecElement</b>.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordSpecTemplate</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for importing a <b>Specification</b> template to
         * </li>
         * </ul>
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Teamcenter.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordObjectTemplate</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for importing a <b>ObjectTemplate</b> to
         * </li>
         * </ul>
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Teamcenter.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordExcelTemplate</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for importing a <b>ExcelTemplate</b> to
         * </li>
         * </ul>
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Teamcenter.
         */
        std::string applicationFormat;
        /**
         * The subtype of <b>SpecElement</b> to be created.
         */
        std::string createSpecElementType;
        /**
         * The subtype of <b>Specification</b> to be created.
         */
        std::string specificationType;
        /**
         * Flag to determine static or live option. Default value is non live.
         */
        bool isLive;
        /**
         * The top <b>BOMLine</b> under which new structure gets imported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedBomLine;
        /**
         * The list of structures that contains information about the physical file path of
         * the file.
         */
        std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::FileMetaData > fileMetaDatalist;
        /**
         * The additional options that user can pass for import purpose.
         */
        std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportExportOptions > importOptions;
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with the input structure.
         */
        std::string clientId;
    };

    /**
     * The structure contains the information about the data that is passed back to the
     * client after the result of importFromApplication SOA operation. It contains the UID
     * of the <b>BOMWindow</b> after the document is imported to Teamcenter.
     */
    struct ImportFromApplicationOutputData
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * The file ticket of the transient file to be imported.
         */
        std::vector< std::string > transientFileTickets;
        /**
         * The objects like the <b>BOMWindow</b> tag if the import is successful.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > resultObjects;
    };

    /**
     * ImportFromApplicationResponse1 structure represents the output of import from application
     * operation. It contains UID of the BOMWindow created after the document is imported.
     * In case of import of templates, it contains the business object of the tenplate
     * after the import operation.
     */
    struct ImportFromApplicationResponse1
    {
        /**
         * The Service Data. It holds the error stack which contains information about any errors
         * that are generated during importFromApplication operation.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The list of structure containing the resultant objects which contains the UID of
         * the <b>BOMWindow</b> created after the document is imported.  In case of importing
         * templates, it contains the business object of the template. It also contains the
         * file ticket of the xml file containing the details about the generated errors at
         * the server during importFromApplication operation.
         */
        std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportFromApplicationOutputData > output;
    };

    /**
     * Input structure containing the Single Markup XML info and Markup dataset info to
     * be created
     */
    struct MarkupReqInput
    {
        /**
         * This is not used.
         */
        std::string clientId;
        /**
         * This is not used.
         */
        Teamcenter::Services::Importexport::_2011_06::Fileimportexport::DatasetInfo markupDataset;
        /**
         * This is not used.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  reqObj;
        /**
         * This should be always false as we do not support markup in live mode.
         * <br>
         */
        bool isLiveMarkup;
        /**
         * FMS ticket of "mrk" file.
         */
        std::vector< std::string > transientFileWriteTickets;
    };

    /**
     * This structure containing the information about the created markup <b>Dataset</b>
     * and the <b>GRM</b> relation on the created markup <b>Dataset</b> to the <b>FullText</b>.
     */
    struct MarkupReqOutput
    {
        /**
         * The created markup <b>Dataset</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  markupDatset;
        /**
         * The <b>GRM</b> relation on the created <b>Dataset</b> to the <b>FullText</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  relation;
    };

    /**
     * Structure containing markup output with created markup <b>Dataset</b> information
     * and ServiceData.
     */
    struct MarkupReqResponse
    {
        /**
         * This is not used.
         */
        MarkupReqOutputMap markupInfo;
        /**
         * Updated markup <b>Dataset</b> are added to updated object list of ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Markup dataset sent by the client that needs to be updated
     */
    struct MarkupReqUpdateInput
    {
        /**
         * Markup dataset sent by the client that needs to be updated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  markupDataset;
        /**
         * Requirement object ID which has the markups that need an update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  reqObj;
        /**
         * Flag indicating whether markup is on live or non live document
         */
        bool isLiveMarkup;
        /**
         * Contains an FMS ticket of the single XML file uploaded
         */
        std::vector< std::string > transientFileWriteTickets;
    };

    /**
     * Structure containing markup dataset update response
     */
    struct MarkupReqUpdateResponse
    {
        /**
         * Updated markup dataset will be returned in the ServiceData. Any failure will be returned
         * with error message in the ServiceData list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation creates new markups and updates existing markups in rich text content
     * of <b>SpecElement</b> objects that are exported to <b>MSWord</b> using markup option.
     * <br>
     * This operation will take information about markups in the form of mrk file. User
     * needs to have Office Client installed to create and update the markups in Word document.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can install Office Client and export <b>SpecElement</b> to <b>MSWord</b> using
     * the markup option. Office Client provides a mechainsm to create or update markups
     * in a Word document.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Import/Export - Import / export of Tc data model in a binary format that CMS uses.
     *
     * @param inputs
     *        A list of structures containing the required information to create or update markups
     *        for <b>Requirement</b> objects.
     *
     * @return
     *         Response contains created and updated markup <b>Dataset</b> information and ServiceData
     *         with partial errors.
     *
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::MarkupReqUpdateResponse updateReqMarkup ( const std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::MarkupReqUpdateInput >& inputs ) = 0;

    /**
     * This operation will take info for markup datasets to be created for the requirement
     * objects and create a markup dataset for each markup data requirement object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        Inputs containing markup dataset info to be created, requirement obj IDs, single
     *        markup xml to be uploaded
     *
     * @return
     *         Response contains created markup dataset info and service data with partial errors
     *
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::MarkupReqResponse createReqMarkup ( const std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::MarkupReqInput >& inputs ) = 0;

    /**
     * This operation is used for exporting Teamcenter objects (<b>WorkspaceObject</b>)
     * to applications like MSWord and MSExcel. Teamcenter business objects should already
     * be created so that the objects can be exported to Word and Excel using the service
     * operation.
     * <br>
     * An MSExcel (.xlsm) or a MSWord (.docx) file or a comma separated file (.csv) file
     * is generated at the server as a result of this operation.  The generated file will
     * contain Teamcenter objects and their properties. Depending upon the application format
     * that is being passed as input parameter, the generated file can be opened in MSWord
     * or MSExcel.  If the application format is "<code>CSV</code>" then a comma separated
     * file is generated at the server.  If the application format is "<code>MSWordXML</code>"
     * then the generated document is a Word document.  It traverses the structure for the
     * given SpecElement deep and exports all its children to MSWord document. If the application
     * format is "<code>MSExcel</code>" then the generated sheet is a static Excel spreadsheet.
     * If the application format is "<code>MSExcelLive</code>" then the generated sheet
     * is a Live Excel spreadsheet. "Live" sheet means that modifications can be done to
     * the data will reflect to Teamcenter.  If the application format is "<code>MSWordXMLLive</code>"
     * then the generated document is a Live Word document.  This mode provides the capability
     * of Live editing the SpecElement in the word document.  A "Live" Word document means
     * that the any modifications done in the document like changing the rich text or editing
     * of properties will be saved to Teamcenter on click of "Save"button in MSWord. If
     * the application format is "<code>MSExcelReimport</code>" then the generated sheet
     * can be reimported back to Teamcenter. If the application format is "<code>MSExcelLiveBulkMode</code>"
     * then the sheet is generated in "Bulk Live" mode. This mode enables the user to make
     * all the changes to the properties of objectsfrom Excel and then commit the changes
     * to Teamcenter on click of "Save to Teamcenter" button in Excel.  If the application
     * format is "<code>StructureOnly</code>" then the structure can be exported to Word
     * without the contents having only "object_name" property in the exported document.
     * If the application format is "<code>StructureWithContents</code>" then the structure
     * is exported to MSWord along with the contents (rich text) of each element in the
     * structure.  This mode provides the ability of live editing and structure editing
     * of SpecElements in the MSWord document. User can edit the contents or can make structural
     * changes to the exported document.  If the application format is "<code>MSWordXMLLiveMarkupFN</code>"
     * then Markups will be exported to MSWord using FindNo as sorting key.  If the application
     * format is "<code>MSWordXMLFN</code>" then a static structure can be exported to MSWord
     * using FindNo as sorting key.  If the application format is "<code>MSWordXMLLiveFN</code>"
     * then a "Live" structure can be exported to MSWord using FindNo as sorting key.  If
     * the export Option is "CheckOutObjects" then the objects can be checked out before
     * exporting to MSWord/Excel.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create Teamcenter objects in RAC and then export those objects and their
     * properties to Word or Excel. If "Live" option is selected then user can create "Live"
     * documents after export to Word/Excel.  During the export to Word/Excel, Teamcenter
     * objects are exported to Word/Excel by applying the appropriate templates. User can
     * export Teamcenter objects to Excel which can be imported back to Teamcenter. User
     * can create excel sheet in a "Bulk Live" mode so that bulk changes can be committed
     * to Teamcenter.  User can export the objects and properties to a comma separated file.
     * User can create SpecTemplate, ObjectTemplate and ExcelTemplate in Teamcenter and
     * customize these templates as per User need such as adding more properties or adding
     * formatting information to the templates.  User can associate different objectTemplate
     * for every Business object type at runtime and specify this configuration when using
     * this operation. User can export a structure to <b>MSWord</b> without exporting the
     * rich text of each SpecElement. User can export a structure for "Live" edit and structure
     * edit to MSWord.  User can export a static or a "Live" structure along with the Markups.
     * Users can checkout objects during Export to MSWord/<b>MSExcel</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of ExportToApplicationInputData2 structures containing the required information
     *        to export Teamcenter business objects to Word /Excel.  The set of objects to export,
     *        the attributes to export, the application format and the template name to be used
     *        for exporting are part of the input structure.
     *
     * @return
     *         A list of transientFileReadTickets structures, one for each successfully generated
     *         file is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the generation of file then the appropriate error is added in the ServiceData and
     *         returned. Example-If there is an error generated during export of non workspace objects
     *         to Word then the appropriate error code and the error message is added to the error
     *         stack. This error stack is part of serviceData.
     *         <br>
     *
     *
     * @exception ServiceException
     *           Service Exception If there is any error during generating transient file read
     *           ticket due to a configuration issue at the server, then the operation throws a service
     *           exception. Example- If the transient volume directory is not configured at the server
     *           then the FMS fails to generate a file at the server and subsequent file download
     *           operation fails. In such situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ExportToApplicationResponse1 exportToApplication ( const std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ExportToApplicationInputData2 >& inputs ) = 0;

    /**
     * <code>getExportTemplates</code> is responsible for getting various export templates
     * from database based on input filter. Export templates can be of type <b>SpecTemplate</b>,
     * <b>ObjectTemplate</b> or <b>ExcelTemplate</b>. Depending upon the input filter, the
     * templates of type <b>SpecTemplate</b> or <b>ObjectTemplate</b> or <b>ExcelTemplate</b>
     * are retrieved from the database. These templates can be used by the application for
     * export purpose.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create Items of type <b>SpecTemplate</b> or <b>ObjectTemplate</b> or <b>ExcelTemplate</b>
     * in Teamcenter and use this operation to get the desired template types.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param filter
     *        A list of GetTemplateInput structures containing the required information to retrieve
     *        the type of export templates to get from database.
     *
     * @return
     *         A list of structure GetExportTemplateResponse1 each containing a list of export templates
     *         is returned.
     *         <br>
     *         There are no objects returned in the ServiceData.  If there are any errors during
     *         the generation of file then the appropriate error is added in the ServiceData and
     *         returned.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::GetExportTemplateResponse1 getExportTemplates ( const std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::GetTemplateInput >& filter ) = 0;

    /**
     * This operation is used for importing the contents of the given <b>MSWord</b>  document
     * (.docx) to create objects of type <b>SpecElement</b>.  Based on the application format,
     * this operation can also be used for importing <b>SpecTemplate</b>, <b>ObjectTemplate</b>
     * and <b>ExcelTemplate</b> in database.
     * <br>
     * If the application format is "<b>MSWordXML</b>" then the operation parses the given
     * MS Word document to creates a structure of type SpecElement.
     * <br>
     * If the application format is "<b>MSWordSpecTemplate</b>" or "<b>MSWordObjTemplate</b>"
     * or <b>"MSExcelTemplate</b>" then the chosen template can be imported into Teamcenter.
     * <br>
     * If the application format is <b>"MSWordXMLLive</b>" then a "Live" document can be
     * imported to Teamcenter.  To use this application format, a "Live" document should
     * be generated from Teamcenter.
     * <br>
     * If the application format is <b>"MSWordSetContent</b>" then it can set the rich text
     * of the <b>SpecElement</b>  by applying the templates at the server.
     * <br>
     * If the application format is "<b>MSWordXMLExisting</b>" then the given MSWord document
     * is imported to Teamcenter to create a Specification within an existing chosen Specification.
     * <br>
     * If the application format is <b>"MSWordImportUsingKW</b>" then the given MSWord document
     * is imported to Teamcenter if user chooses keywords supplied by user. The keywords
     * are parsed at the server to create the appropriate SpecElement type when the keyword
     * is found.
     * <br>
     * If the application format is "<b>StructureOnly</b>" then the given MSWord Live document
     * is imported to Teamcenter without its  contents.(only object_name property value)
     * <br>
     * If the application format is <b>"StructureWithContents</b>" then the given MSWord
     * Live document is imported to Teamcenter along with its rich text contents.
     * <br>
     * If the application format is <b>"MSWordXWithFulltext</b>" then this operation can
     * be used to create new FullText with provided rich text in given <b>MSWord</b> document
     * and this <b>FullText</b> needs to be attached to selected ItemRevision. Currently
     * this gets called from Rich client in case of editing rich text for only Systems Engineering
     * revision objects,if there is no <b>FullText</b> dataset associated.to selected <b>ItemRevision</b>.
     * <br>
     * If the application format is "<b>MSWordXWithFulltext</b>"then this operation can
     * be used to create <b>FullText</b> object with input rich text in given document.
     * The created <b>FullText</b> object will be attached to selected object revision.
     * Currently this format is called from Rich client in case of editing rich text for
     * only Systems Engineering revision objects and if there is no <b>FullText</b> dataset
     * associated.to selected revision.
     * <br>
     * When Objects objects of type <b>Requirement/Paragraph</b> are created at the server
     * after importing the document.  When this operation is called from Teamcenter rich
     * client, a structure is created and is opened in the <b>Requirement</b>sManagement
     * application.  The structure and indentation of the child Requirement is driven by
     * the outline levels in the document.  Each <b>Paragraph</b> that is formatted in an
     * outline level style produces a separate <b>Requirement</b>. This file may be located
     * in a local file system folder or a network folder.  Import of document to Teamcenter
     * supports Word documents in <b>MSOffice</b> Open XML format (.docx format) only. Import
     * of templates to Teamcenter supports Word documents in <b>MSOffice</b> Open XML format.
     * (.docx and .docm format)
     * <br>
     * <br>
     * Supported application formats for this operation
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><b>StructureOnly</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
     * importing <b>MSWord</b> document to Teamcenter without its  contents.(only object_name
     * property value).
     * </li>
     * <li type="disc"><b>StructureWithContents</b> This format is used for importing <b>WorkspaceObject</b>
     * to <b>MSWord</b> Live and so that user can modify its contents and save them back
     * to Teamcenter.
     * </li>
     * <li type="disc"><b>MSWordImportUsingKW</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
     * used for importing a <b>MSWord</b> document to Teamcenter using keywords supplied
     * by user.
     * </li>
     * <li type="disc"><b>MSWordImportExistingUsingKW</b> This format is used for importing
     * a <b>MSWord</b> document to create a Specification in Teamcenter into an existing
     * Specification when keywords are supplied by user.
     * </li>
     * <li type="disc"><b>MSWordXWithFulltext</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
     * used for importing a MSWord document when user wanted to create new <b>FullText</b>
     * with provided rich text in given document and this FullText needs to be attached
     * to selected <b>ItemRevision</b>. Currently this gets called from Rich client in case
     * of editing rich text for only <b>ItemRevision</b> objects, if there is no <b>FullText</b>
     * dataset associated to selected <b>ItemRevision</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create an <b>MSWord</b> document and import it using this operation to create
     * a structure. Each paragraph in Word document represents a Requirement/Paragraph in
     * the structure. User can import templates (<b>SpecTemplate</b>, <b>ObjectTemplate</b>
     * and <b>ExcelTemplate</b>) to Teamcenter. User can import a "Live" document generated
     * in Teamcenter and set the properties of Workspace objects. User can set the rich
     * text of the SpecElement using the embedded <b>MSWord</b> from RAC. User can prevent
     * overwrite of objects which are edited by others.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of <code>ImportFromApplicationInput2</code> structures containing the required
     *        information to import MSWord document to Teamcenter or import templates to teamcenter.
     *
     * @return
     *         A vector of <code>ImportFromApplicationResponse1</code> structures, one for each
     *         successfully imported Word document or imported template is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the import of document then the appropriate error is added in the ServiceData and
     *         returned
     *         <br>
     *
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportFromApplicationResponse1 importFromApplication ( const std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportFromApplicationInputData2 >& inputs ) = 0;


protected:
    virtual ~Fileimportexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/importexport/ImportExport_undef.h>
#endif

