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

#ifndef MDL0_SERVICES_MODELCORE__2011_06_DATAMANAGEMENT_HXX
#define MDL0_SERVICES_MODELCORE__2011_06_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ListOfValues.hxx>
#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            namespace _2011_06
            {
                class Datamanagement;

class MDL0SOAMODELCORESTRONGMNGD_API Datamanagement
{
public:

    struct SaveAsInput;
    struct DeepCopyData;
    struct DeleteModelContentResponse;
    struct PropDesc;
    struct PropDescSaveAs;
    struct SaveAsDesc;
    struct SaveAsDescResponse;
    struct SaveAsIn;
    struct SaveAsObjectsResponse;
    struct SaveAsOut;
    struct SaveAsTree;

    /**
     * Enumeration of the different property types for which DeepCopy Rule  configuration
     * is enabled
     */
    enum PropertyType{ Relation,
                 Reference
                 };

    /**
     * BoolMap
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * BoolVectorMap
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * DateMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * DateVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * Map containing deep copy information for a Business Object
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< DeepCopyData > > DeepCopyInfoMap;

    /**
     * DoubleMap
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * DoubleVectorMap
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * FloatMap
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * FloatVectorMap
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * IntMap
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * IntVectorMap
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * Map for SaveAsDescriptor
     */
    typedef std::map< std::string, SaveAsDesc > SaveAsDescMap;

    /**
     * String Map
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * StringVectorMap
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * TagMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * TagVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * Input properties for new revision
     */
    struct SaveAsInput
    {
        /**
         * Business object name
         */
        std::string boName;
        /**
         * Map containing string property value pairs<string,string>
         */
        StringMap stringProps;
        /**
         * Map containing string array property name value pairs<string,vector<string>>
         */
        StringVectorMap stringArrayProps;
        /**
         * Map containing double property name value pairs<string,vector<float>>
         */
        DoubleMap doubleProps;
        /**
         * Map containing double array property name value pairs<string,vector<double>>
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map containing float property name value pairs<string,float>
         */
        FloatMap floatProps;
        /**
         * Map containing float array property name value pairs<string,vector<float>>
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map containing int property name value pairs<string,int>
         */
        IntMap intProps;
        /**
         * Map containing int array property name value pairs<string,vector<int>>
         */
        IntVectorMap intArrayProps;
        /**
         * Map containing bool property name value pairs<string,bool>
         */
        BoolMap boolProps;
        /**
         * Map containing bool array property name value pairs<string,vector<bool>>
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map containing date property name value pairs<string,DateTime>
         */
        DateMap dateProps;
        /**
         * Map containing date array property name value pairs<string,vector<DateTime>>
         */
        DateVectorMap dateArrayProps;
        /**
         * Map containing tag business object property name value pairs<string,BusinessObject>
         */
        TagMap tagProps;
        /**
         * Map containing tag array property name value pairs<string,vector<BusinessObject>>
         */
        TagVectorMap tagArrayProps;
    };

    /**
     * <code>DeepCopyData</code> describes information regarding related objects to be copied
     * or referenced during a revise operation.This structure is the same as that used for
     * save as operations.
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
         * Indicates if property represents a reference or a relation; valid values are:
         * <br>
         * <ul>
         * <li type="disc"><i>Relation</i>
         * </li>
         * <li type="disc"><i>Reference</i>
         * </li>
         * </ul>
         */
        PropertyType propertyType;
        /**
         * The type of deep copy action to be performed; These are the valid values:
         * <br>
         * <ul>
         * <li type="disc"><i>NoCopy</i>
         * </li>
         * <li type="disc"><i>copyAsReference</i>
         * </li>
         * <li type="disc"><i>CopyAsObject</i>
         * </li>
         * </ul>
         */
        std::string copyAction;
        /**
         * Flag indicating if target object is primary or secondary
         */
        bool isTargetPrimary;
        /**
         * If this flag is false, the copy action can be changed by the user.
         */
        bool isRequired;
        /**
         * Captures user inputs for copied properties on revised and deep copied objects
         */
        Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsInput saveAsInput;
        /**
         * Vector of <b>DeepCopyData</b> for secondary objects on the other side of the reference
         * or relation.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::DeepCopyData > childDeepCopyData;
        /**
         * Flag to specify whether or not  relation properties should be copied during a deep
         * copy.
         */
        bool copyRelations;
    };

    /**
     * The response <b>(</b><code>DeleteModelContentResponse</code>) contains list of any
     * input objects that could not be deleted.The service data contains any errors and
     * list of objects deleted by the operation.
     */
    struct DeleteModelContentResponse
    {
        /**
         * list of input objects that could not be deleted by the system
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  > undeletedObjects;
        /**
         * Contains error information and a list of deleted objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>PropDesc</code> describes information about a Teamcenter property.
     */
    struct PropDesc
    {
        /**
         * Name of property
         */
        std::string propName;
        /**
         * Display Name of property
         */
        std::string displayName;
        /**
         * Default value of property
         */
        std::string defaultValue;
        /**
         * Value type for property
         */
        int propValueType;
        /**
         * Type for the property
         */
        int propType;
        /**
         * Specifies if property is displayable.
         */
        bool isDisplayable;
        /**
         * Specifies whether the property is an array or single value
         */
        bool isArray;
        /**
         * Specifies the max number of elements in the array
         */
        int maxNumElems;
        /**
         * List of values (LOV) object attached to property (if any)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
        /**
         * Specifies if property is required
         */
        bool isRequired;
        /**
         * Specifies if property is enabled
         */
        bool isEnabled;
        /**
         * Specifies if property is modifiable
         */
        bool isModifiable;
        /**
         * LOV attach specifier
         */
        int attachedSpecifier;
        /**
         * Specifies maximum length of property(e.g. max string length)
         */
        int maxLength;
        /**
         * List of other property names which are interdependent with the property.
         */
        std::vector< std::string > interdependentProps;
        /**
         * Naming patterns for property, can be null
         */
        std::vector< std::string > namingPatterns;
    };

    /**
     * <code>PropDescSaveAs</code> property descriptor for save as and revise operations
     */
    struct PropDescSaveAs
    {
        /**
         * Core Property Descriptor Structure
         */
        Mdl0::Services::Modelcore::_2011_06::Datamanagement::PropDesc parent;
        /**
         * Flag indicating if value is to be copied from original object for SaveAs[true indicates
         * value is to be copied from original object]
         */
        bool copyFromOriginal;
    };

    /**
     * <code>saveAsDesc</code> is a descriptor for inputs into save as and revise operations.It
     * is a container of metadata which clients can use to generically construct SaveAs
     * dialogs for business objects
     */
    struct SaveAsDesc
    {
        /**
         * Business Object that owns the descriptor
         */
        std::string businessObjectName;
        /**
         * Property Descriptors for SaveAs
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::PropDescSaveAs > propDescs;
    };

    /**
     * <code>SaveAsDescResponse</code> is used to return data from the <code>getReviseDesc</code>
     * operation.  It contains descriptors and deep copy information needed to perform the
     * <code>reviseObjects</code> operation.
     */
    struct SaveAsDescResponse
    {
        /**
         * Map of business object type name to its save as descriptor (<code>SaveAsDesc</code>).
         */
        SaveAsDescMap saveAsDescMap;
        /**
         * Map of input object to a list of its <code>DeepCopyInfo</code>.
         */
        DeepCopyInfoMap deepCopyInfoMap;
        /**
         * Service data containing created objects, errors, etc.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for revise operation.  Contains a reference to an object to be revised
     * (<code>targetObject</code>), its save as input and its deep copy data.
     * <br>
     * Note:revise uses same input descriptor as save as operation
     * <br>
     * <ul>
     * <li type="disc"><code>targetObject</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * An object to be revised  must be a subtype of
     * </li>
     * </ul>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * <b> Mdl0ConditionalElement</b>.
     * <br>
     * <ul>
     * <li type="disc"><code>saveAsInput</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * User/application input property values for the revise operation.
     * </li>
     * <li type="disc"><code>deepCopyDatas</code>&nbsp;&nbsp;&nbsp;&nbsp;  Deep copy information
     * regarding other objects referenced  by or related
     * </li>
     * </ul>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * to the revised object.
     */
    struct SaveAsIn
    {
        /**
         * An object to be revised must be a subtype of <b>Mdl0ConditionalElement</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * User/application input property values for the revise operation.
         */
        Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsInput saveAsInput;
        /**
         * Deepcopy information regarding other objects referenced by or related to the revised
         * object.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::DeepCopyData > deepCopyDatas;
    };

    /**
     * Response from <code>reviseObjects</code> operation. Returns a list of the input object
     * and its new revision.
     */
    struct SaveAsObjectsResponse
    {
        /**
         * List that holds original input object and new objects.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsOut > output;
        /**
         * List that holds mapping between original objects and copied objects
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsTree > saveAsTrees;
        /**
         * Service data containing created objects and error
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Output data from <code>reviseObjects</code> operation. Contains an input object and
     * the set of new objects created when it was revised.
     */
    struct SaveAsOut
    {
        /**
         * The original object that was revised
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * A list of all new objects created in conjunction with revising <code>targetObject</code>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * <code>SaveAsTree</code> is used to capture the result tree of the deep copy process
     * carried out as part of a <code>reviseObjects</code> operation. It contains a reference
     * to an original object, a reference to the new object that resulted from copying the
     * original object and recursive child results from copying objects reached by traversing
     * relations and references recursively from the original object.
     */
    struct SaveAsTree
    {
        /**
         * Original object being saved as
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  originalObject;
        /**
         * Object copy after save as
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectCopy;
        /**
         * Nested Information for next level
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsTree > childSaveAsNodes;
    };




    /**
     * Deletes <b>Mdl0ModelElement</b> objects from an <b>Mdl0ApplicationModel.</b>This
     * operation will attempt to delete as many objects as it can and returns a list of
     * any objects that could not be deleted.Order of objects in the input list is not important.This
     * operation handles the case when one input object has a non circular reference to
     * another input object; deletion of the referenced object will occur after its referencing
     * object is deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports model element authoring use cases, specifically the bulk deletion
     * of objects within a model.
     * <br>
     * the following steps can be used for deleting model elements from a model.
     * <br>
     * <ul>
     * <li type="disc">Find through query or navigate the model elements to be deleted.
     * </li>
     * <li type="disc">Call the delete operation <code>deleteModelContent</code> to delete
     * a list of existing model elements from a model.
     * </li>
     * </ul>
     * <br>
     * Note:  <code>deleteObjects</code> operation can also be used, but requires proper
     * ordering of input   elements to handle the case when one model element in the input
     * list references another model element in the input list.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param objectsToDelete
     *        The input list of model elements to be deleted.
     *
     * @return
     *         The response (<code>DeleteModelContentResponse</code>) contains list of any input
     *         objects that could not be deleted.The service data contains any errors and list of
     *         objects deleted by the operation.
     *         <br>
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Datamanagement::DeleteModelContentResponse deleteModelContent ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  >& objectsToDelete ) = 0;

    /**
     * Gets a save as descriptor for a revise operation.Clients may use the output of this
     * call to construct generic UI dialogs to collect user input for the revise operation.This
     * operation takes in a list of objects to be revised, and returns save as descriptors
     * and deep copy for each object input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * See the <code>reviseObjects</code> operation documentation for applicable use cases.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getReviseDesc, reviseObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param targetObjects
     *        Input list of objects to be revised. It must be a subtype of <b>Mdl0ConditionalElement</b>
     *
     * @return
     *         The response contains a map of business object types to their save as descriptor
     *         (used for revise operations as well), and a map of the deep copy data for each of
     *         input objects.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsDescResponse getReviseDesc ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& targetObjects ) = 0;

    /**
     * Revises a set of input objects and performs a deep copy of related objects.New objects
     * are saved in the Teamcenter database and returned in the response.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the authoring use case where an object or a set of objects requires
     * a new revision. Objects which are a subtype of <b>Mdl0ConditionalElement</b> support
     * the concept of revise.   The elements are first created by a user, undergo edits,
     * and then are approved through a workflow and given status. At this point, a new revision
     * of the object must be created to further modify it.
     * <br>
     * The <code>reviseObjects</code>  operation is used to create the new revision.  Deep
     * copy rules, defined in BMIDE and deployed to Teamcenter, control the sub object copy
     * process during the revise operation.  The operation <code>getReviseDesc</code> is
     * called prior to calling <code>reviseObjects</code> to construct the deep copy information
     * and descriptors for the objects to be revised.
     * <br>
     * Use Case :<b> Revise a conditional element  </b>
     * <br>
     * The following assumes an initial revision has been created and released.
     * <br>
     * <ul>
     * <li type="disc">Construct list of existing, released objects to be revised (objects
     * must be valid subtypes of <b>Mdl0ConditionalElement</b>).
     * </li>
     * <li type="disc">Construct deep copy data and get saveAs descriptors for the input
     * set of objects by using operation <code>getReviseDesc</code>.
     * </li>
     * <li type="disc">Revise the objects in Teamcenter by using the <code>reviseObjects</code>
     * operation.
     * </li>
     * <li type="disc">Post process / display new object revisions in client
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getReviseDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param saveAsIn
     *        List of input data  containing object to be revised and its deep copy data.
     *
     * @return
     *         A list of objects that were created and saved during the revise operation. Any failure
     *         will be returned with Business object mapped to error message in the ServiceData
     *         list of partial errors.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsObjectsResponse reviseObjects ( const std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsIn >& saveAsIn ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

