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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DPVEXECUTIONFREQ_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DPVEXECUTIONFREQ_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/DpvMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOADPVMODELMNGD_API DPVExecutionFreq : public Teamcenter::Soa::Client::Model::Form
{
public:
    int get_load_frequency();
    const std::string& get_active_start_time();
    const std::string& get_active_end_time();
    bool get_active_mon();
    bool get_active_tue();
    bool get_active_wed();
    bool get_active_thu();
    bool get_active_fri();
    bool get_active_sat();
    bool get_active_sun();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DPVExecutionFreq")

   virtual ~DPVExecutionFreq();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
