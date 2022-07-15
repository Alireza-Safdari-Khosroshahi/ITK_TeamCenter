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

#ifndef TEAMCENTER_SERVICES_CORE__2011_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2011_06_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/PSBOMView.hxx>
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
            namespace _2011_06
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct SaveAsInput;
    struct DeepCopyData;
    struct ObjectInfo;
    struct Report;
    struct SaveAsIn;
    struct SaveAsObjectsResponse;
    struct SaveAsOut;
    struct SaveAsTree;
    struct TraceabilityInfoInput;
    struct TraceabilityReportOutput;
    struct TraceReport;
    struct ValidateRevIdsInfo;
    struct ValidateRevIdsOutput;
    struct ValidateRevIdsResponse;

    /**
     * Map of the enumeration of the different property types for which DeepCopy Rule configuration
     * is enabled.
     */
    enum PropertyType{ Relation,
                 Reference
                 };

    /**
     * Revision Id status enum after validation against Naming Rules/Revision Naming Rules.
     * <br>
     * Meanings of the enum values are as follows:
     * <br>
     * <ul>
     * <li type="disc">ValidRevID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision
     * Id is valid.
     * </li>
     * <li type="disc">InvalidRevID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision
     * Id is not valid. Do not allow the user to create a revision with this revision id.
     * </li>
     * <li type="disc">ModifiedRevID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision
     * Id is not valid. However, allow user to create revision with this id if they really
     * want to.
     * </li>
     * <li type="disc">OverrideRevID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision
     * Id was not valid. Use the modified versions without telling the user. (Useful for
     * case conversions)
     * </li>
     * <li type="disc">DuplicateRevID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision
     * Id is not valid, because it is already in use.
     * </li>
     * </ul>
     */
    enum ValidateRevIdsStatus{ ValidRevID,
                 InvalidRevID,
                 ModifiedRevID,
                 OverrideRevID,
                 DuplicateRevID
                 };

    /**
     * Map of bool property names to values <code>(string, bool</code>).
     */
    typedef std::map< std::string, bool > BoolMap1;

    /**
     * Map of bool array property names to values (<code>string, vector< bool ></code>).
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap1;

    /**
     * DateMap1
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap1;

    /**
     * Map of DateTime array property names to values (<code>string, vector< DateTime></code>).
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap1;

    /**
     * DoubleMap1
     */
    typedef std::map< std::string, double > DoubleMap1;

    /**
     * Map of double array property names to values (<code>string, vector< double></code>).
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap1;

    /**
     * Map of float property names to values (<code>string, float</code>).
     */
    typedef std::map< std::string, float > FloatMap1;

    /**
     * Map of float array property names to values (<code>string, vector<float></code>).
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap1;

    /**
     * Map of int property names to values (<code>string, int</code>).
     */
    typedef std::map< std::string, int > IntMap1;

    /**
     * Map of int array property names to values <b>(</b><code>string, vector< int></code>).
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap1;

    /**
     * Map of <b>BusinessObject</b> property names to values (<code>string, BusinessObject</code>).
     */
    typedef std::map< std::string, std::string > StringMap1;

    /**
     * StringVectorMap1
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap1;

    /**
     * TagMap1
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap1;

    /**
     * Map of <b>BusinessObject</b> array property names to values <code>(string, vector<
     * BusinessObject ></code>).
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap1;

    /**
     * This structure is used to capture the inputs required for savingof a business object.
     */
    struct SaveAsInput
    {
        /**
         * Business object type name
         */
        std::string boName;
        /**
         * Map of string property names to values (<code>string, string</code>)
         */
        StringMap1 stringProps;
        /**
         * Map of string array property names to values (<code>string, vector<string></code>)
         */
        StringVectorMap1 stringArrayProps;
        /**
         * Map of double property names to values (<code>string, double</code>)
         */
        DoubleMap1 doubleProps;
        /**
         * Map of double array property names to values (<code>string, vector<double></code>)
         */
        DoubleVectorMap1 doubleArrayProps;
        /**
         * Map of float property names to values <code>(string, float</code>)
         */
        FloatMap1 floatProps;
        /**
         * Map of float array property names to values (<code>string, vector<float></code>)
         */
        FloatVectorMap1 floatArrayProps;
        /**
         * Map of int property names to values (<code>string, int</code>)
         */
        IntMap1 intProps;
        /**
         * Map of int array property names to values (<code>string, vector<int></code>)
         */
        IntVectorMap1 intArrayProps;
        /**
         * Map of boolean property names to values (<code>string, bool</code>)
         */
        BoolMap1 boolProps;
        /**
         * Map of boolean array property names to values (<code>string, vector<bool></code>)
         */
        BoolVectorMap1 boolArrayProps;
        /**
         * Map of DateTime property names to values (<code>string, DateTime</code>)
         */
        DateMap1 dateProps;
        /**
         * Map of DateTime array property names to values (<code>string, vector<DateTime></code>)
         */
        DateVectorMap1 dateArrayProps;
        /**
         * Map of <b>BusinessObject</b> property names to values (<code>string, BusinessObject</code>)
         */
        TagMap1 tagProps;
        /**
         * Map of <b>BusinessObject</b> array property names to values (<code>string, vector<BusinessObject></code>)
         */
        TagVectorMap1 tagArrayProps;
    };

    /**
     * DeepCopyData definition
     */
    struct DeepCopyData
    {
        /**
         * Other side object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  attachedObject;
        /**
         * Name of relation type or reference property for which DeepCopy rule is configured
         */
        std::string propertyName;
        /**
         * enumeration value indicating if DeepCopyRule is configured for Relation or Reference
         * property
         */
        PropertyType propertyType;
        /**
         * DeepCopy action [NoCopy, CopyAsReference, CopyAsObject or Select]
         */
        std::string copyAction;
        /**
         * Flag indicating if target object is primary or secondary
         */
        bool isTargetPrimary;
        /**
         * If this flag is false, the copy action can be dynamicaly changed by user
         */
        bool isRequired;
        /**
         * This is a Boolean representing whether the Properties on the Relation if any in the
         * Relation that exists between
         */
        bool copyRelations;
        /**
         * SaveAsInput type name
         */
        std::string saveAsInputTypeName;
        /**
         * Vector of DeepCopy data for the secondary objects on the other side
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::DeepCopyData > childDeepCopyData;
        /**
         * SaveAsInput field to capture user inputs on the SaveAs dialog. NOTE: This field is
         * unused in the getSaveAsDesc operation. It is used in the saveAsObjects operation
         */
        Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsInput saveAsInput;
    };

    /**
     * This structure holds object information of parent object of trace link in Report
     * structure.
     */
    struct ObjectInfo
    {
        /**
         * This parameter will hold the name of context for source or target object of Trace
         * Link.
         */
        std::string contextName;
        /**
         * If the Trace Link is created on the occurrence then this variable will represent
         * the object to show in the Trace Report.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  displayObj;
        /**
         * This object represent any<b> Business Object</b> in Teamcenter on which Trace Link
         * is created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * This field represents the BOM View of context line for the Trace Link.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  bomView;
    };

    /**
     * This structure holds information each trace link report with information of parent
     * object, and its children associated with trace link relation.
     */
    struct Report
    {
        /**
         * Parent object of trace link.
         */
        Teamcenter::Services::Core::_2011_06::Datamanagement::ObjectInfo parent;
        /**
         * list of all child objects for the parent with trace link relation
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::ObjectInfo > children;
    };

    /**
     * <code>SaveAsI</code>n structure contains the object to be saved and the corresponding
     * <code>DeepCopyData</code> of the attached objects of the object to be saved.
     */
    struct SaveAsIn
    {
        /**
         * Target object being saved as
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * SaveAsInput (user input from SaveAs dialog) for the targetobject being saved as
         */
        Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsInput saveAsInput;
        /**
         * DeepCopyData of the objects attached to the targetobject
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::DeepCopyData > deepCopyDatas;
    };

    /**
     * This structure contains a vector corresponding to the input target objects that holds
     * mapping between the original objects and the saved objects.
     */
    struct SaveAsObjectsResponse
    {
        /**
         * SaveAsout vector
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsOut > output;
        /**
         * Vector corresponding to the input target objects that holds mapping between the original
         * objects and the copied  objects
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsTree > saveAsTrees;
        /**
         * Service data containing created objects, errors, etc
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for <code>SaveAs</code> operation including unique
     * target object.
     */
    struct SaveAsOut
    {
        /**
         * <b>BusinessObject</b> name
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * Input data for <code>SaveAs</code> Operation
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * This structure contains tree structure for <code>SaveAs</code>.
     */
    struct SaveAsTree
    {
        /**
         * Original object being saved as
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  originalObject;
        /**
         * Object copy after <code>SaveAs</code>. This could be NULL if no copy was made or
         * same as original object if the copy is a reference to the original
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectCopy;
        /**
         * Nested information for next level of the tree
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsTree > childSaveAsNodes;
    };

    /**
     * TraceabilityInfoInput structure represents parameters required for creating trace
     * report including objects for which this trace report should be generated, type of
     * trace report, if indirect trace link included, and type of base relation of trace
     * link.
     */
    struct TraceabilityInfoInput
    {
        /**
         * Vector of objects on which to generate the Trace Report
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > selectedObjs;
        /**
         * Type of Report that is defining, complying, or both.
         */
        int reportType;
        /**
         * Level to which Trace Report should be generated.
         */
        int reportDepth;
        /**
         * If this variable is true then only Indirect Trace Report will be included in the
         * final Trace Report.
         */
        bool isIndirectTraceReportNeeded;
        /**
         * The Trace Report will be generated for this type of relations, which Includes the
         * subtypes also.
         */
        std::string relationTypeName;
    };

    /**
     * TraceabilityReportOutput structure holds information about generated trace reports
     * with defining and complying trace trees with selected objects and its persistent
     * objects, including service data.
     */
    struct TraceabilityReportOutput
    {
        /**
         * This member holds all the Trace Reports user has asked for. This is vector of
         * <br>
         * TraceReport type of structures.
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::TraceReport > traceReports;
        /**
         * Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds information about generated trace reports with defining and
     * complying trace trees with selected objects, and its persistent objects.
     */
    struct TraceReport
    {
        /**
         * Represents the Defining Tree in the Trace Report giving all defining trace link details.
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::Report > definingTree;
        /**
         * Represents an Indirect Defining Tree in the Trace  Report.
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::Report > indirectDefiningTree;
        /**
         * Represents the Complying Tree in the Trace Report giving all complying trace link
         * details.
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::Report > complyingTree;
        /**
         * Represents an Indirect Complying Tree in the Trace Report
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::Report > indirectComplyingTree;
        /**
         * Represents selected object for which Trace Report generated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedObject;
        /**
         * Represents persistent object for the selected object for which Trace Report generated.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > persistentObjects;
    };

    /**
     * Input structure for <code>validateRevIds</code> operation. It contains the revision
     * id to be validated along with information about the object and object type.
     */
    struct ValidateRevIdsInfo
    {
        /**
         * Input Revision id to be validated.
         */
        std::string revId;
        /**
         * <b>Item</b> object for which revision id needs to be validated. For new a <b>Item</b>
         * to be created this property must be set to null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  itemObject;
        /**
         * String describing the type of the <b>Item</b> for which the identifier is being validated.
         */
        std::string itemType;
    };

    /**
     * This structure contains the modified revision id and enum status of the id.  Valid
     * values for the enums are Valid (ids are valid), Invalid (ids are not valid), Modified
     * (ids are not ideal but can be used if the user really wants them), Override (ids
     * are not valid, silently replace with modified ones), and Duplicate (ids are already
     * allocated in the system).
     */
    struct ValidateRevIdsOutput
    {
        /**
         * Modified rev id if specified by Naming Rules/Revision Naming Rules.
         */
        std::string modRevId;
        /**
         * Status of the revision id represented as a <code>ValidateRevIdsStatus</code> enum.
         */
        ValidateRevIdsStatus revIdStatus;
    };

    /**
     * Response structure for <code>validateRevIds</code> service operation.
     */
    struct ValidateRevIdsResponse
    {
        /**
         * List of <code>ValidateRevIdsOutput</code> structures, which contain the modified
         * revision id and the validation status of the input revision id.
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::ValidateRevIdsOutput > output;
        /**
         * Standard <code>ServiceData</code> structure. It contains partial errors and failures
         * along with the clientIds.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Validates and/or modifies the Revision Id based on the naming rules/revision naming
     * rules and user exit callbacks.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is generally used to validate revision id before providing it as input
     * for create, revise and save-as operations.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param inputs
     *        A list of <code>ValidateRevIdsInfo</code> structures, each of which contain revId/itemObject/itemType
     *        that have to be validated.
     *
     * @return
     *         The response object containts a list of <code>ValidateRevIdsOutput</code> and <code>ServiceData</code>.
     *         The <code>ValidateRevIdsOutput</code> contains validation statuses for Revision Id.
     *         If the Ids are modified because of the Naming Rules/Revision Naming Rules, then the
     *         modified Revision Ids are returned. Any failure is returned in the <code>ServiceData</code>
     *         list of partial errors with index of <code>ValidateRevIdsInfo</code> mapped to error
     *         message.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74007&nbsp;&nbsp;&nbsp;&nbsp;Supplied item_revision_id value <code>inputs[index].revId</code>
     *         is invalid.
     *         </li>
     *         <li type="disc">74026&nbsp;&nbsp;&nbsp;&nbsp;Value must be between <code>Initial
     *         value</code> and <code>Maximum value</code>.
     *         </li>
     *         <li type="disc">74028&nbsp;&nbsp;&nbsp;&nbsp;The Revision ID cannot contain the following
     *         letters: <code>List of excluded letters</code>.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         Other than this, errors thrown from any of the following Teamcenter system calls
     *         may be caught and added to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">ITEM_ask_id()
     *         </li>
     *         <li type="disc">USER_validate_item_rev_id_3()
     *         </li>
     *         <li type="disc">ITEM_find_items_by_key_attributes()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::ValidateRevIdsResponse validateRevIds ( const std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::ValidateRevIdsInfo >& inputs ) = 0;

    /**
     * This operation is generic operation for saving of Business Objects. It will also
     * save any secondary objects that also need to be saved based on deep copy rule information
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Client constructs the SaveAs dialog for a Business Object using <code>OperationDescriptor.getSaveAsDesc</code>
     * operation.  The information returned by that operation allows client to construct
     * the SaveAs dialogs and DeepCopy panels for user input. Once the user input is received,
     * client can make subsequent invocation to this (<code>DataManagement.saveAsObjects</code>)
     * operation to execute SaveAs on the object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getSaveAsDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param saveAsIn
     *        Input data containing target object and DeepCopyData of the attached objects
     *
     * @return
     *         The return contains a list of business objects representing the objects that were
     *         saved. Failure for any element in the input vector is returned as a Partial Error
     *         in the <code>ServiceData</code>. The Partial Error includes the index of the failed
     *         element from the input vector.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsObjectsResponse saveAsObjects ( const std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsIn >& saveAsIn ) = 0;

    /**
     * This operation will generate a Trace Report on the objects selected by user.  User
     * will get information about complying as well as defining objects which are connected
     * to selected object using <b> FND_TraceLink</b> or its subtype of GRM relation.
     * <br>
     * <br>
     * Trace links can be between following objects:
     * <br>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * occurrences of an <b>ItemRevision</b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * <b>ItemRevisions</b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * <b>Items</b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * any two <b>WorkspaceObject</b>.
     * <br>
     * <br>
     * If indirect trace report flag is set to <b>true</b> during this operation, then user
     * will get trace report for <b>ItemRevision</b> if selected object is <b>Occurrence</b>,
     * and trace report for Items if selected objects is <b>ItemRevision</b> in addition
     * to direct trace report for the selected object.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Suppose user created trace link between Requirement R1 as start point and R2 as end
     * point and creates trace link from Requirement R3 as start and R1 as end point.
     * <br>
     * When user runs traceability report on R1 requirement he will get R2 object as complying
     * object and R3 will come as defining object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A TraceabilityInfoInput structure to generate a Trace Report.This input structure
     *        holds selected objects for which trace report needs to be generated, trace report
     *        type, if indirect report required, and base relation type.
     *
     * @return
     *         TraceabilityReportOutput structure holds vector of trace reports which gives the
     *         trace tree of defining and complying objects, including indirect tree if isIndirectTraceReportNeeded
     *         is true, and any failure is return in service data.
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::TraceabilityReportOutput getTraceReport ( const Teamcenter::Services::Core::_2011_06::Datamanagement::TraceabilityInfoInput&  input ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

