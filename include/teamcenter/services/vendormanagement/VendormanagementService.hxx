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

#ifndef TEAMCENTER_SERVICES_VENDORMANAGEMENT_VENDORMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_VENDORMANAGEMENT_VENDORMANAGEMENTSERVICE_HXX

#include <teamcenter/services/vendormanagement/_2007_06/Vendormanagement.hxx>
#include <teamcenter/services/vendormanagement/_2008_06/Vendormanagement.hxx>
#include <teamcenter/services/vendormanagement/_2012_02/Vendormanagement.hxx>
#include <teamcenter/services/vendormanagement/_2012_09/Vendormanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/vendormanagement/Vendormanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Vendormanagement
        {
            class VendormanagementService;

/**
 * The Vendor Management service exposes operations that are used to address Vendor
 * Management related functionalities. Common uses of this service are to create, modify
 * and delete Vendor Management complex objects through different operations.
 * <br>
 * <br>
 * This service provides following Vendor Management use cases.
 * <br>
 * <ul>
 * <li type="disc">Create or update of BidPackage, Vendor Part, Vendor, BidPackage Line
 * Item,
 * </li>
 * <li type="disc">Deletion of BidPackage Line Item, Vendor,
 * </li>
 * <li type="disc">Change Vendor of an existing Vendor Part,
 * </li>
 * <li type="disc">Fetching Vendor Parts based on a selection rule,
 * </li>
 * <li type="disc">Add or remove Vendor roles to or from a Vendor.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoavendormanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoavendormanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAVENDORMANAGEMENTSTRONGMNGD_API VendormanagementService
    : public Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement,
             public Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement,
             public Teamcenter::Services::Vendormanagement::_2012_02::Vendormanagement,
             public Teamcenter::Services::Vendormanagement::_2012_09::Vendormanagement
{
public:
    static VendormanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This service operation creates or updates a group of <b>BidPackage</b>, <b>BidPackageRevision
     * </b>objects. This operation allows the user to find or create a set of <b>BidPackage</b>
     * objects based on the input data. The service first tries to find the existence of
     * the specified <b>BidPackage</b> or <b>BidPackageRevision</b>. If the specified <b>BidPackage</b>
     * objects exist and any of the input attribute values differ from those already set,
     * the <b>BidPackage</b> objects will be updated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param properties
     *        A list of <code>BidPackageProps</code> structures which are used to create or update
     *        <b>BidPackage</b> objects.
     *
     * @param container
     *        A parent object reference with which the created <b>BidPackage</b> objects will be
     *        associated.
     *
     * @param relationType
     *        A relation name to be used for associating the <b>BidPackage</b> to its parent.
     *
     * @return
     *         A list of <code>CreateBidPacksOutput</code> structures. These structures contain
     *         information about the <b>BidPackages</b>, <b>BidPackageRevisions</b>.
     *         <br>
     *         Failures are returned through <code>ServiceData</code> with client id and error message.
     *         <br>
     *         <br>
     *         Typical errors returned can be:
     *         <br>
     *         <ul>
     *         <li type="disc">Error 48161: Multiple BidPackage objects existing with the specified
     *         itemId Id
     *         </li>
     *         <li type="disc">Error 48005, 48032: Unable to create BidPackage or BidPackageRevision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::CreateBidPacksResponse createOrUpdateBidPackages ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::BidPackageProps >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * This service operation creates or updates a group of <b>BidPackageLineItem</b> objects
     * in the context of the mentioned <b>BidPackage</b>. This operation allows the user
     * to find or create a set of <b>BidPackageLineItem</b> objects based on the input data.
     * It first tries to find the existence of the specified <b>BidPackageLineItem</b> for
     * the specified <b>BidPackage</b>. If the specified <b>BidPackageLineItem</b> is found,
     * then its corresponding data will be updated. Otherwise, it will create the specified
     * <b>BidPackageLineItem</b> and associate it to the specified <b>BidPackageRevision</b>.
     * If the specified <b>BidPackageLineItem</b> objects exist and any of the input attribute
     * values differ from those already set, the <b>BidPackageLineItem</b> objects will
     * be updated.
     * <br>
     * <br>
     * The operation is now deprecated. It is now replaced by <code>Teamcenter::Soa::Vendormanagement::VendorManagement::createOrUpdateLineItemsWithType.</code>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param properties
     *        A list of <code>LineItemProps</code> structures which are used to create or update
     *        <b>BidPackageLineItem</b> objects.
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
     *         <ul>
     *         <li type="disc">Errors 29006, 29013 while creating or updating Line Items
     *         </li>
     *         <li type="disc">Low level relation ITK errors while adding the <b>BidPackageLineItem</b>
     *         objects to the <b>BidPackageRevision</b>.
     *         </li>
     *         <li type="disc">Errors 29006, 29013, 29020 while processing rules (Revision, Variant
     *         or Closure) for <b>LineItemConfigContext</b>.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of Tc 8, replaced by Teamcenter::Soa::Vendormanagement::VendorManagement::createOrUpdateLineItemsWithType
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, replaced by Teamcenter::Soa::Vendormanagement::VendorManagement::createOrUpdateLineItemsWithType"))
#endif
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateLineItems ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::LineItemProps >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bidPackage ) = 0;

    /**
     * This service operation creates or updates a group of <b>VendorPart</b> objects or
     * <b>CommericialPart</b> objects. The choice could be either <b>CommercialPart</b>
     * or <b>VendorPart</b> only. This operation allows the user to update or create a set
     * of <b>CommercialPart</b> objects or <b>VendorPart</b> objects based on the input
     * data. It first tries to find the existence of the specified <b>VendorPart</b> or
     * <b>VendorPartRevision</b>. If the specified parts are found, those parts will be
     * updated with the specified values. Otherwise new parts will be created.
     * <br>
     * The choice for type of part is given through data member type of <code>VendorPartProperties</code>
     * structure. Only '<i>ManufacturerPart</i>' and '<i>CommercialPart</i>' are valid types.
     * <br>
     * <b>Behavior for CommercialPart:</b>  The service will create the <b>CommercialPart</b>
     * and <b>CommercialPartRevision</b> and it will associate the created <b>CommercialPart</b>
     * to the specified parent (container). It also associates the part to the specified
     * <b>Vendor</b> object if given.
     * <br>
     * <b>Behavior for ManufacturerPart: </b> The service will create the <b>ManufacturerPart</b>
     * and <b>ManufacturerPartRevision</b> and will associate the part to the specified
     * <b>Vendor</b> object. It also associates the created <b>ManufacturerPart</b> to the
     * <b>CommercialPart</b> if specified.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param properties
     *        A list of <code>VectorPartProperties</code> structures which are used to create or
     *        update <b>VendorPart</b> objects or <b>CommercialPart</b> objects.
     *        <br>
     *        <br>
     *        <b>VendorPartProperties</b>
     *        <br>
     *        The information about each <b>VendorPart</b> to be processed is provided by way of
     *        the <code>VendorPartProperties</code> data structure.
     *        <br>
     *
     * @param container
     *        A parent object reference with which the created parts will be associated.
     *
     * @param relationType
     *        A relation name to be used for associating the <b>Vendor</b> to its parent.
     *
     * @return
     *         <code>CreateVendorPartsResponse</code> object returned contains a list of <code>CreateVendorPartsOutput</code>
     *         structures which contain information about the <b>VendorPart</b> and <b>VendorPartRevision</b>.
     *         Failure will be with client id and error message in the <code>ServiceData</code>
     *         structure returned from within the <code>CreateVendorPartsResponse</code> object.
     *         <br>
     *         <br>
     *         Typical errors returned are:
     *         <br>
     *         <ul>
     *         <li type="disc">48161 - Multiple <b>Vendor</b> objects existing with the specified
     *         <b>Vendor</b> Id
     *         </li>
     *         <li type="disc">29020 - Unable to create <b>Vendor</b> or <b>CommercialPart</b> or
     *         respective <b>PartRevision</b>.
     *         </li>
     *         <li type="disc">35002 - Unable to add specified <b>Vendor</b> to the <b>VendorPart</b>.
     *         </li>
     *         <li type="disc">35002, 35013 - Cannot relate created or updated <b>VendorPart</b>
     *         to the specified <b>CommercialPart</b> or <b>PartRevision</b>.
     *         </li>
     *         <li type="disc">35013, 35006 - Unable to add <b>VendorPart</b> to the parent Business
     *         Object.
     *         </li>
     *         <li type="disc">29024 - Unable to create <b>VendorPart</b> due to invalid release
     *         status of the <b>Vendor</b> & its latest revision specified.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::CreateVendorPartsResponse createOrUpdateVendorParts ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::VendorPartProperties >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * This service operation creates or updates a group of <b>Vendor</b>, <b>VendorRevision</b>
     * Objects and <b>VendorRole</b> objects. It allows the user to update or create a set
     * of <b>Vendor</b> objects based on the input data. The service first tries to find
     * the existence of the specified <b>Vendor</b> or <b>VendorRevision</b> or <b>VendorRole</b>.
     * If the service is able to find any of those objects, then those objects will be updated.
     * If the service is not able to find those objects, then those objects will be created.
     * If the <b>Vendor</b> exists, but <b>VendorRevision</b> does not, then <b>VendorRevision</b>
     * and <b>VendorRole</b> (and <b>VendorRole</b> form) will be created. If the specified
     * <b>Vendor</b> object and its associated objects exist and any of the input attribute
     * values differ from those already set, the <b>Vendor</b> and its associated objects
     * will be updated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param properties
     *        A list of <code>VendorProperties</code> structures which are used to create or update
     *        the <b>Vendor</b> objects.
     *        <br>
     *
     * @param container
     *        A parent object reference to which the created <b>Vendor</b> objects will be associated.
     *
     * @param relationType
     *        A relation name to be used for associating the <b>Vendor</b> to its parent.
     *
     * @return
     *         <code>CreateVendorsResponse</code> is the returned object. It contains the output
     *         in the form of list of <code>CreateVendorsOutput</code> structures which contain
     *         information about the <b>Vendor</b>, <b>VendorRevision</b> Objects and <b>VendorRole</b>
     *         objects. It also contains standard Teamcenter <code>ServiceData</code> structure.
     *         Failure will be with client id and potential error messages as mentioned below in
     *         the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         Typical errors returned can be:
     *         <br>
     *         <ul>
     *         <li type="disc">Error 48161: Multiple <b>Vendor</b> objects existing with the specified
     *         <b>Vendor</b> Id
     *         </li>
     *         <li type="disc">Error 48005: Unable to create <b>Vendor</b> or <b>VendorRevision</b>
     *         or <b>VendorRole</b> or <b>VendorRoleForm</b>.
     *         </li>
     *         <li type="disc">Error 267023: Unable to add created <b>VendorRole</b> to the <b>VendorRevision</b>
     *         </li>
     *         <li type="disc">Error 35002: Unable to add Vendor to the parent Business Object.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of Teamcenter 10, this operation is deprecated in TC 10.0. Replaced by new operation
     *         addRemoveVendorRoles.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, this operation is deprecated in TC 10.0. Replaced by new operation addRemoveVendorRoles."))
#endif
    virtual Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::CreateVendorsResponse createOrUpdateVendors ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::VendorProperties >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * This service operation deletes the <b>BidPackageLineItem </b>objects associated with
     * a specific <b>BidPackageRevision</b>. The <b>BidPackageLineItem</b> objects to be
     * deleted are searched with their names provided through the input data structures
     * <code>LineItemProps</code>. Hence there will be one entry in the input vector 'input'
     * per <b>BidPackageLineItem</b> to be deleted. There will be one call each for every
     * <b>BidPackageRevision</b> for which <b>BidPackageLineItem</b> objects are to be deleted.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param input
     *        List of <code>LineItemProps</code> structures which denote the exact <b>BidPackageLineItem</b>
     *        to be deleted. Out of all the members of this structure, name is needed to be populated
     *        as it will be used as the key for search within specified <b>BidPackage</b> Context.
     *
     * @param bidPackage
     *        This is reference to <code>BidPackageProps</code> structure used to define context
     *        to look for <b>BidPackageLineItem</b> objects. ItemId and RevId need to be populated
     *        for this structure to accurately define the <b>BidPackageRevision</b>, which will
     *        be used to look for <b>BidPackageLineItem</b> objects to be deleted.
     *
     * @return
     *         Standard Teamcenter <code>ServiceData</code> structure. It will contain all the partial
     *         errors and failures if any with specific client Ids.
     *         <br>
     *         <br>
     *         Typical Errors possible are:
     *         <br>
     *         <ul>
     *         <li type="disc">Error 48008: <b>BidPackage</b> with given Id not found.
     *         </li>
     *         <li type="disc">Error 48161: Error Multiple <b>BidPackage</b> objects with given
     *         Id found.
     *         </li>
     *         <li type="disc">Error 48014: Specified <b>BidPackageRevision</b> not found.
     *         </li>
     *         <li type="disc">Error 48006: Error in deleting the specific <b>BidPackageLineItem</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteLineItems ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::LineItemProps >& input,
        const Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::BidPackageProps&  bidPackage ) = 0;

    /**
     * This service operation deletes specified <b>VendorRole</b> objects attached with
     * <b>VendorRevision</b> objects mentioned through <code>VendorProperties</code>  data
     * structure. <b>VendorRevision</b> is specified through vendor ID and Revision name
     * in <code>VendorProperties</code>. The combination to be specified thus is '<i>vendorId</i>
     * + <i>revId</i> + <i>roleType</i>'. So, this combination denotes that there will be
     * one instance of <code>VendorProperties</code> per <b>VendorRole</b> to be deleted.
     * In case of <b>VendorRevision</b> is not found based on the Id and Revision key, this
     * operation will return an error.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param input
     *        The input is a list of <code>VendorProperties</code> structures. There will be an
     *        entry for each of the <b>VendorRole</b> objects to be deleted.
     *
     * @return
     *         Standard Teamcenter <code>ServiceData</code> structure. It will contain all the partial
     *         errors and failures such as mentioned below, if any, with specific client Ids.
     *         <br>
     *         <ul>
     *         <li type="disc">In case multiple vendors are found with same ItemId and RevId combination,
     *         the service operation will throw error 48161.
     *         </li>
     *         <li type="disc">Error 229004 will be thrown in case the VendorRole could not be deleted.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of Teamcenter 10, this operation is deprecated in TC 10.0. Replaced by new operation
     *         addRemoveVendorRoles.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, this operation is deprecated in TC 10.0. Replaced by new operation addRemoveVendorRoles."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData deleteVendorRoles ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::VendorProperties >& input ) = 0;

    /**
     * This service operation deletes <b>Vendor</b> objects and associated <b>VendorRevision</b>
     * objects and <b>VendorRole</b> objects. When provided with the input in the form of
     * <code>VendorProperties</code> structure, the operation finds the specified <b>Vendor</b>
     * objects and deletes them. <b>VendorRole</b> objects  will also be deleted along with
     * the associated <b>VendorRevision</b> objects and <b>Vendor</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param input
     *        A list of <code>VectorProperties</code> structures which are used to search for <b>Vendor</b>
     *        objects for deletion operation.
     *
     * @return
     *         The operation returns standard <code>ServiceData</code> object. The partial errors
     *         and failures are updated and returned thru this object. The success of the operation
     *         must be checked through this object only.
     *         <br>
     *         Typical errors possible are:
     *         <br>
     *         <ul>
     *         <li type="disc">Error 48006: Unable to delete the specified <b>Item</b> (<b>Vendor</b>).
     *         </li>
     *         <li type="disc">Error 48035: Error Unable to delete the specified <b>ItemRevision</b>
     *         (<b>VendorRevision</b>).
     *         </li>
     *         <li type="disc">Error 48008: <b>Vendor</b> with specified ID is not found.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteVendors ( const std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::VendorProperties >& input ) = 0;

    /**
     * This service operation can be called on either a <b>VendorPart</b> or a <b>Vendor</b>.
     * <br>
     * <br>
     * For <b>VendorPart</b>: It creates a new copy of <b>VendorPart</b> with the new <b>Vendor</b>
     * information. This newly created <b>VendorPart</b> is associated to the new revision
     * of the <b>CommercialPart</b> of the old <b>VendorPart</b>.
     * <br>
     * For <b>Vendor</b>: All <b>VendorPart</b> objects related with given <b>Vendor</b>
     * are taken into consideration. Each of these <b>VendorPart</b> objects are then processed
     * as mentioned above.
     * <br>
     * <br>
     * This operation shows old and new part id with the information of the success or failure.
     * <br>
     * <br>
     * <b>Typical Client Usage: </b>
     * <br>
     * Typical usage involves two Vendor objects and a VendorPart created with either one
     * of them.
     * <br>
     * <br>
     * <code><b>VendorManagementService vmService =
     * <br>
     * VendorManagementService.getService(session);
     * <br>
     * ChangeVendorInputInfo[]chanProps = new ChangeVendorInputInfo[1];
     * <br>
     * ChangeVendorInputInfo changeProps = new ChangeVendorInputInfo();
     * <br>
     * ChangeVendorResponse response = null;
     * <br>
     * changeProps.newVendor = (TCComponentVendor)newVendor;
     * <br>
     * changeProps.vendorParts=selectedParts;
     * <br>
     * chanProps[0] = changeProps;
     * <br>
     * <br>
     * response = vmService.changeVendor( chanProps );</b></code>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param input
     *        input is a list of <code>ChangeVendorInputInfo</code> structures. If a <b>Vendor</b>
     *        is supplied in the list, all the related parts are processed. If <b>VendorPart</b>
     *        objects are supplied, they are processed one by one for changing <b>Vendor</b>.
     *        <br>
     *        <br>
     *        <b>ChangeVendorInputInfo</b>
     *        <br>
     *        Input structure containing <b>Vendor</b> to change, <b>VendorPart</b> to change and
     *        destination new <b>Vendor</b>.
     *        <br>
     *        <br>
     *        <code>struct ChangeVendorInputInfo
     *        <br>
     *        {
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;Teamcenter::Soa::Client::Model::Vendor* vendorToChange;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;vector< Teamcenter::Soa::Client::Model::Item* > vendorParts;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;Teamcenter::Soa::Client::Model::Vendor* newVendor;
     *        <br>
     *        }</code>
     *        <br>
     *        <br>
     *        <ul>
     *        <li type="disc">vendorToChange&nbsp;&nbsp;&nbsp;&nbsp;This is Object pointing to
     *        the Vendor to change. If this input is specified, all the related VendorPart objects
     *        are processed for change Vendor operation. This input takes precedence over VendorPart
     *        objects input.
     *        </li>
     *        <li type="disc">vendorParts&nbsp;&nbsp;&nbsp;&nbsp;VendorPart objects to be processed
     *        for change Vendor operation.
     *        </li>
     *        <li type="disc">newVendor&nbsp;&nbsp;&nbsp;&nbsp;The new Vendor to be attached to
     *        the part.
     *        </li>
     *        </ul>
     *
     * @return
     *         <code>ChangeVendorResponse</code> structure returned contains information about the
     *         updated <b>VendorParts</b> and their statuses along with the notes if any.
     *         <br>
     *         List of <code>ChangeVendorStatus</code> structure contains:
     *         <br>
     *         A String list of Number of old VendorPart Ids before performing the change <b>Vendor</b>
     *         operation.
     *         <br>
     *         A String list of Number of new VendorPart Ids after performing the change <b>Vendor</b>
     *         operation.
     *         <br>
     *         A String list of Remarks (notes) corresponding to the each change <b>Vendor</b> operation.
     *         e.g. "<i>Success</i>", "<i>Failure</i>".
     *         <br>
     *         <br>
     *         Typical errors returned are:
     *         <br>
     *         <ul>
     *         <li type="disc">Error 229013: Invalid Id supplied for New Vendor
     *         </li>
     *         <li type="disc">Error 229013: Invalid Id for old Vendor to change
     *         </li>
     *         <li type="disc">Error 48005: Cannot create a new VendorPart
     *         </li>
     *         <li type="disc">Error 48043: VendorPart with given credentials already exists
     *         </li>
     *         <li type="disc">Error 229024: Cannot find either Vendor to change or VendorPart objects
     *         to change.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         <br>
     *         <b>ChangeVendorResponse</b>
     *         <br>
     *         Response structure for the operation contains statuses member. It is a list of <code>ChangeVendorStatus</code>
     *         structures.
     *         <br>
     *         <br>
     *         <code>struct ChangeVendorResponse
     *         <br>
     *         {
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;vector<ChangeVendorStatus> statuses;
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;Teamcenter::Soa::Client::ServiceData serviceData;
     *         <br>
     *         }</code>
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">statuses&nbsp;&nbsp;&nbsp;&nbsp;List of ChangeVendorStatus structures.
     *         There is an entry per entry in input structure.
     *         </li>
     *         <li type="disc">serviceData&nbsp;&nbsp;&nbsp;&nbsp;Standard ServiceData structure.
     *         It contains partial errors and failures along with the clientIds.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         <b>ChangeVendorStatus</b>
     *         <br>
     *         This is the structure containing a list of structures for each <b>VendorPart</b>
     *         statuses.
     *         <br>
     *         <br>
     *         <code>struct ChangeVendorStatus
     *         <br>
     *         {
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;vector<ChangedPartStatus> changedStatus;
     *         <br>
     *         }</code>
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">changedStatus&nbsp;&nbsp;&nbsp;&nbsp;This structure contains the
     *         status of VendorPart objects and remarks from the operation.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         <b>ChangedPartStatus</b>
     *         <br>
     *         This is the structure containing a list of statuses for change <b>Vendor</b> operation.
     *         <br>
     *         <br>
     *         <code>struct ChangedPartStatus
     *         <br>
     *         {
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;string oldPartStr;
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;string newPartStr;
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;string notes;
     *         <br>
     *         }</code>
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">oldPartStr&nbsp;&nbsp;&nbsp;&nbsp;Id of old VendorPart.
     *         </li>
     *         <li type="disc">newPartStr&nbsp;&nbsp;&nbsp;&nbsp;Id of new VendorPart created.
     *         </li>
     *         <li type="disc">Notes&nbsp;&nbsp;&nbsp;&nbsp;Remarks (notes) corresponding to the
     *         each change Vendor operation. e.g. "<i>Success</i>" <i>Failure</i>".
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::ChangeVendorResponse changeVendor ( const std::vector< Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::ChangeVendorInputInfo >& input ) = 0;

    /**
     * This service operation returns <b>VendorPart</b> objects  associated with the given
     * <b>CommercialPartRevision</b>  based on the selection rule set for the <b>VendorPart</b>
     * objects in Structure Manager. If no value is given for the selection rule, it is
     * read  from the preference <b>VMS_vendor_part_selection_rule</b>. Typical OOTB selection
     * rules provided are <i>showAllVendorParts</i> and <i>showPreferredVendorPartsOnly</i>.
     * First selection rule is to show all related <b>VendorPart</b> objects and later
     * is used to show the related <b>VendorPart</b> objects carrying <i>preferred</i> status.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Vendor Management - Solution template that provides capability to manage vendor relation
     * information.
     *
     * @param input
     *        List of <code>GetVendorPartsWithSelRuleInputInfo</code> structures containing <b>CommercialPartRevision</b>
     *        objects to be used as input to find related <b>VendorPart</b> objects.  It also contains
     *        condition name string.
     *
     * @return
     *         <code>GetVendorPartsWithSelRuleResponse</code> contains a list of <code>vendorPartData</code>
     *         structures. <code>vendorPartData</code> structure essentially consists of an list
     *         of collection of <b>VendorPart</b> objects and its relation objects with <b>CommercialPartRevision</b>
     *         objects.
     *
     */
    virtual Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::GetVendorPartsWithSelRuleResponse getVendorPartsWithSelRule ( const std::vector< Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::GetVendorPartsWithSelRuleInputInfo >& input ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VendormanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/vendormanagement/Vendormanagement_undef.h>
#endif

