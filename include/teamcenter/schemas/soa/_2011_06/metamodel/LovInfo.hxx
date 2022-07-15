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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_LOVINFO_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_LOVINFO_HXX


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

#include <teamcenter/schemas/soa/_2011_06/metamodel/LovValue.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/Bounds.hxx>


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

                    class LovInfo;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<LovInfo> > LovInfoArray;
                    class LovValue;
                    class Bounds;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovInfo : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    LovInfo(   );


    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    std::string& getAttachedProps() ;
    const std::string& getAttachedProps() const;
    void setAttachedProps( const std::string& attachedProps );
    bool isAttachedPropsSet() const;
    void setIsAttachedPropsSet( bool flag );
    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    std::string& getAttachedSpecs() ;
    const std::string& getAttachedSpecs() const;
    void setAttachedSpecs( const std::string& attachedSpecs );
    bool isAttachedSpecsSet() const;
    void setIsAttachedSpecsSet( bool flag );
    std::string& getUsage() ;
    const std::string& getUsage() const;
    void setUsage( const std::string& usage );
    std::string& getBasedOnType() ;
    const std::string& getBasedOnType() const;
    void setBasedOnType( const std::string& basedOnType );
    bool isBasedOnTypeSet() const;
    void setIsBasedOnTypeSet( bool flag );
    std::string& getTypeName() ;
    const std::string& getTypeName() const;
    void setTypeName( const std::string& typeName );
    std::string& getDescription() ;
    const std::string& getDescription() const;
    void setDescription( const std::string& description );
    std::string& getAttachedTypes() ;
    const std::string& getAttachedTypes() const;
    void setAttachedTypes( const std::string& attachedTypes );
    bool isAttachedTypesSet() const;
    void setIsAttachedTypesSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue> >& getValueArray() const;
    void setValueArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue> >& values );
    void addValue( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue>& value );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Bounds>& getRange() ;
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Bounds>& getRange() const;
    void setRange( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Bounds>& bounds );
    bool isRangeSet() const;
    void setIsRangeSet( bool flag );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "LovInfo" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual LovInfo* reallyClone();

         std::string   m_name;
    std::string   m_attachedProps;
    bool   m_attachedProps_isSet;
    std::string   m_uid;
    std::string   m_attachedSpecs;
    bool   m_attachedSpecs_isSet;
    std::string   m_usage;
    std::string   m_basedOnType;
    bool   m_basedOnType_isSet;
    std::string   m_typeName;
    std::string   m_description;
    std::string   m_attachedTypes;
    bool   m_attachedTypes_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue> >   m_values;
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Bounds>   m_range;
    bool   m_range_isSet;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

