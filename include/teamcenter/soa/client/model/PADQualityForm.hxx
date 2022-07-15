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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PADQUALITYFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PADQUALITYFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API PADQualityForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_registration_no();
    const std::string& get_funct_type();
    const std::string& get_kpc_desc();
    const std::string& get_kcc_desc();
    const std::string& get_draw_no();
    const std::string& get_part_no();
    const std::string& get_pdt_desc();
    const std::string& get_scw_dynamic();
    const std::string& get_scw_static();
    int get_kpc_no();
    int get_rank();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PADQualityForm")

   virtual ~PADQualityForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
