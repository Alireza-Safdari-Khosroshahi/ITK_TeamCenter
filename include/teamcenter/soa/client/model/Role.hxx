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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ROLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ROLE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Role : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_role_name();
    const std::string& get_description();
    int get_data_source();
    const Teamcenter::Soa::Common::DateTime& get_last_sync_date();
    const std::string& get_object_name();
    const std::string& get_fnd0export_sites();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Role")

   virtual ~Role();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
