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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_NAMINGRULE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_NAMINGRULE_HXX


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

#include <teamcenter/schemas/soa/_2011_06/metamodel/RulePattern.hxx>


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

                    class NamingRule;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<NamingRule> > NamingRuleArray;
                    class RulePattern;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::NamingRule : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    NamingRule(   );


    std::string& getConditionName() ;
    const std::string& getConditionName() const;
    void setConditionName( const std::string& conditionName );
    std::string& getCaze() ;
    const std::string& getCaze() const;
    void setCaze( const std::string& caze );
    std::string& getPattern() ;
    const std::string& getPattern() const;
    void setPattern( const std::string& pattern );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RulePattern> >& getRulePatternArray() const;
    void setRulePatternArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RulePattern> >& rulePatterns );
    void addRulePattern( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RulePattern>& rulePattern );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "NamingRule" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual NamingRule* reallyClone();

         std::string   m_conditionName;
    std::string   m_caze;
    std::string   m_pattern;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::RulePattern> >   m_rulePatterns;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

