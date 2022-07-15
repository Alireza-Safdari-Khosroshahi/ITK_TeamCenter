/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRDATUM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRDATUM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrBopManufacturingFeature.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrDatum : public Teamcenter::Soa::Client::Model::Mfg0BvrBopManufacturingFeature
{
public:
    const std::string& get_Mfg0datum_type();
    const std::string& get_Mfg0datum_usage_type();
    const std::string& get_Mfg0control_direction();
    bool get_Mfg0cntrl_i_direction();
    bool get_Mfg0cntrl_j_direction();
    bool get_Mfg0cntrl_k_direction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrDatum")

   virtual ~Mfg0BvrDatum();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
