/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
#ifndef INCLUDE_TEAMCENTER_SOA_SERVER_SERVICEPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_SERVER_SERVICEPOLICY_HXX

#include <string>
#include <vector>

#include <teamcenter/soa/common/PolicyType.hxx>




#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Server
        {

typedef std::vector< Teamcenter::Soa::Common::PolicyType >    OperationPolicy;

/**
 * The ServicePolciy interface is used by the SOA Framework and the Object Property
 * Policy to retrieve the Per Service Policy from the servcie implementation at
 * run time. Each SOA Service implemenation must implement this interface. A
 * default implementation of the getOperationPolicy is provided to return an empty policy.
 **/
class TCSOASERVER_API ServicePolicy
{
public:

    /**
     * Returns the OperationPolicy (Per Service Policy) for a given operation.
     * This policy will be applied to the current service return data regardless of
     * what is set in other Policies (Site, User .etc). The service implementor
     * may use this method to ensure a certain set of properties are returned for
     * each object.
     * While each service implemenation must include this interface, the implementation
     * of this method is optional. The default implementation will return an empty policy.
     *
     * The implemenation of the method may return the same policy for all operations
     * in the service, or unique policies for each operation.
     *      OperationPolicy operationPolicy;
     *      if( operationName == "foo")
     *      {
     *             ObjectProperties itemProps   ( "Item{ bom_view_tags,uom_tag,item_master_tag}");
     *          operationPolicy.push_back( itemProps );
     *      }
     *      else if( operationName == "bar")
     *      {
     *          PolicyType itemRevProps( "ItemRevision{ item_revision_id,items_tag}");
     *          operationPolicy.push_back( itemProps );
     *      }
     *      return operationPolicy;
     *
     *
     * @param operationName  The name of the service operatio(method)
     * @return The Per Service Policy for this service operation.
     **/
     virtual OperationPolicy getOperationPolicy( const std::string&  operationName );



};        // End Class
}}}       // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif

