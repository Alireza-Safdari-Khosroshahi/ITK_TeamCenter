// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_TYPEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_TYPEIMPL_HXX

#include <string>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/internal/PropertyDescriptionImpl.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>


#define TYPEIMPL_UNKNOWN_TYPE_UID    "TYPE::UnknownType::UnknownClass::UnknownParent"
#define TYPEIMPL_UNKNOWN_TYPE_NAME   "UnknownModelObjectName"
#define TYPEIMPL_UNKNOWN_TYPE_CLASS  "UnknownModelObjectClass"
#define TYPEIMPL_UNKNOWN_TYPE        "unknownType"

// This is implementing the deprecated isMatchType method,
// when the method is removed from interface, remove it from here, and this pragma push
#pragma warning ( push )
#pragma warning (  disable : 4996  ) 

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TypeImpl : public virtual Type
{
public:



    TypeImpl( const std::string& uid,       const std::string& typeUid,   
              const std::string& name,      const std::string& displayName, 
              const std::string& className, const std::vector<std::string>& classNameHierarchy,
              Type* parent,  const std::string& owningType, 
              const std::map<std::string,PropertyDescription*>& properties,
              const std::map<std::string,std::string>& constants, 
              ConditionChoices* revRules,
              RevisionRuleCategory ruleCategory );

    virtual ~TypeImpl();

    virtual Teamcenter::Soa::Client::PropertyDescription* getPropertyDescription( const std::string& name );
    virtual const std::string& getUid( );
    virtual const std::string& getName();
    virtual Type* getParentType();
    virtual const std::string& getUIFValue();
    virtual bool isMatchType();
    virtual const std::string& getClassName ();
    virtual const std::string& getTypeUid();
    virtual std::map<std::string, Teamcenter::Soa::Client::PropertyDescription*> getPropertyDescriptions();
    virtual const std::vector<std::string>& getClassNameHierarchy();    
    virtual bool isInstanceOf( const std::string& className );

    virtual std::string  getConstant( const std::string&  name);
    virtual std::string getOwningType();
    virtual std::map<std::string,std::string>  getConstants( );
    virtual RevNameRule* getRevisionNamingRule();
    virtual RevisionRuleCategory getRevisionNamingRuleCategory() const;



    SOA_CLASS_NEW_OPERATORS

private:
    TypeImpl(); // do not allow use of default


    std::string     m_name;
    std::string     m_uid;
    Type*           m_parent;
    std::string     m_uifValue;
    std::string     m_className;
    std::string     m_typeUid;
    bool            m_isMatchType;
    std::vector<std::string>    m_classNameHierarchy;
    std::map<std::string, Teamcenter::Soa::Client::PropertyDescription*>     m_propDescMap;
    std::string     m_owningType;
    std::map<std::string,std::string>   m_constants;
    ConditionChoices*   m_revRules;
    RevisionRuleCategory m_ruleCategory;

    bool isInstance ( const std::string& className );


};

}}} //end namespace

#pragma warning ( pop )

#endif
