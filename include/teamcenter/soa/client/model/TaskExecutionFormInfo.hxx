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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TASKEXECUTIONFORMINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TASKEXECUTIONFORMINFO_HXX

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
                class EPMJob;


class TCSOACLIENTMNGD_API TaskExecutionFormInfo : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    int get_work_complete();
    double get_complete_percent();
    const Teamcenter::Soa::Common::DateTime& get_actual_start_date();
    const Teamcenter::Soa::Common::DateTime& get_actual_finish_date();
    int get_status();
    int get_approved_work();
    int get_work_remaining();
    const std::string& get_fnd0status();
    const std::string& get_fnd0state();
    Teamcenter::Soa::Common::AutoPtr<EPMJob> get_workflow_process();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TaskExecutionFormInfo")

   virtual ~TaskExecutionFormInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
