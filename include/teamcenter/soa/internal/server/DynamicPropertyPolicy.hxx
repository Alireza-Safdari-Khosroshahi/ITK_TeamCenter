//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_DYNAMICPROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_DYNAMICPROPERTYPOLICY_HXX

#include <string>
#include <map>


#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>
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
                class DynamicPropertyPolicy;
            }
       }
    }
}

class TCSOASERVER_API Teamcenter::Soa::Internal::Server::DynamicPropertyPolicy:
               public Teamcenter::Soa::Internal::Server::PropertyPolicy
{
public:
    static const  std::string     POLICY_NAME;


   static DynamicPropertyPolicy* createPolicy( const std::string& name, const Teamcenter::Soa::Common::ObjectPropertyPolicy &policy);
   static DynamicPropertyPolicy* createPolicy( const std::string& name );

   static void deletePolicy( const std::string& name );

   ~DynamicPropertyPolicy();

    virtual  std::string  getName();

    void addProperties   ( const std::vector< Teamcenter::Soa::Common::PolicyType> &properties );
    void removeProperties( const std::vector< Teamcenter::Soa::Common::PolicyType> &properties );

protected:
    virtual Teamcenter::Soa::Common::PolicyType getObjectProperties( const std::string& typeOrClassName );

private:
    DynamicPropertyPolicy();
    explicit DynamicPropertyPolicy(const std::string& name): PropertyPolicy(), policyName(name), myNamePropertyMap(),mUseRefCounting(false){}

    static DynamicPropertyPolicy* findEquivalentPolicy( const Teamcenter::Soa::Common::ObjectPropertyPolicy & policy );

    static     std::map<std::string, Teamcenter::Soa::Internal::Server::DynamicPropertyPolicy*> namePolicyMap;
    static     void expandModifiers( const Teamcenter::Soa::Common::ObjectPropertyPolicy& sourcePolicy, Teamcenter::Soa::Common::ObjectPropertyPolicy& expandedPolicy);
    static     void expandModifiers( const Teamcenter::Soa::Common::PolicyType& sourceType, Teamcenter::Soa::Common::PolicyType& expandedType);

    std::string policyName;
    // Not to be confused with the map of PolicyTypes the base PropertyPolicy keeps.
    // The PropertyPolicy map has property information from inherited parents, and expanded preferences
    // this map is just the raw source definition
    std::map< std::string, Teamcenter::Soa::Common::PolicyType > myNamePropertyMap;
    bool mUseRefCounting;

};

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
