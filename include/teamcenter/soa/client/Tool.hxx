/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_TOOL_HXX
#define TEAMCENTER_SOA_CLIENT_TOOL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ToolAction.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 */
class TCSOACLIENTMNGD_API Tool
{
public:

    virtual ~Tool();

    /**
     * @return  The name of the tool
     */
    virtual std::string getName()=0;

    /**
     * @return The list of actions associated available for this tool.
     */
    virtual std::vector<ToolAction*> getActions()=0;

    /**
     * @param name  The name of the desired action.
     * @return The named action.
     */
    virtual ToolAction* getAction( const std::string& name)=0;

    /**
     * @return The description
     */
    virtual std::string getDescription()=0;

    /**
     * @return The input formats
     */
    virtual std::vector<std::string> getInputFormats()=0;

    /**
     * @return The output formats
     */
    virtual std::vector<std::string> getOutputFormats()=0;

    /**
     * @return The Mac launch command
     */
    virtual std::string getLaunchCommandMac()=0;

    /**
     * @return The MIME type
     */
    virtual std::string getMimeType()=0;

    /**
     * @return The package name
     */
    virtual std::string getPackageName()=0;

    /**
     * @return The release date
     */
    virtual std::string getReleaseDate()=0;

    /**
     * @return symbol
     */
    virtual std::string getSymbol()=0;

    /**
     * @return vendor
     */
    virtual std::string getVendorName()=0;

    /**
     * @return version
     */
    virtual std::string getVersion()=0;

    /**
     * @return Callback enabled
     */
    virtual bool isCallbackEnabled()=0;

    /**
     * @return Digital signature capable
     */
    virtual bool isDigitalSignatureCapable()=0;

    /**
     * @return Download required
     */
    virtual bool isDownloadRequired()=0;

    /**
     * @return Embed Application
     */
    virtual bool isEmbedApplication()=0;

    /**
     * @return Markup capable
     */
    virtual bool isMarkupCapable()=0;

    /**
     * @return View Capable
     */
    virtual bool isViewCapable()=0;

    /**
     * @return VVI is required
     */
    virtual bool isVviRequired()=0;


   SOA_CLASS_NEW_OPERATORS

protected:
    Tool();
};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
