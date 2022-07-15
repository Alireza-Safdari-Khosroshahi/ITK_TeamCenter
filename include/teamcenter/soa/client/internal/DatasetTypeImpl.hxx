// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_DATASETTYPEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_DATASETTYPEIMPL_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/DatasetType.hxx>
#include <teamcenter/soa/client/internal/TypeImpl.hxx>



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



class DatasetTypeImpl: public TypeImpl, public virtual DatasetType
{
public:


    /**
     * Constructor
     *
     * @param uid
     * @param typeUid
     * @param name
     * @param displayName
     * @param className
     * @param classNameHierarchy
     * @param parent
     * @param owningType
     * @param properties
     * @param constants
     * @param revRules
     * @param viewTools
     * @param editTools
     * @unpublished
     */
    DatasetTypeImpl(
              const std::string& uid,       const std::string& typeUid,
              const std::string& name,      const std::string& displayName,
              const std::string& className, const std::vector<std::string>& classNameHierarchy,
              Type* parent,  const std::string& owningType,
              const std::map<std::string,PropertyDescription*>& properties,
              const std::map<std::string,std::string>& constants,
              ConditionChoices* revRules, RevisionRuleCategory ruleCategory,
              const std::vector<Tool*>& viewTools,
              const std::vector<Tool*>& editTools,
              const std::vector<Reference*>& references);
    virtual ~DatasetTypeImpl();

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

    virtual std::string     getConstant( const std::string&  name);
    virtual std::string     getOwningType();
    virtual std::map<std::string,std::string>  getConstants( );
    virtual RevNameRule*    getRevisionNamingRule();
    virtual RevisionRuleCategory getRevisionNamingRuleCategory() const;

    virtual std::vector<Tool*> getViewTools();
    virtual std::vector<Tool*> getEditTools();
    virtual Tool* getViewTool( const std::string& name );
    virtual Tool* getEditTool( const std::string& name );
    virtual std::vector<Reference*> getReferences();
    virtual std::vector<std::string> getReferenceNames();
    virtual Reference* getReference( const std::string& name );

    SOA_CLASS_NEW_OPERATORS


private:
    std::vector<Tool*>      mViewTools;
    std::vector<Tool*>      mEditTools;
    std::vector<Reference*> mReferences;

    DatasetTypeImpl();


};

}}}//end namespace

#pragma warning ( pop )

#endif
