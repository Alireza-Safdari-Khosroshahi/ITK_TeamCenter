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

#ifndef TEAMCENTER_SERVICES_RDV__2012_09_CONTEXTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_RDV__2012_09_CONTEXTMANAGEMENT_HXX

#include <teamcenter/services/rdv/_2010_09/Contextmanagement.hxx>
#include <teamcenter/soa/client/model/ApprSearchCriteriaInClass.hxx>
#include <teamcenter/soa/client/model/Fnd0ApprSchCriteriaFormAttr.hxx>
#include <teamcenter/soa/client/model/Fnd0ApprSchCriteriaScpAttr.hxx>
#include <teamcenter/soa/client/model/SearchStructureContext.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2012_09
            {
                class Contextmanagement;

class TCSOARDVSTRONGMNGD_API Contextmanagement
{
public:

    struct CreateFormAttrSearchCriteriaInputInfo;
    struct CreateFormAttrSearchCriteriaResponse;
    struct CreateSearchCriteriaScopeInfo;
    struct CreateSearchCriteriaScpResponse;
    struct CreateSearchSCOInputInfo;
    struct CreateSearchSCOResponse;
    struct GetICSClassNamesResponse;
    struct UpdateSearchSCOInputInfo;
    struct UpdateSearchSCOResponse;

    /**
     * Specifies the full set of inputs required to create the Form Search Criteria object.
     */
    struct CreateFormAttrSearchCriteriaInputInfo
    {
        /**
         * Type name of Relation with which Form is attached to an Item/Item Revision. (For
         * example: References). The valid relation types can be fetched from BMIDE: Open BMIDE->Go
         * to Business Objects View->Search for <b>ImanRelation</b>->Expand <b>ImanRelation</b>.
         * The name of any object listed as child of <b>ImanRelation</b>, can be supplied.
         */
        std::string relationtype;
        /**
         * Boolean value indicating type of parent (true if the parent type is Item and false
         * if the parent type is Item Revision)
         */
        bool parentType;
        /**
         * Type name of Form being used for the search. The valid form type can be fetched from
         * BMIDE: Open BMIDE->Go to Business Objects View->Search for Form. The name of any
         * object listed as child of 'Form' can be supplied.
         */
        std::string formType;
        /**
         * Logical operator. The only valid operator currently supported is 'AND'.
         */
        std::string logicalOpr;
        /**
         * Name of the selected property on the form used for the search.
         */
        std::string propertyName;
        /**
         * Operator used for comparison. List of valid operators:
         * <br>
         * <ul>
         * <li type="disc">'EQ' - Equal
         * </li>
         * <li type="disc">'NE' - Not Equal
         * </li>
         * <li type="disc">'GT' - Greater Than
         * </li>
         * <li type="disc">'GE' - Greater Than or Equal
         * </li>
         * <li type="disc">'LT' - Less Than
         * </li>
         * <li type="disc">'LE' - Less Than or Equal
         * </li>
         * <li type="disc">'LIKE'
         * </li>
         * <li type="disc">'NOT LIKE'
         * </li>
         * </ul>
         */
        std::string mathOpr;
        /**
         * Name of the type of property. The valid string values for this member are:
         * <br>
         * <ul>
         * <li type="disc">'BooleanType' - For Boolean Property
         * </li>
         * <li type="disc">'DateType' - For Date Property
         * </li>
         * <li type="disc">'IntegerType' - For Integer Property
         * </li>
         * <li type="disc">'StringType' - For String Property
         * </li>
         * <li type="disc">'DoubleType' - For Double Property
         * </li>
         * <li type="disc">'TagType' - For Tag Property
         * </li>
         * </ul>
         */
        std::string propertyType;
        /**
         * List of string values used for the search. Each value specified here would be an
         * appropriate value for the property specified in 'propertyName' parameter. These &nbsp;&nbsp;&nbsp;&nbsp;values
         * are passed in string format and converted back to their original format based on
         * the 'propertyType' parameter specified above.
         */
        std::vector< std::string > values;
    };

    /**
     * Contains the list of newly created <b>Fnd0ApprSchCriteriaFormAttr</b> objects and
     * <code>ServiceData</code> object
     */
    struct CreateFormAttrSearchCriteriaResponse
    {
        /**
         * List of newly created <b>Fnd0ApprSchCriteriaFormAttr</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ApprSchCriteriaFormAttr>  > formAttrSchCriteria;
        /**
         * An object of <code>ServiceData</code> which contains any exceptions if occurred during
         * creation of Form attribute object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure is used to store the list of scope <b>BOMLine</b> objects and the
     * Apprearance Goup objects.
     */
    struct CreateSearchCriteriaScopeInfo
    {
        /**
         * List of all the scope <b>BOMLine</b> objects. If the search is performed on occurrence
         * group object then this list will be empty.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > nodes;
        /**
         * It is a vector of BusinessObjects. If search is performed on one or more Occurrence
         * group <b>BOMLine</b> objects then this list should have those occurrence group objects.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > collections;
    };

    /**
     * This structure is used to store information about the newly created <b>Fnd0ApprSchCriteriaScpAttr</b>
     * objects and <code>ServiceData</code> object after execution of the operation <code>createSearchCriteriaScope</code>.
     */
    struct CreateSearchCriteriaScpResponse
    {
        /**
         * The list of objects of <b>Fnd0ApprSchCriteriaScpAttr</b> created by the <code>createSearchCriteriaScope</code>
         * action.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ApprSchCriteriaScpAttr>  > searchCriteriaScpObjects;
        /**
         * An object of <code>ServiceData</code> which contains any exceptions if occurred during
         * the creation of Scope Search Criteria object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure is used to store additional information about a SCO object such as
     * the availability of results, option to specify if SCO is shared or not.
     */
    struct CreateSearchSCOInputInfo
    {
        /**
         * It is an object of <code>CreateSCOInputInfo</code> structure which contains name,
         * description, search criteria information.
         */
        Teamcenter::Services::Rdv::_2010_09::Contextmanagement::CreateSCOInputInfo scoInputInfo;
        /**
         * Specifies whether results are stored or not in the SearchSCO.
         */
        bool resultStored;
        /**
         * Specifies whether the SearchSCO object will be shared with other users or not.
         */
        bool isShared;
        /**
         * List of all the scope bomlines used to store additional information in the SearchSCO.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > nodes;
    };

    /**
     * The CreateSearchSCOResponse structure represents search structure context object
     * created and the service data.
     */
    struct CreateSearchSCOResponse
    {
        /**
         * The vector of objects of <b>SearchStructureContext</b> created by the <code>createSearchSCO</code>
         * action
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SearchStructureContext>  > srchSCO;
        /**
         * An object of <code>ServiceData</code> which contains any exceptions if occurred during
         * creation of SearchSCO
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the ICS class names and error, if any, in <code>ServiceData</code>
     * object.
     */
    struct GetICSClassNamesResponse
    {
        /**
         * ICS Class names for the corresponding &nbsp;&nbsp;&nbsp;&nbsp;<b>ApprSearchCriteriaInClass</b>
         * objects provided &nbsp;&nbsp;&nbsp;&nbsp;in input paramter.
         */
        std::vector< std::string > icsClassNames;
        /**
         * Contains any exceptions if occurred while getting the class name of InClass Search
         * Criteria object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the Search Structure Context Object, the <code>StructureCntxtObjectInfo</code>
     * object containing information to be updated, a flag to indicate if results should
     * be stored or not and the scope bomlines.
     */
    struct UpdateSearchSCOInputInfo
    {
        /**
         * Search Structure Context Object that needs to be updated. This SCO object will be
         * updated with the modified values.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SearchStructureContext>  srchSCO;
        /**
         * Object of <code>StructureCntxtObjectInfo</code> structure. It internally holds all
         * the details related to the search criteria and search results.
         */
        Teamcenter::Services::Rdv::_2010_09::Contextmanagement::StructureCntxtObjectInfo scoInfo;
        /**
         * Describes whether the results are stored or not.
         */
        bool resultStored;
        /**
         * It is a vector of all the scope bomlines used.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > nodes;
    };

    /**
     * This structure contains the list of updated <b>SearchStructureContext</b> object
     * and error, if any, in <code>ServiceData</code> object.
     */
    struct UpdateSearchSCOResponse
    {
        /**
         * Vector of object of <b>SearchStructureContext</b> updated with the supplied inputs.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SearchStructureContext>  > srchSCO;
        /**
         * Contains any exception that occurred during updating the SearchSCO.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Contextmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/rdv/Rdv_undef.h>
#endif

