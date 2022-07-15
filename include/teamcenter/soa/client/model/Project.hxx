// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROJECT_HXX


#include <teamcenter/soa/client/model/TC_Project.hxx>

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
 * Fixed class to represent the old name of TcType/TcClass TC_Project
 * It extended the properly named, generated class so that it can be
 * used interchangeably during the deprecation period.
 *
 *  @deprecated As of 8.0, use TC_Project.
 */
#ifdef WNT
__declspec(deprecated("As of 8.0, use TC_Project."))
#endif
class TCSOACLIENTMNGD_API Project : public Teamcenter::Soa::Client::Model::TC_Project
{
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
