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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TOOL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Tool : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_symbol_name();
    const std::string& get_site_classification();
    const std::string& get_vendor_name();
    const std::string& get_version();
    const Teamcenter::Soa::Common::DateTime& get_install_date();
    const Teamcenter::Soa::Client::StringVector& get_variables();
    const Teamcenter::Soa::Client::StringVector& get_default_values();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_encapsulator();
    const Teamcenter::Soa::Client::StringVector& get_input_formats();
    const Teamcenter::Soa::Client::StringVector& get_output_formats();
    int get_shell_or_translator();
    int get_tool_flags();
    const std::string& get_launch_cmd_mac();
    const std::string& get_launch_cmd_win();
    bool get_download_require();
    bool get_callback_enable();
    bool get_view_capable();
    bool get_markup_capable();
    bool get_embed_application();
    bool get_vvi_require();
    bool get_digital_signing_capable();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Tool")

   virtual ~Tool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
