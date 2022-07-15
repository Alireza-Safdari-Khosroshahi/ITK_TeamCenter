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

#ifndef TEAMCENTER_SERVICES_IMPORTEXPORT__2007_06_FILEIMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_IMPORTEXPORT__2007_06_FILEIMPORTEXPORT_HXX

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
            namespace _2007_06
            {
                class Fileimportexport;

class TCSOAIMPORTEXPORTSTRONGMNGD_API Fileimportexport
{
public:

    struct ExportToApplicationInputData;
    struct ExportToApplicationResponse;
    struct ImportFromApplicationInputData;
    struct ImportFromApplicationResponse;

    /**
     * The ExportToApplicationInputData structure represents all of the data necessary to
     * export selected objects to Word/Excel.
     */
    struct ExportToApplicationInputData
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
         * The application format such as "<code>MSWordXML</code>", "<code>MSExcel</code>" and
         * "<code>MSExcelLive</code>".
         * <br>
         * <br>
         * Supported application format for this operation
         * <br>
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordXML</b> &nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting WorkspaceObject to static <b>MSWord</b> application.
         * </li>
         * <li type="disc"><b>MSExcel</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for exporting
         * Teamcenter objects to static <b>MSExcel</b>  application.
         * </li>
         * <li type="disc"><b>MSExcelLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Teamcenter objects to Live <b>MSExcel</b>  application.
         * </li>
         * </ul>
         */
        std::string applicationFormat;
        /**
         * The name of the Word/Excel template.
         */
        std::string templateId;
    };

    /**
     * ExportToApplicationResponse structure represents the output of export to application
     * operation.
     * <br>
     * It has information about file ticket for the exported file generated at the server.
     */
    struct ExportToApplicationResponse
    {
        /**
         * The transient file read tickets for the exported file.
         */
        std::vector< std::string > transientFileReadTickets;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This holds the data necessary to import an <b>MSWord</b> document into Teamcenter.
     */
    struct ImportFromApplicationInputData
    {
        /**
         * The file ticket of the. docx file to be imported into Teamcenter.
         */
        std::string transientFileWriteTicket;
        /**
         * The supported application format is <b>MSWordXML</b>
         * <br>
         * <br>
         * Supported application format for this operation
         * <br>
         * <br>
         * <ul>
         * <li type="disc"><b>MSWordXML</b> &nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting <b>WorkspaceObjects</b> business objects to static MSWord application.
         * </li>
         * </ul>
         */
        std::string applicationFormat;
        /**
         * The subtype of <b>SpecElement</b> to be created.
         */
        std::string createSpecElementType;
    };

    /**
     * ImportFromApplicationResponse structure represents the output of import from application
     * operation. It contains the UID of the BOMWindow after the document is imported to
     * Teamcenter.
     */
    struct ImportFromApplicationResponse
    {
        /**
         * The resultant objects which contains the UID of the BOMWindow created after the document
         * is imported.  In case of importing templates, it contains the tag of the template.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > resultObjects;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Fileimportexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/importexport/ImportExport_undef.h>
#endif

