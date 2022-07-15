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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATIONDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATIONDATA_HXX

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
                class Allocation;


class TCSOACLIENTMNGD_API AllocationData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_changeSourceList();
    const Teamcenter::Soa::Client::ModelObjectVector& get_changeTargetList();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_changeCondition();
    const std::string& get_changeReason();
    int get_changeType();
    Teamcenter::Soa::Common::AutoPtr<Allocation> get_allocationTag();
    const std::string& get_object_type();
    const std::string& get_absocc_attr_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AllocationData")

   virtual ~AllocationData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
