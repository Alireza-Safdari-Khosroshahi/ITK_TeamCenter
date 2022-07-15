/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PREFERENCPROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PREFERENCPROPERTYPOLICY_HXX

#include <string>
#include <map>
#include <set>

#include <teamcenter/soa/internal/server/PropertyPolicy.hxx>
#include <teamcenter/soa/common/PolicyType.hxx>




#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {
                class PreferencePropertyPolicy;
            }
        }
    }
}

/**
 * The PropertyPolicy class manages  lists of properties for a all Types or Classes.
 * The Policy is an additive list the comes from the different levels of Preferences, Site,
 * User, Group and Role. The preferences found in the User Group or Role do not override
 * Site preferences, but add to preferences defined in the Site. So the following
 * preference values would result in the following policy list
 *      Site:   User{ volume }
 *      User:   User{ mailbox }
 *      Group:  User{ home_folder }
 *      Policy: User{ volume, mailbox,home_folder }
 *
 * The resulting Policy is not only compiled from the above sources, it also inherites properties
 * defined in parent classes. So if the Site Policy defined the folling
 *      Site:   User{volume, mailbox,home_folder }
 *              Pom_user { user_id, group}
 *      Policy: User{volume, mailbox,home_folder,user_id, group }
 *
 **/
class TCSOASERVER_API Teamcenter::Soa::Internal::Server::PreferencePropertyPolicy :
               public Teamcenter::Soa::Internal::Server::PropertyPolicy
{
public:
    static const std::string    POLICY_NAME;

    /**
     * Create an instance of the PreferencePropertyPolicy
     **/
    PreferencePropertyPolicy( );

        virtual std::string getName();

protected:
       virtual Teamcenter::Soa::Common::PolicyType getObjectProperties( const std::string& typeOrClassName );
};



#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
