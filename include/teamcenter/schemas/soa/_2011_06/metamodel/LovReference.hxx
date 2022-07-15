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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_LOVREFERENCE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_LOVREFERENCE_HXX


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

                    class LovReference;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<LovReference> > LovReferenceArray;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovReference : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    LovReference(   );


    std::string& getLovTypeUid() ;
    const std::string& getLovTypeUid() const;
    void setLovTypeUid( const std::string& lovTypeUid );
    bool isLovTypeUidSet() const;
    void setIsLovTypeUidSet( bool flag );
    std::string& getSpecifier() ;
    const std::string& getSpecifier() const;
    void setSpecifier( const std::string& specifier );
    std::string& getConditionName() ;
    const std::string& getConditionName() const;
    void setConditionName( const std::string& conditionName );
    std::string& getStyle() ;
    const std::string& getStyle() const;
    void setStyle( const std::string& style );
    std::string& getLovUid() ;
    const std::string& getLovUid() const;
    void setLovUid( const std::string& lovUid );
    std::string& getPropDependents() ;
    const std::string& getPropDependents() const;
    void setPropDependents( const std::string& propDependents );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "LovReference" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual LovReference* reallyClone();

         std::string   m_lovTypeUid;
    bool   m_lovTypeUid_isSet;
    std::string   m_specifier;
    std::string   m_conditionName;
    std::string   m_style;
    std::string   m_lovUid;
    std::string   m_propDependents;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

