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

#ifndef TEAMCENTER_SERVICES_CORE__2007_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2007_06_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/DatasetType.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2007_06
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct AvailableTypeInfo;
    struct BaseClassInput;
    struct DatasetTypeInfo;
    struct DatasetTypeInfoResponse;
    struct ExpandGRMRelationsData;
    struct ExpandGRMRelationsOutput;
    struct ExpandGRMRelationsPref;
    struct ExpandGRMRelationsResponse;
    struct GetAvailableTypesResponse;
    struct PurgeSequencesInfo;
    struct ReferenceInfo;
    struct RelationAndTypesFilter;
    struct RelationAndTypesFilter2;
    struct SetOrRemoveImmunityInfo;
    struct ValidateIdsInfo;
    struct ValidateIdsOutput;
    struct ValidateItemIdsAndRevIdsResponse;
    struct WhereReferencedByRelationNameInfo;
    struct WhereReferencedByRelationNameOutput;
    struct WhereReferencedByRelationNameOutputInfo;
    struct WhereReferencedByRelationNameResponse;

    /**
     * A map of enum of the status for validating ids.
     */
    enum ValidateIdsStatus{ Valid,
                 Invalid,
                 Modified,
                 Override,
                 Duplicate
                 };

    /**
     * ClassToTypesMap
     */
    typedef std::map< std::string, std::vector< AvailableTypeInfo > > ClassToTypesMap;

    /**
     * This structure represents string  instance of type and its hierarchy.
     */
    struct AvailableTypeInfo
    {
        /**
         * The name of instance type
         */
        std::string type;
        /**
         * hierarchies
         */
        std::vector< std::string > hierarchies;
    };

    /**
     * The <b>baseClassInput</b> structure represents input data structure to get available
     * Business Objects.
     */
    struct BaseClassInput
    {
        /**
         * This is the name of the Business Object for which this operation returns the descendant
         * Business Objects.
         */
        std::string baseClass;
        /**
         * Names of Business Objects (and its secondary Business Objects) to be excluded from
         * returned list.
         */
        std::vector< std::string > exclusionTypes;
    };

    /**
     * This structure contains the <b>Dataset</b> type object reference corresponding to
     * the input <b>Dataset</b> type name and the reference information for each valid named
     * reference of the <b>Dataset</b> type.
     */
    struct DatasetTypeInfo
    {
        /**
         * <b>Dataset</b> type reference object for the <b>Dataset</b> type
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::DatasetType>  tag;
        /**
         * List of valid references for the <b>Dataset</b> type
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::ReferenceInfo > refInfos;
    };

    /**
     * The response from <code>getDatasetTypeInfo</code> operation.
     */
    struct DatasetTypeInfoResponse
    {
        /**
         * List of named reference information for each dataset type specified in <code>datasetTypeNames</code>
         * input.
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::DatasetTypeInfo > infos;
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData
         * </code>plain objects with the dataset type object that corresponds to the input dataset
         * type name.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for <code>ExpandGRMRelationsData</code>.
     */
    struct ExpandGRMRelationsData
    {
        /**
         * Objects on the other side of the relationship
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > otherSideObjects;
        /**
         * Input GRM relation name
         */
        std::string relationName;
    };

    /**
     * This structure contains information for Expand GRM Relations Output.
     */
    struct ExpandGRMRelationsOutput
    {
        /**
         * Object that was expanded
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputObject;
        /**
         * List of <code>ExpandGRMRelationsData</code>
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsData > otherSideObjData;
    };

    /**
     * Expand GRM Relations Pref
     */
    struct ExpandGRMRelationsPref
    {
        /**
         * Flag to expand any Item Revisions that are in the return data
         */
        bool expItemRev;
        /**
         * List of RelationAndTypesFilter2
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::RelationAndTypesFilter2 > info;
    };

    /**
     * Expand GRM Relations Response
     */
    struct ExpandGRMRelationsResponse
    {
        /**
         * List of SaveQueryCriteriaInfo
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsOutput > output;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The GetAvailableTypesResponse struct resprents return repsonse of all types implemented
     * by the given class.
     */
    struct GetAvailableTypesResponse
    {
        /**
         * A map of given class names and all according AvailableTypeInfo objects.
         */
        ClassToTypesMap inputClassToTypes;
        /**
         * ServiceData contains any parital error if any failure happens.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The data structure represents all of the data necessary to purge sequences. The structure
     * contains the selected object and a flag indicating whether to validate that the selected
     * sequences is the active sequence.
     */
    struct PurgeSequencesInfo
    {
        /**
         * A flag indicating if <code>inputObject</code> should be validated that it is the
         * latest sequence of the <b>ItemRevision</b>. To purge all previous sequences, set
         * <code>validateLatestFlag</code> true and set <code>inputObject</code> to the latest
         * sequence of the <b>ItemRevision</b>.  To purge a specific sequence, set <code>validateLatestFlag</code>
         * false and set <code>inputObject</code> to the specific sequence of the <b>ItemRevision</b>
         * that should be purged.
         */
        bool validateLatestFlag;
        /**
         * A business object representing the <b>ItemRevision</b> sequence that should be purged.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  inputObject;
    };

    /**
     * This structure contains information for a given <b>Dataset</b> type.
     */
    struct ReferenceInfo
    {
        /**
         * Reference name for the input <b>Dataset</b> type
         */
        std::string referenceName;
        /**
         * Flag that signifies the reference is an object if the value is true.  False signifies
         * the reference is a file.
         */
        bool isObject;
        /**
         * The format for reference object.  Valid values are either <i>TEXT</i>, <i>BINARY</i>
         * or <i>OBJECT</i>.
         */
        std::string fileFormat;
        /**
         * The default extension for a file, such as <i>*.gif</i> or <i>*.doc</i>.
         */
        std::string fileExtension;
    };

    /**
     * This structure contains the relation name to traverse for the given operation and
     * a list of other side object types that are valid to return.
     */
    struct RelationAndTypesFilter
    {
        /**
         * Name of relation to traverse
         */
        std::string relationTypeName;
        /**
         * List of names of valid other side object types to return
         */
        std::vector< std::string > otherSideObjectTypes;
    };

    /**
     * This structure contains the relation name to traverse for the given operation and
     * a list of other side object types that are valid to return.
     */
    struct RelationAndTypesFilter2
    {
        /**
         * Types of relationships allowed
         */
        std::string relationName;
        /**
         * Types of other objects allowed
         */
        std::vector< std::string > objectTypeNames;
    };

    /**
     * The data structure represents all of the data necessary to toggle the immunity of
     * an <b>ItemRevision</b> sequence. It contains a reference to the <b>ItemRevision</b>
     * sequence whose immunity will be is modified and a flag indicating whether immunity
     * will be revoked or applied.
     */
    struct SetOrRemoveImmunityInfo
    {
        /**
         * Flag indicating if immunity should be set or removed on the <code>inpoutObject</code>.
         * To set immunity, the <code>setOrRemoveImmunityFlag</code> should be true.  To remove
         * immunity, the<code> setOrRemoveImmunityFlag</code> should be false.
         */
        bool setOrRemoveFlag;
        /**
         * <b>ItemRevision</b> sequence object which should be made immune or have immunity
         * removed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  inputObject;
    };

    /**
     * The <code>ValidateIdsInfo</code> struct contains the input ids for item and revision
     * and the item type.
     */
    struct ValidateIdsInfo
    {
        /**
         * Item ID to be validated
         */
        std::string itemId;
        /**
         * Revision ID to be validated
         */
        std::string revId;
        /**
         * <b>Item</b> type to validate against, can be null
         */
        std::string itemType;
    };

    /**
     * This structure contains the modified item and revision ids and enum status of the
     * ids respectively.  Valid values for the enums are Valid (ids are valid), Invalid
     * (ids are not valid), Modified (ids are not ideal but can be used if the user really
     * wants them), Override (ids are not valid, silently replace with modified ones), and
     * Duplicate (ids are already allocated in the system).
     */
    struct ValidateIdsOutput
    {
        /**
         * Modified item id if specified by Naming Rules
         */
        std::string modItemId;
        /**
         * Status of the item id represented as a <code>ValidateIdsStatus</code> enum
         */
        ValidateIdsStatus itemIdStatus;
        /**
         * Modified rev id if specified by Naming Rules
         */
        std::string modRevId;
        /**
         * Status of the revision id represented as a <code>ValidateIdsStatus</code> enum
         */
        ValidateIdsStatus revIdStatus;
    };

    /**
     * The list of <code>ValidateIdsOutput</code> structures and the <code>ServiceData</code>.
     */
    struct ValidateItemIdsAndRevIdsResponse
    {
        /**
         * List of <code>ValidateIdsOutput</code> structures
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::ValidateIdsOutput > output;
        /**
         * ServiceData contains only error information returned by this operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The data structure contains the object to perform the where referenced operation
     * on and the filters to narrow the list of referencing objects returned.
     */
    struct WhereReferencedByRelationNameInfo
    {
        /**
         * Desired business object to find referencing objects of
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of filters to limit the search of referencing objects
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::RelationAndTypesFilter > filter;
    };

    /**
     * This structure contains the object that the where referenced operation was performed
     * on and list of <code>WhereReferencedRelationNameOutputInfo</code> structures.
     */
    struct WhereReferencedByRelationNameOutput
    {
        /**
         * Input object for which referencers were found
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputObject;
        /**
         * List of <code>WhereReferencedByRelationNameOutputInfo</code> structures
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::WhereReferencedByRelationNameOutputInfo > info;
    };

    /**
     * This structure contains the referencer object, the corresponding relation name, and
     * the level at which the referencer was found.
     */
    struct WhereReferencedByRelationNameOutputInfo
    {
        /**
         * Referencer object of the input object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  referencer;
        /**
         * Relation type name of how referencer is related to input object
         */
        std::string relationTypeName;
        /**
         * Integer value for the level depth where referencer found
         */
        int level;
    };

    /**
     * The data structure contains the list of the referencing objects that meet the filter
     * criteria for each of the input objects.
     */
    struct WhereReferencedByRelationNameResponse
    {
        /**
         * A list of filtered referencing objects for each input object
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::WhereReferencedByRelationNameOutput > output;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Returns the secondary objects related to the input object for the given list of properties
     * / relations and other side object types.  If no properties/relations or other side
     * objects types are input, then all related objects will be returned.  In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned.  Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned.
     *
     * @param primaryObjects
     *        A Vector of Teamcenter primary objects
     *
     * @param pref
     *        Expand GRM Relations Preference
     *
     * @return
     *         Secondary objects related to the primary objects identified after filtering and ServiceData
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsResponse expandGRMRelationsForPrimary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& primaryObjects,
        const Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsPref&  pref ) = 0;

    /**
     * This will return type names implemented by the given classes. This is lightweight
     * way to get all displayable types by name rather than model object.
     *
     * @param classes
     *        A list of given base class name and exclusion list.
     *
     * @return
     *         A map of given base class name and its available instance types. Failure will be
     *         returned with error messages in service data.
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::GetAvailableTypesResponse getAvailableTypes ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::BaseClassInput >& classes ) = 0;

    /**
     * Given a list of <b>ItemRevision</b> sequences, this opertion is used ot perform per
     * the following criteria:
     * <br>
     * <ul>
     * <li type="disc">If the input object is the latest sequence of an <b>ItemRevision</b>,
     * all previous sequences will be purged.
     * </li>
     * <li type="disc">If the input object is not the latest sequence of the <b>ItemRevision</b>
     * and the <code>validateLatestFlag</code> is false, the input object will be purged.
     * </li>
     * <li type="disc">If the input object is not the latest sequence of the <b>ItemRevision</b>
     * and the <code>validateLatestFlag</code> is true, the <code>ServiceData</code> will
     * be updated with an error.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param objects
     *        A list of the objects to be purged and a flag noting whether to validate the object
     *        is the latest sequence.
     *
     * @return
     *         This operation returns <code>ServiceData</code> containing successfully purged sequences
     *         in the <code>Delete</code> list and partial errors for any sequences which could
     *         not be purged. The following partial error may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">214110: The input object is not valid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData purgeSequences ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::PurgeSequencesInfo >& objects ) = 0;

    /**
     * This operation is used to add or remove immunity for each object in the input list
     * according to the value of the associated <code>setOrRemoveFlag</code>.  A value of
     * true indicates to apply immunity to the object.  A value of false indicates that
     * immunity should be removed from the object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param objects
     *        A list of the <b>ItemRevision</b> sequence objects and a flag set true or false.
     *
     * @return
     *         Any errors that occur will be returned as a partial error with the source business
     *         object attached to the partial error. The following partial error may be returned:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214110: The input object is not valid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setOrRemoveImmunity ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::SetOrRemoveImmunityInfo >& objects ) = 0;

    /**
     * This operation returns the named reference information for a set of dataset types.
     * Named references are Teamcenter objects that relate to a specific data file.
     * <br>
     * <br>
     * Any failure that occurs during this operation is returned in the <code>ServiceData</code>
     * list of partial errors with the dataset type name string mapped to error message.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to see which file type is allowed for attaching to a dataset.
     * <br>
     * <br>
     * For this operation, the dataset type name is passed in the <code>datasetTypeNames</code>
     * input and the named reference information is returned.  The file extension, <code>fileExtension</code>,
     * is returned in <code>ReferenceInfo</code> and can be used to determine the supported
     * file type for the dataset.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Types - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Types
     * framework.
     *
     * @param datasetTypeNames
     *        List of dataset type names used to get the named reference information. An empty
     *        list will return information for all dataset types defined in Teamcenter.
     *
     * @return
     *         Named reference information for each input dataset type name.
     *         <br>
     *         <br>
     *         The following error originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214135: The input dataset type does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::DatasetTypeInfoResponse getDatasetTypeInfo ( const std::vector< std::string >& datasetTypeNames ) = 0;

    /**
     * Validates the item ID and revision ID based on the naming rules and user exit callbacks.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param infos
     *        A List of item IDs, revision IDs, and item type for validation.
     *        <br>
     *
     * @return
     *         - the response object containts a list of ValidateIdsOutput and ServiceData. The
     *         ValidateIdsOutput contains validation statuses for Item Id and Revision Id. If the
     *         Ids are modified because of the Naming Rules, then the modified Item Id and Revision
     *         Id are returned. Any failure is returned in the ServiceData list of partial errors
     *         with index of ValidateIdsInfo mapped to error message.
     *
     * @deprecated
     *         As of Teamcenter 10.1, use the validateValues operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, use the validateValues operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::ValidateItemIdsAndRevIdsResponse validateItemIdsAndRevIds ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::ValidateIdsInfo >& infos ) = 0;

    /**
     * Returns the primary objects related to the input object for the given list of properties
     * / relations and other side object types.  If no properties/relations or other side
     * objects types are input, then all related objects will be returned.  In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned.  Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param secondaryObjects
     *        A Vector of Teamcenter secondary objects
     *
     * @param pref
     *        Expand GRM Relations Preference
     *
     * @return
     *         Primary objects related to the primary objects identified after filtering and ServiceData
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsResponse expandGRMRelationsForSecondary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& secondaryObjects,
        const Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsPref&  pref ) = 0;

    /**
     * Finds the objects that reference a given object by specific relation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1: Use this operation to find the objects referencing the input object by
     * a specific relation.
     * <br>
     * Use case 2: Use this operation to find objects of a specific type that reference
     * the input object by a specific relation.
     * <br>
     * Use case 3: Use this operation to find objects of a specific type referencing the
     * input object.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param inputs
     *        A list of desired business objects and filters to find the referencing objects for
     *
     * @param numLevels
     *        The number of levels to search.  For example, if A references B, and B references
     *        C, a 1-level search from C produces just B, but a 2-level search produces both A
     *        and B. If -1, all levels are returned.
     *
     * @return
     *         The list of requested objects and the objects that reference them. The following
     *         partial errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">214110: The input object is not valid.
     *         </li>
     *         <li type="disc">214160: The input preference filter is NULL.
     *         </li>
     *         <li type="disc">214120: The input preference filter contains an empty or an invalid
     *         relation type name.
     *         </li>
     *         <li type="disc">214116: The input relation type name is not a valid relation type
     *         name.
     *         </li>
     *         <li type="disc">214117: No referencer matches the input relation type name.
     *         </li>
     *         <li type="disc">214119: No referencer matches the input other side object type name.
     *         </li>
     *         <li type="disc">214118: No referencer can be found for the given object.
     *         </li>
     *         <li type="disc">214111: Where Referenced operation failed.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::WhereReferencedByRelationNameResponse whereReferencedByRelationName ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::WhereReferencedByRelationNameInfo >& inputs,
        int numLevels ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

