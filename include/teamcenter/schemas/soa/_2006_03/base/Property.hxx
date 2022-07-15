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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_PROPERTY_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_PROPERTY_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/PropertyValue.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2006_03
            {
                namespace Base
                {

                    class Property;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<Property> > PropertyArray;
                    class PropertyValue;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::Property : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    Property(   );


    bool getModifiable() const;
    void setModifiable( bool modifiable );
    bool isModifiableSet() const;
    void setIsModifiableSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    std::string& getUiValue() ;
    const std::string& getUiValue() const;
    void setUiValue( const std::string& uiValue );
    bool isUiValueSet() const;
    void setIsUiValueSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropertyValue> >& getValueArray() const;
    void setValueArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropertyValue> >& values );
    void addValue( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropertyValue>& value );
    const std::vector<std::string>& getUiValueArray() const;
    void setUiValueArray( const std::vector<std::string>& uiValues );
    void addUiValue( const std::string& uiValue );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "Property" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual Property* reallyClone();

         bool   m_modifiable;
    bool   m_modifiable_isSet;
    std::string   m_name;
    std::string   m_uiValue;
    bool   m_uiValue_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropertyValue> >   m_values;
    std::vector<std::string>   m_uiValues;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

