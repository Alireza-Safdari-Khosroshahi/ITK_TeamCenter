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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_MODELTYPE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_MODELTYPE_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/PropDescriptor.hxx>


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

                    class ModelType;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ModelType> > ModelTypeArray;
                    class PropDescriptor;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ModelType : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ModelType(   );


    bool getTransientType() const;
    void setTransientType( bool transientType );
    std::string& getParentTypeName() ;
    const std::string& getParentTypeName() const;
    void setParentTypeName( const std::string& parentTypeName );
    bool isParentTypeNameSet() const;
    void setIsParentTypeNameSet( bool flag );
    bool getExternalObject() const;
    void setExternalObject( bool externalObject );
    std::string& getUifName() ;
    const std::string& getUifName() const;
    void setUifName( const std::string& uifName );
    bool isUifNameSet() const;
    void setIsUifNameSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    std::string& getClassName() ;
    const std::string& getClassName() const;
    void setClassName( const std::string& className );
    std::string& getTypeUid() ;
    const std::string& getTypeUid() const;
    void setTypeUid( const std::string& typeUid );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor> >& getPropDescriptorArray() const;
    void setPropDescriptorArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor> >& propDescriptor );
    void addPropDescriptor( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor>& propDescriptor );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ModelType" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ModelType* reallyClone();

         bool   m_transientType;
    std::string   m_parentTypeName;
    bool   m_parentTypeName_isSet;
    bool   m_externalObject;
    std::string   m_uifName;
    bool   m_uifName_isSet;
    std::string   m_name;
    std::string   m_uid;
    std::string   m_className;
    std::string   m_typeUid;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor> >   m_propDescriptor;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

