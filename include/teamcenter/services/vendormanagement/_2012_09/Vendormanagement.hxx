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

#ifndef TEAMCENTER_SERVICES_VENDORMANAGEMENT__2012_09_VENDORMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VENDORMANAGEMENT__2012_09_VENDORMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/vendormanagement/Vendormanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Vendormanagement
        {
            namespace _2012_09
            {
                class Vendormanagement;

class TCSOAVENDORMANAGEMENTSTRONGMNGD_API Vendormanagement
{
public:

    struct VendorRoleData;

    /**
     * This is the structure containing <b>VendorRole</b> information.
     */
    struct VendorRoleData
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify the Partial Errors
         * associated with this <code>VendorRoleData</code> input.
         */
        std::string clientId;
        /**
         * Description of the object to be created.
         */
        std::string description;
        /**
         * <b>VendorRole</b> type, it shall be <i>Manufacturer</i>,<i>Supplier</i> or <i>Distributor</i>
         */
        std::string roleType;
        /**
         * Flag to indicate VendorRole is to be added or removed.
         */
        bool remove;
    };




    /**
     * This operation adds or removes set of roles to/from a <b>VendorRevision</b>. Typically
     * a role can be assigned to a <b>VendorRevision</b> by adding a role form with different
     * role specific information. OOTB <b>VendorRevision</b> can be assigned with 3 roles
     * namely <i>Distributor</i>, <i>Supplier</i> and <i>Manufacturer</i>. All these role
     * forms contain information about the <b>Vendor</b> based on the type of the role.
     * Similarly a role can be revoked from a <b>VendorRevision</b>. When a <b>Vendor</b>
     * is revised, the new revision inherits all the assigned roles to the previous <b>VendorRevision</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param vendorRoles
     *        It is a list of <code>VendorRoleData</code> structures meant to hold data for <b>VendorRole</b>
     *        objects to be processed.
     *
     * @param vendorRevRef
     *        Reference to the <b>VendorRevision</b> object in the context of which these roles
     *        are to be processed.
     *
     * @return
     *         The partial errors and failures are updated and returned through the object <code>ServiceData</code>.
     *         <br>
     *         Typical errors returned are:
     *         <br>
     *         <ul>
     *         <li type="disc">Error 480014: <b>VendorRevision</b> object is not valid.
     *         </li>
     *         <li type="disc">Error 229024: Unable to get <b>VendorRoles</b> from <b>VendorRevision</b>.
     *         </li>
     *         <li type="disc">Error 229022: Unable to add specified <b>VendorRole</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData addRemoveVendorRoles ( const std::vector< Teamcenter::Services::Vendormanagement::_2012_09::Vendormanagement::VendorRoleData >& vendorRoles,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  vendorRevRef ) = 0;


protected:
    virtual ~Vendormanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/vendormanagement/Vendormanagement_undef.h>
#endif

