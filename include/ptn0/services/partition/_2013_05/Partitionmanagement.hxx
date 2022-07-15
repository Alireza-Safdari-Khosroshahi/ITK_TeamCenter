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

#ifndef PTN0_SERVICES_PARTITION__2013_05_PARTITIONMANAGEMENT_HXX
#define PTN0_SERVICES_PARTITION__2013_05_PARTITIONMANAGEMENT_HXX

#include <ptn0/services/partition/_2011_06/Partitionmanagement.hxx>
#include <teamcenter/soa/client/model/Mdl0ApplicationModel.hxx>
#include <teamcenter/soa/client/model/Ptn0Partition.hxx>
#include <teamcenter/soa/client/model/Ptn0PartitionScheme.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <ptn0/services/partition/Partition_exports.h>

namespace Ptn0
{
    namespace Services
    {
        namespace Partition
        {
            namespace _2013_05
            {
                class Partitionmanagement;

class PTN0SOAPARTITIONSTRONGMNGD_API Partitionmanagement
{
public:

    struct ClonePartitionsFailedObjsErrorStruct;
    struct ClonePartitionsInputInfo;
    struct ClonePartitionsOutputInfo;
    struct ClonePartitionsResponse;
    struct CreateOrUpdateRealizedPartitionsInputInfo;
    struct StringBoolMapStruct;

    /**
     * Contains the mapping between string and boolean values.
     */
    typedef std::map< std::string, bool > StringBoolMap;

    /**
     * <code>ClonePartitionsFailedObjsErrorStruct</code> structure represents the source
     * Partitions that failed, source Partition Scheme and <code>ErrorValuesStruct</code>
     * structure.
     */
    struct ClonePartitionsFailedObjsErrorStruct
    {
        /**
         * The source Partition scheme business object of the partition that failed to clone.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  sourceScheme;
        /**
         * The source Partition business object that failed to clone.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  sourcePartition;
        /**
         * List containing error detail.
         */
        Ptn0::Services::Partition::_2011_06::Partitionmanagement::ErrorValuesStruct errorValue;
    };

    /**
     * <code>ClonePartitionsInputInfo</code> structure contains the target Application Model,
     * clone input options and source Application Model or source Partition schemes.
     */
    struct ClonePartitionsInputInfo
    {
        /**
         * The source Partition Template business object from where partition breakdowns are
         * to be cloned. Partitions from all schemes from a model, can be cloned by giving business
         * object as input. <code>sourceSchemes</code> should be null to clone entire partition
         * breakdown of the given Application Model.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  sourceModel;
        /**
         * A list of source Partition schemes from where partition breakdowns are to be cloned.
         * Partitions from given schemes  can be cloned by giving Partition schemes as input.
         * Application Model of the given Partition schemes are known hence <code>sourceModel</code>
         * input will be ignored.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  > sourceSchemes;
        /**
         * A list containing map of option names and flag values (string/boolean). Valid option
         * names are:
         * <br>
         * <code>checkOutOnCreate</code> - if true, the cloned partitions are checked-out on
         * create.
         * <br>
         * <code>includeVariantExpressions</code> - if true, the variant expressions are carried
         * forward from source partitions to target partitions.
         * <br>
         * <code>includeAttributeGroups</code> - if true, the attribute groups are carried forward
         * from source partitions to target partitions.
         * <br>
         */
        std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::StringBoolMapStruct > inputOptions;
        /**
         * The target Application Model business object where the cloned partition breakdowns
         * are to be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  targetModel;
    };

    /**
     * <code>ClonePartitionsOutputInfo</code> structure represents the source Application
     * Model for which failed partitions are reported and the list of <code>ClonePartitionsFailedObjsErrorStruct</code>
     * strucutre containing source Partition scheme, source Partitions and <code>ErrorValuesStruct</code>
     * structure.
     */
    struct ClonePartitionsOutputInfo
    {
        /**
         * The source ApplicationModel business object for which failed partitions are reported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  sourceModel;
        /**
         * List of structure containing source Partition scheme, source Partition and its error
         * structure.
         */
        std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::ClonePartitionsFailedObjsErrorStruct > failedPartitions;
    };

    /**
     * <code>ClonePartitionsResponse</code> structure represents vector of <code>ClonePartitionsOutputInfo</code>
     * and the errors via <code>serviceData</code> if invalid input parameters are supplied.
     */
    struct ClonePartitionsResponse
    {
        /**
         * Contatins list of newly created Partition objects. Also contains list of any errors
         * occurred during the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List containing partitions that failed to clone, Partition schemes of the failed
         * partitions, and source Application Model of the failed Partitions and the corresponding
         * failure detail. This will be empty when there is no failure in partition cloning.
         */
        std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::ClonePartitionsOutputInfo > output;
    };

