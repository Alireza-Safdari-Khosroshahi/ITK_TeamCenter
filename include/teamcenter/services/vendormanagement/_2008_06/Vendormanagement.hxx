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

#ifndef TEAMCENTER_SERVICES_VENDORMANAGEMENT__2008_06_VENDORMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_VENDORMANAGEMENT__2008_06_VENDORMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ImanRelation.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/Vendor.hxx>


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
            namespace _2008_06
            {
                class Vendormanagement;

class TCSOAVENDORMANAGEMENTSTRONGMNGD_API Vendormanagement
{
public:

    struct ChangedPartStatus;
    struct ChangeVendorInputInfo;
    struct ChangeVendorResponse;
    struct ChangeVendorStatus;
    struct GetVendorPartsWithSelRuleInputInfo;
    struct GetVendorPartsWithSelRuleResponse;
    struct VendorPartAndRel;
    struct VendorPartData;

    /**
     * This structure contains the status of <b>VendorPart</b> objects and remarks from
     * the operation.
     */
    struct ChangedPartStatus
    {
        /**
         * Id of old <b>VendorPart</b>.
         */
        std::string oldPartStr;
        /**
         * Id of new <b>VendorPart</b> created.
         */
        std::string newPartStr;
        /**
         * Remarks (notes) corresponding to the each change <b>Vendor</b> operation. e.g. <i>Success</i>,
         * <i>Failure</i>.
         */
        std::string notes;
    };

    /**
     * Input structure containing <b>Vendor</b> to change, <b>VendorPart</b> to change and
     * destination new <b>Vendor</b>.
     */
    struct ChangeVendorInputInfo
    {
        /**
         * This is Object pointing to the <b>Vendor</b> to change. If this input is specified,
         * all the related <b>VendorPart</b> objects are processed for change <b>Vendor</b>
         * operation. This input takes precedence over <b>VendorPart</b> objects input.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Vendor>  vendorToChange;
        /**
         * <b>VendorPart</b> objects to be processed for change <b>Vendor</b> operation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  > vendorParts;
        /**
         * The new <b>Vendor</b> to be attached to the part.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Vendor>  newVendor;
    };

    /**
     * Response structure for the <code>changeVendor</code> operation contains statuses
     * member. It is a list of <code>ChangeVendorStatus</code> structures.
     */
    struct ChangeVendorResponse
    {
        /**
         * List of <code>ChangeVendorStatus</code> structures. There is an entry per entry in
         * input structure.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::ChangeVendorStatus > statuses;
        /**
         * Standard <code>ServiceData</code> structure. It contains partial errors and failures
         * along with the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This is the structure containing a list of structures for each <b>VendorPart</b>
     * statuses.
     */
    struct ChangeVendorStatus
    {
        /**
         * This is the structure containing a list of statuses for change <b>Vendor</b> operation.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::ChangedPartStatus > changedStatus;
    };

    /**
     * A structure of <b>CommercialPartRevision</b> and condition name.
     */
    struct GetVendorPartsWithSelRuleInputInfo
    {
        /**
         * Selected <b>CommercialPartRevision</b> object from BOM. This revision is used for
         * searching the related <b>VendorPart</b> objects based on selection rule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  comPartRev;
        /**
         * The name of the condition in Teamcenter which is used as a selection rule while finding
         * the <b>VendorPart</b> objects. The service operation will try and search for a valid
         * selection rule based on the condition name. If this input is given as an empty string,
         * the default selection rule is used which is governed by the preference <b>VMS_vendor_part_selection_rule</b>.
         */
        std::string conditionName;
    };

    /**
     * The response structure containing <code>VendorPartData</code> structure which in
     * turn stores information about found <b>VendorPart</b> objects.
     */
    struct GetVendorPartsWithSelRuleResponse
    {
        /**
         * The output structure, which is essentially a list of <code>VendorPartData</code>
         * structures returned. Each of them will contain relation and part information for
         * each <b>VendorPart</b> found.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::VendorPartData > partData;
        /**
         * Standard Teamcenter service response data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure containing a <b>VendorPart</b> object and its relation object to a <b>CommercialPart</b>.
     */
    struct VendorPartAndRel
    {
        /**
         * <b>VendorPart</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  vendorPart;
        /**
         * Each of these <b>VendorPart</b> objects are related to the input <b>CommercialPartRevision</b>
         * with a relation called <b>VMRepresents</b>. This object represents an instance of
         * that relation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  vmRepresentRel;
    };

    /**
     * Structure containing a filtered list of relation and part information for each <b>VendorPart</b>
     * objects.
     */
    struct VendorPartData
    {
        /**
         * It is the vector of <code>VendorPartAndRel</code> objects holding the information
         * of individual <b>VendorPart</b> objects and relation of input <b>CommercialPartRevision</b>
         * with each of them.
         */
        std::vector< Teamcenter::Services::Vendormanagement::_2008_06::Vendormanagement::VendorPartAndRel > partAndRel;
    };




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


protected:
    virtual ~Vendormanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/vendormanagement/Vendormanagement_undef.h>
#endif

