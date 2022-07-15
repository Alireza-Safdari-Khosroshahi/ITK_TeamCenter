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

#ifndef TEAMCENTER_SERVICES_VENDORMANAGEMENT__2007_06_VENDORMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VENDORMANAGEMENT__2007_06_VENDORMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BidPackage.hxx>
#include <teamcenter/soa/client/model/BidPackageRevision.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/Part.hxx>
#include <teamcenter/soa/client/model/Vendor.hxx>
#include <teamcenter/soa/client/model/VendorRevision.hxx>
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
            namespace _2007_06
            {
                class Vendormanagement;

class TCSOAVENDORMANAGEMENTSTRONGMNGD_API Vendormanagement
{
public:

    struct BidPackageProps;
    struct CreateBidPacksOutput;
    struct CreateBidPacksResponse;
    struct CreateVendorPartsOutput;
    struct CreateVendorPartsResponse;
    struct CreateVendorsOutput;
    struct CreateVendorsResponse;
    struct LineItemProps;
    struct VendorPartProperties;
    struct VendorProperties;

    /**
     * The information about each <b>BidPackage</b> to be processed is provided by way of
     * the <code>BidPackageProps</code> data structure.
     */
    struct BidPackageProps
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify the Partial Errors
         * associated with this <code>BidPackageProps</code> input.
         */
        std::string clientId;
        /**
         * Id to create <b>BidPackage</b>, generated if the string is empty.
         */
        std::string itemId;
        /**
         * Name for the <b>BidPackage</b>. Default name generated if left empty.
         */
        std::string name;
        /**
         * Object Type to be created. It is <i>BidPackage</i>.
         */
        std::string type;
        /**
         * Revision Id to create <b>BidPackageRevision</b>. Generated if left empty.
         */
        std::string revId;
        /**
         * Description of the object to be created.
         */
        std::string description;
    };

    /**
     * The information about each <b>BidPackage</b> object output after creation is provided
     * by  way of the <code>CreateVendorsOutput</code> data structure.
     */
    struct CreateBidPacksOutput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify the Partial Errors
         * associated with input.
         */
        std::string clientId;
        /**
         * Model Object pointing to the <b>BidPackage</b> created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BidPackage>  bidPackage;
        /**
         * Model Object poinitng to the <b>BidPackageRevision</b> created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BidPackageRevision>  bidPackageRev;
    };

    /**
     * The <code>CreateBidPacksResponse</code> structure represents the output vector <code>CreateBidPacksOutput</code>
     * and standard Teamcenter <code>ServiceData</code> structure instance.
     */
    struct CreateBidPacksResponse
    {
        /**
         * A list of <code>CreateBidPacksOutput</code> structures. Each entry represents a <b>BidPackage</b>
         * created or updated.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::CreateBidPacksOutput > output;
        /**
         * Standard <code>ServiceData</code> structure. It contains typical potential errors
         * as mentioned in throws and failures along with the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The information about each <b>VendorPart</b> object output after creation is provided
     * by way of the <code>CreateVendorPartsOutput</code> data structure.
     */
    struct CreateVendorPartsOutput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify the Partial Errors
         * associated with input.
         */
        std::string clientId;
        /**
         * Model Object pointing to the <b>VendorPart</b> created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Part>  vendorPart;
        /**
         * Model Object poinitng to the <b>VendorPart</b> revision created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  vendorPartRev;
    };

    /**
     * The <code>CreateVendorPartsResponse</code> structure represents the list of <code>CreateVendorPartsOutput</code>
     * and Standard Teamcenter <code>ServiceData</code>.
     */
    struct CreateVendorPartsResponse
    {
        /**
         * Output is list of <code>CreateVendorPartsOutput</code> data structures, each of them
         * representing a new <b>VendorPart</b> created.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::CreateVendorPartsOutput > output;
        /**
         * Standard <code>ServiceData</code> structure. It contains partial errors and failures
         * along with the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The information about each <b>Vendor</b> object output after creation is provided
     * by way of the <code>CreateVendorsOutput</code> data structure.
     */
    struct CreateVendorsOutput
    {
        /**
         * A unique string supplied by the caller.
         */
        std::string clientId;
        /**
         * <b>Vendor</b> Object created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Vendor>  vendor;
        /**
         * <b>VendorRevision</b> Object created or Updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VendorRevision>  vendorRev;
    };

    /**
     * The <code>CreateVendorsResponse</code> structure represents the output vector <code>CreateVendorsOutput</code>
     * and the <code>ServiceData</code>.
     */
    struct CreateVendorsResponse
    {
        /**
         * A list of <code>CreateVendorsOutput</code> structures. Each of them represents a
         * <b>Vendor</b> created or updated.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2007_06::Vendormanagement::CreateVendorsOutput > output;
        /**
         * Standard <code>ServiceData</code> structure. It contains partial errors and failures
         * along with the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The information about each <b>BidPackageLineItem</b> to be processed is provided
     * by way of the <code>LineItemProps</code> data structure.
     */
    struct LineItemProps
    {
        /**
         * Name of the <b>BidPackageLineItem</b> to be created.
         */
        std::string name;
        /**
         * Description of the BidPackageLineItem Object.
         */
        std::string description;
        /**
         * Name of the <b>LineItemConfigContext</b> to be created.
         */
        std::string liccname;
        /**
         * Description for the <code><b>LineItemConfigContext</b></code> object to be created.
         */
        std::string liccdesc;
        /**
         * Id of the part to be associated with <b>BidPackageLineItem</b>.
         */
        std::string partid;
        /**
         * <code>PSViewType</code> to be associated with <b>LineItemConfigContext</b>.
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
         * Variant rule to be associated with LineItemConfigContext.
         */
        std::string varRule;
        /**
         * Closure rule to be associated with LineItemConfigContext.
         */
        std::string closureRule;
        /**
         * Model Object for <b>Quote</b> to be added to <b>BidPackageLineItem</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  quote;
    };

    /**
     * The information about each <b>VendorPart</b> to be processed is provided by way of
     * the <code>VendorPartProperties</code> data structure.
     */
    struct VendorPartProperties
    {
        /**
         * Id for part to be created, mandatory for <b>ManufacturerPart</b> objects but generated
         * for <b>CommercialPart</b> objects if the string is empty. Output PartId in case of
         * <b>ManufacturerPart</b> will contain the provided partId and provided VendorId.
         */
        std::string partId;
        /**
         * Name of the Part object to be created.
         */
        std::string name;
        /**
         * A unique string supplied by the caller. This ID is used to identify the Partial Errors
         * associated with this <code>VendorPartProperties</code> input.
         */
        std::string clientId;
        /**
         * Object type to be created. Only <i>ManufacturerPart</i> and <i>CommercialPart</i>
         * are valid.
         */
        std::string type;
        /**
         * Revision Id specified for create. Generated if the string is empty.
         */
        std::string revId;
        /**
         * Description of the <b>VendorPart</b>.
         */
        std::string description;
        /**
         * <b>Vendor</b> Id to be associated with Part. <b>Vendor</b> Id is optional for <b>CommercialPart</b>
         * but mandatory for <b>ManufacturerPart</b>.
         */
        std::string vendorid;
        /**
         * Id of <b>CommercialPart</b> to be associated with <b>ManufacturerPart</b>.
         */
        std::string commercialpartid;
        /**
         * <b>CommercialPartRevision</b> Id to be associated with <b>ManufacturerPart</b>. If
         * blank, <b>ManufacturerPart</b> is attached with the <b>CommercialPart</b> instead.
         */
        std::string commercialpartrevid;
        /**
         * Flag to decide if the design is required.
         */
        bool isDesignReq;
        /**
         * Unit of Measure for Model Object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  uom;
        /**
         * Make Buy Value for Part. The value could be either <i>Make</i> or <i>Buy</i>.
         */
        int makebuy;
    };

    /**
     * The information about each <b>Vendor</b> to be processed is provided by way of the
     * <code>VendorProperties</code> data structure.
     */
    struct VendorProperties
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify the Partial Errors
         * associated with this <code>VendorProperties</code> input.
         */
        std::string clientId;
        /**
         * <b>Item</b> Id of the <b>Vendor</b>. Generated if the string is empty.
         */
        std::string itemId;
        /**
         * Name of the <b>Vendor</b>. Default name is generated if kept empty.
         */
        std::string name;
        /**
         * Object type to be created.
         */
        std::string type;
        /**
         * <b>VendorRevision</b> Id specified for create. Generated if the string is empty.
         */
        std::string revId;
        /**
         * Description of the <b>Vendor</b>.
         */
        std::string description;
        /**
         * Type of <b>VendorRole</b>. It can be <i>Manufacturer,Supplier, Distributor</i> or
         * blank.
         */
        std::string roleType;
        /**
         * <b>Vendor</b> Certification status like <i>Gold</i>,<i>Silver</i> etc.
         */
        std::string certifiStatus;
        /**
         * <b>Vendor</b> status like <i>Preferred</i>,<i>Approved</i> etc.
         */
        std::string vendorStatus;
    };




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


protected:
    virtual ~Vendormanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/vendormanagement/Vendormanagement_undef.h>
#endif

