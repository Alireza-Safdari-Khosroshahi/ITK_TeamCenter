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

#ifndef TEAMCENTER_SERVICES_GLOBALMULTISITE__2007_12_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_GLOBALMULTISITE__2007_12_IMPORTEXPORT_HXX

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
            namespace _2007_12
            {
                class Importexport;

class TCSOAGLOBALMULTISITESTRONGMNGD_API Importexport
{
public:

    struct CallToRemoteSiteResponse;
    struct NamesAndValues;
    struct OwningSiteAndObjs;

    /**
     * CallToRemoteSiteResponse
     */
    struct CallToRemoteSiteResponse
    {
        /**
         * msgIDs
         */
        std::vector< std::string > msgIDs;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The NamesAndValues structure represents a generic name-value pair.
     */
    struct NamesAndValues
    {
        /**
         * The name of the session option.
         */
        std::string name;
        /**
         * The value of the session option.
         */
        std::string value;
    };

    /**
     * Vector of object and it's owning site. These objects need to be remote imported
     */
    struct OwningSiteAndObjs
    {
        /**
         * owningSiteId
         */
        int owningSiteId;
        /**
         * objs
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objs;
    };




    /**
     * This is the test service.
     *
     * @return
     *         This service allways returns hadrcoded value ZERO
     *
     */
    virtual int foo (  ) = 0;

    /**
     * This operation returns a list of sites registered for the requested type of transfer.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param siteType
     *        Following type of transfer supported by a site:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>&nbsp;&nbsp;&nbsp;&nbsp;</b>GMS<b> </b>         Sites participating
     *        in Global MultiSite
     *        </li>
     *        <li type="disc">  PLM          Non Global MultiSite sites or external application
     *        sites mentorBSLib,
     *        </li>
     *        </ul>
     *        <br>
     *        mentorPadsLib, mentorExpLib, cadenceLib, orcadLib, zukenCR5000Lib,
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        zukenCadStarLib, altiumDesLib, altiumPcadLib, mentorEDXLib, cadenceADWLib
     *        <br>
     *        <ul>
     *        <li type="disc"> Offline       GMS Sites participating in briefcase transfer
     *        </li>
     *        </ul>
     *
     * @return
     *         List of sites of particular type is returned in the plain list of the ServiceData.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getRemoteSites ( const std::string&  siteType ) = 0;

    /**
     * This operation exports objects to specified sites using Global Multisite.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation gets invoked from RAC when user does following actions from Navigator
     * or structure manager
     * <br>
     * 1>&nbsp;&nbsp;&nbsp;&nbsp;Tools->Export->To Remote Site Via Global Services.
     * <br>
     * 2>&nbsp;&nbsp;&nbsp;&nbsp;Tools->Export->To PDX
     * <br>
     * 3>&nbsp;&nbsp;&nbsp;&nbsp;Tools->Export->To Briefcase
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param reason
     *        The reason for remote export. This has limit of 240.
     *
     * @param sites
     *        A list of sites to which object(s) need to be exported.
     *
     * @param objects
     *        Objects to be exported
     *
     * @param optionSet
     *        A reference to <b>TransferOptionSet</b> object which is selected by the user. This
     *        object holds the list of options and their default values which can influence the
     *        contents of the exported briefcase or PDX or on-line export.
     *
     * @param optionNameAndValues
     *        This is the list of options and values that user has overridden from the <b>TransferOptionSet</b>
     *        object specified above. E.g option name 'opt_all_ds_files' (Export all dataset files)
     *        has default value as True in Transfer option set. If use does not want to export
     *        all dataset he can override it to false.
     *
     * @param sessionOptionNamesAndValues
     *        This is the list of session options and values (options which are not part of the
     *        option set). E.g 1) If user wants to run export in dry run mode then session option
     *        'dry_run' needs to be specified and its value should be 'True'. 2)If user wants to
     *        export unconfigured variants then 'processUnconfiguredVariants' should be set to
     *        'True'.
     *
     * @return
     *         The message ID for all the objects for which remote export transfer gets initiated
     *         through Global Services. If any error is encountered then it is stored in partial
     *         error of ServiceData. Following are possible errors:-
     *         <br>
     *         <ul>
     *         <li type="disc">105005:- Error while logging to global services.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;105039:- Cannot change site ownership in
     *         the offline transfer mode
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;203409:- Transfer Option Sets could not be
     *         retrieved.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_12::Importexport::CallToRemoteSiteResponse requestExportToRemoteSites ( const std::string&  reason,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& sites,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  optionSet,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& optionNameAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptionNamesAndValues ) = 0;

    /**
     * This operation imports objects to specified sites using Global Multisite.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is not in use.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param reason
     *        The reason of Import. This has limit of 240 characters.
     *
     * @param owningSitesAndObjs
     *        A list of owning site and corresponding objects that need to be imported.
     *
     * @param optionSet
     *        A reference to <b>TransferOptionSet</b> object which is selected by the user. This
     *        object holds the list of options and their default values which can influence the
     *        result of import.
     *
     * @param optionNamesAndValues
     *        This is the list of options and values that user has overridden from the <b>TransferOptionSet</b>
     *        object specified above.
     *
     * @param sessionOptionNamesAndValues
     *        This is the list of session options and values (options which are not part of the
     *        option set).
     *
     * @return
     *         The message ID for all the objects for which remote export transfer gets initiated
     *         through Global Services. Errors are returned in ServiceData. Following are possible
     *         errors:-
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;105005 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         Error while logging to global services.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;105039&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         Cannot change site ownership in the offline transfer mode
     *         </li>
     *         <li type="disc">  203409&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Transfer
     *         Option Sets could not be retrieved.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_12::Importexport::CallToRemoteSiteResponse requestImportFromRemoteSites ( const std::string&  reason,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::OwningSiteAndObjs >& owningSitesAndObjs,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  optionSet,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptionNamesAndValues ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/globalmultisite/GlobalMultiSite_undef.h>
#endif

