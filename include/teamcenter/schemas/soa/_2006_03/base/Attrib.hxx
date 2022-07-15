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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_ATTRIB_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_ATTRIB_HXX


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

                    class Attrib;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<Attrib> > AttribArray;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::Attrib : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    Attrib(   );


    int getMaxLength() const;
    void setMaxLength( int maxLength );
    bool isMaxLengthSet() const;
    void setIsMaxLengthSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    int getDescriptors() const;
    void setDescriptors( int descriptors );
    int getType() const;
    void setType( int type );
    std::string& getRefClassUid() ;
    const std::string& getRefClassUid() const;
    void setRefClassUid( const std::string& refClassUid );
    bool isRefClassUidSet() const;
    void setIsRefClassUidSet( bool flag );
    std::string& getUiName() ;
    const std::string& getUiName() const;
    void setUiName( const std::string& uiName );
    bool isUiNameSet() const;
    void setIsUiNameSet( bool flag );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "Attrib" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual Attrib* reallyClone();

         int   m_maxLength;
    bool   m_maxLength_isSet;
    std::string   m_name;
    std::string   m_uid;
    int   m_descriptors;
    int   m_type;
    std::string   m_refClassUid;
    bool   m_refClassUid_isSet;
    std::string   m_uiName;
    bool   m_uiName_isSet;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

