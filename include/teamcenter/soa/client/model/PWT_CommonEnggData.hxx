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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWT_COMMONENGGDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWT_COMMONENGGDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PWT_EngineeringData.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API PWT_CommonEnggData : public Teamcenter::Soa::Client::Model::PWT_EngineeringData
{
public:
    const std::string& get_chng_category();
    const std::string& get_engg_proj_num();
    const std::string& get_engg_proj_desc();
    const std::string& get_temp_ar_num();
    const std::string& get_temp_ar_desc();
    const std::string& get_final_ar_num();
    const std::string& get_final_ar_desc();
    const std::string& get_issue_date();
    const std::string& get_change_initiator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PWT_CommonEnggData")

   virtual ~PWT_CommonEnggData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
