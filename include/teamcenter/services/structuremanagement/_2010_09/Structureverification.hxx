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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_09_STRUCTUREVERIFICATION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_09_STRUCTUREVERIFICATION_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
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
            namespace _2010_09
            {
                class Structureverification;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structureverification
{
public:

    struct AccountabilityCheckResponse;
    struct AccountabilityCheckResult;
    struct ReportCriteria;
    struct ACInput;
    struct BOMLineNetEffectivityDetail;
    struct CompareNetEffectivityGroup;
    struct CompareNetEffectivityResponse;
    struct EndItemAndUnitDetails;
    struct EndItemDetail;
    struct EquivalentLines;
    struct TransientFileInfo;
    struct UnitAndLineDetails;

    /**
     * Contains all the results from the accountabilityCheck operation
     */
    struct AccountabilityCheckResponse
    {
        /**
         * A vector of accountability check results
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::AccountabilityCheckResult > accountabilityCheckResults;
        /**
         * A vector of reachable target lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > reachableTargets;
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Encapsulates one accountability check result
     */
    struct AccountabilityCheckResult
    {
        /**
         * The source bom line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceLine;
        /**
         * A vector of equivalent source lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentSourceLines;
        /**
         * A vector of equivalent target lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentTargetLines;
        /**
         * Accountability check result represented by a color value
         */
        int checkResult;
        /**
         * If OccurrenceGroup report option is chosen, this will be the created OccurrenceGroup.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  resultViewTag;
        /**
         * details of report files generated in the transient volume.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::TransientFileInfo > reportFileInfo;
    };

    /**
     * criteria for generating print report
     */
    struct ReportCriteria
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
     * Provides a set of input values for the accountabilityCheck operation
     */
    struct ACInput
    {
        /**
         * The source bom lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sourceObjects;
        /**
         * The target bom lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetObjects;
        /**
         * Sum of integer values representing different UI options
         */
        int options;
        /**
         * The possible source context line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceContextLine;
        /**
         * The possible target context line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContextLine;
        /**
         * Represents user choice in color display
         */
        int matchType;
        /**
         * The source filtering rule
         */
        std::string sourceFilteringRule;
        /**
         * The target filtering rule
         */
        std::string targetFilteringRule;
        /**
         * The source structure search depth; -1 represents all depths
         */
        int sourceDepth;
        /**
         * The target structure search depth; -1 represents all depths
         */
        int targetDepth;
        /**
         * Name of the OccurrenceGroup to be created.
         */
        std::string resultName;
        /**
         * optional description of the OccurrenceGroup to be created - if OccurrenceGroup report
         * option is chosen.
         */
        std::string resultDesc;
        /**
         * the criteria for printable report.
         */
        Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::ReportCriteria reportCriteria;
        /**
         * Indicates in what mode the accountability check is running. It can be occurrence
         * group mode, excel report mode, coloring mode, or a combination of report and coloring.
         * Valid values for        reportMode are: 1 - coloring mode, 2 - excel report mode,
         * 3 - coloring and excel report mode, 4 - occurrence group mode
         */
        int reportMode;
    };

    /**
     * structure to encapsulate a BOMLine and the associated endItem effectivity details.
     */
    struct BOMLineNetEffectivityDetail
    {
        /**
         * The bomline for which the effectivity details will be added.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  line;
        /**
         * The array of effectivity details for the bomline.
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
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::BOMLineNetEffectivityDetail > srcLineEffectivities;
        /**
         * effectivities of targetLines.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::BOMLineNetEffectivityDetail > targetLineEffectivities;
        /**
         * details of missing src by effectivity comparison.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::EndItemAndUnitDetails > missingSrcDetails;
        /**
         * Details of missing target effectivities.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::EndItemAndUnitDetails > missingTargetDetails;
        /**
         * Details of overlapping effectivities. Source lines that have overlapping units or
         * target lines that have overlapping units will be listed.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::EndItemAndUnitDetails > overlappingEffectivities;
        /**
         * Details of matching source and target effectivities
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::EndItemAndUnitDetails > matchingEffectivities;
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
         * lines.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::CompareNetEffectivityGroup > compareGroups;
        /**
         * serviceData to return any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * endItem (item used to specify the unit effectivity) tag and the associated UnitAndLineDetails
     * structure.
     */
    struct EndItemAndUnitDetails
    {
        /**
         * The endItem object to be associated with the Unit details.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endItem;
        /**
         * structure capturing the details of line(s) and effectivities.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_09::Structureverification::UnitAndLineDetails > details;
    };

    /**
     * structure to capture the details of enditem - the identifier, effectivity units associated
     * with that enditem and dates (future).
     */
    struct EndItemDetail
    {
        /**
         * the endItem to be associated with the units.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endItem;
        /**
         * unit ranges for the endItem. The units are in pairs - meaning - if you have unit
         * effectivtiy like:1-7,10 - this array will be 1,7,10,10.
         */
        std::vector< int > units;
        /**
         * date ranges. Currently not supported. Meaning - will be empty.
         */
        std::vector< Teamcenter::Soa::Common::DateTime > dates;
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
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > eqvSrcLines;
        /**
         * set of target bomlines (not the same window as source lines) that are equivalent
         * in a manner consistent with the source lines.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > eqvTargetLines;
    };

    /**
     * info about any transient report files that are generated.
     */
    struct TransientFileInfo
    {
        /**
         * Name of the file generated in transient volume.
         */
        std::string fileName;
        /**
         * Flag to indicate whether the file is a text file or binary file.
         */
        bool isText;
        /**
         * transient file ticket string.
         */
        std::string ticket;
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
         * lines. Current implementation does not support this.
         */
        std::vector< Teamcenter::Soa::Common::DateTime > dates;
        /**
         * list of of srclines that satisfy the units/dates in this structure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > srcLines;
        /**
         * list of of target lines ( lines from another window  that are equivalent in some
         * way to the src lines - eg: ID in context) that satisfy the units/dates in this structure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > targetLines;
    };




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


protected:
    virtual ~Structureverification() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

