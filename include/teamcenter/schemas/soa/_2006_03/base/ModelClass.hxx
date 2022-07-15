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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_MODELCLASS_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_MODELCLASS_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/Attrib.hxx>


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

                    class ModelClass;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ModelClass> > ModelClassArray;
                    class Attrib;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ModelClass : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ModelClass(   );


    std::string& getParentClassName() ;
    const std::string& getParentClassName() const;
    void setParentClassName( const std::string& parentClassName );
    bool isParentClassNameSet() const;
    void setIsParentClassNameSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Attrib> >& getAttributeArray() const;
    void setAttributeArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Attrib> >& attributes );
    void addAttribute( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Attrib>& attribute );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ModelClass" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ModelClass* reallyClone();

         std::string   m_parentClassName;
    bool   m_parentClassName_isSet;
    std::string   m_name;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Attrib> >   m_attributes;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

