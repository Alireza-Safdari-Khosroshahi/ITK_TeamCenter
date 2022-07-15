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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_PROPDESCRIPTOR_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_PROPDESCRIPTOR_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/PropDependant.hxx>


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

                    class PropDescriptor;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<PropDescriptor> > PropDescriptorArray;
                    class PropDependant;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    PropDescriptor(   );


    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    int getMaxLength() const;
    void setMaxLength( int maxLength );
    bool isMaxLengthSet() const;
    void setIsMaxLengthSet( bool flag );
    std::string& getLovUid() ;
    const std::string& getLovUid() const;
    void setLovUid( const std::string& lovUid );
    bool isLovUidSet() const;
    void setIsLovUidSet( bool flag );
    std::string& getLovTypeUid() ;
    const std::string& getLovTypeUid() const;
    void setLovTypeUid( const std::string& lovTypeUid );
    bool isLovTypeUidSet() const;
    void setIsLovTypeUidSet( bool flag );
    bool getDisplayable() const;
    void setDisplayable( bool displayable );
    int getMaxArraySize() const;
    void setMaxArraySize( int maxArraySize );
    bool isMaxArraySizeSet() const;
    void setIsMaxArraySizeSet( bool flag );
    int getAttachedSpecifier() const;
    void setAttachedSpecifier( int attachedSpecifier );
    bool isAttachedSpecifierSet() const;
    void setIsAttachedSpecifierSet( bool flag );
    std::string& getTypeUid() ;
    const std::string& getTypeUid() const;
    void setTypeUid( const std::string& typeUid );
    bool getEnabled() const;
    void setEnabled( bool enabled );
    bool isEnabledSet() const;
    void setIsEnabledSet( bool flag );
    bool getRequired() const;
    void setRequired( bool required );
    bool isRequiredSet() const;
    void setIsRequiredSet( bool flag );
    int getType() const;
    void setType( int type );
    bool getAnArray() const;
    void setAnArray( bool anArray );
    std::string& getUiname() ;
    const std::string& getUiname() const;
    void setUiname( const std::string& uiname );
    int getPtype() const;
    void setPtype( int ptype );
    bool getModifiable() const;
    void setModifiable( bool modifiable );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDependant> >& getPropDependantArray() const;
    void setPropDependantArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDependant> >& propDependants );
    void addPropDependant( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDependant>& propDependant );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "PropDescriptor" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual PropDescriptor* reallyClone();

         std::string   m_name;
    int   m_maxLength;
    bool   m_maxLength_isSet;
    std::string   m_lovUid;
    bool   m_lovUid_isSet;
    std::string   m_lovTypeUid;
    bool   m_lovTypeUid_isSet;
    bool   m_displayable;
    int   m_maxArraySize;
    bool   m_maxArraySize_isSet;
    int   m_attachedSpecifier;
    bool   m_attachedSpecifier_isSet;
    std::string   m_typeUid;
    bool   m_enabled;
    bool   m_enabled_isSet;
    bool   m_required;
    bool   m_required_isSet;
    int   m_type;
    bool   m_anArray;
    std::string   m_uiname;
    int   m_ptype;
    bool   m_modifiable;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDependant> >   m_propDependants;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

