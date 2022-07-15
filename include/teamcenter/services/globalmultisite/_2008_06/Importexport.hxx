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

#ifndef TEAMCENTER_SERVICES_GLOBALMULTISITE__2008_06_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_GLOBALMULTISITE__2008_06_IMPORTEXPORT_HXX

#include <teamcenter/services/globalmultisite/_2007_06/Importexport.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/TransferOptionSet.hxx>
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
            namespace _2008_06
            {
                class Importexport;

class TCSOAGLOBALMULTISITESTRONGMNGD_API Importexport
{
public:

    struct ExportObjectsToOfflinePackageResponse;
    struct ImportObjectsFromOfflinePackageResponse;

    /**
     * ExportObjectsToOfflinePackageResponse structure defines the response from ExportObjectsToOfflinePackage
     * operation. It contains briefcase file FMS ticket, export log file FMS ticekts, briefcase
     * dataset, and partial errors.
     */
    struct ExportObjectsToOfflinePackageResponse
    {
        /**
         * FMS ticket of the briefcase file, which can be used to download the briefcase file
         * from server to client.
         */
        std::string briefcaseFileFMSTicket;
        /**
         * FMS ticket of the briefcase file, which can be used to download the briefcase file
         * from server to client.
         */
        std::vector< std::string > exportLogFileFMSTickets;
        /**
         * A <b>Dataset</b> which includes the out briefcase file in its namedReference.
         * <br>
         * After export, a new Dataset will be created. The exported briefcase file will be
         * added to the new Dataset. And a new mail which contains the Dataset will be added
         * to mailbox folder of the user.  The mail will also be send to mail box of the user
         * if the user has set the Email Address.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  briefcaseDataSet;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors listed above in case of failure conditions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * ImportObjectsFromOfflinePackageResponse structure defines the response from ImportObjectsFromOfflinePackageResponse
     * operation. It contains FMS ticket of the log file, error file, and partial errors
     * and objects that are imported.
     */
    struct ImportObjectsFromOfflinePackageResponse
    {
        /**
         * FMS ticket of the import log file, which can be used to download the import log file
         * from server to client.
         */
        std::string logFileFMSTicket;
        /**
         * FMS ticket of the import error file, which can be used to download the import error
         * file from server to client.
         */
        std::string errorFileFMSTicket;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors listed above in case of failure conditions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Exports the objects to an offline package called briefcase. This operation returns
     * a structure which includes the briefcase's FMS file ticket and exporter log file's
     * FMS ticket. The briefcase ticket is used for downloading the briefcase file from
     * the server to the client side by using FMS utility. Exporter log ticket is used for
     * downloading the exporter log.
     * <br>
     * The briefcase is a package contains an exported TC XML file and a set of physical
     * dataset files. The TC XML file holds the exported objects traversed by TC XML Export
     * framework with the input <b>TransferOptionSet</b> and options, session options.
     * <br>
     * Exporter log include the exporting status of the related objects.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can set a list of root objects, a destination site, a transfer option set, a
     * list of traverse options and a list of session options. All the objects which can
     * be traversed by the option set and options will be exported into an output TC XML
     * file. The physical Iman files related exported dataset objects will be downloaded
     * and packed into the briefcase file along with the TC XML file.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param reason
     *        The reason for the export, the size is limited to 240 characters.
     *
     * @param sites
     *        The destination sites, only one site is supported as of now. The site should be marked
     *        as offline in Organization application to perform a Briefcase export.
     *
     * @param objects
     *        List of root objects to be exported.
     *
     * @param optionSetTag
     *        A reference to the <b>TransferOptionSet</b> object, this object holds the list of
     *        options and their default values which can influence the contents of the exported
     *        briefcase.
     *
     * @param optionNamesAndValues
     *        A list of all the option set options names and values. This is the list of options
     *        and values that overrides the values from the optionSetTag.
     *        <br>
     *        For example: there is an option in <b>TransferOptionSet</b>, which is used to control
     *        if exporting the configured assembly or not. The default value in the TransferOptionSet
     *        is false. A replaced value can be transferred by adding the option with new value
     *        of true.
     *        <br>
     *
     * @param sessionOptionAndValues
     *        A list of all the session option names (options which are not part of the option
     *        set) and values.
     *        <br>
     *        For example: A session option will mark the export is offline or not.
     *        <br>
     *
     * @return
     *         A <b>Dataset</b> with the briefcase file as the namedReference. Also the FMS file
     *         tickets for the briefcase file and the export log file. A new mail is crated which
     *         contains the Dataset and is added to the mailbox folder of the user. The mail will
     *         be sent to the mail box of the user if the email address is set. The <b>Dataset</b>
     *         is also returned in the updated list of the ServiceData. This operation may return
     *         these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">11059    An invalid <b>ItemRevision</b> export selector was supplied
     *         </li>
     *         <li type="disc">105034  There are no target sites.
     *         </li>
     *         <li type="disc">228004  A part file could not be added into the briefcase.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2008_06::Importexport::ExportObjectsToOfflinePackageResponse exportObjectsToOfflinePackage ( const std::string&  reason,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& sites,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSetTag,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& sessionOptionAndValues ) = 0;

    /**
     * This operation imports the data of a briefcase into Teamcenter. A packed briefcase
     * contains a TC XML file which holds a number of Teamcenter objects and related physical
     * dataset files. After import, those objects will be replica in the importing site.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In data exchange, user may transfer a briefcase file from the source site to a remote
     * site. In the importing site, user can use this operation to import the briefcase
     * file into Teamcenter. After import, the objects held in the TC XML file will be created
     * or updated if they have been imported before, physical dataset files will uploaded
     * and attached to the related datasets.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param fmsTicket
     *        The FMS file ticket for the briefcase file, the file should be uploaded to the server
     *        before calling this operation.
     *
     * @param optionSetTag
     *        A reference to the <b>TransferOptionSet</b> object, this object holds the list of
     *        options and their default values which can influence importing briefcase.
     *
     * @param optionNamesAndValues
     *        A list of all the option set options names and values. This is the list of options
     *        and values that overrides the values from the optionSetTag.
     *        <br>
     *        For example: there is an option in TransferOptionSet, opt_imp_XXX. The default value
     *        in the TransferOptionSet is false. A replaced value can be transferred by adding
     *        the option with new value of true.
     *        <br>
     *
     * @param sessionOptionAndValues
     *        A list of all the session option names (options which are not part of the option
     *        set) and values.
     *        <br>
     *        For example: A session option modified_objects_only will mark the import is only
     *        importing modified object or not.
     *        <br>
     *
     * @return
     *         The FMS file tickets for the import log file and import error file. New imported
     *         or modified objects are returned in the updated list of the ServiceData. This operation
     *         may return these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">11038  Importer has no privilege to update local object since owning
     *         sites are different.
     *         </li>
     *         <li type="disc">11032  Target/Master site passed for import/export is invalid.
     *         </li>
     *         <li type="disc">48043  <b>Item</b> with the same id in importing already exists in
     *         the importing site.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2008_06::Importexport::ImportObjectsFromOfflinePackageResponse importObjectsFromOfflinePackage ( const std::string&  fmsTicket,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSetTag,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& sessionOptionAndValues ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/globalmultisite/GlobalMultiSite_undef.h>
#endif

