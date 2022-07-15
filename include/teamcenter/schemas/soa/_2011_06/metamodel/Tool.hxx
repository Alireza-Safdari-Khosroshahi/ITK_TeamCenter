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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_TOOL_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_TOOL_HXX


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



#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_exports.h>

namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2011_06
            {
                namespace Metamodel
                {

                    class Tool;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<Tool> > ToolArray;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    Tool(   );


    std::string& getVersion() ;
    const std::string& getVersion() const;
    void setVersion( const std::string& version );
    bool isVersionSet() const;
    void setIsVersionSet( bool flag );
    std::string& getMimeType() ;
    const std::string& getMimeType() const;
    void setMimeType( const std::string& mimeType );
    bool isMimeTypeSet() const;
    void setIsMimeTypeSet( bool flag );
    bool getCallbackEnabled() const;
    void setCallbackEnabled( bool callbackEnabled );
    bool isCallbackEnabledSet() const;
    void setIsCallbackEnabledSet( bool flag );
    std::string& getLaunchCommandMac() ;
    const std::string& getLaunchCommandMac() const;
    void setLaunchCommandMac( const std::string& launchCommandMac );
    bool isLaunchCommandMacSet() const;
    void setIsLaunchCommandMacSet( bool flag );
    std::string& getLaunchCommandWin() ;
    const std::string& getLaunchCommandWin() const;
    void setLaunchCommandWin( const std::string& launchCommandWin );
    bool isLaunchCommandWinSet() const;
    void setIsLaunchCommandWinSet( bool flag );
    bool getVviRequired() const;
    void setVviRequired( bool vviRequired );
    bool isVviRequiredSet() const;
    void setIsVviRequiredSet( bool flag );
    std::string& getToolUid() ;
    const std::string& getToolUid() const;
    void setToolUid( const std::string& toolUid );
    bool isToolUidSet() const;
    void setIsToolUidSet( bool flag );
    bool getDownloadRequired() const;
    void setDownloadRequired( bool downloadRequired );
    bool isDownloadRequiredSet() const;
    void setIsDownloadRequiredSet( bool flag );
    std::string& getVendorName() ;
    const std::string& getVendorName() const;
    void setVendorName( const std::string& vendorName );
    bool isVendorNameSet() const;
    void setIsVendorNameSet( bool flag );
    std::string& getPackageName() ;
    const std::string& getPackageName() const;
    void setPackageName( const std::string& packageName );
    bool isPackageNameSet() const;
    void setIsPackageNameSet( bool flag );
    std::string& getSymbol() ;
    const std::string& getSymbol() const;
    void setSymbol( const std::string& symbol );
    std::string& getDescription() ;
    const std::string& getDescription() const;
    void setDescription( const std::string& description );
    bool isDescriptionSet() const;
    void setIsDescriptionSet( bool flag );
    bool getMarkupCapable() const;
    void setMarkupCapable( bool markupCapable );
    bool isMarkupCapableSet() const;
    void setIsMarkupCapableSet( bool flag );
    std::string& getReleaseDate() ;
    const std::string& getReleaseDate() const;
    void setReleaseDate( const std::string& releaseDate );
    bool isReleaseDateSet() const;
    void setIsReleaseDateSet( bool flag );
    bool getViewCapable() const;
    void setViewCapable( bool viewCapable );
    bool isViewCapableSet() const;
    void setIsViewCapableSet( bool flag );
    bool getDigitalSignatureCapable() const;
    void setDigitalSignatureCapable( bool digitalSignatureCapable );
    bool isDigitalSignatureCapableSet() const;
    void setIsDigitalSignatureCapableSet( bool flag );
    bool getEmbedApplication() const;
    void setEmbedApplication( bool embedApplication );
    bool isEmbedApplicationSet() const;
    void setIsEmbedApplicationSet( bool flag );
    std::string& getName() ;
    const std::string& getName() const;
    void setName( const std::string& name );
    const std::vector<std::string>& getInputFormatArray() const;
    void setInputFormatArray( const std::vector<std::string>& inputFormats );
    void addInputFormat( const std::string& inputFormat );
    const std::vector<std::string>& getOutputFormatArray() const;
    void setOutputFormatArray( const std::vector<std::string>& outputFormats );
    void addOutputFormat( const std::string& outputFormat );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "Tool" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual Tool* reallyClone();

         std::string   m_version;
    bool   m_version_isSet;
    std::string   m_mimeType;
    bool   m_mimeType_isSet;
    bool   m_callbackEnabled;
    bool   m_callbackEnabled_isSet;
    std::string   m_launchCommandMac;
    bool   m_launchCommandMac_isSet;
    std::string   m_launchCommandWin;
    bool   m_launchCommandWin_isSet;
    bool   m_vviRequired;
    bool   m_vviRequired_isSet;
    std::string   m_toolUid;
    bool   m_toolUid_isSet;
    bool   m_downloadRequired;
    bool   m_downloadRequired_isSet;
    std::string   m_vendorName;
    bool   m_vendorName_isSet;
    std::string   m_packageName;
    bool   m_packageName_isSet;
    std::string   m_symbol;
    std::string   m_description;
    bool   m_description_isSet;
    bool   m_markupCapable;
    bool   m_markupCapable_isSet;
    std::string   m_releaseDate;
    bool   m_releaseDate_isSet;
    bool   m_viewCapable;
    bool   m_viewCapable_isSet;
    bool   m_digitalSignatureCapable;
    bool   m_digitalSignatureCapable_isSet;
    bool   m_embedApplication;
    bool   m_embedApplication_isSet;
    std::string   m_name;
    std::vector<std::string>   m_inputFormats;
    std::vector<std::string>   m_outputFormats;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

