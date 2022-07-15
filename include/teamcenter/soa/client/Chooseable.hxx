/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_CHOOSEABLE_HXX
#define TEAMCENTER_SOA_CLIENT_CHOOSEABLE_HXX

#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API Chooseable
{
public:
    SOA_CLASS_NEW_OPERATORS

    virtual ~Chooseable();
    virtual bool needsToBeResolved();
    virtual Chooseable* resolve();
    virtual std::vector<Chooseable*> resolveVector();
};


}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>


#endif

