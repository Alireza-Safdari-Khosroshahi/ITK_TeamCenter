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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PERSON_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PERSON_HXX

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


class TCSOACLIENTMNGD_API Person : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_user_name();
    const std::string& get_form_name();
    const std::string& get_PA1();
    const std::string& get_PA2();
    const std::string& get_PA3();
    const std::string& get_PA4();
    const std::string& get_PA5();
    const std::string& get_PA6();
    const std::string& get_PA7();
    const std::string& get_PA8();
    const std::string& get_PA9();
    const std::string& get_PA10();
    int get_data_source();
    const Teamcenter::Soa::Common::DateTime& get_last_sync_date();
    const std::string& get_timezone();
    const std::string& get_locale();
    const std::string& get_fnd0export_sites();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Person")

   virtual ~Person();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
