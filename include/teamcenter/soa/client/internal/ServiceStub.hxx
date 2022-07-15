/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

/**
    @file

    This class serves no purpose except as a way to have the SessionManager
    maintain a list of stubs and be able to delete them at end
*/

/*  */


#ifndef TEAMCENTER_SOA_CLIENT_SERVICESTUB_HXX
#define TEAMCENTER_SOA_CLIENT_SERVICESTUB_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API ServiceStub
{
public:
    virtual ~ServiceStub() {}
    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Teamcenter::Soa::Client::ServiceStub")
};

}}}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
