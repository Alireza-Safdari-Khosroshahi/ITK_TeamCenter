// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_HTTPTRANSPORT_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_HTTPTRANSPORT_HXX

#include <string>
#include <new>
#include <vector>
#include <curl/curl.h>

#include <teamcenter/soa/client/internal/Transport.hxx>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class TCSOACLIENTMNGD_API HttpTransport : public Transport
{
public:
    SOA_CLASS_NEW_OPERATORS
     
    explicit HttpTransport(  Teamcenter::Soa::Client::SessionManager *sessionManager );
    ~HttpTransport();

    typedef std::map< std::string, std::string > cookiesMap;


    virtual void sendRequest( const std::string& port, const std::string& method, const std::string& args, const std::string& servletURI, std::string& responseString );

    static size_t headerReader( char *data, size_t size, size_t nmemb, std::map<std::string,std::string>* headers);
    static void getCookies( const std::map<std::string,std::string>& headers, cookiesMap& oldCookies );
    static void getCookieString(cookiesMap& cookies, std::string& cookieString);


    

protected:

    Teamcenter::Soa::Client::SessionManager* m_sessionManager;

private:
    HttpTransport(); // don't allow use of default

    std::string m_connectString;
    std::string m_certFile;
    std::string m_clientCertFile;
    std::string m_clientKeyFile;
    std::string m_clientKeyPass;

    std::string cookieString;
    cookiesMap webSealCookies, oldCookies, lastCookies, cookieJar;
    std::map<CURL*, bool> mapCurlHandle; //True=Inuse, False=free and can be used.
    Teamcenter::Soa::Internal::Common::Mutex mutex1;

    bool isWebSealChallange(const std::map<std::string,std::string>& headers, const std::string& responseString);
    void updateWebSealCookies(const std::map<std::string,std::string>& headers, CURL* curlHandle);
    bool hasNewCookies( cookiesMap& newCookies, cookiesMap prevCookies ) const;
    void applyCookies(CURL* curlHandle);
    void initialize();
    void getCertPath();
    CURL* getCurlHandle();
    void releaseCurlHandle(CURL* hCurl);

};


}}} // namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif