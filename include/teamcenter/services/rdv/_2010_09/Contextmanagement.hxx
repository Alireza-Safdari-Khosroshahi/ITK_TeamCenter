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

#ifndef TEAMCENTER_SERVICES_RDV__2010_09_CONTEXTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_RDV__2010_09_CONTEXTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ApprSearchCriteriaGroup.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/StructureContext.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>


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
            namespace _2010_09
            {
                class Contextmanagement;

class TCSOARDVSTRONGMNGD_API Contextmanagement
{
public:

    struct StructureCntxtObjectInfo;
    struct CreateSCOInputInfo;
    struct CreateSCOResponse;
    struct UpdateSCOInputInfo;
    struct UpdateSCOResponse;

    /**
     * This structure contains the information required to create or update the SCO.
     */
    struct StructureCntxtObjectInfo
    {
        /**
         * Product Item Revision used during performing the search.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  prdItemRevision;
        /**
         * Revision Rule used during performing the search. For e.g, '<b>Latest working</b>'.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
        /**
         * Variant Rule set while performing the search.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  varRule;
        /**
         * List of work parts selected from <b>DesignContext</b>(DC) UserInterface(UI).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  > workParts;
        /**
         * List of all the Target <b>BOMLine</b> objects selected in DC UI.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > tgtBomLines;
        /**
         * List of Background <b>BOMLine</b> objects returned by the search.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > bgdBomLines;
        /**
         * List of selected Target <b>BOMLine</b> objects used. This is used for storing &nbsp;&nbsp;&nbsp;&nbsp;the
         * selections.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > selTgtBomLines;
        /**
         * List of selected Background <b>BOMLine</b> objects. This is used for storing the
         * selections.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > selBgdBomLines;
        /**
         * Object of Appearance Search Criteria Group for Target.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ApprSearchCriteriaGroup>  tgtSearchCrtGrp;
        /**
         * Object of Appearance Search Criteria Group for Background.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ApprSearchCriteriaGroup>  bgdSearchCrtGrp;
    };

    /**
     * This structure specifies the type, name and description information of a SCO object.
     */
    struct CreateSCOInputInfo
    {
        /**
         * Type of the Structure Context Object. For e.g. <b>VisStructureContext</b>.
         */
        std::string scoType;
        /**
         * Name by which the <b>StructureContext</b> Object will be created.
         */
        std::string scoName;
        /**
         * Description provided while creating the <b>StructureContext</b> object in DC UI.
         */
        std::string scoDesc;
        /**
         * <code>StructureCntxtObjectInfo</code> object which contains all the details related
         * to the search criteria and search results.
         */
        Teamcenter::Services::Rdv::_2010_09::Contextmanagement::StructureCntxtObjectInfo scoInfo;
    };

    /**
     * This structure contains newly created <b>StructureContext</b> object and <code>ServiceData</code>
     * object
     */
    struct CreateSCOResponse
    {
        /**
         * Object of <b>StructureContext</b> created newly using the values passed in the &nbsp;&nbsp;&nbsp;&nbsp;input
         * parameter. This object encapsulates complete DesignContext session information.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext>  strCntxtObject;
        /**
         * An object of <code>ServiceData</code> which contains any exceptions if occurred during
         * creation of SCO.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the <b>StructureContext</b> object and <code>StructureCntxtObjectInfo</code>
     * object containing information that needs to be updated.
     */
    struct UpdateSCOInputInfo
    {
        /**
         * Structure Context Object that needs to be updated. This SCO object will be updated
         * with the modified values.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext>  strCntxtObject;
        /**
         * Object of <code>StructureCntxtObjectInfo</code> structure. It internally holds all
         * the details related to the search criteria and search results.
         */
        Teamcenter::Services::Rdv::_2010_09::Contextmanagement::StructureCntxtObjectInfo scoInfo;
    };

    /**
     * This structure contains the updated <b>StructureContext</b> object and error, if
     * any, in serviceData object.
     */
    struct UpdateSCOResponse
    {
        /**
         * Object of <b>StructureContext</b> updated with the values supplied through the input
         * parameter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext>  strCntxtObject;
        /**
         * Contains any exceptions if occurred during updation of SCOs.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Contextmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/rdv/Rdv_undef.h>
#endif

