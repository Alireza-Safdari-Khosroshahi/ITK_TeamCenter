// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_OBJECTFACTORY_HXX
#define TEAMCENTER_SOA_CLIENT_OBJECTFACTORY_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/Lov.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/ErrorStack.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>
#include <teamcenter/soa/client/PropertyDescription.hxx>
#include <teamcenter/soa/client/RevNameRule.hxx>
#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/NamingRule.hxx>
#include <teamcenter/soa/client/RulePattern.hxx>
#include <teamcenter/soa/client/BasedOn.hxx>
#include <teamcenter/soa/client/Tool.hxx>
#include <teamcenter/soa/client/DatasetType.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>

#include <teamcenter/schemas/soa/_2006_03/base/ServiceData.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ErrorStack.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/Preferences.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/Property.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
/**
 * This class is responsible for constructing object for the Client Meta Model
 * and Client Data Model.
 */
class TCSOACLIENTMNGD_API ObjectFactory
{
public:





    /**
     * Register an implementation of the ObjectFactor. There will only be one
     * factory in the application space.
     *
     * @param factory   The ObjectFactory
     */
    static void registerObjectFactory(ObjectFactory* factory );

    /**
     *
     * @return The object factory
     */
    static ObjectFactory* getObjectFactory( );

    virtual ~ObjectFactory();


    /**
     * Construct an instance of the ModelObject interface.
     *
     *
     * @param type  The type of ModelObject to create.
     * @param uid   The UID of the ModelObject to create.
     *
     * @return  An instance of a ModelObject.
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructModelObject( Type* type, const std::string& uid )=0;


    /**
     * Add a Property to an existing instance of a ModelObject.
     *
     *
     * @param modelObj              The ModelObject to add the property to.
     * @param propertyDescription   The description of the property to add.
     * @param xmlProperty           The XSD/XML representation of the Property.
     * @param clientDataModel       The ClientDataModel to resolve referenced UIDs to actual objects
     * @return The Property instance.
     */
    virtual Property* addProperty(Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObj, PropertyDescription*  propertyDescription,
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property> xmlProperty,
                            ClientDataModel* clientDataModel )=0;

    /**
     * Add a Property to an existing instance of a ModelObject.
     *
     *
     * @param modelObj              The ModelObject to add the property to.
     * @param name                  The Name of the property.
     * @param values                The values of the property.
     */
    virtual void addProperty( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObj, const std::string& name, const std::vector<std::string>& values)=0;


    /**
     * Update or refine the type that describes a given ModelObject
     *
     * @param modelObject   The object to update.
     * @param newType       The new type of the object
     * @return              true if the object is updated.
     */
    virtual bool refineType( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObject, Type* newType )=0;



    /**
     * Construct an instance of the ServiceData interface.
     *
     *
     * @param clientDataModel   The ClientDataModel to resolve referenced UIDs to actual objects
     * @param xmlServiceData    The XSD/XML representation of the ServiceData
     * @param partialErrors
     * @return                  An instance of ServiceData

     */
    virtual ServiceData constructServiceData( ClientDataModel* clientDataModel,
                Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> xmlServiceData,
                std::vector<ErrorStack> partialErrors ) =0;

    /**
     * Construct an instance of ErrorStack.
     *
     * @param clientDataModel   The ClientDataModel to resolve referenced UIDs to actual objects
     * @param xmlPartialError   The XSD/XML representation of the partial error
     *
     * @return                  An instance of ErrorStack
     */
    virtual ErrorStack constructPartialError( ClientDataModel* clientDataModel,
                Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack> xmlPartialError )=0;

    /**
     * Construct an instance of PartialErrors.
     *
     * @param partialErrors  The array of partial errors
     * @return  An instance of PartialErrors
     */
    virtual PartialErrors constructPartialErrors( const std::vector<ErrorStack>& partialErrors )=0;

    /**
     * Construct an instance of Preferences.
     *
     * @param xmlPreferences  The XSD/XML representation of the preferences
     * @return  An instance of Preferences
     */
    virtual Preferences constructPreferences(Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Preferences> xmlPreferences )=0;



