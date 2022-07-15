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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0PROFILER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0PROFILER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RuntimeBusinessObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0Profiler : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    const std::string& get_fnd0server_request_id();
    const std::string& get_fnd0server_request_name();
    int get_fnd0process_memory_usage();
    int get_fnd0sm_memory_usage();
    int get_fnd0sql_count();
    double get_fnd0db_time();
    double get_fnd0cpu_time();
    double get_fnd0wall_clock_time();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0Profiler")

   virtual ~Fnd0Profiler();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
