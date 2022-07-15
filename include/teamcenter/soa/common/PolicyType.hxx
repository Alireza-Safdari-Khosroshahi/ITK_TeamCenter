// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_COMMON_POLICTYPE_HXX
#define TEAMCENTER_SOA_COMMON_POLICTYPE_HXX

#include <string>
#include <map>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/PolicyProperty.hxx>
#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {

class PolicyType;

/**
 * The PolicyType class manages a list of properties for a single Type or Class.
 **/
class TCSOACOMMON_API PolicyType
{
public:


    PolicyType( );
    /**
     * Create an instance of the PolicyType.
     * @param name   The name of the Type or Class,
     *               This value may also contain the list of properties
     *               'User' or 'User{volume,mailbox,home_folder}'
     **/
    explicit PolicyType( const std::string& name );

    /**
     * Create an instance of the PolicyType.
     * @param name   The name of the Type or Class,
     * @param props  A set of Property Names
     **/
    PolicyType( const std::string& name, const std::set<std::string>& props);
    
    /**
     * Create an instance of the PolicyType.
     * @param name   The name of the Type or Class,
     * @param props  A  comma separated list of Property Names
     **/
    PolicyType( const std::string& name, const std::string& props);

    /**
     * Create an instance of the PolicyType.
     * @param name       The name of the Type or Class,
     * @param props      A  comma separated list of Property Names
     * @param modifiers  A  comma separated list of Modifiers to be applied (true) to the list of properties.
     **/
    PolicyType( const std::string& name, const std::string& props, const std::string& modifiers);

    ~PolicyType();




    /**
     * Returns the list of properties associated with this Type or Class.
     * @return Set of property names.
     * @deprecated As of 9.0, use getProperties(std::set&lt;Teamcenter::Soa::Common::PolicyProperty*&gt;&amp; ).
     */
#ifdef WNT
__declspec(deprecated(" As of 9.0, use getProperties(std::set<Teamcenter::Soa::Common::PolicyProperty*>& )"))
#endif
    const std::set<Teamcenter::Soa::Common::PolicyProperty>& getProperties() const;

    /**
     * Returns the list of properties associated with this Type or Class.
     * @return Set of property names.
     * @deprecated As of 9.0, use getProperties(std::set&lt;Teamcenter::Soa::Common::PolicyProperty*&gt;&amp; ).
     */
#ifdef WNT
__declspec(deprecated(" As of 9.0, use getProperties(std::set<Teamcenter::Soa::Common::PolicyProperty*>& )"))
#endif
    std::set<Teamcenter::Soa::Common::PolicyProperty>& getProperties();

   /**
     * Returns the list of properties associated with this Type or Class.
     * @properties The set of property names.
     */
    void getProperties( std::set< const Teamcenter::Soa::Common::PolicyProperty*>& properties ) const;

   /**
     * Returns the list of property names associated with this Type or Class.
     *
     * @return A vector of PolicyProperty names.
     */
    std::vector<std::string> getPropertyNames() const;




    /**
     * Returns the Type or Class name this PolicyType.
     *
     * @return Type or Class name.
     */
    std::string  getName() const;
    void setName( const std::string& name );

   /**
     * Returns true if the named property is in this type.
     *
     * @param propertyName  The name of the desired property.
     *
     * @return true if the property is in this type.
     */
    bool hasProperty( const std::string& propertyName );


    /**
     * Return a string that represents this Object Property list.
     * The string will have the format:
     * TypeOrClassName { propertyName [,propertyName]...}
     *
     * @return String representation of this class
     **/
    std::string toString();

    /**
     * Add a single property to the list of properties.
     * Property modifiers (i.e. POLICY_MODIFIER_WITH_PROPERTIES) that exist on the PolicyType will be applied
     * to the named property. If the source property already exists in the PolicyType, all modifiers on that property will be
     * lost and only the modifiers from the PolicyType will be applied.
     *
     * @param propName    The name of the property to add
     **/
    void addProperty( const std::string& propName );

