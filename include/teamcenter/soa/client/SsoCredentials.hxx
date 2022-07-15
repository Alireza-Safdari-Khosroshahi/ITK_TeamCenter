/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
#ifndef TEAMCENTER_SOA_CLIENT_SSOCREDENTIALS_HXX
#define TEAMCENTER_SOA_CLIENT_SSOCREDENTIALS_HXX
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ModelManager.hxx>
#include <teamcenter/soa/client/CredentialManager.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>


struct  TCSSO_Exception_s;
typedef TCSSO_Exception_s *TCSSO_Exception_p_t;

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API SsoCredentials : public Teamcenter::Soa::Client::CredentialManager
{
public:
    /**
     * Creates an instance of the SsoCredentials.
     * SOA client framework uses TcSS client-side library for SSO login. SOA client applications 
     * must supply values for "ssoServerUrl" and "ssoAppID" with this consrutor. Internally 
     * SOA uses SSO API to login to the SSO server and generate unique token for the supplied 
     * "ssoAppID". The user will be prompted with a web based UI for the initial SSO login. 
     * Upon successful login to the SSO server, a user ID and token will be returned. 
     * The client applications must then use this SSO credentials to login to the tcserver 
     * using the "loginSSO" service.
     *
     * @param ssoServerUrl   SSO login service URL. SOA client applications must supply this value.
     * @param ssoAppID       SSO application ID. SOA client applications must supply this value.
     */    
    SsoCredentials( const std::string& ssoServerUrl, const std::string& ssoAppID );

    ~SsoCredentials();

    virtual Teamcenter::Soa::Client::CredentialManager::CredentialsType getCredentialType();
    virtual Teamcenter::Soa::Client::CredentialManager::Credentials     getCredentials ( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InvalidUserException invalidUser );
    virtual Teamcenter::Soa::Client::CredentialManager::Credentials     getCredentials ( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InvalidCredentialsException invalidCredentials );
    

    /**
     * The SSO tokens are not valid for re-authentication, but may want discriminator
     */
    virtual void setUserPassword( const std::string& user, const std::string& password, const std::string& discriminator );

    /**
     * Save for relogin attempt if user expires on server
     */
    virtual void setGroupRole ( const std::string& group, const std::string& role );

    /**
     * Get SSO URL.
     *
     * Return URL used to connect to the SSO Server
     */
    const std::string getSSOUrl() const;
    
    const std::string& getSSOAppId() const;

    SOA_CLASS_NEW_OPERATORS


protected:
    /**
     * Constant for SSO Session Flag
     */
    const bool TC_SSO_SESSION_FLAG;
    void handleException_( TCSSO_Exception_p_t e ) const;
private:
    SsoCredentials();
    

    std::string _ssoServerUrl;
    std::string _ssoAppID;
    std::string _group;
    std::string _role;
    std::string _discriminator;
};
}}}//end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
