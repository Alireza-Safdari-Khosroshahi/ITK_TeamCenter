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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2007_06_PUBLISHBYLINK_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2007_06_PUBLISHBYLINK_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/PSBOMView.hxx>
#include <teamcenter/soa/client/model/PublishLink.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2007_06
            {
                class Publishbylink;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Publishbylink
{
public:

    struct CompletenessCheckInputData;
    struct CompletenessCheckOutput;
    struct CompletenessCheckResponse;
    struct FindSourceOutput;
    struct FindSourceResponse;
    struct FindTargetsOutput;
    struct FindTargetsResponse;
    struct GetSourceTopLevelOutput;
    struct GetSourceTopLevelResponse;
    struct LineAndWindow;
    struct LogicallyEquivalentLinesOutput;
    struct LogicallyEquivalentLinesResponse;
    struct PublishLinkInfo;
    struct PublishDataInfo;
    struct PublishLinkOutput;
    struct PublishLinksResponse;
    struct SourceAndTargets;

    /**
     * Contains string mentioning which action be performed on input <b>BOMLine</b> representing
     * <b>Part</b>.
     */
    struct CompletenessCheckInputData
    {
        /**
         * string representing action to be performed on <b>BOMLine</b>. Valid values are <code>VerifyPartStructInteractive</code>
         * and <code>ClearCompletenessCheckResults</code>. The Completeness check is performed
         * with action string is <code>VerifyPartStructInteractive</code>. The Completeness
         * check is cleared if string is <code>ClearCompletenessCheckResults</code>.
         */
        std::string action;
        /**
         * <b>BOMLine</b> representing <b>Part</b> structure for which Completeness Check has
         * to be performed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomline;
    };

    /**
     * Contains set of Complete, Incomplete and Skipped <b>BOMLine</b>s for CompletenessCheck.
     * Integer based index points output to corresponding input.
     */
    struct CompletenessCheckOutput
    {
        /**
         * Integer pointing to input. Useful to map output with input.
         */
        int inputIndex;
        /**
         * <b>BOMLine</b>s that satisfy Completeness criteria.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > completeLines;
        /**
         * <b>BOMLine</b>s that do not satisfy Completeness criteria.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > incompleteLines;
        /**
         * <b>BOMLine</b>s for which Completeness criteria do not apply.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > skippedLines;
    };

    /**
     * <code>CompletenessCheckResponse</code> containing list of <code>CompletenessCheckOutput</code>
     * and <code>ServiceData</code>.  <code>CompletenessCheckOutput</code> contains list
     * of Complete, Incomplete and Skipped <b>BOMLine</b>s and integer to map with input
     * <b>BOMLine</b>. <code>ServiceData</code> contains any error that might have occurred
     * during operation.
     */
    struct CompletenessCheckResponse
    {
        /**
         * <code>CompletenessCheckOutput</code> containing Complete, Incomplete and Skipped
         * <b>BOMLine</b> objects. The integer inputIndex maps to index of input <b>BOMLine</b>
         * to map output and input.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::CompletenessCheckOutput > output;
        /**
         * <code>ServiceData</code> contains partial error (if any)
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains source <b>BOMLine</b> and integer based index to point output to corresponding
     * input.
     */
    struct FindSourceOutput
    {
        /**
         * Integer pointing to input. Useful to map output with input.
         */
        int inputIndex;
        /**
         * Source <b>BOMLine</b> for input target <b>BOMLine</b> and source <b>BOMWindow</b>.
         * Source <b>BOMLine</b> and Target <b>BOMLine</b> are associated via <b>PublishLink</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  sourceLine;
    };

    /**
     * Contains <code>FindSourceOutput</code> containing source <b>BOMLine</b> and index
     * to map to source <b>BOMLine</b> to corresponding input target <b>BOMLine</b>.
     */
    struct FindSourceResponse
    {
        /**
         * <code>FindSourceOutput</code> containing source <b>BOMLine</b> and integer index
         * to map source <b>BOMLine</b> to input target <b>BOMLine</b>.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::FindSourceOutput > output;
        /**
         * <code>ServiceData</code> with plain objects containing source <b>BOMLine</b> and
         * partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains target <b>BOMLine</b>s and integer based index to point output to corresponding
     * input.
     */
    struct FindTargetsOutput
    {
        /**
         * Integer pointing to input. Useful to map output with input.
         */
        int inputIndex;
        /**
         * Target <b>BOMLine</b> for given source <b>BOMLine</b> and target <b>BOMWindow</b>.Target
         * <b>BOMLine</b> and Source <b>BOMLine</b> are associated via <b>PublishLink</b>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > targetLines;
    };

    /**
     * Contains <code>FindTargetsOutput</code> containing target <b>BOMLine</b> objects
     * and index to map to target <b>BOMLine</b> to corresponding source.
     */
    struct FindTargetsResponse
    {
        /**
         * <code>FindTargetsOutput</code> containing target <b>BOMLine</b> for input source
         * <b>BOMLine</b> and integer index to map target <b>BOMLine</b> to input source <b>BOMLine</b>.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::FindTargetsOutput > output;
        /**
         * <code>ServiceData</code> with plain objects containing target <b>BOMLine</b> objects
         * and partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains context <b>PSBOMView</b> of the source of <b>PublishLink</b> for given input
     * target <b>BOMLine</b>. Integer based index points <b>PSBOMView</b> to corresponding
     * input.
     */
    struct GetSourceTopLevelOutput
    {
        /**
         * Integer pointing to input. Useful to map output with input.
         */
        int inputIndex;
        /**
         * <b>PSBOMView</b> of the source of <b>PublishLink</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  topLevelBomView;
    };

    /**
     * <code>GetSourceTopLevelResponse</code> contains vector of <code>GetSourceTopLevelOutput</code>
     * and <code>ServiceData</code>.
     */
    struct GetSourceTopLevelResponse
    {
        /**
         * <code>GetSourceTopLevelOutput</code>  containing <b>PSBOMView</b> in which context
         * targets were added and integer index to map <b>PSBOMView</b> to input <b>BOMLine</b>.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::GetSourceTopLevelOutput > output;
        /**
         * <code>ServiceData</code> containing partial error and <b>PSBOMView</b> in plain objects
         * list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains source <b>BOMLine</b> and target <b>BOMWindow</b> in which associated target
     * <b>BOMLine</b> of <b>PublishLink</b> to look for.
     */
    struct LineAndWindow
    {
        /**
         * Source <b>BOMLine</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  line;
        /**
         * Target <b>BOMWindow</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window;
    };

    /**
     * Contains logically equivalent <b>BOMLine</b>s from input <b>BOMWindow</b> and <b>BOMLine</b>.
     * The integer based index points equivalent line to input <b>BOMLine</b>.
     */
    struct LogicallyEquivalentLinesOutput
    {
        /**
         * Integer pointing to input <b>BOMLine</b>. Useful to map output with input.
         */
        int inputIndex;
        /**
         * Logically equivalent <b>BOMLine</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > lines;
    };

    /**
     * <code>LogicallyEquivalentLinesResponse</code> contains vector of <code>LogicallyEquivalentLinesOutput</code>
     * and <code>ServiceData</code>.
     */
    struct LogicallyEquivalentLinesResponse
    {
        /**
         * <code>LogicallyEquivalentLinesOutput</code> with equivalent <b>BOMLine</b> objects
         * for input <b>BOMLine</b> pointed by integer inputIndex.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::LogicallyEquivalentLinesOutput > output;
        /**
         * <code>ServiceData</code> with equivalent <b>BOMLine</b>s in plain objects and partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Required data to create a <b>PublishLink</b> like name, type, source and target <b>BOMLine</b>s.
     */
    struct PublishLinkInfo
    {
        /**
         * object_name to be set on the <b>PublishLink</b>.
         */
        std::string name;
        /**
         * Valid type to set on the <b>PublishLink</b>'s object_type.
         */
        std::string type;
        /**
         * <b>BOMLine</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  source;
        /**
         * List of <b>BOMLine</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > targets;
    };

    /**
     * Contains <code>PublishLinkInfo</code> and <code>dataFlags</code>. Each bit of <code>dataFlags</code>
     * denotes what data to be published.
     */
    struct PublishDataInfo
    {
        /**
         * <code>PublishLinkInfo</code> containing information to create <b>PublishLink</b>.
         */
        Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishLinkInfo linkInfo;
        /**
         * <code>dataFlags</code> representing what data to be published.
         */
        int dataFlags;
    };

    /**
     * Contains <b>PublishLink</b> created by the operation and integer based index points
     * <b>PublishLink</b> to corresponding input.
     */
    struct PublishLinkOutput
    {
        /**
         * Integer pointing to input. Useful to map output with input.
         */
        int inputIndex;
        /**
         * <b>PublishLink</b> object created during the operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PublishLink>  publishLink;
    };

    /**
     * <code>PublishLinksResponse</code> contains list of <code>PublishLinkOutput</code>
     * structures and <code>ServiceData</code>.
     */
    struct PublishLinksResponse
    {
        /**
         * <code>PublishLinkOutput</code> containing <b>PublishLink</b> to which targets were
         * added and integer index to map <b>PublishLink</b> to input <b>BOMLine</b>
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2007_06::Publishbylink::PublishLinkOutput > output;
        /**
         * <code>ServiceData</code> with created objects and partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure that contains <b>BOMLine</b> objects representing source and targets
     * of <b>PublishLink</b>
     */
    struct SourceAndTargets
    {
        /**
         * <b>BOMLine</b> as source for <b>PublishLink</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  source;
        /**
         * <b>BOMLine</b> objects as target for <b>PublishLink</b> object
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > targets;
    };




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


protected:
    virtual ~Publishbylink() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

