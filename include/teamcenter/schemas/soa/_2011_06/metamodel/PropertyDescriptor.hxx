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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_PROPERTYDESCRIPTOR_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_PROPERTYDESCRIPTOR_HXX


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

#include <teamcenter/schemas/soa/_2011_06/metamodel/LovReference.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/NamingRule.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/BasedOn.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/Constant.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/Renderer.hxx>


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

                    class PropertyDescriptor;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<PropertyDescriptor> > PropertyDescriptorArray;
                    class LovReference;
                    class NamingRule;
                    class BasedOn;
                    class Constant;
                    class Renderer;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    PropertyDescriptor(   );


    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    int getMaxLength() const;
    void setMaxLength( int maxLength );
    bool isMaxLengthSet() const;
    void setIsMaxLengthSet( bool flag );
    int getPropertyType() const;
    void setPropertyType( int propertyType );
    int getLovCategory() const;
    void setLovCategory( int lovCategory );
    std::string& getCompoundObjType() ;
    const std::string& getCompoundObjType() const;
    void setCompoundObjType( const std::string& compoundObjType );
    bool isCompoundObjTypeSet() const;
    void setIsCompoundObjTypeSet( bool flag );
    int getValueType() const;
    void setValueType( int valueType );
    int getMaxArraySize() const;
    void setMaxArraySize( int maxArraySize );
    bool isMaxArraySizeSet() const;
    void setIsMaxArraySizeSet( bool flag );
    int getFieldType() const;
    void setFieldType( int fieldType );
    bool isFieldTypeSet() const;
    void setIsFieldTypeSet( bool flag );
    std::string& getMaxValue() ;
    const std::string& getMaxValue() const;
    void setMaxValue( const std::string& maxValue );
    bool isMaxValueSet() const;
    void setIsMaxValueSet( bool flag );
    bool getAnArray() const;
    void setAnArray( bool anArray );
    std::string& getMinValue() ;
    const std::string& getMinValue() const;
    void setMinValue( const std::string& minValue );
    bool isMinValueSet() const;
    void setIsMinValueSet( bool flag );
    std::string& getDisplayName() ;
    const std::string& getDisplayName() const;
    void setDisplayName( const std::string& displayName );
    bool isDisplayNameSet() const;
    void setIsDisplayNameSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovReference> >& getLovArray() const;
    void setLovArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovReference> >& lovs );
    void addLov( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovReference>& lov );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::NamingRule> >& getNamingRuleArray() const;
    void setNamingRuleArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::NamingRule> >& namingRules );
    void addNamingRule( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::NamingRule>& namingRule );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::BasedOn>& getBasedOn() ;
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::BasedOn>& getBasedOn() const;
    void setBasedOn( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::BasedOn>& basedOn );
    bool isBasedOnSet() const;
    void setIsBasedOnSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant> >& getConstantArray() const;
    void setConstantArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant> >& constants );
    void addConstant( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant>& constant );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Renderer> >& getRendererArray() const;
    void setRendererArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Renderer> >& renderers );
    void addRenderer( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Renderer>& renderer );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "PropertyDescriptor" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual PropertyDescriptor* reallyClone();

         std::string   m_name;
    int   m_maxLength;
    bool   m_maxLength_isSet;
    int   m_propertyType;
    int   m_lovCategory;
    std::string   m_compoundObjType;
    bool   m_compoundObjType_isSet;
    int   m_valueType;
    int   m_maxArraySize;
    bool   m_maxArraySize_isSet;
    int   m_fieldType;
    bool   m_fieldType_isSet;
    std::string   m_maxValue;
    bool   m_maxValue_isSet;
    bool   m_anArray;
    std::string   m_minValue;
    bool   m_minValue_isSet;
    std::string   m_displayName;
    bool   m_displayName_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovReference> >   m_lovs;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::NamingRule> >   m_namingRules;
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::BasedOn>   m_basedOn;
    bool   m_basedOn_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Constant> >   m_constants;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Renderer> >   m_renderers;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

