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

#ifndef TEAMCENTER_SERVICES_BOM__2008_06_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_BOM__2008_06_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/bom/Bom_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Bom
        {
            namespace _2008_06
            {
                class Structuremanagement;

class TCSOABOMSTRONGMNGD_API Structuremanagement
{
public:

    struct AddOrUpdateChildrenToParentLineInfo;
    struct AddOrUpdateChildrenToParentLineResponse;
    struct BaselineInput;
    struct BaselineOutput;
    struct BaselineResponse;
    struct BOMLinesOutput;
    struct ItemElementLineInfo;
    struct ItemLineInfo;
    struct RemoveChildrenFromParentLineResponse;

    /**
     * Refers to a map of <b>BOMLine</b> object property as key and <b>BOMLine</b> object
     * property value as value pair.
     */
    typedef std::map< std::string, std::string > BomLineProperties;

    /**
     * Input structure for addOrUpdateChildrenToParentLine operation
     */
    struct AddOrUpdateChildrenToParentLineInfo
    {
        /**
         * Parent <b>BOMLine</b> business object under which item or item element occurrences
         * are added or modified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  parentLine;
        /**
         * View Type string used for creating <b>BOMView</b> for parent <b>BOMLine</b> if it
         * does not exist (NULL implies use default view type).
         */
        std::string viewType;
        /**
         * Array of ItemLineInfo input structure.
         */
        std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::ItemLineInfo > items;
        /**
         * Array of ItemElementLineInfo input structure
         */
        std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::ItemElementLineInfo > itemElements;
    };

    /**
     * Return structure for addOrUpdateChildrenToParentLine operation
     */
    struct AddOrUpdateChildrenToParentLineResponse
    {
        /**
         * Array of Output itemLines
         */
        std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::BOMLinesOutput > itemLines;
        /**
         * Array of Output itemElementLines
         */
        std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::BOMLinesOutput > itemelementLines;
        /**
         * This is a common data strucuture used to return sets of Teamcenter Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure that holds information to create a new Baseline <b>ItemRevision</b>
     */
    struct BaselineInput
    {
        /**
         * To be set as 'true' if dryrun is to be performed, false if not. This is an optional
         * element and the default value is false. Dry run option helps users to know of any
         * possible errors without performing the actual baseline action. Choosing this option
         * generates a report and can be accessed from the <code>BaselineResponse</code>.
         */
        bool dryrun;
        /**
         * Identifier that helps the client to track the object(s) created
         */
        std::string clientID;
        /**
         * Input <b>ItemRevision</b> object, that is to be baselined
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * View type name. To be provided if input <b>ItemRevision</b> has <b>BOMViewRevision</b>
         */
        std::string viewType;
        /**
         * <b>RevisionRule</b> object. To be provided if input <b>ItemRevision</b> has <b>BOMViewRevision</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
        /**
         * Creates a precise baseline if set to true. If set to false, creates an imprecise
         * baseline. Default value is false.
         */
        bool precise;
        /**
         * Name of the workflow process template to be used for baselining.
         */
        std::string releaseProcess;
        /**
         * Description for baseline <b>ItemRevision</b>, optional
         */
        std::string description;
        /**
         * Name to identify the job initiated during baseline. Operation will fail if a job
         * name is not provided. In general job name is a combination of ItemId, Revision Id
         * and <b>ItemRevision</b> Name property values.
         */
        std::string baselineJobName;
        /**
         * Description for baseline job, optional
         */
        std::string baselineJobDescription;
    };

    /**
     * Refers to the output structure for baseline create operation.
     */
    struct BaselineOutput
    {
        /**
         * BaselineOutput structure contains following elements
         * <br>
         * dryrun - Dry run indicates that the operation will not create a baseline but it will
         * only do the required validation. Boolean variable indicating if dry option was used.
         * <br>
         */
        bool dryrun;
        /**
         * Client Identifier
         */
        std::string clientID;
        /**
         * Created baseline <b>ItemRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  baselineItemRev;
        /**
         * FMS ticket for dryrun log. Contains path to dry run report if dryrun flag is set
         * to true.
         */
        std::string dryrunLogTicket;
    };

    /**
     * Output structure containing list of <code>BaselineOutput</code> structures and <code>ServiceData</code>
     * with list of errors encountered during the Operation
     */
    struct BaselineResponse
    {
        /**
         * List of <code>BaselineOutput</code> structures
         */
        std::vector< Teamcenter::Services::Bom::_2008_06::Structuremanagement::BaselineOutput > output;
        /**
         * structure containing error codes and messages
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This represents output structure for addOrUpdateChildrenToParentLine operation.
     */
    struct BOMLinesOutput
    {
        /**
         * Identifier that helps the client to track the object created.
         */
        std::string clientId;
        /**
         * The refers to <b>BOMLine</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomline;
    };

    /**
     * This contains <b>Item</b> element Input structure for addOrUpdateChildrenToParentLine
     * operation.
     */
    struct ItemElementLineInfo
    {
        /**
         * Identifier that helps the client to track the object created. This is an optional
         * parameter.
         */
        std::string clientId;
        /**
         * Refers to the <b>Item</b> element object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  itemElement;
        /**
         * The occurrence type used for the child <b>BOMLine</b> creation objects.
         */
        std::string occType;
        /**
         * Refers to <b>BOMLine</b> object which represents itemElement for modification of
         * properties (Used in case of update).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  itemElementline;
        /**
         * Refers to the <code>BomLineProperties</code> struct.
         */
        BomLineProperties itemElementLineProperties;
    };

    /**
     * Refers to <b>Item</b> input structure for addOrUpdateChildrenToParentLine operation.
     */
    struct ItemLineInfo
    {
        /**
         * Identifier that helps the client to track the object created. This is an optional
         * parameter.
         */
        std::string clientId;
        /**
         * Refers to <b>Item</b> object.(used in case of precise structure)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  item;
        /**
         * Refers to the <b>ItemRevision</b> object (used in case of imprecise structure)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  itemRev;
        /**
         * Refers to occurrence type used for the child <b>BOMLine</b> (occurrence) creation.
         */
        std::string occType;
        /**
         * Refers to <b>BOMLine</b> for modification of its properties (Used in case of update
         * when clientId is empty).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomline;
        /**
         * Refers <code>BomLineProperties</code>  struct which represents to property name/value
         * pairs for additional properties.
         */
        BomLineProperties itemLineProperties;
    };

    /**
     * Return structure for removeChildrenFromParentLine operation
     */
    struct RemoveChildrenFromParentLineResponse
    {
        /**
         * The <i>ServiceData</i> structure is used to return the updated parent <i>BOMLine</i>
         * business objects whose children have been removed and can contain partial errors
         * if the operations fails to create bom window. It also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/bom/Bom_undef.h>
#endif

