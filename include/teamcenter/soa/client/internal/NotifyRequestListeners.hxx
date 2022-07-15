// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_NOTIFYREQUESTLISTENERS_HXX
#define TEAMCENTER_SOA_CLIENT_NOTIFYREQUESTLISTENERS_HXX


#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/RequestListener.hxx>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class NotifyRequestListeners
{
public:
    explicit NotifyRequestListeners();
    ~NotifyRequestListeners();

    void notifyRequestListeners(const ServiceInfo& info);

    void notifyResponseListeners(const ServiceInfo& info);

};


}}}//end namespace

#endif

