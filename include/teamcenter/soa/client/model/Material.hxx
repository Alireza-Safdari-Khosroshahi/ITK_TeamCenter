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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MATERIAL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MATERIAL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API Material : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_p_mat();
    const std::string& get_p_mat2();
    const std::string& get_p_mat3();
    const std::string& get_p_mat4();
    const std::string& get_p_pcoat();
    const std::string& get_p_pcoat2();
    const std::string& get_p_pcoat3();
    const std::string& get_p_pcoat4();
    const std::string& get_p_perf();
    const std::string& get_p_perf2();
    const std::string& get_p_perf3();
    const std::string& get_p_perf4();
    const std::string& get_p_pcperf();
    const std::string& get_p_pcperf2();
    const std::string& get_p_pcperf3();
    const std::string& get_p_pcperf4();
    const std::string& get_p_appear();
    const std::string& get_p_appear2();
    const std::string& get_p_appear3();
    const std::string& get_p_appear4();
    const std::string& get_p_fin();
    const std::string& get_p_fin2();
    const std::string& get_p_fin3();
    const std::string& get_p_fin4();
    const std::string& get_p_svc();
    const std::string& get_p_svc2();
    const std::string& get_p_addreq();
    const std::string& get_p_addreq2();
    const std::string& get_p_addreq3();
    const std::string& get_p_addreq4();
    const std::string& get_p_mateng();
    const std::string& get_p_appeng();
    const std::string& get_p_pnteng();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Material")

   virtual ~Material();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
