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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPADELEMENTVERSIONMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPADELEMENTVERSIONMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MEProcessTypeVersionMaster.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API MEPADElementVersionMaster : public Teamcenter::Soa::Client::Model::MEProcessTypeVersionMaster
{
public:
    const std::string& get_element_notes();
    const Teamcenter::Soa::Client::StringVector& get_usage_desc();
    const std::string& get_location_on_product();
    const std::string& get_op_loc();
    const std::string& get_prd_dev_team();
    const std::string& get_me_engineer();
    const std::string& get_me_group();
    const std::string& get_me_department();
    const std::string& get_m_c_cred();
    const std::string& get_ckd_ind();
    const std::string& get_ecs_mcs_no();
    const std::string& get_mfg_vs();
    const std::string& get_serv_ind();
    const std::string& get_vpps();
    const Teamcenter::Soa::Client::StringVector& get_element_notes_array();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEPADElementVersionMaster")

   virtual ~MEPADElementVersionMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
