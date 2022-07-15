// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef INCLUDE_TEAMCENTER_SOA_COMMON_POLICYPROPERTY_HXX
#define INCLUDE_TEAMCENTER_SOA_COMMON_POLICYPROPERTY_HXX

#include <string>
#include <map>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>

/**
 * Key value to be used in the get/set Modifier methods.
 * By default the Object Property Policy is applied only to the objects explicitly 
 * returned by the service implemenation. So if the service returns a 'User' object and the 'home_folder' property is
 * part of the policy, the referenced 'home_folder' obect will be added to the return data, but without any associated properties. 
 * By setting this modifier to true, on the the 'home_folder' property,  properties for home folder will also be returned.
 */
#define  POLICY_MODIFIER_WITH_PROPERTIES     "withProperties"

/**
 * Key value to be used in the get/setModifier methods.
 * By default the Object Property Policy returns both the database and UI value for each property. By setting this modifier to 
 * true, only the database values of a property are returned, the UI value is excluded from the return data.
 */
#define  POLICY_MODIFIER_EXCLUDE_UI_VALUE    "excludeUiValues"

/**
 * Key value to be used in the get/setModifier methods.
 * By default the Object Property Policy does not returns the 'Is Modifiable' flag with
 * each property value. The 'modifiable' flag is the instance based flag vs. the Meta Model flag
 * defined on the PropertyDesciption. By setting this modifier to 
 * true, the 'Is Modifiable' flag will be returned.
 */
#define  POLICY_MODIFIER_INCLUDE_MODIFIABLE  "includeIsModifiable"

/**
 * Obsolete
 * Use POLICY_MODIFIER_INCLUDE_MODIFIABLE to include the 'Is Modifiable' when the client actually needs 
 * this data.
 */
#define  POLICY_MODIFIER_EXCLUDE_MODIFIABLE  "excludeIsModifiable"

    
/**
 * Key value to be usedin the get/setModifier methods.
 * This modifier is effective only for attribute properties stored directly in the database (those of type ImanPropAttribute).
 * By default the Object Property Policy ensures that all standard and customized runtime modifications are performed
 * on the property value before it is returned.  By setting this modifier to true, the database attribute value
 * is returned without checking for runtime modifications.  This can be used as a perrformance enhancement, but should be used only
 * when the application and customizations do not use any runtime modifications for the property.
 */
#define  POLICY_MODIFIER_AS_ATTRIBUTE  "asAttribute"

/**
 * Key value to be used in the get/set Modifier methods. 
 * By default the full property information is returned for the named property, this includes the database value,
 * the display or UI value, and flags such as 'isModifiable'. With this flag set to 'true' only the UI value will be returned.
 * This flag takes precedence over any other flags set in the policy for the named property.
 */
#define  POLICY_MODIFIER_UI_VALUE_ONLY  "uIValueOnly"

/**
 * Key value to be used in the get/set Modifier methods. 
 * By default the properties defined on the parent type are included in the current type. 
 * With this property set to 'true' properties defined on the parent are excluded.
 */
#define  POLICY_MODIFIER_EXCLUDE_PARENT_PROPERTIES  "excludeParentProperties"



namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            class ObjectPropertyPolicy;
            class PolicyType;



class TCSOACOMMON_API PolicyProperty
{
 public:

    /**
     * Create an instance of the PolicyProperty.
     * @param name   The name of the property,
     **/
    explicit PolicyProperty(const std::string& name );
    PolicyProperty();

    /**
     * Create an instance of the PolicyProperty.
     * @param name       The name of the property,
     * @param modifiers  A comma separated list of modifiers to be applied (true) to this property. 
     * Legal value are:
     * <UL>
     *    <li> POLICY_MODIFIER_WITH_PROPERTIES     
     *    <li> POLICY_MODIFIER_EXCLUDE_UI_VALUE    
     *    <li> POLICY_MODIFIER_INCLUDE_MODIFIABLE  
     *    <li> POLICY_MODIFIER_AS_ATTRIBUTE
     *    <li> POLICY_MODIFIER_UI_VALUE_ONLY
     *    <li> POLICY_MODIFIER_EXCLUDE_PARENT_PROPERTIES
     *</UL>   **/
    PolicyProperty( const std::string& name, const std::string& modifiers);

    PolicyProperty(const PolicyProperty& policyProperty ); 
    ~PolicyProperty();

    /**
     * Returns the property name.
     *
     * @return Property name.
     */
    const std::string& getName() const;
    void setName( const std::string& name );

    /**
     * Returns the value of the named modifier.
     *
     * @param name The name of the desired modifier
     * @return The value true/false of the named modifier. If the modifier does not exist on the PolicyProperty false will be returned.
     */
    bool getBooleanModifier( const std::string& name )const;

    /**
     * Set the value for a modifier
     *
     * @param name The name of the desired modifier. 
     *  Setting a modifier on the PolicyProperty will override a modifier on the PolicyType or ObjectPropertyPolicy.
     * Legal value are:
     * <UL>
     *    <li> POLICY_MODIFIER_WITH_PROPERTIES     
     *    <li> POLICY_MODIFIER_EXCLUDE_UI_VALUE    
     *    <li> POLICY_MODIFIER_INCLUDE_MODIFIABLE  
     *    <li> POLICY_MODIFIER_AS_ATTRIBUTE
     *    <li> POLICY_MODIFIER_UI_VALUE_ONLY
     *    <li> POLICY_MODIFIER_EXCLUDE_PARENT_PROPERTIES
     *</UL>
     * @param value true/false value to set the modifier to.
     */
    void setModifier( const std::string& name, bool value );

    /**
     * Returns a list of Modifier names that are set on this PolicyProperty.
     *
     * @return A vector of modifier names.
     */
    std::vector<std::string>getModifierNames() const; 

    /**
     * Returns boolean if the string constant is a flag or not.
     *
     * @return bool true/false for the modifier.
     */
    static bool isAFlag(const std::string flag);

    
    bool operator ==(const PolicyProperty& that) const;
    bool operator !=(const PolicyProperty& that) const {return !operator==(that);}
    bool operator  >(const PolicyProperty& that) const; //needed for std::set
    bool operator  <(const PolicyProperty& that) const; //needed for std::set

    SOA_CLASS_NEW_OPERATORS
      
private:
    friend class ObjectPropertyPolicy;
    friend class PolicyType;


    

    
     

     std::string                        name;
     std::map<std::string,std::string>  modifiers;

};        // End Class
}}}       // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
