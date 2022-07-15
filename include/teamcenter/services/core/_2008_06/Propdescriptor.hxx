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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_PROPDESCRIPTOR_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_PROPDESCRIPTOR_HXX

#include <teamcenter/soa/client/model/ListOfValues.hxx>


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
            namespace _2008_06
            {
                class Propdescriptor;

class TCSOACORESTRONGMNGD_API Propdescriptor
{
public:

    struct CreateDesc;
    struct CreateDescResponse;
    struct PropDesc;
    struct SecCreateDesc;

    /**
     * Enum for compounding context. Used to indicate if secondary (compounded) object is
     * a compound object (value will be <code>CompoundObject</code>) or compound relation
     * (value will be <code>CompoundRelation</code>). When the context is <code>CompoundRelation</code>,
     * it is usually for the roperties on Relation use case when the Relation creation descriptor
     * itself may have properties configured for creation
     * <br>
     * NOTE: <code>CompoundRelation</code> case is not supported at this time
     * <br>
     */
    enum CompoundingContext{ CompoundObject,
                 CompoundRelation
                 };

    /**
     * SecCreateDescMap
     */
    typedef std::map< std::string, std::vector< SecCreateDesc > > SecCreateDescMap;

    /**
     * Create Descriptor definition
     */
    struct CreateDesc
    {
        /**
         * Business Object Type Name
         */
        std::string businessObjectTypeName;
        /**
         * Vector of Property Descriptors
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Propdescriptor::PropDesc > propDescs;
        /**
         * Map of property name to secondary object's create descriptors
         */
        SecCreateDescMap secondaryCreateDescs;
    };

    /**
     * Structure containing Create Descriptor information representing the metadata about
     * the properties relevant to a Create Operation
     */
    struct CreateDescResponse
    {
        /**
         * List of <code>Teamcenter::Soa::Core::_2008_06::PropDescriptor::CreateDesc</code>
         * objects. Each element in the list is a Create Descriptor for a business object which
         * contains metadata information about the properties necessary to create the business
         * object i.e, property is mandatory, property is visible, etc. It is a recursive data
         * structure which may point to secondary <code>CreateDesc</code> objects e.g <b>Item</b>
         * <code>CreateDesc</code> contains references to <b>ItemRevision</b> and <b>Item Master</b>
         * <code>CreateDesc</code> objects
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Propdescriptor::CreateDesc > createDescs;
        /**
         * Service data containing partial errors. If there is any error in retrieving the Create
         * Descriptor for any Business Object in the input vector, it is returned as part of
         * the error stack. The service data also contains LOV objects for the properties in
         * the plain objects vector in the service data
         */
        Teamcenter::Soa::Client::ServiceData srvData;
    };

    /**
     * The PropDesc struct describes information about the Teamcenter property
     */
    struct PropDesc
    {
        /**
         * Name of the property
         */
        std::string propName;
        /**
         * Display name of the property
         */
        std::string displayName;
        /**
         * Default value for the property
         */
        std::string defaultValue;
        /**
         * Value type for the property, PROP_untyped (0) No Value type PROP_char (1) Value is
         * a single character PROP_date (2) Value is a date PROP_double (3) Value is a double
         * PROP_float (4) Value is a float PROP_int (5) Value is an integer PROP_logical (6)
         * Value is a logical PROP_short (7) Value is a short PROP_string (8) Value is a character
         * string PROP_typed_reference (9) Value is a typed reference PROP_untyped_reference
         * (10) Value is an untyped reference PROP_external_reference (11) Value is an external
         * reference PROP_note (12) Value is a note PROP_typed_relation (13) Value is a typed
         * relation PROP_untyped_relation (14) Value is an untyped relation
         */
        int propValueType;
        /**
         * Type for the property PROP_unknown (0) Property type is Unknown PROP_attribute (1)
         * Based on a POM Attribute (int, string, ...) PROP_reference (2)  Based on a POM Reference
         * PROP_relation (3) Based on an ImanRelation PROP_compound (4) Based on a property
         * from another Type PROP_runtime (5) Based on a computed value
         */
        int propType;
        /**
         * isDisplayable
         */
        bool isDisplayable;
        /**
         * Specifies whether the property is an array or single value
         */
        bool isArray;
        /**
         * Specifies the max number of elements
         */
        int maxNumElems;
        /**
         * ListOfValues object attached to the property (if any)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
        /**
         * Specifies whether the property is required
         */
        bool isRequired;
        /**
         * Specifies whether the property is enabled
         */
        bool isEnabled;
        /**
         * Specifies whether the property is modifiable
         */
        bool isModifiable;
        /**
         * attachedSpecifier
         */
        int attachedSpecifier;
        /**
         * maxLength
         */
        int maxLength;
        /**
         * interdependentProps
         */
        std::vector< std::string > interdependentProps;
        /**
         * Naming patterns for property, can be null
         */
        std::vector< std::string > namingPatterns;
    };

    /**
     * Secondary Create Descriptor definition. This is the secondary create descriptor data
     * type for secondary objects that get created during object creation. For example,
     * <b>ItemRevision</b> and <b>Item Master</b> are the secondary objects that get created
     * during creation of <b>Item</b>. Note that this is a recursive data structure which
     * can itself point to other Secondary Create Descriptors (<b>ItemRevision</b> pointing
     * to <b>ItemRevision Master</b>)
     */
    struct SecCreateDesc
    {
        /**
         * Business Object Type Name of the secondary object
         */
        std::string businessObjectTypeName;
        /**
         * Boolean field indicating if creation of secondary object is required (non optional)
         * or not
         */
        bool isRequired;
        /**
         * true indicates the secondary descriptor is part of an array of secondary descriptors
         * (The relation or reference property on the primary create descriptor could potentially
         * point to several secondary descriptors i.e Create several secondary objects for the
         * same reference or relation property. This is the usecase for which the field will
         * be true for each Secondary Descriptor in the array)
         */
        bool isArray;
        /**
         * enum indicating if the secondary object is a relation (in which case value is <code>CompoundRelation</code>)
         * or a regular business object (in which case value is <code>CompoundObject</code>)
         */
        CompoundingContext compoundingCtxt;
        /**
         * List of Property Descriptors for the Secondary Object
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Propdescriptor::PropDesc > propDescs;
        /**
         * Map <code>(string, Teamcenter::Soa::Core::_2008_06::PropDescriptor::SecCreateDesc</code>)
         * of the secondary descriptor objects. For example, an <b>ItemRevision</b> is the Secondary
         * CreateDescriptor for <b>Item</b>. The <b>ItemRevision</b> Secondary Create Descriptor
         * itself will contain SecCreateDesc objects for <b>ItemRevision Master</b> which is
         * also created when the <b>ItemRevision</b> is created. The map contains the reference
         * property or relation property name on the Parent Secondary Business Object as the
         * key and the <code>SecCreateDesc</code> as the value. If there are no secondary objects
         * to be created, the map will be empty (For example, the secondary create descriptor
         * for <b>Item Master</b>  which is created when <b>Item</b> is created has an empty
         * map)
         */
        SecCreateDescMap secondaryCreateDescs;
    };




    /**
     * The operation returns information required to create a Business Object. The Create
     * Descriptor (CreateDesc object) includes the metadata information for the properties
     * required when creating a business object  i.e, property is mandatory, property is
     * visible, etc. The CreateDesc is a recursive data structure. The CreateDesc object
     * can also reference CreateDesc on secondary objects through a reference or relation
     * property. For example, the CreateDesc for <b>Item</b> points to CreateDesc on its
     * related secondary objects, <b>ItemRevison</b> and <b>Item Master</b>. The CreateDesc
     * for <b>ItemRevision</b> in turn points to the CreateDesc for <b>ItemRevision Master</b>.
     * <br>
     * <br>
     * NOTE:  The operation will be deprecated as of Teamcenter 10. All the metadata information
     * necessary for the Create operation can be retrieved from the SOA client metamodel.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Get Create Descriptor information for the Create wizard for an object.
     * <br>
     * This call is made to populate the Create dialog for any Business Object. After obtaining
     * the user input on the fields of the create dialog, a call is made to the <code>Teamcenter::Soa::Core::_2008_06::DataManagement::createObjects</code>
     * operation to create the object
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param businessObjectTypeNames
     *        list of business object names for which Create Descriptor is needed.
     *
     * @return
     *         Contains information from the Create Descriptor representing metadata about the properties
     *         relevant to a Create Operation.  For example, property is
     *         <br>
     *         mandatory or property is visible.
     *         <br>
     *         It is a recursive data structure that contains metadata information about any secondary
     *         objects that need to be created
     *         <br>
     *         One of the possible errors returned in the ServiceData is:
     *         <br>
     *         214133  No type was found for the given name
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Propdescriptor::CreateDescResponse getCreateDesc ( const std::vector< std::string >& businessObjectTypeNames ) = 0;


protected:
    virtual ~Propdescriptor() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

