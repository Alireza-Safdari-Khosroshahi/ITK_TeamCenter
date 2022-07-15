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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_09__CLIENTCONTEXT_NAMEBOOLEANVALUE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_09__CLIENTCONTEXT_NAMEBOOLEANVALUE_HXX


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
            namespace _2006_09
            {
                namespace Clientcontext
                {

                    class NameBooleanValue;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<NameBooleanValue> > NameBooleanValueArray;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_09::Clientcontext::NameBooleanValue : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    NameBooleanValue(   );


    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    bool getValue() const;
    void setValue( bool value );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "NameBooleanValue" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual NameBooleanValue* reallyClone();

         std::string   m_name;
    bool   m_value;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

