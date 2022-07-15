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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_10_STRUCTUREVERIFICATION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_10_STRUCTUREVERIFICATION_HXX

#include <teamcenter/services/structuremanagement/_2012_02/Structureverification.hxx>
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
            namespace _2012_10
            {
                class Structureverification;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structureverification
{
public:

    struct AssignmentTypeDetail;
    struct ComparisonSummaries;
    struct ExtensionAssignmentTypeDetails;
    struct ExtensionComparisonSummary;
    struct GetAssignmentComparisonDetailsResponse;
    struct GetComparisonSummariesResponse;
    struct StringToPartialMatchCriteria;

    /**
     * a structure to pair the AssignmentTypeDetail Element with an index into the input
     * vector of equivalent sets of objects.
     */
    struct AssignmentTypeDetail
    {
        /**
         * Index of equivalent set in the input vector for which these details were calculated.
         */
        int index;
        /**
         * The list of all equivalent lines in the input equivalent set (all equivalent sources
         * in sequence and then all targets in sequence).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentLines;
        /**
         * Assignment type details of this equivalent set.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::ExtensionAssignmentTypeDetails > assignmentDetails;
    };

    /**
     * the  ExtensionComparisonSummary for each extension per input vector element
     */
    struct ComparisonSummaries
    {
        /**
         * Index of equivalent set in the input vector for which these results were calculated.
         */
        int index;
        /**
         * The list of elements that capture the result of an extension comparison.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::ExtensionComparisonSummary > summaries;
    };

    /**
     * Structure that keeps assignment types details for each extension name.
     */
    struct ExtensionAssignmentTypeDetails
    {
        /**
         * Extension name that was compared.
         */
        std::string extensionName;
        /**
         * A list of details for each assignment type.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::AssignmentTypeDetailElement > assignmentTypesDetails;
    };

    /**
     * an element to capture the result of an extension comparison
     */
    struct ExtensionComparisonSummary
    {
        /**
         * Extension name that was compared.
         */
        std::string extensionName;
        /**
         * True if there is a difference in comparison of this equivalent set for this extension,
         * false otherwise.
         */
        bool isDifferent;
    };

    /**
     * response of method getAssignmentComparisonDetails - a vector of AssignmentTypeDetail
     * element and serviceData
     */
    struct GetAssignmentComparisonDetailsResponse
    {
        /**
         * Object that captures any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The list of AssignmentType detail elements - one for each input equivalent set.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::AssignmentTypeDetail > details;
    };

    /**
     * response of method getComparisonSummaries - a vector of ComparisonSummaries element
     * and serviceData
     */
    struct GetComparisonSummariesResponse
    {
        /**
         * The list of extension summaries elements - one for each input equivalent set.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_10::Structureverification::ComparisonSummaries > comparisonSummaries;
        /**
         * Object that captures any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds PartialMatchCriteria object for each extension name.
     */
    struct StringToPartialMatchCriteria
    {
        /**
         * Extension name that needs to be compared.
         */
        std::string extensionName;
        /**
         * The comparison criteria of this extension.
         */
        Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::PartialMatchCriteria extensionCriteria;
    };




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


protected:
    virtual ~Structureverification() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

