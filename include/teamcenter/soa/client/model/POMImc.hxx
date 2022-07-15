// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POMIMC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POMIMC_HXX


#include <teamcenter/soa/client/model/POM_imc.hxx>

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
 * Fixed class to represent the old name of TcType/TcClass POM_imc
 * It extended the properly named, generated class so that it can be
 * used interchangeably during the deprecation period.
 *
 *  @deprecated As of 8.0, use POM_imc.
 */
#ifdef WNT
__declspec(deprecated("As of 8.0, use POM_imc."))
#endif
class TCSOACLIENTMNGD_API POMImc : public Teamcenter::Soa::Client::Model::POM_imc
{
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