    /**
     * <code>CreateOrUpdateRealizedPartitionsInputInfo</code> structure contains target
     * Application Model, instantiation input options, Revision Rule, Variant Rule and source
     * Application Model or source Partition Schemes or source Partitions
     */
    struct CreateOrUpdateRealizedPartitionsInputInfo
    {
        /**
         * The target Application Model business object where the realized partition breakdowns
         * are to be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  targetModel;
        /**
         * A list containing map of option names and flag values (string/boolean). Valid option
         * names are:
         * <br>
         * <code>includeVariantExpressions</code> - if true, the variant expressions are carried
         * forward from source partitions to target partitions.
         * <br>
         * <code>includeAttributeGroups</code> - if true, the attribute groups are carried forward
         * from source partitions to target partitions.
         * <br>
         * <code>includeChildPartitions</code> - if true, the child Partitions are carried forward
         * from source partitions to target partitions.
         * <br>
         * <code>updateRealizedPartition</code> - if true, updates the realized partitions from
         * source partitions.
         */
        std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::StringBoolMapStruct > inputOptions;
        /**
         * The Revision Rule to be applied to configure the partition breakdowns at source Application
         * Model.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
        /**
         * The Variant Rule to be applied to configure the partition breakdowns at source Application
         * Model.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  varRule;
        /**
         * The source Partition Template business object from where partition breakdowns are
         * to be realized. Partitions from all schemes from a model, can be realized by giving
         * Application Model business object as input. Both <code>sourceSchemes</code> and <code>sourcePartitions</code>
         * elements should be null to realize entire partition breakdown of the given Application
         * Model.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  sourceModel;
        /**
         * A list of source Partition schemes from where partition breakdowns are to be realized.
         * Partitions from different Partition schemes  can be realized by giving Partition
         * schemes as input. Application Model of the given Partition schemes are known, hence
         * <code>sourceModel</code> input will be ignored. <code>sourcePartitions</code> elements
         * should be null to realize entire partition breakdown of the given Partition schemes.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  > sourceSchemes;
        /**
         * A list of source Partitions from where partition breakdowns are to be realized. Partitions
         * from different schemes and different models can be realized selectively by giving
         * Partitions as input. Application Models and Partition schemes of the given Partitions
         * are known, hence both <code>sourceModel</code> and <code>sourceSchemes</code> inputs
         * will be ignored.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  > sourcePartitions;
    };

    /**
     * <code>StringBoolMapStruct</code> represent the structure of <code>StringBoolMap</code>.
     */
    struct StringBoolMapStruct
    {
        /**
         * A Map that contains option name and flag value (string/boolean).
         * <br>
         * <br>
         * Valid option names for <b>clonePartitions</b> operation are:
         * <br>
         * <code>checkOutOnCreate</code> - if true, the cloned partitions are checked-out on
         * create.
         * <br>
         * <code>includeVariantExpressions</code> - if true, the variant expressions are carried
         * forward from source partitions to target partitions.
         * <br>
         * <code>includeAttributeGroups</code> - if true, the attribute groups are carried forward
         * from source partitions to target partitions.
         * <br>
         * <br>
         * Valid option names for <b>createOrUpdateRealizedPartitions</b> operation are:
         * <br>
         * <code>includeVariantExpressions</code> - if true, the variant expressions are carried
         * forward from source partitions to target partitions.
         * <br>
         * <code>includeAttributeGroups</code> - if true, the attribute groups are carried forward
         * from source partitions to target partitions.
         * <br>
         * <code>includeChildPartitions</code> - if true, the child Partitions are carried forward
         * from source partitions to target partitions.
         * <br>
         * <code>updateRealizedPartition</code> - if true, updates the realized partitions from
         * source partitions.
         * <br>
         */
        StringBoolMap boolMap;
    };




    /**
     * This operation clones partition breakdowns (<b>Ptn0Partition</b>) from a source Application
     * Model (<b>Mdl0ApplicationModel</b>) to a target Application Model. Source Application
     * Model may be a Partition Template (<b>Ptn0PartitionTemplateModel</b>) or Collaborative
     * Design (<b>Cpd0CollaborativeDesign</b>). This operation can optionally carry forward
     * variant expressions (<b>Fnd0VariantExpression</b>), effectivity expressions (<b>Fnd0EffectivityExpression</b>)
     * and attribute groups (<b>Mdl0AttributeGroup</b>) from source partitions to target
     * partitions.
     * <br>
     * <br>
     * Partition breakdowns from a source Application Model can be used as a template to
     * create similar partition breakdowns in target Application Model. After cloning the
     * user could re-orient or modify partition breakdown in the target Application Model.
     * Cloned partitions do not maintain any references to source partitions in source Application
     * Model.
     * <br>
     * <br>
     * When partition breakdowns are cloned in to an existing scheme in target model, and
     * if there are already Partitions present in this scheme with the same Multi Field
     * Key attributes then there will be a MFK uniqueness violation error reported for that
     * duplicate Partitions, but this error is presented to the user only after saving of
     * all non-duplicate Partitions.
     * <br>
     * <br>
     * Note: <code>createOrUpdateRealizedPartitions</code> operation should be used if one
     * wants to strictly maintain the child parent hierarchy of partitions in target Application
     * Model.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Partition breakdowns from an Application Model can be used to create similar Partition
     * schemes (<b>Ptn0PartitionScheme</b>) and partition breakdowns in other Application
     * Model. This can be done by cloning partitions from selected Partition schemes of
     * different Application Models or cloning the entire partition breakdown of the given
     * source Application Model. The user may also optionally carry over the variant expressions,
     * effectivity expressions and attribute groups optionally from source Application Model
     * to target Application Model. Since the cloned partition breakdowns in target Application
     * Model do not have any reference to source Application Model, it can be modified after
     * cloning.
     * <br>
     * <br>
     * Variant Expressions are carried forward only when dictionary of options and values
     * required for the Variant Expression are available for the target Partition otherwise
     * an error message will be thrown.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        List of target Application Model, clone input options and source Application Model
     *        or source Partition schemes.
     *
     * @return
     *         List of partitions failed to clone, Partition schemes of the failed partitions, source
     *         Application Model of the failed partitions and the corresponding failure detail will
     *         be returned. Partial errors are returned in ServiceData
     *
     *
     * @exception ServiceException
     *           Following are possible errors returned in ServiceData while performing this operation.
     *           <br>
     *           <ul>
     *           <li type="disc">280011:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given Scheme type already
     *           exists with the given Partition ID in the current model. This could occur when trying
     *           to create a duplicate Partition in the same Partition.
     *           </li>
     *           <li type="disc">280006:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given type cannot be
     *           created within a Scheme of given type. This could occur when trying to create an
     *           un-allowed Partition type under a Partition scheme.
     *           </li>
     *           </ul>
     */
    virtual Ptn0::Services::Partition::_2013_05::Partitionmanagement::ClonePartitionsResponse clonePartitions ( const std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::ClonePartitionsInputInfo >& inputs ) = 0;

