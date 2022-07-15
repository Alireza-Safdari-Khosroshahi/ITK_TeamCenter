/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_POLICYMANAGER_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_POLICYMANAGER_HXX

#include <string>
#include <map>
#include <set>

#include <teamcenter/soa/common/PolicyType.hxx>
#include <teamcenter/soa/internal/server/PropertyPolicy.hxx>



#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {
                class PolicyManager;
            }
        }
    }
}

/**
 **/
class TCSOASERVER_API Teamcenter::Soa::Internal::Server::PolicyManager
{
public:
    static void setPropertyPolicy   (   Teamcenter::Soa::Internal::Server::PropertyPolicy* propPolicy );
    static void setPropertyPolicy   (   Teamcenter::Soa::Internal::Server::PropertyPolicy* propPolicy, bool forceUpdate );


    /**
     * Sets the Empty flag on the Object Property Policy.
     * When the empty flag is true, all current policies will be ignored and only the
     * basic properties (UID, type name, .etc) will be returned in the ServiceData
     **/
    static void setEmptyPolicy( bool empty );

    /**
     * Returns an PolicyType (with list of properties) that reflects the current Policy
     * for the given Type or Class.
     *
     * @param typeName   Name of Type, may be blank
     * @param className  Name of Class, may  be blank
     *
     * @return Policy for this Type or Class.
     **/
    static const Teamcenter::Soa::Common::PolicyType* getObjectProperties( const std::string& typeName, const std::string& className );


    /**
     * Return a string that represents this Object Property Policy.
     * The string will have the format:
     * TypeOrClassName { propertyName [,propertyName]...}
     *
     * @pramam  ifChanged   If this is set to true, this method will return a
     *                      non-empty string only if the policy has changed since
     *                      the last call to toString.
     * @return String representation of this class
     **/
    static std::string toString( bool ifChanged = false);


    /**
     * Return a comma seprated lists of policy names that are currently
     * contributing to the overall policy.
     * The string will have the format:
     * XMLPolicy:Default,XMLPolicy:MyApp
     *
     * @return Names of the policies
     **/
    static std::string getPolicyNames( );

private:
    static void initialize ( );


    static bool empty;
    static bool hasChanged;
    static std::map< std::string, Teamcenter::Soa::Common::PolicyType > namePropertyMap;
    static Teamcenter::Soa::Internal::Server::PropertyPolicy *          currentPolicy;

};




#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
