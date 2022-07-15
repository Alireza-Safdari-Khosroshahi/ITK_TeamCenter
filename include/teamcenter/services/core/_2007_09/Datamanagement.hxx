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

#ifndef TEAMCENTER_SERVICES_CORE__2007_09_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2007_09_DATAMANAGEMENT_HXX

#include <teamcenter/services/core/_2007_06/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ImanRelation.hxx>
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
            namespace _2007_09
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct ExpandGRMRelationsData2;
    struct ExpandGRMRelationship;
    struct ExpandGRMRelationsOutput2;
    struct ExpandGRMRelationsPref2;
    struct ExpandGRMRelationsResponse2;
    struct NamedReferenceInfo;
    struct RemoveNamedReferenceFromDatasetInfo;

    /**
     * The data returned from <code>expandGRMRelationsPrimary</code> and <code>expandGRMRelationsSecondary</code>
     * operations.
     */
    struct ExpandGRMRelationsData2
    {
        /**
         * The list of relation objects for the relationships between the input object and side
         * objects.
         */
        std::vector< Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationship > relationshipObjects;
        /**
         * The input Generic Relationship Manager (GRM) relation type name.
         */
        std::string relationName;
    };

    /**
     * The relation information returned from <code>expandGRMRelationsPrimary</code> and
     * <code>expandGRMRelationsSecondary</code> operations.
     */
    struct ExpandGRMRelationship
    {
        /**
         * The found side object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  otherSideObject;
        /**
         * The found relation object for the side object to primary object relationship.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  relation;
    };

    /**
     * The output from <code>expandGRMRelationsPrimary</code> and <code>expandGRMRelationsSecondary</code>
     * operations.
     */
    struct ExpandGRMRelationsOutput2
    {
        /**
         * The object that was input to be expanded.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputObject;
        /**
         * The list of data for relationships between the input object and found side objects.
         */
        std::vector< Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsData2 > relationshipData;
    };

    /**
     * Preference structure for <code>expandGRMRelationsPrimary</code> and <code>expandGRMRelationsSecondary</code>.
     */
    struct ExpandGRMRelationsPref2
    {
        /**
         * Flag that if true signifies that any item revisions that are in the return data should
         * be expanded.
         */
        bool expItemRev;
        /**
         * Flag that if true signifies that the relation objects should be returned.
         */
        bool returnRelations;
        /**
         * The list of relation type and primary or secondary object type filters, depending
         * on whether <code>expandGRMRelationsForPrimary</code> or <code>expandGRMRelationsForSecondary</code>
         * is called.  This input must be specified or error 214160 will be returned.  For <code>expandGRMRelationsForPrimary</code>,
         * if all secondary objects should be returned, <code>RelationAndTypesFilter</code>
         * input parameters should be empty.  For <code>expandGRMRelationsForSecondary</code>,
         * if all primary objects should be returned, <code>RelationAndTypesFilter</code> input
         * parameters should be empty.
         */
        std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::RelationAndTypesFilter > info;
    };

    /**
     * The response from <code>expandGRMRelationsPrimary</code> and <code>expandGRMRelationsSecondary</code>
     * operations.
     */
    struct ExpandGRMRelationsResponse2
    {
        /**
         * The list of input objects and the found related side objects.
         */
        std::vector< Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsOutput2 > output;
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData</code>
         * with the input object, any found side object and any found relation object.  All
         * objects are added as plain objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for NamedReference to be removed.
     */
    struct NamedReferenceInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * Remove all <code>NamedReference</code> of this type ( required )
         */
        std::string type;
        /**
         * Target object of a specific <code>NamedReference</code> to remove ( optional, must
         * match type above ) ) If specified then only this specific <code>NamedReference</code>
         * will be removed; other <code>NamedReferences</code> of the same type will not be
         * effected.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * Flag to indicate if <code>targetObject</code> is to be deleted
         */
        bool deleteTarget;
    };

    /**
     * Input structure for the <code>removeNamedReferenceFromDataset</code> operation
     */
    struct RemoveNamedReferenceFromDatasetInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * The dataset object from which to remove the specified named references.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * A list of named reference information.
         */
        std::vector< Teamcenter::Services::Core::_2007_09::Datamanagement::NamedReferenceInfo > nrInfo;
    };




    /**
     * Load business objects into the client data model for each of the UIDs supplied. The
     * business objects are loaded from the Teamcenter server's in memory cache of business
     * objects or from the database. UIDs of runtime business objects (<b>BOMLines</b>)
     * that are not currently loaded in the Teamcenter server's memory will result in a
     * partial error being returned.
     *
     * @param uids
     *        An array of UIDs. These UID may come from an outside source or from other service
     *        operations such as executeSavedQuery.
     *
     * @return
     *         The objecs will be returned in the 'plain' slot of the ServiceData with partial errors
     *         for any UID that is not valid or references an object the user does not have asscess
     *         to.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData loadObjects ( const std::vector< std::string >& uids ) = 0;

    /**
     * This operation removes the specified named references from a dataset.
     * <br>
     * <br>
     * If the <code>NamedReferenceInfo.targetObject</code> input is not specified then all
     * named references of the type specified are removed from the dataset.  If the <code>NamedReferenceInfo.targetObject</code>
     * input is specified then only that named reference is removed from the dataset.  If
     * the <code>NamedReferenceInfo.deleteTarget</code> input is true then the <code>NamedReferenceInfo.targetObject</code>
     * will be deleted if it is no longer referenced.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User deletes a single named reference from a dataset that has multiple named references
     * of the same type.
     * <br>
     * <br>
     * For this operation, the dataset is passed in along with the named reference type
     * and object reference for the specific named reference to be removed from the dataset.
     * The specific named reference is removed from the dataset and the dataset is added
     * to the <code>ServiceData</code> list of updated objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param inputs
     *        A list of datasets and the named references to be removed from the datasets.
     *
     * @return
     *         <code>ServiceData</code>&nbsp;&nbsp;&nbsp;&nbsp;   Datasets that were successfully
     *         modified will be returned in <code>ServiceData</code> updated objects.  If a target
     *         object is deleted, the target object UID is added to <code>ServiceData</code> deleted
     *         objects.  Error messages for problems are returned in the <code>ServiceData</code>
     *         partial errors.
     *         <br>
     *         <br>
     *         The following warning originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214125: Nothing matching the specified input was found to delete.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeNamedReferenceFromDataset ( const std::vector< Teamcenter::Services::Core::_2007_09::Datamanagement::RemoveNamedReferenceFromDatasetInfo >& inputs ) = 0;

    /**
     * This operation returns the secondary objects that are related to the input primary
     * objects.  Relation type names and secondary object types can be input as a filter
     * to reduce the set of returned secondary objects.  In the context of expanding primary
     * objects, secondary objects may be referred to as side objects. If no relation type
     * names or secondary object types are input, then all related objects will be returned.
     * <br>
     * <br>
     * For improved performance, if an item is the output of the expansion, then its associated
     * item revisions and the datasets for those item revisions will be returned.  Similarly,
     * if an item revision is the output of the expansion, then its associated datasets
     * will be returned.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to see all the secondary objects related to the input primary item object.
     * <br>
     * <br>
     * For this operation, the item object is input in <code>primaryObjects</code> and the
     * filter preference <code>info</code> <code>relationTypeName</code> and <code>otherSideObjectTypes</code>
     * parameters are set to be empty.  All secondary objects that have a relation to the
     * item are returned in <code>ExpandGRMRelationsOutput2</code>  <code>relationshipData</code>.
     * The primary object, secondary objects and relation objects are returned as plain
     * objects in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param primaryObjects
     *        The list of Teamcenter primary objects.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         Secondary objects related to each input primary object identified after filtering.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">7007: The specified primary object is invalid.
     *         </li>
     *         <li type="disc">214160: The input preference filter is null.
     *         </li>
     *         <li type="disc">214231: The input object is not a valid Teamcenter object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsResponse2 expandGRMRelationsForPrimary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& primaryObjects,
        const Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsPref2&  pref ) = 0;

    /**
     * This operation returns the primary objects that are related to the input secondary
     * objects.  Relation type names and secondary object types can be input as a filter
     * to reduce the set of returned primary objects.  In the context of expanding secondary
     * objects, primary objects may be referred to as side objects.  If no relation type
     * names or secondary object types are input, then all related objects will be returned.
     * <br>
     * <br>
     * For improved performance, if an item is the output of the expansion, then its associated
     * item revisions and the datasets for those item revisions will be returned.  Similarly,
     * if an item revision is the output of the expansion, then its associated datasets
     * will be returned.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to see all the primary objects related to the input secondary dataset
     * object.
     * <br>
     * <br>
     * For this operation, the dataset object is input in <code>secondaryObjects</code>
     * and the filter preference info <code>relationTypeName</code> and <code>otherSideObjectTypes</code>
     * parameters are set to be empty.  All primary objects that have a relation to the
     * dataset are returned in <code>ExpandGRMRelationsOutput2</code>  <code>relationshipData</code>.
     * The secondary object, primary objects and relation objects are returned as plain
     * objects in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param secondaryObjects
     *        The list of Teamcenter secondary objects.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         Primary objects related to each input secondary object identified after filtering.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">7007: The specified secondary object is invalid.
     *         </li>
     *         <li type="disc">214160: The input preference filter is null.
     *         </li>
     *         <li type="disc">214231: The input object is not a valid Teamcenter object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsResponse2 expandGRMRelationsForSecondary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& secondaryObjects,
        const Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsPref2&  pref ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

