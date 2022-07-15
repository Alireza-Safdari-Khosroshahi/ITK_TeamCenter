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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEI0EXECUTIONPLAN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEI0EXECUTIONPLAN_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MECollaborationContext.hxx>

#include <teamcenter/soa/client/model/CmtmesintegMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESINTEGMODELMNGD_API Mei0ExecutionPlan : public Teamcenter::Soa::Client::Model::MECollaborationContext
{
public:
    const std::string& get_mei0orderId();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mei0ExecutionPlan")

   virtual ~Mei0ExecutionPlan();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesintegMngd_undef.h>
#endif
