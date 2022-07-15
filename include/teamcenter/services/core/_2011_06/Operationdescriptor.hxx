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

#ifndef TEAMCENTER_SERVICES_CORE__2011_06_OPERATIONDESCRIPTOR_HXX
#define TEAMCENTER_SERVICES_CORE__2011_06_OPERATIONDESCRIPTOR_HXX

#include <teamcenter/services/core/_2008_06/Propdescriptor.hxx>
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
                class Operationdescriptor;

class TCSOACORESTRONGMNGD_API Operationdescriptor
{
public:

    struct SaveAsInput;
    struct DeepCopyData;
    struct PropDescSaveAs;
    struct SaveAsDesc;
    struct SaveAsDescResponse;

    /**
     * This is an enumeration of the property types for which DeepCopy Rule configuration
     * is enabled.
     */
    enum PropertyType{ Relation,
                 Reference
                 };

    /**
     * Map contains a list of <name, value> pairs (<code>string, bool</code>).  Each pair
     * stores information for a bool property. In each pair, name is the property name and
     * value is a bool for the property.
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * Map contains a list of <name, valueVector> pairs.  Each pair stores information for
     * a bool array property. In each pair, name is the property name and value is a list
     * of bool values for the property.
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * Map contains a list of <name, value> pairs <code>(string, DateTime</code>).  Each
     * pair stores information for a date property. In each pair,  name is the property
     * name and value is  a DateTime for the property.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * Map contains a list of <name, valueList> pairs (<code>string, vector< DateTime></code>).
     * Each pair stores information for a Date array property. In each pair, name is the
     * property name and value is a list of DateTime for the property.
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * Map contains a list of <name, value> pairs (<code>BusinessObject, vector<DeepCopyData></code>).
     * For each pair, name is the business object and value holds  the deep copy data for
     * the business object.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< DeepCopyData > > DeepCopyInfoMap;

    /**
     * Map contains a list of <name, value> pairs (<code>string, double</code>).  Each pair
     * stores information for a double property. In each pair, name is the property name
     * and value is a double for the property.
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * Map contains a list of <name, valueList> pairs (<code>string, vector< double></code>).
     * Each pair stores information for a double array property. In each pair, name is
     * the property name and value is a list of doubles for the property.
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * Map contains a list of <name, value> pairs (<code>string, float</code>).  Each pair
     * stores information for a float property. In each pair,  name is the property name
     * and value is a float for the property.
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * Map contains a list of <name, valueList> pairs (<code>string, vector< float></code>).
     * Each pair stores information for a float array property. In each pair, name is the
     * property name and  value is a list of floats for the property.
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * Map contains a list of <name, value> pairs <code>(string, vector< int></code>).
     * Each pair stores information for an int property. In each pair,  name is the property
     * name and value is an int value for the property.
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * Map contains a list of <name, valueList> pairs (<code>string, int</code>).  Each
     * pair stores information for an int array property. In each pair, name is the property
     * name and  value is the list of ints for the property.
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * Map contains a list of <name, value> pairs (<code>string, SaveAsDesc</code>).  For
     * each pair, name is the business object name and value corresponds to <code>SaveAs</code>
     * Descriptor data for the business object.
     */
    typedef std::map< std::string, SaveAsDesc > SaveAsDescMap;

