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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEWELDOP_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEWELDOP_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API MEWeldOp_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_program_id();
    const std::string& get_process_comment();
    double get_target_time();
    double get_target_cost();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEWeldOp_Master")

   virtual ~MEWeldOp_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
