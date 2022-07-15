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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0ORGANIZATIONAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0ORGANIZATIONAUDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0AuditLog.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0OrganizationAudit : public Teamcenter::Soa::Client::Model::Fnd0AuditLog
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_object_name();
    const std::string& get_object_type();
    const std::string& get_fnd0EventTypeName();
    const std::string& get_fnd0UserId();
    const std::string& get_fnd0GroupName();
    const std::string& get_fnd0RoleName();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LoggedDate();
    const std::string& get_fnd0ErrorMessage();
    int get_fnd0ErrorCode();
    const std::string& get_user_name();
    const std::string& get_user_id();
    const std::string& get_role_name();
    const std::string& get_tccal_name();
    const std::string& get_name();
    const std::string& get_volume_name();
    const std::string& get_ACL_Name();
    const std::string& get_rule_name();
    const std::string& get_discipline_name();
    const std::string& get_project_name();
    const std::string& get_project_id();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0SecondaryObject();
    const std::string& get_fnd0SecondaryObjectType();
    const std::string& get_fnd0SecondaryObjectName();
    const std::string& get_fnd0SecondaryObjectID();
    const std::string& get_fnd0SecondaryObjectRevID();
    int get_fnd0SecondaryObjectSeqID();
    const std::string& get_fnd0SecondaryObjDispName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0OrganizationAudit")

   virtual ~Fnd0OrganizationAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