    /**
     * Map contains a list of <name, value> pairs (<code>string, string</code>).  Each pair
     * stores information for a string property. In each pair,  name is the property name
     * and  value is a string for the property.
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * Map contains a list of <name, valueVector> pairs <code>(string, vector< string></code>).
     * Each pair stores information for a string array property. In each pair, name is
     * the property name  and value is a list of strings for the property.
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * Map contains a list of <name, value> pairs (<code>string, BusinessObjec</code>t).
     * Each pair stores information for a reference property. In each pair, name is the
     * property name and  value is the business object for the property.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * Map contains a list of <name, valueList> pairs (<code>string, vector<BusinessObject></code>).
     * . Each pair stores information for a reference array property. In each pair, name
     * is the property name and value is the list of business objects for the property.
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * This structure stores all the property input that are to be set to the object copy
     * by the <code>SaveAs</code> operation.
     */
    struct SaveAsInput
    {
        /**
         * Business object name
         */
        std::string boName;
        /**
         * Map (string, string) containing propName, stringValue> pairs for string properties
         */
        StringMap stringProps;
        /**
         * Map (string, vector<string>) containing <<code>propName, stringList</code>> pairs
         * for string array properties
         */
        StringVectorMap stringArrayProps;
        /**
         * Map (string, double) containing <<code>propName, doubleValue</code>> pairs for double
         * properties
         */
        DoubleMap doubleProps;
        /**
         * Map (string, vector<double>) containing <<code>propName, doubleList</code>> for double
         * array properties
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map (string, float) containing <<code>propName, floatValue</code>> for float properties
         */
        FloatMap floatProps;
        /**
         * Map (string, vector<float>) containing <<code>propName, floatList</code>> for float
         * array properties
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map (string, int) containing <<code>propName, intValue</code>> for int properties
         */
        IntMap intProps;
        /**
         * Map (string, vector<int>) containing <<code>propName, intList</code>> for int array
         * properties
         */
        IntVectorMap intArrayProps;
        /**
         * Map (string, bool) containing <<code>propName, boolValue</code>> for bool properties
         */
        BoolMap boolProps;
        /**
         * Map (string, vector<bool>) containing <<code>propName, boolList</code>> for bool
         * array properties
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map (string, DateTime) containing <<code>propName, dateTimeValue</code>> for date
         * properties
         */
        DateMap dateProps;
        /**
         * Map (string, vector<DateTime>) containing <<code>propName, dateTimeList</code>> for
         * date  array properties
         */
        DateVectorMap dateArrayProps;
        /**
         * Map (<code>string, BusinessObject</code>) containing <propName, businessObject> for
         * reference properties
         */
        TagMap tagProps;
        /**
         * Map (string, vector<BusinessObject>) containing <<code>propName, businessObjectList</code>>
         * for reference array properties
         */
        TagVectorMap tagArrayProps;
    };

    /**
     * DeepCopyData stores the deep copy information and <code>OperationInput</code> data
     * of the objects that will be copied via <code>saveAs</code> or revise operation. It
     * also stores the nested deep copy data at the next level.
     */
    struct DeepCopyData
    {
        /**
         * Other side object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  attachedObject;
        /**
         * Name of relation type or reference property for which <code>DeepCopy</code> rule
         * is configured
         */
        std::string propertyName;
        /**
         * Enumeration indicating if <code>DeepCopyRule</code> is configured for relation or
         * feference property
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
         * If flag is false, the copy action can be dynamicaly changed by user
         */
        bool isRequired;
        /**
         * Flag indicating whether the properties on the relation object itself need to be copied
         * or not
         */
        bool copyRelations;
        /**
         * SaveAsInput type name
         */
        std::string saveAsInputTypeName;
        /**
         * List of DeepCopy data for the objects on the other side of the relation property
         * or reference property
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Operationdescriptor::DeepCopyData > childDeepCopyData;
        /**
         * Store the user inputs on the <code>SaveAs</code> dialog. NOTE: This field is not
         * used in the <code>getSaveAsDesc</code> operation. It is used in the <code>saveAsObjects</code>
         * operation
         */
        Teamcenter::Services::Core::_2011_06::Operationdescriptor::SaveAsInput saveAsInput;
    };

    /**
     * This structure captures a property definition for a <code>SaveAs</code> Descriptor.
     */
    struct PropDescSaveAs
    {
        /**
         * Core property descriptor structure
         */
        Teamcenter::Services::Core::_2008_06::Propdescriptor::PropDesc parent;
        /**
         * Indicating if the property value is to be copied from original object to the object
         * copy -  true indicates the property value is to be copied.
         */
        bool copyFromOriginal;
    };

