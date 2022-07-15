// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYDESCRIPTION_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYDESCRIPTION_HXX

#include <string>
#include <new>
#include <vector>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/Lov.hxx>
#include <teamcenter/soa/client/NamingRule.hxx>
#include <teamcenter/soa/client/BasedOn.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

// Simple class to wrap the Property Renderer Data string
// This allows the dynamic_casting in the ConditionChoice class
class TCSOACLIENTMNGD_API Renderer : public Chooseable
{
public:
    virtual ~Renderer();
    SOA_CLASS_NEW_OPERATORS

    virtual std::string getRenderData()const =0;
};


class TCSOACLIENTMNGD_API PropertyDescription
{
public:
    enum PropertyType
    {
        CLIENT_PROP_TYPE_char           = 0x01, /** Value is a single character */
        CLIENT_PROP_TYPE_date           = 0x02, /** Value is a date */
        CLIENT_PROP_TYPE_double         = 0x03, /** Value is a double */
        CLIENT_PROP_TYPE_float          = 0x04, /** Value is a float */
        CLIENT_PROP_TYPE_int            = 0x05, /** Value is an integer */
        CLIENT_PROP_TYPE_bool           = 0x06, /** Value is a logical */
        CLIENT_PROP_TYPE_short          = 0x07, /** Value is a short */
        CLIENT_PROP_TYPE_string         = 0x08, /** Value is a character string */
        CLIENT_PROP_TYPE_ModelObject    = 0x09  /** Value is Business Model Object */
    };

        // This is coppied from propdesc.h on the server
    // Maybe dodgey - but then it's not changed in years!
    enum ServerPropType
    {
        SERVER_PROP_untyped,               /** No Value type */
        SERVER_PROP_char,                  /** Value is a single character */
        SERVER_PROP_date,                  /** Value is a date */
        SERVER_PROP_double,                /** Value is a double */
        SERVER_PROP_float,                 /** Value is a float */
        SERVER_PROP_int,                   /** Value is an integer */
        SERVER_PROP_logical,               /** Value is a logical */
        SERVER_PROP_short,                 /** Value is a short */
        SERVER_PROP_string,                /** Value is a character string */
        SERVER_PROP_typed_reference,       /** Value is a typed reference */
        SERVER_PROP_untyped_reference,     /** Value is an untyped reference */
        SERVER_PROP_external_reference,    /** Value is an external reference */
        SERVER_PROP_note,                  /** Value is a note */
        SERVER_PROP_typed_relation,        /** Value is a typed relation */
        SERVER_PROP_untyped_relation       /** Value is an untyped relation */
    };
    enum ServerPropertyType
    {
        PROPERTY_TYPE_UNKNOWN                 = 0,
        PROPERTY_TYPE_POM_ATTRIBUTE           = 1,
        PROPERTY_TYPE_POM_REFERENCE           = 2,
        PROPERTY_TYPE_IMAN_RELATION           = 3,
        PROPERTY_TYPE_PROP_FROM_ANOTHER_TYPE  = 4,
        PROPERTY_TYPE_COMPUTED                = 5,
        PROPERTY_TYPE_SOURCE_PROPERTY         = 6
    };

    enum FieldType
    {
        FIELD_TYPE_UNKNOWN                  = 0,
        FIELD_TYPE_SIMPLE                   = 1,
        FIELD_TYPE_COMPOUND_OBJECT          = 2
    };

    enum CategoryType
    {
        LOV_CATEGORY_NONE                 = 0,
        LOV_CATEGORY_IS_TRUE_CONDITION    = 1,
        LOV_CATEGORY_SESSION_CONDITIONS   = 2,
        LOV_CATEGORY_OBJECT_CONDITIONS    = 3
    };


