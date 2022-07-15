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

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_ERRORSTACK_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_ERRORSTACK_HXX


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

#include <teamcenter/schemas/soa/_2006_03/base/ErrorValue.hxx>


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

                    class ErrorStack;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ErrorStack> > ErrorStackArray;
                    class ErrorValue;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ErrorStack(   );


    std::string& getClientId() ;
    const std::string& getClientId() const;
    void setClientId( const std::string& clientId );
    bool isClientIdSet() const;
    void setIsClientIdSet( bool flag );
    std::string& getUid() ;
    const std::string& getUid() const;
    void setUid( const std::string& uid );
    bool isUidSet() const;
    void setIsUidSet( bool flag );
    int getClientIndex() const;
    void setClientIndex( int clientIndex );
    bool isClientIndexSet() const;
    void setIsClientIndexSet( bool flag );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorValue> >& getErrorValueArray() const;
    void setErrorValueArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorValue> >& errorValues );
    void addErrorValue( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorValue>& errorValue );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ErrorStack" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ErrorStack* reallyClone();

         std::string   m_clientId;
    bool   m_clientId_isSet;
    std::string   m_uid;
    bool   m_uid_isSet;
    int   m_clientIndex;
    bool   m_clientIndex_isSet;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorValue> >   m_errorValues;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

