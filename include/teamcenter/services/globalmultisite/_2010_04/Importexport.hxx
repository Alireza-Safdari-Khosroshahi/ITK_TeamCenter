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

#ifndef TEAMCENTER_SERVICES_GLOBALMULTISITE__2010_04_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_GLOBALMULTISITE__2010_04_IMPORTEXPORT_HXX

#include <teamcenter/services/globalmultisite/_2007_12/Importexport.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/TransferMode.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/globalmultisite/GlobalMultiSite_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Globalmultisite
        {
            namespace _2010_04
            {
                class Importexport;

class TCSOAGLOBALMULTISITESTRONGMNGD_API Importexport
{
public:

    struct FileTicket;
    struct ExportObjectsToPLMXMLResponse;
    struct ImportObjectsFromPLMXMLResponse;

    /**
     * To represent a  file ticket and its original file name.
     */
    struct FileTicket
    {
        /**
         * The FMS file Ticket.
         */
        std::string ticket;
        /**
         * The original file name.
         */
        std::string fileName;
    };

    /**
     * The response for <code>exportObjectsToPLMXML</code> operation. It holds the file
     * ticket for the exported XML file, file ticket for the export log file, file tickets
     * for the dataset named reference files, and any partial failures.
     */
    struct ExportObjectsToPLMXMLResponse
    {
        /**
         * The FMS ticket is used to get the generated PLMXML file.
         */
        Teamcenter::Services::Globalmultisite::_2010_04::Importexport::FileTicket xmlFileTicket;
        /**
         * The FMS ticket is used to get the generated export log file.
         */
        Teamcenter::Services::Globalmultisite::_2010_04::Importexport::FileTicket logFileTicket;
        /**
         * The FMS tickets are used to get the dataset named  reference files. On Teamcenter
         * Services client, the files must be loaded into the directory along with the PLMXML
         * file. And the directory must have the same name as the PLMXML file without the file
         * extension name.
         */
        std::vector< Teamcenter::Services::Globalmultisite::_2010_04::Importexport::FileTicket > namedRefFileTickets;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors is used to report any partial failures.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The response for <code>importObjectsFromPLMXML</code> operation. It holds the file
     * ticket for the import log file, and any partial failures.
     */
    struct ImportObjectsFromPLMXMLResponse
    {
        /**
         * The FMS ticket is used to get the generated import log file.
         */
        Teamcenter::Services::Globalmultisite::_2010_04::Importexport::FileTicket logFileTicket;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * The <code>exportObjectsToPLMXML</code> operation will generate a PLMXML file and
     * a export log file for the input object list, transfer mode, revision rule and language
     * set.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Export object to PLMXML file</b>
     * <br>
     * You can export any business object by specify:
     * <br>
     * 1)&nbsp;&nbsp;&nbsp;&nbsp;The objects that you want to exported.
     * <br>
     * 2)&nbsp;&nbsp;&nbsp;&nbsp;Transfer mode and revision rule.
     * <br>
     * 3)&nbsp;&nbsp;&nbsp;&nbsp;Languages that for localization value.
     * <br>
     * 4)&nbsp;&nbsp;&nbsp;&nbsp;Xml file name.
     * <br>
     * 5)&nbsp;&nbsp;&nbsp;&nbsp;Session options.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param exportObjects
     *        Objects to be exported.
     *
     * @param transfermode
     *        The transfermode which you want to use to traverse from the objects.
     *
     * @param revRule
     *        Revision Rule that you want to use to traverse bom structure.
     *
     * @param languages
     *        The languages to export with.The language code is used to identify a langauge. It
     *        follows the Java locale naming conventions: 2letterlanguage_2LETTERAREA (e.g: en_US,
     *        fr_FR, de_DE). The language order will be honored and the site master language will
     *        always be included.
     *
     * @param xmlFileName
     *        The file name that you want the xml to be export to.
     *
     * @param sessionOptions
     *        The session options to control export behavior as name-value pairs. This is in place
     *        for future use to pass additional flags to the PLM XML export which can control the
     *        behavior.
     *
     * @return
     *         The output is struct <code>ExportObjectsToPLMXMLResponse</code> with the generated
     *         PLMXML file ticket, export log file ticket, dataset named reference file tickets
     *         if any and soa service data.
     *
     *
     * @exception ServiceException
     *           203331&nbsp;&nbsp;&nbsp;&nbsp;will throw while all input objects is invalid objects.
     *           <br>
     *           203447&nbsp;&nbsp;&nbsp;&nbsp;will throw while fail to get download ticket from FMS.
     *           <br>
     *           Other PIE failure in the whole export process.
     */
    virtual Teamcenter::Services::Globalmultisite::_2010_04::Importexport::ExportObjectsToPLMXMLResponse exportObjectsToPLMXML ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& exportObjects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  transfermode,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule,
        const std::vector< std::string >& languages,
        const std::string&  xmlFileName,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptions ) = 0;

    /**
     * The <code>importObjectsFromPLMXML</code> operation will import the objects from a
     * PLMXML file. The XML file and the named reference files for datasets should be uploaded
     * to transient volume before the calling of this operation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Import PLMXML file to database</b>
     * <br>
     * You can import PLMXML file by specify:
     * <br>
     * 1)&nbsp;&nbsp;&nbsp;&nbsp;The xml file that you want to import.
     * <br>
     * 2)&nbsp;&nbsp;&nbsp;&nbsp;The related dataset file you want to import.
     * <br>
     * 3)&nbsp;&nbsp;&nbsp;&nbsp;Transfer mode that you want to traverse to the xml.
     * <br>
     * 4)&nbsp;&nbsp;&nbsp;&nbsp;The incremental change context.
     * <br>
     * 5)&nbsp;&nbsp;&nbsp;&nbsp;Session options.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param xmlFileTicket
     *        The FMS file ticket for the input XML file to be imported.
     *
     * @param namedRefFileTickets
     *        The FMS file tickets for dataset named reference files.
     *
     * @param transfermode
     *        The transfer mode used to control the import process.
     *
     * @param icRev
     *        The incremental change context for the import restuls. The ItemRevision is used to
     *        represent its sub-calss EngChange.
     *
     * @param sessionOptions
     *        The session options to control export behavior as name-value pairs. This is in place
     *        for future use to pass additional flags to the PLM XML export which can control the
     *        behavior.
     *
     * @return
     *         The output is struct <code>ImportObjectsFromPLMXMLResponse</code> with the import
     *         log and soa service data.
     *
     *
     * @exception ServiceException
     *           203474&nbsp;&nbsp;&nbsp;&nbsp;will throw while the input file name is too long.
     *           <br>
     *           Other PIE failure in the whole import process.
     */
    virtual Teamcenter::Services::Globalmultisite::_2010_04::Importexport::ImportObjectsFromPLMXMLResponse importObjectsFromPLMXML ( const std::string&  xmlFileTicket,
        const std::vector< std::string >& namedRefFileTickets,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  transfermode,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  icRev,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptions ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/globalmultisite/GlobalMultiSite_undef.h>
#endif

