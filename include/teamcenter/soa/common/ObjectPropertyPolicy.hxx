// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.




#ifndef INCLUDE_TEAMCENTER_SOA_COMMON_OBJECTPROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_COMMON_OBJECTPROPERTYPOLICY_HXX

#include <string>
#include <map>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/PolicyType.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>



namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {

/**
 * The Object Property Policy is a list of Teamcenter types and classes, and properties associated with those types.
 * The properties defined in a parent type are inherited by child types. The Object Property Policy defines which properties
 * are returned from a service operation for a given object type. The business logic of a service operation determines what
 * Business Objects are returned while the Object Property Policy determines which properties will be returned on each
 * Business Object instance. This allows the client application to determine how much or how little data is returned
 * based on how the client application will use those returned Business Objects. The policy is applied uniformly to all
 * service operations. The client application manages what policy is to be used at any given time during the session
 */
class  TCSOACOMMON_API ObjectPropertyPolicy
{
public:
     ObjectPropertyPolicy();
    ~ObjectPropertyPolicy();

 
 
    /**
     * Add a single PolicyType to the list of objects.
     * Property modifiers (i.e. POLICY_MODIFIER_WITH_PROPERTIES) that exist on the ObjectPropetyPolicy will be applied
     * to the PolicyType if the PolicyType does not have that modifier explicitly defined. If the source properties on PolicyType
     * already exists in the ObjectPropertyPolicy, all modifiers on those properties will be lost and only the modifiers from the
     * input/ObjectPropetyPolicy will be applied.<br>
     *
     * @param object    The PolicyType to add.
     **/
     void addType( Teamcenter::Soa::Common::PolicyType& object);

    /**
     * Add a single PolicyType to the list of objects.
     *
     * @param name    The name of the Type or Class to add, an instance of a PolicyType will be created internally.
     **/
    void addType(const std::string& name);

    /**
     * Add a single PolicyType with a list of property names to the list of objects.
     * Property modifiers (i.e. POLICY_MODIFIER_WITH_PROPERTIES) that exist on the ObjectPropetyPolicy will be applied
     * to the named properties. If the source properties already exists in the ObjectPropertyPolicy, all modifiers on those properties
     * will be lost and only the modifiers from the ObjectPropetyPolicy will be applied.<br>
     *
     * @param name    The name of the Type or Class to add, an instance of a PolicyType will be created internally.
     * @param props   A set of Property Names
     **/
    void addType(const std::string& name, const std::set<std::string>& props);

   /**
     * Returns the value of the named modifier.
     *
     * @param name The name of the desired modifier
     * @return The value true/false of the named modifier. If the modifier does not exist on the ObjectPropertyPolicy false will be returned.
     */
    bool getBooleanModifier( const std::string& name )const;

    /**
     * Set the value for a modifier
     *
     * @param name The name of the desired modifier. 
     *  Setting a modifier on the ObjectPropertyPolicy will apply that modifier to all of 
     *  PolicyTypes associated with this ObjectPropertyPolicy, unless the modifier is explicitly defined on the PolicyTypes.
     * Legal value are:
     * <UL>
     *    <li> POLICY_MODIFIER_WITH_PROPERTIES     
     *    <li> POLICY_MODIFIER_EXCLUDE_UI_VALUE    
     *    <li> POLICY_MODIFIER_EXCLUDE_MODIFIABLE  
     *</UL>
     * @param value true/false value to set the modifier to.
     *
     * @see PolicyProperty for complete definiton of the modifiers.
     */
    void setModifier( const std::string& name, bool value );
      
    
    /**
     * Returns a list of Modifier names that are set on this ObjectPropertyPolicy.
     *
     * @return A vector of modifier names.
     */
    std::vector<std::string> getModifierNames() const;


    /**
     * Returns a list of PolicyType names that are set on this ObjectPropertyPolicy.
     *
     * @return A vector of PolicyType names.
     */
    std::vector<std::string> getTypeNames() const;

    /**
     * Returns the list of PolicyTypes.
     * @return Set of PolicyTypes.
     */
    std::set<Teamcenter::Soa::Common::PolicyType>&  getTypes();

    /**
     * Returns the list of PolicyTypes.
     * @return Set of PolicyTypes.
     */
    const std::set<Teamcenter::Soa::Common::PolicyType>&  getTypes() const ;

    /**
     * Returns the a named PolicyType.
     *    
     * @param name The name of the desired PolicyType. 
     * @return  The pointer to the PolicyType for the given name, NULL if the named type does not exist.
     */
    Teamcenter::Soa::Common::PolicyType* getType( const std::string& name ) const;



    /**
     * Returns the list of PolicyTypes.
     * @return Set of PolicyTypes.
     */
     bool  removeType(const std::string& name);
         
     /**
      * Remove the properties from the given type.
      * If the source PolicyType defines a type with no properties, the whole type is removed.
      *
      * @param type PolicyType with desired properties to remove.
      * @return true if the properties were found and removed.
      */
     bool  removeProperties(const Teamcenter::Soa::Common::PolicyType& type );

     /**
     * Saves the current instance of the policy to file.
     *    
     * @param filePath  Target file name with path. 
     * @throws IOException if the save fails then throws IOException.
     */
     void save(const std::string &filePath);
   
     /**
     * Loads the ObjectPropertyPolicy from the XML file specified.
     * The format of the XML file is as per the policy schema. Please refer Teamcenter Services
     * Guide for more information.
     *
     * Property modifiers (i.e.POLICY_MODIFIER_WITH_PROPERTIES) that exist on the ObjectPropetyPolicy will be applied
     * to the data read from the file. If the source properties in the file already exists in the ObjectPropertyPolicy, all modifiers
     * on those properties will be lost and only the modifiers from the source file will be applied.<br>
     *
     * @param filePath  filename with complete path to read.
     * @throws IOException if the load fails then throws IOException.
     */
     void load(const std::string &filePath);

    bool operator ==(const ObjectPropertyPolicy& that) const;
    bool operator !=(const ObjectPropertyPolicy& that) const {return !operator==(that);}

    SOA_CLASS_NEW_OPERATORS

private:
    void mergeModifiers( PolicyType& policyType );
    void createDir(std::string filePath) const;


    std::map<std::string,std::string>               mPolicyModifiers;   
    std::set<Teamcenter::Soa::Common::PolicyType>   mPolicyTypes;

};        // End Class
}}}       // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
