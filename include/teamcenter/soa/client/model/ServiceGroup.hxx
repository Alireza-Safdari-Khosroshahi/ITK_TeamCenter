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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SERVICEGROUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SERVICEGROUP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Transaction.hxx>

#include <teamcenter/soa/client/model/ServiceeventmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEEVENTMANAGEMENTMODELMNGD_API ServiceGroup : public Teamcenter::Soa::Client::Model::Transaction
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_inprogress_phys_elements();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServiceGroup")

   virtual ~ServiceGroup();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceeventmanagementMngd_undef.h>
#endif
