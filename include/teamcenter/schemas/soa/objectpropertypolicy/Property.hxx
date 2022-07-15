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

#ifndef TEAMCENTER__SCHEMAS__SOA__OBJECTPROPERTYPOLICY_PROPERTY_HXX
#define TEAMCENTER__SCHEMAS__SOA__OBJECTPROPERTYPOLICY_PROPERTY_HXX


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



#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace Objectpropertypolicy
            {

                    class Property;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<Property> > PropertyArray;

            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::Objectpropertypolicy::Property : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    Property(   );


    std::string& getWithProperties() ;
    const std::string& getWithProperties() const;
    void setWithProperties( const std::string& withProperties );
    bool isWithPropertiesSet() const;
    void setIsWithPropertiesSet( bool flag );
    std::string& getExcludeParentProperties() ;
    const std::string& getExcludeParentProperties() const;
    void setExcludeParentProperties( const std::string& excludeParentProperties );
    bool isExcludeParentPropertiesSet() const;
    void setIsExcludeParentPropertiesSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    std::string& getAsAttribute() ;
    const std::string& getAsAttribute() const;
    void setAsAttribute( const std::string& asAttribute );
    bool isAsAttributeSet() const;
    void setIsAsAttributeSet( bool flag );
    std::string& getUIValueOnly() ;
    const std::string& getUIValueOnly() const;
    void setUIValueOnly( const std::string& uIValueOnly );
    bool isUIValueOnlySet() const;
    void setIsUIValueOnlySet( bool flag );
    std::string& getExcludeUiValues() ;
    const std::string& getExcludeUiValues() const;
    void setExcludeUiValues( const std::string& excludeUiValues );
    bool isExcludeUiValuesSet() const;
    void setIsExcludeUiValuesSet( bool flag );
    std::string& getExcludeIsModifiable() ;
    const std::string& getExcludeIsModifiable() const;
    void setExcludeIsModifiable( const std::string& excludeIsModifiable );
    bool isExcludeIsModifiableSet() const;
    void setIsExcludeIsModifiableSet( bool flag );
    std::string& getIncludeIsModifiable() ;
    const std::string& getIncludeIsModifiable() const;
    void setIncludeIsModifiable( const std::string& includeIsModifiable );
    bool isIncludeIsModifiableSet() const;
    void setIsIncludeIsModifiableSet( bool flag );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "Property" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual Property* reallyClone();

         std::string   m_withProperties;
    bool   m_withProperties_isSet;
    std::string   m_excludeParentProperties;
    bool   m_excludeParentProperties_isSet;
    std::string   m_name;
    std::string   m_asAttribute;
    bool   m_asAttribute_isSet;
    std::string   m_uIValueOnly;
    bool   m_uIValueOnly_isSet;
    std::string   m_excludeUiValues;
    bool   m_excludeUiValues_isSet;
    std::string   m_excludeIsModifiable;
    bool   m_excludeIsModifiable_isSet;
    std::string   m_includeIsModifiable;
    bool   m_includeIsModifiable_isSet;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

