/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_IIOPSKELETON_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_IIOPSKELETON_HXX


#include <string>
#include <map>

#include <tcgateway/t2lservice.hxx>



#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {

/**
 */
class  TCSOASERVER_API IiopSkeleton : public T2LService
{
public:



    virtual void invokeMethod( const std::string& method, const std::string& xmlIn , std::string& utf8Out);
    virtual void initialize();

    virtual void invokeManagementOperation( const std::string& method,
                               const std::string& argDoc,
                                     std::string& outDoc );

protected:

    std::map< std::string, void(*)( const std::string& xmlIn, std::string& xmlOut) > _svcMap;
    std::string m_serviceName;


};    // End Class

}}}}    // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif

