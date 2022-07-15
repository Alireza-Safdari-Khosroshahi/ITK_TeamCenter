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

#ifndef TEAMCENTER_SERVICES_VENDORMANAGEMENT__2012_02_VENDORMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VENDORMANAGEMENT__2012_02_VENDORMANAGEMENT_HXX

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
            namespace _2012_02
            {
                class Vendormanagement;

class TCSOAVENDORMANAGEMENTSTRONGMNGD_API Vendormanagement
{
public:

    struct LineItemPropertiesWithType;

    /**
     * The information about each <b>BidPackageLineItem</b> to be processed is provided
     * by way of the <code>LineItemPropertiesWithType</code> data structure.
     */
    struct LineItemPropertiesWithType
    {
        /**
         * Name of the <b>BidPackageLineItem</b> to be created.
         */
        std::string name;
        /**
         * Description of the <b>BidPackageLineItem</b> Object.
         */
        std::string description;
        /**
         * Name of the <b>LineItemConfigContext</b> to be created.
         */
        std::string liccname;
        /**
         * Description of the <b>LineItemConfigContext</b> to be created.
         */
        std::string liccdesc;
        /**
         * Id of the part to be associated with <b>BidPackageLineItem</b>.
         */
        std::string partid;
        /**
         * PSView Type to be associated with <b>LineItemConfigContext</b>.
         */
        std::string viewtype;
        /**
         * Quantity to be created for <b>BidPackageLineItem</b>.
         */
        int quantity;
        /**
         * Revision rule to be associated with <b>LineItemConfigContext</b>.
         */
        std::string revRule;
        /**
         * Variant rule to be associated with <b>LineItemConfigContext</b>.
         */
        std::string varRule;
        /**
         * Closure rule to be associated with <b>LineItemConfigContext</b>.
         */
        std::string closureRule;
        /**
         * <b>Quote</b> form to be added to <b>BidPackageLineItem</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  quote;
        /**
         * Name of the type of the <b>BidPackageLineItem</b> to be used.
         */
        std::string bpliTypeName;
    };




    /**
     * This service operation creates or updates a group of <b>BidPackageLineItem</b> objects
     * and any subtype of it in the context of the mentioned <b>BidPackage</b>. This operation
     * allows the user to find or create a set of <b>BidPackageLineItem</b> objects based
     * on the input data. It first tries to find the existence of the specified <b>BidPackageLineItem</b>
     * for the specified <b>BidPackage</b>. If the specified <b>BidPackageLineItem</b> is
     * found, then the its data will be updated. Otherwise, it will create the specified
     * <b>BidPackageLineItem</b> and associate it to the specified <b>BidPackageRevision</b>.
     * If the specified <b>BidPackageLineItem</b> objects exist and any of the input attribute
     * values differ from those already set, they will be updated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param properties
     *        A list of <code>LineItemPropertiesWithType</code> structures which are used to create
     *        or update <b>BidPackageLineItem</b> objects.
     *        <br>
     *
     * @param bidPackage
     *        Reference to the <b>BidPackageRevision</b> object which will be used to associate
     *        the created <b>BidPackageLineItem</b> objects.
     *
     * @return
     *         Standard Teamcenter <code>ServiceData</code> instance is returned. Failure will be
     *         with client id and error message in the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         Typical Errors returned are:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">Errors 9006, 29013 while creating or updating <b>BidPackageLineItem</b>
     *         objects.
     *         </li>
     *         <li type="disc">Low level relation ITK errors while adding the <b>BidPackageLineItem</b>
     *         objects to the <b>BidPackageRevision</b>.
     *         </li>
     *         <li type="disc">Errors 29006, 29013, 29020 while processing rules (Revision, Variant
     *         or Closure) for <b>LineItemConfigContext</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateLineItemsWithType ( const std::vector< Teamcenter::Services::Vendormanagement::_2012_02::Vendormanagement::LineItemPropertiesWithType >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bidPackage ) = 0;


protected:
    virtual ~Vendormanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/vendormanagement/Vendormanagement_undef.h>
#endif

