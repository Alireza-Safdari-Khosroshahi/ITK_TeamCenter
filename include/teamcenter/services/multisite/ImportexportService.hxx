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

#ifndef TEAMCENTER_SERVICES_MULTISITE_IMPORTEXPORTSERVICE_HXX
#define TEAMCENTER_SERVICES_MULTISITE_IMPORTEXPORTSERVICE_HXX

#include <teamcenter/services/multisite/_2007_06/Importexport.hxx>
#include <teamcenter/services/multisite/_2011_06/Importexport.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/multisite/Multisite_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Multisite
        {
            class ImportexportService;

/**
 * The <code>ImportExport</code> service provides operations to share the data within
 * the sites in the Multi-Site federation. Data sharing is achieved using the data replication,
 * through import and export operations. These are the foundation of Multi-Site Collaboration.
 * Using this service the participating sites in a Multi-Site federation get a reliable
 * way of importing the data from the rest of the site(s).
 * <br>
 * <br>
 * This service also provides the operation to maintain the item id uniqueness in the
 * Multi-Site federation. In a Multi-Site federation item id uniqueness is maintained
 * using the central item id registry. This service provides the operation for registering
 * and unregistering item ids to and from the central item id registry.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamultisitestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamultisitetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMULTISITESTRONGMNGD_API ImportexportService
    : public Teamcenter::Services::Multisite::_2007_06::Importexport,
             public Teamcenter::Services::Multisite::_2011_06::Importexport
{
public:
    static ImportexportService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * The <code>registerItemId</code> operation is used to register the list of items at
     * the central item registry.  The central registry holds all item ids from the Multi-Site
     * federation. The item ID could be manually registered using Rich client, Command line
     * utility <b>data_share </b>OR using this operation.
     * <br>
     * <br>
     * Usage of this operation is influenced by the following preferences.
     * <br>
     * 
     * <br>
     * The preference <b>ITEM_id_registry</b> activates/deactivates the central item registry.
     * If the preference value is set to TRUE, during item creation, the system checks
     * the item registry for duplicates. Creating the item fails if a duplicate is found.
     * Setting <b>ITEM_id_Registry</b> to FALSE would make Item registry disabled. Thus,
     * while creating a new item, the item registry is not checked for duplicates.
     * <br>
     * <br>
     * The preference <b>ITEM_id_registry_site</b> identifies the site name at which the
     * central item registry server is running. This must be set, if the preference<b> ITEM_id_registry</b>
     * is set to TRUE and will be ignored otherwise.
     * <br>
     * 
     * <br>
     * The preference <b>ITEM_id_allow_if_registry_down</b> determines if items can be created,
     * if the registry server is not available. If the registry is not active (<b>ITEM_id_registry</b>
     * = FALSE), this preference is ignored.
     * <br>
     * <br>
     * The preference <b>ITEM_id_always_register_on_creation</b> determines if item IDs
     * are automatically registered when items are created or the item ID is changed.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">Admin user(s) set the <b>ITEM_id_always_register_on_creation</b>
     * to TRUE on all sites within a Multi-Site federation. On item creation the items created
     * automatically registers with the central item registry.
     * </li>
     * <li type="disc">Admin user(s) can register existing item(s) with the central item
     * registry, using <b>Register Item Id </b>command in the Rich Client(<b>RAC</b>) or
     * command line utility <b>data_share f=register</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Import/Export - Import / export of Tc data model in a binary format that CMS uses.
     *
     * @param itemInfo
     *        List of Teamcenter <b>Item</b> which need to be registered with the central item
     *        ID registry. These are the business objects of Class <b>Item</b> created in Teamcenter.
     *
     * @return
     *         <code>ServiceData</code> which has the list of partial errors along with the error
     *         messages.
     *         <br>
     *         <br>
     *         Possible errors are:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">100304 - The Item ID is already registered.
     *         </li>
     *         <li type="disc">100306 - The Item ID parameter is invalid.
     *         </li>
     *         <li type="disc">100308 - The Item registry is not active.
     *         </li>
     *         <li type="disc">100309 - The Item registry is not available.
     *         </li>
     *         <li type="disc">100311 - An Item with the same multifield key value, is already registered.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData registerItemId ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  >& itemInfo ) = 0;

    /**
     * The central registry holds all item ids from the multisite federation. To unregister
     * the item id(s), this operation is used, this unregisters supplied items from the
     * central item registry. The item ID could be manually unregistered using Rich client,
     * Command line utility <b>data_share</b> OR using this operation.
     * <br>
     * <br>
     * The preference <b>ITEM_id_registry</b> activates/deactivates the central item registry.
     * If the preference value set to TRUE, during item creation, the system checks the
     * item registry for duplicates. Creating the item fails if a duplicate is found. Setting
     * <b>ITEM_id_Registry</b> to FALSE would make item registry disabled. So while creating
     * a new item, the item registry is not checked for duplicates.
     * <br>
     * <br>
     * The preference<b> ITEM_id_registry_site</b> identifies the site name at which the
     * central item registry server is running. This must be set, if the preference <b>ITEM_id_registry</b>
     * is set to TRUE and will be ignored otherwise.
     * <br>
     * <br>
     * The preference <b>ITEM_id_unregister_on_delete</b> determines if item Ids are automatically
     * unregistered when items are deleted or the item ID is changed.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">Admin user(s) can unregister existing item(s) from the central item
     * registry, using <b>Unregister Item Id</b> command in the Rich Client (<b>RAC</b>)
     * or command line utility <b>data_share f=unregister</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Import/Export - Import / export of Tc data model in a binary format that CMS uses.
     *
     * @param itemInfo
     *        List of items which needs to be unregistered with the central item id registry. These
     *        are the business objects of Class <b>Item</b> created in Teamcenter.
     *
     * @return
     *         <code>ServiceData</code> which has the list of partial errors along with the error
     *         messages.
     *         <br>
     *         <br>
     *         Possible errors are:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">100306 - The Item ID parameter is invalid.
     *         </li>
     *         <li type="disc">100308 - The Item registry is not active.
     *         </li>
     *         <li type="disc">100309 - The Item registry is not available.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData unregisterItemId ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  >& itemInfo ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImportexportService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/multisite/Multisite_undef.h>
#endif

