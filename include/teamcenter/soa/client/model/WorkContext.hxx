// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_MODEL_WORKCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_WORKCONTEXT_HXX


#include <teamcenter/soa/client/model/TC_WorkContext.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {

/**
 * Fixed class to represent the old name of TcType/TcClass TC_WorkContext
 * It extended the properly named, generated class so that it can be
 * used interchangeably during the deprecation period.
 *
 *  @deprecated As of 8.0, use TC_WorkContext.
 */
#ifdef WNT
__declspec(deprecated("As of 8.0, use TC_WorkContext."))
#endif
class TCSOACLIENTMNGD_API WorkContext : public Teamcenter::Soa::Client::Model::TC_WorkContext
{
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
