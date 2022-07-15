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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEACTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEACTIVITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Folder.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API MEActivity : public Teamcenter::Soa::Client::Model::Folder
{
public:
    double get_time();
    double get_start_time();
    const Teamcenter::Soa::Client::ModelObjectVector& get_pred_list();
    const Teamcenter::Soa::Client::StringVector& get_tool_list();
    const std::string& get_act_location();
    const std::string& get_long_description();
    const std::string& get_seq_no();
    const std::string& get_time_system_code();
    const std::string& get_time_system_category();
    double get_simulated_time();
    double get_time_system_unit_time();
    double get_time_system_frequency();
    const std::string& get_Mfg0equivalence_id();
    bool get_Mfg0has_origin();
    double get_min_start_time();
    double get_calc_time();
    double get_calc_start_time();
    int get_nc_tool_number();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEActivity")

   virtual ~MEActivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
