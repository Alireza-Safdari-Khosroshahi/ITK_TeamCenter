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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_STRUCTUREVERIFICATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_STRUCTUREVERIFICATIONSERVICE_HXX

#include <teamcenter/services/structuremanagement/_2008_05/Structureverification.hxx>
#include <teamcenter/services/structuremanagement/_2008_12/Structureverification.hxx>
#include <teamcenter/services/structuremanagement/_2010_09/Structureverification.hxx>
#include <teamcenter/services/structuremanagement/_2012_02/Structureverification.hxx>
#include <teamcenter/services/structuremanagement/_2012_10/Structureverification.hxx>
#include <teamcenter/services/structuremanagement/_2013_05/Structureverification.hxx>



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
            class StructureverificationService;

/**
 * Contains StructureVerification Services
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

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API StructureverificationService
    : public Teamcenter::Services::Structuremanagement::_2008_05::Structureverification,
             public Teamcenter::Services::Structuremanagement::_2008_12::Structureverification,
             public Teamcenter::Services::Structuremanagement::_2010_09::Structureverification,
             public Teamcenter::Services::Structuremanagement::_2012_02::Structureverification,
             public Teamcenter::Services::Structuremanagement::_2012_10::Structureverification,
             public Teamcenter::Services::Structuremanagement::_2013_05::Structureverification
{
public:
    static StructureverificationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * An alignment connects two occurrences that are to be considered equivalent. They
     * are referred to as source and target. An alignment can connect one source to multiple
     * targets. Alignment can be used to transfer data from source to target. An alignment
     * check is used to determine if the source and target of an alignment have matching
     * data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        The source ebom and the target mbom structures.
     *
     * @return
     *         contains ServiceData along with vector of AlignmentCheckResponse
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::AlignmentCheckResponse checkAlignment ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::BOMLinePair >& input ) = 0;

    /**
     * The operation will call the existing accountability check functions,  which will
     * generate a check result for report in the colored display.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        a set of input values
     *
     * @return
     *         return AccountabilityCheckResponse including lines from source and target windows
     *         and check result
     *
     * @deprecated
     *         As of Teamcenter 8.3, use the accountabilityCheck operation from the _2010_09 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.3, use the accountabilityCheck operation from the _2010_09 namespace."))
#endif
    virtual Teamcenter::Services::Structuremanagement::_2008_12::Structureverification::AccountabilityCheckResponse accountabilityCheck ( const Teamcenter::Services::Structuremanagement::_2008_12::Structureverification::AccCheckInput&  input ) = 0;

    /**
     * The operation will call the existing accountability check functions, which will generate
     * a check result for report in the colored display.
     *
     * @param input
     *        Input values to the operation
     *
     * @return
     *         Results from the accountability check
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::AccountabilityCheckResponse accountabilityCheck ( const Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::ACInput&  input ) = 0;

    /**
     * effectivity of 2 sets of lines that are deemed equivalent in some form.
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
     *         effectivities for the set of input equivalent lines (source and target).
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::CompareNetEffectivityResponse compareNetEffectivity ( const std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::EquivalentLines >& lines,
        bool ignoreOverlapErrors,
        bool useStructureConfiguration,
        bool returnOnFirstMismatch ) = 0;

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

    /**
     * This operation returns the details of any differences between assignments for the
     * supplied source and target BOMLine objects. Assignments can be parts or tools, manual
     * or resolved by logical assignments. The operation takes the source and target BOMLine
     * objects and compares their assignments according to their types - manual assignments
     * are compared with manual, resolved with resolved, parts with parts and tools with
     * tools. The source and target assignments are returned by this operation in the form
     * of a table that is created by the output structures.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        The list of source and target BOMLine objects that were deemed equivalent by some
     *        method, for which any differences in assignments is required.
     *
     * @param partialMatchCriteria
     *        The list of partial match criteria for comparison. For each extension name it holds
     *        a PartialMatchCriteria object with comparison criteria of this extension.
     *
     * @return
     *         The differences between the source and target asssignments in the form of a table,
     *         where the columns represent the input equivalent BOMLines, and the rows are the assignments
     *         themselves. All the equivalent assignments are returned together on the same row.
     *         Assignments that are missing from the source or target are represented by "nulls".
     *         The following partial errors may be returned:  - 253001 This error can only be returned
     *         if there is some kind of environment issue or a bug in the code, it will never happen
     *         during normal execution.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::GetAssignmentComparisonDetailsResponse getAssignmentComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects,
        const std::vector< Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::StringToPartialMatchCriteria >& partialMatchCriteria ) = 0;

    /**
     * This operation retrieves comparison summaries for supplied extensions on the provided
     * equivalent sets of objects. The source objects in each set can be BOMLines, Cpd0DesignElements
     * or Cpd0DesignFeatures. The target objects in each set can be only BOMLines. For each
     * received extension on each received equivalent set it performs comparison of objects
     * in the equivalent set for this extension according to received criteria. For each
     * such comparison only the result is returned - a flag indicating whether the input
     * objects were determined different or not. This operation returns comparison results
     * for any number of extensions simultaneously.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        The list of source and target objects that were deemed equivalent by some method,
     *        for which extensions comparison results are required. The source objects can be BOMLines,
     *        Cpd0DesignElements or Cpd0DesignFeatures. The target objects can be only BOMLines.
     *
     * @param partialMatchCriteria
     *        The list of partial match criteria for comparison. For each extension name it holds
     *        a PartialMatchCriteria object with comparison criteria of this extension.
     *
     * @return
     *         The operation returns the extensions comparison results for each supplied equivalent
     *         set. For each extension on each equivalent set it returns a boolean flag which is
     *         "true" if there is any difference in comparison of this equivalent set for this extension,
     *         and "false" otherwise. The following partial errors may be returned:  - 253049 The
     *         input equivalent set of lines doesn't contain any source lines or any target lines.
     *         - 253001 This error can only be returned if there is some kind of environment issue
     *         or a bug in the code, it will never happen during normal execution.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::GetComparisonSummariesResponse getComparisonSummaries ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects,
        const std::vector< Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::StringToPartialMatchCriteria >& partialMatchCriteria ) = 0;

    /**
     * This operation returns the details of differences between the supplied Attribute
     * Groups for the supplied equivalent objects (that can be Cpd0DesignElement, Cpd0DesignFeature,
     * or BOMLine objects). For each supplied attribute group the operation returns the
     * list of its attributes, the attributes values for each supplied source and target,
     * and the result of comparing each attribute on all supplied sources and targets.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        The list ofCpd0DesignElement, Cpd0DesignFeature or BOMLine objects that  were deemed
     *        equivalent by some method, for which any differences in attribute groups is required.
     *
     * @param attributeGroupsNames
     *        The list of attribute groups names that need to be compared.
     *
     * @return
     *         For each supplied attribute group the operation returns the list of its attributes,
     *         the attributes' values for each supplied source and target, and the result of comparing
     *         each attribute on all supplied sources and targets. The following partial errors
     *         may be returned: - 253049 The input equivalent set doesn't contain any sources or
     *         any targets. - 253001 This error can only be returned if there is some kind of environment
     *         issue or a bug in the code, it will never happen during normal execution.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::AttributeGroupAndFormComparisonResponse getAttributeGroupsAndFormsComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects,
        const std::vector< std::string >& attributeGroupsNames ) = 0;

    /**
     * This operation returns the details of any differences between connected objects (that
     * can be either BOMLines or Cpd0DesignElements) for the supplied equivalent objects
     * (that can be either BOMLines or Cpd0DesignFeatures). The operation takes the source
     * and target and compares their connected objects. The source and target connected
     * objects are returned by this operation in the form of a table that is created by
     * the output structures.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        The list of BOMLines or Cpd0DesignFeatures that were deemed  equivalent  by some
     *        method, for which any differences in connected objects are required.
     *
     * @return
     *         For each input set of equivalent objects a list of comparison results of their connected
     *         elements (can be full match, partial match, or multiple match) and for each object
     *         in the set a detailed connected elements breakdown. The following partial errors
     *         may be returned:  - 253049 The input equivalent set doesn't contain any sources or
     *         any targets. -  253001 This error can only be returned if there is some kind of environment
     *         issue or a bug in    the code, it will never happen during normal execution.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::ConnectedObjectsComparisonResponse getConnectedObjectsComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructureverificationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

