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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWTCANCELCOSTDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWTCANCELCOSTDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API PwtCancelCostData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::StringVector& get_part_id();
    const Teamcenter::Soa::Client::FloatVector& get_cancel_cost();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PwtCancelCostData")

   virtual ~PwtCancelCostData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
