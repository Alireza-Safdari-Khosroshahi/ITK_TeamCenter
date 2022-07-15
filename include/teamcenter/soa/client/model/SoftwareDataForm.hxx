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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SOFTWAREDATAFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SOFTWAREDATAFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API SoftwareDataForm : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_sw_data_type();
    const std::string& get_module_id();
    const std::string& get_module_name();
    const std::string& get_pad_byte();
    bool get_header_prepend();
    int get_header_prepend_sz();
    const std::string& get_cal_ver_num_cal_mtd();
    const std::string& get_chksum_cal_mtd();
    const std::string& get_eASEE_Domain();
    const std::string& get_Assembly_Plant_Usage();
    const std::string& get_BuildBucketPlant();
    const std::string& get_ECUName();
    const std::string& get_NVM_Check_Status();
    const std::string& get_SW_Release_Level();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SoftwareDataForm")

   virtual ~SoftwareDataForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
