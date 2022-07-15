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

#ifndef TEAMCENTER_SERVICES_MULTISITE__2007_06_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_MULTISITE__2007_06_IMPORTEXPORT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/multisite/Multisite_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Multisite
        {
            namespace _2007_06
            {
                class Importexport;

class TCSOAMULTISITESTRONGMNGD_API Importexport
{
public:

    struct RemoteImportInfo;
    struct RIAttributeInfo;

    /**
     * The <code>RemoteImportInfo</code> holds the business object and related information
     * meant for remote import.
     * <br>
     */
    struct RemoteImportInfo
    {
        /**
         * Object for the remote import service
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * User input to explain, why the remote import of business object required. Its not
         * a mandatory input and user can pass empty string.
         */
        std::string reason;
        /**
         * Import options that influence, how the Business Objects are imported to target site.
         */
        std::vector< Teamcenter::Services::Multisite::_2007_06::Importexport::RIAttributeInfo > importOptions;
    };

    /**
     * The <code>RIAttributeInfo</code> structures holds the name/value pairs of import
     * option. Value can be single or multiple valued. The import options influences the
     * business object export and has default value.
     */
    struct RIAttributeInfo
    {
        /**
         * Import option name for remote import.
         * <br>
         */
        std::string name;
        /**
         * Values for remote import option (can be multi-valued strings).
         */
        std::vector< std::string > value;
    };




    /**
     * The <code>remoteImport</code> operation is used to import given business objects
     * from the target site to the source site. The import options supplied in the <code>RemoteImportInfo</code>
     * structure influences the business object import.
     * <br>
     * <br>
     * E.g. In case user supplies <code>Include All revision</code> as TRUE, from target
     * site, source site will import all versions of the dataset.
     * <br>
     * <br>
     * When option(s) are not specified in the RemoteImportInfo structure, by default user
     * session preferences at the importing site are considered for import.  Default values
     * are mentioned under the <code>RIAttributeInfo</code> structure.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">In the Multi-Site federation user can share the business objects
     * among the participating sites, the client shares business object(s) using the remote
     * import or remote export functionality. Incase of the remote import the source site
     * need to publish the item to the object directory services.
     * </li>
     * <li type="disc">To remote import the business object, first the source site user
     * creates an Item and publishes it to the default ODS. The target site user performs
     * remote search with the item id and imports it to the target site using the remote
     * import operation. On successful completion of remote import operation, the item is
     * imported to the target site database.
     * </li>
     * <li type="disc">Also remote import of business objects can be achieved using the
     * command line utility data_share f=remote_import.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Import/Export - Import / export of Tc data model in a binary format that CMS uses.
     *
     * @param infos
     *        List of <code>RemoteImportInfo</code> structures.  The <code>RemoteImportInfo</code>
     *        holds business object meant for remote import and the <code>RIAttributeInfo</code>
     *        structures are name/value pairs. Value can be single or multiple valued.
     *        <br>
     *        Eg. Name having single value,
     *        <br>
     *        name: ownerhip_transfer
     *        <br>
     *        value: false/true
     *        <br>
     *
     * @return
     *         Any failure is returned in the <code>ServiceData</code> list of partial errors with
     *         input business objects mapped to the error message.
     *         <br>
     *         <br>
     *         Possible errors are
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">100201 - The IDSM connection to site on host failed.
     *         </li>
     *         <li type="disc">100202 - The IDSM request to site on host failed.
     *         </li>
     *         <li type="disc">100204 - Asynchronous operation not supported.
     *         </li>
     *         <li type="disc">100205 - Asynchronous operation already in progress.
     *         </li>
     *         <li type="disc">100211 - Requesting client site has no access to IDSM.
     *         </li>
     *         <li type="disc">100213 - The IDSM is not logged in to the expected site.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           .
     */
    virtual Teamcenter::Soa::Client::ServiceData remoteImport ( const std::vector< Teamcenter::Services::Multisite::_2007_06::Importexport::RemoteImportInfo >& infos ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/multisite/Multisite_undef.h>
#endif

