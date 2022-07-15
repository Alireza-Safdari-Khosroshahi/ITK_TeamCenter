// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYDESCRIPTIONIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYDESCRIPTIONIMPL_HXX

#include <string>
#include <new>
#include <vector>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/PropertyDescription.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
// Simple class to wrap the Property Renderer Data string
// This allows the dynamic_casting in the ConditionChoice class
class RendererImpl : public Renderer
{
public:
    explicit RendererImpl(const std::string& data );
    ~RendererImpl();
    SOA_CLASS_NEW_OPERATORS

    virtual std::string getRenderData() const;
private:
    RendererImpl(); // Don't allow use of default constructor
    std::string mRenderData;
};


class PropertyDescriptionImpl : public Teamcenter::Soa::Client::PropertyDescription
{
public:


    PropertyDescriptionImpl( 
                const std::string& theTypeUid,
                const std::string& propName,    const std::string& propDisplayName,
                int   propValueType,            int propType2,
                int   maxLength, 
                bool  isArray,int maxArraySize,
                int   fieldType,    const std::string& compoundObjType,
                ConditionChoices* lovs, int lovCategory, RuleCategory ruleCategory,
                const std::map<std::string,std::string>& constants,
                ConditionChoices* namingRules,
                ConditionChoices* renderers,
                const std::string& minValue, const std::string& maxValue,
        BasedOn* basedOn
                );


    ~PropertyDescriptionImpl();

    void setMaxArraySize( const int size );

    virtual const std::string&  getName() const;
    virtual PropertyType        getType() const;
    virtual bool                isArray() const;
    virtual bool                isModifiable() const;
    virtual int                 getMaxArraySize() const;
    virtual int                 getAttachedSpecifier();
    virtual std::string         getLovTypeUid();
    virtual std::string         getLovUid();
    virtual int                 getMaxLength() const;
    virtual std::string         getMaxValue()const;
    virtual std::string         getMinValue() const;

    virtual std::vector<std::string> getPropDependants();
    virtual ServerPropType      getServerType() const;
    virtual ServerPropertyType  getServerPropertyType() const;
    virtual const std::string&  getUiName()const;
    virtual const std::string&  getTypeUid() const;
    virtual bool                isDisplayable() const;
    virtual bool                isEnabled() const;
    virtual bool                isRequired() const;
    virtual bool                isLocalizable() const;
    virtual std::string         getConstant( const std::string&  name) const;
    virtual std::string*        getInitialValue() const;
    virtual FieldType           getFieldType() const;
    virtual std::string         getCompoundObjectType() const;
    virtual CategoryType        getLovCategory() const;
    virtual Lov*                getLovReference();
    virtual std::string         getRootLovPropertyName()const;
    virtual NamingRule*         getNamingRule();
    virtual std::string         getRenderer();
    virtual RuleCategory        getNamingRuleCategory() const;
    virtual BasedOn*            getBasedOn()const;

    static PropertyType propServerTypeToClientType( int t );

    SOA_CLASS_NEW_OPERATORS

private:
    PropertyDescriptionImpl(); //Do not allow use of default
    PropertyDescriptionImpl( const PropertyDescriptionImpl& right);
    PropertyDescriptionImpl& operator = ( const PropertyDescriptionImpl& right);

    std::string                 m_name;
    PropertyType                m_type;
    bool                        m_isArray;
    std::string                 m_uiName;
    std::string                 m_typeUid;
    int                         m_maxLength;
    std::string                 m_minValue;
    std::string                 m_maxValue;
    int                         m_maxArraySize;
    ServerPropType              m_serverType;
    ServerPropertyType          m_serverPropteryType;
    std::string*                m_initialValue;
    FieldType                   m_fieldType;
    std::string                 m_compondObjType;
    CategoryType                m_lovCategory;
    ConditionChoices*           m_lovs;
    std::string                 m_rootPropName;
    ConditionChoices*           m_namingRules;
    ConditionChoices*           m_renderers;
    std::map<std::string,std::string>  m_constants;
    RuleCategory                m_ruleCategory;
    BasedOn*                    m_basedOn;

};
}}} //end namespace

#endif


