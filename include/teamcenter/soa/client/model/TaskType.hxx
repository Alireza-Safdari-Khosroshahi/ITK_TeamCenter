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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TASKTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TASKTYPE_HXX

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
                class Role;
                class Role;


class TCSOACLIENTMNGD_API TaskType : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    size_t count_approver_roles();
    Teamcenter::Soa::Common::AutoPtr<Role> get_approver_roles_at( size_t inx );
    size_t count_authorizer_roles();
    Teamcenter::Soa::Common::AutoPtr<Role> get_authorizer_roles_at( size_t inx );
    const std::string& get_tasktype_name();
    const std::string& get_description();
    const std::string& get_followup_action();
    const std::string& get_form_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TaskType")

   virtual ~TaskType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