    /**
     * This structure captures the list of property description data for <code>SaveAs</code>
     * Descriptor. Clients can use this information to generically construct <code>SaveAs</code>
     * dialogs for any business object.
     */
    struct SaveAsDesc
    {
        /**
         * Name of business object that owns the descriptor
         */
        std::string businessObjectName;
        /**
         * List of property description data
         */
        std::vector< Teamcenter::Services::Core::_2011_06::Operationdescriptor::PropDescSaveAs > propDescs;
    };

    /**
     * Structure that contains metadata information about the properties relevant to the
     * SaveAs operation i.e, property is mandatory, property is visible, if value is to
     * be copied from original object, etc. It also has the <code>DeepCopyData</code> embedded
     * within which is a recursive data structure. The <code>DeepCopyData</code> contains
     * information about how the secondary objects (related and referenced objects) are
     * to be copied (reference, copy as object, no copy).
     */
    struct SaveAsDescResponse
    {
        /**
         * A map of business object types and SaveAs Descriptors (string/SaveAsDesc).  This
         * is the container of metadata for SaveAs that can be used by clients to generically
         * construct SaveAs dialogs for business objects.
         */
        SaveAsDescMap saveAsDescMap;
        /**
         * A map of business objects and <code>DeepCopyData</code> (business object/<code>DeepCopyData</code>).
         * Each business object from the method input will have a <code>DeepCopyData</code>
         * in the map. The <code>DeepCopyData</code> object contains all the information about
         * how the attached objects are to be copied (Copy as Object, Copy as Reference, NoCopy,
         * etc.).  <code>DeepCopyData</code> is a recursive data structure that contains the
         * details for the attached objects at the next level.
         * <br>
         * NOTE: Attached objects can be either referenced objects or related objects.
         */
        DeepCopyInfoMap deepCopyInfoMap;
        /**
         * Service data containing errors, etc. The plain object list of the Service data is
         * populated with the target objects which are to be copied as part of the SaveAs operation.
         * If there is an error retrieving Business Object for the business object name corresponding
         * to the target object, it is added to the error stack of the <code>ServiceData</code>
         * as a partial error
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation returns information required to save a business object. The <code>SaveAsDescriptor</code>
     * includes the metadata information for the properties required when saving a business
     * object, i.e., the property is mandatory, the property is visible, if value is to
     * be copied from original object, etc.  The <code>SaveAsDescriptor</code> also includes
     * the <code>DeepCopyData</code> which is a recursive data structure. The <code>DeepCopyData</code>
     * contains information about how the secondary objects (related and referenced objects)
     * are to be copied (reference, copy as object, no copy).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Get SaveAsDescriptor for the SaveAs wizard</b>
     * <br>
     * Client constructs the SaveAs dialog for a Business Object using this operation. The
     * information returned by this operation allows a client to construct the SaveAs dialogs
     * and DeepCopy panels for user input. Once the user input is received, client can make
     * subsequent invocation to the <code>DataManagement.saveAsObjects</code> operation
     * to execute SaveAs on the object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * saveAsObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param targetObjects
     *        Set of objects for which the SaveAs Descriptor is needed.
     *
     * @return
     *         This is metadata information about the properties relevant to a Save As operation
     *         i.e, the property is mandatory, the property is visible, if value is to be copied
     *         from original object, etc. It also includes the <code>DeepCopyData</code> which is
     *         a recursive data structure. The <code>DeepCopyData</code> contains information about
     *         how the secondary objects (related and referenced objects) are to be copied (reference,
     *         copy as object, no copy).
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2011_06::Operationdescriptor::SaveAsDescResponse getSaveAsDesc ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& targetObjects ) = 0;


protected:
    virtual ~Operationdescriptor() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