    /**
     * Add a single property to the list of properties.
     * Property modifiers (i.e. POLICY_MODIFIER_WITH_PROPERTIES) that exist on the PolicyType will be applied
     * to the PolicyProperty if the PolicyProperty does not have that modifier explicitly defined. If the source property already
     * exists in the PolicyType, all modifiers on that property will be lost and only the modifiers from the input/PolicyType will be applied.
     *
     * @param prop    The PolicyProperty to add
     **/
    void addProperty( Teamcenter::Soa::Common::PolicyProperty& prop );

    /*
     * Erase a property form the list of properties
     *
     * @param prop    The property to erase
     **/
    void eraseProperty( const Teamcenter::Soa::Common::PolicyProperty& prop );

    /*
     * Erase a property form the list of properties
     *
     * @param propName    The name of the property to erase
     **/
    void eraseProperty( const std::string& propName );


    /**
     * Sets the list of properties for this Type or Class.
     * Any properties currently mantained by this instance of PolicyType are
     * thrown away.
     *
     * @param props  List of property names, i.e. '{volume,mailbox,home_folder}'.
     */
    void setProperties( const std::string& props);

    /**
     * Adds to the list of properties for this Type or Class.
     * Property modifiers (i.e. POLICY_MODIFIER_WITH_PROPERTIES) that exist on the PolicyType will be applied
     * to the named properties. If the source property already exists in the PolicyType, all modifiers on that property will be
     * lost and only the modifiers from the PolicyType will be applied.
     *
     * @param props  List of property names, i.e. '{volume,mailbox,home_folder}'.
     */
    void addProperties( const std::string& props);

    /**
     * Adds to the list of properties for this Type or Class.
     *
     * @param props  Another instance of PolicyType, the list
     *               of properties for this object will be appended to the current list.
     */
    void addProperties( const PolicyType&  props);

    /**
     * Get a named property.
     *
     * @param name  The name of the desired property.
     * @return The pointer to the PolicyProperty for the given name, NULL if the named property does not exist.
     */
    Teamcenter::Soa::Common::PolicyProperty* getProperty( const std::string& name ) const;

    /**
     * Returns a list of Modifier names that are set on this PolicyType.
     *
     * @return A vector of modifier names.
     */
    std::vector<std::string>getModifierNames() const;

    /**
     * Returns the value of the named modifier.
     *
     * @param name The name of the desired modifier
     * @return The value true/false of the named modifier. If the modifier does not exist on the PolicyType false will be returned.
     */
    bool getBooleanModifier( const std::string& name )const;

    /**
     * Set the value for a modifier
     *
     * @param name The name of the desired modifier.
     *  Setting a modifier on the PolicyType will apply that modifer to all of
     *  PolicyProperties associated with this PolicyType, unless the modifier is explicitly defined on the PolicyProperty.
     * Legal value are:
     * <UL>
     *    <li> POLICY_MODIFIER_WITH_PROPERTIES
     *    <li> POLICY_MODIFIER_EXCLUDE_UI_VALUE
     *    <li> POLICY_MODIFIER_INCLUDE_MODIFIABLE
     *    <li> POLICY_MODIFIER_AS_ATTRIBUTE
     *</UL>
     * @param value true/false value to set the modifier to.
     *
     * @see PolicyProperty for complete definiton of the modifiers.
     */
    void setModifier( const std::string& name, bool value );

    bool operator ==(const PolicyType& that) const;
    bool operator !=(const PolicyType& that) const {return !operator==(that);}
    bool operator  >(const PolicyType& that) const; //needed for std::set
    bool operator  <(const PolicyType& that) const; //needed for std::set


    SOA_CLASS_NEW_OPERATORS


private:



    void mergeModifiers(PolicyProperty *policyProperty );

 

    void eraseFromSet( const std::string& propName);


    std::string            mName;
    std::map<std::string,std::string>   mTypeModifiers;
    std::set<Teamcenter::Soa::Common::PolicyProperty> mProperties;




};

typedef PolicyType  ObjectProperties;


}}} // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
