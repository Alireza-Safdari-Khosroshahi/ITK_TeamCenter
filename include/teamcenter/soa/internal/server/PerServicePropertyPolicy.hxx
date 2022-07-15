/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PERSERVICEPROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PERSERVICEPROPERTYPOLICY_HXX

#include <string>
#include <map>
#include <set>

#include <teamcenter/soa/internal/server/PropertyPolicy.hxx>
#include <teamcenter/soa/common/PolicyType.hxx>
#include <teamcenter/soa/server/ServicePolicy.hxx>



#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {
                class PerServicePropertyPolicy;
            }
        }
    }
}

/**
 * The PropertyPolicy class manages  lists of properties for a all Types or Classes.
 * The Policy is an additive list the comes from three sources
 *  1. Per Service Policy
 *     This policy is retrieved from the the current executing SOA Service operation.
 *     Service implementors may optionally return a OperationPolicy from the
 *     ServicePolicy::getOperationPolicy() interface.
 *  2. Site Policy
 *     This policy is retrieved from the Site perferences
 *  3. User Policy
 *     This policy is retrieved from the User/Group/Role preferences.
 *     The preferences found in the User Group or Role do not override Site preferences,
 *     but add to preferences defined in the Site. So the following preference values
 *     would result in the following policy list
 *      Site:   User{ volume }
 *      User:   User{ mailbox }
 *      Group:  User{ home_folder }
 *      Policy: User{volume, mailbox,home_folder }
 *
 * The resulting Policy is not only compiled from the above sources, it also inherites properties
 * defined in parent classes. So if the Site Policy defined the folling
 *      Site:   User{volume, mailbox,home_folder }
 *              Pom_user { user_id, group}
 *      Policy: User{volume, mailbox,home_folder,user_id, group }
 *
 **/
class TCSOASERVER_API Teamcenter::Soa::Internal::Server::PerServicePropertyPolicy :
               public Teamcenter::Soa::Internal::Server::PropertyPolicy
{
public:

    static const  std::string POLICY_NAME;

    /**
     * Construct a PropertyPolicy with the give OperationPolicy.
     */
    PerServicePropertyPolicy( const std::string& operationName, const Teamcenter::Soa::Server::OperationPolicy& operationPolicy );

    virtual int size() const;
    virtual std::string getName();

protected:
      virtual Teamcenter::Soa::Common::PolicyType getObjectProperties( const std::string& typeOrClassName );




private:
    PerServicePropertyPolicy();

    Teamcenter::Soa::Server::OperationPolicy operationPolicy;
    std::string operationName;
};




#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
