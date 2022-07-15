// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_DEFAULTOBJECTFACTORY_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_DEFAULTOBJECTFACTORY_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ObjectFactory.hxx>
#include <teamcenter/soa/client/ModelObjectFactory.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>




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
class  DefaultObjectFactory : public ObjectFactory
{
public:

    DefaultObjectFactory();
    ~DefaultObjectFactory();




    static void registerModelObjectFactory( std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >* objectFactory);

    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>    constructModelObject(
                                    Type* type,
                                    const std::string& uid
                                    );
    virtual Property*       addProperty(
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObj,
                                    PropertyDescription*  propertyDescription,
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property> xmlProperty,
                                    ClientDataModel* clientDataModel
                                    );
    virtual void            addProperty(
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObj,
                                    const std::string& name,
                                    const std::vector<std::string>& values
                                    );
    virtual bool            refineType(
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObject,
                                    Type* newType
                                    );
    virtual ServiceData     constructServiceData(
                                    ClientDataModel* clientDataModel,
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> xmlServiceData,
                                    std::vector<ErrorStack> partialErrors
                                    );
    virtual ErrorStack      constructPartialError(
                                    ClientDataModel* clientDataModel,
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack> xmlPartialError
                                    );
    virtual PartialErrors   constructPartialErrors(
                                    const std::vector<ErrorStack>& partialErrors
                                    );
    virtual Preferences     constructPreferences(
                                    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Preferences> xmlPreferences
                                    );
    virtual Type*           constructType(
                                    const std::string& uid,       const std::string& typeUid,
                                    const std::string& name,      const std::string& displayName,
                                    const std::string& className, const std::vector<std::string>& classNameHierarchy,
                                    Type* parent,  const std::string& owningType,
                                    const std::map<std::string,PropertyDescription*>& properties,
                                    const std::map<std::string,std::string>& constants,
                                    ConditionChoices* revRules,
                                    Type::RevisionRuleCategory ruleCategory
                                    );
    virtual RevNameRule*    constructRevNameRule(
                                    const std::string& name,
                                    const std::string& initStart,   const std::string& initDescription,   RevNameRule::RuleType initType,
                                    const std::string& secondStart, const std::string& secondDescription, RevNameRule::RuleType secondType,
                                    bool excludeLetters, const std::string& skipLetters,
                                    RevNameRule::AlphabeticCase alphaCase, RevNameRule::SupplementalRuleType suppRuleType
                                    );
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
                    BasedOn* basedOn
                                    );
    virtual NamingRule*     constructNamingRule(
                                    const std::string& pattern, NamingRule::RuleCase caze,
                                    const std::vector<RulePattern*>& patterns
                                    );

    virtual RulePattern*    constructeRulePattern( const std::string& pattern, bool autoGen, int initVal, int maxVal );

    virtual BasedOn*        constructBasedOn( const std::string& sourceType, const std::string& sourceProperty );

    virtual LovValue*       constructLovValue(
                                    const std::string& value,       const std::string& dislayValue,
                                    const std::string& description, const std::string& displayDescription,
                                    ConditionChoices*   childLovChoices,
                                    int valueType, ClientDataModel* clientDataModel
                                    );
    virtual LovInfo*        constructLovInfo(
                                    const std::string& uid,
                                    const std::string& name,        const std::string& displayName,
                                    const std::string& description, const std::string& displayDescription,
                                    Type* type, int lovValueType, LovInfo::Usage usage,
                                    const std::vector<std::string>& typeNames,
                                    const std::vector<std::string>& propNames,
                                    const std::vector<int>&         specifiers,
                                    ConditionChoices*  valueChoices
                                    );
   virtual Lov*             constructLov(
                                    Lov::Style style,
                                    const std::vector<std::string>& dependProps,
                                    const std::vector<Lov::Style>& dependStyles,
                                    const std::string& uid,
                                    int specifier,
                                    LovInfo* info
                                    );
   virtual DatasetType*     constructDatasetType(
                                    const std::string& uid,       const std::string& typeUid,
                                    const std::string& name,      const std::string& displayName,
                                    const std::string& className, const std::vector<std::string>& classNameHierarchy,
                                    Type* parent, const std::string& owningType,
                                    const std::map<std::string,PropertyDescription*>& properties,
                                    const std::map<std::string,std::string>& constants,
                                    ConditionChoices* revRules, Type::RevisionRuleCategory ruleCategory,
                                    const std::vector<Tool*>& viewTools,
                                    const std::vector<Tool*>& editTools,
                                    const std::vector<Reference*>& references
                                    );
   virtual Tool*            constructTool(
                                    const std::string& name,  const std::string&  description,
                                    const std::vector<std::string>& inputFormats,
                                    const std::vector<std::string>& outputFormats,
                                    const std::string& launchCommandMac ,
                                    const std::string& mimeType,
                                    const std::string& packageName,
                                    const std::string& releaseDate,
                                    const std::string& symbol,
                                    const std::string& vendorName,
                                    const std::string&version,
                                    bool callbackEnabled,
                                    bool digitalSignatureCapable,
                                    bool downloadRequired,
                                    bool embedApplication,
                                    bool markupCapable,
                                    bool viewCapable,
                                    bool vviRequired,
                                    const std::vector<ToolAction*>& actions
                                    );
   virtual ToolAction*      constructToolAction(
                                    const std::string& name,
                                    const std::map<std::string,ActionReference*>& references
                                    );
   virtual ActionReference*   constructActionReference(
                                    const std::string& name,
                                    bool exportFlag,
                                    Reference *reference
                                    );
   virtual Reference*   constructReference(
                                    const std::string& name,
                                    const std::vector<std::string>& templates,
                                    const std::vector<std::string>& formats
                                    );




   SOA_CLASS_NEW_OPERATORS


private:
    typedef Teamcenter::Schemas::Soa::_2006_03::Base::RefIdArray XsdRefIdArray;

    static std::map< std::string, ModelObjectFactory* >* s_objectFactoryMap;

    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>    constructObjectOfType( Type* type );
    void            loadRefIdArray( const XsdRefIdArray& ids, ModelObjectVector& objs, ClientDataModel* clientDataModel ) const;

};
}}}//end namespace


#endif

