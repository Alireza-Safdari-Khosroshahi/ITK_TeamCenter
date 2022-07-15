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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSFERMODE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSFERMODE_HXX

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
                class ClosureRule;
                class Filter;
                class PropertySet;
                class ImanFile;


class TCSOACLIENTMNGD_API TransferMode : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_context_string();
    int get_direction();
    bool get_incremental();
    bool get_multi_site();
    Teamcenter::Soa::Common::AutoPtr<ClosureRule> get_closure_rules();
    Teamcenter::Soa::Common::AutoPtr<Filter> get_filters();
    Teamcenter::Soa::Common::AutoPtr<PropertySet> get_prop_sets();
    size_t count_xslt_files();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_xslt_files_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_config_objs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_action_list();
    int get_schema_format();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TransferMode")

   virtual ~TransferMode();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
