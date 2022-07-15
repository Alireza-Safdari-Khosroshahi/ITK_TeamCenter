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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVROPERATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVROPERATION_HXX

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


class TCSOACLIENTMNGD_API Mfg0BvrOperation : public Teamcenter::Soa::Client::Model::ImanItemBOPLine
{
public:
    const std::string& get_Mfg0ld_representation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0successors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0input_flows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0output_flows();
    double get_Mfg0calc_start_time();
    double get_Mfg0calc_duration();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0implements();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0implementations();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0other_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0consumed_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0handled_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assembled_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0disassembled_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0all_material();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0allocated_features();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0used_equipment();
    double get_Mfg0allocated_time();
    double get_Mfg0calc_dur_start_time();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0prec_const_successors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0prec_const_predecessors();
    bool get_Mfg0has_origin();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0origin();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assigned_workarea();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0container();
    double get_Mfg0probability();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0ExecPositions();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0MELogicalDesignatorForm();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0product_logical_assignments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0tool_requirements();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrOperation")

   virtual ~Mfg0BvrOperation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
