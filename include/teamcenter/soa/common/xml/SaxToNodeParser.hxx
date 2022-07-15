/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#ifndef TEAMCENTER_SOA_COMMON_XML_SAXTONODEPARSER_HXX
#define TEAMCENTER_SOA_COMMON_XML_SAXTONODEPARSER_HXX

#include <string>
#include <map>
#include <vector>
#include <ostream>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/SoaStlAllocator.h>
#include <teamcenter/soa/internal/common/XercesWarnings.hxx>

XERCES_CPP_NAMESPACE_USE


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Xml
            {

class XMLNode;
typedef std::vector<XMLNode*, Teamcenter::Soa::Common::tcsoastlallocator<XMLNode*> > XMLNodeVector;
typedef XMLNodeVector::const_iterator XMLNodeIterator;

//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of XMLCh data to local code page for display.
class TCSOACOMMON_API TcStrX
{
public :


    /**
     * Construct a string from a source Xerces XMLCh.
     * The string is decoded from UTF-8 to the local code page.
     *
     * @param toTranscode   Source string from Xerces
     * @param replaceOneA   By default Xerces will replace invalid characters
     *                      (ones in UTF-8 character set, but not in the local code page)
     *                      with 0x1a byte code. The 0x1a is ASCII for 'replace', but
     *                      this character causes problems down stream. By setting this
     *                      flag, the 0x1a will be replaced by '?'
     *                      This constructor is called throughout the SAX Parsing of
     *                      SAXToNodeParser, it it only required to scan for 0x1a on
     *                      data in the XML document, not the XML tags
     * @param encodingName  the data encoding 
     *
     *
     */
    explicit TcStrX(const XMLCh* const toTranscode, const std::string& encodingName,  bool replaceOneA=false);


    ~TcStrX();


    const char* localForm() const;
    operator const std::string&() const; //lint !e1930 should use a function like c_str, but this method is already widely used

    SOA_CLASS_NEW_OPERATORS


private :
    TcStrX():str(){}

    std::string str;
    static std::map<std::string, XMLTranscoder*>    xmlTranscoders;
};

class TCSOACOMMON_API XMLNode
{
public:
//For some reason using allocator for map is giving compile error on SUN OS. Need to look into.
    typedef std::map< std::string, std::string, std::less<std::string>, Teamcenter::Soa::Common::tcsoastlallocator<std::pair<const std::string, std::string> > > StrStrMap;

    XMLNode()
        :  uri(), name(), children(), characters(), parent(0), m_attrs(), m_extensionName()
    {}

    ~XMLNode();

    void putAttr( const std::string& key, const std::string& value );
    std::string getAttr( const std::string& key ) const;
    bool existsAttr( const std::string& key ) const;
    std::string getExtensionName() const;
    void setExtensionName( const std::string& extensionName );

    // Debug
    void output( std::ostream& out, const std::string& indent = "" ) const;

    std::string uri;
    std::string name;
    XMLNodeVector children;
    std::string characters;

    XMLNode* parent;

    const StrStrMap& attrs()const { return m_attrs; }

    SOA_CLASS_NEW_OPERATORS

private:
    typedef StrStrMap::const_iterator MapItr;

    // Disallow copying.
    XMLNode( const XMLNode& other );
    XMLNode& operator = ( const XMLNode& other );

    StrStrMap  m_attrs;
    std::string m_extensionName;

};

class TCSOACOMMON_API SAXToNodeParser : public DefaultHandler
{
public:
    static bool checkForIllegalXMLchars(const std::string& xmlString,  std::string& message);

    /**
     * Allow the calling app (TcServer or SOA Client application) to choose whether
     * to replace invalid characters returned by Xerces transcode function as 0x1a with
     * with the industry standard printable character '?'.
     */
    static void replaceHexOneA( bool replace );

    /**
     * Allow the calling app (TcServer or SOA Client application) to choose the desired
     * encoding
     */
    void setEncodingName( const std::string& encodingName );

    SAXToNodeParser();

    ~SAXToNodeParser();

     /**
     * Parse the input xml file.
     * @param fileName the name of the file to parse.
     * @returns Parsed representation of the xml in the XMLNode format.
     * @throws DomException if issue for parsing.
     */
    const XMLNode& parseFile( const std::string& fileName );
    const XMLNode& parseFile( const std::string& fileName, const std::string& encodingName);
    const XMLNode& parseString( const std::string& toParse );
    const XMLNode& parseString( const std::string& toParse, const std::string& encodingName);

    const XMLNode& getRoot();

    // -----------------------------------------------------------------------
    //  Implementations of the SAX DocumentHandler interface
    // -----------------------------------------------------------------------
    void endDocument()
    {};

    void endElement( const XMLCh* const uri,
                     const XMLCh* const localname,
                     const XMLCh* const qname);

    void characters( const XMLCh* const chars,
                     const unsigned int length);

    void ignorableWhitespace( const XMLCh* const /*chars*/,
                              const unsigned int /*length*/ )
    {}

    void processingInstruction ( const XMLCh* const /*target*/,
                                 const XMLCh* const /*data*/ )
    {}


    void startDocument()
    {};

    void startElement(    const   XMLCh* const uri,
                        const   XMLCh* const localname,
                        const   XMLCh* const qname,
                        const   Attributes&        attributes);


    // -----------------------------------------------------------------------
    //  Implementations of the SAX ErrorHandler interface
    // -----------------------------------------------------------------------
    void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);

    SOA_CLASS_NEW_OPERATORS

private :
    
    static bool s_replaceHexOneA;

    XMLNode* m_root;
    XMLNode* m_currentNode;
    SAX2XMLReader* m_parser;
    std::string m_encodingName;
    std::string    m_targetNamespace;
    std::string    m_sourceFile;
    const char *         m_sourceString;
};


}}}}  // Namespace


#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif

