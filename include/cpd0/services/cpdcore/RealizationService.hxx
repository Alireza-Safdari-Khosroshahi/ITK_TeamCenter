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

#ifndef CPD0_SERVICES_CPDCORE_REALIZATIONSERVICE_HXX
#define CPD0_SERVICES_CPDCORE_REALIZATIONSERVICE_HXX

#include <cpd0/services/cpdcore/_2011_06/Realization.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <cpd0/services/cpdcore/CpdCore_exports.h>

namespace Cpd0
{
    namespace Services
    {
        namespace Cpdcore
        {
            class RealizationService;

/**
 * This service exposes operations pertaining to update Realization of objects instantiated
 * under workset revision.
 * <br>
 * It contains model configuration statements needed to specify how a source model (e.g.
 * collaborative design) should be configured prior to being realized.   It also contains
 * a recipe which describes what content from the source model should be selected for
 * processing.  The recipe can contain criteria for object attributes, spatial proximity,
 * and for partition membership.
 * <br>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libcpd0soacpdcorestrongmngd.dll
 * </li>
 * <li type="disc">libcpd0soacpdcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class CPD0SOACPDCORESTRONGMNGD_API RealizationService
    : public Cpd0::Services::Cpdcore::_2011_06::Realization
{
public:
    static RealizationService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RealizationService")

};
        }
    }
}


#pragma warning ( pop )

#include <cpd0/services/cpdcore/CpdCore_undef.h>
#endif

