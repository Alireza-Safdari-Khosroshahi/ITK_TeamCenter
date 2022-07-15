/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

/*  */


#ifndef TEAMCENTER_SOA_CLIENT_DELETELISTENER_HXX
#define TEAMCENTER_SOA_CLIENT_DELETELISTENER_HXX

#include <string>
#include <vector>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API DeleteListener
{
public:

    virtual void modelObjectDelete( const std::vector< std::string >& deletedObjs ) = 0;

    virtual ~DeleteListener() {}

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
