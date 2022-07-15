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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMJOB_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMJOB_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class EPMTask;


class TCSOACLIENTMNGD_API EPMJob : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_current_acl();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_audit_file_tag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_process_template();
    Teamcenter::Soa::Common::AutoPtr<EPMTask> get_root_task();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_def_file_tag();
    const Teamcenter::Soa::Common::DateTime& get_process_due_date();
    const Teamcenter::Soa::Client::ModelObjectVector& get_project_status();
    bool get_is_parallel_process();
    const Teamcenter::Soa::Client::ModelObjectVector& get_epm_parentprocess();
    const Teamcenter::Soa::Client::ModelObjectVector& get_all_tasks();
    const Teamcenter::Soa::Common::DateTime& get_due_date_project();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_WorkContext_Relation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_process_status();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMJob")

   virtual ~EPMJob();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
