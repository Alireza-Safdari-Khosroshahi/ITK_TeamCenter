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

#ifndef TEAMCENTER_SERVICES_IMPORTEXPORT__2008_06_FILEIMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_IMPORTEXPORT__2008_06_FILEIMPORTEXPORT_HXX

#include <teamcenter/services/importexport/_2007_06/Fileimportexport.hxx>
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
            namespace _2008_06
            {
                class Fileimportexport;

class TCSOAIMPORTEXPORTSTRONGMNGD_API Fileimportexport
{
public:

    struct ConfiguredTemplate;
    struct ExportTemplateInput;
    struct ExportToApplicationInputData1;
    struct GetExportTemplateResponse;
    struct ImportFromApplicationInputData1;
    struct TemplateOverride;

    /**
     * The <code>ConfiguredTemplate</code> structure contains the information required to
     * get IRDC configured export templates. BMIDE enables the user to configure templates
     * based on the object type using the IRDC configuration.
     */
    struct ConfiguredTemplate
    {
        /**
         * Type name of business object.
         */
        std::string businessObjectType;
        /**
         * The name of the configured template on business object type.
         */
        std::string templateName;
        /**
         * The type name of configured template.
         */
        std::string templateType;
    };

    /**
     * The ExportTemplateInput structure contains the flags that are required to filter
     * the different type of export templates such as <b>SpecTemplate</b>, <b>ObjectTemplate</b>
     * and <b>ExcelTemplate</b> from the database.
     */
    struct ExportTemplateInput
    {
        /**
         * If set to true then it will query for SpecTemplates in database.
         */
        bool getSpecTemplates;
        /**
         * If set to true then it will query for ObjectTemplates in database.
         */
        bool getObjectTemplates;
        /**
         * If set to true then it will query for ExcelTemplates in database.
         */
        bool getExcelTemplates;
        /**
         * This element is not used.
         */
        bool getConfiguredSpecTemplate;
        /**
         * This element is not used.
         */
        bool getConfiguredObjectTemplate;
    };

    /**
     * The ExportToApplicationInputData1 structure represents all of the data necessary
     * to export selected Teamcenter objects to MSWord/Excel.
     */
    struct ExportToApplicationInputData1
    {
        /**
         * The list of Teamcenter business objects to export.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToExport;
        /**
         * The list of attributes to export.
         */
        std::vector< std::string > attributesToExport;
        /**
         * The application format such as "<code>MSWordXML</code>", "<code>MSExcel</code>",
         * "<code>MSExcelLive</code>", "<code>MSExcelReimport</code>", "<code>MSWordXMLLive</code>",
         * "<code>MSExcelLiveBulkMode</code>".
         * <br>
         * <br>
         * Supported application format for this operation
         * <br>
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordXML</b> &nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Workspace objects to static MSWord application.
         * </li>
         * <li type="disc"><b>MSExcel</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for exporting
         * Teamcenter objects to static MSExcel  application.
         * </li>
         * <li type="disc"><b>MSExcelLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Teamcenter objects to Live MSExcel  application.
         * </li>
         * <li type="disc"><b>MSExcelReimport</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for exporting Teamcenter objects to MSExcel
         * </li>
         * </ul>
         * <br>
         * application for reimport purpose.
         * <br>
         * <ul>
         * <li type="disc"><b>MSExcelLiveBulkMode</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for exporting Teamcenter objects to MSExcel  application for Bulk Live mode
         * so that user can make all the property changes and save all the changes to Teamcenter
         * on click of "Save to Teamcenter"button.
         * </li>
         * <li type="disc"><b>MSWordXMLLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Workspace objects to Live MSWord application.
         * </li>
         * </ul>
         */
        std::string applicationFormat;
        /**
         * The name of the Word/Excel template
         */
        std::string templateId;
        /**
         * The type of the export template.
         */
        std::string templateType;
        /**
         * The runtime object template override which is association of objectTemplate for a
         * Business object type for a  chosen SpecTemplate.
         */
        std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::TemplateOverride > objectTemplateOverride;
    };

    /**
     * The GetExportTemplateResponse Return represents the output of getExportTemplates
     * operation which contains the information about the objects of type <b>SpecTemplate</b>,
     * <b>ObjectTemplate</b> and <b>ExcelTemplate</b> that are queried from the database.
     * Example- If the input filter flag (getSpecTemplates) is set to true in ExportTemplateInput
     * structure, then the GetExportTemplateResponse structure will contain the all the
     * objects of type <b>SpecTemplate</b>
     */
    struct GetExportTemplateResponse
    {
        /**
         * The list of objects of type <b>SpecTemplate</b>
         */
        std::vector< std::string > specTemplates;
        /**
         * The list of objects of type <b>ObjectTemplate</b>
         */
        std::vector< std::string > objectTemplats;
        /**
         * The list of objects of type <b>ExcelTemplate</b>
         */
        std::vector< std::string > excelTemplates;
        /**
         * This is not used
         */
        std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ConfiguredTemplate > configuredSpecTemplates;
        /**
         * This is not used
         */
        std::vector< Teamcenter::Services::Importexport::_2008_06::Fileimportexport::ConfiguredTemplate > configuredObjectTemplates;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The ImportFromApplicationInputData1 structure represents all of the data necessary
     * to import a specification into Teamcenter or import templates to Teamcenter.
     */
    struct ImportFromApplicationInputData1
    {
        /**
         * The file ticket of the. docx file to be imported into Teamcenter.
         */
        std::string transientFileWriteTicket;
        /**
         * The application format suchas "<code>MSWordXML</code>", "<code>MSWordXMLLive</code>",
         * "<code>MSWordXMLOverWriteCheck</code>", "<code>MSWordSpecTemplate</code>","<code>MSWordObjTemplate</code>","<code>MSExcelTemplate</code>"
         * and "<code>MSWordSetContent</code>"
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
         * importing a Live <b>MSWord</b> document to Teamcenter.
         * </li>
         * <li type="disc"><b>MSWordXMLOverwriteCheck</b>&nbsp;&nbsp;&nbsp;&nbsp;This format
         * is used for importing a  Live <b>MSWord</b> document to Teamcenter and check for
         * overwrite condition on the object during setting of properties in database.
         * </li>
         * <li type="disc"><b>MSWordSetContent</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for importing a  Live MSWord document to
         * </li>
         * </ul>
         * <br>
         * Teamcenter. This format is used by the embedded viewer to set the rich text of SpecElement
         * and to set the properties on the SpecElement.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordSpecTemplate</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used
         * for importing a SpecificationTemplate to
         * </li>
         * </ul>
         * <br>
         * Teamcenter.
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordObjectTemplate</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for importing a ObjectTemplate to Teamcenter.
         * </li>
         * <li type="disc"><b>MSWordExcelTemplate</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is
         * used for importing a ExcelTemplate to Teamcenter.
         * </li>
         * </ul>
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
         * If the flag is set to true then it indicates "live" option.
         * <br>
         * If the flag is set to false then it indicates "static" option.
         * <br>
         */
        bool isLive;
    };

    /**
     * The structure represents all of the data necessary to override object templates.
     */
    struct TemplateOverride
    {
        /**
         * The type of business object.
         */
        std::string businessObjectType;
        /**
         * The name of object template.
         */
        std::string templateId;
        /**
         * The type of object template.
         */
        std::string templateType;
    };




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


protected:
    virtual ~Fileimportexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/importexport/ImportExport_undef.h>
#endif

