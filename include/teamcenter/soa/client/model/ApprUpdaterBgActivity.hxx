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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDATERBGACTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDATERBGACTIVITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ApprUpdaterAuditRecord;


class TCSOACLIENTMNGD_API ApprUpdaterBgActivity : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_process_id();
    const std::string& get_machine();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_package();
    int get_stage();
    const Teamcenter::Soa::Common::DateTime& get_when();
    int get_ifail();
    Teamcenter::Soa::Common::AutoPtr<ApprUpdaterAuditRecord> get_audit_record();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdaterBgActivity")

   virtual ~ApprUpdaterBgActivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
