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

#ifndef TEAMCENTER_SERVICES_BOM_STRUCTUREMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_BOM_STRUCTUREMANAGEMENTSERVICE_HXX

#include <teamcenter/services/bom/_2008_06/Structuremanagement.hxx>
#include <teamcenter/services/bom/_2010_09/Structuremanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/bom/Bom_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Bom
        {
            class StructuremanagementService;

/**
 * This library has operations related to BOM related functionality. This service has
 * 5 operations
 * <br>
 * <ul>
 * <li type="disc">addOrUpdateChildrenToParentLine
 * </li>
 * <li type="disc">createBaseline
 * </li>
 * <li type="disc">getTraversedObjectsByRule
 * </li>
 * <li type="disc">removeChildrenFromParentLine
 * </li>
 * <li type="disc">verifyObjectCoverageByRule
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoabomstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoabomtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOABOMSTRONGMNGD_API StructuremanagementService
    : public Teamcenter::Services::Bom::_2008_06::Structuremanagement,
             public Teamcenter::Services::Bom::_2010_09::Structuremanagement
{
public:
    static StructuremanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Creates a new Baseline <b>ItemRevision</b> based on a work in progress <b>ItemRevision</b>.
     * If the input <b>ItemRevision</b> consists of a <b>PSBOMViewRevision</b> that represents
     * a multi level structure, all components of the structure are baselined in a recursive
     * fashion. If smart baseline option is enabled at the site, then components of the
     * structure will be baselined only if they satisfy the criteria set forth by smart
     * baseline feature. Released <b>ItemRevision</b> objects are not baselined, unless
     * the specific name of <b>ReleaseStatus</b> object is mentioned in the preference <b>Baseline_allowed_baserev_statuses</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Baseline - Allows creation of a new baseline ItemRevision based on an input ItemRevision
     *
     * @param inputs
     *        List of <code>BaselineInput</code> structures.
     *        <br>
     *        Each of the structures , holds the <b>ItemRevision</b> to be baselined, <b>RevisionRule</b>
     *        and valid <b>PSViewType</b> name to be used in case the <b>ItemRevision</b> has <b>BOMViewRevision</b>.
     *        Dry run can be performed by providing value as 'true' for the dry run flag. In addition
     *        to the above, user  needs to provide the Workflow template name to be used for baselining
     *        and job name required to initialize the baseline workflow process.
     *
     * @return
     *         sets of Teamcenter Data Model object from a service request. This also holds services
     *         exceptions. To process BaselineResponse:
     *
     */
    virtual Teamcenter::Services::Bom::_2008_06::Structuremanagement::BaselineResponse createBaseline ( const std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::BaselineInput >& inputs ) = 0;

    /**
     * This operation takes <i>item</i> / <i>item revision</i> (depending on precise or
     * imprecise structure) or a <i>GDE</i>. It takes view type to create a <b>BOMView</b>
     * for the parent line in a product structure.  When the <b>BOMLine</b> for the item/item
     * revision is provided and client id is empty, an update will be performed.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param inputs
     *        This is a vector of AddOrUpdateChildrenToParentLineInfo. Each element of this vector
     *        contains an input <b>BOMLine</b> which is going to get updated, view type e.g. CAEAnalysis,
     *        MEProcess, MESetup, View, an array of ItemLineInfo and ItemElementLineInfo capturing
     *        the details of children to be added or updated.
     *
     * @return
     *         structures containing newly added Item BOMLines, Item Element Lines and ServiceData
     *         containing any created child bomline and the updated bomline object will be sent
     *         back in the standard ServiceData member lists of created objects and updated objects
     *         respectively. Any failures will be returned in the ServiceData list of partial errors.
     *
     */
    virtual Teamcenter::Services::Bom::_2008_06::Structuremanagement::AddOrUpdateChildrenToParentLineResponse addOrUpdateChildrenToParentLine ( const std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::AddOrUpdateChildrenToParentLineInfo >& inputs ) = 0;

    /**
     * This operation allows developers to remove a <b>BOMLine</b> from an assembly /product
     * structure. This operation takes vector of <b>BOMLine</b> business objects as input,
     * which allows removal of multiple <b>BOMLines</b> from the structure in a single operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param bomlines
     *        This is a vector of <i>Teamcenter::BOMLine</i> and contains all the <i>BOMLines</i>
     *        that need to be deleted from an assembly/product structure
     *
     * @return
     *         sets of Teamcenter Data Model object from a service request. This also holds services
     *         exceptions.
     *
     */
    virtual Teamcenter::Services::Bom::_2008_06::Structuremanagement::RemoveChildrenFromParentLineResponse removeChildrenFromParentLine ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& bomlines ) = 0;

    /**
     * This SOA traverses the structure according to supplied filtering rule and returns
     * the full list of resulting lines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BOM Expand - Set of core services that allow to efficiently solve a product structure
     * based on revision rules; effectivities etc.
     *
     * @param input
     *        TraversedObjectsInput structure
     *
     * @return
     *         return the filtered and expanded lines for a structure
     *
     */
    virtual Teamcenter::Services::Bom::_2010_09::Structuremanagement::TraversedObjectsResponse getTraversedObjectsByRule ( const Teamcenter::Services::Bom::_2010_09::Structuremanagement::TraversedObjectsInput&  input ) = 0;

    /**
     * This SOA verifies whether the received lines fit the supplied filtering rule.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BOM Expand - Set of core services that allow to efficiently solve a product structure
     * based on revision rules; effectivities etc.
     *
     * @param input
     *        ObjectCoverageInput structure
     *
     * @return
     *         for each received line returns whether it fits the supplied closure rule
     *
     */
    virtual Teamcenter::Services::Bom::_2010_09::Structuremanagement::ObjectCoverageResponse verifyObjectCoverageByRule ( const Teamcenter::Services::Bom::_2010_09::Structuremanagement::ObjectCoverageInput&  input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuremanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/bom/Bom_undef.h>
#endif

