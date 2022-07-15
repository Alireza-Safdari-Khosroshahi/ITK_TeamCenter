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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_IMC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_IMC_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_data_manager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API POM_imc : public Teamcenter::Soa::Client::Model::POM_data_manager
{
public:
    const std::string& get_name();
    int get_site_id();
    int get_dbms();
    const std::string& get_user_id();
    const std::string& get_password();
    const std::string& get_connect_string();
    const std::string& get_imc_node_name();
    int get_imc_ods_site();
    const std::string& get_geography();
    const std::string& get_http_site_node();
    const std::string& get_gms_url();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_imc")

   virtual ~POM_imc();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
