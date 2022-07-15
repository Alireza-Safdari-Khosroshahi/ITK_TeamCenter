//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_COMMON_XML_XMLUTILS_HXX
#define TEAMCENTER_SOA_COMMON_XML_XMLUTILS_HXX

#include <sstream>
#include <string>
#include <cstring>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/xml/BaseObject.hxx>
#include <teamcenter/soa/internal/json/JSONObject.hxx>

#ifndef LOGICAL_DEFINED
typedef bool logical;
#endif
//typedef bool logical;       //lint !e761


#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {
               namespace Xml
               {

class bad_lexical_cast {};
template<typename Target, typename Source>
Target lexical_cast( const Source& arg )
{
  std::stringstream interpreter;
  Target result;

  if(!(interpreter << arg) ||
     !(interpreter >> result) ||
     !(interpreter >> std::ws).eof())
    throw bad_lexical_cast();

  return result;
}

template<> TCSOACOMMON_API bool        lexical_cast<bool,    std::string>( const std::string& arg );
template<> TCSOACOMMON_API std::string lexical_cast<std::string, ::logical>( const ::logical& arg );

template<> TCSOACOMMON_API std::string lexical_cast<std::string, Teamcenter::Soa::Common::DateTime> ( const Teamcenter::Soa::Common::DateTime& arg );
template<> TCSOACOMMON_API Teamcenter::Soa::Common::DateTime lexical_cast<Teamcenter::Soa::Common::DateTime, std::string>( const std::string& arg );

template<> TCSOACOMMON_API std::string lexical_cast<std::string, std::string>( const std::string& arg );

template<> TCSOACOMMON_API std::string lexical_cast<std::string, double>( const double& arg );
template<> TCSOACOMMON_API std::string lexical_cast<std::string, int>   ( const int& arg );
template<> TCSOACOMMON_API std::string lexical_cast<std::string, float> ( const float& arg );

template<> TCSOACOMMON_API double lexical_cast<double, std::string >( const std::string& arg );
template<> TCSOACOMMON_API int    lexical_cast<int,    std::string >( const std::string& arg );
template<> TCSOACOMMON_API float  lexical_cast<float,  std::string >( const std::string& arg );



std::string TCSOACOMMON_API toXmlString  ( const std::string& in );

std::string TCSOACOMMON_API decodeXml  ( const std::string& in );
std::string TCSOACOMMON_API toJsonString  ( const std::string& in );

std::string TCSOACOMMON_API decodeJson  ( const std::string& in );

std::string TCSOACOMMON_API getRootNamespace( const std::string& xml );
size_t      TCSOACOMMON_API findElement( const std::string &xml, const std::string& name, bool open);

class TCSOACOMMON_API XmlUtil
{
public:
    static const std::string sXmlContent;
    static const std::string sJsonContent;

    static  bool isXMML   ( const std::string& document );
    static  bool isJSON   ( const std::string& document );
    static  Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> parseJSON( const std::string& document );

    static  std::string parse    ( const std::string& document,    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Common::Xml::BaseObject> object );
    static  void        serialize( const std::string& contentType, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Common::Xml::BaseObject> object, std::string& document );

};

}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
