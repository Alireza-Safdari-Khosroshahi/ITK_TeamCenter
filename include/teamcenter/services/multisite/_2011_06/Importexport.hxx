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

#ifndef TEAMCENTER_SERVICES_MULTISITE__2011_06_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_MULTISITE__2011_06_IMPORTEXPORT_HXX

#include <teamcenter/soa/client/model/Item.hxx>


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
            namespace _2011_06
            {
                class Importexport;

class TCSOAMULTISITESTRONGMNGD_API Importexport
{
public:





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


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/multisite/Multisite_undef.h>
#endif