    /**
     * Construct an instance of the Type interface.
     *
     *
     * @param uid                   The Unique Identifier of the Business Model type or class. This has the syntax of
     *                              "TYPE:&lt;typeName&gt;:&lt;ClassName&gt;:&lt;ParentTypeName&gt;"
     *                              (i.e. TYPE::User::User::POM_user, TYPE::Newstuff Folder::Folder::Folder).
     * @param typeUid               The Unique Identifier of the Business Model type. This has the syntax of
     *                              "TYPE:&lt;typeName&gt;:&lt;ClassName&gt;:&lt;ParentTypeName&gt;"
     *                              (i.e. TYPE::ImanType::ImanType::POM_object, TYPE::ImanType::ImanType::POM_object).
     * @param name                  The name of the type (i.e. User, Newstuff Folder).
     * @param displayName           The localized name.
     * @param className             The class name (i.e. User, Folder).
     * @param classNameHierarchy    An array of class names representing the type hierarchy
     * @param parent                The parent Type,
     * @param owningType            The Owning Type name of a Create Descriptor Type
     * @param properties            The list of property descriptions
     * @param constants             The list of type constants
     * @param revRules              Revision Naming Rule
     * @param ruleCategory          The category of the Revision Naming Rule
     * @return                      An instance of Type
     */
    virtual Type* constructType(
                            const std::string& uid,       const std::string& typeUid,
                            const std::string& name,      const std::string& displayName,
                            const std::string& className, const std::vector<std::string>& classNameHierarchy,
                            Type* parent,  const std::string& owningType,
                            const std::map<std::string,PropertyDescription*>& properties,
                            const std::map<std::string,std::string>& constants,
                            ConditionChoices* revRules,
                            Type::RevisionRuleCategory ruleCategory
                            )=0;


    /**
     * @param name           The name of the Revision Naming Rule
     * @param initStart             The starting value for the Initial Revision rule.
     * @param initDescription       The description for the Initial Revision rule.
     * @param initType              The type for the Initial Revision rule.
     * @param secondStart           The starting value for the Secondary Revision rule.
     * @param secondDescription     The description for the Secondary Revision rule.
     * @param secondType            The type for the Secondary Revision rule.
     * @param excludeLetters        Exclude defined letters from revisions
     * @param skipLetters           List of letters to excluded
     * @param alphaCase             The alphabetic case of the Initial, Secondary and Supplemental rules
     * @param suppRuleType          The type of the Supplemental Revision rule.
     * @return  The Revision Naming Rule
     */
    virtual RevNameRule* constructRevNameRule(const std::string& name,
            const std::string& initStart,   const std::string& initDescription,   RevNameRule::RuleType initType,
            const std::string& secondStart, const std::string& secondDescription, RevNameRule::RuleType secondType,
            bool excludeLetters, const std::string& skipLetters,
            RevNameRule::AlphabeticCase alphaCase, RevNameRule::SupplementalRuleType suppRuleType )=0;


    /**
     * Construct and instance of PropertyDiscription and add it to the Type.
     *
     * @param typeUid           The UID of the parent Type object.
     * @param name              The property name (i.e. os_username, contents).
     * @param displayName       The localized version of the name.
     * @param propertyType      The property type (ptype). This is defined on the server with the enum PROP_type_t
     *                          <UL>
     *                              <LI>0: Property type is Unknown
     *                              <LI>1: Based on a POM Attribute (int, string, ...)
     *                              <LI>2: Based on a POM Reference
     *                              <LI>3: Based on an ImanRelation
     *                              <LI>4: Based on a property from another Type
     *                              <LI>5: Based on a computed value
     *                              <LI>6: Based on the source property on a BO
     *                          </UL>
     * @param valueType         The property value type. This is defined on the server with the enum PROP_value_type_t
     *                          <UL>
     *                              <LI>0: No Value type
     *                              <LI>1: Value is a single character (byte)
     *                              <LI>2: Value is a date
     *                              <LI>3: Value is a double
     *                              <LI>4: Value is a float
     *                              <LI>5: Value is an integer
     *                              <LI>6: Value is a logical
     *                              <LI>7: Value is a short
     *                              <LI>8: Value is a character string
     *                              <LI>9: Value is a typed reference
     *                              <LI>10: Value is an untyped reference
     *                              <LI>11: Value is an external reference
     *                              <LI>12: Value is a note
     *                              <LI>13: Value is a typed relation
     *                              <LI>14: Value is an untyped relation
     *                          </UL>
     * @param isArray           True if the property has an array of values.
     * @param maxLength         If the property is a string, this is the maximum length the value may be.
     * @param maxArraySize      If the property is an array, this is the maximum number of values this property may have.
     * @param fieldType         Property used for OperationInput Dialog (e.g. Create Descriptor)
     *                          This is defined on the server with the enum PROP_field_type_t
     *                          <UL>
     *                              <LI>0: Field type is unknown
     *                              <LI>1: Simple property
     *                              <LI>2: Compound object
     *                              <LI>3: Compound relation
     *                          </UL>
     * @param compoundObjType   The UID of the compound object type if the fieldType of the property is Compound object.
     * @param lovs              LOVs
     * @param lovCategory       Defines categories of LOVs attached to the property.
     *                          <UL>
     *                              <LI>0:  No attachments
     *                              <LI>1:  Only isTrue condition is attached
     *                              <LI>2:  Only Session Based Conditions are attached
     *                              <LI>3:  One or More Object Based Conditions are attached
     *                          </UL>
     * @param constants         Map of description constants, valid keys:
     *                          <UL>
     *                              <LI>modifiable:      True ("1") if the property can be modified.
     *                              <LI>displayable:     True ("1") if the property can be displayed.
     *                              <LI>enabled:         True ("1") if this property is enabled.
     *                              <LI>required:        True ("1") if this property is required.
     *                              <LI>localizable:     True ("1") if this property can be localized.
     *                              <LI>initialValue     The initial or default value of this property. If not defined this key is not present.
     *                          </UL>
     * @param namingRules       Naming Rules
     * @param renderers         Property Renderers
     * @param ruleCategory      Category of Nameing Rules
     * @param minValue          The minimum allowable value of the property.
     * @param maxValue          The maximum allowable value of the property.
     * @param basedOn           The based-on property information, may be null
     * @return the PropertyDescipiton instance
     */
     virtual PropertyDescription* constructPropertyDescription(
                                                 const std::string& typeUid,
                                                 const std::string& name, const std::string& displayName,
                                                 int propertyType,        int valueType,
                                                 int maxLength,
                                                 bool isArray,            int maxArraySize,
                                                 int fieldType,           const std::string& compoundObjType,
                                                 ConditionChoices* lovs,  int lovCategory,
                                                 const std::map<std::string,std::string>& constants,
                                                 ConditionChoices* namingRules,
                                                 ConditionChoices* renderers,
                                                 PropertyDescription::RuleCategory ruleCategory,
                                                 const std::string& minValue, const std::string& maxValue,
                         BasedOn*      basedOn
                                                 ) =0;

