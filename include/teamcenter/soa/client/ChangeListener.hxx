/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_CHANGELISTENER_HXX
#define TEAMCENTER_SOA_CLIENT_CHANGELISTENER_HXX

#include <string>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API ChangeListener
{
public:

    virtual void modelObjectChange( const std::vector< Teamcenter::Soa::Common::AutoPtr<ModelObject> >& changedObjs ) = 0;

    virtual ~ChangeListener() {};
};
}}}//end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