    enum RuleCategory
    {
        /** The Property description does not have a  {@link NamingRule}   */
        RULE_CATEGORY_NONE = 0,
        /** There is a single {@link NamingRule}  attached to this property description with the 'isTrue'  */
        RULE_CATEGORY_IS_TRUE = 1,
        /** There are one or more {@link NamingRule} attached to this property description with conditions based on the
         * current User Session. These  {@link NamingRule}s should not be cached but instead retrieved from the
         *  {@link PropertyDescription}  when ever it is display or used  */
        RULE_CATEGORY_SESSION_CONDITION = 2
    };

    static const std::string PROPERTY_CONSTANT_MODIFIABLE;
    static const std::string PROPERTY_CONSTANT_DISPLAYABLE;
    static const std::string PROPERTY_CONSTANT_REQUIRED;
    static const std::string PROPERTY_CONSTANT_EDITABLE;
    static const std::string PROPERTY_CONSTANT_LOCALIZABLE;
    static const std::string PROPERTY_CONSTANT_INITIAL_VALUE;
    static const std::string PROPERTY_CONSTANT_COPY_FROM_ORIGINAL;
    static const std::string PROPERTY_CONSTANT_AUTOASSIGNABLE;
    static const std::string PROPERTY_CONSTANT_VALIDATABLE;

    /**
     * Get the name of the property.
     *
     * @return The property name.
     */
    virtual const std::string&  getName() const = 0;

    /**
     * The property value type.
     *
     * @return The property value type.
     */
    virtual PropertyType        getType() const = 0;

    /**
     *
     * @return True if the property has an array of values.
     */
    virtual bool                isArray() const = 0;

    /**
     *
     * @return True if the property can be modified.
     */
    virtual bool                isModifiable() const = 0;

    /**
     * Get the maximum number of values a property may have.
     * If there is no limit on the size of the value array -1 is returned. Otherwise
     * a positive integer is returned.
     *
     * @return If the property is an array, this is the maximum number of values this property may have.
     */
    virtual int                 getMaxArraySize() const = 0;


    /**
     * @return The localized (displayable) name of the property.
     */
     virtual const std::string&  getUiName()const = 0;

    /**
     * @return Type UID
     */
    virtual const std::string&  getTypeUid() const = 0;


    /**
     * @return True if the property can be displayed.
     */
     virtual bool                isDisplayable() const = 0;

   /**
    * @return If the property is a string, this is the maximum length the value may be.
    */
    virtual int                 getMaxLength() const = 0;


   /**
    * The maximum allowable value of the property.
    * For date properties ( {@link #CLIENT_PROP_TYPE_date} == {@link #getType()}) the format of
    * this returned string will be 'YYYY-MM-DDThh:mm:ss.sTZD' (1997-07-16T19:20:30.45-08:00)
    * Floating point properties ( {@link #CLIENT_PROP_TYPE_double} == {@link #getType()})will always be represented with a decimal point (3.14).
    *
    * @return The maximum allowable value of the property.
    * @since %Teamcenter Server 9.1
    */
    virtual std::string         getMaxValue() const = 0;


   /**
    * The minimum allowable value of the property.
    * For date properties ( {@link #CLIENT_PROP_TYPE_date} == {@link #getType()}) the format of
    * this returned string will be 'YYYY-MM-DDThh:mm:ss.sTZD' (1997-07-16T19:20:30.45-08:00)
    * Floating point properties ( {@link #CLIENT_PROP_TYPE_double} == {@link #getType()})will always be represented with a decimal point (3.14).
    *
    * @return The minimum allowable value of the property.
    * @since %Teamcenter Server 9.1
    */
    virtual std::string         getMinValue() const = 0;

   /**
    * @return Attached specifier
    */
    virtual int                 getAttachedSpecifier() = 0;

    /**
    * @return LOV Type UID
    */
    virtual std::string  getLovTypeUid() = 0;


   /**
    * @return True if this property needs to be set during creation and editing.
    */
    virtual bool                isRequired() const = 0;

