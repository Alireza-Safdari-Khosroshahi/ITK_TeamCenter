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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_09__CLIENTCONTEXT_REQUESTENVELOPE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_09__CLIENTCONTEXT_REQUESTENVELOPE_HXX


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

#include <teamcenter/schemas/soa/_2006_09/clientcontext/RequestHeader.hxx>
#include <teamcenter/schemas/soa/_2006_09/clientcontext/RequestBody.hxx>


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

                    class RequestEnvelope;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<RequestEnvelope> > RequestEnvelopeArray;
                    class RequestHeader;
                    class RequestBody;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestEnvelope : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    RequestEnvelope(   );


    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestHeader>& getHeader() ;
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestHeader>& getHeader() const;
    void setHeader( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestHeader>& requestHeader );
    bool isHeaderSet() const;
    void setIsHeaderSet( bool flag );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestBody>& getBody() ;
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestBody>& getBody() const;
    void setBody( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestBody>& requestBody );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "RequestEnvelope" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual RequestEnvelope* reallyClone();

         Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestHeader>   m_header;
    bool   m_header_isSet;
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_09::Clientcontext::RequestBody>   m_body;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

