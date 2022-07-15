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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_SOFTWAREREVMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_SOFTWAREREVMASTER_HXX

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


class TCSOAGMOMODELMNGD_API CORP_SoftwareRevMaster : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_dls();
    const std::string& get_release_level();
    const std::string& get_prelim_data();
    const Teamcenter::Soa::Client::StringVector& get_change_desc();
    const std::string& get_DLS_1();
    const std::string& get_FNA();
    const std::string& get_FNM();
    const std::string& get_FNA_Description();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_SoftwareRevMaster")

   virtual ~CORP_SoftwareRevMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
