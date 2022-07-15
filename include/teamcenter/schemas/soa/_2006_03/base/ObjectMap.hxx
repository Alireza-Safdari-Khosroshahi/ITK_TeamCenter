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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_OBJECTMAP_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_OBJECTMAP_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/ModelObject.hxx>


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

                    class ObjectMap;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ObjectMap> > ObjectMapArray;
                    class ModelObject;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ObjectMap : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ObjectMap(   );


    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& getBo() ;
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& getBo() const;
    void setBo( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& modelObject );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ObjectMap" ); }
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
    virtual ObjectMap* reallyClone();

         std::string   m_uid;
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>   m_bo;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

