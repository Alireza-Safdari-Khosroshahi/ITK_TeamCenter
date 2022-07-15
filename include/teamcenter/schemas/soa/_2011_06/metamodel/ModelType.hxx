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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_MODELTYPE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_MODELTYPE_HXX


#include <vector>
#include <string>
#include <set>
#include <ostream>
#include <new> // for size_t

#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/xml/BaseObject.hxx>
#include <teamcenter/soa/common/xml/XmlUtils.hxx>
#include <teamcenter/soa/common/xml/XmlStream.hxx>
#include <teamcenter/soa/common/xml/JsonStream.hxx>

#include <teamcenter/schemas/soa/_2011_06/metamodel/PropertyDescriptor.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/Constant.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/RevNameRule.hxx>


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_exports.h>

namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2011_06
            {
                namespace Metamodel
                {

                    class ModelType;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ModelType> > ModelTypeArray;
                    class PropertyDescriptor;
                    class Constant;
                    class RevNameRule;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ModelType(   );


    std::string& getTypeHierarchy() ;
    const std::string& getTypeHierarchy() const;
    void setTypeHierarchy( const std::string& typeHierarchy );
    bool isTypeHierarchySet() const;
    void setIsTypeHierarchySet( bool flag );
    std::string& getParentTypeName() ;
    const std::string& getParentTypeName() const;
    void setParentTypeName( const std::string& parentTypeName );
    std::string& getDisplayName() ;
    const std::string& getDisplayName() const;
    void setDisplayName( const std::string& displayName );
    bool isDisplayNameSet() const;
    void setIsDisplayNameSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    std::string& getClassName() ;
    const std::string& getClassName() const;
    void setClassName( const std::string& className );
    std::string& getOwningType() ;
    const std::string& getOwningType() const;
    void setOwningType( const std::string& owningType );
    bool isOwningTypeSet() const;
    void setIsOwningTypeSet( bool flag );
    std::string& getTypeUid() ;
    const std::string& getTypeUid() const;
    void setTypeUid( const std::string& typeUid );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& getPropertyDescriptorArray() const;
    void setPropertyDescriptorArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& propertyDescriptors );
    void addPropertyDescriptor( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor>& propertyDescriptor );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant> >& getConstantArray() const;
    void setConstantArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant> >& constants );
    void addConstant( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant>& constant );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RevNameRule> >& getRevNameRuleArray() const;
    void setRevNameRuleArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RevNameRule> >& revNameRules );
    void addRevNameRule( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RevNameRule>& revNameRule );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ModelType" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ModelType* reallyClone();

         std::string   m_typeHierarchy;
    bool   m_typeHierarchy_isSet;
    std::string   m_parentTypeName;
    std::string   m_displayName;
    bool   m_displayName_isSet;
    std::string   m_name;
    std::string   m_uid;
    std::string   m_className;
    std::string   m_owningType;
    bool   m_owningType_isSet;
    std::string   m_typeUid;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >   m_propertyDescriptors;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant> >   m_constants;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RevNameRule> >   m_revNameRules;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

