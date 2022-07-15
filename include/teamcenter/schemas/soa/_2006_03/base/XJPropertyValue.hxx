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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_XJPROPERTYVALUE_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_XJPROPERTYVALUE_HXX


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

                    class XJPropertyValue;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<XJPropertyValue> > XJPropertyValueArray;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::XJPropertyValue : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    XJPropertyValue(   );


    bool getModifiable() const;
    void setModifiable( bool modifiable );
    bool isModifiableSet() const;
    void setIsModifiableSet( bool flag );
    const std::vector<std::string>& getDbValueArray() const;
    void setDbValueArray( const std::vector<std::string>& dbValues );
    void addDbValue( const std::string& dbValue );
    const std::vector<std::string>& getUiValueArray() const;
    void setUiValueArray( const std::vector<std::string>& uiValues );
    void addUiValue( const std::string& uiValue );
    const std::vector<bool>& getIsNullArray() const;
    void setIsNullArray( const std::vector<bool>& isNulls );
    void addIsNull( const bool& isNull );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "XJPropertyValue" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual XJPropertyValue* reallyClone();

         bool   m_modifiable;
    bool   m_modifiable_isSet;
    std::vector<std::string>   m_dbValues;
    std::vector<std::string>   m_uiValues;
    std::vector<bool>   m_isNulls;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

