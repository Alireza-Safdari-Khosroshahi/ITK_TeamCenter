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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATIONLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATIONLINE_HXX

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


class TCSOACLIENTMNGD_API AllocationLine : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    const std::string& get_allocation_line_reason();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_allocation_line_allocation();
    const std::string& get_allocation_line_type_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allocation_line_data_ice_tags();
    bool get_allocation_line_is_removed_by_ic();
    bool get_allocation_line_is_added_by_ic();
    const Teamcenter::Soa::Client::StringVector& get_allocation_line_data_props_list();
    const std::string& get_allocation_line_ic_release_status();
    const std::string& get_allocation_line_ic_effectivity();
    const std::string& get_allocation_line_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allocation_line_source_occs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allocation_line_sources();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_allocation_line_window();
    const std::string& get_allocation_line_conf_ic_name_list();
    bool get_allocation_line_is_conf_by_ic();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allocation_line_ice_tags();
    const std::string& get_allocation_line_ic_intent();
    const std::string& get_allocation_line_ic_name_list();
    bool get_allocation_line_is_changed_by_ic();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allocation_line_target_occs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allocation_line_targets();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_allocation_line_type();
    const Teamcenter::Soa::Client::StringVector& get_allocation_line_data_values_list();
    int get_allocation_line_affecting_ice_types();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_allocation_line_condition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AllocationLine")

   virtual ~AllocationLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
