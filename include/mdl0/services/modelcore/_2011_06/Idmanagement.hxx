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

#ifndef MDL0_SERVICES_MODELCORE__2011_06_IDMANAGEMENT_HXX
#define MDL0_SERVICES_MODELCORE__2011_06_IDMANAGEMENT_HXX

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
                class Idmanagement;

class MDL0SOAMODELCORESTRONGMNGD_API Idmanagement
{
public:

    struct InputData;
    struct AssignInput;
    struct AssignResponse;

    /**
     * Types of operation for which the values are being assigned.
     */
    enum OperationType{ CreateOperation,
                 SaveAsOperation,
                 ReviseOperation
                 };

    /**
     * Generic map of string to bool.
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * Generic map of string to bool vector.
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * Generic map of string to date.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * Generic map of string to date vector.
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * Generic map of string to double.
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * Generic map of string to double vector.
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * Generic map of string to float.
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * Generic map of string to float vector.
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * Generic Map of InputData
     */
    typedef std::map< std::string, std::vector< InputData > > InputDataMap;

    /**
     * Generic map of string to int.
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * Generic map of string to int vector.
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * Generic map of string to string.
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * Generic map of string to string vector.
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * Generic map of string to tag.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * Generic map of string to tag vector
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * A generic structure for holding operation input data for which values will be auto
     * assigned
     */
    struct InputData
    {
        /**
         * Client ID to uniquely identify this data; also used in error reporting.
         */
        std::string clientID;
        /**
         * Business object that will be used as original object for revise and copy operations;
         * set to NULLTAG if object is being created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bo;
        /**
         * Business Object name; required when operation input is create, must be empty otherwise.
         */
        std::string boType;
        /**
         * Map containing string property name value pairs<string,string>
         */
        StringMap stringProps;
        /**
         * Map containing string array property name value pairs<string,vector<string>>
         */
        StringVectorMap stringArrayProps;
        /**
         * Map containing double property name value pairs<string,double>
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
         * Map containing tag property name value pairs<string,BusinessObject>
         */
        TagMap tagProps;
        /**
         * Map containing tag array property name value pairs<string,vector<BusinessObject>>
         */
        TagVectorMap tagArrayProps;
        /**
         * A map of compound input data, for operations and object types that support compound
         * objects.  Key value is property name, value is a list of <code>InputData</code> for
         * the compound objects
         */
        InputDataMap compoundInputData;
        /**
         * A map of auto assignable properties that were assigned for the object. The key is
         * the property name, and the value is a boolean flag which indicates if the assigned
         * value can be further modified by the client application.
         */
        BoolMap modifiableAssignedValues;
    };

    /**
     * Inputs required for auto generating attribute values for a workspace object.
     */
    struct AssignInput
    {
        /**
         * Property name value pairs from the objects operation descriptor.  Assignable properties
         * having no input value will be assigned a value in the response.
         */
        Mdl0::Services::Modelcore::_2011_06::Idmanagement::InputData data;
        OperationType operation;
    };

    /**
     * <code>AssignResponse</code> contains the input data with auto generated attribute
     * values filled in.
     */
    struct AssignResponse
    {
        /**
         * The list of input data with key values auto assigned
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Idmanagement::InputData > output;
        /**
         * Contains error information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Auto generates the values of the auto assignable  properties in bulk. The input parameters
     * expected on the input, include the business object or the business object name.
     * For cases where the assignment is based on other properties, those values must be
     * supplied on input; this includes any reference objects.  The output includes the
     * generated values as well as other properties defined in the input.
     * <br>
     * <br>
     * Support is currently limited to the following Collaborative Product Development (CPD)
     * specific classes:
     * <br>
     * <b>&nbsp;&nbsp;&nbsp;&nbsp;Mdl0ApplicationModel (</b><code>mdl0model_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Ptn0Partition (</b><code>ptn0partition_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Cpd0DesignElement (</b><code>cpd0design_element_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Cpd0DesignFeature (</b><code>cpd0design_feature_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Cpd0DesignControlElement (c</b><code>pd0design_control_element_id</code><b>)
     * <br>
     * </b>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the authoring use case for model content.It is used to fill in
     * autoassignable property values. Applications may choose to allow a user to enter
     * a value or assign one.
     * <br>
     * Use Case 1: <b>Assign ID during Create </b>
     * <br>
     * During creation of a new object, the user requests the system to assign a value
     * <br>
     * <ul>
     * <li type="disc">Application constructs <code>AssignInput</code> and specifies the
     * business object type (boType) of the object being created and an operationType: <code>CreateOperation</code>.
     * A client ID (unique for the call) is also specified on the <code>AssignInput</code>
     * for error reporting.
     * </li>
     * <li type="disc">Generate new ID values for the object using the <code>autoAssignValues</code>
     * operation.
     * </li>
     * <li type="disc">Post process the new ID value (e.g. display it back to the user).
     * </li>
     * </ul>
     * <br>
     * Use Case 2:<b> Assign ID during Revise </b>
     * <br>
     * During revise of an existing object, the user requests the system to assign an ID
     * value to the new revision.
     * <br>
     * <ul>
     * <li type="disc">Application constructs AssignInput and specifies the business object
     * (bo) of the object being revised and an operationType: <code>ReviseOperation</code>.
     * A client ID (unique for the call) can be optionally specified on the <code>AssignInput</code>.
     * </li>
     * <li type="disc">Generate ID value for new revision using the <code>autoAssignValues</code>
     * operation.
     * </li>
     * <li type="disc">Post process the ID value (e.g. display it back to the user).
     * </li>
     * </ul>
     * <br>
     * Use Case 3: <b>Assign ID during SaveAs </b>
     * <br>
     * During saveas (copy) of an existing object, the user requests the system to assign
     * an ID value to the new object.
     * <br>
     * <ul>
     * <li type="disc">Application constructs <code>AssignInput</code> and specifies the
     * business object (bo) of the object being revised and an operationType: <code>SaveAsOperation</code>.A
     * client ID (unique for the call) can be optionally specified on the <code>AssignInput</code>.
     * </li>
     * <li type="disc">Generate ID value for new revision using the <code>autoAssignValues</code>
     * operation.
     * </li>
     * <li type="disc">Post process the ID value (e.g. display it back to the user).
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param input
     *        A list of <code>AssignInput</code> for which property values should be autoassigned.
     *
     * @return
     *         The the input data with autoassigned values filled in.The errors if any are returned
     *         in the service data.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Idmanagement::AssignResponse autoAssignValues ( const std::vector< Mdl0::Services::Modelcore::_2011_06::Idmanagement::AssignInput >& input ) = 0;


protected:
    virtual ~Idmanagement() {}
};
            }
        }
    }
}

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

