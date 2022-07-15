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

#ifndef TEAMCENTER_SERVICES_RDV__2008_05_CONTEXTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_RDV__2008_05_CONTEXTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/MEAppearancePathNode.hxx>
#include <teamcenter/soa/client/model/NamedVariantExpression.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/rdv/Rdv_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Rdv
        {
            namespace _2008_05
            {
                class Contextmanagement;

class TCSOARDVSTRONGMNGD_API Contextmanagement
{
public:

    struct AddPartSolutionInputInfo;
    struct AddPartSolutionResponse;
    struct GetProductItemResponse;
    struct GetRemoveABEPartsResponse;
    struct OccNotesAttributes;
    struct RemoveABEPartsInputInfo;
    struct ReplacePartSolutionInputInfo;
    struct ReplacePartSolutionResponse;

    /**
     * The information of added part is provided by way of the AddPartSolutionInputInfo
     * data structure.
     */
    struct AddPartSolutionInputInfo
    {
        /**
         * Vector of OccNotesAttributes for each added component
         */
        std::vector< Teamcenter::Services::Rdv::_2008_05::Contextmanagement::OccNotesAttributes > values;
        /**
         * Component to be added
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  component;
        /**
         * BomLine to which the component is to be added
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  abe;
        /**
         * Vector of product revisions for each selected component
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  > prodRevTags;
        /**
         * Appearance Path Node for each added component
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEAppearancePathNode>  abeApnTag;
        /**
         * Vector of authorized NVEs present on ABE
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::NamedVariantExpression>  > aNves;
        /**
         * Quantity of part to be added
         */
        int quantity;
    };

    /**
     * The AddPartSolutionResponse structure represents one output vector AddPartSolutionOutputInfo
     * and the service data.
     */
    struct AddPartSolutionResponse
    {
        /**
         * partSolutionAPNs
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEAppearancePathNode>  > partSolutionAPNs;
        /**
         * serviceData returned as response for retrieving add part to product information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetProductItemResponse</code> structure contains a list of all Product
     * Items found in the database and a <code>ServiceData</code> object.
     */
    struct GetProductItemResponse
    {
        /**
         * A list of  all Product Items found in the database.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  > output;
        /**
         * The <code>ServiceData</code> object containing error codes and error messages in
         * case of failure.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetRemoveABEPartsResponse</code> structure contains the <code>ServiceData</code>
     * object.
     */
    struct GetRemoveABEPartsResponse
    {
        /**
         * The <code>ServiceData</code> containing error codes and error messages along with
         * the indices for which the <code>removePartsRelatedToABE</code> operation fails.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The part data information about each component is provided by way of the OccNotesAttributes
     * data structure.
     */
    struct OccNotesAttributes
    {
        /**
         * Note type for selected component
         */
        std::string noteType;
        /**
         * Note text for selected component
         */
        std::string noteText;
    };

    /**
     * The information to remove parts related to ABE is provided by way of the <code>RemoveABEPartsInputInfo</code>
     * data structure.
     */
    struct RemoveABEPartsInputInfo
    {
        /**
         * The reference to the Appearance Path Node of the Architecture Breakdown Element of
         * which Part Solutions are to be removed. This is a mandatory attribute for the operation
         * to succeed and cannot be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEAppearancePathNode>  abeAPN;
        /**
         * The reference to the topline to which Architecture Breakdown Element is linked. This
         * is a mandatory attribute for the operation to succeed and cannot be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topline;
    };

    /**
     * The information to replace part is provided by way of the ReplacePartSolutionInputInfo
     * data structure.
     */
    struct ReplacePartSolutionInputInfo
    {
        /**
         * Vector of OccNotesAttributes for each added component
         */
        std::vector< Teamcenter::Services::Rdv::_2008_05::Contextmanagement::OccNotesAttributes > values;
        /**
         * Component by which the replacement has been doing
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  component;
        /**
         * Bomline to which the part is to be replaced
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * APN of the associated ABE
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEAppearancePathNode>  abeAPN;
        /**
         * Vector of authorized NVEs present on ABE
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::NamedVariantExpression>  > aNves;
        /**
         * splitAndClone
         */
        bool splitAndClone;
        /**
         * carrySubstitutes
         */
        bool carrySubstitutes;
    };

    /**
     * The ReplacePartSolutionResponse structure represents one output vector ReplacePartSolutionOutputInfo
     * and the service data.
     */
    struct ReplacePartSolutionResponse
    {
        /**
         * component
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  > component;
        /**
         * serviceData returned as response for retrieving replace part in product information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * get the required Information for add part to product.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param inputs
     *        Vector of structure containing the required info to call add part to product
     *
     * @return
     *         contains required info regarding the success of add part to product for the inputs
     *         provided.
     *
     */
    virtual Teamcenter::Services::Rdv::_2008_05::Contextmanagement::AddPartSolutionResponse addPartToProduct ( const std::vector< Teamcenter::Services::Rdv::_2008_05::Contextmanagement::AddPartSolutionInputInfo >& inputs ) = 0;

    /**
     * Returns a list of all Product Items found in the database. The following preferences
     * can be used to define an object as a Product Item.
     * <br>
     * The preference PortalDesignContextProductItemProperties is used to specify one or
     * more of the following properties to be used to define the object as Product Item.
     * Multiple properties could be specified at the same time and the algorithm will check
     * all the specified property values to be satisfied in order to deem an object as a
     * Product Item.
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;object_type
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;object_desc
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;owning_group
     * </li>
     * </ul>
     * <br>
     * For Example: PortalDesignContextProductItemProperties = object_type,object_desc
     * <br>
     * The preference PortalDesignContextProductItemProperties.<property_name>  is used
     * to specify the value to be checked in order to determine whether the object is a
     * Product Item. For example: PortalDesignContextProductItemProperties.object_type =
     * CORP_Vehicle
     * <br>
     * Only an object of type <b>Item</b> or its sub type could be defined as a Product
     * Item. The operation will return empty if any other objects are specified.
     * <br>
     * The default values are
     * <br>
     * PortalDesignContextProductItemProperties = object_type, object_desc
     * <br>
     * PortalDesignContextProductItemProperties.object_type=Item
     * <br>
     * PortalDesignContextProductItemProperties.object_desc=Product
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The <code>getProductItemInfo</code> operation is called when user wants to fetch
     * all Product Items present in the database which are defined by setting the PortalDesignContextProductItemProperties
     * preference.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @return
     *         A <code>GetProductItemResponse</code> object that contains a list of all the product
     *         items present in the database, and a <code>ServiceData</code> object. The <code>GetProductItemResponse</code>
     *         object will contain 0 product items if
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;There are no product items found
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Type other than Item or its sub type is defined
     *         as Product Item
     *         </li>
     *         </ul>
     *         <br>
     *         If PortalDesignContextProductItemProperties preference is set to wrong property or
     *         if there is any other exception, a partial error will be returned.
     *
     */
    virtual Teamcenter::Services::Rdv::_2008_05::Contextmanagement::GetProductItemResponse getProductItemInfo (  ) = 0;

    /**
     * Deletes all the related Part Solutions of an Architecture Breakdown Element (ABE).
     * The links through which the Part solutions are related to the Architecture Breakdown
     * Element are also removed.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The <code>removePartsRelatedToABE</code> operation is called when user wants to remove
     * all part solutions related to Architecture Breakdown Element and their corresponding
     * links. The user can specify the input Architecture Breakdown Element and top line
     * to which the Architecture Breakdown Element is linked using <code>RemoveABEPartsInputInfo</code>
     * object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param inputs
     *        The list of <code>RemoveABEPartsInputInfo</code> objects. Each object contains all
     *        the required information to remove Part Solutions related to the Architecture Breakdown
     *        Element along with configured Part Data information.
     *
     * @return
     *         A <code>GetRemoveABEPartsResponse</code> object that contains a <code>ServiceData</code>
     *         object. If there is any exception during removing of part solutions, it will be added
     *         to the <code>ServiceData</code> object and a partial error will be returned.
     *
     */
    virtual Teamcenter::Services::Rdv::_2008_05::Contextmanagement::GetRemoveABEPartsResponse removePartsRelatedToABE ( const std::vector< Teamcenter::Services::Rdv::_2008_05::Contextmanagement::RemoveABEPartsInputInfo >& inputs ) = 0;

    /**
     * get the required Information for replace part in product.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param inputs
     *        Vector of structure containing the required info to call replace part in product
     *
     * @return
     *         contains required info regarding the success of replace part in product for the inputs
     *         provided.
     *
     */
    virtual Teamcenter::Services::Rdv::_2008_05::Contextmanagement::ReplacePartSolutionResponse replacePartInProduct ( const std::vector< Teamcenter::Services::Rdv::_2008_05::Contextmanagement::ReplacePartSolutionInputInfo >& inputs ) = 0;


protected:
    virtual ~Contextmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/rdv/Rdv_undef.h>
#endif

