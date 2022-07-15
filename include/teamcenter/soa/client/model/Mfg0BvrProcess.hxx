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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPROCESS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPROCESS_HXX

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


class TCSOACLIENTMNGD_API Mfg0BvrProcess : public Teamcenter::Soa::Client::Model::ImanItemBOPLine
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0container();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0sub_elements();
    const std::string& get_Mfg0ld_representation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0successors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0input_flows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0output_flows();
    double get_Mfg0calc_start_time();
    double get_Mfg0calc_duration();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0implementations();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0other_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assigned_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0consumed_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0all_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0allocated_feature();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0used_equipment();
    double get_Mfg0allocated_time();
    double get_Mfg0calc_dur_start_time();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0prec_const_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0prec_const_successors();
    bool get_Mfg0has_origin();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0origin();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assigned_workarea();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0child_processes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0child_discrete_ops();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0child_continuous_ops();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0assembled_IPA();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0MELogicalDesignatorForm();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0product_logical_assignments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0tool_requirements();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrProcess")

   virtual ~Mfg0BvrProcess();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
