// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2011.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TC_SOA_SERVERLOGGER_HXX
#define TC_SOA_SERVERLOGGER_HXX

#include <mld/logging/Logger.hxx>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Server
        {
            // Keep this class unpublished (teamcenter/soa/internal/server directory) but 
            // make the namespace match the Logger string in the logger.property file
            Teamcenter::Logging::Logger* logger();
        }
    }
}

#endif
