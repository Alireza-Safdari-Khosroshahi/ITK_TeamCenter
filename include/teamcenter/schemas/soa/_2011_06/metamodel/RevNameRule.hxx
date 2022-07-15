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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_REVNAMERULE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_REVNAMERULE_HXX


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

                    class RevNameRule;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<RevNameRule> > RevNameRuleArray;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::RevNameRule : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    RevNameRule(   );


    bool getExcludeSkipLetters() const;
    void setExcludeSkipLetters( bool excludeSkipLetters );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    int getSupplementalType() const;
    void setSupplementalType( int supplementalType );
    bool isSupplementalTypeSet() const;
    void setIsSupplementalTypeSet( bool flag );
    std::string& getSecondaryDescription() ;
    const std::string& getSecondaryDescription() const;
    void setSecondaryDescription( const std::string& secondaryDescription );
    bool isSecondaryDescriptionSet() const;
    void setIsSecondaryDescriptionSet( bool flag );
    std::string& getSecondaryStartRevision() ;
    const std::string& getSecondaryStartRevision() const;
    void setSecondaryStartRevision( const std::string& secondaryStartRevision );
    bool isSecondaryStartRevisionSet() const;
    void setIsSecondaryStartRevisionSet( bool flag );
    std::string& getSkipLetters() ;
    const std::string& getSkipLetters() const;
    void setSkipLetters( const std::string& skipLetters );
    bool isSkipLettersSet() const;
    void setIsSkipLettersSet( bool flag );
    std::string& getStartRevision() ;
    const std::string& getStartRevision() const;
    void setStartRevision( const std::string& startRevision );
    int getType() const;
    void setType( int type );
    int getSecondaryType() const;
    void setSecondaryType( int secondaryType );
    bool isSecondaryTypeSet() const;
    void setIsSecondaryTypeSet( bool flag );
    int getAlphabecticCase() const;
    void setAlphabecticCase( int alphabecticCase );
    bool isAlphabecticCaseSet() const;
    void setIsAlphabecticCaseSet( bool flag );
    std::string& getConditionName() ;
    const std::string& getConditionName() const;
    void setConditionName( const std::string& conditionName );
    std::string& getDescription() ;
    const std::string& getDescription() const;
    void setDescription( const std::string& description );
    bool isDescriptionSet() const;
    void setIsDescriptionSet( bool flag );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "RevNameRule" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual RevNameRule* reallyClone();

         bool   m_excludeSkipLetters;
    std::string   m_name;
    int   m_supplementalType;
    bool   m_supplementalType_isSet;
    std::string   m_secondaryDescription;
    bool   m_secondaryDescription_isSet;
    std::string   m_secondaryStartRevision;
    bool   m_secondaryStartRevision_isSet;
    std::string   m_skipLetters;
    bool   m_skipLetters_isSet;
    std::string   m_startRevision;
    int   m_type;
    int   m_secondaryType;
    bool   m_secondaryType_isSet;
    int   m_alphabecticCase;
    bool   m_alphabecticCase_isSet;
    std::string   m_conditionName;
    std::string   m_description;
    bool   m_description_isSet;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

