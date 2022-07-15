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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_OBJECTPROPERTYPOLICY_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_OBJECTPROPERTYPOLICY_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/Modifiers.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/PolicyType.hxx>


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

                    class ObjectPropertyPolicy;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ObjectPropertyPolicy> > ObjectPropertyPolicyArray;
                    class Modifiers;
                    class PolicyType;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ObjectPropertyPolicy : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ObjectPropertyPolicy(   );


    bool getUseRefCount() const;
    void setUseRefCount( bool useRefCount );
    bool isUseRefCountSet() const;
    void setIsUseRefCountSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Modifiers> >& getModifierArray() const;
    void setModifierArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Modifiers> >& modifiers );
    void addModifier( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Modifiers>& modifier );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyType> >& getTypeArray() const;
    void setTypeArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyType> >& types );
    void addType( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyType>& type );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ObjectPropertyPolicy" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ObjectPropertyPolicy* reallyClone();

         bool   m_useRefCount;
    bool   m_useRefCount_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Modifiers> >   m_modifiers;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyType> >   m_types;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

