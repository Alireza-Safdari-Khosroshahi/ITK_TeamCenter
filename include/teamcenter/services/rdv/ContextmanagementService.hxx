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

#ifndef TEAMCENTER_SERVICES_RDV_CONTEXTMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_RDV_CONTEXTMANAGEMENTSERVICE_HXX

#include <teamcenter/services/rdv/_2008_05/Contextmanagement.hxx>
#include <teamcenter/services/rdv/_2009_04/Contextmanagement.hxx>
#include <teamcenter/services/rdv/_2010_09/Contextmanagement.hxx>
#include <teamcenter/services/rdv/_2012_09/Contextmanagement.hxx>
#include <teamcenter/services/rdv/_2013_05/Contextmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/rdv/Rdv_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Rdv
        {
            class ContextmanagementService;

/**
 * <code>ContextManagement</code> service allows a designer to accurately model specific
 * product assembly configurations and use the results with analytical and visualization
 * tools to facilitate learning and decision making.
 * <br>
 * <br>
 * The <b>Design Context</b> application allows the user to quickly focus on a particular
 * work part in the <b>Context Management</b> environment and any other parts affected
 * within the context of a change to that part.
 * <br>
 * <br>
 * When you have identified your parts, you can view them in the embedded viewer in
 * <b>Structure Manager</b> or a <b>CAD tool</b> or send them to <b>Lifecycle Visualization</b>.
 * You can also perform <b>clearance analysis</b> in <b>Structure Manager</b> or <b>Lifecycle
 * Visualization</b>. <b>Design Context</b> also interoperates with <b>Platform Designer</b>
 * to manage changes to the design solutions in the product.
 * <br>
 * <br>
 * The <code>ContextManagement</code> service provides operations to carry out the following
 * context management related use-cases.
 * <br>
 * <br>
 * 1)&nbsp;&nbsp;&nbsp;&nbsp;<b>Retrieve product context information</b>
 * <br>
 * 2)&nbsp;&nbsp;&nbsp;&nbsp;<b>Manage the objects that are used to store the search
 * criteria information</b>
 * <br>
 * <br>
 * <b>Retrieve the Product Context Information</b>:  The <code>ContextManagement</code>
 * service provides the <code>getProductItemInfo</code> operation, which can be used
 * to retrieve all the <b>Product Context</b> objects that are available in the database.
 * The Product Context is an item of type <b>Item</b> or subtype whose properties satisfy
 * the values specified through preference settings of the <b>PortalDesignContextProductItemProperties</b>
 * preference. Please refer to the operation documentation for more detailed information.
 * <br>
 * <br>
 * <b>Manage the search criteria persistence objects</b>: The context management service
 * provides a set of operations, which can be used to maintain a <b>structure context</b>
 * object. A<b> structure context</b> object is a top level container that houses all
 * the information related to search criterion specified for multiple search criteria.
 * <br>
 * <br>
 * This service also provides an operation to create <b>SearchStructureContext</b> object
 * which is a subtype of the structure context object and provides support for saving
 * additional information such as scope of the search etc.,
 * <br>
 * <br>
 * In addition to the <b>search criteria</b> objects the service provides an operation
 * to create the search criteria for the <b>Form attribute</b> based search criteria
 * and the scope criteria used in the search.  Currently SOA operations are not available
 * for storing any other types of search criteria objects. All other search criteria
 * could currently be managed through operations in the legacy ICT layer.
 * <br>
 * <br>
 * The <code>ContextManagement</code> service also provides an operation to get the
 * ICS Class Names as required in the classification search. However, this operation
 * would need to be used in conjunction with current ICT layer calls that are available
 * to create the Classification Attribute Based search criteria persistence objects.
 * <br>
 * <br>
 * The steps in creating the search criteria object are mentioned below
 * <br>
 * <br>
 * 1)&nbsp;&nbsp;&nbsp;&nbsp;Perform a <b>Form Attribute Based</b> Search.
 * <br>
 * 2)&nbsp;&nbsp;&nbsp;&nbsp;Capture the <b>search criteria</b> from the UI using existing
 * data structure in the UI code.
 * <br>
 * 3)&nbsp;&nbsp;&nbsp;&nbsp;Convert the search criteria into the data structure accepted
 * by the <code>createFormAttrSearchCriteria</code>.
 * <br>
 * 4)&nbsp;&nbsp;&nbsp;&nbsp;Invoke the <code>createFormAttrSearchCriteria</code> to
 * create the <b>search criteria</b> object.
 * <br>
 * 5)&nbsp;&nbsp;&nbsp;&nbsp;Group the search criteria object into a <b>search criteria
 * grouping</b> object. SOA is unavailable for performing this step currently. We need
 * to use an ICT call for this function.
 * <br>
 * 6)&nbsp;&nbsp;&nbsp;&nbsp;Use the grouping object tag along with other criteria information
 * that forms the overall context of the search and create a structure context object.
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * StructureManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoardvstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoardvtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOARDVSTRONGMNGD_API ContextmanagementService
    : public Teamcenter::Services::Rdv::_2008_05::Contextmanagement,
             public Teamcenter::Services::Rdv::_2009_04::Contextmanagement,
             public Teamcenter::Services::Rdv::_2010_09::Contextmanagement,
             public Teamcenter::Services::Rdv::_2012_09::Contextmanagement,
             public Teamcenter::Services::Rdv::_2013_05::Contextmanagement
{
public:
    static ContextmanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * Get the required information for display of part solutions of selected GBE and its
     * instantiating ABE.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param goBomLine
     *        contains selected GBE bomline
     *
     * @return
     *         Contains vector of APN of line of usages (part solution) and            instantiating
     *         architecture bom window
     *
     */
    virtual Teamcenter::Services::Rdv::_2009_04::Contextmanagement::GetGOPartSolutionsResponse getAllGOPartSolutions ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  goBomLine ) = 0;

    /**
     * This operation pastes source <b>Architecture Breakdown Element</b> (ABE) <b>BOMLine</b>
     * to the target <b>Architecture Breakdown </b>(AB) <b>BOMLine</b>. It pastes all the
     * parents (up to top level AB) of the source ABE under target AB. This operation also
     * copies the variability, Named Variant Expressions (NVEs) and part solutions from
     * the source <b>BOMLine</b> to target <b>BOMLine</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used to paste the source Architecture Breakdown Element <b>BOMLine</b>
     * to target Architecture Breakdown <b>BOMLine</b>.
     * <br>
     * <br>
     * Use case 1: Copy variability
     * <br>
     * User needs to set flag value as 1 in GetPastePrimeInfo structure to copy only the
     * variability from the source <b>BOMLine</b> to target <b>BOMLine</b>.
     * <br>
     * <br>
     * Use case 2: Copy variability and NamedVariantExpressions
     * <br>
     * User needs to set flag value as 2 in GetPastePrimeInfo structure to copy the variability
     * and Named Variant Expressions from the source <b>BOMLine</b> to target <b>BOMLine</b>.
     * <br>
     * <br>
     * Use case 3: Copy variability, NamedVariantExpressions and part solutions
     * <br>
     * User needs to set flag value as 3 in GetPastePrimeInfo structure to copy the variability,
     * Named Variant Expressions and part solutions from the source <b>BOMLine</b> to target
     * <b>BOMLine</b>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param input
     *        Reference to <code>GetPastePrimeInfo</code> object which contains the list of source
     *        and target <b>BOMLine</b> and a flag to indicate which attributes needs to be copied
     *        from the source <b>BOMLine</b> to target <b>BOMLine</b>.
     *
     * @return
     *         Returns the <code>ServiceData</code> object. If there is any exception during this
     *         operation it will be added to the <code>ServiceData</code> object and returned as
     *         a partial error.
     *         <br>
     *         Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM module
     *         </li>
     *         <li type="disc">46000 Internal error in BOM module
     *         </li>
     *         <li type="disc">38041 An invalid object is being used in conjunction with property
     *         </li>
     *         <li type="disc">46024 You cannot have variants of the top line of the BOM
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData getPastePrimeAttributes ( const Teamcenter::Services::Rdv::_2009_04::Contextmanagement::GetPastePrimeInfo&  input ) = 0;

    /**
     * Creates the Structure Context Object (SCO) based on the inputs supplied. It creates
     * an SCO object and then sets the following properties on SCO object created: Product
     * Item Revision, Revision Rule, Variant Rule, Work parts selected, Search Criteria
     * Group, Target and Background <b>BOMLine</b> objects from the input structure. This
     * SCO will contain the Item, Item revisions, Target <b>BOMLine</b> objects, Background
     * <b>BOMLine</b> objects. The operation is designed to support multiple SCOs creations
     * in a single call. (Limitation: Though this operation can create multiple SCO objects
     * however it can return reference of only one object). The operation will initially
     * create the SCO object using the name, type and description. Subsequently it would
     * set the additional parameters supplied through the input structure. SCO object would
     * still be created and saved even if setting of the additional parameters is not successful.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>1. Create an SCO</b>
     * <br>
     * YouYou can create a new SCO object of type <b>VisStructureContext</b> using <code>createSCO</code>
     * operation by providing the <code>CreateSCOInputInfo</code> structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param inputs
     *        An object of <b>StructureContext</b> is created for each <code>CreateSCOInputInfo</code>
     *        object  in the inputs list. The data in the <code>CreateSCOInputInfo</code> like
     *        SCO type, name, and description along with search related criteria is used to create
     *        object of <b>StructureContext</b>.
     *
     * @return
     *         <code>CreateSCOResponse</code> object, this object contains newly created <b>StructureContext</b>
     *         object and <code>ServiceData</code>. If there is any exception during the object
     *         creation it will be added to <code>ServiceData</code> object and will be returned
     *         as partial error.
     *         <br>
     *         <br>
     *         Following are some possible errors returned in <code>ServiceData</code> object:
     *         <br>
     *         <ul>
     *         <li type="disc">202017&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The class cannot
     *         be instantiated.
     *         </li>
     *         <li type="disc">7005&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *         enquiry cannot be executed.
     *         </li>
     *         <li type="disc">202023&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The attribute
     *         of object cannot be retrieved.
     *         </li>
     *         <li type="disc">202024&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *         cannot be found.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2010_09::Contextmanagement::CreateSCOResponse createSCO ( const std::vector< Teamcenter::Services::Rdv::_2010_09::Contextmanagement::CreateSCOInputInfo >& inputs ) = 0;

    /**
     * Updates the Structure Context Object (SCO) based on the inputs attributes. It sets
     * the following properties on SCO object which is to be modified: Product Item Revision,
     * Revision Rule, Variant Rule, Work parts, Search Criteria Group, Target and Background
     * <b>BOMLine</b> objects from the input structure. This SCO will contain the Item,
     * Item revisions, Target <b>BOMLine</b> objects, Background <b>BOMLine</b> objects.
     * The operation is designed to support multiple SCOs creations in a single call. (Limitation:
     * Though this operation can update multiple SCO objects however it can return reference
     * of only one object). This operation first checks for the local ownership of the object
     * to be updated. This operation will fail if null or incorrect reference to existing
     * SCO object is passed in the input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1. Update an SCO
     * <br>
     * You can update an SCO object of type <b>VisStructureContext</b> using <code>updateSCO</code>
     * operation by providing the <code>UpdateSCOInputInfo</code> structure.
     * <br>
     * <ul>
     * <li type="disc">Create an SCO, object of <b>StructureContext</b>, using the <code>createSCO</code>
     * operation.
     * </li>
     * <li type="disc">Retrieve the reference to <b>StructureContext</b> returned from above
     * step.
     * </li>
     * <li type="disc">Modify the required search criteria and populate the <code>UpdateSCOInputInfo</code>
     * structure.
     * </li>
     * <li type="disc">Call <code>updateSCO</code> which will modify the existing <b>StructureContext</b>
     * object.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createSCO
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param inputs
     *        An object of <b>StructureContext</b> is updated for each <code>UpdateSCOInputInfo</code>
     *        in the inputs list. The data in the <code>UpdateSCOInputInfo</code> object is used
     *        for updation.
     *
     * @return
     *         <code>UpdateSCOResponse</code> object, this object contains <b>StructureContext</b>
     *         object updated by this operation and <code>ServiceData</code> object. If there is
     *         any exception during the object updation it will be added to <code>ServiceData</code>
     *         object and will be returned as partial error.<b>
     *         <br>
     *         <br>
     *         </b>Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">202217&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The Structure
     *         Context object cannot be saved, since its ownership is not transferred from the owning
     *         site.
     *         </li>
     *         <li type="disc">202017&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The class cannot
     *         be instantiated.
     *         </li>
     *         <li type="disc">7005&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *         enquiry cannot be executed.
     *         </li>
     *         <li type="disc">202023&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The attribute
     *         of object cannot be retrieved
     *         </li>
     *         <li type="disc">202024&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *         cannot be found.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2010_09::Contextmanagement::UpdateSCOResponse updateSCO ( const std::vector< Teamcenter::Services::Rdv::_2010_09::Contextmanagement::UpdateSCOInputInfo >& inputs ) = 0;

    /**
     * Creates a list of Form Search Criteria objects based on the input parameters. It
     * uses the following inputs from the input structure
     * <br>
     * <ul>
     * <li type="disc">Form type
     * </li>
     * <li type="disc">Parent Type
     * </li>
     * <li type="disc">Name of the property
     * </li>
     * <li type="disc">Type of the property
     * </li>
     * <li type="disc">Relation type
     * </li>
     * <li type="disc">Operator and
     * </li>
     * <li type="disc">Search value
     * </li>
     * </ul>
     * <br>
     * Form Search Criteria object is created as part of creation of the <b>VisStructureContext</b>
     * object to persist form attribute search criteria.
     * <br>
     * It is mandatory to provide all the input parameters. This operation will fail if
     * null is provided for any of the string input parameters. The Form type or Relation
     * type input should be valid string representing the name of a type in Teamcenter database.
     * Empty string for Form type or Relation type input will cause the operation to fail.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1. Creating an Structure Context Oject(SCO)
     * <br>
     * While pesristing the search criterias in Structure Context Oject, <code>createFormAttrSearchCriteria</code>
     * operation is called to persist the Form serach criteria related information . You
     * can create this object by providing the <code>CreateFormAttrSearchCriteriaInputInfo</code>
     * structure. This form search criteria object is wrapped in Appearance Search Criteria
     * Group object and stored in <b>StructureContext</b> object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param inputs
     *        An object of Form Search Criteria is created for each <code>CreateFormAttrSearchCriteriaInputInfo</code>
     *        in the inputs list. The data on the <code>CreateFormAttrSearchCriteriaInputInfo</code>
     *        is used to create object of Form Search Criteria.
     *
     * @return
     *         <code>CreateFormAttrSearchCriteriaResponse</code> object, this object contains list
     *         of newly created Form Search Criteria objects, one for each successfully created
     *         Form Search Criteria object and <code>ServiceData</code> object. If there is any
     *         exception during the object creations it will be added to the <code>ServiceData</code>
     *         object and returned as a partial error. If the creation of an object fails, then
     *         error code 202017 is returned as a partial error.
     *
     *
     * @exception ServiceException
     *           Following are some possible errors returned in <code>ServiceData</code>:
     *           <br>
     *           <ul>
     *           <li type="disc">202017&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The class cannot
     *           be instantiated.
     *           </li>
     *           <li type="disc">39007&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *           name is invalid for a type.
     *           </li>
     *           <li type="disc">39014&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *           type does not exist.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Rdv::_2012_09::Contextmanagement::CreateFormAttrSearchCriteriaResponse createFormAttrSearchCriteria ( const std::vector< Teamcenter::Services::Rdv::_2012_09::Contextmanagement::CreateFormAttrSearchCriteriaInputInfo >& inputs ) = 0;

    /**
     * This operation creates the <b>Fnd0ApprSchCriteriaScpAttr</b> object (ScpSrchCriteria)
     * based on the inputs supplied. It creates a Scope Search Criteria object and stores
     * the scope of the search. Scope Search Criteria object is created as part of the creation
     * of the <b>SearchStructureContext</b> object to persist the scope of the search.
     * <br>
     * If the input contains APNs or <b>BOMLine</b> objects, then these are saved in either
     * appearance path nodes list or occurrence list property depending on the value of
     * RDV_CREATE_SCO_WITHOUT_APN preference. If the input contains appearance groups, these
     * are stored in occurrence group list property of ScpSrchCriteria object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1. Creating a Search Search Criteria
     * <br>
     * While persisting the search criteria in Search Structure Context object, <code>createSearchCriteriaScope</code>
     * operation is called to persist the scope of the search. User can create this object
     * by providing the <code>CreateSearchCriteriaScopeInfo</code> structure. This scope
     * search criteria object is wrapped in Appearance Search Criteria Group object and
     * stored in <b>SearchStructureContext</b> object.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param inputs
     *        An object of <b>Fnd0ApprSchCriteriaScpAttr</b> is created for each <code>CreateSearchCriteriaScopeInfo</code>
     *        in the inputs list. The data in the <code>CreateSearchCriteriaScopeInfo</code> like
     *        <b>BOMLine</b> objects and appGrps is used to create object of <b>Fnd0ApprSchCriteriaScpAttr</b>.
     *
     * @return
     *         <code>CreateSearchCriteriaScpResponse</code> object, this object contains newly created
     *         <b>Fnd0ApprSchCriteriaScpAttr</b> objects, one for each successfully created Scope
     *         Search Criteria object and <code>ServiceData</code> object. If there is any exception
     *         during the object creation it will be added to <code>ServiceData</code> object and
     *         will be returned as partial error.
     *         <br>
     *         Following are some possible errors returned in <code>ServiceData</code> object:
     *         <br>
     *         <ul>
     *         <li type="disc">202017&nbsp;&nbsp;&nbsp;&nbsp;    The class cannot be instantiated.
     *         </li>
     *         <li type="disc">39007        The specified name is invalid for a type.
     *         </li>
     *         <li type="disc">39014        The specified type does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2012_09::Contextmanagement::CreateSearchCriteriaScpResponse createSearchCriteriaScope ( const std::vector< Teamcenter::Services::Rdv::_2012_09::Contextmanagement::CreateSearchCriteriaScopeInfo >& inputs ) = 0;

    /**
     * Creates the <b>SearchStructureContext</b> object (SearchSCO) based on the inputs
     * supplied. It creates a SearchSCO object and then sets the following properties on
     * SearchSCO object created: Product Item Revision, Revision Rule, Variant Rule, Work
     * parts selected, Search Criteria Group, Target and Background <b>BOMLine</b> objects
     * from the input structure, result stored status, object shared status. This SearchSCO
     * will contain the Item, Item revisions, Target <b>BOMLine</b> objects, Background
     * <b>BOMLine</b> objects. The operation is designed to support multiple SearchSCOs
     * creation in a single call. The operation will initially create the SearchSCO object
     * using the name, type and description. Subsequently it would set the additional parameters
     * supplied through the input structure. SearchSCO object would still be created and
     * saved even if setting of the additional parameters is not successful.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1. Create a Search SCO
     * <br>
     * You can create a new SCO object of type <b>SearchStructureContext</b> using <code>createSearchSCO</code>
     * operation, by providing the <code>CreateSearchSCOInputInfo</code> structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param inputs
     *        An object of <b>SearchStructureContext</b> is created for each <code>CreateSearchSCOInputInfo</code>
     *        in the inputs list. The data in the <code>CreateSearchSCOInputInfo</code> like name
     *        and description along with search related information is used to create object of
     *        <b>SearchStructureContext</b>.
     *
     * @return
     *         <code>CreateSearchSCOResponse</code> object, this object contains newly created <b>SearchStructureContext</b>
     *         objects and <code>ServiceData</code> object. If there is any exception during the
     *         object creation it will be added to <code>ServiceData</code> object and will be returned
     *         as partial error.
     *         <br>
     *         Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">202017&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The class cannot
     *         be instantiated.
     *         </li>
     *         <li type="disc">7005&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *         enquiry cannot be executed.
     *         </li>
     *         <li type="disc">202023&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The attribute
     *         of object cannot be retrieved.
     *         </li>
     *         <li type="disc">202024&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *         cannot be found.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2012_09::Contextmanagement::CreateSearchSCOResponse createSearchSCO ( const std::vector< Teamcenter::Services::Rdv::_2012_09::Contextmanagement::CreateSearchSCOInputInfo >& inputs ) = 0;

    /**
     * Creates a list of ICS class names for the <b>ApprSearchCriteriaInClass</b> objects
     * passed in the input. Object of ICS class is stored inside <b>ApprSearchCriteriaInClass</b>
     * object and this is persisted along with other search criteria in Structure Context
     * object (SCO). During replay of SCO, in order to reconstruct the Classification object
     * this operation is called to get the class name. Using this class name ICS object
     * is recreated at client side. This method is required because the classification object
     * cannot be retrieved in its original format from the SCO object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>1. Replaying an SCO</b>
     * <br>
     * You can reconstruct the classification object stored in SCO using the class name
     * returned from the <code>getICSClassNames</code> operation by providing the reference
     * to the <b>ApprSearchCriteriaInClass</b> object.
     * <br>
     * <ul>
     * <li type="disc">Create an SCO, object of <b>StructureContext</b>, using the <code>createSCO</code>
     * operation.
     * </li>
     * <li type="disc">Retrieve the reference to <b>StructureContext</b> returned from above
     * step.
     * </li>
     * <li type="disc">Fetch the reference of <b>ApprSearchCriteriaInClass</b> stored in
     * the Appearance Grouping object.
     * </li>
     * <li type="disc">Provide the object retrieved above to <code>getICSClassNames</code>
     * operation.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param searchCriteriaInClass
     *        List of Appearance InClass Search Criteria, i.e. <b>ApprSearchCriteriaInClass</b>,
     *        object for which ICS class names are to be fetched.
     *
     * @return
     *         <code>GetICSClassNamesResponse</code> object, this object contains list of ICS class
     *         names corresponding to the class objects stored in the <b>ApprSearchCriteriaInClass</b>
     *         object and <code>ServiceData</code> object. If there is any exception during the
     *         object creation it will be added to <code>ServiceData</code> object and returned
     *         as partial error.
     *
     *
     * @exception ServiceException
     *           Following are some possible errors returned in <code>ServiceData</code>:
     *           <br>
     *           <ul>
     *           <li type="disc">202023&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The attribute
     *           of object cannot be retrieved
     *           </li>
     *           <li type="disc">202024&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *           cannot be found.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Rdv::_2012_09::Contextmanagement::GetICSClassNamesResponse getICSClassNames ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ApprSearchCriteriaInClass>  >& searchCriteriaInClass ) = 0;

    /**
     * Updates the Search Structure Context Object (SearchSCO) based on the inputs attributes.
     * It sets the following properties on SearchSCO object which is to be modified: Product
     * Item Revision, Revision Rule, Variant Rule, Work parts selected, Search Criteria
     * Group, Target and Background <b>BOMLine</b> objects, and result status from the input
     * structure. This SearchSCO will contain the Item, Item revisions, Target <b>BOMLine</b>
     * objects, Background <b>BOMLine</b> objects. The operation is designed to support
     * multiple SearchSCOs creation in a single call. This operation first checks for the
     * local ownership of the object to be updated. This operation will fail if null or
     * incorrect reference to existing SearchSCO object is passed in the input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can update an SCO object of type <b>SearchStructureContext</b> using <code>updateSearchSCO</code>
     * operation by providing the <code>UpdateSearchSCOInputInfo</code> structure.
     * <br>
     * <ul>
     * <li type="disc">Create an SCO, object of <b>SearchStructureContext</b>, using the
     * <code>createSearchSCO</code> operation.
     * </li>
     * <li type="disc">Retrieve the reference to <b>SearchStructureContext</b> returned
     * from above step.
     * </li>
     * <li type="disc">Modify the required search criteria and populate the <code>UpdateSearchSCOInputInfo</code>
     * structure.
     * </li>
     * <li type="disc">Call <code>updateSearchSCO</code> which will modify the existing
     * <b>SearchStructureContext</b> object.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param inputs
     *        An object of <b>SearchStructureContext</b> is updated for each <code>UpdateSearchSCOInputInfo</code>
     *        in the inputs list. The data in the <code>UpdateSearchSCOInputInfo</code> object
     *        is used for updating.
     *
     * @return
     *         <code>UpdateSearchSCOResponse</code> object, this object contains <b>SearchStructureContext</b>
     *         object updated by this operation and <code>ServiceData</code>. If there is any exception
     *         while updating the object it will be added to <code>ServiceData</code> object and
     *         will be returned as partial error.
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">202217&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The Search
     *         Structure Context object cannot be saved, since its ownership is not transferred
     *         from the owning site.
     *         </li>
     *         <li type="disc">202017&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The class cannot
     *         be instantiated.
     *         </li>
     *         <li type="disc">7005&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *         enquiry cannot be executed.
     *         </li>
     *         <li type="disc">202023&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The attribute
     *         of object cannot be retrieved
     *         </li>
     *         <li type="disc">202024&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *         cannot be found.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2012_09::Contextmanagement::UpdateSearchSCOResponse updateSearchSCO ( const std::vector< Teamcenter::Services::Rdv::_2012_09::Contextmanagement::UpdateSearchSCOInputInfo >& inputs ) = 0;

    /**
     * This operation finds all the business objects that are within the current active
     * context of the list of objects sent as input. The objects within context are objects
     * of the types specified below that are related to the input object either through
     * reference or relation.
     * <br>
     * <ul>
     * <li type="disc"><b>Items</b>
     * </li>
     * <li type="disc"><b>Processes</b>
     * </li>
     * <li type="disc"><b>ChangeRequestRevision</b>
     * </li>
     * <li type="disc"><b>StructureContext</b>
     * </li>
     * <li type="disc"><b>AppearanceGroup</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <br>
     * The RDV module maintains a state that defines the currently active context. A combination
     * of one or more of the following objects defines the current active context.
     * <br>
     * <ul>
     * <li type="disc"><b>WorkpartItem</b>
     * </li>
     * <li type="disc"><b>Process</b>
     * </li>
     * <li type="disc"><b>ChangeRequestRevision</b>
     * </li>
     * <li type="disc"><b>ConfigurationContext</b>
     * </li>
     * <li type="disc"><b>StructureContext</b>
     * </li>
     * <li type="disc"><b>AppearanceGroup</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <br>
     * Every time this operation is invoked, the objects in the current context are refreshed.
     * <br>
     * This operation is mainly used for adding work parts, EngChange revisions and processes
     * to the Design Context application.
     * <br>
     * The following criteria is used to determine the objects related to the inputs:
     * <br>
     * <br>
     * 1) Item objects that are attached with the ChangeRequestRevision, Process objects
     * through the relation type mentioned in the preferences listed below.
     * <br>
     * <br>
     * <code>PortalDesignContextProcess.WorkPartOrChangeAttachmentTypes</code>
     * <br>
     * <code>PortalDesignContextECObject.WorkPartRelationships</code>
     * <br>
     * <br>
     * <br>
     * 2) Item objects that are associated with the EPM job where the input object is also
     * a part of the EPM job.
     * <br>
     * <br>
     * 3) Item objects that are part of the same ConfigurationContext object, StructureContext
     * object or an AppearanceGroup object as that of the input objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: If user enters an item ID in the WorkParts text field in DesignContext
     * application. The Design Context application uses this operation to display the item
     * revision in the WorkParts list, and any changes or processes that reference the item
     * revision in the EngChange Revision and Processes lists.
     * <br>
     * <br>
     * Use Case 2: If user enters a change ID in the EngChange Revision text field DesignContext
     * application. The DesignContext application uses this operation to add the change
     * object to the EngChange Revision list, and any item revisions or processes referenced
     * by the change object are displayed in the WorkParts and Processes lists. If the change
     * references revisions of Product Items, Teamcenter automatically adds them to the
     * Selected Product Context list.
     * <br>
     * <br>
     * Use Case 3: If user enters a process name in Processes test field DesignContext application.
     * The DesignContext application uses this operation to add the process object to the
     * Processes list, and any objects targeted by the process are displayed in the WorkParts
     * and EngChange lists.
     * <br>
     * <br>
     * The items in the WorkPart lists can then be selected by the user for carrying out
     * the design validation analysis.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param objectList
     *        List of objects for which the related objects in the current active context are to
     *        be found.
     *        <br>
     *        The list may contain the following objects based on the input:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>Items</b>
     *        </li>
     *        <li type="disc"><b>Processes</b>
     *        </li>
     *        <li type="disc"><b>ChangeRequestRevision</b>
     *        </li>
     *        <li type="disc"><b>StructureContext</b>
     *        </li>
     *        <li type="disc"><b>AppearanceGroup</b>
     *        </li>
     *        </ul>
     *
     * @return
     *         The map of <b>Item</b>, <b>Process</b> <b>and ChangeRequestRevision</b> objects that
     *         are related to input objects in current active context.
     *         <br>
     *         <br>
     *         The following partial errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">202003 If no related object is found for the current input object.
     *         </li>
     *         <li type="disc">202004 If the number of objects added to result list exceeds the
     *         value set in <b>PortalDesignContextMaxMatchingObjects</b> preference.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2013_05::Contextmanagement::ContextObjectResponse getRelatedObjectsInContext ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objectList ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ContextmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/rdv/Rdv_undef.h>
#endif

