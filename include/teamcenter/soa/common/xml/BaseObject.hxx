//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_COMMON_XML_BASEOBJECT_HXX
#define TEAMCENTER_SOA_COMMON_XML_BASEOBJECT_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/xml/XmlStream.hxx>
#include <teamcenter/soa/common/xml/Handle.hxx>
#include <teamcenter/soa/internal/json/JSONObject.hxx>
#include <teamcenter/soa/internal/json/Value.hxx>

#include <teamcenter/soa/common/AutoPtr.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Xml
            {
                class JsonStream;
                class BaseObject;
                class XMLNode;
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Soa::Common::Xml::BaseObject
{
public:
    BaseObject* clone();
    int askRefCount() const { return refCount; }

    void ref();
    void unref();
    int getCount();

            std::string getQaulifiedName() const;
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const;
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const = 0;

    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );
    virtual void parseJSON( const std::string& key, const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );
    virtual void parseSimpleJSONMapEntry( const std::string& key, const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );
    virtual void parseComplexJSONMapKey( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::Value> node );
    virtual void parseComplexJSONMapValue( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::Value> node );

    virtual bool isJsonMapEntry( ) const;
    virtual bool isJsonMapKeyReferenceType( ) const;
    virtual void writeJSONKey( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void writeJSONValue( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;

    SOA_CLASS_NEW_OPERATORS

protected:
    BaseObject();
    explicit BaseObject( const char* xsdNamespace );
    BaseObject( const char* xsdNamespace , const char* xsdTypeName );
    virtual ~BaseObject() ;
    virtual BaseObject* reallyClone() = 0;
    std::string m_xsdNamespace;
    std::string m_xsdTypeName;
    bool outputXMLBase(Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName, const char* strMonitorTag) const;

private:
    template< class T > friend class Handle;
    void addRef() { ++refCount; }
    void removeRef() { if (--refCount == 0) delete this;  }

    int refCount;
};



#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
