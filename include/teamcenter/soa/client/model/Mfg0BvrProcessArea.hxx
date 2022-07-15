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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPROCESSAREA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPROCESSAREA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanItemBOPLine.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrProcessArea : public Teamcenter::Soa::Client::Model::ImanItemBOPLine
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0successors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0input_flows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0output_flows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0all_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0used_equipment();
    double get_Mfg0allocated_time();
    double get_Mfg0calc_duration();
    double get_Mfg0calc_start_time();
    double get_Mfg0calc_dur_start_time();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0allocated_ops();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0plant_specific_ops();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0none_plant_specific_ops();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0consumed_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0other_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0sub_elements();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0allocated_feature();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assigned_material();
    double get_Mfg0cycle_time();
    double get_Mfg0worker_count();
    double get_Mfg0capacity();
    double get_Mfg0work_content();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assigned_workarea();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0container();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0child_processes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0child_discrete_ops();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0child_continuous_ops();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0assembled_IPA();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0Carpet();
    const std::string& get_Mfg0Direction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrProcessArea")

   virtual ~Mfg0BvrProcessArea();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