    /**
     * This operation realizes partition breakdowns (<b>Ptn0Partition</b>) from Partition
     * Template (<b>Ptn0PartitionTemplateModel</b>) to a target Application Model (<b>Mdl0ApplicationModel</b>)
     * and updates partition breakdowns from source Partition Templates. This operation
     * can optionally carry forward variant expressions (<b>Fnd0VariantExpression</b>),
     * effectivity expressions (<b>Fnd0EffectivityExpression</b>), attribute groups (<b>Mdl0AttributeGroup</b>)
     * and child Partitions from source Application Model to target Application Model. Realized
     * partitions in the target Application Model can be updated to reflect the changes
     * from source partitions.
     * <br>
     * <br>
     * Instantiated or realized partition breakdowns maintains reference to source partitions
     * in Partition Template. User can add a new partition to realized partition structure
     * in target application model. However, deleting an instantiated partition after realization
     * is allowed in target application model. Realization of a Partition maintains a strict
     * child parent hierarchy and will be same as that of its source Partition parent hierarchy.
     * During update of realized partitions Child-parent links are automatically established
     * in target application model wherever possible. Duplicate partitions will not be created
     * during update of realized partitions. But the partitions are updated with Variant
     * conditions and other related objects (based on Deep copy rules) from the source Partition
     * Template to the target application model.
     * <br>
     * <br>
     * Note: <code>clonePartitions</code> operation should be used if one wants to modify
     * the child parent hierarchy of partitions in target Application Model.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <br>
     * Use Case1:
     * <br>
     * Partition Templates can be used as blue print which can be reused to create partition
     * breakdowns in other Application Models (Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     * or Partition Template (<b>Ptn0PartitionTemplateModel</b>)). This enables users to
     * reuse Partition Templates and create similar Partition schemes (<b>Ptn0PartitionScheme</b>)
     * and partition breakdowns in other Application Models.  This can be done by copy/pasting
     * or drag/drop of Partitions from Partition Template to another Application Model in
     * RAC. The user may also want to optionally carry over the child Partitions, variant
     * expressions, and effectivity expressions and attribute groups.
     * <br>
     * <br>
     * Variant Expressions are carried forward only when dictionary of options and values
     * required for the Variant Expression are available for the target Partition otherwise
     * an error message will be thrown.
     * <br>
     * <br>
     * Use case2:
     * <br>
     * Once Partitions are realized from a Partition Template to other Application Model,
     * Partitions in source Partition Template may undergo changes and user may want to
     * bring these updates from Partition Template in to the target model.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        List containing target Application Model, instantiation input options, Revision Rule,
     *        Variant Rule and source Application Model or source Partition schemes or source Partitions.
     *
     * @return
     *         Partial errors are returned in ServiceData when the operation failed to update given
     *         partitions.
     *
     *
     * @exception ServiceException
     *           Following are possible errors returned in ServiceData while performing this operation.
     *           <br>
     *           <br>
     *           <ul>
     *           <li type="disc">280011:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given Partition scheme
     *           type already exists with the given Partition ID in the current model. This error
     *           could occur when trying to create a duplicate Partition under the same Partition
     *           scheme.
     *           </li>
     *           <li type="disc">280006:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given type cannot be
     *           created within a Partition scheme of given type. This could occur when trying to
     *           create an un-allowed Partition type under a Partition scheme.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateRealizedPartitions ( const std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::CreateOrUpdateRealizedPartitionsInputInfo >& inputs ) = 0;


protected:
    virtual ~Partitionmanagement() {}
};
            }
        }
    }
}

#include <ptn0/services/partition/Partition_undef.h>
#endif

