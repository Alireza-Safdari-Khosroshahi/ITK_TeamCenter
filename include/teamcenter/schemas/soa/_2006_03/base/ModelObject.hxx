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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_MODELOBJECT_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_MODELOBJECT_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/Property.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/DisplayProperty.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/XJProperty.hxx>


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

                    class ModelObject;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ModelObject> > ModelObjectArray;
                    class Property;
                    class DisplayProperty;
                    class XJProperty;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ModelObject(   );


    std::string& getClassUid() ;
    const std::string& getClassUid() const;
    void setClassUid( const std::string& classUid );
    bool isClassUidSet() const;
    void setIsClassUidSet( bool flag );
    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    bool getUpdateDesc() const;
    void setUpdateDesc( bool updateDesc );
    bool isUpdateDescSet() const;
    void setIsUpdateDescSet( bool flag );
    std::string& getClassName() ;
    const std::string& getClassName() const;
    void setClassName( const std::string& className );
    bool isClassNameSet() const;
    void setIsClassNameSet( bool flag );
    std::string& getType() ;
    const std::string& getType() const;
    void setType( const std::string& type );
    bool isTypeSet() const;
    void setIsTypeSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property> >& getPropertieArray() const;
    void setPropertieArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property> >& properties );
    void addPropertie( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property>& propertie );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::DisplayProperty> >& getUipropertieArray() const;
    void setUipropertieArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::DisplayProperty> >& uiproperties );
    void addUipropertie( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::DisplayProperty>& uipropertie );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJProperty> >& getPropArray() const;
    void setPropArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJProperty> >& props );
    void addProp( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJProperty>& prop );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ModelObject" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ModelObject* reallyClone();

         std::string   m_classUid;
    bool   m_classUid_isSet;
    std::string   m_uid;
    bool   m_updateDesc;
    bool   m_updateDesc_isSet;
    std::string   m_className;
    bool   m_className_isSet;
    std::string   m_type;
    bool   m_type_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property> >   m_properties;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::DisplayProperty> >   m_uiproperties;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::XJProperty> >   m_props;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