    /**
     *
     * @param pattern    Name rule patterns of the property name rule.
     * @param caze       Mixed, Lower or Upper case letters
     * @param patterns   Rule patterns
     * @return           The NamingRule
     */
     virtual NamingRule* constructNamingRule( const std::string& pattern, NamingRule::RuleCase caze, 
                                              const std::vector<RulePattern*>& patterns )=0;

   /**
     *
     * @param pattern   The pattern
     * @param autoGen   True if the rule has an auto-generated pattern
     * @param initVal   The initial value of a the auto-generated counter.
     * @param maxVal    The maximum value of a the auto-generated counter.
     *
     * @return The RulePattern
     */
     virtual RulePattern* constructeRulePattern( const std::string& pattern, bool autoGen, int initVal, int maxVal ) =0;


    /**
     * Construct and instance of BasedOn.
     *
     * @param sourceType        The name of the based-on type.
     * @param sourceProperty    The name of the based-on property.
     * @return The BasedOn
     */
    virtual BasedOn* constructBasedOn( const std::string& sourceType, const std::string& sourceProperty )=0;


    /**
     * @param value             The value
     * @param dislayValue       The localized value (may be null).
     * @param description       The  element's description (may be null)
     * @param displayDescription The element's displayable description (may be null)
     * @param childLovChoices   A set of LovInfos that can be used for the next level of LOVs for Interdependent or Coordinated LOV.
     * @param valueType         The value type of the LOV value
     * @param clientDataModel   The current ClientDataModel
     * @return  The LOV instance
     */
    virtual LovValue* constructLovValue( const std::string& value, const std::string& dislayValue,
                                         const std::string& description, const std::string& displayDescription,
                                         ConditionChoices*   childLovChoices,
                                         int valueType, ClientDataModel* clientDataModel )=0;




    /**
     *
     * @param uid          The UID of this List of Values.  (14 character database UID)
     * @param name         The name of the LOV.
     * @param displayName  The localized name of the LOV
     * @param description  The description of this LOV.
     * @param displayDescription  The localized description of this LOV.
     * @param type         The Type of this LOV.
     * @param lovValueType The value type as defined by the associated property description
     * @param usage        The LOV's usage type - Exhaustive, Suggestive, Range
     * @param typeNames    All the Type names associated with this LOV
     * @param propNames    All the Property names associated with this LOV
     * @param specifiers   All the specifiers associated with this LOV
     * @param valueChoices The values
     * @return The LovInfo
     */
    virtual LovInfo* constructLovInfo( const std::string& uid, const std::string& name, const std::string& displayName,
                                       const std::string& description, const std::string& displayDescription,
                                       Type* type, int lovValueType, LovInfo::Usage usage,
                                       const std::vector<std::string>& typeNames,
                                       const std::vector<std::string>&  propNames, const std::vector<int>& specifiers,
                                       ConditionChoices*  valueChoices)=0;



