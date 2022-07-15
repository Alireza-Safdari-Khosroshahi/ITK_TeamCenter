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

#ifndef CPD0_SERVICES_CPDCORE__2011_06_REALIZATION_HXX
#define CPD0_SERVICES_CPDCORE__2011_06_REALIZATION_HXX

#include <teamcenter/soa/client/model/Cpd0DesignSubsetElement.hxx>
#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>
#include <teamcenter/soa/client/model/Rlz0Realization.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <cpd0/services/cpdcore/CpdCore_exports.h>

namespace Cpd0
{
    namespace Services
    {
        namespace Cpdcore
        {
            namespace _2011_06
            {
                class Realization;

class CPD0SOACPDCORESTRONGMNGD_API Realization
{
public:

    struct RealizedContent;
    struct UpdateWorksetSubsetContentInfo;
    struct UpdateWorksetSubsetContentResponse;

    /**
     * realized content
     */
    struct RealizedContent
    {
        /**
         * BusinessObject Reference to the realization Object that was updated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Rlz0Realization>  realization;
        /**
         * A list of Model element (e.g design elements, design control element) newly added
         * to the workset model.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > addedContent;
        /**
         * A list of Model element (e.g design elements, design control element) that are updated
         * in the workset model.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > updatedContent;
        /**
         * A list of design elements where effectivity conditions are encountered in the realized
         * item structure.
         */
        bool unmappedEffectivityConditionsEncountered;
        /**
         * A list of Model element (e.g design elements, design control element) that are removed
         * from the workset model.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > removedContent;
    };

    /**
     * Realization to be updated, refreshing the realized content based on changes to the
     * source data
     */
    struct UpdateWorksetSubsetContentInfo
    {
        /**
         * Design Subset element for which realization content to be updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignSubsetElement>  reuseModelElement;
        /**
         * Flag indicating if the recipe whould be run as part of the realization update. If
         * set to <i>false</i> the recipe will not be run, and the newer versions of source
         * content used during last update will be used as selected input.
         */
        bool executeRecipe;
    };

    /**
     * Response to <code>UpdateWorksetSubsetContentResponse</code> contains a list of Realizations
     * updated.
     */
    struct UpdateWorksetSubsetContentResponse
    {
        /**
         * realized content
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Realization::RealizedContent > realizedContent;
        /**
         * Contain a list of deleted Objects  and also list of any errors which occurred within
         * the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is used to check for any updates in the source model(Collaborative
     * Design) that have occurred since the last realization update and reflects any of
     * those changes correspondingly in the target model( Workset Model).  The list of added,
     * updated, and removed content will be returned for each realization input.  If the
     * <code>executeRecipe</code> flag is set to <i>false</i>, the recipe will not be reexecuted
     * for a recipe based realizations.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A design subset element is used to represent a subset of collaborative design in
     * a workset. Design elements may be created by CAD applications or directly in the
     * Teamcenter RAC user interface using the Collaborative Product Development application.
     * <br>
     * <br>
     * This API supports workset authoring use cases; specifically, it is used when the
     * user wishes to update the content of a subset by reexecuting its search recipe.
     * <br>
     * <br>
     * Use Case : <b>Update selected content of existing design subset elements </b>
     * <br>
     * <br>
     * The following operation can be used for updating an existing design subset element
     * in a workset
     * <br>
     * <ul>
     * <li type="disc">Design subset elements are found by the application by expanding
     * a workset (see <code>startStructureExpand</code> operation).
     * </li>
     * <li type="disc">The set of content referenced by design subset elements can be updated
     * by reexecuting the search recipe. This is done by using the <code>updateWorksetSubsetContent</code>
     * operation. The application specifies which design subset elements should have their
     * set of selected content updated.
     * </li>
     * <li type="disc">During the <code>updateWorksetSubsetContent</code> operation, the
     * server will find the set of collaborative design content that satisfies the search
     * criteria.This set of objects will be updated on the design subset element, and will
     * remain static until the next call to <code>updateWorksetSubsetContent</code>.
     * </li>
     * <li type="disc">Note: The search recipe on design subset elements is normally changed
     * using the <code>setRecipes</code> operation. The <code>updateWorksetSubsetContent</code>
     * can be called after <code>setRecipes</code> in order to update the workset based
     * on the new/modified search recipe.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param input
     *        set of realizations to update.
     *
     * @return
     *         UpdateWorksetSubsetContentResponse contains a vector of set of design model elements.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Realization::UpdateWorksetSubsetContentResponse updateWorksetSubsetContent ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Realization::UpdateWorksetSubsetContentInfo >& input ) = 0;


protected:
    virtual ~Realization() {}
};
            }
        }
    }
}

#include <cpd0/services/cpdcore/CpdCore_undef.h>
#endif

