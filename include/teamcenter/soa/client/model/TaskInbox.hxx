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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TASKINBOX_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TASKINBOX_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Folder.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_system_class;
                class WorkspaceObject;
                class WorkspaceObject;


class TCSOACLIENTMNGD_API TaskInbox : public Teamcenter::Soa::Client::Model::Folder
{
public:
    int get_new_tasks_count();
    Teamcenter::Soa::Common::AutoPtr<POM_system_class> get_owner();
    bool get_new_tasks_flag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0ScheduleTasks();
    size_t count_tasks_to_perform();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_tasks_to_perform_at( size_t inx );
    size_t count_tasks_to_track();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_tasks_to_track_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TaskInbox")

   virtual ~TaskInbox();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
