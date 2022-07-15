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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_PUBLISHBYLINKSERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_PUBLISHBYLINKSERVICE_HXX

#include <teamcenter/services/structuremanagement/_2007_06/Publishbylink.hxx>
#include <teamcenter/services/structuremanagement/_2012_09/Publishbylink.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            class PublishbylinkService;

/**
 * Teamcenter offers CAD and BOM independence through which customer can have separation
 * of design and part related information so that both part and design structures can
 * evolve at different pace. It is desired to have association between part and design
 * structures through which user can link logically equivalent occurrences. The PublishByLink
 * feature allows user to perform in-context association of occurrences.
 * <br>
 * <br>
 * This service contains various operations to do in-context association of occurrences
 * and other subsequent operations like publishing geometry related information from
 * source (typically design) to target occurrence, find target/source <b>BOMLine</b>
 * objects, CompletenessCheck, delete <b>PublishLink</b>.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoastructuremanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoastructuremanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API PublishbylinkService
    : public Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink,
             public Teamcenter::Services::Structuremanagement::_2012_09::Publishbylink
{
public:
    static PublishbylinkService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Adds <b>AbsOccViewQualifier</b> of target <b>BOMLine</b> objects to the existing
     * <b>PublishLink</b> of input source <b>BOMLine</b>. The operation also saves updated
     * <b>PublishLink</b>.
     * <br>
     * <br>
     * Following validations are performed during operation and failures are reported in
     * <code>ServiceData</code>.
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><b>PublishLink</b> exists with source as input source and user has
     * access to it.
     * </li>
     * <li type="disc"><b>Item</b> type of source and target <b>BOMLine</b> as per PUBLISH_AlignableSourceTypes
     * and PUBLISH_AlignableTargetTypes preference respectively.
     * </li>
     * <li type="disc">No <b>PublishLink</b> exists with target as input target.
     * </li>
     * <li type="disc">Logical identity of all target <b>BOMLine</b> is same.
     * </li>
     * <li type="disc">Logical identity of source and target <b>BOMLine</b>s is same.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Add in-context occurrence as target to an existing <b>PublishLink</b> for given source.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createLinks
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param input
     *        <code>SourceAndTargets</code> containing source <b>BOMLine</b> and corresponding
     *        target <b>BOMLine</b> objects.
     *
     * @return
     *         <code>PublishLinksResponse</code> containing ,list of <code>PublishLinkOutput</code>
     *         and <code>ServiceData</code>. Note that <code>PublishLinkOutput</code> is not populated
     *         by this operation. Updated <b>PublishLink</b> objects are added into created objects
     *         list of the <code>ServiceData</code>. <code>ServiceData</code> also contains any
     *         error that might have occurred during operation.
     *         <br>
     *         <br>
     *         43111 Invalid source as input.
     *         <br>
     *         43114 Occurrence chosen as target is already a target for some PublishLink.
     *         <br>
     *         43124 Underlying object of target occurence is of invalid type.
     *         <br>
     *         43127 Logical identity of source and target occurrence are not same.
     *         <br>
     *         43128 Logical identity of target occurrences are not same.
     *         <br>
     *         43141 A top line cannot be selected as a target for publishing data.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishLinksResponse addTargets ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::SourceAndTargets >& input ) = 0;

    /**
     * Recursively evaluates completeness for <b>BOMLine</b> objects having underlying component
     * as <b>Part</b>.  A <b>BOMLine</b> which requires positioned designed is marked as
     * complete if underlying <b>PartRevision</b> has primary representation OR <b>BOMLine</b>
     * has source associated via <b>PublishLink</b> object. If a <b>BOMLine</b> does not
     * need positioned designed then such <b>BOMLine</b> is marked as complete as well.
     * This operation also supports recursively clearing completeness results.
     * <br>
     * <br>
     * If required the BOM is expanded internally. In case of packed <b>BOMLine</b>s, if
     * any of the <b>BOMLine</b> is incomplete then that packed line is marked as incomplete.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">Recursively perform completeness check for <b>Part</b> structure.
     * </li>
     * <li type="disc">Recursively clears completeness check for <b>Part</b> structure.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param input
     *        String representing action to be performed on corresponding <b>BOMLine</b>.
     *
     * @return
     *         <code>CompletenessCheckResponse</code> containing list of <code>CompletenessCheckOutput</code>
     *         and <code>ServiceData</code>.  <code>CompletenessCheckOutput</code> contains list
     *         of Complete, Incomplete and Skipped <b>BOMLine</b>s and integer to map with input
     *         <b>BOMLine</b>.  <code>ServiceData</code> contains any error that might have occurred
     *         during operation.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::CompletenessCheckResponse completenessCheck ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::CompletenessCheckInputData >& input ) = 0;

    /**
     * Creates <b>PublishLink</b> between <b>AbsOccurrenceViewQualifier</b> of source and
     * target <b>BOMLine</b>s. The <code>dataFlags</code> attribute of the <b>PublishLink</b>
     * is set to 0 as no data was published. The operation also saves new <b>PublishLink</b>
     * object.
     * <br>
     * <br>
     * Following validations are performed during operation and failures are reported in
     * <code>ServiceData</code>.
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><b>Item</b> type of source and target <b>BOMLine</b> as per PUBLISH_AlignableSourceTypes
     * and PUBLISH_AlignableTargetTypes preference respectively.
     * </li>
     * <li type="disc">Type name is a valid <b>TCType</b> name.
     * </li>
     * <li type="disc"><b>PSBOMView</b> of the source is local.
     * </li>
     * <li type="disc">No <b>PublishLink</b> exists with source as input source.
     * </li>
     * <li type="disc">No <b>PublishLink</b> exists with target as input target.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Perform in-context association between occurrences of two structures.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param linkInfos
     *        Contains information to create <b>PublishLink</b>.
     *
     * @return
     *         <code>PublishLinksResponse</code> containing list of <code>PublishLinkOutput</code>
     *         and <code>ServiceData</code>. Created <b>PublishLink</b> are added into created object
     *         list of the <code>ServiceData</code>. Note that <code>PublishLinkOutput</code> is
     *         not populated by this operation. <code>ServiceData</code> also contains any error
     *         that might have occurred during operation.
     *         <br>
     *         <br>
     *         43113 Invalid PublishLink type.
     *         <br>
     *         43122 PublishLink cannot be created with source occurrence being a replica object.
     *         <br>
     *         43123 Underlying object of source occurence is of invalid type.
     *         <br>
     *         43124 Underlying object of target occurence is of invalid type.
     *         <br>
     *         43140 A top line cannot be selected as a source for publishing data.
     *         <br>
     *         43141 A top line cannot be selected as a target for publishing data.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishLinksResponse createLinks ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishLinkInfo >& linkInfos ) = 0;

    /**
     * Finds and deletes <b>PublishLink</b> for input source <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Delete PublishLink.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param sources
     *        Set of source <b>BOMLine</b> objects for which <b>PublishLink</b> to be deleted.
     *
     * @return
     *         <code>ServiceData</code> containing partial error information.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43111 Invalid source as input.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteLinkForSource ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& sources ) = 0;

    /**
     * Deletes <b>AbsOccViewQualifier</b> of target <b>BOMLine</b>s from the existing <b>PublishLink</b>.
     * If the target being removed is the last one for <b>PublishLink</b> then <b>PublishLink</b>
     * is also deleted. Otherwise operation saves updated <b>PublishLink</b>.
     * <br>
     * <br>
     * Following validations are performed during operation.
     * <br>
     * <b>
     * <br>
     * PublishLink</b> exists whose target as input
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Detach target <b>BOMLine</b> from <b>PublishLink</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param targets
     *        Target <b>BOMLine</b> objects which need to be removed from existing <b>PublishLink</b>.
     *
     * @return
     *         <code>ServiceData</code> containing partial error.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43111 Invalid source as input.
     *         <br>
     *         43115 Invalid target for remove.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteTargetsFromLink ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& targets ) = 0;

    /**
     * Finds logically equivalent <b>BOMLine</b>s in <b>BOMWindow</b> for list of input
     * <b>BOMLine</b>s.
     * <br>
     * <br>
     * <b>BOMLine</b>s are said to be identical if their <b>AbsoluteOccurrence</b> objects
     * have same <code>Usage Address</code> and <code>Positioned Designator</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Find equivalent <b>BOMLine</b> objects and associate them.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createLinks
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param input
     *        <code>LineAndWindow</code> containing <b>BOMLine</b> for which equivalent <b>BOMLine</b>s
     *        to be searched in corresponding input <b>BOMWindow</b>.
     *
     * @return
     *         <code>LogicallyEquivalentLinesResponse</code> containing list of <code>LogicallyEquivalentLinesOutput</code>
     *         and <code>ServiceData</code>. <code>LogicallyEquivalentLinesOutput</code> contains
     *         list of equivalent <b>BOMLine</b>s and integer to map corresponding input <b>BOMLine</b>.
     *         Equivalent <b>BOMLine</b>s are added into plain objects list of the <code>ServiceData</code>.
     *         <code>ServiceData</code> contains error that might have occurred during operation.
     *         <br>
     *         
     *         <br>
     *         43125 Usage address of the occurrence is empty.
     *         <br>
     *         43126 Position Designator of the occurrence is empty.
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::LogicallyEquivalentLinesResponse findLinesWithSameLogicalIdentity ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::LineAndWindow >& input ) = 0;

    /**
     * Finds source of the <b>PublishLink</b> in source <b>BOMWindow</b> for input target
     * <b>BOMLine</b> objects. Source is returned as <b>BOMLine</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Determine if <b>BOMWindow</b> has source for input target <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param input
     *        <code>LineAndWindow</code> containing target <b>BOMLine</b> and <b>BOMWindow</b>
     *        in which source of <b>PublishLink</b> to search.
     *
     * @return
     *         <code>FindSourceResponse</code> containing list of <code>FindSourceOutput</code>
     *         and <code>ServiceData</code>. <code>FindSourceOutput</code> contains target <b>BOMLine</b>s
     *         and integer pointing input target <b>BOMLine</b>. Source <b>BOMLines</b> are added
     *         into plainObjects list of the <code>ServiceData</code>.
     *         <br>
     *         
     *         <br>
     *         43120 No Publish Link exists for the target.
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::FindSourceResponse findSourceInWindow ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::LineAndWindow >& input ) = 0;

    /**
     * Finds target of the <b>PublishLink</b> in target <b>BOMWindow</b> for input source
     * <b>BOMLine</b> objects. Targets are returned as <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">Determine if <b>BOMWindow</b> has targets for input source <b>BOMLine</b>.
     * </li>
     * <li type="disc">Find targets for source of <b>PublishLink</b> and subsequently use
     * found target <b>BOMLine</b> objects to delete links.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * deleteTargetsFromLink
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param input
     *        <code>LineAndWindow</code> containing source <b>BOMLine</b> and <b>BOMWindow</b>
     *        in which target of <b>PublishLink</b> to search.
     *
     * @return
     *         <code>FindTargetsResponse</code> containing vector of <code>FindTargetsOutput</code>
     *         and <code>ServiceData</code>.
     *         <br>
     *         <code>FindTargetsOutput</code> contains target <b>BOMLine</b> objects and integer
     *         pointing input source <b>BOMLine</b>. Target <b>BOMLine</b> objects are added into
     *         plain list of the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43111 Invalid source as input.
     *         <br>
     *         43119 No Publish Link exists for the source.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::FindTargetsResponse findTargetsInWindow ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::LineAndWindow >& input ) = 0;

    /**
     * Finds source of <b>PublishLink</b> for given target <b>BOMLine</b>. For the source
     * of the <b>PublishLink</b> finds context <b>PSBOMView</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Find context <b>PSBOMView</b> for the source of <b>PublishLink</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param targets
     *        <b>BOMLine</b>s for which source has to be found in order to determine context <b>PSBOMView</b>.
     *
     * @return
     *         <code>GetSourceTopLevelResponse</code> with <code>ServiceData</code> and list of
     *         <code>GetSourceTopLevelOutput</code>.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43112 Invalid target as input.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::GetSourceTopLevelResponse getSourceTopLevel ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& targets ) = 0;

    /**
     * Copies <code>Absolute Transformation Matrix</code> and/or JT from source <b>BOMLine</b>
     * to target <b>BOMLine</b> objects. If a <b>PublishLink</b> does not exist for source
     * and target then a new <b>PublishLink</b> is created with input dataFlags. In case
     * if <b>PublishLink</b> already exists then dataFlags of the <b>PublishLink</b> object
     * is updated.
     * <br>
     * <br>
     * Input <code>dataFlags</code> is used to determine which data has to be copied. Unless
     * context was explicitly set - the data on target <b>BOMLine</b>s is stored in-context
     * of top <b>BOMLine</b> of the target <b>BOMWindow</b>.
     * <br>
     * <br>
     * The <b>DirectModel Dataset</b> is attached with Rendering relation. If the target
     * <b>BOMLine</b> is an assembly then PLMXML file is created based on <b>RevisionRule</b>
     * of the source <b>BOMWindow</b> and attached to target <b>BOMLine</b> as <b>Text</b>
     * <b>Dataset</b> with Rendering relation. In case, in-context <b>Dataset</b> with Rendering
     * relation already exists then that is replaced with the new one. The <b>BOMWindow</b>
     * is saved after attaching the <b>Dataset</b>.
     * <br>
     * <br>
     * Below validations are performed during operation and failures are reported in <code>ServiceData</code>.
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><code>dataFlags</code> contains a valid value.
     * </li>
     * <li type="disc">Target <b>BOMLine</b> requires positioned design.
     * </li>
     * <li type="disc"><b>Item</b> type of source and target <b>BOMLine</b> as per PUBLISH_AlignableSourceTypes
     * and PUBLISH_AlignableTargetTypes preference respectively.
     * </li>
     * <li type="disc">Type name is a valid <b>TCType</b> name.
     * </li>
     * <li type="disc"><b>PSBOMView</b> of the source is local.
     * </li>
     * <li type="disc">No <b>PublishLink</b> exists other than source and target as in input.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Perform in-context association between occurrences of two structures and copy <code>Absolute
     * Transformation Matrix</code> and/or JT from source to target <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createLinks
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param publishDataInfos
     *        <code>PublishDataInfo</code> containing information to create <b>PublishLink</b>
     *        and <code>dataFlag</code> to determine which attributes should be copied to target
     *        <b>BOMLine</b>s.
     *
     * @return
     *         <code>PublishLinksResponse</code> containing vector of <code>PublishLinkOutput</code>
     *         and <code>ServiceData</code>. Created and updated <b>PublishLink</b> are added into
     *         created list of the <code>ServiceData</code>. Note that <code>PublishLinkOutput</code>
     *         is not populated by this operation. <code>ServiceData</code> contains error that
     *         may have occurred during operation.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43123 Underlying object of source occurence is of invalid type.
     *         <br>
     *         43124 Underlying object of target occurence is of invalid type.
     *         <br>
     *         43129 Target occurrence(s) set to not require positioned design.
     *         <br>
     *         43140 A top line cannot be selected as a source for publishing data.
     *         <br>
     *         43141 A top line cannot be selected as a target for publishing data.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishLinksResponse publishData ( const std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishDataInfo >& publishDataInfos ) = 0;

    /**
     * Finds and deletes <b>PublishLink</b> for input source <b>BOMLine</b> objects.
     * <br>
     * <br>
     * The <b>AbsOccXform</b> of the target <b>BOMLine</b> objects will be deleted if <code>dataToUnpublish</code>
     * is TRANSFORM. All in context JTs of the target <b>BOMLine</b> objects will be unattached
     * if <code>dataToUnpublish</code> is SHAPE. If all data(as of now TRANSFORM and SHAPE
     * only) needs to be removed then value of <code>dataToUnpublish</code> should be ALL.
     * None of the published data will be impacted when <code>dataToPublish</code> is empty
     * string.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Delete <b>PublishLink</b> and unpublish data from target <b>BOMLine</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param sourceBOMLines
     *        Source <b>BOMLine</b> objects for which  <b>PublishLink</b> to be deleted. The <b>PublishLink</b>
     *        found is used to find target <b>BOMLine</b> objects before <b>PublishLink</b>s are
     *        deleted.
     *
     * @param dataToUnpublish
     *        Data to unpublish. Valid values are TRANSFORM, SHAPRE, ALL or empty string. The value
     *        is case sensitive.
     *
     * @return
     *         <code>ServiceData</code> containing partial error information.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43111 Invalid source as input.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteLinksForSource2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& sourceBOMLines,
        const std::string&  dataToUnpublish ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PublishbylinkService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

