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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_ACTIONREFERENCE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_ACTIONREFERENCE_HXX


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

                    class ActionReference;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ActionReference> > ActionReferenceArray;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::ActionReference : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ActionReference(   );


    bool getExprt() const;
    void setExprt( bool exprt );
    bool isExprtSet() const;
    void setIsExprtSet( bool flag );
    std::string& getReferenceName() ;
    const std::string& getReferenceName() const;
    void setReferenceName( const std::string& referenceName );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ActionReference" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ActionReference* reallyClone();

         bool   m_exprt;
    bool   m_exprt_isSet;
    std::string   m_referenceName;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

