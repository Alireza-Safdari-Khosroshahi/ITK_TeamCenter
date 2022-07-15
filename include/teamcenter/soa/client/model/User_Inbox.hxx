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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_USER_INBOX_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_USER_INBOX_HXX

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
                class WorkspaceObject;
                class WorkspaceObject;


class TCSOACLIENTMNGD_API User_Inbox : public Teamcenter::Soa::Client::Model::Folder
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_inbox_delegate();
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    const Teamcenter::Soa::Common::DateTime& get_end_date();
    int get_new_tasks();
    const Teamcenter::Soa::Client::ModelObjectVector& get_surrogate_list();
    const Teamcenter::Soa::Common::DateTimeVector& get_surrogate_st_dates();
    const Teamcenter::Soa::Common::DateTimeVector& get_surrogate_end_dates();
    bool get_is_valid_surrogate();
    bool get_is_out_of_office();
    size_t count_tasks_to_perform();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_tasks_to_perform_at( size_t inx );
    size_t count_tasks_to_track();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_tasks_to_track_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("User_Inbox")

   virtual ~User_Inbox();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
