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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPLP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPLP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrManufacturingFeature.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrPLP : public Teamcenter::Soa::Client::Model::Mfg0BvrManufacturingFeature
{
public:
    const std::string& get_Mfg0datum_type();
    const std::string& get_Mfg0control_direction();
    bool get_Mfg0cntrl_i_direction();
    bool get_Mfg0cntrl_j_direction();
    bool get_Mfg0cntrl_k_direction();
    double get_Mfg0axis_direction_x();
    double get_Mfg0axis_direction_y();
    double get_Mfg0axis_direction_z();
    const std::string& get_Mfg0derived();
    double get_Mfg0plane_normal_x();
    double get_Mfg0plane_normal_y();
    double get_Mfg0plane_normal_z();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrPLP")

   virtual ~Mfg0BvrPLP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
