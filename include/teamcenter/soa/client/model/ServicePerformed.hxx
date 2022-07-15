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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SERVICEPERFORMED_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SERVICEPERFORMED_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ServiceActivity.hxx>

#include <teamcenter/soa/client/model/ServiceprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PartMovement;


class TCSOASERVICEPROCESSINGMODELMNGD_API ServicePerformed : public Teamcenter::Soa::Client::Model::ServiceActivity
{
public:
    const Teamcenter::Soa::Common::DateTime& get_work_start_date();
    size_t count_parts_moved();
    Teamcenter::Soa::Common::AutoPtr<PartMovement> get_parts_moved_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServicePerformed")

   virtual ~ServicePerformed();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceprocessingMngd_undef.h>
#endif