   /**
    * @param style             The style of the LOV, Standard, Interdependent, Hierarchical, Coordinated or Description
    * @param dependProps       List of PropertyDescriptors that an Interdependent LOV is dependent on.
    * @param dependStyles      List of Sytels that an Interdependent LOV is dependent on.
    * @param uid               The UID of the LOV
    * @param specifier         The specifier
    * @param info              The LovInfo data
    * @return                  The LOV
    */
    virtual Lov* constructLov( Lov::Style style, const std::vector<std::string>& dependProps,  const std::vector<Lov::Style>& dependStyles, const std::string& uid, int specifier, LovInfo* info)=0;





   /**
    * Construct an instance of the DatasetType interface.
    *
    *
    * @param uid                   The Unique Identifier of the Business Model type or class. This has the syntax of
    *                              "TYPE:&lt;typeName&gt;:&lt;ClassName&gt;:&lt;ParentTypeName&gt;"
    *                              (i.e. TYPE::User::User::POM_user, TYPE::Newstuff Folder::Folder::Folder).
    * @param typeUid               The Unique Identifier of the Business Model type. This has the syntax of
    *                              "TYPE:&lt;typeName&gt;:&lt;ClassName&gt;:&lt;ParentTypeName&gt;"
    *                              (i.e. TYPE::ImanType::ImanType::POM_object, TYPE::ImanType::ImanType::POM_object).
    * @param name                  The name of the type (i.e. User, Newstuff Folder).
    * @param displayName           The localized name.
    * @param className             The class name (i.e. User, Folder).
    * @param classNameHierarchy    An array of class names representing the type hierarchy
    * @param parent                The parent Type
    * @param owningType            The Owning Type name of a Create Descriptor Type
    * @param properties            The list of property descriptions
    * @param constants             The list of type constants
    * @param revRules              Revision Naming Rule
    * @param ruleCategory          Category of the Revision Naming Rule
    * @param viewTools             The list of view Tools
    * @param editTools             The list of edit Tools
    * @param references            Dataset references
    * @return                      An instance of DatasetType
    */
   virtual DatasetType* constructDatasetType(
                                    const std::string& uid, const std::string& typeUid,
                                    const std::string& name, const std::string& displayName,
                                    const std::string& className, const std::vector<std::string>& classNameHierarchy,
                                    Type* parent, const std::string& owningType,
                                    const std::map<std::string,PropertyDescription*>& properties,
                                    const std::map<std::string,std::string>& constants,
                                    ConditionChoices* revRules, Type::RevisionRuleCategory ruleCategory,
                                    const std::vector<Tool*>& viewTools, const std::vector<Tool*>& editTools,
                                    const std::vector<Reference*>& references 
                                    )=0;

   /**
    * Construct an instance of Tool interface
    *
    * @param name
    * @param description
    * @param inputFormats
    * @param outputFormats
    * @param launchCommandMac
    * @param mimeType
    * @param packageName
    * @param releaseDate
    * @param symbol
    * @param vendorName
    * @param version
    * @param callbackEnabled
    * @param digitalSignatureCapable
    * @param downloadRequired
    * @param embedApplication
    * @param markupCapable
    * @param viewCapable
    * @param vviRequired
    * @param actions
    * @return           The Tool
    */
   virtual Tool* constructTool( const std::string& name,  const std::string&  description, const std::vector<std::string>& inputFormats,
                       const std::vector<std::string>& outputFormats, const std::string& launchCommandMac , const std::string& mimeType,
                       const std::string& packageName,const std::string& releaseDate,const std::string& symbol,
                       const std::string& vendorName, const std::string&version,bool callbackEnabled,
                       bool digitalSignatureCapable,bool downloadRequired,
                       bool embedApplication,bool markupCapable, bool viewCapable,
                       bool vviRequired, const std::vector<ToolAction*>& actions )=0;

   /**
    * Construct an instance of the ToolAction interface.
    *
    * @param name               The name of the action
    * @param references         A list of References
    * @return                   The instance of ToolAction
    */
   virtual ToolAction* constructToolAction( const std::string& name, const std::map<std::string,ActionReference*>& references )=0;



   /**
    * Construct an instance of the ActionReference interface.
    *
    * @param name          The name
    * @param exportFlag    The export flag
    * @param reference     The reference
    * @return   The ActionReference
    */
   virtual ActionReference* constructActionReference( const std::string& name, bool exportFlag, Reference* reference )=0;

   /**
    * Construct an instance of the Reference interface.
    *
    * @param name        The name
    * @param templates   The templates
    * @param formats     The formats
    * @return   The Reference
    */
   virtual Reference* constructReference( const std::string& name,  const std::vector<std::string>& templates, const std::vector<std::string>& formats )=0;


   SOA_CLASS_NEW_OPERATORS

protected:
    ObjectFactory();

private:
    static ObjectFactory* theObjectFactory;

};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