   /**
    * @return The default or initial value a property should be assigned. May be null if a value is not defined.
    */
    virtual std::string*       getInitialValue() const = 0;


   /**
    * The property type enumeration as defined on the server.
    *
    * @return The property value type.
    */
    virtual ServerPropType                 getServerType() const = 0;

   /**
    * @return The server property type
    */
    virtual ServerPropertyType getServerPropertyType() const = 0;


   /**
    * @return True if this property is editable in UI.
    */
    virtual bool                isEnabled() const = 0;



   /**
    * @return True if this property can be localized.
    */
    virtual bool                isLocalizable() const = 0;

   /**
    * Get the named property constant.
    * <ul>
    * <li> {@link #PROPERTY_CONSTANT_MODIFIABLE}         True ("1") if the property can be modified.
    * <li> {@link #PROPERTY_CONSTANT_DISPLAYABLE}        True ("1") if the property can be displayed
    * <li> {@link #PROPERTY_CONSTANT_REQUIRED}           True ("1") if this property needs to be set during creation and editing.
    * <li> {@link #PROPERTY_CONSTANT_EDITABLE}           True ("1") if this property is editable in UI. (enabled)
    * <li> {@link #PROPERTY_CONSTANT_LOCALIZABLE}        True ("1") if this property can be localized.
    * <li> {@link #PROPERTY_CONSTANT_INITIAL_VALUE}      The initial value of this property, may be null.
    * <li> {@link #PROPERTY_CONSTANT_COPY_FROM_ORIGINAL} True ("1") if this property is copied from original. Since %Teamcenter Server 9.1
    * <li> {@link #PROPERTY_CONSTANT_AUTOASSIGNABLE}     True ("1") if this property is assignable by the server.
    * <li> {@link #PROPERTY_CONSTANT_VALIDATABLE}        True ("1") if this property is validatable by the server.
    *</ul>
    * The more common constants have explicit accessor methods (i.e. isModifiable()).
    * For property constants representing boolean values, the Property::parseBoolean
    * method can be used to convert the string to a boolean.
    *
    * @param name The constant name
    * @return  The named constant value
    * @since %Teamcenter Server 9.0
    */
    virtual std::string  getConstant( const std::string&  name) const = 0;



   /**
    * Property used for OperationInput Dialog (e.g. Create Descriptor)
    *
    * @return the field type
    * @since %Teamcenter Server 9.0
    */
    virtual FieldType getFieldType() const = 0;


   /**
    * The UID of the compound OperationInput type (TYPE::&lt;typeName&gt;::&lt;ClassName&gt;::&lt;ParentTypeName&gt;)
    * This attribute is used for:
    * <ul>
    * <li> getServerPropertyType = PROPERTY_TYPE_SOURCE_PROPERTY and getFieldType = FIELD_TYPE_COMPOUND_OBJECT
    *      Example: compoundObjType of IMAN_master_form at ItemCreI is Item MasterCreI
    * <li> getServerPropertyType= PROPERTY_TYPE_COMPUTED
    *      Example: compoundObjType of revision at ItemCreI is ItemRevisionCreI
    *</ul>
    *
    * @return The UID of the compound OperationInput type
    *
    * @since %Teamcenter Server 9.0
    */
    virtual std::string getCompoundObjectType() const = 0;

  /**
    * @return  The category of LOVs attached to the property.
    * @see PropertyDescription#getLovReference()
    * @since %Teamcenter Server 9.0
    */
    virtual CategoryType getLovCategory() const = 0;

   /**
    * @return The Property dependents
    */
    virtual std::vector<std::string> getPropDependants() = 0;

   /**
    * @return The LOV UID
    */
    virtual std::string  getLovUid() = 0;




