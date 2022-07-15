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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPSOFTWARE_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPSOFTWARE_REVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Software_Revision_Master.hxx>

#include <teamcenter/soa/client/model/EsmsoftwareMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAESMSOFTWAREMODELMNGD_API AppSoftware_Revision_Master : public Teamcenter::Soa::Client::Model::Software_Revision_Master
{
public:
    const std::string& get_addrForPartNum();
    const std::string& get_sw_architecture();
    const std::string& get_flashingMethod();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppSoftware_Revision_Master")

   virtual ~AppSoftware_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EsmsoftwareMngd_undef.h>
#endif
