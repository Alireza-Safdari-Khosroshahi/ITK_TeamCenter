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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PRINTCONFIGURATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PRINTCONFIGURATION_HXX

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
                class Tool;
                class DatasetType;
                class DispatcherServiceArgument;


class TCSOACLIENTMNGD_API PrintConfiguration : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    const std::string& get_provider_display_name();
    const std::string& get_provider_name();
    const std::string& get_dispatcher_svc_name();
    size_t count_supp_mk_apps();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_supp_mk_apps_at( size_t inx );
    const std::string& get_dispatcher_svc_display_name();
    bool get_support_stamp();
    const std::string& get_printer_name();
    size_t count_supp_dataset_types();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_supp_dataset_types_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_paper_sizes();
    size_t count_dispatcher_svc_arguments();
    Teamcenter::Soa::Common::AutoPtr<DispatcherServiceArgument> get_dispatcher_svc_arguments_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PrintConfiguration")

   virtual ~PrintConfiguration();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
