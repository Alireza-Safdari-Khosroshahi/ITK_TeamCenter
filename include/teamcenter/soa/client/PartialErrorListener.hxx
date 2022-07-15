/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PARTIALERRORLISTENER_HXX
#define TEAMCENTER_SOA_CLIENT_PARTIALERRORLISTENER_HXX

#include <string>
#include <vector>   

#include <teamcenter/soa/client/ErrorStack.hxx> 
#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API PartialErrorListener
{
public:

    virtual void handlePartialErrors( const std::vector< ErrorStack >& partialErrors ) = 0;

    virtual ~PartialErrorListener() {};
};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
