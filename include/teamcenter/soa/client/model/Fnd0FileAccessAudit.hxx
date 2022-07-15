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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0FILEACCESSAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0FILEACCESSAUDIT_HXX

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


class TCSOACLIENTMNGD_API Fnd0FileAccessAudit : public Teamcenter::Soa::Client::Model::Fnd0AuditLog
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
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_volume_tag();
    const std::string& get_original_file_name();
    const std::string& get_fnd0ErrorMessage();
    int get_fnd0ErrorCode();
    const std::string& get_file_name();
    const std::string& get_volume_tagDisp();
    const std::string& get_fnd0SecondaryObjDispName();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0SecondaryObject();
    const std::string& get_fnd0SecondaryObjectName();
    const std::string& get_fnd0SecondaryObjectType();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0FileAccessAudit")

   virtual ~Fnd0FileAccessAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
