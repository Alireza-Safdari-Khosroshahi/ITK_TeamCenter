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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_PROPERTYVALUE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_PROPERTYVALUE_HXX


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
            namespace _2006_03
            {
                namespace Base
                {

                    class PropertyValue;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<PropertyValue> > PropertyValueArray;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::PropertyValue : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    PropertyValue(   );


    bool getIsNull() const;
    void setIsNull( bool isNull );
    bool isIsNullSet() const;
    void setIsIsNullSet( bool flag );
    std::string& getValue() ;
    const std::string& getValue() const;
    void setValue( const std::string& value );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "PropertyValue" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual PropertyValue* reallyClone();

         bool   m_isNull;
    bool   m_isNull_isSet;
    std::string   m_value;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

