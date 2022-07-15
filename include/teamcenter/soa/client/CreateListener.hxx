/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

/**
    @file  CreateListener.hxx

    This is the interface used to listen Model Manager for Create Events.
*/

#ifndef TEAMCENTER_SOA_CLIENT_CREATELISTENER_HXX
#define TEAMCENTER_SOA_CLIENT_CREATELISTENER_HXX

#include <string>
#include <vector>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API CreateListener
{
public:

    virtual void modelObjectCreate( const std::vector< Teamcenter::Soa::Common::AutoPtr<ModelObject> >& createdObjs ) = 0;

    virtual ~CreateListener() {}

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
