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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPROCESSTYPEVERSIONMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPROCESSTYPEVERSIONMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MEProcessVersionMaster.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API MEProcessTypeVersionMaster : public Teamcenter::Soa::Client::Model::MEProcessVersionMaster
{
public:
    double get_allocated_time();
    double get_calculated_time();
    double get_sim_allocated_time();
    double get_sim_waiting_time();
    const std::string& get_sim_date();
    double get_target_cost();
    double get_target_time();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEProcessTypeVersionMaster")

   virtual ~MEProcessTypeVersionMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
