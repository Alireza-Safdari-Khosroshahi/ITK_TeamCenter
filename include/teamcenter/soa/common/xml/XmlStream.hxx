/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#ifndef TEAMCENTER_SOA_COMMON_XML_XMLSTREAM_HXX
#define TEAMCENTER_SOA_COMMON_XML_XMLSTREAM_HXX

#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/xml/LinkedStreamBuffer.hxx>



#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {
               namespace Xml
               {

class TCSOACOMMON_API XmlStream : public std::iostream
{
public:
    struct NameValuePair
    {
        std::string    name;
        std::string  value;
    };
    typedef std::vector<NameValuePair> NameValuePairArray;


    XmlStream();
    ~XmlStream();
    bool isRootElement        ()const;
    void writeOpenElement     ( const std::string& ns, const std::string& name );
    void writeAttribute       ( const std::string& name, const std::string& value );
    void writeOpenElementClose( const std::string& ns, bool empty=false );
    void writeOpenElement     ( const std::string& ns, const std::string& name, const NameValuePairArray& attributes );
    void writeCloseElement    ( const std::string& ns, const std::string& name );
    const std::string getNamespacePrefix( const std::string& xsdNamespace );

    void    addNamespaces( const std::set< std::string > namespaces );

    // Return the contents of the XmlStream as a string
    std::string str();

    // Place the contents of the XmlStream into a string
    void str( std::string& s );

    SOA_CLASS_NEW_OPERATORS

private:
    // Don't allow copy constructors
    XmlStream( const XmlStream& right);
    XmlStream& operator = ( const XmlStream& right);

    bool  addNamespace   ( const std::string& xsdNamespace );
    void  removeNamespace( const std::string& xsdNamespace );


    typedef std::map< std::string, std::string > StrStrMap;
    typedef StrStrMap::const_iterator              StrStrMapItr;

    LinkedStreamCharBuffer *m_buffer;
    StrStrMap           m_namespaceMap;
    std::stack<bool>    m_definedNamespaces;
    int                 m_prefixIndex;
    bool                m_root;
};

}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
