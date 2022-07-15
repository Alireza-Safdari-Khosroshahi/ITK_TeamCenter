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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AUTHORIZATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AUTHORIZATION_HXX

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
                class TaskType;
                class Form;
                class DistributionList;
                class Folder;
                class Folder;
                class ReleaseStatus;
                class User;


class TCSOACLIENTMNGD_API Authorization : public Teamcenter::Soa::Client::Model::Folder
{
public:
    const std::string& get_release_number();
    int get_current_status();
    int get_previous_status();
    const Teamcenter::Soa::Common::DateTime& get_date_of_current_status();
    Teamcenter::Soa::Common::AutoPtr<TaskType> get_task_type();
    Teamcenter::Soa::Common::AutoPtr<Form> get_task_form();
    Teamcenter::Soa::Common::AutoPtr<DistributionList> get_notification_list();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_target_folder();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_reference_folder();
    Teamcenter::Soa::Common::AutoPtr<ReleaseStatus> get_release_status();
    const Teamcenter::Soa::Common::DateTime& get_date_submitted();
    Teamcenter::Soa::Common::AutoPtr<User> get_submitted_by();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Authorization")

   virtual ~Authorization();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