   /**
    * The LOV associated with this property.
    *
    * The LOV Category of this PropertyDescription determines what will be returned from this method:
    * <UL>
    * <li> {@link #LOV_CATEGORY_NONE}     No LOVs are attached, this method will always return null.
    * <li> {@link #LOV_CATEGORY_IS_TRUE_CONDITION}  A single LOV is attached with the 'isTrue' condition, this method
    * will always return the same rule.
    * <li> {@link #LOV_CATEGORY_SESSION_CONDITIONS} Multiple LOVs are be attached to this same PropertyDescription
    * through session based conditions. The conditions are evaluated when this method is called.
    * When there are multiple true conditions, the first LOV with a true condition is the one that is returned.
    * These LOVs should not be cached, but instead retrieved from the PropertyDescription when ever it is display or used.
    * <li> {@link #LOV_CATEGORY_OBJECT_CONDITIONS} Multiple LOVs are be attached to this same PropertyDescription
    * through object instance based conditions.
    * </UL>
    * @return  The LOV associated with this property.
    *
    * @see PropertyDescription#getLovCategory()
    */
    virtual Lov* getLovReference() =0;

   /**
    * If this property is used multi-level LOV, this method will return the name of the property of
    * the root level of the LOV it is used in.
    *
    * @return The name of the LOV root level property, empty string if this property is not associated with any LOV.
    */
    virtual std::string getRootLovPropertyName() const=0;


   /**
    * Naming rule of the property.
    * Name Rule is used to specify the patterns the property value has to follow.
    * <pre>
    * Example: object_name. Its Name Rule is: "CSTMNOTE-"nnnnnn.
    * The object name can be: CSTMNOTE-123456.
    * </pre>
    * The client application should validate values entered by user,
    * to give the user immediate feedback that of an invalid entry.
    * The server will ultimately validate to ensure invalid data is not persisted in the database.<br>
    *
    * The RuleCategory of this PropertyDescription determines what will be returned from this method:
    * <UL>
    * <li> {@link #RULE_CATEGORY_NONE}     No rules are attached, this method will always return null.
    * <li> {@link #RULE_CATEGORY_IS_TRUE}   A single rule is attached with the 'isTrue' condition, this method
    * will always return the same rule.
    * <li> {@link #RULE_CATEGORY_SESSION_CONDITION} Multiple rules are attached to the PropertyDescription
    * with different session based conditions, however only a single rule applies at any given time.
    * The conditions are resolved at the time of the call to this method. When there are multiple true conditions,
    * the first rule with a true condition is the one that is returned. These rules should not be cached,
    * but instead retrieved from the PropertyDescription when ever it is display or used.
    * </UL>
    *
    *
    * @return Naming rule of the property
    * @see PropertyDescription#getNamingRuleCategory()
    * @since %Teamcenter Server 9.0
    */
    virtual NamingRule* getNamingRule()=0;


   /**
    * The category of the {@link NamingRule} attached to this PropertyDescription
    *
    * @return The category of {@link NamingRule} attached to this PropertyDescription
    *
    * @see PropertyDescription#getNamingRule()
    */
   virtual RuleCategory getNamingRuleCategory() const =0;

   /**
    * The renderer associated with this property.
    *
    * This may be an empty string if the property does not have a renderer,
    * this includes use cases where none of the attached renderers' conditions
    * are currently true.  Multiple renderers can be attached to the same
    * property through conditions.  The condition is determined to be true
    * based on valid conditions on UserSession.fnd0isTrueConditions.
    * This is evaluated when this method is called.
    * When there are multiple true conditions, the first renderer with a true
    * condition is the one that is returned.

    * @return The renderer associated with this property.
    * @since %Teamcenter Server 9.1
    */
    virtual std::string getRenderer() = 0;

   /**
    *  Indicates if the property is a derived property that is based on another property.
    *
    * @return The Based-On information, or null if this property is not derived from another.
    * @since Teamcenter Server 9.0
    */
   virtual BasedOn* getBasedOn() const=0;

    SOA_CLASS_NEW_OPERATORS

protected:
    virtual ~PropertyDescription();
};

}}} //end namespace


#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
