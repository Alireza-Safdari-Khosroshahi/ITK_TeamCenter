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

#ifndef TEAMCENTER_SERVICES_IMPORTEXPORT_FILEIMPORTEXPORTSERVICE_HXX
#define TEAMCENTER_SERVICES_IMPORTEXPORT_FILEIMPORTEXPORTSERVICE_HXX

#include <teamcenter/services/importexport/_2007_06/Fileimportexport.hxx>
#include <teamcenter/services/importexport/_2008_06/Fileimportexport.hxx>
#include <teamcenter/services/importexport/_2011_06/Fileimportexport.hxx>
#include <teamcenter/services/importexport/_2012_09/Fileimportexport.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/importexport/ImportExport_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Importexport
        {
            class FileimportexportService;

/**
 * The <code>FileImportExport</code> service provides operations to import and export
 * data from/to Teamcenter.  The operation in this service allows to import word documents
 * or import of templates to Teamcenter. The operation in this service allows the export
 * of Teamcenter business objects to <b>MSWord</b>/<b>MSExcel</b>.
 * <br>
 * The FileImportExport service can be used for supporting following use cases:
 * <br>
 * <ul>
 * <li type="disc">Export Teamcenter business objects to Word using static option.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Word using Live option.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Word for Markups.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Excel using static option.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Excel using Live option.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Excel using Bulk Live option.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Excel using export for reimport
 * option.
 * </li>
 * <li type="disc">Export Teamcenter business objects to Excel using Checkout option
 * </li>
 * <li type="disc">Export Teamcenter business objects to Excel using Excel template.
 * </li>
 * <li type="disc">Import a Word document to Teamcenter.
 * </li>
 * <li type="disc">Import of SpecTemplate, ObjectTemplate and ExcelTemplate.
 * </li>
 * <li type="disc">Import a Word document using keywords.
 * </li>
 * <li type="disc">Import a Word Live document to set the properties
 * </li>
 * <li type="disc">Import a Word Live document to make structural changes.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaimportexportstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaimportexporttypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAIMPORTEXPORTSTRONGMNGD_API FileimportexportService
    : public Teamcenter::Services::Importexport::_2007_06::Fileimportexport,
             public Teamcenter::Services::Importexport::_2008_06::Fileimportexport,
             public Teamcenter::Services::Importexport::_2011_06::Fileimportexport,
             public Teamcenter::Services::Importexport::_2012_09::Fileimportexport
{
public:
    static FileimportexportService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation is used for exporting Teamcenter objects (<b>WorkspaceObject</b>)
     * to applications like <b>MSWord</b> and <b>MSExcel</b>. Teamcenter business objects
     * should already be created so that the objects can be exported to Word and Excel using
     * the service operation.
     * <br>
     * An <b>MSExcel</b> (.mhtml) or a <b>MSWord</b> (.docx) file is generated at the server
     * as a result of this operation.  The generated file will contain Teamcenter objects
     * and their properties. Depending upon the application format that is being passed
     * as input parameter, the generated file can be opened in Word or Excel.  If the application
     * format is "<code>MSWordXML</code>" then the generated document is a Word document.
     * If the application format is "<code>MSExcel</code>" then the generated sheet is
     * a static Excel spreadsheet.  If the application format is "<code>MSExcelLive</code>"
     * then the generated sheet is a Live Excel spreadsheet. "Live" sheet means that modifications
     * can be done to the data in Excel which will reflect to Teamcenter.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create Teamcenter objects in RAC and then export those objects and their
     * properties to Word or Excel. If "Live" option is selected then User can create "Live"
     * spreadsheet after export to Excel.
     * <br>
     * <br>
     * Following usecases are supported in this operation
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Export of Workspace objects to MSWord (static)
     * </li>
     * <li type="disc">Export of Teamcenter objects to MSExcel(static)
     * </li>
     * <li type="disc">Export of Teamcenter objects to MSExcel(Live) and edit the properties
     * from Excel Live sheet.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A vector of <code>ExportToApplicationInputData</code> structures containing the required
     *        information to export Teamcenter business objects to Word /Excel.
     *
     * @return
     *         A vector of <code>ExportToApplicationResponse</code> structures, one for each successfully
     *         generated file is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the generation of file then the appropriate error is added in the ServiceData and
     *         returned.
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
    virtual Teamcenter::Services::Importexport::_2007_06::Fileimportexport::ExportToApplicationResponse exportToApplication ( const std::vector< Teamcenter::Services::Importexport::_2007_06::Fileimportexport::ExportToApplicationInputData >& inputs ) = 0;

    /**
     * This operation imports the contents of the given <b>MSWord</b> document to create
     * objects of type <b>SpecElement</b>.  The <b>MSWord</b> document to be imported to
     * Teamcenter should have .docx file format. If the application format is <b>MSWordXML</b>
     * then the operation parses the given MSWord document to creates a structure of chosen
     * subtype of <b>SpecElement</b>.  The parsing of dcoument involves parsing of individual
     * paragraphs in the document. Each paragraph in the document with a Heading becomes
     * a SpecElement. After the BOM structure is created at the server, a <b>BOMWIndow</b>
     * is constructed at the server and returned returned to the caller. Objects of type
     * <b>Requirement/Paragraph</b> are created at the server after importing the document.
     * This operation supports Word documents in <b>MSOffice</b> Open XML format (.docx
     * format) only. If the application format is not set then the operation does not do
     * anything.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create an <b>MSWord</b> document and import it using this operation to create
     * a structure. Each paragraph in <b>MSWord</b> document represents a <b>Requirement/Paragraph</b>
     * in the structure. When this operation is called from Teamcenter rich client, a structure
     * is created and is opened in the Requirements Management application.  The structure
     * and indentation of the child Requirements is driven by the <b>MSWord</b> outline
     * level in the document.  Each <b>Paragraph</b> that is formatted in an outline level
     * style produces a separate <b>Requirement</b>. This file may be located in a local
     * file system folder or a network folder.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of <b>MSWord</b> files to be imported into Teamcenter.
     *
     * @return
     *         A <b>BOMWindow</b> for each imported <b>MSWord</b> document.
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;This occurs due to an error during generating
     *           transient file ticket due to a configuration issue at the server. For example, if
     *           the transient volume directory is not configured at the server then the FMS fails
     *           to import the document and subsequent file upload operation fails. In such situation
     *           a <code>ServiceException</code> is thrown.
     */
    virtual Teamcenter::Services::Importexport::_2007_06::Fileimportexport::ImportFromApplicationResponse importFromApplication ( const std::vector< Teamcenter::Services::Importexport::_2007_06::Fileimportexport::ImportFromApplicationInputData >& inputs ) = 0;

    /**
     * This operation is used for exporting Teamcenter objects (WorkspaceObject) to applications
     * like MSWord and MSExcel. Teamcenter business objects should already be created so
     * that the objects can be exported to MSWord and MSExcel using the service operation.
     * <br>
     * An Excel (.mhtml) or a Word (.docx) file or a comma separated file (.csv) file is
     * generated at the server as a result of this operation.  The generated file will contain
     * Teamcenter objects and their properties. Depending upon the application format that
     * is being passed as input parameter, the generated file can be opened in MSWord or
     * MXExcel.  If the application format is "<b>MSWordXML</b>" then the generated document
     * is a Word document.  It traverses the structure for the given SpecElement deep and
     * exports all its children to <b>MSWord</b> document. If the application format is
     * "<b>MSExcel</b>" then the generated sheet is a static Excel spreadsheet.  If the
     * application format is "<b>MSExcelLive</b>" then the generated sheet is a Live Excel
     * spreadsheet. "Live" sheet means that modifications can be done to the data will reflect
     * to Teamcenter.  If the application format is "<b>MSWordXMLLive</b>" then the generated
     * document is a Live Word document.  A "Live" Word diocument means that the any modifications
     * done in the document like changing the rich text or editing of properties will be
     * saved to Teamcenter on click of "Save" button in <b>MSWord</b>. If the application
     * format is "<b>MSExcelReimport</b>" then the generated sheet can be reimported back
     * to Teamcenter. If the application format is "<b>MSExcelLiveBulkMode</b>"then the
     * sheet is generated in "Bulk Live" mode. This mode enables the user to make all the
     * changes to the properties of objectsfrom Excel and then commit the changes to Teamcenter
     * on click of "Save to Teamcenter" button in Excel.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create Teamcenter objects in RAC and then export those objects and their
     * properties to Word or Excel. If "Live" option is selected then User can create "Live"
     * documents after export to Word/Excel.  During the export to Word/Excel, Teamcenter
     * objects are exported to Word/Excel by applying the appropriate templates. User can
     * export Teamcenter objects to Excel which can be imported back to Teamcenter. User
     * can create excel sheet in a "Bulk Live" mode so that bulk changes can be committed
     * to Teamcenter.  User can export the objects and properties to a comma separated file.
     * User can create SpecTemplate, ObjectTemplate and ExcelTemplate in Teamcenter and
     * customize these templates as per User need such as adding more properties or adding
     * formatting information to the templates.  User can associate different objectTemplate
     * for every Business object type at runtime and specify this configuration when using
     * this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A vector of <code>ExportToApplicationInputData1</code> structures containing the
     *        required information to export Teamcenter business objects to Word /Excel. The set
     *        of objects to export, the attributes to export, the application format and the template
     *        name to be used for exporting are part of the input structure.
     *
     * @return
     *         A list of transientFileReadTickets structures, one for each successfully generated
     *         file is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the generation of file then the appropriate error is added in the ServiceData and
     *         returned.
     *         <br>
     *
     *
     * @exception ServiceException
     *           Service Exception  If there is any error during generating transient file read
     *           ticket due to a configuration issue at the server, then the operation throws a service
     *           exception. Example-  If the transient volume directory is not configured at the server
     *           then the FMS fails to generate a file at the server and subsequent file download
     *           operation fails. In such situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Importexport::_2007_06::Fileimportexport::ExportToApplicationResponse exportToApplication ( const std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ExportToApplicationInputData1 >& inputs ) = 0;

    /**
     * This operation is used for retrieving all the MSWord and MSExcel templates from database.
     * An input filter can be applied to get the desired template type from database. All
     * the Word and Excel templates are of <code>Item</code> type. Depending on the input
     * filter, the Item of type <b>SpecTemplate</b> or <b>ObjectTemplate</b> or <b>ExcelTemplate</b>
     * are retrieved from the database. These templates are used by the application for
     * export purpose. If the chosen filter is of type <b>SpecTemplate</b> or <b>ObjectTemplate</b>
     * then the document to be imported is in .docx or .docm file format.  If the chosen
     * filter is of type <b>ExcelTemplate</b> then the spreadsheet to be imported is in
     * .xlsx or .xlsm file format.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can import MSWord and MSExcel templates to Teamcenter and use these templates
     * for export purpose. During this operation, items of type <b>SpecTemplate</b> or <b>ObjectTemplate</b>
     * or ExcelTemplate is created after the import operation in Teamcenter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param filter
     *        A list of structures containing the flags required to filter the <b>SpecTemplate</b>,
     *        <b>ObjectTemplate</b> and <b>ExcelTemplate</b> type of the export templates from
     *        database.
     *
     * @return
     *         A list of structure <code>GetExportTemplateResponse</code> each containing containing
     *         a list of export templates is returned.
     *         <br>
     *         There are no objects returned in the ServiceData.  If there are any errors during
     *         the import of file then the appropriate error code and the error message is added
     *         to the error stack. This error stack is part of serviceData.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Teamcenter 9, use the getExportTemplates operation from the _2011_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the getExportTemplates operation from the _2011_06 namespace."))
#endif
    virtual Teamcenter::Services::Importexport::_2008_06::Fileimportexport::GetExportTemplateResponse getExportTemplates ( const Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ExportTemplateInput&  filter ) = 0;

    /**
     * This operation is used for importing the contents of the given MSWord document (.docx)
     * to create objects of type <b>SpecElement</b>.  Based on the application format, this
     * operation can also be used to import objects of type <b>SpecTemplate</b>,<b>ObjectTemplate</b>
     * and <b>ExcelTemplate</b> in database. If the application format is "<code>MSWordXML</code>"then
     * the operation parses the given MS Word document to creates a structure of type SpecElement.
     * If the application format is "<code>MSWordSpecTemplate</code>" or "<code>MSWordObjTemplate</code>"or
     * "<code>MSExcelTemplate</code>" then the chosen template can be imported into Teamcenter.
     * If the application format is "<code>MSWordXMLLive</code>" then a "Live" document
     * can be imported to Teamcenter.  To use this application format, a "Live" document
     * should be generated from Teamcenter. If the application format is "<code>MSWordSetContent</code>"
     * then it can set the rich text of the <b>SpecElement</b>  and the properties on the
     * <b>SpecElement</b> by using the <b>SpecficationTemplate</b> and ObjectTemplate at
     * the server. If the application format is "<code>MSWordXMLOverWriteCheck</code>" then
     * the Teamcenter objects will be checked for overwrite condition at the server.
     * <br>
     * The objects of type <b>Requirement/Paragraph</b> are created at the server after
     * import of the document.  If this operation is called from Teamcenter rich client,
     * a structure is created and is opened in the <b>Requirement</b>sManagement application.
     * The structure and indentation of the child Requirement is driven by the outline
     * levels in the document.  Each <b>Paragraph</b> that is formatted in an outline level
     * style produces a separate <b>Requirement</b>. This file may be located in a local
     * file system folder or a network folder.  Import of document to Teamcenter supports
     * Word documents in MS Office Open XML format (.docx format) only. Import of templates
     * to Teamcenter supports MSWord documents in MS Office Open XML format. (.docx and
     * .docm format)
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create an <b>MSWord</b> document and import it using this operation to create
     * a structure. Each paragraph in <b>MSWord</b> document represents a Requirement/Paragraph
     * in the structure. User can import templates (<b>SpecTemplate</b>, <b>ObjectTemplate</b>
     * and <b>ExcelTemplate</b>) to Teamcenter. User can import a "Live" document generated
     * in Teamcenter and set the properties of Workspace objects. User can set the rich
     * text of the SpecElement using the embedded Word from RAC. User can prevent overwrite
     * of objects which are edited by others.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A vector of <code>ImportFromApplicationInputData1</code> containing the required
     *        information to import MSWord document to Teamcenter or import templates to Teamcenter.
     *        The transientfile ticket of the file to be imported, application format, the <b>SpecElement</b>
     *        type to be imported, the type of <b>Specification</b> and the flag to indicate live
     *        import are part of this structure.
     *
     * @return
     *         A list of <code>ImportFromApplicationResponse</code> structures, one for each successfully
     *         imported Word document or imported template is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the import of document then the appropriate error is added in the ServiceData and
     *         returned. Example if there is a error generated during import of Word document to
     *         Teamcenter then the appropriate error code and the error message is added to the
     *         error stack. This error stack is part of serviceData. If there is any error, then
     *         the import operation is aborted and appropriate error message is shown to user.
     *         <br>
     *
     *
     * @exception ServiceException
     *           Service Exception If there is any error during generating transient file ticket
     *           due to a configuration issue at the server, then the operation throws a service exception.
     *           Example - If there is any exception due FMS not configured then the file upload to
     *           server will fail and a service exception will occur.
     */
    virtual Teamcenter::Services::Importexport::_2007_06::Fileimportexport::ImportFromApplicationResponse importFromApplication ( const std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ImportFromApplicationInputData1 >& inputs ) = 0;

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

    /**
     * This operation imports a Requirement Specification document containing Requirement
     * and Paragraph objects. It creates Requirement / Paragraph objects and associated
     * data (FullText for each created Item to store the content from the document and IMAN_Specification
     * relation between FullText and each created Item). The input structure for this operation
     * contains file meta data information, type of specification elements (SpecElement)
     * to be created, application format of the MS Word document being imported, keyword
     * parsing options to be used during import, live or static import mode to be used for
     * import, option to import as new specification or under the selected BOMLine object
     * and description to be set on the Item once imported.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        The structure which holds the file meta data, format of the document, type of specification
     *        elements to be created.
     *
     * @return
     *         A list of created objects, one for each successfully imported Requirement Specification.
     *         The following partial error may be returned: 46147   Cannot add the child to the
     *         selected parent since this child type is not valid for parent type. 46180   The child
     *         cannot be added to the selected parent since the parent type is not valid for the
     *         child type.
     *
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportFromApplicationResponse1 importFromApplication ( const std::vector< Teamcenter::Services::Importexport::_2012_09::Fileimportexport::ImportFromApplicationInputData3 >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FileimportexportService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/importexport/ImportExport_undef.h>
#endif

