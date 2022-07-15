// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_TRANSPORT_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_TRANSPORT_HXX

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
            class  SessionManager; // forward decl

// Interface declaration for transmitting Messages 

class TCSOACLIENTMNGD_API Transport
{
public:
    virtual ~Transport();
    SOA_CLASS_NEW_OPERATORS
    
    virtual void sendRequest( const std::string& port, const std::string& method, const std::string& args, const std::string& servletURI, std::string& responseString ) =0;
};

}}} // namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif