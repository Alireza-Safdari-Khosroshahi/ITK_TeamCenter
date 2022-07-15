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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DISPATCHERSERVICECONFIG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DISPATCHERSERVICECONFIG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DatasetType;
                class DatasetType;
                class ImanType;
                class ImanType;
                class DispatcherServiceArgument;


class TCSOACLIENTMNGD_API DispatcherServiceConfig : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    const std::string& get_der_dataset_named_ref();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_der_dataset_type_name();
    bool get_dispatcher_svc_available();
    const std::string& get_dispatcher_svc_display_name();
    const std::string& get_dispatcher_svc_name();
    int get_priority();
    const std::string& get_provider_name();
    const std::string& get_provider_display_name();
    int get_sort_order();
    const std::string& get_src_dataset_named_ref();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_src_dataset_type_name();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_item_revision_relation();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_der_from_dataset_relation();
    size_t count_dispatcher_svc_arguments();
    Teamcenter::Soa::Common::AutoPtr<DispatcherServiceArgument> get_dispatcher_svc_arguments_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DispatcherServiceConfig")

   virtual ~DispatcherServiceConfig();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
