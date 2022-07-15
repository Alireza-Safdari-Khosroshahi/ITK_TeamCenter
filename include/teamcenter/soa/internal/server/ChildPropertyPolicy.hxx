/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_CHILDPROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_CHILDPROPERTYPOLICY_HXX

#include <string>
#include <map>
#include <set>


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
                class ChildPropertyPolicy;
            }
        }
    }
}


/**
  * Assemble list of child property values based on the <type>_DefaultChildProperties perferences
  **/
class TCSOASERVER_API Teamcenter::Soa::Internal::Server::ChildPropertyPolicy :
               public Teamcenter::Soa::Internal::Server::PropertyPolicy
{
public:




    /**
     * Create in instance of an ChildPropertyPolicy.
     *
     * @return                  Instance of the ChildPropertyPolicy.
     **/
    ChildPropertyPolicy( );

    virtual int size() const;
    virtual std::string getName();

protected:
    virtual Teamcenter::Soa::Common::PolicyType getObjectProperties( const std::string& typeOrClassName );


private:


    const Teamcenter::Soa::Common::PolicyType& processTypeOrClass( const std::string& typeOrClassName );

    std::map< std::string, Teamcenter::Soa::Common::PolicyType > childNamePropertyMap;



};



#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
