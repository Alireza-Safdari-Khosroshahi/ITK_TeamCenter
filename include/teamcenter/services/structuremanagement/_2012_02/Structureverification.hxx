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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_02_STRUCTUREVERIFICATION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_02_STRUCTUREVERIFICATION_HXX

#include <teamcenter/services/structuremanagement/_2010_09/Structureverification.hxx>
#include <teamcenter/soa/client/model/ReportDefinition.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2012_02
            {
                class Structureverification;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structureverification
{
public:

    struct ACInput;
    struct AssignmentDetail;
    struct AssignmentTypeDetail;
    struct AssignmentTypeDetailElement;
    struct AsyncReportCriteria;
    struct AsyncACInput;
    struct AsyncDetails;
    struct AsyncPartialMatchCriteria;
    struct BatchDetails;
    struct BOMLineNetEffectivityDetail;
    struct CompareNetEffectivityGroup;
    struct CompareNetEffectivityResponse;
    struct DescendentDetail;
    struct DescendentDetailElement;
    struct EndItemAndUnitDetails;
    struct EquivalentLines;
    struct EquivalentSetElement;
    struct GetAssignmentComparisonDetailsResponse;
    struct GetDescendentComparisonDetailsResponse;
    struct GetPartitionComparisonDetailsResponse;
    struct GetPredecessorComparisonDetailsResponse;
    struct GetPropertyComparisonDetailsResponse;
    struct LogicalAssignmentDetail;
    struct PartialMatchCriteria;
    struct PartitionDetail;
    struct PredecessorDetail;
    struct PredecessorDetailElement;
    struct PropagationInput;
    struct PropagationResponse;
    struct PropagationResult;
    struct PropagationResultElement;
    struct PropertyDetail;
    struct PropertyDetailsElement;
    struct UnitAndLineDetails;

    /**
     * a map of string to AsyncPartialMatchCriteriaMap
     */
    typedef std::map< std::string, AsyncPartialMatchCriteria > AsyncStringToPartialMatchCriteriaMap;

    /**
     * a map of string (an id) and the vector of PropagationResult objects.
     */
    typedef std::map< std::string, std::vector< PropagationResultElement > > PropagationResultMap;

    /**
     * a map of string to vector of dates
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > StringToDateVectorMap;

    /**
     * String to vector of doubles map.
     */
    typedef std::map< std::string, std::vector< double > > StringToDblVectorMap;

    /**
     * map of string to vector of integers.
     */
    typedef std::map< std::string, std::vector< int > > StringToIntVectorMap;

    /**
     * a map of string to vector of objects.
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > StringToObjVectorMap;

    /**
     * a map of string to PartialMatchCriteriaMap
     */
    typedef std::map< std::string, PartialMatchCriteria > StringToPartialMatchCriteriaMap;

    /**
     * a map of String to vector of strings.
     */
    typedef std::map< std::string, std::vector< std::string > > StringToStrVectorMap;

    /**
     * provides a set of input values for the accountabilityCheck operation.
     */
    struct ACInput
    {
        /**
         * The source bom lines.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sourceObjects;
        /**
         * The target bom lines.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetObjects;
        /**
         * mask of integer values representing different UI options.
         */
        int options;
        /**
         * Optional source context line.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceContextLine;
        /**
         * optional target context line.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContextLine;
        /**
         * Represents user choice of color display.
         */
        int matchType;
        /**
         * The source filtering rule.
         */
        std::string sourceFilteringRule;
        /**
         * The target filtering rule.
         */
        std::string targetFilteringRule;
        /**
         * the depth of source structure. -1 represents all depths.
         */
        int sourceDepth;
        /**
         * The depth of target structure from each target root. -1 to set it to any depth.
         */
        int targetDepth;
        /**
         * Name of occurrenceGroup to be created - when report is generated.
         */
        std::string resultName;
        /**
         * optional description of the OccurrenceGroup to be created.
         */
        std::string resultDesc;
        /**
         * criteria for printable report.
         */
        Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::ReportCriteria reportCriteria;
        /**
         * Indicates which mode the accountability check report has to be generated. Occurrence
         * group mode of excel report mode or coloring mode or a combination of those or batch
         * report or batch propagate. This is a bit masked flag. 1 - coloring mode, 2 - generate
         * report, 3 - color and generate report, 4 - occurrence group report, 8 - batch report,
         * 16 - batch propagate.
         */
        int reportMode;
        /**
         * the set of options to be used for comparison on equivalent lines. It is a map - with
         * the key being the name of plugin or string to be used as a discriminator between
         * various components.
         */
        StringToPartialMatchCriteriaMap partialMatchCriteria;
        /**
         * Flag to indicate whether  to include scope lines as part of result set.
         */
        bool includeScopeLines;
    };

    /**
     * For each line in input equivalent set  holds the tag of the current assigned objects
     * for that line.
     */
    struct AssignmentDetail
    {
        /**
         * size is same as the size of the input equivalent line. It is the list of assignments
         * (one per line) - across the row.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > assignments;
        /**
         * flag to indicate match of the current assignment.
         */
        int matchType;
    };

    /**
     * a structure to pair the AssignmentTypeDetail Element with an index into the input
     * vector of equivalent sets of objects.
     */
    struct AssignmentTypeDetail
    {
        /**
         * index into the input vector.
         */
        int index;
        /**
         * the size of the vector is same as maximum number of  assignmentTypes among the set
         * equivalent lines. eg: if src1, target1 are equivalent and src1 has 3 manual assignments
         * and target1 has 2 - this vector will have 3 elements. The first AssignmentTypeDetailElement
         * will have src1_assign1, target1_assign1; the second AssignmentTypeDetailElement will
         * have src1_assign2,target1_assign2; the third AssignmentTypeDetailElement will have
         * src1_assign3, NULL
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::AssignmentTypeDetailElement > details;
        /**
         * the set of all equivalent lines in input (all equivalent srcs in sequence and then
         * all targets in sequence).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentLines;
    };

    /**
     * a structure to capture the details for assignment comparison.
     */
    struct AssignmentTypeDetailElement
    {
        /**
         * a string to indicate the type of assignment (MEConsumed, MEResource etc.)
         */
        std::string assignmentType;
        /**
         * length of the vector will be the maximum number of assignments among all the equivalent
         * lines for the given type. If there are 3 assigments for src1 and 1 for target1 -
         * the size of this vector will be 3, with the first AssignmentDetails element having
         * {src1assign1,target1assign1}, the second AssignmentDetail element having {src1assign2,NULLTAG},
         * the third {src1assign3,NULLTAG}.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::AssignmentDetail > manualAssignments;
        /**
         * length of the vector will be the maximum number of logical assignments among all
         * the equivalent lines for the given type.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::LogicalAssignmentDetail > logicalAssignments;
    };

    /**
     * criteria for generating print report
     */
    struct AsyncReportCriteria
    {
        /**
         * report definition Tag (required)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ReportDefinition>  rdTag;
        /**
         * name of the report.
         */
        std::string reportName;
        /**
         * stylesheet Tag (optional)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  stylesheetTag;
        /**
         * Name of the stylesheet.
         */
        std::string stylesheetName;
        /**
         * name of containing DataSet (optional)
         */
        std::string datasetName;
        /**
         * a vector of strings containing the Names in a series of Name/Value pairs used to
         * specify additional criteria (optional)
         */
        std::vector< std::string > criteriaName;
        /**
         * a vector of strings containing the Values in a series of Name/Value pairs used to
         * specify additional criteria (optional)
         */
        std::vector< std::string > criteriaValues;
        /**
         * The uid for the context dataset
         */
        std::string datasetCtxUID;
        /**
         * Dataset context tag
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  datasetCtxObj;
        /**
         * relation name to be used.
         */
        std::string relationName;
        /**
         * Dataset type to be used.
         */
        std::string datasetType;
        /**
         * StructElement name="reportOptionsNames" description="a vector of strings containing
         * the Names in a series of Name/Value pairs used to specify additional criteria (optional)
         */
        std::vector< std::string > reportOptionsNames;
        /**
         * a vector of strings containing the Values in a series of Name/Value pairs used to
         * specify additional criteria (optional)
         */
        std::vector< std::string > reportOptionsValues;
        /**
         * a vector of Tags representing context object(s) (required for item reports)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextObjects;
        /**
         * a vector of uids representing context objects
         */
        std::vector< std::string > contextObjectUIDs;
    };

    /**
     * provides a set of input values for the accountabilityCheckAsync operation.
     */
    struct AsyncACInput
    {
        /**
         * persistent objects that can be converted to bomlines. Currently, the only supported
         * object is VisStructureContext object, with the array length being 1.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sourceObjects;
        /**
         * persistent objects (target) that can be converted to bomlines. Currently, the only
         * supported object is VisStructureContext object, with the array length being 1.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetObjects;
        /**
         * mask of integer values representing different UI options.
         */
        int options;
        /**
         * Optional source context line. Currently unused.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceContextLine;
        /**
         * optional target context line. Currently, not used.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContextLine;
        /**
         * Represents user choice of color display.
         */
        int matchType;
        /**
         * The source filtering rule.
         */
        std::string sourceFilteringRule;
        /**
         * The target filtering rule.
         */
        std::string targetFilteringRule;
        /**
         * the depth of source structure. -1 represents all depths.
         */
        int sourceDepth;
        /**
         * The depth of target structure from each target root. -1 to set it to any depth.
         */
        int targetDepth;
        /**
         * Name of occurrenceGroup to be created - when report is generated.
         */
        std::string resultName;
        /**
         * optional description of the OccurrenceGroup to be created.
         */
        std::string resultDesc;
        /**
         * criteria for printable report.
         */
        Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::AsyncReportCriteria reportCriteria;
        /**
         * Indicates which mode the accountability check report has to be generated.10 - batch
         * report, 16 - batch propagate.
         */
        int reportMode;
        /**
         * the set of options to be used for comparison on equivalent lines. It is a map - with
         * the key being the name of plugin or string to be used as a discriminator between
         * various components.
         */
        AsyncStringToPartialMatchCriteriaMap partialMatchCriteria;
        /**
         * Flag to indicate whether  to include scope lines as part of result set.
         */
        bool includeScopeLines;
    };

    /**
     * details that are to be specified if an operation is to be performed asynchronously.
     * This is same as the BatchUtils parameters that is (optionally) passed to accountabilityCheck.
     * Duplicated as structures are not to be shared in soa framework.
     */
    struct AsyncDetails
    {
        /**
         * any user defined string for recognizing the request
         */
        std::string identifier;
        /**
         * processing mode on server. Possible values are "BackGround", "Blocking" and "InProcess"
         * (case sensitive). Currently, the only supported value is BackGround. In this mode
         * the Dispatcher services must be installed, or the server will default to InProcess
         * (meaning same tcserver as the one the client connects to will be used for accountability).
         */
        std::string mode;
        /**
         * processing site. 0 - local. This information is used in the blocking mode to get
         * the http url.
         */
        int site;
        /**
         * possible values - 0-3, 0 being the lowest.
         */
        int priority;
        /**
         * start date/time of scheduled dispatcher request
         */
        Teamcenter::Soa::Common::DateTime startTime;
        /**
         * end date/time of scheduled dispatcher request
         */
        Teamcenter::Soa::Common::DateTime endTime;
        /**
         * on which day of the week translator (async process) has to be run. Should have 7
         * entries and a true indicates should be run on that day. Starting on Sunday (1st entry).
         */
        std::vector< bool > daysOfWeek;
        /**
         * number of times the async process has to run.
         */
        int endAfterOccurrences;
        /**
         * objects used directly or indirectly for the asynchronous processing.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > primaryObjects;
        /**
         * any auxiliary objects to be used as additional info during processing of asynchronous
         * request. Example - a folder to add some datasets to.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaryObjects;
    };

    /**
     * a structure to capture generic Partial Match criteria
     */
    struct AsyncPartialMatchCriteria
    {
        /**
         * map of string to vector or integers.
         */
        StringToIntVectorMap intMap;
        /**
         * map of string to vector of doubles.
         */
        StringToDblVectorMap dblMap;
        /**
         * map of string to vector of strings.
         */
        StringToStrVectorMap strMap;
        /**
         * map of string to vector of objects.
         */
        StringToObjVectorMap objMap;
    };

    /**
     * details that are to be specified if an operation is to be performed asynchronously.
     */
    struct BatchDetails
    {
        /**
         * any user defined string for recognizing the request
         */
        std::string identifier;
        /**
         * processing mode on server. Possible values are "BackGround", "Blocking" and "InProcess"
         * (case sensitive). Currently, the only supported value is BackGround. In this mode
         * the Dispatcher services must be installed, or the server will default to InProcess
         * (meaning same tcserver as the one the client connects to will be used for accountability).
         */
        std::string mode;
        /**
         * processing site. 0 - local. This information is used in the blocking mode to get
         * the http url.
         */
        int site;
        /**
         * possible values - 0-3, 0 being the lowest.
         */
        int priority;
        /**
         * start date/time of scheduled dispatcher request
         */
        Teamcenter::Soa::Common::DateTime startTime;
        /**
         * end date/time of scheduled dispatcher request
         */
        Teamcenter::Soa::Common::DateTime endTime;
        /**
         * on which day of the week translator (async process) has to be run. Should have 7
         * entries and a true indicates should be run on that day. Starting on Sunday (1st entry).
         */
        std::vector< bool > daysOfWeek;
        /**
         * number of times the async process has to run.
         */
        int endAfterOccurrences;
        /**
         * objects used directly or indirectly for the asynchronous processing.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > primaryObjects;
        /**
         * any auxiliary objects to be used as additional info during processing of asynchronous
         * request. Example - a folder to add some datasets to.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaryObjects;
    };

    /**
     * structure to encapsulate a BOMLine and the associated endItem effectivity details.
     */
    struct BOMLineNetEffectivityDetail
    {
        /**
         * The bomline for which the effectivity details will added.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  line;
        /**
         * The array of effectivity details for the bomline
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::EndItemDetail > effDetails;
    };

    /**
     * structure to capture the response of CompareNetEffectivity method.
     */
    struct CompareNetEffectivityGroup
    {
        /**
         * effectivities of the source lines.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::BOMLineNetEffectivityDetail > srcLineEffectivities;
        /**
         * effectivities of targetLines.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::BOMLineNetEffectivityDetail > targetLineEffectivities;
        /**
         * details of missing src by effectivity comparison.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EndItemAndUnitDetails > missingSrcDetails;
        /**
         * Details of missing target effectivities
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EndItemAndUnitDetails > missingTargetDetails;
        /**
         * Details of overlapping effectivities. Source lines that have overlapping units or
         * target lines that have overlapping units will be listed.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EndItemAndUnitDetails > overlappingEffectivities;
        /**
         * Details of matching source and target effectivities
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EndItemAndUnitDetails > matchingEffectivities;
        /**
         * flag that is set to true if there is a mismatch.
         */
        bool isMisMatch;
    };

    /**
     * structure to capture the response of compareNetEffectivityGroup method.  Vector of
     * CompareNetEffectivityGroup structures one per input set based equivalent lines and
     * a serviceData member to report partial errors.
     */
    struct CompareNetEffectivityResponse
    {
        /**
         * vector of the compare results for each corresponding set of input vector of equivalent
         * lines
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::CompareNetEffectivityGroup > compareGroups;
        /**
         * serviceData to return any partial errors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * the list of DescendentDetailElements for each set of input equivalent objects.
     */
    struct DescendentDetail
    {
        /**
         * position in the input vector.
         */
        int index;
        /**
         * The size of the vector matches the maximum number of descendents for each line in
         * input equivalent set at index above (given now by equivalentLines - src lines being
         * followed by targetlines). Eg: equivalentset(src1,target1) - src1 has 3 children,
         * target1 has 1 child. details element vector size will be 3. The first DescendentDetailElement
         * will contain 2 children: SrcChild1,targetChild1. The second DescendentDetailElement
         * will have SrcChild2,NULLTAG, and 3rd DescendentDetailElement will have SrcChild3,NULLTAG.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::DescendentDetailElement > details;
        /**
         * the set of all equivalent lines in input (all equivalent srcs in sequence and then
         * all targets in sequence).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentLines;
    };

    /**
     * the list of DescendentDetailElements for each set of input equivalent objects.
     */
    struct DescendentDetailElement
    {
        /**
         * The size of the vector will match the size of the equivalent lines at input index
         * i. This array represents one predecessor per input line (row in a table, and not
         * a column). . Eg: SrcChild1, NULLTAG, TargetChild1, NULLTAG (assuming 4 eqv. lines)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > children;
        /**
         * 0 means fullmatch, 1 means match, 2 means multiple match
         */
        int matchType;
    };

    /**
     * endItem (item used to specify the unit effectivity) tag and the associated UnitAndLineDetails
     * structure.
     */
    struct EndItemAndUnitDetails
    {
        /**
         * Teamcenter::BusinessObject The endItem object to be associated with the Unit details
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endItem;
        /**
         * structure capturing the details of line(s) and effectivities.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::UnitAndLineDetails > details;
    };

    /**
     * Lines from a Source Window and a Target Window that are equivalent. For example -
     * having the same ID in Context or other criteria.
     */
    struct EquivalentLines
    {
        /**
         * set of source bomlines that are equivalent based on some criteria like ID in context.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > eqvSrcLines;
        /**
         * set of target bomlines (not the same window as source lines) that are equivalent
         * in a manner consistent with the source lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > eqvTargetLines;
    };

    /**
     * a structure to capture the equivalent src and target lines along with the partial
     * match criteria.
     */
    struct EquivalentSetElement
    {
        /**
         * the src lines which are equivalent (currently only id in context)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > eqvSrcLines;
        /**
         * equivalent target lines - based on In context id (absoccid) or apn or ebop criteria
         * (origin link, logical designator, uid )
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > eqvTargetLines;
        /**
         * input map for specifying criteria, the key being server extension id.
         */
        StringToPartialMatchCriteriaMap criteria;
    };

    /**
     * response of method getAssignmentComparisonDetails - a vector of AssignmentTypeDetail
     * element and serviceData
     */
    struct GetAssignmentComparisonDetailsResponse
    {
        /**
         * a list of AssignmentType detail elements - for all the input equivalent sets.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::AssignmentTypeDetail > details;
        /**
         * serviceData element to capture any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * structure to capture the response of getDescendentComparisonDetails method. Has the
     * list of details for each input set and serviceData to capture partial errors.
     */
    struct GetDescendentComparisonDetailsResponse
    {
        /**
         * detail list.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::DescendentDetail > details;
        /**
         * serviceData member to capture any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * structure to capture the vector of PartitionDetail elements and serviceData for partial
     * errors.
     */
    struct GetPartitionComparisonDetailsResponse
    {
        /**
         * vector of partitionDetail elements.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PartitionDetail > details;
        /**
         * serviceData member to capture partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * return the list of predecessor detail elements and service data for partial errors.
     */
    struct GetPredecessorComparisonDetailsResponse
    {
        /**
         * details about the predecessor detail for each element.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PredecessorDetail > details;
        /**
         * serviceData to capture any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * response of getPropertyComparisonDetails method.
     */
    struct GetPropertyComparisonDetailsResponse
    {
        /**
         * the list of elements that have the details for each property in the input.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PropertyDetail > details;
        /**
         * serviceData element to capture any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * For each line in input equivalent set  holds the tag of the current assigned objects
     * for that line.
     */
    struct LogicalAssignmentDetail
    {
        /**
         * for each line in input equivalent set holds the criteria of the current line's LA
         * - across the row.
         */
        std::vector< std::string > criteria;
        /**
         * length of the vector will be the maximum number of resolved assignments among all
         * the equivalent lines for the given type.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::AssignmentDetail > resolvedAssignments;
        /**
         * flag to indicate match of the current assignment.
         */
        int matchType;
        /**
         * For each line in input equivalent set holds the logical assignment or tool requirement
         * object.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > logicalAssignments;
    };

    /**
     * a structure to capture generic Partial Match criteria
     */
    struct PartialMatchCriteria
    {
        /**
         * map of string to vector or integers.
         */
        StringToIntVectorMap intMap;
        /**
         * map of string to vector of doubles.
         */
        StringToDblVectorMap dblMap;
        /**
         * map of string to vector of strings.
         */
        StringToStrVectorMap strMap;
        /**
         * map of string to vector of objects.
         */
        StringToObjVectorMap objMap;
        /**
         * map of string to vector of dates
         */
        StringToDateVectorMap dateMap;
    };

    /**
     * structure to capture the position(index) in the input equivalence set and the partition
     * elements vector.
     */
    struct PartitionDetail
    {
        /**
         * position in the input vector.
         */
        int index;
        /**
         * The size of the vector matches the equivalent lines. This list the partition per
         * input equivalent line as a row.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > partitions;
        /**
         * flag to indicate whether any of the partitions in a single row is different.
         */
        bool isDifferent;
        /**
         * the set of all equivalent lines in input (all equivalent srcs in sequence and then
         * all targets in sequence).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentLines;
    };

    /**
     * the list of PredecessorDetailElements for each set of input equivalent objects.
     */
    struct PredecessorDetail
    {
        /**
         * position in the input vector.
         */
        int index;
        /**
         * The size of the vector matches the maximum number of predecessors for each line in
         * input equivalent set at index above (given now by equivalentLines - src lines being
         * followed by targetlines). The PredecessorDetailElement will be the size of the input
         * lines. Eg: equivalentset(src1,target1) - src1 has 3 predecessors, target1 has 1 predecessor.
         * details element vector size will be 3. The first PredecessorDetailElement will contain
         * 2 predecessors: SrcPred1,targetPred1. The second PredecessorDetailElement will have
         * SrcPred2,NULLTAG, and 3rd PredecessorDetailElement will have SrcPred3,NULLTAG.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PredecessorDetailElement > details;
        /**
         * the set of all equivalent lines in input (all equivalent srcs in sequence and then
         * all targets in sequence).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentLines;
    };

    /**
     * the list of PredecessorDetailElements for each set of input equivalent objects.
     */
    struct PredecessorDetailElement
    {
        /**
         * The size of the vector will match the size of the equivalent lines at input index
         * i. This array represents one predecessor per input line (row in a table, and not
         * a column). . Eg: SrcPred1, NULLTAG, TargetPred1, NULLTAG (assuming 4 eqv. lines)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > predecessors;
        /**
         * 0 means fullmatch, 1 means match, 2 means multiple match
         */
        int matchType;
    };

    /**
     * the input structure for propagateProperties.
     */
    struct PropagationInput
    {
        /**
         * the target object to which the changes will be propagated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  target;
        /**
         * the source object(s) from which the changes will be propagated to target.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sources;
        /**
         * the partialMatchCriteria structure to be used for change propagation. This is a map
         * of a string (a client id) to that client's properties/criteria.
         */
        StringToPartialMatchCriteriaMap criteria;
    };

    /**
     * The response of Propagation Service.
     */
    struct PropagationResponse
    {
        /**
         * a vector of propagationResults.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PropagationResult > results;
        /**
         * a fms ticket for the transient file that captures the log of propagation service.
         */
        std::string logFileTicket;
        /**
         * Service Data object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * a structure to capture a single result for an object that is being propagated from
     * one context to another.
     */
    struct PropagationResult
    {
        /**
         * a integer representing the position in input vector.
         */
        int index;
        /**
         * a map of string to vector of propagationResultElements. The key of the map would
         * indicate the client id corresponding to what is passed in PropagationInput.
         */
        PropagationResultMap propagationResults;
    };

    /**
     * a structure to capture a single result for an object that is being propagated from
     * one context to another.
     */
    struct PropagationResultElement
    {
        /**
         * an object which is participating in the propagation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * successfully propagatedProperties.
         */
        std::vector< std::string > propagatedProperties;
        /**
         * an optional log file ticket. If the extension/server generates a specific logfile
         * - this will be the fms ticket for that file (transient).
         */
        std::string logFileTicket;
    };

    /**
     * the  propertyDetailElement for each of the properties per input vector element.
     */
    struct PropertyDetail
    {
        /**
         * index of the input vector of equivalent set of obejcts.
         */
        int index;
        /**
         * the list of PropertyDetailsElement
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PropertyDetailsElement > details;
    };

    /**
     * a element to capture the details of a property for an object(s).
     */
    struct PropertyDetailsElement
    {
        /**
         * the name of the property.
         */
        std::string propertyName;
        /**
         * flag to indicate if any of the objects have a value(s) that is different.
         */
        bool isDifferent;
    };

    /**
     * Structure to capture the Equivalent BomLines (potentially from 2 windows - a source
     * and target window) along with their matched units or dates.
     */
    struct UnitAndLineDetails
    {
        /**
         * all or a subset of Unit numbers/dates associated with the source and targetlines.
         * The units are in pairs - meaning - if you have unit effectivtiy like:1-7,10 - this
         * array will be 1,7,10,10.
         */
        std::vector< int > units;
        /**
         * If date effectivity is  used - this will have the date ranges for the equivalent
         * lines. Current implementation does not support thi
         */
        std::vector< Teamcenter::Soa::Common::DateTime > dates;
        /**
         * list of of srclines that satisfy the units/dates in this structure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > srcLines;
        /**
         * list of of target lines ( lines from another window  that are equivalent in some
         * way to the src lines - eg: ID in context) that satisfy the units/dates in this structure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetLines;
    };




    /**
     * get the details of any differences between assignments for the supplied src and target
     * objects.
     *
     * @param equivalentObjects
     *        The source and target objects that were deemed equivalent by some method, for which
     *        any differences in assignments is required.
     *
     * @param partRelationTypes
     *        past assignments to be considered for equivalence.
     *
     * @param toolRelationTypes
     *        tool assignments to be considered for equivalence - eg:weld
     *
     * @param compareLA
     *        LogicalAssignment consideration for comparison: 0  means NO_COMPARE, 1means DEFINITION_ONLY,
     *        2 means DEFINITION_AND_RESOLVED
     *
     * @param compareManual
     *        flag to indicate whether to compare manual assignments or not.
     *
     * @return
     *         a vector of AssignmentTypeDetail elements and serviceData
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::GetAssignmentComparisonDetailsResponse getAssignmentComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects,
        const std::vector< std::string >& partRelationTypes,
        const std::vector< std::string >& toolRelationTypes,
        int compareLA,
        bool compareManual ) = 0;

    /**
     * The operation will call the existing accountability check functions, which will generate
     * a check result for report in the colored display.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        Input values to the operation
     *
     * @param batchDetails
     *        In case the operation has to be performed asynchronously, this parameter can be used
     *        to pass that information. Pass NULL for second parameter if unused.
     *
     * @return
     *         Results from the accountability check
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::AccountabilityCheckResponse accountabilityCheck ( const Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::ACInput&  input,
        const Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::BatchDetails*  batchDetails ) = 0;

    /**
     * effectivity of 2 sets of lines that are deemed equivalent in some form.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param lines
     *        Set of lines from a source and target structure that are deemed equivalent  (either
     *        by ID in context or some other criteria). Vector to support set based approach.
     *
     * @param ignoreOverlapErrors
     *        flag to indicate that the compare proceed even if there are overlapping effectivities
     *        in source or in target lines.
     *
     * @param useStructureConfiguration
     *        flag to indicate whether to use the revision rule and effectivity groups in computing
     *        net effectivity - for use during comparison.
     *
     * @param returnOnFirstMismatch
     *        Flag to indicate that compareNetEffectivity method should return on first mismatch
     *        and not process further. In this case the response will not have much information
     *        - other than the mismatch flag - and partial errors if any.
     *
     * @return
     *         returns CompareNetEffectivityResponse which has details of matching/missing and overlapping
     *         effectivities for the set of input equivalent lines.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::CompareNetEffectivityResponse compareNetEffectivity ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& lines,
        bool ignoreOverlapErrors,
        bool useStructureConfiguration,
        bool returnOnFirstMismatch ) = 0;

    /**
     * for each input equivalent set capture the response of getDescendentComparisonDetails
     * method. Has the list of details for each input set and serviceData to capture partial
     * errors.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        list of equivalent sets of lines.
     *
     * @param ignoreStructureSpecific
     *        flag to indicate if non-allocated lines are to be ignored.
     *
     * @return
     *         structure to capture the response of getDescendentComparisonDetails method. Has the
     *         list of details for each input set and serviceData to capture partial errors.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::GetDescendentComparisonDetailsResponse getDescendentComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& input,
        bool ignoreStructureSpecific ) = 0;

    /**
     * service to get details on a mismatch of parititions.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        equivalent sets of src/targets objects.
     *
     * @return
     *         details of a mismatch of partitions.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::GetPartitionComparisonDetailsResponse getPartitionComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& input ) = 0;

    /**
     * for a given equivalent set of lines/object, compute and return the list of predecessor
     * detail elements and flag if different.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        list of input equivalent objects.
     *
     * @param ignoreStructureSpecific
     *        flag to indicate if non-allocated lines are to be ignored.
     *
     * @return
     *         return the list of predecessor detail elements and service data for partial errors.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::GetPredecessorComparisonDetailsResponse getPredecessorComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& input,
        bool ignoreStructureSpecific ) = 0;

    /**
     * method to retrieve details for supplied properties on the provided equivalent sets
     * of lines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        the list of equivalent objects and the property names supplied in the string map
     *        of strings.
     *
     * @return
     *         return the property values for each supplied equivalent set and any partial errors.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::GetPropertyComparisonDetailsResponse getPropertyComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentSetElement >& equivalentObjects ) = 0;

    /**
     * method to propagate properties.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        The list of PropagationInput structures - one for each target which needs the changes
     *        propagated to.
     *
     * @return
     *         a map of string to vector of PropagationResultElement structure. The string key will
     *         match to the input PartialMatchCriteria.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PropagationResponse propagateProperties ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PropagationInput >& input ) = 0;


protected:
    virtual ~Structureverification() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

