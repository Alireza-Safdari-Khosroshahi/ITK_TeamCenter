/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_TOOLIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_TOOLIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/Tool.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class ToolImpl: public Tool
{
public:



    /**
     *
     * Constructor
     *
     * @param name
     * @param description
     * @param inputFormats
     * @param outputFormats
     * @param launchCommandMac
     * @param mimeType
     * @param packageName
     * @param releaseDate
     * @param symbol
     * @param vendorName
     * @param version
     * @param callbackEnabled
     * @param digitalSignatureCapable
     * @param downloadRequired
     * @param embedApplication
     * @param markupCapable
     * @param viewCapable
     * @param vviRequired
     * @param actions
     */
    ToolImpl(  const std::string& name,  const std::string&  description, std::vector<std::string> inputFormats,
            std::vector<std::string> outputFormats, const std::string& launchCommandMac , const std::string& mimeType,
            const std::string& packageName,const std::string& releaseDate,const std::string& symbol,
            const std::string& vendorName, const std::string& version,bool callbackEnabled,
            bool digitalSignatureCapable,bool downloadRequired,
            bool embedApplication,bool markupCapable, bool viewCapable,
            bool vviRequired, std::vector<ToolAction*> actions );
    ~ToolImpl();



    virtual std::string getName();
    virtual std::vector<ToolAction*> getActions();
    virtual ToolAction* getAction( const std::string& name );
    virtual std::string getDescription();
    virtual std::vector<std::string> getInputFormats();
    virtual std::vector<std::string> getOutputFormats();
    virtual std::string getLaunchCommandMac();
    virtual std::string getMimeType();
    virtual std::string getPackageName();
    virtual std::string getReleaseDate();
    virtual std::string getSymbol();
    virtual std::string getVendorName();
    virtual std::string getVersion();
    virtual bool isCallbackEnabled();
    virtual bool isDigitalSignatureCapable();
    virtual bool isDownloadRequired();
    virtual bool isEmbedApplication();
    virtual bool isMarkupCapable();
    virtual bool isViewCapable();
    virtual bool isVviRequired();

    SOA_CLASS_NEW_OPERATORS

private:
    ToolImpl();     // don't allow use of default

    const std::string                mName;
    const std::string                mDescription;
    const std::vector<std::string>   mInputFormats;
    const std::vector<std::string>   mOutputFormats;
    const std::string                mLaunchCommandMac;
    const std::string                mMimeType;
    const std::string                mPackageName;
    const std::string                mReleaseDate;
    const std::string                mSymbol;
    const std::string                mVendorName;
    const std::string                mVersion;
    const bool                       mCallbackEnabled;
    const bool                       mDigitalSignatureCapable;
    const bool                       mDownloadRequired;
    const bool                       mEmbedApplication;
    const bool                       mMarkupCapable;
    const bool                       mViewCapable;
    const bool                       mVviRequired;
          std::vector<ToolAction*>   mActions;







};

}}}//end namespace


#endif

