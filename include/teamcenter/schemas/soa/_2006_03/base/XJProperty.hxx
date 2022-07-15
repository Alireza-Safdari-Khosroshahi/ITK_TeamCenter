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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_XJPROPERTY_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_XJPROPERTY_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/XJPropertyValue.hxx>


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

                    class XJProperty;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<XJProperty> > XJPropertyArray;
                    class XJPropertyValue;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::XJProperty : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    XJProperty(   );


    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJPropertyValue>& getValue() ;
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJPropertyValue>& getValue() const;
    void setValue( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJPropertyValue>& xJPropertyValue );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "XJProperty" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual bool isJsonMapEntry( ) const;
virtual bool isJsonMapKeyReferenceType( ) const;
virtual void writeJSONKey( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
virtual void writeJSONValue( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
virtual void parseSimpleJSONMapEntry( const std::string& key, const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual XJProperty* reallyClone();

         std::string   m_name;
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJPropertyValue>   m_value;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

