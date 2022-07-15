/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

/*  */


#ifndef TEAMCENTER_SOA_CLIENT_CREDENTIALMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_CREDENTIALMANAGER_HXX

#include <string>

#include <teamcenter/schemas/soa/_2006_03/exceptions/InvalidCredentialsException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InvalidUserException.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API CredentialManager
{
public:

    enum CredentialsType { USERPASSWORD, SSO };

    struct TCSOACLIENTMNGD_API Credentials
    {
        std::string username;
        std::string securetoken;
        std::string group;
        std::string role;
        std::string descriminator;

        Credentials( const std::string& _username,
                     const std::string& _securetoken,
                     const std::string& _group,
                     const std::string& _role,
                     const std::string& _descriminator );
    private:
        Credentials(): username(), securetoken(), group(), role(), descriminator(){};

    };

    virtual ~CredentialManager();


    virtual CredentialsType getCredentialType() = 0;

    /**
     * This method is called by the SOA client framework when the server has
     * returned an InvalidCredentialsException. The implementing class should
     * prompt the user for new credentials.
     *
     * @param invalidCredentials Exception returned by the server. The
     * error message should contain details as to why the server rejected
     * the credentials i.e. "The password is not valid".
     *
     * @return An array of 4 strings, Username, Password, Group, and Role
     *
     * @throws CanceledOperationException
     */
    virtual Credentials getCredentials ( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InvalidCredentialsException invalidCredentials ) = 0;


    /**
     * This method is called by the SOA client framework when the server has
     * returned an InvalidUserException. There are two conditions when the server will
     * return this exception:
     * <ul>
     * <li> The client application has never sent a login request
     * <li> The current session has been terminated or timed-out
     * </ul>
     * The implementing class has the choice of caching the user's credentials.
     * If they have not been cached the implementing class must prompt the user
     * for new credentials.
     *
     * @param invalidUser Exception returned by the server.
     *
     * @return An array of 4 strings, Username, Password, Group, and Role
     *
     * @throws CanceledOperationException
     */
    virtual Credentials getCredentials ( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InvalidUserException invalidUser ) = 0;


    /**
     * This method is called by the SOA client framework when a login service
     * request is issued to the server. This gives the implementing class the
     * option to cache the Username and Password, so a latter re-authentication
     * attempts can be made silently.
     *
     * @param user
     * @param password
     * @param discriminator optional sessionDiscriminator to discriminate one session from another in server
     */
    virtual void setUserPassword( const std::string& user,  const std::string& password, const std::string& discriminator);

    /**
     * This method is called by the SOA client framework when a login or
     * change group/role service request is issued to the server. This gives
     * the implementing class the option to cache the Group and Role, so  latter
     * re-authentication attempts can be made silently.
     *
     * @param group
     * @param role
     */
    virtual void setGroupRole   (const std::string& group, const std::string& role);


protected:
    CredentialManager();
};
}}}//end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

