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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANACTIONHANDLER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANACTIONHANDLER_HXX

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


class TCSOACLIENTMNGD_API ImanActionHandler : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_handler_id();
    const std::string& get_handler_desc();
    const std::string& get_function_name();
    int get_function_type();
    int get_handler_execution_mode();
    const Teamcenter::Soa::Client::StringVector& get_static_args_list();
    int get_retry_count();
    const Teamcenter::Soa::Common::DateTime& get_execution_time();
    int get_handler_retry_interval();
    int get_okto_override_exectime();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanActionHandler")

   virtual ~ImanActionHandler();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
